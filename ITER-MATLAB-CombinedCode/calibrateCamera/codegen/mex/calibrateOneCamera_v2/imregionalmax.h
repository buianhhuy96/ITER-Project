//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imregionalmax.h
//
// Code generation for function 'imregionalmax'
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
void imregionalmax(const emlrtStack *sp,
                   const ::coder::array<real32_T, 2U> &varargin_1,
                   ::coder::array<boolean_T, 2U> &BW);

}

// End of code generation (imregionalmax.h)
