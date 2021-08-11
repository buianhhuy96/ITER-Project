//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double S[3][3]
//                double V[3][3]
// Return Type  : void
//
namespace coder {
void b_svd(const double A[3][3], double U[3][3], double S[3][3], double V[3][3])
{
  double s[3];
  int k;
  boolean_T p;
  p = true;
  for (k = 0; k < 3; k++) {
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
    internal::d_svd(A, U, s, V);
  } else {
    for (k = 0; k < 3; k++) {
      s[k] = rtNaN;
      U[k][0] = rtNaN;
      V[k][0] = rtNaN;
      U[k][1] = rtNaN;
      V[k][1] = rtNaN;
      U[k][2] = rtNaN;
      V[k][2] = rtNaN;
    }
  }
  for (k = 0; k < 3; k++) {
    S[k][0] = 0.0;
    S[k][1] = 0.0;
    S[k][2] = 0.0;
  }
  S[0][0] = s[0];
  S[1][1] = s[1];
  S[2][2] = s[2];
}

//
// Arguments    : const double A[29][29]
//                double U[29][29]
//                double S[29][29]
//                double V[29][29]
// Return Type  : void
//
void svd(const double A[29][29], double U[29][29], double S[29][29],
         double V[29][29])
{
  double s[29];
  int b_k;
  int k;
  boolean_T p;
  p = true;
  for (k = 0; k < 29; k++) {
    for (b_k = 0; b_k < 29; b_k++) {
      if (p) {
        if ((std::isinf(A[k][b_k])) || (std::isnan(A[k][b_k]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (p) {
    internal::c_svd(A, U, s, V);
  } else {
    for (k = 0; k < 29; k++) {
      s[k] = rtNaN;
      for (b_k = 0; b_k < 29; b_k++) {
        U[k][b_k] = rtNaN;
        V[k][b_k] = rtNaN;
      }
    }
  }
  (void)std::memset(&S[0][0], 0, 841U * (sizeof(double)));
  for (k = 0; k < 29; k++) {
    S[k][k] = s[k];
  }
}

} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
