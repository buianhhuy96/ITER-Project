#include "calibrateHandEye.h"
using std::isnan;

namespace calibrateHandEye_ns {

/**************************************************************************
-Function: convertDataType4RobotPoses
-Type: Internal function  
-Inputs: 
std::vector<double4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken 

-Outputs: 
coder::array<double, 3U> &robot_pose_array     - robotPoses in array type

-Functionality: 
Convert robot poses from user input type (vector) to API processing type (array)

-Error cases and handling: 
*

-Dependencies: 
*
**/
void convertDataType4RobotPoses(const std::vector<double4x4> &robotPoses,
                             coder::array<double, 3U> &robot_pose_array)
{
  int numPoses = robotPoses.size();
  robot_pose_array.set_size(4, 4, numPoses);
  int i2 = 0;
  
  for (double4x4 pose : robotPoses) {
    for (int i1 = 0; i1 < 4; i1++) {
      for (int i0 = 0; i0 < 4; i0++) {
    	  robot_pose_array[i0 + (4 * i1) + (16 * i2)] = pose[i1][i0];
      }
    }
    i2++;
  }
}


/**************************************************************************
-Function: validateInputs
-Type: Internal function
-Inputs: 
std::vector<imageWrap> calibrationImages 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
std::vector<double4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken 
calibrationPatternParameters calibPatternParam - calibration pattern parameters 
intrinsicParameters camParam 				   - camera calibration parameters as returned 
												 by calibrateCamera 

-Outputs: 
*

-Functionality: 
Check for the validity of API input arguments to prevent errors during calculation

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
*
**/
void validateInputs(const std::vector<imageWrap> &images,
                      const std::vector<double4x4> &robotPosesVec,
                      const calibrationPatternParameters &calibPatternParam,
                      const intrinsicParameters &camParam){
	int number_of_images = images.size();
	int number_of_robot_poses = robotPosesVec.size();

	if (number_of_images < NUM_IMG_MIN){
		throw std::runtime_error(API_error_codes.at(0001));
	}
	int image_size[2];
	image_size[0] = images.front().height;
	image_size[1] = images.front().width;
	for (imageWrap image : images) {
		if ((image.numChannels != 1) && (image.numChannels != 3)) {
			throw std::runtime_error(API_error_codes.at(0002));
		}
		if ((image.height != image_size[0]) || (image.width != image_size[1])) {
			throw std::runtime_error(API_error_codes.at(0003));
		}
	}

	if ((calibPatternParam.squareSize < 0.001)
			|| (calibPatternParam.squareSize > 10000)) {
		throw std::runtime_error(API_error_codes.at(0004));
	}

	if (isnan(camParam.principalPoint.x) || isnan(camParam.principalPoint.y)
			|| isnan(camParam.focalLength.x) || isnan(camParam.focalLength.y)
			|| isnan(camParam.distortionsRadial.x)
			|| isnan(camParam.distortionsRadial.y)
			|| isnan(camParam.distortionsRadial.z)
			|| isnan(camParam.distortionsTangential.x)
			|| isnan(camParam.distortionsTangential.y)) {
		throw std::runtime_error(API_error_codes.at(0005));
	}

	if (number_of_images != number_of_robot_poses) {
		throw std::runtime_error(API_error_codes.at(0006));
	}

	for (double4x4 pose : robotPosesVec) {
		for (int i1 = 0; i1 < 4; i1++) {
			for (int i0 = 0; i0 < 4; i0++) {
				if (isnan(pose[i1][i0]))
					throw std::runtime_error(API_error_codes.at(0007));	
			}
		}
	}
}
}

/**************************************************************************
-Function: calibrateHandEye
-Type: Application Program Interface 
-Inputs: 
std::vector<imageWrap> calibrationImages 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
std::vector<double4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken 
calibrationPatternParameters calibPatternParam - calibration pattern parameters 
intrinsicParameters camParam 				   - camera calibration parameters as returned 
												 by calibrateCamera 

-Outputs: 
double4x4 handEyeCalibration 				   - the computed hand eye calibration as a HTM 
												 based on the input images and the robot poses 
int usedImages 								   - how many images were successfully used 
												 from the calibration images 
double reprojectionError 					   - Error metric as computed by the algorithm 
double rotationError 						   - Error metric as computed by the algorithm 
double translationError 					   - Error metric as computed by the algorithm 

-Functionality: 
Computes the Hand-eye calibration using MilliShah's algorithm 

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
Chessboard detection function + possible helpers (MV library) 
Extrinsics computation function (MV library) 
**/
void calibrateHandEye(const std::vector<imageWrap> &images,
					  const std::vector<double4x4> &robotPosesVec,
				      const calibrationPatternParameters &calibPatternParam,
					  const intrinsicParameters &camParam,

					  double4x4 &handEyeCalibration,
					  int &usedImages,
					  double &reprojectionError,
					  double &rotationError,
					  double &translationError)
{
	// Definition of interal variables
	coder::array<double, 3U> robotPoses;
	coder::array<double, 3U> Poses;
	coder::array<double, 3U> Extrinsics;

	double square_size = calibPatternParam.squareSize;
	coder::array<uint8_T, 4U> images_array;
	coder::array<uint8_T, 4U> gray_images;
	coder::array<double, 3U> image_points;
	coder::array<bool, 1U> valid_idx;
	coder::array<double, 3U> cam_extrinsics;
	coder::array<double, 3U> camera_poses;
	coder::array<double, 2U> world_points;
	cam_struct_t camera_params;
	int err = ITER::NO_ERROR;

	double base2grid[4][4];
	double handEyeHT[4][4];

	double errors[5];
	double KM[4][3];
	
	// Input conversion and validation
	calibrateHandEye_ns::validateInputs(images, robotPosesVec,
			calibPatternParam, camParam);
			
	calibrateHandEye_ns::convertDataType4RobotPoses(robotPosesVec, robotPoses);
	ITER::convertDataType4Images(images, images_array);
	ITER::generateCameraParameters(camParam, camera_params);
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			KM[j][k] = camera_params.IntrinsicMatrix[k][j];
		}
	}

	KM[3][0] = 0;
	KM[3][1] = 0;
	KM[3][2] = 0;

	preprocessImages(images_array, &camera_params, true, gray_images);

	// Load robot poses
	readRobotPoses(robotPoses, Poses, Extrinsics);

	// Compute Camera extrinsics
	ComputeCamExtrinsics(gray_images, square_size, &camera_params, image_points,
			valid_idx, cam_extrinsics, camera_poses, world_points, &err);

	if (err != ITER::NO_ERROR) {
		ITER_API_terminate();
		throw std::runtime_error(calibrateHandEye_ns::API_error_codes.at(-err));
	}

	// Compute hand-eye- transformation (AX=ZB)
	// Handeye Shah
	HandeyeShah(Extrinsics, cam_extrinsics, base2grid, handEyeHT, &err);

	if (err != ITER::NO_ERROR) {
		ITER_API_terminate();
		throw std::runtime_error(calibrateHandEye_ns::API_error_codes.at(-err));
	}
	// This should be reduced to only errors which can be computed without
	// ground truth

	// Computing Errors
	computeErrors(Extrinsics, handEyeHT, base2grid, cam_extrinsics,
			image_points, world_points, KM, errors);

	//  Output conversion
	rotationError = errors[0];
	translationError = errors[1];
	reprojectionError = errors[2];

	for (int i1 = 0; i1 < 4; i1++) {
		for (int i0 = 0; i0 < 4; i0++) {
			if (std::isinf(handEyeHT[i1][i0])
					|| std::isnan(handEyeHT[i1][i0])) {
				ITER_API_terminate();
				throw std::runtime_error(
						calibrateHandEye_ns::API_error_codes.at(8));
			}
			handEyeCalibration[i1][i0] = handEyeHT[i1][i0];
		}
	}

	int img_counter = 0;
	for (int i0 = 0; i0 < valid_idx.size(0); i0++) {
		if (valid_idx[i0] == true) {
			img_counter++;
		}
	}
	usedImages = img_counter;
	ITER_API_terminate();

}
