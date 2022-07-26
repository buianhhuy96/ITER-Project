#include "estimatePoseReflective.h"
#include "Pitag/FiducialDefines.h"
#include "Pitag/FiducialModelPi.h"
#include <map>
#include <fstream>
using namespace std;
#include <string.h>
namespace estimatePoseReflective_ns {

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
double worldPts[3][5]						   - constellation parsed from JSON.

-Functionality: 
Parse inputs from JSON format into internal type.

-Error cases and handling: 
*

-Dependencies: 
**/
void loadTagWorldPoints(const std::string &constellation,
		double worldPts[3][5]){
	// -----Reading the PI models -----------------
	cv::FileStorage fs(constellation, cv::FileStorage::MEMORY);
	std::vector<std::vector<double>> lbpval;
	fs["worldPoints"] >> lbpval;
	fs.release();

	for (int i = 0; i < 5; ++i){
		for( int j = 0; j < 2; ++j){
			worldPts[j][i] = lbpval.at(i).at(j);
		}
	}
	worldPts[2][0] = 0;
	worldPts[2][1] = 0;
	worldPts[2][2] = 0;
	worldPts[2][3] = 0;
	worldPts[2][4] = 0;
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
		estimatePoseReflective_ns::KnuckleParams &algorithmParams) {
	cv::FileStorage fs(algorithmParamString, cv::FileStorage::MEMORY);
		fs["minArea"] >> algorithmParams.minArea;
		fs["maxArea"] >> algorithmParams.maxArea;
		fs["ThresholdDelta"] >> algorithmParams.ThresholdDelta;
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
		cv::FileStorage fs(constellation, cv::FileStorage::MEMORY);
		if (fs["worldPoints"].empty()) {
			throw std::runtime_error(API_error_codes.at(0005));
		}
		std::vector<std::vector<double>> worldPoints;
		fs["worldPoints"] >> worldPoints;
		if (worldPoints.size() != 5) {
			throw std::runtime_error(API_error_codes.at(0006));
		}
		for (auto point : worldPoints) {
			if (point.size() != 2) {
				throw std::runtime_error(API_error_codes.at(0006));
			}
		}
	} catch (const cv::Exception &e) {
		const char *msg = (std::string(API_error_codes.at(0004))
				+ "constellation").c_str();

		throw std::runtime_error(msg);
	}

	try {
		cv::FileStorage fs(algorithmParametersString, cv::FileStorage::MEMORY);
		if ((!fs["minArea"].isReal() && !fs["minArea"].isInt())) {
			missingParams += "minArea, ";
		}
		if ((!fs["maxArea"].isReal() && !fs["maxArea"].isInt())) {
			missingParams += "maxArea, ";
		}
		if ((!fs["ThresholdDelta"].isReal() && !fs["ThresholdDelta"].isInt())) {
			missingParams += "ThresholdDelta, ";
		}
		if (!missingParams.empty()) {
			missingParams.pop_back();
			missingParams.pop_back();
			(void)missingParams.append(".");
			const char *msg = (std::string(API_error_codes.at(0007)) + "\n"
					+ missingParams).c_str();
			throw std::runtime_error(msg);
		}
		double minArea;
		double maxArea;
		double ThresholdDelta;
		fs["minArea"] >> minArea;
		fs["maxArea"] >> maxArea;
		fs["ThresholdDelta"] >> ThresholdDelta;
		if ((minArea < MIN_AREA_L || minArea > maxArea)) {
			outOfRangeParams += "minArea, ";
		}
		if ((maxArea > inputImage.width*inputImage.height)) {
			outOfRangeParams += "maxArea, ";
		}
		if (((ThresholdDelta < THRESHOLD_DELTA_L || ThresholdDelta > THRESHOLD_DELTA_H))) {
			outOfRangeParams += "ThresholdDelta, ";
		}

		if (!outOfRangeParams.empty()) {
			outOfRangeParams.pop_back();
			outOfRangeParams.pop_back();
			(void)outOfRangeParams.append(".");

			const char *msg = (std::string(API_error_codes.at(8)) + "\n"
					+ outOfRangeParams).c_str();


			throw std::runtime_error(msg);

		}
	} catch (const cv::Exception &e) {
		const char *msg = (std::string(API_error_codes.at(0004)) + "algorithm parameters").c_str();

		throw std::runtime_error(msg);
	}



}

}

/**************************************************************************
-Function: estimatePoseReflective
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
void estimatePoseReflective(const imageWrap &inputImage, const double4x4 &robotPose,
		const std::string &constellation, const intrinsicParameters &camParam,
		const double4x4 &handEyeCalibration,
		const std::string &algorithmParametersString,

		std::vector<double2> &targetLocImage2D, double4x4 &targetPoseCamera,
		double4x4 &targetPoseRobot, double &confidence) {


	coder::array<uint8_T, 4U> image;
	coder::array<uint8_T, 4U> grayImage;
	ITER::cam_struct_t cameraParams;
	estimatePoseReflective_ns::KnuckleParams algorithmParams;

	coder::array<double, 2U> imagePoints;
	double robotPose_l[4][4];
	double worldPts[3][5];
	double handEyeCalibration_l[4][4];

	double poseCamera[4][4];
	double poseRobot[4][4];
	int err = ITER::NO_ERROR;

	::coder::array<double, 2U> markerCentroidsOrdered;

	ITER::convertDataType4Image(inputImage, image);
	ITER::generateCameraParameters(camParam, cameraParams);

	// Convert input arguments to suitable data types for processing
	estimatePoseReflective_ns::convertDataType4Inputs(robotPose, handEyeCalibration,
			robotPose_l, handEyeCalibration_l);

	estimatePoseReflective_ns::validateInputs(inputImage, robotPose_l, constellation,
				handEyeCalibration_l, algorithmParametersString);

	estimatePoseReflective_ns::loadTagWorldPoints(constellation, worldPts);
	estimatePoseReflective_ns::readAlgorithmParameters(algorithmParametersString,
				algorithmParams);

	// Undistort the image
	ITER::preprocessImages(image, &cameraParams, true, grayImage);
	ofstream outfile;
	outfile.open("Report_24.csv");
	outfile << "image\n";
	for (int i0 = 0; i0 < 400; i0++) {
		for (int i1 = 0; i1 < 640; i1++) {
		outfile << (int)grayImage[i0+i1*400] << ", ";
		}
		outfile<< "\n";
	}
	// Detect marker points in image
	ITER::RRDetectionKnuckle(grayImage, &algorithmParams,cameraParams.IntrinsicMatrix, markerCentroidsOrdered, &err);
	if (err != ITER::NO_ERROR){
		ITER::ITER_API_terminate();
		throw std::runtime_error(estimatePoseReflective_ns::API_error_codes.at(-err));
	}

	// Calculate pose from detected marker points
	ITER::estimateKnucklePose(markerCentroidsOrdered,
			robotPose_l, worldPts, handEyeCalibration_l, &cameraParams, poseCamera, poseRobot, &confidence, &err);
	if (err != ITER::NO_ERROR){
		ITER::ITER_API_terminate();
		throw std::runtime_error(estimatePoseReflective_ns::API_error_codes.at(-err));
	}

	// Assign outputs
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
						estimatePoseReflective_ns::API_error_codes.at(9));
			}
		}
	}

	for (int i = 0; i < (int)markerCentroidsOrdered.size(0); i++){
		double2 currentPoint {markerCentroidsOrdered[i],markerCentroidsOrdered[i+markerCentroidsOrdered.size(0)]};
		targetLocImage2D.push_back(currentPoint);
	}

	ITER::ITER_API_terminate();
}
