//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
// Return Type  : double
//
namespace coder {
double mean(const ::coder::array<double, 2U> &x)
{
  double y;
  int vlen;
  vlen = x.size(1);
  if (x.size(1) == 0) {
    y = 0.0;
  } else {
    int firstBlockLength;
    int k;
    int lastBlockLength;
    int nblocks;
    if (x.size(1) <= 1024) {
      firstBlockLength = x.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x.size(1) / 1024;
      lastBlockLength = x.size(1) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x[0];
    for (k = 2; k <= firstBlockLength; k++) {
      if (vlen >= 2) {
        y += x[k - 1];
      }
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      double bsum;
      int hi;
      firstBlockLength = (ib - 1) * 1024;
      bsum = x[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        if (vlen >= 2) {
          bsum += x[(firstBlockLength + k) - 1];
        }
      }
      y += bsum;
    }
  }
  y /= static_cast<double>(x.size(1));
  return y;
}

//
// Arguments    : const ::coder::array<float, 1U> &x
// Return Type  : float
//
float mean(const ::coder::array<float, 1U> &x)
{
  float y;
  int vlen;
  vlen = x.size(0);
  if (x.size(0) == 0) {
    y = 0.0F;
  } else {
    int firstBlockLength;
    int k;
    int lastBlockLength;
    int nblocks;
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x.size(0) / 1024;
      lastBlockLength = x.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x[0];
    for (k = 2; k <= firstBlockLength; k++) {
      if (vlen >= 2) {
        y += x[k - 1];
      }
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      float bsum;
      int hi;
      firstBlockLength = (ib - 1) * 1024;
      bsum = x[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        if (vlen >= 2) {
          bsum += x[(firstBlockLength + k) - 1];
        }
      }
      y += bsum;
    }
  }
  y /= static_cast<float>(x.size(0));
  return y;
}

} // namespace coder

//
// File trailer for mean.cpp
//
// [EOF]
//
