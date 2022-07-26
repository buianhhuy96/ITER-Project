//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: roots.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "roots.h"
#include "eigStandard.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "coder_array.h"
#include "rtGetNaN.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double c[5]
//                ::coder::array<creal_T, 1U> &r
// Return Type  : void
//
namespace ITER {
namespace coder {
void roots(const double c[5], ::coder::array<creal_T, 1U> &r)
{
  static creal_T dc{
      0.0, // re
      0.0  // im
  };
  ::coder::array<creal_T, 1U> eiga;
  ::coder::array<double, 2U> T;
  ::coder::array<double, 2U> b_a;
  ::coder::array<double, 1U> V;
  double ctmp[5];
  int b_k1;
  int b_loop_ub;
  int i4;
  int k2;
  int nTrailingZeros;
  signed char b_companDim[2];
  dc.re = rtGetNaN();
  r.set_size(4);
  for (int b_i{0}; b_i < 4; b_i++) {
    r[b_i].re = 0.0;
    r[b_i].im = 0.0;
  }
  b_k1 = 1;
  while ((b_k1 <= 5) && (!(c[b_k1 - 1] != 0.0))) {
    b_k1++;
  }
  k2 = 5;
  while ((k2 >= b_k1) && (!(c[k2 - 1] != 0.0))) {
    k2--;
  }
  nTrailingZeros = 4 - k2;
  if (b_k1 < k2) {
    int companDim;
    bool exitg1;
    companDim = k2 - b_k1;
    exitg1 = false;
    while ((!exitg1) && (companDim > 0)) {
      int j;
      bool exitg2;
      j = 0;
      exitg2 = false;
      while ((!exitg2) && ((j + 1) <= companDim)) {
        ctmp[j] = c[b_k1 + j] / c[b_k1 - 1];
        if (std::isinf(std::abs(ctmp[j]))) {
          exitg2 = true;
        } else {
          j++;
        }
      }
      if ((j + 1) > companDim) {
        exitg1 = true;
      } else {
        b_k1++;
        companDim--;
      }
    }
    if (companDim < 1) {
      int i2;
      if (1 > (5 - k2)) {
        i2 = 0;
      } else {
        i2 = 5 - k2;
      }
      r.set_size(i2);
    } else {
      int i5;
      int loop_ub;
      bool p;
      b_companDim[0] = static_cast<signed char>(companDim);
      b_a.set_size(companDim, companDim);
      loop_ub = companDim;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4,        \
                                                                    b_loop_ub)

      for (int i3 = 0; i3 < loop_ub; i3++) {
        b_loop_ub = static_cast<int>(b_companDim[0]);
        for (i4 = 0; i4 < b_loop_ub; i4++) {
          b_a[i4 + (b_a.size(0) * i3)] = 0.0;
        }
      }
      for (int k{0}; k <= (companDim - 2); k++) {
        b_a[b_a.size(0) * k] = -ctmp[k];
        b_a[(k + (b_a.size(0) * k)) + 1] = 1.0;
      }
      b_a[b_a.size(0) * (companDim - 1)] = -ctmp[companDim - 1];
      if ((static_cast<int>((nTrailingZeros + 1) < 4)) != 0) {
        for (int b_k{0}; b_k <= nTrailingZeros; b_k++) {
          r[b_k].re = 0.0;
          r[b_k].im = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_k = 0; b_k <= nTrailingZeros; b_k++) {
          r[b_k].re = 0.0;
          r[b_k].im = 0.0;
        }
      }
      p = true;
      i5 = b_a.size(1);
      for (int c_k{0}; c_k < i5; c_k++) {
        int i6;
        i6 = b_a.size(0);
        for (int d_k{0}; d_k < i6; d_k++) {
          double b_x;
          b_x = b_a[d_k + (b_a.size(0) * c_k)];
          if (p) {
            if ((std::isinf(b_x)) || (std::isnan(b_x))) {
              p = false;
            }
          } else {
            p = false;
          }
        }
      }
      if (!p) {
        int c_loop_ub;
        eiga.set_size(b_a.size(0));
        c_loop_ub = b_a.size(0);
        if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
          for (int i7{0}; i7 < c_loop_ub; i7++) {
            eiga[i7] = dc;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i7 = 0; i7 < c_loop_ub; i7++) {
            eiga[i7] = dc;
          }
        }
      } else {
        int exitg3;
        bool b_p;
        bool c_p;
        b_p = (b_a.size(0) == b_a.size(1));
        c_p = b_p;
        if (b_p) {
          int b_j;
          b_j = 0;
          exitg1 = false;
          while ((!exitg1) && (b_j <= (b_a.size(1) - 1))) {
            int c_i;
            c_i = 0;
            do {
              exitg3 = 0;
              if (c_i <= b_j) {
                if (!(b_a[c_i + (b_a.size(0) * b_j)] ==
                      b_a[b_j + (b_a.size(0) * c_i)])) {
                  c_p = false;
                  exitg3 = 1;
                } else {
                  c_i++;
                }
              } else {
                b_j++;
                exitg3 = 2;
              }
            } while (exitg3 == 0);
            if (exitg3 == 1) {
              exitg1 = true;
            }
          }
        }
        if (c_p) {
          int d_loop_ub;
          int h_n;
          schur(b_a, T);
          h_n = T.size(0);
          V.set_size(T.size(0));
          if ((static_cast<int>(T.size(0) < 4)) != 0) {
            for (int g_k{0}; g_k < h_n; g_k++) {
              V[g_k] = T[g_k + (T.size(0) * g_k)];
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

            for (int g_k = 0; g_k < h_n; g_k++) {
              V[g_k] = T[g_k + (T.size(0) * g_k)];
            }
          }
          eiga.set_size(V.size(0));
          d_loop_ub = V.size(0);
          if ((static_cast<int>(V.size(0) < 4)) != 0) {
            for (int b_i8{0}; b_i8 < d_loop_ub; b_i8++) {
              eiga[b_i8].re = V[b_i8];
              eiga[b_i8].im = 0.0;
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

            for (int b_i8 = 0; b_i8 < d_loop_ub; b_i8++) {
              eiga[b_i8].re = V[b_i8];
              eiga[b_i8].im = 0.0;
            }
          }
        } else {
          bool d_p;
          bool e_p;
          d_p = (b_a.size(0) == b_a.size(1));
          e_p = d_p;
          if (d_p) {
            int c_j;
            c_j = 0;
            exitg1 = false;
            while ((!exitg1) && (c_j <= (b_a.size(1) - 1))) {
              int d_i;
              d_i = 0;
              do {
                exitg3 = 0;
                if (d_i <= c_j) {
                  if (!(b_a[d_i + (b_a.size(0) * c_j)] ==
                        (-b_a[c_j + (b_a.size(0) * d_i)]))) {
                    e_p = false;
                    exitg3 = 1;
                  } else {
                    d_i++;
                  }
                } else {
                  c_j++;
                  exitg3 = 2;
                }
              } while (exitg3 == 0);
              if (exitg3 == 1) {
                exitg1 = true;
              }
            }
          }
          if (e_p) {
            int e_i;
            int p_n;
            schur(b_a, T);
            p_n = T.size(0);
            eiga.set_size(T.size(0));
            e_i = 1;
            do {
              exitg3 = 0;
              if (e_i <= p_n) {
                bool guard1{false};
                guard1 = false;
                if (e_i != p_n) {
                  double d;
                  d = T[e_i + (T.size(0) * (e_i - 1))];
                  if (d != 0.0) {
                    double lambda;
                    lambda = std::abs(d);
                    eiga[e_i - 1].re = 0.0;
                    eiga[e_i - 1].im = lambda;
                    eiga[e_i].re = 0.0;
                    eiga[e_i].im = -lambda;
                    e_i += 2;
                  } else {
                    guard1 = true;
                  }
                } else {
                  guard1 = true;
                }
                if (guard1) {
                  eiga[e_i - 1].re = 0.0;
                  eiga[e_i - 1].im = 0.0;
                  e_i++;
                }
              } else {
                exitg3 = 1;
              }
            } while (exitg3 == 0);
          } else {
            eigStandard(b_a, eiga);
          }
        }
      }
      if ((static_cast<int>(companDim < 4)) != 0) {
        for (int e_k{0}; e_k < companDim; e_k++) {
          r[(e_k - k2) + 5] = eiga[e_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_k = 0; e_k < 4; e_k++) {
          r[(e_k - k2) + 5] = eiga[e_k];
        }
      }
      r.set_size((companDim - k2) + 5);
    }
  } else {
    int i1;
    if (1 > (5 - k2)) {
      i1 = 0;
    } else {
      i1 = 5 - k2;
    }
    r.set_size(i1);
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for roots.cpp
//
// [EOF]
//
