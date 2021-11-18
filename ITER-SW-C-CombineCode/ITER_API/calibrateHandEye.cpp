#include "calibrateHandEye.h"

/**
-Function: convertDataType4RobotPoses
-Inputs: 
std::vector<Float4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken. 
-Outputs: 
coder::array<double, 3U> &robot_pose_array     - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken with 
												 MATLAB array type.

-Functionality: 
Convert user input for robot poses to suitable data type (heap).

-Dependencies: 
*

**/
void convertDataType4RobotPoses(const std::vector<double4x4> &robot_pose_vector,
                             coder::array<double, 3U> &robot_pose_array)
{
  int numPoses = robot_pose_vector.size();
  robot_pose_array.set_size(4, 4, numPoses);
  int i2 = 0;
  
  for (double4x4 pose : robot_pose_vector) {
    for (int i1 = 0; i1 < 4; i1++) {
      for (int i0 = 0; i0 < 4; i0++) {
    	  robot_pose_array[i0 + (4 * i1) + (16 * i2)] = pose[i1][i0];
      }
    }
    i2++;
  }
}


/**
-Function: calibrateHandEye
-Inputs: 
std::vector<imageWrap> calibrationImages 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
std::vector<Float4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken 
calibrationPatternParameters calibPatternParam - calibration pattern parameters 
intrinsicParameters camParam 				   - camera calibration parameters as returned by calibrateCamera 

-Outputs: 
*

-Functionality: 
Ensure all inputs to API are valid to prevent unexpected behaviors during calculation. 

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
		throw "Error 0001: Number of images is less than requirement"; // 58
	}
	int image_size[2];
	image_size[0] = images.front().height;
	image_size[1] = images.front().width;
	for (imageWrap image : images) {
		if ((image.numChannels != 1) && (image.numChannels != 3)) {
			throw "Error 0002: Function only supports gray or RGB images"; //57
		}
		if ((image.height != image_size[0]) || (image.width != image_size[1])) {
			throw "Error 0003: There are images with different sizes."; //56
		}
	}

	if ((calibPatternParam.squareSize < 0.001)
			|| (calibPatternParam.squareSize > 10000)) {
		throw "Error 0004: Square size is not in valid range.";
	}

	if (isnan(camParam.principalPoint.x) || isnan(camParam.principalPoint.y)
			|| isnan(camParam.focalLength.x) || isnan(camParam.focalLength.y)
			|| isnan(camParam.distortionsRadial.x)
			|| isnan(camParam.distortionsRadial.y)
			|| isnan(camParam.distortionsRadial.z)
			|| isnan(camParam.distortionsTangential.x)
			|| isnan(camParam.distortionsTangential.y)) {
		throw "Error 0005: Detect NaN in camera parameters.";
	}

	if (number_of_images != number_of_robot_poses) {
		throw "Error 0006: Difference in number of images and robot poses can cause wrong calculation."; // 55
	}

	for (double4x4 pose : robotPosesVec) {
		for (int i1 = 0; i1 < 4; i1++) {
			for (int i0 = 0; i0 < 4; i0++) {
				if (isnan(pose[i1][i0]))
					throw "Error 0007: Robot pose is NaN.";
			}
		}
	}



}
/**
-Function: calibrateHandEye
-Type: Application  
-Inputs: 
std::vector<imageWrap> calibrationImages 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
std::vector<Float4x4> robotPoses 			   - The HTM of robot poses in the robot coordinate						
												 system corresponding to the positions 
												 where calibrationImages were taken 
calibrationPatternParameters calibPatternParam - calibration pattern parameters 
intrinsicParameters camParam 				   - camera calibration parameters as returned by calibrateCamera 

-Outputs: 
Float4x4 handEyeCalibration 				   - the computed hand eye calibration as a HTM 
												 based on the input images and the robot poses 
int usedImages 								   - how many images were successfully used 
												 from the calibration images 
double reprojectionError 					   - Error metric as computed by the algorithm 
double rotationError 						   - Error metric as computed by the algorithm 
double translationError 					   - Error metric as computed by the algorithm 

-Functionality: 
Computes the Hand-eye calibration using MilliShah's algorithm 

-Error cases and handling: 
Pattern is not found in all images -> discard useless images. Indicated to caller when usedImages < calibrationImages.size() 
Pattern is not found in enough images -> fail and throw notDetected 
Calibration procedure does not converge -> fail and throw notComputing 

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
  // Load robot poses
  coder::array<double, 3U> robotPoses;
  coder::array<double, 3U> Poses;
  coder::array<double, 3U> Extrinsics;


  // Compute Camera extrinsics
  double square_size = calibPatternParam.squareSize;
  coder::array<uint8_T, 4U> images_array;
  coder::array<uint8_T, 4U> gray_images;
  coder::array<double, 3U> image_points;
  coder::array<bool, 1U> valid_idx;
  coder::array<double, 3U> cam_extrinsics;
  coder::array<double, 3U> camera_poses;
  coder::array<double, 2U> world_points;
  cam_struct_t camera_params;
  int err;

  // Handeye Shah
  double base2grid[4][4];
  double handEyeHT[4][4];

  // Computing Errors
  double errors[5];
  double KM[4][3];

  validateInputs(images, robotPosesVec, calibPatternParam, camParam);
  convertDataType4RobotPoses(robotPosesVec, robotPoses);
  convertDataType4Images(images, images_array);

  generateCameraParameters(camParam, camera_params);
  for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			KM[j][k] = camera_params.IntrinsicMatrix[k][j];
		}
	}

	KM[3][0] = 0;
	KM[3][1] = 0;
	KM[3][2] = 0;
	
  preprocessImages(images_array, &camera_params, true, gray_images);

  readRobotPoses(robotPoses,
							Poses, Extrinsics);

  ComputeCamExtrinsics(gray_images, square_size, &camera_params,
		  image_points, valid_idx, cam_extrinsics, camera_poses, world_points, &err);

  if (err == -101)
  {
	  throw "Error 0101: Cannot detect any checkerboard in images.";
  }
  else if (err == -102){
	  throw "Error 0102: Detected different size of checkerboards.";
  }
  // Compute hand-eye- transformation (AX=ZB)
  HandeyeShah(Extrinsics, cam_extrinsics,
							base2grid, handEyeHT, &err);

  if (err == -201)
   {
 	  throw "Error 0201: Detected NaN during Handeye calculation";
   }
 // This should be reduced to only errors which can be computed without
 // ground truth
 
  computeErrors(Extrinsics, handEyeHT, base2grid, cam_extrinsics, image_points,  world_points, KM,
							errors);



 //  Output
  rotationError = errors[0];
  translationError = errors[1];
  reprojectionError = errors[2];

  for (int i1 = 0; i1 < 4; i1++){
	for (int i0 = 0; i0 < 4; i0++){
	  handEyeCalibration[i1][i0] = handEyeHT[i1][i0];
	}
  }

  int img_counter = 0;
  for (int i0 = 0; i0 < valid_idx.size(0); i0++){
	if (valid_idx[i0] == true){
		img_counter++;
	}
  }
  usedImages = img_counter;

  ITER_API_terminate();
}
