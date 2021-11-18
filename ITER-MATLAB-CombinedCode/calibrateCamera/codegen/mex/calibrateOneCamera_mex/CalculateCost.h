//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// CalculateCost.h
//
// Code generation for function 'CalculateCost'
//

#pragma once

// Include files
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

// Type Declarations
namespace Codegen {
struct cell_wrap_0;

}

// Function Declarations
namespace Codegen {
void CalculateCost(
    const emlrtStack *sp, const ::coder::array<real_T, 1U> &calib,
    const real_T c_refCalibration_CameraParamete[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    ::coder::array<real_T, 1U> &cost);

}

// End of code generation (CalculateCost.h)
