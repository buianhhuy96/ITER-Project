//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 1U> &b_x
// Return Type  : int
//
namespace Codegen {
namespace coder {
int b_combineVectorElements(const ::coder::array<bool, 1U> &b_x)
{
  int vlen;
  int y;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y = 0;
  } else {
    y = static_cast<int>(b_x[0]);
    for (int k{2}; k <= vlen; k++) {
      if (vlen >= 2) {
        y += static_cast<int>(b_x[k - 1]);
      }
    }
  }
  return y;
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
double combineVectorElements(const ::coder::array<double, 1U> &b_x)
{
  double y;
  int vlen;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y = 0.0;
  } else {
    int firstBlockLength;
    int k;
    int lastBlockLength;
    int nblocks;
    if (b_x.size(0) <= 1024) {
      firstBlockLength = b_x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = b_x.size(0) / 1024;
      lastBlockLength = b_x.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = b_x[0];
    for (k = 2; k <= firstBlockLength; k++) {
      if (vlen >= 2) {
        y += b_x[k - 1];
      }
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      double bsum;
      int hi;
      firstBlockLength = (ib - 1) * 1024;
      bsum = b_x[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        if (vlen >= 2) {
          bsum += b_x[(firstBlockLength + k) - 1];
        }
      }
      y += bsum;
    }
  }
  return y;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
