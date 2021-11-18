//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XAXPY_H
#define XAXPY_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int32_T g_n, real_T b_a, int32_T ix0, real_T y[6][6], int32_T iy0);

void c_xaxpy(int32_T g_n, real_T b_a, int32_T ix0, real_T y[3][3], int32_T iy0);

void d_xaxpy(real_T b_a, const real_T b_x[3][3], int32_T ix0, real_T y[3]);

void e_xaxpy(real_T b_a, const real_T b_x[3], real_T y[3][3], int32_T iy0);

void xaxpy(int32_T g_n, real_T b_a, int32_T ix0, ::coder::array<real_T, 2U> &y,
           int32_T iy0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
