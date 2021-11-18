//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cameraParameters.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "cameraParameters.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double varargin_2[2]
// Return Type  : cameraParameters *
//
namespace coder {
cameraParameters *cameraParameters::init(const double varargin_2[2])
{
  cameraParameters *c_this_;
  c_this_ = this;
  for (int b_i{0}; b_i < 3; b_i++) {
    c_this_->IntrinsicMatrixInternal[b_i][0] = static_cast<double>(iv[b_i][0]);
    c_this_->IntrinsicMatrixInternal[b_i][1] = static_cast<double>(iv[b_i][1]);
    c_this_->IntrinsicMatrixInternal[b_i][2] = static_cast<double>(iv[b_i][2]);
  }
  c_this_->RadialDistortion[0] = 0.0;
  c_this_->RadialDistortion[1] = 0.0;
  c_this_->RadialDistortion[2] = 0.0;
  c_this_->TangentialDistortion[0] = 0.0;
  c_this_->TangentialDistortion[1] = 0.0;
  c_this_->ImageSize[0] = varargin_2[0];
  c_this_->ImageSize[1] = varargin_2[1];
  c_this_->WorldUnits[0] = 'm';
  c_this_->WorldUnits[1] = 'm';
  c_this_->EstimateSkew = false;
  c_this_->NumRadialDistortionCoefficients = 2.0;
  c_this_->EstimateTangentialDistortion = false;
  return c_this_;
}

//
// Arguments    : double paramStruct_RadialDistortion[3]
//                double paramStruct_TangentialDistortion[2]
//                double paramStruct_ImageSize[2]
//                char paramStruct_WorldUnits[2]
//                bool *paramStruct_EstimateSkew
//                double *paramStruct_NumRadialDistortionCoefficients
//                bool *paramStruct_EstimateTangentialDistortion
//                double paramStruct_IntrinsicMatrix[3][3]
// Return Type  : void
//
void cameraParameters::toStruct(
    double paramStruct_RadialDistortion[3],
    double paramStruct_TangentialDistortion[2], double paramStruct_ImageSize[2],
    char paramStruct_WorldUnits[2], bool *paramStruct_EstimateSkew,
    double *paramStruct_NumRadialDistortionCoefficients,
    bool *paramStruct_EstimateTangentialDistortion,
    double paramStruct_IntrinsicMatrix[3][3]) const
{
  paramStruct_RadialDistortion[0] = RadialDistortion[0];
  paramStruct_RadialDistortion[1] = RadialDistortion[1];
  paramStruct_RadialDistortion[2] = RadialDistortion[2];
  paramStruct_TangentialDistortion[0] = TangentialDistortion[0];
  paramStruct_ImageSize[0] = ImageSize[0];
  paramStruct_WorldUnits[0] = WorldUnits[0];
  paramStruct_TangentialDistortion[1] = TangentialDistortion[1];
  paramStruct_ImageSize[1] = ImageSize[1];
  paramStruct_WorldUnits[1] = WorldUnits[1];
  *paramStruct_EstimateSkew = EstimateSkew;
  *paramStruct_NumRadialDistortionCoefficients =
      NumRadialDistortionCoefficients;
  *paramStruct_EstimateTangentialDistortion = EstimateTangentialDistortion;
  for (int b_i{0}; b_i < 3; b_i++) {
    paramStruct_IntrinsicMatrix[b_i][0] = IntrinsicMatrixInternal[0][b_i];
    paramStruct_IntrinsicMatrix[b_i][1] = IntrinsicMatrixInternal[1][b_i];
    paramStruct_IntrinsicMatrix[b_i][2] = IntrinsicMatrixInternal[2][b_i];
  }
}

} // namespace coder

//
// File trailer for cameraParameters.cpp
//
// [EOF]
//
