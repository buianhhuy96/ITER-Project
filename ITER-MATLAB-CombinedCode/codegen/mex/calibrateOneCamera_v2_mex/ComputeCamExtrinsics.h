//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics.h
//
// Code generation for function 'ComputeCamExtrinsics'
//

#pragma once

// Include files
#include "calibrateOneCamera_v2_mex_types.h"
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
void ComputeCamExtrinsics(const emlrtStack *sp,
                          const coder::array<uint8_T, 4U> &images,
                          real_T squareSize, const struct1_T *cameraParams,
                          coder::array<real_T, 3U> &imagePoints,
                          coder::array<boolean_T, 1U> &validIdx,
                          coder::array<real_T, 3U> &camExtrinsics,
                          coder::array<real_T, 3U> &cameraPoses,
                          coder::array<real_T, 2U> &worldPoints, int32_T *err);

// End of code generation (ComputeCamExtrinsics.h)
