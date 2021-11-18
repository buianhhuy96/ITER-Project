//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// polyfit.h
//
// Code generation for function 'polyfit'
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
void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             const ::coder::array<real_T, 2U> &y, real_T n, real_T p_data[],
             int32_T p_size[2]);

void polyfit(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y, real_T n, real_T p_data[],
             int32_T p_size[2]);

} // namespace coder
} // namespace Codegen

// End of code generation (polyfit.h)
