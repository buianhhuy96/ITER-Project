//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "polyfit.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                const ::coder::array<double, 2U> &y
//                double c_n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
namespace coder {
void b_polyfit(const ::coder::array<double, 2U> &b_x,
               const ::coder::array<double, 2U> &y, double c_n,
               ::coder::array<double, 2U> &p)
{
  array<double, 2U> V;
  array<double, 1U> b_y;
  array<double, 1U> p1;
  int b_i;
  int c_x;
  V.set_size(b_x.size(1), static_cast<int>(static_cast<double>(c_n + 1.0)));
  if ((b_x.size(1) != 0) &&
      ((static_cast<int>(static_cast<double>(c_n + 1.0))) != 0)) {
    int k;
    b_i = b_x.size(1);
    for (k = 0; k < b_i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(c_n + 1.0))) - 1))] = 1.0;
    }
    if (!(c_n < 1.0)) {
      b_i = b_x.size(1);
      for (k = 0; k < b_i; k++) {
        V[k + (V.size(0) * ((static_cast<int>(c_n)) - 1))] = b_x[k];
      }
      b_i =
          static_cast<int>(static_cast<double>(-((-1.0 - (c_n - 1.0)) + 1.0)));
      if (0 <= ((static_cast<int>(
                    static_cast<double>(-((-1.0 - (c_n - 1.0)) + 1.0)))) -
                1)) {
        c_x = b_x.size(1);
      }
      for (int j{0}; j < b_i; j++) {
        double b_j;
        b_j = (c_n - 1.0) + (-(static_cast<double>(j)));
        for (k = 0; k < c_x; k++) {
          V[k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              b_x[k] *
              V[k + (V.size(0) *
                     ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  c_x = y.size(1);
  b_y = y.reshape(c_x);
  internal::qrsolve(V, b_y, p1, &c_x);
  p.set_size(1, p1.size(0));
  c_x = p1.size(0);
  for (b_i = 0; b_i < c_x; b_i++) {
    p[b_i] = p1[b_i];
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                const ::coder::array<double, 1U> &y
//                double c_n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
void polyfit(const ::coder::array<double, 1U> &b_x,
             const ::coder::array<double, 1U> &y, double c_n,
             ::coder::array<double, 2U> &p)
{
  array<double, 2U> V;
  array<double, 1U> p1;
  int b_i;
  int rr;
  V.set_size(b_x.size(0), static_cast<int>(static_cast<double>(c_n + 1.0)));
  if ((b_x.size(0) != 0) &&
      ((static_cast<int>(static_cast<double>(c_n + 1.0))) != 0)) {
    int k;
    b_i = b_x.size(0);
    for (k = 0; k < b_i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(c_n + 1.0))) - 1))] = 1.0;
    }
    if (!(c_n < 1.0)) {
      b_i = b_x.size(0);
      for (k = 0; k < b_i; k++) {
        V[k + (V.size(0) * ((static_cast<int>(c_n)) - 1))] = b_x[k];
      }
      b_i =
          static_cast<int>(static_cast<double>(-((-1.0 - (c_n - 1.0)) + 1.0)));
      for (int j{0}; j < b_i; j++) {
        double b_j;
        b_j = (c_n - 1.0) + (-(static_cast<double>(j)));
        rr = b_x.size(0);
        for (k = 0; k < rr; k++) {
          V[k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              b_x[k] *
              V[k + (V.size(0) *
                     ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  internal::qrsolve(V, y, p1, &rr);
  p.set_size(1, p1.size(0));
  rr = p1.size(0);
  for (b_i = 0; b_i < rr; b_i++) {
    p[b_i] = p1[b_i];
  }
}

} // namespace coder

//
// File trailer for polyfit.cpp
//
// [EOF]
//
