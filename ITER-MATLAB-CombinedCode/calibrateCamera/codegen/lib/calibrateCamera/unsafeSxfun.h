//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

#ifndef UNSAFESXFUN_H
#define UNSAFESXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct struct1_T;

}

// Function Declarations
namespace Codegen {
void binary_expand_op(::coder::array<real_T, 2U> &projectedPointsnorm,
                      const ::coder::array<real_T, 2U> &centeredPoints,
                      const struct1_T *calibrationConverted_CameraParameters,
                      const ::coder::array<real_T, 2U> &b_points);

}

#endif
//
// File trailer for unsafeSxfun.h
//
// [EOF]
//
