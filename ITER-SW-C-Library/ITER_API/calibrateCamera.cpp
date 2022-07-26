#include "calibrateCamera.h"

namespace calibrateCamera_ns {

/**************************************************************************
-Function: validateInputs
-Type: Internal function
-Inputs: 
std::vector<imageWrap> images        	 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
calibrationPatternParameters calibPatternParam - calibration pattern parameters 

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
				      const calibrationPatternParameters &calibPatternParam){
	int number_of_images = images.size();
	int image_size[2];
	image_size[0] = images.front().height;
	image_size[1] = images.front().width;

	if (number_of_images < NUM_IMG_MIN){
		throw std::runtime_error(API_error_codes.at(0001));
	}
	
	for (imageWrap image: images){
		if ((image.numChannels != 1) &&
			(image.numChannels != 3)){
			throw std::runtime_error(API_error_codes.at(0002));
		}
		if ((image.height != image_size[0]) ||
			(image.width != image_size[1])) {
			throw std::runtime_error(API_error_codes.at(0003));
		}
	}

	if ((calibPatternParam.squareSize < 0.001)
			|| (calibPatternParam.squareSize > 10000)) {
		throw std::runtime_error(API_error_codes.at(0004));
	}


	if ((calibPatternParam.numSquaresHor <= 0) ||
			(calibPatternParam.numSquaresVer <= 0) ||
			((calibPatternParam.numSquaresHor % 2 == 0) && (calibPatternParam.numSquaresVer % 2 == 0)) ||
			((calibPatternParam.numSquaresVer % 2 != 0) && (calibPatternParam.numSquaresHor % 2 != 0))) {
		throw std::runtime_error(API_error_codes.at(0005));
	}

}
}

/**************************************************************************
-Function: calibrateCamera
-Type: Application Program Interface 
-Inputs: 
std::vector<imageWrap> calibrationImages 	   - images of the calibration target, N>2
												 as required by the calibration algorithm 
calibrationPatternParameters calibPatternParam - calibration pattern parameters  

-Outputs: 
intrinsicParameters camParam 				   - camera calibration parameters as returned 
												 by calibrateCamera
-Functionality: 
Analyzes the set of input images, detects the presence of the chessboard calibration pattern
and computes the intrinsic camera parameters. Internally, validates the inputs, 
calls the MV library implementation of calibration pattern finding and camera calibration
and formats the calibration data according to the API specification. 

-Error cases and handling: 
(Refer to errors in error-list document)

-Dependencies: 
Chessboard detection function + possible helpers (MV library)  
Camera calibration function + possible helpers (MV library) 
**/
void calibrateCamera(const std::vector<imageWrap> &calibrationImages,
				      const calibrationPatternParameters &calibPatternParam,
					  intrinsicParameters &camParam)
{
	// Definition of interal variables
	coder::array<uint8_T, 4U> images_array;	
	ITER::cam_struct_t camera_params_in;
	
	coder::array<uint8_T, 4U> gray_images;
	
	double squareSize;
	int boardSize[2];
	
	ITER::struct0_T camera_params;
	coder::array<double, 1U> errorOptimized;
	double MRef;
	coder::array<bool, 1U> valid_idx;
	int err = ITER::NO_ERROR;
	
	// Input conversion and validation
	calibrateCamera_ns::validateInputs(calibrationImages, calibPatternParam);

	ITER::convertDataType4CalibParams(calibPatternParam, 
								squareSize,
								boardSize);
								
	ITER::convertDataType4Images(calibrationImages, images_array);

	ITER::preprocessImages(images_array, &camera_params_in, false, gray_images);

	// calibrateOneCamera
	ITER::calibrateOneCamera(gray_images, squareSize, boardSize, &camera_params,
			errorOptimized, &MRef, valid_idx, &err);

	if (err != ITER::NO_ERROR) {
		ITER::ITER_API_terminate();
		throw std::runtime_error(calibrateCamera_ns::API_error_codes.at(-err));
	}



	if (std::isinf(camera_params.IntrinsicMatrix[0][0])
			|| std::isinf(camera_params.IntrinsicMatrix[1][1])
			|| std::isinf(camera_params.IntrinsicMatrix[0][2])
			|| std::isinf(camera_params.IntrinsicMatrix[1][2])
			|| std::isinf(camera_params.RadialDistortion[0])
			|| std::isinf(camera_params.RadialDistortion[1])
			|| std::isinf(camera_params.RadialDistortion[2])
			|| std::isinf(camera_params.TangentialDistortion[0])
			|| std::isinf(camera_params.TangentialDistortion[1])
			|| std::isinf(MRef)
			|| std::isnan(camera_params.IntrinsicMatrix[0][0])
			|| std::isnan(camera_params.IntrinsicMatrix[1][1])
			|| std::isnan(camera_params.IntrinsicMatrix[0][2])
			|| std::isnan(camera_params.IntrinsicMatrix[1][2])
			|| std::isnan(camera_params.RadialDistortion[0])
			|| std::isnan(camera_params.RadialDistortion[1])
			|| std::isnan(camera_params.RadialDistortion[2])
			|| std::isnan(camera_params.TangentialDistortion[0])
			|| std::isnan(camera_params.TangentialDistortion[1])
			|| std::isnan(MRef)) {
		ITER::ITER_API_terminate();
		throw std::runtime_error(
				calibrateCamera_ns::API_error_codes.at(6));
	}
	camParam.focalLength.x = camera_params.IntrinsicMatrix[0][0];
	camParam.focalLength.y = camera_params.IntrinsicMatrix[1][1];

	camParam.distortionsRadial.x = camera_params.RadialDistortion[0];
	camParam.distortionsRadial.y = camera_params.RadialDistortion[1];
	camParam.distortionsRadial.z = camera_params.RadialDistortion[2];

	camParam.principalPoint.x = camera_params.IntrinsicMatrix[0][2];
	camParam.principalPoint.y = camera_params.IntrinsicMatrix[1][2];

	camParam.distortionsTangential.x = camera_params.TangentialDistortion[0];
	camParam.distortionsTangential.y = camera_params.TangentialDistortion[1];
	camParam.reprojectionError = MRef;
	int counter=0;
	for (int i0 = 0; i0 < valid_idx.size(0); i0++) {
		if (valid_idx[i0] == true) {
			counter++;
		}
	}
	camParam.numUsedImages = counter;
	
	ITER::ITER_API_terminate();
}
