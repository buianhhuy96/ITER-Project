#pragma once
#ifndef CALIBRATEHANDEYE_H
#define CALIBRATEHANDEYE_H

// Include Files

#include "HandeyeShah.h"
#include "linalg.h"
#include "readRobotPoses.h"
#include "ComputeCamExtrinsics.h"
#include "calibrateHandeye_terminate.h"
#include "calibrateHandeye_data.h"
#include "computeErrors.h"
#include "HandeyeShah.h"

using namespace std;
using namespace linalg;
using namespace aliases;

struct imageWrap {
  unsigned char *imageData;
  int numChannels;
  int width;
  int height;
};


struct calibrationPatternParameters {
  float squareSize;
  int numSquaresHor;
  int numSquaresVer;
};

struct intrinsicParameters {
  float2 focalLength;
  float2 principalPoint;
  float2 distortionsTangential;
  float3 distortionsRadial;
  float reprojectionError;
  int numUsedImages;
};

void generateCamParamStruct(
    const calibrationPatternParameters &calibPatternParam,
    const intrinsicParameters &camParam, struct0_T &cameraParams);

void convertImages2Array(const std::vector<imageWrap> &ImagesV,
                         coder::array<uint8_T, 4U> &Images);

void convertRobotPoses2Array(const std::vector<float4x4> &robotPosesVec,
                             coder::array<double, 3U> &robotPoses);

void calibrateHandEye(const std::vector<imageWrap> &Images,
                      const std::vector<float4x4> &robotPosesVec,
                      const calibrationPatternParameters &calibPatternParam,
                      const intrinsicParameters &camParam,

                      float4x4 &handEyeCalibration, int &usedImages,
                      float &reprojectionError, float &rotationError,
                      float &translationError);

#endif
