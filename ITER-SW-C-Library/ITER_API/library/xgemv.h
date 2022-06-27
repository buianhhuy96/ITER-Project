//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemv.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XGEMV_H
#define XGEMV_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void b_xgemv(int b_m, int h_n, const double A[15][15], int d_lda,
             const double b_x[8], double y[8][15]);

void c_xgemv(int b_m, int h_n, int d_lda, const double b_x[15], int ix0,
             double y[8]);

void xgemv(int b_m, int h_n, const ::coder::array<double, 2U> &A, int d_lda,
           const ::coder::array<double, 1U> &b_x,
           ::coder::array<double, 1U> &y);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xgemv.h
//
// [EOF]
//
