//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
               ::coder::array<double, 1U> &b_B, int rankA,
               ::coder::array<double, 1U> &g_Y);

void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &b_B,
             ::coder::array<double, 1U> &g_Y, int *rankA);

} // namespace internal
} // namespace coder

#endif
//
// File trailer for qrsolve.h
//
// [EOF]
//
