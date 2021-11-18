//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesMatrixToVector.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "rodriguesMatrixToVector.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double rotationMatrix[3][3]
//                double rotationVector[3]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(double rotationMatrix[3][3],
                             double rotationVector[3])
{
  double a__1[3][3];
  double d_U[3][3];
  double e_V[3][3];
  double v[3];
  double varargin_1[3];
  double b_t;
  double d3;
  double r_idx_0;
  double r_idx_1;
  double r_idx_2;
  double theta;
  svd(rotationMatrix, d_U, a__1, e_V);
  for (int b_i{0}; b_i < 3; b_i++) {
    double b_d1;
    double d;
    double d2;
    d = d_U[0][b_i];
    b_d1 = d_U[1][b_i];
    d2 = d_U[2][b_i];
    for (int i1{0}; i1 < 3; i1++) {
      rotationMatrix[i1][b_i] =
          ((d * e_V[0][i1]) + (b_d1 * e_V[1][i1])) + (d2 * e_V[2][i1]);
    }
  }
  b_t = (rotationMatrix[0][0] + rotationMatrix[1][1]) + rotationMatrix[2][2];
  theta = std::acos((b_t - 1.0) / 2.0);
  r_idx_0 = rotationMatrix[1][2] - rotationMatrix[2][1];
  r_idx_1 = rotationMatrix[2][0] - rotationMatrix[0][2];
  r_idx_2 = rotationMatrix[0][1] - rotationMatrix[1][0];
  d3 = std::sin(theta);
  if (d3 >= 0.0001) {
    double b;
    b = 1.0 / (2.0 * d3);
    rotationVector[0] = theta * (r_idx_0 * b);
    rotationVector[1] = theta * (r_idx_1 * b);
    rotationVector[2] = theta * (r_idx_2 * b);
  } else if ((b_t - 1.0) > 0.0) {
    double a;
    a = 0.5 - ((b_t - 3.0) / 12.0);
    rotationVector[0] = a * r_idx_0;
    rotationVector[1] = a * r_idx_1;
    rotationVector[2] = a * r_idx_2;
  } else {
    double absxk;
    double b_b;
    double c;
    double c_t;
    double s;
    double scale;
    double y;
    int idx;
    int iindx;
    varargin_1[0] = rotationMatrix[0][0];
    varargin_1[1] = rotationMatrix[1][1];
    varargin_1[2] = rotationMatrix[2][2];
    if (!std::isnan(rotationMatrix[0][0])) {
      idx = 1;
    } else {
      int k;
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!std::isnan(varargin_1[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      iindx = 0;
    } else {
      double b_ex;
      int i2;
      b_ex = varargin_1[idx - 1];
      iindx = idx - 1;
      i2 = idx + 1;
      for (int b_k{i2}; b_k < 4; b_k++) {
        double d4;
        d4 = varargin_1[b_k - 1];
        if (b_ex < d4) {
          b_ex = d4;
          iindx = b_k - 1;
        }
      }
    }
    b_b = b_mod((static_cast<double>(iindx)) + 1.0, 3.0) + 1.0;
    c = b_mod(((static_cast<double>(iindx)) + 1.0) + 1.0, 3.0) + 1.0;
    s = std::sqrt(
        ((rotationMatrix[iindx][iindx] -
          rotationMatrix[(static_cast<int>(b_b)) - 1]
                        [(static_cast<int>(b_b)) - 1]) -
         rotationMatrix[(static_cast<int>(c)) - 1][(static_cast<int>(c)) - 1]) +
        1.0);
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    v[iindx] = s / 2.0;
    v[(static_cast<int>(b_b)) - 1] =
        (rotationMatrix[iindx][(static_cast<int>(b_b)) - 1] +
         rotationMatrix[(static_cast<int>(b_b)) - 1][iindx]) /
        (2.0 * s);
    v[(static_cast<int>(c)) - 1] =
        (rotationMatrix[iindx][(static_cast<int>(c)) - 1] +
         rotationMatrix[(static_cast<int>(c)) - 1][iindx]) /
        (2.0 * s);
    scale = 3.3121686421112381E-170;
    absxk = std::abs(v[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      c_t = absxk / 3.3121686421112381E-170;
      y = c_t * c_t;
    }
    absxk = std::abs(v[1]);
    if (absxk > scale) {
      c_t = scale / absxk;
      y = ((y * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      y += c_t * c_t;
    }
    absxk = std::abs(v[2]);
    if (absxk > scale) {
      c_t = scale / absxk;
      y = ((y * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      y += c_t * c_t;
    }
    y = scale * std::sqrt(y);
    rotationVector[0] = (theta * v[0]) / y;
    rotationVector[1] = (theta * v[1]) / y;
    rotationVector[2] = (theta * v[2]) / y;
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for rodriguesMatrixToVector.cpp
//
// [EOF]
//
