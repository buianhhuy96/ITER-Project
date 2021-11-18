//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unserializeCalib.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "unserializeCalib.h"
#include "calibrateCamera_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &b_x
//                const struct1_T *refCalibration_CameraParameters
//                const ::coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions const ::coder::array<real_T,
//                3U> &refCalibration_ImagePoints struct1_T
//                *newCalibration_CameraParameters
//                ::coder::array<cell_wrap_0, 2U>
//                &newCalibration_PatternPositions
//                ::coder::array<real_T, 3U> &newCalibration_ImagePoints
// Return Type  : void
//
namespace Codegen {
void b_unserializeCalib(
    const ::coder::array<real_T, 2U> &b_x,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints)
{
  real_T b_a[3][3];
  real_T c_u_data[9];
  real_T b_u_data[3];
  real_T rotationVector_data[3];
  real_T t_data[3];
  real_T u_data[3];
  real_T camLength;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i1;
  int32_T loop_ub;
  int8_T c_a[3][3];
  //  Start with original values. Overwrite if changed.
  *newCalibration_CameraParameters = *refCalibration_CameraParameters;
  newCalibration_ImagePoints.set_size(refCalibration_ImagePoints.size(0),
                                      refCalibration_ImagePoints.size(1),
                                      refCalibration_ImagePoints.size(2));
  loop_ub = refCalibration_ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = refCalibration_ImagePoints.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T c_loop_ub;
      c_loop_ub = refCalibration_ImagePoints.size(0);
      for (int32_T i2{0}; i2 < c_loop_ub; i2++) {
        newCalibration_ImagePoints[(i2 +
                                    (newCalibration_ImagePoints.size(0) * i1)) +
                                   ((newCalibration_ImagePoints.size(0) *
                                     newCalibration_ImagePoints.size(1)) *
                                    b_i)] = refCalibration_ImagePoints
            [(i2 + (refCalibration_ImagePoints.size(0) * i1)) +
             ((refCalibration_ImagePoints.size(0) *
               refCalibration_ImagePoints.size(1)) *
              b_i)];
      }
    }
  }
  // RTcnc1 = refCalibration.Extrinsics;
  newCalibration_PatternPositions.set_size(
      1, refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newCalibration_PatternPositions[b_i] = refCalibration_PatternPositions[b_i];
  }
  // options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  newCalibration_CameraParameters->IntrinsicMatrix[0][0] = b_x[0];
  newCalibration_CameraParameters->IntrinsicMatrix[1][0] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[2][0] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[0][1] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[1][1] = b_x[1];
  newCalibration_CameraParameters->IntrinsicMatrix[2][1] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[0][2] = b_x[2];
  newCalibration_CameraParameters->IntrinsicMatrix[1][2] = b_x[3];
  newCalibration_CameraParameters->IntrinsicMatrix[2][2] = 1.0;
  newCalibration_CameraParameters->RadialDistortion[0] = b_x[4];
  newCalibration_CameraParameters->RadialDistortion[1] = b_x[5];
  newCalibration_CameraParameters->RadialDistortion[2] = b_x[6];
  camLength = 7.0;
  // newCalibration.CameraParameters = cameraParameters('IntrinsicMatrix', K,
  // ...
  //     'RadialDistortion', radialCoeffs,  'NumRadialDistortionCoefficients',
  //     3);
  newCalibration_CameraParameters->NumRadialDistortionCoefficients = 3.0;
  b_i = refCalibration_PatternPositions.size(1);
  for (b_loop_ub = 0; b_loop_ub < b_i; b_loop_ub++) {
    real_T absxk;
    real_T b_t;
    real_T scale;
    real_T theta;
    scale = 3.3121686421112381E-170;
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 1.0))) - 1];
    rotationVector_data[0] = absxk;
    t_data[0] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 4.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      theta = b_t * b_t;
    }
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 2.0))) - 1];
    rotationVector_data[1] = absxk;
    t_data[1] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 5.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > scale) {
      b_t = scale / absxk;
      theta = ((theta * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      theta += b_t * b_t;
    }
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 3.0))) - 1];
    rotationVector_data[2] = absxk;
    t_data[2] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 6.0))) - 1];
    absxk = std::abs(absxk);
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
      for (i1 = 0; i1 < 3; i1++) {
        b_a[i1][0] = 0.0;
        b_a[i1][1] = 0.0;
        b_a[i1][2] = 0.0;
      }
      b_a[0][0] = 1.0;
      b_a[1][1] = 1.0;
      b_a[2][2] = 1.0;
    } else {
      absxk = std::cos(theta);
      b_t = std::sin(theta);
      for (i1 = 0; i1 < 3; i1++) {
        scale = rotationVector_data[i1] / theta;
        b_u_data[i1] = scale;
        u_data[i1] = scale;
        c_a[i1][0] = 0;
        c_a[i1][1] = 0;
        c_a[i1][2] = 0;
      }
      b_a[0][0] = b_t * 0.0;
      b_a[1][0] = b_t * (-u_data[2]);
      b_a[2][0] = b_t * u_data[1];
      b_a[0][1] = b_t * u_data[2];
      b_a[1][1] = b_t * 0.0;
      b_a[2][1] = b_t * (-u_data[0]);
      b_a[0][2] = b_t * (-u_data[1]);
      b_a[1][2] = b_t * u_data[0];
      b_a[2][2] = b_t * 0.0;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        c_a[loop_ub][loop_ub] = 1;
        c_u_data[3 * loop_ub] = b_u_data[0] * b_u_data[loop_ub];
        c_u_data[(3 * loop_ub) + 1] = b_u_data[1] * b_u_data[loop_ub];
        c_u_data[(3 * loop_ub) + 2] = b_u_data[2] * b_u_data[loop_ub];
      }
      for (i1 = 0; i1 < 3; i1++) {
        b_a[i1][0] =
            (((static_cast<real_T>(c_a[i1][0])) * absxk) + b_a[i1][0]) +
            ((1.0 - absxk) * c_u_data[3 * i1]);
        b_a[i1][1] =
            (((static_cast<real_T>(c_a[i1][1])) * absxk) + b_a[i1][1]) +
            ((1.0 - absxk) * c_u_data[(3 * i1) + 1]);
        b_a[i1][2] =
            (((static_cast<real_T>(c_a[i1][2])) * absxk) + b_a[i1][2]) +
            ((1.0 - absxk) * c_u_data[(3 * i1) + 2]);
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (i1 = 0; i1 < 4; i1++) {
      newCalibration_PatternPositions[b_loop_ub].f1[i1][0] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][1] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][2] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][3] = 0.0;
    }
    for (i1 = 0; i1 < 3; i1++) {
      newCalibration_PatternPositions[b_loop_ub].f1[i1][0] = b_a[0][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][1] = b_a[1][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][2] = b_a[2][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][3] = t_data[i1];
    }
    newCalibration_PatternPositions[b_loop_ub].f1[3][0] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][1] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][2] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][3] = 1.0;
    camLength += 6.0;
  }
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
}

//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
//                const struct1_T *refCalibration_CameraParameters
//                const ::coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions const ::coder::array<real_T,
//                3U> &refCalibration_ImagePoints struct1_T
//                *newCalibration_CameraParameters
//                ::coder::array<cell_wrap_0, 2U>
//                &newCalibration_PatternPositions
//                ::coder::array<real_T, 3U> &newCalibration_ImagePoints
// Return Type  : void
//
void unserializeCalib(
    const ::coder::array<real_T, 1U> &b_x,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints)
{
  real_T b_a[3][3];
  real_T b_rotationVector[3][3];
  real_T b_t[3];
  real_T rotationVector[3];
  real_T camLength;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i1;
  int32_T loop_ub;
  int8_T c_a[3][3];
  //  Start with original values. Overwrite if changed.
  *newCalibration_CameraParameters = *refCalibration_CameraParameters;
  newCalibration_ImagePoints.set_size(refCalibration_ImagePoints.size(0),
                                      refCalibration_ImagePoints.size(1),
                                      refCalibration_ImagePoints.size(2));
  loop_ub = refCalibration_ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = refCalibration_ImagePoints.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      int32_T c_loop_ub;
      c_loop_ub = refCalibration_ImagePoints.size(0);
      for (int32_T i2{0}; i2 < c_loop_ub; i2++) {
        newCalibration_ImagePoints[(i2 +
                                    (newCalibration_ImagePoints.size(0) * i1)) +
                                   ((newCalibration_ImagePoints.size(0) *
                                     newCalibration_ImagePoints.size(1)) *
                                    b_i)] = refCalibration_ImagePoints
            [(i2 + (refCalibration_ImagePoints.size(0) * i1)) +
             ((refCalibration_ImagePoints.size(0) *
               refCalibration_ImagePoints.size(1)) *
              b_i)];
      }
    }
  }
  // RTcnc1 = refCalibration.Extrinsics;
  newCalibration_PatternPositions.set_size(
      1, refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    newCalibration_PatternPositions[b_i] = refCalibration_PatternPositions[b_i];
  }
  // options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  newCalibration_CameraParameters->IntrinsicMatrix[0][0] = b_x[0];
  newCalibration_CameraParameters->IntrinsicMatrix[1][0] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[2][0] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[0][1] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[1][1] = b_x[1];
  newCalibration_CameraParameters->IntrinsicMatrix[2][1] = 0.0;
  newCalibration_CameraParameters->IntrinsicMatrix[0][2] = b_x[2];
  newCalibration_CameraParameters->IntrinsicMatrix[1][2] = b_x[3];
  newCalibration_CameraParameters->IntrinsicMatrix[2][2] = 1.0;
  newCalibration_CameraParameters->RadialDistortion[0] = b_x[4];
  newCalibration_CameraParameters->RadialDistortion[1] = b_x[5];
  newCalibration_CameraParameters->RadialDistortion[2] = b_x[6];
  camLength = 7.0;
  // newCalibration.CameraParameters = cameraParameters('IntrinsicMatrix', K,
  // ...
  //     'RadialDistortion', radialCoeffs,  'NumRadialDistortionCoefficients',
  //     3);
  newCalibration_CameraParameters->NumRadialDistortionCoefficients = 3.0;
  b_i = refCalibration_PatternPositions.size(1);
  for (b_loop_ub = 0; b_loop_ub < b_i; b_loop_ub++) {
    real_T absxk;
    real_T c_t;
    real_T scale;
    real_T theta;
    scale = 3.3121686421112381E-170;
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 1.0))) - 1];
    rotationVector[0] = absxk;
    b_t[0] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 4.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      c_t = absxk / 3.3121686421112381E-170;
      theta = c_t * c_t;
    }
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 2.0))) - 1];
    rotationVector[1] = absxk;
    b_t[1] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 5.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > scale) {
      c_t = scale / absxk;
      theta = ((theta * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      theta += c_t * c_t;
    }
    absxk =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 3.0))) - 1];
    rotationVector[2] = absxk;
    b_t[2] =
        b_x[(static_cast<int32_T>(static_cast<real_T>(camLength + 6.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > scale) {
      c_t = scale / absxk;
      theta = ((theta * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      theta += c_t * c_t;
    }
    theta = scale * std::sqrt(theta);
    if (theta < 1.0E-6) {
      for (i1 = 0; i1 < 3; i1++) {
        b_a[i1][0] = 0.0;
        b_a[i1][1] = 0.0;
        b_a[i1][2] = 0.0;
      }
      b_a[0][0] = 1.0;
      b_a[1][1] = 1.0;
      b_a[2][2] = 1.0;
    } else {
      absxk = std::cos(theta);
      c_t = std::sin(theta);
      for (i1 = 0; i1 < 3; i1++) {
        rotationVector[i1] /= theta;
        c_a[i1][0] = 0;
        c_a[i1][1] = 0;
        c_a[i1][2] = 0;
      }
      b_a[0][0] = c_t * 0.0;
      b_a[1][0] = c_t * (-rotationVector[2]);
      b_a[2][0] = c_t * rotationVector[1];
      b_a[0][1] = c_t * rotationVector[2];
      b_a[1][1] = c_t * 0.0;
      b_a[2][1] = c_t * (-rotationVector[0]);
      b_a[0][2] = c_t * (-rotationVector[1]);
      b_a[1][2] = c_t * rotationVector[0];
      b_a[2][2] = c_t * 0.0;
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        c_a[loop_ub][loop_ub] = 1;
        b_rotationVector[loop_ub][0] =
            rotationVector[0] * rotationVector[loop_ub];
        b_rotationVector[loop_ub][1] =
            rotationVector[1] * rotationVector[loop_ub];
        b_rotationVector[loop_ub][2] =
            rotationVector[2] * rotationVector[loop_ub];
      }
      for (i1 = 0; i1 < 3; i1++) {
        b_a[i1][0] =
            (((static_cast<real_T>(c_a[i1][0])) * absxk) + b_a[i1][0]) +
            ((1.0 - absxk) * b_rotationVector[i1][0]);
        b_a[i1][1] =
            (((static_cast<real_T>(c_a[i1][1])) * absxk) + b_a[i1][1]) +
            ((1.0 - absxk) * b_rotationVector[i1][1]);
        b_a[i1][2] =
            (((static_cast<real_T>(c_a[i1][2])) * absxk) + b_a[i1][2]) +
            ((1.0 - absxk) * b_rotationVector[i1][2]);
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (i1 = 0; i1 < 4; i1++) {
      newCalibration_PatternPositions[b_loop_ub].f1[i1][0] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][1] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][2] = 0.0;
      newCalibration_PatternPositions[b_loop_ub].f1[i1][3] = 0.0;
    }
    for (i1 = 0; i1 < 3; i1++) {
      newCalibration_PatternPositions[b_loop_ub].f1[i1][0] = b_a[0][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][1] = b_a[1][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][2] = b_a[2][i1];
      newCalibration_PatternPositions[b_loop_ub].f1[i1][3] = b_t[i1];
    }
    newCalibration_PatternPositions[b_loop_ub].f1[3][0] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][1] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][2] = 0.0;
    newCalibration_PatternPositions[b_loop_ub].f1[3][3] = 1.0;
    camLength += 6.0;
  }
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
}

} // namespace Codegen

//
// File trailer for unserializeCalib.cpp
//
// [EOF]
//
