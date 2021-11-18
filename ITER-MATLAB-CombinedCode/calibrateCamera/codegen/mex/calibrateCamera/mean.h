//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mean.h
//
// Code generation for function 'mean'
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

// Function Declarations
namespace Codegen {
namespace coder {
real_T mean(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x);

real32_T mean(const emlrtStack *sp, const ::coder::array<real32_T, 1U> &x);

real_T mean(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x);

} // namespace coder
} // namespace Codegen

// End of code generation (mean.h)
