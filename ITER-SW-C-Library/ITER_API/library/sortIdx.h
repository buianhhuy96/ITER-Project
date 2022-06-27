//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
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
namespace coder {
namespace internal {
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int h_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork);

void b_sortIdx(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx);

void c_sortIdx(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx);

void d_merge(int idx[4], double b_x[4], int offset, int np, int nq,
             int iwork[4], double xwork[4]);

void sortIdx(const ::coder::array<double, 2U> &b_x,
             ::coder::array<int, 2U> &idx);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for sortIdx.h
//
// [EOF]
//
