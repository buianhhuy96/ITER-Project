//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_ITER_API_api.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef _CODER_ITER_API_API_H
#define _CODER_ITER_API_API_H

// Include Files
#include "coder_array_mex.h"
#include "emlrt.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Type Definitions
typedef struct {
  coder::array<real_T, 2U> RadialDistortion;
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  coder::array<real_T, 2U> RotationVectors;
  coder::array<real_T, 2U> TranslationVectors;
  real_T IntrinsicMatrix[3][3];
} struct0_T;

typedef struct {
  real_T RadialDistortion[3];
  real_T TangentialDistortion[2];
  real_T ImageSize[2];
  char_T WorldUnits[2];
  boolean_T EstimateSkew;
  real_T NumRadialDistortionCoefficients;
  boolean_T EstimateTangentialDistortion;
  real_T IntrinsicMatrix[3][3];
} struct1_T;

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void ComputeCamExtrinsics(coder::array<uint8_T, 4U> *images, real_T squareSize,
                          struct1_T *cameraParams,
                          coder::array<real_T, 3U> *imagePoints,
                          coder::array<boolean_T, 1U> *validIdx,
                          coder::array<real_T, 3U> *camExtrinsics,
                          coder::array<real_T, 3U> *cameraPoses,
                          coder::array<real_T, 2U> *worldPoints, int32_T *err);

void ComputeCamExtrinsics_api(const mxArray *const prhs[3], int32_T nlhs,
                              const mxArray *plhs[6]);

void HandeyeShah(coder::array<real_T, 3U> *As, coder::array<real_T, 3U> *Bs,
                 real_T X[4][4], real_T k_Y[4][4], int32_T *err);

void HandeyeShah_api(const mxArray *const prhs[2], int32_T nlhs,
                     const mxArray *plhs[3]);

void ITER_API_atexit();

void ITER_API_initialize();

void ITER_API_terminate();

void ITER_API_xil_shutdown();

void ITER_API_xil_terminate();

void calibrateOneCamera_v2(coder::array<uint8_T, 4U> *images, real_T squareSize,
                           int32_T boardSize[2], struct0_T *cameraParams,
                           coder::array<real_T, 1U> *errorOptimized,
                           real_T *MREf, coder::array<boolean_T, 1U> *validIdx,
                           int32_T *err);

void calibrateOneCamera_v2_api(const mxArray *const prhs[3], int32_T nlhs,
                               const mxArray *plhs[5]);

void computeErrors(coder::array<real_T, 3U> *Hhand2base, real_T Hhand2eye[4][4],
                   real_T Hbase2grid[4][4], coder::array<real_T, 3U> *Hcam2grid,
                   coder::array<real_T, 3U> *imgPts,
                   coder::array<real_T, 2U> *Worldpts, real_T K[4][3],
                   real_T errors[3]);

void computeErrors_api(const mxArray *const prhs[7], const mxArray **plhs);

void preprocessImages(coder::array<uint8_T, 4U> *images,
                      struct1_T *cameraParams, boolean_T undistort,
                      coder::array<uint8_T, 4U> *gray_images);

void preprocessImages_api(const mxArray *const prhs[3], const mxArray **plhs);

void readRobotPoses(coder::array<real_T, 3U> *robotPosesVec,
                    coder::array<real_T, 3U> *poses,
                    coder::array<real_T, 3U> *extrinsics);

void readRobotPoses_api(const mxArray *prhs, int32_T nlhs,
                        const mxArray *plhs[2]);

#endif
//
// File trailer for _coder_ITER_API_api.h
//
// [EOF]
//
