//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<real32_T, 1U> &b_x
// Return Type  : real32_T
//
namespace Codegen {
namespace coder {
real32_T b_mean(const ::coder::array<real32_T, 1U> &b_x)
{
  int32_T vlen;
  real32_T y;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y = 0.0F;
  } else {
    int32_T firstBlockLength;
    int32_T k;
    int32_T lastBlockLength;
    int32_T nblocks;
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
    for (int32_T ib{2}; ib <= nblocks; ib++) {
      int32_T b_hi;
      real32_T bsum;
      firstBlockLength = (ib - 1) * 1024;
      bsum = b_x[firstBlockLength];
      if (ib == nblocks) {
        b_hi = lastBlockLength;
      } else {
        b_hi = 1024;
      }
      for (k = 2; k <= b_hi; k++) {
        if (vlen >= 2) {
          bsum += b_x[(firstBlockLength + k) - 1];
        }
      }
      y += bsum;
    }
  }
  y /= static_cast<real32_T>(b_x.size(0));
  return y;
}

//
// Arguments    : const ::coder::array<real_T, 2U> &b_x
// Return Type  : real_T
//
real_T mean(const ::coder::array<real_T, 2U> &b_x)
{
  real_T y;
  int32_T vlen;
  vlen = b_x.size(1);
  if (b_x.size(1) == 0) {
    y = 0.0;
  } else {
    int32_T firstBlockLength;
    int32_T k;
    int32_T lastBlockLength;
    int32_T nblocks;
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
    for (int32_T ib{2}; ib <= nblocks; ib++) {
      real_T bsum;
      int32_T b_hi;
      firstBlockLength = (ib - 1) * 1024;
      bsum = b_x[firstBlockLength];
      if (ib == nblocks) {
        b_hi = lastBlockLength;
      } else {
        b_hi = 1024;
      }
      for (k = 2; k <= b_hi; k++) {
        if (vlen >= 2) {
          bsum += b_x[(firstBlockLength + k) - 1];
        }
      }
      y += bsum;
    }
  }
  y /= static_cast<real_T>(b_x.size(1));
  return y;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for mean.cpp
//
// [EOF]
//
