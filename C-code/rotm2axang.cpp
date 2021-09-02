//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2axang.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "rotm2axang.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "svd1.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaN;
  } else if ((std::isinf(u0)) && (std::isinf(u1))) {
    int b_u0;
    int b_u1;
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = std::atan2(static_cast<double>(b_u0), static_cast<double>(b_u1));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// Arguments    : const double R[3][3]
//                double axang[4]
// Return Type  : void
//
namespace coder {
void rotm2axang(const double R[3][3], double axang[4])
{
  array<double, 2U> vspecial;
  creal_T u;
  creal_T v;
  double V[3][3];
  double a__1[3][3];
  double a__2[3][3];
  double c_I[3][3];
  double b_v[3];
  double br_tmp_tmp;
  int k;
  signed char b_I[3][3];
  bool b;
  bool exitg1;
  bool rEQ0;
  u.re = 0.5 * (((R[0][0] + R[1][1]) + R[2][2]) - 1.0);
  if (!(std::abs(u.re) > 1.0)) {
    br_tmp_tmp = u.re;
    u.re = std::acos(br_tmp_tmp);
  } else {
    v.re = u.re + 1.0;
    v.im = 0.0;
    internal::scalar::b_sqrt(&v);
    br_tmp_tmp = u.re;
    u.re = 1.0 - br_tmp_tmp;
    u.im = 0.0;
    internal::scalar::b_sqrt(&u);
    br_tmp_tmp = u.re;
    u.re = 2.0 * rt_atan2d_snf(br_tmp_tmp, v.re);
  }
  br_tmp_tmp = 2.0 * std::sin(u.re);
  b_v[0] = (R[1][2] - R[2][1]) / br_tmp_tmp;
  b_v[1] = (R[2][0] - R[0][2]) / br_tmp_tmp;
  b_v[2] = (R[0][1] - R[1][0]) / br_tmp_tmp;
  if (std::isnan(u.re)) {
    br_tmp_tmp = rtNaN;
  } else if (std::isinf(u.re)) {
    br_tmp_tmp = rtNaN;
  } else if (u.re == 0.0) {
    br_tmp_tmp = 0.0;
  } else {
    br_tmp_tmp = std::fmod(u.re, 3.1415926535897931);
    rEQ0 = (br_tmp_tmp == 0.0);
    if (!rEQ0) {
      double q;
      q = std::abs(u.re / 3.1415926535897931);
      rEQ0 =
          !(std::abs(q - std::floor(q + 0.5)) > (2.2204460492503131E-16 * q));
    }
    if (rEQ0) {
      br_tmp_tmp = 0.0;
    } else if (u.re < 0.0) {
      br_tmp_tmp += 3.1415926535897931;
    } else {
      /* no actions */
    }
  }
  rEQ0 = (br_tmp_tmp == 0.0);
  b = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!(b_v[k] == 0.0)) {
      b = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  k = static_cast<int>(rEQ0 || b);
  if (rEQ0 || b) {
    int i;
    vspecial.set_size(3, k);
    for (i = 0; i < k; i++) {
      vspecial[0] = 0.0;
      vspecial[1] = 0.0;
      vspecial[2] = 0.0;
    }
    for (int b_i{0}; b_i < k; b_i++) {
      for (i = 0; i < 3; i++) {
        b_I[i][0] = 0;
        b_I[i][1] = 0;
        b_I[i][2] = 0;
      }
      b_I[0][0] = 1;
      b_I[1][1] = 1;
      b_I[2][2] = 1;
      for (i = 0; i < 3; i++) {
        c_I[i][0] = (static_cast<double>(b_I[i][0])) - R[i][0];
        c_I[i][1] = (static_cast<double>(b_I[i][1])) - R[i][1];
        c_I[i][2] = (static_cast<double>(b_I[i][2])) - R[i][2];
      }
      svd(c_I, a__1, a__2, V);
      vspecial[0] = V[2][0];
      vspecial[1] = V[2][1];
      vspecial[2] = V[2][2];
    }
    k = 0;
    if (rEQ0 || b) {
      k = 1;
    }
    if (0 <= (k - 1)) {
      b_v[0] = vspecial[0];
      b_v[1] = vspecial[1];
      b_v[2] = vspecial[2];
    }
  }
  br_tmp_tmp =
      1.0 / std::sqrt((rt_powd_snf(b_v[0], 2.0) + rt_powd_snf(b_v[1], 2.0)) +
                      rt_powd_snf(b_v[2], 2.0));
  axang[0] = b_v[0] * br_tmp_tmp;
  axang[1] = b_v[1] * br_tmp_tmp;
  axang[2] = b_v[2] * br_tmp_tmp;
  axang[3] = u.re;
}

} // namespace coder

//
// File trailer for rotm2axang.cpp
//
// [EOF]
//
