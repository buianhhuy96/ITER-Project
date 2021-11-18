//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
  coder::array<double, 2U> varargin_1;
  coder::array<float, 3U> outputImage;
  coder::array<float, 2U> XIntrinsic;
  coder::array<float, 2U> Xin;
  coder::array<float, 2U> YIntrinsic;
  coder::array<float, 2U> Yin;
  coder::array<float, 2U> c_current_images;
  coder::array<float, 2U> r2;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<unsigned char, 3U> c_J;
  coder::array<unsigned char, 3U> current_images;
  coder::array<unsigned char, 3U> d_J;
  coder::array<char, 2U> b;
  coder::array<unsigned char, 2U> b_current_images;
  double b_intrinsicMatrix[3][3];
  double c_camera_params[3];
  double d_camera_params[2];
  double dv[2];
  double dv1[2];
  unsigned int varargin_2[3];
  int b_i;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i1;
  int i2;
  int loop_ub;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  for (b_i = 0; b_i < 3; b_i++) {
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
  for (b_i = 0; b_i < 3; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .RotationVectors[i1 +
                           (b_camera_params.RotationVectors.size(0) * b_i)] =
          camera_params
              ->RotationVectors[i1 +
                                (camera_params->RotationVectors.size(0) * b_i)];
    }
  }
  b_camera_params.TranslationVectors.set_size(
      camera_params->TranslationVectors.size(0), 3);
  loop_ub = camera_params->TranslationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .TranslationVectors[i1 + (b_camera_params.TranslationVectors.size(0) *
                                    b_i)] =
          camera_params->TranslationVectors
              [i1 + (camera_params->TranslationVectors.size(0) * b_i)];
    }
  }
  b_camera_params.WorldPoints.set_size(camera_params->WorldPoints.size(0), 2);
  loop_ub = camera_params->WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .WorldPoints[i1 + (b_camera_params.WorldPoints.size(0) * b_i)] =
          camera_params
              ->WorldPoints[i1 + (camera_params->WorldPoints.size(0) * b_i)];
    }
  }
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  b_camera_params.DetectedKeypoints.set_size(
      camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  loop_ub = camera_params->DetectedKeypoints.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = camera_params->DetectedKeypoints.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_camera_params
          .DetectedKeypoints[i1 + (b_camera_params.DetectedKeypoints.size(0) *
                                   b_i)] =
          camera_params->DetectedKeypoints
              [i1 + (camera_params->DetectedKeypoints.size(0) * b_i)];
    }
  }
  if ((camera_params->ReprojectionErrors.size(0) == 0) ||
      (camera_params->ReprojectionErrors.size(2) == 0)) {
    b_camera_params.ReprojectionErrors.set_size(0, 2, 1);
  } else {
    b_camera_params.ReprojectionErrors.set_size(
        camera_params->ReprojectionErrors.size(0), 2,
        camera_params->ReprojectionErrors.size(2));
    loop_ub = camera_params->ReprojectionErrors.size(2);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = camera_params->ReprojectionErrors.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_camera_params.ReprojectionErrors
              [(i2 + (b_camera_params.ReprojectionErrors.size(0) * i1)) +
               ((b_camera_params.ReprojectionErrors.size(0) * 2) * b_i)] =
              camera_params->ReprojectionErrors
                  [(i2 + (camera_params->ReprojectionErrors.size(0) * i1)) +
                   ((camera_params->ReprojectionErrors.size(0) * 2) * b_i)];
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
  for (b_i = 0; b_i < 5; b_i++) {
    b_camera_params.UndistortMap.ClassOfImage[b_i] = b_cv[b_i];
  }
  b_camera_params.UndistortMap.OutputView.set_size(1, 1);
  b_camera_params.UndistortMap.OutputView[0] = 'a';
  b_camera_params.UndistortMap.OutputView.set_size(1, 4);
  for (b_i = 0; b_i < 4; b_i++) {
    b_camera_params.UndistortMap.OutputView[b_i] = x2[b_i];
  }
  b_camera_params.UndistortMap.XmapSingle.set_size(2, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    b_camera_params.UndistortMap
        .XmapSingle[b_camera_params.UndistortMap.XmapSingle.size(0) * b_i] =
        0.0F;
    b_camera_params.UndistortMap
        .XmapSingle[(b_camera_params.UndistortMap.XmapSingle.size(0) * b_i) +
                    1] = 0.0F;
  }
  b_camera_params.UndistortMap.YmapSingle.set_size(2, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    b_camera_params.UndistortMap
        .YmapSingle[b_camera_params.UndistortMap.YmapSingle.size(0) * b_i] =
        0.0F;
    b_camera_params.UndistortMap
        .YmapSingle[(b_camera_params.UndistortMap.YmapSingle.size(0) * b_i) +
                    1] = 0.0F;
  }
  gray_images.set_size(images.size(0), images.size(1), 1, images.size(3));
  loop_ub = images.size(3);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = images.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      e_loop_ub = images.size(0);
      for (i2 = 0; i2 < e_loop_ub; i2++) {
        gray_images[(i2 + (gray_images.size(0) * i1)) +
                    ((gray_images.size(0) * gray_images.size(1)) * b_i)] = 0U;
      }
    }
  }
  b_i = images.size(3);
  if (0 <= (b_i - 1)) {
    c_loop_ub = images.size(0);
    d_loop_ub = images.size(1);
    f_loop_ub = images.size(2);
  }
  for (int c_i{0}; c_i < b_i; c_i++) {
    int c_P;
    int i3;
    bool b_p;
    bool exitg1;
    bool p;
    bool sameClass;
    current_images.set_size(images.size(0), images.size(1), images.size(2));
    for (i1 = 0; i1 < f_loop_ub; i1++) {
      for (i2 = 0; i2 < d_loop_ub; i2++) {
        for (i3 = 0; i3 < c_loop_ub; i3++) {
          current_images[(i3 + (current_images.size(0) * i2)) +
                         ((current_images.size(0) * current_images.size(1)) *
                          i1)] =
              images[((i3 + (images.size(0) * i2)) +
                      ((images.size(0) * images.size(1)) * i1)) +
                     (((images.size(0) * images.size(1)) * images.size(2)) *
                      c_i)];
        }
      }
    }
    //  If gray images, convert to RGB
    if (images.size(2) == 3) {
      loop_ub = images.size(0);
      b_loop_ub = images.size(1);
      current_images.set_size(images.size(0), images.size(1), 3);
      for (i1 = 0; i1 < 3; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (i3 = 0; i3 < loop_ub; i3++) {
            current_images[(i3 + (current_images.size(0) * i2)) +
                           ((current_images.size(0) * current_images.size(1)) *
                            i1)] =
                images[((i3 + (images.size(0) * i2)) +
                        ((images.size(0) * images.size(1)) * i1)) +
                       (((images.size(0) * images.size(1)) * images.size(2)) *
                        c_i)];
          }
        }
      }
      coder::rgb2gray(current_images, b_current_images);
      e_loop_ub = b_current_images.size(0);
      b_loop_ub = b_current_images.size(1);
      current_images.set_size(b_current_images.size(0),
                              b_current_images.size(1), 1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < e_loop_ub; i2++) {
          current_images[i2 + (current_images.size(0) * i1)] =
              b_current_images[i2 + (e_loop_ub * i1)];
        }
      }
    }
    loop_ub = gray_images.size(0);
    r.set_size(gray_images.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1] = i1;
    }
    loop_ub = gray_images.size(1);
    r1.set_size(gray_images.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1] = i1;
    }
    varargin_1.set_size(1, b_camera_params.UndistortMap.SizeOfImage.size(1));
    loop_ub = b_camera_params.UndistortMap.SizeOfImage.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1[i1] = b_camera_params.UndistortMap.SizeOfImage[i1];
    }
    varargin_2[0] = static_cast<unsigned int>(current_images.size(0));
    varargin_2[1] = static_cast<unsigned int>(current_images.size(1));
    varargin_2[2] = static_cast<unsigned int>(current_images.size(2));
    p = (varargin_1.size(1) == 3);
    if (p) {
      if (varargin_1.size(1) != 0) {
        p = true;
        e_loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (e_loop_ub <= (varargin_1.size(1) - 1))) {
          if (!(varargin_1[e_loop_ub] ==
                (static_cast<double>(varargin_2[e_loop_ub])))) {
            p = false;
            exitg1 = true;
          } else {
            e_loop_ub++;
          }
        }
      }
    }
    b.set_size(1, b_camera_params.UndistortMap.ClassOfImage.size(1));
    loop_ub = b_camera_params.UndistortMap.ClassOfImage.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b[i1] = b_camera_params.UndistortMap.ClassOfImage[i1];
    }
    sameClass = false;
    if (5 == b.size(1)) {
      e_loop_ub = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (e_loop_ub < 5) {
          if (cv1[e_loop_ub] != b[e_loop_ub]) {
            exitg2 = 1;
          } else {
            e_loop_ub++;
          }
        } else {
          sameClass = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    b.set_size(1, b_camera_params.UndistortMap.OutputView.size(1));
    loop_ub = b_camera_params.UndistortMap.OutputView.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b[i1] = b_camera_params.UndistortMap.OutputView[i1];
    }
    b_p = (b.size(1) == 4);
    if (b_p) {
      if (b.size(1) != 0) {
        b_p = true;
        e_loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (e_loop_ub <= (b.size(1) - 1))) {
          if (!(b[e_loop_ub] == x2[e_loop_ub])) {
            b_p = false;
            exitg1 = true;
          } else {
            e_loop_ub++;
          }
        }
      }
    }
    if (((!p) || (!sameClass)) || (!b_p)) {
      for (i1 = 0; i1 < 3; i1++) {
        b_intrinsicMatrix[i1][0] =
            b_camera_params.IntrinsicMatrixInternal[0][i1];
        b_intrinsicMatrix[i1][1] =
            b_camera_params.IntrinsicMatrixInternal[1][i1];
        b_intrinsicMatrix[i1][2] =
            b_camera_params.IntrinsicMatrixInternal[2][i1];
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
    loop_ub = b_this->XmapSingle.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_this->XmapSingle.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        Xin[i2 + (Xin.size(0) * i1)] =
            b_this->XmapSingle[i2 + (b_this->XmapSingle.size(0) * i1)];
      }
    }
    Yin.set_size(b_this->YmapSingle.size(0), b_this->YmapSingle.size(1));
    loop_ub = b_this->YmapSingle.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_this->YmapSingle.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        Yin[i2 + (Yin.size(0) * i1)] =
            b_this->YmapSingle[i2 + (b_this->YmapSingle.size(0) * i1)];
      }
    }
    if (current_images.size(2) == 1) {
      unsigned int sizeVec_idx_0;
      unsigned int sizeVec_idx_1;
      c_P = 0;
      sizeVec_idx_0 = static_cast<unsigned int>(Xin.size(0));
      sizeVec_idx_1 = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), 1);
      loop_ub = static_cast<int>(sizeVec_idx_1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = static_cast<int>(sizeVec_idx_0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          outputImage[i2 + (outputImage.size(0) * i1)] = 0.0F;
        }
      }
    } else {
      c_P = current_images.size(2) - 1;
      varargin_2[0] = static_cast<unsigned int>(Xin.size(0));
      varargin_2[1] = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), current_images.size(2));
      loop_ub = current_images.size(2);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = static_cast<int>(varargin_2[1]);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          e_loop_ub = static_cast<int>(varargin_2[0]);
          for (i3 = 0; i3 < e_loop_ub; i3++) {
            outputImage[(i3 + (outputImage.size(0) * i2)) +
                        ((outputImage.size(0) * outputImage.size(1)) * i1)] =
                0.0F;
          }
        }
      }
    }
    if (current_images.size(1) < 1) {
      varargin_1.set_size(1, 0);
    } else {
      varargin_1.set_size(1, current_images.size(1));
      loop_ub = current_images.size(1) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        varargin_1[i1] = (static_cast<double>(i1)) + 1.0;
      }
    }
    XIntrinsic.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      XIntrinsic[i1] = static_cast<float>(varargin_1[i1]);
    }
    if (current_images.size(0) < 1) {
      varargin_1.set_size(1, 0);
    } else {
      varargin_1.set_size(1, current_images.size(0));
      loop_ub = current_images.size(0) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        varargin_1[i1] = (static_cast<double>(i1)) + 1.0;
      }
    }
    YIntrinsic.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      YIntrinsic[i1] = static_cast<float>(varargin_1[i1]);
    }
    for (e_loop_ub = 0; e_loop_ub <= c_P; e_loop_ub++) {
      loop_ub = current_images.size(0);
      b_loop_ub = current_images.size(1);
      c_current_images.set_size(current_images.size(0), current_images.size(1));
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          c_current_images[i2 + (c_current_images.size(0) * i1)] =
              static_cast<float>(
                  current_images[(i2 + (current_images.size(0) * i1)) +
                                 ((current_images.size(0) *
                                   current_images.size(1)) *
                                  e_loop_ub)]);
        }
      }
      coder::images::internal::coder::interp2_local(
          c_current_images, Xin, Yin, 0.0F, XIntrinsic, YIntrinsic, r2);
      loop_ub = r2.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r2.size(0);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          outputImage[(i2 + (outputImage.size(0) * i1)) +
                      ((outputImage.size(0) * outputImage.size(1)) *
                       e_loop_ub)] = r2[i2 + (r2.size(0) * i1)];
        }
      }
    }
    c_J.set_size(outputImage.size(0), outputImage.size(1), outputImage.size(2));
    loop_ub = outputImage.size(2);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = outputImage.size(1);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        e_loop_ub = outputImage.size(0);
        for (i3 = 0; i3 < e_loop_ub; i3++) {
          float f;
          unsigned char b_u;
          f = std::round(
              outputImage[(i3 + (outputImage.size(0) * i2)) +
                          ((outputImage.size(0) * outputImage.size(1)) * i1)]);
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
          c_J[(i3 + (c_J.size(0) * i2)) + ((c_J.size(0) * c_J.size(1)) * i1)] =
              b_u;
        }
      }
    }
    d_J.set_size(current_images.size(0), current_images.size(1),
                 current_images.size(2));
    if (1 > current_images.size(0)) {
      loop_ub = 0;
    } else {
      loop_ub = current_images.size(0);
    }
    if (1 > current_images.size(1)) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = current_images.size(1);
    }
    if (1 > current_images.size(2)) {
      e_loop_ub = 0;
    } else {
      e_loop_ub = current_images.size(2);
    }
    for (i1 = 0; i1 < e_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          d_J[(i3 + (d_J.size(0) * i2)) + ((d_J.size(0) * d_J.size(1)) * i1)] =
              c_J[(i3 + (c_J.size(0) * i2)) +
                  ((c_J.size(0) * c_J.size(1)) * i1)];
        }
      }
    }
    e_loop_ub = r.size(0);
    loop_ub = r1.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < e_loop_ub; i2++) {
        gray_images[(r[i2] + (gray_images.size(0) * r1[i1])) +
                    ((gray_images.size(0) * gray_images.size(1)) * c_i)] =
            d_J[i2 + (e_loop_ub * i1)];
      }
    }
  }
}

//
// File trailer for preprocessImages.cpp
//
// [EOF]
//
