//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "calibrateOneCamera.h"
#include "CalculateCost.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_initialize.h"
#include "ITER_API_v2_internal_types.h"
#include "ITER_API_v2_internal_types11.h"
#include "ITER_API_v2_internal_types2.h"
#include "ITER_API_v2_internal_types3.h"
#include "ITER_API_v2_types.h"
#include "anonymous_function1.h"
#include "cat.h"
#include "combineVectorElements.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "isequal.h"
#include "lsqnonlin.h"
#include "nanmean.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Retrieve useful information
//
// Arguments    : const coder::array<unsigned char, 4U> &images
//                double squareSize
//                const double boardSize[2]
//                struct0_T *b_cameraParameters
//                coder::array<double, 1U> &errorOptimized
//                double *calculation_err
//                int *err
// Return Type  : void
//
void calibrateOneCamera(const coder::array<unsigned char, 4U> &images,
                        double squareSize, const double boardSize[2],
                        struct0_T *b_cameraParameters,
                        coder::array<double, 1U> &errorOptimized,
                        double *calculation_err, int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::anonymous_function b_this;
  coder::array<cell_wrap_0, 2U> a__6;
  coder::array<cell_wrap_1, 2U> board_points;
  coder::array<double, 3U> RotationMatrices;
  coder::array<double, 2U> b_world_points;
  coder::array<double, 2U> c_worldPoints;
  coder::array<double, 2U> current_board_points;
  coder::array<double, 2U> jacobian;
  coder::array<double, 1U> b_serialCalib;
  coder::array<double, 1U> b_v;
  coder::array<double, 1U> c_serialCalib;
  coder::array<double, 1U> d_serialCalib;
  coder::array<double, 1U> f_expl_temp;
  coder::array<double, 1U> g_expl_temp;
  coder::array<double, 1U> residual;
  coder::array<double, 1U> serialCalib;
  coder::array<double, 1U> tmp;
  coder::array<double, 1U> varargin_1;
  coder::array<int, 1U> r;
  coder::array<int, 1U> r1;
  coder::array<int, 1U> r2;
  coder::array<unsigned char, 2U> b_images;
  coder::array<bool, 1U> a__1;
  coder::array<bool, 1U> d__1;
  coder::array<bool, 1U> imagesUsed;
  c_struct_T initialParams;
  double b_a[3][3];
  double c_this[3][3];
  double c_u[3][3];
  double rotationMatrix[3][3];
  double rvec[6];
  double varargin_2[6];
  double v[4];
  double b_u[3];
  double dv1[3];
  double u[3];
  double board_size_detected[2];
  double board_size_valid[2];
  double c_images[2];
  double dv[2];
  double a__2;
  double a__3;
  double b_expl_temp;
  double c_expl_temp;
  double d_expl_temp;
  double expl_temp;
  int ab_loop_ub;
  int b_end;
  int b_err;
  int b_i;
  int b_partialTrueCount;
  int b_trueCount;
  int c_err;
  int d_end;
  int db_loop_ub;
  int e_loop_ub;
  int end;
  int i21;
  int i41;
  int i6;
  int image_point_valid_size_idx_0;
  int image_point_valid_size_idx_1;
  int k_loop_ub;
  int m_loop_ub;
  int p_loop_ub;
  int partialTrueCount;
  int result;
  int trueCount;
  int u_loop_ub;
  int w_loop_ub;
  int x_loop_ub;
  int y_loop_ub;
  char e_expl_temp[19];
  signed char c_a[3][3];
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_ITER_API_v2) {
    ITER_API_v2_initialize();
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
  //  Initalize error flag
  b_err = 0;
  board_size_valid[0] = 0.0;
  image_point_valid_size_idx_0 = 0;
  board_size_valid[1] = 0.0;
  image_point_valid_size_idx_1 = 0;
  // board_sizes = zeros(num_of_images,1);
  a__1.set_size(images.size(3));
  b_i = images.size(3);
  board_points.set_size(1, images.size(3));
  for (int c_i{0}; c_i < b_i; c_i++) {
    int b_loop_ub;
    int f_loop_ub;
    int loop_ub;
    //  perform checkerboards detection in each image
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
      a__1[c_i] = false;
    } else if (!coder::isequal(board_size_detected, boardSize)) {
      a__1[c_i] = false;
    } else {
      dv[0] = 0.0;
      dv[1] = 0.0;
      if (coder::isequal(board_size_valid, dv)) {
        board_size_valid[0] = board_size_detected[0];
        image_point_valid_size_idx_0 = current_board_points.size(0);
        board_size_valid[1] = board_size_detected[1];
        image_point_valid_size_idx_1 = current_board_points.size(1);
      } else if (!coder::isequal(board_size_valid, board_size_detected)) {
        b_err = -1;
      } else {
        /* no actions */
      }
      a__1[c_i] = true;
    }
    f_loop_ub = current_board_points.size(1);
    board_points[board_points.size(0) * c_i].f1.set_size(
        current_board_points.size(0), current_board_points.size(1));
    for (int i10{0}; i10 < f_loop_ub; i10++) {
      int g_loop_ub;
      g_loop_ub = current_board_points.size(0);
      for (int i12{0}; i12 < g_loop_ub; i12++) {
        board_points[c_i].f1[i12 + (board_points[c_i].f1.size(0) * i10)] =
            current_board_points[i12 + (current_board_points.size(0) * i10)];
      }
    }
  }
  if (b_err != 0) {
    b_this.workspace.calibration.ImagePoints.set_size(0, 0, 1);
    b_world_points.set_size(0, 0);
  } else {
    int k;
    bool exitg1;
    bool y;
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (a__1.size(0) - 1))) {
      if (!a__1[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!y) {
      // err = "Wrong detection of board size";
      b_this.workspace.calibration.ImagePoints.set_size(0, 0, 1);
      b_world_points.set_size(0, 0);
    } else {
      unsigned int b_k;
      int board_size_valid_idx_0;
      int c_loop_ub;
      int d_loop_ub;
      int i17;
      int i8;
      int j_loop_ub;
      d__1.set_size(a__1.size(0));
      c_loop_ub = a__1.size(0);
      for (int i3{0}; i3 < c_loop_ub; i3++) {
        d__1[i3] = a__1[i3];
      }
      d_loop_ub = coder::b_combineVectorElements(d__1);
      b_this.workspace.calibration.ImagePoints.set_size(
          image_point_valid_size_idx_0, image_point_valid_size_idx_1,
          coder::b_combineVectorElements(d__1));
      for (int i5{0}; i5 < d_loop_ub; i5++) {
        for (int i9{0}; i9 < image_point_valid_size_idx_1; i9++) {
          for (int i11{0}; i11 < image_point_valid_size_idx_0; i11++) {
            b_this.workspace.calibration.ImagePoints
                [(i11 +
                  (b_this.workspace.calibration.ImagePoints.size(0) * i9)) +
                 ((b_this.workspace.calibration.ImagePoints.size(0) *
                   b_this.workspace.calibration.ImagePoints.size(1)) *
                  i5)] = 0.0;
          }
        }
      }
      i8 = images.size(3);
      for (int g_i{0}; g_i < i8; g_i++) {
        if (a__1[g_i]) {
          int h_loop_ub;
          h_loop_ub = board_points[g_i].f1.size(1);
          for (int i13{0}; i13 < h_loop_ub; i13++) {
            int i_loop_ub;
            i_loop_ub = board_points[g_i].f1.size(0);
            for (int i15{0}; i15 < i_loop_ub; i15++) {
              b_this.workspace.calibration.ImagePoints
                  [(i15 +
                    (b_this.workspace.calibration.ImagePoints.size(0) * i13)) +
                   ((b_this.workspace.calibration.ImagePoints.size(0) *
                     b_this.workspace.calibration.ImagePoints.size(1)) *
                    g_i)] = board_points[g_i]
                                .f1[i15 + (board_points[g_i].f1.size(0) * i13)];
            }
          }
        }
      }
      //  Generate world coordinates of the corners of the squares in meters
      board_size_valid[0]--;
      board_size_valid[1]--;
      board_size_valid_idx_0 = static_cast<int>(
          static_cast<double>(board_size_valid[0] * board_size_valid[1]));
      c_worldPoints.set_size(board_size_valid_idx_0, 2);
      for (int i14{0}; i14 < 2; i14++) {
        for (int i16{0}; i16 < board_size_valid_idx_0; i16++) {
          c_worldPoints[i16 + (c_worldPoints.size(0) * i14)] = 0.0;
        }
      }
      b_k = 1U;
      i17 = static_cast<int>(
          static_cast<double>((board_size_valid[1] - 1.0) + 1.0));
      for (int j{0}; j < i17; j++) {
        int i18;
        i18 = static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0));
        for (int o_i{0}; o_i < i18; o_i++) {
          int worldPoints_tmp;
          worldPoints_tmp = (static_cast<int>(static_cast<unsigned int>(
                                b_k + (static_cast<unsigned int>(o_i))))) -
                            1;
          c_worldPoints[worldPoints_tmp] =
              (static_cast<double>(j)) * squareSize;
          c_worldPoints[worldPoints_tmp + c_worldPoints.size(0)] =
              (static_cast<double>(o_i)) * squareSize;
        }
        b_k += static_cast<unsigned int>(static_cast<int>(
            static_cast<double>((board_size_valid[0] - 1.0) + 1.0)));
      }
      b_world_points.set_size(c_worldPoints.size(0), 2);
      j_loop_ub = c_worldPoints.size(0);
      for (int i19{0}; i19 < 2; i19++) {
        for (int i20{0}; i20 < j_loop_ub; i20++) {
          b_world_points[i20 + (b_world_points.size(0) * i19)] =
              c_worldPoints[i20 + (c_worldPoints.size(0) * i19)];
        }
      }
    }
  }
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  c_images[0] = static_cast<double>(static_cast<unsigned int>(images.size(0)));
  c_images[1] = static_cast<double>(static_cast<unsigned int>(images.size(1)));
  computeInitialParameterEstimate(b_world_points,
                                  b_this.workspace.calibration.ImagePoints,
                                  c_images, &initialParams, imagesUsed, &c_err);
  //  Convert Extrinsics to my way
  RotationMatrices.set_size(3, 3,
                            b_this.workspace.calibration.ImagePoints.size(2));
  e_loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (int i4{0}; i4 < e_loop_ub; i4++) {
    for (int i7{0}; i7 < 3; i7++) {
      RotationMatrices[(3 * i7) + (9 * i4)] = 0.0;
      RotationMatrices[((3 * i7) + (9 * i4)) + 1] = 0.0;
      RotationMatrices[((3 * i7) + (9 * i4)) + 2] = 0.0;
    }
  }
  i6 = b_this.workspace.calibration.ImagePoints.size(2);
  for (int e_i{0}; e_i < i6; e_i++) {
    double absxk;
    double b_t;
    double scale;
    double theta;
    scale = 3.3121686421112381E-170;
    absxk = std::abs(initialParams.RotationVectors[e_i]);
    if (absxk > 3.3121686421112381E-170) {
      theta = 1.0;
      scale = absxk;
    } else {
      b_t = absxk / 3.3121686421112381E-170;
      theta = b_t * b_t;
    }
    absxk = std::abs(
        initialParams
            .RotationVectors[e_i + initialParams.RotationVectors.size(0)]);
    if (absxk > scale) {
      b_t = scale / absxk;
      theta = ((theta * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      theta += b_t * b_t;
    }
    absxk = std::abs(
        initialParams
            .RotationVectors[e_i +
                             (initialParams.RotationVectors.size(0) * 2)]);
    if (absxk > scale) {
      b_t = scale / absxk;
      theta = ((theta * b_t) * b_t) + 1.0;
      scale = absxk;
    } else {
      b_t = absxk / scale;
      theta += b_t * b_t;
    }
    theta = scale * std::sqrt(theta);
    if (theta < 1.0E-6) {
      for (int i22{0}; i22 < 3; i22++) {
        rotationMatrix[i22][0] = 0.0;
        rotationMatrix[i22][1] = 0.0;
        rotationMatrix[i22][2] = 0.0;
      }
      rotationMatrix[0][0] = 1.0;
      rotationMatrix[1][1] = 1.0;
      rotationMatrix[2][2] = 1.0;
    } else {
      double a;
      double alpha;
      alpha = std::cos(theta);
      a = std::sin(theta);
      for (int i23{0}; i23 < 3; i23++) {
        double u_tmp;
        u_tmp =
            initialParams
                .RotationVectors[e_i + (initialParams.RotationVectors.size(0) *
                                        i23)] /
            theta;
        b_u[i23] = u_tmp;
        u[i23] = u_tmp;
        c_a[i23][0] = 0;
        c_a[i23][1] = 0;
        c_a[i23][2] = 0;
      }
      b_a[0][0] = a * 0.0;
      b_a[1][0] = a * (-u[2]);
      b_a[2][0] = a * u[1];
      b_a[0][1] = a * u[2];
      b_a[1][1] = a * 0.0;
      b_a[2][1] = a * (-u[0]);
      b_a[0][2] = a * (-u[1]);
      b_a[1][2] = a * u[0];
      b_a[2][2] = a * 0.0;
      for (int c_k{0}; c_k < 3; c_k++) {
        c_a[c_k][c_k] = 1;
        c_u[c_k][0] = b_u[0] * b_u[c_k];
        c_u[c_k][1] = b_u[1] * b_u[c_k];
        c_u[c_k][2] = b_u[2] * b_u[c_k];
      }
      for (int i29{0}; i29 < 3; i29++) {
        rotationMatrix[i29][0] =
            (((static_cast<double>(c_a[i29][0])) * alpha) + b_a[i29][0]) +
            ((1.0 - alpha) * c_u[i29][0]);
        rotationMatrix[i29][1] =
            (((static_cast<double>(c_a[i29][1])) * alpha) + b_a[i29][1]) +
            ((1.0 - alpha) * c_u[i29][1]);
        rotationMatrix[i29][2] =
            (((static_cast<double>(c_a[i29][2])) * alpha) + b_a[i29][2]) +
            ((1.0 - alpha) * c_u[i29][2]);
      }
    }
    for (int i24{0}; i24 < 3; i24++) {
      RotationMatrices[(3 * i24) + (9 * e_i)] = rotationMatrix[0][i24];
      RotationMatrices[((3 * i24) + (9 * e_i)) + 1] = rotationMatrix[1][i24];
      RotationMatrices[((3 * i24) + (9 * e_i)) + 2] = rotationMatrix[2][i24];
    }
  }
  end = imagesUsed.size(0) - 1;
  trueCount = 0;
  for (int h_i{0}; h_i <= end; h_i++) {
    if (imagesUsed[h_i]) {
      trueCount++;
    }
  }
  r.set_size(trueCount);
  partialTrueCount = 0;
  for (int k_i{0}; k_i <= end; k_i++) {
    if (imagesUsed[k_i]) {
      r[partialTrueCount] = k_i + 1;
      partialTrueCount++;
    }
  }
  b_this.workspace.calibration.PatternPositions.set_size(1, r.size(0));
  b_end = imagesUsed.size(0) - 1;
  b_trueCount = 0;
  for (int m_i{0}; m_i <= b_end; m_i++) {
    if (imagesUsed[m_i]) {
      b_trueCount++;
    }
  }
  r1.set_size(b_trueCount);
  b_partialTrueCount = 0;
  for (int p_i{0}; p_i <= b_end; p_i++) {
    if (imagesUsed[p_i]) {
      r1[b_partialTrueCount] = p_i + 1;
      b_partialTrueCount++;
    }
  }
  i21 = r1.size(0);
  for (int q_i{0}; q_i < i21; q_i++) {
    int c_end;
    int c_partialTrueCount;
    int c_trueCount;
    c_end = imagesUsed.size(0) - 1;
    c_trueCount = 0;
    for (int s_i{0}; s_i <= c_end; s_i++) {
      if (imagesUsed[s_i]) {
        c_trueCount++;
      }
    }
    r2.set_size(c_trueCount);
    c_partialTrueCount = 0;
    for (int t_i{0}; t_i <= c_end; t_i++) {
      if (imagesUsed[t_i]) {
        r2[c_partialTrueCount] = t_i + 1;
        c_partialTrueCount++;
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (int i25{0}; i25 < 4; i25++) {
      for (int i27{0}; i27 < 4; i27++) {
        b_this.workspace.calibration.PatternPositions[q_i].f1[i25][i27] = 0.0;
      }
    }
    for (int i26{0}; i26 < 3; i26++) {
      b_this.workspace.calibration.PatternPositions[q_i].f1[i26][0] =
          RotationMatrices[(3 * i26) + (9 * (r2[q_i] - 1))];
      b_this.workspace.calibration.PatternPositions[q_i].f1[i26][1] =
          RotationMatrices[((3 * i26) + (9 * (r2[q_i] - 1))) + 1];
      b_this.workspace.calibration.PatternPositions[q_i].f1[i26][2] =
          RotationMatrices[((3 * i26) + (9 * (r2[q_i] - 1))) + 2];
      b_this.workspace.calibration.PatternPositions[q_i].f1[i26][3] =
          initialParams.TranslationVectors
              [(r2[q_i] + (initialParams.TranslationVectors.size(0) * i26)) -
               1];
    }
    for (int i28{0}; i28 < 4; i28++) {
      b_this.workspace.calibration.PatternPositions[q_i].f1[3][i28] =
          static_cast<double>(b_iv[i28]);
    }
  }
  //  Crete Calibration Struct
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
  //  Optimization options: fixedK, fixedDistortions, fixedRTpnc1
  // World and Image Points
  if ((b_world_points.size(0) != 0) && (b_world_points.size(1) != 0)) {
    result = b_world_points.size(0);
  } else if (b_world_points.size(0) != 0) {
    result = b_world_points.size(0);
  } else {
    result = 0;
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = static_cast<signed char>(b_world_points.size(1));
  } else if ((b_world_points.size(0) != 0) && (b_world_points.size(1) != 0)) {
    input_sizes_idx_1 = static_cast<signed char>(b_world_points.size(1));
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 1;
  } else if (b_world_points.size(0) != 0) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  b_this.workspace.genPoints.set_size(
      result, (static_cast<int>(input_sizes_idx_1)) +
                  (static_cast<int>(b_input_sizes_idx_1)));
  k_loop_ub = static_cast<int>(input_sizes_idx_1);
  for (int i30{0}; i30 < k_loop_ub; i30++) {
    for (int i31{0}; i31 < result; i31++) {
      b_this.workspace
          .genPoints[i31 + (b_this.workspace.genPoints.size(0) * i30)] =
          b_world_points[i31 + (result * i30)];
    }
  }
  m_loop_ub = static_cast<int>(b_input_sizes_idx_1);
  for (int i32{0}; i32 < m_loop_ub; i32++) {
    for (int i33{0}; i33 < result; i33++) {
      b_this.workspace
          .genPoints[i33 + (b_this.workspace.genPoints.size(0) *
                            (static_cast<int>(input_sizes_idx_1)))] = 1.0;
    }
  }
  //  Convert initial estimate
  //  Changed for just 1 camera - 1/10/2021
  // RTcnc1 = calibration.Extrinsics;
  //  options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
  v[0] = initialParams.IntrinsicMatrix[0][0];
  v[1] = initialParams.IntrinsicMatrix[1][1];
  v[2] = initialParams.IntrinsicMatrix[0][2];
  v[3] = initialParams.IntrinsicMatrix[1][2];
  serialCalib.set_size(4);
  for (int i34{0}; i34 < 4; i34++) {
    serialCalib[i34] = v[i34];
  }
  if (initialParams.EstimateSkew) {
    int i37;
    int o_loop_ub;
    b_serialCalib.set_size(serialCalib.size(0));
    o_loop_ub = serialCalib.size(0) - 1;
    for (int i35{0}; i35 <= o_loop_ub; i35++) {
      b_serialCalib[i35] = serialCalib[i35];
    }
    serialCalib.set_size(b_serialCalib.size(0) + 1);
    i37 = b_serialCalib.size(0);
    for (int b_j{0}; b_j < i37; b_j++) {
      serialCalib[b_j] = b_serialCalib[b_j];
    }
    serialCalib[b_serialCalib.size(0)] = initialParams.IntrinsicMatrix[1][0];
  }
  if (1.0 > initialParams.NumRadialDistortionCoefficients) {
    p_loop_ub = 0;
  } else {
    p_loop_ub = static_cast<int>(initialParams.NumRadialDistortionCoefficients);
  }
  b_v.set_size(p_loop_ub);
  for (int i36{0}; i36 < p_loop_ub; i36++) {
    b_v[i36] = initialParams.RadialDistortion[i36];
  }
  if (serialCalib.size(0) == 0) {
    int r_loop_ub;
    serialCalib.set_size(b_v.size(0));
    r_loop_ub = b_v.size(0);
    for (int i39{0}; i39 < r_loop_ub; i39++) {
      serialCalib[i39] = b_v[i39];
    }
  } else {
    int q_loop_ub;
    c_serialCalib.set_size(serialCalib.size(0));
    q_loop_ub = serialCalib.size(0) - 1;
    for (int i38{0}; i38 <= q_loop_ub; i38++) {
      c_serialCalib[i38] = serialCalib[i38];
    }
    coder::b_cat(c_serialCalib, b_v, serialCalib);
  }
  if (initialParams.EstimateTangentialDistortion) {
    int s_loop_ub;
    d_serialCalib.set_size(serialCalib.size(0));
    s_loop_ub = serialCalib.size(0) - 1;
    for (int i40{0}; i40 <= s_loop_ub; i40++) {
      d_serialCalib[i40] = serialCalib[i40];
    }
    coder::c_cat(d_serialCalib, initialParams.TangentialDistortion,
                 serialCalib);
  }
  //  Extrinsics
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx;
  //  Ty; Tz];
  i41 = b_this.workspace.calibration.PatternPositions.size(1);
  for (int u_i{0}; u_i < i41; u_i++) {
    int t_loop_ub;
    for (int i42{0}; i42 < 3; i42++) {
      c_this[i42][0] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[0][i42];
      c_this[i42][1] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[1][i42];
      c_this[i42][2] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[2][i42];
    }
    coder::vision::internal::calibration::rodriguesMatrixToVector(c_this, dv1);
    t_loop_ub = serialCalib.size(0);
    if (serialCalib.size(0) == 0) {
      rvec[0] = dv1[0];
      rvec[3] = b_this.workspace.calibration.PatternPositions[u_i].f1[0][3];
      rvec[1] = dv1[1];
      rvec[4] = b_this.workspace.calibration.PatternPositions[u_i].f1[1][3];
      rvec[2] = dv1[2];
      rvec[5] = b_this.workspace.calibration.PatternPositions[u_i].f1[2][3];
      serialCalib.set_size(6);
      for (int i45{0}; i45 < 6; i45++) {
        serialCalib[i45] = rvec[i45];
      }
    } else {
      int i49;
      varargin_1.set_size(serialCalib.size(0));
      for (int i43{0}; i43 < t_loop_ub; i43++) {
        varargin_1[i43] = serialCalib[i43];
      }
      int i48;
      varargin_2[0] = dv1[0];
      varargin_2[3] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[0][3];
      varargin_2[1] = dv1[1];
      varargin_2[4] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[1][3];
      varargin_2[2] = dv1[2];
      varargin_2[5] =
          b_this.workspace.calibration.PatternPositions[u_i].f1[2][3];
      i48 = serialCalib.size(0) + 6;
      serialCalib.set_size(i48);
      i49 = varargin_1.size(0);
      for (int c_j{0}; c_j < i49; c_j++) {
        serialCalib[c_j] = varargin_1[c_j];
      }
      for (int d_j{0}; d_j < 6; d_j++) {
        serialCalib[i49 + d_j] = varargin_2[d_j];
      }
    }
  }
  //  Optimization
  b_this.workspace.calibration.CameraParameters.RadialDistortion[0] =
      initialParams.RadialDistortion[0];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[1] =
      initialParams.RadialDistortion[1];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[2] =
      initialParams.RadialDistortion[2];
  b_this.workspace.calibration.CameraParameters.TangentialDistortion[0] =
      initialParams.TangentialDistortion[0];
  b_this.workspace.calibration.CameraParameters.ImageSize[0] =
      initialParams.ImageSize[0];
  b_this.workspace.calibration.CameraParameters.TangentialDistortion[1] =
      initialParams.TangentialDistortion[1];
  b_this.workspace.calibration.CameraParameters.ImageSize[1] =
      initialParams.ImageSize[1];
  b_this.workspace.calibration.CameraParameters.WorldPoints.set_size(
      initialParams.WorldPoints.size(0), initialParams.WorldPoints.size(1));
  u_loop_ub = initialParams.WorldPoints.size(1);
  for (int i44{0}; i44 < u_loop_ub; i44++) {
    int v_loop_ub;
    v_loop_ub = initialParams.WorldPoints.size(0);
    for (int i46{0}; i46 < v_loop_ub; i46++) {
      b_this.workspace.calibration.CameraParameters
          .WorldPoints[i46 + (b_this.workspace.calibration.CameraParameters
                                  .WorldPoints.size(0) *
                              i44)] =
          initialParams
              .WorldPoints[i46 + (initialParams.WorldPoints.size(0) * i44)];
    }
  }
  b_this.workspace.calibration.CameraParameters.WorldUnits.set_size(
      1, initialParams.WorldUnits.size(1));
  w_loop_ub = initialParams.WorldUnits.size(1);
  for (int i47{0}; i47 < w_loop_ub; i47++) {
    b_this.workspace.calibration.CameraParameters.WorldUnits[i47] =
        initialParams.WorldUnits[i47];
  }
  b_this.workspace.calibration.CameraParameters.EstimateSkew =
      initialParams.EstimateSkew;
  b_this.workspace.calibration.CameraParameters
      .NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  b_this.workspace.calibration.CameraParameters.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  b_this.workspace.calibration.CameraParameters.RotationVectors.set_size(
      initialParams.RotationVectors.size(0), 3);
  b_this.workspace.calibration.CameraParameters.TranslationVectors.set_size(
      initialParams.TranslationVectors.size(0), 3);
  x_loop_ub = initialParams.RotationVectors.size(0);
  y_loop_ub = initialParams.TranslationVectors.size(0);
  for (int i50{0}; i50 < 3; i50++) {
    for (int i51{0}; i51 < x_loop_ub; i51++) {
      b_this.workspace.calibration.CameraParameters
          .RotationVectors[i51 + (b_this.workspace.calibration.CameraParameters
                                      .RotationVectors.size(0) *
                                  i50)] =
          initialParams
              .RotationVectors[i51 +
                               (initialParams.RotationVectors.size(0) * i50)];
    }
    for (int i53{0}; i53 < y_loop_ub; i53++) {
      b_this.workspace.calibration.CameraParameters
          .TranslationVectors[i53 +
                              (b_this.workspace.calibration.CameraParameters
                                   .TranslationVectors.size(0) *
                               i50)] =
          initialParams.TranslationVectors
              [i53 + (initialParams.TranslationVectors.size(0) * i50)];
    }
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[i50][0] =
        initialParams.IntrinsicMatrix[i50][0];
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[i50][1] =
        initialParams.IntrinsicMatrix[i50][1];
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[i50][2] =
        initialParams.IntrinsicMatrix[i50][2];
  }
  b_this.workspace.detPoints.set_size(
      b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  ab_loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (int i52{0}; i52 < ab_loop_ub; i52++) {
    int bb_loop_ub;
    bb_loop_ub = b_this.workspace.calibration.ImagePoints.size(1);
    for (int i54{0}; i54 < bb_loop_ub; i54++) {
      int cb_loop_ub;
      cb_loop_ub = b_this.workspace.calibration.ImagePoints.size(0);
      for (int i55{0}; i55 < cb_loop_ub; i55++) {
        b_this.workspace
            .detPoints[(i55 + (b_this.workspace.detPoints.size(0) * i54)) +
                       ((b_this.workspace.detPoints.size(0) *
                         b_this.workspace.detPoints.size(1)) *
                        i52)] =
            b_this.workspace.calibration.ImagePoints
                [(i55 +
                  (b_this.workspace.calibration.ImagePoints.size(0) * i54)) +
                 ((b_this.workspace.calibration.ImagePoints.size(0) *
                   b_this.workspace.calibration.ImagePoints.size(1)) *
                  i52)];
      }
    }
  }
  coder::lsqnonlin(&b_this, serialCalib, &a__2, residual, &a__3, &expl_temp,
                   &b_expl_temp, &c_expl_temp, &d_expl_temp, e_expl_temp,
                   f_expl_temp, g_expl_temp, jacobian);
  // serialCI = my_nlparci(optimizedSerialCalib,residual,jacobian);
  // CI = cell(1,2);
  // CI{1} = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI{2} = unserializeCalib(serialCI(:,2)', options, calibration);
  CalculateCost(serialCalib, initialParams.ImageSize,
                b_this.workspace.calibration.PatternPositions,
                b_this.workspace.genPoints,
                b_this.workspace.calibration.ImagePoints, errorOptimized);
  tmp.set_size(errorOptimized.size(0));
  db_loop_ub = errorOptimized.size(0);
  for (int i56{0}; i56 < db_loop_ub; i56++) {
    tmp[i56] = errorOptimized[i56];
  }
  d_end = errorOptimized.size(0);
  for (int v_i{0}; v_i < d_end; v_i++) {
    if (errorOptimized[v_i] < 1.0E-6) {
      tmp[v_i] = rtNaN;
    }
  }
  double b_calculation_err;
  b_calculation_err = coder::nanmean(tmp);
  // disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);
  unserializeCalib(serialCalib, initialParams.ImageSize,
                   b_this.workspace.calibration.PatternPositions,
                   b_cameraParameters, a__6);
  *calculation_err = b_calculation_err;
  *err = c_err;
}

//
// File trailer for calibrateOneCamera.cpp
//
// [EOF]
//
