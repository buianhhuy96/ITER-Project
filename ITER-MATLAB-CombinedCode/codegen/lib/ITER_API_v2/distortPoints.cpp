//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: distortPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "distortPoints.h"
#include "ITER_API_v2_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_points
//                const double b_intrinsicMatrix[3][3]
//                const double b_radialDistortion[3]
//                const double b_tangentialDistortion[2]
//                ::coder::array<double, 2U> &distortedPoints
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void distortPoints(const ::coder::array<double, 2U> &b_points,
                   const double b_intrinsicMatrix[3][3],
                   const double b_radialDistortion[3],
                   const double b_tangentialDistortion[2],
                   ::coder::array<double, 2U> &distortedPoints)
{
  array<double, 2U> b_normalizedPoints;
  array<double, 2U> c_a;
  array<double, 2U> centeredPoints;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> normalizedPoints;
  array<double, 1U> alpha;
  array<double, 1U> b;
  array<double, 1U> b_b;
  array<double, 1U> b_xNorm;
  array<double, 1U> b_z1;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  array<double, 1U> z1;
  double center[2];
  double a;
  double b_a;
  double k_idx_0;
  double k_idx_1;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m_N;
  int m_loop_ub;
  int o_N;
  int o_loop_ub;
  int p_N;
  int p_loop_ub;
  int q_N;
  int q_loop_ub;
  int r_loop_ub;
  int s_loop_ub;
  center[0] = b_intrinsicMatrix[0][2];
  center[1] = b_intrinsicMatrix[1][2];
  centeredPoints.set_size(b_points.size(0), 2);
  if (b_points.size(0) != 0) {
    int acoef;
    acoef = static_cast<int>(b_points.size(0) != 1);
    for (int k{0}; k < 2; k++) {
      int i1;
      i1 = centeredPoints.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        centeredPoints[b_k + (centeredPoints.size(0) * k)] =
            b_points[(acoef * b_k) + (b_points.size(0) * k)] - center[k];
      }
    }
  }
  loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    yNorm[b_i] =
        centeredPoints[b_i + centeredPoints.size(0)] / b_intrinsicMatrix[1][1];
  }
  b_loop_ub = centeredPoints.size(0);
  b_xNorm.set_size(centeredPoints.size(0));
  for (int i2{0}; i2 < b_loop_ub; i2++) {
    b_xNorm[i2] = centeredPoints[i2] / b_intrinsicMatrix[0][0];
  }
  z1.set_size(b_xNorm.size(0));
  m_N = b_xNorm.size(0);
  for (int c_k{0}; c_k < m_N; c_k++) {
    z1[c_k] = rt_powd_snf(b_xNorm[c_k], 2.0);
  }
  b_z1.set_size(yNorm.size(0));
  o_N = yNorm.size(0);
  for (int d_k{0}; d_k < o_N; d_k++) {
    b_z1[d_k] = rt_powd_snf(yNorm[d_k], 2.0);
  }
  r2.set_size(z1.size(0));
  c_loop_ub = z1.size(0);
  for (int i3{0}; i3 < c_loop_ub; i3++) {
    r2[i3] = z1[i3] + b_z1[i3];
  }
  r4.set_size(r2.size(0));
  d_loop_ub = r2.size(0);
  for (int i4{0}; i4 < d_loop_ub; i4++) {
    r4[i4] = r2[i4] * r2[i4];
  }
  k_idx_0 = b_radialDistortion[0];
  k_idx_1 = b_radialDistortion[1];
  alpha.set_size(r2.size(0));
  e_loop_ub = r2.size(0);
  for (int i5{0}; i5 < e_loop_ub; i5++) {
    alpha[i5] = ((k_idx_0 * r2[i5]) + (k_idx_1 * r4[i5])) +
                (b_radialDistortion[2] * (r2[i5] * r4[i5]));
  }
  xyProduct.set_size(b_xNorm.size(0));
  f_loop_ub = b_xNorm.size(0);
  for (int i6{0}; i6 < f_loop_ub; i6++) {
    xyProduct[i6] = b_xNorm[i6] * yNorm[i6];
  }
  b.set_size(b_xNorm.size(0));
  z1.set_size(b_xNorm.size(0));
  g_loop_ub = b_xNorm.size(0);
  for (int i7{0}; i7 < g_loop_ub; i7++) {
    z1[i7] = b[i7];
  }
  p_N = b_xNorm.size(0);
  for (int e_k{0}; e_k < p_N; e_k++) {
    z1[e_k] = rt_powd_snf(b_xNorm[e_k], 2.0);
  }
  a = 2.0 * b_tangentialDistortion[0];
  b_b.set_size(yNorm.size(0));
  b_z1.set_size(yNorm.size(0));
  h_loop_ub = yNorm.size(0);
  for (int i8{0}; i8 < h_loop_ub; i8++) {
    b_z1[i8] = b_b[i8];
  }
  q_N = yNorm.size(0);
  for (int f_k{0}; f_k < q_N; f_k++) {
    b_z1[f_k] = rt_powd_snf(yNorm[f_k], 2.0);
  }
  b_a = 2.0 * b_tangentialDistortion[1];
  normalizedPoints.set_size(b_xNorm.size(0), 2);
  i_loop_ub = b_xNorm.size(0);
  for (int i9{0}; i9 < i_loop_ub; i9++) {
    normalizedPoints[i9] = b_xNorm[i9];
  }
  j_loop_ub = yNorm.size(0);
  for (int i10{0}; i10 < j_loop_ub; i10++) {
    normalizedPoints[i10 + normalizedPoints.size(0)] = yNorm[i10];
  }
  b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
  k_loop_ub = normalizedPoints.size(0);
  for (int i11{0}; i11 < k_loop_ub; i11++) {
    double d;
    d = normalizedPoints[i11];
    b_normalizedPoints[i11] = d + (d * alpha[i11]);
  }
  m_loop_ub = normalizedPoints.size(0);
  for (int i12{0}; i12 < m_loop_ub; i12++) {
    double b_d1;
    b_d1 = normalizedPoints[i12 + normalizedPoints.size(0)];
    b_normalizedPoints[i12 + b_normalizedPoints.size(0)] =
        b_d1 + (b_d1 * alpha[i12]);
  }
  c_a.set_size(xyProduct.size(0), 2);
  o_loop_ub = xyProduct.size(0);
  for (int i13{0}; i13 < o_loop_ub; i13++) {
    c_a[i13] = (a * xyProduct[i13]) +
               (b_tangentialDistortion[1] * (r2[i13] + (2.0 * z1[i13])));
  }
  p_loop_ub = r2.size(0);
  for (int i14{0}; i14 < p_loop_ub; i14++) {
    c_a[i14 + c_a.size(0)] =
        (b_tangentialDistortion[0] * (r2[i14] + (2.0 * b_z1[i14]))) +
        (b_a * xyProduct[i14]);
  }
  distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
  q_loop_ub = b_normalizedPoints.size(0);
  for (int i15{0}; i15 < 2; i15++) {
    for (int i16{0}; i16 < q_loop_ub; i16++) {
      distortedNormalizedPoints[i16 +
                                (distortedNormalizedPoints.size(0) * i15)] =
          b_normalizedPoints[i16 + (b_normalizedPoints.size(0) * i15)] +
          c_a[i16 + (c_a.size(0) * i15)];
    }
  }
  r_loop_ub = distortedNormalizedPoints.size(0);
  s_loop_ub = distortedNormalizedPoints.size(0);
  distortedPoints.set_size(distortedNormalizedPoints.size(0), 2);
  for (int i17{0}; i17 < r_loop_ub; i17++) {
    distortedPoints[i17] =
        ((distortedNormalizedPoints[i17] * b_intrinsicMatrix[0][0]) +
         b_intrinsicMatrix[0][2]) +
        (b_intrinsicMatrix[0][1] *
         distortedNormalizedPoints[i17 + distortedNormalizedPoints.size(0)]);
  }
  for (int i18{0}; i18 < s_loop_ub; i18++) {
    distortedPoints[i18 + distortedPoints.size(0)] =
        (distortedNormalizedPoints[i18 + distortedNormalizedPoints.size(0)] *
         b_intrinsicMatrix[1][1]) +
        b_intrinsicMatrix[1][2];
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for distortPoints.cpp
//
// [EOF]
//
