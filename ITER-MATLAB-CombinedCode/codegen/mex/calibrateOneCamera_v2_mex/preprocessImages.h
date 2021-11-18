//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// preprocessImages.h
//
// Code generation for function 'preprocessImages'
//

#pragma once

// Include files
#include "calibrateOneCamera_v2_mex_types.h"
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
void preprocessImages(const emlrtStack *sp,
                      const coder::array<uint8_T, 4U> &images,
                      const struct1_T *cameraParams, boolean_T undistort,
                      coder::array<uint8_T, 4U> &gray_images);

// End of code generation (preprocessImages.h)
