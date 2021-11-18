//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2_mex_internal_types11.h
//
// Code generation for function 'calibrateOneCamera_v2_mex_internal_types11'
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

// Type Definitions
struct b_struct_T {
  struct_T initialParams;
  coder::array<real_T, 2U> world_points;
  coder::array<real_T, 3U> image_points;
};

// End of code generation (calibrateOneCamera_v2_mex_internal_types11.h)
