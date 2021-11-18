//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_calibrateOneCamera_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef _CODER_CALIBRATEONECAMERA_API_H
#define _CODER_CALIBRATEONECAMERA_API_H

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

typedef struct {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  coder::array<real_T, 2U> WorldPoints;
  coder::array<char_T, 2U> WorldUnits;
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[3][3];
} struct1_T;

typedef struct {
  struct1_T CameraParameters;
  coder::array<cell_wrap_0, 2U> PatternPositions;
  coder::array<real_T, 3U> ImagePoints;
  coder::array<real_T, 1U> b_Error;
} struct0_T;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void calibrateOneCamera(coder::array<uint8_T, 4U> *images, real_T squareSize,
                        int32_T boardSize[2], struct0_T *calibrationOptimized,
                        real_T *calculation_err, int32_T *err);

void calibrateOneCamera_api(const mxArray *const prhs[3], int32_T nlhs,
                            const mxArray *plhs[3]);

void calibrateOneCamera_atexit();

void calibrateOneCamera_initialize();

void calibrateOneCamera_terminate();

void calibrateOneCamera_xil_shutdown();

void calibrateOneCamera_xil_terminate();

void preprocessImages(coder::array<uint8_T, 4U> *images,
                      coder::array<uint8_T, 4U> *gray_images);

void preprocessImages_api(const mxArray *prhs, const mxArray **plhs);

#endif
//
// File trailer for _coder_calibrateOneCamera_api.h
//
// [EOF]
//
