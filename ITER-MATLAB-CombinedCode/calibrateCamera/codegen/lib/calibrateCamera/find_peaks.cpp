//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "find_peaks.h"
#include "bwlookup.h"
#include "calibrateCamera_rtwutil.h"
#include "imregionalmax.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace Codegen {
static int32_T div_s32_floor(int32_T numerator, int32_T denominator);

}

// Function Definitions
//
// Arguments    : int32_T numerator
//                int32_T denominator
// Return Type  : int32_T
//
namespace Codegen {
static int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    uint32_T absDenominator;
    uint32_T absNumerator;
    uint32_T tempAbsQuotient;
    boolean_T quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = (~(static_cast<uint32_T>(numerator))) + 1U;
    } else {
      absNumerator = static_cast<uint32_T>(numerator);
    }
    if (denominator < 0) {
      absDenominator = (~(static_cast<uint32_T>(denominator))) + 1U;
    } else {
      absDenominator = static_cast<uint32_T>(denominator);
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -(static_cast<int32_T>(tempAbsQuotient));
    } else {
      quotient = static_cast<int32_T>(tempAbsQuotient);
    }
  }
  return quotient;
}

//
// Arguments    : const ::coder::array<real32_T, 2U> &metric
//                ::coder::array<real32_T, 2U> &loc
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const ::coder::array<real32_T, 2U> &metric,
                ::coder::array<real32_T, 2U> &loc)
{
  ::coder::array<int32_T, 1U> b_ii;
  ::coder::array<int32_T, 1U> vk;
  ::coder::array<boolean_T, 2U> b_bw;
  ::coder::array<boolean_T, 2U> last_aout;
  ::coder::array<boolean_T, 2U> m;
  int32_T b_i;
  int32_T idx;
  int32_T k;
  int32_T last;
  real32_T maxMetric;
  uint32_T siz[2];
  boolean_T exitg1;
  last = metric.size(0) * metric.size(1);
  if ((metric.size(0) * metric.size(1)) <= 2) {
    if ((metric.size(0) * metric.size(1)) == 1) {
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
      b_i = idx + 1;
      for (k = b_i; k <= last; k++) {
        if (maxMetric < metric[k - 1]) {
          maxMetric = metric[k - 1];
        }
      }
    }
  }
  if ((static_cast<real_T>(maxMetric)) <= 4.94065645841247E-324) {
    loc.set_size(0, 2);
  } else {
    int32_T i1;
    int32_T loop_ub;
    imregionalmax(metric, b_bw);
    maxMetric *= 0.15F;
    k = (metric.size(0) * metric.size(1)) - 1;
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        last++;
      }
    }
    b_ii.set_size(last);
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        b_ii[last] = idx + 1;
        last++;
      }
    }
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_bw[b_ii[b_i] - 1] = false;
    }
    if ((b_bw.size(0) != 0) && (b_bw.size(1) != 0)) {
      do {
        int32_T i2;
        int32_T i3;
        int32_T i4;
        int32_T i5;
        int32_T i6;
        int32_T i7;
        last_aout.set_size(b_bw.size(0), b_bw.size(1));
        loop_ub = b_bw.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          last = b_bw.size(0);
          for (i1 = 0; i1 < last; i1++) {
            last_aout[i1 + (last_aout.size(0) * b_i)] =
                b_bw[i1 + (b_bw.size(0) * b_i)];
          }
        }
        bwlookup(b_bw, m);
        m.set_size(b_bw.size(0), b_bw.size(1));
        loop_ub = b_bw.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          last = b_bw.size(0);
          for (i1 = 0; i1 < last; i1++) {
            m[i1 + (m.size(0) * b_i)] = ((b_bw[i1 + (b_bw.size(0) * b_i)]) &&
                                         (!m[i1 + (m.size(0) * b_i)]));
          }
        }
        if (1 > m.size(0)) {
          b_i = 1;
          i1 = 0;
        } else {
          b_i = 2;
          i1 = m.size(0);
        }
        if (1 > m.size(1)) {
          idx = 1;
          i2 = 0;
        } else {
          idx = 2;
          i2 = m.size(1);
        }
        if (1 > b_bw.size(0)) {
          i3 = 1;
        } else {
          i3 = 2;
        }
        if (1 > b_bw.size(1)) {
          i4 = 1;
        } else {
          i4 = 2;
        }
        loop_ub = div_s32_floor(i2 - 1, idx);
        for (i2 = 0; i2 <= loop_ub; i2++) {
          last = div_s32_floor(i1 - 1, b_i);
          for (i5 = 0; i5 <= last; i5++) {
            b_bw[(i3 * i5) + (b_bw.size(0) * (i4 * i2))] =
                m[(b_i * i5) + (m.size(0) * (idx * i2))];
          }
        }
        bwlookup(b_bw, m);
        m.set_size(b_bw.size(0), b_bw.size(1));
        loop_ub = b_bw.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          last = b_bw.size(0);
          for (i1 = 0; i1 < last; i1++) {
            m[i1 + (m.size(0) * b_i)] = ((b_bw[i1 + (b_bw.size(0) * b_i)]) &&
                                         (!m[i1 + (m.size(0) * b_i)]));
          }
        }
        if (2 > m.size(0)) {
          b_i = 0;
          i1 = 1;
          idx = 0;
        } else {
          b_i = 1;
          i1 = 2;
          idx = m.size(0);
        }
        if (2 > m.size(1)) {
          i2 = 0;
          i3 = 1;
          i4 = 0;
        } else {
          i2 = 1;
          i3 = 2;
          i4 = m.size(1);
        }
        if (2 > b_bw.size(0)) {
          i5 = 0;
          k = 1;
        } else {
          i5 = 1;
          k = 2;
        }
        if (2 > b_bw.size(1)) {
          i6 = 0;
          i7 = 1;
        } else {
          i6 = 1;
          i7 = 2;
        }
        loop_ub = div_s32_floor((i4 - i2) - 1, i3);
        for (i4 = 0; i4 <= loop_ub; i4++) {
          last = div_s32_floor((idx - b_i) - 1, i1);
          for (int32_T b_i8{0}; b_i8 <= last; b_i8++) {
            b_bw[(i5 + (k * b_i8)) + (b_bw.size(0) * (i6 + (i7 * i4)))] =
                m[(b_i + (i1 * b_i8)) + (m.size(0) * (i2 + (i3 * i4)))];
          }
        }
        bwlookup(b_bw, m);
        m.set_size(b_bw.size(0), b_bw.size(1));
        loop_ub = b_bw.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          last = b_bw.size(0);
          for (i1 = 0; i1 < last; i1++) {
            m[i1 + (m.size(0) * b_i)] = ((b_bw[i1 + (b_bw.size(0) * b_i)]) &&
                                         (!m[i1 + (m.size(0) * b_i)]));
          }
        }
        if (1 > m.size(0)) {
          b_i = 1;
          i1 = 0;
        } else {
          b_i = 2;
          i1 = m.size(0);
        }
        if (2 > m.size(1)) {
          idx = 0;
          i2 = 1;
          i3 = 0;
        } else {
          idx = 1;
          i2 = 2;
          i3 = m.size(1);
        }
        if (1 > b_bw.size(0)) {
          i4 = 1;
        } else {
          i4 = 2;
        }
        if (2 > b_bw.size(1)) {
          i5 = 0;
          k = 1;
        } else {
          i5 = 1;
          k = 2;
        }
        loop_ub = div_s32_floor((i3 - idx) - 1, i2);
        for (i3 = 0; i3 <= loop_ub; i3++) {
          last = div_s32_floor(i1 - 1, b_i);
          for (i6 = 0; i6 <= last; i6++) {
            b_bw[(i4 * i6) + (b_bw.size(0) * (i5 + (k * i3)))] =
                m[(b_i * i6) + (m.size(0) * (idx + (i2 * i3)))];
          }
        }
        bwlookup(b_bw, m);
        m.set_size(b_bw.size(0), b_bw.size(1));
        loop_ub = b_bw.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          last = b_bw.size(0);
          for (i1 = 0; i1 < last; i1++) {
            m[i1 + (m.size(0) * b_i)] = ((b_bw[i1 + (b_bw.size(0) * b_i)]) &&
                                         (!m[i1 + (m.size(0) * b_i)]));
          }
        }
        if (2 > m.size(0)) {
          b_i = 0;
          i1 = 1;
          idx = 0;
        } else {
          b_i = 1;
          i1 = 2;
          idx = m.size(0);
        }
        if (1 > m.size(1)) {
          i2 = 1;
          i3 = 0;
        } else {
          i2 = 2;
          i3 = m.size(1);
        }
        if (2 > b_bw.size(0)) {
          i4 = 0;
          i5 = 1;
        } else {
          i4 = 1;
          i5 = 2;
        }
        if (1 > b_bw.size(1)) {
          k = 1;
        } else {
          k = 2;
        }
        loop_ub = div_s32_floor(i3 - 1, i2);
        for (i3 = 0; i3 <= loop_ub; i3++) {
          last = div_s32_floor((idx - b_i) - 1, i1);
          for (i6 = 0; i6 <= last; i6++) {
            b_bw[(i4 + (i5 * i6)) + (b_bw.size(0) * (k * i3))] =
                m[(b_i + (i1 * i6)) + (m.size(0) * (i2 * i3))];
          }
        }
      } while (!b_isequal(last_aout, b_bw));
      //  the output is not changing anymore
    }
    loop_ub = b_bw.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_bw[b_bw.size(0) * b_i] = false;
    }
    last = b_bw.size(0) - 1;
    loop_ub = b_bw.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_bw[last + (b_bw.size(0) * b_i)] = false;
    }
    loop_ub = b_bw.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_bw[b_i] = false;
    }
    last = b_bw.size(1) - 1;
    loop_ub = b_bw.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_bw[b_i + (b_bw.size(0) * last)] = false;
    }
    last = b_bw.size(0) * b_bw.size(1);
    idx = 0;
    b_ii.set_size(last);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (last - 1))) {
      if (b_bw[k]) {
        idx++;
        b_ii[idx - 1] = k + 1;
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
        b_ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      b_ii.set_size(idx);
    }
    loc.set_size(b_ii.size(0), 2);
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        loc[i1 + (loc.size(0) * b_i)] = 0.0F;
      }
      siz[b_i] = static_cast<uint32_T>(metric.size(b_i));
    }
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_ii[b_i] = b_ii[b_i] - 1;
    }
    vk.set_size(b_ii.size(0));
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      vk[b_i] = div_s32(b_ii[b_i], static_cast<int32_T>(siz[0]));
    }
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_ii[b_i] = b_ii[b_i] - (vk[b_i] * (static_cast<int32_T>(siz[0])));
    }
    loop_ub = b_ii.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loc[b_i + loc.size(0)] =
          static_cast<real32_T>(static_cast<int32_T>(b_ii[b_i] + 1));
    }
    loop_ub = vk.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      loc[b_i] = static_cast<real32_T>(static_cast<int32_T>(vk[b_i] + 1));
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for find_peaks.cpp
//
// [EOF]
//
