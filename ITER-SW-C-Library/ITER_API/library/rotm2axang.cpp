//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2axang.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "rotm2axang.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "svd.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace ITER {
static double rt_atan2d_snf(double u0, double b_u1);

}

// Function Definitions
//
// Arguments    : double u0
//                double b_u1
// Return Type  : double
//
namespace ITER {
static double rt_atan2d_snf(double u0, double b_u1)
{
  double y;
  if ((std::isnan(u0)) || (std::isnan(b_u1))) {
    y = rtNaN;
  } else if ((std::isinf(u0)) && (std::isinf(b_u1))) {
    int b_u0;
    int c_u1;
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (b_u1 > 0.0) {
      c_u1 = 1;
    } else {
      c_u1 = -1;
    }
    y = std::atan2(static_cast<double>(b_u0), static_cast<double>(c_u1));
  } else if (b_u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, b_u1);
  }
  return y;
}

//
// Arguments    : const double b_R[3][3]
//                double axang[4]
// Return Type  : void
//
namespace coder {
void rotm2axang(const double b_R[3][3], double axang[4])
{
  ::coder::array<double, 2U> vspecial;
  creal_T c_u;
  creal_T e_v;
  double V[3][3];
  double a__1[3][3];
  double a__2[3][3];
  double p_I[3][3];
  double f_v[3];
  double b_a;
  double b_b;
  double r;
  double x_re;
  int k;
  int nz_tmp;
  signed char o_I[3][3];
  bool b;
  bool b_b1;
  bool exitg1;
  x_re = 0.5 * (((b_R[0][0] + b_R[1][1]) + b_R[2][2]) - 1.0);
  if (!(std::abs(x_re) > 1.0)) {
    double d;
    d = x_re;
    x_re = std::acos(d);
  } else {
    e_v.re = x_re + 1.0;
    e_v.im = 0.0;
    internal::scalar::b_sqrt(&e_v);
    c_u.re = 1.0 - x_re;
    c_u.im = 0.0;
    internal::scalar::b_sqrt(&c_u);
    x_re = 2.0 * rt_atan2d_snf(c_u.re, e_v.re);
  }
  b_a = 2.0 * std::sin(x_re);
  f_v[0] = (b_R[1][2] - b_R[2][1]) / b_a;
  f_v[1] = (b_R[2][0] - b_R[0][2]) / b_a;
  f_v[2] = (b_R[0][1] - b_R[1][0]) / b_a;
  if (std::isnan(x_re)) {
    r = rtNaN;
  } else if (std::isinf(x_re)) {
    r = rtNaN;
  } else if (x_re == 0.0) {
    r = 0.0;
  } else {
    bool rEQ0;
    r = std::fmod(x_re, 3.1415926535897931);
    rEQ0 = (r == 0.0);
    if (!rEQ0) {
      double b_q;
      b_q = std::abs(x_re / 3.1415926535897931);
      rEQ0 = !(std::abs(b_q - std::floor(b_q + 0.5)) >
               (2.2204460492503131E-16 * b_q));
    }
    if (rEQ0) {
      r = 0.0;
    } else if (x_re < 0.0) {
      r += 3.1415926535897931;
    } else {
      /* no actions */
    }
  }
  b = (r == 0.0);
  b_b1 = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!(f_v[k] == 0.0)) {
      b_b1 = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  nz_tmp = static_cast<int>(b || b_b1);
  if (b || b_b1) {
    int trueCount;
    vspecial.set_size(3, nz_tmp);
    for (int b_i{0}; b_i < nz_tmp; b_i++) {
      vspecial[0] = 0.0;
      vspecial[1] = 0.0;
      vspecial[2] = 0.0;
    }
    for (int c_i{0}; c_i < nz_tmp; c_i++) {
      for (int i1{0}; i1 < 3; i1++) {
        o_I[i1][0] = 0;
        o_I[i1][1] = 0;
        o_I[i1][2] = 0;
      }
      o_I[0][0] = 1;
      o_I[1][1] = 1;
      o_I[2][2] = 1;
      for (int i2{0}; i2 < 3; i2++) {
        p_I[i2][0] = (static_cast<double>(o_I[i2][0])) - b_R[i2][0];
        p_I[i2][1] = (static_cast<double>(o_I[i2][1])) - b_R[i2][1];
        p_I[i2][2] = (static_cast<double>(o_I[i2][2])) - b_R[i2][2];
      }
      b_svd(p_I, a__1, a__2, V);
      vspecial[0] = V[2][0];
      vspecial[1] = V[2][1];
      vspecial[2] = V[2][2];
    }
    trueCount = 0;
    if (b || b_b1) {
      trueCount = 1;
    }
    if (0 <= (trueCount - 1)) {
      f_v[0] = vspecial[0];
      f_v[1] = vspecial[1];
      f_v[2] = vspecial[2];
    }
  }
  b_b = 1.0 / std::sqrt((rt_powd_snf(f_v[0], 2.0) + rt_powd_snf(f_v[1], 2.0)) +
                        rt_powd_snf(f_v[2], 2.0));
  axang[0] = f_v[0] * b_b;
  axang[1] = f_v[1] * b_b;
  axang[2] = f_v[2] * b_b;
  axang[3] = x_re;
}

} // namespace coder
} // namespace ITER

//
// File trailer for rotm2axang.cpp
//
// [EOF]
//
