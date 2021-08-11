//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: undistort.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "undistort.h"
#include "ImageTransformer.h"
#include "calibrateHandeye_data.h"
#include "calibrateHandeye_initialize.h"
#include "calibrateHandeye_types.h"
#include "cameraParameters.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimterp2d.h"

// Function Definitions
//
// Arguments    : coder::array<unsigned char, 4U> &b_images
//                const struct0_T *camera_params
// Return Type  : void
//
void undistort(coder::array<unsigned char, 4U> &b_images,
               const struct0_T *camera_params)
{
  static const char cv[5]{'u', 'i', 'n', 't', '8'};
  static const char cv1[5]{'u', 'i', 'n', 't', '8'};
  static const char x2[4]{'s', 'a', 'm', 'e'};
  coder::b_cameraParameters b_camera_params;
  coder::vision::internal::calibration::b_ImageTransformer *b_this;
  coder::array<float, 2U> Y_T;
  coder::array<unsigned char, 3U> J;
  coder::array<unsigned char, 3U> b_I;
  coder::array<unsigned char, 3U> fill;
  coder::array<signed char, 3U> fillValues;
  coder::array<char, 2U> b;
  double intrinsicMatrix[3][3];
  double inputImageSize[3];
  double outputImageSize[3];
  double c_camera_params[2];
  double dv[2];
  double dv1[2];
  int b_loop_ub;
  int i;
  int i1;
  int i2;
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
  b_camera_params.RotationVectors.set_size(
      camera_params->RotationVectors.size(0), 3);
  loop_ub = camera_params->RotationVectors.size(0);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .RotationVectors[i1 + (b_camera_params.RotationVectors.size(0) * i)] =
          camera_params
              ->RotationVectors[i1 +
                                (camera_params->RotationVectors.size(0) * i)];
    }
  }
  b_camera_params.TranslationVectors.set_size(
      camera_params->TranslationVectors.size(0), 3);
  loop_ub = camera_params->TranslationVectors.size(0);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .TranslationVectors[i1 + (b_camera_params.TranslationVectors.size(0) *
                                    i)] =
          camera_params->TranslationVectors
              [i1 + (camera_params->TranslationVectors.size(0) * i)];
    }
  }
  b_camera_params.WorldPoints.set_size(camera_params->WorldPoints.size(0), 2);
  loop_ub = camera_params->WorldPoints.size(0);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_camera_params
          .WorldPoints[i1 + (b_camera_params.WorldPoints.size(0) * i)] =
          camera_params
              ->WorldPoints[i1 + (camera_params->WorldPoints.size(0) * i)];
    }
  }
  b_camera_params.NumRadialDistortionCoefficients =
      camera_params->NumRadialDistortionCoefficients;
  b_camera_params.DetectedKeypoints.set_size(
      camera_params->DetectedKeypoints.size(0),
      camera_params->DetectedKeypoints.size(1));
  loop_ub = camera_params->DetectedKeypoints.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = camera_params->DetectedKeypoints.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_camera_params
          .DetectedKeypoints[i1 +
                             (b_camera_params.DetectedKeypoints.size(0) * i)] =
          camera_params->DetectedKeypoints
              [i1 + (camera_params->DetectedKeypoints.size(0) * i)];
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
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = camera_params->ReprojectionErrors.size(0);
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_camera_params.ReprojectionErrors
              [(i2 + (b_camera_params.ReprojectionErrors.size(0) * i1)) +
               ((b_camera_params.ReprojectionErrors.size(0) * 2) * i)] =
              camera_params->ReprojectionErrors
                  [(i2 + (camera_params->ReprojectionErrors.size(0) * i1)) +
                   ((camera_params->ReprojectionErrors.size(0) * 2) * i)];
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
  i = b_images.size(3);
  for (int b_i{0}; b_i < i; b_i++) {
    int c_loop_ub;
    int i3;
    boolean_T exitg1;
    boolean_T p;
    boolean_T sameClass;
    boolean_T sameOutputView;
    boolean_T sameSize;
    loop_ub = b_images.size(0);
    b_loop_ub = b_images.size(1);
    c_loop_ub = b_images.size(2);
    b_I.set_size(loop_ub, b_loop_ub, c_loop_ub);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_I[(i3 + (b_I.size(0) * i2)) + ((b_I.size(0) * b_I.size(1)) * i1)] =
              b_images[((i3 + (b_images.size(0) * i2)) +
                        ((b_images.size(0) * b_images.size(1)) * i1)) +
                       (((b_images.size(0) * b_images.size(1)) *
                         b_images.size(2)) *
                        b_i)];
        }
      }
    }
    if (b_images.size(2) > 1) {
      fillValues.set_size(fillValues.size(0), fillValues.size(1), 3);
    } else {
      fillValues.set_size(fillValues.size(0), fillValues.size(1), 1);
    }
    outputImageSize[0] = static_cast<double>(b_images.size(0));
    outputImageSize[1] = static_cast<double>(b_images.size(1));
    outputImageSize[2] = static_cast<double>(b_images.size(2));
    p = (b_camera_params.UndistortMap.SizeOfImage.size(1) == 3);
    if (p) {
      if (b_camera_params.UndistortMap.SizeOfImage.size(1) != 0) {
        p = true;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) &&
               (loop_ub <=
                (b_camera_params.UndistortMap.SizeOfImage.size(1) - 1))) {
          if (!(b_camera_params.UndistortMap.SizeOfImage[loop_ub] ==
                outputImageSize[loop_ub])) {
            p = false;
          }
          if (!p) {
            exitg1 = true;
          } else {
            loop_ub++;
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
      loop_ub = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (loop_ub < 5) {
          if (cv1[loop_ub] != b[loop_ub]) {
            exitg2 = 1;
          } else {
            loop_ub++;
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
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= (b.size(1) - 1))) {
          if (!(b[loop_ub] == x2[loop_ub])) {
            p = false;
          }
          if (!p) {
            exitg1 = true;
          } else {
            loop_ub++;
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
      outputImageSize[0] = b_camera_params.RadialDistortion[0];
      outputImageSize[1] = b_camera_params.RadialDistortion[1];
      outputImageSize[2] = b_camera_params.RadialDistortion[2];
      c_camera_params[0] = b_camera_params.TangentialDistortion[0];
      c_camera_params[1] = b_camera_params.TangentialDistortion[1];
      b_camera_params.UndistortMap.update(b_I, intrinsicMatrix, outputImageSize,
                                          c_camera_params, dv, dv1);
    }
    b_this = &b_camera_params.UndistortMap;
    Y_T.set_size(b_this->XmapSingle.size(0), b_this->XmapSingle.size(1));
    loop_ub = b_this->XmapSingle.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_this->XmapSingle.size(0);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        Y_T[i2 + (Y_T.size(0) * i1)] =
            b_this->XmapSingle[i2 + (b_this->XmapSingle.size(0) * i1)];
      }
    }
    if (fillValues.size(2) == 1) {
      unsigned int sizeVec_idx_0;
      sizeVec_idx_0 = static_cast<unsigned int>(b_images.size(2));
      fill.set_size(static_cast<int>(static_cast<signed char>(sizeVec_idx_0)),
                    1, 1);
      if ((static_cast<signed char>(b_images.size(2))) != 0) {
        i1 = (static_cast<int>(static_cast<signed char>(sizeVec_idx_0))) - 1;
        for (loop_ub = 0; loop_ub <= i1; loop_ub++) {
          fill[loop_ub] = 0U;
        }
      }
    } else {
      fill.set_size(1, 1, fillValues.size(2));
      loop_ub = fillValues.size(2);
      for (i1 = 0; i1 < loop_ub; i1++) {
        fill[(fill.size(0) * fill.size(1)) * i1] = 0U;
      }
    }
    J.set_size(Y_T.size(0), Y_T.size(1), b_images.size(2));
    inputImageSize[0] =
        static_cast<double>(static_cast<unsigned int>(b_images.size(0)));
    inputImageSize[1] =
        static_cast<double>(static_cast<unsigned int>(b_images.size(1)));
    inputImageSize[2] =
        static_cast<double>(static_cast<unsigned int>(b_images.size(2)));
    outputImageSize[0] = static_cast<double>(Y_T.size(0));
    outputImageSize[1] = static_cast<double>(Y_T.size(1));
    outputImageSize[2] = static_cast<double>(J.size(2));
    imterp2d32f_uint8(&b_I[0], &inputImageSize[0], &b_this->YmapSingle[0],
                      &Y_T[0], &outputImageSize[0], 2.0,
                      (fill.size(0) * fill.size(2)) == 1, &fill[0], &J[0]);
    b_I.set_size(b_images.size(0), b_images.size(1), b_images.size(2));
    if (1 > b_images.size(0)) {
      loop_ub = -1;
    } else {
      loop_ub = b_images.size(0) - 1;
    }
    if (1 > b_images.size(1)) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = b_images.size(1) - 1;
    }
    if (1 > b_images.size(2)) {
      c_loop_ub = -1;
    } else {
      c_loop_ub = b_images.size(2) - 1;
    }
    for (i1 = 0; i1 <= c_loop_ub; i1++) {
      for (i2 = 0; i2 <= b_loop_ub; i2++) {
        for (i3 = 0; i3 <= loop_ub; i3++) {
          b_I[(i3 + (b_I.size(0) * i2)) + ((b_I.size(0) * b_I.size(1)) * i1)] =
              J[(i3 + (J.size(0) * i2)) + ((J.size(0) * J.size(1)) * i1)];
        }
      }
    }
    loop_ub = b_I.size(2);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = b_I.size(1);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        c_loop_ub = b_I.size(0);
        for (i3 = 0; i3 < c_loop_ub; i3++) {
          b_images[((i3 + (b_images.size(0) * i2)) +
                    ((b_images.size(0) * b_images.size(1)) * i1)) +
                   (((b_images.size(0) * b_images.size(1)) * b_images.size(2)) *
                    b_i)] = b_I[(i3 + (b_I.size(0) * i2)) +
                                ((b_I.size(0) * b_I.size(1)) * i1)];
        }
      }
    }
  }
}

//
// File trailer for undistort.cpp
//
// [EOF]
//
