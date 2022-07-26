//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xswap.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XSWAP_H
#define XSWAP_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
namespace internal {
namespace blas {
void b_xswap(double b_x[6][6], int ix0, int iy0);

void c_xswap(double b_x[3][3], int ix0, int iy0);

void d_xswap(double b_x[9][9], int ix0, int iy0);

void xswap(double b_x[29][29], int ix0, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xswap.h
//
// [EOF]
//
