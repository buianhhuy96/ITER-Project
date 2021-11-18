//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// algbwmorph.h
//
// Code generation for function 'algbwmorph'
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
namespace images {
namespace internal {
void bwmorphApplyOnce(const emlrtStack *sp, ::coder::array<boolean_T, 2U> &bw);

}
} // namespace images
} // namespace coder

// End of code generation (algbwmorph.h)
