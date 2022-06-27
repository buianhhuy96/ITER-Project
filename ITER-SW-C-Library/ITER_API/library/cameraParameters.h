//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cameraParameters.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
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
  cameraParameters *init(const double varargin_2[2]);
  void toStruct(double paramStruct_RadialDistortion[3],
                double paramStruct_TangentialDistortion[2],
                double paramStruct_ImageSize[2], char paramStruct_WorldUnits[2],
                bool *paramStruct_EstimateSkew,
                double *paramStruct_NumRadialDistortionCoefficients,
                bool *paramStruct_EstimateTangentialDistortion,
                double paramStruct_IntrinsicMatrix[3][3]) const;
  cameraParameters *b_init(const double varargin_1_RadialDistortion[3],
                           const double varargin_1_TangentialDistortion[2],
                           const double varargin_1_ImageSize[2],
                           const char varargin_1_WorldUnits[2],
                           bool varargin_1_EstimateSkew,
                           double varargin_1_NumRadialDistortionCoefficients,
                           bool varargin_1_EstimateTangentialDistortion,
                           const double varargin_1_IntrinsicMatrix[3][3]);
  double ImageSize[2];
  double RadialDistortion[3];
  double TangentialDistortion[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  double IntrinsicMatrixInternal[3][3];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class b_cameraParameters {
public:
  double ImageSize[2];
  double RadialDistortion[3];
  double TangentialDistortion[2];
  array<double, 2U> WorldPoints;
  array<char, 2U> WorldUnits;
  double NumRadialDistortionCoefficients;
  array<double, 2U> TranslationVectors;
  array<double, 2U> RotationVectors;
  double IntrinsicMatrixInternal[3][3];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class c_cameraParameters {
public:
  double ImageSize[2];
  array<double, 2U> RadialDistortion;
  double TangentialDistortion[2];
  char WorldUnits[2];
  bool EstimateSkew;
  double NumRadialDistortionCoefficients;
  bool EstimateTangentialDistortion;
  array<double, 2U> TranslationVectors;
  array<double, 2U> RotationVectors;
  double IntrinsicMatrixInternal[3][3];

protected:
  vision::internal::calibration::ImageTransformer UndistortMap;
};

class d_cameraParameters {
public:
  double ImageSize[2];
  double RadialDistortion[3];
  double TangentialDistortion[2];
  double NumRadialDistortionCoefficients;
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
