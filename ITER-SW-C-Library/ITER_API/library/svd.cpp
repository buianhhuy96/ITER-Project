//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double c_S[3][3]
//                double V[3][3]
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_svd(const double A[3][3], double U[3][3], double c_S[3][3],
           double V[3][3])
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
    internal::f_svd(A, U, s, V);
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < 3; b_i++) {
      s[b_i] = rtNaN;
      U[b_i][0] = rtNaN;
      V[b_i][0] = rtNaN;
      U[b_i][1] = rtNaN;
      V[b_i][1] = rtNaN;
      U[b_i][2] = rtNaN;
      V[b_i][2] = rtNaN;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int c_i = 0; c_i < 3; c_i++) {
    c_S[c_i][0] = 0.0;
    c_S[c_i][1] = 0.0;
    c_S[c_i][2] = 0.0;
  }
  c_S[0][0] = s[0];
  c_S[1][1] = s[1];
  c_S[2][2] = s[2];
}

//
// Arguments    : const double A[29][29]
//                double U[29][29]
//                double c_S[29][29]
//                double V[29][29]
// Return Type  : void
//
void svd(const double A[29][29], double U[29][29], double c_S[29][29],
         double V[29][29])
{
  double s[29];
  int i1;
  int i2;
  bool p;
  p = true;
  for (int k{0}; k < 29; k++) {
    for (int b_k{0}; b_k < 29; b_k++) {
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
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < 29; b_i++) {
      s[b_i] = rtNaN;
      for (i1 = 0; i1 < 29; i1++) {
        U[b_i][i1] = rtNaN;
        V[b_i][i1] = rtNaN;
      }
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

  for (int c_i = 0; c_i < 29; c_i++) {
    for (i2 = 0; i2 < 29; i2++) {
      c_S[c_i][i2] = 0.0;
    }
  }
  for (int c_k{0}; c_k < 29; c_k++) {
    c_S[c_k][c_k] = s[c_k];
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for svd.cpp
//
// [EOF]
//
