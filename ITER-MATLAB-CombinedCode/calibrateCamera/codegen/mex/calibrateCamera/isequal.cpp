//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// isequal.cpp
//
// Code generation for function 'isequal'
//

// Include files
#include "isequal.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace Codegen {
namespace coder {
boolean_T isequal(const real_T varargin_1[2])
{
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == static_cast<real_T>(k) + 1.0)) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  return p;
}

boolean_T isequal(const real_T varargin_1_data[],
                  const int32_T varargin_1_size[2], real_T varargin_2)
{
  boolean_T p;
  p = (varargin_1_size[1] == 1);
  if (p && (varargin_1_size[1] != 0) && (!(varargin_1_data[0] == varargin_2))) {
    p = false;
  }
  return p;
}

} // namespace coder
} // namespace Codegen

// End of code generation (isequal.cpp)
