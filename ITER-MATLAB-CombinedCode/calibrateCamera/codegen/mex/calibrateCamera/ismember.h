//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ismember.h
//
// Code generation for function 'ismember'
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

// Function Declarations
namespace Codegen {
namespace coder {
void local_ismember(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                    const ::coder::array<real_T, 2U> &s,
                    ::coder::array<boolean_T, 2U> &tf);

}
} // namespace Codegen

// End of code generation (ismember.h)
