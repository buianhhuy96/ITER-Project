//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SVD1_H
#define SVD1_H

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
void c_svd(const double A[29][29], double U[29][29], double s[29],
           double V[29][29]);

void d_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U);

void e_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           ::coder::array<double, 1U> &s, double V[6][6]);

void f_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3]);

void g_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           ::coder::array<double, 1U> &s, double V[3][3]);

void h_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9]);

} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for svd1.h
//
// [EOF]
//
