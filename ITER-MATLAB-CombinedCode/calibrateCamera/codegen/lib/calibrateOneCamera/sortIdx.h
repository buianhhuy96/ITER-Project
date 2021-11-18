//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int g_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork);

void b_sortIdx(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx);

void c_merge_block(::coder::array<int, 1U> &idx,
                   ::coder::array<double, 1U> &b_x, int offset, int g_n,
                   int preSortLevel, ::coder::array<int, 1U> &iwork,
                   ::coder::array<double, 1U> &xwork);

void sortIdx(const ::coder::array<double, 2U> &b_x,
             ::coder::array<int, 2U> &idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for sortIdx.h
//
// [EOF]
//
