//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: minOrMax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
namespace ITER {
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
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      int k;
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
      double c_ex;
      int b_i;
      c_ex = b_x[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        double d;
        d = b_x[b_k - 1];
        if (c_ex < d) {
          c_ex = d;
        }
      }
      b_ex = c_ex;
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<float, 1U> &b_x
// Return Type  : float
//
float b_minimum(const ::coder::array<float, 1U> &b_x)
{
  float b_ex;
  int last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 0) {
      b_ex = rtNaNF;
    } else if (b_x.size(0) == 1) {
      b_ex = b_x[0];
    } else if (b_x[0] > b_x[1]) {
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
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      int k;
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
      float c_ex;
      int b_i;
      c_ex = b_x[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        float f;
        f = b_x[b_k - 1];
        if (c_ex > f) {
          c_ex = f;
        }
      }
      b_ex = c_ex;
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                double b_ex[2]
// Return Type  : void
//
void c_maximum(const ::coder::array<double, 2U> &b_x, double b_ex[2])
{
  double b;
  int b_i;
  int m;
  bool p;
  m = b_x.size(0);
  if (b_x.size(0) == 0) {
    b_ex[0] = rtNaN;
    b_ex[1] = rtNaN;
  } else if ((static_cast<int>(((b_x.size(0) - 1) * 2) < 4)) != 0) {
    for (int j{0}; j < 2; j++) {
      b_ex[j] = b_x[b_x.size(0) * j];
      for (b_i = 2; b_i <= m; b_i++) {
        b = b_x[(b_i + (b_x.size(0) * j)) - 1];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(b_ex[j])) {
          p = true;
        } else {
          p = (b_ex[j] < b);
        }
        if (p) {
          b_ex[j] = b;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(p, b, b_i)

    for (int j = 0; j < 2; j++) {
      b_ex[j] = b_x[b_x.size(0) * j];
      for (b_i = 2; b_i <= m; b_i++) {
        b = b_x[(b_i + (b_x.size(0) * j)) - 1];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(b_ex[j])) {
          p = true;
        } else {
          p = (b_ex[j] < b);
        }
        if (p) {
          b_ex[j] = b;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                double *b_ex
//                int *idx
// Return Type  : void
//
void c_minimum(const ::coder::array<double, 1U> &b_x, double *b_ex, int *idx)
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
    int b_idx;
    if (!std::isnan(b_x[0])) {
      b_idx = 1;
    } else {
      int k;
      bool exitg1;
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(b_x[k - 1])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (b_idx == 0) {
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      double c_ex;
      int b_i;
      c_ex = b_x[b_idx - 1];
      *idx = b_idx;
      b_i = b_idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        double d;
        d = b_x[b_k - 1];
        if (c_ex > d) {
          c_ex = d;
          *idx = b_k;
        }
      }
      *b_ex = c_ex;
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
// Return Type  : double
//
double d_maximum(const ::coder::array<double, 2U> &b_x)
{
  double b_ex;
  int last;
  last = b_x.size(1);
  if (b_x.size(1) <= 2) {
    if (b_x.size(1) == 0) {
      b_ex = rtNaN;
    } else if (b_x.size(1) == 1) {
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
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      int k;
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
      double c_ex;
      int b_i;
      c_ex = b_x[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        double d;
        d = b_x[b_k - 1];
        if (c_ex < d) {
          c_ex = d;
        }
      }
      b_ex = c_ex;
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
// Return Type  : double
//
double d_minimum(const ::coder::array<double, 1U> &b_x)
{
  double b_ex;
  int last;
  last = b_x.size(0);
  if (b_x.size(0) <= 2) {
    if (b_x.size(0) == 0) {
      b_ex = rtNaN;
    } else if (b_x.size(0) == 1) {
      b_ex = b_x[0];
    } else if (b_x[0] > b_x[1]) {
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
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      int k;
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
      double c_ex;
      int b_i;
      c_ex = b_x[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        double d;
        d = b_x[b_k - 1];
        if (c_ex > d) {
          c_ex = d;
        }
      }
      b_ex = c_ex;
    }
  }
  return b_ex;
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                double b_ex[2]
// Return Type  : void
//
void e_minimum(const ::coder::array<double, 2U> &b_x, double b_ex[2])
{
  double b;
  int b_i;
  int m;
  bool p;
  m = b_x.size(0);
  if (b_x.size(0) == 0) {
    b_ex[0] = rtNaN;
    b_ex[1] = rtNaN;
  } else if ((static_cast<int>(((b_x.size(0) - 1) * 2) < 4)) != 0) {
    for (int j{0}; j < 2; j++) {
      b_ex[j] = b_x[b_x.size(0) * j];
      for (b_i = 2; b_i <= m; b_i++) {
        b = b_x[(b_i + (b_x.size(0) * j)) - 1];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(b_ex[j])) {
          p = true;
        } else {
          p = (b_ex[j] > b);
        }
        if (p) {
          b_ex[j] = b;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(p, b, b_i)

    for (int j = 0; j < 2; j++) {
      b_ex[j] = b_x[b_x.size(0) * j];
      for (b_i = 2; b_i <= m; b_i++) {
        b = b_x[(b_i + (b_x.size(0) * j)) - 1];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(b_ex[j])) {
          p = true;
        } else {
          p = (b_ex[j] > b);
        }
        if (p) {
          b_ex[j] = b;
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
// Return Type  : double
//
double f_minimum(const ::coder::array<double, 2U> &b_x)
{
  double b_ex;
  int last;
  last = b_x.size(1);
  if (b_x.size(1) <= 2) {
    if (b_x.size(1) == 0) {
      b_ex = rtNaN;
    } else if (b_x.size(1) == 1) {
      b_ex = b_x[0];
    } else if (b_x[0] > b_x[1]) {
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
    if (!std::isnan(b_x[0])) {
      idx = 1;
    } else {
      int k;
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
      double c_ex;
      int b_i;
      c_ex = b_x[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        double d;
        d = b_x[b_k - 1];
        if (c_ex > d) {
          c_ex = d;
        }
      }
      b_ex = c_ex;
    }
  }
  return b_ex;
}

//
// Arguments    : const double b_x[2]
// Return Type  : double
//
double g_minimum(const double b_x[2])
{
  double b_ex;
  if (b_x[0] > b_x[1]) {
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
  return b_ex;
}

//
// Arguments    : const float b_x[3]
// Return Type  : float
//
float maximum(const float b_x[3])
{
  float b_ex;
  int idx;
  if (!std::isnan(b_x[0])) {
    idx = 1;
  } else {
    int k;
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
    float c_ex;
    int b_i;
    c_ex = b_x[idx - 1];
    b_i = idx + 1;
    for (int b_k{b_i}; b_k < 4; b_k++) {
      float f;
      f = b_x[b_k - 1];
      if (c_ex < f) {
        c_ex = f;
      }
    }
    b_ex = c_ex;
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
    int b_idx;
    if (!std::isnan(b_x[0])) {
      b_idx = 1;
    } else {
      int k;
      bool exitg1;
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(b_x[k - 1])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (b_idx == 0) {
      *b_ex = b_x[0];
      *idx = 1;
    } else {
      float c_ex;
      int b_i;
      c_ex = b_x[b_idx - 1];
      *idx = b_idx;
      b_i = b_idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        float f;
        f = b_x[b_k - 1];
        if (c_ex > f) {
          c_ex = f;
          *idx = b_k;
        }
      }
      *b_ex = c_ex;
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
