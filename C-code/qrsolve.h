//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef QRSOLVE_H
#define QRSOLVE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void LSQFromQR(const ::coder::array<double, 2U> &A,
               const ::coder::array<double, 1U> &tau,
               const ::coder::array<int, 2U> &jpvt,
               ::coder::array<double, 1U> &B, int rankA,
               ::coder::array<double, 1U> &Y);

void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &B, ::coder::array<double, 1U> &Y,
             int *rankA);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for qrsolve.h
//
// [EOF]
//