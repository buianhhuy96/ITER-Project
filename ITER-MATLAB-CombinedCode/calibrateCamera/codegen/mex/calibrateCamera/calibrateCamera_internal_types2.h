//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateCamera_internal_types2.h
//
// Code generation for function 'calibrateCamera_internal_types2'
//

#pragma once

// Include files
#include "calibrateCamera_types.h"
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
struct struct_T {
  struct1_T CameraParameters;
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<real_T, 3U> ImagePoints;
};

} // namespace Codegen

// End of code generation (calibrateCamera_internal_types2.h)
