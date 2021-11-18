//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
void b_merge_block(::coder::array<int32_T, 1U> &idx,
                   ::coder::array<int32_T, 1U> &b_x, int32_T offset,
                   int32_T g_n, int32_T preSortLevel,
                   ::coder::array<int32_T, 1U> &iwork,
                   ::coder::array<int32_T, 1U> &xwork);

void c_merge_block(::coder::array<int32_T, 1U> &idx,
                   ::coder::array<real_T, 1U> &b_x, int32_T offset, int32_T g_n,
                   int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                   ::coder::array<real_T, 1U> &xwork);

void merge_block(::coder::array<int32_T, 1U> &idx,
                 ::coder::array<real32_T, 1U> &b_x, int32_T offset, int32_T g_n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<real32_T, 1U> &xwork);

void sortIdx(const ::coder::array<real_T, 2U> &b_x,
             ::coder::array<int32_T, 2U> &idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for sortIdx.h
//
// [EOF]
//
