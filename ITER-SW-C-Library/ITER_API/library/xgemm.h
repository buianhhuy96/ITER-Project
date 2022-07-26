//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgemm.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XGEMM_H
#define XGEMM_H

// Include Files
#include "rtwtypes.h"
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
void b_xgemm(int m, int h_n, int k, const double A[15][15], int ia0, int d_lda,
             const double e_B[8][15], double c_C[15][15], int ldc);

void xgemm(int m, int h_n, int k, const double A[7][7], int d_lda,
           const double e_B[15][15], int b_ib0, int ldb, double c_C[8][15]);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xgemm.h
//
// [EOF]
//
