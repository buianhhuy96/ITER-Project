//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "preprocessImages.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_initialize.h"
#include "ITER_API_v2_types.h"
#include "ImageTransformer.h"
#include "cameraParameters.h"
#include "colon.h"
#include "distortPoints.h"
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                const struct1_T *camera_params
//                coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
void preprocessImages(const coder::array<unsigned char, 4U> &images,
                      const struct1_T *camera_params,
                      coder::array<unsigned char, 4U> &gray_images)
{
  static const char cv2[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char cv1[5]{'u', 'i', 'n', 't', '8'};
  static const char b_outputView[4]{'s', 'a', 'm', 'e'};
  static const char x2[4]{'s', 'a', 'm', 'e'};
  coder::d_cameraParameters camera_params_o;
  coder::vision::internal::calibration::b_ImageTransformer *b_this;
  coder::array<double, 2U> b_y;
  coder::array<double, 2U> g_X;
  coder::array<double, 2U> h_Y;
  coder::array<double, 2U> j_X;
  coder::array<double, 2U> ptsOut;
  coder::array<double, 2U> y;
  coder::array<double, 1U> b_ptsOut;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<unsigned char, 3U> b_images;
  coder::array<unsigned char, 3U> current_images;
  coder::array<unsigned char, 3U> fillValues;
  coder::array<unsigned char, 3U> j_J;
  coder::array<unsigned char, 3U> k_J;
  coder::array<unsigned char, 2U> b_current_images;
  coder::array<char, 2U> c_a;
  double b_intrinsicMatrix[3][3];
  double radialDist[3];
  double newOrigin[2];
  double tangentialDist[2];
  unsigned int varargin_2[3];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int h_loop_ub;
  int i17;
  int loop_ub;
  if (!isInitialized_ITER_API_v2) {
    ITER_API_v2_initialize();
  }
  for (int b_i{0}; b_i < 3; b_i++) {
    camera_params_o.IntrinsicMatrixInternal[b_i][0] =
        camera_params->IntrinsicMatrix[0][b_i];
    camera_params_o.IntrinsicMatrixInternal[b_i][1] =
        camera_params->IntrinsicMatrix[1][b_i];
    camera_params_o.IntrinsicMatrixInternal[b_i][2] =
        camera_params->IntrinsicMatrix[2][b_i];
  }
  camera_params_o.RadialDistortion[0] = camera_params->RadialDistortion[0];
  camera_params_o.RadialDistortion[1] = camera_params->RadialDistortion[1];
  camera_params_o.RadialDistortion[2] = camera_params->RadialDistortion[2];
  camera_params_o.TangentialDistortion[0] =
      camera_params->TangentialDistortion[0];
  camera_params_o.TangentialDistortion[1] =
      camera_params->TangentialDistortion[1];
  camera_params_o.ImageSize[0] = camera_params->ImageSize[0];
  camera_params_o.ImageSize[1] = camera_params->ImageSize[1];
  camera_params_o.RotationVectors.set_size(
      camera_params->RotationVectors.size(0), 3);
  loop_ub = camera_params->RotationVectors.size(0);
  for (int i1{0}; i1 < 3; i1++) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      camera_params_o
          .RotationVectors[i2 +
                           (camera_params_o.RotationVectors.size(0) * i1)] =
          camera_params
              ->RotationVectors[i2 +
                                (camera_params->RotationVectors.size(0) * i1)];
    }
  }
  camera_params_o.TranslationVectors.set_size(
      camera_params->TranslationVectors.size(0), 3);
  b_loop_ub = camera_params->TranslationVectors.size(0);
  for (int i3{0}; i3 < 3; i3++) {
    for (int i4{0}; i4 < b_loop_ub; i4++) {
      camera_params_o
          .TranslationVectors[i4 + (camera_params_o.TranslationVectors.size(0) *
                                    i3)] =
          camera_params->TranslationVectors
              [i4 + (camera_params->TranslationVectors.size(0) * i3)];
    }
  }
  camera_params_o.WorldPoints.set_size(camera_params->WorldPoints.size(0), 2);
  c_loop_ub = camera_params->WorldPoints.size(0);
  for (int i5{0}; i5 < 2; i5++) {
    for (int i6{0}; i6 < c_loop_ub; i6++) {
      camera_params_o
          .WorldPoints[i6 + (camera_params_o.WorldPoints.size(0) * i5)] =
          camera_params
              ->WorldPoints[i6 + (camera_params->WorldPoints.size(0) * i5)];
    }
  }
  camera_params_o.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  camera_params_o.DetectedKeypoints.set_size(
      camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  d_loop_ub = camera_params->DetectedKeypoints.size(1);
  for (int i7{0}; i7 < d_loop_ub; i7++) {
    int e_loop_ub;
    e_loop_ub = camera_params->DetectedKeypoints.size(0);
    for (int i8{0}; i8 < e_loop_ub; i8++) {
      camera_params_o
          .DetectedKeypoints[i8 +
                             (camera_params_o.DetectedKeypoints.size(0) * i7)] =
          camera_params->DetectedKeypoints
              [i8 + (camera_params->DetectedKeypoints.size(0) * i7)];
    }
  }
  if ((camera_params->ReprojectionErrors.size(0) == 0) ||
      (camera_params->ReprojectionErrors.size(2) == 0)) {
    camera_params_o.ReprojectionErrors.set_size(0, 2, 1);
  } else {
    int f_loop_ub;
    camera_params_o.ReprojectionErrors.set_size(
        camera_params->ReprojectionErrors.size(0), 2,
        camera_params->ReprojectionErrors.size(2));
    f_loop_ub = camera_params->ReprojectionErrors.size(2);
    for (int i9{0}; i9 < f_loop_ub; i9++) {
      int g_loop_ub;
      g_loop_ub = camera_params->ReprojectionErrors.size(0);
      for (int i10{0}; i10 < 2; i10++) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          camera_params_o.ReprojectionErrors
              [(i11 + (camera_params_o.ReprojectionErrors.size(0) * i10)) +
               ((camera_params_o.ReprojectionErrors.size(0) * 2) * i9)] =
              camera_params->ReprojectionErrors
                  [(i11 + (camera_params->ReprojectionErrors.size(0) * i10)) +
                   ((camera_params->ReprojectionErrors.size(0) * 2) * i9)];
        }
      }
    }
  }
  camera_params_o.UndistortMap.XBounds[0] = -1.0;
  camera_params_o.UndistortMap.XBounds[1] = -1.0;
  camera_params_o.UndistortMap.YBounds[0] = -1.0;
  camera_params_o.UndistortMap.YBounds[1] = -1.0;
  camera_params_o.UndistortMap.SizeOfImage.set_size(1, 2);
  camera_params_o.UndistortMap.SizeOfImage[0] = 0.0;
  camera_params_o.UndistortMap.SizeOfImage[1] = 0.0;
  camera_params_o.UndistortMap.SizeOfImage.set_size(1, 3);
  camera_params_o.UndistortMap.SizeOfImage[0] = 0.0;
  camera_params_o.UndistortMap.SizeOfImage[1] = 0.0;
  camera_params_o.UndistortMap.SizeOfImage[2] = 0.0;
  camera_params_o.UndistortMap.ClassOfImage.set_size(1, 1);
  camera_params_o.UndistortMap.ClassOfImage[0] = 'a';
  camera_params_o.UndistortMap.ClassOfImage.set_size(1, 5);
  for (int i12{0}; i12 < 5; i12++) {
    camera_params_o.UndistortMap.ClassOfImage[i12] = b_cv[i12];
  }
  camera_params_o.UndistortMap.OutputView.set_size(1, 1);
  camera_params_o.UndistortMap.OutputView[0] = 'a';
  camera_params_o.UndistortMap.OutputView.set_size(1, 4);
  for (int i13{0}; i13 < 4; i13++) {
    camera_params_o.UndistortMap.OutputView[i13] = x2[i13];
  }
  camera_params_o.UndistortMap.XmapSingle.set_size(2, 2);
  for (int i14{0}; i14 < 2; i14++) {
    camera_params_o.UndistortMap
        .XmapSingle[camera_params_o.UndistortMap.XmapSingle.size(0) * i14] =
        0.0F;
    camera_params_o.UndistortMap
        .XmapSingle[(camera_params_o.UndistortMap.XmapSingle.size(0) * i14) +
                    1] = 0.0F;
  }
  camera_params_o.UndistortMap.YmapSingle.set_size(2, 2);
  for (int i15{0}; i15 < 2; i15++) {
    camera_params_o.UndistortMap
        .YmapSingle[camera_params_o.UndistortMap.YmapSingle.size(0) * i15] =
        0.0F;
    camera_params_o.UndistortMap
        .YmapSingle[(camera_params_o.UndistortMap.YmapSingle.size(0) * i15) +
                    1] = 0.0F;
  }
  gray_images.set_size(images.size(0), images.size(1), 1, images.size(3));
  h_loop_ub = images.size(3);
  for (int i16{0}; i16 < h_loop_ub; i16++) {
    int i_loop_ub;
    i_loop_ub = images.size(1);
    for (int i18{0}; i18 < i_loop_ub; i18++) {
      int k_loop_ub;
      k_loop_ub = images.size(0);
      for (int i19{0}; i19 < k_loop_ub; i19++) {
        gray_images[(i19 + (gray_images.size(0) * i18)) +
                    ((gray_images.size(0) * gray_images.size(1)) * i16)] = 0U;
      }
    }
  }
  i17 = images.size(3);
  for (int c_i{0}; c_i < i17; c_i++) {
    int exitg2;
    int j_loop_ub;
    int m_loop_ub;
    int o_loop_ub;
    int q_loop_ub;
    int s_loop_ub;
    int t_loop_ub;
    int u_loop_ub;
    int unnamed_idx_0;
    int v_loop_ub;
    int w_loop_ub;
    bool b_p;
    bool c_p;
    bool d_p;
    bool exitg1;
    bool p;
    bool sameClass;
    j_loop_ub = images.size(0);
    m_loop_ub = images.size(1);
    o_loop_ub = images.size(2);
    current_images.set_size(images.size(0), images.size(1), images.size(2));
    for (int i20{0}; i20 < o_loop_ub; i20++) {
      for (int i21{0}; i21 < m_loop_ub; i21++) {
        for (int i22{0}; i22 < j_loop_ub; i22++) {
          current_images[(i22 + (current_images.size(0) * i21)) +
                         ((current_images.size(0) * current_images.size(1)) *
                          i20)] =
              images[((i22 + (images.size(0) * i21)) +
                      ((images.size(0) * images.size(1)) * i20)) +
                     (((images.size(0) * images.size(1)) * images.size(2)) *
                      c_i)];
        }
      }
    }
    //  If gray images, convert to RGB
    if (images.size(2) == 3) {
      int current_images_idx_0;
      int current_images_idx_1;
      int p_loop_ub;
      int r_loop_ub;
      p_loop_ub = images.size(0);
      r_loop_ub = images.size(1);
      b_images.set_size(images.size(0), images.size(1), 3);
      for (int i24{0}; i24 < 3; i24++) {
        for (int i25{0}; i25 < r_loop_ub; i25++) {
          for (int i27{0}; i27 < p_loop_ub; i27++) {
            b_images[(i27 + (b_images.size(0) * i25)) +
                     ((b_images.size(0) * b_images.size(1)) * i24)] =
                images[((i27 + (images.size(0) * i25)) +
                        ((images.size(0) * images.size(1)) * i24)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
      coder::rgb2gray(b_images, b_current_images);
      current_images_idx_0 = b_current_images.size(0);
      current_images_idx_1 = b_current_images.size(1);
      current_images.set_size(b_current_images.size(0),
                              b_current_images.size(1), 1);
      for (int i28{0}; i28 < current_images_idx_1; i28++) {
        for (int i29{0}; i29 < current_images_idx_0; i29++) {
          current_images[i29 + (current_images.size(0) * i28)] =
              b_current_images[i29 + (current_images_idx_0 * i28)];
        }
      }
    }
    q_loop_ub = gray_images.size(0);
    r.set_size(gray_images.size(0));
    for (int i23{0}; i23 < q_loop_ub; i23++) {
      r[i23] = i23;
    }
    s_loop_ub = gray_images.size(1);
    r1.set_size(gray_images.size(1));
    for (int i26{0}; i26 < s_loop_ub; i26++) {
      r1[i26] = i26;
    }
    if (current_images.size(2) > 1) {
      fillValues.set_size(1, 1, 3);
      fillValues[0] = 0U;
      fillValues[1] = 0U;
      fillValues[2] = 0U;
    } else {
      fillValues.set_size(1, 1, 1);
      fillValues[0] = 0U;
    }
    varargin_2[0] = static_cast<unsigned int>(current_images.size(0));
    varargin_2[1] = static_cast<unsigned int>(current_images.size(1));
    varargin_2[2] = static_cast<unsigned int>(current_images.size(2));
    p = (camera_params_o.UndistortMap.SizeOfImage.size(1) == 3);
    b_p = p;
    if (p) {
      if (camera_params_o.UndistortMap.SizeOfImage.size(1) != 0) {
        int k;
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) &&
               (k <= (camera_params_o.UndistortMap.SizeOfImage.size(1) - 1))) {
          if (!(camera_params_o.UndistortMap.SizeOfImage[k] ==
                (static_cast<double>(varargin_2[k])))) {
            b_p = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
    }
    sameClass = false;
    if (5 == camera_params_o.UndistortMap.ClassOfImage.size(1)) {
      int kstr;
      kstr = 0;
      do {
        exitg2 = 0;
        if (kstr < 5) {
          if (cv1[kstr] != camera_params_o.UndistortMap.ClassOfImage[kstr]) {
            exitg2 = 1;
          } else {
            kstr++;
          }
        } else {
          sameClass = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    c_p = (camera_params_o.UndistortMap.OutputView.size(1) == 4);
    d_p = c_p;
    if (c_p) {
      if (camera_params_o.UndistortMap.OutputView.size(1) != 0) {
        int b_k;
        d_p = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) &&
               (b_k <= (camera_params_o.UndistortMap.OutputView.size(1) - 1))) {
          if (!(camera_params_o.UndistortMap.OutputView[b_k] == x2[b_k])) {
            d_p = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }
      }
    }
    if (((!b_p) || (!sameClass)) || (!d_p)) {
      double a;
      double b;
      double b_a;
      double b_b;
      double h_n;
      double m;
      int ab_loop_ub;
      int b_ny;
      int i_X;
      int i_Y;
      int nx;
      bool b_bool;
      bool guard1{false};
      bool guard2{false};
      bool guard3{false};
      for (int i30{0}; i30 < 3; i30++) {
        b_intrinsicMatrix[i30][0] =
            camera_params_o.IntrinsicMatrixInternal[0][i30];
        b_intrinsicMatrix[i30][1] =
            camera_params_o.IntrinsicMatrixInternal[1][i30];
        b_intrinsicMatrix[i30][2] =
            camera_params_o.IntrinsicMatrixInternal[2][i30];
      }
      b_this = &camera_params_o.UndistortMap;
      radialDist[0] = camera_params_o.RadialDistortion[0];
      radialDist[1] = camera_params_o.RadialDistortion[1];
      radialDist[2] = camera_params_o.RadialDistortion[2];
      tangentialDist[0] = camera_params_o.TangentialDistortion[0];
      tangentialDist[1] = camera_params_o.TangentialDistortion[1];
      b_this->SizeOfImage.set_size(1, 3);
      b_this->SizeOfImage[0] = static_cast<double>(current_images.size(0));
      b_this->SizeOfImage[1] = static_cast<double>(current_images.size(1));
      b_this->SizeOfImage[2] = static_cast<double>(current_images.size(2));
      b_this->ClassOfImage.set_size(1, 5);
      for (int i32{0}; i32 < 5; i32++) {
        b_this->ClassOfImage[i32] = b_cv[i32];
      }
      b_this->OutputView.set_size(1, 4);
      for (int i36{0}; i36 < 4; i36++) {
        b_this->OutputView[i36] = b_outputView[i36];
      }
      b_this->XBounds[0] = 1.0;
      b_this->XBounds[1] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(1)));
      b_this->YBounds[0] = 1.0;
      b_this->YBounds[1] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(0)));
      a = b_this->XBounds[0];
      b = b_this->XBounds[1];
      guard1 = false;
      guard2 = false;
      guard3 = false;
      if (std::isnan(a)) {
        guard2 = true;
      } else if (std::isnan(b)) {
        guard2 = true;
      } else if (b < a) {
        y.set_size(1, 0);
      } else if (std::isinf(a)) {
        guard3 = true;
      } else if (std::isinf(b)) {
        guard3 = true;
      } else {
        guard1 = true;
      }
      if (guard3) {
        if (a == b) {
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
        if (std::floor(a) == a) {
          int x_loop_ub;
          x_loop_ub = static_cast<int>(std::floor(b - a));
          y.set_size(1, x_loop_ub + 1);
          for (int i38{0}; i38 <= x_loop_ub; i38++) {
            y[i38] = a + (static_cast<double>(i38));
          }
        } else {
          coder::eml_float_colon(a, b, y);
        }
      }
      b_a = b_this->YBounds[0];
      b_b = b_this->YBounds[1];
      guard1 = false;
      guard2 = false;
      guard3 = false;
      if (std::isnan(b_a)) {
        guard2 = true;
      } else if (std::isnan(b_b)) {
        guard2 = true;
      } else if (b_b < b_a) {
        b_y.set_size(1, 0);
      } else if (std::isinf(b_a)) {
        guard3 = true;
      } else if (std::isinf(b_b)) {
        guard3 = true;
      } else {
        guard1 = true;
      }
      if (guard3) {
        if (b_a == b_b) {
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
        if (std::floor(b_a) == b_a) {
          int y_loop_ub;
          y_loop_ub = static_cast<int>(std::floor(b_b - b_a));
          b_y.set_size(1, y_loop_ub + 1);
          for (int i39{0}; i39 <= y_loop_ub; i39++) {
            b_y[i39] = b_a + (static_cast<double>(i39));
          }
        } else {
          coder::eml_float_colon(b_a, b_b, b_y);
        }
      }
      nx = y.size(1);
      b_ny = b_y.size(1);
      g_X.set_size(b_y.size(1), y.size(1));
      h_Y.set_size(b_y.size(1), y.size(1));
      if (y.size(1) != 0) {
        if (b_y.size(1) != 0) {
          for (int j{0}; j < nx; j++) {
            for (int e_i{0}; e_i < b_ny; e_i++) {
              g_X[e_i + (g_X.size(0) * j)] = y[j];
              h_Y[e_i + (h_Y.size(0) * j)] = b_y[e_i];
            }
          }
        }
      }
      i_X = g_X.size(0) * g_X.size(1);
      i_Y = h_Y.size(0) * h_Y.size(1);
      j_X.set_size(i_X, 2);
      for (int i40{0}; i40 < i_X; i40++) {
        j_X[i40] = g_X[i40];
      }
      for (int i41{0}; i41 < i_Y; i41++) {
        j_X[i41 + j_X.size(0)] = h_Y[i41];
      }
      coder::vision::internal::calibration::distortPoints(
          j_X, b_intrinsicMatrix, radialDist, tangentialDist, ptsOut);
      m = (b_this->YBounds[1] - b_this->YBounds[0]) + 1.0;
      h_n = (b_this->XBounds[1] - b_this->XBounds[0]) + 1.0;
      c_a.set_size(1, b_this->ClassOfImage.size(1));
      ab_loop_ub = b_this->ClassOfImage.size(1);
      for (int i42{0}; i42 < ab_loop_ub; i42++) {
        c_a[i42] = b_this->ClassOfImage[i42];
      }
      b_bool = false;
      if (c_a.size(1) == 6) {
        int b_kstr;
        b_kstr = 0;
        do {
          exitg2 = 0;
          if (b_kstr < 6) {
            if (c_a[b_kstr] != cv2[b_kstr]) {
              exitg2 = 1;
            } else {
              b_kstr++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }
      if (!b_bool) {
        int bb_loop_ub;
        int cb_loop_ub;
        int num_idx_0_tmp;
        int num_idx_1_tmp_tmp;
        num_idx_1_tmp_tmp = static_cast<int>(h_n);
        bb_loop_ub = ptsOut.size(0);
        b_ptsOut.set_size(ptsOut.size(0));
        for (int i43{0}; i43 < bb_loop_ub; i43++) {
          b_ptsOut[i43] = ptsOut[i43];
        }
        num_idx_0_tmp = static_cast<int>(m);
        b_this->XmapSingle.set_size(num_idx_0_tmp, num_idx_1_tmp_tmp);
        for (int i44{0}; i44 < num_idx_1_tmp_tmp; i44++) {
          for (int i45{0}; i45 < num_idx_0_tmp; i45++) {
            b_this->XmapSingle[i45 + (b_this->XmapSingle.size(0) * i44)] =
                static_cast<float>(
                    b_ptsOut[i45 + ((static_cast<int>(m)) * i44)]);
          }
        }
        cb_loop_ub = ptsOut.size(0);
        b_ptsOut.set_size(ptsOut.size(0));
        for (int i46{0}; i46 < cb_loop_ub; i46++) {
          b_ptsOut[i46] = ptsOut[i46 + ptsOut.size(0)];
        }
        b_this->YmapSingle.set_size(num_idx_0_tmp, num_idx_1_tmp_tmp);
        for (int i47{0}; i47 < num_idx_1_tmp_tmp; i47++) {
          for (int i48{0}; i48 < num_idx_0_tmp; i48++) {
            b_this->YmapSingle[i48 + (b_this->YmapSingle.size(0) * i47)] =
                static_cast<float>(
                    b_ptsOut[i48 + ((static_cast<int>(m)) * i47)]);
          }
        }
      }
    }
    camera_params_o.UndistortMap.transformImage(current_images, fillValues, j_J,
                                                newOrigin);
    k_J.set_size(current_images.size(0), current_images.size(1),
                 current_images.size(2));
    if (1 > current_images.size(0)) {
      t_loop_ub = 0;
    } else {
      t_loop_ub = current_images.size(0);
    }
    if (1 > current_images.size(1)) {
      u_loop_ub = 0;
    } else {
      u_loop_ub = current_images.size(1);
    }
    if (1 > current_images.size(2)) {
      v_loop_ub = 0;
    } else {
      v_loop_ub = current_images.size(2);
    }
    for (int i31{0}; i31 < v_loop_ub; i31++) {
      for (int i33{0}; i33 < u_loop_ub; i33++) {
        for (int i35{0}; i35 < t_loop_ub; i35++) {
          k_J[(i35 + (k_J.size(0) * i33)) +
              ((k_J.size(0) * k_J.size(1)) * i31)] =
              j_J[(i35 + (j_J.size(0) * i33)) +
                  ((j_J.size(0) * j_J.size(1)) * i31)];
        }
      }
    }
    unnamed_idx_0 = r.size(0);
    w_loop_ub = r1.size(0);
    for (int i34{0}; i34 < w_loop_ub; i34++) {
      for (int i37{0}; i37 < unnamed_idx_0; i37++) {
        gray_images[(r[i37] + (gray_images.size(0) * r1[i34])) +
                    ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
            k_J[i37 + (unnamed_idx_0 * i34)];
      }
    }
  }
}

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
