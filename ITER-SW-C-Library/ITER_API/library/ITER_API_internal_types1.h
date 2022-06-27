//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef ITER_API_INTERNAL_TYPES1_H
#define ITER_API_INTERNAL_TYPES1_H

// Include Files
#include "anonymous_function1.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct f_struct_T {
  coder::array<double, 2U> undist_imgMarkerPts;
  coder::array<double, 2U> WptsTrio;
  double K11[4][3];
};

struct q_struct_T {
  coder::b_anonymous_function fun;
};

#endif
//
// File trailer for ITER_API_internal_types1.h
//
// [EOF]
//
