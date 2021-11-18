//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
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
namespace coder {
float b_mean(const ::coder::array<float, 1U> &b_x)
{
  float d_x;
  int vlen;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    d_x = 0.0F;
  } else {
    float b_y;
    int firstBlockLength;
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
    b_y = b_x[0];
    for (int k{2}; k <= firstBlockLength; k++) {
      float c_y;
      c_y = b_y;
      if (vlen >= 2) {
        c_y = b_y + b_x[k - 1];
      }
      b_y = c_y;
    }
    for (int b_ib{2}; b_ib <= nblocks; b_ib++) {
      float bsum;
      int b_hi;
      int offset;
      offset = (b_ib - 1) * 1024;
      bsum = b_x[offset];
      if (b_ib == nblocks) {
        b_hi = lastBlockLength;
      } else {
        b_hi = 1024;
      }
      for (int b_k{2}; b_k <= b_hi; b_k++) {
        float b_bsum;
        b_bsum = bsum;
        if (vlen >= 2) {
          b_bsum = bsum + b_x[(offset + b_k) - 1];
        }
        bsum = b_bsum;
      }
      b_y += bsum;
    }
    d_x = b_y;
  }
  return d_x / (static_cast<float>(b_x.size(0)));
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
// Return Type  : double
//
double mean(const ::coder::array<double, 2U> &b_x)
{
  double b_y;
  int vlen;
  vlen = b_x.size(1);
  if (b_x.size(1) == 0) {
    b_y = 0.0;
  } else {
    double c_y;
    int firstBlockLength;
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
    c_y = b_x[0];
    for (int k{2}; k <= firstBlockLength; k++) {
      double d_y;
      d_y = c_y;
      if (vlen >= 2) {
        d_y = c_y + b_x[k - 1];
      }
      c_y = d_y;
    }
    for (int b_ib{2}; b_ib <= nblocks; b_ib++) {
      double bsum;
      int b_hi;
      int offset;
      offset = (b_ib - 1) * 1024;
      bsum = b_x[offset];
      if (b_ib == nblocks) {
        b_hi = lastBlockLength;
      } else {
        b_hi = 1024;
      }
      for (int b_k{2}; b_k <= b_hi; b_k++) {
        double b_bsum;
        b_bsum = bsum;
        if (vlen >= 2) {
          b_bsum = bsum + b_x[(offset + b_k) - 1];
        }
        bsum = b_bsum;
      }
      c_y += bsum;
    }
    b_y = c_y;
  }
  return b_y / (static_cast<double>(b_x.size(1)));
}

} // namespace coder

//
// File trailer for mean.cpp
//
// [EOF]
//
