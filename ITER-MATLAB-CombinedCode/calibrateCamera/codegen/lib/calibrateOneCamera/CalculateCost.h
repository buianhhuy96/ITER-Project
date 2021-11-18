//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CalculateCost.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALCULATECOST_H
#define CALCULATECOST_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct cell_wrap_0;

}

// Function Declarations
namespace Codegen {
void CalculateCost(
    const ::coder::array<double, 1U> &calib,
    const double refCalibration_CameraParameters_ImageSize[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<double, 2U> &genPoints,
    const ::coder::array<double, 3U> &detPoints,
    ::coder::array<double, 1U> &cost);

}

#endif
//
// File trailer for CalculateCost.h
//
// [EOF]
//
