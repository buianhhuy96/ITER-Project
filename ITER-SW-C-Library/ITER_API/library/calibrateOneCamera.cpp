//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "calibrateOneCamera.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_types.h"
#include "anonymous_function1.h"
#include "cameraParameters.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "isequal.h"
#include "lsqnonlin.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "worldToImage.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <string.h>

// Function Declarations
static void unpackSerializedParams(
    const h_struct_T *cameraParams, coder::array<double, 1U> &b_x,
    coder::array<double, 2U> &outputParams_RadialDistortion,
    double outputParams_TangentialDistortion[2],
    double outputParams_ImageSize[2], char outputParams_WorldUnits[2],
    bool *outputParams_EstimateSkew,
    double *outputParams_NumRadialDistortionCoefficients,
    bool *outputParams_EstimateTangentialDistortion,
    coder::array<double, 2U> &outputParams_RotationVectors,
    coder::array<double, 2U> &outputParams_TranslationVectors,
    double outputParams_IntrinsicMatrix[3][3]);

// Function Definitions
//
// {
//     if cameraParams.EstimateSkew
//         skew = x(5);
//         numIntrinsicMatrixEntries = 5;
//     else
// }
//
// Arguments    : const h_struct_T *cameraParams
//                coder::array<double, 1U> &b_x
//                coder::array<double, 2U> &outputParams_RadialDistortion
//                double outputParams_TangentialDistortion[2]
//                double outputParams_ImageSize[2]
//                char outputParams_WorldUnits[2]
//                bool *outputParams_EstimateSkew
//                double *outputParams_NumRadialDistortionCoefficients
//                bool *outputParams_EstimateTangentialDistortion
//                coder::array<double, 2U> &outputParams_RotationVectors
//                coder::array<double, 2U> &outputParams_TranslationVectors
//                double outputParams_IntrinsicMatrix[3][3]
// Return Type  : void
//
static void unpackSerializedParams(
    const h_struct_T *cameraParams, coder::array<double, 1U> &b_x,
    coder::array<double, 2U> &outputParams_RadialDistortion,
    double outputParams_TangentialDistortion[2],
    double outputParams_ImageSize[2], char outputParams_WorldUnits[2],
    bool *outputParams_EstimateSkew,
    double *outputParams_NumRadialDistortionCoefficients,
    bool *outputParams_EstimateTangentialDistortion,
    coder::array<double, 2U> &outputParams_RotationVectors,
    coder::array<double, 2U> &outputParams_TranslationVectors,
    double outputParams_IntrinsicMatrix[3][3])
{
  double b_cy;
  double cx;
  double fx;
  double fy;
  int b_i;
  int b_i8;
  int b_loop_ub;
  int b_loop_ub_tmp;
  int i1;
  int i10;
  int i4;
  int i5;
  int loop_ub;
  int loop_ub_tmp;
  // end
  fx = b_x[0];
  fy = b_x[1];
  cx = b_x[2];
  b_cy = b_x[3];
  if (5 > b_x.size(0)) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = 4;
    i1 = b_x.size(0);
  }
  loop_ub_tmp = i1 - b_i;
  for (int i2{0}; i2 < loop_ub_tmp; i2++) {
    b_x[i2] = b_x[b_i + i2];
  }
  b_x.set_size(loop_ub_tmp);
  if (1.0 > cameraParams->NumRadialDistortionCoefficients) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(cameraParams->NumRadialDistortionCoefficients);
  }
  outputParams_RadialDistortion.set_size(1, loop_ub);
  b_loop_ub = loop_ub;
  if ((static_cast<int>(loop_ub < 4)) != 0) {
    for (int i3{0}; i3 < loop_ub; i3++) {
      outputParams_RadialDistortion[i3] = b_x[i3];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i3 = 0; i3 < b_loop_ub; i3++) {
      outputParams_RadialDistortion[i3] = b_x[i3];
    }
  }
  //     %{
  //     if cameraParams.EstimateTangentialDistortion
  //         tangentialDistortion = ...
  //             x(numRadialCoeffs+1:numRadialCoeffs+2)';
  //         numDistortionCoeffs = numRadialCoeffs + 2;
  //     else
  //     %}
  //  end
  if ((cameraParams->NumRadialDistortionCoefficients + 1.0) >
      (static_cast<double>(b_x.size(0)))) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = (static_cast<int>(static_cast<double>(
             cameraParams->NumRadialDistortionCoefficients + 1.0))) -
         1;
    i5 = b_x.size(0);
  }
  b_loop_ub_tmp = i5 - i4;
  for (int i6{0}; i6 < b_loop_ub_tmp; i6++) {
    b_x[i6] = b_x[i4 + i6];
  }
  b_x.set_size(b_loop_ub_tmp);
  if (b_loop_ub_tmp == 0) {
    outputParams_RotationVectors.set_size(0, 0);
    outputParams_TranslationVectors.set_size(0, 0);
  } else {
    int c_loop_ub;
    int d_loop_ub;
    int sz_idx_1;
    sz_idx_1 = b_loop_ub_tmp / 6;
    outputParams_RotationVectors.set_size(sz_idx_1, 3);
    c_loop_ub = sz_idx_1;
    if ((static_cast<int>((3 * sz_idx_1) < 4)) != 0) {
      for (int i7{0}; i7 < 3; i7++) {
        for (b_i8 = 0; b_i8 < sz_idx_1; b_i8++) {
          outputParams_RotationVectors[b_i8 +
                                       (outputParams_RotationVectors.size(0) *
                                        i7)] = b_x[i7 + (6 * b_i8)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

      for (int i7 = 0; i7 < 3; i7++) {
        for (b_i8 = 0; b_i8 < c_loop_ub; b_i8++) {
          outputParams_RotationVectors[b_i8 +
                                       (outputParams_RotationVectors.size(0) *
                                        i7)] = b_x[i7 + (6 * b_i8)];
        }
      }
    }
    outputParams_TranslationVectors.set_size(sz_idx_1, 3);
    d_loop_ub = sz_idx_1;
    if ((static_cast<int>((3 * sz_idx_1) < 4)) != 0) {
      for (int i9{0}; i9 < 3; i9++) {
        for (i10 = 0; i10 < sz_idx_1; i10++) {
          outputParams_TranslationVectors
              [i10 + (outputParams_TranslationVectors.size(0) * i9)] =
                  b_x[(i9 + (6 * i10)) + 3];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i10)

      for (int i9 = 0; i9 < 3; i9++) {
        for (i10 = 0; i10 < d_loop_ub; i10++) {
          outputParams_TranslationVectors
              [i10 + (outputParams_TranslationVectors.size(0) * i9)] =
                  b_x[(i9 + (6 * i10)) + 3];
        }
      }
    }
  }
  outputParams_TangentialDistortion[0] = 0.0;
  outputParams_ImageSize[0] = cameraParams->ImageSize[0];
  outputParams_WorldUnits[0] = 'm';
  outputParams_TangentialDistortion[1] = 0.0;
  outputParams_ImageSize[1] = cameraParams->ImageSize[1];
  outputParams_WorldUnits[1] = 'm';
  outputParams_IntrinsicMatrix[0][0] = fx;
  outputParams_IntrinsicMatrix[0][1] = 0.0;
  outputParams_IntrinsicMatrix[0][2] = cx;
  outputParams_IntrinsicMatrix[1][0] = 0.0;
  outputParams_IntrinsicMatrix[1][1] = fy;
  outputParams_IntrinsicMatrix[1][2] = b_cy;
  outputParams_IntrinsicMatrix[2][0] = 0.0;
  outputParams_IntrinsicMatrix[2][1] = 0.0;
  outputParams_IntrinsicMatrix[2][2] = 1.0;
  *outputParams_EstimateSkew = cameraParams->EstimateSkew;
  *outputParams_NumRadialDistortionCoefficients =
      cameraParams->NumRadialDistortionCoefficients;
  *outputParams_EstimateTangentialDistortion =
      cameraParams->EstimateTangentialDistortion;
}

//
// Retrieve useful information
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                double squareSize
//                const int boardSize[2]
//                struct0_T *cameraParams
//                coder::array<double, 1U> &errorOptimized
//                double *MREf
//                coder::array<bool, 1U> &validIdx
//                int *err
// Return Type  : void
//
void calibrateOneCamera(const coder::array<unsigned char, 4U> &images,
                        double squareSize, const int boardSize[2],
                        struct0_T *cameraParams,
                        coder::array<double, 1U> &errorOptimized, double *MREf,
                        coder::array<bool, 1U> &validIdx, int *err)
{
  coder::b_anonymous_function b_this;
  coder::b_cameraParameters b_cameraParams;
  coder::cameraParameters lobj_0;
  coder::array<cell_wrap_19, 2U> board_points;
  coder::array<double, 2U> c_worldPoints;
  coder::array<double, 2U> current_board_points;
  coder::array<double, 2U> jacobian;
  coder::array<double, 2U> rt;
  coder::array<double, 1U> f_expl_temp;
  coder::array<double, 1U> g_expl_temp;
  coder::array<double, 1U> initialParamsSerial;
  coder::array<double, 1U> r;
  coder::array<double, 1U> r1;
  coder::array<double, 1U> residual;
  coder::array<double, 1U> tmp;
  coder::array<unsigned char, 2U> b_images;
  coder::array<bool, 1U> a__1;
  coder::array<bool, 1U> b_x;
  double t9_RadialDistortion[3];
  double b_image_size[2];
  double board_size_detected[2];
  double board_size_valid[2];
  double dv[2];
  double a__2;
  double a__3;
  double b_MREf;
  double b_expl_temp;
  double c_expl_temp;
  double d_expl_temp;
  double expl_temp;
  double t9_NumRadialDistortionCoefficients;
  int b_err;
  int b_i;
  int c_err;
  int d_err;
  int i14;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  char e_expl_temp[19];
  bool exitg1;
  bool t9_EstimateSkew;
  bool t9_EstimateTangentialDistortion;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  //  Multiple Camera Calibration Toolbox - V1
  //  Laura Ribeiro, Tampere University, Finland
  //  (laura.goncalvesribeiro@tuni.fi)
  //  Step 1
  //  Calibrates each camera independently using Matlab Camera Calibrator
  //  Application Calculates extrinsic parameters between camera N and camera 1
  //  Inputs: directory of calibration images, squareSize, boardSize
  //  Follow the naming convetion for calibration images: PositionXXX_CameraXX
  //  Step 2
  //  Overall Optimization
  //  Options:
  //  Re-estimate all: [1, 1, 1 ,1];
  //  Fixed Intrinsics: [1, 1, 0 ,0];
  //  Fixed lens distortions: [0, 1, 0 ,0];
  //  Default: Fixed intrinsics.
  // {
  //  ITER API ALGORITHM IMPLEMENTATION STARTS HERE
  //  Calibrate One Camera
  // function [CameraParameters,errorOptimized, calculation_err, err] =
  // calibrateOneCamera(images, squareSize, boardSize)
  //
  //  Generate world coordinates of the checkerboard keypoints
  // worldPoints = generateCheckerboardPoints(boardSize, squareSize);
  //
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  // [ImagePoints, boardSizeDetected , checkFound] =
  // detectCheckerboardPoints(imageFileNames(:)); % detect checkerboard for
  // every position of camera i
  //
  // disp(boardSize == boardSizeDetected);
  //
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  // cameraModel.EstimateSkew = false;
  // cameraModel.EstimateTangentialDistortion = false;
  // cameraModel.NumRadialDistortionCoefficients =3;
  //
  // [initialParams, imagesUsed] = computeInitialParameterEstimate(...
  //     worldPoints, ImagePoints, [], cameraModel, 'millimeters', [], []);
  //
  //  Convert Extrinsics to my way
  // clear RTc1pn
  // tempR= initialParams.RotationMatrices(:,:,imagesUsed);
  // tempt= initialParams.TranslationVectors(imagesUsed,:);
  // for i=1:size(tempR,3)
  //     RTc1pn{i} = RTtoTransform(tempR(:,:,i),tempt(i,:));
  // end
  //  Crete Calibration Struct
  // calibration.CameraParameters = initialParams;
  // calibration.PatternPositions = RTc1pn;
  // calibration.ImagePoints = ImagePoints;
  //  Minimization options
  //  Default options give better outcome
  //  minimization_options=optimset('LargeScale','on',...
  //      'Algorithm','levenberg-marquardt',...
  //      'TolFun',1e-10,...
  //      'Display','on',...
  //      'TolX',1e-10,...
  //      'MaxFunEvals',200000,...
  //      'MaxIter',10000,...
  //      'UseParallel', false);
  //
  //  Optimization options: fixedK, fixedDistortions, fixedRTpnc1
  // options = [0,0,0];
  // World and Image Points
  // genPoints = [worldPoints, ones(size(worldPoints,1),1)];
  // detPoints = calibration.ImagePoints;
  //  Convert initial estimate
  // serialCalib = serializeCalib(calibration, options);
  //
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration); errorInitial = CalculateCost(serialCalib, options,
  // calibration, genPoints, detPoints); tmp = errorInitial;
  // tmp(tmp<0.000001)=NaN; MREi = mean(tmp(~isnan(tmp(:)))); disp (['Mean
  // Reprojection Error - Before Optimization: ', num2str(MREi)]);
  //  Optimization
  // h = waitbar(0, 'Running global Optimization...','Name', 'Global
  // Optimization');
  //
  // [optimizedSerialCalib,~,residual,~,~,~,jacobian] = lsqnonlin(@(x)
  // CalculateCost(x, options, calibration, genPoints, detPoints),serialCalib,
  // [],[]);
  //
  // delete(h);
  //
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  // CI(:,1) = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI(:,2) = unserializeCalib(serialCI(:,2)', options, calibration);
  //
  // errorOptimized = CalculateCost(optimizedSerialCalib, options, calibration,
  // genPoints, detPoints); tmp = errorOptimized; tmp(tmp<0.000001)=NaN; MREf =
  // nanmean(tmp(:)); disp (['Mean Reprojection Error - After Optimization: ',
  // num2str(MREf)]);
  //
  // [calibrationOptimized] = unserializeCalib(optimizedSerialCalib, options,
  // calibration);
  //
  // calibrationOptimized.OptimizationOptions = options;
  // calibrationOptimized.Jacobian = jacobian;
  // calibrationOptimized.Error = errorOptimized;
  // calibrationOptimized.CI = CI;
  //
  // end
  // }
  b_image_size[0] =
      static_cast<double>(static_cast<unsigned int>(images.size(0)));
  b_image_size[1] =
      static_cast<double>(static_cast<unsigned int>(images.size(1)));
  //  Initalize error flag
  lobj_0.init(b_image_size)
      ->toStruct(t9_RadialDistortion, cameraParams->TangentialDistortion,
                 cameraParams->ImageSize, cameraParams->WorldUnits,
                 &t9_EstimateSkew, &t9_NumRadialDistortionCoefficients,
                 &t9_EstimateTangentialDistortion,
                 cameraParams->IntrinsicMatrix);
  cameraParams->RadialDistortion.set_size(1, 3);
  cameraParams->RadialDistortion[0] = t9_RadialDistortion[0];
  cameraParams->RadialDistortion[1] = t9_RadialDistortion[1];
  cameraParams->RadialDistortion[2] = t9_RadialDistortion[2];
  cameraParams->EstimateSkew = t9_EstimateSkew;
  cameraParams->NumRadialDistortionCoefficients =
      t9_NumRadialDistortionCoefficients;
  cameraParams->EstimateTangentialDistortion = t9_EstimateTangentialDistortion;
  cameraParams->RotationVectors.set_size(0, 3);
  cameraParams->TranslationVectors.set_size(0, 3);
  errorOptimized.set_size(0);
  b_MREf = rtInf;
  //  Initialize error flags
  b_err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size_idx_0 = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size_idx_1 = 0;
  validIdx.set_size(images.size(3));
  //  perform checkerboards detection in each image
  b_i = images.size(3);
  board_points.set_size(1, images.size(3));
  for (int c_i{0}; c_i < b_i; c_i++) {
    int b_loop_ub;
    int d_loop_ub;
    int loop_ub;
    loop_ub = images.size(0);
    b_loop_ub = images.size(1);
    b_images.set_size(images.size(0), images.size(1));
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_images[i2 + (b_images.size(0) * i1)] =
            images[(i2 + (images.size(0) * i1)) +
                   ((images.size(0) * images.size(1)) * c_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, current_board_points,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    dv[0] = 0.0;
    dv[1] = 0.0;
    if (coder::isequal(board_size_detected, dv)) {
      validIdx[c_i] = false;
    } else {
      int b_k;
      bool p;
      p = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 2)) {
        if (!(board_size_detected[b_k] ==
              (static_cast<double>(boardSize[b_k])))) {
          p = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      if (!p) {
        validIdx[c_i] = false;
      } else {
        dv[0] = 0.0;
        dv[1] = 0.0;
        if (coder::isequal(board_size_valid, dv)) {
          board_size_valid[0] = board_size_detected[0];
          image_point_valid_size_idx_0 = current_board_points.size(0);
          board_size_valid[1] = board_size_detected[1];
          image_point_valid_size_idx_1 = current_board_points.size(1);
        } else if (!coder::isequal(board_size_valid, board_size_detected)) {
          b_err = -102;
        } else {
          /* no actions */
        }
        validIdx[c_i] = true;
      }
    }
    d_loop_ub = current_board_points.size(1);
    board_points[board_points.size(0) * c_i].f1.set_size(
        current_board_points.size(0), current_board_points.size(1));
    for (int i5{0}; i5 < d_loop_ub; i5++) {
      int e_loop_ub;
      e_loop_ub = current_board_points.size(0);
      for (int i6{0}; i6 < e_loop_ub; i6++) {
        board_points[c_i].f1[i6 + (board_points[c_i].f1.size(0) * i5)] =
            current_board_points[i6 + (current_board_points.size(0) * i5)];
      }
    }
  }
  if (b_err != 0) {
    // err = "Checkerboards detected has different size from given boardSize";
    b_this.workspace.image_points.set_size(0, 0, 1);
    b_this.workspace.b_world_points.set_size(0, 0);
  } else {
    int k;
    bool varargout_1;
    varargout_1 = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (validIdx.size(0) - 1))) {
      if (validIdx[k]) {
        varargout_1 = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!varargout_1) {
      // err = "No detect of checkerboard in all images";
      b_err = -101;
      b_this.workspace.image_points.set_size(0, 0, 1);
      b_this.workspace.b_world_points.set_size(0, 0);
    } else {
      int b_y;
      int board_size_valid_idx_0;
      int c_loop_ub;
      unsigned int d_k;
      int i15;
      int i9;
      int i_loop_ub;
      unsigned int j;
      int j_loop_ub;
      int vlen;
      //  Extract valid image points into matrix
      b_x.set_size(validIdx.size(0));
      c_loop_ub = validIdx.size(0);
      if ((static_cast<int>(validIdx.size(0) < 4)) != 0) {
        for (int i3{0}; i3 < c_loop_ub; i3++) {
          b_x[i3] = validIdx[i3];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i3 = 0; i3 < c_loop_ub; i3++) {
          b_x[i3] = validIdx[i3];
        }
      }
      vlen = b_x.size(0);
      if (b_x.size(0) == 0) {
        b_y = 0;
      } else {
        int y;
        y = static_cast<int>(b_x[0]);
        for (int c_k{2}; c_k <= vlen; c_k++) {
          int c_y;
          c_y = y;
          if (vlen >= 2) {
            c_y = y + (static_cast<int>(b_x[c_k - 1]));
          }
          y = c_y;
        }
        b_y = y;
      }
      b_this.workspace.image_points.set_size(image_point_valid_size_idx_0,
                                             image_point_valid_size_idx_1, b_y);
      for (int i7{0}; i7 < b_y; i7++) {
        for (int b_i8{0}; b_i8 < image_point_valid_size_idx_1; b_i8++) {
          for (int i10{0}; i10 < image_point_valid_size_idx_0; i10++) {
            b_this.workspace
                .image_points[(i10 +
                               (b_this.workspace.image_points.size(0) * b_i8)) +
                              ((b_this.workspace.image_points.size(0) *
                                b_this.workspace.image_points.size(1)) *
                               i7)] = 0.0;
          }
        }
      }
      j = 1U;
      i9 = images.size(3);
      for (int d_i{0}; d_i < i9; d_i++) {
        if (validIdx[d_i]) {
          int g_loop_ub;
          g_loop_ub = board_points[d_i].f1.size(1);
          for (int i11{0}; i11 < g_loop_ub; i11++) {
            int h_loop_ub;
            h_loop_ub = board_points[d_i].f1.size(0);
            for (int i12{0}; i12 < h_loop_ub; i12++) {
              b_this.workspace
                  .image_points[(i12 + (b_this.workspace.image_points.size(0) *
                                        i11)) +
                                ((b_this.workspace.image_points.size(0) *
                                  b_this.workspace.image_points.size(1)) *
                                 ((static_cast<int>(j)) - 1))] =
                  board_points[d_i]
                      .f1[i12 + (board_points[d_i].f1.size(0) * i11)];
            }
          }
          j++;
        }
      }
      //  Generate world coordinates of the corners of the squares in meters
      board_size_valid[0]--;
      board_size_valid[1]--;
      board_size_valid_idx_0 = static_cast<int>(
          static_cast<double>(board_size_valid[0] * board_size_valid[1]));
      c_worldPoints.set_size(board_size_valid_idx_0, 2);
      i_loop_ub = board_size_valid_idx_0;
      if ((static_cast<int>((board_size_valid_idx_0 * 2) < 4)) != 0) {
        for (int i13{0}; i13 < 2; i13++) {
          for (i14 = 0; i14 < board_size_valid_idx_0; i14++) {
            c_worldPoints[i14 + (c_worldPoints.size(0) * i13)] = 0.0;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i14)

        for (int i13 = 0; i13 < 2; i13++) {
          for (i14 = 0; i14 < i_loop_ub; i14++) {
            c_worldPoints[i14 + (c_worldPoints.size(0) * i13)] = 0.0;
          }
        }
      }
      d_k = 1U;
      i15 = static_cast<int>(
          static_cast<double>((board_size_valid[1] - 1.0) + 1.0));
      for (int b_j{0}; b_j < i15; b_j++) {
        int i16;
        i16 = static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0));
        for (int e_i{0}; e_i < i16; e_i++) {
          int worldPoints_tmp;
          worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                d_k + (static_cast<unsigned int>(e_i))))) -
                            1;
          c_worldPoints[worldPoints_tmp] =
              (static_cast<double>(b_j)) * squareSize;
          c_worldPoints[worldPoints_tmp + c_worldPoints.size(0)] =
              (static_cast<double>(e_i)) * squareSize;
        }
        d_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0)));
      }
      b_this.workspace.b_world_points.set_size(c_worldPoints.size(0), 2);
      j_loop_ub = c_worldPoints.size(0);
      for (int i17{0}; i17 < 2; i17++) {
        for (int i19{0}; i19 < j_loop_ub; i19++) {
          b_this.workspace
              .b_world_points[i19 +
                              (b_this.workspace.b_world_points.size(0) * i17)] =
              c_worldPoints[i19 + (c_worldPoints.size(0) * i17)];
        }
      }
    }
  }
  c_err = b_err;
  if (b_err == 0) {
    //  Inital Parameter Estimate
    // If want different values of EstimateSkew, EstimateTangentialDistortion,
    // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
    computeInitialParameterEstimate(
        b_this.workspace.b_world_points, b_this.workspace.image_points,
        b_image_size, &b_this.workspace.initialParams, a__1, &d_err);
    c_err = d_err;
    if (d_err == 0) {
      int b_rt;
      int end;
      int f_loop_ub;
      int o_loop_ub;
      int p_loop_ub;
      int q_loop_ub;
      int r_loop_ub;
      int result;
      int unnamed_idx_0;
      signed char b_input_sizes_idx_1;
      signed char input_sizes_idx_1;
      bool empty_non_axis_sizes;
      //
      for (int i4{0}; i4 < 3; i4++) {
        b_cameraParams.IntrinsicMatrixInternal[i4][0] =
            b_this.workspace.initialParams.IntrinsicMatrix[0][i4];
        b_cameraParams.IntrinsicMatrixInternal[i4][1] =
            b_this.workspace.initialParams.IntrinsicMatrix[1][i4];
        b_cameraParams.IntrinsicMatrixInternal[i4][2] =
            b_this.workspace.initialParams.IntrinsicMatrix[2][i4];
      }
      //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
      //     %{
      //     if cameraParams.EstimateSkew
      //         x = [x; cameraParams.Skew];
      //     end
      //     %}
      if (1.0 >
          b_this.workspace.initialParams.NumRadialDistortionCoefficients) {
        f_loop_ub = 4;
      } else {
        f_loop_ub = (static_cast<int>(b_this.workspace.initialParams
                                          .NumRadialDistortionCoefficients)) +
                    4;
      }
      //     %{
      //     if cameraParams.EstimateTangentialDistortion
      //         x = [x; cameraParams.TangentialDistortion'];
      //     end
      //     %}
      if (b_this.workspace.initialParams.RotationVectors.size(0) != 0) {
        result = b_this.workspace.initialParams.RotationVectors.size(0);
      } else if (b_this.workspace.initialParams.TranslationVectors.size(0) !=
                 0) {
        result = b_this.workspace.initialParams.TranslationVectors.size(0);
      } else {
        result = b_this.workspace.initialParams.RotationVectors.size(0);
        if (b_this.workspace.initialParams.TranslationVectors.size(0) >
            b_this.workspace.initialParams.RotationVectors.size(0)) {
          result = b_this.workspace.initialParams.TranslationVectors.size(0);
        }
      }
      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes) {
        input_sizes_idx_1 = 3;
      } else if (b_this.workspace.initialParams.RotationVectors.size(0) != 0) {
        input_sizes_idx_1 = 3;
      } else {
        input_sizes_idx_1 = 0;
      }
      if (empty_non_axis_sizes) {
        b_input_sizes_idx_1 = 3;
      } else if (b_this.workspace.initialParams.TranslationVectors.size(0) !=
                 0) {
        b_input_sizes_idx_1 = 3;
      } else {
        b_input_sizes_idx_1 = 0;
      }
      rt.set_size((static_cast<int>(input_sizes_idx_1)) +
                      (static_cast<int>(b_input_sizes_idx_1)),
                  result);
      for (int i18{0}; i18 < result; i18++) {
        int k_loop_ub;
        k_loop_ub = static_cast<int>(input_sizes_idx_1);
        for (int i21{0}; i21 < k_loop_ub; i21++) {
          rt[i21 + (rt.size(0) * i18)] =
              b_this.workspace.initialParams
                  .RotationVectors[i18 + (result * i21)];
        }
      }
      for (int i20{0}; i20 < result; i20++) {
        int m_loop_ub;
        m_loop_ub = static_cast<int>(b_input_sizes_idx_1);
        for (int i22{0}; i22 < m_loop_ub; i22++) {
          rt[(i22 + (static_cast<int>(input_sizes_idx_1))) +
             (rt.size(0) * i20)] =
              b_this.workspace.initialParams
                  .TranslationVectors[i20 + (result * i22)];
        }
      }
      b_rt = rt.size(0) * rt.size(1);
      initialParamsSerial.set_size(f_loop_ub + b_rt);
      initialParamsSerial[0] = b_cameraParams.IntrinsicMatrixInternal[0][0];
      initialParamsSerial[1] = b_cameraParams.IntrinsicMatrixInternal[1][1];
      initialParamsSerial[2] = b_cameraParams.IntrinsicMatrixInternal[2][0];
      initialParamsSerial[3] = b_cameraParams.IntrinsicMatrixInternal[2][1];
      for (int i23{0}; i23 <= (f_loop_ub - 5); i23++) {
        initialParamsSerial[i23 + 4] =
            b_this.workspace.initialParams.RadialDistortion[i23];
      }
      o_loop_ub = b_rt;
      if ((static_cast<int>(b_rt < 4)) != 0) {
        for (int i24{0}; i24 < b_rt; i24++) {
          initialParamsSerial[i24 + f_loop_ub] = rt[i24];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i24 = 0; i24 < o_loop_ub; i24++) {
          initialParamsSerial[i24 + f_loop_ub] = rt[i24];
        }
      }
      //  r1, t1, r2, t2, ...
      // unpackedCameraParams = unpackSerializedParams(initialParams,
      // initialParamsSerial, 0);
      //  Calculate mre - before optimization
      // [errorInitial] = reprojectWrapper(initialParamsSerial, initialParams,
      // 0, worldPoints, ImagePoints); tmp = errorInitial;
      // tmp(tmp<0.000001)=NaN; MREi = nanmean(tmp(:)); disp (['Mean
      // Reprojection Error - Before Optimization: ', num2str(MREi)]); Optimize
      //  Optimization
      unnamed_idx_0 = initialParamsSerial.size(0);
      r.set_size(initialParamsSerial.size(0));
      p_loop_ub = initialParamsSerial.size(0);
      if ((static_cast<int>(initialParamsSerial.size(0) < 4)) != 0) {
        for (int i25{0}; i25 < p_loop_ub; i25++) {
          r[i25] = -1.7976931348623157E+308;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i25 = 0; i25 < p_loop_ub; i25++) {
          r[i25] = -1.7976931348623157E+308;
        }
      }
      r1.set_size(unnamed_idx_0);
      q_loop_ub = unnamed_idx_0;
      if ((static_cast<int>(unnamed_idx_0 < 4)) != 0) {
        for (int i26{0}; i26 < unnamed_idx_0; i26++) {
          r1[i26] = 1.7976931348623157E+308;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i26 = 0; i26 < q_loop_ub; i26++) {
          r1[i26] = 1.7976931348623157E+308;
        }
      }
      coder::lsqnonlin(&b_this, initialParamsSerial, r, r1, &a__2, residual,
                       &a__3, &expl_temp, &b_expl_temp, &c_expl_temp,
                       &d_expl_temp, e_expl_temp, f_expl_temp, g_expl_temp,
                       jacobian);
      //  Calculate mre - after optimization
      reprojectWrapper(initialParamsSerial, &b_this.workspace.initialParams,
                       b_this.workspace.b_world_points,
                       b_this.workspace.image_points, errorOptimized);
      tmp.set_size(errorOptimized.size(0));
      r_loop_ub = errorOptimized.size(0);
      if ((static_cast<int>(errorOptimized.size(0) < 4)) != 0) {
        for (int i27{0}; i27 < r_loop_ub; i27++) {
          tmp[i27] = errorOptimized[i27];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i27 = 0; i27 < r_loop_ub; i27++) {
          tmp[i27] = errorOptimized[i27];
        }
      }
      end = errorOptimized.size(0);
      if ((static_cast<int>(errorOptimized.size(0) < 4)) != 0) {
        for (int g_i{0}; g_i < end; g_i++) {
          if (errorOptimized[g_i] < 1.0E-6) {
            tmp[g_i] = rtNaN;
          }
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int g_i = 0; g_i < end; g_i++) {
          if (errorOptimized[g_i] < 1.0E-6) {
            tmp[g_i] = rtNaN;
          }
        }
      }
      if (tmp.size(0) == 0) {
        b_MREf = rtNaN;
      } else {
        int b_vlen;
        int c;
        b_vlen = tmp.size(0);
        b_MREf = 0.0;
        c = 0;
        for (int e_k{0}; e_k < b_vlen; e_k++) {
          if (!std::isnan(tmp[e_k])) {
            b_MREf += tmp[e_k];
            c++;
          }
        }
        if (c == 0) {
          b_MREf = rtNaN;
        } else {
          b_MREf /= static_cast<double>(c);
        }
      }
      // disp (['Mean Reprojection Error - After Optimization: ',
      // num2str(MREf)]);
      unpackSerializedParams(
          &b_this.workspace.initialParams, initialParamsSerial,
          cameraParams->RadialDistortion, cameraParams->TangentialDistortion,
          cameraParams->ImageSize, cameraParams->WorldUnits,
          &cameraParams->EstimateSkew,
          &cameraParams->NumRadialDistortionCoefficients,
          &cameraParams->EstimateTangentialDistortion,
          cameraParams->RotationVectors, cameraParams->TranslationVectors,
          cameraParams->IntrinsicMatrix);
    }
  }
  *MREf = b_MREf;
  *err = c_err;
}

//
// Arguments    : const coder::array<double, 1U> &paramsVector
//                const h_struct_T *cameraParams
//                const coder::array<double, 2U> &c_worldPoints
//                const coder::array<double, 3U> &e_ImagePoints
//                coder::array<double, 1U> &cost
// Return Type  : void
//
void reprojectWrapper(const coder::array<double, 1U> &paramsVector,
                      const h_struct_T *cameraParams,
                      const coder::array<double, 2U> &c_worldPoints,
                      const coder::array<double, 3U> &e_ImagePoints,
                      coder::array<double, 1U> &cost)
{
  coder::c_cameraParameters paramStruct;
  coder::array<double, 3U> r;
  coder::array<double, 2U> b_paramStruct;
  coder::array<double, 2U> b_v;
  coder::array<double, 2U> c_u;
  coder::array<double, 2U> d_u;
  coder::array<double, 2U> projectedPoints;
  coder::array<double, 2U> r1;
  coder::array<double, 2U> r3;
  coder::array<double, 2U> x1;
  coder::array<double, 1U> b_error;
  coder::array<double, 1U> b_paramsVector;
  coder::array<int, 2U> r2;
  double c_R[3][3];
  double d_a[3][3];
  double dv[3][3];
  double varargin_1_IntrinsicMatrix[3][3];
  double varargin_1_NumRadialDistortionCoefficients;
  int b_i8;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i10;
  int i3;
  int i4;
  int i5;
  int i9;
  int k;
  int loop_ub;
  int paramStruct_idx_0;
  int unnamed_idx_2;
  int ysize_idx_0;
  int ysize_idx_1;
  signed char c_a[3][3];
  bool varargin_1_EstimateSkew;
  bool varargin_1_EstimateTangentialDistortion;
  b_paramsVector.set_size(paramsVector.size(0));
  loop_ub = paramsVector.size(0) - 1;
  for (int b_i{0}; b_i <= loop_ub; b_i++) {
    b_paramsVector[b_i] = paramsVector[b_i];
  }
  unpackSerializedParams(
      cameraParams, b_paramsVector, paramStruct.RadialDistortion,
      paramStruct.TangentialDistortion, paramStruct.ImageSize,
      paramStruct.WorldUnits, &varargin_1_EstimateSkew,
      &varargin_1_NumRadialDistortionCoefficients,
      &varargin_1_EstimateTangentialDistortion, paramStruct.RotationVectors,
      paramStruct.TranslationVectors, varargin_1_IntrinsicMatrix);
  for (int i1{0}; i1 < 3; i1++) {
    paramStruct.IntrinsicMatrixInternal[i1][0] =
        varargin_1_IntrinsicMatrix[0][i1];
    paramStruct.IntrinsicMatrixInternal[i1][1] =
        varargin_1_IntrinsicMatrix[1][i1];
    paramStruct.IntrinsicMatrixInternal[i1][2] =
        varargin_1_IntrinsicMatrix[2][i1];
  }
  paramStruct.EstimateSkew = varargin_1_EstimateSkew;
  paramStruct.NumRadialDistortionCoefficients =
      varargin_1_NumRadialDistortionCoefficients;
  paramStruct.EstimateTangentialDistortion =
      varargin_1_EstimateTangentialDistortion;
  ysize_idx_1 = c_worldPoints.size(1) + 1;
  ysize_idx_0 = c_worldPoints.size(0);
  x1.set_size(c_worldPoints.size(0), c_worldPoints.size(1));
  b_loop_ub = c_worldPoints.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    c_loop_ub)

  for (int i2 = 0; i2 < b_loop_ub; i2++) {
    c_loop_ub = c_worldPoints.size(0);
    for (i3 = 0; i3 < c_loop_ub; i3++) {
      x1[i3 + (x1.size(0) * i2)] =
          c_worldPoints[i3 + (c_worldPoints.size(0) * i2)];
    }
  }
  x1.set_size(ysize_idx_0, ysize_idx_1);
  k = 0;
  i4 = c_worldPoints.size(1);
  for (int j{0}; j < i4; j++) {
    int i6;
    k++;
    i6 = x1.size(0);
    for (int c_k{0}; c_k < i6; c_k++) {
      x1[c_k + (x1.size(0) * (k - 1))] =
          c_worldPoints[c_k + (c_worldPoints.size(0) * j)];
    }
  }
  i5 = x1.size(0);
  if ((static_cast<int>(x1.size(0) < 4)) != 0) {
    for (int b_k{0}; b_k < i5; b_k++) {
      x1[b_k + (x1.size(0) * k)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_k = 0; b_k < i5; b_k++) {
      x1[b_k + (x1.size(0) * k)] = 0.0;
    }
  }
  paramStruct_idx_0 = static_cast<int>(static_cast<double>(
      (static_cast<double>(paramStruct.RotationVectors.size(0))) *
      (static_cast<double>(e_ImagePoints.size(0)))));
  cost.set_size(paramStruct_idx_0);
  d_loop_ub = paramStruct_idx_0;
  if ((static_cast<int>(paramStruct_idx_0 < 4)) != 0) {
    for (int i7{0}; i7 < paramStruct_idx_0; i7++) {
      cost[i7] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < d_loop_ub; i7++) {
      cost[i7] = 0.0;
    }
  }
  b_i8 = paramStruct.RotationVectors.size(0);
  if (0 <= (paramStruct.RotationVectors.size(0) - 1)) {
    unnamed_idx_2 = paramStruct.RotationVectors.size(0);
    e_loop_ub = paramStruct.RotationVectors.size(0);
    i9 = paramStruct.RotationVectors.size(0);
    i10 = paramStruct.TranslationVectors.size(1);
    f_loop_ub = paramStruct.TranslationVectors.size(1);
  }
  for (int h_n{0}; h_n < b_i8; h_n++) {
    double b_d1;
    double d;
    int i17;
    int i23;
    int i24;
    int j_loop_ub;
    int k_loop_ub;
    //  for each image
    r.set_size(3, 3, unnamed_idx_2);
    for (int i11{0}; i11 < e_loop_ub; i11++) {
      for (int i12{0}; i12 < 3; i12++) {
        r[(3 * i12) + (9 * i11)] = 0.0;
        r[((3 * i12) + (9 * i11)) + 1] = 0.0;
        r[((3 * i12) + (9 * i11)) + 2] = 0.0;
      }
    }
    for (int c_i{0}; c_i < i9; c_i++) {
      double theta;
      int g_loop_ub;
      g_loop_ub = paramStruct.RotationVectors.size(1);
      b_v.set_size(1, paramStruct.RotationVectors.size(1));
      for (int i14{0}; i14 < g_loop_ub; i14++) {
        b_v[i14] =
            paramStruct
                .RotationVectors[c_i +
                                 (paramStruct.RotationVectors.size(0) * i14)];
      }
      if (paramStruct.RotationVectors.size(1) == 0) {
        theta = 0.0;
      } else {
        theta = 0.0;
        if (paramStruct.RotationVectors.size(1) >= 1) {
          if (paramStruct.RotationVectors.size(1) == 1) {
            theta = std::abs(paramStruct.RotationVectors[c_i]);
          } else {
            double scale;
            int i18;
            scale = 3.3121686421112381E-170;
            i18 = paramStruct.RotationVectors.size(1) - 1;
            for (int e_k{0}; e_k <= i18; e_k++) {
              double absxk;
              absxk = std::abs(b_v[e_k]);
              if (absxk > scale) {
                double b_t;
                b_t = scale / absxk;
                theta = ((theta * b_t) * b_t) + 1.0;
                scale = absxk;
              } else {
                double b_t;
                b_t = absxk / scale;
                theta += b_t * b_t;
              }
            }
            theta = scale * std::sqrt(theta);
          }
        }
      }
      if (theta < 1.0E-6) {
        for (int i16{0}; i16 < 3; i16++) {
          c_R[i16][0] = 0.0;
          c_R[i16][1] = 0.0;
          c_R[i16][2] = 0.0;
        }
        c_R[0][0] = 1.0;
        c_R[1][1] = 1.0;
        c_R[2][2] = 1.0;
      } else {
        double alpha;
        double b_a;
        int i_loop_ub;
        int m_loop_ub;
        int p_loop_ub;
        c_u.set_size(1, b_v.size(1));
        i_loop_ub = b_v.size(1);
        for (int i20{0}; i20 < i_loop_ub; i20++) {
          c_u[i20] = b_v[i20] / theta;
        }
        alpha = std::cos(theta);
        b_a = std::sin(theta);
        for (int i21{0}; i21 < 3; i21++) {
          c_a[i21][0] = 0;
          c_a[i21][1] = 0;
          c_a[i21][2] = 0;
        }
        c_a[0][0] = 1;
        c_a[1][1] = 1;
        c_a[2][2] = 1;
        d_a[0][0] = b_a * 0.0;
        d_a[1][0] = b_a * (-c_u[2]);
        d_a[2][0] = b_a * c_u[1];
        d_a[0][1] = b_a * c_u[2];
        d_a[1][1] = b_a * 0.0;
        d_a[2][1] = b_a * (-c_u[0]);
        d_a[0][2] = b_a * (-c_u[1]);
        d_a[1][2] = b_a * c_u[0];
        d_a[2][2] = b_a * 0.0;
        d_u.set_size(c_u.size(1), c_u.size(1));
        m_loop_ub = c_u.size(1);
        for (int i27{0}; i27 < m_loop_ub; i27++) {
          int o_loop_ub;
          o_loop_ub = c_u.size(1);
          for (int i28{0}; i28 < o_loop_ub; i28++) {
            d_u[i28 + (d_u.size(0) * i27)] = c_u[i28] * c_u[i27];
          }
        }
        r3.set_size(d_u.size(0), d_u.size(1));
        p_loop_ub = d_u.size(1);
        for (int i29{0}; i29 < p_loop_ub; i29++) {
          int q_loop_ub;
          q_loop_ub = d_u.size(0);
          for (int i31{0}; i31 < q_loop_ub; i31++) {
            r3[i31 + (r3.size(0) * i29)] =
                (1.0 - alpha) * d_u[i31 + (d_u.size(0) * i29)];
          }
        }
        for (int i30{0}; i30 < 3; i30++) {
          c_R[i30][0] =
              (((static_cast<double>(c_a[i30][0])) * alpha) + d_a[i30][0]) +
              r3[3 * i30];
          c_R[i30][1] =
              (((static_cast<double>(c_a[i30][1])) * alpha) + d_a[i30][1]) +
              r3[(3 * i30) + 1];
          c_R[i30][2] =
              (((static_cast<double>(c_a[i30][2])) * alpha) + d_a[i30][2]) +
              r3[(3 * i30) + 2];
        }
      }
      for (int i22{0}; i22 < 3; i22++) {
        r[(3 * i22) + (9 * c_i)] = c_R[0][i22];
        r[((3 * i22) + (9 * c_i)) + 1] = c_R[1][i22];
        r[((3 * i22) + (9 * c_i)) + 2] = c_R[2][i22];
      }
    }
    b_paramStruct.set_size(1, i10);
    for (int i13{0}; i13 < f_loop_ub; i13++) {
      b_paramStruct[i13] =
          paramStruct.TranslationVectors
              [h_n + (paramStruct.TranslationVectors.size(0) * i13)];
    }
    (void)std::copy(&(*((double(*)[3][3])(&r[9 * h_n])))[0][0],
                    (&(*((double(*)[3][3])(&r[9 * h_n])))[0][0]) + 9U,
                    &dv[0][0]);
    coder::worldToImage(&paramStruct, dv, b_paramStruct, x1, projectedPoints);
    if ((projectedPoints.size(0) == e_ImagePoints.size(0)) &&
        (2 == e_ImagePoints.size(1))) {
      int h_loop_ub;
      r1.set_size(projectedPoints.size(0), 2);
      h_loop_ub = projectedPoints.size(0);
      for (int i15{0}; i15 < 2; i15++) {
        for (int i19{0}; i19 < h_loop_ub; i19++) {
          double varargin_1;
          varargin_1 =
              projectedPoints[i19 + (projectedPoints.size(0) * i15)] -
              e_ImagePoints[(i19 + (e_ImagePoints.size(0) * i15)) +
                            ((e_ImagePoints.size(0) * e_ImagePoints.size(1)) *
                             h_n)];
          r1[i19 + (r1.size(0) * i15)] = varargin_1 * varargin_1;
        }
      }
    } else {
      binary_expand_op(r1, projectedPoints, e_ImagePoints, h_n);
    }
    coder::sum(r1, b_error);
    i17 = b_error.size(0);
    for (int d_k{0}; d_k < i17; d_k++) {
      b_error[d_k] = std::sqrt(b_error[d_k]);
    }
    d = ((((static_cast<double>(h_n)) + 1.0) - 1.0) *
         (static_cast<double>(e_ImagePoints.size(0)))) +
        1.0;
    b_d1 = ((static_cast<double>(h_n)) + 1.0) *
           (static_cast<double>(e_ImagePoints.size(0)));
    if (d > b_d1) {
      i23 = 0;
      i24 = 0;
    } else {
      i23 = (static_cast<int>(d)) - 1;
      i24 = static_cast<int>(b_d1);
    }
    j_loop_ub = i24 - i23;
    r2.set_size(1, j_loop_ub);
    for (int i25{0}; i25 < j_loop_ub; i25++) {
      r2[i25] = i23 + i25;
    }
    k_loop_ub = r2.size(1);
    for (int i26{0}; i26 < k_loop_ub; i26++) {
      cost[r2[i26]] = b_error[i26];
    }
  }
}

//
// File trailer for calibrateOneCamera.cpp
//
// [EOF]
//
