//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "polyfit.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                const ::coder::array<double, 2U> &y
//                double h_n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_polyfit(const ::coder::array<double, 2U> &b_x,
               const ::coder::array<double, 2U> &y, double h_n,
               ::coder::array<double, 2U> &p)
{
  ::coder::array<double, 2U> V;
  ::coder::array<double, 1U> b_p1;
  ::coder::array<double, 1U> c_y;
  int b_y;
  int loop_ub;
  int rr;
  V.set_size(b_x.size(1), static_cast<int>(static_cast<double>(h_n + 1.0)));
  if ((b_x.size(1) != 0) &&
      ((static_cast<int>(static_cast<double>(h_n + 1.0))) != 0)) {
    int b_i;
    b_i = b_x.size(1);
    for (int k{0}; k < b_i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(h_n + 1.0))) - 1))] = 1.0;
    }
    if (!(h_n < 1.0)) {
      int i1;
      int i3;
      i1 = b_x.size(1);
      if ((static_cast<int>(b_x.size(1) < 4)) != 0) {
        for (int b_k{0}; b_k < i1; b_k++) {
          V[b_k + (V.size(0) * ((static_cast<int>(h_n)) - 1))] = b_x[b_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_k = 0; b_k < i1; b_k++) {
          V[b_k + (V.size(0) * ((static_cast<int>(h_n)) - 1))] = b_x[b_k];
        }
      }
      i3 = static_cast<int>(static_cast<double>(-((-1.0 - (h_n - 1.0)) + 1.0)));
      for (int j{0}; j < i3; j++) {
        double b_j;
        int i4;
        b_j = (h_n - 1.0) + (-(static_cast<double>(j)));
        i4 = b_x.size(1);
        for (int c_k{0}; c_k < i4; c_k++) {
          V[c_k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              b_x[c_k] *
              V[c_k +
                (V.size(0) *
                 ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  b_y = y.size(1);
  c_y = y.reshape(b_y);
  internal::qrsolve(V, c_y, b_p1, &rr);
  p.set_size(1, b_p1.size(0));
  loop_ub = b_p1.size(0);
  if ((static_cast<int>(b_p1.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      p[i2] = b_p1[i2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < loop_ub; i2++) {
      p[i2] = b_p1[i2];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &y
//                double h_n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
void polyfit(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y, double h_n,
             ::coder::array<double, 2U> &p)
{
  ::coder::array<double, 2U> V;
  ::coder::array<double, 1U> b_p1;
  int loop_ub;
  int rr;
  V.set_size(b_x.size(0), static_cast<int>(static_cast<double>(h_n + 1.0)));
  if ((b_x.size(0) != 0) &&
      ((static_cast<int>(static_cast<double>(h_n + 1.0))) != 0)) {
    int b_i;
    b_i = b_x.size(0);
    for (int k{0}; k < b_i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(h_n + 1.0))) - 1))] = 1.0;
    }
    if (!(h_n < 1.0)) {
      int i1;
      int i3;
      i1 = b_x.size(0);
      if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
        for (int b_k{0}; b_k < i1; b_k++) {
          V[b_k + (V.size(0) * ((static_cast<int>(h_n)) - 1))] = b_x[b_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_k = 0; b_k < i1; b_k++) {
          V[b_k + (V.size(0) * ((static_cast<int>(h_n)) - 1))] = b_x[b_k];
        }
      }
      i3 = static_cast<int>(static_cast<double>(-((-1.0 - (h_n - 1.0)) + 1.0)));
      for (int j{0}; j < i3; j++) {
        double b_j;
        int i4;
        b_j = (h_n - 1.0) + (-(static_cast<double>(j)));
        i4 = b_x.size(0);
        for (int c_k{0}; c_k < i4; c_k++) {
          V[c_k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              b_x[c_k] *
              V[c_k +
                (V.size(0) *
                 ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  internal::qrsolve(V, y, b_p1, &rr);
  p.set_size(1, b_p1.size(0));
  loop_ub = b_p1.size(0);
  if ((static_cast<int>(b_p1.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      p[i2] = b_p1[i2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < loop_ub; i2++) {
      p[i2] = b_p1[i2];
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for polyfit.cpp
//
// [EOF]
//
