//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
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
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 3U> &As
//                const ::coder::array<double, 3U> &b_Bs
//                double d_X[4][4]
//                double g_Y[4][4]
//                int *err
// Return Type  : void
//
namespace ITER {
void HandeyeShah(const ::coder::array<double, 3U> &As,
                 const ::coder::array<double, 3U> &b_Bs, double d_X[4][4],
                 double g_Y[4][4], int *err)
{
  static const signed char b_iv1[4]{0, 0, 0, 1};
  ::coder::array<double, 2U> A;
  ::coder::array<double, 1U> b;
  ::coder::array<double, 1U> b_t;
  ::coder::array<signed char, 1U> r;
  double T[9][9];
  double c_u[9][9];
  double e_v[9][9];
  double f_K[9][9];
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
  double b_d1;
  double b_x_tmp;
  double c_a;
  double c_x_tmp;
  double d2;
  double d3;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d_x_tmp;
  double h_n;
  double x_tmp;
  int Ra_tmp[3];
  int b_iv[3];
  int b_i8;
  int b_loop_ub;
  int b_y;
  int c_loop_ub;
  int c_y;
  int i1;
  int i17;
  int i18;
  int i2;
  int i20;
  int i27;
  int loop_ub;
  int sz_idx_1;
  int unnamed_idx_0;
  int y;
  signed char o_I[3][3];
  bool b_x[81];
  bool e_x[9];
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
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

  for (int b_i = 0; b_i < 9; b_i++) {
    for (i2 = 0; i2 < 9; i2++) {
      T[b_i][i2] = 0.0;
    }
  }
  i1 = static_cast<int>(h_n);
  for (int c_i{0}; c_i < i1; c_i++) {
    int i3;
    int kidx;
    i3 = ((c_i + 1) * 4) - 3;
    Ra_tmp[0] = i3;
    Ra_tmp[1] = i3 + 1;
    Ra_tmp[2] = i3 + 2;
    kidx = -1;
    for (int b_j1{0}; b_j1 < 3; b_j1++) {
      for (int j2{0}; j2 < 3; j2++) {
        for (int b_i1{0}; b_i1 < 3; b_i1++) {
          double d;
          d = b_Bs[b_i1 + (4 * (Ra_tmp[b_j1] - 1))];
          (&f_K[0][0])[kidx + 1] = d * As[4 * (Ra_tmp[j2] - 1)];
          (&f_K[0][0])[kidx + 2] = d * As[(4 * (Ra_tmp[j2] - 1)) + 1];
          (&f_K[0][0])[kidx + 3] = d * As[(4 * (Ra_tmp[j2] - 1)) + 2];
          kidx += 3;
        }
      }
    }
    for (int i5{0}; i5 < 9; i5++) {
      for (int i6{0}; i6 < 9; i6++) {
        T[i5][i6] += f_K[i5][i6];
      }
    }
  }
  //  Check for NaN in T
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i4 = 0; i4 < 81; i4++) {
    b_x[i4] = std::isnan((&T[0][0])[i4]);
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
    coder::internal::h_svd(T, c_u, s, e_v);
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

    for (int i7 = 0; i7 < 9; i7++) {
      for (b_i8 = 0; b_i8 < 9; b_i8++) {
        c_u[i7][b_i8] = rtNaN;
        e_v[i7][b_i8] = rtNaN;
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
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i9 = 0; i9 < 9; i9++) {
    f_v[i9] = e_v[0][i9];
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i10 = 0; i10 < 3; i10++) {
    x1[i10][0] = b_a * f_v[3 * i10];
    x1[i10][1] = b_a * f_v[(3 * i10) + 1];
    x1[i10][2] = b_a * f_v[(3 * i10) + 2];
  }
  //  Check for NaN in x1
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i11 = 0; i11 < 9; i11++) {
    e_x[i11] = std::isnan((&x1[0][0])[i11]);
  }
  b_y = static_cast<int>(e_x[0]);
  for (int d_k{0}; d_k < 8; d_k++) {
    b_y += static_cast<int>(e_x[d_k + 1]);
  }
  if (b_y != 0) {
    *err = -201;
  }
  coder::b_svd(x1, d_u, *((double(*)[3][3])(&s[0])), g_v);
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
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i12 = 0; i12 < 9; i12++) {
    e_u[i12] = c_u[0][i12];
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i13 = 0; i13 < 3; i13++) {
    b_y1[i13][0] = c_a * e_u[3 * i13];
    b_y1[i13][1] = c_a * e_u[(3 * i13) + 1];
    b_y1[i13][2] = c_a * e_u[(3 * i13) + 2];
  }
  //  Check for NaN in Y
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i14 = 0; i14 < 9; i14++) {
    e_x[i14] = std::isnan((&b_y1[0][0])[i14]);
  }
  c_y = static_cast<int>(e_x[0]);
  for (int e_k{0}; e_k < 8; e_k++) {
    c_y += static_cast<int>(e_x[e_k + 1]);
  }
  if (c_y != 0) {
    *err = -201;
  }
  coder::b_svd(b_y1, f_u, *((double(*)[3][3])(&s[0])), h_v);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_d1, i17, d2, d3, d4)

  for (int i15 = 0; i15 < 3; i15++) {
    d2 = f_u[0][i15];
    d3 = f_u[1][i15];
    d4 = f_u[2][i15];
    for (i17 = 0; i17 < 3; i17++) {
      b_d1 = ((d2 * h_v[0][i17]) + (d3 * h_v[1][i17])) + (d4 * h_v[2][i17]);
      b_y1[i17][i15] = b_d1;
    }
  }
  loop_ub = static_cast<int>(static_cast<double>(3.0 * h_n));
  A.set_size(loop_ub, 6);
  b_loop_ub = loop_ub;
  if ((static_cast<int>((6 * loop_ub) < 4)) != 0) {
    for (int i16{0}; i16 < 6; i16++) {
      for (i18 = 0; i18 < loop_ub; i18++) {
        A[i18 + (A.size(0) * i16)] = 0.0;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18)

    for (int i16 = 0; i16 < 6; i16++) {
      for (i18 = 0; i18 < b_loop_ub; i18++) {
        A[i18 + (A.size(0) * i16)] = 0.0;
      }
    }
  }
  unnamed_idx_0 = static_cast<int>(static_cast<double>(3.0 * h_n));
  b.set_size(unnamed_idx_0);
  c_loop_ub = unnamed_idx_0;
  if ((static_cast<int>(unnamed_idx_0 < 4)) != 0) {
    for (int i19{0}; i19 < unnamed_idx_0; i19++) {
      b[i19] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < c_loop_ub; i19++) {
      b[i19] = 0.0;
    }
  }
  i20 = static_cast<int>(h_n);
  for (int d_i{0}; d_i < i20; d_i++) {
    int b_kidx;
    int i21;
    int i30;
    i21 = (3 * (d_i + 1)) - 2;
    b_iv[0] = i21;
    b_iv[1] = i21 + 1;
    b_iv[2] = i21 + 2;
    r.set_size(6);
    for (int i25{0}; i25 < 6; i25++) {
      r[i25] = static_cast<signed char>(i25);
    }
    for (int i28{0}; i28 < 3; i28++) {
      o_I[i28][0] = 0;
      o_I[i28][1] = 0;
      o_I[i28][2] = 0;
    }
    i30 = (d_i + 1) * 4;
    for (int g_k{0}; g_k < 3; g_k++) {
      int As_tmp;
      o_I[g_k][g_k] = 1;
      As_tmp = (g_k + i30) - 4;
      b_As[g_k][0] = -As[4 * As_tmp];
      b_As[g_k][1] = -As[(4 * As_tmp) + 1];
      b_As[g_k][2] = -As[(4 * As_tmp) + 2];
    }
    for (int i31{0}; i31 < 3; i31++) {
      b_As[i31 + 3][0] = static_cast<double>(o_I[i31][0]);
      b_As[i31 + 3][1] = static_cast<double>(o_I[i31][1]);
      b_As[i31 + 3][2] = static_cast<double>(o_I[i31][2]);
    }
    for (int i32{0}; i32 < 6; i32++) {
      A[(i21 + (A.size(0) * (static_cast<int>(r[i32])))) - 1] =
          (&b_As[0][0])[3 * i32];
      A[i21 + (A.size(0) * (static_cast<int>(r[i32])))] =
          (&b_As[0][0])[(3 * i32) + 1];
      A[(i21 + (A.size(0) * (static_cast<int>(r[i32])))) + 1] =
          (&b_As[0][0])[(3 * i32) + 2];
    }
    b_kidx = -1;
    for (int c_j1{0}; c_j1 < 3; c_j1++) {
      double d9;
      d9 = b_Bs[c_j1 + (4 * (i30 - 1))];
      for (int b_j2{0}; b_j2 < 3; b_j2++) {
        (&d_a[0][0])[b_kidx + 1] = d9 * (static_cast<double>(iv[b_j2][0]));
        (&d_a[0][0])[b_kidx + 2] = d9 * (static_cast<double>(iv[b_j2][1]));
        (&d_a[0][0])[b_kidx + 3] = d9 * (static_cast<double>(iv[b_j2][2]));
        b_kidx += 3;
      }
    }
    for (int i33{0}; i33 < 3; i33++) {
      double d10;
      d10 = 0.0;
      for (int i34{0}; i34 < 9; i34++) {
        d10 += d_a[i34][i33] * (&b_y1[0][0])[i34];
      }
      b[b_iv[i33] - 1] = As[i33 + (4 * (i30 - 1))] - d10;
    }
  }
  coder::d_mldivide(A, b, b_t);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d5, i27, d6, d7, d8)

  for (int i22 = 0; i22 < 3; i22++) {
    d6 = d_u[0][i22];
    d7 = d_u[1][i22];
    d8 = d_u[2][i22];
    for (i27 = 0; i27 < 3; i27++) {
      d5 = ((d6 * g_v[0][i27]) + (d7 * g_v[1][i27])) + (d8 * g_v[2][i27]);
      f_u[i27][i22] = d5;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i23 = 0; i23 < 3; i23++) {
    d_X[i23][0] = f_u[i23][0];
    d_X[i23][1] = f_u[i23][1];
    d_X[i23][2] = f_u[i23][2];
    d_X[3][i23] = b_t[i23];
  }
  for (int i24{0}; i24 < 4; i24++) {
    d_X[i24][3] = static_cast<double>(b_iv1[i24]);
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i26 = 0; i26 < 3; i26++) {
    g_Y[i26][0] = b_y1[i26][0];
    g_Y[i26][1] = b_y1[i26][1];
    g_Y[i26][2] = b_y1[i26][2];
    g_Y[3][i26] = b_t[i26 + 3];
  }
  for (int i29{0}; i29 < 4; i29++) {
    g_Y[i29][3] = static_cast<double>(b_iv1[i29]);
  }
}

} // namespace ITER

//
// File trailer for HandeyeShah.cpp
//
// [EOF]
//
