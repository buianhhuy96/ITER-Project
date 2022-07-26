//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef MEAN_H
#define MEAN_H

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
void b_mean(const ::coder::array<double, 2U> &b_x,
            ::coder::array<double, 2U> &y);

void c_mean(const ::coder::array<double, 2U> &b_x, double y[2]);

float mean(const ::coder::array<float, 1U> &b_x);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for mean.h
//
// [EOF]
//
