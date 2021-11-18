//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calibrateOneCamera.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "calibrateOneCamera.h"
#include "CalculateCost.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera_data.h"
#include "calibrateOneCamera_initialize.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_internal_types11.h"
#include "calibrateOneCamera_internal_types2.h"
#include "calibrateOneCamera_types.h"
#include "cat.h"
#include "combineVectorElements.h"
#include "computeInitialParameterEstimate.h"
#include "detectCheckerboardPoints.h"
#include "generateCheckerboardPoints.h"
#include "lsqnonlin.h"
#include "nanmean.h"
#include "rodriguesMatrixToVector.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "unserializeCalib.h"
#include "coder_array.h"

// Type Definitions
namespace Codegen {
struct cell_wrap_1 {
  ::coder::array<double, 2U> f1;
};

} // namespace Codegen

// Function Definitions
//
// Retrieve useful information
//
// Arguments    : const ::coder::array<unsigned char, 4U> &images
//                double squareSize
//                const int boardSize[2]
//                struct0_T *calibrationOptimized
//                double *calculation_err
//                int *err
// Return Type  : void
//
namespace Codegen {
void calibrateOneCamera(const ::coder::array<unsigned char, 4U> &images,
                        double squareSize, const int boardSize[2],
                        struct0_T *calibrationOptimized,
                        double *calculation_err, int *err)
{
  coder::anonymous_function b_this;
  ::coder::array<cell_wrap_1, 1U> board_points;
  ::coder::array<double, 3U> RotationMatrices;
  ::coder::array<double, 2U> b_world_points;
  ::coder::array<double, 2U> jacobian;
  ::coder::array<double, 1U> b_serialCalib;
  ::coder::array<double, 1U> c_f1;
  ::coder::array<double, 1U> f1;
  ::coder::array<double, 1U> f_expl_temp;
  ::coder::array<double, 1U> serialCalib;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<int, 1U> r2;
  ::coder::array<unsigned char, 2U> b_images;
  ::coder::array<bool, 1U> b_valid_idx;
  ::coder::array<bool, 1U> valid_idx;
  e_struct_T CameraParameters;
  struct1_T initialParams;
  double c_this[3][3];
  double t4_f2[6];
  double rvec[3];
  double board_size_detected[2];
  double a__1;
  double a__2;
  double b_expl_temp;
  double c_expl_temp;
  double d_expl_temp;
  double expl_temp;
  int b_i;
  int b_loop_ub;
  int c_i;
  int i1;
  int i2;
  int loop_ub;
  int nz;
  char e_expl_temp[19];
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  if (!isInitialized_calibrateOneCamera) {
    calibrateOneCamera_initialize();
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
  valid_idx.set_size(images.size(3));
  //  Initalize error flag
  //  Generate world coordinates of the checkerboard keypoints
  coder::generateCheckerboardPoints(boardSize, squareSize, b_world_points);
  //  REPLACE WITH FOR LOOP OF SINGLE detectCheckerBoardPoints
  //   load("detectCheckerboard_workspace.mat");
  b_i = images.size(3);
  board_points.set_size(images.size(3));
  for (c_i = 0; c_i < b_i; c_i++) {
    bool exitg1;
    //  perform checkerboards detection in each image
    loop_ub = images.size(0);
    b_loop_ub = images.size(1);
    b_images.set_size(images.size(0), images.size(1));
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_images[i2 + (b_images.size(0) * i1)] =
            images[(i2 + (images.size(0) * i1)) +
                   ((images.size(0) * images.size(1)) * c_i)];
      }
    }
    coder::detectCheckerboardPoints(b_images, board_points[c_i].f1,
                                    board_size_detected);
    //  mark if checkerboards is detected or not
    empty_non_axis_sizes = true;
    nz = 0;
    exitg1 = false;
    while ((!exitg1) && (nz < 2)) {
      if (!((static_cast<double>(boardSize[nz])) == board_size_detected[nz])) {
        empty_non_axis_sizes = false;
        exitg1 = true;
      } else {
        nz++;
      }
    }
    valid_idx[c_i] = empty_non_axis_sizes;
  }
  b_valid_idx.set_size(valid_idx.size(0));
  loop_ub = valid_idx.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_valid_idx[b_i] = valid_idx[b_i];
  }
  nz = coder::b_combineVectorElements(b_valid_idx);
  loop_ub = board_points[0].f1.size(0);
  b_loop_ub = board_points[0].f1.size(1);
  b_this.workspace.calibration.ImagePoints.set_size(
      board_points[0].f1.size(0), board_points[0].f1.size(1), nz);
  for (b_i = 0; b_i < nz; b_i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_this.workspace.calibration.ImagePoints
            [(i2 + (b_this.workspace.calibration.ImagePoints.size(0) * i1)) +
             ((b_this.workspace.calibration.ImagePoints.size(0) *
               b_this.workspace.calibration.ImagePoints.size(1)) *
              b_i)] = 0.0;
      }
    }
  }
  for (c_i = 0; c_i < nz; c_i++) {
    if (valid_idx[c_i]) {
      loop_ub = board_points[c_i].f1.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_loop_ub = board_points[c_i].f1.size(0);
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_this.workspace.calibration.ImagePoints
              [(i1 + (b_this.workspace.calibration.ImagePoints.size(0) * b_i)) +
               ((b_this.workspace.calibration.ImagePoints.size(0) *
                 b_this.workspace.calibration.ImagePoints.size(1)) *
                c_i)] =
              board_points[c_i].f1[i1 + (board_points[c_i].f1.size(0) * b_i)];
        }
      }
    }
  }
  //  Estimate without using estimateCameraParameters
  // If want different values of EstimateSkew, EstimateTangentialDistortion,
  // NumRadialDistortionCoefficients unserializeCalib fuction needs be changed
  board_size_detected[0] =
      static_cast<double>(static_cast<unsigned int>(images.size(0)));
  board_size_detected[1] =
      static_cast<double>(static_cast<unsigned int>(images.size(1)));
  computeInitialParameterEstimate(
      b_world_points, b_this.workspace.calibration.ImagePoints,
      board_size_detected, &initialParams, valid_idx, err);
  //  Convert Extrinsics to my way
  RotationMatrices.set_size(3, 3,
                            b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      RotationMatrices[(3 * i1) + (9 * b_i)] = 0.0;
      RotationMatrices[((3 * i1) + (9 * b_i)) + 1] = 0.0;
      RotationMatrices[((3 * i1) + (9 * b_i)) + 2] = 0.0;
    }
  }
  b_i = b_this.workspace.calibration.ImagePoints.size(2);
  for (c_i = 0; c_i < b_i; c_i++) {
    rvec[0] = initialParams.RotationVectors[c_i];
    rvec[1] = initialParams
                  .RotationVectors[c_i + initialParams.RotationVectors.size(0)];
    rvec[2] =
        initialParams
            .RotationVectors[c_i + (initialParams.RotationVectors.size(0) * 2)];
    coder::vision::internal::calibration::rodriguesVectorToMatrix(rvec, c_this);
    for (i1 = 0; i1 < 3; i1++) {
      RotationMatrices[(3 * i1) + (9 * c_i)] = c_this[0][i1];
      RotationMatrices[((3 * i1) + (9 * c_i)) + 1] = c_this[1][i1];
      RotationMatrices[((3 * i1) + (9 * c_i)) + 2] = c_this[2][i1];
    }
  }
  b_loop_ub = valid_idx.size(0) - 1;
  nz = 0;
  for (c_i = 0; c_i <= b_loop_ub; c_i++) {
    if (valid_idx[c_i]) {
      nz++;
    }
  }
  r.set_size(nz);
  nz = 0;
  for (c_i = 0; c_i <= b_loop_ub; c_i++) {
    if (valid_idx[c_i]) {
      r[nz] = c_i + 1;
      nz++;
    }
  }
  b_this.workspace.calibration.PatternPositions.set_size(1, r.size(0));
  b_loop_ub = valid_idx.size(0) - 1;
  nz = 0;
  for (c_i = 0; c_i <= b_loop_ub; c_i++) {
    if (valid_idx[c_i]) {
      nz++;
    }
  }
  r1.set_size(nz);
  nz = 0;
  for (c_i = 0; c_i <= b_loop_ub; c_i++) {
    if (valid_idx[c_i]) {
      r1[nz] = c_i + 1;
      nz++;
    }
  }
  b_i = r1.size(0);
  for (c_i = 0; c_i < b_i; c_i++) {
    b_loop_ub = valid_idx.size(0) - 1;
    nz = 0;
    for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
      if (valid_idx[loop_ub]) {
        nz++;
      }
    }
    r2.set_size(nz);
    nz = 0;
    for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
      if (valid_idx[loop_ub]) {
        r2[nz] = loop_ub + 1;
        nz++;
      }
    }
    //  Before applying transform all R's coming from outside Matlab
    for (i1 = 0; i1 < 4; i1++) {
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][0] = 0.0;
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][1] = 0.0;
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][2] = 0.0;
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][3] = 0.0;
    }
    for (i1 = 0; i1 < 3; i1++) {
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][0] =
          RotationMatrices[(3 * i1) + (9 * (r2[c_i] - 1))];
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][1] =
          RotationMatrices[((3 * i1) + (9 * (r2[c_i] - 1))) + 1];
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][2] =
          RotationMatrices[((3 * i1) + (9 * (r2[c_i] - 1))) + 2];
      b_this.workspace.calibration.PatternPositions[c_i].f1[i1][3] =
          initialParams.TranslationVectors
              [(r2[c_i] + (initialParams.TranslationVectors.size(0) * i1)) - 1];
    }
    b_this.workspace.calibration.PatternPositions[c_i].f1[3][0] = 0.0;
    b_this.workspace.calibration.PatternPositions[c_i].f1[3][1] = 0.0;
    b_this.workspace.calibration.PatternPositions[c_i].f1[3][2] = 0.0;
    b_this.workspace.calibration.PatternPositions[c_i].f1[3][3] = 1.0;
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
    nz = b_world_points.size(0);
  } else {
    nz = 0;
  }
  empty_non_axis_sizes = (nz == 0);
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
  b_this.workspace.genPoints.set_size(nz,
                                      (static_cast<int>(input_sizes_idx_1)) +
                                          (static_cast<int>(sizes_idx_1)));
  loop_ub = static_cast<int>(input_sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < nz; i1++) {
      b_this.workspace
          .genPoints[i1 + (b_this.workspace.genPoints.size(0) * b_i)] =
          b_world_points[i1 + (nz * b_i)];
    }
  }
  loop_ub = static_cast<int>(sizes_idx_1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    for (i1 = 0; i1 < nz; i1++) {
      b_this.workspace.genPoints[i1 + (b_this.workspace.genPoints.size(0) *
                                       (static_cast<int>(input_sizes_idx_1)))] =
          1.0;
    }
  }
  //  Convert initial estimate
  //  Changed for just 1 camera - 1/10/2021
  // RTcnc1 = calibration.Extrinsics;
  //  options (fixedK, fixedDistortions, fixedRTpnc1, fixedRTcnc1)
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs];
  serialCalib.set_size(4);
  serialCalib[0] = initialParams.IntrinsicMatrix[0][0];
  serialCalib[1] = initialParams.IntrinsicMatrix[1][1];
  serialCalib[2] = initialParams.IntrinsicMatrix[0][2];
  serialCalib[3] = initialParams.IntrinsicMatrix[1][2];
  if (initialParams.EstimateSkew) {
    calibrationOptimized->b_Error.set_size(4);
    for (b_i = 0; b_i < 4; b_i++) {
      calibrationOptimized->b_Error[b_i] = serialCalib[b_i];
    }
    serialCalib.set_size(5);
    serialCalib[0] = calibrationOptimized->b_Error[0];
    serialCalib[1] = calibrationOptimized->b_Error[1];
    serialCalib[2] = calibrationOptimized->b_Error[2];
    serialCalib[3] = calibrationOptimized->b_Error[3];
    serialCalib[4] = initialParams.IntrinsicMatrix[1][0];
  }
  if (1.0 > initialParams.NumRadialDistortionCoefficients) {
    loop_ub = 0;
  } else {
    loop_ub = static_cast<int>(initialParams.NumRadialDistortionCoefficients);
  }
  f1.set_size(loop_ub);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    f1[b_i] = initialParams.RadialDistortion[b_i];
  }
  c_f1.set_size(serialCalib.size(0));
  b_loop_ub = serialCalib.size(0);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    c_f1[b_i] = serialCalib[b_i];
  }
  input_sizes_idx_1 = static_cast<signed char>(serialCalib.size(0) + loop_ub);
  serialCalib.set_size(static_cast<int>(input_sizes_idx_1));
  b_i = c_f1.size(0);
  for (nz = 0; nz < b_i; nz++) {
    serialCalib[nz] = c_f1[nz];
  }
  i1 = f1.size(0);
  for (nz = 0; nz < i1; nz++) {
    serialCalib[b_i + nz] = f1[nz];
  }
  if (initialParams.EstimateTangentialDistortion) {
    b_serialCalib.set_size(serialCalib.size(0));
    loop_ub = serialCalib.size(0) - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      b_serialCalib[b_i] = serialCalib[b_i];
    }
    coder::b_cat(b_serialCalib, initialParams.TangentialDistortion,
                 serialCalib);
  }
  //  Extrinsics
  //  x = [fx; fy; cx; cy; skew; radial; tangential; rvecs; tvecs; A; B; C; Tx;
  //  Ty; Tz];
  b_i = b_this.workspace.calibration.PatternPositions.size(1);
  for (c_i = 0; c_i < b_i; c_i++) {
    for (i1 = 0; i1 < 3; i1++) {
      c_this[i1][0] =
          b_this.workspace.calibration.PatternPositions[c_i].f1[0][i1];
      c_this[i1][1] =
          b_this.workspace.calibration.PatternPositions[c_i].f1[1][i1];
      c_this[i1][2] =
          b_this.workspace.calibration.PatternPositions[c_i].f1[2][i1];
    }
    coder::vision::internal::calibration::rodriguesMatrixToVector(c_this, rvec);
    loop_ub = serialCalib.size(0);
    if (serialCalib.size(0) == 0) {
      t4_f2[0] = rvec[0];
      t4_f2[3] = b_this.workspace.calibration.PatternPositions[c_i].f1[0][3];
      t4_f2[1] = rvec[1];
      t4_f2[4] = b_this.workspace.calibration.PatternPositions[c_i].f1[1][3];
      t4_f2[2] = rvec[2];
      t4_f2[5] = b_this.workspace.calibration.PatternPositions[c_i].f1[2][3];
      serialCalib.set_size(6);
      for (i1 = 0; i1 < 6; i1++) {
        serialCalib[i1] = t4_f2[i1];
      }
    } else {
      calibrationOptimized->b_Error.set_size(serialCalib.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        calibrationOptimized->b_Error[i1] = serialCalib[i1];
      }
      t4_f2[0] = rvec[0];
      t4_f2[3] = b_this.workspace.calibration.PatternPositions[c_i].f1[0][3];
      t4_f2[1] = rvec[1];
      t4_f2[4] = b_this.workspace.calibration.PatternPositions[c_i].f1[1][3];
      t4_f2[2] = rvec[2];
      t4_f2[5] = b_this.workspace.calibration.PatternPositions[c_i].f1[2][3];
      i1 = serialCalib.size(0) + 6;
      serialCalib.set_size(i1);
      i1 = calibrationOptimized->b_Error.size(0);
      for (nz = 0; nz < i1; nz++) {
        serialCalib[nz] = calibrationOptimized->b_Error[nz];
      }
      for (nz = 0; nz < 6; nz++) {
        serialCalib[i1 + nz] = t4_f2[nz];
      }
    }
  }
  // [calibrationConverted] = unserializeCalib(serialCalib, options,
  // calibration);
  // {
  // errorInitial = CalculateCost(serialCalib, options, calibration, genPoints,
  // detPoints); tmp = errorInitial; tmp(tmp<0.000001)=NaN; MREi =
  // mean(tmp(~isnan(tmp(:)))); disp (['Mean Reprojection Error - Before
  // Optimization: ', num2str(MREi)]);
  // }
  //  Optimization
  // h = waitbar(0, 'Running global Optimization...','Name', 'Global
  // Optimization');
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
    b_this.workspace.calibration.CameraParameters.ImageSize[b_i] =
        initialParams.ImageSize[b_i];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_this.workspace.calibration.CameraParameters
          .WorldPoints[i1 + (b_this.workspace.calibration.CameraParameters
                                 .WorldPoints.size(0) *
                             b_i)] =
          initialParams
              .WorldPoints[i1 + (initialParams.WorldPoints.size(0) * b_i)];
    }
  }
  b_this.workspace.calibration.CameraParameters.WorldUnits.set_size(
      1, initialParams.WorldUnits.size(1));
  loop_ub = initialParams.WorldUnits.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_this.workspace.calibration.CameraParameters.WorldUnits[b_i] =
        initialParams.WorldUnits[b_i];
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
  b_loop_ub = initialParams.TranslationVectors.size(0);
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
    for (i1 = 0; i1 < b_loop_ub; i1++) {
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
  b_this.workspace.detPoints.set_size(
      b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_this.workspace.calibration.ImagePoints.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      nz = b_this.workspace.calibration.ImagePoints.size(0);
      for (i2 = 0; i2 < nz; i2++) {
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
                   e_expl_temp, b_serialCalib, f_expl_temp, jacobian);
  // delete(h);
  // serialCI = nlparci(optimizedSerialCalib,residual,'jacobian',jacobian);
  // serialCI = my_nlparci(optimizedSerialCalib,residual,jacobian);
  // CI = cell(1,2);
  // CI{1} = unserializeCalib(serialCI(:,1)', options, calibration);
  // CI{2} = unserializeCalib(serialCI(:,2)', options, calibration);
  CalculateCost(
      serialCalib, initialParams.ImageSize,
      b_this.workspace.calibration.PatternPositions, b_this.workspace.genPoints,
      b_this.workspace.calibration.ImagePoints, calibrationOptimized->b_Error);
  f1.set_size(calibrationOptimized->b_Error.size(0));
  loop_ub = calibrationOptimized->b_Error.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    f1[b_i] = calibrationOptimized->b_Error[b_i];
  }
  b_loop_ub = calibrationOptimized->b_Error.size(0);
  for (c_i = 0; c_i < b_loop_ub; c_i++) {
    if (calibrationOptimized->b_Error[c_i] < 1.0E-6) {
      f1[c_i] = rtNaN;
    }
  }
  *calculation_err = coder::nanmean(f1);
  // disp (['Mean Reprojection Error - After Optimization: ', num2str(MREf)]);
  unserializeCalib(serialCalib, initialParams.ImageSize,
                   b_this.workspace.calibration.PatternPositions,
                   &CameraParameters, calibrationOptimized->PatternPositions);
  calibrationOptimized->ImagePoints.set_size(
      b_this.workspace.calibration.ImagePoints.size(0),
      b_this.workspace.calibration.ImagePoints.size(1),
      b_this.workspace.calibration.ImagePoints.size(2));
  loop_ub = b_this.workspace.calibration.ImagePoints.size(2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_this.workspace.calibration.ImagePoints.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      nz = b_this.workspace.calibration.ImagePoints.size(0);
      for (i2 = 0; i2 < nz; i2++) {
        calibrationOptimized
            ->ImagePoints[(i2 +
                           (calibrationOptimized->ImagePoints.size(0) * i1)) +
                          ((calibrationOptimized->ImagePoints.size(0) *
                            calibrationOptimized->ImagePoints.size(1)) *
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
  // calibrationOptimized.OptimizationOptions = options;
  // calibrationOptimized.Jacobian = jacobian;
  // calibrationOptimized.CI = CI;
  calibrationOptimized->CameraParameters.RadialDistortion[0] =
      CameraParameters.RadialDistortion[0];
  calibrationOptimized->CameraParameters.RadialDistortion[1] =
      CameraParameters.RadialDistortion[1];
  calibrationOptimized->CameraParameters.RadialDistortion[2] =
      CameraParameters.RadialDistortion[2];
  calibrationOptimized->CameraParameters.WorldPoints.set_size(0, 2);
  calibrationOptimized->CameraParameters.WorldUnits.set_size(1, 2);
  calibrationOptimized->CameraParameters.TangentialDistortion[0] =
      CameraParameters.TangentialDistortion[0];
  calibrationOptimized->CameraParameters.ImageSize[0] =
      CameraParameters.ImageSize[0];
  calibrationOptimized->CameraParameters.WorldUnits[0] =
      CameraParameters.WorldUnits[0];
  calibrationOptimized->CameraParameters.TangentialDistortion[1] =
      CameraParameters.TangentialDistortion[1];
  calibrationOptimized->CameraParameters.ImageSize[1] =
      CameraParameters.ImageSize[1];
  calibrationOptimized->CameraParameters.WorldUnits[1] =
      CameraParameters.WorldUnits[1];
  calibrationOptimized->CameraParameters.EstimateSkew =
      CameraParameters.EstimateSkew;
  calibrationOptimized->CameraParameters.NumRadialDistortionCoefficients =
      CameraParameters.NumRadialDistortionCoefficients;
  calibrationOptimized->CameraParameters.EstimateTangentialDistortion =
      CameraParameters.EstimateTangentialDistortion;
  calibrationOptimized->CameraParameters.RotationVectors.set_size(0, 3);
  calibrationOptimized->CameraParameters.TranslationVectors.set_size(0, 3);
  for (b_i = 0; b_i < 3; b_i++) {
    calibrationOptimized->CameraParameters.IntrinsicMatrix[b_i][0] =
        CameraParameters.IntrinsicMatrix[b_i][0];
    calibrationOptimized->CameraParameters.IntrinsicMatrix[b_i][1] =
        CameraParameters.IntrinsicMatrix[b_i][1];
    calibrationOptimized->CameraParameters.IntrinsicMatrix[b_i][2] =
        CameraParameters.IntrinsicMatrix[b_i][2];
  }
}

} // namespace Codegen

//
// File trailer for calibrateOneCamera.cpp
//
// [EOF]
//
