//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rodriguesVectorToMatrix.cpp
//
// Code generation for function 'rodriguesVectorToMatrix'
//

// Include files
#include "rodriguesVectorToMatrix.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <cstring>

// Function Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void rodriguesVectorToMatrix(const real_T rotationVector[3],
                             real_T rotationMatrix[9])
{
  real_T b_u[9];
  real_T u[3];
  real_T absxk;
  real_T scale;
  real_T t;
  real_T theta;
  int8_T a[9];
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(rotationVector[0]);
  if (absxk > 3.3121686421112381E-170) {
    theta = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    theta = t * t;
  }
  absxk = muDoubleScalarAbs(rotationVector[1]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }
  absxk = muDoubleScalarAbs(rotationVector[2]);
  if (absxk > scale) {
    t = scale / absxk;
    theta = theta * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    theta += t * t;
  }
  theta = scale * muDoubleScalarSqrt(theta);
  if (theta < 1.0E-6) {
    std::memset(&rotationMatrix[0], 0, 9U * sizeof(real_T));
    rotationMatrix[0] = 1.0;
    rotationMatrix[4] = 1.0;
    rotationMatrix[8] = 1.0;
  } else {
    real_T alpha;
    real_T u_tmp;
    int32_T k;
    absxk = rotationVector[0] / theta;
    u[0] = absxk;
    t = rotationVector[1] / theta;
    u[1] = t;
    u_tmp = rotationVector[2] / theta;
    u[2] = u_tmp;
    alpha = muDoubleScalarCos(theta);
    scale = muDoubleScalarSin(theta);
    for (k = 0; k < 9; k++) {
      a[k] = 0;
    }
    rotationMatrix[0] = scale * 0.0;
    rotationMatrix[3] = scale * -u_tmp;
    rotationMatrix[6] = scale * t;
    rotationMatrix[1] = scale * u_tmp;
    rotationMatrix[4] = scale * 0.0;
    rotationMatrix[7] = scale * -absxk;
    rotationMatrix[2] = scale * -t;
    rotationMatrix[5] = scale * absxk;
    rotationMatrix[8] = scale * 0.0;
    for (k = 0; k < 3; k++) {
      a[k + 3 * k] = 1;
      scale = u[k];
      b_u[3 * k] = absxk * scale;
      b_u[3 * k + 1] = t * scale;
      b_u[3 * k + 2] = u_tmp * scale;
    }
    for (k = 0; k < 9; k++) {
      rotationMatrix[k] =
          (static_cast<real_T>(a[k]) * alpha + rotationMatrix[k]) +
          (1.0 - alpha) * b_u[k];
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (rodriguesVectorToMatrix.cpp)
