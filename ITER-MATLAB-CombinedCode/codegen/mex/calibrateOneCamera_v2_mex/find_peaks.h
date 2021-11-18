//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find_peaks.h
//
// Code generation for function 'find_peaks'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const emlrtStack *sp,
                const ::coder::array<real32_T, 2U> &metric,
                ::coder::array<real32_T, 2U> &loc);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (find_peaks.h)
