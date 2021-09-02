//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "squeeze.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 3U> &a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace coder {
void b_squeeze(const ::coder::array<double, 3U> &a,
               ::coder::array<double, 2U> &b)
{
  int sqsz[2];
  int j;
  int loop_ub;
  bool guard1{false};
  sqsz[0] = 1;
  sqsz[1] = 1;
  guard1 = false;
  if (a.size(2) == 1) {
    if (a.size(0) == 1) {
      sqsz[1] = 1;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    j = 0;
    if (a.size(0) != 1) {
      j = 1;
      sqsz[0] = a.size(0);
    }
    if (a.size(2) != 1) {
      sqsz[j] = a.size(2);
    }
  }
  j = sqsz[0];
  b.set_size(sqsz[0], sqsz[1]);
  loop_ub = sqsz[1];
  for (int i{0}; i < loop_ub; i++) {
    for (int i1{0}; i1 < j; i1++) {
      b[i1 + (b.size(0) * i)] = a[i1 + (j * i)];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 3U> &a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
void squeeze(const ::coder::array<double, 3U> &a, ::coder::array<double, 2U> &b)
{
  int sqsz[2];
  int j;
  int loop_ub;
  sqsz[0] = 1;
  sqsz[1] = 1;
  if (a.size(2) == 1) {
    sqsz[1] = a.size(1);
  } else {
    j = 0;
    if (a.size(1) != 1) {
      j = 1;
      sqsz[0] = a.size(1);
    }
    if (a.size(2) != 1) {
      sqsz[j] = a.size(2);
    }
  }
  j = sqsz[0];
  b.set_size(sqsz[0], sqsz[1]);
  loop_ub = sqsz[1];
  for (int i{0}; i < loop_ub; i++) {
    for (int i1{0}; i1 < j; i1++) {
      b[i1 + (b.size(0) * i)] = a[i1 + (j * i)];
    }
  }
}

} // namespace coder

//
// File trailer for squeeze.cpp
//
// [EOF]
//
