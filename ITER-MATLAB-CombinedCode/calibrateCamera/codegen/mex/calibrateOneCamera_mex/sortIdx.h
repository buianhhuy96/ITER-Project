//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortIdx.h
//
// Code generation for function 'sortIdx'
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
void merge_block(const emlrtStack *sp, ::coder::array<int32_T, 1U> &idx,
                 ::coder::array<int32_T, 1U> &x, int32_T offset, int32_T n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<int32_T, 1U> &xwork);

void merge_pow2_block(::coder::array<int32_T, 1U> &idx,
                      ::coder::array<int32_T, 1U> &x, int32_T offset);

void sortIdx(const emlrtStack *sp, ::coder::array<real32_T, 1U> &x,
             ::coder::array<int32_T, 1U> &idx);

void sortIdx(const emlrtStack *sp, ::coder::array<real_T, 1U> &x,
             ::coder::array<int32_T, 1U> &idx);

void sortIdx(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
             ::coder::array<int32_T, 2U> &idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

// End of code generation (sortIdx.h)
