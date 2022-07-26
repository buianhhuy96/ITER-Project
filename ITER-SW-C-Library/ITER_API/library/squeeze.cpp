//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: squeeze.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "squeeze.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 3U> &b_a
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_squeeze(const ::coder::array<double, 3U> &b_a,
               ::coder::array<double, 2U> &b)
{
  int b_szb[2];
  int szb[2];
  int b_loop_ub;
  int i1;
  int loop_ub;
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
  b_szb[0] = szb[0];
  b.set_size(szb[0], szb[1]);
  loop_ub = szb[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_szb[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b[i1 + (b.size(0) * b_i)] = b_a[i1 + (b_szb[0] * b_i)];
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
  int b_szb[2];
  int szb[2];
  int b_loop_ub;
  int i1;
  int loop_ub;
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
  b_szb[0] = szb[0];
  b.set_size(szb[0], szb[1]);
  loop_ub = szb[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_szb[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b[i1 + (b.size(0) * b_i)] = b_a[i1 + (b_szb[0] * b_i)];
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for squeeze.cpp
//
// [EOF]
//
