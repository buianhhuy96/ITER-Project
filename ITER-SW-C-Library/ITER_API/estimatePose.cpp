#include "estimatePose.h"
#include "Pitag/FiducialDefines.h"
#include "Pitag/FiducialModelPi.h"
#include <map>

#include <string.h>
namespace estimatePose_ns {

/**************************************************************************
-Function: convertDataType4Inputs
-Type: Internal function
double4x4 robotPose                            - the current robot pose corresponding to inputImage.
double4x4 handEyeCalibration				   - hand eye calibration HTM as returned by
												 calibrateHandEye.
-Outputs: 
double robotPose_l[4][4]                       - robotPose in internal type.
double handEyeCalibration_l[4][4]			   - hand eye calibration in internal type.

-Functionality: 
Convert user's inputs into internal type.

-Error cases and handling: 
*

-Dependencies: 
*
**/
void convertDataType4Inputs(const double4x4 robotPose,
		const double4x4 handEyeCalibration, double robotPose_l[4][4],
		double handEyeCalibration_l[4][4]) {

	for (int i1 = 0; i1 < 4; i1++) {
		for (int i0 = 0; i0 < 4; i0++) {
			robotPose_l[i0][i1] = robotPose[i1][i0];
			handEyeCalibration_l[i0][i1] = handEyeCalibration[i1][i0];
		}
	}
}

/**************************************************************************
-Function: loadTagWorldPoints
-Type: Internal function
std::string constellation				   	   - JSON encoded definition of the 
												 constellation which is to be localized.
-Outputs: 
coder::array<double, 2U> worldPts			   - constellation parsed from JSON.

-Functionality: 
Parse inputs from JSON format into internal type.

-Error cases and handling: 
*

-Dependencies: 
**/
void loadTagWorldPoints(const std::string &constellation,
		coder::array<double, 2U> &worldPts){
	// -----Reading the PI models -----------------
	cv::FileStorage fs2(constellation, cv::FileStorage::MEMORY);

	// first method: use (type) operator on FileNode.
	cv::FileNode models = fs2["PI"];
	cv::FileNodeIterator it = models.begin(), it_end = models.end();
	int idx = 0;
	double scale=66.0723;
	worldPts.set_size(12,2);
	// iterate through a models using FileNodeIterator
	for (; it != it_end; ++it, idx++)
	{
		//cout << "models #" << idx << ": ";
		// you can also easily read numerical arrays using FileNode >> std::vector operator.
		//(*it)["ID"] >> pi_parameters.m_id*scale;
		worldPts[0]=0*scale;
		(*it)["CrossRatioLine0AB"] >> worldPts[1];
		worldPts[1] *= scale;// CrossRatioLine0AB*scale;
		(*it)["CrossRatioLine0AC"] >> worldPts[2];
		worldPts[2] *= scale;//  CrossRatioLine0AC*scale;
		worldPts[3]=1*scale;
		worldPts[4]=1*scale;
		worldPts[5]=1*scale;
		worldPts[6]=1*scale;
		(*it)["CrossRatioLine1AC"] >> worldPts[7];
		worldPts[7]*=scale;
		(*it)["CrossRatioLine1AB"] >> worldPts[8];
		worldPts[8]*=scale;
		worldPts[9]=0*scale;
		worldPts[10]=0*scale;
		worldPts[11]=0*scale;
		worldPts[12]=0*scale;
		worldPts[13]=0*scale;
		worldPts[14]=0*scale;
		worldPts[15]=0*scale;
		(*it)["CrossRatioLine1AB"] >> worldPts[16];
		worldPts[16]*=scale;
		(*it)["CrossRatioLine1AC"] >> worldPts[17];
		worldPts[17]*=scale;
		worldPts[18]=1*scale;
		worldPts[19]=1*scale;
		worldPts[20]=1*scale;
		worldPts[21]=1*scale;
		(*it)["CrossRatioLine0AC"] >> worldPts[22];
		worldPts[22]*=scale;//  CrossRatioLine0AC*scale;
		(*it)["CrossRatioLine0AB"] >> worldPts[23];
		worldPts[23]*=scale;// CrossRatioLine0AB*scale;

	}
	fs2.release();
}

/**************************************************************************
-Function: readAlgorithmParameters
-Type: Internal function
std::string algorithmParametersString		   - JSON encoded parameters needed by the algorithm.

-Outputs: 
algorithmParameters algorithmParams			   - Parameters parsed from JSON input.

-Functionality: 
Parse inputs from JSON format into internal type.

-Error cases and handling: 
*

-Dependencies: 
*
 **/
void readAlgorithmParameters(const std::string &algorithmParamString,
		algorithmParameters &algorithmParams) {

	std::shared_ptr<ipa_Fiducials::AbstractFiducialModel> tag_detector =
			std::shared_ptr<ipa_Fiducials::FiducialModelPi>(
					new ipa_Fiducials::FiducialModelPi());
	(void)tag_detector->LoadProcessingParametersJSON(algorithmParamString,
			algorithmParams.Param_blob, algorithmParams.Param_filt,
			algorithmParams.Param_ellip, algorithmParams.Param_LenAng);
}




/**************************************************************************
-Function: validateInputs
-Type: Internal function
-Inputs: 
imageWrap inputImage						   - image of the target to be localized.
double4x4 robotPose                            - the current robot pose corresponding to inputImage.
std::string constellation 					   - JSON encoded definition of the constellation which 
												 is to be localized.
double4x4 handEyeCalibration				   - hand eye calibration HTM as returned by
												 calibrateHandEye.
std::string algorithmParametersString		   - JSON encoded parameters needed by the algorithm.


-Outputs: 
*

-Functionality: 
Check for the validity of API input arguments to prevent errors during calculation

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
*
**/
void validateInputs(const imageWrap &inputImage, const double robotPose[4][4],
		const std::string &constellation,
		const double handEyeCalibration[4][4],
		const std::string &algorithmParametersString){


	std::string missingParams;
	std::string outOfRangeParams;
	std::string missingTags;
	bool new_line=false;
	if ((inputImage.numChannels != 1) && (inputImage.numChannels != 3)) {
		throw std::runtime_error(API_error_codes.at(0001));
	}
	if (!ITER::isT(robotPose)) {
		throw std::runtime_error(API_error_codes.at(0002));
	}
	if (!ITER::isT(handEyeCalibration)) {
		throw std::runtime_error(API_error_codes.at(0003));
	}

	try {
		cv::FileStorage fs(algorithmParametersString, cv::FileStorage::MEMORY);
		for (auto paramSet : algorithmParamInfo) {
			for (auto param : paramSet.second) {
				if ((!fs[paramSet.first][param.name].isReal()
						&& !fs[paramSet.first][param.name].isInt())) {
					if (!missingParams.empty() && new_line) {
						missingParams += "\n";
						new_line = false;
					}
					missingParams += paramSet.first + "." + param.name + ", ";
				} else {
					double current_param;
					fs[paramSet.first][param.name] >> current_param;
					if ((current_param > param.max)
							|| (current_param < param.min)) {
						if (!outOfRangeParams.empty() && new_line) {
							outOfRangeParams += "\n";
							new_line = false;
						}
						outOfRangeParams += paramSet.first + "." + param.name
								+ ", ";
					}
				}
			}
			new_line = true;
		}

		if (!missingParams.empty()) {
			missingParams.pop_back();
			missingParams.pop_back();
			(void)missingParams.append(".");

			const char *msg = (std::string(API_error_codes.at(0005)) + "\n"
					+ missingParams).c_str();
			throw std::runtime_error(msg);
		}

		if (!outOfRangeParams.empty()) {
			outOfRangeParams.pop_back();
			outOfRangeParams.pop_back();
			(void)outOfRangeParams.append(".");

			const char *msg = (std::string(API_error_codes.at(0006)) + "\n"
					+ outOfRangeParams).c_str();


			throw std::runtime_error(msg);

		}
	} catch (const cv::Exception &e) {
		const char *msg = (std::string(API_error_codes.at(0004)) + "algorithm parameters").c_str();

		throw std::runtime_error(msg);
	}

	try {
		cv::FileStorage fs2(constellation, cv::FileStorage::MEMORY);
		if (fs2["PI"].size() > 1) {
			throw std::runtime_error(API_error_codes.at(0007));
		}
		for (auto line : tagElement) {
			if ((!(*fs2["PI"].begin())[line].isReal()
					&& !(*fs2["PI"].begin())[line].isInt())) {
				missingTags += line + ", ";
			}
		}
		if (!missingTags.empty()) {
			missingTags.pop_back();
			missingTags.pop_back();
			(void)missingTags.append(".");

			const char *msg = (std::string(API_error_codes.at(8)) + missingTags).c_str();

			throw std::runtime_error(msg);
		}
	} catch (const cv::Exception &e) {
		const char *msg = (std::string(API_error_codes.at(0004)) + "constellation").c_str();

		throw std::runtime_error(msg);
	}

}

}

/**************************************************************************
-Function: estimatePose
-Type: Application Program Interface 
-Inputs: 
imageWrap inputImage						   - image of the target to be localized.
double4x4 robotPose                            - the current robot pose corresponding to inputImage.
std::string constellation 					   - JSON encoded definition of the constellation which 
												 is to be localized.
intrinsicParameters camParam				   - camera calibration parameters as returned by
												 calibrateCamera.
double4x4 handEyeCalibration				   - hand eye calibration HTM as returned by
												 calibrateHandEye.
std::string algorithmParametersString		   - JSON encoded parameters needed by the algorithm.

-Outputs: 
std::vector<double2> targetLocImage2D		   - location of the target markers in pixel coordinates (u,
												 v).
double4x4 targetPoseCamera					   - HTM of the pose of the target in the coordinate space of the
												 camera.
double4x4 targetPoseRobot					   - HTM of the pose of the target in the coordinate space of the
												 camera.
double confidence							   - The aggregated confidence of the localization result.

-Functionality: 
Undistorts the input image, detects the marker constellation and computes the camera pose
from it.

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
Image undistortion (MV library)
Local adaptive thresholding (MV library)
Extrinsics computation function (MV library)
**/
void estimatePose(const imageWrap &inputImage, const double4x4 &robotPose,
		const std::string &constellation, const intrinsicParameters &camParam,
		const double4x4 &handEyeCalibration,
		const std::string &algorithmParametersString,

		std::vector<double2> &targetLocImage2D, double4x4 &targetPoseCamera,
		double4x4 &targetPoseRobot, double &confidence) {

	coder::array<uint8_T, 4U> image;
	coder::array<uint8_T, 4U> grayImage;
	ITER::cam_struct_t cameraParams;
	std::vector<ipa_Fiducials::t_points> vec_points;
	estimatePose_ns::algorithmParameters algorithmParams;

	coder::array<double, 2U> imagePoints;
	double robotPose_l[4][4];
	coder::array<double, 2U> worldPts;
	double handEyeCalibration_l[4][4];

	double poseCamera[4][4];
	double poseRobot[4][4];
	int err = ITER::NO_ERROR;

	// Convert input arguments to suitable data types for processing
	estimatePose_ns::convertDataType4Inputs(robotPose, handEyeCalibration,
			robotPose_l, handEyeCalibration_l);

	estimatePose_ns::validateInputs(inputImage, robotPose_l, constellation,
			handEyeCalibration_l, algorithmParametersString);

	estimatePose_ns::readAlgorithmParameters(algorithmParametersString,
			algorithmParams);

	ITER::convertDataType4Image(inputImage, image);
	ITER::generateCameraParameters(camParam, cameraParams);

	// Undistort the image
	ITER::preprocessImages(image, &cameraParams, true, grayImage);

	// Detect markers
	estimatePose_ns::pitagDetector(grayImage, constellation, algorithmParams, vec_points, &err);

	if (err != ITER::NO_ERROR) {
		throw std::runtime_error(estimatePose_ns::API_error_codes.at(-err));
	}

	// Get marker points
	imagePoints.set_size(estimatePose_ns::NUM_POINTS, 2);
	std::vector<ipa_Fiducials::t_points>::size_type point_index = 0;
	double validPoints = 0;
	for (auto point : vec_points.front().image_points) {

		imagePoints[point_index] = point.x;
		imagePoints[estimatePose_ns::NUM_POINTS + point_index++] = point.y;
		if ((point.x != 0) || (point.y != 0)) {
			validPoints++;
			double2 currentPoint { point.x, point.y };
			targetLocImage2D.push_back(currentPoint);
		}
	}
	confidence = validPoints / imagePoints.size(0);
	estimatePose_ns::loadTagWorldPoints(constellation, worldPts);

	// Perform calculation using detected marker points
	ITER::estimatePitagPose(imagePoints, robotPose_l, worldPts, handEyeCalibration_l,
			&cameraParams, poseCamera, poseRobot);

	for (int i1 = 0; i1 < 4; i1++) {
		for (int i0 = 0; i0 < 4; i0++) {
			targetPoseCamera[i1][i0] = poseCamera[i0][i1];
			targetPoseRobot[i1][i0] = poseRobot[i0][i1];

			if (std::isinf(targetPoseCamera[i1][i0])
					|| std::isnan(targetPoseCamera[i1][i0])
					|| std::isinf(targetPoseRobot[i1][i0])
					|| std::isnan(targetPoseRobot[i1][i0])) {
				ITER::ITER_API_terminate();
				throw std::runtime_error(
						estimatePose_ns::API_error_codes.at(9));
			}
		}
	}

	ITER::ITER_API_terminate();
}
