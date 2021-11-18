//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsearch.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "bsearch.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &b_x
//                float b_xi
// Return Type  : int
//
namespace coder {
namespace internal {
int b_bsearch(const ::coder::array<float, 2U> &b_x, float b_xi)
{
  int c_n;
  int high_i;
  int low_ip1;
  high_i = b_x.size(1);
  c_n = 1;
  low_ip1 = 2;
  while (high_i > low_ip1) {
    int mid_i;
    mid_i = asr_s32(c_n, 1U) + asr_s32(high_i, 1U);
    if (((c_n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }
    if (b_xi >= b_x[mid_i - 1]) {
      c_n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }
  return c_n;
}

} // namespace internal
} // namespace coder

//
// File trailer for bsearch.cpp
//
// [EOF]
//
