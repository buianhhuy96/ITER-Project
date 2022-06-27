//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xgeqp3.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XGEQP3_H
#define XGEQP3_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace lapack {
void b_xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
              int jpvt[8]);

void c_xgeqp3(double A[15][15], int b_m, int h_n, int jpvt[15], double tau[15]);

void xgeqp3(::coder::array<double, 2U> &A, ::coder::array<double, 1U> &tau,
            ::coder::array<int, 2U> &jpvt);

} // namespace lapack
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xgeqp3.h
//
// [EOF]
//
