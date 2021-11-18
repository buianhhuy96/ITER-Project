//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesMatrixToVector.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cmath>

// Function Definitions
//
// Arguments    : double rotationMatrix[3][3]
//                double rotationVector[3]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesMatrixToVector(double rotationMatrix[3][3],
                             double rotationVector[3])
{
  double V[3][3];
  double b_U[3][3];
  double s[3];
  double absxk;
  double b_s;
  double b_t;
  double theta;
  double y;
  int b_i;
  int idx;
  int k;
  bool p;
  p = true;
  for (k = 0; k < 3; k++) {
    if (p) {
      if ((std::isinf(rotationMatrix[k][0])) ||
          (std::isnan(rotationMatrix[k][0]))) {
        p = false;
      }
    } else {
      p = false;
    }
    if (p) {
      if ((std::isinf(rotationMatrix[k][1])) ||
          (std::isnan(rotationMatrix[k][1]))) {
        p = false;
      }
    } else {
      p = false;
    }
    if (p) {
      if ((std::isinf(rotationMatrix[k][2])) ||
          (std::isnan(rotationMatrix[k][2]))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    ::Codegen::coder::internal::c_svd(rotationMatrix, b_U, s, V);
  } else {
    for (b_i = 0; b_i < 3; b_i++) {
      b_U[b_i][0] = rtNaN;
      V[b_i][0] = rtNaN;
      b_U[b_i][1] = rtNaN;
      V[b_i][1] = rtNaN;
      b_U[b_i][2] = rtNaN;
      V[b_i][2] = rtNaN;
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    y = b_U[0][b_i];
    b_s = b_U[1][b_i];
    absxk = b_U[2][b_i];
    for (idx = 0; idx < 3; idx++) {
      rotationMatrix[idx][b_i] =
          ((y * V[0][idx]) + (b_s * V[1][idx])) + (absxk * V[2][idx]);
    }
  }
  b_t = (rotationMatrix[0][0] + rotationMatrix[1][1]) + rotationMatrix[2][2];
  theta = std::acos((b_t - 1.0) / 2.0);
  rotationVector[0] = rotationMatrix[1][2] - rotationMatrix[2][1];
  rotationVector[1] = rotationMatrix[2][0] - rotationMatrix[0][2];
  rotationVector[2] = rotationMatrix[0][1] - rotationMatrix[1][0];
  y = std::sin(theta);
  if (y >= 0.0001) {
    b_s = 1.0 / (2.0 * y);
    rotationVector[0] = theta * (rotationVector[0] * b_s);
    rotationVector[1] = theta * (rotationVector[1] * b_s);
    rotationVector[2] = theta * (rotationVector[2] * b_s);
  } else if ((b_t - 1.0) > 0.0) {
    b_s = 0.5 - ((b_t - 3.0) / 12.0);
    rotationVector[0] *= b_s;
    rotationVector[1] *= b_s;
    rotationVector[2] *= b_s;
  } else {
    int iindx;
    s[0] = rotationMatrix[0][0];
    s[1] = rotationMatrix[1][1];
    s[2] = rotationMatrix[2][2];
    if (!std::isnan(rotationMatrix[0][0])) {
      idx = 1;
    } else {
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!std::isnan(s[k - 1])) {
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
      b_s = s[idx - 1];
      iindx = idx - 1;
      b_i = idx + 1;
      for (k = b_i; k < 4; k++) {
        y = s[k - 1];
        if (b_s < y) {
          b_s = y;
          iindx = k - 1;
        }
      }
    }
    idx = static_cast<int>(std::fmod((static_cast<double>(iindx)) + 1.0, 3.0));
    k = static_cast<int>(
        std::fmod(((static_cast<double>(iindx)) + 1.0) + 1.0, 3.0));
    b_s = std::sqrt(((rotationMatrix[iindx][iindx] - rotationMatrix[idx][idx]) -
                     rotationMatrix[k][k]) +
                    1.0);
    rotationVector[0] = 0.0;
    rotationVector[1] = 0.0;
    rotationVector[2] = 0.0;
    rotationVector[iindx] = b_s / 2.0;
    rotationVector[idx] =
        (rotationMatrix[iindx][idx] + rotationMatrix[idx][iindx]) / (2.0 * b_s);
    rotationVector[k] =
        (rotationMatrix[iindx][k] + rotationMatrix[k][iindx]) / (2.0 * b_s);
    b_s = 3.3121686421112381E-170;
    absxk = std::abs(rotationVector[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      b_s = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      y = b_t * b_t;
    }
    absxk = std::abs(rotationVector[1]);
    if (absxk > b_s) {
      b_t = b_s / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      b_s = absxk;
    } else {
      b_t = absxk / b_s;
      y += b_t * b_t;
    }
    absxk = std::abs(rotationVector[2]);
    if (absxk > b_s) {
      b_t = b_s / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      b_s = absxk;
    } else {
      b_t = absxk / b_s;
      y += b_t * b_t;
    }
    y = b_s * std::sqrt(y);
    rotationVector[0] = (theta * rotationVector[0]) / y;
    rotationVector[1] = (theta * rotationVector[1]) / y;
    rotationVector[2] = (theta * rotationVector[2]) / y;
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for rodriguesMatrixToVector.cpp
//
// [EOF]
//
