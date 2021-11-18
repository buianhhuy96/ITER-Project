//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "fitgeotrans.h"
#include "inv.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &movingPoints
//                const ::coder::array<double, 2U> &fixedPoints
//                projective2d *tform
// Return Type  : void
//
namespace coder {
void fitgeotrans(const ::coder::array<double, 2U> &movingPoints,
                 const ::coder::array<double, 2U> &fixedPoints,
                 projective2d *tform)
{
  array<double, 2U> i_X;
  array<double, 2U> uv;
  array<double, 2U> xy;
  array<double, 1U> b_x;
  array<double, 1U> c_B;
  array<double, 1U> c_u;
  array<double, 1U> e_v;
  array<double, 1U> r;
  array<double, 1U> s;
  array<double, 1U> tau;
  array<double, 1U> y;
  double T[3][3];
  double Tvec[9];
  double e_B[3][3];
  double h_Y[3][3];
  double normMatrix1[3][3];
  double normMatrix2[3][3];
  double g_Y[8];
  double a21;
  double d3;
  double d4;
  double maxval;
  int jpvt[8];
  int ab_loop_ub;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int exponent;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m_loop_ub;
  int o_loop_ub;
  int p_loop_ub;
  int q_loop_ub;
  int r1;
  int r2;
  int r3;
  int r_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int u_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int x_loop_ub;
  int y_loop_ub;
  signed char ipiv[8];
  bool guard1{false};
  images::geotrans::internal::normalizeControlPoints(movingPoints, uv,
                                                     normMatrix1);
  images::geotrans::internal::normalizeControlPoints(fixedPoints, xy,
                                                     normMatrix2);
  loop_ub = xy.size(0);
  b_x.set_size(xy.size(0));
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    b_x[b_i] = xy[b_i];
  }
  b_loop_ub = xy.size(0);
  y.set_size(xy.size(0));
  for (int i1{0}; i1 < b_loop_ub; i1++) {
    y[i1] = xy[i1 + xy.size(0)];
  }
  c_loop_ub = uv.size(0);
  c_u.set_size(uv.size(0));
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    c_u[i2] = uv[i2];
  }
  d_loop_ub = uv.size(0);
  e_v.set_size(uv.size(0));
  for (int i3{0}; i3 < d_loop_ub; i3++) {
    e_v[i3] = uv[i3 + uv.size(0)];
  }
  c_B.set_size(c_u.size(0));
  e_loop_ub = c_u.size(0);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    c_B[i4] = -c_u[i4];
  }
  r.set_size(e_v.size(0));
  f_loop_ub = e_v.size(0);
  for (int i5{0}; i5 < f_loop_ub; i5++) {
    r[i5] = -e_v[i5];
  }
  i_X.set_size(b_x.size(0) + xy.size(0), 8);
  g_loop_ub = b_x.size(0);
  for (int i6{0}; i6 < g_loop_ub; i6++) {
    i_X[i6] = b_x[i6];
  }
  h_loop_ub = y.size(0);
  for (int i7{0}; i7 < h_loop_ub; i7++) {
    i_X[i7 + i_X.size(0)] = y[i7];
  }
  i_loop_ub = xy.size(0);
  for (int i8{0}; i8 < i_loop_ub; i8++) {
    i_X[i8 + (i_X.size(0) * 2)] = 1.0;
  }
  j_loop_ub = xy.size(0);
  for (int i9{0}; i9 < j_loop_ub; i9++) {
    i_X[i9 + (i_X.size(0) * 3)] = 0.0;
  }
  k_loop_ub = xy.size(0);
  for (int i10{0}; i10 < k_loop_ub; i10++) {
    i_X[i10 + (i_X.size(0) * 4)] = 0.0;
  }
  m_loop_ub = xy.size(0);
  for (int i11{0}; i11 < m_loop_ub; i11++) {
    i_X[i11 + (i_X.size(0) * 5)] = 0.0;
  }
  o_loop_ub = c_B.size(0);
  for (int i12{0}; i12 < o_loop_ub; i12++) {
    i_X[i12 + (i_X.size(0) * 6)] = c_B[i12] * b_x[i12];
  }
  p_loop_ub = c_B.size(0);
  for (int i13{0}; i13 < p_loop_ub; i13++) {
    i_X[i13 + (i_X.size(0) * 7)] = c_B[i13] * y[i13];
  }
  q_loop_ub = xy.size(0);
  for (int i14{0}; i14 < q_loop_ub; i14++) {
    i_X[i14 + b_x.size(0)] = 0.0;
  }
  r_loop_ub = xy.size(0);
  for (int i15{0}; i15 < r_loop_ub; i15++) {
    i_X[(i15 + b_x.size(0)) + i_X.size(0)] = 0.0;
  }
  s_loop_ub = xy.size(0);
  for (int i16{0}; i16 < s_loop_ub; i16++) {
    i_X[(i16 + b_x.size(0)) + (i_X.size(0) * 2)] = 0.0;
  }
  t_loop_ub = b_x.size(0);
  for (int i17{0}; i17 < t_loop_ub; i17++) {
    i_X[(i17 + b_x.size(0)) + (i_X.size(0) * 3)] = b_x[i17];
  }
  u_loop_ub = y.size(0);
  for (int i18{0}; i18 < u_loop_ub; i18++) {
    i_X[(i18 + b_x.size(0)) + (i_X.size(0) * 4)] = y[i18];
  }
  v_loop_ub = xy.size(0);
  for (int i19{0}; i19 < v_loop_ub; i19++) {
    i_X[(i19 + b_x.size(0)) + (i_X.size(0) * 5)] = 1.0;
  }
  w_loop_ub = r.size(0);
  for (int i20{0}; i20 < w_loop_ub; i20++) {
    i_X[(i20 + b_x.size(0)) + (i_X.size(0) * 6)] = r[i20] * b_x[i20];
  }
  x_loop_ub = r.size(0);
  for (int i21{0}; i21 < x_loop_ub; i21++) {
    i_X[(i21 + b_x.size(0)) + (i_X.size(0) * 7)] = r[i21] * y[i21];
  }
  if (i_X.size(0) != 0) {
    double absx;
    int h_n;
    int i22;
    bool p;
    p = true;
    i22 = i_X.size(0);
    for (int k{0}; k < 8; k++) {
      for (int b_k{0}; b_k < i22; b_k++) {
        double d_x;
        d_x = i_X[b_k + (i_X.size(0) * k)];
        if (p) {
          if ((std::isinf(d_x)) || (std::isnan(d_x))) {
            p = false;
          }
        } else {
          p = false;
        }
      }
    }
    h_n = static_cast<int>(std::fmin(static_cast<double>(i_X.size(0)), 8.0));
    if (p) {
      internal::b_svd(i_X, s);
    } else {
      s.set_size(h_n);
      for (int i25{0}; i25 < h_n; i25++) {
        s[i25] = rtNaN;
      }
    }
    absx = std::abs(s[0]);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (!(absx <= 2.2250738585072014E-308)) {
        (void)frexp(absx, &exponent);
      }
    }
  }
  c_B.set_size(c_u.size(0) + e_v.size(0));
  y_loop_ub = c_u.size(0);
  for (int i23{0}; i23 < y_loop_ub; i23++) {
    c_B[i23] = c_u[i23];
  }
  ab_loop_ub = e_v.size(0);
  for (int i24{0}; i24 < ab_loop_ub; i24++) {
    c_B[i24 + c_u.size(0)] = e_v[i24];
  }
  guard1 = false;
  if (i_X.size(0) == 0) {
    guard1 = true;
  } else if (c_B.size(0) == 0) {
    guard1 = true;
  } else if (i_X.size(0) == 8) {
    for (int i26{0}; i26 < 8; i26++) {
      ipiv[i26] = static_cast<signed char>(i26 + 1);
    }
    for (int j{0}; j < 7; j++) {
      double smax;
      int b_a;
      int b_tmp;
      int i_n;
      int jA;
      int jp1j;
      int mmj_tmp;
      signed char i33;
      mmj_tmp = 6 - j;
      b_tmp = j * 9;
      jp1j = b_tmp + 2;
      i_n = 8 - j;
      b_a = 0;
      smax = std::abs(i_X[b_tmp]);
      for (int e_k{2}; e_k <= i_n; e_k++) {
        double b_s;
        b_s = std::abs(i_X[(b_tmp + e_k) - 1]);
        if (b_s > smax) {
          b_a = e_k - 1;
          smax = b_s;
        }
      }
      if (i_X[b_tmp + b_a] != 0.0) {
        int i32;
        if (b_a != 0) {
          int ipiv_tmp;
          ipiv_tmp = j + b_a;
          ipiv[j] = static_cast<signed char>(ipiv_tmp + 1);
          for (int f_k{0}; f_k < 8; f_k++) {
            double b_temp;
            int b_temp_tmp;
            int i38;
            int temp_tmp;
            temp_tmp = f_k * 8;
            b_temp_tmp = j + temp_tmp;
            b_temp = i_X[b_temp_tmp];
            i38 = ipiv_tmp + temp_tmp;
            i_X[b_temp_tmp] = i_X[i38];
            i_X[i38] = b_temp;
          }
        }
        i32 = (b_tmp - j) + 8;
        for (int g_i{jp1j}; g_i <= i32; g_i++) {
          i_X[g_i - 1] = i_X[g_i - 1] / i_X[b_tmp];
        }
      }
      jA = b_tmp;
      for (int c_j{0}; c_j <= mmj_tmp; c_j++) {
        double yjy;
        int yjy_tmp;
        yjy_tmp = (b_tmp + (c_j * 8)) + 8;
        yjy = i_X[yjy_tmp];
        if (i_X[yjy_tmp] != 0.0) {
          int i35;
          int i37;
          i35 = jA + 10;
          i37 = (jA - j) + 16;
          for (int ijA{i35}; ijA <= i37; ijA++) {
            i_X[ijA - 1] =
                i_X[ijA - 1] + (i_X[((b_tmp + ijA) - jA) - 9] * (-yjy));
          }
        }
        jA += 8;
      }
      i33 = ipiv[j];
      if ((static_cast<int>(i33)) != (j + 1)) {
        double temp;
        int b_B_tmp;
        temp = c_B[j];
        b_B_tmp = (static_cast<int>(i33)) - 1;
        c_B[j] = c_B[b_B_tmp];
        c_B[b_B_tmp] = temp;
      }
    }
    for (int c_k{0}; c_k < 8; c_k++) {
      int kAcol;
      kAcol = c_k * 8;
      if (c_B[c_k] != 0.0) {
        int i30;
        i30 = c_k + 2;
        for (int c_i{i30}; c_i < 9; c_i++) {
          c_B[c_i - 1] = c_B[c_i - 1] - (c_B[c_k] * i_X[(c_i + kAcol) - 1]);
        }
      }
    }
    for (int d_k{7}; d_k >= 0; d_k--) {
      int b_kAcol;
      b_kAcol = d_k * 8;
      if (c_B[d_k] != 0.0) {
        c_B[d_k] = c_B[d_k] / i_X[d_k + b_kAcol];
        for (int d_i{0}; d_i < d_k; d_i++) {
          c_B[d_i] = c_B[d_i] - (c_B[d_k] * i_X[d_i + b_kAcol]);
        }
      }
    }
  } else {
    int b_mn;
    int m;
    int maxmn;
    int minmn;
    int rankA;
    int u0;
    internal::lapack::b_xgeqp3(i_X, tau, jpvt);
    rankA = 0;
    if (i_X.size(0) < 8) {
      minmn = i_X.size(0);
      maxmn = 8;
    } else {
      minmn = 8;
      maxmn = i_X.size(0);
    }
    if (minmn > 0) {
      double tol;
      bool exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(i_X[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(i_X[rankA + (i_X.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    (void)std::memset(&g_Y[0], 0, 8U * (sizeof(double)));
    m = i_X.size(0);
    u0 = i_X.size(0);
    if (u0 <= 8) {
      b_mn = u0;
    } else {
      b_mn = 8;
    }
    for (int b_j{0}; b_j < b_mn; b_j++) {
      if (tau[b_j] != 0.0) {
        double wj;
        int i34;
        wj = c_B[b_j];
        i34 = b_j + 2;
        for (int h_i{i34}; h_i <= m; h_i++) {
          wj += i_X[(h_i + (i_X.size(0) * b_j)) - 1] * c_B[h_i - 1];
        }
        wj *= tau[b_j];
        if (wj != 0.0) {
          c_B[b_j] = c_B[b_j] - wj;
          for (int m_i{i34}; m_i <= m; m_i++) {
            c_B[m_i - 1] =
                c_B[m_i - 1] - (i_X[(m_i + (i_X.size(0) * b_j)) - 1] * wj);
          }
        }
      }
    }
    for (int e_i{0}; e_i < rankA; e_i++) {
      g_Y[jpvt[e_i] - 1] = c_B[e_i];
    }
    for (int d_j{rankA}; d_j >= 1; d_j--) {
      int Y_tmp;
      Y_tmp = jpvt[d_j - 1] - 1;
      g_Y[Y_tmp] /= i_X[(d_j + (i_X.size(0) * (d_j - 1))) - 1];
      for (int k_i{0}; k_i <= (d_j - 2); k_i++) {
        int i39;
        i39 = jpvt[k_i];
        g_Y[i39 - 1] -= g_Y[Y_tmp] * i_X[k_i + (i_X.size(0) * (d_j - 1))];
      }
    }
    c_B.set_size(8);
    for (int i36{0}; i36 < 8; i36++) {
      c_B[i36] = g_Y[i36];
    }
  }
  if (guard1) {
    c_B.set_size(8);
    for (int i28{0}; i28 < 8; i28++) {
      c_B[i28] = 0.0;
    }
  }
  for (int i27{0}; i27 < 8; i27++) {
    Tvec[i27] = c_B[i27];
  }
  Tvec[8] = 1.0;
  for (int i29{0}; i29 < 3; i29++) {
    double b_d1;
    double d;
    double d2;
    d = Tvec[i29];
    b_d1 = Tvec[i29 + 3];
    d2 = Tvec[i29 + 6];
    for (int i31{0}; i31 < 3; i31++) {
      e_B[i31][i29] =
          ((d * normMatrix1[i31][0]) + (b_d1 * normMatrix1[i31][1])) +
          (d2 * normMatrix1[i31][2]);
    }
  }
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = std::abs(normMatrix2[0][0]);
  a21 = std::abs(normMatrix2[0][1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (std::abs(normMatrix2[0][2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  normMatrix2[0][r2] /= normMatrix2[0][r1];
  normMatrix2[0][r3] /= normMatrix2[0][r1];
  normMatrix2[1][r2] -= normMatrix2[0][r2] * normMatrix2[1][r1];
  normMatrix2[1][r3] -= normMatrix2[0][r3] * normMatrix2[1][r1];
  normMatrix2[2][r2] -= normMatrix2[0][r2] * normMatrix2[2][r1];
  normMatrix2[2][r3] -= normMatrix2[0][r3] * normMatrix2[2][r1];
  if (std::abs(normMatrix2[1][r3]) > std::abs(normMatrix2[1][r2])) {
    int rtemp;
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  normMatrix2[1][r3] /= normMatrix2[1][r2];
  normMatrix2[2][r3] -= normMatrix2[1][r3] * normMatrix2[2][r2];
  d3 = e_B[0][r2] - (e_B[0][r1] * normMatrix2[0][r2]);
  d4 = ((e_B[0][r3] - (e_B[0][r1] * normMatrix2[0][r3])) -
        (d3 * normMatrix2[1][r3])) /
       normMatrix2[2][r3];
  h_Y[0][2] = d4;
  d3 -= d4 * normMatrix2[2][r2];
  d3 /= normMatrix2[1][r2];
  h_Y[0][1] = d3;
  h_Y[0][0] =
      ((e_B[0][r1] - (d4 * normMatrix2[2][r1])) - (d3 * normMatrix2[1][r1])) /
      normMatrix2[0][r1];
  d3 = e_B[1][r2] - (e_B[1][r1] * normMatrix2[0][r2]);
  d4 = ((e_B[1][r3] - (e_B[1][r1] * normMatrix2[0][r3])) -
        (d3 * normMatrix2[1][r3])) /
       normMatrix2[2][r3];
  h_Y[1][2] = d4;
  d3 -= d4 * normMatrix2[2][r2];
  d3 /= normMatrix2[1][r2];
  h_Y[1][1] = d3;
  h_Y[1][0] =
      ((e_B[1][r1] - (d4 * normMatrix2[2][r1])) - (d3 * normMatrix2[1][r1])) /
      normMatrix2[0][r1];
  d3 = e_B[2][r2] - (e_B[2][r1] * normMatrix2[0][r2]);
  d4 = ((e_B[2][r3] - (e_B[2][r1] * normMatrix2[0][r3])) -
        (d3 * normMatrix2[1][r3])) /
       normMatrix2[2][r3];
  h_Y[2][2] = d4;
  d3 -= d4 * normMatrix2[2][r2];
  d3 /= normMatrix2[1][r2];
  h_Y[2][1] = d3;
  h_Y[2][0] =
      ((e_B[2][r1] - (d4 * normMatrix2[2][r1])) - (d3 * normMatrix2[1][r1])) /
      normMatrix2[0][r1];
  inv(h_Y, T);
  for (int i40{0}; i40 < 3; i40++) {
    tform->T[i40][0] = T[i40][0] / T[2][2];
    tform->T[i40][1] = T[i40][1] / T[2][2];
    tform->T[i40][2] = T[i40][2] / T[2][2];
  }
}

} // namespace coder

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
