//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef UNSAFESXFUN_H
#define UNSAFESXFUN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace Codegen {
struct e_struct_T;

}

// Function Declarations
namespace Codegen {
void binary_expand_op(::coder::array<double, 2U> &projectedPointsnorm,
                      const ::coder::array<double, 2U> &centeredPoints,
                      const e_struct_T *CameraParameters,
                      const ::coder::array<double, 2U> &b_points);

}

#endif
//
// File trailer for unsafeSxfun.h
//
// [EOF]
//
