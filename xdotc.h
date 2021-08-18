//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef XDOTC_H
#define XDOTC_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
double b_xdotc(int n, const double x[9][9], int ix0, const double y[9][9],
               int iy0);

double xdotc(int n, const double x[3][3], int ix0, const double y[3][3],
             int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xdotc.h
//
// [EOF]
//