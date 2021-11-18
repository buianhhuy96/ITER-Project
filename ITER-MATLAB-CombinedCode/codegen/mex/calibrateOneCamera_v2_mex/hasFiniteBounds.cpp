//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// hasFiniteBounds.cpp
//
// Code generation for function 'hasFiniteBounds'
//

// Include files
#include "hasFiniteBounds.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtBCInfo ty_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    1,                 // lineNo
    1,                 // colNo
    "",                // aName
    "hasFiniteBounds", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "utils\\hasFiniteBounds.p", // pName
    0                           // checkKind
};

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace utils {
boolean_T hasFiniteBounds(const emlrtStack *sp, int32_T nvar,
                          ::coder::array<boolean_T, 1U> &hasLB,
                          ::coder::array<boolean_T, 1U> &hasUB)
{
  boolean_T hasBounds;
  hasBounds = false;
  for (int32_T idx{1}; idx <= nvar; idx++) {
    int32_T i;
    i = hasLB.size(0);
    if ((idx < 1) || (idx > i)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ty_emlrtBCI, (emlrtCTX)sp);
    }
    hasLB[idx - 1] = false;
    i = hasUB.size(0);
    if (idx > i) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, i, &ty_emlrtBCI, (emlrtCTX)sp);
    }
    hasUB[idx - 1] = false;
  }
  return hasBounds;
}

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (hasFiniteBounds.cpp)
