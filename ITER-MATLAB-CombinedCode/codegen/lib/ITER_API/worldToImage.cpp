//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: worldToImage.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "worldToImage.h"
#include "ITER_API_rtwutil.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

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
  array<double, 2U> c_result;
  array<double, 2U> cameraMatrix;
  array<double, 2U> centeredPoints;
  array<double, 2U> d_a;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> imagePointsTmp;
  array<double, 2U> normalizedPoints;
  array<double, 2U> projectedPoints;
  array<double, 2U> result;
  array<double, 1U> alpha;
  array<double, 1U> b_b;
  array<double, 1U> b_z1;
  array<double, 1U> c_imagePointsTmp;
  array<double, 1U> f_b;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xNorm;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  array<double, 1U> z1;
  double h_K[3][3];
  double b[2];
  double b_a;
  double b_intrinsics;
  double c_a;
  double c_intrinsics;
  double k_idx_0;
  double k_idx_1;
  double k_idx_2;
  int b_input_sizes_idx_0;
  int b_loop_ub;
  int b_result;
  int c_loop_ub;
  int csz_idx_0;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i_loop_ub;
  int inner;
  int input_sizes_idx_1;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m;
  int m_N;
  int m_loop_ub;
  int mc;
  int o_N;
  int o_loop_ub;
  int p_N;
  int p_loop_ub;
  int q_N;
  int q_loop_ub;
  int r_loop_ub;
  int s_loop_ub;
  int t_loop_ub;
  int u_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_0;
  bool empty_non_axis_sizes;
  for (int b_i{0}; b_i < 3; b_i++) {
    h_K[b_i][0] = intrinsics->IntrinsicMatrixInternal[0][b_i];
    h_K[b_i][1] = intrinsics->IntrinsicMatrixInternal[1][b_i];
    h_K[b_i][2] = intrinsics->IntrinsicMatrixInternal[2][b_i];
  }
  input_sizes_idx_0 = static_cast<signed char>(varargin_2.size(1) != 0);
  b_varargin_2.set_size(1, varargin_2.size(1));
  loop_ub = varargin_2.size(1);
  for (int i1{0}; i1 < loop_ub; i1++) {
    b_varargin_2[i1] = varargin_2[i1];
  }
  b_input_sizes_idx_0 = static_cast<int>(varargin_2.size(1) != 0);
  result.set_size((static_cast<int>(input_sizes_idx_0)) + 3, 3);
  b_loop_ub = static_cast<int>(input_sizes_idx_0);
  for (int i2{0}; i2 < 3; i2++) {
    result[result.size(0) * i2] = varargin_1[i2][0];
    result[(result.size(0) * i2) + 1] = varargin_1[i2][1];
    result[(result.size(0) * i2) + 2] = varargin_1[i2][2];
    for (int i3{0}; i3 < b_loop_ub; i3++) {
      result[(result.size(0) * i2) + 3] =
          b_varargin_2[b_input_sizes_idx_0 * i2];
    }
  }
  m = result.size(0);
  cameraMatrix.set_size(result.size(0), 3);
  for (int j{0}; j < 3; j++) {
    for (int c_i{0}; c_i < m; c_i++) {
      cameraMatrix[c_i + (cameraMatrix.size(0) * j)] =
          ((result[c_i] * h_K[j][0]) +
           (result[c_i + result.size(0)] * h_K[j][1])) +
          (result[c_i + (result.size(0) * 2)] * h_K[j][2]);
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
  c_result.set_size(b_result, input_sizes_idx_1 +
                                  (static_cast<int>(b_input_sizes_idx_1)));
  for (int i4{0}; i4 < input_sizes_idx_1; i4++) {
    for (int i5{0}; i5 < b_result; i5++) {
      c_result[i5 + (c_result.size(0) * i4)] = varargin_3[i5 + (b_result * i4)];
    }
  }
  c_loop_ub = static_cast<int>(b_input_sizes_idx_1);
  for (int i6{0}; i6 < c_loop_ub; i6++) {
    for (int i7{0}; i7 < b_result; i7++) {
      c_result[i7 + (c_result.size(0) * input_sizes_idx_1)] = 1.0;
    }
  }
  mc = c_result.size(0) - 1;
  inner = c_result.size(1);
  projectedPoints.set_size(c_result.size(0), 3);
  for (int b_j{0}; b_j < 3; b_j++) {
    for (int d_i{0}; d_i <= mc; d_i++) {
      projectedPoints[d_i + (projectedPoints.size(0) * b_j)] = 0.0;
    }
    for (int k{0}; k < inner; k++) {
      double bkj;
      bkj = cameraMatrix[k + (cameraMatrix.size(0) * b_j)];
      for (int e_i{0}; e_i <= mc; e_i++) {
        projectedPoints[e_i + (projectedPoints.size(0) * b_j)] =
            projectedPoints[e_i + (projectedPoints.size(0) * b_j)] +
            (c_result[e_i + (c_result.size(0) * k)] * bkj);
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
    for (int b_k{0}; b_k < 2; b_k++) {
      int i9;
      i9 = imagePointsTmp.size(0) - 1;
      for (int c_k{0}; c_k <= i9; c_k++) {
        imagePointsTmp[c_k + (imagePointsTmp.size(0) * b_k)] =
            projectedPoints[(acoef * c_k) + (projectedPoints.size(0) * b_k)] /
            projectedPoints[(bcoef * c_k) + (projectedPoints.size(0) * 2)];
      }
    }
  }
  if (h_K[0][1] != 0.0) {
    int b_imagePointsTmp;
    int d_loop_ub;
    b_imagePointsTmp = imagePointsTmp.size(0) - 1;
    c_imagePointsTmp.set_size(imagePointsTmp.size(0));
    for (int i8{0}; i8 <= b_imagePointsTmp; i8++) {
      c_imagePointsTmp[i8] =
          imagePointsTmp[i8] -
          ((h_K[0][1] *
            (imagePointsTmp[i8 + imagePointsTmp.size(0)] - h_K[1][2])) /
           h_K[1][1]);
    }
    d_loop_ub = c_imagePointsTmp.size(0);
    for (int i10{0}; i10 < d_loop_ub; i10++) {
      imagePointsTmp[i10] = c_imagePointsTmp[i10];
    }
  }
  b[0] = h_K[0][2];
  b[1] = h_K[1][2];
  centeredPoints.set_size(imagePointsTmp.size(0), 2);
  if (imagePointsTmp.size(0) != 0) {
    int b_acoef;
    b_acoef = static_cast<int>(imagePointsTmp.size(0) != 1);
    for (int d_k{0}; d_k < 2; d_k++) {
      int i12;
      i12 = centeredPoints.size(0) - 1;
      for (int e_k{0}; e_k <= i12; e_k++) {
        centeredPoints[e_k + (centeredPoints.size(0) * d_k)] =
            imagePointsTmp[(b_acoef * e_k) + (imagePointsTmp.size(0) * d_k)] -
            b[d_k];
      }
    }
  }
  e_loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  for (int i11{0}; i11 < e_loop_ub; i11++) {
    yNorm[i11] = centeredPoints[i11 + centeredPoints.size(0)] / h_K[1][1];
  }
  f_loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  for (int i13{0}; i13 < f_loop_ub; i13++) {
    xNorm[i13] = centeredPoints[i13] / h_K[0][0];
  }
  z1.set_size(xNorm.size(0));
  m_N = xNorm.size(0);
  for (int f_k{0}; f_k < m_N; f_k++) {
    z1[f_k] = rt_powd_snf(xNorm[f_k], 2.0);
  }
  b_z1.set_size(yNorm.size(0));
  o_N = yNorm.size(0);
  for (int g_k{0}; g_k < o_N; g_k++) {
    b_z1[g_k] = rt_powd_snf(yNorm[g_k], 2.0);
  }
  r2.set_size(z1.size(0));
  g_loop_ub = z1.size(0);
  for (int i14{0}; i14 < g_loop_ub; i14++) {
    r2[i14] = z1[i14] + b_z1[i14];
  }
  r4.set_size(r2.size(0));
  h_loop_ub = r2.size(0);
  for (int i15{0}; i15 < h_loop_ub; i15++) {
    r4[i15] = r2[i15] * r2[i15];
  }
  k_idx_0 = intrinsics->RadialDistortion[0];
  k_idx_1 = intrinsics->RadialDistortion[1];
  if (intrinsics->RadialDistortion.size(1) < 3) {
    k_idx_2 = 0.0;
  } else {
    k_idx_2 = intrinsics->RadialDistortion[2];
  }
  alpha.set_size(r2.size(0));
  i_loop_ub = r2.size(0);
  for (int i16{0}; i16 < i_loop_ub; i16++) {
    alpha[i16] = ((k_idx_0 * r2[i16]) + (k_idx_1 * r4[i16])) +
                 (k_idx_2 * (r2[i16] * r4[i16]));
  }
  xyProduct.set_size(xNorm.size(0));
  j_loop_ub = xNorm.size(0);
  for (int i17{0}; i17 < j_loop_ub; i17++) {
    xyProduct[i17] = xNorm[i17] * yNorm[i17];
  }
  b_b.set_size(xNorm.size(0));
  z1.set_size(xNorm.size(0));
  k_loop_ub = xNorm.size(0);
  for (int i18{0}; i18 < k_loop_ub; i18++) {
    z1[i18] = b_b[i18];
  }
  p_N = xNorm.size(0);
  for (int i_k{0}; i_k < p_N; i_k++) {
    z1[i_k] = rt_powd_snf(xNorm[i_k], 2.0);
  }
  b_a = 2.0 * intrinsics->TangentialDistortion[0];
  f_b.set_size(yNorm.size(0));
  b_z1.set_size(yNorm.size(0));
  m_loop_ub = yNorm.size(0);
  for (int i19{0}; i19 < m_loop_ub; i19++) {
    b_z1[i19] = f_b[i19];
  }
  q_N = yNorm.size(0);
  for (int j_k{0}; j_k < q_N; j_k++) {
    b_z1[j_k] = rt_powd_snf(yNorm[j_k], 2.0);
  }
  c_a = 2.0 * intrinsics->TangentialDistortion[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  o_loop_ub = xNorm.size(0);
  for (int i20{0}; i20 < o_loop_ub; i20++) {
    normalizedPoints[i20] = xNorm[i20];
  }
  p_loop_ub = yNorm.size(0);
  for (int i21{0}; i21 < p_loop_ub; i21++) {
    normalizedPoints[i21 + normalizedPoints.size(0)] = yNorm[i21];
  }
  b_intrinsics = intrinsics->TangentialDistortion[1];
  c_intrinsics = intrinsics->TangentialDistortion[0];
  b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
  q_loop_ub = normalizedPoints.size(0);
  for (int i22{0}; i22 < q_loop_ub; i22++) {
    double d;
    d = normalizedPoints[i22];
    b_normalizedPoints[i22] = d + (d * alpha[i22]);
  }
  r_loop_ub = normalizedPoints.size(0);
  for (int i23{0}; i23 < r_loop_ub; i23++) {
    double b_d1;
    b_d1 = normalizedPoints[i23 + normalizedPoints.size(0)];
    b_normalizedPoints[i23 + b_normalizedPoints.size(0)] =
        b_d1 + (b_d1 * alpha[i23]);
  }
  d_a.set_size(xyProduct.size(0), 2);
  s_loop_ub = xyProduct.size(0);
  for (int i24{0}; i24 < s_loop_ub; i24++) {
    d_a[i24] =
        (b_a * xyProduct[i24]) + (b_intrinsics * (r2[i24] + (2.0 * z1[i24])));
  }
  t_loop_ub = r2.size(0);
  for (int i25{0}; i25 < t_loop_ub; i25++) {
    d_a[i25 + d_a.size(0)] =
        (c_intrinsics * (r2[i25] + (2.0 * b_z1[i25]))) + (c_a * xyProduct[i25]);
  }
  distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
  u_loop_ub = b_normalizedPoints.size(0);
  for (int i26{0}; i26 < 2; i26++) {
    for (int i27{0}; i27 < u_loop_ub; i27++) {
      distortedNormalizedPoints[i27 +
                                (distortedNormalizedPoints.size(0) * i26)] =
          b_normalizedPoints[i27 + (b_normalizedPoints.size(0) * i26)] +
          d_a[i27 + (d_a.size(0) * i26)];
    }
  }
  v_loop_ub = distortedNormalizedPoints.size(0);
  w_loop_ub = distortedNormalizedPoints.size(0);
  varargout_1.set_size(distortedNormalizedPoints.size(0), 2);
  for (int i28{0}; i28 < v_loop_ub; i28++) {
    varargout_1[i28] =
        ((distortedNormalizedPoints[i28] * h_K[0][0]) + h_K[0][2]) +
        (h_K[0][1] *
         distortedNormalizedPoints[i28 + distortedNormalizedPoints.size(0)]);
  }
  for (int i29{0}; i29 < w_loop_ub; i29++) {
    varargout_1[i29 + varargout_1.size(0)] =
        (distortedNormalizedPoints[i29 + distortedNormalizedPoints.size(0)] *
         h_K[1][1]) +
        h_K[1][2];
  }
}

} // namespace coder

//
// File trailer for worldToImage.cpp
//
// [EOF]
//
