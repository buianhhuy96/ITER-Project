#include "common_definitions.h"


void ITER::generateCameraParameters(const intrinsicParameters &camParam,
							cam_struct_t &camera_params)
{
	// Radial Distortion
	camera_params.RadialDistortion[0] = camParam.distortionsRadial.x;
	camera_params.RadialDistortion[1] = camParam.distortionsRadial.y;
	camera_params.RadialDistortion[2] = camParam.distortionsRadial.z;

	// Tangential Distortion
	camera_params.TangentialDistortion[0] = camParam.distortionsTangential.x;
	camera_params.TangentialDistortion[1] = camParam.distortionsTangential.y;
	
	// Image Size
	camera_params.ImageSize[0] = 0;
	camera_params.ImageSize[1] = 0;

	// Estimate Skew
	camera_params.EstimateSkew = 0;

	// Radial Distortion Coefficients
	camera_params.NumRadialDistortionCoefficients = 0;

	// Estimate Tangential Distortion
	camera_params.EstimateTangentialDistortion = 0;

	// Intrinsic Matrix
	camera_params.IntrinsicMatrix[0][0] = camParam.focalLength.x;
	camera_params.IntrinsicMatrix[1][0] = 0;
	camera_params.IntrinsicMatrix[2][0] = 0;
	camera_params.IntrinsicMatrix[0][1] = 0;
	camera_params.IntrinsicMatrix[1][1] = camParam.focalLength.y;
	camera_params.IntrinsicMatrix[2][1] = 0;
	camera_params.IntrinsicMatrix[0][2] = camParam.principalPoint.x;
	camera_params.IntrinsicMatrix[1][2] = camParam.principalPoint.y;
	camera_params.IntrinsicMatrix[2][2] = 1;

}


void ITER::convertDataType4Images(const std::vector<imageWrap> &image_vector, coder::array<uint8_T, 4U> &image_array)
{
  imageWrap first_image = image_vector.front();
  int width = first_image.width;
  int height = first_image.height;
  int channel = 3;
  int numImg = image_vector.size();
  // Image iterator
  int iImg = 0;
  // Array size heigh x width x channel x num_of_images
  image_array.set_size(height, width, channel, numImg);
  for (imageWrap image : image_vector) {
		unsigned char* imageData = image.imageData;
		int image_channel = image.numChannels;
		for (int iC = 0; iC < channel; iC++) {
			for (int iW = 0; iW < width; iW++) {
				for (int iH = 0; iH < height; iH++) {
					image_array[iH + height * iW + width * height * iC + width * height * channel * iImg] =
								*(imageData + ((image_channel == 1) ? iW + width * iH
                             : iC + channel * iW + width * channel * iH));
				}
			}
		}
		iImg++;
	}
}

void ITER::convertDataType4Image(const imageWrap &image, coder::array<uint8_T, 3U> &image_array)
{
  int width = image.width;
  int height = image.height;
  int channel = image.numChannels;
  
  // Array size heigh x width x channel
  image_array.set_size(height, width, channel);
  unsigned char* imageData = image.imageData;
  for (int iC = 0; iC < channel; iC++) {
  	for (int iW = 0; iW < width; iW++) {
  		for (int iH = 0; iH < height; iH++) {
  			image_array[iH + height * iW + width * height * iC + width * height * channel * 0] =
  						*(imageData + iC + channel * iW + width * channel * iH);
  		}
  	}
  }
	
}

void ITER::convertDataType4Image(const imageWrap &image, coder::array<uint8_T, 4U> &image_array)
{
  int width = image.width;
  int height = image.height;
  int channel = image.numChannels;

  // Array size heigh x width x channel
  image_array.set_size(height, width, channel, 1);
  unsigned char* imageData = image.imageData;
  for (int iC = 0; iC < channel; iC++) {
  	for (int iW = 0; iW < width; iW++) {
  		for (int iH = 0; iH < height; iH++) {
  			image_array[iH + height * iW + width * height * iC + width * height * channel * 0] =
  						*(imageData + iC + channel * iW + width * channel * iH);
  		}
  	}
  }

}

void ITER::convertDataType4CalibParams(const calibrationPatternParameters &calibPatternParam, 
								double &squareSize,
								int boardSize[2])
{
  squareSize = calibPatternParam.squareSize;
  boardSize[0] = calibPatternParam.numSquaresHor;
  boardSize[1] = calibPatternParam.numSquaresVer;
	
}


