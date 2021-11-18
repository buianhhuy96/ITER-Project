//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "HandeyeShah.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_rtwutil.h"
#include "det.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "svd1.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const coder::array<double, 3U> &As
//                const coder::array<double, 3U> &b_Bs
//                double i_X[4][4]
//                double g_Y[4][4]
//                int *err
// Return Type  : void
//
void HandeyeShah(const coder::array<double, 3U> &As,
                 const coder::array<double, 3U> &b_Bs, double i_X[4][4],
                 double g_Y[4][4], int *err)
{
  static const signed char iv1[4]{0, 0, 0, 1};
  coder::array<double, 2U> A;
  coder::array<double, 1U> b;
  coder::array<double, 1U> b_t;
  coder::array<signed char, 1U> r;
  double T[9][9];
  double c_u[9][9];
  double e_v[9][9];
  double h_K[9][9];
  double d_a[9][3];
  double b_As[6][3];
  double b_y1[3][3];
  double d_u[3][3];
  double e_u[9];
  double f_u[3][3];
  double f_v[9];
  double g_v[3][3];
  double h_v[3][3];
  double s[9];
  double x1[3][3];
  double b_a;
  double b_x_tmp;
  double c_a;
  double c_x_tmp;
  double d_x_tmp;
  double h_n;
  double x_tmp;
  int Ra_tmp[3];
  int b_iv[3];
  int b_i;
  int b_y;
  int c_y;
  int sz_idx_1;
  int unnamed_idx_0;
  int y;
  signed char o_I[3][3];
  bool b_x[81];
  bool d_x[9];
  bool p;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  //  Solves the problem AX=YB
  //  using the formulation of
  //
  //  Simultaneous Robot/World and Tool/Flange
  //  Calibration by Solving Homogeneous Transformation
  //  Equations of the form AX=YB
  //  M. Shah
  //
  //  Mili Shah
  //  July 2014
  *err = 0;
  sz_idx_1 = (b_Bs.size(2) * 16) / 4;
  h_n = (static_cast<double>(sz_idx_1)) / 4.0;
  (void)std::memset(&T[0][0], 0, 81U * (sizeof(double)));
  b_i = static_cast<int>(h_n);
  for (int c_i{0}; c_i < b_i; c_i++) {
    int i1;
    int kidx;
    i1 = ((c_i + 1) * 4) - 3;
    Ra_tmp[0] = i1;
    Ra_tmp[1] = i1 + 1;
    Ra_tmp[2] = i1 + 2;
    kidx = -1;
    for (int b_j1{0}; b_j1 < 3; b_j1++) {
      for (int j2{0}; j2 < 3; j2++) {
        for (int b_i1{0}; b_i1 < 3; b_i1++) {
          double d;
          d = b_Bs[b_i1 + (4 * (Ra_tmp[b_j1] - 1))];
          (&h_K[0][0])[kidx + 1] = d * As[4 * (Ra_tmp[j2] - 1)];
          (&h_K[0][0])[kidx + 2] = d * As[(4 * (Ra_tmp[j2] - 1)) + 1];
          (&h_K[0][0])[kidx + 3] = d * As[(4 * (Ra_tmp[j2] - 1)) + 2];
          kidx += 3;
        }
      }
    }
    for (int i3{0}; i3 < 9; i3++) {
      for (int i4{0}; i4 < 9; i4++) {
        T[i3][i4] += h_K[i3][i4];
      }
    }
  }
  //  Check for NaN in T
  for (int i2{0}; i2 < 81; i2++) {
    b_x[i2] = std::isnan((&T[0][0])[i2]);
  }
  y = static_cast<int>(b_x[0]);
  for (int k{0}; k < 80; k++) {
    y += static_cast<int>(b_x[k + 1]);
  }
  if (y != 0) {
    *err = -201;
  }
  p = true;
  for (int b_k{0}; b_k < 9; b_k++) {
    for (int c_k{0}; c_k < 9; c_k++) {
      if (p) {
        if ((std::isinf(T[b_k][c_k])) || (std::isnan(T[b_k][c_k]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (p) {
    coder::internal::e_svd(T, c_u, s, e_v);
  } else {
    for (int i5{0}; i5 < 9; i5++) {
      for (int i6{0}; i6 < 9; i6++) {
        c_u[i5][i6] = rtNaN;
        e_v[i5][i6] = rtNaN;
      }
    }
  }
  x_tmp = coder::det(*((double(*)[3][3])(&e_v[0][0])));
  if (x_tmp < 0.0) {
    b_x_tmp = -1.0;
  } else if (x_tmp > 0.0) {
    b_x_tmp = 1.0;
  } else if (x_tmp == 0.0) {
    b_x_tmp = 0.0;
  } else {
    b_x_tmp = rtNaN;
  }
  b_a = b_x_tmp / rt_powd_snf(std::abs(x_tmp), 0.33333333333333331);
  (void)std::copy(&e_v[0][0], (&e_v[0][0]) + 9U, &f_v[0]);
  for (int i7{0}; i7 < 3; i7++) {
    x1[i7][0] = b_a * f_v[3 * i7];
    x1[i7][1] = b_a * f_v[(3 * i7) + 1];
    x1[i7][2] = b_a * f_v[(3 * i7) + 2];
  }
  //  Check for NaN in x1
  for (int i8{0}; i8 < 9; i8++) {
    d_x[i8] = std::isnan((&x1[0][0])[i8]);
  }
  b_y = static_cast<int>(d_x[0]);
  for (int d_k{0}; d_k < 8; d_k++) {
    b_y += static_cast<int>(d_x[d_k + 1]);
  }
  if (b_y != 0) {
    *err = -201;
  }
  coder::svd(x1, d_u, *((double(*)[3][3])(&s[0])), g_v);
  c_x_tmp = coder::det(*((double(*)[3][3])(&c_u[0][0])));
  if (c_x_tmp < 0.0) {
    d_x_tmp = -1.0;
  } else if (c_x_tmp > 0.0) {
    d_x_tmp = 1.0;
  } else if (c_x_tmp == 0.0) {
    d_x_tmp = 0.0;
  } else {
    d_x_tmp = rtNaN;
  }
  c_a = d_x_tmp / rt_powd_snf(std::abs(c_x_tmp), 0.33333333333333331);
  (void)std::copy(&c_u[0][0], (&c_u[0][0]) + 9U, &e_u[0]);
  for (int i9{0}; i9 < 3; i9++) {
    b_y1[i9][0] = c_a * e_u[3 * i9];
    b_y1[i9][1] = c_a * e_u[(3 * i9) + 1];
    b_y1[i9][2] = c_a * e_u[(3 * i9) + 2];
  }
  //  Check for NaN in Y
  for (int i10{0}; i10 < 9; i10++) {
    d_x[i10] = std::isnan((&b_y1[0][0])[i10]);
  }
  c_y = static_cast<int>(d_x[0]);
  for (int e_k{0}; e_k < 8; e_k++) {
    c_y += static_cast<int>(d_x[e_k + 1]);
  }
  if (c_y != 0) {
    *err = -201;
  }
  coder::svd(b_y1, f_u, *((double(*)[3][3])(&s[0])), h_v);
  for (int i11{0}; i11 < 3; i11++) {
    double b_d1;
    double d2;
    double d3;
    b_d1 = f_u[0][i11];
    d2 = f_u[1][i11];
    d3 = f_u[2][i11];
    for (int i13{0}; i13 < 3; i13++) {
      b_y1[i13][i11] =
          ((b_d1 * h_v[0][i13]) + (d2 * h_v[1][i13])) + (d3 * h_v[2][i13]);
    }
  }
  unnamed_idx_0 = static_cast<int>(static_cast<double>(3.0 * h_n));
  A.set_size(unnamed_idx_0, 6);
  for (int i12{0}; i12 < 6; i12++) {
    for (int i14{0}; i14 < unnamed_idx_0; i14++) {
      A[i14 + (A.size(0) * i12)] = 0.0;
    }
  }
  b.set_size(unnamed_idx_0);
  for (int i15{0}; i15 < unnamed_idx_0; i15++) {
    b[i15] = 0.0;
  }
  for (int d_i{0}; d_i < b_i; d_i++) {
    int b_kidx;
    int i16;
    int i25;
    i16 = (3 * (d_i + 1)) - 2;
    b_iv[0] = i16;
    b_iv[1] = i16 + 1;
    b_iv[2] = i16 + 2;
    r.set_size(6);
    for (int i20{0}; i20 < 6; i20++) {
      r[i20] = static_cast<signed char>(i20);
    }
    for (int i23{0}; i23 < 3; i23++) {
      o_I[i23][0] = 0;
      o_I[i23][1] = 0;
      o_I[i23][2] = 0;
    }
    i25 = (d_i + 1) * 4;
    for (int f_k{0}; f_k < 3; f_k++) {
      int As_tmp;
      o_I[f_k][f_k] = 1;
      As_tmp = (f_k + i25) - 4;
      b_As[f_k][0] = -As[4 * As_tmp];
      b_As[f_k][1] = -As[(4 * As_tmp) + 1];
      b_As[f_k][2] = -As[(4 * As_tmp) + 2];
    }
    for (int i26{0}; i26 < 3; i26++) {
      b_As[i26 + 3][0] = static_cast<double>(o_I[i26][0]);
      b_As[i26 + 3][1] = static_cast<double>(o_I[i26][1]);
      b_As[i26 + 3][2] = static_cast<double>(o_I[i26][2]);
    }
    for (int i27{0}; i27 < 6; i27++) {
      A[(i16 + (A.size(0) * (static_cast<int>(r[i27])))) - 1] =
          (&b_As[0][0])[3 * i27];
      A[i16 + (A.size(0) * (static_cast<int>(r[i27])))] =
          (&b_As[0][0])[(3 * i27) + 1];
      A[(i16 + (A.size(0) * (static_cast<int>(r[i27])))) + 1] =
          (&b_As[0][0])[(3 * i27) + 2];
    }
    b_kidx = -1;
    for (int c_j1{0}; c_j1 < 3; c_j1++) {
      double d7;
      d7 = b_Bs[c_j1 + (4 * (i25 - 1))];
      for (int b_j2{0}; b_j2 < 3; b_j2++) {
        (&d_a[0][0])[b_kidx + 1] = d7 * (static_cast<double>(iv[b_j2][0]));
        (&d_a[0][0])[b_kidx + 2] = d7 * (static_cast<double>(iv[b_j2][1]));
        (&d_a[0][0])[b_kidx + 3] = d7 * (static_cast<double>(iv[b_j2][2]));
        b_kidx += 3;
      }
    }
    for (int i28{0}; i28 < 3; i28++) {
      double d8;
      d8 = 0.0;
      for (int i29{0}; i29 < 9; i29++) {
        d8 += d_a[i29][i28] * (&b_y1[0][0])[i29];
      }
      b[b_iv[i28] - 1] = As[i28 + (4 * (i25 - 1))] - d8;
    }
  }
  coder::b_mldivide(A, b, b_t);
  for (int i17{0}; i17 < 3; i17++) {
    double d4;
    double d5;
    double d6;
    d4 = d_u[0][i17];
    d5 = d_u[1][i17];
    d6 = d_u[2][i17];
    for (int i21{0}; i21 < 3; i21++) {
      f_u[i21][i17] =
          ((d4 * g_v[0][i21]) + (d5 * g_v[1][i21])) + (d6 * g_v[2][i21]);
    }
  }
  for (int i18{0}; i18 < 3; i18++) {
    i_X[i18][0] = f_u[i18][0];
    i_X[i18][1] = f_u[i18][1];
    i_X[i18][2] = f_u[i18][2];
    i_X[3][i18] = b_t[i18];
  }
  for (int i19{0}; i19 < 4; i19++) {
    i_X[i19][3] = static_cast<double>(iv1[i19]);
  }
  for (int i22{0}; i22 < 3; i22++) {
    g_Y[i22][0] = b_y1[i22][0];
    g_Y[i22][1] = b_y1[i22][1];
    g_Y[i22][2] = b_y1[i22][2];
    g_Y[3][i22] = b_t[i22 + 3];
  }
  for (int i24{0}; i24 < 4; i24++) {
    g_Y[i24][3] = static_cast<double>(iv1[i24]);
  }
}

//
// File trailer for HandeyeShah.cpp
//
// [EOF]
//
