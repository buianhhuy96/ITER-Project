//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "bsxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
void b_bsxfun(const ::coder::array<double, 2U> &b_a,
              const ::coder::array<double, 2U> &b,
              ::coder::array<double, 2U> &c)
{
  int b_i;
  int b_u0;
  int b_u1;
  int b_y;
  int c_u1;
  int csz_idx_1;
  int u0;
  int varargin_2;
  int varargin_3;
  int y;
  u0 = b.size(1);
  b_u1 = b_a.size(1);
  if (u0 <= b_u1) {
    y = u0;
  } else {
    y = b_u1;
  }
  if (b.size(1) == 1) {
    csz_idx_1 = b_a.size(1);
  } else if (b_a.size(1) == 1) {
    csz_idx_1 = b.size(1);
  } else if (b_a.size(1) == b.size(1)) {
    csz_idx_1 = b_a.size(1);
  } else {
    csz_idx_1 = y;
  }
  b_u0 = b.size(1);
  c_u1 = b_a.size(1);
  if (b_u0 <= c_u1) {
    b_y = b_u0;
  } else {
    b_y = c_u1;
  }
  if (b.size(1) == 1) {
    b_i = b_a.size(1);
  } else if (b_a.size(1) == 1) {
    b_i = b.size(1);
  } else if (b_a.size(1) == b.size(1)) {
    b_i = b_a.size(1);
  } else {
    b_i = b_y;
  }
  c.set_size(3, b_i);
  if (csz_idx_1 != 0) {
    int acoef;
    int bcoef;
    int i1;
    acoef = static_cast<int>(b_a.size(1) != 1);
    bcoef = static_cast<int>(b.size(1) != 1);
    i1 = csz_idx_1 - 1;
    if ((static_cast<int>((c.size(1) * 3) < 4)) != 0) {
      for (int k{0}; k <= i1; k++) {
        varargin_2 = acoef * k;
        varargin_3 = bcoef * k;
        c[3 * k] = b_a[3 * varargin_2] / b[varargin_3];
        c[(3 * k) + 1] = b_a[(3 * varargin_2) + 1] / b[varargin_3];
        c[(3 * k) + 2] = b_a[(3 * varargin_2) + 2] / b[varargin_3];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    varargin_3, varargin_2)

      for (int k = 0; k <= i1; k++) {
        varargin_2 = acoef * k;
        varargin_3 = bcoef * k;
        c[3 * k] = b_a[3 * varargin_2] / b[varargin_3];
        c[(3 * k) + 1] = b_a[(3 * varargin_2) + 1] / b[varargin_3];
        c[(3 * k) + 2] = b_a[(3 * varargin_2) + 2] / b[varargin_3];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &b_a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<float, 2U> &c
// Return Type  : void
//
void bsxfun(const ::coder::array<float, 2U> &b_a,
            const ::coder::array<double, 2U> &b, ::coder::array<float, 2U> &c)
{
  int b_acoef;
  int b_i;
  int b_k;
  int b_u0;
  int b_u1;
  int b_y;
  int c_u1;
  int csz_idx_1;
  int i2;
  int u0;
  int varargin_2;
  int varargin_3;
  int y;
  u0 = b.size(1);
  b_u1 = b_a.size(1);
  if (u0 <= b_u1) {
    y = u0;
  } else {
    y = b_u1;
  }
  if (b.size(1) == 1) {
    csz_idx_1 = b_a.size(1);
  } else if (b_a.size(1) == 1) {
    csz_idx_1 = b.size(1);
  } else if (b_a.size(1) == b.size(1)) {
    csz_idx_1 = b_a.size(1);
  } else {
    csz_idx_1 = y;
  }
  b_u0 = b.size(1);
  c_u1 = b_a.size(1);
  if (b_u0 <= c_u1) {
    b_y = b_u0;
  } else {
    b_y = c_u1;
  }
  if (b.size(1) == 1) {
    b_i = b_a.size(1);
  } else if (b_a.size(1) == 1) {
    b_i = b.size(1);
  } else if (b_a.size(1) == b.size(1)) {
    b_i = b_a.size(1);
  } else {
    b_i = b_y;
  }
  c.set_size(b_a.size(0), b_i);
  if ((b_a.size(0) != 0) && (csz_idx_1 != 0)) {
    int acoef;
    int bcoef;
    int i1;
    acoef = static_cast<int>(b_a.size(1) != 1);
    bcoef = static_cast<int>(b.size(1) != 1);
    i1 = csz_idx_1 - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_k, i2, b_acoef, varargin_3, varargin_2)

    for (int k = 0; k <= i1; k++) {
      varargin_2 = acoef * k;
      varargin_3 = bcoef * k;
      b_acoef = static_cast<int>(b_a.size(0) != 1);
      i2 = c.size(0) - 1;
      for (b_k = 0; b_k <= i2; b_k++) {
        c[b_k + (c.size(0) * k)] =
            b_a[(b_acoef * b_k) + (b_a.size(0) * varargin_2)] -
            (static_cast<float>(b[varargin_3]));
      }
    }
  }
}

} // namespace coder

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
