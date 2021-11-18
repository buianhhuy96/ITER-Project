//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// unserializeCalib.h
//
// Code generation for function 'unserializeCalib'
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
struct struct1_T;

struct cell_wrap_0;

} // namespace Codegen

// Function Declarations
namespace Codegen {
void unserializeCalib(
    const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints);

}

// End of code generation (unserializeCalib.h)
