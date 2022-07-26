//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SUM_H
#define SUM_H

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
void b_sum(const double b_x[3][4], double y[4]);

void sum(const ::coder::array<double, 2U> &b_x, ::coder::array<double, 1U> &y);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for sum.h
//
// [EOF]
//
