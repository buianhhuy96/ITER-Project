//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "ImageTransformer.h"
#include "calibrateHandeye_rtwutil.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &k_I
//                const double b_intrinsicMatrix[3][3]
//                const double radialDist[3]
//                const double tangentialDist[2]
//                const double b_xBounds[2]
//                const double b_yBounds[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void b_ImageTransformer::update(const ::coder::array<unsigned char, 3U> &k_I,
                                const double b_intrinsicMatrix[3][3],
                                const double radialDist[3],
                                const double tangentialDist[2],
                                const double b_xBounds[2],
                                const double b_yBounds[2])
{
  static const char cv1[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char b_outputView[4]{'s', 'a', 'm', 'e'};
  array<double, 2U> b_normalizedPoints;
  array<double, 2U> b_points;
  array<double, 2U> b_y;
  array<double, 2U> centeredPoints;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> e_X;
  array<double, 2U> g_a;
  array<double, 2U> h_Y;
  array<double, 2U> normalizedPoints;
  array<double, 2U> ptsOut;
  array<double, 2U> y;
  array<double, 1U> alpha;
  array<double, 1U> b_ptsOut;
  array<double, 1U> b_z1;
  array<double, 1U> f_b;
  array<double, 1U> g_b;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xNorm;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  array<double, 1U> z1;
  double center[2];
  double b;
  double b_a;
  double c_a;
  double c_b;
  double d_a;
  double f_a;
  double k_idx_0;
  double k_idx_1;
  int b_ny;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_N;
  int f_X;
  int f_loop_ub;
  int g_N;
  int g_loop_ub;
  int h_N;
  int h_loop_ub;
  int i_N;
  int i_loop_ub;
  int j_Y;
  int j_loop_ub;
  int k_loop_ub;
  int m_loop_ub;
  int nx;
  int o_loop_ub;
  int p_loop_ub;
  int q_loop_ub;
  int r_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int u_loop_ub;
  bool b_bool;
  bool guard1{false};
  bool guard2{false};
  bool guard3{false};
  SizeOfImage.set_size(1, 3);
  SizeOfImage[0] = static_cast<double>(k_I.size(0));
  SizeOfImage[1] = static_cast<double>(k_I.size(1));
  SizeOfImage[2] = static_cast<double>(k_I.size(2));
  ClassOfImage.set_size(1, 5);
  for (int b_i{0}; b_i < 5; b_i++) {
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
      int loop_ub;
      loop_ub = static_cast<int>(std::floor(b - b_a));
      y.set_size(1, loop_ub + 1);
      for (int i2{0}; i2 <= loop_ub; i2++) {
        y[i2] = b_a + (static_cast<double>(i2));
      }
    } else {
      eml_float_colon(b_a, b, y);
    }
  }
  c_a = YBounds[0];
  c_b = YBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(c_a)) {
    guard2 = true;
  } else if (std::isnan(c_b)) {
    guard2 = true;
  } else if (c_b < c_a) {
    b_y.set_size(1, 0);
  } else if (std::isinf(c_a)) {
    guard3 = true;
  } else if (std::isinf(c_b)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (c_a == c_b) {
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
      int b_loop_ub;
      b_loop_ub = static_cast<int>(std::floor(c_b - c_a));
      b_y.set_size(1, b_loop_ub + 1);
      for (int i3{0}; i3 <= b_loop_ub; i3++) {
        b_y[i3] = c_a + (static_cast<double>(i3));
      }
    } else {
      eml_float_colon(c_a, c_b, b_y);
    }
  }
  nx = y.size(1);
  b_ny = b_y.size(1);
  e_X.set_size(b_y.size(1), y.size(1));
  h_Y.set_size(b_y.size(1), y.size(1));
  if (y.size(1) != 0) {
    if (b_y.size(1) != 0) {
      for (int j{0}; j < nx; j++) {
        for (int c_i{0}; c_i < b_ny; c_i++) {
          e_X[c_i + (e_X.size(0) * j)] = y[j];
          h_Y[c_i + (h_Y.size(0) * j)] = b_y[c_i];
        }
      }
    }
  }
  f_X = e_X.size(0) * e_X.size(1);
  j_Y = h_Y.size(0) * h_Y.size(1);
  b_points.set_size(f_X, 2);
  for (int i4{0}; i4 < f_X; i4++) {
    b_points[i4] = e_X[i4];
  }
  for (int i5{0}; i5 < j_Y; i5++) {
    b_points[i5 + b_points.size(0)] = h_Y[i5];
  }
  center[0] = b_intrinsicMatrix[0][2];
  center[1] = b_intrinsicMatrix[1][2];
  centeredPoints.set_size(b_points.size(0), 2);
  if (b_points.size(0) != 0) {
    int acoef;
    acoef = static_cast<int>(b_points.size(0) != 1);
    for (int k{0}; k < 2; k++) {
      int i7;
      i7 = centeredPoints.size(0) - 1;
      for (int b_k{0}; b_k <= i7; b_k++) {
        centeredPoints[b_k + (centeredPoints.size(0) * k)] =
            b_points[(acoef * b_k) + (b_points.size(0) * k)] - center[k];
      }
    }
  }
  c_loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  for (int i6{0}; i6 < c_loop_ub; i6++) {
    yNorm[i6] =
        centeredPoints[i6 + centeredPoints.size(0)] / b_intrinsicMatrix[1][1];
  }
  d_loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  for (int i8{0}; i8 < d_loop_ub; i8++) {
    xNorm[i8] = centeredPoints[i8] / b_intrinsicMatrix[0][0];
  }
  z1.set_size(xNorm.size(0));
  f_N = xNorm.size(0);
  for (int c_k{0}; c_k < f_N; c_k++) {
    z1[c_k] = rt_powd_snf(xNorm[c_k], 2.0);
  }
  b_z1.set_size(yNorm.size(0));
  g_N = yNorm.size(0);
  for (int d_k{0}; d_k < g_N; d_k++) {
    b_z1[d_k] = rt_powd_snf(yNorm[d_k], 2.0);
  }
  r2.set_size(z1.size(0));
  e_loop_ub = z1.size(0);
  for (int i9{0}; i9 < e_loop_ub; i9++) {
    r2[i9] = z1[i9] + b_z1[i9];
  }
  r4.set_size(r2.size(0));
  f_loop_ub = r2.size(0);
  for (int i10{0}; i10 < f_loop_ub; i10++) {
    r4[i10] = r2[i10] * r2[i10];
  }
  k_idx_0 = radialDist[0];
  k_idx_1 = radialDist[1];
  alpha.set_size(r2.size(0));
  g_loop_ub = r2.size(0);
  for (int i11{0}; i11 < g_loop_ub; i11++) {
    alpha[i11] = ((k_idx_0 * r2[i11]) + (k_idx_1 * r4[i11])) +
                 (radialDist[2] * (r2[i11] * r4[i11]));
  }
  xyProduct.set_size(xNorm.size(0));
  h_loop_ub = xNorm.size(0);
  for (int i12{0}; i12 < h_loop_ub; i12++) {
    xyProduct[i12] = xNorm[i12] * yNorm[i12];
  }
  f_b.set_size(xNorm.size(0));
  z1.set_size(xNorm.size(0));
  i_loop_ub = xNorm.size(0);
  for (int i13{0}; i13 < i_loop_ub; i13++) {
    z1[i13] = f_b[i13];
  }
  h_N = xNorm.size(0);
  for (int f_k{0}; f_k < h_N; f_k++) {
    z1[f_k] = rt_powd_snf(xNorm[f_k], 2.0);
  }
  d_a = 2.0 * tangentialDist[0];
  g_b.set_size(yNorm.size(0));
  b_z1.set_size(yNorm.size(0));
  j_loop_ub = yNorm.size(0);
  for (int i14{0}; i14 < j_loop_ub; i14++) {
    b_z1[i14] = g_b[i14];
  }
  i_N = yNorm.size(0);
  for (int g_k{0}; g_k < i_N; g_k++) {
    b_z1[g_k] = rt_powd_snf(yNorm[g_k], 2.0);
  }
  f_a = 2.0 * tangentialDist[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  k_loop_ub = xNorm.size(0);
  for (int i15{0}; i15 < k_loop_ub; i15++) {
    normalizedPoints[i15] = xNorm[i15];
  }
  m_loop_ub = yNorm.size(0);
  for (int i16{0}; i16 < m_loop_ub; i16++) {
    normalizedPoints[i16 + normalizedPoints.size(0)] = yNorm[i16];
  }
  b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
  o_loop_ub = normalizedPoints.size(0);
  for (int i17{0}; i17 < o_loop_ub; i17++) {
    double d;
    d = normalizedPoints[i17];
    b_normalizedPoints[i17] = d + (d * alpha[i17]);
  }
  p_loop_ub = normalizedPoints.size(0);
  for (int i18{0}; i18 < p_loop_ub; i18++) {
    double b_d1;
    b_d1 = normalizedPoints[i18 + normalizedPoints.size(0)];
    b_normalizedPoints[i18 + b_normalizedPoints.size(0)] =
        b_d1 + (b_d1 * alpha[i18]);
  }
  g_a.set_size(xyProduct.size(0), 2);
  q_loop_ub = xyProduct.size(0);
  for (int i19{0}; i19 < q_loop_ub; i19++) {
    g_a[i19] = (d_a * xyProduct[i19]) +
               (tangentialDist[1] * (r2[i19] + (2.0 * z1[i19])));
  }
  r_loop_ub = r2.size(0);
  for (int i20{0}; i20 < r_loop_ub; i20++) {
    g_a[i20 + g_a.size(0)] =
        (tangentialDist[0] * (r2[i20] + (2.0 * b_z1[i20]))) +
        (f_a * xyProduct[i20]);
  }
  distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
  s_loop_ub = b_normalizedPoints.size(0);
  for (int i21{0}; i21 < 2; i21++) {
    for (int i22{0}; i22 < s_loop_ub; i22++) {
      distortedNormalizedPoints[i22 +
                                (distortedNormalizedPoints.size(0) * i21)] =
          b_normalizedPoints[i22 + (b_normalizedPoints.size(0) * i21)] +
          g_a[i22 + (g_a.size(0) * i21)];
    }
  }
  t_loop_ub = distortedNormalizedPoints.size(0);
  u_loop_ub = distortedNormalizedPoints.size(0);
  ptsOut.set_size(distortedNormalizedPoints.size(0), 2);
  for (int i23{0}; i23 < t_loop_ub; i23++) {
    ptsOut[i23] =
        ((distortedNormalizedPoints[i23] * b_intrinsicMatrix[0][0]) +
         b_intrinsicMatrix[0][2]) +
        (b_intrinsicMatrix[0][1] *
         distortedNormalizedPoints[i23 + distortedNormalizedPoints.size(0)]);
  }
  for (int i24{0}; i24 < u_loop_ub; i24++) {
    ptsOut[i24 + ptsOut.size(0)] =
        (distortedNormalizedPoints[i24 + distortedNormalizedPoints.size(0)] *
         b_intrinsicMatrix[1][1]) +
        b_intrinsicMatrix[1][2];
  }
  b_bool = false;
  if (ClassOfImage.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (ClassOfImage[kstr] != cv1[kstr]) {
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
    double varargin_1_tmp_idx_0_tmp;
    double varargin_1_tmp_idx_1_tmp;
    int num_idx_0_tmp_tmp;
    int num_idx_1_tmp_tmp;
    int v_loop_ub;
    int w_loop_ub;
    varargin_1_tmp_idx_0_tmp = (YBounds[1] - YBounds[0]) + 1.0;
    varargin_1_tmp_idx_1_tmp = (XBounds[1] - XBounds[0]) + 1.0;
    num_idx_0_tmp_tmp = static_cast<int>(varargin_1_tmp_idx_0_tmp);
    num_idx_1_tmp_tmp = static_cast<int>(varargin_1_tmp_idx_1_tmp);
    v_loop_ub = ptsOut.size(0);
    b_ptsOut.set_size(ptsOut.size(0));
    for (int i25{0}; i25 < v_loop_ub; i25++) {
      b_ptsOut[i25] = ptsOut[i25];
    }
    XmapSingle.set_size(num_idx_0_tmp_tmp, num_idx_1_tmp_tmp);
    for (int i26{0}; i26 < num_idx_1_tmp_tmp; i26++) {
      for (int i27{0}; i27 < num_idx_0_tmp_tmp; i27++) {
        XmapSingle[i27 + (XmapSingle.size(0) * i26)] = static_cast<float>(
            b_ptsOut[i27 +
                     ((static_cast<int>(varargin_1_tmp_idx_0_tmp)) * i26)]);
      }
    }
    w_loop_ub = ptsOut.size(0);
    b_ptsOut.set_size(ptsOut.size(0));
    for (int i28{0}; i28 < w_loop_ub; i28++) {
      b_ptsOut[i28] = ptsOut[i28 + ptsOut.size(0)];
    }
    int i29;
    int i30;
    i29 = static_cast<int>(varargin_1_tmp_idx_0_tmp);
    i30 = static_cast<int>(varargin_1_tmp_idx_1_tmp);
    YmapSingle.set_size(i29, i30);
    for (int i31{0}; i31 < num_idx_1_tmp_tmp; i31++) {
      for (int i32{0}; i32 < num_idx_0_tmp_tmp; i32++) {
        YmapSingle[i32 + (YmapSingle.size(0) * i31)] = static_cast<float>(
            b_ptsOut[i32 +
                     ((static_cast<int>(varargin_1_tmp_idx_0_tmp)) * i31)]);
      }
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for ImageTransformer.cpp
//
// [EOF]
//
