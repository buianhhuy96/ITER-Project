//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotm2axang.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
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
// Arguments    : const double d_R[3][3]
//                double axang[4]
// Return Type  : void
//
namespace coder {
void rotm2axang(const double d_R[3][3], double axang[4])
{
  array<double, 2U> vspecial;
  creal_T b_u;
  creal_T b_v;
  double V[3][3];
  double a__1[3][3];
  double a__2[3][3];
  double m_I[3][3];
  double c_v[3];
  double b_a;
  double c_b;
  double r;
  double x_re;
  int k;
  int nz_tmp;
  signed char k_I[3][3];
  bool b;
  bool b_b1;
  bool exitg1;
  x_re = 0.5 * (((d_R[0][0] + d_R[1][1]) + d_R[2][2]) - 1.0);
  if (!(std::abs(x_re) > 1.0)) {
    double d;
    d = x_re;
    x_re = std::acos(d);
  } else {
    b_v.re = x_re + 1.0;
    b_v.im = 0.0;
    internal::scalar::b_sqrt(&b_v);
    b_u.re = 1.0 - x_re;
    b_u.im = 0.0;
    internal::scalar::b_sqrt(&b_u);
    x_re = 2.0 * rt_atan2d_snf(b_u.re, b_v.re);
  }
  b_a = 2.0 * std::sin(x_re);
  c_v[0] = (d_R[1][2] - d_R[2][1]) / b_a;
  c_v[1] = (d_R[2][0] - d_R[0][2]) / b_a;
  c_v[2] = (d_R[0][1] - d_R[1][0]) / b_a;
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
      double q;
      q = std::abs(x_re / 3.1415926535897931);
      rEQ0 =
          !(std::abs(q - std::floor(q + 0.5)) > (2.2204460492503131E-16 * q));
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
    if (!(c_v[k] == 0.0)) {
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
        k_I[i1][0] = 0;
        k_I[i1][1] = 0;
        k_I[i1][2] = 0;
      }
      k_I[0][0] = 1;
      k_I[1][1] = 1;
      k_I[2][2] = 1;
      for (int i2{0}; i2 < 3; i2++) {
        m_I[i2][0] = (static_cast<double>(k_I[i2][0])) - d_R[i2][0];
        m_I[i2][1] = (static_cast<double>(k_I[i2][1])) - d_R[i2][1];
        m_I[i2][2] = (static_cast<double>(k_I[i2][2])) - d_R[i2][2];
      }
      svd(m_I, a__1, a__2, V);
      vspecial[0] = V[2][0];
      vspecial[1] = V[2][1];
      vspecial[2] = V[2][2];
    }
    trueCount = 0;
    if (b || b_b1) {
      trueCount = 1;
    }
    if (0 <= (trueCount - 1)) {
      c_v[0] = vspecial[0];
      c_v[1] = vspecial[1];
      c_v[2] = vspecial[2];
    }
  }
  c_b = 1.0 / std::sqrt((rt_powd_snf(c_v[0], 2.0) + rt_powd_snf(c_v[1], 2.0)) +
                        rt_powd_snf(c_v[2], 2.0));
  axang[0] = c_v[0] * c_b;
  axang[1] = c_v[1] * c_b;
  axang[2] = c_v[2] * c_b;
  axang[3] = x_re;
}

} // namespace coder

//
// File trailer for rotm2axang.cpp
//
// [EOF]
//
