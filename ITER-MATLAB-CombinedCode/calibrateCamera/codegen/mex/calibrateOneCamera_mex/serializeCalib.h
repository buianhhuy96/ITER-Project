//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// serializeCalib.h
//
// Code generation for function 'serializeCalib'
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
void serializeCalib(
    const emlrtStack *sp, const real_T c_calibration_CameraParameters_[3],
    const real_T d_calibration_CameraParameters_[2],
    boolean_T e_calibration_CameraParameters_,
    real_T f_calibration_CameraParameters_,
    boolean_T g_calibration_CameraParameters_,
    const real_T h_calibration_CameraParameters_[9],
    const ::coder::array<cell_wrap_0, 2U> &calibration_PatternPositions,
    ::coder::array<real_T, 1U> &x);

}

// End of code generation (serializeCalib.h)
