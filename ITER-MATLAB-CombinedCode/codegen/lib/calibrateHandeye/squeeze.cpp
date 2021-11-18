//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "squeeze.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 3U> &b_a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace coder {
void b_squeeze(const ::coder::array<double, 3U> &b_a,
               ::coder::array<double, 2U> &b)
{
  int szb[2];
  int loop_ub;
  int szb_idx_0;
  szb[0] = b_a.size(0);
  szb[1] = 1;
  if (b_a.size(2) != 1) {
    int j;
    j = 0;
    if (b_a.size(0) != 1) {
      j = 1;
      szb[0] = b_a.size(0);
    }
    if (b_a.size(2) != 1) {
      szb[j] = b_a.size(2);
    }
  }
  szb_idx_0 = szb[0];
  b.set_size(szb[0], szb[1]);
  loop_ub = szb[1];
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    for (int i1{0}; i1 < szb_idx_0; i1++) {
      b[i1 + (b.size(0) * b_i)] = b_a[i1 + (szb_idx_0 * b_i)];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 3U> &b_a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
void squeeze(const ::coder::array<double, 3U> &b_a,
             ::coder::array<double, 2U> &b)
{
  int szb[2];
  int loop_ub;
  int szb_idx_0;
  szb[0] = 1;
  szb[1] = b_a.size(1);
  if (b_a.size(2) != 1) {
    int j;
    j = 0;
    if (b_a.size(1) != 1) {
      j = 1;
      szb[0] = b_a.size(1);
    }
    if (b_a.size(2) != 1) {
      szb[j] = b_a.size(2);
    }
  }
  szb_idx_0 = szb[0];
  b.set_size(szb[0], szb[1]);
  loop_ub = szb[1];
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    for (int i1{0}; i1 < szb_idx_0; i1++) {
      b[i1 + (b.size(0) * b_i)] = b_a[i1 + (szb_idx_0 * b_i)];
    }
  }
}

} // namespace coder

//
// File trailer for squeeze.cpp
//
// [EOF]
//
