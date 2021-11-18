//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2AXPYValidCMP.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

#ifndef CONV2AXPYVALIDCMP_H
#define CONV2AXPYVALIDCMP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
                         ::coder::array<double, 2U> &c);

void c_conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
                         ::coder::array<double, 2U> &c);

void conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
                       ::coder::array<double, 2U> &c);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for conv2AXPYValidCMP.h
//
// [EOF]
//
