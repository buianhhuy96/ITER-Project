//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: HandeyeShah.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
#include "tic.h"
#include "toc.h"
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
// Arguments    : const coder::array<double, 3U> &As
//                const coder::array<double, 3U> &Bs
//                double b_X[4][4]
//                double Y[4][4]
//                double *b_time
// Return Type  : void
//
void HandeyeShah(const coder::array<double, 3U> &As,
                 const coder::array<double, 3U> &Bs, double b_X[4][4],
                 double Y[4][4], double *b_time)
{
  static const signed char B[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  coder::array<double, 2U> A;
  coder::array<double, 1U> b;
  coder::array<double, 1U> b_b;
  coder::array<double, 1U> tau;
  coder::array<int, 2U> jpvt;
  coder::array<signed char, 1U> r;
  double K[9][9];
  double T[9][9];
  double V[9][9];
  double a[9][3];
  double b_As[6][3];
  double b_Y[3][3];
  double b_u[3][3];
  double b_v[3][3];
  double s[9];
  double u[3][3];
  double v[3][3];
  double b_s;
  double d;
  double n;
  double tol;
  int Ra_tmp[3];
  int b_i;
  int i;
  int i1;
  int j2;
  int k;
  int maxmn;
  int rankA;
  int sz_idx_1;
  boolean_T guard1{false};
  boolean_T p;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  coder::tic();
  sz_idx_1 = (As.size(2) * 16) / 4;
  n = (static_cast<double>(sz_idx_1)) / 4.0;
  (void)std::memset(&T[0][0], 0, 81U * (sizeof(double)));
  i = static_cast<int>(n);
  for (b_i = 0; b_i < i; b_i++) {
    i1 = ((b_i + 1) * 4) - 3;
    Ra_tmp[0] = i1;
    Ra_tmp[1] = i1 + 1;
    Ra_tmp[2] = i1 + 2;
    sz_idx_1 = -1;
    for (rankA = 0; rankA < 3; rankA++) {
      for (j2 = 0; j2 < 3; j2++) {
        for (maxmn = 0; maxmn < 3; maxmn++) {
          tol = Bs[maxmn + (4 * (Ra_tmp[rankA] - 1))];
          (&K[0][0])[sz_idx_1 + 1] = tol * As[4 * (Ra_tmp[j2] - 1)];
          (&K[0][0])[sz_idx_1 + 2] = tol * As[(4 * (Ra_tmp[j2] - 1)) + 1];
          (&K[0][0])[sz_idx_1 + 3] = tol * As[(4 * (Ra_tmp[j2] - 1)) + 2];
          sz_idx_1 += 3;
        }
      }
    }
    for (i1 = 0; i1 < 9; i1++) {
      for (maxmn = 0; maxmn < 9; maxmn++) {
        T[i1][maxmn] += K[i1][maxmn];
      }
    }
  }
  p = true;
  for (k = 0; k < 9; k++) {
    for (sz_idx_1 = 0; sz_idx_1 < 9; sz_idx_1++) {
      if (p) {
        if ((std::isinf(T[k][sz_idx_1])) || (std::isnan(T[k][sz_idx_1]))) {
          p = false;
        }
      } else {
        p = false;
      }
    }
  }
  if (p) {
    coder::internal::e_svd(T, K, s, V);
  } else {
    for (i1 = 0; i1 < 9; i1++) {
      for (maxmn = 0; maxmn < 9; maxmn++) {
        K[i1][maxmn] = rtNaN;
        V[i1][maxmn] = rtNaN;
      }
    }
  }
  tol = coder::det(*((double(*)[3][3])(&V[0][0])));
  b_s = tol;
  if (tol < 0.0) {
    b_s = -1.0;
  } else if (tol > 0.0) {
    b_s = 1.0;
  } else if (tol == 0.0) {
    b_s = 0.0;
  } else {
    /* no actions */
  }
  tol = b_s / rt_powd_snf(std::abs(tol), 0.33333333333333331);
  (void)std::copy(&V[0][0], (&V[0][0]) + 9U, &s[0]);
  for (i1 = 0; i1 < 3; i1++) {
    b_Y[i1][0] = tol * s[3 * i1];
    b_Y[i1][1] = tol * s[(3 * i1) + 1];
    b_Y[i1][2] = tol * s[(3 * i1) + 2];
  }
  coder::b_svd(b_Y, u, *((double(*)[3][3])(&s[0])), v);
  tol = coder::det(*((double(*)[3][3])(&K[0][0])));
  b_s = tol;
  if (tol < 0.0) {
    b_s = -1.0;
  } else if (tol > 0.0) {
    b_s = 1.0;
  } else if (tol == 0.0) {
    b_s = 0.0;
  } else {
    /* no actions */
  }
  tol = b_s / rt_powd_snf(std::abs(tol), 0.33333333333333331);
  (void)std::copy(&K[0][0], (&K[0][0]) + 9U, &s[0]);
  for (i1 = 0; i1 < 3; i1++) {
    b_Y[i1][0] = tol * s[3 * i1];
    b_Y[i1][1] = tol * s[(3 * i1) + 1];
    b_Y[i1][2] = tol * s[(3 * i1) + 2];
  }
  coder::b_svd(b_Y, b_u, *((double(*)[3][3])(&s[0])), b_v);
  for (i1 = 0; i1 < 3; i1++) {
    tol = b_u[0][i1];
    b_s = b_u[1][i1];
    d = b_u[2][i1];
    for (maxmn = 0; maxmn < 3; maxmn++) {
      b_Y[maxmn][i1] =
          ((tol * b_v[0][maxmn]) + (b_s * b_v[1][maxmn])) + (d * b_v[2][maxmn]);
    }
  }
  sz_idx_1 = static_cast<int>(static_cast<double>(3.0 * n));
  A.set_size(sz_idx_1, 6);
  for (i1 = 0; i1 < 6; i1++) {
    for (maxmn = 0; maxmn < sz_idx_1; maxmn++) {
      A[maxmn + (A.size(0) * i1)] = 0.0;
    }
  }
  b.set_size(sz_idx_1);
  for (i1 = 0; i1 < sz_idx_1; i1++) {
    b[i1] = 0.0;
  }
  for (b_i = 0; b_i < i; b_i++) {
    i1 = (3 * (b_i + 1)) - 2;
    Ra_tmp[0] = i1;
    Ra_tmp[1] = i1 + 1;
    Ra_tmp[2] = i1 + 2;
    r.set_size(6);
    for (maxmn = 0; maxmn < 6; maxmn++) {
      r[maxmn] = static_cast<signed char>(maxmn);
    }
    (void)std::memset(&s[0], 0, 9U * (sizeof(double)));
    maxmn = (b_i + 1) * 4;
    for (k = 0; k < 3; k++) {
      s[k + (3 * k)] = 1.0;
      sz_idx_1 = (k + maxmn) - 4;
      b_As[k][0] = -As[4 * sz_idx_1];
      b_As[k][1] = -As[(4 * sz_idx_1) + 1];
      b_As[k][2] = -As[(4 * sz_idx_1) + 2];
      b_As[k + 3][0] = s[3 * k];
      b_As[k + 3][1] = s[(3 * k) + 1];
      b_As[k + 3][2] = s[(3 * k) + 2];
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
    for (rankA = 0; rankA < 3; rankA++) {
      tol = Bs[rankA + (4 * (maxmn - 1))];
      for (j2 = 0; j2 < 3; j2++) {
        (&a[0][0])[sz_idx_1 + 1] = tol * (static_cast<double>(B[j2][0]));
        (&a[0][0])[sz_idx_1 + 2] = tol * (static_cast<double>(B[j2][1]));
        (&a[0][0])[sz_idx_1 + 3] = tol * (static_cast<double>(B[j2][2]));
        sz_idx_1 += 3;
      }
    }
    for (i1 = 0; i1 < 3; i1++) {
      tol = 0.0;
      for (sz_idx_1 = 0; sz_idx_1 < 9; sz_idx_1++) {
        tol += a[sz_idx_1][i1] * (&b_Y[0][0])[sz_idx_1];
      }
      b[Ra_tmp[i1] - 1] = As[i1 + (4 * (maxmn - 1))] - tol;
    }
  }
  guard1 = false;
  if (A.size(0) == 0) {
    guard1 = true;
  } else if (b.size(0) == 0) {
    guard1 = true;
  } else if (A.size(0) == 6) {
    int b_n;
    b_n = b.size(0);
    if (b_n >= 6) {
      b_n = 6;
    }
    jpvt.set_size(1, b_n);
    jpvt[0] = 1;
    sz_idx_1 = 1;
    for (k = 2; k <= b_n; k++) {
      sz_idx_1++;
      jpvt[k - 1] = sz_idx_1;
    }
    j2 = b_n - 1;
    if (j2 >= b_n) {
      j2 = b_n;
    }
    for (int j{0}; j < j2; j++) {
      int b_tmp;
      int mmj_tmp;
      mmj_tmp = b_n - j;
      b_tmp = j * 7;
      rankA = b_tmp + 2;
      if (mmj_tmp < 1) {
        sz_idx_1 = -1;
      } else {
        sz_idx_1 = 0;
        if (mmj_tmp > 1) {
          tol = std::abs(A[b_tmp]);
          for (k = 2; k <= mmj_tmp; k++) {
            b_s = std::abs(A[(b_tmp + k) - 1]);
            if (b_s > tol) {
              sz_idx_1 = k - 1;
              tol = b_s;
            }
          }
        }
      }
      if (A[b_tmp + sz_idx_1] != 0.0) {
        if (sz_idx_1 != 0) {
          sz_idx_1 += j;
          jpvt[j] = sz_idx_1 + 1;
          for (k = 0; k < b_n; k++) {
            maxmn = j + (k * 6);
            tol = A[maxmn];
            i = sz_idx_1 + (k * 6);
            A[maxmn] = A[i];
            A[i] = tol;
          }
        }
        i = b_tmp + mmj_tmp;
        for (b_i = rankA; b_i <= i; b_i++) {
          A[b_i - 1] = A[b_i - 1] / A[b_tmp];
        }
      }
      maxmn = b_tmp + 6;
      for (rankA = 0; rankA <= (mmj_tmp - 2); rankA++) {
        sz_idx_1 = (b_tmp + (rankA * 6)) + 6;
        tol = A[sz_idx_1];
        if (A[sz_idx_1] != 0.0) {
          i = maxmn + 2;
          i1 = mmj_tmp + maxmn;
          for (sz_idx_1 = i; sz_idx_1 <= i1; sz_idx_1++) {
            A[sz_idx_1 - 1] = A[sz_idx_1 - 1] +
                              (A[((b_tmp + sz_idx_1) - maxmn) - 1] * (-tol));
          }
        }
        maxmn += 6;
      }
    }
    for (b_i = 0; b_i <= (b_n - 2); b_i++) {
      i = jpvt[b_i];
      if (i != (b_i + 1)) {
        tol = b[b_i];
        b[b_i] = b[i - 1];
        b[i - 1] = tol;
      }
    }
    for (k = 0; k < b_n; k++) {
      sz_idx_1 = 6 * k;
      if (b[k] != 0.0) {
        i = k + 2;
        for (b_i = i; b_i <= b_n; b_i++) {
          b[b_i - 1] = b[b_i - 1] - (b[k] * A[(b_i + sz_idx_1) - 1]);
        }
      }
    }
    for (k = b_n; k >= 1; k--) {
      sz_idx_1 = 6 * (k - 1);
      tol = b[k - 1];
      if (tol != 0.0) {
        b[k - 1] = tol / A[(k + sz_idx_1) - 1];
        for (b_i = 0; b_i <= (k - 2); b_i++) {
          b[b_i] = b[b_i] - (b[k - 1] * A[b_i + sz_idx_1]);
        }
      }
    }
  } else {
    coder::internal::lapack::xgeqp3(A, tau, jpvt);
    rankA = 0;
    if (A.size(0) < A.size(1)) {
      sz_idx_1 = A.size(0);
      maxmn = A.size(1);
    } else {
      sz_idx_1 = A.size(1);
      maxmn = A.size(0);
    }
    if (sz_idx_1 > 0) {
      boolean_T exitg1;
      tol = std::fmin(1.4901161193847656E-8,
                      2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
            std::abs(A[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < sz_idx_1)) {
        if (!(std::abs(A[rankA + (A.size(0) * rankA)]) <= tol)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    b_b.set_size(b.size(0));
    sz_idx_1 = b.size(0) - 1;
    for (i = 0; i <= sz_idx_1; i++) {
      b_b[i] = b[i];
    }
    coder::internal::LSQFromQR(A, tau, jpvt, b_b, rankA, b);
  }
  if (guard1) {
    b.set_size(6);
    for (i = 0; i < 6; i++) {
      b[i] = 0.0;
    }
  }
  for (i = 0; i < 3; i++) {
    tol = u[0][i];
    b_s = u[1][i];
    d = u[2][i];
    for (i1 = 0; i1 < 3; i1++) {
      b_u[i1][i] = ((tol * v[0][i1]) + (b_s * v[1][i1])) + (d * v[2][i1]);
    }
  }
  b_X[0][3] = 0.0;
  b_X[1][3] = 0.0;
  b_X[2][3] = 0.0;
  b_X[3][3] = 1.0;
  for (i = 0; i < 3; i++) {
    b_X[i][0] = b_u[i][0];
    b_X[i][1] = b_u[i][1];
    b_X[i][2] = b_u[i][2];
    b_X[3][i] = b[i];
    Y[i][0] = b_Y[i][0];
    Y[i][1] = b_Y[i][1];
    Y[i][2] = b_Y[i][2];
    Y[3][i] = b[i + 3];
  }
  Y[0][3] = 0.0;
  Y[1][3] = 0.0;
  Y[2][3] = 0.0;
  Y[3][3] = 1.0;
  *b_time = coder::toc();
}

//
// File trailer for HandeyeShah.cpp
//
// [EOF]
//
