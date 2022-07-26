//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unique.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "unique.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_a
//                ::coder::array<double, 1U> &b
// Return Type  : void
//
namespace ITER {
namespace coder {
void unique_vector(const ::coder::array<double, 1U> &b_a,
                   ::coder::array<double, 1U> &b)
{
  ::coder::array<int, 1U> idx;
  int b_i;
  int b_k;
  int c_k;
  int exponent;
  int nInf;
  int nMInf;
  int nNaN;
  int na;
  int nb;
  bool exitg1;
  na = b_a.size(0);
  internal::b_sortIdx(b_a, idx);
  b.set_size(b_a.size(0));
  if ((static_cast<int>(b_a.size(0) < 4)) != 0) {
    for (int k{0}; k < na; k++) {
      b[k] = b_a[idx[k] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < na; k++) {
      b[k] = b_a[idx[k] - 1];
    }
  }
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && ((b_k + 1) <= na)) {
    if (std::isinf(b[b_k])) {
      if (b[b_k] < 0.0) {
        b_k++;
      } else {
        exitg1 = true;
      }
    } else {
      exitg1 = true;
    }
  }
  nMInf = b_k;
  b_k = b_a.size(0);
  exitg1 = false;
  while ((!exitg1) && (b_k >= 1)) {
    if (std::isnan(b[b_k - 1])) {
      b_k--;
    } else {
      exitg1 = true;
    }
  }
  nNaN = b_a.size(0) - b_k;
  exitg1 = false;
  while ((!exitg1) && (b_k >= 1)) {
    double d;
    d = b[b_k - 1];
    if (std::isinf(d)) {
      if (d > 0.0) {
        b_k--;
      } else {
        exitg1 = true;
      }
    } else {
      exitg1 = true;
    }
  }
  nInf = (b_a.size(0) - b_k) - nNaN;
  nb = -1;
  if (nMInf > 0) {
    nb = 0;
  }
  c_k = nMInf;
  while ((c_k + 1) <= b_k) {
    double b_x;
    b_x = b[c_k];
    int exitg2;
    do {
      exitg2 = 0;
      c_k++;
      if ((c_k + 1) > b_k) {
        exitg2 = 1;
      } else {
        double absx;
        double r;
        absx = std::abs(b_x / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            r = 4.94065645841247E-324;
          } else {
            (void)frexp(absx, &exponent);
            r = std::ldexp(1.0, exponent - 53);
          }
        } else {
          r = rtNaN;
        }
        if (!(std::abs(b_x - b[c_k]) < r)) {
          if (std::isinf(b[c_k])) {
            if (std::isinf(b_x)) {
              if ((b[c_k] > 0.0) != (b_x > 0.0)) {
                exitg2 = 1;
              }
            } else {
              exitg2 = 1;
            }
          } else {
            exitg2 = 1;
          }
        }
      }
    } while (exitg2 == 0);
    nb++;
    b[nb] = b_x;
  }
  if (nInf > 0) {
    nb++;
    b[nb] = b[b_k];
  }
  c_k = b_k + nInf;
  for (int j{0}; j < nNaN; j++) {
    b[(nb + j) + 1] = b[c_k + j];
  }
  nb += nNaN;
  if (1 > (nb + 1)) {
    b_i = -1;
  } else {
    b_i = nb;
  }
  b.set_size(b_i + 1);
}

} // namespace coder
} // namespace ITER

//
// File trailer for unique.cpp
//
// [EOF]
//
