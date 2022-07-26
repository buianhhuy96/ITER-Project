//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "calibrateOneCamera.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_rtwutil.h"
#include "ITER_API_types.h"
#include "anonymous_function1.h"
#include "bsxfun.h"
#include "cameraParameters.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "isequal.h"
#include "lsqnonlin.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "unsafeSxfun.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace ITER {
static void unpackSerializedParams(
    const k_struct_T *cameraParams, ::coder::array<double, 1U> &b_x,
    ::coder::array<double, 2U> &outputParams_RadialDistortion,
    double outputParams_TangentialDistortion[2],
    double outputParams_ImageSize[2], char outputParams_WorldUnits[2],
    bool *outputParams_EstimateSkew,
    double *outputParams_NumRadialDistortionCoefficients,
    bool *outputParams_EstimateTangentialDistortion,
    ::coder::array<double, 2U> &outputParams_RotationVectors,
    ::coder::array<double, 2U> &outputParams_TranslationVectors,
    double outputParams_IntrinsicMatrix[3][3]);

}

// Function Definitions
//
// {
//     if cameraParams.EstimateSkew
//         skew = x(5);
//         numIntrinsicMatrixEntries = 5;
//     else
// }
//
// Arguments    : const k_struct_T *cameraParams
//                ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 2U> &outputParams_RadialDistortion
//                double outputParams_TangentialDistortion[2]
//                double outputParams_ImageSize[2]
//                char outputParams_WorldUnits[2]
//                bool *outputParams_EstimateSkew
//                double *outputParams_NumRadialDistortionCoefficients
//                bool *outputParams_EstimateTangentialDistortion
//                ::coder::array<double, 2U> &outputParams_RotationVectors
//                ::coder::array<double, 2U> &outputParams_TranslationVectors
//                double outputParams_IntrinsicMatrix[3][3]
// Return Type  : void
//
namespace ITER {
static void unpackSerializedParams(
    const k_struct_T *cameraParams, ::coder::array<double, 1U> &b_x,
    ::coder::array<double, 2U> &outputParams_RadialDistortion,
    double outputParams_TangentialDistortion[2],
    double outputParams_ImageSize[2], char outputParams_WorldUnits[2],
    bool *outputParams_EstimateSkew,
    double *outputParams_NumRadialDistortionCoefficients,
    bool *outputParams_EstimateTangentialDistortion,
    ::coder::array<double, 2U> &outputParams_RotationVectors,
    ::coder::array<double, 2U> &outputParams_TranslationVectors,
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
// Arguments    : const ::coder::array<unsigned char, 4U> &images
//                double squareSize
//                const int boardSize[2]
//                struct0_T *cameraParams
//                ::coder::array<double, 1U> &errorOptimized
//                double *MREf
//                ::coder::array<bool, 1U> &validIdx
//                int *err
// Return Type  : void
//
void calibrateOneCamera(const ::coder::array<unsigned char, 4U> &images,
                        double squareSize, const int boardSize[2],
                        struct0_T *cameraParams,
                        ::coder::array<double, 1U> &errorOptimized,
                        double *MREf, ::coder::array<bool, 1U> &validIdx,
                        int *err)
{
  coder::b_cameraParameters b_cameraParams;
  coder::cameraParameters lobj_0;
  coder::d_anonymous_function b_this;
  ::coder::array<cell_wrap_19, 2U> board_points;
  ::coder::array<double, 2U> c_worldPoints;
  ::coder::array<double, 2U> current_board_points;
  ::coder::array<double, 2U> jacobian;
  ::coder::array<double, 2U> rt;
  ::coder::array<double, 1U> f_expl_temp;
  ::coder::array<double, 1U> g_expl_temp;
  ::coder::array<double, 1U> initialParamsSerial;
  ::coder::array<double, 1U> r;
  ::coder::array<double, 1U> r1;
  ::coder::array<double, 1U> residual;
  ::coder::array<double, 1U> tmp;
  ::coder::array<unsigned char, 2U> b_images;
  ::coder::array<bool, 1U> a__1;
  ::coder::array<bool, 1U> b_x;
  double t10_RadialDistortion[3];
  double b_dv[2];
  double b_image_size[2];
  double board_size_detected[2];
  double board_size_valid[2];
  double a__2;
  double a__3;
  double b_MREf;
  double b_expl_temp;
  double c_expl_temp;
  double d_expl_temp;
  double expl_temp;
  double t10_NumRadialDistortionCoefficients;
  int b_err;
  int b_i;
  int c_err;
  int d_err;
  int i14;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  char e_expl_temp[19];
  bool exitg1;
  bool t10_EstimateSkew;
  bool t10_EstimateTangentialDistortion;
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
      ->toStruct(t10_RadialDistortion, cameraParams->TangentialDistortion,
                 cameraParams->ImageSize, cameraParams->WorldUnits,
                 &t10_EstimateSkew, &t10_NumRadialDistortionCoefficients,
                 &t10_EstimateTangentialDistortion,
                 cameraParams->IntrinsicMatrix);
  cameraParams->RadialDistortion.set_size(1, 3);
  cameraParams->RadialDistortion[0] = t10_RadialDistortion[0];
  cameraParams->RadialDistortion[1] = t10_RadialDistortion[1];
  cameraParams->RadialDistortion[2] = t10_RadialDistortion[2];
  cameraParams->EstimateSkew = t10_EstimateSkew;
  cameraParams->NumRadialDistortionCoefficients =
      t10_NumRadialDistortionCoefficients;
  cameraParams->EstimateTangentialDistortion = t10_EstimateTangentialDistortion;
  cameraParams->RotationVectors.set_size(0, 3);
  cameraParams->TranslationVectors.set_size(0, 3);
  errorOptimized.set_size(0);
  b_MREf = rtInf;
  //  Inform MATLAB Coder that these arrays' size can be change.
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
    b_dv[0] = 0.0;
    b_dv[1] = 0.0;
    if (coder::isequal(board_size_detected, b_dv)) {
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
        b_dv[0] = 0.0;
        b_dv[1] = 0.0;
        if (coder::isequal(board_size_valid, b_dv)) {
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
          int b_worldPoints_tmp;
          b_worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                  d_k + (static_cast<unsigned int>(e_i))))) -
                              1;
          c_worldPoints[b_worldPoints_tmp] =
              (static_cast<double>(b_j)) * squareSize;
          c_worldPoints[b_worldPoints_tmp + c_worldPoints.size(0)] =
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
      //  Add an option for lsqnonlin to generate C++
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
// Arguments    : const ::coder::array<double, 1U> &paramsVector
//                const k_struct_T *cameraParams
//                const ::coder::array<double, 2U> &c_worldPoints
//                const ::coder::array<double, 3U> &e_ImagePoints
//                ::coder::array<double, 1U> &b_cost
// Return Type  : void
//
void reprojectWrapper(const ::coder::array<double, 1U> &paramsVector,
                      const k_struct_T *cameraParams,
                      const ::coder::array<double, 2U> &c_worldPoints,
                      const ::coder::array<double, 3U> &e_ImagePoints,
                      ::coder::array<double, 1U> &b_cost)
{
  coder::c_cameraParameters paramStruct;
  ::coder::array<double, 3U> r;
  ::coder::array<double, 2U> b_distortedNormalizedPoints;
  ::coder::array<double, 2U> b_normalizedPoints;
  ::coder::array<double, 2U> b_projectedPoints;
  ::coder::array<double, 2U> b_r4;
  ::coder::array<double, 2U> b_result;
  ::coder::array<double, 2U> b_varargin_1_TranslationVectors;
  ::coder::array<double, 2U> c_result;
  ::coder::array<double, 2U> c_u;
  ::coder::array<double, 2U> cameraMatrix;
  ::coder::array<double, 2U> centeredPoints;
  ::coder::array<double, 2U> d_u;
  ::coder::array<double, 2U> distortedNormalizedPoints;
  ::coder::array<double, 2U> e_v;
  ::coder::array<double, 2U> g_a;
  ::coder::array<double, 2U> imagePointsTmp;
  ::coder::array<double, 2U> normalizedPoints;
  ::coder::array<double, 2U> projectedPoints;
  ::coder::array<double, 2U> r1;
  ::coder::array<double, 2U> varargin_1_RadialDistortion;
  ::coder::array<double, 2U> varargin_1_RotationVectors;
  ::coder::array<double, 2U> varargin_1_TranslationVectors;
  ::coder::array<double, 2U> x1;
  ::coder::array<double, 1U> b_alpha;
  ::coder::array<double, 1U> b_b;
  ::coder::array<double, 1U> b_error;
  ::coder::array<double, 1U> b_paramsVector;
  ::coder::array<double, 1U> b_r2;
  ::coder::array<double, 1U> b_z1;
  ::coder::array<double, 1U> c_b;
  ::coder::array<double, 1U> c_imagePointsTmp;
  ::coder::array<double, 1U> c_projectedPoints;
  ::coder::array<double, 1U> r2;
  ::coder::array<double, 1U> r3;
  ::coder::array<double, 1U> r4;
  ::coder::array<double, 1U> xNorm;
  ::coder::array<double, 1U> xyProduct;
  ::coder::array<double, 1U> yNorm;
  ::coder::array<double, 1U> z1;
  ::coder::array<int, 2U> r5;
  double b_R[3][3];
  double f_K[3][3];
  double f_a[3][3];
  double varargin_1_IntrinsicMatrix[3][3];
  double b[2];
  double expl_temp[2];
  double varargin_1_TangentialDistortion[2];
  double b_a;
  double b_varargin_1_TangentialDistortion;
  double c_varargin_1_TangentialDistortion;
  double d_a;
  double d_expl_temp;
  double k_idx_0;
  double k_idx_1;
  double k_idx_2;
  int b_i8;
  int b_loop_ub;
  int b_result_idx_0;
  int b_result_idx_1;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int i3;
  int i4;
  int i5;
  int i9;
  int input_sizes_idx_0;
  int j_loop_ub;
  int k;
  int k_loop_ub;
  int loop_ub;
  int result_idx_0;
  int result_idx_1;
  int unnamed_idx_0;
  int unnamed_idx_2;
  int varargin_1_RotationVectors_idx_0;
  int ysize_idx_0;
  int ysize_idx_1;
  signed char e_a[3][3];
  char b_expl_temp[2];
  bool c_expl_temp;
  bool e_expl_temp;
  b_paramsVector.set_size(paramsVector.size(0));
  loop_ub = paramsVector.size(0) - 1;
  for (int b_i{0}; b_i <= loop_ub; b_i++) {
    b_paramsVector[b_i] = paramsVector[b_i];
  }
  unpackSerializedParams(
      cameraParams, b_paramsVector, varargin_1_RadialDistortion,
      varargin_1_TangentialDistortion, expl_temp, b_expl_temp, &c_expl_temp,
      &d_expl_temp, &e_expl_temp, varargin_1_RotationVectors,
      varargin_1_TranslationVectors, varargin_1_IntrinsicMatrix);
  for (int i1{0}; i1 < 3; i1++) {
    paramStruct.IntrinsicMatrixInternal[i1][0] =
        varargin_1_IntrinsicMatrix[0][i1];
    paramStruct.IntrinsicMatrixInternal[i1][1] =
        varargin_1_IntrinsicMatrix[1][i1];
    paramStruct.IntrinsicMatrixInternal[i1][2] =
        varargin_1_IntrinsicMatrix[2][i1];
  }
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
  varargin_1_RotationVectors_idx_0 = static_cast<int>(static_cast<double>(
      (static_cast<double>(varargin_1_RotationVectors.size(0))) *
      (static_cast<double>(e_ImagePoints.size(0)))));
  b_cost.set_size(varargin_1_RotationVectors_idx_0);
  d_loop_ub = varargin_1_RotationVectors_idx_0;
  if ((static_cast<int>(varargin_1_RotationVectors_idx_0 < 4)) != 0) {
    for (int i7{0}; i7 < varargin_1_RotationVectors_idx_0; i7++) {
      b_cost[i7] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i7 = 0; i7 < d_loop_ub; i7++) {
      b_cost[i7] = 0.0;
    }
  }
  b_i8 = varargin_1_RotationVectors.size(0);
  if (0 <= (varargin_1_RotationVectors.size(0) - 1)) {
    int input_sizes_idx_1;
    int result;
    signed char b_input_sizes_idx_1;
    bool empty_non_axis_sizes;
    unnamed_idx_2 = varargin_1_RotationVectors.size(0);
    e_loop_ub = varargin_1_RotationVectors.size(0);
    i9 = varargin_1_RotationVectors.size(0);
    unnamed_idx_0 = varargin_1_TranslationVectors.size(1);
    f_loop_ub = varargin_1_TranslationVectors.size(1);
    input_sizes_idx_0 =
        static_cast<int>(varargin_1_TranslationVectors.size(1) != 0);
    g_loop_ub = static_cast<int>(varargin_1_TranslationVectors.size(1) != 0);
    if ((x1.size(0) != 0) && (x1.size(1) != 0)) {
      result = x1.size(0);
    } else if (x1.size(0) != 0) {
      result = x1.size(0);
    } else {
      result = 0;
    }
    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes) {
      input_sizes_idx_1 = x1.size(1);
    } else if ((x1.size(0) != 0) && (x1.size(1) != 0)) {
      input_sizes_idx_1 = x1.size(1);
    } else {
      input_sizes_idx_1 = 0;
    }
    if (empty_non_axis_sizes) {
      b_input_sizes_idx_1 = 1;
    } else if (x1.size(0) != 0) {
      b_input_sizes_idx_1 = 1;
    } else {
      b_input_sizes_idx_1 = 0;
    }
    result_idx_0 = result;
    result_idx_1 = input_sizes_idx_1;
    b_result_idx_0 = result;
    b_result_idx_1 = static_cast<int>(b_input_sizes_idx_1);
    j_loop_ub = input_sizes_idx_1;
    k_loop_ub = static_cast<int>(b_input_sizes_idx_1);
    b_a = 2.0 * varargin_1_TangentialDistortion[0];
    d_a = 2.0 * varargin_1_TangentialDistortion[1];
    b_varargin_1_TangentialDistortion = varargin_1_TangentialDistortion[1];
    c_varargin_1_TangentialDistortion = varargin_1_TangentialDistortion[0];
  }
  if (0 <= (b_i8 - 1)) {
    k_idx_0 = varargin_1_RadialDistortion[0];
    k_idx_1 = varargin_1_RadialDistortion[1];
    if (varargin_1_RadialDistortion.size(1) < 3) {
      k_idx_2 = 0.0;
    } else {
      k_idx_2 = varargin_1_RadialDistortion[2];
    }
    for (int i11{0}; i11 < 3; i11++) {
      f_K[i11][0] = paramStruct.IntrinsicMatrixInternal[0][i11];
      f_K[i11][1] = paramStruct.IntrinsicMatrixInternal[1][i11];
      f_K[i11][2] = paramStruct.IntrinsicMatrixInternal[2][i11];
    }
  }
  for (int h_n{0}; h_n < b_i8; h_n++) {
    double d2;
    double d3;
    int ab_loop_ub;
    int bb_loop_ub;
    int cb_loop_ub;
    int db_loop_ub;
    int eb_loop_ub;
    int fb_loop_ub;
    int gb_loop_ub;
    int hb_loop_ub;
    int i58;
    int i61;
    int i63;
    int i_N;
    int ib_loop_ub;
    int inner;
    int jb_loop_ub;
    int k_N;
    int kb_loop_ub;
    int m;
    int m_N;
    int m_loop_ub;
    int mb_loop_ub;
    int mc;
    int o_N;
    int o_loop_ub;
    int ob_loop_ub;
    int pb_loop_ub;
    int qb_loop_ub;
    int rb_loop_ub;
    int t_loop_ub;
    int v_loop_ub;
    int vb_loop_ub;
    int w_loop_ub;
    int wb_loop_ub;
    int x_loop_ub;
    int y_loop_ub;
    //  for each image
    r.set_size(3, 3, unnamed_idx_2);
    for (int i10{0}; i10 < e_loop_ub; i10++) {
      for (int i12{0}; i12 < 3; i12++) {
        r[(3 * i12) + (9 * i10)] = 0.0;
        r[((3 * i12) + (9 * i10)) + 1] = 0.0;
        r[((3 * i12) + (9 * i10)) + 2] = 0.0;
      }
    }
    for (int c_i{0}; c_i < i9; c_i++) {
      double theta;
      int h_loop_ub;
      h_loop_ub = varargin_1_RotationVectors.size(1);
      e_v.set_size(1, varargin_1_RotationVectors.size(1));
      for (int i14{0}; i14 < h_loop_ub; i14++) {
        e_v[i14] = varargin_1_RotationVectors
            [c_i + (varargin_1_RotationVectors.size(0) * i14)];
      }
      if (varargin_1_RotationVectors.size(1) == 0) {
        theta = 0.0;
      } else {
        theta = 0.0;
        if (varargin_1_RotationVectors.size(1) == 1) {
          theta = std::abs(varargin_1_RotationVectors[c_i]);
        } else {
          double scale;
          int kend;
          scale = 3.3121686421112381E-170;
          kend = varargin_1_RotationVectors.size(1) - 1;
          for (int d_k{0}; d_k <= kend; d_k++) {
            double absxk;
            absxk = std::abs(e_v[d_k]);
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
      if (theta < 1.0E-6) {
        for (int i16{0}; i16 < 3; i16++) {
          b_R[i16][0] = 0.0;
          b_R[i16][1] = 0.0;
          b_R[i16][2] = 0.0;
        }
        b_R[0][0] = 1.0;
        b_R[1][1] = 1.0;
        b_R[2][2] = 1.0;
      } else {
        double alpha;
        double c_a;
        int i_loop_ub;
        int p_loop_ub;
        int r_loop_ub;
        c_u.set_size(1, e_v.size(1));
        i_loop_ub = e_v.size(1);
        for (int i18{0}; i18 < i_loop_ub; i18++) {
          c_u[i18] = e_v[i18] / theta;
        }
        alpha = std::cos(theta);
        c_a = std::sin(theta);
        for (int i22{0}; i22 < 3; i22++) {
          e_a[i22][0] = 0;
          e_a[i22][1] = 0;
          e_a[i22][2] = 0;
        }
        e_a[0][0] = 1;
        e_a[1][1] = 1;
        e_a[2][2] = 1;
        f_a[0][0] = c_a * 0.0;
        f_a[1][0] = c_a * (-c_u[2]);
        f_a[2][0] = c_a * c_u[1];
        f_a[0][1] = c_a * c_u[2];
        f_a[1][1] = c_a * 0.0;
        f_a[2][1] = c_a * (-c_u[0]);
        f_a[0][2] = c_a * (-c_u[1]);
        f_a[1][2] = c_a * c_u[0];
        f_a[2][2] = c_a * 0.0;
        d_u.set_size(c_u.size(1), c_u.size(1));
        p_loop_ub = c_u.size(1);
        for (int i28{0}; i28 < p_loop_ub; i28++) {
          int q_loop_ub;
          q_loop_ub = c_u.size(1);
          for (int i30{0}; i30 < q_loop_ub; i30++) {
            d_u[i30 + (d_u.size(0) * i28)] = c_u[i30] * c_u[i28];
          }
        }
        r1.set_size(d_u.size(0), d_u.size(1));
        r_loop_ub = d_u.size(1);
        for (int i31{0}; i31 < r_loop_ub; i31++) {
          int u_loop_ub;
          u_loop_ub = d_u.size(0);
          for (int i34{0}; i34 < u_loop_ub; i34++) {
            r1[i34 + (r1.size(0) * i31)] =
                (1.0 - alpha) * d_u[i34 + (d_u.size(0) * i31)];
          }
        }
        for (int i33{0}; i33 < 3; i33++) {
          b_R[i33][0] =
              (((static_cast<double>(e_a[i33][0])) * alpha) + f_a[i33][0]) +
              r1[3 * i33];
          b_R[i33][1] =
              (((static_cast<double>(e_a[i33][1])) * alpha) + f_a[i33][1]) +
              r1[(3 * i33) + 1];
          b_R[i33][2] =
              (((static_cast<double>(e_a[i33][2])) * alpha) + f_a[i33][2]) +
              r1[(3 * i33) + 2];
        }
      }
      for (int i23{0}; i23 < 3; i23++) {
        r[(3 * i23) + (9 * c_i)] = b_R[0][i23];
        r[((3 * i23) + (9 * c_i)) + 1] = b_R[1][i23];
        r[((3 * i23) + (9 * c_i)) + 2] = b_R[2][i23];
      }
    }
    b_varargin_1_TranslationVectors.set_size(1, unnamed_idx_0);
    for (int i13{0}; i13 < f_loop_ub; i13++) {
      b_varargin_1_TranslationVectors[i13] = varargin_1_TranslationVectors
          [h_n + (varargin_1_TranslationVectors.size(0) * i13)];
    }
    b_result.set_size(input_sizes_idx_0 + 3, 3);
    for (int i15{0}; i15 < 3; i15++) {
      b_result[b_result.size(0) * i15] = r[(3 * i15) + (9 * h_n)];
      b_result[(b_result.size(0) * i15) + 1] = r[((3 * i15) + (9 * h_n)) + 1];
      b_result[(b_result.size(0) * i15) + 2] = r[((3 * i15) + (9 * h_n)) + 2];
      for (int i17{0}; i17 < g_loop_ub; i17++) {
        b_result[(b_result.size(0) * i15) + 3] =
            b_varargin_1_TranslationVectors[input_sizes_idx_0 * i15];
      }
    }
    m = b_result.size(0);
    cameraMatrix.set_size(b_result.size(0), 3);
    for (int b_j{0}; b_j < 3; b_j++) {
      for (int d_i{0}; d_i < m; d_i++) {
        cameraMatrix[d_i + (cameraMatrix.size(0) * b_j)] =
            ((b_result[d_i] * f_K[b_j][0]) +
             (b_result[d_i + b_result.size(0)] * f_K[b_j][1])) +
            (b_result[d_i + (b_result.size(0) * 2)] * f_K[b_j][2]);
      }
    }
    c_result.set_size(result_idx_0, result_idx_1 + b_result_idx_1);
    for (int i19{0}; i19 < j_loop_ub; i19++) {
      for (int i21{0}; i21 < result_idx_0; i21++) {
        c_result[i21 + (c_result.size(0) * i19)] =
            x1[i21 + (result_idx_0 * i19)];
      }
    }
    for (int i20{0}; i20 < k_loop_ub; i20++) {
      for (int i24{0}; i24 < b_result_idx_0; i24++) {
        c_result[i24 + (c_result.size(0) * result_idx_1)] = 1.0;
      }
    }
    mc = c_result.size(0) - 1;
    inner = c_result.size(1);
    projectedPoints.set_size(c_result.size(0), 3);
    for (int c_j{0}; c_j < 3; c_j++) {
      for (int e_i{0}; e_i <= mc; e_i++) {
        projectedPoints[e_i + (projectedPoints.size(0) * c_j)] = 0.0;
      }
      for (int e_k{0}; e_k < inner; e_k++) {
        double bkj;
        bkj = cameraMatrix[e_k + (cameraMatrix.size(0) * c_j)];
        for (int g_i{0}; g_i <= mc; g_i++) {
          projectedPoints[g_i + (projectedPoints.size(0) * c_j)] =
              projectedPoints[g_i + (projectedPoints.size(0) * c_j)] +
              (c_result[g_i + (c_result.size(0) * e_k)] * bkj);
        }
      }
    }
    m_loop_ub = projectedPoints.size(0);
    b_projectedPoints.set_size(projectedPoints.size(0), 2);
    for (int i25{0}; i25 < 2; i25++) {
      for (int i26{0}; i26 < m_loop_ub; i26++) {
        b_projectedPoints[i26 + (b_projectedPoints.size(0) * i25)] =
            projectedPoints[i26 + (projectedPoints.size(0) * i25)];
      }
    }
    o_loop_ub = projectedPoints.size(0);
    c_projectedPoints.set_size(projectedPoints.size(0));
    for (int i27{0}; i27 < o_loop_ub; i27++) {
      c_projectedPoints[i27] =
          projectedPoints[i27 + (projectedPoints.size(0) * 2)];
    }
    coder::b_bsxfun(b_projectedPoints, c_projectedPoints, imagePointsTmp);
    if (f_K[0][1] != 0.0) {
      int b_imagePointsTmp;
      int s_loop_ub;
      b_imagePointsTmp = imagePointsTmp.size(0) - 1;
      c_imagePointsTmp.set_size(imagePointsTmp.size(0));
      for (int i29{0}; i29 <= b_imagePointsTmp; i29++) {
        c_imagePointsTmp[i29] =
            imagePointsTmp[i29] -
            ((f_K[0][1] *
              (imagePointsTmp[i29 + imagePointsTmp.size(0)] - f_K[1][2])) /
             f_K[1][1]);
      }
      s_loop_ub = c_imagePointsTmp.size(0);
      for (int i32{0}; i32 < s_loop_ub; i32++) {
        imagePointsTmp[i32] = c_imagePointsTmp[i32];
      }
    }
    b[0] = f_K[0][2];
    b[1] = f_K[1][2];
    centeredPoints.set_size(imagePointsTmp.size(0), 2);
    if (imagePointsTmp.size(0) != 0) {
      int acoef;
      acoef = static_cast<int>(imagePointsTmp.size(0) != 1);
      for (int g_k{0}; g_k < 2; g_k++) {
        int i36;
        i36 = centeredPoints.size(0) - 1;
        for (int h_k{0}; h_k <= i36; h_k++) {
          centeredPoints[h_k + (centeredPoints.size(0) * g_k)] =
              imagePointsTmp[(acoef * h_k) + (imagePointsTmp.size(0) * g_k)] -
              b[g_k];
        }
      }
    }
    t_loop_ub = centeredPoints.size(0);
    yNorm.set_size(centeredPoints.size(0));
    for (int i35{0}; i35 < t_loop_ub; i35++) {
      yNorm[i35] = centeredPoints[i35 + centeredPoints.size(0)] / f_K[1][1];
    }
    v_loop_ub = centeredPoints.size(0);
    xNorm.set_size(centeredPoints.size(0));
    for (int i37{0}; i37 < v_loop_ub; i37++) {
      xNorm[i37] = centeredPoints[i37] / f_K[0][0];
    }
    w_loop_ub = xNorm.size(0);
    r2.set_size(xNorm.size(0));
    z1.set_size(xNorm.size(0));
    for (int i38{0}; i38 < w_loop_ub; i38++) {
      z1[i38] = r2[i38];
    }
    i_N = xNorm.size(0);
    for (int i_k{0}; i_k < i_N; i_k++) {
      z1[i_k] = rt_powd_snf(xNorm[i_k], 2.0);
    }
    r2.set_size(z1.size(0));
    x_loop_ub = z1.size(0);
    for (int i39{0}; i39 < x_loop_ub; i39++) {
      r2[i39] = z1[i39];
    }
    y_loop_ub = yNorm.size(0);
    r3.set_size(yNorm.size(0));
    b_z1.set_size(yNorm.size(0));
    for (int i40{0}; i40 < y_loop_ub; i40++) {
      b_z1[i40] = r3[i40];
    }
    k_N = yNorm.size(0);
    for (int j_k{0}; j_k < k_N; j_k++) {
      b_z1[j_k] = rt_powd_snf(yNorm[j_k], 2.0);
    }
    r3.set_size(b_z1.size(0));
    ab_loop_ub = b_z1.size(0);
    for (int i41{0}; i41 < ab_loop_ub; i41++) {
      r3[i41] = b_z1[i41];
    }
    b_r2.set_size(z1.size(0));
    bb_loop_ub = z1.size(0);
    for (int i42{0}; i42 < bb_loop_ub; i42++) {
      b_r2[i42] = z1[i42] + b_z1[i42];
    }
    r4.set_size(b_r2.size(0));
    cb_loop_ub = b_r2.size(0);
    for (int i43{0}; i43 < cb_loop_ub; i43++) {
      r4[i43] = b_r2[i43] * b_r2[i43];
    }
    b_alpha.set_size(b_r2.size(0));
    db_loop_ub = b_r2.size(0);
    for (int i44{0}; i44 < db_loop_ub; i44++) {
      b_alpha[i44] = ((k_idx_0 * b_r2[i44]) + (k_idx_1 * r4[i44])) +
                     (k_idx_2 * (b_r2[i44] * r4[i44]));
    }
    xyProduct.set_size(xNorm.size(0));
    eb_loop_ub = xNorm.size(0);
    for (int i45{0}; i45 < eb_loop_ub; i45++) {
      xyProduct[i45] = xNorm[i45] * yNorm[i45];
    }
    fb_loop_ub = xNorm.size(0);
    b_b.set_size(xNorm.size(0));
    z1.set_size(xNorm.size(0));
    for (int i46{0}; i46 < fb_loop_ub; i46++) {
      z1[i46] = b_b[i46];
    }
    m_N = xNorm.size(0);
    for (int k_k{0}; k_k < m_N; k_k++) {
      z1[k_k] = rt_powd_snf(xNorm[k_k], 2.0);
    }
    b_b.set_size(z1.size(0));
    gb_loop_ub = z1.size(0);
    for (int i47{0}; i47 < gb_loop_ub; i47++) {
      b_b[i47] = z1[i47];
    }
    hb_loop_ub = yNorm.size(0);
    c_b.set_size(yNorm.size(0));
    b_z1.set_size(yNorm.size(0));
    for (int i48{0}; i48 < hb_loop_ub; i48++) {
      b_z1[i48] = c_b[i48];
    }
    o_N = yNorm.size(0);
    for (int m_k{0}; m_k < o_N; m_k++) {
      b_z1[m_k] = rt_powd_snf(yNorm[m_k], 2.0);
    }
    c_b.set_size(b_z1.size(0));
    ib_loop_ub = b_z1.size(0);
    for (int i49{0}; i49 < ib_loop_ub; i49++) {
      c_b[i49] = b_z1[i49];
    }
    normalizedPoints.set_size(xNorm.size(0), 2);
    jb_loop_ub = xNorm.size(0);
    for (int i50{0}; i50 < jb_loop_ub; i50++) {
      normalizedPoints[i50] = xNorm[i50];
    }
    kb_loop_ub = yNorm.size(0);
    for (int i51{0}; i51 < kb_loop_ub; i51++) {
      normalizedPoints[i51 + normalizedPoints.size(0)] = yNorm[i51];
    }
    b_normalizedPoints.set_size(normalizedPoints.size(0), 2);
    mb_loop_ub = normalizedPoints.size(0);
    for (int i52{0}; i52 < mb_loop_ub; i52++) {
      double d;
      d = normalizedPoints[i52];
      b_normalizedPoints[i52] = d + (d * b_alpha[i52]);
    }
    ob_loop_ub = normalizedPoints.size(0);
    for (int i53{0}; i53 < ob_loop_ub; i53++) {
      double b_d1;
      b_d1 = normalizedPoints[i53 + normalizedPoints.size(0)];
      b_normalizedPoints[i53 + b_normalizedPoints.size(0)] =
          b_d1 + (b_d1 * b_alpha[i53]);
    }
    g_a.set_size(xyProduct.size(0), 2);
    pb_loop_ub = xyProduct.size(0);
    for (int i54{0}; i54 < pb_loop_ub; i54++) {
      g_a[i54] = (b_a * xyProduct[i54]) + (b_varargin_1_TangentialDistortion *
                                           (b_r2[i54] + (2.0 * z1[i54])));
    }
    qb_loop_ub = b_r2.size(0);
    for (int i55{0}; i55 < qb_loop_ub; i55++) {
      g_a[i55 + g_a.size(0)] = (c_varargin_1_TangentialDistortion *
                                (b_r2[i55] + (2.0 * b_z1[i55]))) +
                               (d_a * xyProduct[i55]);
    }
    distortedNormalizedPoints.set_size(b_normalizedPoints.size(0), 2);
    rb_loop_ub = b_normalizedPoints.size(0);
    for (int i56{0}; i56 < 2; i56++) {
      for (int i57{0}; i57 < rb_loop_ub; i57++) {
        distortedNormalizedPoints[i57 +
                                  (distortedNormalizedPoints.size(0) * i56)] =
            b_normalizedPoints[i57 + (b_normalizedPoints.size(0) * i56)] +
            g_a[i57 + (g_a.size(0) * i56)];
      }
    }
    if ((distortedNormalizedPoints.size(0) == e_ImagePoints.size(0)) &&
        (2 == e_ImagePoints.size(1))) {
      int sb_loop_ub;
      int tb_loop_ub;
      int ub_loop_ub;
      sb_loop_ub = distortedNormalizedPoints.size(0);
      tb_loop_ub = distortedNormalizedPoints.size(0);
      b_distortedNormalizedPoints.set_size(distortedNormalizedPoints.size(0),
                                           2);
      for (int i59{0}; i59 < sb_loop_ub; i59++) {
        b_distortedNormalizedPoints[i59] =
            ((distortedNormalizedPoints[i59] * f_K[0][0]) + f_K[0][2]) +
            (f_K[0][1] *
             distortedNormalizedPoints[i59 +
                                       distortedNormalizedPoints.size(0)]);
      }
      for (int i60{0}; i60 < tb_loop_ub; i60++) {
        b_distortedNormalizedPoints[i60 + b_distortedNormalizedPoints.size(0)] =
            (distortedNormalizedPoints[i60 +
                                       distortedNormalizedPoints.size(0)] *
             f_K[1][1]) +
            f_K[1][2];
      }
      b_r4.set_size(b_distortedNormalizedPoints.size(0), 2);
      ub_loop_ub = b_distortedNormalizedPoints.size(0);
      for (int i62{0}; i62 < 2; i62++) {
        for (int i64{0}; i64 < ub_loop_ub; i64++) {
          double varargin_1;
          varargin_1 =
              b_distortedNormalizedPoints[i64 +
                                          (b_distortedNormalizedPoints.size(0) *
                                           i62)] -
              e_ImagePoints[(i64 + (e_ImagePoints.size(0) * i62)) +
                            ((e_ImagePoints.size(0) * e_ImagePoints.size(1)) *
                             h_n)];
          b_r4[i64 + (b_r4.size(0) * i62)] = varargin_1 * varargin_1;
        }
      }
    } else {
      binary_expand_op(b_r4, distortedNormalizedPoints, f_K, e_ImagePoints,
                       h_n);
    }
    coder::sum(b_r4, b_error);
    i58 = b_error.size(0);
    for (int o_k{0}; o_k < i58; o_k++) {
      b_error[o_k] = std::sqrt(b_error[o_k]);
    }
    d2 = ((((static_cast<double>(h_n)) + 1.0) - 1.0) *
          (static_cast<double>(e_ImagePoints.size(0)))) +
         1.0;
    d3 = ((static_cast<double>(h_n)) + 1.0) *
         (static_cast<double>(e_ImagePoints.size(0)));
    if (d2 > d3) {
      i61 = 0;
      i63 = 0;
    } else {
      i61 = (static_cast<int>(d2)) - 1;
      i63 = static_cast<int>(d3);
    }
    vb_loop_ub = i63 - i61;
    r5.set_size(1, vb_loop_ub);
    for (int i65{0}; i65 < vb_loop_ub; i65++) {
      r5[i65] = i61 + i65;
    }
    wb_loop_ub = r5.size(1);
    for (int i66{0}; i66 < wb_loop_ub; i66++) {
      b_cost[r5[i66]] = b_error[i66];
    }
  }
}

} // namespace ITER

//
// File trailer for calibrateOneCamera.cpp
//
// [EOF]
//
