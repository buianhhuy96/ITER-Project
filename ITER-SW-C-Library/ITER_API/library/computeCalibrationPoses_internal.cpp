//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCalibrationPoses_internal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeCalibrationPoses_internal.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_rtwutil.h"
#include "ITER_API_types.h"
#include "cameraParameters.h"
#include "detectCheckerboardPoints.h"
#include "inv.h"
#include "linspace.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "rank.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include "libmwrgb2gray_tbb.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Type Definitions
namespace ITER {
struct cell_wrap_79 {
  ::coder::array<double, 2U> f1;
};

} // namespace ITER

// Function Definitions
//
// Function starts
//  Initialize outputs
//
// Arguments    : const ::coder::array<unsigned char, 3U> &initialImage
//                const double initialRobotPose[4][4]
//                const double handEyeEstimate[4][4]
//                double roughDistance
//                const double angularBounds[3][2]
//                double squareSize
//                const int boardSize[2]
//                const struct1_T *factoryCamParam
//                const int requestedNumPoses[3]
//                ::coder::array<double, 3U> &robotPoses
//                int *err
// Return Type  : void
//
namespace ITER {
void computeCalibrationPoses_internal(
    const ::coder::array<unsigned char, 3U> &initialImage,
    const double initialRobotPose[4][4], const double handEyeEstimate[4][4],
    double roughDistance, const double angularBounds[3][2], double squareSize,
    const int boardSize[2], const struct1_T *factoryCamParam,
    const int requestedNumPoses[3], ::coder::array<double, 3U> &robotPoses,
    int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::cameraParameters b_factoryCamParam;
  ::coder::array<double, 3U> c_rz;
  ::coder::array<double, 3U> rx;
  ::coder::array<double, 3U> ry;
  ::coder::array<double, 2U> Rchange;
  ::coder::array<double, 2U> aroundX;
  ::coder::array<double, 2U> aroundY;
  ::coder::array<double, 2U> aroundZ;
  ::coder::array<double, 2U> b_imagePoints;
  ::coder::array<double, 2U> c_f1;
  ::coder::array<double, 2U> c_worldPoints;
  ::coder::array<double, 2U> d_X;
  ::coder::array<double, 2U> d_f1;
  ::coder::array<double, 2U> f1;
  ::coder::array<double, 2U> uv;
  ::coder::array<double, 2U> xy;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> b_y;
  ::coder::array<double, 1U> c_u;
  ::coder::array<double, 1U> d_u;
  ::coder::array<double, 1U> e_v;
  ::coder::array<double, 1U> r;
  ::coder::array<double, 1U> r1;
  ::coder::array<unsigned char, 2U> grayImage;
  ::coder::array<signed char, 1U> b_r2;
  ::coder::array<signed char, 1U> r3;
  cell_wrap_79 rv[3];
  double RT12center[4][4];
  double RT34center[4][4];
  double RT34initial[4][4];
  double RTcorner_center[4][4];
  double a_tmp[4][4];
  double b_a_tmp[4][4];
  double b_dv2[4][4];
  double b_transform[4][4];
  double c_a_tmp[4][4];
  double dv3[4][4];
  double dv4[4][4];
  double A[3][3];
  double H[3][3];
  double T[3][3];
  double Tvec[9];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_R[3][3];
  double b_Tvec[3][3];
  double b_dv[3][3];
  double c_r1[3][3];
  double intrinsics[3][3];
  double normMatrix1[3][3];
  double normMatrix2[3][3];
  double b_dv1[3];
  double b_lambda[3];
  double b_r1[3];
  double e_x[3];
  double r2[3];
  double b_boardSizeDetected[2];
  double b_d1;
  double d;
  double d2;
  double d3;
  double d4;
  double d5;
  double d7;
  double d8;
  int b_err;
  int b_j;
  int d_i;
  int i1;
  int i2;
  int i38;
  int i4;
  int i42;
  int i44;
  int i49;
  int i6;
  int k;
  int loop_ub;
  int unnamed_idx_2;
  bool exitg1;
  bool y;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  unnamed_idx_2 =
      mul_s32_sat(mul_s32_sat(requestedNumPoses[0], requestedNumPoses[1]),
                  requestedNumPoses[2]);
  robotPoses.set_size(4, 4, unnamed_idx_2);
  loop_ub = unnamed_idx_2;
  if ((static_cast<int>((unnamed_idx_2 * 16) < 4)) != 0) {
    for (int b_i{0}; b_i < unnamed_idx_2; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          robotPoses[(i2 + (robotPoses.size(0) * i1)) +
                     ((robotPoses.size(0) * robotPoses.size(1)) * b_i)] = 0.0;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2, i1)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < 4; i1++) {
        for (i2 = 0; i2 < 4; i2++) {
          robotPoses[(i2 + (robotPoses.size(0) * i1)) +
                     ((robotPoses.size(0) * robotPoses.size(1)) * b_i)] = 0.0;
        }
      }
    }
  }
  b_err = 0;
  //  Setup Parameters
  (void)b_factoryCamParam.b_init(
      factoryCamParam->RadialDistortion, factoryCamParam->TangentialDistortion,
      factoryCamParam->ImageSize, factoryCamParam->WorldUnits,
      factoryCamParam->EstimateSkew,
      factoryCamParam->NumRadialDistortionCoefficients,
      factoryCamParam->EstimateTangentialDistortion,
      factoryCamParam->IntrinsicMatrix);
  //  Desired target distance (mm)
  //  Detect checker and calculate current pose
  if (initialImage.size(2) == 1) {
    int b_loop_ub;
    int c_loop_ub;
    b_loop_ub = initialImage.size(0);
    grayImage.set_size(initialImage.size(0), initialImage.size(1));
    c_loop_ub = initialImage.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

    for (int i3 = 0; i3 < c_loop_ub; i3++) {
      for (i4 = 0; i4 < b_loop_ub; i4++) {
        grayImage[i4 + (grayImage.size(0) * i3)] =
            initialImage[i4 + (initialImage.size(0) * i3)];
      }
    }
  } else {
    grayImage.set_size(initialImage.size(0), initialImage.size(1));
    rgb2gray_tbb_uint8(&initialImage[0],
                       (static_cast<double>(initialImage.size(0))) *
                           (static_cast<double>(initialImage.size(1))),
                       &grayImage[0], true);
  }
  coder::b_detectCheckerboardPoints(grayImage, b_imagePoints,
                                    b_boardSizeDetected);
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (b_boardSizeDetected[k] == 0.0) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!y) {
    b_err = -101;
    robotPoses.set_size(0, 0, 1);
  } else {
    int b_k;
    bool p;
    p = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 2)) {
      if (!((static_cast<double>(boardSize[b_k])) ==
            b_boardSizeDetected[b_k])) {
        p = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }
    if (!p) {
      b_err = -102;
      robotPoses.set_size(0, 0, 1);
    } else {
      double absxk;
      double b_t;
      double boardSize_idx_0;
      double boardSize_idx_1;
      double c_T;
      double c_y;
      double d10;
      double d6;
      double d9;
      double lambda;
      double scale;
      int ab_loop_ub;
      int b_boardSize_idx_0;
      int b_nx;
      int b_qY;
      int b_rx;
      int b_ry;
      int b_saturatedUnaryMinus;
      int b_xy_idx_0;
      int bb_loop_ub;
      unsigned int c_k;
      int c_xy_idx_0;
      int cb_loop_ub;
      int d_loop_ub;
      int d_rz;
      int d_xy_idx_0;
      int db_loop_ub;
      int e_loop_ub;
      int e_xy_idx_0;
      int eb_loop_ub;
      int f_loop_ub;
      int f_xy_idx_0;
      int fb_loop_ub;
      int g_loop_ub;
      int g_xy_idx_0;
      int gb_loop_ub;
      int h_loop_ub;
      int h_xy_idx_0;
      int hb_loop_ub;
      int i45;
      int i46;
      int i50;
      int i64;
      int i65;
      int i7;
      int i_loop_ub;
      int ib_loop_ub;
      int j_loop_ub;
      int k_loop_ub;
      int m_loop_ub;
      int middlepoint_tmp_idx_0;
      int middlepoint_tmp_idx_1;
      int ny;
      int nz;
      int o_loop_ub;
      int p_loop_ub;
      int qY;
      int q_loop_ub;
      int r_loop_ub;
      int s_loop_ub;
      int saturatedUnaryMinus;
      int t_loop_ub;
      int u_loop_ub;
      int v_loop_ub;
      int w_loop_ub;
      int x_loop_ub;
      int xy_idx_0;
      int y_loop_ub;
      boardSize_idx_0 = (static_cast<double>(boardSize[0])) - 1.0;
      boardSize_idx_1 = (static_cast<double>(boardSize[1])) - 1.0;
      b_boardSize_idx_0 = static_cast<int>(
          static_cast<double>(((static_cast<double>(boardSize[0])) - 1.0) *
                              ((static_cast<double>(boardSize[1])) - 1.0)));
      c_worldPoints.set_size(b_boardSize_idx_0, 2);
      d_loop_ub = b_boardSize_idx_0;
      if ((static_cast<int>((b_boardSize_idx_0 * 2) < 4)) != 0) {
        for (int i5{0}; i5 < 2; i5++) {
          for (i6 = 0; i6 < b_boardSize_idx_0; i6++) {
            c_worldPoints[i6 + (c_worldPoints.size(0) * i5)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6)

        for (int i5 = 0; i5 < 2; i5++) {
          for (i6 = 0; i6 < d_loop_ub; i6++) {
            c_worldPoints[i6 + (c_worldPoints.size(0) * i5)] = 0.0;
          }
        }
      }
      c_k = 1U;
      i7 = static_cast<int>(static_cast<double>((boardSize_idx_1 - 1.0) + 1.0));
      for (int j{0}; j < i7; j++) {
        int b_i8;
        b_i8 = static_cast<int>(
            static_cast<double>((boardSize_idx_0 - 1.0) + 1.0));
        for (int c_i{0}; c_i < b_i8; c_i++) {
          int b_worldPoints_tmp;
          b_worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                  c_k + (static_cast<unsigned int>(c_i))))) -
                              1;
          c_worldPoints[b_worldPoints_tmp] =
              (static_cast<double>(j)) * squareSize;
          c_worldPoints[b_worldPoints_tmp + c_worldPoints.size(0)] =
              (static_cast<double>(c_i)) * squareSize;
        }
        c_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((boardSize_idx_0 - 1.0) + 1.0)));
      }
      //  Check for valid checkerboard detected.
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i9 = 0; i9 < 3; i9++) {
        intrinsics[i9][0] = b_factoryCamParam.IntrinsicMatrixInternal[0][i9];
        intrinsics[i9][1] = b_factoryCamParam.IntrinsicMatrixInternal[1][i9];
        intrinsics[i9][2] = b_factoryCamParam.IntrinsicMatrixInternal[2][i9];
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i10 = 0; i10 < 3; i10++) {
        A[i10][0] = intrinsics[0][i10];
        A[i10][1] = intrinsics[1][i10];
        A[i10][2] = intrinsics[2][i10];
      }
      coder::images::geotrans::internal::b_normalizeControlPoints(
          c_worldPoints, uv, normMatrix1);
      coder::images::geotrans::internal::normalizeControlPoints(
          b_imagePoints, xy, normMatrix2);
      e_loop_ub = xy.size(0);
      b_x.set_size(xy.size(0));
      f_loop_ub = xy.size(0);
      if ((static_cast<int>(xy.size(0) < 4)) != 0) {
        for (int i11{0}; i11 < e_loop_ub; i11++) {
          b_x[i11] = xy[i11];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i11 = 0; i11 < f_loop_ub; i11++) {
          b_x[i11] = xy[i11];
        }
      }
      g_loop_ub = xy.size(0);
      b_y.set_size(xy.size(0));
      h_loop_ub = xy.size(0);
      if ((static_cast<int>(xy.size(0) < 4)) != 0) {
        for (int i12{0}; i12 < g_loop_ub; i12++) {
          b_y[i12] = xy[i12 + xy.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i12 = 0; i12 < h_loop_ub; i12++) {
          b_y[i12] = xy[i12 + xy.size(0)];
        }
      }
      i_loop_ub = uv.size(0);
      c_u.set_size(uv.size(0));
      j_loop_ub = uv.size(0);
      if ((static_cast<int>(uv.size(0) < 4)) != 0) {
        for (int i13{0}; i13 < i_loop_ub; i13++) {
          c_u[i13] = uv[i13];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i13 = 0; i13 < j_loop_ub; i13++) {
          c_u[i13] = uv[i13];
        }
      }
      k_loop_ub = uv.size(0);
      e_v.set_size(uv.size(0));
      m_loop_ub = uv.size(0);
      if ((static_cast<int>(uv.size(0) < 4)) != 0) {
        for (int i14{0}; i14 < k_loop_ub; i14++) {
          e_v[i14] = uv[i14 + uv.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i14 = 0; i14 < m_loop_ub; i14++) {
          e_v[i14] = uv[i14 + uv.size(0)];
        }
      }
      r.set_size(c_u.size(0));
      o_loop_ub = c_u.size(0);
      if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
        for (int i15{0}; i15 < o_loop_ub; i15++) {
          r[i15] = -c_u[i15];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i15 = 0; i15 < o_loop_ub; i15++) {
          r[i15] = -c_u[i15];
        }
      }
      r1.set_size(e_v.size(0));
      p_loop_ub = e_v.size(0);
      if ((static_cast<int>(e_v.size(0) < 4)) != 0) {
        for (int i16{0}; i16 < p_loop_ub; i16++) {
          r1[i16] = -e_v[i16];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i16 = 0; i16 < p_loop_ub; i16++) {
          r1[i16] = -e_v[i16];
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
      q_loop_ub = b_x.size(0);
      if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
        for (int i17{0}; i17 < q_loop_ub; i17++) {
          d_X[i17] = b_x[i17];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i17 = 0; i17 < q_loop_ub; i17++) {
          d_X[i17] = b_x[i17];
        }
      }
      r_loop_ub = b_y.size(0);
      if ((static_cast<int>(b_y.size(0) < 4)) != 0) {
        for (int i18{0}; i18 < r_loop_ub; i18++) {
          d_X[i18 + d_X.size(0)] = b_y[i18];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i18 = 0; i18 < r_loop_ub; i18++) {
          d_X[i18 + d_X.size(0)] = b_y[i18];
        }
      }
      s_loop_ub = xy_idx_0;
      if ((static_cast<int>(xy_idx_0 < 4)) != 0) {
        for (int i19{0}; i19 < xy_idx_0; i19++) {
          d_X[i19 + (d_X.size(0) * 2)] = 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i19 = 0; i19 < s_loop_ub; i19++) {
          d_X[i19 + (d_X.size(0) * 2)] = 1.0;
        }
      }
      t_loop_ub = b_xy_idx_0;
      if ((static_cast<int>(b_xy_idx_0 < 4)) != 0) {
        for (int i20{0}; i20 < b_xy_idx_0; i20++) {
          d_X[i20 + (d_X.size(0) * 3)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i20 = 0; i20 < t_loop_ub; i20++) {
          d_X[i20 + (d_X.size(0) * 3)] = 0.0;
        }
      }
      u_loop_ub = c_xy_idx_0;
      if ((static_cast<int>(c_xy_idx_0 < 4)) != 0) {
        for (int i21{0}; i21 < c_xy_idx_0; i21++) {
          d_X[i21 + (d_X.size(0) * 4)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i21 = 0; i21 < u_loop_ub; i21++) {
          d_X[i21 + (d_X.size(0) * 4)] = 0.0;
        }
      }
      v_loop_ub = d_xy_idx_0;
      if ((static_cast<int>(d_xy_idx_0 < 4)) != 0) {
        for (int i22{0}; i22 < d_xy_idx_0; i22++) {
          d_X[i22 + (d_X.size(0) * 5)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i22 = 0; i22 < v_loop_ub; i22++) {
          d_X[i22 + (d_X.size(0) * 5)] = 0.0;
        }
      }
      w_loop_ub = r.size(0);
      if ((static_cast<int>(r.size(0) < 4)) != 0) {
        for (int i23{0}; i23 < w_loop_ub; i23++) {
          d_X[i23 + (d_X.size(0) * 6)] = r[i23] * b_x[i23];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i23 = 0; i23 < w_loop_ub; i23++) {
          d_X[i23 + (d_X.size(0) * 6)] = r[i23] * b_x[i23];
        }
      }
      x_loop_ub = r.size(0);
      if ((static_cast<int>(r.size(0) < 4)) != 0) {
        for (int i24{0}; i24 < x_loop_ub; i24++) {
          d_X[i24 + (d_X.size(0) * 7)] = r[i24] * b_y[i24];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i24 = 0; i24 < x_loop_ub; i24++) {
          d_X[i24 + (d_X.size(0) * 7)] = r[i24] * b_y[i24];
        }
      }
      y_loop_ub = e_xy_idx_0;
      if ((static_cast<int>(e_xy_idx_0 < 4)) != 0) {
        for (int i25{0}; i25 < e_xy_idx_0; i25++) {
          d_X[i25 + b_x.size(0)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i25 = 0; i25 < y_loop_ub; i25++) {
          d_X[i25 + b_x.size(0)] = 0.0;
        }
      }
      ab_loop_ub = f_xy_idx_0;
      if ((static_cast<int>(f_xy_idx_0 < 4)) != 0) {
        for (int i26{0}; i26 < f_xy_idx_0; i26++) {
          d_X[(i26 + b_x.size(0)) + d_X.size(0)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i26 = 0; i26 < ab_loop_ub; i26++) {
          d_X[(i26 + b_x.size(0)) + d_X.size(0)] = 0.0;
        }
      }
      bb_loop_ub = g_xy_idx_0;
      if ((static_cast<int>(g_xy_idx_0 < 4)) != 0) {
        for (int i27{0}; i27 < g_xy_idx_0; i27++) {
          d_X[(i27 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i27 = 0; i27 < bb_loop_ub; i27++) {
          d_X[(i27 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
        }
      }
      cb_loop_ub = b_x.size(0);
      if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
        for (int i28{0}; i28 < cb_loop_ub; i28++) {
          d_X[(i28 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i28];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i28 = 0; i28 < cb_loop_ub; i28++) {
          d_X[(i28 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i28];
        }
      }
      db_loop_ub = b_y.size(0);
      if ((static_cast<int>(b_y.size(0) < 4)) != 0) {
        for (int i29{0}; i29 < db_loop_ub; i29++) {
          d_X[(i29 + b_x.size(0)) + (d_X.size(0) * 4)] = b_y[i29];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i29 = 0; i29 < db_loop_ub; i29++) {
          d_X[(i29 + b_x.size(0)) + (d_X.size(0) * 4)] = b_y[i29];
        }
      }
      eb_loop_ub = h_xy_idx_0;
      if ((static_cast<int>(h_xy_idx_0 < 4)) != 0) {
        for (int i30{0}; i30 < h_xy_idx_0; i30++) {
          d_X[(i30 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i30 = 0; i30 < eb_loop_ub; i30++) {
          d_X[(i30 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
        }
      }
      fb_loop_ub = r1.size(0);
      if ((static_cast<int>(r1.size(0) < 4)) != 0) {
        for (int i31{0}; i31 < fb_loop_ub; i31++) {
          d_X[(i31 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i31] * b_x[i31];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i31 = 0; i31 < fb_loop_ub; i31++) {
          d_X[(i31 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i31] * b_x[i31];
        }
      }
      gb_loop_ub = r1.size(0);
      if ((static_cast<int>(r1.size(0) < 4)) != 0) {
        for (int i32{0}; i32 < gb_loop_ub; i32++) {
          d_X[(i32 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i32] * b_y[i32];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i32 = 0; i32 < gb_loop_ub; i32++) {
          d_X[(i32 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i32] * b_y[i32];
        }
      }
      (void)coder::local_rank(d_X);
      d_u.set_size(c_u.size(0) + e_v.size(0));
      hb_loop_ub = c_u.size(0);
      if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
        for (int i33{0}; i33 < hb_loop_ub; i33++) {
          d_u[i33] = c_u[i33];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i33 = 0; i33 < hb_loop_ub; i33++) {
          d_u[i33] = c_u[i33];
        }
      }
      ib_loop_ub = e_v.size(0);
      if ((static_cast<int>(e_v.size(0) < 4)) != 0) {
        for (int i34{0}; i34 < ib_loop_ub; i34++) {
          d_u[i34 + c_u.size(0)] = e_v[i34];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i34 = 0; i34 < ib_loop_ub; i34++) {
          d_u[i34 + c_u.size(0)] = e_v[i34];
        }
      }
      coder::mldivide(d_X, d_u, r);
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i35 = 0; i35 < 8; i35++) {
        Tvec[i35] = r[i35];
      }
      Tvec[8] = 1.0;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d, i38, b_d1, d2, d3)

      for (int i36 = 0; i36 < 3; i36++) {
        b_d1 = Tvec[i36];
        d2 = Tvec[i36 + 3];
        d3 = Tvec[i36 + 6];
        for (i38 = 0; i38 < 3; i38++) {
          d = ((b_d1 * normMatrix1[i38][0]) + (d2 * normMatrix1[i38][1])) +
              (d3 * normMatrix1[i38][2]);
          b_Tvec[i38][i36] = d;
        }
      }
      coder::b_mldivide(normMatrix2, b_Tvec, b_dv);
      coder::inv(b_dv, T);
      c_T = T[2][2];
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i37 = 0; i37 < 3; i37++) {
        T[i37][0] /= c_T;
        T[i37][1] /= c_T;
        T[i37][2] /= c_T;
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i39 = 0; i39 < 3; i39++) {
        H[i39][0] = T[0][i39];
        H[i39][1] = T[1][i39];
        H[i39][2] = T[2][i39];
      }
      coder::c_mldivide(A, *((double(*)[3])(&H[0][0])), e_x);
      scale = 3.3121686421112381E-170;
      absxk = std::abs(e_x[0]);
      if (absxk > 3.3121686421112381E-170) {
        c_y = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        c_y = b_t * b_t;
      }
      absxk = std::abs(e_x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        c_y = ((c_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        c_y += b_t * b_t;
      }
      absxk = std::abs(e_x[2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        c_y = ((c_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        c_y += b_t * b_t;
      }
      c_y = scale * std::sqrt(c_y);
      lambda = 1.0 / c_y;
      b_lambda[0] = lambda * H[0][0];
      b_lambda[1] = lambda * H[0][1];
      b_lambda[2] = lambda * H[0][2];
      coder::c_mldivide(A, b_lambda, b_r1);
      b_lambda[0] = lambda * H[1][0];
      b_lambda[1] = lambda * H[1][1];
      b_lambda[2] = lambda * H[1][2];
      coder::c_mldivide(A, b_lambda, r2);
      c_r1[0][0] = b_r1[0];
      c_r1[0][1] = r2[0];
      c_r1[1][0] = b_r1[1];
      c_r1[1][1] = r2[1];
      c_r1[2][0] = b_r1[2];
      c_r1[2][1] = r2[2];
      c_r1[0][2] = (b_r1[1] * r2[2]) - (r2[1] * b_r1[2]);
      c_r1[1][2] = (r2[0] * b_r1[2]) - (b_r1[0] * r2[2]);
      c_r1[2][2] = (b_r1[0] * r2[1]) - (r2[0] * b_r1[1]);
      coder::b_svd(c_r1, U, a__1, V);
      //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i42)

      for (int i40 = 0; i40 < 4; i40++) {
        for (i42 = 0; i42 < 4; i42++) {
          RT34initial[i40][i42] = 0.0;
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d4, i44, d5, d7, d8)

      for (int i41 = 0; i41 < 3; i41++) {
        d5 = U[0][i41];
        d7 = U[1][i41];
        d8 = U[2][i41];
        for (i44 = 0; i44 < 3; i44++) {
          d4 = ((d5 * V[0][i44]) + (d7 * V[1][i44])) + (d8 * V[2][i44]);
          RT34initial[i44][i41] = d4;
        }
        b_lambda[i41] = lambda * H[2][i41];
      }
      coder::c_mldivide(A, b_lambda, b_dv1);
      RT34initial[0][3] = b_dv1[0];
      RT34initial[1][3] = b_dv1[1];
      RT34initial[2][3] = b_dv1[2];
      for (int i43{0}; i43 < 4; i43++) {
        RT34initial[3][i43] = static_cast<double>(b_iv[i43]);
      }
      //  Calculate Centre Pose
      if (boardSize[0] < -2147483646) {
        qY = MIN_int32_T;
      } else {
        qY = boardSize[0] - 2;
      }
      d6 = std::round(std::round((static_cast<double>(qY)) / 2.0) * squareSize);
      if (d6 < 2.147483648E+9) {
        if (d6 >= -2.147483648E+9) {
          i45 = static_cast<int>(d6);
        } else {
          i45 = MIN_int32_T;
        }
      } else if (d6 >= 2.147483648E+9) {
        i45 = MAX_int32_T;
      } else {
        i45 = 0;
      }
      middlepoint_tmp_idx_0 = i45;
      if (boardSize[1] < -2147483646) {
        b_qY = MIN_int32_T;
      } else {
        b_qY = boardSize[1] - 2;
      }
      d9 = std::round(std::round((static_cast<double>(b_qY)) / 2.0) *
                      squareSize);
      if (d9 < 2.147483648E+9) {
        if (d9 >= -2.147483648E+9) {
          i46 = static_cast<int>(d9);
        } else {
          i46 = MIN_int32_T;
        }
      } else if (d9 >= 2.147483648E+9) {
        i46 = MAX_int32_T;
      } else {
        i46 = 0;
      }
      middlepoint_tmp_idx_1 = i46;
      //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i49)

      for (int i47 = 0; i47 < 4; i47++) {
        for (i49 = 0; i49 < 4; i49++) {
          RT34center[i47][i49] = 0.0;
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i48 = 0; i48 < 3; i48++) {
        RT34center[i48][0] = static_cast<double>(iv[i48][0]);
        RT34center[i48][1] = static_cast<double>(iv[i48][1]);
        RT34center[i48][2] = static_cast<double>(iv[i48][2]);
      }
      if (middlepoint_tmp_idx_1 <= MIN_int32_T) {
        saturatedUnaryMinus = MAX_int32_T;
      } else {
        saturatedUnaryMinus = -middlepoint_tmp_idx_1;
      }
      RT34center[0][3] = static_cast<double>(saturatedUnaryMinus);
      if (middlepoint_tmp_idx_0 <= MIN_int32_T) {
        b_saturatedUnaryMinus = MAX_int32_T;
      } else {
        b_saturatedUnaryMinus = -middlepoint_tmp_idx_0;
      }
      RT34center[1][3] = static_cast<double>(b_saturatedUnaryMinus);
      d10 = std::round(roughDistance);
      if (d10 < 2.147483648E+9) {
        if (d10 >= -2.147483648E+9) {
          i50 = static_cast<int>(d10);
        } else {
          i50 = MIN_int32_T;
        }
      } else if (d10 >= 2.147483648E+9) {
        i50 = MAX_int32_T;
      } else {
        i50 = 0;
      }
      RT34center[2][3] = static_cast<double>(i50);
      for (int i51{0}; i51 < 4; i51++) {
        RT34center[3][i51] = static_cast<double>(b_iv[i51]);
      }
      coder::b_inv(handEyeEstimate, a_tmp);
      coder::b_inv(RT34center, b_dv2);
      for (int i52{0}; i52 < 4; i52++) {
        for (int i53{0}; i53 < 4; i53++) {
          double d11;
          d11 = 0.0;
          for (int i55{0}; i55 < 4; i55++) {
            d11 += a_tmp[i55][i52] * b_dv2[i53][i55];
          }
          b_a_tmp[i53][i52] = d11;
        }
        for (int i54{0}; i54 < 4; i54++) {
          double d12;
          d12 = 0.0;
          for (int i57{0}; i57 < 4; i57++) {
            d12 += b_a_tmp[i57][i52] * RT34initial[i54][i57];
          }
          c_a_tmp[i54][i52] = d12;
        }
        for (int i56{0}; i56 < 4; i56++) {
          double d13;
          d13 = 0.0;
          for (int i59{0}; i59 < 4; i59++) {
            d13 += c_a_tmp[i59][i52] * handEyeEstimate[i56][i59];
          }
          b_a_tmp[i56][i52] = d13;
        }
        for (int i58{0}; i58 < 4; i58++) {
          double d14;
          d14 = 0.0;
          for (int i60{0}; i60 < 4; i60++) {
            d14 += b_a_tmp[i60][i52] * initialRobotPose[i58][i60];
          }
          RT12center[i58][i52] = d14;
        }
      }
      //  Creates a set of robot poses
      coder::linspace(angularBounds[0][0], angularBounds[0][1],
                      requestedNumPoses[0], aroundX);
      coder::linspace(angularBounds[1][0], angularBounds[1][1],
                      requestedNumPoses[1], aroundY);
      coder::linspace(angularBounds[2][0], angularBounds[2][1],
                      requestedNumPoses[2], aroundZ);
      b_nx = aroundX.size(1);
      ny = aroundY.size(1);
      nz = aroundZ.size(1);
      c_rz.set_size(aroundY.size(1), aroundX.size(1), aroundZ.size(1));
      ry.set_size(aroundY.size(1), aroundX.size(1), aroundZ.size(1));
      rx.set_size(aroundY.size(1), aroundX.size(1), aroundZ.size(1));
      if (aroundX.size(1) != 0) {
        if (aroundY.size(1) != 0) {
          if (aroundZ.size(1) != 0) {
            if ((static_cast<int>((aroundZ.size(1) *
                                   (aroundX.size(1) * aroundY.size(1))) < 4)) !=
                0) {
              for (int d_k{0}; d_k < nz; d_k++) {
                for (b_j = 0; b_j < b_nx; b_j++) {
                  for (d_i = 0; d_i < ny; d_i++) {
                    c_rz[(d_i + (c_rz.size(0) * b_j)) +
                         ((c_rz.size(0) * c_rz.size(1)) * d_k)] = aroundX[b_j];
                    ry[(d_i + (ry.size(0) * b_j)) +
                       ((ry.size(0) * ry.size(1)) * d_k)] = aroundY[d_i];
                    rx[(d_i + (rx.size(0) * b_j)) +
                       ((rx.size(0) * rx.size(1)) * d_k)] = aroundZ[d_k];
                  }
                }
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_i, b_j)

              for (int d_k = 0; d_k < nz; d_k++) {
                for (b_j = 0; b_j < b_nx; b_j++) {
                  for (d_i = 0; d_i < ny; d_i++) {
                    c_rz[(d_i + (c_rz.size(0) * b_j)) +
                         ((c_rz.size(0) * c_rz.size(1)) * d_k)] = aroundX[b_j];
                    ry[(d_i + (ry.size(0) * b_j)) +
                       ((ry.size(0) * ry.size(1)) * d_k)] = aroundY[d_i];
                    rx[(d_i + (rx.size(0) * b_j)) +
                       ((rx.size(0) * rx.size(1)) * d_k)] = aroundZ[d_k];
                  }
                }
              }
            }
          }
        }
      }
      b_ry = (ry.size(0) * ry.size(1)) * ry.size(2);
      f1.set_size(1, b_ry);
      for (int i61{0}; i61 < b_ry; i61++) {
        f1[i61] = ry[i61];
      }
      d_rz = (c_rz.size(0) * c_rz.size(1)) * c_rz.size(2);
      c_f1.set_size(1, d_rz);
      for (int i62{0}; i62 < d_rz; i62++) {
        c_f1[i62] = c_rz[i62];
      }
      Rchange.set_size(3, (rx.size(0) * rx.size(1)) * rx.size(2));
      b_rx = (rx.size(0) * rx.size(1)) * rx.size(2);
      d_f1.set_size(1, b_rx);
      for (int i63{0}; i63 < b_rx; i63++) {
        d_f1[i63] = rx[i63];
      }
      rv[0].f1 = d_f1;
      rv[1].f1 = f1;
      rv[2].f1 = c_f1;
      i64 = (rx.size(0) * rx.size(1)) * rx.size(2);
      if ((static_cast<int>(((rx.size(0) * rx.size(1)) * rx.size(2)) < 4)) !=
          0) {
        for (int e_k{0}; e_k < i64; e_k++) {
          Rchange[3 * e_k] = d_f1[e_k];
          Rchange[(3 * e_k) + 1] = f1[e_k];
          Rchange[(3 * e_k) + 2] = c_f1[e_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_k = 0; e_k < i64; e_k++) {
          Rchange[3 * e_k] = rv[0].f1[e_k];
          Rchange[(3 * e_k) + 1] = rv[1].f1[e_k];
          Rchange[(3 * e_k) + 2] = rv[2].f1[e_k];
        }
      }
      i65 = Rchange.size(1);
      for (int e_i{0}; e_i < i65; e_i++) {
        double R_tmp;
        double b_R_tmp;
        double ct_idx_0;
        double ct_idx_1;
        double ct_idx_2;
        double d15;
        double st_idx_0;
        double st_idx_1;
        // Calculate transformation
        d15 = 0.017453292519943295 * Rchange[3 * e_i];
        ct_idx_0 = std::cos(d15);
        d15 = std::sin(d15);
        st_idx_0 = d15;
        d15 = 0.017453292519943295 * Rchange[(3 * e_i) + 1];
        ct_idx_1 = std::cos(d15);
        d15 = std::sin(d15);
        st_idx_1 = d15;
        d15 = 0.017453292519943295 * Rchange[(3 * e_i) + 2];
        ct_idx_2 = std::cos(d15);
        d15 = std::sin(d15);
        b_R[0][0] = ct_idx_0 * ct_idx_1;
        R_tmp = st_idx_1 * d15;
        b_R[1][0] = (R_tmp * ct_idx_0) - (st_idx_0 * ct_idx_2);
        b_R_tmp = st_idx_1 * ct_idx_2;
        b_R[2][0] = (b_R_tmp * ct_idx_0) + (st_idx_0 * d15);
        b_R[0][1] = st_idx_0 * ct_idx_1;
        b_R[1][1] = (R_tmp * st_idx_0) + (ct_idx_0 * ct_idx_2);
        b_R[2][1] = (b_R_tmp * st_idx_0) - (ct_idx_0 * d15);
        b_R[0][2] = -st_idx_1;
        b_R[1][2] = ct_idx_1 * d15;
        b_R[2][2] = ct_idx_1 * ct_idx_2;
        //  Before applying transform all R's coming from outside Matlab
        (void)std::memset(&b_transform[0][0], 0, 16U * (sizeof(double)));
        for (int i66{0}; i66 < 3; i66++) {
          b_transform[i66][0] = b_R[0][i66];
          b_transform[i66][1] = b_R[1][i66];
          b_transform[i66][2] = b_R[2][i66];
          b_transform[i66][3] = 0.0;
        }
        //  Before applying transform all R's coming from outside Matlab
        for (int i67{0}; i67 < 4; i67++) {
          b_transform[3][i67] = static_cast<double>(b_iv[i67]);
          for (int i69{0}; i69 < 4; i69++) {
            RTcorner_center[i67][i69] = 0.0;
          }
        }
        for (int i68{0}; i68 < 3; i68++) {
          RTcorner_center[i68][0] = static_cast<double>(iv[i68][0]);
          RTcorner_center[i68][1] = static_cast<double>(iv[i68][1]);
          RTcorner_center[i68][2] = static_cast<double>(iv[i68][2]);
        }
        RTcorner_center[0][3] = static_cast<double>(middlepoint_tmp_idx_1);
        RTcorner_center[1][3] = static_cast<double>(middlepoint_tmp_idx_0);
        RTcorner_center[2][3] = 0.0;
        b_r2.set_size(4);
        r3.set_size(4);
        for (int i70{0}; i70 < 4; i70++) {
          RTcorner_center[3][i70] = static_cast<double>(b_iv[i70]);
          b_r2[i70] = static_cast<signed char>(i70);
          r3[i70] = static_cast<signed char>(i70);
        }
        coder::b_inv(RTcorner_center, b_dv2);
        coder::b_inv(b_transform, dv3);
        for (int i71{0}; i71 < 4; i71++) {
          for (int i73{0}; i73 < 4; i73++) {
            double d16;
            d16 = 0.0;
            for (int i77{0}; i77 < 4; i77++) {
              d16 += b_dv2[i77][i71] * dv3[i73][i77];
            }
            dv4[i73][i71] = d16;
          }
          for (int i75{0}; i75 < 4; i75++) {
            double d18;
            d18 = 0.0;
            for (int i81{0}; i81 < 4; i81++) {
              d18 += dv4[i81][i71] * RTcorner_center[i75][i81];
            }
            b_dv2[i75][i71] = d18;
          }
        }
        for (int i72{0}; i72 < 4; i72++) {
          for (int i74{0}; i74 < 4; i74++) {
            double d17;
            d17 = 0.0;
            for (int i80{0}; i80 < 4; i80++) {
              d17 += b_dv2[i80][i72] * RT34center[i74][i80];
            }
            dv3[i74][i72] = d17;
          }
        }
        coder::b_inv(dv3, b_dv2);
        for (int i76{0}; i76 < 4; i76++) {
          for (int i79{0}; i79 < 4; i79++) {
            double d19;
            d19 = 0.0;
            for (int i84{0}; i84 < 4; i84++) {
              d19 += a_tmp[i84][i76] * b_dv2[i79][i84];
            }
            b_a_tmp[i79][i76] = d19;
          }
          for (int i83{0}; i83 < 4; i83++) {
            double d20;
            d20 = 0.0;
            for (int i86{0}; i86 < 4; i86++) {
              d20 += b_a_tmp[i86][i76] * RT34center[i83][i86];
            }
            c_a_tmp[i83][i76] = d20;
          }
          for (int i85{0}; i85 < 4; i85++) {
            double d21;
            d21 = 0.0;
            for (int i88{0}; i88 < 4; i88++) {
              d21 += c_a_tmp[i88][i76] * handEyeEstimate[i85][i88];
            }
            b_a_tmp[i85][i76] = d21;
          }
          for (int i87{0}; i87 < 4; i87++) {
            double d22;
            d22 = 0.0;
            for (int i89{0}; i89 < 4; i89++) {
              d22 += b_a_tmp[i89][i76] * RT12center[i87][i89];
            }
            c_a_tmp[i87][i76] = d22;
          }
        }
        for (int i78{0}; i78 < 4; i78++) {
          for (int i82{0}; i82 < 4; i82++) {
            robotPoses[((static_cast<int>(b_r2[i82])) +
                        (robotPoses.size(0) * (static_cast<int>(r3[i78])))) +
                       ((robotPoses.size(0) * robotPoses.size(1)) * e_i)] =
                (&c_a_tmp[0][0])[i82 + (4 * i78)];
          }
        }
      }
    }
  }
  *err = b_err;
}

} // namespace ITER

//
// File trailer for computeCalibrationPoses_internal.cpp
//
// [EOF]
//
