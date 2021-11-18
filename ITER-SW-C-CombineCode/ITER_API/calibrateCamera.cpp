#include "calibrateCamera.h"


void validateInputs(const std::vector<imageWrap> &images,
				      const calibrationPatternParameters &calibPatternParam){
	int number_of_images = images.size();
	int image_size[2];
	image_size[0] = images.front().height;
	image_size[1] = images.front().width;

	if (number_of_images < NUM_IMG_MIN){
		throw "Error 0001: Number of images is less than requirement"; // 58
	}
	
	for (imageWrap image: images){
		if ((image.numChannels != 1) &&
			(image.numChannels != 3)){
			throw "Error 0003: Function only supports gray or RGB images"; //57
		}
		if ((image.height != image_size[0]) ||
			(image.width != image_size[1])) {
			throw "Error 0004: There are images with different sizes."; //56
		}
	}

	if ((calibPatternParam.squareSize < 0.001)
			|| (calibPatternParam.squareSize > 10000)) {
		throw "Error 0005: Square size is not in valid range.";
	}

}

void calibrateCamera(const std::vector<imageWrap> &calibrationImages,
				      const calibrationPatternParameters &calibPatternParam,
					  intrinsicParameters &camParam)
{
  // preprocessImages
	coder::array<uint8_T, 4U> images_array;
	coder::array<uint8_T, 4U> gray_images;
	coder::array<double, 1U> errorOptimized;
	cam_struct_t camera_params_in;
	struct0_T camera_params;
	double square_size;
	int boardSize[2];
	double calculation_err;
	coder::array<bool, 1U> valid_idx;
	int err;

	// Compute Camera extrinsics
	square_size = calibPatternParam.squareSize * 1000;
	boardSize[0] = calibPatternParam.numSquaresHor;
	boardSize[1] = calibPatternParam.numSquaresVer;
	validateInputs(calibrationImages, calibPatternParam);

	convertDataType4Images(calibrationImages, images_array);

	preprocessImages(images_array, &camera_params_in, false, gray_images);

	calibrateOneCamera_v2(gray_images, square_size, boardSize, &camera_params,
			errorOptimized, &calculation_err, valid_idx, &err);

	if (err == -1) {
		throw "Error 0101: Cannot detect any checkerboard in images.";
	} else if (err == -2) {
		throw "Error 0102: Detected different size of checkerboards.";
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
	camParam.reprojectionError = calculation_err;
	camParam.numUsedImages = valid_idx.size(0);

}
