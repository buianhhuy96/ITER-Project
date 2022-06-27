//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "fitgeotrans.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rank.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

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
  array<double, 2U> d_X;
  array<double, 2U> uv;
  array<double, 2U> xy;
  array<double, 1U> b_v;
  array<double, 1U> b_x;
  array<double, 1U> c_u;
  array<double, 1U> d_u;
  array<double, 1U> r;
  array<double, 1U> r1;
  array<double, 1U> y;
  double T[3][3];
  double Tvec[9];
  double b_Tvec[3][3];
  double dv[3][3];
  double normMatrix1[3][3];
  double normMatrix2[3][3];
  double b_d1;
  double d;
  double d2;
  double d3;
  double e_T;
  int ab_loop_ub;
  int b_loop_ub;
  int b_xy_idx_0;
  int bb_loop_ub;
  int c_loop_ub;
  int c_xy_idx_0;
  int cb_loop_ub;
  int d_loop_ub;
  int d_xy_idx_0;
  int db_loop_ub;
  int e_loop_ub;
  int e_xy_idx_0;
  int eb_loop_ub;
  int f_loop_ub;
  int f_xy_idx_0;
  int g_loop_ub;
  int g_xy_idx_0;
  int h_loop_ub;
  int h_xy_idx_0;
  int i27;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m_loop_ub;
  int o_loop_ub;
  int p_loop_ub;
  int q_loop_ub;
  int r_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int u_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int x_loop_ub;
  int xy_idx_0;
  int y_loop_ub;
  images::geotrans::internal::normalizeControlPoints(movingPoints, uv,
                                                     normMatrix1);
  images::geotrans::internal::normalizeControlPoints(fixedPoints, xy,
                                                     normMatrix2);
  loop_ub = xy.size(0);
  b_x.set_size(xy.size(0));
  b_loop_ub = xy.size(0);
  if ((static_cast<int>(xy.size(0) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      b_x[b_i] = xy[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < b_loop_ub; b_i++) {
      b_x[b_i] = xy[b_i];
    }
  }
  c_loop_ub = xy.size(0);
  y.set_size(xy.size(0));
  d_loop_ub = xy.size(0);
  if ((static_cast<int>(xy.size(0) < 4)) != 0) {
    for (int i1{0}; i1 < c_loop_ub; i1++) {
      y[i1] = xy[i1 + xy.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < d_loop_ub; i1++) {
      y[i1] = xy[i1 + xy.size(0)];
    }
  }
  e_loop_ub = uv.size(0);
  c_u.set_size(uv.size(0));
  f_loop_ub = uv.size(0);
  if ((static_cast<int>(uv.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < e_loop_ub; i2++) {
      c_u[i2] = uv[i2];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < f_loop_ub; i2++) {
      c_u[i2] = uv[i2];
    }
  }
  g_loop_ub = uv.size(0);
  b_v.set_size(uv.size(0));
  h_loop_ub = uv.size(0);
  if ((static_cast<int>(uv.size(0) < 4)) != 0) {
    for (int i3{0}; i3 < g_loop_ub; i3++) {
      b_v[i3] = uv[i3 + uv.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < h_loop_ub; i3++) {
      b_v[i3] = uv[i3 + uv.size(0)];
    }
  }
  r.set_size(c_u.size(0));
  i_loop_ub = c_u.size(0);
  if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < i_loop_ub; i4++) {
      r[i4] = -c_u[i4];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < i_loop_ub; i4++) {
      r[i4] = -c_u[i4];
    }
  }
  r1.set_size(b_v.size(0));
  j_loop_ub = b_v.size(0);
  if ((static_cast<int>(b_v.size(0) < 4)) != 0) {
    for (int i5{0}; i5 < j_loop_ub; i5++) {
      r1[i5] = -b_v[i5];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < j_loop_ub; i5++) {
      r1[i5] = -b_v[i5];
    }
  }
  xy_idx_0 = xy.size(0);
  b_xy_idx_0 = xy.size(0);
  c_xy_idx_0 = xy.size(0);
  d_xy_idx_0 = xy.size(0);
  e_xy_idx_0 = xy.size(0);
  f_xy_idx_0 = xy.size(0);
  g_xy_idx_0 = xy.size(0);
  h_xy_idx_0 = xy.size(0);
  d_X.set_size(b_x.size(0) + xy.size(0), 8);
  k_loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int i6{0}; i6 < k_loop_ub; i6++) {
      d_X[i6] = b_x[i6];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < k_loop_ub; i6++) {
      d_X[i6] = b_x[i6];
    }
  }
  m_loop_ub = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int i7{0}; i7 < m_loop_ub; i7++) {
      d_X[i7 + d_X.size(0)] = y[i7];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < m_loop_ub; i7++) {
      d_X[i7 + d_X.size(0)] = y[i7];
    }
  }
  o_loop_ub = xy_idx_0;
  if ((static_cast<int>(xy_idx_0 < 4)) != 0) {
    for (int b_i8{0}; b_i8 < xy_idx_0; b_i8++) {
      d_X[b_i8 + (d_X.size(0) * 2)] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < o_loop_ub; b_i8++) {
      d_X[b_i8 + (d_X.size(0) * 2)] = 1.0;
    }
  }
  p_loop_ub = b_xy_idx_0;
  if ((static_cast<int>(b_xy_idx_0 < 4)) != 0) {
    for (int i9{0}; i9 < b_xy_idx_0; i9++) {
      d_X[i9 + (d_X.size(0) * 3)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i9 = 0; i9 < p_loop_ub; i9++) {
      d_X[i9 + (d_X.size(0) * 3)] = 0.0;
    }
  }
  q_loop_ub = c_xy_idx_0;
  if ((static_cast<int>(c_xy_idx_0 < 4)) != 0) {
    for (int i10{0}; i10 < c_xy_idx_0; i10++) {
      d_X[i10 + (d_X.size(0) * 4)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i10 = 0; i10 < q_loop_ub; i10++) {
      d_X[i10 + (d_X.size(0) * 4)] = 0.0;
    }
  }
  r_loop_ub = d_xy_idx_0;
  if ((static_cast<int>(d_xy_idx_0 < 4)) != 0) {
    for (int i11{0}; i11 < d_xy_idx_0; i11++) {
      d_X[i11 + (d_X.size(0) * 5)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i11 = 0; i11 < r_loop_ub; i11++) {
      d_X[i11 + (d_X.size(0) * 5)] = 0.0;
    }
  }
  s_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i12{0}; i12 < s_loop_ub; i12++) {
      d_X[i12 + (d_X.size(0) * 6)] = r[i12] * b_x[i12];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i12 = 0; i12 < s_loop_ub; i12++) {
      d_X[i12 + (d_X.size(0) * 6)] = r[i12] * b_x[i12];
    }
  }
  t_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i13{0}; i13 < t_loop_ub; i13++) {
      d_X[i13 + (d_X.size(0) * 7)] = r[i13] * y[i13];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i13 = 0; i13 < t_loop_ub; i13++) {
      d_X[i13 + (d_X.size(0) * 7)] = r[i13] * y[i13];
    }
  }
  u_loop_ub = e_xy_idx_0;
  if ((static_cast<int>(e_xy_idx_0 < 4)) != 0) {
    for (int i14{0}; i14 < e_xy_idx_0; i14++) {
      d_X[i14 + b_x.size(0)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < u_loop_ub; i14++) {
      d_X[i14 + b_x.size(0)] = 0.0;
    }
  }
  v_loop_ub = f_xy_idx_0;
  if ((static_cast<int>(f_xy_idx_0 < 4)) != 0) {
    for (int i15{0}; i15 < f_xy_idx_0; i15++) {
      d_X[(i15 + b_x.size(0)) + d_X.size(0)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i15 = 0; i15 < v_loop_ub; i15++) {
      d_X[(i15 + b_x.size(0)) + d_X.size(0)] = 0.0;
    }
  }
  w_loop_ub = g_xy_idx_0;
  if ((static_cast<int>(g_xy_idx_0 < 4)) != 0) {
    for (int i16{0}; i16 < g_xy_idx_0; i16++) {
      d_X[(i16 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i16 = 0; i16 < w_loop_ub; i16++) {
      d_X[(i16 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
    }
  }
  x_loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int i17{0}; i17 < x_loop_ub; i17++) {
      d_X[(i17 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i17];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i17 = 0; i17 < x_loop_ub; i17++) {
      d_X[(i17 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i17];
    }
  }
  y_loop_ub = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int i18{0}; i18 < y_loop_ub; i18++) {
      d_X[(i18 + b_x.size(0)) + (d_X.size(0) * 4)] = y[i18];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < y_loop_ub; i18++) {
      d_X[(i18 + b_x.size(0)) + (d_X.size(0) * 4)] = y[i18];
    }
  }
  ab_loop_ub = h_xy_idx_0;
  if ((static_cast<int>(h_xy_idx_0 < 4)) != 0) {
    for (int i19{0}; i19 < h_xy_idx_0; i19++) {
      d_X[(i19 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < ab_loop_ub; i19++) {
      d_X[(i19 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
    }
  }
  bb_loop_ub = r1.size(0);
  if ((static_cast<int>(r1.size(0) < 4)) != 0) {
    for (int i20{0}; i20 < bb_loop_ub; i20++) {
      d_X[(i20 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i20] * b_x[i20];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i20 = 0; i20 < bb_loop_ub; i20++) {
      d_X[(i20 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i20] * b_x[i20];
    }
  }
  cb_loop_ub = r1.size(0);
  if ((static_cast<int>(r1.size(0) < 4)) != 0) {
    for (int i21{0}; i21 < cb_loop_ub; i21++) {
      d_X[(i21 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i21] * y[i21];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i21 = 0; i21 < cb_loop_ub; i21++) {
      d_X[(i21 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i21] * y[i21];
    }
  }
  (void)local_rank(d_X);
  d_u.set_size(c_u.size(0) + b_v.size(0));
  db_loop_ub = c_u.size(0);
  if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
    for (int i22{0}; i22 < db_loop_ub; i22++) {
      d_u[i22] = c_u[i22];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i22 = 0; i22 < db_loop_ub; i22++) {
      d_u[i22] = c_u[i22];
    }
  }
  eb_loop_ub = b_v.size(0);
  if ((static_cast<int>(b_v.size(0) < 4)) != 0) {
    for (int i23{0}; i23 < eb_loop_ub; i23++) {
      d_u[i23 + c_u.size(0)] = b_v[i23];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i23 = 0; i23 < eb_loop_ub; i23++) {
      d_u[i23 + c_u.size(0)] = b_v[i23];
    }
  }
  mldivide(d_X, d_u, r);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i24 = 0; i24 < 8; i24++) {
    Tvec[i24] = r[i24];
  }
  Tvec[8] = 1.0;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d, i27, b_d1, d2, d3)

  for (int i25 = 0; i25 < 3; i25++) {
    b_d1 = Tvec[i25];
    d2 = Tvec[i25 + 3];
    d3 = Tvec[i25 + 6];
    for (i27 = 0; i27 < 3; i27++) {
      d = ((b_d1 * normMatrix1[i27][0]) + (d2 * normMatrix1[i27][1])) +
          (d3 * normMatrix1[i27][2]);
      b_Tvec[i27][i25] = d;
    }
  }
  b_mldivide(normMatrix2, b_Tvec, dv);
  inv(dv, T);
  e_T = T[2][2];
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i26 = 0; i26 < 3; i26++) {
    tform->T[i26][0] = T[i26][0] / e_T;
    tform->T[i26][1] = T[i26][1] / e_T;
    tform->T[i26][2] = T[i26][2] / e_T;
  }
}

} // namespace coder

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
