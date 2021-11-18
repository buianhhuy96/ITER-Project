//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int c_n
//                const double b_x[9][9]
//                int ix0
//                const double y[9][9]
//                int iy0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double b_xdotc(int c_n, const double b_x[9][9], int ix0, const double y[9][9],
               int iy0)
{
  double d;
  d = 0.0;
  if (c_n >= 1) {
    for (int k{0}; k < c_n; k++) {
      d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
    }
  }
  return d;
}

//
// Arguments    : int c_n
//                const double b_x[3][3]
//                int ix0
//                const double y[3][3]
//                int iy0
// Return Type  : double
//
double xdotc(int c_n, const double b_x[3][3], int ix0, const double y[3][3],
             int iy0)
{
  double d;
  d = 0.0;
  if (c_n >= 1) {
    for (int k{0}; k < c_n; k++) {
      d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
    }
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xdotc.cpp
//
// [EOF]
//
