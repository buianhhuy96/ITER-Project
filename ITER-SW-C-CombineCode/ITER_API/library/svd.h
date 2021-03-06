//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

#ifndef SVD_H
#define SVD_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U);

void c_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &U,
           ::coder::array<double, 1U> &s, double V[6][6]);

void d_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3]);

void e_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9]);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for svd.h
//
// [EOF]
//
