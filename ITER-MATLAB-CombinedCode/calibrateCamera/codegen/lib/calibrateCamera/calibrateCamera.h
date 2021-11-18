//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateCamera.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef CALIBRATECAMERA_H
#define CALIBRATECAMERA_H

// Include Files
#include "calibrateCamera_types.h"
#include "rtwtypes.h"
#include "string1.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
extern void calibrateCamera(const ::coder::array<uint8_T, 4U> &images,
                            real_T squareSize, const real_T boardSize[2],
                            struct0_T *calibrationOptimized,
                            coder::rtString *err);

}

#endif
//
// File trailer for calibrateCamera.h
//
// [EOF]
//
