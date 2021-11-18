//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: nanmean.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "nanmean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &varargin_1
// Return Type  : double
//
namespace coder {
double nanmean(const ::coder::array<double, 1U> &varargin_1)
{
  double y;
  if (varargin_1.size(0) == 0) {
    y = rtNaN;
  } else {
    int c;
    int vlen;
    vlen = varargin_1.size(0);
    y = 0.0;
    c = 0;
    for (int k{0}; k < vlen; k++) {
      if (!std::isnan(varargin_1[k])) {
        y += varargin_1[k];
        c++;
      }
    }
    if (c == 0) {
      y = rtNaN;
    } else {
      y /= static_cast<double>(c);
    }
  }
  return y;
}

} // namespace coder

//
// File trailer for nanmean.cpp
//
// [EOF]
//
