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
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder {
class projective2d;

}

// Function Declarations
namespace coder {
void fitgeotrans(const emlrtStack *sp,
                 const ::coder::array<real_T, 2U> &movingPoints,
                 const ::coder::array<real_T, 2U> &fixedPoints,
                 projective2d *tform);

}

// End of code generation (fitgeotrans.h)
