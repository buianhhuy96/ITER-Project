#pragma once
#ifndef COMMON_DEFINITION_H
#define COMMON_DEFINITION_H

// Include Files
#include <exception>
#include <stdexcept>
#include "./library/linalg.h"
#include "./library/ITER_API_types.h"
#include "./library/ITER_API_terminate.h"
#include "./library/coder_array.h"
#include "./library/isT.h"

using linalg::aliases::int2;
using linalg::aliases::int3;
using linalg::aliases::double2;
using linalg::aliases::double3;
using linalg::aliases::double4;
using linalg::aliases::double2x3;
using linalg::aliases::double4x4;


typedef struct1_T cam_struct_t;

struct imageWrap {
  unsigned char *imageData;
  int numChannels;
  int width;
  int height;
};


struct calibrationPatternParameters {
  double squareSize;
  int numSquaresHor;
  int numSquaresVer;
};

struct intrinsicParameters {
  double2 focalLength;
  double2 principalPoint;
  double2 distortionsTangential;
  double3 distortionsRadial;
  double reprojectionError;
  int numUsedImages;
};

/*****************************************************************************************
Name space: ITER
Functionality: Definition of functions to convert data type from API I/O to Matlab generated
				code I/O.
Functions: 
generateCameraParameters 	   					- Generate a struct of camera parameters based on
												input intrinsic parameters.
convertDataType4Image							- convert user input image (type imageWrap) into 
												MATLAB image type (coder::array)
convertDataType4CalibParams 			   		- Generate calibration data based on input 
												Calibration Pattern Parameters.
**/
namespace ITER {
#ifndef NO_ERROR
	const int NO_ERROR = 0;
#endif // NO_ERROR


void generateCameraParameters(const intrinsicParameters &camParam,
							cam_struct_t &camera_params);

void convertDataType4Image(const imageWrap &image, coder::array<uint8_T, 3U> &image_array);
void convertDataType4Image(const imageWrap &image, coder::array<uint8_T, 4U> &image_array);
void convertDataType4Images(const std::vector<imageWrap> &image_vector, coder::array<uint8_T, 4U> &image_array);
void convertDataType4CalibParams(const calibrationPatternParameters &calibPatternParam,
								double &squareSize,
								int boardSize[2]);
}
#endif
