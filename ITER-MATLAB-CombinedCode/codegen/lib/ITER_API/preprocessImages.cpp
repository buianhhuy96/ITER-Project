//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "preprocessImages.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_types.h"
#include "ImageTransformer.h"
#include "cameraParameters.h"
#include "interp2.h"
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                const struct1_T *cameraParams
//                bool undistort
//                coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
void preprocessImages(const coder::array<unsigned char, 4U> &images,
                      const struct1_T *cameraParams, bool undistort,
                      coder::array<unsigned char, 4U> &gray_images)
{
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char cv1[5]{'u', 'i', 'n', 't', '8'};
  static const char x2[4]{'s', 'a', 'm', 'e'};
  coder::d_cameraParameters d_camera_params;
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
  double e_camera_params[3];
  double dv[2];
  double dv1[2];
  double f_camera_params[2];
  unsigned int varargin_2[3];
  int i6;
  int loop_ub;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  //  Undistort and convert images into grayscale
  //  Input:
  // images             a row x col x color channels x Number_of_images matrix
  //
  // cameraParams      camera parameters object
  // undistort          logical flag indicate if the images can be/required to
  //                    be undistorted
  // Output:
  // gray_images        matrix contains images in grayscale and undistorted
  for (int b_i{0}; b_i < 3; b_i++) {
    d_camera_params.IntrinsicMatrixInternal[b_i][0] =
        cameraParams->IntrinsicMatrix[0][b_i];
    d_camera_params.IntrinsicMatrixInternal[b_i][1] =
        cameraParams->IntrinsicMatrix[1][b_i];
    d_camera_params.IntrinsicMatrixInternal[b_i][2] =
        cameraParams->IntrinsicMatrix[2][b_i];
  }
  d_camera_params.RadialDistortion[0] = cameraParams->RadialDistortion[0];
  d_camera_params.RadialDistortion[1] = cameraParams->RadialDistortion[1];
  d_camera_params.RadialDistortion[2] = cameraParams->RadialDistortion[2];
  d_camera_params.TangentialDistortion[0] =
      cameraParams->TangentialDistortion[0];
  d_camera_params.TangentialDistortion[1] =
      cameraParams->TangentialDistortion[1];
  d_camera_params.ImageSize[0] = cameraParams->ImageSize[0];
  d_camera_params.ImageSize[1] = cameraParams->ImageSize[1];
  d_camera_params.NumRadialDistortionCoefficients =
      cameraParams->NumRadialDistortionCoefficients;
  d_camera_params.UndistortMap.XBounds[0] = -1.0;
  d_camera_params.UndistortMap.XBounds[1] = -1.0;
  d_camera_params.UndistortMap.YBounds[0] = -1.0;
  d_camera_params.UndistortMap.YBounds[1] = -1.0;
  d_camera_params.UndistortMap.SizeOfImage.set_size(1, 2);
  d_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  d_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  d_camera_params.UndistortMap.SizeOfImage.set_size(1, 3);
  d_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  d_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  d_camera_params.UndistortMap.SizeOfImage[2] = 0.0;
  d_camera_params.UndistortMap.ClassOfImage.set_size(1, 1);
  d_camera_params.UndistortMap.ClassOfImage[0] = 'a';
  d_camera_params.UndistortMap.ClassOfImage.set_size(1, 5);
  for (int i1{0}; i1 < 5; i1++) {
    d_camera_params.UndistortMap.ClassOfImage[i1] = b_cv[i1];
  }
  d_camera_params.UndistortMap.OutputView.set_size(1, 1);
  d_camera_params.UndistortMap.OutputView[0] = 'a';
  d_camera_params.UndistortMap.OutputView.set_size(1, 4);
  for (int i2{0}; i2 < 4; i2++) {
    d_camera_params.UndistortMap.OutputView[i2] = x2[i2];
  }
  d_camera_params.UndistortMap.XmapSingle.set_size(2, 2);
  for (int i3{0}; i3 < 2; i3++) {
    d_camera_params.UndistortMap
        .XmapSingle[d_camera_params.UndistortMap.XmapSingle.size(0) * i3] =
        0.0F;
    d_camera_params.UndistortMap
        .XmapSingle[(d_camera_params.UndistortMap.XmapSingle.size(0) * i3) +
                    1] = 0.0F;
  }
  d_camera_params.UndistortMap.YmapSingle.set_size(2, 2);
  for (int i4{0}; i4 < 2; i4++) {
    d_camera_params.UndistortMap
        .YmapSingle[d_camera_params.UndistortMap.YmapSingle.size(0) * i4] =
        0.0F;
    d_camera_params.UndistortMap
        .YmapSingle[(d_camera_params.UndistortMap.YmapSingle.size(0) * i4) +
                    1] = 0.0F;
  }
  gray_images.set_size(images.size(0), images.size(1), 1, images.size(3));
  loop_ub = images.size(3);
  for (int i5{0}; i5 < loop_ub; i5++) {
    int b_loop_ub;
    b_loop_ub = images.size(1);
    for (int i7{0}; i7 < b_loop_ub; i7++) {
      int c_loop_ub;
      c_loop_ub = images.size(0);
      for (int i8{0}; i8 < c_loop_ub; i8++) {
        gray_images[(i8 + (gray_images.size(0) * i7)) +
                    ((gray_images.size(0) * gray_images.size(1)) * i5)] = 0U;
      }
    }
  }
  i6 = images.size(3);
  for (int c_i{0}; c_i < i6; c_i++) {
    int d_loop_ub;
    //  If gray images, convert to RGB
    d_loop_ub = images.size(2);
    if (images.size(2) == 3) {
      int current_images_idx_0;
      int current_images_idx_1;
      int f_loop_ub;
      int h_loop_ub;
      f_loop_ub = images.size(0);
      h_loop_ub = images.size(1);
      b_images.set_size(images.size(0), images.size(1), 3);
      for (int i10{0}; i10 < 3; i10++) {
        for (int i12{0}; i12 < h_loop_ub; i12++) {
          for (int i14{0}; i14 < f_loop_ub; i14++) {
            b_images[(i14 + (b_images.size(0) * i12)) +
                     ((b_images.size(0) * b_images.size(1)) * i10)] =
                images[((i14 + (images.size(0) * i12)) +
                        ((images.size(0) * images.size(1)) * i10)) +
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
      for (int i17{0}; i17 < current_images_idx_1; i17++) {
        for (int i18{0}; i18 < current_images_idx_0; i18++) {
          current_images[i18 + (current_images.size(0) * i17)] =
              b_current_images[i18 + (current_images_idx_0 * i17)];
        }
      }
    } else {
      int e_loop_ub;
      int g_loop_ub;
      e_loop_ub = images.size(0);
      g_loop_ub = images.size(1);
      current_images.set_size(images.size(0), images.size(1), images.size(2));
      for (int i9{0}; i9 < d_loop_ub; i9++) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          for (int i13{0}; i13 < e_loop_ub; i13++) {
            current_images[(i13 + (current_images.size(0) * i11)) +
                           ((current_images.size(0) * current_images.size(1)) *
                            i9)] =
                images[((i13 + (images.size(0) * i11)) +
                        ((images.size(0) * images.size(1)) * i9)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
    }
    if (undistort) {
      int ab_loop_ub;
      int cb_loop_ub;
      int e_P;
      int eb_loop_ub;
      int hb_loop_ub;
      int j_loop_ub;
      int kb_loop_ub;
      int m_loop_ub;
      int ob_loop_ub;
      int p_loop_ub;
      int pb_loop_ub;
      int r_loop_ub;
      int unnamed_idx_0;
      bool b_p;
      bool c_p;
      bool d_p;
      bool exitg1;
      bool p;
      bool sameClass;
      j_loop_ub = gray_images.size(0);
      r.set_size(gray_images.size(0));
      for (int i16{0}; i16 < j_loop_ub; i16++) {
        r[i16] = i16;
      }
      m_loop_ub = gray_images.size(1);
      r1.set_size(gray_images.size(1));
      for (int i20{0}; i20 < m_loop_ub; i20++) {
        r1[i20] = i20;
      }
      varargin_2[0] = static_cast<unsigned int>(current_images.size(0));
      varargin_2[1] = static_cast<unsigned int>(current_images.size(1));
      varargin_2[2] = static_cast<unsigned int>(current_images.size(2));
      p = (d_camera_params.UndistortMap.SizeOfImage.size(1) == 3);
      b_p = p;
      if (p) {
        if (d_camera_params.UndistortMap.SizeOfImage.size(1) != 0) {
          int k;
          b_p = true;
          k = 0;
          exitg1 = false;
          while (
              (!exitg1) &&
              (k <= (d_camera_params.UndistortMap.SizeOfImage.size(1) - 1))) {
            if (!(d_camera_params.UndistortMap.SizeOfImage[k] ==
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
      if (5 == d_camera_params.UndistortMap.ClassOfImage.size(1)) {
        int kstr;
        kstr = 0;
        int exitg2;
        do {
          exitg2 = 0;
          if (kstr < 5) {
            if (cv1[kstr] != d_camera_params.UndistortMap.ClassOfImage[kstr]) {
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
      c_p = (d_camera_params.UndistortMap.OutputView.size(1) == 4);
      d_p = c_p;
      if (c_p) {
        if (d_camera_params.UndistortMap.OutputView.size(1) != 0) {
          int b_k;
          d_p = true;
          b_k = 0;
          exitg1 = false;
          while (
              (!exitg1) &&
              (b_k <= (d_camera_params.UndistortMap.OutputView.size(1) - 1))) {
            if (!(d_camera_params.UndistortMap.OutputView[b_k] == x2[b_k])) {
              d_p = false;
              exitg1 = true;
            } else {
              b_k++;
            }
          }
        }
      }
      if (((!b_p) || (!sameClass)) || (!d_p)) {
        for (int i23{0}; i23 < 3; i23++) {
          b_intrinsicMatrix[i23][0] =
              d_camera_params.IntrinsicMatrixInternal[0][i23];
          b_intrinsicMatrix[i23][1] =
              d_camera_params.IntrinsicMatrixInternal[1][i23];
          b_intrinsicMatrix[i23][2] =
              d_camera_params.IntrinsicMatrixInternal[2][i23];
        }
        dv[0] = 1.0;
        dv[1] = static_cast<double>(
            static_cast<unsigned int>(current_images.size(1)));
        dv1[0] = 1.0;
        dv1[1] = static_cast<double>(
            static_cast<unsigned int>(current_images.size(0)));
        e_camera_params[0] = d_camera_params.RadialDistortion[0];
        e_camera_params[1] = d_camera_params.RadialDistortion[1];
        e_camera_params[2] = d_camera_params.RadialDistortion[2];
        f_camera_params[0] = d_camera_params.TangentialDistortion[0];
        f_camera_params[1] = d_camera_params.TangentialDistortion[1];
        d_camera_params.UndistortMap.update(current_images, b_intrinsicMatrix,
                                            e_camera_params, f_camera_params,
                                            dv, dv1);
      }
      b_this = &d_camera_params.UndistortMap;
      Xin.set_size(b_this->XmapSingle.size(0), b_this->XmapSingle.size(1));
      p_loop_ub = b_this->XmapSingle.size(1);
      for (int i24{0}; i24 < p_loop_ub; i24++) {
        int q_loop_ub;
        q_loop_ub = b_this->XmapSingle.size(0);
        for (int i25{0}; i25 < q_loop_ub; i25++) {
          Xin[i25 + (Xin.size(0) * i24)] =
              b_this->XmapSingle[i25 + (b_this->XmapSingle.size(0) * i24)];
        }
      }
      Yin.set_size(b_this->YmapSingle.size(0), b_this->YmapSingle.size(1));
      r_loop_ub = b_this->YmapSingle.size(1);
      for (int i26{0}; i26 < r_loop_ub; i26++) {
        int s_loop_ub;
        s_loop_ub = b_this->YmapSingle.size(0);
        for (int i27{0}; i27 < s_loop_ub; i27++) {
          Yin[i27 + (Yin.size(0) * i26)] =
              b_this->YmapSingle[i27 + (b_this->YmapSingle.size(0) * i26)];
        }
      }
      if (current_images.size(2) == 1) {
        unsigned int b_unnamed_idx_1;
        unsigned int c_unnamed_idx_0;
        int u_loop_ub;
        e_P = 0;
        c_unnamed_idx_0 = static_cast<unsigned int>(Xin.size(0));
        b_unnamed_idx_1 = static_cast<unsigned int>(Xin.size(1));
        outputImage.set_size(Xin.size(0), Xin.size(1), 1);
        u_loop_ub = static_cast<int>(b_unnamed_idx_1);
        for (int i29{0}; i29 < u_loop_ub; i29++) {
          int w_loop_ub;
          w_loop_ub = static_cast<int>(c_unnamed_idx_0);
          for (int i31{0}; i31 < w_loop_ub; i31++) {
            outputImage[i31 + (outputImage.size(0) * i29)] = 0.0F;
          }
        }
      } else {
        unsigned int b_unnamed_idx_0;
        int t_loop_ub;
        unsigned int unnamed_idx_1;
        e_P = current_images.size(2) - 1;
        b_unnamed_idx_0 = static_cast<unsigned int>(Xin.size(0));
        unnamed_idx_1 = static_cast<unsigned int>(Xin.size(1));
        outputImage.set_size(Xin.size(0), Xin.size(1), current_images.size(2));
        t_loop_ub = current_images.size(2);
        for (int i28{0}; i28 < t_loop_ub; i28++) {
          int v_loop_ub;
          v_loop_ub = static_cast<int>(unnamed_idx_1);
          for (int i30{0}; i30 < v_loop_ub; i30++) {
            int y_loop_ub;
            y_loop_ub = static_cast<int>(b_unnamed_idx_0);
            for (int i33{0}; i33 < y_loop_ub; i33++) {
              outputImage[(i33 + (outputImage.size(0) * i30)) +
                          ((outputImage.size(0) * outputImage.size(1)) * i28)] =
                  0.0F;
            }
          }
        }
      }
      if (current_images.size(1) < 1) {
        y.set_size(1, 0);
      } else {
        int x_loop_ub;
        y.set_size(1, current_images.size(1));
        x_loop_ub = current_images.size(1) - 1;
        for (int i32{0}; i32 <= x_loop_ub; i32++) {
          y[i32] = (static_cast<double>(i32)) + 1.0;
        }
      }
      XIntrinsic.set_size(1, y.size(1));
      ab_loop_ub = y.size(1);
      for (int i34{0}; i34 < ab_loop_ub; i34++) {
        XIntrinsic[i34] = static_cast<float>(y[i34]);
      }
      if (current_images.size(0) < 1) {
        y.set_size(1, 0);
      } else {
        int bb_loop_ub;
        y.set_size(1, current_images.size(0));
        bb_loop_ub = current_images.size(0) - 1;
        for (int i35{0}; i35 <= bb_loop_ub; i35++) {
          y[i35] = (static_cast<double>(i35)) + 1.0;
        }
      }
      YIntrinsic.set_size(1, y.size(1));
      cb_loop_ub = y.size(1);
      for (int i36{0}; i36 < cb_loop_ub; i36++) {
        YIntrinsic[i36] = static_cast<float>(y[i36]);
      }
      for (int plane{0}; plane <= e_P; plane++) {
        int db_loop_ub;
        int fb_loop_ub;
        int ib_loop_ub;
        db_loop_ub = current_images.size(0);
        fb_loop_ub = current_images.size(1);
        c_current_images.set_size(current_images.size(0),
                                  current_images.size(1));
        for (int i38{0}; i38 < fb_loop_ub; i38++) {
          for (int i40{0}; i40 < db_loop_ub; i40++) {
            c_current_images[i40 + (c_current_images.size(0) * i38)] =
                static_cast<float>(
                    current_images[(i40 + (current_images.size(0) * i38)) +
                                   ((current_images.size(0) *
                                     current_images.size(1)) *
                                    plane)]);
          }
        }
        coder::images::internal::coder::interp2_local(
            c_current_images, Xin, Yin, 0.0F, XIntrinsic, YIntrinsic, r2);
        ib_loop_ub = r2.size(1);
        for (int i41{0}; i41 < ib_loop_ub; i41++) {
          int mb_loop_ub;
          mb_loop_ub = r2.size(0);
          for (int i43{0}; i43 < mb_loop_ub; i43++) {
            outputImage[(i43 + (outputImage.size(0) * i41)) +
                        ((outputImage.size(0) * outputImage.size(1)) * plane)] =
                r2[i43 + (r2.size(0) * i41)];
          }
        }
      }
      j_J.set_size(outputImage.size(0), outputImage.size(1),
                   outputImage.size(2));
      eb_loop_ub = outputImage.size(2);
      for (int i37{0}; i37 < eb_loop_ub; i37++) {
        int gb_loop_ub;
        gb_loop_ub = outputImage.size(1);
        for (int i39{0}; i39 < gb_loop_ub; i39++) {
          int jb_loop_ub;
          jb_loop_ub = outputImage.size(0);
          for (int i42{0}; i42 < jb_loop_ub; i42++) {
            float f;
            unsigned char c_u;
            f = std::round(
                outputImage[(i42 + (outputImage.size(0) * i39)) +
                            ((outputImage.size(0) * outputImage.size(1)) *
                             i37)]);
            if (f < 256.0F) {
              if (f >= 0.0F) {
                c_u = static_cast<unsigned char>(f);
              } else {
                c_u = 0U;
              }
            } else if (f >= 256.0F) {
              c_u = MAX_uint8_T;
            } else {
              c_u = 0U;
            }
            j_J[(i42 + (j_J.size(0) * i39)) +
                ((j_J.size(0) * j_J.size(1)) * i37)] = c_u;
          }
        }
      }
      k_J.set_size(current_images.size(0), current_images.size(1),
                   current_images.size(2));
      if (1 > current_images.size(0)) {
        hb_loop_ub = 0;
      } else {
        hb_loop_ub = current_images.size(0);
      }
      if (1 > current_images.size(1)) {
        kb_loop_ub = 0;
      } else {
        kb_loop_ub = current_images.size(1);
      }
      if (1 > current_images.size(2)) {
        ob_loop_ub = 0;
      } else {
        ob_loop_ub = current_images.size(2);
      }
      for (int i44{0}; i44 < ob_loop_ub; i44++) {
        for (int i45{0}; i45 < kb_loop_ub; i45++) {
          for (int i47{0}; i47 < hb_loop_ub; i47++) {
            k_J[(i47 + (k_J.size(0) * i45)) +
                ((k_J.size(0) * k_J.size(1)) * i44)] =
                j_J[(i47 + (j_J.size(0) * i45)) +
                    ((j_J.size(0) * j_J.size(1)) * i44)];
          }
        }
      }
      unnamed_idx_0 = r.size(0);
      pb_loop_ub = r1.size(0);
      for (int i46{0}; i46 < pb_loop_ub; i46++) {
        for (int i48{0}; i48 < unnamed_idx_0; i48++) {
          gray_images[(r[i48] + (gray_images.size(0) * r1[i46])) +
                      ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
              k_J[i48 + (unnamed_idx_0 * i46)];
        }
      }
    } else {
      int i_loop_ub;
      int k_loop_ub;
      int o_loop_ub;
      int unnamed_idx_0;
      i_loop_ub = gray_images.size(0);
      r.set_size(gray_images.size(0));
      for (int i15{0}; i15 < i_loop_ub; i15++) {
        r[i15] = i15;
      }
      k_loop_ub = gray_images.size(1);
      r1.set_size(gray_images.size(1));
      for (int i19{0}; i19 < k_loop_ub; i19++) {
        r1[i19] = i19;
      }
      unnamed_idx_0 = r.size(0);
      o_loop_ub = r1.size(0);
      for (int i21{0}; i21 < o_loop_ub; i21++) {
        for (int i22{0}; i22 < unnamed_idx_0; i22++) {
          gray_images[(r[i22] + (gray_images.size(0) * r1[i21])) +
                      ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
              current_images[i22 + (unnamed_idx_0 * i21)];
        }
      }
    }
  }
}

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
