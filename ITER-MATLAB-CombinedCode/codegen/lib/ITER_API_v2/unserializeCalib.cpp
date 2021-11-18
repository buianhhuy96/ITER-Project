//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unserializeCalib.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "unserializeCalib.h"
#include "ITER_API_v2_internal_types3.h"
#include "ITER_API_v2_types.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<double, 1U> &b_x
//                const double refCalibration_CameraParameters_ImageSize[2]
//                const coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions struct0_T *CameraParameters
//                coder::array<cell_wrap_0, 2U> &PatternPositions
// Return Type  : void
//
void unserializeCalib(
    const coder::array<double, 1U> &b_x,
    const double refCalibration_CameraParameters_ImageSize[2],
    const coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    struct0_T *CameraParameters,
    coder::array<cell_wrap_0, 2U> &PatternPositions)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::b_cameraParameters lobj_0;
  double b_a[3][3];
  double b_u[3][3];
  double rotationMatrix[3][3];
  double b_t[3];
  double rotationVector[3];
  double u[3];
  double camLength;
  int i1;
  int loop_ub;
  signed char c_a[3][3];
  //  Start with original values. Overwrite if changed.
  // newCalibration=refCalibration;
  // RTcnc1 = refCalibration.Extrinsics;
  PatternPositions.set_size(1, refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    PatternPositions[b_i] = refCalibration_PatternPositions[b_i];
  }
  // options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  camLength = 7.0;
  lobj_0.IntrinsicMatrixInternal[0][0] = b_x[0];
  lobj_0.IntrinsicMatrixInternal[0][1] = 0.0;
  lobj_0.IntrinsicMatrixInternal[0][2] = 0.0;
  lobj_0.IntrinsicMatrixInternal[1][0] = 0.0;
  lobj_0.IntrinsicMatrixInternal[1][1] = b_x[1];
  lobj_0.IntrinsicMatrixInternal[1][2] = 0.0;
  lobj_0.IntrinsicMatrixInternal[2][0] = b_x[2];
  lobj_0.IntrinsicMatrixInternal[2][1] = b_x[3];
  lobj_0.IntrinsicMatrixInternal[2][2] = 1.0;
  lobj_0.RadialDistortion[0] = b_x[4];
  lobj_0.RadialDistortion[1] = b_x[5];
  lobj_0.RadialDistortion[2] = b_x[6];
  lobj_0.TangentialDistortion[0] = 0.0;
  lobj_0.TangentialDistortion[1] = 0.0;
  lobj_0.ImageSize[0] = refCalibration_CameraParameters_ImageSize[0];
  lobj_0.ImageSize[1] = refCalibration_CameraParameters_ImageSize[1];
  lobj_0.WorldUnits[0] = 'm';
  lobj_0.WorldUnits[1] = 'm';
  lobj_0.EstimateSkew = false;
  lobj_0.NumRadialDistortionCoefficients = 3.0;
  lobj_0.EstimateTangentialDistortion = false;
  lobj_0.toStruct(CameraParameters->RadialDistortion,
                  CameraParameters->TangentialDistortion,
                  CameraParameters->ImageSize, CameraParameters->WorldUnits,
                  &CameraParameters->EstimateSkew,
                  &CameraParameters->NumRadialDistortionCoefficients,
                  &CameraParameters->EstimateTangentialDistortion,
                  CameraParameters->IntrinsicMatrix);
  //             %{
  //             newCalibration.CameraParameters.IntrinsicMatrix = K;
  //             newCalibration.CameraParameters.FocalLength = [K(1, 1) K(2,
  //             2)]; newCalibration.CameraParameters.PrincipalPoint = [K(3, 1)
  //             K(3, 2)]; newCalibration.CameraParameters.Skew = K(2, 1);
  //             newCalibration.CameraParameters.RadialDistortion =
  //             radialCoeffs;
  //             newCalibration.CameraParameters.NumRadialDistortionCoefficients
  //             = 3;
  //             %}
  i1 = refCalibration_PatternPositions.size(1);
  for (int c_i{0}; c_i < i1; c_i++) {
    double absxk;
    double b_rotationVector_tmp;
    double c_rotationVector_tmp;
    double c_t;
    double rotationVector_tmp;
    double scale;
    double theta;
    scale = 3.3121686421112381E-170;
    rotationVector_tmp =
        b_x[(static_cast<int>(static_cast<double>(camLength + 1.0))) - 1];
    rotationVector[0] = rotationVector_tmp;
    b_t[0] = b_x[(static_cast<int>(static_cast<double>(camLength + 4.0))) - 1];
    absxk = std::abs(rotationVector_tmp);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      c_t = absxk / 3.3121686421112381E-170;
      theta = c_t * c_t;
    }
    b_rotationVector_tmp =
        b_x[(static_cast<int>(static_cast<double>(camLength + 2.0))) - 1];
    rotationVector[1] = b_rotationVector_tmp;
    b_t[1] = b_x[(static_cast<int>(static_cast<double>(camLength + 5.0))) - 1];
    absxk = std::abs(b_rotationVector_tmp);
    if (absxk > scale) {
      c_t = scale / absxk;
      theta = ((theta * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      theta += c_t * c_t;
    }
    c_rotationVector_tmp =
        b_x[(static_cast<int>(static_cast<double>(camLength + 3.0))) - 1];
    rotationVector[2] = c_rotationVector_tmp;
    b_t[2] = b_x[(static_cast<int>(static_cast<double>(camLength + 6.0))) - 1];
    absxk = std::abs(c_rotationVector_tmp);
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
      for (int i2{0}; i2 < 3; i2++) {
        rotationMatrix[i2][0] = 0.0;
        rotationMatrix[i2][1] = 0.0;
        rotationMatrix[i2][2] = 0.0;
      }
      rotationMatrix[0][0] = 1.0;
      rotationMatrix[1][1] = 1.0;
      rotationMatrix[2][2] = 1.0;
    } else {
      double a;
      double alpha;
      alpha = std::cos(theta);
      a = std::sin(theta);
      for (int e_i{0}; e_i < 3; e_i++) {
        u[e_i] = rotationVector[e_i] / theta;
        c_a[e_i][0] = 0;
        c_a[e_i][1] = 0;
        c_a[e_i][2] = 0;
      }
      b_a[0][0] = a * 0.0;
      b_a[1][0] = a * (-u[2]);
      b_a[2][0] = a * u[1];
      b_a[0][1] = a * u[2];
      b_a[1][1] = a * 0.0;
      b_a[2][1] = a * (-u[0]);
      b_a[0][2] = a * (-u[1]);
      b_a[1][2] = a * u[0];
      b_a[2][2] = a * 0.0;
      for (int k{0}; k < 3; k++) {
        c_a[k][k] = 1;
        b_u[k][0] = u[0] * u[k];
        b_u[k][1] = u[1] * u[k];
        b_u[k][2] = u[2] * u[k];
      }
      for (int i7{0}; i7 < 3; i7++) {
        rotationMatrix[i7][0] =
            (((static_cast<double>(c_a[i7][0])) * alpha) + b_a[i7][0]) +
            ((1.0 - alpha) * b_u[i7][0]);
        rotationMatrix[i7][1] =
            (((static_cast<double>(c_a[i7][1])) * alpha) + b_a[i7][1]) +
            ((1.0 - alpha) * b_u[i7][1]);
        rotationMatrix[i7][2] =
            (((static_cast<double>(c_a[i7][2])) * alpha) + b_a[i7][2]) +
            ((1.0 - alpha) * b_u[i7][2]);
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (int i3{0}; i3 < 4; i3++) {
      for (int i5{0}; i5 < 4; i5++) {
        PatternPositions[c_i].f1[i3][i5] = 0.0;
      }
    }
    for (int i4{0}; i4 < 3; i4++) {
      PatternPositions[c_i].f1[i4][0] = rotationMatrix[0][i4];
      PatternPositions[c_i].f1[i4][1] = rotationMatrix[1][i4];
      PatternPositions[c_i].f1[i4][2] = rotationMatrix[2][i4];
      PatternPositions[c_i].f1[i4][3] = b_t[i4];
    }
    for (int i6{0}; i6 < 4; i6++) {
      PatternPositions[c_i].f1[3][i6] = static_cast<double>(b_iv[i6]);
    }
    camLength += 6.0;
  }
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
  // newCalibration.PatternPositions = RTpnc1;
}

//
// File trailer for unserializeCalib.cpp
//
// [EOF]
//
