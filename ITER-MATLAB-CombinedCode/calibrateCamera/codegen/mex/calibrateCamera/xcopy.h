//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xcopy.h
//
// Code generation for function 'xcopy'
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
namespace internal {
namespace blas {
void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 1U> &y,
           int32_T iy0);

void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 2U> &y);

void xcopy(const emlrtStack *sp, int32_T n, ::coder::array<real_T, 2U> &y,
           int32_T iy0);

void xcopy(int32_T n, const ::coder::array<real_T, 1U> &x,
           ::coder::array<real_T, 1U> &y);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (xcopy.h)
