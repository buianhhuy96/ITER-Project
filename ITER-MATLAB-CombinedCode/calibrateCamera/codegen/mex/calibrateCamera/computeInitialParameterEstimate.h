//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// computeInitialParameterEstimate.h
//
// Code generation for function 'computeInitialParameterEstimate'
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

}

// Function Declarations
namespace Codegen {
void computeInitialParameterEstimate(
    const emlrtStack *sp, const ::coder::array<real_T, 2U> &worldPoints,
    const ::coder::array<real_T, 3U> &imagePoints, struct1_T *iniltialParams,
    ::coder::array<boolean_T, 1U> &validIdx, int8_T *err);

}

// End of code generation (computeInitialParameterEstimate.h)
