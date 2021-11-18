//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
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
namespace Codegen {
namespace coder {
namespace internal {
void b_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 2U> &b_U,
           ::coder::array<double, 1U> &s, double V[6][6]);

void c_svd(const double A[3][3], double b_U[3][3], double s[3], double V[3][3]);

void svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &b_U);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for svd.h
//
// [EOF]
//
