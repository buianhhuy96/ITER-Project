//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "find_peaks.h"
#include "bwmorph.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimregionalmax.h"
#include <cmath>

// Function Declarations
static int div_s32(int numerator, int denominator);

// Function Definitions
//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int b_denominator;
    unsigned int b_numerator;
    if (numerator < 0) {
      b_numerator = (~(static_cast<unsigned int>(numerator))) + 1U;
    } else {
      b_numerator = static_cast<unsigned int>(numerator);
    }
    if (denominator < 0) {
      b_denominator = (~(static_cast<unsigned int>(denominator))) + 1U;
    } else {
      b_denominator = static_cast<unsigned int>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(static_cast<int>(b_numerator));
    } else {
      quotient = static_cast<int>(b_numerator);
    }
  }
  return quotient;
}

//
// Arguments    : const ::coder::array<float, 2U> &metric
//                ::coder::array<float, 2U> &loc
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const ::coder::array<float, 2U> &metric,
                ::coder::array<float, 2U> &loc)
{
  array<unsigned int, 1U> b_idx;
  array<int, 1U> ii;
  array<int, 1U> vk;
  array<boolean_T, 2U> bw;
  double connSizeT[2];
  double imSizeT[2];
  float maxMetric;
  int idx;
  int k;
  int last;
  boolean_T conn[3][3];
  boolean_T exitg1;
  last = metric.size(0) * metric.size(1);
  if ((metric.size(0) * metric.size(1)) <= 2) {
    if ((metric.size(0) * metric.size(1)) == 0) {
      maxMetric = rtNaNF;
    } else if ((metric.size(0) * metric.size(1)) == 1) {
      maxMetric = metric[0];
    } else if (metric[0] < metric[(metric.size(0) * metric.size(1)) - 1]) {
      maxMetric = metric[(metric.size(0) * metric.size(1)) - 1];
    } else if (std::isnan(metric[0])) {
      if (!std::isnan(metric[(metric.size(0) * metric.size(1)) - 1])) {
        maxMetric = metric[(metric.size(0) * metric.size(1)) - 1];
      } else {
        maxMetric = metric[0];
      }
    } else {
      maxMetric = metric[0];
    }
  } else {
    if (!std::isnan(metric[0])) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(metric[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxMetric = metric[0];
    } else {
      maxMetric = metric[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        if (maxMetric < metric[k - 1]) {
          maxMetric = metric[k - 1];
        }
      }
    }
  }
  if ((static_cast<double>(maxMetric)) <= 4.94065645841247E-324) {
    loc.set_size(0, 2);
  } else {
    bw.set_size(metric.size(0), metric.size(1));
    imSizeT[0] = static_cast<double>(metric.size(0));
    imSizeT[1] = static_cast<double>(metric.size(1));
    for (idx = 0; idx < 3; idx++) {
      conn[idx][0] = true;
      conn[idx][1] = true;
      conn[idx][2] = true;
    }
    connSizeT[0] = 3.0;
    connSizeT[1] = 3.0;
    imregionalmax_real32(&metric[0], &bw[0], 2.0, &imSizeT[0], &conn[0][0], 2.0,
                         &connSizeT[0]);
    maxMetric *= 0.15F;
    k = (metric.size(0) * metric.size(1)) - 1;
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        last++;
      }
    }
    ii.set_size(last);
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        ii[last] = idx + 1;
        last++;
      }
    }
    k = ii.size(0);
    for (idx = 0; idx < k; idx++) {
      bw[ii[idx] - 1] = false;
    }
    bwmorph(bw);
    k = bw.size(1);
    for (idx = 0; idx < k; idx++) {
      bw[bw.size(0) * idx] = false;
    }
    last = bw.size(0) - 1;
    k = bw.size(1);
    for (idx = 0; idx < k; idx++) {
      bw[last + (bw.size(0) * idx)] = false;
    }
    k = bw.size(0);
    for (idx = 0; idx < k; idx++) {
      bw[idx] = false;
    }
    last = bw.size(1) - 1;
    k = bw.size(0);
    for (idx = 0; idx < k; idx++) {
      bw[idx + (bw.size(0) * last)] = false;
    }
    last = bw.size(0) * bw.size(1);
    idx = 0;
    ii.set_size(last);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (last - 1))) {
      if (bw[k]) {
        idx++;
        ii[idx - 1] = k + 1;
        if (idx >= last) {
          exitg1 = true;
        } else {
          k++;
        }
      } else {
        k++;
      }
    }
    if (last == 1) {
      if (idx == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      ii.set_size(idx);
    }
    b_idx.set_size(ii.size(0));
    k = ii.size(0);
    for (idx = 0; idx < k; idx++) {
      b_idx[idx] = static_cast<unsigned int>(ii[idx]);
    }
    loc.set_size(b_idx.size(0), 2);
    k = b_idx.size(0);
    for (idx = 0; idx < 2; idx++) {
      for (last = 0; last < k; last++) {
        loc[last + (loc.size(0) * idx)] = 0.0F;
      }
      connSizeT[idx] = static_cast<double>(metric.size(idx));
    }
    ii.set_size(b_idx.size(0));
    k = b_idx.size(0);
    for (idx = 0; idx < k; idx++) {
      ii[idx] = (static_cast<int>(b_idx[idx])) - 1;
    }
    vk.set_size(ii.size(0));
    k = ii.size(0);
    for (idx = 0; idx < k; idx++) {
      vk[idx] = div_s32(
          ii[idx], static_cast<int>(static_cast<unsigned int>(connSizeT[0])));
    }
    k = ii.size(0);
    for (idx = 0; idx < k; idx++) {
      ii[idx] = ii[idx] -
                (vk[idx] *
                 (static_cast<int>(static_cast<unsigned int>(connSizeT[0]))));
    }
    k = ii.size(0);
    for (idx = 0; idx < k; idx++) {
      loc[idx + loc.size(0)] =
          static_cast<float>(static_cast<int>(ii[idx] + 1));
    }
    k = vk.size(0);
    for (idx = 0; idx < k; idx++) {
      loc[idx] = static_cast<float>(static_cast<int>(vk[idx] + 1));
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for find_peaks.cpp
//
// [EOF]
//
