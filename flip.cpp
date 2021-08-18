//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: flip.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "flip.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &x
//                double dim
// Return Type  : void
//
namespace coder {
void flip(::coder::array<double, 2U> &x, double dim)
{
  int subs2[2];
  if (dim <= 2.0) {
    if ((x.size(0) != 0) && (x.size(1) != 0)) {
      if (x.size((static_cast<int>(dim)) - 1) > 1) {
        int lup;
        if (dim == 2.0) {
          lup = asr_s32(x.size((static_cast<int>(dim)) - 1), 1U);
        } else {
          lup = x.size(1);
        }
        for (int k{0}; k < lup; k++) {
          int b_lup;
          if (dim == 1.0) {
            b_lup = asr_s32(x.size((static_cast<int>(dim)) - 1), 1U);
          } else {
            b_lup = x.size(0);
          }
          for (int b_k{0}; b_k < b_lup; b_k++) {
            double tmp;
            subs2[0] = b_k + 1;
            subs2[1] = k + 1;
            subs2[(static_cast<int>(dim)) - 1] =
                (x.size((static_cast<int>(dim)) - 1) -
                 subs2[(static_cast<int>(dim)) - 1]) +
                1;
            tmp = x[b_k + (x.size(0) * k)];
            x[b_k + (x.size(0) * k)] =
                x[(subs2[0] + (x.size(0) * (subs2[1] - 1))) - 1];
            x[(subs2[0] + (x.size(0) * (subs2[1] - 1))) - 1] = tmp;
          }
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for flip.cpp
//
// [EOF]
//
