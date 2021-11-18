//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef SORT_H
#define SORT_H

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
void b_sort(::coder::array<int, 1U> &b_x, ::coder::array<int, 1U> &idx);

void c_sort(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx);

void d_sort(double b_x[4]);

void sort(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for sort.h
//
// [EOF]
//
