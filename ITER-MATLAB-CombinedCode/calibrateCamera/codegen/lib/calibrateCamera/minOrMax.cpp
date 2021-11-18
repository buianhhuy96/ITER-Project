//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
namespace internal {
real_T b_maximum(const ::coder::array<real_T, 1U> &b_x)
{
  real_T ex;
  int32_T last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 1) {
      ex = b_x[0];
    } else if (b_x[0] < b_x[b_x.size(0) - 1]) {
      ex = b_x[b_x.size(0) - 1];
    } else if (std::isnan(b_x[0])) {
      if (!std::isnan(b_x[b_x.size(0) - 1])) {
        ex = b_x[b_x.size(0) - 1];
      } else {
        ex = b_x[0];
      }
    } else {
      ex = b_x[0];
    }
  } else {
    int32_T idx;
    int32_T k;
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(b_x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = b_x[0];
    } else {
      ex = b_x[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        real_T d;
        d = b_x[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
//                real_T *ex
//                int32_T *idx
// Return Type  : void
//
void b_minimum(const ::coder::array<real_T, 1U> &b_x, real_T *ex, int32_T *idx)
{
  int32_T last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 1) {
      *ex = b_x[0];
      *idx = 1;
    } else {
      boolean_T guard1{false};
      boolean_T guard2{false};
      guard1 = false;
      guard2 = false;
      if (b_x[0] > b_x[b_x.size(0) - 1]) {
        guard2 = true;
      } else if (std::isnan(b_x[0])) {
        if (!std::isnan(b_x[b_x.size(0) - 1])) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard2) {
        *ex = b_x[b_x.size(0) - 1];
        *idx = b_x.size(0);
      }
      if (guard1) {
        *ex = b_x[0];
        *idx = 1;
      }
    }
  } else {
    int32_T k;
    if (!std::isnan(b_x[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(b_x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if ((*idx) == 0) {
      *ex = b_x[0];
      *idx = 1;
    } else {
      int32_T b_i;
      *ex = b_x[(*idx) - 1];
      b_i = (*idx) + 1;
      for (k = b_i; k <= last; k++) {
        real_T d;
        d = b_x[k - 1];
        if ((*ex) > d) {
          *ex = d;
          *idx = k;
        }
      }
    }
  }
}

//
// Arguments    : const real32_T b_x[3]
// Return Type  : real32_T
//
real32_T maximum(const real32_T b_x[3])
{
  int32_T idx;
  int32_T k;
  real32_T ex;
  if (!std::isnan(b_x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 3)) {
      if (!std::isnan(b_x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = b_x[0];
  } else {
    ex = b_x[idx - 1];
    idx++;
    for (k = idx; k < 4; k++) {
      real32_T f;
      f = b_x[k - 1];
      if (ex < f) {
        ex = f;
      }
    }
  }
  return ex;
}

//
// Arguments    : const ::coder::array<real32_T, 1U> &b_x
//                real32_T *ex
//                int32_T *idx
// Return Type  : void
//
void minimum(const ::coder::array<real32_T, 1U> &b_x, real32_T *ex,
             int32_T *idx)
{
  int32_T last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 1) {
      *ex = b_x[0];
      *idx = 1;
    } else {
      boolean_T guard1{false};
      boolean_T guard2{false};
      guard1 = false;
      guard2 = false;
      if (b_x[0] > b_x[b_x.size(0) - 1]) {
        guard2 = true;
      } else if (std::isnan(b_x[0])) {
        if (!std::isnan(b_x[b_x.size(0) - 1])) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard2) {
        *ex = b_x[b_x.size(0) - 1];
        *idx = b_x.size(0);
      }
      if (guard1) {
        *ex = b_x[0];
        *idx = 1;
      }
    }
  } else {
    int32_T k;
    if (!std::isnan(b_x[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(b_x[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if ((*idx) == 0) {
      *ex = b_x[0];
      *idx = 1;
    } else {
      int32_T b_i;
      *ex = b_x[(*idx) - 1];
      b_i = (*idx) + 1;
      for (k = b_i; k <= last; k++) {
        real32_T f;
        f = b_x[k - 1];
        if ((*ex) > f) {
          *ex = f;
          *idx = k;
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
