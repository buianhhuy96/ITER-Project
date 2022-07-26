//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: estimateKnucklePose.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "estimateKnucklePose.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types11.h"
#include "ITER_API_types.h"
#include "anonymous_function1.h"
#include "bsxfun.h"
#include "calculateReprErr.h"
#include "cameraParameters.h"
#include "combineVectorElements.h"
#include "driver.h"
#include "inv.h"
#include "msac.h"
#include "rodriguesMatrixToVector.h"
#include "rodriguesVectorToMatrix.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &markerCentroidsOrdered
//                const double robotPose[4][4]
//                const double c_worldPoints[3][5]
//                const double handEyeCalibration[4][4]
//                const struct1_T *cameraParams
//                double RT34est[4][4]
//                double RT14[4][4]
//                double *finalMRE
//                int *err
// Return Type  : void
//
namespace ITER {
void estimateKnucklePose(
    const ::coder::array<double, 2U> &markerCentroidsOrdered,
    const double robotPose[4][4], const double c_worldPoints[3][5],
    const double handEyeCalibration[4][4], const struct1_T *cameraParams,
    double RT34est[4][4], double RT14[4][4], double *finalMRE, int *err)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  coder::anonymous_function b_this;
  coder::cameraParameters b_cameraParams;
  ::coder::array<double, 2U> c_this;
  ::coder::array<double, 2U> jacob;
  ::coder::array<double, 2U> residual;
  ::coder::array<bool, 1U> b;
  ::coder::array<bool, 1U> inlierIDX;
  double c_RT[4][4];
  double c_RT34est[4][4];
  double b_RT34est[3][3];
  double b_dv1[3][3];
  double b_intrinsicMatrix[3][3];
  double pose_R[3][3];
  double worldOrientation[3][3];
  double e_x[6];
  double f_expl_temp[6];
  double g_expl_temp[6];
  double b_dv[3];
  double pose_t[3];
  double worldLocation[3];
  double b_expl_temp;
  double c_expl_temp;
  double d;
  double d_expl_temp;
  double exitflag;
  double expl_temp;
  double resnorm;
  int b_loop_ub;
  int c_i;
  int c_loop_ub;
  int d_i;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_n;
  int i13;
  int i18;
  int i25;
  int i28;
  int i3;
  int i35;
  int i9;
  int loop_ub;
  int nrows;
  int nrowx;
  int p_n;
  char e_expl_temp[19];
  bool b_x[2];
  bool guard1{false};
  bool isFound;
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  //  Pose Estimation
  (void)b_cameraParams.b_init(
      cameraParams->RadialDistortion, cameraParams->TangentialDistortion,
      cameraParams->ImageSize, cameraParams->WorldUnits,
      cameraParams->EstimateSkew, cameraParams->NumRadialDistortionCoefficients,
      cameraParams->EstimateTangentialDistortion,
      cameraParams->IntrinsicMatrix);
  //  Knuckle Points
  *err = 0;
  b_this.workspace.worldPointsTmp.set_size(5, 3);
  for (int b_i{0}; b_i < 3; b_i++) {
    for (int i1{0}; i1 < 5; i1++) {
      b_this.workspace
          .worldPointsTmp[i1 + (b_this.workspace.worldPointsTmp.size(0) *
                                b_i)] = c_worldPoints[b_i][i1];
    }
  }
  loop_ub = markerCentroidsOrdered.size(0);
  b.set_size(markerCentroidsOrdered.size(0));
  b_loop_ub = markerCentroidsOrdered.size(0);
  if ((static_cast<int>(markerCentroidsOrdered.size(0) < 4)) != 0) {
    for (int i2{0}; i2 < loop_ub; i2++) {
      b[i2] = std::isnan(markerCentroidsOrdered[i2]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i2 = 0; i2 < b_loop_ub; i2++) {
      b[i2] = std::isnan(markerCentroidsOrdered[i2]);
    }
  }
  h_n = 0;
  i3 = b.size(0);
  for (int k{0}; k < i3; k++) {
    h_n += static_cast<int>(b[k]);
  }
  c_i = 0;
  for (int b_k{0}; b_k < 5; b_k++) {
    guard1 = false;
    if ((b_k + 1) > b.size(0)) {
      guard1 = true;
    } else if (!b[b_k]) {
      guard1 = true;
    } else {
      /* no actions */
    }
    if (guard1) {
      b_this.workspace.worldPointsTmp[c_i] =
          b_this.workspace.worldPointsTmp[b_k];
      b_this.workspace
          .worldPointsTmp[c_i + b_this.workspace.worldPointsTmp.size(0)] =
          b_this.workspace
              .worldPointsTmp[b_k + b_this.workspace.worldPointsTmp.size(0)];
      b_this.workspace
          .worldPointsTmp[c_i + (b_this.workspace.worldPointsTmp.size(0) * 2)] =
          b_this.workspace
              .worldPointsTmp[b_k +
                              (b_this.workspace.worldPointsTmp.size(0) * 2)];
      c_i++;
    }
  }
  if (1 > (5 - h_n)) {
    c_loop_ub = 0;
  } else {
    c_loop_ub = 5 - h_n;
  }
  for (int i4{0}; i4 < 3; i4++) {
    for (int i5{0}; i5 < c_loop_ub; i5++) {
      b_this.workspace.worldPointsTmp[i5 + (c_loop_ub * i4)] =
          b_this.workspace
              .worldPointsTmp[i5 +
                              (b_this.workspace.worldPointsTmp.size(0) * i4)];
    }
  }
  b_this.workspace.worldPointsTmp.set_size(c_loop_ub, 3);
  d_loop_ub = markerCentroidsOrdered.size(0);
  b.set_size(markerCentroidsOrdered.size(0));
  e_loop_ub = markerCentroidsOrdered.size(0);
  if ((static_cast<int>(markerCentroidsOrdered.size(0) < 4)) != 0) {
    for (int i6{0}; i6 < d_loop_ub; i6++) {
      b[i6] = std::isnan(markerCentroidsOrdered[i6]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i6 = 0; i6 < e_loop_ub; i6++) {
      b[i6] = std::isnan(markerCentroidsOrdered[i6]);
    }
  }
  b_this.workspace.imagePointsTmp.set_size(markerCentroidsOrdered.size(0), 2);
  f_loop_ub = markerCentroidsOrdered.size(0);
  for (int i7{0}; i7 < 2; i7++) {
    for (int b_i8{0}; b_i8 < f_loop_ub; b_i8++) {
      b_this.workspace
          .imagePointsTmp[b_i8 +
                          (b_this.workspace.imagePointsTmp.size(0) * i7)] =
          markerCentroidsOrdered[b_i8 + (markerCentroidsOrdered.size(0) * i7)];
    }
  }
  nrowx = markerCentroidsOrdered.size(0);
  p_n = 0;
  i9 = b.size(0);
  for (int c_k{0}; c_k < i9; c_k++) {
    p_n += static_cast<int>(b[c_k]);
  }
  nrows = markerCentroidsOrdered.size(0) - p_n;
  d_i = 0;
  for (int d_k{0}; d_k < nrowx; d_k++) {
    guard1 = false;
    if ((d_k + 1) > b.size(0)) {
      guard1 = true;
    } else if (!b[d_k]) {
      guard1 = true;
    } else {
      /* no actions */
    }
    if (guard1) {
      b_this.workspace.imagePointsTmp[d_i] =
          b_this.workspace.imagePointsTmp[d_k];
      b_this.workspace
          .imagePointsTmp[d_i + b_this.workspace.imagePointsTmp.size(0)] =
          b_this.workspace
              .imagePointsTmp[d_k + b_this.workspace.imagePointsTmp.size(0)];
      d_i++;
    }
  }
  if (1 > nrows) {
    g_loop_ub = 0;
  } else {
    g_loop_ub = nrows;
  }
  for (int i10{0}; i10 < 2; i10++) {
    for (int i11{0}; i11 < g_loop_ub; i11++) {
      b_this.workspace.imagePointsTmp[i11 + (g_loop_ub * i10)] =
          b_this.workspace
              .imagePointsTmp[i11 +
                              (b_this.workspace.imagePointsTmp.size(0) * i10)];
    }
  }
  b_this.workspace.imagePointsTmp.set_size(g_loop_ub, 2);
  if (g_loop_ub <= 3) {
    *err = -201;
    *finalMRE = rtNaN;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i13)

    for (int i12 = 0; i12 < 4; i12++) {
      for (i13 = 0; i13 < 4; i13++) {
        RT34est[i12][i13] = rtNaN;
        RT14[i12][i13] = rtNaN;
      }
    }
  } else {
    int e_k;
    bool exitg1;
    bool y;
    b_x[0] = (g_loop_ub != 5);
    b_x[1] = true;
    y = true;
    e_k = 0;
    exitg1 = false;
    while ((!exitg1) && (e_k < 2)) {
      if (!b_x[e_k]) {
        y = false;
        exitg1 = true;
      } else {
        e_k++;
      }
    }
    if (y) {
      *err = -202;
      *finalMRE = rtNaN;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18)

      for (int i14 = 0; i14 < 4; i14++) {
        for (i18 = 0; i18 < 4; i18++) {
          RT34est[i14][i18] = rtNaN;
          RT14[i14][i18] = rtNaN;
        }
      }
    } else {
      int status;
      // try
      if (b_this.workspace.worldPointsTmp.size(0) < 4) {
        status = 1;
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i16 = 0; i16 < 3; i16++) {
          worldOrientation[i16][0] = rtNaN;
          worldOrientation[i16][1] = rtNaN;
          worldOrientation[i16][2] = rtNaN;
          worldLocation[i16] = rtNaN;
        }
      } else {
        int result;
        result = g_loop_ub;
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i15 = 0; i15 < 3; i15++) {
          b_intrinsicMatrix[i15][0] =
              b_cameraParams.IntrinsicMatrixInternal[0][i15];
          b_intrinsicMatrix[i15][1] =
              b_cameraParams.IntrinsicMatrixInternal[1][i15];
          b_intrinsicMatrix[i15][2] =
              b_cameraParams.IntrinsicMatrixInternal[2][i15];
        }
        c_this.set_size(result, 5);
        for (int i17{0}; i17 < 2; i17++) {
          for (int i20{0}; i20 < result; i20++) {
            c_this[i20 + (c_this.size(0) * i17)] =
                b_this.workspace.imagePointsTmp[i20 + (result * i17)];
          }
        }
        for (int i19{0}; i19 < 3; i19++) {
          for (int i23{0}; i23 < result; i23++) {
            c_this[i23 + (c_this.size(0) * (i19 + 2))] =
                b_this.workspace.worldPointsTmp[i23 + (result * i19)];
          }
        }
        coder::vision::internal::ransac::msac(
            c_this, b_intrinsicMatrix, &isFound, pose_R, pose_t, inlierIDX);
        if (isFound) {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i26 = 0; i26 < 3; i26++) {
            worldOrientation[i26][0] = pose_R[0][i26];
            worldOrientation[i26][1] = pose_R[1][i26];
            worldOrientation[i26][2] = pose_R[2][i26];
            pose_t[i26] = -pose_t[i26];
          }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d)

          for (int i30 = 0; i30 < 3; i30++) {
            d = ((pose_t[0] * pose_R[0][i30]) + (pose_t[1] * pose_R[1][i30])) +
                (pose_t[2] * pose_R[2][i30]);
            worldLocation[i30] = d;
          }
          status = 0;
        } else {
          status = 2;
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int i29 = 0; i29 < 3; i29++) {
            worldOrientation[i29][0] = rtNaN;
            worldOrientation[i29][1] = rtNaN;
            worldOrientation[i29][2] = rtNaN;
            worldLocation[i29] = rtNaN;
          }
        }
      }
      if (status == 2) {
        *finalMRE = rtNaN;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i28)

        for (int i22 = 0; i22 < 4; i22++) {
          for (i28 = 0; i28 < 4; i28++) {
            RT34est[i22][i28] = rtNaN;
            RT14[i22][i28] = rtNaN;
          }
        }
        *err = -203;
      } else {
        //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i25)

        for (int i21 = 0; i21 < 4; i21++) {
          for (i25 = 0; i25 < 4; i25++) {
            c_RT[i21][i25] = 0.0;
          }
        }
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i24 = 0; i24 < 3; i24++) {
          c_RT[i24][0] = worldOrientation[i24][0];
          c_RT[i24][1] = worldOrientation[i24][1];
          c_RT[i24][2] = worldOrientation[i24][2];
          c_RT[i24][3] = worldLocation[i24];
        }
        for (int i27{0}; i27 < 4; i27++) {
          c_RT[3][i27] = static_cast<double>(b_iv[i27]);
        }
        coder::b_inv(c_RT, RT34est);
        //  Optimize Pose
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i31 = 0; i31 < 6; i31++) {
          e_x[i31] = 0.0;
        }
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i32 = 0; i32 < 3; i32++) {
          e_x[i32] = RT34est[i32][3];
          b_RT34est[i32][0] = RT34est[i32][0];
          b_RT34est[i32][1] = RT34est[i32][1];
          b_RT34est[i32][2] = RT34est[i32][2];
        }
        ::coder::array<double, 1U> c_residual;
        int b_residual;
        coder::vision::internal::calibration::rodriguesMatrixToVector(b_RT34est,
                                                                      b_dv);
        e_x[3] = b_dv[0];
        e_x[4] = b_dv[1];
        e_x[5] = b_dv[2];
        b_this.workspace.cameraParams = &b_cameraParams;
        coder::optim::coder::levenbergMarquardt::driver(
            &b_this, e_x, &resnorm, residual, &exitflag, &expl_temp,
            &b_expl_temp, &c_expl_temp, &d_expl_temp, e_expl_temp, f_expl_temp,
            g_expl_temp, jacob);
        b_residual = residual.size(0) * 2;
        c_residual = residual.reshape(b_residual);
        *finalMRE =
            coder::b_combineVectorElements(c_residual) /
            (static_cast<double>(static_cast<int>(residual.size(0) * 2)));
        //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i35)

        for (int i33 = 0; i33 < 4; i33++) {
          for (i35 = 0; i35 < 4; i35++) {
            RT34est[i33][i35] = 0.0;
          }
        }
        coder::vision::internal::calibration::rodriguesVectorToMatrix(
            *((double(*)[3])(&e_x[3])), b_dv1);
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i34 = 0; i34 < 3; i34++) {
          RT34est[i34][0] = b_dv1[i34][0];
          RT34est[i34][1] = b_dv1[i34][1];
          RT34est[i34][2] = b_dv1[i34][2];
          RT34est[i34][3] = e_x[i34];
        }
        for (int i36{0}; i36 < 4; i36++) {
          RT34est[3][i36] = static_cast<double>(b_iv[i36]);
          for (int i37{0}; i37 < 4; i37++) {
            double b_d1;
            b_d1 = 0.0;
            for (int i39{0}; i39 < 4; i39++) {
              b_d1 += RT34est[i39][i36] * handEyeCalibration[i37][i39];
            }
            c_RT34est[i37][i36] = b_d1;
          }
          for (int i38{0}; i38 < 4; i38++) {
            double d2;
            d2 = 0.0;
            for (int i40{0}; i40 < 4; i40++) {
              d2 += c_RT34est[i40][i36] * robotPose[i38][i40];
            }
            RT14[i38][i36] = d2;
          }
        }
        // catch
        //  Not possible calculate pose
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &imagePointsTmp
//                const ::coder::array<double, 2U> &worldPointsTmp
//                const coder::cameraParameters *cameraParams
//                const double b_x[6]
//                ::coder::array<double, 2U> &varargout_1
// Return Type  : void
//
void estimateKnucklePose_anonFcn1(
    const ::coder::array<double, 2U> &imagePointsTmp,
    const ::coder::array<double, 2U> &worldPointsTmp,
    const coder::cameraParameters *cameraParams, const double b_x[6],
    ::coder::array<double, 2U> &varargout_1)
{
  static const signed char b_iv[4]{0, 0, 0, 1};
  ::coder::array<double, 2U> b_projectedPoints;
  ::coder::array<double, 2U> d_result;
  ::coder::array<double, 2U> e_x;
  ::coder::array<double, 2U> genPoints;
  ::coder::array<double, 2U> projectedPoints;
  ::coder::array<double, 2U> projectedPoints_Cam1;
  ::coder::array<double, 1U> c_projectedPoints;
  double RT34[4][4];
  double b_RT34[3][4];
  double cameraMatrix[3][4];
  double b_dv[3][3];
  double b_d1;
  double d;
  double d2;
  double d3;
  int b_result[2];
  int c_result[2];
  int b_i;
  int b_i8;
  int b_loop_ub;
  int c_i;
  int c_loop_ub;
  int d_i;
  int d_k;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int g_k;
  int g_loop_ub;
  int h_loop_ub;
  int i11;
  int i12;
  int i14;
  int i17;
  int i18;
  int i4;
  int inner;
  int k;
  int loop_ub;
  int mc;
  int result;
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  // Calculates reprojection error. One camera.
  genPoints.set_size(worldPointsTmp.size(0), 3);
  k = 0;
  for (int j{0}; j < 2; j++) {
    int i1;
    k++;
    i1 = genPoints.size(0);
    for (int c_k{0}; c_k < i1; c_k++) {
      genPoints[c_k + (genPoints.size(0) * (k - 1))] =
          worldPointsTmp[c_k + (worldPointsTmp.size(0) * j)];
    }
  }
  b_i = genPoints.size(0);
  if ((static_cast<int>(genPoints.size(0) < 4)) != 0) {
    for (int b_k{0}; b_k < b_i; b_k++) {
      genPoints[b_k + (genPoints.size(0) * k)] = 0.0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_k = 0; b_k < b_i; b_k++) {
      genPoints[b_k + (genPoints.size(0) * k)] = 0.0;
    }
  }
  //  Before applying transform all R's coming from outside Matlab
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

  for (int i2 = 0; i2 < 4; i2++) {
    for (i4 = 0; i4 < 4; i4++) {
      RT34[i2][i4] = 0.0;
    }
  }
  coder::vision::internal::calibration::rodriguesVectorToMatrix(
      *((double(*)[3])(&b_x[3])), b_dv);
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i3 = 0; i3 < 3; i3++) {
    RT34[i3][0] = b_dv[i3][0];
    RT34[i3][1] = b_dv[i3][1];
    RT34[i3][2] = b_dv[i3][2];
    RT34[i3][3] = b_x[i3];
  }
  for (int i5{0}; i5 < 4; i5++) {
    RT34[3][i5] = static_cast<double>(b_iv[i5]);
  }
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int i6 = 0; i6 < 3; i6++) {
    b_RT34[i6][0] = RT34[i6][0];
    b_RT34[i6][1] = RT34[i6][1];
    b_RT34[i6][2] = RT34[i6][2];
    b_RT34[i6][3] = RT34[i6][3];
  }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    d, b_i8, b_d1, d2, d3)

  for (int i7 = 0; i7 < 4; i7++) {
    b_d1 = b_RT34[0][i7];
    d2 = b_RT34[1][i7];
    d3 = b_RT34[2][i7];
    for (b_i8 = 0; b_i8 < 3; b_i8++) {
      d = ((b_d1 * cameraParams->IntrinsicMatrixInternal[0][b_i8]) +
           (d2 * cameraParams->IntrinsicMatrixInternal[1][b_i8])) +
          (d3 * cameraParams->IntrinsicMatrixInternal[2][b_i8]);
      cameraMatrix[b_i8][i7] = d;
    }
  }
  if (genPoints.size(0) != 0) {
    result = genPoints.size(0);
  } else {
    result = 0;
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = 3;
  } else if (genPoints.size(0) != 0) {
    input_sizes_idx_1 = 3;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 1;
  } else if (genPoints.size(0) != 0) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  b_result[0] = result;
  b_result[1] = static_cast<int>(input_sizes_idx_1);
  c_result[0] = result;
  c_result[1] = static_cast<int>(b_input_sizes_idx_1);
  d_result.set_size(result, (static_cast<int>(input_sizes_idx_1)) +
                                (static_cast<int>(b_input_sizes_idx_1)));
  loop_ub = static_cast<int>(input_sizes_idx_1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i11,       \
                                                                    c_loop_ub)

  for (int i9 = 0; i9 < loop_ub; i9++) {
    c_loop_ub = b_result[0];
    for (i11 = 0; i11 < c_loop_ub; i11++) {
      d_result[i11 + (d_result.size(0) * i9)] =
          genPoints[i11 + (b_result[0] * i9)];
    }
  }
  b_loop_ub = c_result[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12,       \
                                                                    d_loop_ub)

  for (int i10 = 0; i10 < b_loop_ub; i10++) {
    d_loop_ub = c_result[0];
    for (i12 = 0; i12 < d_loop_ub; i12++) {
      d_result[i12 + (d_result.size(0) * b_result[1])] = 1.0;
    }
  }
  mc = d_result.size(0) - 1;
  inner = d_result.size(1);
  projectedPoints.set_size(d_result.size(0), 3);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i, d_k,  \
                                                                    d_i)

  for (int b_j = 0; b_j < 3; b_j++) {
    for (d_i = 0; d_i <= mc; d_i++) {
      projectedPoints[d_i + (projectedPoints.size(0) * b_j)] = 0.0;
    }
    for (d_k = 0; d_k < inner; d_k++) {
      for (c_i = 0; c_i <= mc; c_i++) {
        projectedPoints[c_i + (projectedPoints.size(0) * b_j)] =
            projectedPoints[c_i + (projectedPoints.size(0) * b_j)] +
            (d_result[c_i + (d_result.size(0) * d_k)] * cameraMatrix[b_j][d_k]);
      }
    }
  }
  e_loop_ub = projectedPoints.size(0);
  b_projectedPoints.set_size(projectedPoints.size(0), 2);
  f_loop_ub = projectedPoints.size(0);
  if ((static_cast<int>((projectedPoints.size(0) * 2) < 4)) != 0) {
    for (int i13{0}; i13 < 2; i13++) {
      for (i14 = 0; i14 < e_loop_ub; i14++) {
        b_projectedPoints[i14 + (b_projectedPoints.size(0) * i13)] =
            projectedPoints[i14 + (projectedPoints.size(0) * i13)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i14)

    for (int i13 = 0; i13 < 2; i13++) {
      for (i14 = 0; i14 < f_loop_ub; i14++) {
        b_projectedPoints[i14 + (b_projectedPoints.size(0) * i13)] =
            projectedPoints[i14 + (projectedPoints.size(0) * i13)];
      }
    }
  }
  g_loop_ub = projectedPoints.size(0);
  c_projectedPoints.set_size(projectedPoints.size(0));
  h_loop_ub = projectedPoints.size(0);
  if ((static_cast<int>(projectedPoints.size(0) < 4)) != 0) {
    for (int i15{0}; i15 < g_loop_ub; i15++) {
      c_projectedPoints[i15] =
          projectedPoints[i15 + (projectedPoints.size(0) * 2)];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i15 = 0; i15 < h_loop_ub; i15++) {
      c_projectedPoints[i15] =
          projectedPoints[i15 + (projectedPoints.size(0) * 2)];
    }
  }
  coder::b_bsxfun(b_projectedPoints, c_projectedPoints, projectedPoints_Cam1);
  // diff = projectedPoints_Cam1-detPoints(:,:);
  if (projectedPoints_Cam1.size(0) == imagePointsTmp.size(0)) {
    int i_loop_ub;
    e_x.set_size(projectedPoints_Cam1.size(0), 2);
    i_loop_ub = projectedPoints_Cam1.size(0);
    if ((static_cast<int>((projectedPoints_Cam1.size(0) * 2) < 4)) != 0) {
      for (int i16{0}; i16 < 2; i16++) {
        for (i17 = 0; i17 < i_loop_ub; i17++) {
          e_x[i17 + (e_x.size(0) * i16)] =
              projectedPoints_Cam1[i17 + (projectedPoints_Cam1.size(0) * i16)] -
              imagePointsTmp[i17 + (imagePointsTmp.size(0) * i16)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i17)

      for (int i16 = 0; i16 < 2; i16++) {
        for (i17 = 0; i17 < i_loop_ub; i17++) {
          e_x[i17 + (e_x.size(0) * i16)] =
              projectedPoints_Cam1[i17 + (projectedPoints_Cam1.size(0) * i16)] -
              imagePointsTmp[i17 + (imagePointsTmp.size(0) * i16)];
        }
      }
    }
  } else {
    c_binary_expand_op(e_x, projectedPoints_Cam1, imagePointsTmp);
  }
  varargout_1.set_size(e_x.size(0), 2);
  if (e_x.size(0) != 0) {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_k, i18)

    for (int e_k = 0; e_k < 2; e_k++) {
      i18 = varargout_1.size(0);
      for (g_k = 0; g_k < i18; g_k++) {
        varargout_1[g_k + (varargout_1.size(0) * e_k)] =
            std::abs(e_x[g_k + (e_x.size(0) * e_k)]);
      }
    }
  }
}

} // namespace ITER

//
// File trailer for estimateKnucklePose.cpp
//
// [EOF]
//
