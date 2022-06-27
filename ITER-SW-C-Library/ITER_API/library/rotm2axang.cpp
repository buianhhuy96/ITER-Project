//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2axang.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "rotm2axang.h"
#include "ITER_API_rtwutil.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "svd1.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>
#include <string.h>

// Function Declarations
static double rt_atan2d_snf(double u0, double b_u1);

// Function Definitions
//
// Arguments    : double u0
//                double b_u1
// Return Type  : double
//
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
// Arguments    : const double c_R[3][3]
//                double axang[4]
// Return Type  : void
//
namespace coder {
void rotm2axang(const double c_R[3][3], double axang[4])
{
  array<double, 2U> vspecial;
  creal_T b_v;
  creal_T c_u;
  double V[3][3];
  double a__1[3][3];
  double a__2[3][3];
  double p_I[3][3];
  double f_v[3];
  double b_a;
  double b_b;
  double x_re;
  int k;
  int nz;
  signed char o_I[3][3];
  bool b;
  bool b_b1;
  bool exitg1;
  x_re = 0.5 * (((c_R[0][0] + c_R[1][1]) + c_R[2][2]) - 1.0);
  if (!(std::abs(x_re) > 1.0)) {
    double d;
    d = x_re;
    x_re = std::acos(d);
  } else {
    b_v.re = x_re + 1.0;
    b_v.im = 0.0;
    internal::scalar::b_sqrt(&b_v);
    c_u.re = 1.0 - x_re;
    c_u.im = 0.0;
    internal::scalar::b_sqrt(&c_u);
    x_re = 2.0 * rt_atan2d_snf(c_u.re, b_v.re);
  }
  b_a = 2.0 * std::sin(x_re);
  f_v[0] = (c_R[1][2] - c_R[2][1]) / b_a;
  f_v[1] = (c_R[2][0] - c_R[0][2]) / b_a;
  f_v[2] = (c_R[0][1] - c_R[1][0]) / b_a;
  b = (b_mod(x_re, 3.1415926535897931) == 0.0);
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
  nz = static_cast<int>(b || b_b1);
  if (b || b_b1) {
    int i1;
    int trueCount;
    vspecial.set_size(3, nz);
    for (int b_i{0}; b_i < nz; b_i++) {
      vspecial[0] = 0.0;
      vspecial[1] = 0.0;
      vspecial[2] = 0.0;
    }
    i1 = static_cast<int>(b || b_b1);
    for (int c_i{0}; c_i < i1; c_i++) {
      for (int i2{0}; i2 < 3; i2++) {
        o_I[i2][0] = 0;
        o_I[i2][1] = 0;
        o_I[i2][2] = 0;
      }
      o_I[0][0] = 1;
      o_I[1][1] = 1;
      o_I[2][2] = 1;
      for (int i3{0}; i3 < 3; i3++) {
        p_I[i3][0] = (static_cast<double>(o_I[i3][0])) - c_R[i3][0];
        p_I[i3][1] = (static_cast<double>(o_I[i3][1])) - c_R[i3][1];
        p_I[i3][2] = (static_cast<double>(o_I[i3][2])) - c_R[i3][2];
      }
      svd(p_I, a__1, a__2, V);
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

//
// File trailer for rotm2axang.cpp
//
// [EOF]
//
