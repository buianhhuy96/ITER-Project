//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int g_n
//                const double b_x[8]
//                int ix0
// Return Type  : double
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
double b_xnrm2(int g_n, const double b_x[8], int ix0)
{
  double y;
  y = 0.0;
  if (g_n >= 1) {
    if (g_n == 1) {
      y = std::abs(b_x[ix0 - 1]);
    } else {
      double scale;
      int b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = (ix0 + g_n) - 1;
      for (int k{ix0}; k <= b_kend; k++) {
        double absxk;
        absxk = std::abs(b_x[k - 1]);
        if (absxk > scale) {
          double b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          double b_t;
          b_t = absxk / scale;
          y += b_t * b_t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : int g_n
//                const double b_x[6]
//                int ix0
// Return Type  : double
//
double c_xnrm2(int g_n, const double b_x[6], int ix0)
{
  double y;
  y = 0.0;
  if (g_n >= 1) {
    if (g_n == 1) {
      y = std::abs(b_x[ix0 - 1]);
    } else {
      double scale;
      int b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = (ix0 + g_n) - 1;
      for (int k{ix0}; k <= b_kend; k++) {
        double absxk;
        absxk = std::abs(b_x[k - 1]);
        if (absxk > scale) {
          double b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          double b_t;
          b_t = absxk / scale;
          y += b_t * b_t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : int g_n
//                const double b_x[3][3]
//                int ix0
// Return Type  : double
//
double d_xnrm2(int g_n, const double b_x[3][3], int ix0)
{
  double y;
  y = 0.0;
  if (g_n >= 1) {
    if (g_n == 1) {
      y = std::abs((&b_x[0][0])[ix0 - 1]);
    } else {
      double scale;
      int b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = (ix0 + g_n) - 1;
      for (int k{ix0}; k <= b_kend; k++) {
        double absxk;
        absxk = std::abs((&b_x[0][0])[k - 1]);
        if (absxk > scale) {
          double b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          double b_t;
          b_t = absxk / scale;
          y += b_t * b_t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

//
// Arguments    : const double b_x[3]
// Return Type  : double
//
double e_xnrm2(const double b_x[3])
{
  double scale;
  double y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int k{2}; k < 4; k++) {
    double absxk;
    absxk = std::abs(b_x[k - 1]);
    if (absxk > scale) {
      double b_t;
      b_t = scale / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      double b_t;
      b_t = absxk / scale;
      y += b_t * b_t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : int g_n
//                const ::coder::array<double, 2U> &b_x
//                int ix0
// Return Type  : double
//
double xnrm2(int g_n, const ::coder::array<double, 2U> &b_x, int ix0)
{
  double y;
  y = 0.0;
  if (g_n >= 1) {
    if (g_n == 1) {
      y = std::abs(b_x[ix0 - 1]);
    } else {
      double scale;
      int b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = (ix0 + g_n) - 1;
      for (int k{ix0}; k <= b_kend; k++) {
        double absxk;
        absxk = std::abs(b_x[k - 1]);
        if (absxk > scale) {
          double b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          double b_t;
          b_t = absxk / scale;
          y += b_t * b_t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

} // namespace blas
} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
