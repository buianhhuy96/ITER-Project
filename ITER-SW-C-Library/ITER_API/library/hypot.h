//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hypot.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef HYPOT_H
#define HYPOT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_hypot(const ::coder::array<float, 1U> &b_x,
             const ::coder::array<float, 1U> &y, ::coder::array<float, 1U> &r);

void c_hypot(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y,
             ::coder::array<double, 1U> &r);

} // namespace coder

#endif
//
// File trailer for hypot.h
//
// [EOF]
//
