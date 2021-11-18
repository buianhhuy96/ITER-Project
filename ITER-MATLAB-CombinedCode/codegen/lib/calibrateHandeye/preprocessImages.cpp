//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 14:44:26
//

// Include Files
#include "preprocessImages.h"
#include "ImageTransformer.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_types.h"
#include "cameraParameters.h"
#include "interp2.h"
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                const struct0_T *camera_params
//                coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
void preprocessImages(const coder::array<unsigned char, 4U> &images,
                      const struct0_T *camera_params,
                      coder::array<unsigned char, 4U> &gray_images)
{
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char cv1[5]{'u', 'i', 'n', 't', '8'};
  static const char x2[4]{'s', 'a', 'm', 'e'};
  coder::b_cameraParameters b_camera_params;
  coder::vision::internal::calibration::b_ImageTransformer *b_this;
  coder::array<double, 2U> y;
  coder::array<float, 3U> outputImage;
  coder::array<float, 2U> XIntrinsic;
  coder::array<float, 2U> Xin;
  coder::array<float, 2U> YIntrinsic;
  coder::array<float, 2U> Yin;
  coder::array<float, 2U> c_current_images;
  coder::array<float, 2U> r2;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<unsigned char, 3U> b_images;
  coder::array<unsigned char, 3U> current_images;
  coder::array<unsigned char, 3U> j_J;
  coder::array<unsigned char, 3U> k_J;
  coder::array<unsigned char, 2U> b_current_images;
  double b_intrinsicMatrix[3][3];
  double c_camera_params[3];
  double d_camera_params[2];
  double dv[2];
  double dv1[2];
  unsigned int varargin_2[3];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int h_loop_ub;
  int i17;
  int loop_ub;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  for (int b_i{0}; b_i < 3; b_i++) {
    b_camera_params.IntrinsicMatrixInternal[b_i][0] =
        camera_params->IntrinsicMatrix[0][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][1] =
        camera_params->IntrinsicMatrix[1][b_i];
    b_camera_params.IntrinsicMatrixInternal[b_i][2] =
        camera_params->IntrinsicMatrix[2][b_i];
  }
  b_camera_params.RadialDistortion[0] = camera_params->RadialDistortion[0];
  b_camera_params.RadialDistortion[1] = camera_params->RadialDistortion[1];
  b_camera_params.RadialDistortion[2] = camera_params->RadialDistortion[2];
  b_camera_params.TangentialDistortion[0] =
      camera_params->TangentialDistortion[0];
  b_camera_params.TangentialDistortion[1] =
      camera_params->TangentialDistortion[1];
  b_camera_params.ImageSize[0] = camera_params->ImageSize[0];
  b_camera_params.ImageSize[1] = camera_params->ImageSize[1];
  b_camera_params.RotationVectors.set_size(
      camera_params->RotationVectors.size(0), 3);
  loop_ub = camera_params->RotationVectors.size(0);
  for (int i1{0}; i1 < 3; i1++) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      b_camera_params
          .RotationVectors[i2 +
                           (b_camera_params.RotationVectors.size(0) * i1)] =
          camera_params
              ->RotationVectors[i2 +
                                (camera_params->RotationVectors.size(0) * i1)];
    }
  }
  b_camera_params.TranslationVectors.set_size(
      camera_params->TranslationVectors.size(0), 3);
  b_loop_ub = camera_params->TranslationVectors.size(0);
  for (int i3{0}; i3 < 3; i3++) {
    for (int i4{0}; i4 < b_loop_ub; i4++) {
      b_camera_params
          .TranslationVectors[i4 + (b_camera_params.TranslationVectors.size(0) *
                                    i3)] =
          camera_params->TranslationVectors
              [i4 + (camera_params->TranslationVectors.size(0) * i3)];
    }
  }
  b_camera_params.WorldPoints.set_size(camera_params->WorldPoints.size(0), 2);
  c_loop_ub = camera_params->WorldPoints.size(0);
  for (int i5{0}; i5 < 2; i5++) {
    for (int i6{0}; i6 < c_loop_ub; i6++) {
      b_camera_params
          .WorldPoints[i6 + (b_camera_params.WorldPoints.size(0) * i5)] =
          camera_params
              ->WorldPoints[i6 + (camera_params->WorldPoints.size(0) * i5)];
    }
  }
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  b_camera_params.DetectedKeypoints.set_size(
      camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  d_loop_ub = camera_params->DetectedKeypoints.size(1);
  for (int i7{0}; i7 < d_loop_ub; i7++) {
    int e_loop_ub;
    e_loop_ub = camera_params->DetectedKeypoints.size(0);
    for (int i8{0}; i8 < e_loop_ub; i8++) {
      b_camera_params
          .DetectedKeypoints[i8 +
                             (b_camera_params.DetectedKeypoints.size(0) * i7)] =
          camera_params->DetectedKeypoints
              [i8 + (camera_params->DetectedKeypoints.size(0) * i7)];
    }
  }
  if ((camera_params->ReprojectionErrors.size(0) == 0) ||
      (camera_params->ReprojectionErrors.size(2) == 0)) {
    b_camera_params.ReprojectionErrors.set_size(0, 2, 1);
  } else {
    int f_loop_ub;
    b_camera_params.ReprojectionErrors.set_size(
        camera_params->ReprojectionErrors.size(0), 2,
        camera_params->ReprojectionErrors.size(2));
    f_loop_ub = camera_params->ReprojectionErrors.size(2);
    for (int i9{0}; i9 < f_loop_ub; i9++) {
      int g_loop_ub;
      g_loop_ub = camera_params->ReprojectionErrors.size(0);
      for (int i10{0}; i10 < 2; i10++) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          b_camera_params.ReprojectionErrors
              [(i11 + (b_camera_params.ReprojectionErrors.size(0) * i10)) +
               ((b_camera_params.ReprojectionErrors.size(0) * 2) * i9)] =
              camera_params->ReprojectionErrors
                  [(i11 + (camera_params->ReprojectionErrors.size(0) * i10)) +
                   ((camera_params->ReprojectionErrors.size(0) * 2) * i9)];
        }
      }
    }
  }
  b_camera_params.UndistortMap.XBounds[0] = -1.0;
  b_camera_params.UndistortMap.XBounds[1] = -1.0;
  b_camera_params.UndistortMap.YBounds[0] = -1.0;
  b_camera_params.UndistortMap.YBounds[1] = -1.0;
  b_camera_params.UndistortMap.SizeOfImage.set_size(1, 2);
  b_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  b_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  b_camera_params.UndistortMap.SizeOfImage.set_size(1, 3);
  b_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  b_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  b_camera_params.UndistortMap.SizeOfImage[2] = 0.0;
  b_camera_params.UndistortMap.ClassOfImage.set_size(1, 1);
  b_camera_params.UndistortMap.ClassOfImage[0] = 'a';
  b_camera_params.UndistortMap.ClassOfImage.set_size(1, 5);
  for (int i12{0}; i12 < 5; i12++) {
    b_camera_params.UndistortMap.ClassOfImage[i12] = b_cv[i12];
  }
  b_camera_params.UndistortMap.OutputView.set_size(1, 1);
  b_camera_params.UndistortMap.OutputView[0] = 'a';
  b_camera_params.UndistortMap.OutputView.set_size(1, 4);
  for (int i13{0}; i13 < 4; i13++) {
    b_camera_params.UndistortMap.OutputView[i13] = x2[i13];
  }
  b_camera_params.UndistortMap.XmapSingle.set_size(2, 2);
  for (int i14{0}; i14 < 2; i14++) {
    b_camera_params.UndistortMap
        .XmapSingle[b_camera_params.UndistortMap.XmapSingle.size(0) * i14] =
        0.0F;
    b_camera_params.UndistortMap
        .XmapSingle[(b_camera_params.UndistortMap.XmapSingle.size(0) * i14) +
                    1] = 0.0F;
  }
  b_camera_params.UndistortMap.YmapSingle.set_size(2, 2);
  for (int i15{0}; i15 < 2; i15++) {
    b_camera_params.UndistortMap
        .YmapSingle[b_camera_params.UndistortMap.YmapSingle.size(0) * i15] =
        0.0F;
    b_camera_params.UndistortMap
        .YmapSingle[(b_camera_params.UndistortMap.YmapSingle.size(0) * i15) +
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
    int c_unnamed_idx_0;
    int e_P;
    int eb_loop_ub;
    int gb_loop_ub;
    int ib_loop_ub;
    int j_loop_ub;
    int m_loop_ub;
    int mb_loop_ub;
    int o_loop_ub;
    int q_loop_ub;
    int qb_loop_ub;
    int s_loop_ub;
    int sb_loop_ub;
    int t_loop_ub;
    int tb_loop_ub;
    int v_loop_ub;
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
    varargin_2[0] = static_cast<unsigned int>(current_images.size(0));
    varargin_2[1] = static_cast<unsigned int>(current_images.size(1));
    varargin_2[2] = static_cast<unsigned int>(current_images.size(2));
    p = (b_camera_params.UndistortMap.SizeOfImage.size(1) == 3);
    b_p = p;
    if (p) {
      if (b_camera_params.UndistortMap.SizeOfImage.size(1) != 0) {
        int k;
        b_p = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) &&
               (k <= (b_camera_params.UndistortMap.SizeOfImage.size(1) - 1))) {
          if (!(b_camera_params.UndistortMap.SizeOfImage[k] ==
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
    if (5 == b_camera_params.UndistortMap.ClassOfImage.size(1)) {
      int kstr;
      kstr = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (kstr < 5) {
          if (cv1[kstr] != b_camera_params.UndistortMap.ClassOfImage[kstr]) {
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
    c_p = (b_camera_params.UndistortMap.OutputView.size(1) == 4);
    d_p = c_p;
    if (c_p) {
      if (b_camera_params.UndistortMap.OutputView.size(1) != 0) {
        int b_k;
        d_p = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) &&
               (b_k <= (b_camera_params.UndistortMap.OutputView.size(1) - 1))) {
          if (!(b_camera_params.UndistortMap.OutputView[b_k] == x2[b_k])) {
            d_p = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }
      }
    }
    if (((!b_p) || (!sameClass)) || (!d_p)) {
      for (int i30{0}; i30 < 3; i30++) {
        b_intrinsicMatrix[i30][0] =
            b_camera_params.IntrinsicMatrixInternal[0][i30];
        b_intrinsicMatrix[i30][1] =
            b_camera_params.IntrinsicMatrixInternal[1][i30];
        b_intrinsicMatrix[i30][2] =
            b_camera_params.IntrinsicMatrixInternal[2][i30];
      }
      dv[0] = 1.0;
      dv[1] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(1)));
      dv1[0] = 1.0;
      dv1[1] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(0)));
      c_camera_params[0] = b_camera_params.RadialDistortion[0];
      c_camera_params[1] = b_camera_params.RadialDistortion[1];
      c_camera_params[2] = b_camera_params.RadialDistortion[2];
      d_camera_params[0] = b_camera_params.TangentialDistortion[0];
      d_camera_params[1] = b_camera_params.TangentialDistortion[1];
      b_camera_params.UndistortMap.update(current_images, b_intrinsicMatrix,
                                          c_camera_params, d_camera_params, dv,
                                          dv1);
    }
    b_this = &b_camera_params.UndistortMap;
    Xin.set_size(b_this->XmapSingle.size(0), b_this->XmapSingle.size(1));
    t_loop_ub = b_this->XmapSingle.size(1);
    for (int i31{0}; i31 < t_loop_ub; i31++) {
      int u_loop_ub;
      u_loop_ub = b_this->XmapSingle.size(0);
      for (int i32{0}; i32 < u_loop_ub; i32++) {
        Xin[i32 + (Xin.size(0) * i31)] =
            b_this->XmapSingle[i32 + (b_this->XmapSingle.size(0) * i31)];
      }
    }
    Yin.set_size(b_this->YmapSingle.size(0), b_this->YmapSingle.size(1));
    v_loop_ub = b_this->YmapSingle.size(1);
    for (int i33{0}; i33 < v_loop_ub; i33++) {
      int w_loop_ub;
      w_loop_ub = b_this->YmapSingle.size(0);
      for (int i34{0}; i34 < w_loop_ub; i34++) {
        Yin[i34 + (Yin.size(0) * i33)] =
            b_this->YmapSingle[i34 + (b_this->YmapSingle.size(0) * i33)];
      }
    }
    if (current_images.size(2) == 1) {
      unsigned int b_unnamed_idx_0;
      unsigned int b_unnamed_idx_1;
      int y_loop_ub;
      e_P = 0;
      b_unnamed_idx_0 = static_cast<unsigned int>(Xin.size(0));
      b_unnamed_idx_1 = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), 1);
      y_loop_ub = static_cast<int>(b_unnamed_idx_1);
      for (int i36{0}; i36 < y_loop_ub; i36++) {
        int bb_loop_ub;
        bb_loop_ub = static_cast<int>(b_unnamed_idx_0);
        for (int i38{0}; i38 < bb_loop_ub; i38++) {
          outputImage[i38 + (outputImage.size(0) * i36)] = 0.0F;
        }
      }
    } else {
      unsigned int unnamed_idx_0;
      unsigned int unnamed_idx_1;
      int x_loop_ub;
      e_P = current_images.size(2) - 1;
      unnamed_idx_0 = static_cast<unsigned int>(Xin.size(0));
      unnamed_idx_1 = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), current_images.size(2));
      x_loop_ub = current_images.size(2);
      for (int i35{0}; i35 < x_loop_ub; i35++) {
        int ab_loop_ub;
        ab_loop_ub = static_cast<int>(unnamed_idx_1);
        for (int i37{0}; i37 < ab_loop_ub; i37++) {
          int db_loop_ub;
          db_loop_ub = static_cast<int>(unnamed_idx_0);
          for (int i40{0}; i40 < db_loop_ub; i40++) {
            outputImage[(i40 + (outputImage.size(0) * i37)) +
                        ((outputImage.size(0) * outputImage.size(1)) * i35)] =
                0.0F;
          }
        }
      }
    }
    if (current_images.size(1) < 1) {
      y.set_size(1, 0);
    } else {
      int cb_loop_ub;
      y.set_size(1, current_images.size(1));
      cb_loop_ub = current_images.size(1) - 1;
      for (int i39{0}; i39 <= cb_loop_ub; i39++) {
        y[i39] = (static_cast<double>(i39)) + 1.0;
      }
    }
    XIntrinsic.set_size(1, y.size(1));
    eb_loop_ub = y.size(1);
    for (int i41{0}; i41 < eb_loop_ub; i41++) {
      XIntrinsic[i41] = static_cast<float>(y[i41]);
    }
    if (current_images.size(0) < 1) {
      y.set_size(1, 0);
    } else {
      int fb_loop_ub;
      y.set_size(1, current_images.size(0));
      fb_loop_ub = current_images.size(0) - 1;
      for (int i42{0}; i42 <= fb_loop_ub; i42++) {
        y[i42] = (static_cast<double>(i42)) + 1.0;
      }
    }
    YIntrinsic.set_size(1, y.size(1));
    gb_loop_ub = y.size(1);
    for (int i43{0}; i43 < gb_loop_ub; i43++) {
      YIntrinsic[i43] = static_cast<float>(y[i43]);
    }
    for (int plane{0}; plane <= e_P; plane++) {
      int hb_loop_ub;
      int jb_loop_ub;
      int ob_loop_ub;
      hb_loop_ub = current_images.size(0);
      jb_loop_ub = current_images.size(1);
      c_current_images.set_size(current_images.size(0), current_images.size(1));
      for (int i45{0}; i45 < jb_loop_ub; i45++) {
        for (int i47{0}; i47 < hb_loop_ub; i47++) {
          c_current_images[i47 + (c_current_images.size(0) * i45)] =
              static_cast<float>(
                  current_images[(i47 + (current_images.size(0) * i45)) +
                                 ((current_images.size(0) *
                                   current_images.size(1)) *
                                  plane)]);
        }
      }
      coder::images::internal::coder::interp2_local(
          c_current_images, Xin, Yin, 0.0F, XIntrinsic, YIntrinsic, r2);
      ob_loop_ub = r2.size(1);
      for (int i48{0}; i48 < ob_loop_ub; i48++) {
        int rb_loop_ub;
        rb_loop_ub = r2.size(0);
        for (int i50{0}; i50 < rb_loop_ub; i50++) {
          outputImage[(i50 + (outputImage.size(0) * i48)) +
                      ((outputImage.size(0) * outputImage.size(1)) * plane)] =
              r2[i50 + (r2.size(0) * i48)];
        }
      }
    }
    j_J.set_size(outputImage.size(0), outputImage.size(1), outputImage.size(2));
    ib_loop_ub = outputImage.size(2);
    for (int i44{0}; i44 < ib_loop_ub; i44++) {
      int kb_loop_ub;
      kb_loop_ub = outputImage.size(1);
      for (int i46{0}; i46 < kb_loop_ub; i46++) {
        int pb_loop_ub;
        pb_loop_ub = outputImage.size(0);
        for (int i49{0}; i49 < pb_loop_ub; i49++) {
          float f;
          unsigned char b_u;
          f = std::round(
              outputImage[(i49 + (outputImage.size(0) * i46)) +
                          ((outputImage.size(0) * outputImage.size(1)) * i44)]);
          if (f < 256.0F) {
            if (f >= 0.0F) {
              b_u = static_cast<unsigned char>(f);
            } else {
              b_u = 0U;
            }
          } else if (f >= 256.0F) {
            b_u = MAX_uint8_T;
          } else {
            b_u = 0U;
          }
          j_J[(i49 + (j_J.size(0) * i46)) +
              ((j_J.size(0) * j_J.size(1)) * i44)] = b_u;
        }
      }
    }
    k_J.set_size(current_images.size(0), current_images.size(1),
                 current_images.size(2));
    if (1 > current_images.size(0)) {
      mb_loop_ub = 0;
    } else {
      mb_loop_ub = current_images.size(0);
    }
    if (1 > current_images.size(1)) {
      qb_loop_ub = 0;
    } else {
      qb_loop_ub = current_images.size(1);
    }
    if (1 > current_images.size(2)) {
      sb_loop_ub = 0;
    } else {
      sb_loop_ub = current_images.size(2);
    }
    for (int i51{0}; i51 < sb_loop_ub; i51++) {
      for (int i52{0}; i52 < qb_loop_ub; i52++) {
        for (int i54{0}; i54 < mb_loop_ub; i54++) {
          k_J[(i54 + (k_J.size(0) * i52)) +
              ((k_J.size(0) * k_J.size(1)) * i51)] =
              j_J[(i54 + (j_J.size(0) * i52)) +
                  ((j_J.size(0) * j_J.size(1)) * i51)];
        }
      }
    }
    c_unnamed_idx_0 = r.size(0);
    tb_loop_ub = r1.size(0);
    for (int i53{0}; i53 < tb_loop_ub; i53++) {
      for (int i55{0}; i55 < c_unnamed_idx_0; i55++) {
        gray_images[(r[i55] + (gray_images.size(0) * r1[i53])) +
                    ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
            k_J[i55 + (c_unnamed_idx_0 * i53)];
      }
    }
  }
}

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
