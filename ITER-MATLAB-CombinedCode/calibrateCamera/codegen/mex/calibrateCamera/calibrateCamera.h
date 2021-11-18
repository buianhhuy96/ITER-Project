//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera.h
//
// Code generation for function 'calibrateCamera'
//

#pragma once

// Include files
#include "calibrateCamera_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace Codegen {
void calibrateCamera(const emlrtStack *sp,
                     const ::coder::array<uint8_T, 4U> &images,
                     real_T squareSize, const real_T boardSize[2],
                     struct0_T *calibrationOptimized, int8_T *err);

void calibrateCamera_anonFcn1(
    const emlrtStack *sp, const struct1_T *calibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    const ::coder::array<real_T, 3U> &calibration_ImagePoints,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    const ::coder::array<real_T, 1U> &x,
    ::coder::array<real_T, 1U> &varargout_1);

emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

} // namespace Codegen

// End of code generation (calibrateCamera.h)
