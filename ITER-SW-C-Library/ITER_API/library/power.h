//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef POWER_H
#define POWER_H

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
void b_power(const ::coder::array<int, 1U> &b_a, ::coder::array<int, 1U> &y);

void power(const ::coder::array<double, 1U> &b_a,
           ::coder::array<double, 1U> &y);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for power.h
//
// [EOF]
//
