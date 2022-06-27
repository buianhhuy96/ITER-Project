#include "pitagDetector.h"

/**************************************************************************
-Function: pitagDetector
-Type: Internal Function
-Inputs:
const coder::array<uint8_T, 4U> gray_image	    - image of the target to be localized.
std::string constellation 					    - JSON encoded definition of the constellation which
												 is to be localized.
std::string algorithmParams		   				- JSON encoded parameters needed by the algorithm.

-Outputs:
std::vector<ipa_Fiducials::t_points> vec_points - location of the target markers in pixel coordinates (u, v).
int err											- error flag.

-Functionality:
Detects the marker constellation.

-Error cases and handling:
(Refer to errors in error-list document)

-Dependencies:
Fiducial library (author Jan Fischer with update from Ihtisham).
**/
void estimatePose_ns::pitagDetector(const coder::array<uint8_T, 4U> &gray_image,
		const std::string &constellation,
		const algorithmParameters &algorithmParams,

		std::vector<ipa_Fiducials::t_points> &vec_points, int *err) {

	// Convert image to openCV class
	int height = gray_image.size(0);
	int width = gray_image.size(1);
	cv::Mat image(height, width, CV_8UC1);
	for (int iW = 0; iW < width; iW++) {
		for (int iH = 0; iH < height; iH++) {
			uchar &intensity = image.at<uchar>(iH, iW);
			uchar color = gray_image[iH + height * iW];
			intensity = color;
		}
	}
	// Initialization of variables for the detector
	std::shared_ptr<ipa_Fiducials::AbstractFiducialModel> tag_detector;
	cv::Mat camera_matrix;

	tag_detector = std::shared_ptr<ipa_Fiducials::FiducialModelPi>(new ipa_Fiducials::FiducialModelPi());
	camera_matrix = cv::Mat::zeros(3, 3, CV_64FC1);

	if (tag_detector->Init(camera_matrix, constellation, false) & RET_FAILED){
		*err = -101;
		return;
	}

	// The main function that processes the image and provides the detected image points
	if (tag_detector->GetPoints(image, vec_points, algorithmParams.Param_blob, algorithmParams.Param_filt,
			algorithmParams.Param_ellip, algorithmParams.Param_LenAng) & RET_FAILED) {
		*err = -102;
		return;
	}

}
