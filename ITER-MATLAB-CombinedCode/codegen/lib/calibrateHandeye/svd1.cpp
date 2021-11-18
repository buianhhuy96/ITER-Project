//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "svd1.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double e_S[3][3]
//                double V[3][3]
// Return Type  : void
//
namespace coder {
void svd(const double A[3][3], double U[3][3], double e_S[3][3], double V[3][3])
{
  double s[3];
  bool p;
  p = true;
  for (int k{0}; k < 3; k++) {
    if (p) {
      if ((std::isinf(A[k][0])) || (std::isnan(A[k][0]))) {
        p = false;
      }
    } else {
      p = false;
    }
    if (p) {
      if ((std::isinf(A[k][1])) || (std::isnan(A[k][1]))) {
        p = false;
      }
    } else {
      p = false;
    }
    if (p) {
      if ((std::isinf(A[k][2])) || (std::isnan(A[k][2]))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    internal::c_svd(A, U, s, V);
  } else {
    for (int b_i{0}; b_i < 3; b_i++) {
      s[b_i] = rtNaN;
      U[b_i][0] = rtNaN;
      V[b_i][0] = rtNaN;
      U[b_i][1] = rtNaN;
      V[b_i][1] = rtNaN;
      U[b_i][2] = rtNaN;
      V[b_i][2] = rtNaN;
    }
  }
  for (int c_i{0}; c_i < 3; c_i++) {
    e_S[c_i][0] = 0.0;
    e_S[c_i][1] = 0.0;
    e_S[c_i][2] = 0.0;
  }
  e_S[0][0] = s[0];
  e_S[1][1] = s[1];
  e_S[2][2] = s[2];
}

} // namespace coder

//
// File trailer for svd1.cpp
//
// [EOF]
//
