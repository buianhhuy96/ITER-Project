//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2.h
//
// Code generation for function 'calibrateOneCamera_v2'
//

#pragma once

// Include files
#include "calibrateOneCamera_v2_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void calibrateOneCamera_v2(const emlrtStack *sp,
                           const coder::array<uint8_T, 4U> &images,
                           real_T squareSize, const int32_T boardSize[2],
                           struct0_T *cameraParams,
                           coder::array<real_T, 1U> &errorOptimized,
                           real_T *MREf, coder::array<boolean_T, 1U> &validIdx,
                           int32_T *err);

void calibrateOneCamera_v2_anonFcn1(
    const emlrtStack *sp, const struct_T *initialParams,
    const coder::array<real_T, 2U> &world_points,
    const coder::array<real_T, 3U> &image_points,
    const coder::array<real_T, 1U> &x, coder::array<real_T, 1U> &varargout_1);

void reprojectWrapper(const emlrtStack *sp,
                      const coder::array<real_T, 1U> &paramsVector,
                      const struct_T *cameraParams,
                      const coder::array<real_T, 2U> &worldPoints,
                      const coder::array<real_T, 3U> &ImagePoints,
                      coder::array<real_T, 1U> &cost);

// End of code generation (calibrateOneCamera_v2.h)
