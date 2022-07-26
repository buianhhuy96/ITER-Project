//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef MINORMAX_H
#define MINORMAX_H

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
double b_maximum(const ::coder::array<double, 1U> &b_x);

float b_minimum(const ::coder::array<float, 1U> &b_x);

void c_maximum(const ::coder::array<double, 2U> &b_x, double b_ex[2]);

void c_minimum(const ::coder::array<double, 1U> &b_x, double *b_ex, int *idx);

double d_maximum(const ::coder::array<double, 2U> &b_x);

double d_minimum(const ::coder::array<double, 1U> &b_x);

void e_minimum(const ::coder::array<double, 2U> &b_x, double b_ex[2]);

double f_minimum(const ::coder::array<double, 2U> &b_x);

double g_minimum(const double b_x[2]);

float maximum(const float b_x[3]);

void minimum(const ::coder::array<float, 1U> &b_x, float *b_ex, int *idx);

} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
