//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int32_T g_n
//                const real_T b_x[3][3]
//                int32_T ix0
//                const real_T y[3][3]
//                int32_T iy0
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
real_T b_xdotc(int32_T g_n, const real_T b_x[3][3], int32_T ix0,
               const real_T y[3][3], int32_T iy0)
{
  real_T d;
  d = 0.0;
  for (int32_T k{0}; k < g_n; k++) {
    d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
  }
  return d;
}

//
// Arguments    : int32_T g_n
//                const real_T b_x[6][6]
//                int32_T ix0
//                const real_T y[6][6]
//                int32_T iy0
// Return Type  : real_T
//
real_T xdotc(int32_T g_n, const real_T b_x[6][6], int32_T ix0,
             const real_T y[6][6], int32_T iy0)
{
  real_T d;
  d = 0.0;
  for (int32_T k{0}; k < g_n; k++) {
    d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xdotc.cpp
//
// [EOF]
//
