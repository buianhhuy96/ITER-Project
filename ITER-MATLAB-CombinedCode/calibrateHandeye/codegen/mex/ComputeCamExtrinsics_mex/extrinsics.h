//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extrinsics.h
//
// Code generation for function 'extrinsics'
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
class cameraParameters;

}

// Function Declarations
namespace coder {
void extrinsics(const emlrtStack *sp,
                const ::coder::array<real_T, 2U> &imagePoints,
                const ::coder::array<real_T, 2U> &worldPoints,
                const cameraParameters *cameraParams, real_T rotationMatrix[9],
                real_T translationVector[3]);

}

// End of code generation (extrinsics.h)
