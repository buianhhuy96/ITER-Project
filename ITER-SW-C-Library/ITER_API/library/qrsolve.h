//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef QRSOLVE_H
#define QRSOLVE_H

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
namespace internal {
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &e_B,
             ::coder::array<double, 1U> &g_Y, int *rankA);

}
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for qrsolve.h
//
// [EOF]
//
