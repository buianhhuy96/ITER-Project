//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_internal_types1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef ITER_API_INTERNAL_TYPES1_H
#define ITER_API_INTERNAL_TYPES1_H

// Include Files
#include "anonymous_function1.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace ITER {
struct g_struct_T {
  ::coder::array<double, 2U> undist_imgMarkerPts;
  ::coder::array<double, 2U> WptsTrio;
  double K11[4][3];
};

struct r_struct_T {
  coder::anonymous_function fun;
};

struct v_struct_T {
  coder::d_anonymous_function fun;
};

} // namespace ITER

#endif
//
// File trailer for ITER_API_internal_types1.h
//
// [EOF]
//
