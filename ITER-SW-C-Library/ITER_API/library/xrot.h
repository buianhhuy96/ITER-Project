//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xrot.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XROT_H
#define XROT_H

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
void b_xrot(double b_x[6][6], int ix0, int iy0, double c, double s);

void c_xrot(double b_x[3][3], int ix0, int iy0, double c, double s);

void d_xrot(double b_x[9][9], int ix0, int iy0, double c, double s);

void xrot(double b_x[29][29], int ix0, int iy0, double c, double s);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xrot.h
//
// [EOF]
//
