//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xpotrf.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef XPOTRF_H
#define XPOTRF_H

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
namespace lapack {
int xpotrf(int h_n, double A[15][15], int d_lda);

}
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for xpotrf.h
//
// [EOF]
//
