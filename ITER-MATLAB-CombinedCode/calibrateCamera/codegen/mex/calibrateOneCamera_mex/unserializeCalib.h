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
struct cell_wrap_0;

struct c_struct_T;

} // namespace Codegen

// Function Declarations
namespace Codegen {
void unserializeCalib(
    const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
    const real_T c_refCalibration_CameraParamete[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    c_struct_T *CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &PatternPositions);

}

// End of code generation (unserializeCalib.h)
