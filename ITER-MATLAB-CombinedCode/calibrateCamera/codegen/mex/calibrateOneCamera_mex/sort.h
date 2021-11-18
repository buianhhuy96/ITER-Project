//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sort.h
//
// Code generation for function 'sort'
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
void sort(const emlrtStack *sp, ::coder::array<real32_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx);

void sort(const emlrtStack *sp, ::coder::array<real_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx);

void sort(const emlrtStack *sp, ::coder::array<int32_T, 1U> &x,
          ::coder::array<int32_T, 1U> &idx);

void sort(real_T x[4]);

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (sort.h)
