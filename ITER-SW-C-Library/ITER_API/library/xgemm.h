//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemm.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XGEMM_H
#define XGEMM_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void b_xgemm(int b_m, int h_n, int k, const double A[15][15], int ia0,
             int d_lda, const double c_B[8][15], double b_C[15][15], int ldc);

void xgemm(int b_m, int h_n, int k, const double A[7][7], int d_lda,
           const double c_B[15][15], int b_ib0, int ldb, double b_C[8][15]);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xgemm.h
//
// [EOF]
//
