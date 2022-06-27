//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types11.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef ITER_API_INTERNAL_TYPES11_H
#define ITER_API_INTERNAL_TYPES11_H

// Include Files
#include "ITER_API_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct m_struct_T {
  h_struct_T initialParams;
  coder::array<double, 2U> b_world_points;
  coder::array<double, 3U> image_points;
};

#endif
//
// File trailer for ITER_API_internal_types11.h
//
// [EOF]
//
