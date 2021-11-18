//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cameraParameters.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "cameraParameters.h"
#include "rt_nonfinite.h"

// Function Definitions
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
namespace Codegen {
namespace coder {
void b_cameraParameters::toStruct(
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
} // namespace Codegen

//
// File trailer for cameraParameters.cpp
//
// [EOF]
//
