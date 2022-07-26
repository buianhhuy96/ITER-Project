//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SORTIDX_H
#define SORTIDX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
namespace internal {
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int h_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork);

void b_sortIdx(const ::coder::array<double, 1U> &b_x,
               ::coder::array<int, 1U> &idx);

void c_sortIdx(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx);

void d_merge(int idx[4], double b_x[4], int offset, int np, int nq,
             int iwork[4], double xwork[4]);

void d_sortIdx(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx);

void e_sortIdx(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx);

void f_merge(int idx[5], double b_x[5], int offset, int np, int nq,
             int iwork[5], double xwork[5]);

void sortIdx(const ::coder::array<double, 2U> &b_x,
             ::coder::array<int, 2U> &idx);

} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for sortIdx.h
//
// [EOF]
//
