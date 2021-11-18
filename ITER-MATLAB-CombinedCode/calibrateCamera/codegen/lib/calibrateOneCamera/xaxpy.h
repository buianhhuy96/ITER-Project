//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef XAXPY_H
#define XAXPY_H

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
namespace blas {
void b_xaxpy(int g_n, double b_a, int ix0, double y[6][6], int iy0);

void c_xaxpy(int g_n, double b_a, int ix0, double y[3][3], int iy0);

void d_xaxpy(double b_a, const double b_x[3][3], int ix0, double y[3]);

void e_xaxpy(double b_a, const double b_x[3], double y[3][3], int iy0);

void xaxpy(int g_n, double b_a, int ix0, ::coder::array<double, 2U> &y,
           int iy0);

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
