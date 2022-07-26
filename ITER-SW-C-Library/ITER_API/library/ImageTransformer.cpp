//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ImageTransformer.h"
#include "ITER_API_rtwutil.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : ImageTransformer
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
ImageTransformer::ImageTransformer()
{
}

//
// Arguments    : void
// Return Type  : void
//
ImageTransformer::~ImageTransformer()
{
}

//
// Arguments    : const ::coder::array<unsigned char, 3U> &o_I
//                const double b_intrinsicMatrix[3][3]
//                const double radialDist[3]
//                const double tangentialDist[2]
//                const double b_xBounds[2]
//                const double b_yBounds[2]
// Return Type  : void
//
void b_ImageTransformer::update(const ::coder::array<unsigned char, 3U> &o_I,
                                const double b_intrinsicMatrix[3][3],
                                const double radialDist[3],
                                const double tangentialDist[2],
                                const double b_xBounds[2],
                                const double b_yBounds[2])
{
  static const char b_cv1[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char b_outputView[4]{'s', 'a', 'm', 'e'};
  ::coder::array<double, 2U> b_normalizedPoints;
  ::coder::array<double, 2U> b_points;
  ::coder::array<double, 2U> b_y;
  ::coder::array<double, 2U> centeredPoints;
  ::coder::array<double, 2U> d_X;
  ::coder::array<double, 2U> distortedNormalizedPoints;
  ::coder::array<double, 2U> f_a;
  ::coder::array<double, 2U> g_Y;
  ::coder::array<double, 2U> normalizedPoints;
  ::coder::array<double, 2U> ptsOut;
  ::coder::array<double, 2U> y;
  ::coder::array<double, 1U> alpha;
  ::coder::array<double, 1U> b_ptsOut;
  ::coder::array<double, 1U> b_z1;
  ::coder::array<double, 1U> g_b;
  ::coder::array<double, 1U> j_b;
  ::coder::array<double, 1U> r2;
  ::coder::array<double, 1U> r4;
  ::coder::array<double, 1U> xNorm;
  ::coder::array<double, 1U> xyProduct;
  ::coder::array<double, 1U> yNorm;
  ::coder::array<double, 1U> z1;
  double c_b[2];
  double b;
  double b_a;
  double b_b;
  double b_d1;
  double b_radialDist;
  double b_tangentialDist;
  double c_a;
  double c_intrinsicMatrix;
  double c_tangentialDist;
  double d;
  double d_a;
  double d_intrinsicMatrix;
  double e_a;
  double e_intrinsicMatrix;
  double e_k;
  double f_intrinsicMatrix;
  double g_intrinsicMatrix;
  double g_k;
  double h_intrinsicMatrix;
  double i_intrinsicMatrix;
  double k_idx_0;
  double k_idx_1;
  int num[2];
  int ab_loop_ub;
  int b_k;
  int b_nx;
  int bb_loop_ub;
  int c_i;
  int cb_loop_ub;
  int db_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i22;
  int i27;
  int i30;
  int i7;
  int i_N;
  int i_loop_ub;
  int j_X;
  int j_Y;
  int j_loop_ub;
  int jb_loop_ub;
  int k_N;
  int k_loop_ub;
  int m_N;
  int m_loop_ub;
  int mb_loop_ub;
  int normalizedPoints_idx_0;
  int ny;
  int o_N;
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
  int y_loop_ub;
  bool b_bool;
  bool guard1{false};
  bool guard2{false};
  bool guard3{false};
  SizeOfImage.set_size(1, 3);
  SizeOfImage[0] = static_cast<double>(o_I.size(0));
  SizeOfImage[1] = static_cast<double>(o_I.size(1));
  SizeOfImage[2] = static_cast<double>(o_I.size(2));
  ClassOfImage.set_size(1, 5);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 5; b_i++) {
    ClassOfImage[b_i] = b_cv[b_i];
  }
  OutputView.set_size(1, 4);
  for (int i1{0}; i1 < 4; i1++) {
    OutputView[i1] = b_outputView[i1];
  }
  XBounds[0] = b_xBounds[0];
  YBounds[0] = b_yBounds[0];
  XBounds[1] = b_xBounds[1];
  YBounds[1] = b_yBounds[1];
  b_a = XBounds[0];
  b = XBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(b_a)) {
    guard2 = true;
  } else if (std::isnan(b)) {
    guard2 = true;
  } else if (b < b_a) {
    y.set_size(1, 0);
  } else if (std::isinf(b_a)) {
    guard3 = true;
  } else if (std::isinf(b)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (b_a == b) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }
  if (guard2) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  }
  if (guard1) {
    if (std::floor(b_a) == b_a) {
      int b_loop_ub;
      int loop_ub;
      loop_ub = static_cast<int>(std::floor(b - b_a));
      y.set_size(1, loop_ub + 1);
      b_loop_ub = loop_ub;
      if ((static_cast<int>((loop_ub + 1) < 4)) != 0) {
        for (int i2{0}; i2 <= loop_ub; i2++) {
          y[i2] = b_a + (static_cast<double>(i2));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i2 = 0; i2 <= b_loop_ub; i2++) {
          y[i2] = b_a + (static_cast<double>(i2));
        }
      }
    } else {
      eml_float_colon(b_a, b, y);
    }
  }
  c_a = YBounds[0];
  b_b = YBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(c_a)) {
    guard2 = true;
  } else if (std::isnan(b_b)) {
    guard2 = true;
  } else if (b_b < c_a) {
    b_y.set_size(1, 0);
  } else if (std::isinf(c_a)) {
    guard3 = true;
  } else if (std::isinf(b_b)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (c_a == b_b) {
      b_y.set_size(1, 1);
      b_y[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }
  if (guard2) {
    b_y.set_size(1, 1);
    b_y[0] = rtNaN;
  }
  if (guard1) {
    if (std::floor(c_a) == c_a) {
      int c_loop_ub;
      int d_loop_ub;
      c_loop_ub = static_cast<int>(std::floor(b_b - c_a));
      b_y.set_size(1, c_loop_ub + 1);
      d_loop_ub = c_loop_ub;
      if ((static_cast<int>((c_loop_ub + 1) < 4)) != 0) {
        for (int i3{0}; i3 <= c_loop_ub; i3++) {
          b_y[i3] = c_a + (static_cast<double>(i3));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i3 = 0; i3 <= d_loop_ub; i3++) {
          b_y[i3] = c_a + (static_cast<double>(i3));
        }
      }
    } else {
      eml_float_colon(c_a, b_b, b_y);
    }
  }
  b_nx = y.size(1);
  ny = b_y.size(1);
  d_X.set_size(b_y.size(1), y.size(1));
  g_Y.set_size(b_y.size(1), y.size(1));
  if (y.size(1) != 0) {
    if (b_y.size(1) != 0) {
      if ((static_cast<int>((y.size(1) * b_y.size(1)) < 4)) != 0) {
        for (int j{0}; j < b_nx; j++) {
          for (c_i = 0; c_i < ny; c_i++) {
            d_X[c_i + (d_X.size(0) * j)] = y[j];
            g_Y[c_i + (g_Y.size(0) * j)] = b_y[c_i];
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i)

        for (int j = 0; j < b_nx; j++) {
          for (c_i = 0; c_i < ny; c_i++) {
            d_X[c_i + (d_X.size(0) * j)] = y[j];
            g_Y[c_i + (g_Y.size(0) * j)] = b_y[c_i];
          }
        }
      }
    }
  }
  j_X = d_X.size(0) * d_X.size(1);
  j_Y = g_Y.size(0) * g_Y.size(1);
  b_points.set_size(j_X, 2);
  e_loop_ub = j_X;
  if ((static_cast<int>(j_X < 4)) != 0) {
    for (int i4{0}; i4 < j_X; i4++) {
      b_points[i4] = d_X[i4];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < e_loop_ub; i4++) {
      b_points[i4] = d_X[i4];
    }
  }
  f_loop_ub = j_Y;
  if ((static_cast<int>(j_Y < 4)) != 0) {
    for (int i5{0}; i5 < j_Y; i5++) {
      b_points[i5 + b_points.size(0)] = g_Y[i5];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i5 = 0; i5 < f_loop_ub; i5++) {
      b_points[i5 + b_points.size(0)] = g_Y[i5];
    }
  }
  c_b[0] = b_intrinsicMatrix[0][2];
  c_b[1] = b_intrinsicMatrix[1][2];
  centeredPoints.set_size(b_points.size(0), 2);
  if (b_points.size(0) != 0) {
    int acoef;
    acoef = static_cast<int>(b_points.size(0) != 1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_k, i7)

    for (int k = 0; k < 2; k++) {
      i7 = centeredPoints.size(0) - 1;
      for (b_k = 0; b_k <= i7; b_k++) {
        centeredPoints[b_k + (centeredPoints.size(0) * k)] =
            b_points[(acoef * b_k) + (b_points.size(0) * k)] - c_b[k];
      }
    }
  }
  c_intrinsicMatrix = b_intrinsicMatrix[1][1];
  g_loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  h_loop_ub = centeredPoints.size(0);
  if ((static_cast<int>(centeredPoints.size(0) < 4)) != 0) {
    for (int i6{0}; i6 < g_loop_ub; i6++) {
      yNorm[i6] =
          centeredPoints[i6 + centeredPoints.size(0)] / c_intrinsicMatrix;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < h_loop_ub; i6++) {
      yNorm[i6] =
          centeredPoints[i6 + centeredPoints.size(0)] / c_intrinsicMatrix;
    }
  }
  d_intrinsicMatrix = b_intrinsicMatrix[0][0];
  i_loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  j_loop_ub = centeredPoints.size(0);
  if ((static_cast<int>(centeredPoints.size(0) < 4)) != 0) {
    for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
      xNorm[b_i8] = centeredPoints[b_i8] / d_intrinsicMatrix;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
      xNorm[b_i8] = centeredPoints[b_i8] / d_intrinsicMatrix;
    }
  }
  z1.set_size(xNorm.size(0));
  i_N = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int c_k{0}; c_k < i_N; c_k++) {
      z1[c_k] = rt_powd_snf(xNorm[c_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_k = 0; c_k < i_N; c_k++) {
      z1[c_k] = rt_powd_snf(xNorm[c_k], 2.0);
    }
  }
  b_z1.set_size(yNorm.size(0));
  k_N = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int d_k{0}; d_k < k_N; d_k++) {
      b_z1[d_k] = rt_powd_snf(yNorm[d_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int d_k = 0; d_k < k_N; d_k++) {
      b_z1[d_k] = rt_powd_snf(yNorm[d_k], 2.0);
    }
  }
  r2.set_size(z1.size(0));
  k_loop_ub = z1.size(0);
  if ((static_cast<int>(z1.size(0) < 4)) != 0) {
    for (int i9{0}; i9 < k_loop_ub; i9++) {
      r2[i9] = z1[i9] + b_z1[i9];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i9 = 0; i9 < k_loop_ub; i9++) {
      r2[i9] = z1[i9] + b_z1[i9];
    }
  }
  r4.set_size(r2.size(0));
  m_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i10{0}; i10 < m_loop_ub; i10++) {
      r4[i10] = r2[i10] * r2[i10];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i10 = 0; i10 < m_loop_ub; i10++) {
      r4[i10] = r2[i10] * r2[i10];
    }
  }
  k_idx_0 = radialDist[0];
  k_idx_1 = radialDist[1];
  e_k = radialDist[0];
  g_k = radialDist[1];
  b_radialDist = radialDist[2];
  alpha.set_size(r2.size(0));
  o_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i11{0}; i11 < o_loop_ub; i11++) {
      alpha[i11] = ((k_idx_0 * r2[i11]) + (k_idx_1 * r4[i11])) +
                   (b_radialDist * (r2[i11] * r4[i11]));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i11 = 0; i11 < o_loop_ub; i11++) {
      alpha[i11] = ((e_k * r2[i11]) + (g_k * r4[i11])) +
                   (b_radialDist * (r2[i11] * r4[i11]));
    }
  }
  xyProduct.set_size(xNorm.size(0));
  p_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i12{0}; i12 < p_loop_ub; i12++) {
      xyProduct[i12] = xNorm[i12] * yNorm[i12];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i12 = 0; i12 < p_loop_ub; i12++) {
      xyProduct[i12] = xNorm[i12] * yNorm[i12];
    }
  }
  g_b.set_size(xNorm.size(0));
  z1.set_size(xNorm.size(0));
  q_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i13{0}; i13 < q_loop_ub; i13++) {
      z1[i13] = g_b[i13];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i13 = 0; i13 < q_loop_ub; i13++) {
      z1[i13] = g_b[i13];
    }
  }
  m_N = g_b.size(0);
  if ((static_cast<int>(g_b.size(0) < 4)) != 0) {
    for (int h_k{0}; h_k < m_N; h_k++) {
      z1[h_k] = rt_powd_snf(xNorm[h_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int h_k = 0; h_k < m_N; h_k++) {
      z1[h_k] = rt_powd_snf(xNorm[h_k], 2.0);
    }
  }
  d_a = 2.0 * tangentialDist[0];
  j_b.set_size(yNorm.size(0));
  b_z1.set_size(yNorm.size(0));
  r_loop_ub = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int i14{0}; i14 < r_loop_ub; i14++) {
      b_z1[i14] = j_b[i14];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < r_loop_ub; i14++) {
      b_z1[i14] = j_b[i14];
    }
  }
  o_N = j_b.size(0);
  if ((static_cast<int>(j_b.size(0) < 4)) != 0) {
    for (int i_k{0}; i_k < o_N; i_k++) {
      b_z1[i_k] = rt_powd_snf(yNorm[i_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i_k = 0; i_k < o_N; i_k++) {
      b_z1[i_k] = rt_powd_snf(yNorm[i_k], 2.0);
    }
  }
  e_a = 2.0 * tangentialDist[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  s_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i15{0}; i15 < s_loop_ub; i15++) {
      normalizedPoints[i15] = xNorm[i15];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i15 = 0; i15 < s_loop_ub; i15++) {
      normalizedPoints[i15] = xNorm[i15];
    }
  }
  t_loop_ub = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int i16{0}; i16 < t_loop_ub; i16++) {
      normalizedPoints[i16 + normalizedPoints.size(0)] = yNorm[i16];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i16 = 0; i16 < t_loop_ub; i16++) {
      normalizedPoints[i16 + normalizedPoints.size(0)] = yNorm[i16];
    }
  }
  normalizedPoints_idx_0 = normalizedPoints.size(0);
  b_tangentialDist = tangentialDist[1];
  c_tangentialDist = tangentialDist[0];
  b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
  u_loop_ub = normalizedPoints.size(0);
  if ((static_cast<int>(normalizedPoints.size(0) < 4)) != 0) {
    for (int i17{0}; i17 < u_loop_ub; i17++) {
      d = normalizedPoints[i17];
      b_normalizedPoints[i17] = d + (d * alpha[i17]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

    for (int i17 = 0; i17 < u_loop_ub; i17++) {
      d = normalizedPoints[i17];
      b_normalizedPoints[i17] = d + (d * alpha[i17]);
    }
  }
  v_loop_ub = normalizedPoints_idx_0;
  if ((static_cast<int>(normalizedPoints_idx_0 < 4)) != 0) {
    for (int i18{0}; i18 < normalizedPoints_idx_0; i18++) {
      b_d1 = normalizedPoints[i18 + normalizedPoints.size(0)];
      b_normalizedPoints[i18 + b_normalizedPoints.size(0)] =
          b_d1 + (b_d1 * alpha[i18]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_d1)

    for (int i18 = 0; i18 < v_loop_ub; i18++) {
      b_d1 = normalizedPoints[i18 + normalizedPoints.size(0)];
      b_normalizedPoints[i18 + b_normalizedPoints.size(0)] =
          b_d1 + (b_d1 * alpha[i18]);
    }
  }
  f_a.set_size(xyProduct.size(0), 2);
  w_loop_ub = xyProduct.size(0);
  if ((static_cast<int>(xyProduct.size(0) < 4)) != 0) {
    for (int i19{0}; i19 < w_loop_ub; i19++) {
      f_a[i19] = (d_a * xyProduct[i19]) +
                 (b_tangentialDist * (r2[i19] + (2.0 * z1[i19])));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < w_loop_ub; i19++) {
      f_a[i19] = (d_a * xyProduct[i19]) +
                 (b_tangentialDist * (r2[i19] + (2.0 * z1[i19])));
    }
  }
  x_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i20{0}; i20 < x_loop_ub; i20++) {
      f_a[i20 + f_a.size(0)] =
          (c_tangentialDist * (r2[i20] + (2.0 * b_z1[i20]))) +
          (e_a * xyProduct[i20]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i20 = 0; i20 < x_loop_ub; i20++) {
      f_a[i20 + f_a.size(0)] =
          (c_tangentialDist * (r2[i20] + (2.0 * b_z1[i20]))) +
          (e_a * xyProduct[i20]);
    }
  }
  distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
  y_loop_ub = b_normalizedPoints.size(0);
  if ((static_cast<int>((b_normalizedPoints.size(0) * 2) < 4)) != 0) {
    for (int i21{0}; i21 < 2; i21++) {
      for (i22 = 0; i22 < y_loop_ub; i22++) {
        distortedNormalizedPoints[i22 +
                                  (distortedNormalizedPoints.size(0) * i21)] =
            b_normalizedPoints[i22 + (b_normalizedPoints.size(0) * i21)] +
            f_a[i22 + (f_a.size(0) * i21)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i22)

    for (int i21 = 0; i21 < 2; i21++) {
      for (i22 = 0; i22 < y_loop_ub; i22++) {
        distortedNormalizedPoints[i22 +
                                  (distortedNormalizedPoints.size(0) * i21)] =
            b_normalizedPoints[i22 + (b_normalizedPoints.size(0) * i21)] +
            f_a[i22 + (f_a.size(0) * i21)];
      }
    }
  }
  e_intrinsicMatrix = b_intrinsicMatrix[0][0];
  f_intrinsicMatrix = b_intrinsicMatrix[0][2];
  g_intrinsicMatrix = b_intrinsicMatrix[0][1];
  h_intrinsicMatrix = b_intrinsicMatrix[1][1];
  i_intrinsicMatrix = b_intrinsicMatrix[1][2];
  ab_loop_ub = distortedNormalizedPoints.size(0);
  bb_loop_ub = distortedNormalizedPoints.size(0);
  ptsOut.set_size(distortedNormalizedPoints.size(0), 2);
  cb_loop_ub = distortedNormalizedPoints.size(0);
  if ((static_cast<int>(distortedNormalizedPoints.size(0) < 4)) != 0) {
    for (int i23{0}; i23 < ab_loop_ub; i23++) {
      ptsOut[i23] =
          ((distortedNormalizedPoints[i23] * e_intrinsicMatrix) +
           f_intrinsicMatrix) +
          (g_intrinsicMatrix *
           distortedNormalizedPoints[i23 + distortedNormalizedPoints.size(0)]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i23 = 0; i23 < cb_loop_ub; i23++) {
      ptsOut[i23] =
          ((distortedNormalizedPoints[i23] * e_intrinsicMatrix) +
           f_intrinsicMatrix) +
          (g_intrinsicMatrix *
           distortedNormalizedPoints[i23 + distortedNormalizedPoints.size(0)]);
    }
  }
  db_loop_ub = bb_loop_ub;
  if ((static_cast<int>(bb_loop_ub < 4)) != 0) {
    for (int i24{0}; i24 < bb_loop_ub; i24++) {
      ptsOut[i24 + ptsOut.size(0)] =
          (distortedNormalizedPoints[i24 + distortedNormalizedPoints.size(0)] *
           h_intrinsicMatrix) +
          i_intrinsicMatrix;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i24 = 0; i24 < db_loop_ub; i24++) {
      ptsOut[i24 + ptsOut.size(0)] =
          (distortedNormalizedPoints[i24 + distortedNormalizedPoints.size(0)] *
           h_intrinsicMatrix) +
          i_intrinsicMatrix;
    }
  }
  b_bool = false;
  if (ClassOfImage.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (ClassOfImage[kstr] != b_cv1[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    double varargin_1_tmp_idx_0;
    double varargin_1_tmp_idx_1;
    int eb_loop_ub;
    int fb_loop_ub;
    int gb_loop_ub;
    int hb_loop_ub;
    int ib_loop_ub;
    int kb_loop_ub;
    int num_idx_0;
    int num_idx_1;
    varargin_1_tmp_idx_0 = (YBounds[1] - YBounds[0]) + 1.0;
    varargin_1_tmp_idx_1 = (XBounds[1] - XBounds[0]) + 1.0;
    num_idx_0 = static_cast<int>(varargin_1_tmp_idx_0);
    num_idx_1 = static_cast<int>(varargin_1_tmp_idx_1);
    eb_loop_ub = ptsOut.size(0);
    b_ptsOut.set_size(ptsOut.size(0));
    fb_loop_ub = ptsOut.size(0);
    if ((static_cast<int>(ptsOut.size(0) < 4)) != 0) {
      for (int i25{0}; i25 < eb_loop_ub; i25++) {
        b_ptsOut[i25] = ptsOut[i25];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i25 = 0; i25 < fb_loop_ub; i25++) {
        b_ptsOut[i25] = ptsOut[i25];
      }
    }
    num[0] = num_idx_0;
    XmapSingle.set_size(num_idx_0, num_idx_1);
    gb_loop_ub = num_idx_1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, jb_loop_ub)

    for (int i26 = 0; i26 < gb_loop_ub; i26++) {
      jb_loop_ub = num[0];
      for (i27 = 0; i27 < jb_loop_ub; i27++) {
        XmapSingle[i27 + (XmapSingle.size(0) * i26)] =
            static_cast<float>(b_ptsOut[i27 + (num[0] * i26)]);
      }
    }
    num_idx_0 = static_cast<int>(varargin_1_tmp_idx_0);
    num_idx_1 = static_cast<int>(varargin_1_tmp_idx_1);
    hb_loop_ub = ptsOut.size(0);
    b_ptsOut.set_size(ptsOut.size(0));
    ib_loop_ub = ptsOut.size(0);
    if ((static_cast<int>(ptsOut.size(0) < 4)) != 0) {
      for (int i28{0}; i28 < hb_loop_ub; i28++) {
        b_ptsOut[i28] = ptsOut[i28 + ptsOut.size(0)];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i28 = 0; i28 < ib_loop_ub; i28++) {
        b_ptsOut[i28] = ptsOut[i28 + ptsOut.size(0)];
      }
    }
    num[0] = num_idx_0;
    YmapSingle.set_size(num_idx_0, num_idx_1);
    kb_loop_ub = num_idx_1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i30, mb_loop_ub)

    for (int i29 = 0; i29 < kb_loop_ub; i29++) {
      mb_loop_ub = num[0];
      for (i30 = 0; i30 < mb_loop_ub; i30++) {
        YmapSingle[i30 + (YmapSingle.size(0) * i29)] =
            static_cast<float>(b_ptsOut[i30 + (num[0] * i29)]);
      }
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for ImageTransformer.cpp
//
// [EOF]
//
