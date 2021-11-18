//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xnrm2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : int32_T g_n
//                const real_T b_x[8]
//                int32_T ix0
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
namespace internal {
namespace blas {
real_T b_xnrm2(int32_T g_n, const real_T b_x[8], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T b_kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  b_kend = (ix0 + g_n) - 1;
  for (int32_T k{ix0}; k <= b_kend; k++) {
    real_T absxk;
    absxk = std::abs(b_x[k - 1]);
    if (absxk > scale) {
      real_T b_t;
      b_t = scale / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      real_T b_t;
      b_t = absxk / scale;
      y += b_t * b_t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : int32_T g_n
//                const real_T b_x[6]
//                int32_T ix0
// Return Type  : real_T
//
real_T c_xnrm2(int32_T g_n, const real_T b_x[6], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T b_kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  b_kend = (ix0 + g_n) - 1;
  for (int32_T k{ix0}; k <= b_kend; k++) {
    real_T absxk;
    absxk = std::abs(b_x[k - 1]);
    if (absxk > scale) {
      real_T b_t;
      b_t = scale / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      real_T b_t;
      b_t = absxk / scale;
      y += b_t * b_t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : int32_T g_n
//                const real_T b_x[3][3]
//                int32_T ix0
// Return Type  : real_T
//
real_T d_xnrm2(int32_T g_n, const real_T b_x[3][3], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T b_kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  b_kend = (ix0 + g_n) - 1;
  for (int32_T k{ix0}; k <= b_kend; k++) {
    real_T absxk;
    absxk = std::abs((&b_x[0][0])[k - 1]);
    if (absxk > scale) {
      real_T b_t;
      b_t = scale / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      real_T b_t;
      b_t = absxk / scale;
      y += b_t * b_t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : const real_T b_x[3]
// Return Type  : real_T
//
real_T e_xnrm2(const real_T b_x[3])
{
  real_T scale;
  real_T y;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (int32_T k{2}; k < 4; k++) {
    real_T absxk;
    absxk = std::abs(b_x[k - 1]);
    if (absxk > scale) {
      real_T b_t;
      b_t = scale / absxk;
      y = ((y * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      real_T b_t;
      b_t = absxk / scale;
      y += b_t * b_t;
    }
  }
  return scale * std::sqrt(y);
}

//
// Arguments    : int32_T g_n
//                const ::coder::array<real_T, 2U> &b_x
//                int32_T ix0
// Return Type  : real_T
//
real_T xnrm2(int32_T g_n, const ::coder::array<real_T, 2U> &b_x, int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (g_n >= 1) {
    if (g_n == 1) {
      y = std::abs(b_x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T b_kend;
      scale = 3.3121686421112381E-170;
      b_kend = (ix0 + g_n) - 1;
      for (int32_T k{ix0}; k <= b_kend; k++) {
        real_T absxk;
        absxk = std::abs(b_x[k - 1]);
        if (absxk > scale) {
          real_T b_t;
          b_t = scale / absxk;
          y = ((y * b_t) * b_t) + 1.0;
          scale = absxk;
        } else {
          real_T b_t;
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
