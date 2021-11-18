//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_v2_internal_types11.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

#ifndef ITER_API_V2_INTERNAL_TYPES11_H
#define ITER_API_V2_INTERNAL_TYPES11_H

// Include Files
#include "ITER_API_v2_internal_types2.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct e_struct_T {
  d_struct_T calibration;
  coder::array<double, 2U> genPoints;
  coder::array<double, 3U> detPoints;
};

#endif
//
// File trailer for ITER_API_v2_internal_types11.h
//
// [EOF]
//
