//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "HandeyeShah.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_rtwutil.h"
#include "det.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "svd1.h"
#include "xgeqp3.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Solves the problem AX=YB
//  using the formulation of
//
//  Simultaneous Robot/World and Tool/Flange
//  Calibration by Solving Homogeneous Transformation
//  Equations of the form AX=YB
//  M. Shah
//
//  Mili Shah
//  July 2014
//
// Arguments    : const double As[15][4][4]
//                const double b_Bs[15][4][4]
//                double e_X[4][4]
//                double h_Y[4][4]
//                int *err
// Return Type  : void
//
void HandeyeShah(const double As[15][4][4], const double b_Bs[15][4][4],
                 double e_X[4][4], double h_Y[4][4], int *err)
{
  static const signed char b_B[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  static const signed char iv1[4]{0, 0, 0, 1};
  coder::array<double, 2U> A;
  coder::array<double, 1U> b;
  coder::array<double, 1U> b_t;
  coder::array<double, 1U> tau;
  coder::array<int, 2U> jpvt;
  coder::array<signed char, 1U> r;
  double T[9][9];
  double b_u[9][9];
  double b_v[9][9];
  double e_K[9][9];
  double d_a[9][3];
  double b_As[6][3];
  double b_y1[3][3];
  double c_u[3][3];
  double c_v[9];
  double d_u[9];
  double e_u[3][3];
  double e_v[3][3];
  double f_v[3][3];
  double s[9];
  double x1[3][3];
  double b_a;
  double b_x_tmp;
  double c_a;
  double c_x_tmp;
  double d_x_tmp;
  double x_tmp;
  int b_y;
  int c_y;
  int maxmn;
  int minmn;
  int rankA;
  int y;
  signed char k_I[3][3];
  signed char iv[3];
  bool b_x[81];
  bool c_x[9];
  bool p;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  *err = 0;
  (void)std::memset(&T[0][0], 0, 81U * (sizeof(double)));
  for (int b_i{0}; b_i < 15; b_i++) {
    int i1;
    int kidx;
    kidx = -1;
    i1 = (b_i + 1) * 4;
    for (int b_j1{0}; b_j1 < 3; b_j1++) {
      for (int j2{0}; j2 < 3; j2++) {
        int i4;
        i4 = (j2 + i1) - 4;
        for (int b_i1{0}; b_i1 < 3; b_i1++) {
          double d;
          d = (*((double(*)[60][4])(&b_Bs[0][0][0])))[(b_j1 + i1) - 4][b_i1];
          (&e_K[0][0])[kidx + 1] =
              d * (*((double(*)[60][4])(&As[0][0][0])))[i4][0];
          (&e_K[0][0])[kidx + 2] =
              d * (*((double(*)[60][4])(&As[0][0][0])))[i4][1];
          (&e_K[0][0])[kidx + 3] =
              d * (*((double(*)[60][4])(&As[0][0][0])))[i4][2];
          kidx += 3;
        }
      }
    }
    for (int i2{0}; i2 < 9; i2++) {
      for (int i3{0}; i3 < 9; i3++) {
        T[i2][i3] += e_K[i2][i3];
      }
    }
  }
  //  Check for NaN in T
  for (int c_i{0}; c_i < 81; c_i++) {
    b_x[c_i] = std::isnan((&T[0][0])[c_i]);
  }
  y = static_cast<int>(b_x[0]);
  for (int k{0}; k < 80; k++) {
    y += static_cast<int>(b_x[k + 1]);
  }
  if (y != 0) {
    *err = -1;
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
    coder::internal::d_svd(T, b_u, s, b_v);
  } else {
    for (int i5{0}; i5 < 9; i5++) {
      for (int i6{0}; i6 < 9; i6++) {
        b_u[i5][i6] = rtNaN;
        b_v[i5][i6] = rtNaN;
      }
    }
  }
  x_tmp = coder::det(*((double(*)[3][3])(&b_v[0][0])));
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
  (void)std::copy(&b_v[0][0], (&b_v[0][0]) + 9U, &c_v[0]);
  for (int i7{0}; i7 < 3; i7++) {
    x1[i7][0] = b_a * c_v[3 * i7];
    x1[i7][1] = b_a * c_v[(3 * i7) + 1];
    x1[i7][2] = b_a * c_v[(3 * i7) + 2];
  }
  //  Check for NaN in x1
  for (int i8{0}; i8 < 9; i8++) {
    c_x[i8] = std::isnan((&x1[0][0])[i8]);
  }
  b_y = static_cast<int>(c_x[0]);
  for (int d_k{0}; d_k < 8; d_k++) {
    b_y += static_cast<int>(c_x[d_k + 1]);
  }
  if (b_y != 0) {
    *err = -1;
  }
  coder::svd(x1, c_u, *((double(*)[3][3])(&s[0])), e_v);
  c_x_tmp = coder::det(*((double(*)[3][3])(&b_u[0][0])));
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
  (void)std::copy(&b_u[0][0], (&b_u[0][0]) + 9U, &d_u[0]);
  for (int i9{0}; i9 < 3; i9++) {
    b_y1[i9][0] = c_a * d_u[3 * i9];
    b_y1[i9][1] = c_a * d_u[(3 * i9) + 1];
    b_y1[i9][2] = c_a * d_u[(3 * i9) + 2];
  }
  //  Check for NaN in Y
  for (int i10{0}; i10 < 9; i10++) {
    c_x[i10] = std::isnan((&b_y1[0][0])[i10]);
  }
  c_y = static_cast<int>(c_x[0]);
  for (int f_k{0}; f_k < 8; f_k++) {
    c_y += static_cast<int>(c_x[f_k + 1]);
  }
  if (c_y != 0) {
    *err = -1;
  }
  coder::svd(b_y1, e_u, *((double(*)[3][3])(&s[0])), f_v);
  for (int i11{0}; i11 < 3; i11++) {
    double b_d1;
    double d2;
    double d3;
    b_d1 = e_u[0][i11];
    d2 = e_u[1][i11];
    d3 = e_u[2][i11];
    for (int i14{0}; i14 < 3; i14++) {
      b_y1[i14][i11] =
          ((b_d1 * f_v[0][i14]) + (d2 * f_v[1][i14])) + (d3 * f_v[2][i14]);
    }
  }
  A.set_size(45, 6);
  for (int i12{0}; i12 < 6; i12++) {
    for (int i13{0}; i13 < 45; i13++) {
      A[i13 + (A.size(0) * i12)] = 0.0;
    }
  }
  b.set_size(45);
  for (int i15{0}; i15 < 45; i15++) {
    b[i15] = 0.0;
  }
  for (int d_i{0}; d_i < 15; d_i++) {
    int b_kidx;
    int i20;
    signed char i16;
    i16 = static_cast<signed char>((3 * (d_i + 1)) - 2);
    iv[0] = i16;
    iv[1] = static_cast<signed char>(i16 + 1);
    iv[2] = static_cast<signed char>(i16 + 2);
    r.set_size(6);
    for (int i17{0}; i17 < 6; i17++) {
      r[i17] = static_cast<signed char>(i17);
    }
    for (int i18{0}; i18 < 3; i18++) {
      k_I[i18][0] = 0;
      k_I[i18][1] = 0;
      k_I[i18][2] = 0;
    }
    i20 = (d_i + 1) * 4;
    for (int g_k{0}; g_k < 3; g_k++) {
      int As_tmp;
      k_I[g_k][g_k] = 1;
      As_tmp = (g_k + i20) - 4;
      b_As[g_k][0] = -(*((double(*)[60][4])(&As[0][0][0])))[As_tmp][0];
      b_As[g_k][1] = -(*((double(*)[60][4])(&As[0][0][0])))[As_tmp][1];
      b_As[g_k][2] = -(*((double(*)[60][4])(&As[0][0][0])))[As_tmp][2];
    }
    for (int i22{0}; i22 < 3; i22++) {
      b_As[i22 + 3][0] = static_cast<double>(k_I[i22][0]);
      b_As[i22 + 3][1] = static_cast<double>(k_I[i22][1]);
      b_As[i22 + 3][2] = static_cast<double>(k_I[i22][2]);
    }
    for (int i25{0}; i25 < 6; i25++) {
      A[((static_cast<int>(i16)) + (A.size(0) * (static_cast<int>(r[i25])))) -
        1] = (&b_As[0][0])[3 * i25];
      A[(static_cast<int>(i16)) + (A.size(0) * (static_cast<int>(r[i25])))] =
          (&b_As[0][0])[(3 * i25) + 1];
      A[((static_cast<int>(i16)) + (A.size(0) * (static_cast<int>(r[i25])))) +
        1] = (&b_As[0][0])[(3 * i25) + 2];
    }
    b_kidx = -1;
    for (int c_j1{0}; c_j1 < 3; c_j1++) {
      double d7;
      d7 = (*((double(*)[60][4])(&b_Bs[0][0][0])))[i20 - 1][c_j1];
      for (int b_j2{0}; b_j2 < 3; b_j2++) {
        (&d_a[0][0])[b_kidx + 1] = d7 * (static_cast<double>(b_B[b_j2][0]));
        (&d_a[0][0])[b_kidx + 2] = d7 * (static_cast<double>(b_B[b_j2][1]));
        (&d_a[0][0])[b_kidx + 3] = d7 * (static_cast<double>(b_B[b_j2][2]));
        b_kidx += 3;
      }
    }
    for (int i28{0}; i28 < 3; i28++) {
      double d8;
      d8 = 0.0;
      for (int i29{0}; i29 < 9; i29++) {
        d8 += d_a[i29][i28] * (&b_y1[0][0])[i29];
      }
      b[(static_cast<int>(iv[i28])) - 1] =
          (*((double(*)[60][4])(&As[0][0][0])))[i20 - 1][i28] - d8;
    }
  }
  coder::internal::lapack::xgeqp3(A, tau, jpvt);
  rankA = 0;
  if (A.size(0) < A.size(1)) {
    minmn = A.size(0);
    maxmn = A.size(1);
  } else {
    minmn = A.size(1);
    maxmn = A.size(0);
  }
  if (minmn > 0) {
    double tol;
    bool exitg1;
    tol = std::fmin(1.4901161193847656E-8,
                    2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
          std::abs(A[0]);
    exitg1 = false;
    while ((!exitg1) && (rankA < minmn)) {
      if (!(std::abs(A[rankA + (A.size(0) * rankA)]) <= tol)) {
        rankA++;
      } else {
        exitg1 = true;
      }
    }
  }
  coder::internal::LSQFromQR(A, tau, jpvt, b, rankA, b_t);
  for (int i19{0}; i19 < 3; i19++) {
    double d4;
    double d5;
    double d6;
    d4 = c_u[0][i19];
    d5 = c_u[1][i19];
    d6 = c_u[2][i19];
    for (int i24{0}; i24 < 3; i24++) {
      e_u[i24][i19] =
          ((d4 * e_v[0][i24]) + (d5 * e_v[1][i24])) + (d6 * e_v[2][i24]);
    }
  }
  for (int i21{0}; i21 < 3; i21++) {
    e_X[i21][0] = e_u[i21][0];
    e_X[i21][1] = e_u[i21][1];
    e_X[i21][2] = e_u[i21][2];
    e_X[3][i21] = b_t[i21];
  }
  for (int i23{0}; i23 < 4; i23++) {
    e_X[i23][3] = static_cast<double>(iv1[i23]);
  }
  for (int i26{0}; i26 < 3; i26++) {
    h_Y[i26][0] = b_y1[i26][0];
    h_Y[i26][1] = b_y1[i26][1];
    h_Y[i26][2] = b_y1[i26][2];
    h_Y[3][i26] = b_t[i26 + 3];
  }
  for (int i27{0}; i27 < 4; i27++) {
    h_Y[i27][3] = static_cast<double>(iv1[i27]);
  }
}

//
// File trailer for HandeyeShah.cpp
//
// [EOF]
//
