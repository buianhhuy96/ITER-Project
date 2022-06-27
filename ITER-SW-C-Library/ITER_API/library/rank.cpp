//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rank.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "rank.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
// Return Type  : int
//
namespace coder {
int local_rank(const ::coder::array<double, 2U> &A)
{
  array<double, 1U> s;
  int exponent;
  int irank;
  irank = 0;
  if (A.size(0) != 0) {
    double absx;
    double r;
    double tol;
    int b_i;
    int c_k;
    int h_n;
    int u0;
    int y;
    bool exitg1;
    bool p;
    p = true;
    b_i = A.size(0);
    for (int k{0}; k < 8; k++) {
      for (int b_k{0}; b_k < b_i; b_k++) {
        double b_x;
        b_x = A[b_k + (A.size(0) * k)];
        if (p) {
          if ((std::isinf(b_x)) || (std::isnan(b_x))) {
            p = false;
          }
        } else {
          p = false;
        }
      }
    }
    h_n = static_cast<int>(std::fmin(static_cast<double>(A.size(0)), 8.0));
    if (p) {
      internal::b_svd(A, s);
    } else {
      int loop_ub;
      s.set_size(h_n);
      loop_ub = h_n;
      if ((static_cast<int>(std::fmin(static_cast<double>(A.size(0)), 8.0) <
                            4.0)) != 0) {
        for (int i1{0}; i1 < h_n; i1++) {
          s[i1] = rtNaN;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i1 = 0; i1 < loop_ub; i1++) {
          s[i1] = rtNaN;
        }
      }
    }
    absx = std::abs(s[0]);
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
    u0 = A.size(0);
    if (u0 >= 8) {
      y = u0;
    } else {
      y = 8;
    }
    tol = (static_cast<double>(y)) * r;
    c_k = 0;
    exitg1 = false;
    while ((!exitg1) && (c_k <= (s.size(0) - 1))) {
      if (s[c_k] > tol) {
        irank++;
        c_k++;
      } else {
        exitg1 = true;
      }
    }
  }
  return irank;
}

} // namespace coder

//
// File trailer for rank.cpp
//
// [EOF]
//
