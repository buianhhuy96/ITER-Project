//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
real_T b_maximum(const ::coder::array<real_T, 1U> &b_x);

void b_minimum(const ::coder::array<real_T, 1U> &b_x, real_T *ex, int32_T *idx);

real32_T maximum(const real32_T b_x[3]);

void minimum(const ::coder::array<real32_T, 1U> &b_x, real32_T *ex,
             int32_T *idx);

} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for minOrMax.h
//
// [EOF]
//
