//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_internal_types11.h
//
// Code generation for function 'calibrateOneCamera_mex_internal_types11'
//

#pragma once

// Include files
#include "calibrateOneCamera_mex_internal_types2.h"
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

// Type Definitions
namespace Codegen {
struct b_struct_T {
  struct_T calibration;
  ::coder::array<real_T, 2U> genPoints;
  ::coder::array<real_T, 3U> detPoints;
};

} // namespace Codegen

// End of code generation (calibrateOneCamera_mex_internal_types11.h)
