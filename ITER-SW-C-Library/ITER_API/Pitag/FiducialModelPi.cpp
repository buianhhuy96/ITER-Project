#include "FiducialModelPi.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <chrono>
#include <iostream>
//#include "opencv2/text.hpp"

using namespace cv;
using namespace ipa_Fiducials;
using namespace std;
using namespace std::chrono;
//using namespace cv::text;




FiducialModelPi::FiducialModelPi() : m_use_fast_pi_tag(false)
{
                
}

FiducialModelPi::~FiducialModelPi()
{
        
}



unsigned long FiducialModelPi::GetPoints(cv::Mat& image, std::vector<t_points>& vec_points, const blobDetectParams &blobDetectParams_set, const blobFilteringParams &blobFilteringParams_set, const ellipseFitParams &ellipseFitParam_set, const tagLenAngParams &tagLenAngParams_set)

{

	//----Auxilary initialization parameters--------------------------
	m_image_size_factor = image.cols*1. / 640.0;  // express relative to a 640x480 pixels camera image
	float rz = 640.f / image.cols;
	int Lsz = static_cast<int>(round((image.cols / 640.0)*1.5));
	cv::Mat src_mat_8U1;
	bool debug = true;
	bool drawOutput = true;
	//bool refine = false;


	if (debug)
		m_debug_img = image.clone();

	// ------------ Convert image to gray scale if necessary -------------------
	if (image.channels() == 3)
	{
		src_mat_8U1.create(image.rows, image.cols, CV_8UC1);
		cv::cvtColor(image, src_mat_8U1, cv::COLOR_RGB2GRAY);

	}
	else
	{
		src_mat_8U1 = image;
	}


	if (debug)
	{
		cv::Mat tempimg = src_mat_8U1.clone();
		cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
		//cv::imshow("00 Grayscale", tempimg);
		//cv::waitKey(0);
	}
	cv::Mat grayscale_image = src_mat_8U1.clone();

	// ------------ Smooth image -------------------
	/*  
		int Sker = round((src_mat_8U1.cols / 640.0) * 1.2);//2....2.5

		if (Sker % 2 != 0 && Sker >= 3) //If the number is an odd decimal. 
			Sker = Sker;
		else if (Sker % 2 == 0 && Sker >= 3)
			Sker = Sker + 1; //Closest odd number is going to be above. 
		else
			Sker = 3;//3
		cv::medianBlur(src_mat_8U1, src_mat_8U1, Sker);  // helps against multiple detection of same region and regions created because of noise
		*/    


	//-------- mser based blob detection----------------------

	int delta = static_cast<int>(blobDetectParams_set.delta);// 1 helps to detect regions in extremely low light condition. Drawback is that can create multiple regions in and around the same region. 
    int min_area = static_cast<int>(blobDetectParams_set.min_area_px);
    int max_area = static_cast<int>(blobDetectParams_set.max_area_per * (src_mat_8U1.cols * src_mat_8U1.rows) / 100); //blob area should not be greater than 2% of image area
	double max_variation = blobDetectParams_set.max_var;  //0.08(for  dark regions),.0.05 (for normal),0.01 for rendered (GOOD to avoid non-uniform shadows)
	Ptr<MSER> ms = cv::MSER::create(delta, min_area, max_area, max_variation);

	vector<vector<Point> > allregions;
	vector<vector<Point> > regions;
	vector<cv::Rect> allmser_bbox;
	vector<cv::Rect> mser_bbox;
	ms->detectRegions(src_mat_8U1, allregions, allmser_bbox);

	cv::Mat mask = cv::Mat(src_mat_8U1.size(), CV_8UC1, Scalar(255));
	cv::Mat r = cv::Mat(src_mat_8U1.size(), CV_8UC1, Scalar(255));
	cv::Mat g = cv::Mat(src_mat_8U1.size(), CV_8UC1, Scalar(255));
	cv::Mat b = cv::Mat(src_mat_8U1.size(), CV_8UC1, Scalar(255));

	// set 1- region properties to filter out
    const int num = static_cast<const int>(allmser_bbox.size());
	vector<Point> allcentroids(num);
	vector<Point> centroids;
	std::vector<float> allarea(num);

	//-------- mser region filtering by region stats----------------------
	//First compute centroid  of the region
	for (long unsigned int j = 0; j < allmser_bbox.size(); j++)
	{
		allarea[j] = static_cast<float>(allregions[j].size());
		allcentroids[j].x = allmser_bbox[j].x + (allmser_bbox[j].width / 2);
		allcentroids[j].y = allmser_bbox[j].y + (allmser_bbox[j].height / 2);	
	}

	if (debug)
	{
		cv::Mat tempimg = src_mat_8U1.clone();
		for (long unsigned int j = 0; j < allmser_bbox.size(); j++)
		{
			circle(tempimg, allcentroids[j], 5, Scalar(128, 0, 0), -1);
		}
		cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
		//cv::imshow("00 Grayscale", tempimg);
		//cv::waitKey(0);
	}


	// supress duplicates of regions
	std::vector<int> toKeep(num);
	int margin = 1;
	int difx;
	int dify;
	for (long unsigned int j = 0; j < allregions.size(); j++)
	{
		for (long unsigned int k = 0; k < allregions.size(); k++)
		{
			if ((j == k) && (toKeep[j] != -1))
			{
				toKeep[j] = 1;
				continue;
			}
			difx = abs(allcentroids[j].x - allcentroids[k].x);
			dify = abs(allcentroids[j].y - allcentroids[k].y);
			if ((difx<= margin) && (dify <= margin) && (allarea[j] >= allarea[k]))  //rect_area bcz donut shape region might have smaller point bsaed area
			{
				if (toKeep[j]!=-1)
					toKeep[j] = 1;
				toKeep[k] = -1;
			}
			else if ((difx <= margin && dify <= margin && (allarea[j] < allarea[k])))
			{
				toKeep[j] = -1;
				if (toKeep[k] != -1)
					toKeep[k] = 1;
			}


		}
	}


	for (long unsigned int j = 0; j < allregions.size(); j++)
	{
		if (toKeep[j] == 1 )
		{
			regions.push_back(allregions[j]);
			mser_bbox.push_back(allmser_bbox[j]);
			centroids.push_back(allcentroids[j]);

		}
	}


	// set 2- region properties to filter out
	const int num2 = static_cast<const int>(mser_bbox.size());
	std::vector<float> width(num2);
	std::vector<float> height(num2);
	std::vector<float> area(num2);
	std::vector<float> aspect_ratio(num2);
	std::vector<float> extent(num2);
	std::vector<float> solidity(num2);
	std::vector<float> hull_area(num2);
	vector<vector<Point>> hull(num2);
	std::vector<int> numSubregions(num2);
	std::vector<float> rect_area(num2);
	//Find number of smaller regions inside each region
	for (long unsigned int j = 0; j < mser_bbox.size(); j++)
	{
		numSubregions[j] = 0;
		for (long unsigned int k = 0; k < mser_bbox.size(); k++)
		{
			if (j == k)
				continue;
			if ((centroids[k].x > mser_bbox[j].x) && (centroids[k].x < mser_bbox[j].x + mser_bbox[j].width) && (centroids[k].y > mser_bbox[j].y) && (centroids[k].y < mser_bbox[j].y + mser_bbox[j].height))
				numSubregions[j] = numSubregions[j] + 1;
		}
	}


	// Compute rest of the resgion stats
	for (long unsigned int j = 0; j < mser_bbox.size(); j++)
	{
		width[j] = static_cast<float>(mser_bbox[j].width);
		height[j] = static_cast<float>(mser_bbox[j].height);
		aspect_ratio[j] = (width[j]) / height[j];
		rect_area[j] = width[j] * height[j];
		convexHull(regions[j], hull[j]);
		hull_area[j] = static_cast<float>(contourArea(hull[j]));

		area[j] = static_cast<float>(regions[j].size());
		extent[j] = area[j] / rect_area[j];
		solidity[j] = area[j] / hull_area[j];

		//printf("Width:%f, Height:%f, aspect_ratio:%f, area:%f, extent:%f, rect_area:%f,hull_area:%f, solidity:%f, subRegions:%d \n", width[j], height[j], aspect_ratio[j], area[j], extent[j], rect_area[j], hull_area[j], solidity[j], numSubregions[j]);

	}


    int xx = 10;
	int maxx = 80;
	int minn = 5;
	int rxx, gxx, bxx;
	int ct = 0;
            for (vector<cv::Point> v : regions){
                xx= xx+20;
                 if (xx>180)
                     {xx=10;}
				 rxx = xx + (minn + rand() % ((maxx + 1) - minn)); gxx= xx + (minn + rand() % ((maxx + 1) - minn)); bxx = xx + (minn + rand() % ((maxx + 1) - minn));
				for (cv::Point p : v) {
					if (debug)
					{
						r.at<uchar>(p.y, p.x) = static_cast<unsigned char>(rxx);
						g.at<uchar>(p.y, p.x) = static_cast<unsigned char>(gxx);
						b.at<uchar>(p.y, p.x) = static_cast<unsigned char>(bxx);
					}
					if (area[ct] > min_area && aspect_ratio[ct] > blobFilteringParams_set.min_aspect && aspect_ratio[ct] < blobFilteringParams_set.max_aspect && solidity[ct] > blobFilteringParams_set.solidity && extent[ct] > blobFilteringParams_set.min_ext && extent[ct] < blobFilteringParams_set.max_ext  && numSubregions[ct] < blobFilteringParams_set.max_Subregions) {
							mask.at<uchar>(p.y, p.x) = 0;
					}

                }
				ct = ct + 1;
            }

		if (debug)
		{

			Mat fin_img;
			vector<Mat> channels;
			channels.push_back(r);
			channels.push_back(g);
			channels.push_back(b);
			merge(channels, fin_img);
			cv::Mat tempimg = fin_img.clone();
			cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
            //imshow("mser regions", tempimg);
            //waitKey(0);

			tempimg = mask.clone();
			cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
			//imshow("mser  mask", tempimg);
			//waitKey(0);
			tempimg = mask.clone();
			cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
        }

    src_mat_8U1= mask.clone();
//------------ Adaptive thresholding --------------------------------------
	// adaptive threshold tend to create rings from sollid blob object

  //  int minus_c = 5;//21
  //  int half_kernel_size = 20 * m_image_size_factor;    // express relative to a 640x480 pixels camera image

	 //   cv::adaptiveThreshold(src_mat_8U1, src_mat_8U1, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 2*half_kernel_size+1, minus_c);

  //  if (debug)
  //  {
  //      cv::Mat tempimg = src_mat_8U1.clone();
		//cv::resize(tempimg,tempimg,cv::Size(), rz, rz);
  //      cv::imshow("20 Adaptive thresholding", tempimg);
  //      cv::waitKey(0);
  //  }

//-------morph close----------------------------------------------------------

	int ker = static_cast<int>(round((src_mat_8U1.cols / 640.0) * 4));

	if (ker % 2 != 0 && ker >= 3) {
	} //If the number is an odd decimal.
	else if (ker % 2 == 0 && ker >= 3)
		ker = ker + 1; //Closest odd number is going to be above.
	else
		ker = 3; //3

	// Divide the image by its morphologically closed counterpart
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE,
			cv::Size(ker, ker)); //19
	cv::Mat closed;
	cv::morphologyEx(src_mat_8U1, src_mat_8U1, cv::MORPH_CLOSE, kernel);

	if (debug) {
		cv::Mat tempimg = src_mat_8U1.clone();
		cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
		//cv::imshow("10 filtering closed", tempimg);
		//cv::waitKey(0);
	}


	
//------------ Contour extraction --------------------------------------
    std::vector<std::vector<cv::Point> > contours1;
	std::vector<std::vector<cv::Point> > contours;
    cv::findContours(src_mat_8U1, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);


    if (debug)
    {
        cv::Mat contour_image = m_debug_img;
 
        for(size_t i = 0; i < contours.size(); i++)
            cv::drawContours(contour_image, contours, (int)i, cv::Scalar(0, 0, 255), 3, 8);
        cv::Mat tempimg = contour_image.clone();
		cv::resize(tempimg,tempimg,cv::Size(), rz, rz);
        //cv::imshow("30 Contours", tempimg);
        //cv::waitKey(0);
    }

	





// ------------ Ellipse extraction --------------------------------------
    int min_ellipse_size = static_cast<int>(ellipseFitParam_set.min_size); // Min ellipse size at 70cm distance is 20x20 pixels
    int max_ellipse_aspect_ratio = static_cast<int>(ellipseFitParam_set.max_aspect);//default 7 (good for high perspectives)
        
        
    std::vector<cv::RotatedRect> ellipses;
    for(size_t i = 0; i < contours.size(); i++)
    {
        size_t count = contours[i].size();
        if( count < 6 )
            continue;

        cv::Mat pointsf;
        cv::Mat(contours[i]).convertTo(pointsf, CV_32F);
        cv::RotatedRect box = cv::fitEllipse(pointsf);

        // Plausibility checks
        double box_max = std::max(box.size.width, box.size.height);
        double box_min = std::min(box.size.width, box.size.height);
        if( box_max > box_min*max_ellipse_aspect_ratio )
            continue;
        if (box_max > std::min(src_mat_8U1.rows, src_mat_8U1.cols)*0.2)
            continue;
        if (box_min < 0.5*min_ellipse_size)
            continue;
        if (box_max < min_ellipse_size)
            continue;
        if(box.center.x < 0 || box.center.x >= src_mat_8U1.cols || box.center.y < 0 || box.center.y >= src_mat_8U1.rows)
            continue;

        bool add_ellipse = true;

  
        // Check for double borders on circles and keep only larger ones
        for(unsigned int j = 0; j < ellipses.size(); j++)
        {
            double dist_thresh = box_min*0.1;
            double dist = std::abs(box.center.x - ellipses[j].center.x) + std::abs(box.center.y - ellipses[j].center.y);
            if (dist < dist_thresh)
            {
                add_ellipse = false;
                ellipses[j] = box;
                break;
            }
        }

        if (add_ellipse)
            ellipses.push_back(box);
    }

    //Fast Pi Tag
    std::vector<cv::Point2i> points;
    std::vector<cv::Rect> rois;
    cv::Mat ellipsevoting(src_mat_8U1.rows,src_mat_8U1.cols,CV_32FC1);
    cv::Mat ellipsedensity(src_mat_8U1.rows,src_mat_8U1.cols,CV_8UC1);


    if (debug)
    {
        cv::Mat ellipse_image = m_debug_img;
        for(unsigned int i = 0; i < ellipses.size(); i++)
        {
            cv::ellipse(ellipse_image, ellipses[i], cv::Scalar(0,255,0), Lsz, cv::LineTypes::LINE_AA);
            cv::ellipse(ellipse_image, ellipses[i].center, ellipses[i].size*0.5f, ellipses[i].angle, 0, 360, cv::Scalar(0,255,255), Lsz, cv::LineTypes::LINE_AA);
        }

       


        //Fast Pi Tag -ENd-
        cv::Mat tempimg = ellipse_image.clone();
		cv::resize(tempimg,tempimg,cv::Size(), rz, rz);
        //cv::imshow("40 Ellipses", tempimg);
        //cv::waitKey(0);
    }
        
        
    //PITAG: For PITAG the loop is executed only once with all ellipses in the cloud
    //FASTPITAG: For FASTPITAG the number of loop excecutions is based on the number of rois
    std::vector<cv::RotatedRect> ellipses_copy(ellipses);
    bool once = true;
        
    for(size_t n = 0; n < points.size() || (!m_use_fast_pi_tag && once); n++){ //Each point is the center of a roi
        once = false;


        // ------------ Fiducial corner extraction --------------------------------------
        std::vector<std::vector<cv::RotatedRect> > marker_lines;
        double max_pixel_dist_to_line; // Will be set automatically
        double max_ellipse_difference; // Will be set automatically
 
        // Compute area
        std::vector<double> ref_A;
        std::vector<double> ref_Ratio;
        for(unsigned int i = 0; i < ellipses.size(); i++)
            ref_A.push_back(std::max(ellipses[i].size.width, ellipses[i].size.height));
            
    

        for(unsigned int i = 0; i < ellipses.size(); i++)
        {
            for(unsigned int j = i+1; j < ellipses.size(); j++)
            {
                
                // Check area
                max_ellipse_difference = 0.5 * std::min(ref_A[i], ref_A[j]);
                if (std::abs(ref_A[i] - ref_A[j]) > max_ellipse_difference)
                    continue;

                // Compute line equation
                cv::Point2f vec_IJ = ellipses[j].center - ellipses[i].center;
                double dot_IJ_IJ = vec_IJ.ddot(vec_IJ);

                // Check all other ellipses if they fit to the line equation
                // Condition: Between two points are at most two other points
                // Not more and not less
                std::vector<cv::RotatedRect> line_candidate;
                int nLine_Candidates = 0;

                for(unsigned int k = 0; k < ellipses.size() && nLine_Candidates < 2; k++)
                {

                    // Check area
                    max_ellipse_difference = 0.5 * std::min(ref_A[j], ref_A[k]);
                    if (std::abs(ref_A[j] - ref_A[k]) > max_ellipse_difference)
                        continue;

                    if (k == i || k == j)
                        continue;

                    // Check if k lies on the line between i and j
                    cv::Point2f vec_IK = ellipses[k].center - ellipses[i].center;
                    double t_k = vec_IK.ddot(vec_IJ) / dot_IJ_IJ;
                    if (t_k < 0 || t_k > 1)
                        continue;

                    // Check distance to line
                    cv::Point2f proj_k = ellipses[i].center + vec_IJ * t_k;
                    cv::Point2f vec_KprojK = proj_k - ellipses[k].center;
                    double d_k_sqr = (vec_KprojK.x*vec_KprojK.x) + (vec_KprojK.y*vec_KprojK.y);

                    max_pixel_dist_to_line = std::sqrt(std::min(ellipses[k].size.height, ellipses[k].size.width));
                    max_pixel_dist_to_line = std::max(2.0, max_pixel_dist_to_line);
                    if (d_k_sqr > max_pixel_dist_to_line*max_pixel_dist_to_line)
                        continue;

                    for(unsigned int l = k+1; l < ellipses.size() && nLine_Candidates < 2; l++)
                    {
                            
                        // Check area
                        max_ellipse_difference = 0.5 * std::min(ref_A[k], ref_A[l]);
                        if (std::abs(ref_A[k] - ref_A[l]) > max_ellipse_difference)
                            continue;

                        if (l == i || l == j)
                            continue;

                        // Check if l lies on the line between i and j
                        cv::Point2f vec_IL = ellipses[l].center - ellipses[i].center;
                        double t_l = vec_IL.ddot(vec_IJ) / dot_IJ_IJ;
                        if (t_l < 0 || t_l > 1)
                            continue;

                        // Check distance to line
                        cv::Point2f proj_l = ellipses[i].center + vec_IJ * t_l;
                        cv::Point2f vec_LprojL = proj_l - ellipses[l].center;
                        double d_l_sqr = (vec_LprojL.x*vec_LprojL.x) + (vec_LprojL.y*vec_LprojL.y);

                        max_pixel_dist_to_line = std::sqrt(std::min(ellipses[l].size.height, ellipses[l].size.width));
                        max_pixel_dist_to_line = std::max(2.0, max_pixel_dist_to_line);
                        if (d_l_sqr > max_pixel_dist_to_line*max_pixel_dist_to_line)
                            continue;

                        // Yeah, we found 4 fitting points
                        line_candidate.push_back(ellipses[i]);
                        if (t_k < t_l)
                        {
                            line_candidate.push_back(ellipses[k]);
                            line_candidate.push_back(ellipses[l]);
                        }
                        else
                        {
                            line_candidate.push_back(ellipses[l]);
                            line_candidate.push_back(ellipses[k]);
                        }
                        line_candidate.push_back(ellipses[j]);
                        nLine_Candidates++;
                    }
                }

                // See condition above
                if(nLine_Candidates == 1)
                    marker_lines.push_back(line_candidate);
            }
        }

        if (debug)
        {
            //cv::Mat line_image = cv::Mat::zeros(src_mat_8U1.size(), CV_8UC3);
            cv::Mat line_image = m_debug_img.clone();
            for(unsigned int i = 0; i < marker_lines.size(); i++)
            {
                cv::line(line_image, marker_lines[i][0].center, marker_lines[i][3].center, cv::Scalar(0, 255, 255), Lsz, 8);
            }
      	    cv::Mat tempimg = line_image.clone();
			cv::resize(tempimg,tempimg,cv::Size(), rz, rz);
            //cv::imshow("Lines", tempimg);
            //cv::waitKey(0);
        }

        // ------------ Fiducial line association --------------------------------------
        double cross_ratio_max_dist = 0.03; //0.03
        std::vector<t_pi> final_tag_vec;

        for (unsigned int i = 0; i < m_ref_tag_vec.size(); i++)
        {
            m_ref_tag_vec[i].fitting_image_lines_0.clear();
            m_ref_tag_vec[i].fitting_image_lines_1.clear();
        }

        for(unsigned int i = 0; i < marker_lines.size(); i++)
        {
            // Cross ratio i
            cv::Point2f i_AB = marker_lines[i][1].center - marker_lines[i][0].center;
            cv::Point2f i_BD = marker_lines[i][3].center - marker_lines[i][1].center;
            cv::Point2f i_AC = marker_lines[i][2].center - marker_lines[i][0].center;
            cv::Point2f i_CD = marker_lines[i][3].center - marker_lines[i][2].center;
            double l_AB = std::sqrt(i_AB.x*i_AB.x + i_AB.y*i_AB.y);
            double l_BD = std::sqrt(i_BD.x*i_BD.x + i_BD.y*i_BD.y);
            double l_AC = std::sqrt(i_AC.x*i_AC.x + i_AC.y*i_AC.y);
            double l_CD = std::sqrt(i_CD.x*i_CD.x + i_CD.y*i_CD.y);
            double cross_ratio_i = (l_AB/l_BD)/(l_AC/l_CD);

            // Associate lines to markers based on their cross ratio
            for (unsigned int j = 0; j < m_ref_tag_vec.size(); j++)
            {
                if (std::abs(cross_ratio_i - m_ref_tag_vec[j].cross_ration_0) < cross_ratio_max_dist)
                    m_ref_tag_vec[j].fitting_image_lines_0.push_back(marker_lines[i]);
                else if (std::abs(cross_ratio_i - m_ref_tag_vec[j].cross_ration_1) < cross_ratio_max_dist)
                    m_ref_tag_vec[j].fitting_image_lines_1.push_back(marker_lines[i]);
            }
        }

        if (debug)
        {
            //cv::Mat line_image = cv::Mat::zeros(src_mat_8U1.size(), CV_8UC3);
            cv::Mat line_image = m_debug_img.clone();
            for (unsigned int j = 0; j < m_ref_tag_vec.size(); j++)
            {
                for(unsigned int i = 0; i < m_ref_tag_vec[j].fitting_image_lines_0.size(); i++)
                {
                    cv::line(line_image, m_ref_tag_vec[j].fitting_image_lines_0[i][0].center, m_ref_tag_vec[j].fitting_image_lines_0[i][3].center, cv::Scalar(255, 255, 0), Lsz, 8);
                }
                for(unsigned int i = 0; i < m_ref_tag_vec[j].fitting_image_lines_1.size(); i++)
                {
                    cv::line(line_image, m_ref_tag_vec[j].fitting_image_lines_1[i][0].center, m_ref_tag_vec[j].fitting_image_lines_1[i][3].center, cv::Scalar(255, 0, 255), Lsz, 8);
                }
            }
      	    cv::Mat tempimg = line_image.clone();
			cv::resize(tempimg,tempimg,cv::Size(), rz, rz);
            //cv::imshow("Valid Lines", tempimg);
            //cv::waitKey(0);
        }

        // Search for all tag types independently
        for(unsigned int i = 0; i < m_ref_tag_vec.size(); i++)
        {
            std::vector<t_pi> ul_tag_vec;
            std::vector<t_pi> lr_tag_vec;

            // Take into account that multi associations from one line to many others may occure
            std::vector<std::vector<int> >ul_idx_lines_0(
                    m_ref_tag_vec[i].fitting_image_lines_0.size(), std::vector<int>());
            std::vector<std::vector<int> >lr_idx_lines_1(
                    m_ref_tag_vec[i].fitting_image_lines_1.size(), std::vector<int>());


			std::vector<std::vector<unsigned int>> mem_ls0;
			std::vector<std::vector<unsigned int>> mem_ls1;
            // -----------------------UPPER LEFT ------------------------------------------------------
            // Check for a common upper left corner
            // cross_ratio = largest
            for(unsigned int j = 0; j < m_ref_tag_vec[i].fitting_image_lines_0.size(); j++)
            {
                for(unsigned int k = j+1; k < m_ref_tag_vec[i].fitting_image_lines_0.size(); k++)
                {
                    bool corners_are_matching = false;
                    bool reorder_j = false;
                    bool reorder_k = false;
                    if (m_ref_tag_vec[i].fitting_image_lines_0[j][0].center == m_ref_tag_vec[i].fitting_image_lines_0[k][0].center)
                    {
                        corners_are_matching = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][3].center == m_ref_tag_vec[i].fitting_image_lines_0[k][0].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;

                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][0].center == m_ref_tag_vec[i].fitting_image_lines_0[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_k = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][3].center == m_ref_tag_vec[i].fitting_image_lines_0[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;
                        reorder_k = true;
                    }

                    if (!corners_are_matching)
                        continue;

                    // Index 0 should corresponds to the common corner
                    if (reorder_j)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_0[j][3];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][3] = m_ref_tag_vec[i].fitting_image_lines_0[j][0];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_0[j][2];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][2] = m_ref_tag_vec[i].fitting_image_lines_0[j][1];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][1] = tmp;
                    }
                    if (reorder_k)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_0[k][3];
                        m_ref_tag_vec[i].fitting_image_lines_0[k][3] = m_ref_tag_vec[i].fitting_image_lines_0[k][0];
                        m_ref_tag_vec[i].fitting_image_lines_0[k][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_0[k][2];
                        m_ref_tag_vec[i].fitting_image_lines_0[k][2] = m_ref_tag_vec[i].fitting_image_lines_0[k][1];
                        m_ref_tag_vec[i].fitting_image_lines_0[k][1] = tmp;
                    }

                    // Compute angular ordering (clockwise)
                    cv::Point2f tag_corner0 = m_ref_tag_vec[i].fitting_image_lines_0[j][3].center;
                    cv::Point2f tag_corner1 = m_ref_tag_vec[i].fitting_image_lines_0[k][3].center;
                    cv::Point2f tag_cornerUL = m_ref_tag_vec[i].fitting_image_lines_0[j][0].center;
                    cv::Point2f tag_center = tag_corner1 + 0.5 * (tag_corner0 - tag_corner1);

                    cv::Point2f vec_center_cUL = tag_cornerUL - tag_center;
                    cv::Point2f vec_center_c0 = tag_corner0 - tag_center;
                    cv::Point2f vec_center_c1 = tag_corner1 - tag_center;

                    double sign_c0 = vec_center_cUL.x*vec_center_c0.y-vec_center_cUL.y*vec_center_c0.x;
                    double sign_c1 = vec_center_cUL.x*vec_center_c1.y-vec_center_cUL.y*vec_center_c1.x;
                    // One must be positive and the other negative
                    // Otherwise the two lines are collinear
                    if(sign_c0 * sign_c1 >= 0)
                        continue;

                    int idx0 = j;
                    int idx1 = k;
                    if (sign_c0 > 0)
                    {
                        idx0 = k;
                        idx1 = j;
                    }        

                    t_pi tag;
                    tag.image_points = std::vector<cv::RotatedRect>(12, cv::RotatedRect());
                    tag.image_points[0] = m_ref_tag_vec[i].fitting_image_lines_0[idx1][0];
                    tag.image_points[1] = m_ref_tag_vec[i].fitting_image_lines_0[idx1][1];
                    tag.image_points[2] = m_ref_tag_vec[i].fitting_image_lines_0[idx1][2];
                    tag.image_points[3] = m_ref_tag_vec[i].fitting_image_lines_0[idx1][3];

                    tag.image_points[9] = m_ref_tag_vec[i].fitting_image_lines_0[idx0][3];
                    tag.image_points[10] = m_ref_tag_vec[i].fitting_image_lines_0[idx0][2];
                    tag.image_points[11] = m_ref_tag_vec[i].fitting_image_lines_0[idx0][1];

                    ul_idx_lines_0[j].push_back(int(ul_tag_vec.size()));
                    ul_idx_lines_0[k].push_back(int(ul_tag_vec.size()));
                    ul_tag_vec.push_back(tag);
					mem_ls0.push_back({j,k});
                }
            }

            // -----------------------LOWER RIGHT ------------------------------------------------------
            // Check for a common lower right corner
            // cross_ratio = lowest
            for(unsigned int j = 0; j < m_ref_tag_vec[i].fitting_image_lines_1.size(); j++)
            {
                for(unsigned int k = j+1; k < m_ref_tag_vec[i].fitting_image_lines_1.size(); k++)
                {
                    bool corners_are_matching = false;
                    bool reorder_j = false;
                    bool reorder_k = false;
                    if (m_ref_tag_vec[i].fitting_image_lines_1[j][0].center == m_ref_tag_vec[i].fitting_image_lines_1[k][0].center)
                    {
                        corners_are_matching = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_1[j][3].center == m_ref_tag_vec[i].fitting_image_lines_1[k][0].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;

                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_1[j][0].center == m_ref_tag_vec[i].fitting_image_lines_1[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_k = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_1[j][3].center == m_ref_tag_vec[i].fitting_image_lines_1[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;
                        reorder_k = true;
                    }

                    if (!corners_are_matching)
                    {
                        continue;
                    }

                    // Index 0 should corresponds to the common corner
                    if (reorder_j)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_1[j][3];
                        m_ref_tag_vec[i].fitting_image_lines_1[j][3] = m_ref_tag_vec[i].fitting_image_lines_1[j][0];
                        m_ref_tag_vec[i].fitting_image_lines_1[j][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_1[j][2];
                        m_ref_tag_vec[i].fitting_image_lines_1[j][2] = m_ref_tag_vec[i].fitting_image_lines_1[j][1];
                        m_ref_tag_vec[i].fitting_image_lines_1[j][1] = tmp;
                    }
                    if (reorder_k)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_1[k][3];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][3] = m_ref_tag_vec[i].fitting_image_lines_1[k][0];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_1[k][2];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][2] = m_ref_tag_vec[i].fitting_image_lines_1[k][1];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][1] = tmp;
                    }

                    // Compute angular ordering (clockwise)
                    cv::Point2f tag_corner0 = m_ref_tag_vec[i].fitting_image_lines_1[j][3].center;
                    cv::Point2f tag_corner1 = m_ref_tag_vec[i].fitting_image_lines_1[k][3].center;
                    cv::Point2f tag_cornerUL = m_ref_tag_vec[i].fitting_image_lines_1[j][0].center;
                    cv::Point2f tag_center = tag_corner1 + 0.5 * (tag_corner0 - tag_corner1);

                    cv::Point2f vec_center_cUL = tag_cornerUL - tag_center;
                    cv::Point2f vec_center_c0 = tag_corner0 - tag_center;
                    cv::Point2f vec_center_c1 = tag_corner1 - tag_center;

                    // Angle from cUL to c0 is negative if sign is positive and vice versa
                    double sign_c0 = vec_center_cUL.x*vec_center_c0.y-vec_center_cUL.y*vec_center_c0.x;
                    double sign_c1 = vec_center_cUL.x*vec_center_c1.y-vec_center_cUL.y*vec_center_c1.x;
                    // One must be positive and the other negative
                    // Otherwise the two lines are collinear
                    if(sign_c0 * sign_c1 >= 0)
                        continue;

                    int idx0 = j;
                    int idx1 = k;
                    if (sign_c0 > 0)
                    {
                        idx0 = k;
                        idx1 = j;
                    }

                    t_pi tag;
                    tag.image_points = std::vector<cv::RotatedRect>(12, cv::RotatedRect());
                    tag.image_points[6] = m_ref_tag_vec[i].fitting_image_lines_1[idx1][0];
                    tag.image_points[7] = m_ref_tag_vec[i].fitting_image_lines_1[idx1][1];
                    tag.image_points[8] = m_ref_tag_vec[i].fitting_image_lines_1[idx1][2];
                    tag.image_points[9] = m_ref_tag_vec[i].fitting_image_lines_1[idx1][3];

                    tag.image_points[3] = m_ref_tag_vec[i].fitting_image_lines_1[idx0][3];
                    tag.image_points[4] = m_ref_tag_vec[i].fitting_image_lines_1[idx0][2];
                    tag.image_points[5] = m_ref_tag_vec[i].fitting_image_lines_1[idx0][1];

                    lr_idx_lines_1[j].push_back(int(lr_tag_vec.size()));
                    lr_idx_lines_1[k].push_back(int(lr_tag_vec.size()));
                    lr_tag_vec.push_back(tag);
					mem_ls1.push_back({ j,k });

                }
            }



            // -----------------------LOWER LEFT or UPPER RIGHT ------------------------------------------------------
            // Check for a common lower left or upper right corner
            // Now, lines could already participate in matchings of ul and lr corners
            // cross_ratio = different
     
			 //create and initialize a bool array
			 int sz = static_cast<int>(m_ref_tag_vec[i].fitting_image_lines_0.size());
			 std::vector<bool> addedLines0;
			 addedLines0.resize(sz);
			 std::fill(addedLines0.begin(), addedLines0.end(), false); // or false

			 sz = static_cast<int>(m_ref_tag_vec[i].fitting_image_lines_1.size());
			 std::vector<bool> addedLines1;
			 addedLines1.resize(sz);
			 std::fill(addedLines1.begin(), addedLines1.end(), false); // or false


            for(unsigned int j = 0; j < m_ref_tag_vec[i].fitting_image_lines_0.size(); j++)
            {
                for(unsigned int k = 0; k < m_ref_tag_vec[i].fitting_image_lines_1.size(); k++)
                {
                    bool corners_are_matching = false;
                    bool reorder_j = false;
                    bool reorder_k = false;
                    if (m_ref_tag_vec[i].fitting_image_lines_0[j][0].center == m_ref_tag_vec[i].fitting_image_lines_1[k][0].center)
                    {
                        corners_are_matching = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][3].center == m_ref_tag_vec[i].fitting_image_lines_1[k][0].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;

                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][0].center == m_ref_tag_vec[i].fitting_image_lines_1[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_k = true;
                    }
                    else if (m_ref_tag_vec[i].fitting_image_lines_0[j][3].center == m_ref_tag_vec[i].fitting_image_lines_1[k][3].center)
                    {
                        corners_are_matching = true;
                        reorder_j = true;
                        reorder_k = true;
                    }

					//if corners are not matching i.e neither LL nor UR is present. Then check if UL and LR exists that should be sent forward
                    if (!corners_are_matching)
                    {
						continue;
                    }


                    // Index 0 should corresponds to the common corner
                    if (reorder_j)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_0[j][3];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][3] = m_ref_tag_vec[i].fitting_image_lines_0[j][0];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_0[j][2];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][2] = m_ref_tag_vec[i].fitting_image_lines_0[j][1];
                        m_ref_tag_vec[i].fitting_image_lines_0[j][1] = tmp;
                    }
                    if (reorder_k)
                    {
                        cv::RotatedRect tmp = m_ref_tag_vec[i].fitting_image_lines_1[k][3];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][3] = m_ref_tag_vec[i].fitting_image_lines_1[k][0];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][0] = tmp;
                        tmp = m_ref_tag_vec[i].fitting_image_lines_1[k][2];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][2] = m_ref_tag_vec[i].fitting_image_lines_1[k][1];
                        m_ref_tag_vec[i].fitting_image_lines_1[k][1] = tmp;
                    }

                    // Compute angular ordering (clockwise)
                    cv::Point2f tag_corner0 = m_ref_tag_vec[i].fitting_image_lines_0[j][3].center;
                    cv::Point2f tag_corner1 = m_ref_tag_vec[i].fitting_image_lines_1[k][3].center;
                    cv::Point2f tag_cornerUL = m_ref_tag_vec[i].fitting_image_lines_0[j][0].center;
                    cv::Point2f tag_center = tag_corner1 + 0.5 * (tag_corner0 - tag_corner1);

                    cv::Point2f vec_center_cUL = tag_cornerUL - tag_center;
                    cv::Point2f vec_center_c0 = tag_corner0 - tag_center;
                    cv::Point2f vec_center_c1 = tag_corner1 - tag_center;

                    double sign_c0 = vec_center_cUL.x*vec_center_c0.y-vec_center_cUL.y*vec_center_c0.x;
                    double sign_c1 = vec_center_cUL.x*vec_center_c1.y-vec_center_cUL.y*vec_center_c1.x;
                    // One must be positive and the other negative
                    // Otherwise the two lines are collinear
                    if(sign_c0 * sign_c1 >= 0)
                        continue;

                    t_pi tag;
                    tag.image_points = std::vector<cv::RotatedRect>(12, cv::RotatedRect());

                    if (sign_c0 > 0)
                    {
                        // Lower left cornerfinal_tag_vec
                        tag.image_points = std::vector<cv::RotatedRect>(12, cv::RotatedRect());
                        tag.image_points[9] = m_ref_tag_vec[i].fitting_image_lines_0[j][0];
                        tag.image_points[10] = m_ref_tag_vec[i].fitting_image_lines_0[j][1];
                        tag.image_points[11] = m_ref_tag_vec[i].fitting_image_lines_0[j][2];
                        tag.image_points[0] = m_ref_tag_vec[i].fitting_image_lines_0[j][3];

                        tag.image_points[6] = m_ref_tag_vec[i].fitting_image_lines_1[k][3];
                        tag.image_points[7] = m_ref_tag_vec[i].fitting_image_lines_1[k][2];
                        tag.image_points[8] = m_ref_tag_vec[i].fitting_image_lines_1[k][1];

						//if the two lines dont agree by length ratio or angle discard combination
						if (!TagAngLenTest(tag, tagLenAngParams_set))
							continue;


                        // Check if lines participated already in a matching
                        if (ul_idx_lines_0[j].empty() && lr_idx_lines_1[k].empty())
                        {
                            if (TagUnique(final_tag_vec, tag))
                            {
                                m_ref_tag_vec[i].sparse_copy_to(tag);
                                tag.no_matching_lines = 2;
                                final_tag_vec.push_back(tag);
                            }
                        }
                        else if (!ul_idx_lines_0[j].empty() && lr_idx_lines_1[k].empty())
                        {
                            for (unsigned int l=0; l<ul_idx_lines_0[j].size(); l++)
                            {
                                t_pi final_tag;
                                final_tag.image_points = tag.image_points;

                                // Add matching line segment to final tag
								//put ratio and angle test for the line to be added
                                final_tag.image_points[1] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[1];
                                final_tag.image_points[2] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[2];
                                final_tag.image_points[3] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[3];

								////if the added line causes disagreement by length ratio or angle, revert to base combination
								if (!TagAngLenTest(final_tag, tagLenAngParams_set)) {
									final_tag.image_points = tag.image_points;
									final_tag.no_matching_lines = 2;
								}
								else
									final_tag.no_matching_lines = 3;

								if (!PtsNotUsed(final_tag_vec, final_tag))
									continue;

                                if (TagUnique(final_tag_vec, final_tag))
                                {
                                    m_ref_tag_vec[i].sparse_copy_to(final_tag);
									final_tag_vec.push_back(final_tag);
                                    addedLines0[j]=true;
                                }
                            }
                        }
                        else if (ul_idx_lines_0[j].empty() && !lr_idx_lines_1[k].empty())
                        {
                            for (unsigned int l=0; l<lr_idx_lines_1[k].size(); l++)
                            {
                                t_pi final_tag;
                                final_tag.image_points = tag.image_points;

                                // Add matching line segment to final tag
                                final_tag.image_points[3] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[3];
                                final_tag.image_points[4] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[4];
                                final_tag.image_points[5] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[5];

								//if the added line causes disagreement by length ratio or angle, revert to base combination
								if (!TagAngLenTest(final_tag, tagLenAngParams_set)) {
									final_tag.image_points = tag.image_points;
									final_tag.no_matching_lines = 2;
								}
								else
									final_tag.no_matching_lines = 3;

								if (!PtsNotUsed(final_tag_vec, final_tag))
									continue;

                                if (TagUnique(final_tag_vec, final_tag))
                                {
                                    m_ref_tag_vec[i].sparse_copy_to(final_tag);
                                    final_tag_vec.push_back(final_tag);
                                    addedLines1[k]=true;
                                }
                            }
                        }
                        else if (!ul_idx_lines_0[j].empty() && !lr_idx_lines_1[k].empty())
                        {
                            // YEAH buddy. You've got a complete matching
                            for (unsigned int l=0; l<ul_idx_lines_0[j].size(); l++)
                            {
                                for (unsigned int m=0; m<lr_idx_lines_1[k].size(); m++)
                                {
                                    t_pi final_tag;
                                    final_tag.image_points = tag.image_points;

                                    // Add matching line segment from ul to final tag
                                    final_tag.image_points[1] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[1];
                                    final_tag.image_points[2] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[2];
                                    final_tag.image_points[3] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[3];

                                    // Add matching line segment from lr to final tag
                                    final_tag.image_points[4] = lr_tag_vec[lr_idx_lines_1[k][m]].image_points[4];
                                    final_tag.image_points[5] = lr_tag_vec[lr_idx_lines_1[k][m]].image_points[5];
									
									if (!TagUnique(final_tag_vec, final_tag))
										continue;
									
									// Check consistency
									if (ul_tag_vec[ul_idx_lines_0[j][l]].image_points[3].center != lr_tag_vec[lr_idx_lines_1[k][m]].image_points[3].center ||
										ul_tag_vec[ul_idx_lines_0[j][l]].image_points[9].center != lr_tag_vec[lr_idx_lines_1[k][m]].image_points[9].center)
										continue;

									if (!AnglesValid2D(final_tag.image_points))
										continue;

									final_tag.no_matching_lines = 4;
									m_ref_tag_vec[i].sparse_copy_to(final_tag);
									final_tag_vec.push_back(final_tag);
									addedLines0[j] = true;
									addedLines1[k] = true;

                                }
                            }
                        } // End - else
                    } // END - Lower left corner
					else
					{
						// Upper right corner
						tag.image_points = std::vector<cv::RotatedRect>(12, cv::RotatedRect());
						tag.image_points[0] = m_ref_tag_vec[i].fitting_image_lines_0[j][3];
						tag.image_points[1] = m_ref_tag_vec[i].fitting_image_lines_0[j][2];
						tag.image_points[2] = m_ref_tag_vec[i].fitting_image_lines_0[j][1];
						tag.image_points[3] = m_ref_tag_vec[i].fitting_image_lines_0[j][0];

						tag.image_points[4] = m_ref_tag_vec[i].fitting_image_lines_1[k][1];
						tag.image_points[5] = m_ref_tag_vec[i].fitting_image_lines_1[k][2];
						tag.image_points[6] = m_ref_tag_vec[i].fitting_image_lines_1[k][3];

						//if the two lines dont agree by length ratio or angle discard combination
						if (!TagAngLenTest(tag, tagLenAngParams_set)) {
						continue;
						}

                        // Check if lines participated already in a matching
                        if (ul_idx_lines_0[j].empty() && lr_idx_lines_1[k].empty())
                        {
                            if (TagUnique(final_tag_vec, tag))
                            {
                                m_ref_tag_vec[i].sparse_copy_to(tag);
                                tag.no_matching_lines = 2;
                                final_tag_vec.push_back(tag);
                            }
                        }
                        else if (!ul_idx_lines_0[j].empty() && lr_idx_lines_1[k].empty())
                        {
                            for (unsigned int l=0; l<ul_idx_lines_0[j].size(); l++)
                            {
                                t_pi final_tag;
                                final_tag.image_points = tag.image_points;

                                // Add matching line segment to final tag
                                final_tag.image_points[9] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[9];
                                final_tag.image_points[10] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[10];
                                final_tag.image_points[11] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[11];

								//if the added line causes disagreement by length ratio or angle, revert to base combination
								if (!TagAngLenTest(final_tag, tagLenAngParams_set)) {
									final_tag.image_points = tag.image_points;
									final_tag.no_matching_lines = 2;
								}
								else
									final_tag.no_matching_lines = 3;

								if (!PtsNotUsed(final_tag_vec, final_tag))
									continue;

                                if (TagUnique(final_tag_vec, final_tag))
                                {
                                    m_ref_tag_vec[i].sparse_copy_to(final_tag);
                                    final_tag_vec.push_back(final_tag);
                                    addedLines0[j]=true;
                                }
                            }
                        }
                        else if (ul_idx_lines_0[j].empty() && !lr_idx_lines_1[k].empty())
                        {
                            for (unsigned int l=0; l<lr_idx_lines_1[k].size(); l++)
                            {
                                t_pi final_tag;
                                final_tag.image_points = tag.image_points;



                                // Add matching line segment to final tag
                                final_tag.image_points[7] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[7];
                                final_tag.image_points[8] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[8];
                                final_tag.image_points[9] = lr_tag_vec[lr_idx_lines_1[k][l]].image_points[9];

								//if the added line causes disagreement by length ratio or angle, revert to base combination
								if (!TagAngLenTest(final_tag, tagLenAngParams_set)) {
									final_tag.image_points = tag.image_points;
									final_tag.no_matching_lines = 2;
								}
								else
									final_tag.no_matching_lines = 3;

								if (!PtsNotUsed(final_tag_vec, final_tag))
									continue;

                                if (TagUnique(final_tag_vec, final_tag))
                                {
                                    m_ref_tag_vec[i].sparse_copy_to(final_tag);
                                    final_tag_vec.push_back(final_tag);
                                    addedLines1[k]=true;                                }
                            }
                        }
                        else if (!ul_idx_lines_0[j].empty() && !lr_idx_lines_1[k].empty())
                        {
                            // YEAH buddy. You've got a complete matching
                            for (unsigned int l=0; l<ul_idx_lines_0[j].size(); l++)
                            {
                                for (unsigned int m=0; m<lr_idx_lines_1[k].size(); m++)
                                {
                                    t_pi final_tag;
                                    final_tag.image_points = tag.image_points;

                                    // Add matching line segment from ul to final tag
                                    final_tag.image_points[9] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[9];
                                    final_tag.image_points[10] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[10];
                                    final_tag.image_points[11] = ul_tag_vec[ul_idx_lines_0[j][l]].image_points[11];

                                    // Add matching line segment from lr to final tag
                                    final_tag.image_points[7] = lr_tag_vec[lr_idx_lines_1[k][m]].image_points[7];
                                    final_tag.image_points[8] = lr_tag_vec[lr_idx_lines_1[k][m]].image_points[8];


                                    if (!TagUnique(final_tag_vec, final_tag))
                                        continue; 


									// Check consistency
									if (ul_tag_vec[ul_idx_lines_0[j][l]].image_points[3].center != lr_tag_vec[lr_idx_lines_1[k][m]].image_points[3].center ||
										ul_tag_vec[ul_idx_lines_0[j][l]].image_points[9].center != lr_tag_vec[lr_idx_lines_1[k][m]].image_points[9].center)
										continue;

									if (!AnglesValid2D(final_tag.image_points))
										continue;

									final_tag.no_matching_lines = 4;
									m_ref_tag_vec[i].sparse_copy_to(final_tag);
									final_tag_vec.push_back(final_tag);
									addedLines1[k] = true;
									addedLines0[j] = true;
                                }
                            }
                        } // End - else
                    } // END - Upper right corner
                }
            } // End - Check for a common lower left or upper right corner



            //--------------------------------------------------------------------------------------------------
            // Add Upper left and Lower Right pairs  as 2 linetags, if they exist, and have not been 
            // already assigned to the existing  Upper right and lower left cases
            //--------------------------------------------------------------------------------------------------

			unsigned int ind1; unsigned int ind2;
            if (ul_tag_vec.size()!=0 ) 
            {
                for(unsigned int j = 0; j < ul_tag_vec.size(); j++)
                {
					ind1 = mem_ls0[j][0];
					ind2 = mem_ls0[j][1];
                    if (addedLines0[ind1]==false && addedLines0[ind2]==false)
                    {
                        //printf("Entered UL, Size of LR: %ld \n",ul_tag_vec.size());
                        if (PtsNotUsed(final_tag_vec, ul_tag_vec[j]) && TagAngLenTest(ul_tag_vec[j], tagLenAngParams_set))
                        {   m_ref_tag_vec[i].sparse_copy_to(ul_tag_vec[j]);
                            ul_tag_vec[j].no_matching_lines = 2;
                            final_tag_vec.push_back(ul_tag_vec[j]);
							//printf("TAG USED at row:%d are L0:%d  and L0:%d\n", j, mem_ls0[j][0], mem_ls0[j][1]);
                        }
                    }

                }
            }

            if( lr_tag_vec.size()!=0  ) 
            {
                //printf("Entered LR\n");
                for(unsigned int k = 0; k < lr_tag_vec.size(); k++)
                {
					ind1 = mem_ls1[k][0];
					ind2 = mem_ls1[k][1];

                    if (addedLines1[ind1]==false && addedLines1[ind2]==false)
                    {
                       // printf("Entered LR, Size of LR: %ld \n",lr_tag_vec.size());
                        if (PtsNotUsed(final_tag_vec, lr_tag_vec[k]) && TagAngLenTest(lr_tag_vec[k], tagLenAngParams_set))
                        {   
                            m_ref_tag_vec[i].sparse_copy_to(lr_tag_vec[k]);
                            lr_tag_vec[k].no_matching_lines = 2;
                            final_tag_vec.push_back(lr_tag_vec[k]);  
                            //printf("the entereed array size is: %f \n",lr_tag_vec[0].image_points[0]);
							//printf("TAG USED at row:%d are L1:%d  and L1:%d\n", k, mem_ls1[k][0], mem_ls1[k][1]);

                         
                        }
                    }

                }

            }
            
/*          printf("fitting_image_lines_0 %ld \n",m_ref_tag_vec[i].fitting_image_lines_0.size());
            printf("fitting_image_lines_1 %ld \n",m_ref_tag_vec[i].fitting_image_lines_1.size());
            printf("ul tags %ld \n",ul_tag_vec.size());
            printf("lr tags%ld \n",lr_tag_vec.size());*/ 
                     

        } // End - Search for all tag types independently
        



        // ------------ Refine ellipses ------------------------------------
		/*if (refine)
		{
			int min_matching_lines = 2;

			int sobel_winsize = 3;
			float gauss_smooth_sigma = 3.0;

			if (sobel_winsize % 2 == 0)
			{
				sobel_winsize++;
				std::cerr << " Sobel winsize changed to " << sobel_winsize << " (must be odd)" << std::endl;
			}

			// Sobel
			cv::Mat input_image_smooth;
			if (gauss_smooth_sigma > 0.0f)
			{
				cv::GaussianBlur(grayscale_image, input_image_smooth, cv::Size(), gauss_smooth_sigma, gauss_smooth_sigma);
			}
			else
			{
				input_image_smooth = grayscale_image.clone();
			}
			cv::Mat gradient_x(input_image_smooth.rows, input_image_smooth.cols, CV_16S);
			cv::Mat gradient_y(input_image_smooth.rows, input_image_smooth.cols, CV_16S);
			cv::Sobel(input_image_smooth, gradient_x, CV_16S, 1, 0, sobel_winsize);
			cv::Sobel(input_image_smooth, gradient_y, CV_16S, 0, 1, sobel_winsize);



			cv::Mat refine_image = image.clone();

			for (unsigned int i = 0; i < final_tag_vec.size(); i++)
			{
				if (final_tag_vec[i].no_matching_lines < min_matching_lines)
					continue;

				for (unsigned int j = 0; j < final_tag_vec[i].image_points.size(); j++)
				{
					cv::Matx33d refined_ellipse;

					if (cv::runetag::ipa_Fiducials::ellipserefine(final_tag_vec[i].image_points[j], gradient_x, gradient_y, refined_ellipse))
					{
						cv::Point2d ellipse_center = cv::runetag::ipa_Fiducials::ellipseCenter(refined_ellipse);
						cv::circle(refine_image, final_tag_vec[i].image_points[j].center, Lsz, CV_RGB(0, 255, 0), 5);
						cv::circle(refine_image, ellipse_center, Lsz, CV_RGB(0, 0, 255), 5);

						final_tag_vec[i].image_points[j].center.x = static_cast<float>(ellipse_center.x);
						final_tag_vec[i].image_points[j].center.y = static_cast<float>(ellipse_center.y);
					}
					else
					{
						//std::cerr << "Ellipse refine failed" << std::endl;
					}
				}
			}

			if (debug)
			{
				cv::Mat tempimg = refine_image.clone();
				cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
				//cv::imshow("refined ellipses", tempimg);
				//cv::waitKey(0);
			}

		}*/
        
        //printf("tag size %ld \n" ,final_tag_vec.size());


        int numTag = static_cast<int>(final_tag_vec.size());
        //printf("tag size>> %d  \n" ,numTag);

		//create and initialize a bool array
		std::vector<bool> invalididx;
		invalididx.resize(numTag);
		std::fill(invalididx.begin(), invalididx.end(), false); // or false



		//Final verification of tags and pushing them to output 
		bool Valid;
		for (int i = 0; i < numTag; i++)
		{

			Valid = false;
			t_points tag_points;
			tag_points.id = final_tag_vec[i].parameters.m_id;
			tag_points.marker_points = std::vector<cv::Point2f>();
			tag_points.image_points = std::vector<cv::Point2f>();

			//test by lengths and angles
			Valid = TagAngLenTest(final_tag_vec[i], tagLenAngParams_set);

			//removes if the tag share points with atleast 2 other tagsFunction return true if tag intrudes other tags
			Valid = (!TagIntrusionTest(final_tag_vec,final_tag_vec[i]));


			// set removal
			if (Valid == false)
			{
				invalididx[i] = true;
				//printf("Tag Rejected by angle or ratio contraints \n");
				continue;
			}

			for (unsigned int j = 0; j < final_tag_vec[i].image_points.size(); j++)
			{

				tag_points.marker_points.push_back(final_tag_vec[i].marker_points[j]);
				tag_points.image_points.push_back(final_tag_vec[i].image_points[j].center);
			}

			vec_points.push_back(tag_points);

		}

			   		 	          


     
        // plot detected tags and skip the invalid as before using continue
        if (drawOutput)
        {
            cv::Mat tag_image = image.clone();
            cv::Vec3b rgbValVec[] = {cv::Vec3b(0,0,0), cv::Vec3b(255,255,255),
                    cv::Vec3b(255,0,0), cv::Vec3b(0,255,255), cv::Vec3b(0,255,0)};
            for (unsigned int i=0; i<final_tag_vec.size(); i++)
            {
				//if (final_tag_vec[i].no_matching_lines !=4)
                if (final_tag_vec[i].no_matching_lines <2 || final_tag_vec[i].no_matching_lines >4 || invalididx[i]==true )
					continue;


                bool connect_points = false;
                for (unsigned int j=0; j<final_tag_vec[i].image_points.size(); j++)
                {
                    cv::Vec3b rgbVal = rgbValVec[final_tag_vec[i].no_matching_lines];
                    if (final_tag_vec[i].image_points[j].center.x != 0)
                    {
                        cv::circle(tag_image, final_tag_vec[i].image_points[j].center, Lsz, cv::Scalar(0,255,0), -1, cv::LineTypes::LINE_AA);
                        if (connect_points)
                        {
                            cv::line(tag_image, final_tag_vec[i].image_points[j-1].center, final_tag_vec[i].image_points[j].center, cv::Scalar(rgbVal[0], rgbVal[1], rgbVal[2]), Lsz, cv::LineTypes::LINE_AA);
							if (j==11)
								cv::line(tag_image, final_tag_vec[i].image_points[j].center, final_tag_vec[i].image_points[0].center, cv::Scalar(rgbVal[0], rgbVal[1], rgbVal[2]), Lsz, cv::LineTypes::LINE_AA);


                        }
                        connect_points = true;
                    }
                    else
                        connect_points = false;
                }
            }
			
			
	
				cv::Mat tempimg = tag_image.clone();
				cv::resize(tempimg, tempimg, cv::Size(), rz, rz);
				//cv::imshow("Tags", tempimg);
				//cv::waitKey(0.1);
				//cv::imwrite("detectdTag.jpg", tag_image);
			
				//destroyAllWindows();
				
			

        }

		//measuring time at the end of file
		//printf("Time by EOF %d \n", duration_cast<milliseconds>(end2 - start));
		//printf("No of Tags: %d \n", vec_points.size()); 











    }

// ------------ END --------------------------------------
        
    if (debug)
    {
       // cv::waitKey();
    }

    if (vec_points.empty())
            return RET_FAILED;

    return RET_OK;
}
























/*
unsigned long FiducialModelPi::GetPose(cv::Mat& image, std::vector<t_pose>& vec_pose, std::string parameter_directory_and_filename)
{
    std::vector<t_points> vec_points;
    //if (GetPoints(image, vec_points, parameter_directory_and_filename) != RET_OK)
    //    return RET_FAILED;s
    
    // ------------ Compute pose --------------------------------------
    
    for (unsigned int i=0; i<vec_points.size(); i++)
    {
        int nPoints = 0;
        for (unsigned int j=0; j<vec_points[i].image_points.size(); j++)
            if (vec_points[i].image_points[j].x != 0)
                nPoints++;

        cv::Mat pattern_coords(nPoints, 3, CV_32F);
        cv::Mat image_coords(nPoints, 2, CV_32F);

        float* p_pattern_coords = 0;
        float* p_image_coords = 0;
        int idx = 0;
        for (unsigned int j=0; j<vec_points[i].image_points.size(); j++)
        {
            if (vec_points[i].image_points[j].x != 0)
            {
                p_pattern_coords = pattern_coords.ptr<float>(idx);
                p_pattern_coords[0] = vec_points[i].marker_points[j].x;
                p_pattern_coords[1] = vec_points[i].marker_points[j].y;
                p_pattern_coords[2] = 0;

                p_image_coords = image_coords.ptr<float>(idx);
                p_image_coords[0] = vec_points[i].image_points[j].x;
                p_image_coords[1] = vec_points[i].image_points[j].y;

                idx++;
            }
        }

        t_pose tag_pose;
        tag_pose.id = vec_points[i].id;
        cv::solvePnP(pattern_coords, image_coords, GetCameraMatrix(), GetDistortionCoeffs(), tag_pose.rot, tag_pose.trans);

        // Apply transformation
        cv::Mat rot_3x3_CfromO;
        cv::Rodrigues(tag_pose.rot, rot_3x3_CfromO);

        cv::Mat reprojection_matrix = GetCameraMatrix();
        if (!ProjectionValid(rot_3x3_CfromO, tag_pose.trans, reprojection_matrix, pattern_coords, image_coords))
            continue;

        ApplyExtrinsics(rot_3x3_CfromO, tag_pose.trans);
        rot_3x3_CfromO.copyTo(tag_pose.rot);
        vec_pose.push_back(tag_pose);
    }
    

    if (vec_points.empty())
        return RET_FAILED;

    return RET_OK;
}
*/

bool FiducialModelPi::AnglesValid2D(std::vector<cv::RotatedRect>& image_points)
{
    // Check angles
    //float max_symtry_deg_diff = 40;
    float min_deg_angle = 20.f;
    cv::Point2f vec_03 = image_points[3].center - image_points[0].center;
    cv::Point2f vec_36 = image_points[6].center - image_points[3].center;
    cv::Point2f vec_69 = image_points[9].center - image_points[6].center;
    cv::Point2f vec_90 = image_points[0].center - image_points[9].center;

    float size_vec_03 = std::sqrt(vec_03.x*vec_03.x + vec_03.y*vec_03.y);
    float size_vec_36 = std::sqrt(vec_36.x*vec_36.x + vec_36.y*vec_36.y);
    float size_vec_69 = std::sqrt(vec_69.x*vec_69.x + vec_69.y*vec_69.y);
    float size_vec_90 = std::sqrt(vec_90.x*vec_90.x + vec_90.y*vec_90.y);

    vec_03.x /= size_vec_03;
    vec_03.y /= size_vec_03;
    vec_36.x /= size_vec_36;
    vec_36.y /= size_vec_36;
    vec_69.x /= size_vec_69;
    vec_69.y /= size_vec_69;
    vec_90.x /= size_vec_90;
    vec_90.y /= size_vec_90;
    
    constexpr float pi = static_cast<float>(CV_PI);

    float angle_ur = std::acos((-vec_03.x)*vec_36.x+(-vec_03.y)*vec_36.y)*180.f/pi;
    float angle_lr = std::acos((-vec_36.x)*vec_69.x+(-vec_36.y)*vec_69.y)*180.f/pi;
    float angle_ll = std::acos((-vec_69.x)*vec_90.x+(-vec_69.y)*vec_90.y)*180.f/pi;
    float angle_ul = std::acos((-vec_90.x)*vec_03.x+(-vec_90.y)*vec_03.y)*180.f/pi;

    //if (std::abs(angle_ur-angle_ll) > max_symtry_deg_diff ||
    //        std::abs(angle_ul-angle_lr) > max_symtry_deg_diff)
    //        return false;

    if (std::abs(angle_ur) < min_deg_angle ||
        std::abs(angle_lr) < min_deg_angle ||
        std::abs(angle_ll) < min_deg_angle ||
        std::abs(angle_ul) < min_deg_angle)
        return false;

    return true;
}

bool FiducialModelPi::ProjectionValid(cv::Mat& rot_CfromO, cv::Mat& trans_CfromO,
        cv::Mat& camera_matrix, cv::Mat& pts_in_O, cv::Mat& image_coords)
{
    double max_avg_pixel_error = 5 * m_image_size_factor;   // express relative to a 640x480 pixels camera image;

    // Check angles
    float* p_pts_in_O = 0;
    double* p_pt_in_O = 0;
    double* p_pt_4x1_in_C = 0;
    double* p_pt_3x1_in_C = 0;
    double* p_pt_3x1_2D = 0;
    float* p_image_coords;

    cv::Mat pt_in_O(4, 1, CV_64FC1);
    p_pt_in_O = pt_in_O.ptr<double>(0);
    cv::Mat pt_4x1_in_C;
    cv::Mat pt_3x1_in_C(3, 1, CV_64FC1);
    p_pt_3x1_in_C = pt_3x1_in_C.ptr<double>(0);
    cv::Mat pt_3x1_2D(3, 1, CV_64FC1);
    p_pt_3x1_2D = pt_3x1_2D.ptr<double>(0);

    // Create 4x4 frame CfromO
    cv::Mat frame_CfromO = cv::Mat::zeros(4, 4, CV_64FC1);
    for (int i=0; i<3; i++)
    {
        frame_CfromO.at<double>(i, 3) = trans_CfromO.at<double>(i,0);
        for (int j=0; j<3; j++)
        {
            frame_CfromO.at<double>(i,j) = rot_CfromO.at<double>(i,j);
        }
    }
    frame_CfromO.at<double>(3,3) = 1.0;

    // Check reprojection error
    double dist = 0;
    for (int i=0; i<pts_in_O.rows; i++)
    {
        p_image_coords = image_coords.ptr<float>(i);
        p_pts_in_O = pts_in_O.ptr<float>(i);

        p_pt_in_O[0] = p_pts_in_O[0];
        p_pt_in_O[1] = p_pts_in_O[1];
        p_pt_in_O[2] = p_pts_in_O[2];
        p_pt_in_O[3] = 1;

        cv::Mat pt_4x1_in_C2 = frame_CfromO * pt_in_O;
        p_pt_4x1_in_C = pt_4x1_in_C2.ptr<double>(0);
        p_pt_3x1_in_C[0] = p_pt_4x1_in_C[0]/p_pt_4x1_in_C[3];
        p_pt_3x1_in_C[1] = p_pt_4x1_in_C[1]/p_pt_4x1_in_C[3];
        p_pt_3x1_in_C[2] = p_pt_4x1_in_C[2]/p_pt_4x1_in_C[3];

        pt_3x1_2D = camera_matrix * pt_3x1_in_C;
        pt_3x1_2D /= p_pt_3x1_2D[2];

        dist = std::sqrt((p_pt_3x1_2D[0] - p_image_coords[0])*(p_pt_3x1_2D[0] - p_image_coords[0])
        + (p_pt_3x1_2D[1] - p_image_coords[1])*(p_pt_3x1_2D[1] - p_image_coords[1]));

        if (dist > max_avg_pixel_error)
            return false;
    }

    return true;
}
bool FiducialModelPi::TagUnique(std::vector<t_pi>& tag_vec, t_pi& newTag)
{
    // Insert if not already existing
    bool duplicate = true;        
    for (unsigned int i=0; i<tag_vec.size(); i++)
    {
        duplicate = true;
        for (int j=0; j<12; j++)
        {
            if (tag_vec[i].image_points[j].center !=
                newTag.image_points[j].center)
            {
                duplicate = false;
                break;
            }
        }
        if (duplicate)
            return false;
    }
    return true;
}


bool FiducialModelPi::PtsNotUsed(std::vector<t_pi>& tag_vec, t_pi& newtag)
{
	// check if individual points have been re used in any other 
	for (unsigned int i = 0; i < tag_vec.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < 12; j++)
		{
			if (newtag.image_points[j].center != Point2f(0)) // discard initialized values
			{			
				for (int k = 0; k < 12; k++)
				{
					if (newtag.image_points[j].center == tag_vec[i].image_points[k].center)
						count++;

				}
			}

		if (count > 2)
			return false;
		}
		
	}
	return true;
}

//if tags intrudes into othr tags the output is true
bool FiducialModelPi::TagIntrusionTest(std::vector<t_pi>& tag_vec, t_pi& newtag)
{
	bool intrusion = false;
	int count = 0;
	// check if individual points have been re used between tags. Usage  in a tag is counted as once only
	for (unsigned int i = 0; i < tag_vec.size(); i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (newtag.image_points[j].center != Point2f(0)) // discard initialized values
			{
				for (int k = 0; k < 12; k++)
				{
					if (newtag.image_points[j].center == tag_vec[i].image_points[k].center)
					{
						intrusion = true;
						break;
					}
				}
				if (intrusion == true)
					break;
			}
		}

		if (intrusion==true)
		{	count++;
			intrusion = false;
		}
		if (count > 3)//2 because ,one from itsel,the other from outside intruder,3rd could be set as a margin
			return true;

	}
	return false;
}


bool FiducialModelPi::TagAngLenTest(t_pi& newtag, const tagLenAngParams& tagLenAngParams_set)
{		
	
	// MAIN FILTERING
		float minAng = tagLenAngParams_set.minAng;//40 try lower with  sharp perspectives
		float maxAng = tagLenAngParams_set.maxAng;//130

		float minRatio = tagLenAngParams_set.minRatio;//not lower than 0.25
		float maxRatio = tagLenAngParams_set.maxRatio;//notlower than 2
		int corID[5] = { 0, 3, 6, 9, 0 };// setting th indices of corners
		unsigned int ct = 0; 
		float dif_L[4];
		float slopes[4] = { 500,500,500,500 };//dummy value

		for (unsigned int q = 0; q < 4; q++)
		{
			//lines raito to eachother should not be abnormal
			unsigned int id1 = corID[q]; unsigned int id2 = corID[q + 1];
			if (newtag.image_points[id1].center.x != 0 && newtag.image_points[id2].center.x != 0)
			{
				dif_L[ct] = static_cast<float>(sqrt(pow(newtag.image_points[id2].center.x - newtag.image_points[id1].center.x, 2) +
					pow(newtag.image_points[id2].center.y - newtag.image_points[id1].center.y, 2)));
				slopes[q] = (newtag.image_points[id2].center.y - newtag.image_points[id1].center.y) /
					(newtag.image_points[id2].center.x - newtag.image_points[id1].center.x);
				//printf("The dif is %f for id %d-%d  at ct:%d \n",dif_L[ct],(id1),id2,ct);
				ct = ct + 1;
			}
		}


		// get line ratios and remove marker with  lines with insane ratioto the first line
		bool inValid = false;
		for (unsigned int q = 0; q < ct; q++)
		{
			for (unsigned int r = 0; r < ct; r++)
			{
				// printf("it: %d, d1:%f   d2:%f  ratios:%f \n",q,dif_L[0],dif_L[q],((dif_L[q]/dif_L[0]) ));
				if (dif_L[q] / dif_L[r] > maxRatio || (dif_L[q] / dif_L[r]) < minRatio) // 1.75 nad 0.35
				{
					inValid = true;
					break;
				}
			}

		}

		// get angles from slopes and remove markers with neighbouring angles less than threshold e.g 45
		int ord[5] = { 0,1,2,3,0 }; float ang;
		for (unsigned int q = 0; q < 4; q++)
		{

			if (slopes[ord[q]] != 500 && slopes[ord[q + 1]] != 500) // if the pair is not equal to dummy values, then use for computation
			{
				ang = atan((slopes[ord[q + 1]] - slopes[ord[q]]) / (1 + (slopes[ord[q + 1]] * slopes[ord[q]])))*(180.f / 3.1458f);
				if (abs(ang) < minAng || abs(ang) > maxAng)
				{
					inValid = true;
				}
				else
				{
					//printf("m1: %f m2:%f and angles: %f \n", slopes[ord[q]], slopes[ord[q + 1]], ang);

				}
			}
		}


		if (inValid)
			return false;
		else
			return true;

}// enf of function


//-----------------------------------------------------------------------------------------------------













unsigned long FiducialModelPi::LoadParameters(std::vector<FiducialPiParameters> pi_tags)
{
        m_ref_tag_vec.clear();
        for(unsigned int i=0; i<pi_tags.size(); i++)
        {
                t_pi ref_tag;
                double tag_size = pi_tags[i].line_width_height;

                ref_tag.parameters = pi_tags[i];

                double d_line0_AB = tag_size * pi_tags[i].d_line0_AB; //AB
                double d_line0_BD = tag_size - tag_size * pi_tags[i].d_line0_AB; //BD
                double d_line0_AC = tag_size * pi_tags[i].d_line0_AC;//AC
                double d_line0_CD = tag_size - tag_size * pi_tags[i].d_line0_AC;//CD
                ref_tag.cross_ration_0 = (d_line0_AB/d_line0_BD)/(d_line0_AC/d_line0_CD);

                double d_line1_AB = tag_size * pi_tags[i].d_line1_AB;
                double d_line1_BD = tag_size - tag_size * pi_tags[i].d_line1_AB;
                double d_line1_AC = tag_size * pi_tags[i].d_line1_AC;
                double d_line1_CD = tag_size - tag_size * pi_tags[i].d_line1_AC;
                ref_tag.cross_ration_1 = (d_line1_AB/d_line1_BD)/(d_line1_AC/d_line1_CD);
        
                // Marker coordinates
                ref_tag.marker_points.push_back(cv::Point2f(0, -0));
                ref_tag.marker_points.push_back(cv::Point2f(float(d_line0_AB), -0));
                ref_tag.marker_points.push_back(cv::Point2f(float(d_line0_AC), -0));
                ref_tag.marker_points.push_back(cv::Point2f(float(tag_size), -0));
                ref_tag.marker_points.push_back(cv::Point2f(float(tag_size), -float(d_line1_AB)));
                ref_tag.marker_points.push_back(cv::Point2f(float(tag_size), -float(d_line1_AC)));
                ref_tag.marker_points.push_back(cv::Point2f(float(tag_size), -float(tag_size)));
                ref_tag.marker_points.push_back(cv::Point2f(float(d_line1_AC), -float(tag_size)));
                ref_tag.marker_points.push_back(cv::Point2f(float(d_line1_AB), -float(tag_size)));
                ref_tag.marker_points.push_back(cv::Point2f(0, -float(tag_size)));
                ref_tag.marker_points.push_back(cv::Point2f(0, -float(d_line0_AC)));
                ref_tag.marker_points.push_back(cv::Point2f(0, -float(d_line0_AB)));

                // Offset
                for(unsigned int j=0; j<ref_tag.marker_points.size(); j++)
                {
                        ref_tag.marker_points[j].x += static_cast<float>(pi_tags[i].m_offset.x);
                        ref_tag.marker_points[j].y += static_cast<float>(pi_tags[i].m_offset.y);
                }

                double delta = ref_tag.cross_ration_0/ref_tag.cross_ration_1;
                if(std::abs(delta - 1) < 0.05)
                {
                        //std::cerr << "[WARNING] FiducialModelPi::LoadCoordinates" << std::endl;
                        //std::cerr << "\t ... Skipping fiducial due to equal cross ratios" << std::endl;
                }
                else if (delta < 1)
                {
                        //std::cerr << "[WARNING] FiducialModelPi::LoadCoordinates" << std::endl;
                        //std::cerr << "\t ... Skipping fiducial "<< ref_tag.parameters.m_id <<" due to cross ratios" << std::endl;
                        //std::cerr << "\t ... Cross ratio 0 must be larger than cross ratio 1" << std::endl;
                }
                else
                {
                        m_ref_tag_vec.push_back(ref_tag);
                }

                if (m_ref_tag_vec.empty())
                {
                        //std::cerr << "[ERROR] FiducialModelPi::LoadCoordinates" << std::endl;
                        //std::cerr << "\t ... No valid fiducials loaded" << std::endl;
                        return RET_FAILED;
                }
        }
        return RET_OK;
}


unsigned long FiducialModelPi::LoadParametersJSON(std::string directory_and_filename)
{
	std::vector<FiducialPiParameters> vec_pi_parameters;
	FiducialPiParameters pi_parameters;
	bool fpitag_default = 0;
	m_use_fast_pi_tag = fpitag_default;


	// -----Reading the PI models -----------------
	FileStorage fs2(directory_and_filename, FileStorage::MEMORY);
	// first method: use (type) operator on FileNode.
	FileNode models = fs2["PI"];
	FileNodeIterator it = models.begin(), it_end = models.end();
	int idx = 0;


	// iterate through a models using FileNodeIterator
	for (; it != it_end; ++it, idx++)
	{
		// you can also easily read numerical arrays using FileNode >> std::vector operator.
		(*it)["ID"] >> pi_parameters.m_id;
		(*it)["CrossRatioLine0AB"] >> pi_parameters.d_line0_AB;// CrossRatioLine0AB;
		(*it)["CrossRatioLine0AC"] >> pi_parameters.d_line0_AC;//  CrossRatioLine0AC;
		(*it)["CrossRatioLine1AB"] >> pi_parameters.d_line1_AB;
		(*it)["CrossRatioLine1AC"] >> pi_parameters.d_line1_AC;
		pi_parameters.line_width_height=1;
		pi_parameters.m_offset.x=0;
		pi_parameters.m_offset.y=0;
		m_general_fiducial_parameters[pi_parameters.m_id].m_sharpness_pattern_area_rect3d.x = 0;
		m_general_fiducial_parameters[pi_parameters.m_id].m_sharpness_pattern_area_rect3d.y = 0;
		m_general_fiducial_parameters[pi_parameters.m_id].m_sharpness_pattern_area_rect3d.width = 0;
		m_general_fiducial_parameters[pi_parameters.m_id].m_sharpness_pattern_area_rect3d.height = 0;

		m_general_fiducial_parameters[pi_parameters.m_id].m_offset = pi_parameters.m_offset;
		vec_pi_parameters.push_back(pi_parameters);

	}
	fs2.release();
	/*
	if (vec_pi_parameters.empty())
	{
		std::cerr << "ERROR - FiducialModelPi::LoadParameters:" << std::endl;
		std::cerr << "\t ... Could't find tag 'PI'" << std::endl;
		return RET_FAILED;
	}
	

	if (LoadParameters(vec_pi_parameters) & RET_FAILED)
	{
		std::cerr << "ERROR - FiducialModelPi::LoadParameters:" << std::endl;
		std::cerr << "\t ... Couldn't set tag parameters'" << std::endl;
		return RET_FAILED;
	}
	*/
	return LoadParameters(vec_pi_parameters);




}








unsigned long FiducialModelPi::LoadProcessingParametersJSON(std::string directory_and_filename, blobDetectParams &Param_blob, blobFilteringParams &Param_filt, ellipseFitParams &Param_ellip, tagLenAngParams &Param_LenAng)
{

	// -------Reading the PI models------------ 
	FileStorage fs3(directory_and_filename, FileStorage::MEMORY);

	// Reading Blob_det.
	FileNode params1 = fs3["Blob_det"];
	params1["delta"] >> Param_blob.delta;
	params1["min_area_pixel"] >> Param_blob.min_area_px;
	params1["max_area_percentage"] >> Param_blob.max_area_per;
	params1["max_variation"] >> Param_blob.max_var;

	//Reading Blob_filter.
	FileNode params2 = fs3["Blob_filter"];
	params2["min_aspect_ratio"] >> Param_filt.min_aspect;
	params2["max_aspect_ratio"] >> Param_filt.max_aspect;
	params2["solidity"] >> Param_filt.solidity;
	params2["min_extent"] >> Param_filt.min_ext;
	params2["max_extent"] >> Param_filt.max_ext;
	params2["max_Subregions"] >> Param_filt.max_Subregions;

	// Reading ellipse_fit.
	FileNode params3 = fs3["ellipse_fit"];
	params3["min_size"] >> Param_ellip.min_size;
	params3["max_aspect_ratio"] >> Param_ellip.max_aspect;

	// Reading TaglenAng.
	FileNode params4 = fs3["TaglenAng"];
	params4["minAng"] >> Param_LenAng.minAng;
	params4["maxAng"] >> Param_LenAng.maxAng;
	params4["minRatio"] >> Param_LenAng.minRatio;
	params4["maxRatio"] >> Param_LenAng.maxRatio;

	fs3.release();

	return RET_OK;


}


