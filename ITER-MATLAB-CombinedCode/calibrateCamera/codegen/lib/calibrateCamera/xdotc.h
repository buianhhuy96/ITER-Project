//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef XDOTC_H
#define XDOTC_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
real_T b_xdotc(int32_T g_n, const real_T b_x[3][3], int32_T ix0,
               const real_T y[3][3], int32_T iy0);

real_T xdotc(int32_T g_n, const real_T b_x[6][6], int32_T ix0,
             const real_T y[6][6], int32_T iy0);

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for xdotc.h
//
// [EOF]
//
