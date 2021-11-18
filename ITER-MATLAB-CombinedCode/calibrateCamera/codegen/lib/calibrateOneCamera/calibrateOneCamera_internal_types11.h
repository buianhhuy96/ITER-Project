//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera_internal_types11.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CALIBRATEONECAMERA_INTERNAL_TYPES11_H
#define CALIBRATEONECAMERA_INTERNAL_TYPES11_H

// Include Files
#include "calibrateOneCamera_internal_types2.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace Codegen {
struct d_struct_T {
  c_struct_T calibration;
  ::coder::array<double, 2U> genPoints;
  ::coder::array<double, 3U> detPoints;
};

} // namespace Codegen

#endif
//
// File trailer for calibrateOneCamera_internal_types11.h
//
// [EOF]
//
