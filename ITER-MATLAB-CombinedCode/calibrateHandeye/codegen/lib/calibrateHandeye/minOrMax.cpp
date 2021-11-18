//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
namespace coder {
namespace internal {
double b_maximum(const ::coder::array<double, 1U> &b_x)
{
  double b_ex;
  int last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 0) {
      b_ex = rtNaN;
    } else if (b_x.size(0) == 1) {
      b_ex = b_x[0];
    } else if (b_x[0] < b_x[1]) {
      b_ex = b_x[1];
    } else if (std::isnan(b_x[0])) {
      if (!std::isnan(b_x[1])) {
        b_ex = b_x[1];
      } else {
        b_ex = b_x[0];
      }
    } else {
      b_ex = b_x[0];
    }
  } else {
    int idx;
    int k;
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      bool exitg1;
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
      b_ex = b_x[0];
    } else {
      b_ex = b_x[idx - 1];
      idx++;
      for (k = idx; k <= last; k++) {
        double d;
        d = b_x[k - 1];
        if (b_ex < d) {
          b_ex = d;
        }
      }
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                double *b_ex
//                int *idx
// Return Type  : void
//
void b_minimum(const ::coder::array<double, 1U> &b_x, double *b_ex, int *idx)
{
  int last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 0) {
      *b_ex = rtNaN;
      *idx = 1;
    } else if (b_x.size(0) == 1) {
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      bool guard1{false};
      bool guard2{false};
      guard1 = false;
      guard2 = false;
      if (b_x[0] > b_x[1]) {
        guard2 = true;
      } else if (std::isnan(b_x[0])) {
        if (!std::isnan(b_x[1])) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard2) {
        *b_ex = b_x[1];
        *idx = 2;
      }
      if (guard1) {
        *b_ex = b_x[0];
        *idx = 1;
      }
    }
  } else {
    int k;
    if (!std::isnan(b_x[0])) {
      *idx = 1;
    } else {
      bool exitg1;
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
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      int b_i;
      *b_ex = b_x[(*idx) - 1];
      b_i = (*idx) + 1;
      for (k = b_i; k <= last; k++) {
        double d;
        d = b_x[k - 1];
        if ((*b_ex) > d) {
          *b_ex = d;
          *idx = k;
        }
      }
    }
  }
}

//
// Arguments    : const float b_x[3]
// Return Type  : float
//
float maximum(const float b_x[3])
{
  float b_ex;
  int idx;
  int k;
  if (!std::isnan(b_x[0])) {
    idx = 1;
  } else {
    bool exitg1;
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
    b_ex = b_x[0];
  } else {
    b_ex = b_x[idx - 1];
    idx++;
    for (k = idx; k < 4; k++) {
      float f;
      f = b_x[k - 1];
      if (b_ex < f) {
        b_ex = f;
      }
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<float, 1U> &b_x
//                float *b_ex
//                int *idx
// Return Type  : void
//
void minimum(const ::coder::array<float, 1U> &b_x, float *b_ex, int *idx)
{
  int last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 0) {
      *b_ex = rtNaNF;
      *idx = 1;
    } else if (b_x.size(0) == 1) {
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      bool guard1{false};
      bool guard2{false};
      guard1 = false;
      guard2 = false;
      if (b_x[0] > b_x[1]) {
        guard2 = true;
      } else if (std::isnan(b_x[0])) {
        if (!std::isnan(b_x[1])) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard2) {
        *b_ex = b_x[1];
        *idx = 2;
      }
      if (guard1) {
        *b_ex = b_x[0];
        *idx = 1;
      }
    }
  } else {
    int k;
    if (!std::isnan(b_x[0])) {
      *idx = 1;
    } else {
      bool exitg1;
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
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      int b_i;
      *b_ex = b_x[(*idx) - 1];
      b_i = (*idx) + 1;
      for (k = b_i; k <= last; k++) {
        float f;
        f = b_x[k - 1];
        if ((*b_ex) > f) {
          *b_ex = f;
          *idx = k;
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
