//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "HandeyeShah.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_rtwutil.h"
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
// Arguments    : const coder::array<double, 3U> &As
//                const coder::array<double, 3U> &Bs
//                double d_X[4][4]
//                double g_Y[4][4]
//                int *err
// Return Type  : void
//
void HandeyeShah(const coder::array<double, 3U> &As,
                 const coder::array<double, 3U> &Bs, double d_X[4][4],
                 double g_Y[4][4], int *err)
{
  static const signed char b_B[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  static const signed char iv[4]{0, 0, 0, 1};
  coder::array<double, 2U> A;
  coder::array<double, 1U> b;
  coder::array<signed char, 1U> r;
  double T[9][9];
  double V[9][9];
  double b_K[9][9];
  double b_a[9][3];
  double b_As[6][3];
  double b_u[3][3];
  double b_v[3][3];
  double b_y1[3][3];
  double c_v[3][3];
  double s[9];
  double x1[3][3];
  double c_n;
  double c_x;
  double d;
  double x_tmp;
  int Ra_tmp[3];
  int b_i;
  int b_i1;
  int b_j1;
  int c_i;
  int i1;
  int j2;
  int sz_idx_1;
  bool b_x[81];
  bool e_x[9];
  bool p;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  *err = 0;
  sz_idx_1 = (As.size(2) * 16) / 4;
  c_n = (static_cast<double>(sz_idx_1)) / 4.0;
  (void)std::memset(&T[0][0], 0, 81U * (sizeof(double)));
  b_i = static_cast<int>(c_n);
  for (c_i = 0; c_i < b_i; c_i++) {
    i1 = ((c_i + 1) * 4) - 3;
    Ra_tmp[0] = i1;
    Ra_tmp[1] = i1 + 1;
    Ra_tmp[2] = i1 + 2;
    sz_idx_1 = -1;
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      for (j2 = 0; j2 < 3; j2++) {
        for (i1 = 0; i1 < 3; i1++) {
          x_tmp = Bs[i1 + (4 * (Ra_tmp[b_j1] - 1))];
          (&b_K[0][0])[sz_idx_1 + 1] = x_tmp * As[4 * (Ra_tmp[j2] - 1)];
          (&b_K[0][0])[sz_idx_1 + 2] = x_tmp * As[(4 * (Ra_tmp[j2] - 1)) + 1];
          (&b_K[0][0])[sz_idx_1 + 3] = x_tmp * As[(4 * (Ra_tmp[j2] - 1)) + 2];
          sz_idx_1 += 3;
        }
      }
    }
    for (i1 = 0; i1 < 9; i1++) {
      for (b_i1 = 0; b_i1 < 9; b_i1++) {
        T[i1][b_i1] += b_K[i1][b_i1];
      }
    }
  }
  //  Check for NaN in T
  for (i1 = 0; i1 < 81; i1++) {
    b_x[i1] = std::isnan((&T[0][0])[i1]);
  }
  sz_idx_1 = static_cast<int>(b_x[0]);
  for (b_j1 = 0; b_j1 < 80; b_j1++) {
    sz_idx_1 += static_cast<int>(b_x[b_j1 + 1]);
  }
  if (sz_idx_1 != 0) {
    *err = -1;
  }
  p = true;
  for (b_j1 = 0; b_j1 < 9; b_j1++) {
    for (sz_idx_1 = 0; sz_idx_1 < 9; sz_idx_1++) {
      if (p) {
        if ((std::isinf(T[b_j1][sz_idx_1])) ||
            (std::isnan(T[b_j1][sz_idx_1]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (p) {
    coder::internal::d_svd(T, b_K, s, V);
  } else {
    for (i1 = 0; i1 < 9; i1++) {
      for (b_i1 = 0; b_i1 < 9; b_i1++) {
        b_K[i1][b_i1] = rtNaN;
        V[i1][b_i1] = rtNaN;
      }
    }
  }
  x_tmp = coder::det(*((double(*)[3][3])(&V[0][0])));
  c_x = x_tmp;
  if (x_tmp < 0.0) {
    c_x = -1.0;
  } else if (x_tmp > 0.0) {
    c_x = 1.0;
  } else if (x_tmp == 0.0) {
    c_x = 0.0;
  } else {
    /* no actions */
  }
  x_tmp = c_x / rt_powd_snf(std::abs(x_tmp), 0.33333333333333331);
  (void)std::copy(&V[0][0], (&V[0][0]) + 9U, &s[0]);
  for (i1 = 0; i1 < 3; i1++) {
    x1[i1][0] = x_tmp * s[3 * i1];
    x1[i1][1] = x_tmp * s[(3 * i1) + 1];
    x1[i1][2] = x_tmp * s[(3 * i1) + 2];
  }
  //  Check for NaN in x1
  for (i1 = 0; i1 < 9; i1++) {
    e_x[i1] = std::isnan((&x1[0][0])[i1]);
  }
  sz_idx_1 = static_cast<int>(e_x[0]);
  for (b_j1 = 0; b_j1 < 8; b_j1++) {
    sz_idx_1 += static_cast<int>(e_x[b_j1 + 1]);
  }
  if (sz_idx_1 != 0) {
    *err = -1;
  }
  coder::svd(x1, b_u, *((double(*)[3][3])(&s[0])), b_v);
  x_tmp = coder::det(*((double(*)[3][3])(&b_K[0][0])));
  c_x = x_tmp;
  if (x_tmp < 0.0) {
    c_x = -1.0;
  } else if (x_tmp > 0.0) {
    c_x = 1.0;
  } else if (x_tmp == 0.0) {
    c_x = 0.0;
  } else {
    /* no actions */
  }
  x_tmp = c_x / rt_powd_snf(std::abs(x_tmp), 0.33333333333333331);
  (void)std::copy(&b_K[0][0], (&b_K[0][0]) + 9U, &s[0]);
  for (i1 = 0; i1 < 3; i1++) {
    b_y1[i1][0] = x_tmp * s[3 * i1];
    b_y1[i1][1] = x_tmp * s[(3 * i1) + 1];
    b_y1[i1][2] = x_tmp * s[(3 * i1) + 2];
  }
  //  Check for NaN in Y
  for (i1 = 0; i1 < 9; i1++) {
    e_x[i1] = std::isnan((&b_y1[0][0])[i1]);
  }
  sz_idx_1 = static_cast<int>(e_x[0]);
  for (b_j1 = 0; b_j1 < 8; b_j1++) {
    sz_idx_1 += static_cast<int>(e_x[b_j1 + 1]);
  }
  if (sz_idx_1 != 0) {
    *err = -1;
  }
  coder::svd(b_y1, x1, *((double(*)[3][3])(&s[0])), c_v);
  for (i1 = 0; i1 < 3; i1++) {
    x_tmp = x1[0][i1];
    c_x = x1[1][i1];
    d = x1[2][i1];
    for (b_i1 = 0; b_i1 < 3; b_i1++) {
      b_y1[b_i1][i1] =
          ((x_tmp * c_v[0][b_i1]) + (c_x * c_v[1][b_i1])) + (d * c_v[2][b_i1]);
    }
  }
  sz_idx_1 = static_cast<int>(static_cast<double>(3.0 * c_n));
  A.set_size(sz_idx_1, 6);
  for (i1 = 0; i1 < 6; i1++) {
    for (b_i1 = 0; b_i1 < sz_idx_1; b_i1++) {
      A[b_i1 + (A.size(0) * i1)] = 0.0;
    }
  }
  b.set_size(sz_idx_1);
  for (i1 = 0; i1 < sz_idx_1; i1++) {
    b[i1] = 0.0;
  }
  for (c_i = 0; c_i < b_i; c_i++) {
    i1 = (3 * (c_i + 1)) - 2;
    Ra_tmp[0] = i1;
    Ra_tmp[1] = i1 + 1;
    Ra_tmp[2] = i1 + 2;
    r.set_size(6);
    for (b_i1 = 0; b_i1 < 6; b_i1++) {
      r[b_i1] = static_cast<signed char>(b_i1);
    }
    for (b_i1 = 0; b_i1 < 3; b_i1++) {
      x1[b_i1][0] = 0.0;
      x1[b_i1][1] = 0.0;
      x1[b_i1][2] = 0.0;
    }
    b_i1 = (c_i + 1) * 4;
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      x1[b_j1][b_j1] = 1.0;
      sz_idx_1 = (b_j1 + b_i1) - 4;
      b_As[b_j1][0] = -As[4 * sz_idx_1];
      b_As[b_j1][1] = -As[(4 * sz_idx_1) + 1];
      b_As[b_j1][2] = -As[(4 * sz_idx_1) + 2];
    }
    for (sz_idx_1 = 0; sz_idx_1 < 3; sz_idx_1++) {
      b_As[sz_idx_1 + 3][0] = x1[sz_idx_1][0];
      b_As[sz_idx_1 + 3][1] = x1[sz_idx_1][1];
      b_As[sz_idx_1 + 3][2] = x1[sz_idx_1][2];
    }
    for (sz_idx_1 = 0; sz_idx_1 < 6; sz_idx_1++) {
      A[(i1 + (A.size(0) * (static_cast<int>(r[sz_idx_1])))) - 1] =
          (&b_As[0][0])[3 * sz_idx_1];
      A[i1 + (A.size(0) * (static_cast<int>(r[sz_idx_1])))] =
          (&b_As[0][0])[(3 * sz_idx_1) + 1];
      A[(i1 + (A.size(0) * (static_cast<int>(r[sz_idx_1])))) + 1] =
          (&b_As[0][0])[(3 * sz_idx_1) + 2];
    }
    sz_idx_1 = -1;
    for (b_j1 = 0; b_j1 < 3; b_j1++) {
      x_tmp = Bs[b_j1 + (4 * (b_i1 - 1))];
      for (j2 = 0; j2 < 3; j2++) {
        (&b_a[0][0])[sz_idx_1 + 1] = x_tmp * (static_cast<double>(b_B[j2][0]));
        (&b_a[0][0])[sz_idx_1 + 2] = x_tmp * (static_cast<double>(b_B[j2][1]));
        (&b_a[0][0])[sz_idx_1 + 3] = x_tmp * (static_cast<double>(b_B[j2][2]));
        sz_idx_1 += 3;
      }
    }
    for (i1 = 0; i1 < 3; i1++) {
      x_tmp = 0.0;
      for (sz_idx_1 = 0; sz_idx_1 < 9; sz_idx_1++) {
        x_tmp += b_a[sz_idx_1][i1] * (&b_y1[0][0])[sz_idx_1];
      }
      b[Ra_tmp[i1] - 1] = As[i1 + (4 * (b_i1 - 1))] - x_tmp;
    }
  }
  coder::b_mldivide(A, b);
  for (b_i = 0; b_i < 3; b_i++) {
    x_tmp = b_u[0][b_i];
    c_x = b_u[1][b_i];
    d = b_u[2][b_i];
    for (i1 = 0; i1 < 3; i1++) {
      x1[i1][b_i] =
          ((x_tmp * b_v[0][i1]) + (c_x * b_v[1][i1])) + (d * b_v[2][i1]);
    }
  }
  for (b_i = 0; b_i < 3; b_i++) {
    d_X[b_i][0] = x1[b_i][0];
    d_X[b_i][1] = x1[b_i][1];
    d_X[b_i][2] = x1[b_i][2];
    d_X[3][b_i] = b[b_i];
  }
  for (b_i = 0; b_i < 4; b_i++) {
    d_X[b_i][3] = static_cast<double>(iv[b_i]);
  }
  for (b_i = 0; b_i < 3; b_i++) {
    g_Y[b_i][0] = b_y1[b_i][0];
    g_Y[b_i][1] = b_y1[b_i][1];
    g_Y[b_i][2] = b_y1[b_i][2];
    g_Y[3][b_i] = b[b_i + 3];
  }
  for (b_i = 0; b_i < 4; b_i++) {
    g_Y[b_i][3] = static_cast<double>(iv[b_i]);
  }
}

//
// File trailer for HandeyeShah.cpp
//
// [EOF]
//
