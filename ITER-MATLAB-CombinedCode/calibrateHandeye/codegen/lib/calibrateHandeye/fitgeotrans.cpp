//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
// Arguments    : const ::coder::array<double, 2U> &uv
//                const ::coder::array<double, 2U> &xy
//                projective2d *tform
// Return Type  : void
//
namespace coder {
void findProjectiveTransform(const ::coder::array<double, 2U> &uv,
                             const ::coder::array<double, 2U> &xy,
                             projective2d *tform)
{
  array<double, 2U> b_uv;
  array<double, 2U> b_xy;
  array<double, 2U> d_X;
  array<double, 1U> b_u;
  array<double, 1U> b_v;
  array<double, 1U> b_x;
  array<double, 1U> r;
  array<double, 1U> r1;
  array<double, 1U> y;
  double T[3][3];
  double Tvec[9];
  double b_B[3][3];
  double normMatrix2[3][3];
  double g_Y[8];
  double absx;
  double s;
  int jpvt[8];
  int b_i;
  int c_n;
  int k;
  int maxmn;
  int minmn;
  int rankA;
  bool guard1{false};
  images::geotrans::internal::normalizeControlPoints(uv, b_uv, T);
  images::geotrans::internal::normalizeControlPoints(xy, b_xy, normMatrix2);
  minmn = b_xy.size(0);
  b_x.set_size(b_xy.size(0));
  for (b_i = 0; b_i < minmn; b_i++) {
    b_x[b_i] = b_xy[b_i];
  }
  minmn = b_xy.size(0);
  y.set_size(b_xy.size(0));
  for (b_i = 0; b_i < minmn; b_i++) {
    y[b_i] = b_xy[b_i + b_xy.size(0)];
  }
  minmn = b_uv.size(0);
  b_u.set_size(b_uv.size(0));
  for (b_i = 0; b_i < minmn; b_i++) {
    b_u[b_i] = b_uv[b_i];
  }
  minmn = b_uv.size(0);
  b_v.set_size(b_uv.size(0));
  for (b_i = 0; b_i < minmn; b_i++) {
    b_v[b_i] = b_uv[b_i + b_uv.size(0)];
  }
  r.set_size(b_u.size(0));
  minmn = b_u.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    r[b_i] = -b_u[b_i];
  }
  r1.set_size(b_v.size(0));
  minmn = b_v.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    r1[b_i] = -b_v[b_i];
  }
  d_X.set_size(b_x.size(0) + b_xy.size(0), 8);
  minmn = b_x.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i] = b_x[b_i];
  }
  minmn = y.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + d_X.size(0)] = y[b_i];
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 2)] = 1.0;
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 3)] = 0.0;
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 4)] = 0.0;
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 5)] = 0.0;
  }
  minmn = r.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 6)] = r[b_i] * b_x[b_i];
  }
  minmn = r.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + (d_X.size(0) * 7)] = r[b_i] * y[b_i];
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[b_i + b_x.size(0)] = 0.0;
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + d_X.size(0)] = 0.0;
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
  }
  minmn = b_x.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[b_i];
  }
  minmn = y.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 4)] = y[b_i];
  }
  minmn = b_xy.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
  }
  minmn = r1.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 6)] = r1[b_i] * b_x[b_i];
  }
  minmn = r1.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    d_X[(b_i + b_x.size(0)) + (d_X.size(0) * 7)] = r1[b_i] * y[b_i];
  }
  if (d_X.size(0) != 0) {
    bool p;
    p = true;
    b_i = d_X.size(0);
    for (k = 0; k < 8; k++) {
      for (minmn = 0; minmn < b_i; minmn++) {
        absx = d_X[minmn + (d_X.size(0) * k)];
        if (p) {
          if ((std::isinf(absx)) || (std::isnan(absx))) {
            p = false;
          }
        } else {
          p = false;
        }
      }
    }
    c_n = static_cast<int>(std::fmin(static_cast<double>(d_X.size(0)), 8.0));
    if (p) {
      internal::b_svd(d_X, b_x);
    } else {
      b_x.set_size(c_n);
      for (b_i = 0; b_i < c_n; b_i++) {
        b_x[b_i] = rtNaN;
      }
    }
    absx = std::abs(b_x[0]);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (!(absx <= 2.2250738585072014E-308)) {
        (void)frexp(absx, &maxmn);
      }
    }
  }
  y.set_size(b_u.size(0) + b_v.size(0));
  minmn = b_u.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    y[b_i] = b_u[b_i];
  }
  minmn = b_v.size(0);
  for (b_i = 0; b_i < minmn; b_i++) {
    y[b_i + b_u.size(0)] = b_v[b_i];
  }
  guard1 = false;
  if (d_X.size(0) == 0) {
    guard1 = true;
  } else if (y.size(0) == 0) {
    guard1 = true;
  } else if (d_X.size(0) == 8) {
    for (b_i = 0; b_i < 8; b_i++) {
      jpvt[b_i] = b_i + 1;
    }
    for (int j{0}; j < 7; j++) {
      int b_tmp;
      int mmj_tmp;
      mmj_tmp = 6 - j;
      b_tmp = j * 9;
      rankA = b_tmp + 2;
      c_n = 8 - j;
      minmn = 0;
      absx = std::abs(d_X[b_tmp]);
      for (k = 2; k <= c_n; k++) {
        s = std::abs(d_X[(b_tmp + k) - 1]);
        if (s > absx) {
          minmn = k - 1;
          absx = s;
        }
      }
      if (d_X[b_tmp + minmn] != 0.0) {
        if (minmn != 0) {
          maxmn = j + minmn;
          jpvt[j] = maxmn + 1;
          for (k = 0; k < 8; k++) {
            minmn = k * 8;
            c_n = j + minmn;
            absx = d_X[c_n];
            b_i = maxmn + minmn;
            d_X[c_n] = d_X[b_i];
            d_X[b_i] = absx;
          }
        }
        b_i = (b_tmp - j) + 8;
        for (c_n = rankA; c_n <= b_i; c_n++) {
          d_X[c_n - 1] = d_X[c_n - 1] / d_X[b_tmp];
        }
      }
      maxmn = b_tmp;
      for (rankA = 0; rankA <= mmj_tmp; rankA++) {
        minmn = (b_tmp + (rankA * 8)) + 8;
        absx = d_X[minmn];
        if (d_X[minmn] != 0.0) {
          b_i = maxmn + 10;
          minmn = (maxmn - j) + 16;
          for (c_n = b_i; c_n <= minmn; c_n++) {
            d_X[c_n - 1] =
                d_X[c_n - 1] + (d_X[((b_tmp + c_n) - maxmn) - 9] * (-absx));
          }
        }
        maxmn += 8;
      }
      b_i = jpvt[j];
      if (b_i != (j + 1)) {
        absx = y[j];
        minmn = b_i - 1;
        y[j] = y[minmn];
        y[minmn] = absx;
      }
    }
    for (k = 0; k < 8; k++) {
      minmn = k * 8;
      if (y[k] != 0.0) {
        b_i = k + 2;
        for (c_n = b_i; c_n < 9; c_n++) {
          y[c_n - 1] = y[c_n - 1] - (y[k] * d_X[(c_n + minmn) - 1]);
        }
      }
    }
    for (k = 7; k >= 0; k--) {
      minmn = k * 8;
      if (y[k] != 0.0) {
        y[k] = y[k] / d_X[k + minmn];
        for (c_n = 0; c_n < k; c_n++) {
          y[c_n] = y[c_n] - (y[k] * d_X[c_n + minmn]);
        }
      }
    }
  } else {
    int j;
    internal::lapack::b_xgeqp3(d_X, b_x, jpvt);
    rankA = 0;
    if (d_X.size(0) < 8) {
      minmn = d_X.size(0);
      maxmn = 8;
    } else {
      minmn = 8;
      maxmn = d_X.size(0);
    }
    if (minmn > 0) {
      bool exitg1;
      absx = std::fmin(1.4901161193847656E-8,
                       2.2204460492503131E-15 * (static_cast<double>(maxmn))) *
             std::abs(d_X[0]);
      exitg1 = false;
      while ((!exitg1) && (rankA < minmn)) {
        if (!(std::abs(d_X[rankA + (d_X.size(0) * rankA)]) <= absx)) {
          rankA++;
        } else {
          exitg1 = true;
        }
      }
    }
    (void)std::memset(&g_Y[0], 0, 8U * (sizeof(double)));
    minmn = d_X.size(0);
    maxmn = d_X.size(0);
    if (maxmn > 8) {
      maxmn = 8;
    }
    for (j = 0; j < maxmn; j++) {
      if (b_x[j] != 0.0) {
        absx = y[j];
        b_i = j + 2;
        for (c_n = b_i; c_n <= minmn; c_n++) {
          absx += d_X[(c_n + (d_X.size(0) * j)) - 1] * y[c_n - 1];
        }
        absx *= b_x[j];
        if (absx != 0.0) {
          y[j] = y[j] - absx;
          for (c_n = b_i; c_n <= minmn; c_n++) {
            y[c_n - 1] =
                y[c_n - 1] - (d_X[(c_n + (d_X.size(0) * j)) - 1] * absx);
          }
        }
      }
    }
    for (c_n = 0; c_n < rankA; c_n++) {
      g_Y[jpvt[c_n] - 1] = y[c_n];
    }
    for (j = rankA; j >= 1; j--) {
      minmn = jpvt[j - 1] - 1;
      g_Y[minmn] /= d_X[(j + (d_X.size(0) * (j - 1))) - 1];
      for (c_n = 0; c_n <= (j - 2); c_n++) {
        g_Y[jpvt[c_n] - 1] -= g_Y[minmn] * d_X[c_n + (d_X.size(0) * (j - 1))];
      }
    }
    y.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      y[b_i] = g_Y[b_i];
    }
  }
  if (guard1) {
    y.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      y[b_i] = 0.0;
    }
  }
  for (b_i = 0; b_i < 8; b_i++) {
    Tvec[b_i] = y[b_i];
  }
  Tvec[8] = 1.0;
  for (b_i = 0; b_i < 3; b_i++) {
    double d;
    absx = Tvec[b_i];
    s = Tvec[b_i + 3];
    d = Tvec[b_i + 6];
    for (minmn = 0; minmn < 3; minmn++) {
      b_B[minmn][b_i] =
          ((absx * T[minmn][0]) + (s * T[minmn][1])) + (d * T[minmn][2]);
    }
  }
  minmn = 0;
  maxmn = 1;
  c_n = 2;
  absx = std::abs(normMatrix2[0][0]);
  s = std::abs(normMatrix2[0][1]);
  if (s > absx) {
    absx = s;
    minmn = 1;
    maxmn = 0;
  }
  if (std::abs(normMatrix2[0][2]) > absx) {
    minmn = 2;
    maxmn = 1;
    c_n = 0;
  }
  normMatrix2[0][maxmn] /= normMatrix2[0][minmn];
  normMatrix2[0][c_n] /= normMatrix2[0][minmn];
  normMatrix2[1][maxmn] -= normMatrix2[0][maxmn] * normMatrix2[1][minmn];
  normMatrix2[1][c_n] -= normMatrix2[0][c_n] * normMatrix2[1][minmn];
  normMatrix2[2][maxmn] -= normMatrix2[0][maxmn] * normMatrix2[2][minmn];
  normMatrix2[2][c_n] -= normMatrix2[0][c_n] * normMatrix2[2][minmn];
  if (std::abs(normMatrix2[1][c_n]) > std::abs(normMatrix2[1][maxmn])) {
    rankA = maxmn;
    maxmn = c_n;
    c_n = rankA;
  }
  normMatrix2[1][c_n] /= normMatrix2[1][maxmn];
  normMatrix2[2][c_n] -= normMatrix2[1][c_n] * normMatrix2[2][maxmn];
  absx = b_B[0][maxmn] - (b_B[0][minmn] * normMatrix2[0][maxmn]);
  s = ((b_B[0][c_n] - (b_B[0][minmn] * normMatrix2[0][c_n])) -
       (absx * normMatrix2[1][c_n])) /
      normMatrix2[2][c_n];
  Tvec[2] = s;
  absx -= s * normMatrix2[2][maxmn];
  absx /= normMatrix2[1][maxmn];
  Tvec[1] = absx;
  Tvec[0] = ((b_B[0][minmn] - (s * normMatrix2[2][minmn])) -
             (absx * normMatrix2[1][minmn])) /
            normMatrix2[0][minmn];
  absx = b_B[1][maxmn] - (b_B[1][minmn] * normMatrix2[0][maxmn]);
  s = ((b_B[1][c_n] - (b_B[1][minmn] * normMatrix2[0][c_n])) -
       (absx * normMatrix2[1][c_n])) /
      normMatrix2[2][c_n];
  Tvec[5] = s;
  absx -= s * normMatrix2[2][maxmn];
  absx /= normMatrix2[1][maxmn];
  Tvec[4] = absx;
  Tvec[3] = ((b_B[1][minmn] - (s * normMatrix2[2][minmn])) -
             (absx * normMatrix2[1][minmn])) /
            normMatrix2[0][minmn];
  absx = b_B[2][maxmn] - (b_B[2][minmn] * normMatrix2[0][maxmn]);
  s = ((b_B[2][c_n] - (b_B[2][minmn] * normMatrix2[0][c_n])) -
       (absx * normMatrix2[1][c_n])) /
      normMatrix2[2][c_n];
  Tvec[8] = s;
  absx -= s * normMatrix2[2][maxmn];
  absx /= normMatrix2[1][maxmn];
  Tvec[7] = absx;
  Tvec[6] = ((b_B[2][minmn] - (s * normMatrix2[2][minmn])) -
             (absx * normMatrix2[1][minmn])) /
            normMatrix2[0][minmn];
  inv(*((double(*)[3][3])(&Tvec[0])), T);
  for (b_i = 0; b_i < 3; b_i++) {
    tform->T[b_i][0] = T[b_i][0] / T[2][2];
    tform->T[b_i][1] = T[b_i][1] / T[2][2];
    tform->T[b_i][2] = T[b_i][2] / T[2][2];
  }
}

} // namespace coder

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
