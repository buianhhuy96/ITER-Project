//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: worldToImage.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "worldToImage.h"
#include "ITER_API_rtwutil.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const c_cameraParameters *intrinsics
//                const double varargin_1[3][3]
//                const ::coder::array<double, 2U> &varargin_2
//                const ::coder::array<double, 2U> &varargin_3
//                ::coder::array<double, 2U> &varargout_1
// Return Type  : void
//
namespace coder {
void worldToImage(const c_cameraParameters *intrinsics,
                  const double varargin_1[3][3],
                  const ::coder::array<double, 2U> &varargin_2,
                  const ::coder::array<double, 2U> &varargin_3,
                  ::coder::array<double, 2U> &varargout_1)
{
  array<double, 2U> b_normalizedPoints;
  array<double, 2U> b_varargin_2;
  array<double, 2U> cameraMatrix;
  array<double, 2U> centeredPoints;
  array<double, 2U> d_a;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> e_result;
  array<double, 2U> imagePointsTmp;
  array<double, 2U> normalizedPoints;
  array<double, 2U> projectedPoints;
  array<double, 2U> result;
  array<double, 1U> alpha;
  array<double, 1U> b_b;
  array<double, 1U> b_z1;
  array<double, 1U> c_imagePointsTmp;
  array<double, 1U> e_b;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xNorm;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  array<double, 1U> z1;
  double f_K[3][3];
  double b[2];
  double b_a;
  double b_d1;
  double b_intrinsics;
  double bkj;
  double c_a;
  double c_intrinsics;
  double d;
  double i_k;
  double j_k;
  double k_idx_0;
  double k_idx_1;
  double k_idx_2;
  double k_k;
  double s;
  double s_K;
  double t_K;
  double u_K;
  double v_K;
  double w_K;
  double x_K;
  double y_K;
  int c_result[2];
  int d_result[2];
  int ab_loop_ub;
  int b_loop_ub;
  int b_m;
  int b_result;
  int bb_loop_ub;
  int c_i;
  int c_k;
  int c_loop_ub;
  int cb_loop_ub;
  int csz_idx_0;
  int d_i;
  int d_loop_ub;
  int db_loop_ub;
  int e_i;
  int e_k;
  int e_loop_ub;
  int eb_loop_ub;
  int f_loop_ub;
  int fb_loop_ub;
  int h_loop_ub;
  int i12;
  int i27;
  int i3;
  int i6;
  int i7;
  int i9;
  int i_loop_ub;
  int inner;
  int input_sizes_idx_1;
  int k;
  int k_N;
  int k_loop_ub;
  int loop_ub;
  int m_N;
  int m_loop_ub;
  int mc;
  int normalizedPoints_idx_0;
  int o_N;
  int o_loop_ub;
  int p_N;
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
  signed char input_sizes[2];
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_0;
  bool empty_non_axis_sizes;
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    f_K[b_i][0] = intrinsics->IntrinsicMatrixInternal[0][b_i];
    f_K[b_i][1] = intrinsics->IntrinsicMatrixInternal[1][b_i];
    f_K[b_i][2] = intrinsics->IntrinsicMatrixInternal[2][b_i];
  }
  input_sizes_idx_0 = static_cast<signed char>(varargin_2.size(1) != 0);
  b_varargin_2.set_size(1, varargin_2.size(1));
  loop_ub = varargin_2.size(1);
  if ((static_cast<int>(varargin_2.size(1) < 4)) != 0) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_varargin_2[i1] = varargin_2[i1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < loop_ub; i1++) {
      b_varargin_2[i1] = varargin_2[i1];
    }
  }
  input_sizes[0] = input_sizes_idx_0;
  result.set_size((static_cast<int>(input_sizes_idx_0)) + 3, 3);
  b_loop_ub = static_cast<int>(input_sizes_idx_0);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

  for (int i2 = 0; i2 < 3; i2++) {
    result[result.size(0) * i2] = varargin_1[i2][0];
    result[(result.size(0) * i2) + 1] = varargin_1[i2][1];
    result[(result.size(0) * i2) + 2] = varargin_1[i2][2];
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      result[(result.size(0) * i2) + 3] =
          b_varargin_2[(static_cast<int>(input_sizes[0])) * i2];
    }
  }
  b_m = result.size(0);
  cameraMatrix.set_size(result.size(0), 3);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(s, c_i)

  for (int j = 0; j < 3; j++) {
    for (c_i = 0; c_i < b_m; c_i++) {
      s = ((result[c_i] * f_K[j][0]) +
           (result[c_i + result.size(0)] * f_K[j][1])) +
          (result[c_i + (result.size(0) * 2)] * f_K[j][2]);
      cameraMatrix[c_i + (cameraMatrix.size(0) * j)] = s;
    }
  }
  if ((varargin_3.size(0) != 0) && (varargin_3.size(1) != 0)) {
    b_result = varargin_3.size(0);
  } else if (varargin_3.size(0) != 0) {
    b_result = varargin_3.size(0);
  } else {
    b_result = 0;
  }
  empty_non_axis_sizes = (b_result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = varargin_3.size(1);
  } else if ((varargin_3.size(0) != 0) && (varargin_3.size(1) != 0)) {
    input_sizes_idx_1 = varargin_3.size(1);
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 1;
  } else if (varargin_3.size(0) != 0) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  c_result[0] = b_result;
  c_result[1] = input_sizes_idx_1;
  d_result[0] = b_result;
  d_result[1] = static_cast<int>(b_input_sizes_idx_1);
  e_result.set_size(b_result, input_sizes_idx_1 +
                                  (static_cast<int>(b_input_sizes_idx_1)));
  c_loop_ub = input_sizes_idx_1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    e_loop_ub)

  for (int i4 = 0; i4 < c_loop_ub; i4++) {
    e_loop_ub = c_result[0];
    for (i6 = 0; i6 < e_loop_ub; i6++) {
      e_result[i6 + (e_result.size(0) * i4)] =
          varargin_3[i6 + (c_result[0] * i4)];
    }
  }
  d_loop_ub = d_result[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    f_loop_ub)

  for (int i5 = 0; i5 < d_loop_ub; i5++) {
    f_loop_ub = d_result[0];
    for (i7 = 0; i7 < f_loop_ub; i7++) {
      e_result[i7 + (e_result.size(0) * c_result[1])] = 1.0;
    }
  }
  mc = e_result.size(0) - 1;
  inner = e_result.size(1);
  projectedPoints.set_size(e_result.size(0), 3);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_i, bkj,  \
                                                                    k, e_i)

  for (int b_j = 0; b_j < 3; b_j++) {
    for (e_i = 0; e_i <= mc; e_i++) {
      projectedPoints[e_i + (projectedPoints.size(0) * b_j)] = 0.0;
    }
    for (k = 0; k < inner; k++) {
      bkj = cameraMatrix[k + (cameraMatrix.size(0) * b_j)];
      for (d_i = 0; d_i <= mc; d_i++) {
        projectedPoints[d_i + (projectedPoints.size(0) * b_j)] =
            projectedPoints[d_i + (projectedPoints.size(0) * b_j)] +
            (e_result[d_i + (e_result.size(0) * k)] * bkj);
      }
    }
  }
  if (projectedPoints.size(0) == 1) {
    csz_idx_0 = 1;
  } else if (projectedPoints.size(0) == 1) {
    csz_idx_0 = 1;
  } else {
    csz_idx_0 = projectedPoints.size(0);
  }
  imagePointsTmp.set_size(csz_idx_0, 2);
  if (csz_idx_0 != 0) {
    int acoef;
    int bcoef;
    acoef = static_cast<int>(projectedPoints.size(0) != 1);
    bcoef = static_cast<int>(projectedPoints.size(0) != 1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_k, i9)

    for (int b_k = 0; b_k < 2; b_k++) {
      i9 = imagePointsTmp.size(0) - 1;
      for (c_k = 0; c_k <= i9; c_k++) {
        imagePointsTmp[c_k + (imagePointsTmp.size(0) * b_k)] =
            projectedPoints[(acoef * c_k) + (projectedPoints.size(0) * b_k)] /
            projectedPoints[(bcoef * c_k) + (projectedPoints.size(0) * 2)];
      }
    }
  }
  if (f_K[0][1] != 0.0) {
    double p_K;
    double q_K;
    double r_K;
    int b_imagePointsTmp;
    int g_loop_ub;
    int j_loop_ub;
    b_imagePointsTmp = imagePointsTmp.size(0) - 1;
    p_K = f_K[0][1];
    q_K = f_K[1][2];
    r_K = f_K[1][1];
    c_imagePointsTmp.set_size(imagePointsTmp.size(0));
    g_loop_ub = imagePointsTmp.size(0) - 1;
    if ((static_cast<int>(imagePointsTmp.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 <= b_imagePointsTmp; b_i8++) {
        c_imagePointsTmp[b_i8] =
            imagePointsTmp[b_i8] -
            ((p_K * (imagePointsTmp[b_i8 + imagePointsTmp.size(0)] - q_K)) /
             r_K);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 <= g_loop_ub; b_i8++) {
        c_imagePointsTmp[b_i8] =
            imagePointsTmp[b_i8] -
            ((p_K * (imagePointsTmp[b_i8 + imagePointsTmp.size(0)] - q_K)) /
             r_K);
      }
    }
    j_loop_ub = c_imagePointsTmp.size(0);
    if ((static_cast<int>(c_imagePointsTmp.size(0) < 4)) != 0) {
      for (int i11{0}; i11 < j_loop_ub; i11++) {
        imagePointsTmp[i11] = c_imagePointsTmp[i11];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i11 = 0; i11 < j_loop_ub; i11++) {
        imagePointsTmp[i11] = c_imagePointsTmp[i11];
      }
    }
  }
  b[0] = f_K[0][2];
  b[1] = f_K[1][2];
  centeredPoints.set_size(imagePointsTmp.size(0), 2);
  if (imagePointsTmp.size(0) != 0) {
    int b_acoef;
    b_acoef = static_cast<int>(imagePointsTmp.size(0) != 1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_k, i12)

    for (int d_k = 0; d_k < 2; d_k++) {
      i12 = centeredPoints.size(0) - 1;
      for (e_k = 0; e_k <= i12; e_k++) {
        centeredPoints[e_k + (centeredPoints.size(0) * d_k)] =
            imagePointsTmp[(b_acoef * e_k) + (imagePointsTmp.size(0) * d_k)] -
            b[d_k];
      }
    }
  }
  s_K = f_K[1][1];
  h_loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  i_loop_ub = centeredPoints.size(0);
  if ((static_cast<int>(centeredPoints.size(0) < 4)) != 0) {
    for (int i10{0}; i10 < h_loop_ub; i10++) {
      yNorm[i10] = centeredPoints[i10 + centeredPoints.size(0)] / s_K;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i10 = 0; i10 < i_loop_ub; i10++) {
      yNorm[i10] = centeredPoints[i10 + centeredPoints.size(0)] / s_K;
    }
  }
  t_K = f_K[0][0];
  k_loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  m_loop_ub = centeredPoints.size(0);
  if ((static_cast<int>(centeredPoints.size(0) < 4)) != 0) {
    for (int i13{0}; i13 < k_loop_ub; i13++) {
      xNorm[i13] = centeredPoints[i13] / t_K;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i13 = 0; i13 < m_loop_ub; i13++) {
      xNorm[i13] = centeredPoints[i13] / t_K;
    }
  }
  z1.set_size(xNorm.size(0));
  k_N = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int g_k{0}; g_k < k_N; g_k++) {
      z1[g_k] = rt_powd_snf(xNorm[g_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int g_k = 0; g_k < k_N; g_k++) {
      z1[g_k] = rt_powd_snf(xNorm[g_k], 2.0);
    }
  }
  b_z1.set_size(yNorm.size(0));
  m_N = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int h_k{0}; h_k < m_N; h_k++) {
      b_z1[h_k] = rt_powd_snf(yNorm[h_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int h_k = 0; h_k < m_N; h_k++) {
      b_z1[h_k] = rt_powd_snf(yNorm[h_k], 2.0);
    }
  }
  r2.set_size(z1.size(0));
  o_loop_ub = z1.size(0);
  if ((static_cast<int>(z1.size(0) < 4)) != 0) {
    for (int i14{0}; i14 < o_loop_ub; i14++) {
      r2[i14] = z1[i14] + b_z1[i14];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < o_loop_ub; i14++) {
      r2[i14] = z1[i14] + b_z1[i14];
    }
  }
  r4.set_size(r2.size(0));
  p_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i15{0}; i15 < p_loop_ub; i15++) {
      r4[i15] = r2[i15] * r2[i15];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i15 = 0; i15 < p_loop_ub; i15++) {
      r4[i15] = r2[i15] * r2[i15];
    }
  }
  k_idx_0 = intrinsics->RadialDistortion[0];
  k_idx_1 = intrinsics->RadialDistortion[1];
  if (intrinsics->RadialDistortion.size(1) < 3) {
    k_idx_2 = 0.0;
  } else {
    k_idx_2 = intrinsics->RadialDistortion[2];
  }
  i_k = k_idx_0;
  j_k = k_idx_1;
  k_k = k_idx_2;
  alpha.set_size(r2.size(0));
  q_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i16{0}; i16 < q_loop_ub; i16++) {
      alpha[i16] = ((k_idx_0 * r2[i16]) + (k_idx_1 * r4[i16])) +
                   (k_idx_2 * (r2[i16] * r4[i16]));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i16 = 0; i16 < q_loop_ub; i16++) {
      alpha[i16] =
          ((i_k * r2[i16]) + (j_k * r4[i16])) + (k_k * (r2[i16] * r4[i16]));
    }
  }
  xyProduct.set_size(xNorm.size(0));
  r_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i17{0}; i17 < r_loop_ub; i17++) {
      xyProduct[i17] = xNorm[i17] * yNorm[i17];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i17 = 0; i17 < r_loop_ub; i17++) {
      xyProduct[i17] = xNorm[i17] * yNorm[i17];
    }
  }
  b_b.set_size(xNorm.size(0));
  z1.set_size(xNorm.size(0));
  s_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i18{0}; i18 < s_loop_ub; i18++) {
      z1[i18] = b_b[i18];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < s_loop_ub; i18++) {
      z1[i18] = b_b[i18];
    }
  }
  o_N = b_b.size(0);
  if ((static_cast<int>(b_b.size(0) < 4)) != 0) {
    for (int m_k{0}; m_k < o_N; m_k++) {
      z1[m_k] = rt_powd_snf(xNorm[m_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int m_k = 0; m_k < o_N; m_k++) {
      z1[m_k] = rt_powd_snf(xNorm[m_k], 2.0);
    }
  }
  b_a = 2.0 * intrinsics->TangentialDistortion[0];
  e_b.set_size(yNorm.size(0));
  b_z1.set_size(yNorm.size(0));
  t_loop_ub = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int i19{0}; i19 < t_loop_ub; i19++) {
      b_z1[i19] = e_b[i19];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < t_loop_ub; i19++) {
      b_z1[i19] = e_b[i19];
    }
  }
  p_N = e_b.size(0);
  if ((static_cast<int>(e_b.size(0) < 4)) != 0) {
    for (int o_k{0}; o_k < p_N; o_k++) {
      b_z1[o_k] = rt_powd_snf(yNorm[o_k], 2.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int o_k = 0; o_k < p_N; o_k++) {
      b_z1[o_k] = rt_powd_snf(yNorm[o_k], 2.0);
    }
  }
  c_a = 2.0 * intrinsics->TangentialDistortion[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  u_loop_ub = xNorm.size(0);
  if ((static_cast<int>(xNorm.size(0) < 4)) != 0) {
    for (int i20{0}; i20 < u_loop_ub; i20++) {
      normalizedPoints[i20] = xNorm[i20];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i20 = 0; i20 < u_loop_ub; i20++) {
      normalizedPoints[i20] = xNorm[i20];
    }
  }
  v_loop_ub = yNorm.size(0);
  if ((static_cast<int>(yNorm.size(0) < 4)) != 0) {
    for (int i21{0}; i21 < v_loop_ub; i21++) {
      normalizedPoints[i21 + normalizedPoints.size(0)] = yNorm[i21];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i21 = 0; i21 < v_loop_ub; i21++) {
      normalizedPoints[i21 + normalizedPoints.size(0)] = yNorm[i21];
    }
  }
  normalizedPoints_idx_0 = normalizedPoints.size(0);
  b_intrinsics = intrinsics->TangentialDistortion[1];
  c_intrinsics = intrinsics->TangentialDistortion[0];
  b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
  w_loop_ub = normalizedPoints.size(0);
  if ((static_cast<int>(normalizedPoints.size(0) < 4)) != 0) {
    for (int i22{0}; i22 < w_loop_ub; i22++) {
      d = normalizedPoints[i22];
      b_normalizedPoints[i22] = d + (d * alpha[i22]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

    for (int i22 = 0; i22 < w_loop_ub; i22++) {
      d = normalizedPoints[i22];
      b_normalizedPoints[i22] = d + (d * alpha[i22]);
    }
  }
  x_loop_ub = normalizedPoints_idx_0;
  if ((static_cast<int>(normalizedPoints_idx_0 < 4)) != 0) {
    for (int i23{0}; i23 < normalizedPoints_idx_0; i23++) {
      b_d1 = normalizedPoints[i23 + normalizedPoints.size(0)];
      b_normalizedPoints[i23 + b_normalizedPoints.size(0)] =
          b_d1 + (b_d1 * alpha[i23]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_d1)

    for (int i23 = 0; i23 < x_loop_ub; i23++) {
      b_d1 = normalizedPoints[i23 + normalizedPoints.size(0)];
      b_normalizedPoints[i23 + b_normalizedPoints.size(0)] =
          b_d1 + (b_d1 * alpha[i23]);
    }
  }
  d_a.set_size(xyProduct.size(0), 2);
  y_loop_ub = xyProduct.size(0);
  if ((static_cast<int>(xyProduct.size(0) < 4)) != 0) {
    for (int i24{0}; i24 < y_loop_ub; i24++) {
      d_a[i24] =
          (b_a * xyProduct[i24]) + (b_intrinsics * (r2[i24] + (2.0 * z1[i24])));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i24 = 0; i24 < y_loop_ub; i24++) {
      d_a[i24] =
          (b_a * xyProduct[i24]) + (b_intrinsics * (r2[i24] + (2.0 * z1[i24])));
    }
  }
  ab_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i25{0}; i25 < ab_loop_ub; i25++) {
      d_a[i25 + d_a.size(0)] = (c_intrinsics * (r2[i25] + (2.0 * b_z1[i25]))) +
                               (c_a * xyProduct[i25]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i25 = 0; i25 < ab_loop_ub; i25++) {
      d_a[i25 + d_a.size(0)] = (c_intrinsics * (r2[i25] + (2.0 * b_z1[i25]))) +
                               (c_a * xyProduct[i25]);
    }
  }
  distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
  bb_loop_ub = b_normalizedPoints.size(0);
  if ((static_cast<int>((b_normalizedPoints.size(0) * 2) < 4)) != 0) {
    for (int i26{0}; i26 < 2; i26++) {
      for (i27 = 0; i27 < bb_loop_ub; i27++) {
        distortedNormalizedPoints[i27 +
                                  (distortedNormalizedPoints.size(0) * i26)] =
            b_normalizedPoints[i27 + (b_normalizedPoints.size(0) * i26)] +
            d_a[i27 + (d_a.size(0) * i26)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i27)

    for (int i26 = 0; i26 < 2; i26++) {
      for (i27 = 0; i27 < bb_loop_ub; i27++) {
        distortedNormalizedPoints[i27 +
                                  (distortedNormalizedPoints.size(0) * i26)] =
            b_normalizedPoints[i27 + (b_normalizedPoints.size(0) * i26)] +
            d_a[i27 + (d_a.size(0) * i26)];
      }
    }
  }
  u_K = f_K[0][0];
  v_K = f_K[0][2];
  w_K = f_K[0][1];
  x_K = f_K[1][1];
  y_K = f_K[1][2];
  cb_loop_ub = distortedNormalizedPoints.size(0);
  db_loop_ub = distortedNormalizedPoints.size(0);
  varargout_1.set_size(distortedNormalizedPoints.size(0), 2);
  eb_loop_ub = distortedNormalizedPoints.size(0);
  if ((static_cast<int>(distortedNormalizedPoints.size(0) < 4)) != 0) {
    for (int i28{0}; i28 < cb_loop_ub; i28++) {
      varargout_1[i28] =
          ((distortedNormalizedPoints[i28] * u_K) + v_K) +
          (w_K *
           distortedNormalizedPoints[i28 + distortedNormalizedPoints.size(0)]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i28 = 0; i28 < eb_loop_ub; i28++) {
      varargout_1[i28] =
          ((distortedNormalizedPoints[i28] * u_K) + v_K) +
          (w_K *
           distortedNormalizedPoints[i28 + distortedNormalizedPoints.size(0)]);
    }
  }
  fb_loop_ub = db_loop_ub;
  if ((static_cast<int>(db_loop_ub < 4)) != 0) {
    for (int i29{0}; i29 < db_loop_ub; i29++) {
      varargout_1[i29 + varargout_1.size(0)] =
          (distortedNormalizedPoints[i29 + distortedNormalizedPoints.size(0)] *
           x_K) +
          y_K;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i29 = 0; i29 < fb_loop_ub; i29++) {
      varargout_1[i29 + varargout_1.size(0)] =
          (distortedNormalizedPoints[i29 + distortedNormalizedPoints.size(0)] *
           x_K) +
          y_K;
    }
  }
}

} // namespace coder

//
// File trailer for worldToImage.cpp
//
// [EOF]
//
