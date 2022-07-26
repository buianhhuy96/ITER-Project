//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XGEMV_H
#define XGEMV_H

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
namespace blas {
void b_xgemv(int m, int h_n, const ::coder::array<double, 2U> &A, int d_lda,
             const ::coder::array<double, 1U> &b_x,
             ::coder::array<double, 1U> &y);

void c_xgemv(int m, const ::coder::array<double, 2U> &A, int d_lda,
             const ::coder::array<double, 2U> &b_x, double y[6]);

void d_xgemv(int m, int h_n, const double A[15][15], int d_lda,
             const double b_x[8], double y[8][15]);

void e_xgemv(int m, int h_n, int d_lda, const double b_x[15], int ix0,
             double y[8]);

void xgemv(int m, int h_n, const ::coder::array<double, 2U> &A, int ia0,
           int d_lda, const ::coder::array<double, 2U> &b_x, int ix0,
           ::coder::array<double, 1U> &y);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xgemv.h
//
// [EOF]
//
