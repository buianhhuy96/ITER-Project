//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CalculateCost.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "CalculateCost.h"
#include "calibrateOneCamera_data.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_rtwutil.h"
#include "calibrateOneCamera_types.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &calib
//                const double refCalibration_CameraParameters_ImageSize[2]
//                const ::coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions const ::coder::array<double,
//                2U> &genPoints const ::coder::array<double, 3U> &detPoints
//                ::coder::array<double, 1U> &cost
// Return Type  : void
//
namespace Codegen {
void CalculateCost(
    const ::coder::array<double, 1U> &calib,
    const double refCalibration_CameraParameters_ImageSize[2],
    const ::coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const ::coder::array<double, 2U> &genPoints,
    const ::coder::array<double, 3U> &detPoints,
    ::coder::array<double, 1U> &cost)
{
  ::coder::array<cell_wrap_0, 2U> PatternPositions;
  ::coder::array<double, 2U> b_points;
  ::coder::array<double, 2U> c_a;
  ::coder::array<double, 2U> centeredPoints;
  ::coder::array<double, 2U> projectedPointsnorm;
  ::coder::array<double, 2U> projectedPointsraw;
  ::coder::array<double, 2U> result;
  ::coder::array<double, 1U> b;
  ::coder::array<double, 1U> b_b;
  ::coder::array<double, 1U> r;
  ::coder::array<double, 1U> r1;
  ::coder::array<double, 1U> r2;
  ::coder::array<double, 1U> r4;
  ::coder::array<double, 1U> xNorm;
  ::coder::array<double, 1U> xyProduct;
  ::coder::array<double, 1U> yNorm;
  ::coder::array<int, 2U> b_r2;
  ::coder::array<bool, 1U> b_x;
  e_struct_T CameraParameters;
  double b_PatternPositions[3][4];
  double cameraMatrix[3][4];
  double c_PatternPositions[3][3];
  double b_k[3];
  double sz[2];
  int acoef;
  int b_i;
  bool y[3];
  //  Changed for 1 camera
  unserializeCalib(calib, refCalibration_CameraParameters_ImageSize,
                   refCalibration_PatternPositions, &CameraParameters,
                   PatternPositions);
  acoef = static_cast<int>(
      static_cast<double>((static_cast<double>(PatternPositions.size(1))) *
                          (static_cast<double>(genPoints.size(0)))));
  cost.set_size(acoef);
  for (b_i = 0; b_i < acoef; b_i++) {
    cost[b_i] = 0.0;
  }
  b_i = PatternPositions.size(1);
  for (int g_n{0}; g_n < b_i; g_n++) {
    int i1;
    int j;
    int k;
    int loop_ub;
    bool empty_non_axis_sizes;
    bool exitg1;
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
        if (PatternPositions[g_n].f1[0][k] == 0.0) {
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
        if (PatternPositions[g_n].f1[1][k] == 0.0) {
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
        if (PatternPositions[g_n].f1[2][k] == 0.0) {
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
        double b_a;
        double d;
        double s;
        int subsY_idx_1;
        for (loop_ub = 0; loop_ub < 3; loop_ub++) {
          s = 0.0;
          for (k = 0; k < 3; k++) {
            s += (static_cast<double>(iv[loop_ub][k])) *
                 PatternPositions[g_n].f1[k][3];
            c_PatternPositions[k][loop_ub] =
                ((PatternPositions[g_n].f1[0][loop_ub] *
                  (static_cast<double>(iv[k][0]))) +
                 (PatternPositions[g_n].f1[1][loop_ub] *
                  (static_cast<double>(iv[k][1])))) +
                (PatternPositions[g_n].f1[2][loop_ub] *
                 (static_cast<double>(iv[k][2])));
          }
          b_k[loop_ub] = s;
        }
        for (i1 = 0; i1 < 3; i1++) {
          b_PatternPositions[i1][0] = c_PatternPositions[i1][0];
          b_PatternPositions[i1][1] = c_PatternPositions[i1][1];
          b_PatternPositions[i1][2] = c_PatternPositions[i1][2];
          b_PatternPositions[i1][3] = b_k[i1];
        }
        for (i1 = 0; i1 < 4; i1++) {
          d = b_PatternPositions[0][i1];
          s = b_PatternPositions[1][i1];
          b_a = b_PatternPositions[2][i1];
          for (j = 0; j < 3; j++) {
            cameraMatrix[j][i1] =
                ((d * CameraParameters.IntrinsicMatrix[j][0]) +
                 (s * CameraParameters.IntrinsicMatrix[j][1])) +
                (b_a * CameraParameters.IntrinsicMatrix[j][2]);
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
          loop_ub = genPoints.size(1);
        } else if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          loop_ub = genPoints.size(1);
        } else {
          loop_ub = 0;
        }
        if (empty_non_axis_sizes) {
          subsY_idx_1 = 1;
        } else if (genPoints.size(0) != 0) {
          subsY_idx_1 = 1;
        } else {
          subsY_idx_1 = 0;
        }
        result.set_size(acoef, loop_ub + subsY_idx_1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          for (j = 0; j < acoef; j++) {
            result[j + (result.size(0) * i1)] = genPoints[j + (acoef * i1)];
          }
        }
        for (i1 = 0; i1 < subsY_idx_1; i1++) {
          for (j = 0; j < acoef; j++) {
            result[j + (result.size(0) * loop_ub)] = 1.0;
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
          acoef = static_cast<int>(projectedPointsraw.size(0) != 1);
          subsY_idx_1 = static_cast<int>(projectedPointsraw.size(0) != 1);
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
        sz[0] = CameraParameters.IntrinsicMatrix[0][2];
        sz[1] = CameraParameters.IntrinsicMatrix[1][2];
        centeredPoints.set_size(projectedPointsnorm.size(0), 2);
        if (projectedPointsnorm.size(0) != 0) {
          acoef = static_cast<int>(projectedPointsnorm.size(0) != 1);
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
          yNorm[i1] = centeredPoints[i1 + centeredPoints.size(0)] /
                      CameraParameters.IntrinsicMatrix[1][1];
        }
        loop_ub = centeredPoints.size(0);
        xNorm.set_size(centeredPoints.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          xNorm[i1] =
              centeredPoints[i1] / CameraParameters.IntrinsicMatrix[0][0];
        }
        i1 = xNorm.size(0);
        r.set_size(xNorm.size(0));
        for (k = 0; k < i1; k++) {
          r[k] = rt_powd_snf(xNorm[k], 2.0);
        }
        i1 = yNorm.size(0);
        r1.set_size(yNorm.size(0));
        for (k = 0; k < i1; k++) {
          r1[k] = rt_powd_snf(yNorm[k], 2.0);
        }
        loop_ub = r.size(0);
        r2.set_size(r.size(0));
        for (i1 = 0; i1 < loop_ub; i1++) {
          r2[i1] = r[i1] + r1[i1];
        }
        r4.set_size(r2.size(0));
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r4[i1] = r2[i1] * r2[i1];
        }
        b_k[0] = CameraParameters.RadialDistortion[0];
        b_k[1] = CameraParameters.RadialDistortion[1];
        r4.set_size(r2.size(0));
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          r4[i1] = ((b_k[0] * r2[i1]) + (b_k[1] * r4[i1])) +
                   (CameraParameters.RadialDistortion[2] * (r2[i1] * r4[i1]));
        }
        xyProduct.set_size(xNorm.size(0));
        loop_ub = xNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          xyProduct[i1] = xNorm[i1] * yNorm[i1];
        }
        i1 = xNorm.size(0);
        b.set_size(xNorm.size(0));
        for (k = 0; k < i1; k++) {
          b[k] = rt_powd_snf(xNorm[k], 2.0);
        }
        s = 2.0 * CameraParameters.TangentialDistortion[0];
        i1 = yNorm.size(0);
        b_b.set_size(yNorm.size(0));
        for (k = 0; k < i1; k++) {
          b_b[k] = rt_powd_snf(yNorm[k], 2.0);
        }
        b_a = 2.0 * CameraParameters.TangentialDistortion[1];
        projectedPointsnorm.set_size(xNorm.size(0), 2);
        loop_ub = xNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          projectedPointsnorm[i1] = xNorm[i1];
        }
        loop_ub = yNorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          projectedPointsnorm[i1 + projectedPointsnorm.size(0)] = yNorm[i1];
        }
        centeredPoints.set_size(projectedPointsnorm.size(0), 2);
        loop_ub = projectedPointsnorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          d = projectedPointsnorm[i1];
          centeredPoints[i1] = d + (d * r4[i1]);
        }
        loop_ub = projectedPointsnorm.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          d = projectedPointsnorm[i1 + projectedPointsnorm.size(0)];
          centeredPoints[i1 + centeredPoints.size(0)] = d + (d * r4[i1]);
        }
        c_a.set_size(xyProduct.size(0), 2);
        loop_ub = xyProduct.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_a[i1] =
              (s * xyProduct[i1]) + (CameraParameters.TangentialDistortion[1] *
                                     (r2[i1] + (2.0 * b[i1])));
        }
        loop_ub = r2.size(0);
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_a[i1 + c_a.size(0)] = (CameraParameters.TangentialDistortion[0] *
                                   (r2[i1] + (2.0 * b_b[i1]))) +
                                  (b_a * xyProduct[i1]);
        }
        centeredPoints.set_size(centeredPoints.size(0), 2);
        for (i1 = 0; i1 < 2; i1++) {
          loop_ub = centeredPoints.size(0);
          for (j = 0; j < loop_ub; j++) {
            centeredPoints[j + (centeredPoints.size(0) * i1)] =
                centeredPoints[j + (centeredPoints.size(0) * i1)] +
                c_a[j + (c_a.size(0) * i1)];
          }
        }
        if (centeredPoints.size(0) == b_points.size(0)) {
          loop_ub = centeredPoints.size(0);
          acoef = centeredPoints.size(0);
          projectedPointsnorm.set_size(centeredPoints.size(0), 2);
          for (i1 = 0; i1 < loop_ub; i1++) {
            projectedPointsnorm[i1] =
                ((centeredPoints[i1] * CameraParameters.IntrinsicMatrix[0][0]) +
                 CameraParameters.IntrinsicMatrix[0][2]) +
                (CameraParameters.IntrinsicMatrix[0][1] *
                 centeredPoints[i1 + centeredPoints.size(0)]);
          }
          for (i1 = 0; i1 < acoef; i1++) {
            projectedPointsnorm[i1 + projectedPointsnorm.size(0)] =
                (centeredPoints[i1 + centeredPoints.size(0)] *
                 CameraParameters.IntrinsicMatrix[1][1]) +
                CameraParameters.IntrinsicMatrix[1][2];
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
                           &CameraParameters, b_points);
        }
        if (projectedPointsnorm.size(0) == 0) {
          yNorm.set_size(0);
        } else {
          yNorm.set_size(projectedPointsnorm.size(0));
          i1 = projectedPointsnorm.size(0);
          for (k = 0; k < i1; k++) {
            yNorm[k] = projectedPointsnorm[k];
          }
          i1 = projectedPointsnorm.size(0);
          for (k = 0; k < i1; k++) {
            yNorm[k] =
                yNorm[k] + projectedPointsnorm[k + projectedPointsnorm.size(0)];
          }
        }
        i1 = yNorm.size(0);
        for (k = 0; k < i1; k++) {
          yNorm[k] = std::sqrt(yNorm[k]);
        }
        d = ((((static_cast<double>(g_n)) + 1.0) - 1.0) *
             (static_cast<double>(yNorm.size(0)))) +
            1.0;
        s = ((static_cast<double>(g_n)) + 1.0) *
            (static_cast<double>(yNorm.size(0)));
        if (d > s) {
          i1 = 0;
          j = 0;
        } else {
          i1 = (static_cast<int>(d)) - 1;
          j = static_cast<int>(s);
        }
        loop_ub = j - i1;
        b_r2.set_size(1, loop_ub);
        for (j = 0; j < loop_ub; j++) {
          b_r2[j] = i1 + j;
        }
        loop_ub = b_r2.size(1);
        for (i1 = 0; i1 < loop_ub; i1++) {
          cost[b_r2[i1]] = yNorm[i1];
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
