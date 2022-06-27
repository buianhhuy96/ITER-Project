//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: linspace.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "linspace.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double b_d1
//                double d2
//                int h_n
//                ::coder::array<double, 2U> &y
// Return Type  : void
//
namespace coder {
void linspace(double b_d1, double d2, int h_n, ::coder::array<double, 2U> &y)
{
  if (h_n < 0) {
    y.set_size(1, 0);
  } else {
    int i_n;
    y.set_size(1, h_n);
    i_n = h_n;
    if (h_n >= 1) {
      y[h_n - 1] = d2;
      if (y.size(1) >= 2) {
        y[0] = b_d1;
        if (y.size(1) >= 3) {
          if ((b_d1 == (-d2)) && (h_n > 2)) {
            double d2scaled;
            int b_i;
            d2scaled = d2 / ((static_cast<double>(h_n)) - 1.0);
            b_i = h_n - 1;
            if ((static_cast<int>((h_n - 2) < 4)) != 0) {
              for (int k{2}; k <= b_i; k++) {
                y[k - 1] = (static_cast<double>(
                               static_cast<int>(((k * 2) - h_n) - 1))) *
                           d2scaled;
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int k = 2; k <= b_i; k++) {
                y[k - 1] = (static_cast<double>(
                               static_cast<int>(((k * 2) - i_n) - 1))) *
                           d2scaled;
              }
            }
            if ((i_n & 1) == 1) {
              y[asr_s32(i_n, 1U)] = 0.0;
            }
          } else {
            double delta1;
            bool guard1{false};
            bool guard2{false};
            guard1 = false;
            guard2 = false;
            if ((b_d1 < 0.0) != (d2 < 0.0)) {
              if (std::abs(b_d1) > 8.9884656743115785E+307) {
                guard2 = true;
              } else if (std::abs(d2) > 8.9884656743115785E+307) {
                guard2 = true;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
            if (guard2) {
              double delta2;
              int i1;
              delta1 = b_d1 / ((static_cast<double>(y.size(1))) - 1.0);
              delta2 = d2 / ((static_cast<double>(y.size(1))) - 1.0);
              i1 = y.size(1);
              if ((static_cast<int>((y.size(1) - 2) < 4)) != 0) {
                for (int b_k{0}; b_k <= (i1 - 3); b_k++) {
                  y[b_k + 1] =
                      (b_d1 + (delta2 * ((static_cast<double>(b_k)) + 1.0))) -
                      (delta1 * ((static_cast<double>(b_k)) + 1.0));
                }
              } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                for (int b_k = 0; b_k <= (i1 - 3); b_k++) {
                  y[b_k + 1] =
                      (b_d1 + (delta2 * ((static_cast<double>(b_k)) + 1.0))) -
                      (delta1 * ((static_cast<double>(b_k)) + 1.0));
                }
              }
            }
            if (guard1) {
              int i2;
              delta1 = (d2 - b_d1) / ((static_cast<double>(y.size(1))) - 1.0);
              i2 = y.size(1);
              if ((static_cast<int>((y.size(1) - 2) < 4)) != 0) {
                for (int c_k{0}; c_k <= (i2 - 3); c_k++) {
                  y[c_k + 1] =
                      b_d1 + (((static_cast<double>(c_k)) + 1.0) * delta1);
                }
              } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

                for (int c_k = 0; c_k <= (i2 - 3); c_k++) {
                  y[c_k + 1] =
                      b_d1 + (((static_cast<double>(c_k)) + 1.0) * delta1);
                }
              }
            }
          }
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for linspace.cpp
//
// [EOF]
//
