//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

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
namespace reflapack {
void b_xzhgeqz(creal_T A[4][4], int b_ilo, int b_ihi, creal_T b_Z[4][4],
               int *info, creal_T alpha1[4], creal_T beta1[4]);

void xzhgeqz(const ::coder::array<creal_T, 2U> &A, int b_ilo, int b_ihi,
             int *info, ::coder::array<creal_T, 1U> &alpha1,
             ::coder::array<creal_T, 1U> &beta1);

} // namespace reflapack
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xzhgeqz.h
//
// [EOF]
//
