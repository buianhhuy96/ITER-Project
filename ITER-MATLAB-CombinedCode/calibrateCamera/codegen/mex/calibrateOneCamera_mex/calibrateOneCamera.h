//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera.h
//
// Code generation for function 'calibrateOneCamera'
//

#pragma once

// Include files
#include "calibrateOneCamera_mex_types.h"
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
void calibrateOneCamera(const emlrtStack *sp,
                        const ::coder::array<uint8_T, 4U> &images,
                        real_T squareSize, const int32_T boardSize[2],
                        struct0_T *calibrationOptimized,
                        real_T *calculation_err, int32_T *err);

void calibrateOneCamera_anonFcn1(
    const emlrtStack *sp, const real_T c_calibration_CameraParameters_[2],
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    const ::coder::array<real_T, 1U> &x,
    ::coder::array<real_T, 1U> &varargout_1);

emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

} // namespace Codegen

// End of code generation (calibrateOneCamera.h)
