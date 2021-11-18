//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "polyfit.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &b_x
//                const ::coder::array<real_T, 2U> &y
//                real_T g_n
//                real_T p_data[]
//                int32_T p_size[2]
// Return Type  : void
//
namespace Codegen {
namespace coder {
void b_polyfit(const ::coder::array<real_T, 2U> &b_x,
               const ::coder::array<real_T, 2U> &y, real_T g_n, real_T p_data[],
               int32_T p_size[2])
{
  ::coder::array<real_T, 2U> V;
  ::coder::array<real_T, 1U> b_y;
  real_T p1_data[5];
  int32_T c_x;
  int32_T rr;
  V.set_size(b_x.size(1), static_cast<int32_T>(static_cast<real_T>(g_n + 1.0)));
  if (b_x.size(1) != 0) {
    int32_T k;
    c_x = b_x.size(1);
    for (k = 0; k < c_x; k++) {
      V[k + (V.size(0) *
             ((static_cast<int32_T>(static_cast<real_T>(g_n + 1.0))) - 1))] =
          1.0;
    }
    c_x = b_x.size(1);
    for (k = 0; k < c_x; k++) {
      V[k + (V.size(0) * ((static_cast<int32_T>(g_n)) - 1))] = b_x[k];
    }
    c_x = static_cast<int32_T>(
        static_cast<real_T>(-((-1.0 - (g_n - 1.0)) + 1.0)));
    if (0 <= ((static_cast<int32_T>(
                  static_cast<real_T>(-((-1.0 - (g_n - 1.0)) + 1.0)))) -
              1)) {
      rr = b_x.size(1);
    }
    for (int32_T j{0}; j < c_x; j++) {
      real_T c_j;
      c_j = (g_n - 1.0) + (-(static_cast<real_T>(j)));
      for (k = 0; k < rr; k++) {
        V[k + (V.size(0) * ((static_cast<int32_T>(c_j)) - 1))] =
            b_x[k] *
            V[k +
              (V.size(0) *
               ((static_cast<int32_T>(static_cast<real_T>(c_j + 1.0))) - 1))];
      }
    }
  }
  c_x = y.size(1);
  b_y = y.reshape(c_x);
  internal::qrsolve(V, b_y, p1_data, &c_x, &rr);
  p_size[0] = 1;
  p_size[1] = c_x;
  if (0 <= (c_x - 1)) {
    (void)std::copy(&p1_data[0], &p1_data[c_x], &p_data[0]);
  }
}

//
// Arguments    : const ::coder::array<real_T, 1U> &b_x
//                const ::coder::array<real_T, 1U> &y
//                real_T g_n
//                real_T p_data[]
//                int32_T p_size[2]
// Return Type  : void
//
void polyfit(const ::coder::array<real_T, 1U> &b_x,
             const ::coder::array<real_T, 1U> &y, real_T g_n, real_T p_data[],
             int32_T p_size[2])
{
  ::coder::array<real_T, 2U> V;
  real_T p1_data[5];
  int32_T p1_size;
  int32_T rr;
  V.set_size(b_x.size(0), static_cast<int32_T>(static_cast<real_T>(g_n + 1.0)));
  if (b_x.size(0) != 0) {
    int32_T k;
    p1_size = b_x.size(0);
    for (k = 0; k < p1_size; k++) {
      V[k + (V.size(0) *
             ((static_cast<int32_T>(static_cast<real_T>(g_n + 1.0))) - 1))] =
          1.0;
    }
    p1_size = b_x.size(0);
    for (k = 0; k < p1_size; k++) {
      V[k + (V.size(0) * ((static_cast<int32_T>(g_n)) - 1))] = b_x[k];
    }
    p1_size = static_cast<int32_T>(
        static_cast<real_T>(-((-1.0 - (g_n - 1.0)) + 1.0)));
    for (int32_T j{0}; j < p1_size; j++) {
      real_T c_j;
      c_j = (g_n - 1.0) + (-(static_cast<real_T>(j)));
      rr = b_x.size(0);
      for (k = 0; k < rr; k++) {
        V[k + (V.size(0) * ((static_cast<int32_T>(c_j)) - 1))] =
            b_x[k] *
            V[k +
              (V.size(0) *
               ((static_cast<int32_T>(static_cast<real_T>(c_j + 1.0))) - 1))];
      }
    }
  }
  internal::qrsolve(V, y, p1_data, &p1_size, &rr);
  p_size[0] = 1;
  p_size[1] = p1_size;
  if (0 <= (p1_size - 1)) {
    (void)std::copy(&p1_data[0], &p1_data[p1_size], &p_data[0]);
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for polyfit.cpp
//
// [EOF]
//
