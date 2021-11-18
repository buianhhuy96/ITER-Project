//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef MLDIVIDE_H
#define MLDIVIDE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_mldivide(const ::coder::array<double, 2U> &d_A,
                const ::coder::array<double, 1U> &c_B,
                ::coder::array<double, 1U> &h_Y);

void mldivide(const double d_A[3][3], const double c_B[3], double h_Y[3]);

} // namespace coder

#endif
//
// File trailer for mldivide.h
//
// [EOF]
//
