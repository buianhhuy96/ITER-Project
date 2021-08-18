//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsearch.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "bsearch.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &x
//                float xi
// Return Type  : int
//
namespace coder {
namespace internal {
int b_bsearch(const ::coder::array<float, 2U> &x, float xi)
{
  int high_i;
  int low_ip1;
  int n;
  high_i = x.size(1);
  n = 1;
  low_ip1 = 2;
  while (high_i > low_ip1) {
    int mid_i;
    mid_i = asr_s32(n, 1U) + asr_s32(high_i, 1U);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }
    if (xi >= x[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i + 1;
    } else {
      high_i = mid_i;
    }
  }
  return n;
}

} // namespace internal
} // namespace coder

//
// File trailer for bsearch.cpp
//
// [EOF]
//
