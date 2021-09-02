//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cameraParameters.h
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

#ifndef CAMERAPARAMETERS_H
#define CAMERAPARAMETERS_H

// Include Files
#include "ImageTransformer.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class cameraParameters {
public:
  double ImageSize[2];
  double RadialDistortion[3];
  double TangentialDistortion[2];
  array<double, 2U> WorldPoints;
  double NumRadialDistortionCoefficients;
  array<double, 2U> TranslationVectors;
  array<double, 3U> ReprojectionErrors;
  array<bool, 2U> DetectedKeypoints;
  array<double, 2U> RotationVectors;
  double IntrinsicMatrixInternal[3][3];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class b_cameraParameters {
public:
  double ImageSize[2];
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double NumRadialDistortionCoefficients;
  double TranslationVectors[3][30];
  double RotationVectors[3][30];
  vision::internal::calibration::b_ImageTransformer UndistortMap;
  double IntrinsicMatrixInternal[3][3];
};

} // namespace coder

#endif
//
// File trailer for cameraParameters.h
//
// [EOF]
//