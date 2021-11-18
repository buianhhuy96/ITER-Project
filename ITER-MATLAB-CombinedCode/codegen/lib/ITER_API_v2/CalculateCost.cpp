//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CalculateCost.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "CalculateCost.h"
#include "ITER_API_v2_data.h"
#include "ITER_API_v2_internal_types3.h"
#include "ITER_API_v2_types.h"
#include "distortPoints.h"
#include "rt_nonfinite.h"
#include "unsafeSxfun.h"
#include "unserializeCalib.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const coder::array<double, 1U> &calib
//                const double refCalibration_CameraParameters_ImageSize[2]
//                const coder::array<cell_wrap_0, 2U>
//                &refCalibration_PatternPositions const coder::array<double,
//                2U> &genPoints const coder::array<double, 3U> &detPoints
//                coder::array<double, 1U> &cost
// Return Type  : void
//
void CalculateCost(
    const coder::array<double, 1U> &calib,
    const double refCalibration_CameraParameters_ImageSize[2],
    const coder::array<cell_wrap_0, 2U> &refCalibration_PatternPositions,
    const coder::array<double, 2U> &genPoints,
    const coder::array<double, 3U> &detPoints, coder::array<double, 1U> &cost)
{
  coder::array<cell_wrap_0, 2U> PatternPositions;
  coder::array<double, 2U> b_points;
  coder::array<double, 2U> b_result;
  coder::array<double, 2U> distortedPoints;
  coder::array<double, 2U> projectedPointsnorm;
  coder::array<double, 2U> projectedPointsraw;
  coder::array<double, 2U> r;
  coder::array<double, 1U> b_error;
  coder::array<int, 2U> r1;
  coder::array<bool, 1U> b_x;
  struct0_T CameraParameters;
  double b_PatternPositions[3][4];
  double cameraMatrix[3][4];
  double c_PatternPositions[3][3];
  double e_y[3];
  int PatternPositions_idx_0;
  int b_loop_ub;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  bool b_y[3];
  //  Changed for 1 camera
  unserializeCalib(calib, refCalibration_CameraParameters_ImageSize,
                   refCalibration_PatternPositions, &CameraParameters,
                   PatternPositions);
  PatternPositions_idx_0 = static_cast<int>(
      static_cast<double>((static_cast<double>(PatternPositions.size(1))) *
                          (static_cast<double>(genPoints.size(0)))));
  cost.set_size(PatternPositions_idx_0);
  for (int b_i{0}; b_i < PatternPositions_idx_0; b_i++) {
    cost[b_i] = 0.0;
  }
  i1 = PatternPositions.size(1);
  if (0 <= (PatternPositions.size(1) - 1)) {
    i2 = detPoints.size(0);
    loop_ub = detPoints.size(0);
    i3 = detPoints.size(0) * 2;
    b_loop_ub = i3;
  }
  for (int h_n{0}; h_n < i1; h_n++) {
    int k;
    bool exitg1;
    bool y;
    //  for each image
    b_points.set_size(i2, 2);
    for (int i4{0}; i4 < 2; i4++) {
      for (int i5{0}; i5 < loop_ub; i5++) {
        b_points[i5 + (b_points.size(0) * i4)] =
            detPoints[(i5 + (detPoints.size(0) * i4)) +
                      ((detPoints.size(0) * detPoints.size(1)) * h_n)];
      }
    }
    b_x.set_size(i3);
    for (int i6{0}; i6 < b_loop_ub; i6++) {
      b_x[i6] = std::isnan(b_points[i6]);
    }
    y = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
      if (!b_x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!y) {
      int b_k;
      int c_k;
      bool d_y;
      b_y[0] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (PatternPositions[h_n].f1[0][b_k] == 0.0) {
          b_y[0] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      b_y[1] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (PatternPositions[h_n].f1[1][b_k] == 0.0) {
          b_y[1] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      b_y[2] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (PatternPositions[h_n].f1[2][b_k] == 0.0) {
          b_y[2] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      d_y = true;
      c_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c_k < 3)) {
        if (!b_y[c_k]) {
          d_y = false;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
      if (d_y) {
        double d3;
        double d4;
        int c_loop_ub;
        int d_loop_ub;
        int f_loop_ub;
        int g_loop_ub;
        int i15;
        int i20;
        int i22;
        int i23;
        int inner;
        int mc;
        int result;
        signed char i10;
        bool empty_non_axis_sizes;
        for (int c_i{0}; c_i < 3; c_i++) {
          double s;
          s = 0.0;
          for (int d_k{0}; d_k < 3; d_k++) {
            s += (static_cast<double>(iv[c_i][d_k])) *
                 PatternPositions[h_n].f1[d_k][3];
            c_PatternPositions[d_k][c_i] =
                ((PatternPositions[h_n].f1[0][c_i] *
                  (static_cast<double>(iv[d_k][0]))) +
                 (PatternPositions[h_n].f1[1][c_i] *
                  (static_cast<double>(iv[d_k][1])))) +
                (PatternPositions[h_n].f1[2][c_i] *
                 (static_cast<double>(iv[d_k][2])));
          }
          e_y[c_i] = s;
        }
        for (int i7{0}; i7 < 3; i7++) {
          b_PatternPositions[i7][0] = c_PatternPositions[i7][0];
          b_PatternPositions[i7][1] = c_PatternPositions[i7][1];
          b_PatternPositions[i7][2] = c_PatternPositions[i7][2];
          b_PatternPositions[i7][3] = e_y[i7];
        }
        for (int i8{0}; i8 < 4; i8++) {
          double b_d1;
          double d;
          double d2;
          d = b_PatternPositions[0][i8];
          b_d1 = b_PatternPositions[1][i8];
          d2 = b_PatternPositions[2][i8];
          for (int i9{0}; i9 < 3; i9++) {
            cameraMatrix[i9][i8] =
                ((d * CameraParameters.IntrinsicMatrix[i9][0]) +
                 (b_d1 * CameraParameters.IntrinsicMatrix[i9][1])) +
                (d2 * CameraParameters.IntrinsicMatrix[i9][2]);
          }
        }
        if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          result = genPoints.size(0);
        } else if (genPoints.size(0) != 0) {
          result = genPoints.size(0);
        } else {
          result = 0;
        }
        empty_non_axis_sizes = (result == 0);
        if (empty_non_axis_sizes) {
          c_loop_ub = genPoints.size(1);
        } else if ((genPoints.size(0) != 0) && (genPoints.size(1) != 0)) {
          c_loop_ub = genPoints.size(1);
        } else {
          c_loop_ub = 0;
        }
        if (empty_non_axis_sizes) {
          i10 = 1;
        } else if (genPoints.size(0) != 0) {
          i10 = 1;
        } else {
          i10 = 0;
        }
        b_result.set_size(result, c_loop_ub + (static_cast<int>(i10)));
        for (int i11{0}; i11 < c_loop_ub; i11++) {
          for (int i12{0}; i12 < result; i12++) {
            b_result[i12 + (b_result.size(0) * i11)] =
                genPoints[i12 + (result * i11)];
          }
        }
        d_loop_ub = static_cast<int>(i10);
        for (int i13{0}; i13 < d_loop_ub; i13++) {
          for (int i14{0}; i14 < result; i14++) {
            b_result[i14 + (b_result.size(0) * c_loop_ub)] = 1.0;
          }
        }
        mc = b_result.size(0) - 1;
        inner = b_result.size(1);
        projectedPointsraw.set_size(b_result.size(0), 3);
        for (int j{0}; j < 3; j++) {
          for (int e_i{0}; e_i <= mc; e_i++) {
            projectedPointsraw[e_i + (projectedPointsraw.size(0) * j)] = 0.0;
          }
          for (int e_k{0}; e_k < inner; e_k++) {
            for (int g_i{0}; g_i <= mc; g_i++) {
              projectedPointsraw[g_i + (projectedPointsraw.size(0) * j)] =
                  projectedPointsraw[g_i + (projectedPointsraw.size(0) * j)] +
                  (b_result[g_i + (b_result.size(0) * e_k)] *
                   cameraMatrix[j][e_k]);
            }
          }
        }
        if (projectedPointsraw.size(0) == 1) {
          i15 = 1;
        } else if (projectedPointsraw.size(0) == 1) {
          i15 = 1;
        } else {
          i15 = projectedPointsraw.size(0);
        }
        projectedPointsnorm.set_size(i15, 2);
        if (i15 != 0) {
          int acoef;
          int bcoef;
          acoef = static_cast<int>(projectedPointsraw.size(0) != 1);
          bcoef = static_cast<int>(projectedPointsraw.size(0) != 1);
          for (int f_k{0}; f_k < 2; f_k++) {
            int i16;
            i16 = projectedPointsnorm.size(0) - 1;
            for (int g_k{0}; g_k <= i16; g_k++) {
              projectedPointsnorm[g_k + (projectedPointsnorm.size(0) * f_k)] =
                  projectedPointsraw[(acoef * g_k) +
                                     (projectedPointsraw.size(0) * f_k)] /
                  projectedPointsraw[(bcoef * g_k) +
                                     (projectedPointsraw.size(0) * 2)];
            }
          }
        }
        coder::vision::internal::calibration::distortPoints(
            projectedPointsnorm, CameraParameters.IntrinsicMatrix,
            CameraParameters.RadialDistortion,
            CameraParameters.TangentialDistortion, distortedPoints);
        if (distortedPoints.size(0) == b_points.size(0)) {
          int e_loop_ub;
          r.set_size(distortedPoints.size(0), 2);
          e_loop_ub = distortedPoints.size(0);
          for (int i17{0}; i17 < 2; i17++) {
            for (int i19{0}; i19 < e_loop_ub; i19++) {
              double varargin_1;
              varargin_1 =
                  distortedPoints[i19 + (distortedPoints.size(0) * i17)] -
                  b_points[i19 + (b_points.size(0) * i17)];
              r[i19 + (r.size(0) * i17)] = varargin_1 * varargin_1;
            }
          }
        } else {
          binary_expand_op(r, distortedPoints, b_points);
        }
        if (r.size(0) == 0) {
          b_error.set_size(0);
        } else {
          int i18;
          int i21;
          b_error.set_size(r.size(0));
          i18 = r.size(0);
          for (int h_k{0}; h_k < i18; h_k++) {
            b_error[h_k] = r[h_k];
          }
          i21 = r.size(0);
          for (int j_k{0}; j_k < i21; j_k++) {
            b_error[j_k] = b_error[j_k] + r[j_k + r.size(0)];
          }
        }
        i20 = b_error.size(0);
        for (int i_k{0}; i_k < i20; i_k++) {
          b_error[i_k] = std::sqrt(b_error[i_k]);
        }
        d3 = ((((static_cast<double>(h_n)) + 1.0) - 1.0) *
              (static_cast<double>(b_error.size(0)))) +
             1.0;
        d4 = ((static_cast<double>(h_n)) + 1.0) *
             (static_cast<double>(b_error.size(0)));
        if (d3 > d4) {
          i22 = 0;
          i23 = 0;
        } else {
          i22 = (static_cast<int>(d3)) - 1;
          i23 = static_cast<int>(d4);
        }
        f_loop_ub = i23 - i22;
        r1.set_size(1, f_loop_ub);
        for (int i24{0}; i24 < f_loop_ub; i24++) {
          r1[i24] = i22 + i24;
        }
        g_loop_ub = r1.size(1);
        for (int i25{0}; i25 < g_loop_ub; i25++) {
          cost[r1[i25]] = b_error[i25];
        }
      }
    }
  }
}

//
// File trailer for CalculateCost.cpp
//
// [EOF]
//
