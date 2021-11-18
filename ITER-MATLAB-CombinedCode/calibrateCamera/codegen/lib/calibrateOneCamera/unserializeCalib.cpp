//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unserializeCalib.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "unserializeCalib.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_types.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                const double refCalibration_CameraParameters_ImageSize[2]
//                const ::coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions e_struct_T *CameraParameters
//                ::coder::array<cell_wrap_0, 2U> &PatternPositions
// Return Type  : void
//
namespace Codegen {
void unserializeCalib(
    const ::coder::array<double, 1U> &b_x,
    const double refCalibration_CameraParameters_ImageSize[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    e_struct_T *CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &PatternPositions)
{
  coder::b_cameraParameters lobj_0;
  double b_a[3][3];
  double b_rotationVector[3][3];
  double b_t[3];
  double rotationVector[3];
  double camLength;
  int b_i;
  int loop_ub;
  signed char c_a[3][3];
  //  Start with original values. Overwrite if changed.
  // newCalibration=refCalibration;
  // RTcnc1 = refCalibration.Extrinsics;
  PatternPositions.set_size(1, refCalibration_PatternPositions.size(1));
  loop_ub = refCalibration_PatternPositions.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
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
  b_i = refCalibration_PatternPositions.size(1);
  for (int c_i{0}; c_i < b_i; c_i++) {
    double absxk;
    double c_t;
    double scale;
    double theta;
    scale = 3.3121686421112381E-170;
    absxk = b_x[(static_cast<int>(static_cast<double>(camLength + 1.0))) - 1];
    rotationVector[0] = absxk;
    b_t[0] = b_x[(static_cast<int>(static_cast<double>(camLength + 4.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      c_t = absxk / 3.3121686421112381E-170;
      theta = c_t * c_t;
    }
    absxk = b_x[(static_cast<int>(static_cast<double>(camLength + 2.0))) - 1];
    rotationVector[1] = absxk;
    b_t[1] = b_x[(static_cast<int>(static_cast<double>(camLength + 5.0))) - 1];
    absxk = std::abs(absxk);
    if (absxk > scale) {
      c_t = scale / absxk;
      theta = ((theta * c_t) * c_t) + 1.0;
      scale = absxk;
    } else {
      c_t = absxk / scale;
      theta += c_t * c_t;
    }
    absxk = b_x[(static_cast<int>(static_cast<double>(camLength + 3.0))) - 1];
    rotationVector[2] = absxk;
    b_t[2] = b_x[(static_cast<int>(static_cast<double>(camLength + 6.0))) - 1];
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
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        b_a[loop_ub][0] = 0.0;
        b_a[loop_ub][1] = 0.0;
        b_a[loop_ub][2] = 0.0;
      }
      b_a[0][0] = 1.0;
      b_a[1][1] = 1.0;
      b_a[2][2] = 1.0;
    } else {
      absxk = std::cos(theta);
      c_t = std::sin(theta);
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        rotationVector[loop_ub] /= theta;
        c_a[loop_ub][0] = 0;
        c_a[loop_ub][1] = 0;
        c_a[loop_ub][2] = 0;
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
      for (loop_ub = 0; loop_ub < 3; loop_ub++) {
        b_a[loop_ub][0] = (((static_cast<double>(c_a[loop_ub][0])) * absxk) +
                           b_a[loop_ub][0]) +
                          ((1.0 - absxk) * b_rotationVector[loop_ub][0]);
        b_a[loop_ub][1] = (((static_cast<double>(c_a[loop_ub][1])) * absxk) +
                           b_a[loop_ub][1]) +
                          ((1.0 - absxk) * b_rotationVector[loop_ub][1]);
        b_a[loop_ub][2] = (((static_cast<double>(c_a[loop_ub][2])) * absxk) +
                           b_a[loop_ub][2]) +
                          ((1.0 - absxk) * b_rotationVector[loop_ub][2]);
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (loop_ub = 0; loop_ub < 4; loop_ub++) {
      PatternPositions[c_i].f1[loop_ub][0] = 0.0;
      PatternPositions[c_i].f1[loop_ub][1] = 0.0;
      PatternPositions[c_i].f1[loop_ub][2] = 0.0;
      PatternPositions[c_i].f1[loop_ub][3] = 0.0;
    }
    for (loop_ub = 0; loop_ub < 3; loop_ub++) {
      PatternPositions[c_i].f1[loop_ub][0] = b_a[0][loop_ub];
      PatternPositions[c_i].f1[loop_ub][1] = b_a[1][loop_ub];
      PatternPositions[c_i].f1[loop_ub][2] = b_a[2][loop_ub];
      PatternPositions[c_i].f1[loop_ub][3] = b_t[loop_ub];
    }
    PatternPositions[c_i].f1[3][0] = 0.0;
    PatternPositions[c_i].f1[3][1] = 0.0;
    PatternPositions[c_i].f1[3][2] = 0.0;
    PatternPositions[c_i].f1[3][3] = 1.0;
    camLength += 6.0;
  }
  // numel(x);
  // newCalibration.Extrinsics = RTcnc1;
  // newCalibration.PatternPositions = RTpnc1;
}

} // namespace Codegen

//
// File trailer for unserializeCalib.cpp
//
// [EOF]
//
