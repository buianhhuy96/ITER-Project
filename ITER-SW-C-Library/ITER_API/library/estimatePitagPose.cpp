//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: estimatePitagPose.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "estimatePitagPose.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types1.h"
#include "ITER_API_types.h"
#include "anonymous_function.h"
#include "cameraParameters.h"
#include "fmincon.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "quat2rotm.h"
#include "rank.h"
#include "rotm2quat.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// initialize
//
// Arguments    : const ::coder::array<double, 2U> &b_imagePoints
//                const double b_robotpose[4][4]
//                const ::coder::array<double, 2U> &b_worldpts
//                const double handeye[4][4]
//                const struct1_T *cameraParams
//                double poseCamera[4][4]
//                double poseRobot[4][4]
// Return Type  : void
//
namespace ITER {
void estimatePitagPose(const ::coder::array<double, 2U> &b_imagePoints,
                       const double b_robotpose[4][4],
                       const ::coder::array<double, 2U> &b_worldpts,
                       const double handeye[4][4],
                       const struct1_T *cameraParams, double poseCamera[4][4],
                       double poseRobot[4][4])
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::b_anonymous_function b_cF1;
  coder::cameraParameters b_cameraParams;
  ::coder::array<double, 2U> d_X;
  ::coder::array<double, 2U> uv;
  ::coder::array<double, 2U> validWorldPoints;
  ::coder::array<double, 2U> xy;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_u;
  ::coder::array<double, 1U> d_u;
  ::coder::array<double, 1U> e_v;
  ::coder::array<double, 1U> r2;
  ::coder::array<double, 1U> r3;
  ::coder::array<double, 1U> y;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<signed char, 2U> varargin_2;
  ::coder::array<bool, 1U> validPoints;
  double c_robotpose[4][4];
  double init[4][4];
  double A[3][3];
  double H[3][3];
  double T[3][3];
  double Tvec[9];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_Tvec[3][3];
  double b_U[3][3];
  double b_dv[3][3];
  double b_dv1[3][3];
  double b_init[3][3];
  double c_r1[3][3];
  double f_K[3][3];
  double intrinsics[3][3];
  double normMatrix1[3][3];
  double normMatrix2[3][3];
  double x0[7];
  double x1[7];
  double dv3[4];
  double b_dv2[3];
  double b_lambda[3];
  double b_r1[3];
  double b_r2[3];
  double e_x[3];
  double absxk;
  double b_d1;
  double b_t;
  double b_y;
  double c_T;
  double d;
  double d2;
  double d3;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double lambda;
  double scale;
  int ab_loop_ub;
  int b_end;
  int b_hi;
  int b_loop_ub;
  int b_partialTrueCount;
  int b_trueCount;
  int b_xy_idx_0;
  int bb_loop_ub;
  int c_loop_ub;
  int c_xy_idx_0;
  int cb_loop_ub;
  int d_loop_ub;
  int d_t;
  int d_xy_idx_0;
  int db_loop_ub;
  int e_loop_ub;
  int e_xy_idx_0;
  int eb_loop_ub;
  int end;
  int f_loop_ub;
  int f_xy_idx_0;
  int fb_loop_ub;
  int g_loop_ub;
  int g_xy_idx_0;
  int gb_loop_ub;
  int h_loop_ub;
  int h_xy_idx_0;
  int hb_loop_ub;
  int i34;
  int i37;
  int i4;
  int i52;
  int i53;
  int i54;
  int i55;
  int i_loop_ub;
  int j_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int m_loop_ub;
  int o_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int q_loop_ub;
  int r_loop_ub;
  int result;
  int s_loop_ub;
  int t_loop_ub;
  int trueCount;
  int u_loop_ub;
  int v_loop_ub;
  int w_loop_ub;
  int x_loop_ub;
  int xy_idx_0;
  int y_loop_ub;
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  validPoints.set_size(b_imagePoints.size(0));
  loop_ub = b_imagePoints.size(0);
  if ((static_cast<int>(b_imagePoints.size(0) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      validPoints[b_i] = false;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      validPoints[b_i] = false;
    }
  }
  b_hi = b_imagePoints.size(0);
  for (int k{0}; k < b_hi; k++) {
    int b_k;
    bool exitg1;
    validPoints[k] = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 2)) {
      if (b_imagePoints[k + (b_imagePoints.size(0) * b_k)] == 0.0) {
        b_k++;
      } else if (std::isnan(b_imagePoints[k + (b_imagePoints.size(0) * b_k)])) {
        b_k++;
      } else {
        validPoints[k] = true;
        exitg1 = true;
      }
    }
  }
  end = validPoints.size(0) - 1;
  trueCount = 0;
  for (int c_i{0}; c_i <= end; c_i++) {
    if (validPoints[c_i]) {
      trueCount++;
    }
  }
  r.set_size(trueCount);
  partialTrueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    if (validPoints[d_i]) {
      r[partialTrueCount] = d_i + 1;
      partialTrueCount++;
    }
  }
  b_cF1.workspace.undist_imgMarkerPts.set_size(r.size(0), 2);
  b_loop_ub = r.size(0);
  for (int i1{0}; i1 < 2; i1++) {
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      b_cF1.workspace.undist_imgMarkerPts
          [i2 + (b_cF1.workspace.undist_imgMarkerPts.size(0) * i1)] =
          b_imagePoints[(r[i2] + (b_imagePoints.size(0) * i1)) - 1];
    }
  }
  b_end = validPoints.size(0) - 1;
  b_trueCount = 0;
  for (int e_i{0}; e_i <= b_end; e_i++) {
    if (validPoints[e_i]) {
      b_trueCount++;
    }
  }
  r1.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int g_i{0}; g_i <= b_end; g_i++) {
    if (validPoints[g_i]) {
      r1[b_partialTrueCount] = g_i + 1;
      b_partialTrueCount++;
    }
  }
  validWorldPoints.set_size(r1.size(0), 2);
  c_loop_ub = r1.size(0);
  if ((static_cast<int>((r1.size(0) * 2) < 4)) != 0) {
    for (int i3{0}; i3 < 2; i3++) {
      for (i4 = 0; i4 < c_loop_ub; i4++) {
        validWorldPoints[i4 + (validWorldPoints.size(0) * i3)] =
            b_worldpts[(r1[i4] + (b_worldpts.size(0) * i3)) - 1];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int i3 = 0; i3 < 2; i3++) {
      for (i4 = 0; i4 < c_loop_ub; i4++) {
        validWorldPoints[i4 + (validWorldPoints.size(0) * i3)] =
            b_worldpts[(r1[i4] + (b_worldpts.size(0) * i3)) - 1];
      }
    }
  }
  (void)b_cameraParams.b_init(
      cameraParams->RadialDistortion, cameraParams->TangentialDistortion,
      cameraParams->ImageSize, cameraParams->WorldUnits,
      cameraParams->EstimateSkew, cameraParams->NumRadialDistortionCoefficients,
      cameraParams->EstimateTangentialDistortion,
      cameraParams->IntrinsicMatrix);
  //  Estimate extrinsics and optimise results per sample
  // compute the extrinsic
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i5 = 0; i5 < 3; i5++) {
    intrinsics[i5][0] = b_cameraParams.IntrinsicMatrixInternal[0][i5];
    intrinsics[i5][1] = b_cameraParams.IntrinsicMatrixInternal[1][i5];
    intrinsics[i5][2] = b_cameraParams.IntrinsicMatrixInternal[2][i5];
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i6 = 0; i6 < 3; i6++) {
    A[i6][0] = intrinsics[0][i6];
    A[i6][1] = intrinsics[1][i6];
    A[i6][2] = intrinsics[2][i6];
  }
  coder::images::geotrans::internal::b_normalizeControlPoints(validWorldPoints,
                                                              uv, normMatrix1);
  coder::images::geotrans::internal::b_normalizeControlPoints(
      b_cF1.workspace.undist_imgMarkerPts, xy, normMatrix2);
  d_loop_ub = xy.size(0);
  b_x.set_size(xy.size(0));
  e_loop_ub = xy.size(0);
  if ((static_cast<int>(xy.size(0) < 4)) != 0) {
    for (int i7{0}; i7 < d_loop_ub; i7++) {
      b_x[i7] = xy[i7];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < e_loop_ub; i7++) {
      b_x[i7] = xy[i7];
    }
  }
  f_loop_ub = xy.size(0);
  y.set_size(xy.size(0));
  g_loop_ub = xy.size(0);
  if ((static_cast<int>(xy.size(0) < 4)) != 0) {
    for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
      y[b_i8] = xy[b_i8 + xy.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < g_loop_ub; b_i8++) {
      y[b_i8] = xy[b_i8 + xy.size(0)];
    }
  }
  h_loop_ub = uv.size(0);
  c_u.set_size(uv.size(0));
  i_loop_ub = uv.size(0);
  if ((static_cast<int>(uv.size(0) < 4)) != 0) {
    for (int i9{0}; i9 < h_loop_ub; i9++) {
      c_u[i9] = uv[i9];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i9 = 0; i9 < i_loop_ub; i9++) {
      c_u[i9] = uv[i9];
    }
  }
  j_loop_ub = uv.size(0);
  e_v.set_size(uv.size(0));
  k_loop_ub = uv.size(0);
  if ((static_cast<int>(uv.size(0) < 4)) != 0) {
    for (int i10{0}; i10 < j_loop_ub; i10++) {
      e_v[i10] = uv[i10 + uv.size(0)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i10 = 0; i10 < k_loop_ub; i10++) {
      e_v[i10] = uv[i10 + uv.size(0)];
    }
  }
  r2.set_size(c_u.size(0));
  m_loop_ub = c_u.size(0);
  if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
    for (int i11{0}; i11 < m_loop_ub; i11++) {
      r2[i11] = -c_u[i11];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i11 = 0; i11 < m_loop_ub; i11++) {
      r2[i11] = -c_u[i11];
    }
  }
  r3.set_size(e_v.size(0));
  o_loop_ub = e_v.size(0);
  if ((static_cast<int>(e_v.size(0) < 4)) != 0) {
    for (int i12{0}; i12 < o_loop_ub; i12++) {
      r3[i12] = -e_v[i12];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i12 = 0; i12 < o_loop_ub; i12++) {
      r3[i12] = -e_v[i12];
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
  p_loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int i13{0}; i13 < p_loop_ub; i13++) {
      d_X[i13] = b_x[i13];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i13 = 0; i13 < p_loop_ub; i13++) {
      d_X[i13] = b_x[i13];
    }
  }
  q_loop_ub = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int i14{0}; i14 < q_loop_ub; i14++) {
      d_X[i14 + d_X.size(0)] = y[i14];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < q_loop_ub; i14++) {
      d_X[i14 + d_X.size(0)] = y[i14];
    }
  }
  r_loop_ub = xy_idx_0;
  if ((static_cast<int>(xy_idx_0 < 4)) != 0) {
    for (int i15{0}; i15 < xy_idx_0; i15++) {
      d_X[i15 + (d_X.size(0) * 2)] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i15 = 0; i15 < r_loop_ub; i15++) {
      d_X[i15 + (d_X.size(0) * 2)] = 1.0;
    }
  }
  s_loop_ub = b_xy_idx_0;
  if ((static_cast<int>(b_xy_idx_0 < 4)) != 0) {
    for (int i16{0}; i16 < b_xy_idx_0; i16++) {
      d_X[i16 + (d_X.size(0) * 3)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i16 = 0; i16 < s_loop_ub; i16++) {
      d_X[i16 + (d_X.size(0) * 3)] = 0.0;
    }
  }
  t_loop_ub = c_xy_idx_0;
  if ((static_cast<int>(c_xy_idx_0 < 4)) != 0) {
    for (int i17{0}; i17 < c_xy_idx_0; i17++) {
      d_X[i17 + (d_X.size(0) * 4)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i17 = 0; i17 < t_loop_ub; i17++) {
      d_X[i17 + (d_X.size(0) * 4)] = 0.0;
    }
  }
  u_loop_ub = d_xy_idx_0;
  if ((static_cast<int>(d_xy_idx_0 < 4)) != 0) {
    for (int i18{0}; i18 < d_xy_idx_0; i18++) {
      d_X[i18 + (d_X.size(0) * 5)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i18 = 0; i18 < u_loop_ub; i18++) {
      d_X[i18 + (d_X.size(0) * 5)] = 0.0;
    }
  }
  v_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i19{0}; i19 < v_loop_ub; i19++) {
      d_X[i19 + (d_X.size(0) * 6)] = r2[i19] * b_x[i19];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i19 = 0; i19 < v_loop_ub; i19++) {
      d_X[i19 + (d_X.size(0) * 6)] = r2[i19] * b_x[i19];
    }
  }
  w_loop_ub = r2.size(0);
  if ((static_cast<int>(r2.size(0) < 4)) != 0) {
    for (int i20{0}; i20 < w_loop_ub; i20++) {
      d_X[i20 + (d_X.size(0) * 7)] = r2[i20] * y[i20];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i20 = 0; i20 < w_loop_ub; i20++) {
      d_X[i20 + (d_X.size(0) * 7)] = r2[i20] * y[i20];
    }
  }
  x_loop_ub = e_xy_idx_0;
  if ((static_cast<int>(e_xy_idx_0 < 4)) != 0) {
    for (int i21{0}; i21 < e_xy_idx_0; i21++) {
      d_X[i21 + b_x.size(0)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i21 = 0; i21 < x_loop_ub; i21++) {
      d_X[i21 + b_x.size(0)] = 0.0;
    }
  }
  y_loop_ub = f_xy_idx_0;
  if ((static_cast<int>(f_xy_idx_0 < 4)) != 0) {
    for (int i22{0}; i22 < f_xy_idx_0; i22++) {
      d_X[(i22 + b_x.size(0)) + d_X.size(0)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i22 = 0; i22 < y_loop_ub; i22++) {
      d_X[(i22 + b_x.size(0)) + d_X.size(0)] = 0.0;
    }
  }
  ab_loop_ub = g_xy_idx_0;
  if ((static_cast<int>(g_xy_idx_0 < 4)) != 0) {
    for (int i23{0}; i23 < g_xy_idx_0; i23++) {
      d_X[(i23 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i23 = 0; i23 < ab_loop_ub; i23++) {
      d_X[(i23 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
    }
  }
  bb_loop_ub = b_x.size(0);
  if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
    for (int i24{0}; i24 < bb_loop_ub; i24++) {
      d_X[(i24 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i24];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i24 = 0; i24 < bb_loop_ub; i24++) {
      d_X[(i24 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i24];
    }
  }
  cb_loop_ub = y.size(0);
  if ((static_cast<int>(y.size(0) < 4)) != 0) {
    for (int i25{0}; i25 < cb_loop_ub; i25++) {
      d_X[(i25 + b_x.size(0)) + (d_X.size(0) * 4)] = y[i25];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i25 = 0; i25 < cb_loop_ub; i25++) {
      d_X[(i25 + b_x.size(0)) + (d_X.size(0) * 4)] = y[i25];
    }
  }
  db_loop_ub = h_xy_idx_0;
  if ((static_cast<int>(h_xy_idx_0 < 4)) != 0) {
    for (int i26{0}; i26 < h_xy_idx_0; i26++) {
      d_X[(i26 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i26 = 0; i26 < db_loop_ub; i26++) {
      d_X[(i26 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
    }
  }
  eb_loop_ub = r3.size(0);
  if ((static_cast<int>(r3.size(0) < 4)) != 0) {
    for (int i27{0}; i27 < eb_loop_ub; i27++) {
      d_X[(i27 + b_x.size(0)) + (d_X.size(0) * 6)] = r3[i27] * b_x[i27];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i27 = 0; i27 < eb_loop_ub; i27++) {
      d_X[(i27 + b_x.size(0)) + (d_X.size(0) * 6)] = r3[i27] * b_x[i27];
    }
  }
  fb_loop_ub = r3.size(0);
  if ((static_cast<int>(r3.size(0) < 4)) != 0) {
    for (int i28{0}; i28 < fb_loop_ub; i28++) {
      d_X[(i28 + b_x.size(0)) + (d_X.size(0) * 7)] = r3[i28] * y[i28];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i28 = 0; i28 < fb_loop_ub; i28++) {
      d_X[(i28 + b_x.size(0)) + (d_X.size(0) * 7)] = r3[i28] * y[i28];
    }
  }
  (void)coder::local_rank(d_X);
  d_u.set_size(c_u.size(0) + e_v.size(0));
  gb_loop_ub = c_u.size(0);
  if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
    for (int i29{0}; i29 < gb_loop_ub; i29++) {
      d_u[i29] = c_u[i29];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i29 = 0; i29 < gb_loop_ub; i29++) {
      d_u[i29] = c_u[i29];
    }
  }
  hb_loop_ub = e_v.size(0);
  if ((static_cast<int>(e_v.size(0) < 4)) != 0) {
    for (int i30{0}; i30 < hb_loop_ub; i30++) {
      d_u[i30 + c_u.size(0)] = e_v[i30];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i30 = 0; i30 < hb_loop_ub; i30++) {
      d_u[i30 + c_u.size(0)] = e_v[i30];
    }
  }
  coder::mldivide(d_X, d_u, r2);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i31 = 0; i31 < 8; i31++) {
    Tvec[i31] = r2[i31];
  }
  Tvec[8] = 1.0;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d, i34, b_d1, d2, d3)

  for (int i32 = 0; i32 < 3; i32++) {
    b_d1 = Tvec[i32];
    d2 = Tvec[i32 + 3];
    d3 = Tvec[i32 + 6];
    for (i34 = 0; i34 < 3; i34++) {
      d = ((b_d1 * normMatrix1[i34][0]) + (d2 * normMatrix1[i34][1])) +
          (d3 * normMatrix1[i34][2]);
      b_Tvec[i34][i32] = d;
    }
  }
  coder::b_mldivide(normMatrix2, b_Tvec, b_dv);
  coder::inv(b_dv, T);
  c_T = T[2][2];
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i33 = 0; i33 < 3; i33++) {
    T[i33][0] /= c_T;
    T[i33][1] /= c_T;
    T[i33][2] /= c_T;
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i35 = 0; i35 < 3; i35++) {
    H[i35][0] = T[0][i35];
    H[i35][1] = T[1][i35];
    H[i35][2] = T[2][i35];
  }
  coder::c_mldivide(A, *((double(*)[3])(&H[0][0])), e_x);
  scale = 3.3121686421112381E-170;
  absxk = std::abs(e_x[0]);
  if (absxk > 3.3121686421112381E-170) {
    b_y = 1.0;
    scale = absxk;
  } else {
    b_t = absxk / 3.3121686421112381E-170;
    b_y = b_t * b_t;
  }
  absxk = std::abs(e_x[1]);
  if (absxk > scale) {
    b_t = scale / absxk;
    b_y = ((b_y * b_t) * b_t) + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    b_y += b_t * b_t;
  }
  absxk = std::abs(e_x[2]);
  if (absxk > scale) {
    b_t = scale / absxk;
    b_y = ((b_y * b_t) * b_t) + 1.0;
    scale = absxk;
  } else {
    b_t = absxk / scale;
    b_y += b_t * b_t;
  }
  b_y = scale * std::sqrt(b_y);
  lambda = 1.0 / b_y;
  b_lambda[0] = lambda * H[0][0];
  b_lambda[1] = lambda * H[0][1];
  b_lambda[2] = lambda * H[0][2];
  coder::c_mldivide(A, b_lambda, b_r1);
  b_lambda[0] = lambda * H[1][0];
  b_lambda[1] = lambda * H[1][1];
  b_lambda[2] = lambda * H[1][2];
  coder::c_mldivide(A, b_lambda, b_r2);
  c_r1[0][0] = b_r1[0];
  c_r1[0][1] = b_r2[0];
  c_r1[1][0] = b_r1[1];
  c_r1[1][1] = b_r2[1];
  c_r1[2][0] = b_r1[2];
  c_r1[2][1] = b_r2[2];
  c_r1[0][2] = (b_r1[1] * b_r2[2]) - (b_r2[1] * b_r1[2]);
  c_r1[1][2] = (b_r2[0] * b_r1[2]) - (b_r1[0] * b_r2[2]);
  c_r1[2][2] = (b_r1[0] * b_r2[1]) - (b_r2[0] * b_r1[1]);
  coder::b_svd(c_r1, U, a__1, V);
  //  Optimize the extrinsic
  // RT2TR Convert rotation and translation to homogeneous transform
  // NOTE:  RT"TR change to createHT
  //  TR = RT2TR(R, t) is a homogeneous transformation matrix (N+1xN+1) formed
  //  from an orthonormal rotation matrix R (NxN) and a translation vector t
  //  (Nx1).  Works for R in SO(2) or SO(3):
  //   - If R is 2x2 and t is 2x1, then TR is 3x3
  //   - If R is 3x3 and t is 3x1, then TR is 4x4
  //
  //  For a sequence R (NxNxK) and t (NxK) results in a transform sequence
  //  (N+1xN+1xK).
  //
  //  Notes::
  //  - The validity of R is not checked
  //
  //  See also T2R, R2T, TR2RT.
  //  Copyright (C) 1993-2017, by Peter I. Corke
  //
  //  This file is part of The Robotics Toolbox for MATLAB (RTB).
  //
  //  RTB is free software: you can redistribute it and/or modify
  //  it under the terms of the GNU Lesser General Public License as published
  //  by the Free Software Foundation, either version 3 of the License, or (at
  //  your option) any later version.
  //
  //  RTB is distributed in the hope that it will be useful,
  //  but WITHOUT ANY WARRANTY; without even the implied warranty of
  //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //  GNU Lesser General Public License for more details.
  //
  //  You should have received a copy of the GNU Leser General Public License
  //  along with RTB.  If not, see <http://www.gnu.org/licenses/>.
  //
  //  http://www.petercorke.com
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d4, i37, d5, d6, d7)

  for (int i36 = 0; i36 < 3; i36++) {
    d5 = U[0][i36];
    d6 = U[1][i36];
    d7 = U[2][i36];
    for (i37 = 0; i37 < 3; i37++) {
      d4 = ((d5 * V[0][i37]) + (d6 * V[1][i37])) + (d7 * V[2][i37]);
      b_U[i37][i36] = d4;
    }
  }
  coder::inv(b_U, b_dv1);
  b_lambda[0] = lambda * H[2][0];
  b_lambda[1] = lambda * H[2][1];
  b_lambda[2] = lambda * H[2][2];
  coder::c_mldivide(A, b_lambda, b_dv2);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i38 = 0; i38 < 3; i38++) {
    init[i38][0] = b_dv1[i38][0];
    init[i38][1] = b_dv1[i38][1];
    init[i38][2] = b_dv1[i38][2];
    init[3][i38] = b_dv2[i38];
  }
  for (int i39{0}; i39 < 4; i39++) {
    init[i39][3] = static_cast<double>(b_iv[i39]);
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i40 = 0; i40 < 3; i40++) {
    f_K[i40][0] = b_cameraParams.IntrinsicMatrixInternal[0][i40];
    f_K[i40][1] = b_cameraParams.IntrinsicMatrixInternal[1][i40];
    f_K[i40][2] = b_cameraParams.IntrinsicMatrixInternal[2][i40];
  }
  for (int i41{0}; i41 < 3; i41++) {
    b_cF1.workspace.K11[i41][0] = f_K[0][i41];
    b_cF1.workspace.K11[i41][1] = f_K[1][i41];
    b_cF1.workspace.K11[i41][2] = f_K[2][i41];
    b_cF1.workspace.K11[3][i41] = 0.0;
  }
  varargin_2.set_size(r1.size(0), 2);
  if (r1.size(0) != 0) {
    int i42;
    i42 = r1.size(0) - 1;
    if ((static_cast<int>((r1.size(0) * 2) < 4)) != 0) {
      for (int c_k{0}; c_k < 2; c_k++) {
        for (d_t = 0; d_t <= i42; d_t++) {
          varargin_2[d_t + (varargin_2.size(0) * c_k)] =
              static_cast<signed char>(c_k);
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_t)

      for (int c_k = 0; c_k < 2; c_k++) {
        for (d_t = 0; d_t <= i42; d_t++) {
          varargin_2[d_t + (varargin_2.size(0) * c_k)] =
              static_cast<signed char>(c_k);
        }
      }
    }
    result = r1.size(0);
  } else if (r1.size(0) != 0) {
    result = r1.size(0);
  } else {
    result = 0;
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = 2;
  } else if (r1.size(0) != 0) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 2;
  } else if (varargin_2.size(0) != 0) {
    b_input_sizes_idx_1 = 2;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  //  optimizer options
  //  options.Algorithm = 'levenberg-marquardt';
  //  options.ScaleProblem='jacobian';
  //  options.Display='off';
  //  use :'interior-point' , if not generating C code, gives better results
  //  Create World Points
  b_cF1.workspace.WptsTrio.set_size((static_cast<int>(input_sizes_idx_1)) +
                                        (static_cast<int>(b_input_sizes_idx_1)),
                                    result);
  for (int i43{0}; i43 < result; i43++) {
    int ib_loop_ub;
    ib_loop_ub = static_cast<int>(input_sizes_idx_1);
    for (int i45{0}; i45 < ib_loop_ub; i45++) {
      b_cF1.workspace.WptsTrio[i45 + (b_cF1.workspace.WptsTrio.size(0) * i43)] =
          validWorldPoints[i43 + (result * i45)];
    }
  }
  for (int i44{0}; i44 < result; i44++) {
    int jb_loop_ub;
    jb_loop_ub = static_cast<int>(b_input_sizes_idx_1);
    for (int i46{0}; i46 < jb_loop_ub; i46++) {
      b_cF1.workspace.WptsTrio[(i46 + (static_cast<int>(input_sizes_idx_1))) +
                               (b_cF1.workspace.WptsTrio.size(0) * i44)] =
          static_cast<double>(varargin_2[i44 + (result * i46)]);
    }
  }
  //  Define Function and optimize
  // dummy initialization
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i47 = 0; i47 < 3; i47++) {
    b_init[i47][0] = init[i47][0];
    b_init[i47][1] = init[i47][1];
    b_init[i47][2] = init[i47][2];
  }
  coder::rotm2quat(b_init, dv3);
  for (int i48{0}; i48 < 4; i48++) {
    x0[i48] = dv3[i48];
  }
  x0[4] = init[3][0];
  x0[5] = init[3][1];
  x0[6] = init[3][2];
  coder::fmincon(&b_cF1, x0, x1);
  // RT2TR Convert rotation and translation to homogeneous transform
  // NOTE:  RT"TR change to createHT
  //  TR = RT2TR(R, t) is a homogeneous transformation matrix (N+1xN+1) formed
  //  from an orthonormal rotation matrix R (NxN) and a translation vector t
  //  (Nx1).  Works for R in SO(2) or SO(3):
  //   - If R is 2x2 and t is 2x1, then TR is 3x3
  //   - If R is 3x3 and t is 3x1, then TR is 4x4
  //
  //  For a sequence R (NxNxK) and t (NxK) results in a transform sequence
  //  (N+1xN+1xK).
  //
  //  Notes::
  //  - The validity of R is not checked
  //
  //  See also T2R, R2T, TR2RT.
  //  Copyright (C) 1993-2017, by Peter I. Corke
  //
  //  This file is part of The Robotics Toolbox for MATLAB (RTB).
  //
  //  RTB is free software: you can redistribute it and/or modify
  //  it under the terms of the GNU Lesser General Public License as published
  //  by the Free Software Foundation, either version 3 of the License, or (at
  //  your option) any later version.
  //
  //  RTB is distributed in the hope that it will be useful,
  //  but WITHOUT ANY WARRANTY; without even the implied warranty of
  //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  //  GNU Lesser General Public License for more details.
  //
  //  You should have received a copy of the GNU Leser General Public License
  //  along with RTB.  If not, see <http://www.gnu.org/licenses/>.
  //
  //  http://www.petercorke.com
  coder::quat2rotm(*((double(*)[4])(&x1[0])), b_dv1);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i49 = 0; i49 < 3; i49++) {
    poseCamera[i49][0] = b_dv1[i49][0];
    poseCamera[i49][1] = b_dv1[i49][1];
    poseCamera[i49][2] = b_dv1[i49][2];
    poseCamera[3][i49] = x1[i49 + 4];
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i52, d8,   \
                                                                    i54)

  for (int i50 = 0; i50 < 4; i50++) {
    poseCamera[i50][3] = static_cast<double>(b_iv[i50]);
    for (i54 = 0; i54 < 4; i54++) {
      d8 = 0.0;
      for (i52 = 0; i52 < 4; i52++) {
        d8 += b_robotpose[i52][i50] * handeye[i54][i52];
      }
      c_robotpose[i54][i50] = d8;
    }
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i53, d9,   \
                                                                    i55)

  for (int i51 = 0; i51 < 4; i51++) {
    for (i55 = 0; i55 < 4; i55++) {
      d9 = 0.0;
      for (i53 = 0; i53 < 4; i53++) {
        d9 += c_robotpose[i53][i51] * poseCamera[i55][i53];
      }
      poseRobot[i55][i51] = d9;
    }
  }
}

} // namespace ITER

//
// File trailer for estimatePitagPose.cpp
//
// [EOF]
//
