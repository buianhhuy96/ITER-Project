//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// worldToImage.h
//
// Code generation for function 'worldToImage'
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
class d_cameraParameters;

}

// Function Declarations
namespace coder {
void worldToImage(const emlrtStack *sp, const d_cameraParameters *intrinsics,
                  const real_T varargin_1[9],
                  const ::coder::array<real_T, 2U> &varargin_2,
                  const ::coder::array<real_T, 2U> &varargin_3,
                  ::coder::array<real_T, 2U> &varargout_1);

}

// End of code generation (worldToImage.h)
