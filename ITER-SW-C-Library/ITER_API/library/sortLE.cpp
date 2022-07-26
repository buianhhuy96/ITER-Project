//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLE.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "sortLE.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double e_v[2][5]
//                int idx1
//                int idx2
// Return Type  : bool
//
namespace ITER {
namespace coder {
namespace internal {
bool b_sortLE(const double e_v[2][5], int idx1, int idx2)
{
  double b_d1;
  double d;
  int k;
  bool exitg1;
  bool guard1{false};
  bool p;
  p = true;
  k = 0;
  guard1 = false;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    bool b_guard1{false};
    d = e_v[k][idx1 - 1];
    b_d1 = e_v[k][idx2 - 1];
    b_guard1 = false;
    if (d == b_d1) {
      b_guard1 = true;
    } else if (std::isnan(d)) {
      if (std::isnan(b_d1)) {
        b_guard1 = true;
      } else {
        guard1 = true;
        exitg1 = true;
      }
    } else {
      guard1 = true;
      exitg1 = true;
    }
    if (b_guard1) {
      k++;
      guard1 = false;
    }
  }
  if (guard1 && (!(d <= b_d1))) {
    if (!std::isnan(b_d1)) {
      p = false;
    }
  }
  return p;
}

//
// Arguments    : const ::coder::array<int, 2U> &e_v
//                const ::coder::array<int, 2U> &dir
//                int idx1
//                int idx2
// Return Type  : bool
//
bool sortLE(const ::coder::array<int, 2U> &e_v,
            const ::coder::array<int, 2U> &dir, int idx1, int idx2)
{
  int k;
  bool exitg1;
  bool p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (dir.size(1) - 1))) {
    int abscolk;
    int e_v1;
    int v2;
    if (dir[k] < 0) {
      abscolk = -dir[k];
    } else {
      abscolk = dir[k];
    }
    e_v1 = e_v[(idx1 + (e_v.size(0) * (abscolk - 1))) - 1];
    v2 = e_v[(idx2 + (e_v.size(0) * (abscolk - 1))) - 1];
    if (e_v1 == v2) {
      k++;
    } else {
      if (dir[k] < 0) {
        p = (e_v1 >= v2);
      } else {
        p = (e_v1 <= v2);
      }
      exitg1 = true;
    }
  }
  return p;
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for sortLE.cpp
//
// [EOF]
//
