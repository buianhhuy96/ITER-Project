//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rodriguesVectorToMatrix.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double rotationVector[3]
//                double rotationMatrix[3][3]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesVectorToMatrix(const double rotationVector[3],
                             double rotationMatrix[3][3])
{
  double c_a[3][3];
  double e_u[3][3];
  double c_u[3];
  double d_u[3];
  double absxk;
  double b_t;
  double scale;
  double theta;
  double u_tmp;
  signed char d_a[3][3];
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
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < 3; b_i++) {
      rotationMatrix[b_i][0] = 0.0;
      rotationMatrix[b_i][1] = 0.0;
      rotationMatrix[b_i][2] = 0.0;
    }
    rotationMatrix[0][0] = 1.0;
    rotationMatrix[1][1] = 1.0;
    rotationMatrix[2][2] = 1.0;
  } else {
    double alpha;
    double b_a;
    double d;
    alpha = std::cos(theta);
    b_a = std::sin(theta);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(u_tmp)

    for (int i1 = 0; i1 < 3; i1++) {
      u_tmp = rotationVector[i1] / theta;
      d_u[i1] = u_tmp;
      c_u[i1] = u_tmp;
      d_a[i1][0] = 0;
      d_a[i1][1] = 0;
      d_a[i1][2] = 0;
    }
    c_a[0][0] = b_a * 0.0;
    c_a[1][0] = b_a * (-c_u[2]);
    c_a[2][0] = b_a * c_u[1];
    c_a[0][1] = b_a * c_u[2];
    c_a[1][1] = b_a * 0.0;
    c_a[2][1] = b_a * (-c_u[0]);
    c_a[0][2] = b_a * (-c_u[1]);
    c_a[1][2] = b_a * c_u[0];
    c_a[2][2] = b_a * 0.0;
    d = 1.0 - alpha;
    for (int k{0}; k < 3; k++) {
      d_a[k][k] = 1;
      e_u[k][0] = d_u[0] * d_u[k];
      e_u[k][1] = d_u[1] * d_u[k];
      e_u[k][2] = d_u[2] * d_u[k];
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < 3; i2++) {
      rotationMatrix[i2][0] =
          (((static_cast<double>(d_a[i2][0])) * alpha) + c_a[i2][0]) +
          (d * e_u[i2][0]);
      rotationMatrix[i2][1] =
          (((static_cast<double>(d_a[i2][1])) * alpha) + c_a[i2][1]) +
          (d * e_u[i2][1]);
      rotationMatrix[i2][2] =
          (((static_cast<double>(d_a[i2][2])) * alpha) + c_a[i2][2]) +
          (d * e_u[i2][2]);
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for rodriguesVectorToMatrix.cpp
//
// [EOF]
//
