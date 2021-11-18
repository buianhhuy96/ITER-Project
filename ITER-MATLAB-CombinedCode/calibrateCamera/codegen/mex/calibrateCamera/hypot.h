//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// hypot.h
//
// Code generation for function 'hypot'
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
void b_hypot(const emlrtStack *sp, const ::coder::array<real32_T, 1U> &x,
             const ::coder::array<real32_T, 1U> &y,
             ::coder::array<real32_T, 1U> &r);

void b_hypot(const emlrtStack *sp, const ::coder::array<real_T, 1U> &x,
             const ::coder::array<real_T, 1U> &y,
             ::coder::array<real_T, 1U> &r);

} // namespace coder
} // namespace Codegen

// End of code generation (hypot.h)
