//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fitgeotrans.h
//
// Code generation for function 'fitgeotrans'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace Codegen {
namespace coder {
class projective2d;

}
} // namespace Codegen

// Function Declarations
namespace Codegen {
namespace coder {
void findProjectiveTransform(const emlrtStack *sp,
                             const ::coder::array<real_T, 2U> &uv,
                             const ::coder::array<real_T, 2U> &xy,
                             projective2d *tform);

}
} // namespace Codegen

// End of code generation (fitgeotrans.h)
