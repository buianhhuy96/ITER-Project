#include "computeCalibrationPoses.h"
using std::isnan;
namespace computeCalibrationPoses_ns {

/**************************************************************************
-Function: convertDataType4RobotPoses
-Type: Internal function  
-Inputs: 

double4x4 initialRobotPose						- HTM of the initial pose of the robot from the robot
												controller, corresponding to the initialImage.
double4x4 handEyeEstimate 			   			- HTM with an initial guess for the hand eye calibration
												so that the camera points are roughly in the correct 
												direction when moving the robotic arm for the first time.
double2x3 angularBounds							- The maximum angle the camera can be placed in wrt to the 
												calibration target around the axis X, Y (planar) and Z
												(facing up from the calibration plane) of the calibration target.
int3 requestedNumPoses							- How many camera poses should be computed and returned.

-Outputs: 

double initialRobotPose_d[4][4]					- initialRobotPose in array type.
double handEyeEstimate_d[4][4] 			   		- handEyeEstimate in array type.
double angularBounds_d[3][2]					- angularBounds_d in array type.
int requestedNumPoses_d[3]						- requestedNumPoses_d in array type.

-Functionality: 
Convert inputs from user input type (linalg) to API processing type (array)

-Error cases and handling: 
*

-Dependencies: 
*
**/
void convertDataType4ArrayInputs(const double4x4 initialRobotPose, const double4x4 handEyeEstimate,
							const double2x3 angularBounds, const int3 &requestedNumPoses,
							double initialRobotPose_d[4][4], double handEyeEstimate_d[4][4],
							double angularBounds_d[3][2], int requestedNumPoses_d[3])
 {

	for (int i1 = 0; i1 < 4; i1++) {
		for (int i0 = 0; i0 < 4; i0++) {
			initialRobotPose_d[i0][i1] = initialRobotPose[i1][i0];
			handEyeEstimate_d[i0][i1] = handEyeEstimate[i1][i0];
		}
	}

	for (int i1 = 0; i1 < 2; i1++) {
		for (int i0 = 0; i0 < 3; i0++) {
			angularBounds_d[i0][i1] = angularBounds[i0][i1];
		}
	}

	for (int i0 = 0; i0 < 3; i0++) {
		requestedNumPoses_d[i0] = requestedNumPoses[i0];
	}
}

/**************************************************************************
-Function: validateInputs
-Type: Internal function
-Inputs: 
imageWrap initialImage 	   						- one image where the calibration pattern is visible, 
												is used by the algorithm to determine the initial 
												position of the camera with respect to the pattern.
double initialRobotPose[4][4]					- HTM of the initial pose of the robot from the robot
												controller, corresponding to the initialImage.
double handEyeEstimate[4][4] 			   		- HTM with an initial guess for the hand eye calibration
												so that the camera points are roughly in the correct 
												direction when moving the robotic arm for the first time.
double roughDistance							- Distance between the computed poses and the calibration target.
double2x3 angularBounds							- The maximum angle the camera can be placed in wrt to the 
												calibration target around the axis X, Y (planar) and Z
												(facing up from the calibration plane) of the calibration target.
calibrationPatternParameters calibPatternParam 	- Calibration pattern parameters. 
intrinsicParameters factoryCamParam 			- Camera calibration parameters. 
int3 &requestedNumPoses							- How many camera poses should be computed and returned.

-Outputs: 
*

-Functionality: 
Check for the validity of API input arguments to prevent errors during calculation

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
*
**/

void validateInputs(const imageWrap &initialImage,
		const double initialRobotPose[4][4], const double handEyeEstimate[4][4],
		const double &roughDistance, const double2x3 angularBounds,
		const calibrationPatternParameters &calibPatternParam,
		const intrinsicParameters &factoryCamParam, const int3 &requestedNumPoses){

	if ((initialImage.numChannels != 1) && (initialImage.numChannels != 3)) {
		throw std::runtime_error(API_error_codes.at(0001));
	}
	if (!isT(initialRobotPose)) {
		throw std::runtime_error(API_error_codes.at(0002));
	}
	if (!isT(handEyeEstimate)) {
		throw std::runtime_error(API_error_codes.at(0003));
	}

	for (int i1 = 0; i1 < 2; i1++) {
		for (int i0 = 0; i0 < 3; i0++) {
			if ((angularBounds[i0][i1] > 180)
					|| (angularBounds[i0][i1] < -180)) {
				throw std::runtime_error(API_error_codes.at(0004));
			}
		}
	}

	if ((calibPatternParam.squareSize < 0.001)
			|| (calibPatternParam.squareSize > 10000)) {
		throw std::runtime_error(API_error_codes.at(0005));
	}
	if ((calibPatternParam.numSquaresHor <= 0)
			|| (calibPatternParam.numSquaresVer <= 0)
			|| ((calibPatternParam.numSquaresHor % 2 == 0)
					&& (calibPatternParam.numSquaresVer % 2 == 0))
			|| ((calibPatternParam.numSquaresVer % 2 != 0)
					&& (calibPatternParam.numSquaresHor % 2 != 0))) {
		throw std::runtime_error(API_error_codes.at(0006));
	}
	if (isnan(factoryCamParam.principalPoint.x)
			|| isnan(factoryCamParam.principalPoint.y)
			|| isnan(factoryCamParam.focalLength.x)
			|| isnan(factoryCamParam.focalLength.y)) {
		throw std::runtime_error(API_error_codes.at(7));
	}
	if ((requestedNumPoses[0] <= 0) || (requestedNumPoses[1] <= 0)
			|| (requestedNumPoses[2] <= 0)) {
		throw std::runtime_error(API_error_codes.at(8));
	}
	if ((requestedNumPoses[0] * requestedNumPoses[1] * requestedNumPoses[2]
			> 1000000)) {
		throw std::runtime_error(API_error_codes.at(9));
	}
}

}
/**************************************************************************
-Function: computeCalibrationPoses
-Type: Application Program Interface 
-Inputs: 

imageWrap &initialImage 	   					- one image where the calibration pattern is visible, 
												is used by the algorithm to determine the initial 
												position of the camera with respect to the pattern.
double4x4 initialRobotPose						- HTM of the initial pose of the robot from the robot
												controller, corresponding to the initialImage.
double4x4 handEyeEstimate 			   			- HTM with an initial guess for the hand eye calibration
												so that the camera points are roughly in the correct 
												direction when moving the robotic arm for the first time.
double &roughDistance							- Distance between the computed poses and the calibration target.
double2x3 angularBounds							- The maximum angle the camera can be placed in wrt to the 
												calibration target around the axis X, Y (planar) and Z
												(facing up from the calibration plane) of the calibration target.
calibrationPatternParameters calibPatternParam 	- Calibration pattern parameters. 
intrinsicParameters factoryCamParam 			- Camera calibration parameters. 
int3 &requestedNumPoses							- How many camera poses should be computed and returned.

-Outputs: 
std::vector<double4x4> &robotPoses				- robot positions where the calibration images should 
												  be captured from.

-Functionality: 
Given one image where a calibration pattern is visible, computes a set of positions where the
manipulator should be moved to to capture a sufficient set of calibration images.

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
Chessboard detection function + possible helpers (MV library) 
Extrinsics computation function (MV library) 
 **/
void computeCalibrationPoses(const imageWrap &initialImage,
		const double4x4 initialRobotPose, const double4x4 handEyeEstimate,
		const double &roughDistance, const double2x3 angularBounds,
		const calibrationPatternParameters &calibPatternParam,
		const intrinsicParameters &factoryCamParam,
		const int3 &requestedNumPoses,

		std::vector<double4x4> &robotPoses) {

	// Definition of interal variables
	coder::array<unsigned char, 3U> initialImage_l;
	double initialRobotPose_l[4][4];
	double handEyeEstimate_l[4][4];
	double angularBounds_l[3][2];
	double squareSize;
	int boardSize[2];
	cam_struct_t factoryCamParam_l;
	int requestedNumPoses_l[3];
	int err = ITER::NO_ERROR;
	coder::array<double, 3U> robotPoses_l;
	
	// Input conversion
	ITER::convertDataType4Image(initialImage, initialImage_l);
	computeCalibrationPoses_ns::convertDataType4ArrayInputs(initialRobotPose, handEyeEstimate,
			angularBounds, requestedNumPoses,

			initialRobotPose_l, handEyeEstimate_l, angularBounds_l,
			requestedNumPoses_l);

	ITER::convertDataType4CalibParams(calibPatternParam, squareSize, boardSize);

	ITER::generateCameraParameters(factoryCamParam, factoryCamParam_l);

	// Input validation
	computeCalibrationPoses_ns::validateInputs(initialImage, initialRobotPose_l, handEyeEstimate_l,
			roughDistance, angularBounds, calibPatternParam, factoryCamParam,
			requestedNumPoses);
			
	// Compute Calibration Poses
	computeCalibrationPoses_internal(initialImage_l, initialRobotPose_l,
			handEyeEstimate_l, roughDistance, angularBounds_l, squareSize,
			boardSize, &factoryCamParam_l, requestedNumPoses_l, robotPoses_l,
			&err);
			
	// Error check
	if (err != ITER::NO_ERROR) {
		ITER_API_terminate();
		throw std::runtime_error(computeCalibrationPoses_ns::API_error_codes.at(-err));
	}
	
	//  Output conversion
	for (int i1 = 0; i1 < robotPoses_l.size(2); i1++) {
		double4x4 robotPose;
		for (int i0 = 0; i0 < 4; i0++) {
			if (std::isinf(robotPoses_l[4 * i0 + 4 * 4 * i1])
					|| std::isinf(robotPoses_l[1 + 4 * i0 + 4 * 4 * i1])
					|| std::isinf(robotPoses_l[2 + 4 * i0 + 4 * 4 * i1])
					|| std::isinf(robotPoses_l[3 + 4 * i0 + 4 * 4 * i1])
					|| std::isnan(robotPoses_l[4 * i0 + 4 * 4 * i1])
					|| std::isnan(robotPoses_l[1 + 4 * i0 + 4 * 4 * i1])
					|| std::isnan(robotPoses_l[2 + 4 * i0 + 4 * 4 * i1])
					|| std::isnan(robotPoses_l[3 + 4 * i0 + 4 * 4 * i1])) {
							ITER_API_terminate();
							throw std::runtime_error(
									computeCalibrationPoses_ns::API_error_codes.at(10));
				}
			robotPose[i0] = { robotPoses_l[4 * i0 + 4 * 4 * i1], robotPoses_l[1
					+ 4 * i0 + 4 * 4 * i1],
					robotPoses_l[2 + 4 * i0 + 4 * 4 * i1], robotPoses_l[3
							+ 4 * i0 + 4 * 4 * i1] };
		}
		robotPoses.push_back(robotPose);
	}
	ITER_API_terminate();
}
