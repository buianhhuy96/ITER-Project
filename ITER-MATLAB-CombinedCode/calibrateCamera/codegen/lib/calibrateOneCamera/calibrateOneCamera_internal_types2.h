//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_internal_types2.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALIBRATEONECAMERA_INTERNAL_TYPES2_H
#define CALIBRATEONECAMERA_INTERNAL_TYPES2_H

// Include Files
#include "calibrateOneCamera_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace Codegen {
struct c_struct_T {
  struct1_T CameraParameters;
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<double, 3U> ImagePoints;
};

} // namespace Codegen

#endif
//
// File trailer for calibrateOneCamera_internal_types2.h
//
// [EOF]
//
