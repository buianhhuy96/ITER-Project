//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesMatrixToVector.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double rotationMatrix[3][3]
//                double rotationVector[3]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(double rotationMatrix[3][3],
                             double rotationVector[3])
{
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double e_v[3];
  double varargin_1[3];
  double b_d1;
  double b_t;
  double d;
  double d2;
  double d3;
  double d4;
  double r_idx_0;
  double r_idx_1;
  double r_idx_2;
  double theta;
  int i1;
  b_svd(rotationMatrix, U, a__1, V);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d, i1, d2, \
                                                                    d3, d4)

  for (int b_i = 0; b_i < 3; b_i++) {
    d2 = U[0][b_i];
    d3 = U[1][b_i];
    d4 = U[2][b_i];
    for (i1 = 0; i1 < 3; i1++) {
      d = ((d2 * V[0][i1]) + (d3 * V[1][i1])) + (d4 * V[2][i1]);
      rotationMatrix[i1][b_i] = d;
    }
  }
  b_t = (rotationMatrix[0][0] + rotationMatrix[1][1]) + rotationMatrix[2][2];
  theta = std::acos((b_t - 1.0) / 2.0);
  r_idx_0 = rotationMatrix[1][2] - rotationMatrix[2][1];
  r_idx_1 = rotationMatrix[2][0] - rotationMatrix[0][2];
  r_idx_2 = rotationMatrix[0][1] - rotationMatrix[1][0];
  b_d1 = std::sin(theta);
  if (b_d1 >= 0.0001) {
    double b;
    b = 1.0 / (2.0 * b_d1);
    rotationVector[0] = theta * (r_idx_0 * b);
    rotationVector[1] = theta * (r_idx_1 * b);
    rotationVector[2] = theta * (r_idx_2 * b);
  } else if ((b_t - 1.0) > 0.0) {
    double b_a;
    b_a = 0.5 - ((b_t - 3.0) / 12.0);
    rotationVector[0] = b_a * r_idx_0;
    rotationVector[1] = b_a * r_idx_1;
    rotationVector[2] = b_a * r_idx_2;
  } else {
    double absxk;
    double d_t;
    double s;
    double scale;
    double y;
    int c_r;
    int idx;
    int iindx;
    int r;
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
        double d5;
        d5 = varargin_1[b_k - 1];
        if (b_ex < d5) {
          b_ex = d5;
          iindx = b_k - 1;
        }
      }
    }
    r = static_cast<int>(std::fmod((static_cast<double>(iindx)) + 1.0, 3.0));
    c_r = static_cast<int>(
        std::fmod(((static_cast<double>(iindx)) + 1.0) + 1.0, 3.0));
    s = std::sqrt(((rotationMatrix[iindx][iindx] - rotationMatrix[r][r]) -
                   rotationMatrix[c_r][c_r]) +
                  1.0);
    e_v[0] = 0.0;
    e_v[1] = 0.0;
    e_v[2] = 0.0;
    e_v[iindx] = s / 2.0;
    e_v[r] = (rotationMatrix[iindx][r] + rotationMatrix[r][iindx]) / (2.0 * s);
    e_v[c_r] =
        (rotationMatrix[iindx][c_r] + rotationMatrix[c_r][iindx]) / (2.0 * s);
    scale = 3.3121686421112381E-170;
    absxk = std::abs(e_v[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      d_t = absxk / 3.3121686421112381E-170;
      y = d_t * d_t;
    }
    absxk = std::abs(e_v[1]);
    if (absxk > scale) {
      d_t = scale / absxk;
      y = ((y * d_t) * d_t) + 1.0;
      scale = absxk;
    } else {
      d_t = absxk / scale;
      y += d_t * d_t;
    }
    absxk = std::abs(e_v[2]);
    if (absxk > scale) {
      d_t = scale / absxk;
      y = ((y * d_t) * d_t) + 1.0;
      scale = absxk;
    } else {
      d_t = absxk / scale;
      y += d_t * d_t;
    }
    y = scale * std::sqrt(y);
    rotationVector[0] = (theta * e_v[0]) / y;
    rotationVector[1] = (theta * e_v[1]) / y;
    rotationVector[2] = (theta * e_v[2]) / y;
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for rodriguesMatrixToVector.cpp
//
// [EOF]
//
