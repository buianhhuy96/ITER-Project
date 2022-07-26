//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzgeqp3.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XZGEQP3_H
#define XZGEQP3_H

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
namespace reflapack {
void qrf(double A[15][15], int m, int h_n, int nfxd, double tau[15]);

}
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xzgeqp3.h
//
// [EOF]
//
