//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// hasFiniteBounds.h
//
// Code generation for function 'hasFiniteBounds'
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
namespace optim {
namespace coder {
namespace utils {
boolean_T hasFiniteBounds(const emlrtStack *sp, int32_T nvar,
                          ::coder::array<boolean_T, 1U> &hasLB,
                          ::coder::array<boolean_T, 1U> &hasUB);

}
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (hasFiniteBounds.h)
