//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_calibrateCamera_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef _CODER_CALIBRATECAMERA_API_H
#define _CODER_CALIBRATECAMERA_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
typedef struct {
  real_T f1[4][4];
} cell_wrap_0;

struct emxArray_char_T_1x2 {
  char_T data[2];
  int32_T size[2];
};

struct emxArray_real_T_1x1 {
  real_T data[1];
  int32_T size[2];
};

struct emxArray_char_T_1x29 {
  char_T data[29];
  int32_T size[2];
};

struct rtString_tag_0 {
  emxArray_char_T_1x29 Value;
};
typedef rtString_tag_0 rtString;

typedef struct {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  coder::array<real_T, 2U> WorldPoints;
  emxArray_char_T_1x2 WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[3][3];
  emxArray_real_T_1x1 NumPatterns;
  real_T FocalLength[2];
  real_T PrincipalPoint[2];
  real_T Skew;
  coder::array<real_T, 3U> RotationMatrices;
  real_T MeanReprojectionError;
} struct1_T;

typedef struct {
  struct1_T CameraParameters;
  coder::array<cell_wrap_0, 2U> PatternPositions;
  coder::array<real_T, 3U> ImagePoints;
} struct2_T;

typedef struct {
  struct1_T CameraParameters;
  coder::array<cell_wrap_0, 2U> PatternPositions;
  coder::array<real_T, 3U> ImagePoints;
  real_T OptimizationOptions[3];
  coder::array<real_T, 2U> Jacobian;
  coder::array<real_T, 1U> b_Error;
  struct2_T CI[2];
} struct0_T;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void calibrateCamera(coder::array<uint8_T, 4U> *images, real_T squareSize,
                     real_T boardSize[2], struct0_T *calibrationOptimized,
                     rtString *err);

void calibrateCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                         const mxArray *plhs[2]);

void calibrateCamera_atexit();

void calibrateCamera_initialize();

void calibrateCamera_terminate();

void calibrateCamera_xil_shutdown();

void calibrateCamera_xil_terminate();

#endif
//
// File trailer for _coder_calibrateCamera_api.h
//
// [EOF]
//
