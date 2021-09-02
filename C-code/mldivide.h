//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
void mldivide(const ::coder::array<double, 2U> &A,
              ::coder::array<double, 1U> &B);

void mldivide(const double A[3][3], const double B[3], double Y[3]);

} // namespace coder

#endif
//
// File trailer for mldivide.h
//
// [EOF]
//
