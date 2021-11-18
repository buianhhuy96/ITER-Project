//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: combineVectorElements.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
namespace coder {
double combineVectorElements(const ::coder::array<double, 1U> &b_x)
{
  double y;
  int vlen;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y = 0.0;
  } else {
    double b_y;
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
      double c_y;
      c_y = b_y;
      if (vlen >= 2) {
        c_y = b_y + b_x[k - 1];
      }
      b_y = c_y;
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
      b_y += bsum;
    }
    y = b_y;
  }
  return y;
}

} // namespace coder

//
// File trailer for combineVectorElements.cpp
//
// [EOF]
//
