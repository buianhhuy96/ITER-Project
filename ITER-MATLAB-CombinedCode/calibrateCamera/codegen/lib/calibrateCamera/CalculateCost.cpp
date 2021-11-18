//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CalculateCost.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "CalculateCost.h"
#include "calibrateCamera_rtwutil.h"
#include "calibrateCamera_types.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 1U> &calib
//                const struct1_T *refCalibration_CameraParameters
//                const ::coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions const ::coder::array<real_T,
//                3U> &refCalibration_ImagePoints const ::coder::array<real_T,
//                2U> &genPoints const ::coder::array<real_T, 3U> &detPoints
//                ::coder::array<real_T, 1U> &cost
// Return Type  : void
//
namespace Codegen {
void CalculateCost(
    const ::coder::array<real_T, 1U> &calib,
    const struct1_T *refCalibration_CameraParameters,
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<real_T, 3U> &refCalibration_ImagePoints,
    const ::coder::array<real_T, 2U> &genPoints,
    const ::coder::array<real_T, 3U> &detPoints,
    ::coder::array<real_T, 1U> &cost)
{
  static const int8_T b[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  ::coder::array<cell_wrap_0, 2U> calibrationConverted_PatternPositions;
  ::coder::array<real_T, 3U> expl_temp;
  ::coder::array<real_T, 2U> b_points;
  ::coder::array<real_T, 2U> centeredPoints;
  ::coder::array<real_T, 2U> projectedPointsnorm;
  ::coder::array<real_T, 2U> projectedPointsraw;
  ::coder::array<real_T, 2U> r1;
  ::coder::array<real_T, 2U> result;
  ::coder::array<real_T, 1U> b_b;
  ::coder::array<real_T, 1U> r;
  ::coder::array<real_T, 1U> r2;
  ::coder::array<real_T, 1U> r4;
  ::coder::array<real_T, 1U> xNorm;
  ::coder::array<real_T, 1U> yNorm;
  ::coder::array<boolean_T, 1U> b_x;
  struct1_T calibrationConverted_CameraParameters;
  real_T calibrationConverted_PatternPos[3][4];
  real_T cameraMatrix[3][4];
  real_T b_calibrationConverted_PatternPos[3][3];
  real_T b_k[3];
  real_T sz[2];
  int32_T acoef;
  int32_T b_i;
  boolean_T y[3];
  //  Changed for 1 camera
  unserializeCalib(calib, refCalibration_CameraParameters,
                   refCalibration_PatternPositions, refCalibration_ImagePoints,
                   &calibrationConverted_CameraParameters,
                   calibrationConverted_PatternPositions, expl_temp);
  acoef = static_cast<int32_T>(static_cast<real_T>(
      (static_cast<real_T>(calibrationConverted_PatternPositions.size(1))) *
      (static_cast<real_T>(genPoints.size(0)))));
  cost.set_size(acoef);
  for (b_i = 0; b_i < acoef; b_i++) {
    cost[b_i] = 0.0;
  }
  b_i = calibrationConverted_PatternPositions.size(1);
  for (int32_T g_n{0}; g_n < b_i; g_n++) {
    int32_T i1;
    int32_T j;
    int32_T k;
    int32_T loop_ub;
    boolean_T empty_non_axis_sizes;
    boolean_T exitg1;
    //  for each image
    loop_ub = detPoints.size(0);
    b_points.set_size(detPoints.size(0), 2);
    for (i1 = 0; i1 < 2; i1++) {
      for (j = 0; j < loop_ub; j++) {
        b_points[j + (b_points.size(0) * i1)] =
            detPoints[(j + (detPoints.size(0) * i1)) +
                      ((detPoints.size(0) * detPoints.size(1)) * g_n)];
      }
    }
    acoef = detPoints.size(0) * 2;
    b_x.set_size(acoef);
    for (i1 = 0; i1 < acoef; i1++) {
      b_x[i1] = std::isnan(b_points[i1]);
    }
    empty_non_axis_sizes = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
      if (!b_x[k]) {
        empty_non_axis_sizes = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!empty_non_axis_sizes) {
      y[0] = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (calibrationConverted_PatternPositions[g_n].f1[0][k] == 0.0) {
          y[0] = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      y[1] = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (calibrationConverted_PatternPositions[g_n].f1[1][k] == 0.0) {
          y[1] = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      y[2] = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (calibrationConverted_PatternPositions[g_n].f1[2][k] == 0.0) {
          y[2] = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      empty_non_axis_sizes = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (!y[k]) {
          empty_non_axis_sizes = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (empty_non_axis_sizes) {
        real_T d;
        real_T s;
        int32_T subsY_idx_1;
        int8_T i2;
        for (loop_ub = 0; loop_ub < 3; loop_ub++) {
          s = 0.0;
          for (k = 0; k < 3; k++) {
            s += (static_cast<real_T>(b[loop_ub][k])) *
                 calibrationConverted_PatternPositions[g_n].f1[k][3];
            b_calibrationConverted_PatternPos[k][loop_ub] =
                ((calibrationConverted_PatternPositions[g_n].f1[0][loop_ub] *
                  (static_cast<real_T>(b[k][0]))) +
                 (calibrationConverted_PatternPositions[g_n].f1[1][loop_ub] *
                  (static_cast<real_T>(b[k][1])))) +
                (calibrationConverted_PatternPositions[g_n].f1[2][loop_ub] *
                 (static_cast<real_T>(b[k][2])));
          }
          b_k[loop_ub] = s;
        }
        for (i1 = 0; i1 < 3; i1++) {
          calibrationConverted_PatternPos[i1][0] =
              b_calibrationConverted_PatternPos[i1][0];
          calibrationConverted_PatternPos[i1][1] =
              b_calibrationConverted_PatternPos[i1][1];
          calibrationConverted_PatternPos[i1][2] =
              b_calibrationConverted_PatternPos[i1][2];
          calibrationConverted_PatternPos[i1][3] = b_k[i1];
        }
        for (i1 = 0; i1 < 4; i1++) {
          real_T b_d1;
          s = calibrationConverted_PatternPos[0][i1];
          d = calibrationConverted_PatternPos[1][i1];
          b_d1 = calibrationConverted_PatternPos[2][i1];
          for (j = 0; j < 3; j++) {
            cameraMatrix[j][i1] =
                ((s *
                  calibrationConverted_CameraParameters.IntrinsicMatrix[j][0]) +
                 (d * calibrationConverted_CameraParameters
                          .IntrinsicMatrix[j][1])) +
                (b_d1 *
                 calibrationConverted_CameraParameters.IntrinsicMatrix[j][2]);
          }
        }
        if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          acoef = genPoints.size(0);
        } else if (genPoints.size(0) != 0) {
          acoef = genPoints.size(0);
        } else {
          acoef = 0;
        }
        empty_non_axis_sizes = (acoef == 0);
        if (empty_non_axis_sizes) {
          i2 = static_cast<int8_T>(genPoints.size(1));
        } else if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          i2 = static_cast<int8_T>(genPoints.size(1));
        } else {
          i2 = 0;
        }
        if (empty_non_axis_sizes) {
          subsY_idx_1 = 1;
        } else if (genPoints.size(0) != 0) {
          subsY_idx_1 = 1;
        } else {
          subsY_idx_1 = 0;
        }
        result.set_size(acoef, (static_cast<int32_T>(i2)) + subsY_idx_1);
        loop_ub = static_cast<int32_T>(i2);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (j = 0; j < acoef; j++) {
            result[j + (result.size(0) * i1)] = genPoints[j + (acoef * i1)];
          }
        }
        for (i1 = 0; i1 < subsY_idx_1; i1++) {
          for (j = 0; j < acoef; j++) {
            result[j + (result.size(0) * (static_cast<int32_T>(i2)))] = 1.0;
          }
        }
        acoef = result.size(0) - 1;
        subsY_idx_1 = result.size(1);
        projectedPointsraw.set_size(result.size(0), 3);
        for (j = 0; j < 3; j++) {
          for (loop_ub = 0; loop_ub <= acoef; loop_ub++) {
            projectedPointsraw[loop_ub + (projectedPointsraw.size(0) * j)] =
                0.0;
          }
          for (k = 0; k < subsY_idx_1; k++) {
            for (loop_ub = 0; loop_ub <= acoef; loop_ub++) {
              projectedPointsraw[loop_ub + (projectedPointsraw.size(0) * j)] =
                  projectedPointsraw[loop_ub +
                                     (projectedPointsraw.size(0) * j)] +
                  (result[loop_ub + (result.size(0) * k)] * cameraMatrix[j][k]);
            }
          }
        }
        if (projectedPointsraw.size(0) == 1) {
          i1 = 1;
        } else if (projectedPointsraw.size(0) == 1) {
          i1 = 1;
        } else {
          i1 = projectedPointsraw.size(0);
        }
        projectedPointsnorm.set_size(i1, 2);
        if (i1 != 0) {
          acoef = static_cast<int32_T>(projectedPointsraw.size(0) != 1);
          subsY_idx_1 = static_cast<int32_T>(projectedPointsraw.size(0) != 1);
          for (k = 0; k < 2; k++) {
            i1 = projectedPointsnorm.size(0) - 1;
            for (loop_ub = 0; loop_ub <= i1; loop_ub++) {
              projectedPointsnorm[loop_ub + (projectedPointsnorm.size(0) * k)] =
                  projectedPointsraw[(acoef * loop_ub) +
                                     (projectedPointsraw.size(0) * k)] /
                  projectedPointsraw[(subsY_idx_1 * loop_ub) +
                                     (projectedPointsraw.size(0) * 2)];
            }
          }
        }
        sz[0] = calibrationConverted_CameraParameters.IntrinsicMatrix[0][2];
        sz[1] = calibrationConverted_CameraParameters.IntrinsicMatrix[1][2];
        centeredPoints.set_size(projectedPointsnorm.size(0), 2);
        if (projectedPointsnorm.size(0) != 0) {
          acoef = static_cast<int32_T>(projectedPointsnorm.size(0) != 1);
          for (k = 0; k < 2; k++) {
            i1 = centeredPoints.size(0) - 1;
            for (loop_ub = 0; loop_ub <= i1; loop_ub++) {
              centeredPoints[loop_ub + (centeredPoints.size(0) * k)] =
                  projectedPointsnorm[(acoef * loop_ub) +
                                      (projectedPointsnorm.size(0) * k)] -
                  sz[k];
            }
          }
        }
        loop_ub = centeredPoints.size(0);
        yNorm.set_size(centeredPoints.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          yNorm[i1] =
              centeredPoints[i1 + centeredPoints.size(0)] /
              calibrationConverted_CameraParameters.IntrinsicMatrix[1][1];
        }
        loop_ub = centeredPoints.size(0);
        xNorm.set_size(centeredPoints.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          xNorm[i1] =
              centeredPoints[i1] /
              calibrationConverted_CameraParameters.IntrinsicMatrix[0][0];
        }
        i1 = xNorm.size(0);
        b_b.set_size(xNorm.size(0));
        for (k = 0; k < i1; k++) {
          b_b[k] = rt_powd_snf(xNorm[k], 2.0);
        }
        r2.set_size(yNorm.size(0));
        acoef = yNorm.size(0);
        for (k = 0; k < acoef; k++) {
          r2[k] = rt_powd_snf(yNorm[k], 2.0);
        }
        loop_ub = b_b.size(0);
        r2.set_size(b_b.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          r2[i1] = b_b[i1] + r2[i1];
        }
        r4.set_size(r2.size(0));
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r4[i1] = r2[i1] * r2[i1];
        }
        b_k[0] = calibrationConverted_CameraParameters.RadialDistortion[0];
        b_k[1] = calibrationConverted_CameraParameters.RadialDistortion[1];
        r4.set_size(r2.size(0));
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r4[i1] = ((b_k[0] * r2[i1]) + (b_k[1] * r4[i1])) +
                   (calibrationConverted_CameraParameters.RadialDistortion[2] *
                    (r2[i1] * r4[i1]));
        }
        r.set_size(xNorm.size(0));
        loop_ub = xNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r[i1] = 0.0 * (xNorm[i1] * yNorm[i1]);
        }
        projectedPointsnorm.set_size(xNorm.size(0), 2);
        loop_ub = xNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          projectedPointsnorm[i1] = xNorm[i1];
        }
        loop_ub = yNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          projectedPointsnorm[i1 + projectedPointsnorm.size(0)] = yNorm[i1];
        }
        xNorm.set_size(yNorm.size(0));
        acoef = yNorm.size(0);
        for (k = 0; k < acoef; k++) {
          xNorm[k] = rt_powd_snf(yNorm[k], 2.0);
        }
        centeredPoints.set_size(projectedPointsnorm.size(0), 2);
        loop_ub = projectedPointsnorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          s = projectedPointsnorm[i1];
          centeredPoints[i1] = s + (s * r4[i1]);
        }
        loop_ub = projectedPointsnorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          s = projectedPointsnorm[i1 + projectedPointsnorm.size(0)];
          centeredPoints[i1 + centeredPoints.size(0)] = s + (s * r4[i1]);
        }
        r1.set_size(r.size(0), 2);
        loop_ub = r.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i1] = r[i1] + (0.0 * (r2[i1] + (2.0 * b_b[i1])));
        }
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r1[i1 + r1.size(0)] = (0.0 * (r2[i1] + (2.0 * xNorm[i1]))) + r[i1];
        }
        centeredPoints.set_size(centeredPoints.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          loop_ub = centeredPoints.size(0);
          for (j = 0; j < loop_ub; j++) {
            centeredPoints[j + (centeredPoints.size(0) * i1)] =
                centeredPoints[j + (centeredPoints.size(0) * i1)] +
                r1[j + (r1.size(0) * i1)];
          }
        }
        if (centeredPoints.size(0) == b_points.size(0)) {
          loop_ub = centeredPoints.size(0);
          acoef = centeredPoints.size(0);
          projectedPointsnorm.set_size(centeredPoints.size(0), 2);
          for (i1 = 0; i1 < loop_ub; i1++) {
            projectedPointsnorm[i1] =
                ((centeredPoints[i1] *
                  calibrationConverted_CameraParameters.IntrinsicMatrix[0][0]) +
                 calibrationConverted_CameraParameters.IntrinsicMatrix[0][2]) +
                (calibrationConverted_CameraParameters.IntrinsicMatrix[0][1] *
                 centeredPoints[i1 + centeredPoints.size(0)]);
          }
          for (i1 = 0; i1 < acoef; i1++) {
            projectedPointsnorm[i1 + projectedPointsnorm.size(0)] =
                (centeredPoints[i1 + centeredPoints.size(0)] *
                 calibrationConverted_CameraParameters.IntrinsicMatrix[1][1]) +
                calibrationConverted_CameraParameters.IntrinsicMatrix[1][2];
          }
          projectedPointsnorm.set_size(projectedPointsnorm.size(0), 2);
          for (i1 = 0; i1 < 2; i1++) {
            loop_ub = projectedPointsnorm.size(0);
            for (j = 0; j < loop_ub; j++) {
              s = projectedPointsnorm[j + (projectedPointsnorm.size(0) * i1)] -
                  b_points[j + (b_points.size(0) * i1)];
              projectedPointsnorm[j + (projectedPointsnorm.size(0) * i1)] =
                  s * s;
            }
          }
        } else {
          binary_expand_op(projectedPointsnorm, centeredPoints,
                           &calibrationConverted_CameraParameters, b_points);
        }
        if (projectedPointsnorm.size(0) == 0) {
          xNorm.set_size(0);
        } else {
          xNorm.set_size(projectedPointsnorm.size(0));
          i1 = projectedPointsnorm.size(0);
          for (k = 0; k < i1; k++) {
            xNorm[k] = projectedPointsnorm[k];
          }
          i1 = projectedPointsnorm.size(0);
          for (k = 0; k < i1; k++) {
            xNorm[k] =
                xNorm[k] + projectedPointsnorm[k + projectedPointsnorm.size(0)];
          }
        }
        i1 = xNorm.size(0);
        for (k = 0; k < i1; k++) {
          xNorm[k] = std::sqrt(xNorm[k]);
        }
        s = ((((static_cast<real_T>(g_n)) + 1.0) - 1.0) *
             (static_cast<real_T>(xNorm.size(0)))) +
            1.0;
        d = ((static_cast<real_T>(g_n)) + 1.0) *
            (static_cast<real_T>(xNorm.size(0)));
        if (s > d) {
          i1 = -1;
          j = 0;
        } else {
          i1 = (static_cast<int32_T>(s)) - 2;
          j = static_cast<int32_T>(d);
        }
        loop_ub = (j - i1) - 1;
        for (j = 0; j < loop_ub; j++) {
          cost[(i1 + j) + 1] = xNorm[j];
        }
      }
    }
  }
}

} // namespace Codegen

//
// File trailer for CalculateCost.cpp
//
// [EOF]
//
