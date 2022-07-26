//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hypot.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef HYPOT_H
#define HYPOT_H

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
void b_hypot(const ::coder::array<float, 1U> &b_x,
             const ::coder::array<float, 1U> &y, ::coder::array<float, 1U> &r);

void c_hypot(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y,
             ::coder::array<double, 1U> &r);

} // namespace coder
} // namespace ITER

#endif
//
// File trailer for hypot.h
//
// [EOF]
//
