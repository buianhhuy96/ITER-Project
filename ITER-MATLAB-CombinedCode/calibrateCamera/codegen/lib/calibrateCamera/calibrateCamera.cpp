//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateCamera.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "calibrateCamera.h"
#include "CalculateCost.h"
#include "anonymous_function1.h"
#include "calibrateCamera_data.h"
#include "calibrateCamera_initialize.h"
#include "calibrateCamera_internal_types11.h"
#include "calibrateCamera_types.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "isequal.h"
#include "lsqnonlin.h"
#include "my_nlparci.h"
#include "rodriguesMatrixToVector.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <algorithm>

// Type Definitions
namespace Codegen {
struct cell_wrap_8 {
  ::coder::array<real_T, 2U> f1;
};

} // namespace Codegen

// Function Definitions
//
// Initalize error flag
//
// Arguments    : const ::coder::array<uint8_T, 4U> &images
//                real_T squareSize
//                const real_T boardSize[2]
//                struct0_T *calibrationOptimized
//                coder::rtString *err
// Return Type  : void
//
namespace Codegen {
void calibrateCamera(const ::coder::array<uint8_T, 4U> &images,
                     real_T squareSize, const real_T boardSize[2],
                     struct0_T *calibrationOptimized, coder::rtString *err)
{
  coder::anonymous_function b_this;
  ::coder::array<cell_wrap_8, 1U> board_points;
  ::coder::array<real_T, 2U> b_world_points;
  ::coder::array<real_T, 2U> c_world_points;
  ::coder::array<real_T, 2U> current_board_points;
  ::coder::array<real_T, 2U> result;
  ::coder::array<real_T, 1U> c_f1;
  ::coder::array<real_T, 1U> f1;
  ::coder::array<real_T, 1U> f_expl_temp;
  ::coder::array<real_T, 1U> g_expl_temp;
  ::coder::array<real_T, 1U> serialCalib;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<uint8_T, 2U> b_images;
  ::coder::array<boolean_T, 1U> b_x;
  ::coder::array<boolean_T, 1U> valid_idx;
  struct1_T h_expl_temp;
  struct1_T i_expl_temp;
  struct1_T initialParams;
  struct1_T j_expl_temp;
  struct1_T k_expl_temp;
  real_T c_this[3][3];
  real_T y_data[7];
  real_T t3_f2[6];
  real_T dv[3];
  real_T b_boardSize[2];
  real_T a__1;
  real_T a__2;
  real_T b_expl_temp;
  real_T c_expl_temp;
  real_T d_expl_temp;
  real_T expl_temp;
  int32_T b_i;
  int32_T d_i;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T loop_ub;
  int32_T vlen;
  uint32_T k;
  char_T e_expl_temp[19];
  int8_T input_sizes_idx_1;
  int8_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  boolean_T exitg1;
  if (!isInitialized_calibrateCamera) {
    calibrateCamera_initialize();
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
  //  ITER API ALGORITHM IMPLEMENTATION STARTS HERE
  //  Calibrate One Camera
  //  Generate world coordinates of the checkerboard keypoints
  b_boardSize[0] = boardSize[0] - 1.0;
  vlen = static_cast<int32_T>(
      static_cast<real_T>((boardSize[0] - 1.0) * (boardSize[1] - 1.0)));
  b_world_points.set_size(vlen, 2);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < vlen; i1++) {
      b_world_points[i1 + (b_world_points.size(0) * b_i)] = 0.0;
    }
  }
  k = 1U;
  b_i = static_cast<int32_T>(
      static_cast<real_T>(((boardSize[1] - 1.0) - 1.0) + 1.0));
  for (j = 0; j < b_i; j++) {
    i1 =
        static_cast<int32_T>(static_cast<real_T>((b_boardSize[0] - 1.0) + 1.0));
    for (d_i = 0; d_i < i1; d_i++) {
      vlen = (static_cast<int32_T>(
                 static_cast<uint32_T>(k + (static_cast<uint32_T>(d_i))))) -
             1;
      b_world_points[vlen] = (static_cast<real_T>(j)) * squareSize;
      b_world_points[vlen + b_world_points.size(0)] =
          (static_cast<real_T>(d_i)) * squareSize;
    }
    k += static_cast<uint32_T>(static_cast<int32_T>(
        static_cast<real_T>((b_boardSize[0] - 1.0) + 1.0)));
  }
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  // [ImagePoints, boardSizeDetected ] = detectCheckerboardPoints(images,
  // 'PartialDetections', false); % detect checkerboard for every position of
  // camera i flag = false; if (flag)
  //    load("detectCheckerboard_workspace.mat");
  // else
  valid_idx.set_size(images.size(3));
  b_i = images.size(3);
  board_points.set_size(images.size(3));
  for (d_i = 0; d_i < b_i; d_i++) {
    //  perform checkerboards detection in each image
    loop_ub = images.size(0);
    j = images.size(1);
    b_images.set_size(images.size(0), images.size(1));
    for (i1 = 0; i1 < j; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_images[i2 + (b_images.size(0) * i1)] =
            images[(i2 + (images.size(0) * i1)) +
                   ((images.size(0) * images.size(1)) * d_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, current_board_points,
                                    b_boardSize);
    //  mark if checkerboards is detected or not
    if (!coder::isequal(boardSize, b_boardSize)) {
      valid_idx[d_i] = false;
    } else if ((current_board_points.size(0) == 0) ||
               (current_board_points.size(1) == 0)) {
      valid_idx[d_i] = false;
    } else {
      valid_idx[d_i] = true;
    }
    loop_ub = current_board_points.size(1);
    board_points[d_i].f1.set_size(current_board_points.size(0),
                                  current_board_points.size(1));
    for (i1 = 0; i1 < loop_ub; i1++) {
      j = current_board_points.size(0);
      for (i2 = 0; i2 < j; i2++) {
        board_points[d_i].f1[i2 + (board_points[d_i].f1.size(0) * i1)] =
            current_board_points[i2 + (current_board_points.size(0) * i1)];
      }
    }
  }
  empty_non_axis_sizes = true;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j <= (valid_idx.size(0) - 1))) {
    if (!valid_idx[j]) {
      empty_non_axis_sizes = false;
      exitg1 = true;
    } else {
      j++;
    }
  }
  if (!empty_non_axis_sizes) {
    b_this.workspace.calibration.ImagePoints.set_size(0, 0, 1);
  } else {
    int32_T nz;
    b_x.set_size(valid_idx.size(0));
    loop_ub = valid_idx.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_x[b_i] = valid_idx[b_i];
    }
    vlen = b_x.size(0);
    if (b_x.size(0) == 0) {
      nz = 0;
    } else {
      nz = static_cast<int32_T>(b_x[0]);
      for (j = 2; j <= vlen; j++) {
        if (vlen >= 2) {
          nz += static_cast<int32_T>(b_x[j - 1]);
        }
      }
    }
    loop_ub = board_points[0].f1.size(0);
    j = board_points[0].f1.size(1);
    b_this.workspace.calibration.ImagePoints.set_size(
        board_points[0].f1.size(0), board_points[0].f1.size(1), nz);
    for (b_i = 0; b_i < nz; b_i++) {
      for (i1 = 0; i1 < j; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_this.workspace.calibration.ImagePoints
              [(i2 + (b_this.workspace.calibration.ImagePoints.size(0) * i1)) +
               ((b_this.workspace.calibration.ImagePoints.size(0) *
                 b_this.workspace.calibration.ImagePoints.size(1)) *
                b_i)] = 0.0;
        }
      }
    }
    for (d_i = 0; d_i < nz; d_i++) {
      if (valid_idx[d_i]) {
        loop_ub = board_points[d_i].f1.size(1);
        for (b_i = 0; b_i < loop_ub; b_i++) {
          j = board_points[d_i].f1.size(0);
          for (i1 = 0; i1 < j; i1++) {
            b_this.workspace.calibration.ImagePoints
                [(i1 +
                  (b_this.workspace.calibration.ImagePoints.size(0) * b_i)) +
                 ((b_this.workspace.calibration.ImagePoints.size(0) *
                   b_this.workspace.calibration.ImagePoints.size(1)) *
                  d_i)] =
                board_points[d_i].f1[i1 + (board_points[d_i].f1.size(0) * b_i)];
          }
        }
      }
    }
  }
  // end
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  computeInitialParameterEstimate(b_world_points,
                                  b_this.workspace.calibration.ImagePoints,
                                  &initialParams, valid_idx, err);
  //  Convert Extrinsics to my way
  j = valid_idx.size(0) - 1;
  vlen = 0;
  for (d_i = 0; d_i <= j; d_i++) {
    if (valid_idx[d_i]) {
      vlen++;
    }
  }
  r.set_size(vlen);
  vlen = 0;
  for (d_i = 0; d_i <= j; d_i++) {
    if (valid_idx[d_i]) {
      r[vlen] = d_i + 1;
      vlen++;
    }
  }
  b_this.workspace.calibration.PatternPositions.set_size(1, r.size(0));
  j = valid_idx.size(0) - 1;
  vlen = 0;
  for (d_i = 0; d_i <= j; d_i++) {
    if (valid_idx[d_i]) {
      vlen++;
    }
  }
  r1.set_size(vlen);
  vlen = 0;
  for (d_i = 0; d_i <= j; d_i++) {
    if (valid_idx[d_i]) {
      r1[vlen] = d_i + 1;
      vlen++;
    }
  }
  b_i = r1.size(0);
  for (d_i = 0; d_i < b_i; d_i++) {
    j = valid_idx.size(0) - 1;
    vlen = 0;
    for (loop_ub = 0; loop_ub <= j; loop_ub++) {
      if (valid_idx[loop_ub]) {
        vlen++;
      }
    }
    r2.set_size(vlen);
    vlen = 0;
    for (loop_ub = 0; loop_ub <= j; loop_ub++) {
      if (valid_idx[loop_ub]) {
        r2[vlen] = loop_ub + 1;
        vlen++;
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (i1 = 0; i1 < 4; i1++) {
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][0] = 0.0;
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][1] = 0.0;
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][2] = 0.0;
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][3] = 0.0;
    }
    for (i1 = 0; i1 < 3; i1++) {
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][0] =
          initialParams
              .RotationMatrices[(initialParams.RotationMatrices.size(0) * i1) +
                                ((initialParams.RotationMatrices.size(0) *
                                  initialParams.RotationMatrices.size(1)) *
                                 (r2[d_i] - 1))];
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][1] =
          initialParams
              .RotationMatrices[((initialParams.RotationMatrices.size(0) * i1) +
                                 ((initialParams.RotationMatrices.size(0) *
                                   initialParams.RotationMatrices.size(1)) *
                                  (r2[d_i] - 1))) +
                                1];
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][2] =
          initialParams
              .RotationMatrices[((initialParams.RotationMatrices.size(0) * i1) +
                                 ((initialParams.RotationMatrices.size(0) *
                                   initialParams.RotationMatrices.size(1)) *
                                  (r2[d_i] - 1))) +
                                2];
      b_this.workspace.calibration.PatternPositions[d_i].f1[i1][3] =
          initialParams.TranslationVectors
              [(r2[d_i] + (initialParams.TranslationVectors.size(0) * i1)) - 1];
    }
    b_this.workspace.calibration.PatternPositions[d_i].f1[3][0] = 0.0;
    b_this.workspace.calibration.PatternPositions[d_i].f1[3][1] = 0.0;
    b_this.workspace.calibration.PatternPositions[d_i].f1[3][2] = 0.0;
    b_this.workspace.calibration.PatternPositions[d_i].f1[3][3] = 1.0;
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
  if (b_world_points.size(0) != 0) {
    vlen = b_world_points.size(0);
  } else {
    vlen = 0;
  }
  empty_non_axis_sizes = (vlen == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = 2;
  } else if (b_world_points.size(0) != 0) {
    input_sizes_idx_1 = 2;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else if (b_world_points.size(0) != 0) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  result.set_size(vlen, (static_cast<int32_T>(input_sizes_idx_1)) +
                            (static_cast<int32_T>(sizes_idx_1)));
  loop_ub = static_cast<int32_T>(input_sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < vlen; i1++) {
      result[i1 + (result.size(0) * b_i)] = b_world_points[i1 + (vlen * b_i)];
    }
  }
  loop_ub = static_cast<int32_T>(sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < vlen; i1++) {
      result[i1 + (result.size(0) *
                   (static_cast<int32_T>(input_sizes_idx_1)))] = 1.0;
    }
  }
  //  Convert initial estimate
  //  Changed for just 1 camera - 1/10/2021
  // RTcnc1 = calibration.Extrinsics;
  //  options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
  f1.set_size(4);
  f1[0] = initialParams.IntrinsicMatrix[0][0];
  f1[1] = initialParams.IntrinsicMatrix[1][1];
  f1[2] = initialParams.IntrinsicMatrix[0][2];
  f1[3] = initialParams.IntrinsicMatrix[1][2];
  c_f1.set_size(3);
  c_f1[0] = initialParams.RadialDistortion[0];
  c_f1[1] = initialParams.RadialDistortion[1];
  c_f1[2] = initialParams.RadialDistortion[2];
  y_data[0] = f1[0];
  y_data[1] = f1[1];
  y_data[2] = f1[2];
  y_data[3] = f1[3];
  y_data[4] = c_f1[0];
  y_data[5] = c_f1[1];
  y_data[6] = c_f1[2];
  serialCalib.set_size(7);
  for (b_i = 0; b_i < 7; b_i++) {
    serialCalib[b_i] = y_data[b_i];
  }
  //  Extrinsics
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx;
  //  Ty; Tz];
  b_i = b_this.workspace.calibration.PatternPositions.size(1);
  for (d_i = 0; d_i < b_i; d_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      c_this[i1][0] =
          b_this.workspace.calibration.PatternPositions[d_i].f1[0][i1];
      c_this[i1][1] =
          b_this.workspace.calibration.PatternPositions[d_i].f1[1][i1];
      c_this[i1][2] =
          b_this.workspace.calibration.PatternPositions[d_i].f1[2][i1];
    }
    coder::vision::internal::calibration::rodriguesMatrixToVector(c_this, dv);
    loop_ub = serialCalib.size(0);
    calibrationOptimized->b_Error.set_size(serialCalib.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      calibrationOptimized->b_Error[i1] = serialCalib[i1];
    }
    t3_f2[0] = dv[0];
    t3_f2[3] = b_this.workspace.calibration.PatternPositions[d_i].f1[0][3];
    t3_f2[1] = dv[1];
    t3_f2[4] = b_this.workspace.calibration.PatternPositions[d_i].f1[1][3];
    t3_f2[2] = dv[2];
    t3_f2[5] = b_this.workspace.calibration.PatternPositions[d_i].f1[2][3];
    i1 = serialCalib.size(0) + 6;
    serialCalib.set_size(i1);
    i1 = calibrationOptimized->b_Error.size(0);
    for (j = 0; j < i1; j++) {
      serialCalib[j] = calibrationOptimized->b_Error[j];
    }
    for (j = 0; j < 6; j++) {
      serialCalib[i1 + j] = t3_f2[j];
    }
  }
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration); disp (['Mean Reprojection Error - Before Optimization: ',
  // num2str(MREi)]);
  //  Optimization
  // h = waitbar(0, 'Running global Optimization...','Name', 'Global
  // Optimization'); [optimizedSerialCalib,~,residual,~,~,~,jacobian] = ...
  //     lsqnonlin(@(x) CalculateCost(x, options, calibration, genPoints,
  //     detPoints),serialCalib, [],[]);
  b_this.workspace.calibration.CameraParameters.RadialDistortion[0] =
      initialParams.RadialDistortion[0];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[1] =
      initialParams.RadialDistortion[1];
  b_this.workspace.calibration.CameraParameters.RadialDistortion[2] =
      initialParams.RadialDistortion[2];
  b_this.workspace.calibration.CameraParameters.WorldPoints.set_size(
      initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    b_this.workspace.calibration.CameraParameters.TangentialDistortion[b_i] =
        initialParams.TangentialDistortion[b_i];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this.workspace.calibration.CameraParameters
          .WorldPoints[i1 + (b_this.workspace.calibration.CameraParameters
                                 .WorldPoints.size(0) *
                             b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
  }
  b_this.workspace.calibration.CameraParameters.WorldUnits.size[0] = 1;
  b_this.workspace.calibration.CameraParameters.WorldUnits.size[1] =
      initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= (loop_ub - 1)) {
    (void)std::copy(
        &initialParams.WorldUnits.data[0],
        &initialParams.WorldUnits.data[loop_ub],
        &b_this.workspace.calibration.CameraParameters.WorldUnits.data[0]);
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
  loop_ub = initialParams.RotationVectors.size(0);
  j = initialParams.TranslationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this.workspace.calibration.CameraParameters
          .RotationVectors[i1 + (b_this.workspace.calibration.CameraParameters
                                     .RotationVectors.size(0) *
                                 b_i)] =
          initialParams
              .RotationVectors[i1 +
                               (initialParams.RotationVectors.size(0) * b_i)];
    }
    for (i1 = 0; i1 < j; i1++) {
      b_this.workspace.calibration.CameraParameters
          .TranslationVectors[i1 +
                              (b_this.workspace.calibration.CameraParameters
                                   .TranslationVectors.size(0) *
                               b_i)] =
          initialParams.TranslationVectors
              [i1 + (initialParams.TranslationVectors.size(0) * b_i)];
    }
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[b_i][0] =
        initialParams.IntrinsicMatrix[b_i][0];
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[b_i][1] =
        initialParams.IntrinsicMatrix[b_i][1];
    b_this.workspace.calibration.CameraParameters.IntrinsicMatrix[b_i][2] =
        initialParams.IntrinsicMatrix[b_i][2];
  }
  b_this.workspace.calibration.CameraParameters.NumPatterns.size[0] =
      initialParams.NumPatterns.size[0];
  b_this.workspace.calibration.CameraParameters.NumPatterns.size[1] =
      initialParams.NumPatterns.size[1];
  loop_ub = initialParams.NumPatterns.size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.NumPatterns.size[0];
    for (i1 = 0; i1 < j; i1++) {
      b_this.workspace.calibration.CameraParameters.NumPatterns.data[0] =
          initialParams.NumPatterns.data[0];
    }
  }
  b_this.workspace.calibration.CameraParameters.FocalLength[0] =
      initialParams.FocalLength[0];
  b_this.workspace.calibration.CameraParameters.PrincipalPoint[0] =
      initialParams.PrincipalPoint[0];
  b_this.workspace.calibration.CameraParameters.FocalLength[1] =
      initialParams.FocalLength[1];
  b_this.workspace.calibration.CameraParameters.PrincipalPoint[1] =
      initialParams.PrincipalPoint[1];
  b_this.workspace.calibration.CameraParameters.Skew = initialParams.Skew;
  b_this.workspace.calibration.CameraParameters.RotationMatrices.set_size(
      initialParams.RotationMatrices.size(0),
      initialParams.RotationMatrices.size(1),
      initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.RotationMatrices.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = initialParams.RotationMatrices.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        b_this.workspace.calibration.CameraParameters
            .RotationMatrices[(i2 +
                               (b_this.workspace.calibration.CameraParameters
                                    .RotationMatrices.size(0) *
                                i1)) +
                              ((b_this.workspace.calibration.CameraParameters
                                    .RotationMatrices.size(0) *
                                b_this.workspace.calibration.CameraParameters
                                    .RotationMatrices.size(1)) *
                               b_i)] =
            initialParams.RotationMatrices
                [(i2 + (initialParams.RotationMatrices.size(0) * i1)) +
                 ((initialParams.RotationMatrices.size(0) *
                   initialParams.RotationMatrices.size(1)) *
                  b_i)];
      }
    }
  }
  b_this.workspace.calibration.CameraParameters.MeanReprojectionError =
      initialParams.MeanReprojectionError;
  b_this.workspace.genPoints.set_size(result.size(0), result.size(1));
  loop_ub = result.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = result.size(0);
    for (i1 = 0; i1 < j; i1++) {
      b_this.workspace
          .genPoints[i1 + (b_this.workspace.genPoints.size(0) * b_i)] =
          result[i1 + (result.size(0) * b_i)];
    }
  }
  b_this.workspace.detPoints.set_size(
      b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = b_this.workspace.calibration.ImagePoints.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = b_this.workspace.calibration.ImagePoints.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        b_this.workspace
            .detPoints[(i2 + (b_this.workspace.detPoints.size(0) * i1)) +
                       ((b_this.workspace.detPoints.size(0) *
                         b_this.workspace.detPoints.size(1)) *
                        b_i)] =
            b_this.workspace.calibration.ImagePoints
                [(i2 +
                  (b_this.workspace.calibration.ImagePoints.size(0) * i1)) +
                 ((b_this.workspace.calibration.ImagePoints.size(0) *
                   b_this.workspace.calibration.ImagePoints.size(1)) *
                  b_i)];
      }
    }
  }
  coder::lsqnonlin(&b_this, serialCalib, &a__1, calibrationOptimized->b_Error,
                   &a__2, &expl_temp, &b_expl_temp, &c_expl_temp, &d_expl_temp,
                   e_expl_temp, f_expl_temp, g_expl_temp,
                   calibrationOptimized->Jacobian);
  // delete(h);
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  f_expl_temp.set_size(calibrationOptimized->b_Error.size(0));
  loop_ub = calibrationOptimized->b_Error.size(0) - 1;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    f_expl_temp[b_i] = calibrationOptimized->b_Error[b_i];
  }
  my_nlparci(serialCalib, f_expl_temp, calibrationOptimized->Jacobian,
             b_world_points);
  h_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  h_expl_temp.RotationMatrices.set_size(initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.RotationMatrices.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = initialParams.RotationMatrices.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        h_expl_temp
            .RotationMatrices[(i2 +
                               (h_expl_temp.RotationMatrices.size(0) * i1)) +
                              ((h_expl_temp.RotationMatrices.size(0) *
                                h_expl_temp.RotationMatrices.size(1)) *
                               b_i)] =
            initialParams.RotationMatrices
                [(i2 + (initialParams.RotationMatrices.size(0) * i1)) +
                 ((initialParams.RotationMatrices.size(0) *
                   initialParams.RotationMatrices.size(1)) *
                  b_i)];
      }
    }
  }
  h_expl_temp.Skew = initialParams.Skew;
  h_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  h_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  h_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  h_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  h_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  h_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  loop_ub = initialParams.NumPatterns.size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.NumPatterns.size[0];
    for (i1 = 0; i1 < j; i1++) {
      h_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
    }
  }
  h_expl_temp.TranslationVectors.set_size(
      initialParams.TranslationVectors.size(0), 3);
  h_expl_temp.RotationVectors.set_size(initialParams.RotationVectors.size(0),
                                       3);
  loop_ub = initialParams.TranslationVectors.size(0);
  j = initialParams.RotationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    h_expl_temp.IntrinsicMatrix[b_i][0] = initialParams.IntrinsicMatrix[b_i][0];
    h_expl_temp.IntrinsicMatrix[b_i][1] = initialParams.IntrinsicMatrix[b_i][1];
    h_expl_temp.IntrinsicMatrix[b_i][2] = initialParams.IntrinsicMatrix[b_i][2];
    for (i1 = 0; i1 < loop_ub; i1++) {
      h_expl_temp
          .TranslationVectors[i1 +
                              (h_expl_temp.TranslationVectors.size(0) * b_i)] =
          initialParams.TranslationVectors
              [i1 + (initialParams.TranslationVectors.size(0) * b_i)];
    }
    for (i1 = 0; i1 < j; i1++) {
      h_expl_temp
          .RotationVectors[i1 + (h_expl_temp.RotationVectors.size(0) * b_i)] =
          initialParams
              .RotationVectors[i1 +
                               (initialParams.RotationVectors.size(0) * b_i)];
    }
  }
  h_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  h_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  h_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  h_expl_temp.WorldUnits.size[0] = 1;
  h_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= (loop_ub - 1)) {
    (void)std::copy(&initialParams.WorldUnits.data[0],
                    &initialParams.WorldUnits.data[loop_ub],
                    &h_expl_temp.WorldUnits.data[0]);
  }
  h_expl_temp.WorldPoints.set_size(initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      h_expl_temp.WorldPoints[i1 + (h_expl_temp.WorldPoints.size(0) * b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
    h_expl_temp.TangentialDistortion[b_i] =
        initialParams.TangentialDistortion[b_i];
  }
  h_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  h_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  h_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  loop_ub = b_world_points.size(0);
  c_world_points.set_size(1, b_world_points.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_world_points[b_i] = b_world_points[b_i];
  }
  b_unserializeCalib(c_world_points, &h_expl_temp,
                     b_this.workspace.calibration.PatternPositions,
                     b_this.workspace.calibration.ImagePoints,
                     &calibrationOptimized->CI[0].CameraParameters,
                     calibrationOptimized->CI[0].PatternPositions,
                     calibrationOptimized->CI[0].ImagePoints);
  i_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  i_expl_temp.RotationMatrices.set_size(initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.RotationMatrices.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = initialParams.RotationMatrices.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        i_expl_temp
            .RotationMatrices[(i2 +
                               (i_expl_temp.RotationMatrices.size(0) * i1)) +
                              ((i_expl_temp.RotationMatrices.size(0) *
                                i_expl_temp.RotationMatrices.size(1)) *
                               b_i)] =
            initialParams.RotationMatrices
                [(i2 + (initialParams.RotationMatrices.size(0) * i1)) +
                 ((initialParams.RotationMatrices.size(0) *
                   initialParams.RotationMatrices.size(1)) *
                  b_i)];
      }
    }
  }
  i_expl_temp.Skew = initialParams.Skew;
  i_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  i_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  i_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  i_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  i_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  i_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  loop_ub = initialParams.NumPatterns.size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.NumPatterns.size[0];
    for (i1 = 0; i1 < j; i1++) {
      i_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
    }
  }
  i_expl_temp.TranslationVectors.set_size(
      initialParams.TranslationVectors.size(0), 3);
  i_expl_temp.RotationVectors.set_size(initialParams.RotationVectors.size(0),
                                       3);
  loop_ub = initialParams.TranslationVectors.size(0);
  j = initialParams.RotationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    i_expl_temp.IntrinsicMatrix[b_i][0] = initialParams.IntrinsicMatrix[b_i][0];
    i_expl_temp.IntrinsicMatrix[b_i][1] = initialParams.IntrinsicMatrix[b_i][1];
    i_expl_temp.IntrinsicMatrix[b_i][2] = initialParams.IntrinsicMatrix[b_i][2];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i_expl_temp
          .TranslationVectors[i1 +
                              (i_expl_temp.TranslationVectors.size(0) * b_i)] =
          initialParams.TranslationVectors
              [i1 + (initialParams.TranslationVectors.size(0) * b_i)];
    }
    for (i1 = 0; i1 < j; i1++) {
      i_expl_temp
          .RotationVectors[i1 + (i_expl_temp.RotationVectors.size(0) * b_i)] =
          initialParams
              .RotationVectors[i1 +
                               (initialParams.RotationVectors.size(0) * b_i)];
    }
  }
  i_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  i_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  i_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  i_expl_temp.WorldUnits.size[0] = 1;
  i_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= (loop_ub - 1)) {
    (void)std::copy(&initialParams.WorldUnits.data[0],
                    &initialParams.WorldUnits.data[loop_ub],
                    &i_expl_temp.WorldUnits.data[0]);
  }
  i_expl_temp.WorldPoints.set_size(initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      i_expl_temp.WorldPoints[i1 + (i_expl_temp.WorldPoints.size(0) * b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
    i_expl_temp.TangentialDistortion[b_i] =
        initialParams.TangentialDistortion[b_i];
  }
  i_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  i_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  i_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  loop_ub = b_world_points.size(0);
  c_world_points.set_size(1, b_world_points.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_world_points[b_i] = b_world_points[b_i + b_world_points.size(0)];
  }
  b_unserializeCalib(c_world_points, &i_expl_temp,
                     b_this.workspace.calibration.PatternPositions,
                     b_this.workspace.calibration.ImagePoints,
                     &calibrationOptimized->CI[1].CameraParameters,
                     calibrationOptimized->CI[1].PatternPositions,
                     calibrationOptimized->CI[1].ImagePoints);
  j_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  j_expl_temp.RotationMatrices.set_size(initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.RotationMatrices.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = initialParams.RotationMatrices.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        j_expl_temp
            .RotationMatrices[(i2 +
                               (j_expl_temp.RotationMatrices.size(0) * i1)) +
                              ((j_expl_temp.RotationMatrices.size(0) *
                                j_expl_temp.RotationMatrices.size(1)) *
                               b_i)] =
            initialParams.RotationMatrices
                [(i2 + (initialParams.RotationMatrices.size(0) * i1)) +
                 ((initialParams.RotationMatrices.size(0) *
                   initialParams.RotationMatrices.size(1)) *
                  b_i)];
      }
    }
  }
  j_expl_temp.Skew = initialParams.Skew;
  j_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  j_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  j_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  j_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  j_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  j_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  loop_ub = initialParams.NumPatterns.size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.NumPatterns.size[0];
    for (i1 = 0; i1 < j; i1++) {
      j_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
    }
  }
  j_expl_temp.TranslationVectors.set_size(
      initialParams.TranslationVectors.size(0), 3);
  j_expl_temp.RotationVectors.set_size(initialParams.RotationVectors.size(0),
                                       3);
  loop_ub = initialParams.TranslationVectors.size(0);
  j = initialParams.RotationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    j_expl_temp.IntrinsicMatrix[b_i][0] = initialParams.IntrinsicMatrix[b_i][0];
    j_expl_temp.IntrinsicMatrix[b_i][1] = initialParams.IntrinsicMatrix[b_i][1];
    j_expl_temp.IntrinsicMatrix[b_i][2] = initialParams.IntrinsicMatrix[b_i][2];
    for (i1 = 0; i1 < loop_ub; i1++) {
      j_expl_temp
          .TranslationVectors[i1 +
                              (j_expl_temp.TranslationVectors.size(0) * b_i)] =
          initialParams.TranslationVectors
              [i1 + (initialParams.TranslationVectors.size(0) * b_i)];
    }
    for (i1 = 0; i1 < j; i1++) {
      j_expl_temp
          .RotationVectors[i1 + (j_expl_temp.RotationVectors.size(0) * b_i)] =
          initialParams
              .RotationVectors[i1 +
                               (initialParams.RotationVectors.size(0) * b_i)];
    }
  }
  j_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  j_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  j_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  j_expl_temp.WorldUnits.size[0] = 1;
  j_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= (loop_ub - 1)) {
    (void)std::copy(&initialParams.WorldUnits.data[0],
                    &initialParams.WorldUnits.data[loop_ub],
                    &j_expl_temp.WorldUnits.data[0]);
  }
  j_expl_temp.WorldPoints.set_size(initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      j_expl_temp.WorldPoints[i1 + (j_expl_temp.WorldPoints.size(0) * b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
    j_expl_temp.TangentialDistortion[b_i] =
        initialParams.TangentialDistortion[b_i];
  }
  j_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  j_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  j_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  CalculateCost(
      serialCalib, &j_expl_temp, b_this.workspace.calibration.PatternPositions,
      b_this.workspace.calibration.ImagePoints, result,
      b_this.workspace.calibration.ImagePoints, calibrationOptimized->b_Error);
  // disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);
  k_expl_temp.MeanReprojectionError = initialParams.MeanReprojectionError;
  k_expl_temp.RotationMatrices.set_size(initialParams.RotationMatrices.size(0),
                                        initialParams.RotationMatrices.size(1),
                                        initialParams.RotationMatrices.size(2));
  loop_ub = initialParams.RotationMatrices.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.RotationMatrices.size(1);
    for (i1 = 0; i1 < j; i1++) {
      vlen = initialParams.RotationMatrices.size(0);
      for (i2 = 0; i2 < vlen; i2++) {
        k_expl_temp
            .RotationMatrices[(i2 +
                               (k_expl_temp.RotationMatrices.size(0) * i1)) +
                              ((k_expl_temp.RotationMatrices.size(0) *
                                k_expl_temp.RotationMatrices.size(1)) *
                               b_i)] =
            initialParams.RotationMatrices
                [(i2 + (initialParams.RotationMatrices.size(0) * i1)) +
                 ((initialParams.RotationMatrices.size(0) *
                   initialParams.RotationMatrices.size(1)) *
                  b_i)];
      }
    }
  }
  k_expl_temp.Skew = initialParams.Skew;
  k_expl_temp.PrincipalPoint[0] = initialParams.PrincipalPoint[0];
  k_expl_temp.FocalLength[0] = initialParams.FocalLength[0];
  k_expl_temp.PrincipalPoint[1] = initialParams.PrincipalPoint[1];
  k_expl_temp.FocalLength[1] = initialParams.FocalLength[1];
  k_expl_temp.NumPatterns.size[0] = initialParams.NumPatterns.size[0];
  k_expl_temp.NumPatterns.size[1] = initialParams.NumPatterns.size[1];
  loop_ub = initialParams.NumPatterns.size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    j = initialParams.NumPatterns.size[0];
    for (i1 = 0; i1 < j; i1++) {
      k_expl_temp.NumPatterns.data[0] = initialParams.NumPatterns.data[0];
    }
  }
  k_expl_temp.TranslationVectors.set_size(
      initialParams.TranslationVectors.size(0), 3);
  k_expl_temp.RotationVectors.set_size(initialParams.RotationVectors.size(0),
                                       3);
  loop_ub = initialParams.TranslationVectors.size(0);
  j = initialParams.RotationVectors.size(0);
  for (b_i = 0; b_i < 3; b_i++) {
    k_expl_temp.IntrinsicMatrix[b_i][0] = initialParams.IntrinsicMatrix[b_i][0];
    k_expl_temp.IntrinsicMatrix[b_i][1] = initialParams.IntrinsicMatrix[b_i][1];
    k_expl_temp.IntrinsicMatrix[b_i][2] = initialParams.IntrinsicMatrix[b_i][2];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k_expl_temp
          .TranslationVectors[i1 +
                              (k_expl_temp.TranslationVectors.size(0) * b_i)] =
          initialParams.TranslationVectors
              [i1 + (initialParams.TranslationVectors.size(0) * b_i)];
    }
    for (i1 = 0; i1 < j; i1++) {
      k_expl_temp
          .RotationVectors[i1 + (k_expl_temp.RotationVectors.size(0) * b_i)] =
          initialParams
              .RotationVectors[i1 +
                               (initialParams.RotationVectors.size(0) * b_i)];
    }
  }
  k_expl_temp.EstimateTangentialDistortion =
      initialParams.EstimateTangentialDistortion;
  k_expl_temp.NumRadialDistortionCoefficients =
      initialParams.NumRadialDistortionCoefficients;
  k_expl_temp.EstimateSkew = initialParams.EstimateSkew;
  k_expl_temp.WorldUnits.size[0] = 1;
  k_expl_temp.WorldUnits.size[1] = initialParams.WorldUnits.size[1];
  loop_ub = initialParams.WorldUnits.size[1];
  if (0 <= (loop_ub - 1)) {
    (void)std::copy(&initialParams.WorldUnits.data[0],
                    &initialParams.WorldUnits.data[loop_ub],
                    &k_expl_temp.WorldUnits.data[0]);
  }
  k_expl_temp.WorldPoints.set_size(initialParams.WorldPoints.size(0), 2);
  loop_ub = initialParams.WorldPoints.size(0);
  for (b_i = 0; b_i < 2; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      k_expl_temp.WorldPoints[i1 + (k_expl_temp.WorldPoints.size(0) * b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
    k_expl_temp.TangentialDistortion[b_i] =
        initialParams.TangentialDistortion[b_i];
  }
  k_expl_temp.RadialDistortion[0] = initialParams.RadialDistortion[0];
  calibrationOptimized->OptimizationOptions[0] = 0.0;
  k_expl_temp.RadialDistortion[1] = initialParams.RadialDistortion[1];
  calibrationOptimized->OptimizationOptions[1] = 0.0;
  k_expl_temp.RadialDistortion[2] = initialParams.RadialDistortion[2];
  calibrationOptimized->OptimizationOptions[2] = 0.0;
  unserializeCalib(serialCalib, &k_expl_temp,
                   b_this.workspace.calibration.PatternPositions,
                   b_this.workspace.calibration.ImagePoints,
                   &calibrationOptimized->CameraParameters,
                   calibrationOptimized->PatternPositions,
                   calibrationOptimized->ImagePoints);
}

} // namespace Codegen

//
// File trailer for calibrateCamera.cpp
//
// [EOF]
//
