//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unserializeCalib.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef UNSERIALIZECALIB_H
#define UNSERIALIZECALIB_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct cell_wrap_0;

struct struct0_T;

// Function Declarations
void unserializeCalib(
    const coder::array<double, 1U> &b_x,
    const double refCalibration_CameraParameters_ImageSize[2],
    const coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    struct0_T *CameraParameters,
    coder::array<cell_wrap_0, 2U> &PatternPositions);

#endif
//
// File trailer for unserializeCalib.h
//
// [EOF]
//
