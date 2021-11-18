//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeInitialParameterEstimate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "computeInitialParameterEstimate.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_internal_types3.h"
#include "cameraParameters.h"
#include "fitgeotrans.h"
#include "inv.h"
#include "projective2d.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Solve for the camera intriniscs and extrinsics in closed form ignoring
//  distortion.
//
// Arguments    : const coder::array<double, 2U> &c_worldPoints
//                const coder::array<double, 3U> &b_imagePoints
//                const double b_imageSize[2]
//                c_struct_T *initialParams
//                coder::array<bool, 1U> &validIdx
//                int *err
// Return Type  : void
//
void computeInitialParameterEstimate(
    const coder::array<double, 2U> &c_worldPoints,
    const coder::array<double, 3U> &b_imagePoints, const double b_imageSize[2],
    c_struct_T *initialParams, coder::array<bool, 1U> &validIdx, int *err)
{
  coder::b_cameraParameters lobj_1;
  coder::projective2d c_H;
  coder::array<double, 3U> H;
  coder::array<double, 3U> b_H;
  coder::array<double, 2U> b_U1;
  coder::array<double, 2U> b_rotationVectors;
  coder::array<double, 2U> b_translationVectors;
  coder::array<double, 2U> c_imagePoints;
  coder::array<double, 2U> d_U;
  coder::array<double, 2U> d_imagePoints;
  coder::array<double, 2U> d_worldPoints;
  coder::array<double, 2U> e_V;
  coder::array<double, 2U> r3;
  coder::array<double, 1U> b_s1;
  coder::array<double, 1U> s;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r2;
  coder::array<bool, 1U> r1;
  coder::array<bool, 1U> validPointsIdx;
  double b_V1[6][6];
  double e_U[6][6];
  double Ainv[3][3];
  double b_r1[3][3];
  double d_A[3][3];
  double e_H[3][3];
  double r1_tmp[3][3];
  double f_H[6];
  double g_H[6];
  double b_r2[3];
  double c_r1[3];
  double dv[3];
  double t3_NumRadialDistortionCoefficients;
  int b_err;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int end;
  int f_loop_ub;
  int g_loop_ub;
  int i1;
  int i_loop_ub;
  int j_loop_ub;
  int loop_ub;
  int trueCount;
  char t3_WorldUnits[2];
  bool t3_EstimateSkew;
  bool t3_EstimateTangentialDistortion;
  //  Compute homographies for all images
  // --------------------------------------------------------------------------
  b_err = 0;
  // w1 = warning('Error', 'MATLAB:nearlySingularMatrix'); %#ok
  // w2 = warning('Error', 'images:maketform:conditionNumberofAIsHigh'); %#ok
  H.set_size(3, 3, b_imagePoints.size(2));
  loop_ub = b_imagePoints.size(2);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    for (int i2{0}; i2 < 3; i2++) {
      H[(3 * i2) + (9 * b_i)] = 0.0;
      H[((3 * i2) + (9 * b_i)) + 1] = 0.0;
      H[((3 * i2) + (9 * b_i)) + 2] = 0.0;
    }
  }
  i1 = b_imagePoints.size(2);
  if (0 <= (i1 - 1)) {
    b_loop_ub = b_imagePoints.size(0);
    c_loop_ub = b_imagePoints.size(1);
    d_loop_ub = b_imagePoints.size(0) - 1;
    e_loop_ub = b_imagePoints.size(1) - 1;
    f_loop_ub = c_worldPoints.size(1);
  }
  for (int c_i{0}; c_i < i1; c_i++) {
    double d_H;
    int b_end;
    int b_trueCount;
    int h_loop_ub;
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
    h_loop_ub = r1.size(0);
    for (int i7{0}; i7 < h_loop_ub; i7++) {
      validPointsIdx[i7] = !r1[i7];
    }
    b_end = validPointsIdx.size(0) - 1;
    b_trueCount = 0;
    for (int h_i{0}; h_i <= b_end; h_i++) {
      if (validPointsIdx[h_i]) {
        b_trueCount++;
      }
    }
    r2.set_size(b_trueCount);
    partialTrueCount = 0;
    for (int k_i{0}; k_i <= b_end; k_i++) {
      if (validPointsIdx[k_i]) {
        r2[partialTrueCount] = k_i + 1;
        partialTrueCount++;
      }
    }
    d_worldPoints.set_size(r2.size(0), c_worldPoints.size(1));
    for (int i12{0}; i12 < f_loop_ub; i12++) {
      int k_loop_ub;
      k_loop_ub = r2.size(0);
      for (int i15{0}; i15 < k_loop_ub; i15++) {
        d_worldPoints[i15 + (d_worldPoints.size(0) * i12)] =
            c_worldPoints[(r2[i15] + (c_worldPoints.size(0) * i12)) - 1];
      }
    }
    d_imagePoints.set_size(r2.size(0), b_imagePoints.size(1));
    for (int i14{0}; i14 <= e_loop_ub; i14++) {
      int m_loop_ub;
      m_loop_ub = r2.size(0);
      for (int i18{0}; i18 < m_loop_ub; i18++) {
        d_imagePoints[i18 + (d_imagePoints.size(0) * i14)] =
            c_imagePoints[(r2[i18] + (c_imagePoints.size(0) * i14)) - 1];
      }
    }
    coder::fitgeotrans(d_worldPoints, d_imagePoints, &c_H);
    for (int i17{0}; i17 < 3; i17++) {
      H[(3 * i17) + (9 * c_i)] = c_H.T[0][i17];
      H[((3 * i17) + (9 * c_i)) + 1] = c_H.T[1][i17];
      H[((3 * i17) + (9 * c_i)) + 2] = c_H.T[2][i17];
    }
    d_H = H[(9 * c_i) + 8];
    for (int i21{0}; i21 < 3; i21++) {
      H[(3 * i21) + (9 * c_i)] = H[(3 * i21) + (9 * c_i)] / d_H;
      H[((3 * i21) + (9 * c_i)) + 1] = H[((3 * i21) + (9 * c_i)) + 1] / d_H;
      H[((3 * i21) + (9 * c_i)) + 2] = H[((3 * i21) + (9 * c_i)) + 2] / d_H;
    }
    //  catch
    //      validIdx(i) = false;
    //  end
  }
  // warning(w1);
  // warning(w2);
  end = b_imagePoints.size(2) - 1;
  trueCount = 0;
  for (int e_i{0}; e_i <= end; e_i++) {
    trueCount++;
  }
  r.set_size(trueCount);
  for (int g_i{0}; g_i <= end; g_i++) {
    r[g_i] = g_i + 1;
  }
  b_H.set_size(3, 3, r.size(0));
  g_loop_ub = r.size(0);
  for (int i6{0}; i6 < g_loop_ub; i6++) {
    for (int i8{0}; i8 < 3; i8++) {
      b_H[(3 * i8) + (9 * i6)] = H[(3 * i8) + (9 * (r[i6] - 1))];
      b_H[((3 * i8) + (9 * i6)) + 1] = H[((3 * i8) + (9 * (r[i6] - 1))) + 1];
      b_H[((3 * i8) + (9 * i6)) + 2] = H[((3 * i8) + (9 * (r[i6] - 1))) + 2];
    }
  }
  H.set_size(3, 3, b_H.size(2));
  i_loop_ub = b_H.size(2);
  for (int i9{0}; i9 < i_loop_ub; i9++) {
    for (int i10{0}; i10 < 3; i10++) {
      H[(3 * i10) + (9 * i9)] = b_H[(3 * i10) + (9 * i9)];
      H[((3 * i10) + (9 * i9)) + 1] = b_H[((3 * i10) + (9 * i9)) + 1];
      H[((3 * i10) + (9 * i9)) + 2] = b_H[((3 * i10) + (9 * i9)) + 2];
    }
  }
  if (H.size(2) < 2) {
    // error(message('vision:calibrate:notEnoughValidHomographies'));
    b_err = -201;
  }
  validIdx.set_size(b_imagePoints.size(2));
  j_loop_ub = b_imagePoints.size(2);
  for (int i11{0}; i11 < j_loop_ub; i11++) {
    validIdx[i11] = true;
  }
  if (b_err == 0) {
    double b_cy_tmp;
    double cy;
    double cy_tmp;
    double fx;
    double fy;
    double lambda;
    double skew;
    double skew_tmp;
    int i19;
    int i23;
    int i29;
    int p_loop_ub;
    int r_loop_ub;
    int s_loop_ub;
    int unnamed_idx_0;
    bool p;
    //  Vb = 0
    // --------------------------------------------------------------------------
    unnamed_idx_0 = 2 * H.size(2);
    e_V.set_size(unnamed_idx_0, 6);
    for (int i16{0}; i16 < 6; i16++) {
      for (int i20{0}; i20 < unnamed_idx_0; i20++) {
        e_V[i20 + (e_V.size(0) * i16)] = 0.0;
      }
    }
    i19 = H.size(2);
    for (int m_i{0}; m_i < i19; m_i++) {
      int i_tmp;
      for (int i22{0}; i22 < 3; i22++) {
        e_H[i22][0] = H[i22 + (9 * m_i)];
        e_H[i22][1] = H[(i22 + (9 * m_i)) + 3];
        e_H[i22][2] = H[(i22 + (9 * m_i)) + 6];
      }
      double H_tmp;
      double b_H_tmp;
      double c_H_tmp;
      double d_H_tmp;
      double e_H_tmp;
      double f_H_tmp;
      // --------------------------------------------------------------------------
      i_tmp = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(static_cast<int>(m_i + 1))) << 1UL));
      e_V[i_tmp - 2] = e_H[0][0] * e_H[0][1];
      e_V[(i_tmp + e_V.size(0)) - 2] =
          (e_H[0][0] * e_H[1][1]) + (e_H[1][0] * e_H[0][1]);
      e_V[(i_tmp + (e_V.size(0) * 2)) - 2] = e_H[1][0] * e_H[1][1];
      e_V[(i_tmp + (e_V.size(0) * 3)) - 2] =
          (e_H[2][0] * e_H[0][1]) + (e_H[0][0] * e_H[2][1]);
      e_V[(i_tmp + (e_V.size(0) * 4)) - 2] =
          (e_H[2][0] * e_H[1][1]) + (e_H[1][0] * e_H[2][1]);
      e_V[(i_tmp + (e_V.size(0) * 5)) - 2] = e_H[2][0] * e_H[2][1];
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
      for (int i28{0}; i28 < 6; i28++) {
        e_V[(i_tmp + (e_V.size(0) * i28)) - 1] = f_H[i28] - g_H[i28];
      }
    }
    //  lambda * B = inv(A)' * inv(A), where A is the intrinsic matrix
    // --------------------------------------------------------------------------
    p = true;
    i23 = e_V.size(0);
    for (int k{0}; k < 6; k++) {
      for (int b_k{0}; b_k < i23; b_k++) {
        double b_x;
        b_x = e_V[b_k + (e_V.size(0) * k)];
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
      coder::internal::c_svd(e_V, d_U, s, e_U);
    } else {
      int o_loop_ub;
      r3.set_size(e_V.size(0), 6);
      o_loop_ub = e_V.size(0);
      for (int i24{0}; i24 < 6; i24++) {
        for (int i25{0}; i25 < o_loop_ub; i25++) {
          r3[i25 + (r3.size(0) * i24)] = 0.0;
        }
      }
      coder::internal::c_svd(r3, b_U1, b_s1, b_V1);
      for (int i26{0}; i26 < 6; i26++) {
        for (int i27{0}; i27 < 6; i27++) {
          e_U[i26][i27] = rtNaN;
        }
      }
    }
    //  b = [B11, B12, B22, B13, B23, B33]
    //  Compute the intrinsic matrix
    // --------------------------------------------------------------------------
    cy_tmp = (e_U[5][1] * e_U[5][3]) - (e_U[5][0] * e_U[5][4]);
    b_cy_tmp = (e_U[5][0] * e_U[5][2]) - (e_U[5][1] * e_U[5][1]);
    cy = cy_tmp / b_cy_tmp;
    lambda =
        e_U[5][5] - (((e_U[5][3] * e_U[5][3]) + (cy * cy_tmp)) / e_U[5][0]);
    fx = std::sqrt(lambda / e_U[5][0]);
    fy = std::sqrt((lambda * e_U[5][0]) / b_cy_tmp);
    skew_tmp = fx * fx;
    skew = (((-e_U[5][1]) * skew_tmp) * fy) / lambda;
    d_A[0][0] = fx;
    d_A[1][0] = skew;
    d_A[2][0] = ((skew * cy) / fx) - ((e_U[5][3] * skew_tmp) / lambda);
    d_A[0][1] = 0.0;
    d_A[1][1] = fy;
    d_A[2][1] = cy;
    d_A[0][2] = 0.0;
    d_A[1][2] = 0.0;
    d_A[2][2] = 1.0;
    //  Compute translation and rotation vectors for all images
    // --------------------------------------------------------------------------
    b_rotationVectors.set_size(3, H.size(2));
    b_translationVectors.set_size(3, H.size(2));
    coder::inv(d_A, Ainv);
    i29 = H.size(2);
    for (int o_i{0}; o_i < i29; o_i++) {
      double a;
      double scale;
      double y;
      y = 0.0;
      scale = 3.3121686421112381E-170;
      for (int c_k{0}; c_k < 3; c_k++) {
        double absxk;
        absxk = std::abs(
            ((Ainv[0][c_k] * H[9 * o_i]) + (Ainv[1][c_k] * H[(9 * o_i) + 1])) +
            (Ainv[2][c_k] * H[(9 * o_i) + 2]));
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
      a = 1.0 / y;
      //  3D rotation matrix
      for (int i30{0}; i30 < 3; i30++) {
        r1_tmp[i30][0] = a * Ainv[i30][0];
        r1_tmp[i30][1] = a * Ainv[i30][1];
        r1_tmp[i30][2] = a * Ainv[i30][2];
      }
      for (int i31{0}; i31 < 3; i31++) {
        double b_d1;
        double d;
        double d2;
        double d3;
        double d4;
        d = r1_tmp[0][i31];
        b_d1 = r1_tmp[1][i31];
        d2 = r1_tmp[2][i31];
        d3 = ((d * H[9 * o_i]) + (b_d1 * H[(9 * o_i) + 1])) +
             (d2 * H[(9 * o_i) + 2]);
        d4 = ((d * H[(9 * o_i) + 3]) + (b_d1 * H[(9 * o_i) + 4])) +
             (d2 * H[(9 * o_i) + 5]);
        b_r2[i31] = d4;
        c_r1[i31] = d3;
        b_r1[0][i31] = d3;
        b_r1[1][i31] = d4;
      }
      b_r1[2][0] = (c_r1[1] * b_r2[2]) - (b_r2[1] * c_r1[2]);
      b_r1[2][1] = (b_r2[0] * c_r1[2]) - (c_r1[0] * b_r2[2]);
      b_r1[2][2] = (c_r1[0] * b_r2[1]) - (b_r2[0] * c_r1[1]);
      coder::vision::internal::calibration::rodriguesMatrixToVector(b_r1, dv);
      (*((double(*)[3])(&b_rotationVectors[3 * o_i])))[0] = dv[0];
      (*((double(*)[3])(&b_rotationVectors[3 * o_i])))[1] = dv[1];
      (*((double(*)[3])(&b_rotationVectors[3 * o_i])))[2] = dv[2];
      //  translation vector
      for (int i34{0}; i34 < 3; i34++) {
        b_translationVectors[i34 + (3 * o_i)] =
            ((r1_tmp[0][i34] * H[(9 * o_i) + 6]) +
             (r1_tmp[1][i34] * H[(9 * o_i) + 7])) +
            (r1_tmp[2][i34] * H[(9 * o_i) + 8]);
      }
    }
    // iniltialParams =
    // my_CameraParameters(radialCoeffs,worldPoints,worldUnits,cameraModel,rvecs,tvecs,A',size(imagePoints,
    // 3));
    initialParams->RadialDistortion[0] = 0.0;
    initialParams->RadialDistortion[1] = 0.0;
    initialParams->RadialDistortion[2] = 0.0;
    initialParams->TangentialDistortion[0] = 0.0;
    initialParams->ImageSize[0] = b_imageSize[0];
    initialParams->TangentialDistortion[1] = 0.0;
    initialParams->ImageSize[1] = b_imageSize[1];
    initialParams->WorldPoints.set_size(c_worldPoints.size(0),
                                        c_worldPoints.size(1));
    p_loop_ub = c_worldPoints.size(1);
    for (int i32{0}; i32 < p_loop_ub; i32++) {
      int q_loop_ub;
      q_loop_ub = c_worldPoints.size(0);
      for (int i33{0}; i33 < q_loop_ub; i33++) {
        initialParams
            ->WorldPoints[i33 + (initialParams->WorldPoints.size(0) * i32)] =
            c_worldPoints[i33 + (c_worldPoints.size(0) * i32)];
      }
    }
    initialParams->WorldUnits.set_size(1, 1);
    initialParams->WorldUnits[0] = 'm';
    initialParams->EstimateSkew = false;
    initialParams->NumRadialDistortionCoefficients = 3.0;
    initialParams->EstimateTangentialDistortion = false;
    initialParams->RotationVectors.set_size(b_rotationVectors.size(1), 3);
    initialParams->TranslationVectors.set_size(b_translationVectors.size(1), 3);
    r_loop_ub = b_rotationVectors.size(1);
    s_loop_ub = b_translationVectors.size(1);
    for (int i35{0}; i35 < 3; i35++) {
      for (int i36{0}; i36 < r_loop_ub; i36++) {
        initialParams
            ->RotationVectors[i36 + (initialParams->RotationVectors.size(0) *
                                     i35)] = b_rotationVectors[i35 + (3 * i36)];
      }
      for (int i37{0}; i37 < s_loop_ub; i37++) {
        initialParams->TranslationVectors
            [i37 + (initialParams->TranslationVectors.size(0) * i35)] =
            b_translationVectors[i35 + (3 * i37)];
      }
      initialParams->IntrinsicMatrix[i35][0] = d_A[0][i35];
      initialParams->IntrinsicMatrix[i35][1] = d_A[1][i35];
      initialParams->IntrinsicMatrix[i35][2] = d_A[2][i35];
    }
  } else {
    // iniltialParams = my_CameraParameters(zeros(1,3),worldPoints,'',
    // cameraModel,zeros(1,3),zeros(1,3),zeros(3,3),[]);
    for (int i13{0}; i13 < 3; i13++) {
      lobj_1.IntrinsicMatrixInternal[i13][0] = static_cast<double>(iv[i13][0]);
      lobj_1.IntrinsicMatrixInternal[i13][1] = static_cast<double>(iv[i13][1]);
      lobj_1.IntrinsicMatrixInternal[i13][2] = static_cast<double>(iv[i13][2]);
      lobj_1.RadialDistortion[i13] = 0.0;
    }
    lobj_1.TangentialDistortion[0] = 0.0;
    lobj_1.TangentialDistortion[1] = 0.0;
    lobj_1.ImageSize[0] = b_imageSize[0];
    lobj_1.ImageSize[1] = b_imageSize[1];
    lobj_1.WorldUnits[0] = 'm';
    lobj_1.WorldUnits[1] = 'm';
    lobj_1.EstimateSkew = false;
    lobj_1.NumRadialDistortionCoefficients = 2.0;
    lobj_1.EstimateTangentialDistortion = false;
    lobj_1.toStruct(
        initialParams->RadialDistortion, initialParams->TangentialDistortion,
        initialParams->ImageSize, t3_WorldUnits, &t3_EstimateSkew,
        &t3_NumRadialDistortionCoefficients, &t3_EstimateTangentialDistortion,
        initialParams->IntrinsicMatrix);
    initialParams->WorldPoints.set_size(0, 2);
    initialParams->WorldUnits.set_size(1, 2);
    initialParams->WorldUnits[0] = t3_WorldUnits[0];
    initialParams->WorldUnits[1] = t3_WorldUnits[1];
    initialParams->EstimateSkew = t3_EstimateSkew;
    initialParams->NumRadialDistortionCoefficients =
        t3_NumRadialDistortionCoefficients;
    initialParams->EstimateTangentialDistortion =
        t3_EstimateTangentialDistortion;
    initialParams->RotationVectors.set_size(0, 3);
    initialParams->TranslationVectors.set_size(0, 3);
  }
  *err = b_err;
}

//
// File trailer for computeInitialParameterEstimate.cpp
//
// [EOF]
//
