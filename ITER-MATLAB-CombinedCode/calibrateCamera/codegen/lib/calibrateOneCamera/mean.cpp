//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<float, 1U> &b_x
// Return Type  : float
//
namespace Codegen {
namespace coder {
float b_mean(const ::coder::array<float, 1U> &b_x)
{
  float y;
  int vlen;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y = 0.0F;
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
      float bsum;
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
  y /= static_cast<float>(b_x.size(0));
  return y;
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
// Return Type  : double
//
double mean(const ::coder::array<double, 2U> &b_x)
{
  double y;
  int vlen;
  vlen = b_x.size(1);
  if (b_x.size(1) == 0) {
    y = 0.0;
  } else {
    int firstBlockLength;
    int k;
    int lastBlockLength;
    int nblocks;
    if (b_x.size(1) <= 1024) {
      firstBlockLength = b_x.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = b_x.size(1) / 1024;
      lastBlockLength = b_x.size(1) - (nblocks * 1024);
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
  y /= static_cast<double>(b_x.size(1));
  return y;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for mean.cpp
//
// [EOF]
//
