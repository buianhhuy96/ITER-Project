#pragma once
#ifndef COMMON_DEFINITION_H
#define COMMON_DEFINITION_H

// Include Files

#include "./library/linalg.h"
#include "./library/ITER_API_types.h"
#include "./library/ITER_API_terminate.h"
#include "./library/coder_array.h"

using namespace std;
using namespace linalg;
using namespace aliases;

typedef struct1_T cam_struct_t;
const int NUM_IMG_MIN = 3;

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

void generateCameraParameters(const intrinsicParameters &camParam,
							cam_struct_t &camera_params);


void convertDataType4Images(const std::vector<imageWrap> &image_vector, coder::array<uint8_T, 4U> &image_array);

#endif
