//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: optimizeCamPose.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "optimizeCamPose.h"
#include "bsxfun.h"
#include "combineVectorElements.h"
#include "costFunc1.h"
#include "quat2rotm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const coder::array<double, 2U> &undist_imgMarkerPts
//                const coder::array<double, 2U> &WptsTrio
//                const double K11[4][3]
//                const double est[7]
// Return Type  : double
//
double
optimizeCamPose_anonFcn1(const coder::array<double, 2U> &undist_imgMarkerPts,
                         const coder::array<double, 2U> &WptsTrio,
                         const double K11[4][3], const double est[7])
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  static const signed char iv1[3]{2, 1, 3};
  coder::array<double, 2U> b_x;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> err;
  coder::array<double, 2U> r;
  coder::array<double, 2U> y;
  coder::array<double, 1U> r1;
  double dv1[4][4];
  double b_y[4][3];
  double dv[3][3];
  double b_varargin_1;
  double d;
  double s;
  double varargout_1;
  int b_err;
  int b_loop_ub;
  int c_i;
  int e_loop_ub;
  int f_loop_ub;
  int h_n;
  int i12;
  int i3;
  int i4;
  int i7;
  int k;
  int loop_ub;
  int subsa_idx_1;
  int unnamed_idx_1;
  bool b;
  //  % Divide with Z to complete the perspective projection and the removing
  //  the unit 1  as a resultant of the division either inv(Z)*A*X
  coder::quat2rotm(*((double(*)[4])(&est[0])), dv);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    dv1[b_i][0] = dv[b_i][0];
    dv1[b_i][1] = dv[b_i][1];
    dv1[b_i][2] = dv[b_i][2];
    dv1[3][b_i] = est[b_i + 4];
  }
  for (int i1{0}; i1 < 4; i1++) {
    dv1[i1][3] = static_cast<double>(b_iv[i1]);
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3, d, i4)

  for (int i2 = 0; i2 < 3; i2++) {
    for (i4 = 0; i4 < 4; i4++) {
      d = 0.0;
      for (i3 = 0; i3 < 4; i3++) {
        d += K11[i3][i2] * dv1[i4][i3];
      }
      b_y[i4][i2] = d;
    }
  }
  h_n = WptsTrio.size(1);
  y.set_size(3, WptsTrio.size(1));
  if ((static_cast<int>((WptsTrio.size(1) * 12) < 4)) != 0) {
    for (int j{0}; j < h_n; j++) {
      for (c_i = 0; c_i < 3; c_i++) {
        s = 0.0;
        for (k = 0; k < 4; k++) {
          s += b_y[k][c_i] * WptsTrio[k + (WptsTrio.size(0) * j)];
        }
        y[c_i + (3 * j)] = s;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k, s, c_i)

    for (int j = 0; j < h_n; j++) {
      for (c_i = 0; c_i < 3; c_i++) {
        s = 0.0;
        for (k = 0; k < 4; k++) {
          s += b_y[k][c_i] * WptsTrio[k + (WptsTrio.size(0) * j)];
        }
        y[c_i + (3 * j)] = s;
      }
    }
  }
  loop_ub = y.size(1);
  c_y.set_size(1, y.size(1));
  b_loop_ub = y.size(1);
  if ((static_cast<int>(y.size(1) < 4)) != 0) {
    for (int i5{0}; i5 < loop_ub; i5++) {
      c_y[i5] = y[(3 * i5) + 2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < b_loop_ub; i5++) {
      c_y[i5] = y[(3 * i5) + 2];
    }
  }
  coder::b_bsxfun(y, c_y, b_x);
  // need to invert HT befor invR, if the representation change of whole inverse
  // is followed
  if (undist_imgMarkerPts.size(0) == b_x.size(1)) {
    int c_loop_ub;
    err.set_size(undist_imgMarkerPts.size(0), 2);
    c_loop_ub = undist_imgMarkerPts.size(0);
    if ((static_cast<int>((undist_imgMarkerPts.size(0) * 2) < 4)) != 0) {
      for (int i6{0}; i6 < 2; i6++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          err[i7 + (err.size(0) * i6)] =
              undist_imgMarkerPts[i7 + (undist_imgMarkerPts.size(0) * i6)] -
              b_x[i6 + (3 * i7)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i6 = 0; i6 < 2; i6++) {
        for (i7 = 0; i7 < c_loop_ub; i7++) {
          err[i7 + (err.size(0) * i6)] =
              undist_imgMarkerPts[i7 + (undist_imgMarkerPts.size(0) * i6)] -
              b_x[i6 + (3 * i7)];
        }
      }
    }
  } else {
    c_binary_expand_op(err, undist_imgMarkerPts, b_x);
  }
  b = true;
  if (err.size(0) != 0) {
    int b_k;
    int plast;
    bool exitg1;
    plast = 0;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      int i10;
      if (iv1[b_k] <= 2) {
        i10 = err.size((static_cast<int>(iv1[b_k])) - 1);
      } else {
        i10 = 1;
      }
      if (i10 != 1) {
        if (plast > (static_cast<int>(iv1[b_k]))) {
          b = false;
          exitg1 = true;
        } else {
          plast = static_cast<int>(iv1[b_k]);
          b_k++;
        }
      } else {
        b_k++;
      }
    }
  }
  if (b) {
    int d_loop_ub;
    r.set_size(2, err.size(0));
    d_loop_ub = err.size(0);
    if ((static_cast<int>((err.size(0) * 2) < 4)) != 0) {
      for (int i9{0}; i9 < d_loop_ub; i9++) {
        r[2 * i9] = err[2 * i9];
        r[(2 * i9) + 1] = err[(2 * i9) + 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i9 = 0; i9 < d_loop_ub; i9++) {
        r[2 * i9] = err[2 * i9];
        r[(2 * i9) + 1] = err[(2 * i9) + 1];
      }
    }
  } else {
    int b_i8;
    r.set_size(2, err.size(0));
    b_i8 = err.size(0);
    for (int c_k{0}; c_k < 2; c_k++) {
      if (0 <= (b_i8 - 1)) {
        subsa_idx_1 = c_k + 1;
      }
      for (int d_k{0}; d_k < b_i8; d_k++) {
        r[(subsa_idx_1 + (2 * d_k)) - 1] =
            err[d_k + (err.size(0) * (subsa_idx_1 - 1))];
      }
    }
  }
  unnamed_idx_1 = (r.size(1) * 2) / 2;
  err.set_size(unnamed_idx_1, 2);
  e_loop_ub = unnamed_idx_1;
  if ((static_cast<int>((unnamed_idx_1 * 2) < 4)) != 0) {
    for (int i11{0}; i11 < 2; i11++) {
      for (i12 = 0; i12 < unnamed_idx_1; i12++) {
        err[i12 + (err.size(0) * i11)] = r[i11 + (2 * i12)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12)

    for (int i11 = 0; i11 < 2; i11++) {
      for (i12 = 0; i12 < e_loop_ub; i12++) {
        err[i12 + (err.size(0) * i11)] = r[i11 + (2 * i12)];
      }
    }
  }
  // This is forbenius norm (L2), extra line for the fmincon. Remove this line
  // if using lsqnonlin
  b_err = err.size(0) * 2;
  r1.set_size(b_err);
  f_loop_ub = b_err;
  if ((static_cast<int>(b_err < 4)) != 0) {
    for (int i13{0}; i13 < b_err; i13++) {
      double varargin_1;
      varargin_1 = err[i13];
      r1[i13] = varargin_1 * varargin_1;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_varargin_1)

    for (int i13 = 0; i13 < f_loop_ub; i13++) {
      b_varargin_1 = err[i13];
      r1[i13] = b_varargin_1 * b_varargin_1;
    }
  }
  varargout_1 = std::sqrt(coder::combineVectorElements(r1));
  // This is forbenius norm (L2), extra line for the fmincon. Remove this line
  // if using lsqnonlin
  return varargout_1;
}

//
// File trailer for optimizeCamPose.cpp
//
// [EOF]
//
