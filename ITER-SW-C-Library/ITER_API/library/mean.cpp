//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "mean.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<double, 2U> &y
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_mean(const ::coder::array<double, 2U> &b_x,
            ::coder::array<double, 2U> &y)
{
  int b_loop_ub;
  int e_x;
  int vlen;
  int xsubs_idx_1;
  int ysubs_idx_1;
  vlen = b_x.size(0);
  if ((b_x.size(0) == 0) || (b_x.size(1) == 0)) {
    int loop_ub;
    y.set_size(1, b_x.size(1));
    loop_ub = b_x.size(1);
    if ((static_cast<int>(b_x.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        y[i1] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < loop_ub; i1++) {
        y[i1] = 0.0;
      }
    }
  } else {
    int b_i;
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    y.set_size(1, b_x.size(1));
    b_i = b_x.size(1);
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
    for (int k{0}; k < b_i; k++) {
      y[k] = b_x[b_x.size(0) * k];
      for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
        if (vlen >= 2) {
          ysubs_idx_1 = k + 1;
          y[k] = y[k] + b_x[(b_k + (b_x.size(0) * k)) - 1];
        }
      }
      if (2 <= nblocks) {
        xsubs_idx_1 = k + 1;
        ysubs_idx_1 = k + 1;
      }
      for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
        double b_bsum;
        int b_hi;
        int offset;
        offset = (c_ib - 1) * 1024;
        b_bsum = b_x[offset + (b_x.size(0) * (xsubs_idx_1 - 1))];
        if (c_ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (int c_k{2}; c_k <= b_hi; c_k++) {
          double c_bsum;
          c_bsum = b_bsum;
          if (vlen >= 2) {
            c_bsum = b_bsum + b_x[((offset + c_k) + (b_x.size(0) * k)) - 1];
          }
          b_bsum = c_bsum;
        }
        y[ysubs_idx_1 - 1] = y[ysubs_idx_1 - 1] + b_bsum;
      }
    }
  }
  e_x = b_x.size(0);
  y.set_size(1, y.size(1));
  b_loop_ub = y.size(1);
  if ((static_cast<int>(y.size(1) < 4)) != 0) {
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      y[i2] = y[i2] / (static_cast<double>(e_x));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      y[i2] = y[i2] / (static_cast<double>(e_x));
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                double y[2]
// Return Type  : void
//
void c_mean(const ::coder::array<double, 2U> &b_x, double y[2])
{
  int vlen;
  int xsubs_idx_1;
  short ysubs_idx_1;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    y[0] = 0.0;
    y[1] = 0.0;
  } else {
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
    for (int k{0}; k < 2; k++) {
      y[k] = b_x[b_x.size(0) * k];
      for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
        if (vlen >= 2) {
          ysubs_idx_1 = static_cast<short>(k + 1);
          y[k] += b_x[(b_k + (b_x.size(0) * k)) - 1];
        }
      }
      if (2 <= nblocks) {
        xsubs_idx_1 = k + 1;
        ysubs_idx_1 = static_cast<short>(k + 1);
      }
      for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
        double b_bsum;
        int b_hi;
        int offset;
        offset = (c_ib - 1) * 1024;
        b_bsum = b_x[offset + (b_x.size(0) * (xsubs_idx_1 - 1))];
        if (c_ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (int c_k{2}; c_k <= b_hi; c_k++) {
          double c_bsum;
          c_bsum = b_bsum;
          if (vlen >= 2) {
            c_bsum = b_bsum + b_x[((offset + c_k) + (b_x.size(0) * k)) - 1];
          }
          b_bsum = c_bsum;
        }
        y[ysubs_idx_1 - 1] += b_bsum;
      }
    }
  }
  y[0] /= static_cast<double>(b_x.size(0));
  y[1] /= static_cast<double>(b_x.size(0));
}

//
// Arguments    : const ::coder::array<float, 1U> &b_x
// Return Type  : float
//
float mean(const ::coder::array<float, 1U> &b_x)
{
  float e_x;
  int vlen;
  vlen = b_x.size(0);
  if (b_x.size(0) == 0) {
    e_x = 0.0F;
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
    for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
      float b_bsum;
      int b_hi;
      int offset;
      offset = (c_ib - 1) * 1024;
      b_bsum = b_x[offset];
      if (c_ib == nblocks) {
        b_hi = lastBlockLength;
      } else {
        b_hi = 1024;
      }
      for (int b_k{2}; b_k <= b_hi; b_k++) {
        float c_bsum;
        c_bsum = b_bsum;
        if (vlen >= 2) {
          c_bsum = b_bsum + b_x[(offset + b_k) - 1];
        }
        b_bsum = c_bsum;
      }
      b_y += b_bsum;
    }
    e_x = b_y;
  }
  return e_x / (static_cast<float>(b_x.size(0)));
}

} // namespace coder
} // namespace ITER

//
// File trailer for mean.cpp
//
// [EOF]
//
