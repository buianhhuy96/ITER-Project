//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeCalibrationPoses_internal.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "computeCalibrationPoses_internal.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_types.h"
#include "cameraParameters.h"
#include "detectCheckerboardPoints.h"
#include "inv.h"
#include "linspace.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "rank.h"
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Type Definitions
struct cell_wrap_81 {
  coder::array<double, 2U> f1;
};

// Function Definitions
//
// Function starts
//  Initialize outputs
//
// Arguments    : const coder::array<unsigned char, 3U> &initialImage
//                const double initialRobotPose[4][4]
//                const double handEyeEstimate[4][4]
//                double roughDistance
//                const double angularBounds[3][2]
//                double squareSize
//                const int boardSize[2]
//                const struct1_T *factoryCamParam
//                const int requestedNumPoses[3]
//                coder::array<double, 3U> &robotPoses
//                int *err
// Return Type  : void
//
void computeCalibrationPoses_internal(
    const coder::array<unsigned char, 3U> &initialImage,
    const double initialRobotPose[4][4], const double handEyeEstimate[4][4],
    double roughDistance, const double angularBounds[3][2], double squareSize,
    const int boardSize[2], const struct1_T *factoryCamParam,
    const int requestedNumPoses[3], coder::array<double, 3U> &robotPoses,
    int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::cameraParameters b_factoryCamParam;
  coder::array<double, 3U> c_rz;
  coder::array<double, 3U> rx;
  coder::array<double, 3U> ry;
  coder::array<double, 2U> Rchange;
  coder::array<double, 2U> aroundX;
  coder::array<double, 2U> aroundY;
  coder::array<double, 2U> aroundZ;
  coder::array<double, 2U> b_imagePoints;
  coder::array<double, 2U> c_f1;
  coder::array<double, 2U> c_worldPoints;
  coder::array<double, 2U> d_X;
  coder::array<double, 2U> d_f1;
  coder::array<double, 2U> f1;
  coder::array<double, 2U> uv;
  coder::array<double, 2U> xy;
  coder::array<double, 1U> b_v;
  coder::array<double, 1U> b_x;
  coder::array<double, 1U> b_y;
  coder::array<double, 1U> c_u;
  coder::array<double, 1U> d_u;
  coder::array<double, 1U> r;
  coder::array<double, 1U> r1;
  coder::array<unsigned char, 2U> grayImage;
  coder::array<signed char, 1U> b_r2;
  coder::array<signed char, 1U> r3;
  cell_wrap_81 rv[3];
  double RT12center[4][4];
  double RT34center[4][4];
  double RT34initial[4][4];
  double RTcorner_center[4][4];
  double a_tmp[4][4];
  double b_a_tmp[4][4];
  double c_a_tmp[4][4];
  double dv2[4][4];
  double dv3[4][4];
  double dv4[4][4];
  double transform[4][4];
  double A[3][3];
  double H[3][3];
  double T[3][3];
  double Tvec[9];
  double U[3][3];
  double V[3][3];
  double a__1[3][3];
  double b_Tvec[3][3];
  double c_R[3][3];
  double c_r1[3][3];
  double dv[3][3];
  double intrinsics[3][3];
  double normMatrix1[3][3];
  double normMatrix2[3][3];
  double b_lambda[3];
  double b_r1[3];
  double dv1[3];
  double g_x[3];
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
  long b_i;
  long i1;
  int b_err;
  int b_i8;
  int b_j;
  int d_i;
  int i3;
  int i4;
  int i40;
  int i44;
  int i46;
  int i51;
  int i6;
  int k;
  int loop_ub;
  int unnamed_idx_2_tmp;
  bool exitg1;
  bool y;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  b_i = (static_cast<long>(requestedNumPoses[0])) *
        (static_cast<long>(requestedNumPoses[1]));
  if (b_i > 2147483647L) {
    b_i = 2147483647L;
  } else if (b_i < -2147483648L) {
    b_i = -2147483648L;
  } else {
    /* no actions */
  }
  i1 = (static_cast<long>(static_cast<int>(b_i))) *
       (static_cast<long>(requestedNumPoses[2]));
  if (i1 > 2147483647L) {
    i1 = 2147483647L;
  } else if (i1 < -2147483648L) {
    i1 = -2147483648L;
  } else {
    /* no actions */
  }
  unnamed_idx_2_tmp = static_cast<int>(i1);
  robotPoses.set_size(4, 4, static_cast<int>(i1));
  loop_ub = static_cast<int>(i1);
  if ((static_cast<int>(((static_cast<int>(i1)) * 16) < 4)) != 0) {
    for (int i2{0}; i2 < unnamed_idx_2_tmp; i2++) {
      for (i3 = 0; i3 < 4; i3++) {
        for (i4 = 0; i4 < 4; i4++) {
          robotPoses[(i4 + (robotPoses.size(0) * i3)) +
                     ((robotPoses.size(0) * robotPoses.size(1)) * i2)] = 0.0;
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4, i3)

    for (int i2 = 0; i2 < loop_ub; i2++) {
      for (i3 = 0; i3 < 4; i3++) {
        for (i4 = 0; i4 < 4; i4++) {
          robotPoses[(i4 + (robotPoses.size(0) * i3)) +
                     ((robotPoses.size(0) * robotPoses.size(1)) * i2)] = 0.0;
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
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6)

    for (int i5 = 0; i5 < c_loop_ub; i5++) {
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        grayImage[i6 + (grayImage.size(0) * i5)] =
            initialImage[i6 + (initialImage.size(0) * i5)];
      }
    }
  } else {
    coder::rgb2gray(initialImage, grayImage);
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
      double c_y;
      double d10;
      double d6;
      double d9;
      double e_T;
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
      int i47;
      int i48;
      int i52;
      int i66;
      int i67;
      int i9;
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
        for (int i7{0}; i7 < 2; i7++) {
          for (b_i8 = 0; b_i8 < b_boardSize_idx_0; b_i8++) {
            c_worldPoints[b_i8 + (c_worldPoints.size(0) * i7)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

        for (int i7 = 0; i7 < 2; i7++) {
          for (b_i8 = 0; b_i8 < d_loop_ub; b_i8++) {
            c_worldPoints[b_i8 + (c_worldPoints.size(0) * i7)] = 0.0;
          }
        }
      }
      c_k = 1U;
      i9 = static_cast<int>(static_cast<double>((boardSize_idx_1 - 1.0) + 1.0));
      for (int j{0}; j < i9; j++) {
        int i10;
        i10 = static_cast<int>(
            static_cast<double>((boardSize_idx_0 - 1.0) + 1.0));
        for (int c_i{0}; c_i < i10; c_i++) {
          int worldPoints_tmp;
          worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                c_k + (static_cast<unsigned int>(c_i))))) -
                            1;
          c_worldPoints[worldPoints_tmp] =
              (static_cast<double>(j)) * squareSize;
          c_worldPoints[worldPoints_tmp + c_worldPoints.size(0)] =
              (static_cast<double>(c_i)) * squareSize;
        }
        c_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((boardSize_idx_0 - 1.0) + 1.0)));
      }
      //  Check for valid checkerboard detected.
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i11 = 0; i11 < 3; i11++) {
        intrinsics[i11][0] = b_factoryCamParam.IntrinsicMatrixInternal[0][i11];
        intrinsics[i11][1] = b_factoryCamParam.IntrinsicMatrixInternal[1][i11];
        intrinsics[i11][2] = b_factoryCamParam.IntrinsicMatrixInternal[2][i11];
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i12 = 0; i12 < 3; i12++) {
        A[i12][0] = intrinsics[0][i12];
        A[i12][1] = intrinsics[1][i12];
        A[i12][2] = intrinsics[2][i12];
      }
      coder::images::geotrans::internal::b_normalizeControlPoints(
          c_worldPoints, uv, normMatrix1);
      coder::images::geotrans::internal::normalizeControlPoints(
          b_imagePoints, xy, normMatrix2);
      e_loop_ub = xy.size(0);
      b_x.set_size(xy.size(0));
      f_loop_ub = xy.size(0);
      if ((static_cast<int>(xy.size(0) < 4)) != 0) {
        for (int i13{0}; i13 < e_loop_ub; i13++) {
          b_x[i13] = xy[i13];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i13 = 0; i13 < f_loop_ub; i13++) {
          b_x[i13] = xy[i13];
        }
      }
      g_loop_ub = xy.size(0);
      b_y.set_size(xy.size(0));
      h_loop_ub = xy.size(0);
      if ((static_cast<int>(xy.size(0) < 4)) != 0) {
        for (int i14{0}; i14 < g_loop_ub; i14++) {
          b_y[i14] = xy[i14 + xy.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i14 = 0; i14 < h_loop_ub; i14++) {
          b_y[i14] = xy[i14 + xy.size(0)];
        }
      }
      i_loop_ub = uv.size(0);
      c_u.set_size(uv.size(0));
      j_loop_ub = uv.size(0);
      if ((static_cast<int>(uv.size(0) < 4)) != 0) {
        for (int i15{0}; i15 < i_loop_ub; i15++) {
          c_u[i15] = uv[i15];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i15 = 0; i15 < j_loop_ub; i15++) {
          c_u[i15] = uv[i15];
        }
      }
      k_loop_ub = uv.size(0);
      b_v.set_size(uv.size(0));
      m_loop_ub = uv.size(0);
      if ((static_cast<int>(uv.size(0) < 4)) != 0) {
        for (int i16{0}; i16 < k_loop_ub; i16++) {
          b_v[i16] = uv[i16 + uv.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i16 = 0; i16 < m_loop_ub; i16++) {
          b_v[i16] = uv[i16 + uv.size(0)];
        }
      }
      r.set_size(c_u.size(0));
      o_loop_ub = c_u.size(0);
      if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
        for (int i17{0}; i17 < o_loop_ub; i17++) {
          r[i17] = -c_u[i17];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i17 = 0; i17 < o_loop_ub; i17++) {
          r[i17] = -c_u[i17];
        }
      }
      r1.set_size(b_v.size(0));
      p_loop_ub = b_v.size(0);
      if ((static_cast<int>(b_v.size(0) < 4)) != 0) {
        for (int i18{0}; i18 < p_loop_ub; i18++) {
          r1[i18] = -b_v[i18];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i18 = 0; i18 < p_loop_ub; i18++) {
          r1[i18] = -b_v[i18];
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
        for (int i19{0}; i19 < q_loop_ub; i19++) {
          d_X[i19] = b_x[i19];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i19 = 0; i19 < q_loop_ub; i19++) {
          d_X[i19] = b_x[i19];
        }
      }
      r_loop_ub = b_y.size(0);
      if ((static_cast<int>(b_y.size(0) < 4)) != 0) {
        for (int i20{0}; i20 < r_loop_ub; i20++) {
          d_X[i20 + d_X.size(0)] = b_y[i20];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i20 = 0; i20 < r_loop_ub; i20++) {
          d_X[i20 + d_X.size(0)] = b_y[i20];
        }
      }
      s_loop_ub = xy_idx_0;
      if ((static_cast<int>(xy_idx_0 < 4)) != 0) {
        for (int i21{0}; i21 < xy_idx_0; i21++) {
          d_X[i21 + (d_X.size(0) * 2)] = 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i21 = 0; i21 < s_loop_ub; i21++) {
          d_X[i21 + (d_X.size(0) * 2)] = 1.0;
        }
      }
      t_loop_ub = b_xy_idx_0;
      if ((static_cast<int>(b_xy_idx_0 < 4)) != 0) {
        for (int i22{0}; i22 < b_xy_idx_0; i22++) {
          d_X[i22 + (d_X.size(0) * 3)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i22 = 0; i22 < t_loop_ub; i22++) {
          d_X[i22 + (d_X.size(0) * 3)] = 0.0;
        }
      }
      u_loop_ub = c_xy_idx_0;
      if ((static_cast<int>(c_xy_idx_0 < 4)) != 0) {
        for (int i23{0}; i23 < c_xy_idx_0; i23++) {
          d_X[i23 + (d_X.size(0) * 4)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i23 = 0; i23 < u_loop_ub; i23++) {
          d_X[i23 + (d_X.size(0) * 4)] = 0.0;
        }
      }
      v_loop_ub = d_xy_idx_0;
      if ((static_cast<int>(d_xy_idx_0 < 4)) != 0) {
        for (int i24{0}; i24 < d_xy_idx_0; i24++) {
          d_X[i24 + (d_X.size(0) * 5)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i24 = 0; i24 < v_loop_ub; i24++) {
          d_X[i24 + (d_X.size(0) * 5)] = 0.0;
        }
      }
      w_loop_ub = r.size(0);
      if ((static_cast<int>(r.size(0) < 4)) != 0) {
        for (int i25{0}; i25 < w_loop_ub; i25++) {
          d_X[i25 + (d_X.size(0) * 6)] = r[i25] * b_x[i25];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i25 = 0; i25 < w_loop_ub; i25++) {
          d_X[i25 + (d_X.size(0) * 6)] = r[i25] * b_x[i25];
        }
      }
      x_loop_ub = r.size(0);
      if ((static_cast<int>(r.size(0) < 4)) != 0) {
        for (int i26{0}; i26 < x_loop_ub; i26++) {
          d_X[i26 + (d_X.size(0) * 7)] = r[i26] * b_y[i26];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i26 = 0; i26 < x_loop_ub; i26++) {
          d_X[i26 + (d_X.size(0) * 7)] = r[i26] * b_y[i26];
        }
      }
      y_loop_ub = e_xy_idx_0;
      if ((static_cast<int>(e_xy_idx_0 < 4)) != 0) {
        for (int i27{0}; i27 < e_xy_idx_0; i27++) {
          d_X[i27 + b_x.size(0)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i27 = 0; i27 < y_loop_ub; i27++) {
          d_X[i27 + b_x.size(0)] = 0.0;
        }
      }
      ab_loop_ub = f_xy_idx_0;
      if ((static_cast<int>(f_xy_idx_0 < 4)) != 0) {
        for (int i28{0}; i28 < f_xy_idx_0; i28++) {
          d_X[(i28 + b_x.size(0)) + d_X.size(0)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i28 = 0; i28 < ab_loop_ub; i28++) {
          d_X[(i28 + b_x.size(0)) + d_X.size(0)] = 0.0;
        }
      }
      bb_loop_ub = g_xy_idx_0;
      if ((static_cast<int>(g_xy_idx_0 < 4)) != 0) {
        for (int i29{0}; i29 < g_xy_idx_0; i29++) {
          d_X[(i29 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i29 = 0; i29 < bb_loop_ub; i29++) {
          d_X[(i29 + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
        }
      }
      cb_loop_ub = b_x.size(0);
      if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
        for (int i30{0}; i30 < cb_loop_ub; i30++) {
          d_X[(i30 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i30];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i30 = 0; i30 < cb_loop_ub; i30++) {
          d_X[(i30 + b_x.size(0)) + (d_X.size(0) * 3)] = b_x[i30];
        }
      }
      db_loop_ub = b_y.size(0);
      if ((static_cast<int>(b_y.size(0) < 4)) != 0) {
        for (int i31{0}; i31 < db_loop_ub; i31++) {
          d_X[(i31 + b_x.size(0)) + (d_X.size(0) * 4)] = b_y[i31];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i31 = 0; i31 < db_loop_ub; i31++) {
          d_X[(i31 + b_x.size(0)) + (d_X.size(0) * 4)] = b_y[i31];
        }
      }
      eb_loop_ub = h_xy_idx_0;
      if ((static_cast<int>(h_xy_idx_0 < 4)) != 0) {
        for (int i32{0}; i32 < h_xy_idx_0; i32++) {
          d_X[(i32 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i32 = 0; i32 < eb_loop_ub; i32++) {
          d_X[(i32 + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
        }
      }
      fb_loop_ub = r1.size(0);
      if ((static_cast<int>(r1.size(0) < 4)) != 0) {
        for (int i33{0}; i33 < fb_loop_ub; i33++) {
          d_X[(i33 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i33] * b_x[i33];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i33 = 0; i33 < fb_loop_ub; i33++) {
          d_X[(i33 + b_x.size(0)) + (d_X.size(0) * 6)] = r1[i33] * b_x[i33];
        }
      }
      gb_loop_ub = r1.size(0);
      if ((static_cast<int>(r1.size(0) < 4)) != 0) {
        for (int i34{0}; i34 < gb_loop_ub; i34++) {
          d_X[(i34 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i34] * b_y[i34];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i34 = 0; i34 < gb_loop_ub; i34++) {
          d_X[(i34 + b_x.size(0)) + (d_X.size(0) * 7)] = r1[i34] * b_y[i34];
        }
      }
      (void)coder::local_rank(d_X);
      d_u.set_size(c_u.size(0) + b_v.size(0));
      hb_loop_ub = c_u.size(0);
      if ((static_cast<int>(c_u.size(0) < 4)) != 0) {
        for (int i35{0}; i35 < hb_loop_ub; i35++) {
          d_u[i35] = c_u[i35];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i35 = 0; i35 < hb_loop_ub; i35++) {
          d_u[i35] = c_u[i35];
        }
      }
      ib_loop_ub = b_v.size(0);
      if ((static_cast<int>(b_v.size(0) < 4)) != 0) {
        for (int i36{0}; i36 < ib_loop_ub; i36++) {
          d_u[i36 + c_u.size(0)] = b_v[i36];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i36 = 0; i36 < ib_loop_ub; i36++) {
          d_u[i36 + c_u.size(0)] = b_v[i36];
        }
      }
      coder::mldivide(d_X, d_u, r);
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i37 = 0; i37 < 8; i37++) {
        Tvec[i37] = r[i37];
      }
      Tvec[8] = 1.0;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d, i40, b_d1, d2, d3)

      for (int i38 = 0; i38 < 3; i38++) {
        b_d1 = Tvec[i38];
        d2 = Tvec[i38 + 3];
        d3 = Tvec[i38 + 6];
        for (i40 = 0; i40 < 3; i40++) {
          d = ((b_d1 * normMatrix1[i40][0]) + (d2 * normMatrix1[i40][1])) +
              (d3 * normMatrix1[i40][2]);
          b_Tvec[i40][i38] = d;
        }
      }
      coder::b_mldivide(normMatrix2, b_Tvec, dv);
      coder::inv(dv, T);
      e_T = T[2][2];
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i39 = 0; i39 < 3; i39++) {
        T[i39][0] /= e_T;
        T[i39][1] /= e_T;
        T[i39][2] /= e_T;
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i41 = 0; i41 < 3; i41++) {
        H[i41][0] = T[0][i41];
        H[i41][1] = T[1][i41];
        H[i41][2] = T[2][i41];
      }
      coder::c_mldivide(A, *((double(*)[3])(&H[0][0])), g_x);
      scale = 3.3121686421112381E-170;
      absxk = std::abs(g_x[0]);
      if (absxk > 3.3121686421112381E-170) {
        c_y = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        c_y = b_t * b_t;
      }
      absxk = std::abs(g_x[1]);
      if (absxk > scale) {
        b_t = scale / absxk;
        c_y = ((c_y * b_t) * b_t) + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        c_y += b_t * b_t;
      }
      absxk = std::abs(g_x[2]);
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
      coder::svd(c_r1, U, a__1, V);
      //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i44)

      for (int i42 = 0; i42 < 4; i42++) {
        for (i44 = 0; i44 < 4; i44++) {
          RT34initial[i42][i44] = 0.0;
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d4, i46, d5, d7, d8)

      for (int i43 = 0; i43 < 3; i43++) {
        d5 = U[0][i43];
        d7 = U[1][i43];
        d8 = U[2][i43];
        for (i46 = 0; i46 < 3; i46++) {
          d4 = ((d5 * V[0][i46]) + (d7 * V[1][i46])) + (d8 * V[2][i46]);
          RT34initial[i46][i43] = d4;
        }
        b_lambda[i43] = lambda * H[2][i43];
      }
      coder::c_mldivide(A, b_lambda, dv1);
      RT34initial[0][3] = dv1[0];
      RT34initial[1][3] = dv1[1];
      RT34initial[2][3] = dv1[2];
      for (int i45{0}; i45 < 4; i45++) {
        RT34initial[3][i45] = static_cast<double>(b_iv[i45]);
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
          i47 = static_cast<int>(d6);
        } else {
          i47 = MIN_int32_T;
        }
      } else if (d6 >= 2.147483648E+9) {
        i47 = MAX_int32_T;
      } else {
        i47 = 0;
      }
      middlepoint_tmp_idx_0 = i47;
      if (boardSize[1] < -2147483646) {
        b_qY = MIN_int32_T;
      } else {
        b_qY = boardSize[1] - 2;
      }
      d9 = std::round(std::round((static_cast<double>(b_qY)) / 2.0) *
                      squareSize);
      if (d9 < 2.147483648E+9) {
        if (d9 >= -2.147483648E+9) {
          i48 = static_cast<int>(d9);
        } else {
          i48 = MIN_int32_T;
        }
      } else if (d9 >= 2.147483648E+9) {
        i48 = MAX_int32_T;
      } else {
        i48 = 0;
      }
      middlepoint_tmp_idx_1 = i48;
      //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i51)

      for (int i49 = 0; i49 < 4; i49++) {
        for (i51 = 0; i51 < 4; i51++) {
          RT34center[i49][i51] = 0.0;
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i50 = 0; i50 < 3; i50++) {
        RT34center[i50][0] = static_cast<double>(iv[i50][0]);
        RT34center[i50][1] = static_cast<double>(iv[i50][1]);
        RT34center[i50][2] = static_cast<double>(iv[i50][2]);
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
          i52 = static_cast<int>(d10);
        } else {
          i52 = MIN_int32_T;
        }
      } else if (d10 >= 2.147483648E+9) {
        i52 = MAX_int32_T;
      } else {
        i52 = 0;
      }
      RT34center[2][3] = static_cast<double>(i52);
      for (int i53{0}; i53 < 4; i53++) {
        RT34center[3][i53] = static_cast<double>(b_iv[i53]);
      }
      coder::b_inv(handEyeEstimate, a_tmp);
      coder::b_inv(RT34center, dv2);
      for (int i54{0}; i54 < 4; i54++) {
        for (int i55{0}; i55 < 4; i55++) {
          double d11;
          d11 = 0.0;
          for (int i57{0}; i57 < 4; i57++) {
            d11 += a_tmp[i57][i54] * dv2[i55][i57];
          }
          b_a_tmp[i55][i54] = d11;
        }
        for (int i56{0}; i56 < 4; i56++) {
          double d12;
          d12 = 0.0;
          for (int i59{0}; i59 < 4; i59++) {
            d12 += b_a_tmp[i59][i54] * RT34initial[i56][i59];
          }
          c_a_tmp[i56][i54] = d12;
        }
        for (int i58{0}; i58 < 4; i58++) {
          double d13;
          d13 = 0.0;
          for (int i61{0}; i61 < 4; i61++) {
            d13 += c_a_tmp[i61][i54] * handEyeEstimate[i58][i61];
          }
          b_a_tmp[i58][i54] = d13;
        }
        for (int i60{0}; i60 < 4; i60++) {
          double d14;
          d14 = 0.0;
          for (int i62{0}; i62 < 4; i62++) {
            d14 += b_a_tmp[i62][i54] * initialRobotPose[i60][i62];
          }
          RT12center[i60][i54] = d14;
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
      for (int i63{0}; i63 < b_ry; i63++) {
        f1[i63] = ry[i63];
      }
      d_rz = (c_rz.size(0) * c_rz.size(1)) * c_rz.size(2);
      c_f1.set_size(1, d_rz);
      for (int i64{0}; i64 < d_rz; i64++) {
        c_f1[i64] = c_rz[i64];
      }
      Rchange.set_size(3, (rx.size(0) * rx.size(1)) * rx.size(2));
      b_rx = (rx.size(0) * rx.size(1)) * rx.size(2);
      d_f1.set_size(1, b_rx);
      for (int i65{0}; i65 < b_rx; i65++) {
        d_f1[i65] = rx[i65];
      }
      rv[0].f1 = d_f1;
      rv[1].f1 = f1;
      rv[2].f1 = c_f1;
      i66 = (rx.size(0) * rx.size(1)) * rx.size(2);
      if ((static_cast<int>(((rx.size(0) * rx.size(1)) * rx.size(2)) < 4)) !=
          0) {
        for (int e_k{0}; e_k < i66; e_k++) {
          Rchange[3 * e_k] = d_f1[e_k];
          Rchange[(3 * e_k) + 1] = f1[e_k];
          Rchange[(3 * e_k) + 2] = c_f1[e_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_k = 0; e_k < i66; e_k++) {
          Rchange[3 * e_k] = rv[0].f1[e_k];
          Rchange[(3 * e_k) + 1] = rv[1].f1[e_k];
          Rchange[(3 * e_k) + 2] = rv[2].f1[e_k];
        }
      }
      i67 = Rchange.size(1);
      for (int e_i{0}; e_i < i67; e_i++) {
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
        c_R[0][0] = ct_idx_0 * ct_idx_1;
        R_tmp = st_idx_1 * d15;
        c_R[1][0] = (R_tmp * ct_idx_0) - (st_idx_0 * ct_idx_2);
        b_R_tmp = st_idx_1 * ct_idx_2;
        c_R[2][0] = (b_R_tmp * ct_idx_0) + (st_idx_0 * d15);
        c_R[0][1] = st_idx_0 * ct_idx_1;
        c_R[1][1] = (R_tmp * st_idx_0) + (ct_idx_0 * ct_idx_2);
        c_R[2][1] = (b_R_tmp * st_idx_0) - (ct_idx_0 * d15);
        c_R[0][2] = -st_idx_1;
        c_R[1][2] = ct_idx_1 * d15;
        c_R[2][2] = ct_idx_1 * ct_idx_2;
        //  Before applying transform all R's coming from outside Matlab
        (void)std::memset(&transform[0][0], 0, 16U * (sizeof(double)));
        for (int i68{0}; i68 < 3; i68++) {
          transform[i68][0] = c_R[0][i68];
          transform[i68][1] = c_R[1][i68];
          transform[i68][2] = c_R[2][i68];
          transform[i68][3] = 0.0;
        }
        //  Before applying transform all R's coming from outside Matlab
        for (int i69{0}; i69 < 4; i69++) {
          transform[3][i69] = static_cast<double>(b_iv[i69]);
          for (int i71{0}; i71 < 4; i71++) {
            RTcorner_center[i69][i71] = 0.0;
          }
        }
        for (int i70{0}; i70 < 3; i70++) {
          RTcorner_center[i70][0] = static_cast<double>(iv[i70][0]);
          RTcorner_center[i70][1] = static_cast<double>(iv[i70][1]);
          RTcorner_center[i70][2] = static_cast<double>(iv[i70][2]);
        }
        RTcorner_center[0][3] = static_cast<double>(middlepoint_tmp_idx_1);
        RTcorner_center[1][3] = static_cast<double>(middlepoint_tmp_idx_0);
        RTcorner_center[2][3] = 0.0;
        b_r2.set_size(4);
        r3.set_size(4);
        for (int i72{0}; i72 < 4; i72++) {
          RTcorner_center[3][i72] = static_cast<double>(b_iv[i72]);
          b_r2[i72] = static_cast<signed char>(i72);
          r3[i72] = static_cast<signed char>(i72);
        }
        coder::b_inv(RTcorner_center, dv2);
        coder::b_inv(transform, dv3);
        for (int i73{0}; i73 < 4; i73++) {
          for (int i75{0}; i75 < 4; i75++) {
            double d16;
            d16 = 0.0;
            for (int i79{0}; i79 < 4; i79++) {
              d16 += dv2[i79][i73] * dv3[i75][i79];
            }
            dv4[i75][i73] = d16;
          }
          for (int i77{0}; i77 < 4; i77++) {
            double d18;
            d18 = 0.0;
            for (int i83{0}; i83 < 4; i83++) {
              d18 += dv4[i83][i73] * RTcorner_center[i77][i83];
            }
            dv2[i77][i73] = d18;
          }
        }
        for (int i74{0}; i74 < 4; i74++) {
          for (int i76{0}; i76 < 4; i76++) {
            double d17;
            d17 = 0.0;
            for (int i82{0}; i82 < 4; i82++) {
              d17 += dv2[i82][i74] * RT34center[i76][i82];
            }
            dv3[i76][i74] = d17;
          }
        }
        coder::b_inv(dv3, dv2);
        for (int i78{0}; i78 < 4; i78++) {
          for (int i81{0}; i81 < 4; i81++) {
            double d19;
            d19 = 0.0;
            for (int i86{0}; i86 < 4; i86++) {
              d19 += a_tmp[i86][i78] * dv2[i81][i86];
            }
            b_a_tmp[i81][i78] = d19;
          }
          for (int i85{0}; i85 < 4; i85++) {
            double d20;
            d20 = 0.0;
            for (int i88{0}; i88 < 4; i88++) {
              d20 += b_a_tmp[i88][i78] * RT34center[i85][i88];
            }
            c_a_tmp[i85][i78] = d20;
          }
          for (int i87{0}; i87 < 4; i87++) {
            double d21;
            d21 = 0.0;
            for (int i90{0}; i90 < 4; i90++) {
              d21 += c_a_tmp[i90][i78] * handEyeEstimate[i87][i90];
            }
            b_a_tmp[i87][i78] = d21;
          }
          for (int i89{0}; i89 < 4; i89++) {
            double d22;
            d22 = 0.0;
            for (int i91{0}; i91 < 4; i91++) {
              d22 += b_a_tmp[i91][i78] * RT12center[i89][i91];
            }
            c_a_tmp[i89][i78] = d22;
          }
        }
        for (int i80{0}; i80 < 4; i80++) {
          for (int i84{0}; i84 < 4; i84++) {
            robotPoses[((static_cast<int>(b_r2[i84])) +
                        (robotPoses.size(0) * (static_cast<int>(r3[i80])))) +
                       ((robotPoses.size(0) * robotPoses.size(1)) * e_i)] =
                (&c_a_tmp[0][0])[i84 + (4 * i80)];
          }
        }
      }
    }
  }
  *err = b_err;
}

//
// File trailer for computeCalibrationPoses_internal.cpp
//
// [EOF]
//
