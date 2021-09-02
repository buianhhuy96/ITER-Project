//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: polyfit.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "polyfit.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                double n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
namespace coder {
void polyfit(const ::coder::array<double, 1U> &x,
             const ::coder::array<double, 1U> &y, double n,
             ::coder::array<double, 2U> &p)
{
  array<double, 2U> V;
  array<double, 1U> p1;
  int i;
  int rr;
  V.set_size(x.size(0), static_cast<int>(static_cast<double>(n + 1.0)));
  if ((x.size(0) != 0) &&
      ((static_cast<int>(static_cast<double>(n + 1.0))) != 0)) {
    int k;
    i = x.size(0);
    for (k = 0; k < i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(n + 1.0))) - 1))] = 1.0;
    }
    if (!(n < 1.0)) {
      i = x.size(0);
      for (k = 0; k < i; k++) {
        V[k + (V.size(0) * ((static_cast<int>(n)) - 1))] = x[k];
      }
      i = static_cast<int>(
          static_cast<double>(((-1.0 - (n - 1.0)) + 1.0) / -1.0));
      for (int j{0}; j < i; j++) {
        double b_j;
        b_j = (n - 1.0) + (-(static_cast<double>(j)));
        rr = x.size(0);
        for (k = 0; k < rr; k++) {
          V[k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              x[k] *
              V[k + (V.size(0) *
                     ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  internal::qrsolve(V, y, p1, &rr);
  p.set_size(1, p1.size(0));
  rr = p1.size(0);
  for (i = 0; i < rr; i++) {
    p[i] = p1[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &y
//                double n
//                ::coder::array<double, 2U> &p
// Return Type  : void
//
void polyfit(const ::coder::array<double, 2U> &x,
             const ::coder::array<double, 2U> &y, double n,
             ::coder::array<double, 2U> &p)
{
  array<double, 2U> V;
  array<double, 1U> b_y;
  array<double, 1U> p1;
  int b_x;
  int i;
  V.set_size(x.size(1), static_cast<int>(static_cast<double>(n + 1.0)));
  if ((x.size(1) != 0) &&
      ((static_cast<int>(static_cast<double>(n + 1.0))) != 0)) {
    int k;
    i = x.size(1);
    for (k = 0; k < i; k++) {
      V[k + (V.size(0) *
             ((static_cast<int>(static_cast<double>(n + 1.0))) - 1))] = 1.0;
    }
    if (!(n < 1.0)) {
      i = x.size(1);
      for (k = 0; k < i; k++) {
        V[k + (V.size(0) * ((static_cast<int>(n)) - 1))] = x[k];
      }
      i = static_cast<int>(
          static_cast<double>(((-1.0 - (n - 1.0)) + 1.0) / -1.0));
      if (0 <= (i - 1)) {
        b_x = x.size(1);
      }
      for (int j{0}; j < i; j++) {
        double b_j;
        b_j = (n - 1.0) + (-(static_cast<double>(j)));
        for (k = 0; k < b_x; k++) {
          V[k + (V.size(0) * ((static_cast<int>(b_j)) - 1))] =
              x[k] *
              V[k + (V.size(0) *
                     ((static_cast<int>(static_cast<double>(b_j + 1.0))) - 1))];
        }
      }
    }
  }
  b_x = y.size(1);
  b_y = y.reshape(b_x);
  internal::qrsolve(V, b_y, p1, &b_x);
  p.set_size(1, p1.size(0));
  b_x = p1.size(0);
  for (i = 0; i < b_x; i++) {
    p[i] = p1[i];
  }
}

} // namespace coder

//
// File trailer for polyfit.cpp
//
// [EOF]
//
