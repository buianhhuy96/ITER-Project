//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
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
void b_mldivide(const double A[3][3], const double c_B[3][3], double g_Y[3][3]);

void c_mldivide(const double A[3][3], const double c_B[3], double g_Y[3]);

void d_mldivide(const ::coder::array<double, 2U> &A,
                const ::coder::array<double, 1U> &c_B,
                ::coder::array<double, 1U> &g_Y);

void mldivide(const ::coder::array<double, 2U> &A,
              const ::coder::array<double, 1U> &c_B,
              ::coder::array<double, 1U> &g_Y);

} // namespace coder

#endif
//
// File trailer for mldivide.h
//
// [EOF]
//
