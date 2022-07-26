//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeInitialParameterEstimate.h"
#include "ITER_API_types.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd1.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Solve for the camera intriniscs and extrinsics in closed form ignoring
//  distortion.
//
// Arguments    : const ::coder::array<double, 2U> &c_worldPoints
//                const ::coder::array<double, 3U> &b_imagePoints
//                const double c_imageSize[2]
//                k_struct_T *initialParams
//                ::coder::array<bool, 1U> &validIdx
//                int *err
// Return Type  : void
//
namespace ITER {
void computeInitialParameterEstimate(
    const ::coder::array<double, 2U> &c_worldPoints,
    const ::coder::array<double, 3U> &b_imagePoints,
    const double c_imageSize[2], k_struct_T *initialParams,
    ::coder::array<bool, 1U> &validIdx, int *err)
{
  coder::cameraParameters lobj_1[2];
  coder::projective2d c_H;
  ::coder::array<double, 3U> H;
  ::coder::array<double, 3U> b_H;
  ::coder::array<double, 2U> U;
  ::coder::array<double, 2U> U1;
  ::coder::array<double, 2U> V;
  ::coder::array<double, 2U> b_rotationVectors;
  ::coder::array<double, 2U> b_translationVectors;
  ::coder::array<double, 2U> c_imagePoints;
  ::coder::array<double, 2U> d_imagePoints;
  ::coder::array<double, 2U> d_worldPoints;
  ::coder::array<double, 2U> r3;
  ::coder::array<double, 1U> s;
  ::coder::array<double, 1U> s1;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r2;
  ::coder::array<bool, 1U> r1;
  ::coder::array<bool, 1U> validPointsIdx;
  double V1[6][6];
  double b_U[6][6];
  double A[3][3];
  double Ainv[3][3];
  double b_r1[3][3];
  double e_H[3][3];
  double r1_tmp[3][3];
  double f_H[6];
  double g_H[6];
  double b_dv[3];
  double b_r2[3];
  double c_r1[3];
  double t9_NumRadialDistortionCoefficients;
  int b_err;
  int b_i8;
  int b_loop_ub;
  int c_err;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int h_loop_ub;
  int i1;
  int i10;
  int i19;
  int i2;
  int i24;
  int i26;
  int i_loop_ub;
  int k_loop_ub;
  int loop_ub;
  int trueCount;
  char t9_WorldUnits[2];
  bool t9_EstimateSkew;
  bool t9_EstimateTangentialDistortion;
  //  Compute homographies for all images
  // --------------------------------------------------------------------------
  b_err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  H.set_size(3, 3, b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  if ((static_cast<int>((b_imagePoints.size(2) * 9) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        H[(3 * i1) + (9 * b_i)] = 0.0;
        H[((3 * i1) + (9 * b_i)) + 1] = 0.0;
        H[((3 * i1) + (9 * b_i)) + 2] = 0.0;
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        H[(3 * i1) + (9 * b_i)] = 0.0;
        H[((3 * i1) + (9 * b_i)) + 1] = 0.0;
        H[((3 * i1) + (9 * b_i)) + 2] = 0.0;
      }
    }
  }
  i2 = b_imagePoints.size(2);
  if (0 <= (i2 - 1)) {
    b_loop_ub = b_imagePoints.size(0);
    c_loop_ub = b_imagePoints.size(1);
    d_loop_ub = b_imagePoints.size(0) - 1;
    e_loop_ub = b_imagePoints.size(1) - 1;
    f_loop_ub = c_worldPoints.size(1);
  }
  for (int c_i{0}; c_i < i2; c_i++) {
    double d_H;
    int b_end;
    int b_trueCount;
    int g_loop_ub;
    int partialTrueCount;
    //  try
    c_imagePoints.set_size(b_imagePoints.size(0), b_imagePoints.size(1));
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      for (int i4{0}; i4 < b_loop_ub; i4++) {
        c_imagePoints[i4 + (c_imagePoints.size(0) * i3)] =
            b_imagePoints[(i4 + (b_imagePoints.size(0) * i3)) +
                          ((b_imagePoints.size(0) * b_imagePoints.size(1)) *
                           c_i)];
      }
    }
    //  Compute projective transformation from worldPoints to imagePoints
    // --------------------------------------------------------------------------
    r1.set_size(b_imagePoints.size(0));
    for (int i5{0}; i5 <= d_loop_ub; i5++) {
      r1[i5] = std::isnan(c_imagePoints[i5]);
    }
    validPointsIdx.set_size(r1.size(0));
    g_loop_ub = r1.size(0);
    for (int i6{0}; i6 < g_loop_ub; i6++) {
      validPointsIdx[i6] = !r1[i6];
    }
    b_end = validPointsIdx.size(0) - 1;
    b_trueCount = 0;
    for (int g_i{0}; g_i <= b_end; g_i++) {
      if (validPointsIdx[g_i]) {
        b_trueCount++;
      }
    }
    r2.set_size(b_trueCount);
    partialTrueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if (validPointsIdx[h_i]) {
        r2[partialTrueCount] = h_i + 1;
        partialTrueCount++;
      }
    }
    d_worldPoints.set_size(r2.size(0), c_worldPoints.size(1));
    for (int i11{0}; i11 < f_loop_ub; i11++) {
      int j_loop_ub;
      j_loop_ub = r2.size(0);
      for (int i13{0}; i13 < j_loop_ub; i13++) {
        d_worldPoints[i13 + (d_worldPoints.size(0) * i11)] =
            c_worldPoints[(r2[i13] + (c_worldPoints.size(0) * i11)) - 1];
      }
    }
    d_imagePoints.set_size(r2.size(0), b_imagePoints.size(1));
    for (int i12{0}; i12 <= e_loop_ub; i12++) {
      int m_loop_ub;
      m_loop_ub = r2.size(0);
      for (int i16{0}; i16 < m_loop_ub; i16++) {
        d_imagePoints[i16 + (d_imagePoints.size(0) * i12)] =
            c_imagePoints[(r2[i16] + (c_imagePoints.size(0) * i12)) - 1];
      }
    }
    coder::fitgeotrans(d_worldPoints, d_imagePoints, &c_H);
    for (int i15{0}; i15 < 3; i15++) {
      H[(3 * i15) + (9 * c_i)] = c_H.T[0][i15];
      H[((3 * i15) + (9 * c_i)) + 1] = c_H.T[1][i15];
      H[((3 * i15) + (9 * c_i)) + 2] = c_H.T[2][i15];
    }
    d_H = H[(9 * c_i) + 8];
    for (int i17{0}; i17 < 3; i17++) {
      H[(3 * i17) + (9 * c_i)] = H[(3 * i17) + (9 * c_i)] / d_H;
      H[((3 * i17) + (9 * c_i)) + 1] = H[((3 * i17) + (9 * c_i)) + 1] / d_H;
      H[((3 * i17) + (9 * c_i)) + 2] = H[((3 * i17) + (9 * c_i)) + 2] / d_H;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
  }
  // warning(w1);
  // warning(w2);
  end = b_imagePoints.size(2) - 1;
  trueCount = 0;
  for (int d_i{0}; d_i <= end; d_i++) {
    trueCount++;
  }
  r.set_size(trueCount);
  if ((static_cast<int>(b_imagePoints.size(2) < 4)) != 0) {
    for (int e_i{0}; e_i <= end; e_i++) {
      r[e_i] = e_i + 1;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int e_i = 0; e_i <= end; e_i++) {
      r[e_i] = e_i + 1;
    }
  }
  b_H.set_size(3, 3, r.size(0));
  h_loop_ub = r.size(0);
  if ((static_cast<int>((r.size(0) * 9) < 4)) != 0) {
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      for (b_i8 = 0; b_i8 < 3; b_i8++) {
        b_H[(3 * b_i8) + (9 * i7)] = H[(3 * b_i8) + (9 * (r[i7] - 1))];
        b_H[((3 * b_i8) + (9 * i7)) + 1] =
            H[((3 * b_i8) + (9 * (r[i7] - 1))) + 1];
        b_H[((3 * b_i8) + (9 * i7)) + 2] =
            H[((3 * b_i8) + (9 * (r[i7] - 1))) + 2];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

    for (int i7 = 0; i7 < h_loop_ub; i7++) {
      for (b_i8 = 0; b_i8 < 3; b_i8++) {
        b_H[(3 * b_i8) + (9 * i7)] = H[(3 * b_i8) + (9 * (r[i7] - 1))];
        b_H[((3 * b_i8) + (9 * i7)) + 1] =
            H[((3 * b_i8) + (9 * (r[i7] - 1))) + 1];
        b_H[((3 * b_i8) + (9 * i7)) + 2] =
            H[((3 * b_i8) + (9 * (r[i7] - 1))) + 2];
      }
    }
  }
  H.set_size(3, 3, b_H.size(2));
  i_loop_ub = b_H.size(2);
  if ((static_cast<int>((b_H.size(2) * 9) < 4)) != 0) {
    for (int i9{0}; i9 < i_loop_ub; i9++) {
      for (i10 = 0; i10 < 3; i10++) {
        H[(3 * i10) + (9 * i9)] = b_H[(3 * i10) + (9 * i9)];
        H[((3 * i10) + (9 * i9)) + 1] = b_H[((3 * i10) + (9 * i9)) + 1];
        H[((3 * i10) + (9 * i9)) + 2] = b_H[((3 * i10) + (9 * i9)) + 2];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i10)

    for (int i9 = 0; i9 < i_loop_ub; i9++) {
      for (i10 = 0; i10 < 3; i10++) {
        H[(3 * i10) + (9 * i9)] = b_H[(3 * i10) + (9 * i9)];
        H[((3 * i10) + (9 * i9)) + 1] = b_H[((3 * i10) + (9 * i9)) + 1];
        H[((3 * i10) + (9 * i9)) + 2] = b_H[((3 * i10) + (9 * i9)) + 2];
      }
    }
  }
  if (H.size(2) < 2) {
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    b_err = -201;
  }
  validIdx.set_size(b_imagePoints.size(2));
  k_loop_ub = b_imagePoints.size(2);
  if ((static_cast<int>(b_imagePoints.size(2) < 4)) != 0) {
    for (int i14{0}; i14 < k_loop_ub; i14++) {
      validIdx[i14] = true;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i14 = 0; i14 < k_loop_ub; i14++) {
      validIdx[i14] = true;
    }
  }
  c_err = b_err;
  if (b_err == 0) {
    double b_cy;
    double b_cy_tmp;
    double cy_tmp;
    double d;
    double fx;
    double fy;
    double lambda;
    double skew;
    double skew_tmp;
    int d_err;
    int i20;
    int i22;
    int o_loop_ub;
    int unnamed_idx_0;
    bool p;
    //  Vb = 0
    // --------------------------------------------------------------------------
    unnamed_idx_0 = 2 * H.size(2);
    V.set_size(unnamed_idx_0, 6);
    o_loop_ub = unnamed_idx_0;
    if ((static_cast<int>((6 * unnamed_idx_0) < 4)) != 0) {
      for (int i18{0}; i18 < 6; i18++) {
        for (i19 = 0; i19 < unnamed_idx_0; i19++) {
          V[i19 + (V.size(0) * i18)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i19)

      for (int i18 = 0; i18 < 6; i18++) {
        for (i19 = 0; i19 < o_loop_ub; i19++) {
          V[i19 + (V.size(0) * i18)] = 0.0;
        }
      }
    }
    i20 = H.size(2);
    for (int k_i{0}; k_i < i20; k_i++) {
      int i_tmp;
      for (int i21{0}; i21 < 3; i21++) {
        e_H[i21][0] = H[i21 + (9 * k_i)];
        e_H[i21][1] = H[(i21 + (9 * k_i)) + 3];
        e_H[i21][2] = H[(i21 + (9 * k_i)) + 6];
      }
      double H_tmp;
      double b_H_tmp;
      double c_H_tmp;
      double d_H_tmp;
      double e_H_tmp;
      double f_H_tmp;
      // --------------------------------------------------------------------------
      i_tmp = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(static_cast<int>(k_i + 1))) << 1U));
      V[i_tmp - 2] = e_H[0][0] * e_H[0][1];
      V[(i_tmp + V.size(0)) - 2] =
          (e_H[0][0] * e_H[1][1]) + (e_H[1][0] * e_H[0][1]);
      V[(i_tmp + (V.size(0) * 2)) - 2] = e_H[1][0] * e_H[1][1];
      V[(i_tmp + (V.size(0) * 3)) - 2] =
          (e_H[2][0] * e_H[0][1]) + (e_H[0][0] * e_H[2][1]);
      V[(i_tmp + (V.size(0) * 4)) - 2] =
          (e_H[2][0] * e_H[1][1]) + (e_H[1][0] * e_H[2][1]);
      V[(i_tmp + (V.size(0) * 5)) - 2] = e_H[2][0] * e_H[2][1];
      // --------------------------------------------------------------------------
      f_H[0] = e_H[0][0] * e_H[0][0];
      H_tmp = e_H[0][0] * e_H[1][0];
      f_H[1] = H_tmp + H_tmp;
      f_H[2] = e_H[1][0] * e_H[1][0];
      b_H_tmp = e_H[0][0] * e_H[2][0];
      f_H[3] = b_H_tmp + b_H_tmp;
      c_H_tmp = e_H[1][0] * e_H[2][0];
      f_H[4] = c_H_tmp + c_H_tmp;
      f_H[5] = e_H[2][0] * e_H[2][0];
      g_H[0] = e_H[0][1] * e_H[0][1];
      d_H_tmp = e_H[0][1] * e_H[1][1];
      g_H[1] = d_H_tmp + d_H_tmp;
      g_H[2] = e_H[1][1] * e_H[1][1];
      e_H_tmp = e_H[0][1] * e_H[2][1];
      g_H[3] = e_H_tmp + e_H_tmp;
      f_H_tmp = e_H[1][1] * e_H[2][1];
      g_H[4] = f_H_tmp + f_H_tmp;
      g_H[5] = e_H[2][1] * e_H[2][1];
      for (int i27{0}; i27 < 6; i27++) {
        V[(i_tmp + (V.size(0) * i27)) - 1] = f_H[i27] - g_H[i27];
      }
    }
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    // --------------------------------------------------------------------------
    p = true;
    i22 = V.size(0);
    for (int k{0}; k < 6; k++) {
      for (int b_k{0}; b_k < i22; b_k++) {
        double b_x;
        b_x = V[b_k + (V.size(0) * k)];
        if (p) {
          if ((std::isinf(b_x)) || (std::isnan(b_x))) {
            p = false;
          }
        } else {
          p = false;
        }
      }
    }
    if (p) {
      coder::internal::e_svd(V, U, s, b_U);
    } else {
      int p_loop_ub;
      r3.set_size(V.size(0), 6);
      p_loop_ub = V.size(0);
      if ((static_cast<int>((6 * V.size(0)) < 4)) != 0) {
        for (int i23{0}; i23 < 6; i23++) {
          for (i24 = 0; i24 < p_loop_ub; i24++) {
            r3[i24 + (r3.size(0) * i23)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i24)

        for (int i23 = 0; i23 < 6; i23++) {
          for (i24 = 0; i24 < p_loop_ub; i24++) {
            r3[i24 + (r3.size(0) * i23)] = 0.0;
          }
        }
      }
      coder::internal::e_svd(r3, U1, s1, V1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i26)

      for (int i25 = 0; i25 < 6; i25++) {
        for (i26 = 0; i26 < 6; i26++) {
          b_U[i25][i26] = rtNaN;
        }
      }
    }
    //  b = [B11, B12, B22, B13, B23, B33]
    //  Compute the intrinsic matrix
    // --------------------------------------------------------------------------
    d_err = 0;
    cy_tmp = (b_U[5][1] * b_U[5][3]) - (b_U[5][0] * b_U[5][4]);
    b_cy_tmp = (b_U[5][0] * b_U[5][2]) - (b_U[5][1] * b_U[5][1]);
    b_cy = cy_tmp / b_cy_tmp;
    lambda =
        b_U[5][5] - (((b_U[5][3] * b_U[5][3]) + (b_cy * cy_tmp)) / b_U[5][0]);
    d = lambda / b_U[5][0];
    if ((d < 0.0) || (((lambda * b_U[5][0]) / b_cy_tmp) < 0.0)) {
      // error(message('vision:calibrate:complexCameraMatrix'));
      d_err = -301;
    }
    fx = std::sqrt(d);
    fy = std::sqrt((lambda * b_U[5][0]) /
                   ((b_U[5][0] * b_U[5][2]) - (b_U[5][1] * b_U[5][1])));
    skew_tmp = fx * fx;
    skew = (((-b_U[5][1]) * skew_tmp) * fy) / lambda;
    A[0][0] = fx;
    A[1][0] = skew;
    A[2][0] = ((skew * b_cy) / fx) - ((b_U[5][3] * skew_tmp) / lambda);
    A[0][1] = 0.0;
    A[1][1] = fy;
    A[2][1] = b_cy;
    A[0][2] = 0.0;
    A[1][2] = 0.0;
    A[2][2] = 1.0;
    c_err = d_err;
    if (d_err == 0) {
      int i28;
      int q_loop_ub;
      int s_loop_ub;
      int t_loop_ub;
      //  Compute translation and rotation vectors for all images
      // --------------------------------------------------------------------------
      b_rotationVectors.set_size(3, H.size(2));
      b_translationVectors.set_size(3, H.size(2));
      coder::inv(A, Ainv);
      i28 = H.size(2);
      for (int m_i{0}; m_i < i28; m_i++) {
        double b_a;
        double scale;
        double y;
        y = 0.0;
        scale = 3.3121686421112381E-170;
        for (int c_k{0}; c_k < 3; c_k++) {
          double absxk;
          absxk = std::abs(((Ainv[0][c_k] * H[9 * m_i]) +
                            (Ainv[1][c_k] * H[(9 * m_i) + 1])) +
                           (Ainv[2][c_k] * H[(9 * m_i) + 2]));
          if (absxk > scale) {
            double b_t;
            b_t = scale / absxk;
            y = ((y * b_t) * b_t) + 1.0;
            scale = absxk;
          } else {
            double b_t;
            b_t = absxk / scale;
            y += b_t * b_t;
          }
        }
        y = scale * std::sqrt(y);
        b_a = 1.0 / y;
        //  3D rotation matrix
        for (int i29{0}; i29 < 3; i29++) {
          r1_tmp[i29][0] = b_a * Ainv[i29][0];
          r1_tmp[i29][1] = b_a * Ainv[i29][1];
          r1_tmp[i29][2] = b_a * Ainv[i29][2];
        }
        for (int i30{0}; i30 < 3; i30++) {
          double b_d1;
          double d2;
          double d3;
          double d4;
          double d5;
          b_d1 = r1_tmp[0][i30];
          d2 = r1_tmp[1][i30];
          d3 = r1_tmp[2][i30];
          d4 = ((b_d1 * H[9 * m_i]) + (d2 * H[(9 * m_i) + 1])) +
               (d3 * H[(9 * m_i) + 2]);
          d5 = ((b_d1 * H[(9 * m_i) + 3]) + (d2 * H[(9 * m_i) + 4])) +
               (d3 * H[(9 * m_i) + 5]);
          b_r2[i30] = d5;
          c_r1[i30] = d4;
          b_r1[0][i30] = d4;
          b_r1[1][i30] = d5;
        }
        b_r1[2][0] = (c_r1[1] * b_r2[2]) - (b_r2[1] * c_r1[2]);
        b_r1[2][1] = (b_r2[0] * c_r1[2]) - (c_r1[0] * b_r2[2]);
        b_r1[2][2] = (c_r1[0] * b_r2[1]) - (b_r2[0] * c_r1[1]);
        coder::vision::internal::calibration::rodriguesMatrixToVector(b_r1,
                                                                      b_dv);
        (*((double(*)[3])(&b_rotationVectors[3 * m_i])))[0] = b_dv[0];
        (*((double(*)[3])(&b_rotationVectors[3 * m_i])))[1] = b_dv[1];
        (*((double(*)[3])(&b_rotationVectors[3 * m_i])))[2] = b_dv[2];
        //  translation vector
        for (int i33{0}; i33 < 3; i33++) {
          b_translationVectors[i33 + (3 * m_i)] =
              ((r1_tmp[0][i33] * H[(9 * m_i) + 6]) +
               (r1_tmp[1][i33] * H[(9 * m_i) + 7])) +
              (r1_tmp[2][i33] * H[(9 * m_i) + 8]);
        }
      }
      // iniltialParams =
      // my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints,
      // 3));
      initialParams->RadialDistortion[0] = 0.0;
      initialParams->RadialDistortion[1] = 0.0;
      initialParams->RadialDistortion[2] = 0.0;
      initialParams->TangentialDistortion[0] = 0.0;
      initialParams->ImageSize[0] = c_imageSize[0];
      initialParams->TangentialDistortion[1] = 0.0;
      initialParams->ImageSize[1] = c_imageSize[1];
      initialParams->WorldPoints.set_size(c_worldPoints.size(0),
                                          c_worldPoints.size(1));
      q_loop_ub = c_worldPoints.size(1);
      for (int i31{0}; i31 < q_loop_ub; i31++) {
        int r_loop_ub;
        r_loop_ub = c_worldPoints.size(0);
        for (int i32{0}; i32 < r_loop_ub; i32++) {
          initialParams
              ->WorldPoints[i32 + (initialParams->WorldPoints.size(0) * i31)] =
              c_worldPoints[i32 + (c_worldPoints.size(0) * i31)];
        }
      }
      initialParams->WorldUnits.set_size(1, 1);
      initialParams->WorldUnits[0] = 'm';
      initialParams->EstimateSkew = false;
      initialParams->NumRadialDistortionCoefficients = 3.0;
      initialParams->EstimateTangentialDistortion = false;
      initialParams->RotationVectors.set_size(b_rotationVectors.size(1), 3);
      initialParams->TranslationVectors.set_size(b_translationVectors.size(1),
                                                 3);
      s_loop_ub = b_rotationVectors.size(1);
      t_loop_ub = b_translationVectors.size(1);
      for (int i34{0}; i34 < 3; i34++) {
        for (int i35{0}; i35 < s_loop_ub; i35++) {
          initialParams
              ->RotationVectors[i35 + (initialParams->RotationVectors.size(0) *
                                       i34)] =
              b_rotationVectors[i34 + (3 * i35)];
        }
        for (int i36{0}; i36 < t_loop_ub; i36++) {
          initialParams->TranslationVectors
              [i36 + (initialParams->TranslationVectors.size(0) * i34)] =
              b_translationVectors[i34 + (3 * i36)];
        }
        initialParams->IntrinsicMatrix[i34][0] = A[0][i34];
        initialParams->IntrinsicMatrix[i34][1] = A[1][i34];
        initialParams->IntrinsicMatrix[i34][2] = A[2][i34];
      }
    } else {
      lobj_1[1]
          .init(c_imageSize)
          ->toStruct(initialParams->RadialDistortion,
                     initialParams->TangentialDistortion,
                     initialParams->ImageSize, t9_WorldUnits, &t9_EstimateSkew,
                     &t9_NumRadialDistortionCoefficients,
                     &t9_EstimateTangentialDistortion,
                     initialParams->IntrinsicMatrix);
      initialParams->WorldPoints.set_size(0, 2);
      initialParams->WorldUnits.set_size(1, 2);
      initialParams->WorldUnits[0] = t9_WorldUnits[0];
      initialParams->WorldUnits[1] = t9_WorldUnits[1];
      initialParams->EstimateSkew = t9_EstimateSkew;
      initialParams->NumRadialDistortionCoefficients =
          t9_NumRadialDistortionCoefficients;
      initialParams->EstimateTangentialDistortion =
          t9_EstimateTangentialDistortion;
      initialParams->RotationVectors.set_size(0, 3);
      initialParams->TranslationVectors.set_size(0, 3);
    }
  } else {
    lobj_1[0]
        .init(c_imageSize)
        ->toStruct(initialParams->RadialDistortion,
                   initialParams->TangentialDistortion,
                   initialParams->ImageSize, t9_WorldUnits, &t9_EstimateSkew,
                   &t9_NumRadialDistortionCoefficients,
                   &t9_EstimateTangentialDistortion,
                   initialParams->IntrinsicMatrix);
    initialParams->WorldPoints.set_size(0, 2);
    initialParams->WorldUnits.set_size(1, 2);
    initialParams->WorldUnits[0] = t9_WorldUnits[0];
    initialParams->WorldUnits[1] = t9_WorldUnits[1];
    initialParams->EstimateSkew = t9_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients =
        t9_NumRadialDistortionCoefficients;
    initialParams->EstimateTangentialDistortion =
        t9_EstimateTangentialDistortion;
    initialParams->RotationVectors.set_size(0, 3);
    initialParams->TranslationVectors.set_size(0, 3);
  }
  *err = c_err;
}

} // namespace ITER

//
// File trailer for computeInitialParameterEstimate.cpp
//
// [EOF]
//
