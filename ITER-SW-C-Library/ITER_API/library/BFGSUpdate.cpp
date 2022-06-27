//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: BFGSUpdate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "BFGSUpdate.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : int b_nvar
//                double g_Bk[7][7]
//                const double b_sk[8]
//                double b_yk[8]
//                double workspace[8][15]
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
bool BFGSUpdate(int b_nvar, double g_Bk[7][7], const double b_sk[8],
                double b_yk[8], double workspace[8][15])
{
  double curvatureS;
  double dotSY;
  bool b_success;
  bool success;
  dotSY = 0.0;
  if (b_nvar >= 1) {
    for (int k{0}; k < b_nvar; k++) {
      dotSY += b_sk[k] * b_yk[k];
    }
  }
  if (b_nvar != 0) {
    int b_i;
    int b_ix;
    if ((static_cast<int>(b_nvar < 4)) != 0) {
      for (int b_iy{0}; b_iy < b_nvar; b_iy++) {
        (&workspace[0][0])[b_iy] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_iy = 0; b_iy < b_nvar; b_iy++) {
        (&workspace[0][0])[b_iy] = 0.0;
      }
    }
    b_ix = 0;
    b_i = (7 * (b_nvar - 1)) + 1;
    for (int iac{1}; iac <= b_i; iac += 7) {
      int i1;
      i1 = (iac + b_nvar) - 1;
      for (int ia{iac}; ia <= i1; ia++) {
        int i2;
        i2 = ia - iac;
        (&workspace[0][0])[i2] += (&g_Bk[0][0])[ia - 1] * b_sk[b_ix];
      }
      b_ix++;
    }
  }
  curvatureS = 0.0;
  if (b_nvar >= 1) {
    for (int b_k{0}; b_k < b_nvar; b_k++) {
      curvatureS += b_sk[b_k] * (&workspace[0][0])[b_k];
    }
  }
  if (dotSY < (0.2 * curvatureS)) {
    double theta;
    theta = (0.8 * curvatureS) / (curvatureS - dotSY);
    if ((static_cast<int>(b_nvar < 4)) != 0) {
      for (int c_k{0}; c_k < b_nvar; c_k++) {
        b_yk[c_k] *= theta;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_k = 0; c_k < b_nvar; c_k++) {
        b_yk[c_k] *= theta;
      }
    }
    if ((b_nvar >= 1) && (!((1.0 - theta) == 0.0))) {
      int ixlast;
      ixlast = b_nvar - 1;
      for (int d_k{0}; d_k <= ixlast; d_k++) {
        b_yk[d_k] += (1.0 - theta) * (&workspace[0][0])[d_k];
      }
    }
    dotSY = 0.0;
    if (b_nvar >= 1) {
      for (int e_k{0}; e_k < b_nvar; e_k++) {
        dotSY += b_sk[e_k] * b_yk[e_k];
      }
    }
  }
  if ((curvatureS > 2.2204460492503131E-16) &&
      (dotSY > 2.2204460492503131E-16)) {
    b_success = true;
  } else {
    b_success = false;
  }
  success = b_success;
  if (b_success) {
    double alpha1;
    double b_alpha1;
    alpha1 = -1.0 / curvatureS;
    if (!(alpha1 == 0.0)) {
      int jA;
      jA = 0;
      for (int j{0}; j < b_nvar; j++) {
        if ((&workspace[0][0])[j] != 0.0) {
          double temp;
          int i3;
          int i4;
          temp = (&workspace[0][0])[j] * alpha1;
          i3 = jA + 1;
          i4 = b_nvar + jA;
          for (int ijA{i3}; ijA <= i4; ijA++) {
            (&g_Bk[0][0])[ijA - 1] += (&workspace[0][0])[(ijA - jA) - 1] * temp;
          }
        }
        jA += 7;
      }
    }
    b_alpha1 = 1.0 / dotSY;
    if (!(b_alpha1 == 0.0)) {
      int b_jA;
      b_jA = 0;
      for (int b_j{0}; b_j < b_nvar; b_j++) {
        if (b_yk[b_j] != 0.0) {
          double b_temp;
          int i5;
          int i6;
          b_temp = b_yk[b_j] * b_alpha1;
          i5 = b_jA + 1;
          i6 = b_nvar + b_jA;
          for (int b_ijA{i5}; b_ijA <= i6; b_ijA++) {
            (&g_Bk[0][0])[b_ijA - 1] += b_yk[(b_ijA - b_jA) - 1] * b_temp;
          }
        }
        b_jA += 7;
      }
    }
  }
  return success;
}

} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for BFGSUpdate.cpp
//
// [EOF]
//
