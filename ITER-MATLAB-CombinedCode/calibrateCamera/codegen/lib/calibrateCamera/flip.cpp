//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: flip.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "flip.h"
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &b_x
//                real_T dim
// Return Type  : void
//
namespace Codegen {
namespace coder {
void flip(::coder::array<real_T, 2U> &b_x, real_T dim)
{
  int32_T subs2[2];
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    if (b_x.size((static_cast<int32_T>(dim)) - 1) > 1) {
      int32_T lup;
      if (dim == 2.0) {
        lup = asr_s32(b_x.size(1), 1U);
      } else {
        lup = b_x.size(1);
      }
      for (int32_T k{0}; k < lup; k++) {
        int32_T b_lup;
        if (dim == 1.0) {
          b_lup = asr_s32(b_x.size(0), 1U);
        } else {
          b_lup = b_x.size(0);
        }
        for (int32_T b_k{0}; b_k < b_lup; b_k++) {
          real_T tmp;
          subs2[0] = b_k + 1;
          subs2[1] = k + 1;
          subs2[(static_cast<int32_T>(dim)) - 1] =
              (b_x.size((static_cast<int32_T>(dim)) - 1) -
               subs2[(static_cast<int32_T>(dim)) - 1]) +
              1;
          tmp = b_x[b_k + (b_x.size(0) * k)];
          b_x[b_k + (b_x.size(0) * k)] =
              b_x[(subs2[0] + (b_x.size(0) * (subs2[1] - 1))) - 1];
          b_x[(subs2[0] + (b_x.size(0) * (subs2[1] - 1))) - 1] = tmp;
        }
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for flip.cpp
//
// [EOF]
//
