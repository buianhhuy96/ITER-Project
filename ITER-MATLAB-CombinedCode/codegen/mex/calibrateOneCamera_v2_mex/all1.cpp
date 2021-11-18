//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// all1.cpp
//
// Code generation for function 'all1'
//

// Include files
#include "all1.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
namespace internal {
namespace valattr {
boolean_T d_all(const ::coder::array<real_T, 2U> &a)
{
  int32_T i;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  p = true;
  i = a.size(0) * a.size(1);
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(a[k])) && (!muDoubleScalarIsNaN(a[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  return p;
}

} // namespace valattr
} // namespace internal
} // namespace coder

// End of code generation (all1.cpp)
