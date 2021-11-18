//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesVectorToMatrix.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double rotationVector[3]
//                double rotationMatrix[3][3]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesVectorToMatrix(const double rotationVector[3],
                             double rotationMatrix[3][3])
{
  double d_u[3][3];
  double c_u[3];
  double u[3];
  double absxk;
  double b_t;
  double scale;
  double theta;
  signed char b_a[3][3];
  scale = 3.3121686421112381E-170;
  absxk = std::abs(rotationVector[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta = 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    theta = b_t * b_t;
  }
  absxk = std::abs(rotationVector[1]);
  if (absxk > scale) {
    b_t = scale / absxk;
    theta = ((theta * b_t) * b_t) + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    theta += b_t * b_t;
  }
  absxk = std::abs(rotationVector[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    theta = ((theta * b_t) * b_t) + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    theta += b_t * b_t;
  }
  theta = scale * std::sqrt(theta);
  if (theta < 1.0E-6) {
    for (int k{0}; k < 3; k++) {
      rotationMatrix[k][0] = 0.0;
      rotationMatrix[k][1] = 0.0;
      rotationMatrix[k][2] = 0.0;
    }
    rotationMatrix[0][0] = 1.0;
    rotationMatrix[1][1] = 1.0;
    rotationMatrix[2][2] = 1.0;
  } else {
    int k;
    scale = std::cos(theta);
    absxk = std::sin(theta);
    for (k = 0; k < 3; k++) {
      b_t = rotationVector[k] / theta;
      c_u[k] = b_t;
      u[k] = b_t;
      b_a[k][0] = 0;
      b_a[k][1] = 0;
      b_a[k][2] = 0;
    }
    rotationMatrix[0][0] = absxk * 0.0;
    rotationMatrix[1][0] = absxk * (-u[2]);
    rotationMatrix[2][0] = absxk * u[1];
    rotationMatrix[0][1] = absxk * u[2];
    rotationMatrix[1][1] = absxk * 0.0;
    rotationMatrix[2][1] = absxk * (-u[0]);
    rotationMatrix[0][2] = absxk * (-u[1]);
    rotationMatrix[1][2] = absxk * u[0];
    rotationMatrix[2][2] = absxk * 0.0;
    for (k = 0; k < 3; k++) {
      b_a[k][k] = 1;
      d_u[k][0] = c_u[0] * c_u[k];
      d_u[k][1] = c_u[1] * c_u[k];
      d_u[k][2] = c_u[2] * c_u[k];
    }
    for (k = 0; k < 3; k++) {
      rotationMatrix[k][0] =
          (((static_cast<double>(b_a[k][0])) * scale) + rotationMatrix[k][0]) +
          ((1.0 - scale) * d_u[k][0]);
      rotationMatrix[k][1] =
          (((static_cast<double>(b_a[k][1])) * scale) + rotationMatrix[k][1]) +
          ((1.0 - scale) * d_u[k][1]);
      rotationMatrix[k][2] =
          (((static_cast<double>(b_a[k][2])) * scale) + rotationMatrix[k][2]) +
          ((1.0 - scale) * d_u[k][2]);
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for rodriguesVectorToMatrix.cpp
//
// [EOF]
//
