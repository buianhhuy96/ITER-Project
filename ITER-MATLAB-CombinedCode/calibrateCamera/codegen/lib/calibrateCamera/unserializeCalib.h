//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unserializeCalib.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef UNSERIALIZECALIB_H
#define UNSERIALIZECALIB_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct struct1_T;

struct cell_wrap_0;

} // namespace Codegen

// Function Declarations
namespace Codegen {
void b_unserializeCalib(
    const ::coder::array<real_T, 2U> &b_x,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints);

void unserializeCalib(
    const ::coder::array<real_T, 1U> &b_x,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    struct1_T *newCalibration_CameraParameters,
    ::coder::array<cell_wrap_0, 2U> &newCalibration_PatternPositions,
    ::coder::array<real_T, 3U> &newCalibration_ImagePoints);

} // namespace Codegen

#endif
//
// File trailer for unserializeCalib.h
//
// [EOF]
//
