//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
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
namespace coder {
namespace internal {
namespace blas {
void b_xaxpy(int h_n, double b_a, const ::coder::array<double, 1U> &b_x,
             int ix0, ::coder::array<double, 2U> &y, int iy0);

void c_xaxpy(int h_n, double b_a, int ix0, ::coder::array<double, 2U> &y,
             int iy0);

void d_xaxpy(int h_n, double b_a, int ix0, double y[6][6], int iy0);

void e_xaxpy(int h_n, double b_a, int ix0, double y[3][3], int iy0);

void f_xaxpy(int h_n, double b_a, int ix0, double y[9][9], int iy0);

void g_xaxpy(int h_n, double b_a, const double b_x[9][9], int ix0, double y[9],
             int iy0);

void h_xaxpy(int h_n, double b_a, const double b_x[9], int ix0, double y[9][9],
             int iy0);

void i_xaxpy(double b_a, const double b_x[3][3], int ix0, double y[3]);

void j_xaxpy(double b_a, const double b_x[3], double y[3][3], int iy0);

void xaxpy(int h_n, double b_a, const ::coder::array<double, 2U> &b_x, int ix0,
           ::coder::array<double, 1U> &y, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
