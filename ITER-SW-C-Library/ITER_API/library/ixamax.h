//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ixamax.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef IXAMAX_H
#define IXAMAX_H

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
int ixamax(int h_n, const double b_x[15][15], int incx);

}
} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for ixamax.h
//
// [EOF]
//
