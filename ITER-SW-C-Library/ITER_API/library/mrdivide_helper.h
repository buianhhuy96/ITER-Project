//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mrdivide_helper.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef MRDIVIDE_HELPER_H
#define MRDIVIDE_HELPER_H

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
void mrdiv(const double A[3][4], const double e_B[3][3], double g_Y[3][4]);

}
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for mrdivide_helper.h
//
// [EOF]
//
