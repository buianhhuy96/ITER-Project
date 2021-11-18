//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int h_n
//                const double b_x[3][3]
//                int ix0
//                const double y[3][3]
//                int iy0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double b_xdotc(int h_n, const double b_x[3][3], int ix0, const double y[3][3],
               int iy0)
{
  double d;
  d = 0.0;
  if (h_n >= 1) {
    for (int k{0}; k < h_n; k++) {
      d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
    }
  }
  return d;
}

//
// Arguments    : int h_n
//                const double b_x[9][9]
//                int ix0
//                const double y[9][9]
//                int iy0
// Return Type  : double
//
double c_xdotc(int h_n, const double b_x[9][9], int ix0, const double y[9][9],
               int iy0)
{
  double d;
  d = 0.0;
  if (h_n >= 1) {
    for (int k{0}; k < h_n; k++) {
      d += (&b_x[0][0])[(ix0 + k) - 1] * (&y[0][0])[(iy0 + k) - 1];
    }
  }
  return d;
}

//
// Arguments    : int h_n
//                const double b_x[6][6]
//                int ix0
//                const double y[6][6]
//                int iy0
// Return Type  : double
//
double xdotc(int h_n, const double b_x[6][6], int ix0, const double y[6][6],
             int iy0)
{
  double d;
  d = 0.0;
  if (h_n >= 1) {
    for (int k{0}; k < h_n; k++) {
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
