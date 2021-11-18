//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cameraParameters.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CAMERAPARAMETERS_H
#define CAMERAPARAMETERS_H

// Include Files
#include "ImageTransformer.h"
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace Codegen {
namespace coder {
class b_cameraParameters {
public:
  void toStruct(double paramStruct_RadialDistortion[3],
                double paramStruct_TangentialDistortion[2],
                double paramStruct_ImageSize[2], char paramStruct_WorldUnits[2],
                bool *paramStruct_EstimateSkew,
                double *paramStruct_NumRadialDistortionCoefficients,
                bool *paramStruct_EstimateTangentialDistortion,
                double paramStruct_IntrinsicMatrix[3][3]) const;
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

} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for cameraParameters.h
//
// [EOF]
//
