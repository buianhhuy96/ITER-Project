//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "preprocessImages.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_types.h"
#include "ImageTransformer.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimterp2d.h"
#include "libmwrgb2gray_tbb.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 4U> &images
//                const struct1_T *cameraParams
//                bool undistort
//                ::coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
namespace ITER {
void preprocessImages(const ::coder::array<unsigned char, 4U> &images,
                      const struct1_T *cameraParams, bool undistort,
                      ::coder::array<unsigned char, 4U> &gray_images)
{
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char b_cv1[5]{'u', 'i', 'n', 't', '8'};
  static const char x2[4]{'s', 'a', 'm', 'e'};
  coder::d_cameraParameters c_camera_params;
  coder::vision::internal::calibration::b_ImageTransformer *b_this;
  ::coder::array<float, 2U> Y_T;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<unsigned char, 3U> current_images;
  ::coder::array<unsigned char, 3U> d_X;
  ::coder::array<unsigned char, 3U> f_J;
  ::coder::array<unsigned char, 3U> fill;
  ::coder::array<signed char, 3U> fillValues;
  ::coder::array<unsigned char, 3U> outputImage;
  ::coder::array<unsigned char, 2U> b_current_images;
  double b_intrinsicMatrix[3][3];
  double d_camera_params[3];
  double inputImageSize[3];
  double outputImageSize[3];
  double b_dv[2];
  double b_dv1[2];
  double e_camera_params[2];
  int b_images[4];
  unsigned int varargin_2[3];
  int b_i8;
  int b_loop_ub;
  int d_loop_ub;
  int i6;
  int i7;
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
    c_camera_params.IntrinsicMatrixInternal[b_i][0] =
        cameraParams->IntrinsicMatrix[0][b_i];
    c_camera_params.IntrinsicMatrixInternal[b_i][1] =
        cameraParams->IntrinsicMatrix[1][b_i];
    c_camera_params.IntrinsicMatrixInternal[b_i][2] =
        cameraParams->IntrinsicMatrix[2][b_i];
  }
  c_camera_params.RadialDistortion[0] = cameraParams->RadialDistortion[0];
  c_camera_params.RadialDistortion[1] = cameraParams->RadialDistortion[1];
  c_camera_params.RadialDistortion[2] = cameraParams->RadialDistortion[2];
  c_camera_params.TangentialDistortion[0] =
      cameraParams->TangentialDistortion[0];
  c_camera_params.TangentialDistortion[1] =
      cameraParams->TangentialDistortion[1];
  c_camera_params.ImageSize[0] = cameraParams->ImageSize[0];
  c_camera_params.ImageSize[1] = cameraParams->ImageSize[1];
  c_camera_params.NumRadialDistortionCoefficients =
      cameraParams->NumRadialDistortionCoefficients;
  c_camera_params.UndistortMap.XBounds[0] = -1.0;
  c_camera_params.UndistortMap.XBounds[1] = -1.0;
  c_camera_params.UndistortMap.YBounds[0] = -1.0;
  c_camera_params.UndistortMap.YBounds[1] = -1.0;
  c_camera_params.UndistortMap.SizeOfImage.set_size(1, 2);
  c_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  c_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  c_camera_params.UndistortMap.SizeOfImage.set_size(1, 3);
  c_camera_params.UndistortMap.SizeOfImage[0] = 0.0;
  c_camera_params.UndistortMap.SizeOfImage[1] = 0.0;
  c_camera_params.UndistortMap.SizeOfImage[2] = 0.0;
  c_camera_params.UndistortMap.ClassOfImage.set_size(1, 1);
  c_camera_params.UndistortMap.ClassOfImage[0] = 'a';
  c_camera_params.UndistortMap.ClassOfImage.set_size(1, 5);
  for (int i1{0}; i1 < 5; i1++) {
    c_camera_params.UndistortMap.ClassOfImage[i1] = b_cv[i1];
  }
  c_camera_params.UndistortMap.OutputView.set_size(1, 1);
  c_camera_params.UndistortMap.OutputView[0] = 'a';
  c_camera_params.UndistortMap.OutputView.set_size(1, 4);
  for (int i2{0}; i2 < 4; i2++) {
    c_camera_params.UndistortMap.OutputView[i2] = x2[i2];
  }
  c_camera_params.UndistortMap.XmapSingle.set_size(2, 2);
  for (int i3{0}; i3 < 2; i3++) {
    c_camera_params.UndistortMap
        .XmapSingle[c_camera_params.UndistortMap.XmapSingle.size(0) * i3] =
        0.0F;
    c_camera_params.UndistortMap
        .XmapSingle[(c_camera_params.UndistortMap.XmapSingle.size(0) * i3) +
                    1] = 0.0F;
  }
  c_camera_params.UndistortMap.YmapSingle.set_size(2, 2);
  for (int i4{0}; i4 < 2; i4++) {
    c_camera_params.UndistortMap
        .YmapSingle[c_camera_params.UndistortMap.YmapSingle.size(0) * i4] =
        0.0F;
    c_camera_params.UndistortMap
        .YmapSingle[(c_camera_params.UndistortMap.YmapSingle.size(0) * i4) +
                    1] = 0.0F;
  }
  b_images[0] = images.size(0);
  b_images[1] = images.size(1);
  gray_images.set_size(images.size(0), images.size(1), 1, images.size(3));
  loop_ub = images.size(3);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i7, b_loop_ub, b_i8, d_loop_ub)

  for (int i5 = 0; i5 < loop_ub; i5++) {
    d_loop_ub = b_images[1];
    for (b_i8 = 0; b_i8 < d_loop_ub; b_i8++) {
      b_loop_ub = b_images[0];
      for (i7 = 0; i7 < b_loop_ub; i7++) {
        gray_images[(i7 + (gray_images.size(0) * b_i8)) +
                    ((gray_images.size(0) * gray_images.size(1)) * i5)] = 0U;
      }
    }
  }
  i6 = images.size(3);
  for (int c_i{0}; c_i < i6; c_i++) {
    int c_loop_ub;
    //  If RGB images, convert to gray
    c_loop_ub = images.size(2);
    if (images.size(2) == 3) {
      int current_images_idx_0;
      int current_images_idx_1;
      int f_loop_ub;
      int h_loop_ub;
      f_loop_ub = images.size(0);
      h_loop_ub = images.size(1);
      d_X.set_size(images.size(0), images.size(1), 3);
      for (int i10{0}; i10 < 3; i10++) {
        for (int i12{0}; i12 < h_loop_ub; i12++) {
          for (int i14{0}; i14 < f_loop_ub; i14++) {
            d_X[(i14 + (d_X.size(0) * i12)) +
                ((d_X.size(0) * d_X.size(1)) * i10)] =
                images[((i14 + (images.size(0) * i12)) +
                        ((images.size(0) * images.size(1)) * i10)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
      b_current_images.set_size(images.size(0), images.size(1));
      rgb2gray_tbb_uint8(&d_X[0],
                         (static_cast<double>(images.size(0))) *
                             (static_cast<double>(images.size(1))),
                         &b_current_images[0], true);
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
      for (int i9{0}; i9 < c_loop_ub; i9++) {
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
    //  If true, the images get undistorted
    if (undistort) {
      int j_loop_ub;
      int m_loop_ub;
      int p_loop_ub;
      int s_loop_ub;
      int t_loop_ub;
      int u_loop_ub;
      int unnamed_idx_0;
      int v_loop_ub;
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
      if (current_images.size(2) > 1) {
        fillValues.set_size(fillValues.size(0), fillValues.size(1), 3);
      } else {
        fillValues.set_size(fillValues.size(0), fillValues.size(1), 1);
      }
      varargin_2[0] = static_cast<unsigned int>(current_images.size(0));
      varargin_2[1] = static_cast<unsigned int>(current_images.size(1));
      varargin_2[2] = static_cast<unsigned int>(current_images.size(2));
      p = (c_camera_params.UndistortMap.SizeOfImage.size(1) == 3);
      b_p = p;
      if (p) {
        if (c_camera_params.UndistortMap.SizeOfImage.size(1) != 0) {
          int k;
          b_p = true;
          k = 0;
          exitg1 = false;
          while (
              (!exitg1) &&
              (k <= (c_camera_params.UndistortMap.SizeOfImage.size(1) - 1))) {
            if (!(c_camera_params.UndistortMap.SizeOfImage[k] ==
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
      if (5 == c_camera_params.UndistortMap.ClassOfImage.size(1)) {
        int kstr;
        kstr = 0;
        int exitg2;
        do {
          exitg2 = 0;
          if (kstr < 5) {
            if (b_cv1[kstr] !=
                c_camera_params.UndistortMap.ClassOfImage[kstr]) {
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
      c_p = (c_camera_params.UndistortMap.OutputView.size(1) == 4);
      d_p = c_p;
      if (c_p) {
        if (c_camera_params.UndistortMap.OutputView.size(1) != 0) {
          int b_k;
          d_p = true;
          b_k = 0;
          exitg1 = false;
          while (
              (!exitg1) &&
              (b_k <= (c_camera_params.UndistortMap.OutputView.size(1) - 1))) {
            if (!(c_camera_params.UndistortMap.OutputView[b_k] == x2[b_k])) {
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
              c_camera_params.IntrinsicMatrixInternal[0][i23];
          b_intrinsicMatrix[i23][1] =
              c_camera_params.IntrinsicMatrixInternal[1][i23];
          b_intrinsicMatrix[i23][2] =
              c_camera_params.IntrinsicMatrixInternal[2][i23];
        }
        b_dv[0] = 1.0;
        b_dv[1] = static_cast<double>(
            static_cast<unsigned int>(current_images.size(1)));
        b_dv1[0] = 1.0;
        b_dv1[1] = static_cast<double>(
            static_cast<unsigned int>(current_images.size(0)));
        d_camera_params[0] = c_camera_params.RadialDistortion[0];
        d_camera_params[1] = c_camera_params.RadialDistortion[1];
        d_camera_params[2] = c_camera_params.RadialDistortion[2];
        e_camera_params[0] = c_camera_params.TangentialDistortion[0];
        e_camera_params[1] = c_camera_params.TangentialDistortion[1];
        c_camera_params.UndistortMap.update(current_images, b_intrinsicMatrix,
                                            d_camera_params, e_camera_params,
                                            b_dv, b_dv1);
      }
      b_this = &c_camera_params.UndistortMap;
      Y_T.set_size(b_this->XmapSingle.size(0), b_this->XmapSingle.size(1));
      p_loop_ub = b_this->XmapSingle.size(1);
      for (int i24{0}; i24 < p_loop_ub; i24++) {
        int q_loop_ub;
        q_loop_ub = b_this->XmapSingle.size(0);
        for (int i25{0}; i25 < q_loop_ub; i25++) {
          Y_T[i25 + (Y_T.size(0) * i24)] =
              b_this->XmapSingle[i25 + (b_this->XmapSingle.size(0) * i24)];
        }
      }
      if (fillValues.size(2) == 1) {
        fill.set_size(
            static_cast<int>(static_cast<signed char>(current_images.size(2))),
            1, 1);
        if ((static_cast<signed char>(current_images.size(2))) != 0) {
          int i27;
          i27 = (static_cast<int>(
                    static_cast<signed char>(current_images.size(2)))) -
                1;
          for (int b_t{0}; b_t <= i27; b_t++) {
            fill[b_t] = 0U;
          }
        }
      } else {
        int r_loop_ub;
        fill.set_size(1, 1, fillValues.size(2));
        r_loop_ub = fillValues.size(2);
        for (int i26{0}; i26 < r_loop_ub; i26++) {
          fill[fill.size(0) * i26] = 0U;
        }
      }
      outputImage.set_size(Y_T.size(0), Y_T.size(1), current_images.size(2));
      inputImageSize[0] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(0)));
      inputImageSize[1] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(1)));
      inputImageSize[2] = static_cast<double>(
          static_cast<unsigned int>(current_images.size(2)));
      outputImageSize[0] = static_cast<double>(Y_T.size(0));
      outputImageSize[1] = static_cast<double>(Y_T.size(1));
      outputImageSize[2] = static_cast<double>(current_images.size(2));
      imterp2d32f_uint8(&current_images[0], &inputImageSize[0],
                        &b_this->YmapSingle[0], &Y_T[0], &outputImageSize[0],
                        2.0, (fill.size(0) * fill.size(2)) == 1, &fill[0],
                        &outputImage[0]);
      f_J.set_size(current_images.size(0), current_images.size(1),
                   current_images.size(2));
      if (1 > current_images.size(0)) {
        s_loop_ub = 0;
      } else {
        s_loop_ub = current_images.size(0);
      }
      if (1 > current_images.size(1)) {
        t_loop_ub = 0;
      } else {
        t_loop_ub = current_images.size(1);
      }
      if (1 > current_images.size(2)) {
        u_loop_ub = 0;
      } else {
        u_loop_ub = current_images.size(2);
      }
      for (int i28{0}; i28 < u_loop_ub; i28++) {
        for (int i29{0}; i29 < t_loop_ub; i29++) {
          for (int i31{0}; i31 < s_loop_ub; i31++) {
            f_J[(i31 + (f_J.size(0) * i29)) +
                ((f_J.size(0) * f_J.size(1)) * i28)] =
                outputImage[(i31 + (outputImage.size(0) * i29)) +
                            ((outputImage.size(0) * outputImage.size(1)) *
                             i28)];
          }
        }
      }
      unnamed_idx_0 = r.size(0);
      v_loop_ub = r1.size(0);
      for (int i30{0}; i30 < v_loop_ub; i30++) {
        for (int i32{0}; i32 < unnamed_idx_0; i32++) {
          gray_images[(r[i32] + (gray_images.size(0) * r1[i30])) +
                      ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
              f_J[i32 + (unnamed_idx_0 * i30)];
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

} // namespace ITER

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
