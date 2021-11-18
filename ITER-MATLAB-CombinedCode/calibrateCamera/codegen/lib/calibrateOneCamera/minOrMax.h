//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef MINORMAX_H
#define MINORMAX_H

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
double b_maximum(const ::coder::array<double, 1U> &b_x);

void b_minimum(const ::coder::array<double, 1U> &b_x, double *ex, int *idx);

float maximum(const float b_x[3]);

void minimum(const ::coder::array<float, 1U> &b_x, float *ex, int *idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
