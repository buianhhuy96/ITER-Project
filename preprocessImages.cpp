//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: preprocessImages.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
#include <algorithm>
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<unsigned char, 4U> &b_images
//                const struct1_T *camera_params
//                coder::array<unsigned char, 4U> &gray_images
// Return Type  : void
//
void preprocessImages(const coder::array<unsigned char, 4U> &b_images,
                      const struct1_T *camera_params,
                      coder::array<unsigned char, 4U> &gray_images)
{
  static const char cv[5]{'u', 'i', 'n', 't', '8'};
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
  coder::array<float, 2U> b_inputImage;
  coder::array<float, 2U> r;
  coder::array<int, 1U> r2;
  coder::array<int, 1U> r3;
  coder::array<unsigned char, 3U> fill;
  coder::array<unsigned char, 3U> inputImage;
  coder::array<char, 2U> b;
  coder::array<unsigned char, 2U> r1;
  double intrinsicMatrix[3][3];
  double c_camera_params[3];
  double d_camera_params[2];
  double dv[2];
  double dv1[2];
  unsigned int varargin_2[3];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i;
  int i1;
  int i10;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i9;
  int i_loop_ub;
  int loop_ub;
  if (!isInitialized_calibrateHandeye) {
    calibrateHandeye_initialize();
  }
  for (i = 0; i < 3; i++) {
    b_camera_params.IntrinsicMatrixInternal[i][0] =
        camera_params->IntrinsicMatrix[0][i];
    b_camera_params.IntrinsicMatrixInternal[i][1] =
        camera_params->IntrinsicMatrix[1][i];
    b_camera_params.IntrinsicMatrixInternal[i][2] =
        camera_params->IntrinsicMatrix[2][i];
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
  (void)std::copy(&camera_params->RotationVectors[0][0],
                  (&camera_params->RotationVectors[0][0]) + 90U,
                  &b_camera_params.RotationVectors[0][0]);
  (void)std::copy(&camera_params->TranslationVectors[0][0],
                  (&camera_params->TranslationVectors[0][0]) + 90U,
                  &b_camera_params.TranslationVectors[0][0]);
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
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
  for (i = 0; i < 5; i++) {
    b_camera_params.UndistortMap.ClassOfImage[i] = cv[i];
  }
  b_camera_params.UndistortMap.OutputView.set_size(1, 1);
  b_camera_params.UndistortMap.OutputView[0] = 'a';
  b_camera_params.UndistortMap.OutputView.set_size(1, 4);
  b_camera_params.UndistortMap.OutputView[0] = 's';
  b_camera_params.UndistortMap.OutputView[1] = 'a';
  b_camera_params.UndistortMap.OutputView[2] = 'm';
  b_camera_params.UndistortMap.OutputView[3] = 'e';
  b_camera_params.UndistortMap.XmapSingle.set_size(2, 2);
  b_camera_params.UndistortMap.XmapSingle[0] = 0.0F;
  b_camera_params.UndistortMap.XmapSingle[1] = 0.0F;
  b_camera_params.UndistortMap
      .XmapSingle[b_camera_params.UndistortMap.XmapSingle.size(0)] = 0.0F;
  b_camera_params.UndistortMap
      .XmapSingle[b_camera_params.UndistortMap.XmapSingle.size(0) + 1] = 0.0F;
  b_camera_params.UndistortMap.YmapSingle.set_size(2, 2);
  b_camera_params.UndistortMap.YmapSingle[0] = 0.0F;
  b_camera_params.UndistortMap.YmapSingle[1] = 0.0F;
  b_camera_params.UndistortMap
      .YmapSingle[b_camera_params.UndistortMap.YmapSingle.size(0)] = 0.0F;
  b_camera_params.UndistortMap
      .YmapSingle[b_camera_params.UndistortMap.YmapSingle.size(0) + 1] = 0.0F;
  gray_images.set_size(b_images.size(0), b_images.size(1), 1, b_images.size(3));
  loop_ub = b_images.size(3);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_images.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      e_loop_ub = b_images.size(0);
      for (i3 = 0; i3 < e_loop_ub; i3++) {
        gray_images[(i3 + (gray_images.size(0) * i1)) +
                    ((gray_images.size(0) * gray_images.size(1)) * i)] = 0U;
      }
    }
  }
  i = b_images.size(3);
  if (0 <= (b_images.size(3) - 1)) {
    c_loop_ub = b_images.size(0);
    d_loop_ub = b_images.size(1);
    i2 = b_images.size(2);
    f_loop_ub = b_images.size(2);
    i4 = b_images.size(0);
    i5 = b_images.size(1);
    i6 = b_images.size(2);
    i7 = b_images.size(0);
    i9 = b_images.size(1);
    i10 = b_images.size(2);
    if (1 > b_images.size(0)) {
      g_loop_ub = -1;
    } else {
      g_loop_ub = b_images.size(0) - 1;
    }
    if (1 > b_images.size(1)) {
      h_loop_ub = -1;
    } else {
      h_loop_ub = b_images.size(1) - 1;
    }
    if (1 > b_images.size(2)) {
      i_loop_ub = -1;
    } else {
      i_loop_ub = b_images.size(2) - 1;
    }
  }
  for (int b_i{0}; b_i < i; b_i++) {
    int P;
    int i8;
    bool exitg1;
    bool p;
    bool sameClass;
    bool sameOutputView;
    bool sameSize;
    inputImage.set_size(c_loop_ub, d_loop_ub, i2);
    for (i1 = 0; i1 < f_loop_ub; i1++) {
      for (i3 = 0; i3 < d_loop_ub; i3++) {
        for (i8 = 0; i8 < c_loop_ub; i8++) {
          inputImage[(i8 + (inputImage.size(0) * i3)) +
                     ((inputImage.size(0) * inputImage.size(1)) * i1)] =
              b_images[((i8 + (b_images.size(0) * i3)) +
                        ((b_images.size(0) * b_images.size(1)) * i1)) +
                       (((b_images.size(0) * b_images.size(1)) *
                         b_images.size(2)) *
                        b_i)];
        }
      }
    }
    varargin_1.set_size(1, b_camera_params.UndistortMap.SizeOfImage.size(1));
    loop_ub = b_camera_params.UndistortMap.SizeOfImage.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1[i1] = b_camera_params.UndistortMap.SizeOfImage[i1];
    }
    varargin_2[0] = static_cast<unsigned int>(i4);
    varargin_2[1] = static_cast<unsigned int>(i5);
    varargin_2[2] = static_cast<unsigned int>(i6);
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
          }
          if (!p) {
            exitg1 = true;
          } else {
            e_loop_ub++;
          }
        }
      }
    }
    sameSize = p;
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
    p = (b.size(1) == 4);
    if (p) {
      if (b.size(1) != 0) {
        p = true;
        e_loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (e_loop_ub <= (b.size(1) - 1))) {
          if (!(b[e_loop_ub] == x2[e_loop_ub])) {
            p = false;
          }
          if (!p) {
            exitg1 = true;
          } else {
            e_loop_ub++;
          }
        }
      }
    }
    sameOutputView = p;
    if (((!sameSize) || (!sameClass)) || (!sameOutputView)) {
      for (i1 = 0; i1 < 3; i1++) {
        intrinsicMatrix[i1][0] = b_camera_params.IntrinsicMatrixInternal[0][i1];
        intrinsicMatrix[i1][1] = b_camera_params.IntrinsicMatrixInternal[1][i1];
        intrinsicMatrix[i1][2] = b_camera_params.IntrinsicMatrixInternal[2][i1];
      }
      dv[0] = 1.0;
      dv[1] = static_cast<double>(static_cast<unsigned int>(b_images.size(1)));
      dv1[0] = 1.0;
      dv1[1] = static_cast<double>(static_cast<unsigned int>(b_images.size(0)));
      c_camera_params[0] = b_camera_params.RadialDistortion[0];
      c_camera_params[1] = b_camera_params.RadialDistortion[1];
      c_camera_params[2] = b_camera_params.RadialDistortion[2];
      d_camera_params[0] = b_camera_params.TangentialDistortion[0];
      d_camera_params[1] = b_camera_params.TangentialDistortion[1];
      b_camera_params.UndistortMap.update(inputImage, intrinsicMatrix,
                                          c_camera_params, d_camera_params, dv,
                                          dv1);
    }
    b_this = &b_camera_params.UndistortMap;
    Xin.set_size(b_this->XmapSingle.size(0), b_this->XmapSingle.size(1));
    loop_ub = b_this->XmapSingle.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_this->XmapSingle.size(0);
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        Xin[i3 + (Xin.size(0) * i1)] =
            b_this->XmapSingle[i3 + (b_this->XmapSingle.size(0) * i1)];
      }
    }
    Yin.set_size(b_this->YmapSingle.size(0), b_this->YmapSingle.size(1));
    loop_ub = b_this->YmapSingle.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_this->YmapSingle.size(0);
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        Yin[i3 + (Yin.size(0) * i1)] =
            b_this->YmapSingle[i3 + (b_this->YmapSingle.size(0) * i1)];
      }
    }
    if (inputImage.size(2) == 1) {
      unsigned int sizeVec_idx_0;
      unsigned int sizeVec_idx_1;
      P = 0;
      sizeVec_idx_0 = static_cast<unsigned int>(Xin.size(0));
      sizeVec_idx_1 = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), 1);
      loop_ub = static_cast<int>(sizeVec_idx_1);
      for (i1 = 0; i1 < 1; i1++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_loop_ub = static_cast<int>(sizeVec_idx_0);
          for (i8 = 0; i8 < b_loop_ub; i8++) {
            outputImage[i8 + (outputImage.size(0) * i3)] = 0.0F;
          }
        }
      }
    } else {
      P = inputImage.size(2) - 1;
      varargin_2[0] = static_cast<unsigned int>(Xin.size(0));
      varargin_2[1] = static_cast<unsigned int>(Xin.size(1));
      outputImage.set_size(Xin.size(0), Xin.size(1), inputImage.size(2));
      loop_ub = inputImage.size(2);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = static_cast<int>(varargin_2[1]);
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          e_loop_ub = static_cast<int>(varargin_2[0]);
          for (i8 = 0; i8 < e_loop_ub; i8++) {
            outputImage[(i8 + (outputImage.size(0) * i3)) +
                        ((outputImage.size(0) * outputImage.size(1)) * i1)] =
                0.0F;
          }
        }
      }
    }
    if (inputImage.size(1) < 1) {
      varargin_1.set_size(1, 0);
    } else {
      varargin_1.set_size(1, inputImage.size(1));
      loop_ub = inputImage.size(1) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        varargin_1[i1] = (static_cast<double>(i1)) + 1.0;
      }
    }
    XIntrinsic.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      XIntrinsic[i1] = static_cast<float>(varargin_1[i1]);
    }
    if (inputImage.size(0) < 1) {
      varargin_1.set_size(1, 0);
    } else {
      varargin_1.set_size(1, inputImage.size(0));
      loop_ub = inputImage.size(0) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        varargin_1[i1] = (static_cast<double>(i1)) + 1.0;
      }
    }
    YIntrinsic.set_size(1, varargin_1.size(1));
    loop_ub = varargin_1.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      YIntrinsic[i1] = static_cast<float>(varargin_1[i1]);
    }
    for (e_loop_ub = 0; e_loop_ub <= P; e_loop_ub++) {
      loop_ub = inputImage.size(0);
      b_loop_ub = inputImage.size(1);
      b_inputImage.set_size(inputImage.size(0), inputImage.size(1));
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_inputImage[i3 + (b_inputImage.size(0) * i1)] = static_cast<float>(
              inputImage[(i3 + (inputImage.size(0) * i1)) +
                         ((inputImage.size(0) * inputImage.size(1)) *
                          e_loop_ub)]);
        }
      }
      coder::images::internal::coder::interp2_local(
          b_inputImage, Xin, Yin, 0.0F, XIntrinsic, YIntrinsic, r);
      loop_ub = r.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r.size(0);
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          outputImage[(i3 + (outputImage.size(0) * i1)) +
                      ((outputImage.size(0) * outputImage.size(1)) *
                       e_loop_ub)] = r[i3 + (r.size(0) * i1)];
        }
      }
    }
    inputImage.set_size(outputImage.size(0), outputImage.size(1),
                        outputImage.size(2));
    loop_ub = outputImage.size(2);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = outputImage.size(1);
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        e_loop_ub = outputImage.size(0);
        for (i8 = 0; i8 < e_loop_ub; i8++) {
          float f;
          unsigned char u;
          f = std::round(
              outputImage[(i8 + (outputImage.size(0) * i3)) +
                          ((outputImage.size(0) * outputImage.size(1)) * i1)]);
          if (f < 256.0F) {
            if (f >= 0.0F) {
              u = static_cast<unsigned char>(f);
            } else {
              u = 0U;
            }
          } else if (f >= 256.0F) {
            u = MAX_uint8_T;
          } else {
            u = 0U;
          }
          inputImage[(i8 + (inputImage.size(0) * i3)) +
                     ((inputImage.size(0) * inputImage.size(1)) * i1)] = u;
        }
      }
    }
    fill.set_size(i7, i9, i10);
    for (i1 = 0; i1 <= i_loop_ub; i1++) {
      for (i3 = 0; i3 <= h_loop_ub; i3++) {
        for (i8 = 0; i8 <= g_loop_ub; i8++) {
          fill[(i8 + (fill.size(0) * i3)) +
               ((fill.size(0) * fill.size(1)) * i1)] =
              inputImage[(i8 + (inputImage.size(0) * i3)) +
                         ((inputImage.size(0) * inputImage.size(1)) * i1)];
        }
      }
    }
    //  If gray images, convert to RGB
    if (b_images.size(2) == 3) {
      coder::rgb2gray(fill, r1);
      loop_ub = r1.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = r1.size(0);
        for (i3 = 0; i3 < b_loop_ub; i3++) {
          gray_images[(i3 + (gray_images.size(0) * i1)) +
                      ((gray_images.size(0) * gray_images.size(1)) * b_i)] =
              r1[i3 + (r1.size(0) * i1)];
        }
      }
    } else {
      loop_ub = gray_images.size(0);
      r2.set_size(gray_images.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        r2[i1] = i1;
      }
      loop_ub = gray_images.size(1);
      r3.set_size(gray_images.size(1));
      for (i1 = 0; i1 < loop_ub; i1++) {
        r3[i1] = i1;
      }
      e_loop_ub = r2.size(0);
      loop_ub = r3.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i3 = 0; i3 < e_loop_ub; i3++) {
          gray_images[(r2[i3] + (gray_images.size(0) * r3[i1])) +
                      ((gray_images.size(0) * gray_images.size(1)) * b_i)] =
              fill[i3 + (e_loop_ub * i1)];
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
