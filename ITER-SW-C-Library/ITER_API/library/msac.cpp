//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: msac.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "msac.h"
#include "ITER_API_rtwutil.h"
#include "bsxfun.h"
#include "combineVectorElements.h"
#include "minOrMax.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "solveP3P.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &allPoints
//                const double varargin_1[3][3]
//                bool *isFound
//                double bestModelParams_R[3][3]
//                double bestModelParams_t[3]
//                ::coder::array<bool, 1U> &inliers
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace ransac {
void msac(const ::coder::array<double, 2U> &allPoints,
          const double varargin_1[3][3], bool *isFound,
          double bestModelParams_R[3][3], double bestModelParams_t[3],
          ::coder::array<bool, 1U> &inliers)
{
  ::coder::array<double, 3U> b_Rs;
  ::coder::array<double, 2U> Ts;
  ::coder::array<double, 2U> b_allPoints;
  ::coder::array<double, 2U> b_projectedPointsHomog;
  ::coder::array<double, 2U> c_worldPoints;
  ::coder::array<double, 2U> diffs;
  ::coder::array<double, 2U> p;
  ::coder::array<double, 2U> projectedPoints;
  ::coder::array<double, 2U> projectedPointsHomog;
  ::coder::array<double, 2U> samplePoints;
  ::coder::array<double, 2U> worldPointsHomog;
  ::coder::array<double, 2U> z1;
  ::coder::array<double, 1U> b_dis;
  ::coder::array<double, 1U> c_projectedPointsHomog;
  ::coder::array<double, 1U> errors;
  ::coder::array<bool, 1U> b_x;
  double b_modelParams_R[3][4];
  double c_Rs[3][4];
  double cameraMatrix[3][4];
  double d_Rs[3][4];
  double modelParams_R[3][3];
  double b_imagePoints[2][4];
  double hashTbl[4];
  double indices[4];
  double link[4];
  double loc[4];
  double modelParams_t[3];
  double projectedPoint[3];
  double b_ex;
  double bestDis;
  int val[4];
  int b_loop_ub;
  int b_loop_ub_tmp;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int i2;
  int i3;
  int i4;
  int i5;
  int idxTrial;
  int iindx;
  int input_sizes_idx_1;
  int loop_ub;
  int loop_ub_tmp;
  int numPts;
  int numTrials;
  int result;
  signed char b_input_sizes_idx_1;
  bool b_isFound;
  bool c_isFound;
  bool empty_non_axis_sizes;
  numPts = allPoints.size(0);
  idxTrial = 1;
  numTrials = 1000;
  bestDis = 9.0 * (static_cast<double>(allPoints.size(0)));
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 3; b_i++) {
    bestModelParams_R[b_i][0] = rtNaN;
    bestModelParams_R[b_i][1] = rtNaN;
    bestModelParams_R[b_i][2] = rtNaN;
    bestModelParams_t[b_i] = rtNaN;
  }
  inliers.set_size(allPoints.size(0));
  loop_ub = allPoints.size(0);
  if ((static_cast<int>(allPoints.size(0) < 4)) != 0) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      inliers[i1] = false;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < loop_ub; i1++) {
      inliers[i1] = false;
    }
  }
  b_loop_ub = allPoints.size(1);
  if (3 > allPoints.size(1)) {
    i2 = 0;
    i3 = -1;
    i4 = -1;
    i5 = -1;
  } else {
    i2 = 2;
    i3 = allPoints.size(1) - 1;
    i4 = 1;
    i5 = allPoints.size(1) - 1;
  }
  loop_ub_tmp = i3 - i2;
  c_loop_ub = allPoints.size(0);
  b_loop_ub_tmp = i5 - i4;
  d_loop_ub = allPoints.size(0);
  if ((allPoints.size(0) != 0) && (b_loop_ub_tmp != 0)) {
    result = allPoints.size(0);
  } else if (allPoints.size(0) != 0) {
    result = allPoints.size(0);
  } else {
    result = 0;
  }
  empty_non_axis_sizes = (result == 0);
  if (empty_non_axis_sizes) {
    input_sizes_idx_1 = i5 - i4;
  } else if ((allPoints.size(0) != 0) && (b_loop_ub_tmp != 0)) {
    input_sizes_idx_1 = i5 - i4;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes) {
    b_input_sizes_idx_1 = 1;
  } else if (allPoints.size(0) != 0) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  e_loop_ub = static_cast<int>(b_input_sizes_idx_1);
  while (idxTrial <= numTrials) {
    double accDis;
    int end;
    int g_loop_ub;
    int h_loop_ub;
    int inner;
    int mc;
    for (int i6{0}; i6 < 4; i6++) {
      indices[i6] = 0.0;
    }
    if (4 >= numPts) {
      indices[0] = 1.0;
      for (int d_i{0}; d_i <= (numPts - 2); d_i++) {
        double j;
        j = b_rand() * (((static_cast<double>(d_i)) + 1.0) + 1.0);
        j = std::floor(j);
        indices[d_i + 1] =
            indices[(static_cast<int>(static_cast<double>(j + 1.0))) - 1];
        indices[(static_cast<int>(static_cast<double>(j + 1.0))) - 1] =
            ((static_cast<double>(d_i)) + 1.0) + 1.0;
      }
    } else if (4.0 >= ((static_cast<double>(numPts)) / 4.0)) {
      double b_t;
      b_t = 0.0;
      for (int m{0}; m < 4; m++) {
        double c_u;
        double denom;
        double pt;
        denom = (static_cast<double>(numPts)) - b_t;
        pt = (4.0 - (static_cast<double>(m))) / denom;
        c_u = b_rand();
        while (c_u > pt) {
          b_t++;
          denom--;
          pt += (1.0 - pt) * ((4.0 - (static_cast<double>(m))) / denom);
        }
        double j;
        b_t++;
        j = b_rand() * ((static_cast<double>(m)) + 1.0);
        j = std::floor(j);
        indices[m] =
            indices[(static_cast<int>(static_cast<double>(j + 1.0))) - 1];
        indices[(static_cast<int>(static_cast<double>(j + 1.0))) - 1] = b_t;
      }
    } else {
      double newEntry;
      for (int c_i{0}; c_i < 4; c_i++) {
        hashTbl[c_i] = 0.0;
        link[c_i] = 0.0;
        val[c_i] = 0;
        loc[c_i] = 0.0;
      }
      newEntry = 1.0;
      for (int b_m{0}; b_m < 4; b_m++) {
        double j;
        double r;
        double selectedLoc;
        int nleftm1;
        nleftm1 = (numPts - b_m) - 1;
        selectedLoc = b_rand() * ((static_cast<double>(nleftm1)) + 1.0);
        selectedLoc = std::floor(selectedLoc);
        if (std::isnan(selectedLoc)) {
          r = rtNaN;
        } else if (std::isinf(selectedLoc)) {
          r = rtNaN;
        } else if (selectedLoc == 0.0) {
          r = 0.0;
        } else {
          r = std::fmod(selectedLoc, 4.0);
          if (r == 0.0) {
            r = 0.0;
          } else if (selectedLoc < 0.0) {
            r += 4.0;
          } else {
            /* no actions */
          }
        }
        j = hashTbl[(static_cast<int>(static_cast<double>(r + 1.0))) - 1];
        while ((j > 0.0) && (loc[(static_cast<int>(j)) - 1] != selectedLoc)) {
          j = link[(static_cast<int>(j)) - 1];
        }
        if (j > 0.0) {
          indices[b_m] =
              (static_cast<double>(val[(static_cast<int>(j)) - 1])) + 1.0;
        } else {
          indices[b_m] = selectedLoc + 1.0;
          j = newEntry;
          newEntry++;
          loc[(static_cast<int>(j)) - 1] = selectedLoc;
          link[(static_cast<int>(j)) - 1] =
              hashTbl[(static_cast<int>(static_cast<double>(r + 1.0))) - 1];
          hashTbl[(static_cast<int>(static_cast<double>(r + 1.0))) - 1] = j;
        }
        if ((b_m + 1) < 4) {
          double jlast;
          jlast = hashTbl[static_cast<int>(
              std::fmod(static_cast<double>(nleftm1), 4.0))];
          while ((jlast > 0.0) && (loc[(static_cast<int>(jlast)) - 1] !=
                                   (static_cast<double>(nleftm1)))) {
            jlast = link[(static_cast<int>(jlast)) - 1];
          }
          if (jlast > 0.0) {
            val[(static_cast<int>(j)) - 1] = val[(static_cast<int>(jlast)) - 1];
          } else {
            val[(static_cast<int>(j)) - 1] = nleftm1;
          }
        }
      }
    }
    samplePoints.set_size(4, b_loop_ub);
    for (int b_i8{0}; b_i8 < b_loop_ub; b_i8++) {
      for (int i10{0}; i10 < 4; i10++) {
        samplePoints[i10 + (4 * b_i8)] =
            allPoints[((static_cast<int>(indices[i10])) +
                       (allPoints.size(0) * b_i8)) -
                      1];
      }
    }
    for (int i9{0}; i9 < 2; i9++) {
      for (int i11{0}; i11 < 4; i11++) {
        b_imagePoints[i9][i11] = samplePoints[i11 + (4 * i9)];
      }
    }
    c_worldPoints.set_size(4, loop_ub_tmp + 1);
    for (int i12{0}; i12 <= loop_ub_tmp; i12++) {
      for (int i13{0}; i13 < 4; i13++) {
        c_worldPoints[i13 + (4 * i12)] = samplePoints[i13 + (4 * (i2 + i12))];
      }
    }
    calibration::solveP3P(b_imagePoints, c_worldPoints, varargin_1, b_Rs, Ts);
    p.set_size(1, loop_ub_tmp + 2);
    for (int i14{0}; i14 <= loop_ub_tmp; i14++) {
      p[i14] = c_worldPoints[(4 * i14) + 3];
    }
    p[loop_ub_tmp + 1] = 1.0;
    for (int i15{0}; i15 < 3; i15++) {
      modelParams_R[i15][0] = rtNaN;
      modelParams_R[i15][1] = rtNaN;
      modelParams_R[i15][2] = rtNaN;
      modelParams_t[i15] = rtNaN;
    }
    if (b_Rs.size(2) != 0) {
      int i17;
      errors.set_size(Ts.size(0));
      i17 = Ts.size(0);
      for (int e_i{0}; e_i < i17; e_i++) {
        for (int i19{0}; i19 < 3; i19++) {
          c_Rs[i19][0] = b_Rs[(3 * i19) + (9 * e_i)];
          c_Rs[i19][1] = b_Rs[((3 * i19) + (9 * e_i)) + 1];
          c_Rs[i19][2] = b_Rs[((3 * i19) + (9 * e_i)) + 2];
          c_Rs[i19][3] = Ts[e_i + (Ts.size(0) * i19)];
        }
        for (int i22{0}; i22 < 4; i22++) {
          double d3;
          double d4;
          double d7;
          d3 = c_Rs[0][i22];
          d4 = c_Rs[1][i22];
          d7 = c_Rs[2][i22];
          for (int i30{0}; i30 < 3; i30++) {
            d_Rs[i30][i22] =
                ((d3 * varargin_1[i30][0]) + (d4 * varargin_1[i30][1])) +
                (d7 * varargin_1[i30][2]);
          }
        }
        for (int i25{0}; i25 < 3; i25++) {
          double d6;
          d6 = 0.0;
          for (int i29{0}; i29 < 4; i29++) {
            d6 += p[i29] * d_Rs[i25][i29];
          }
          projectedPoint[i25] = d6;
        }
        double c_d;
        double d5;
        d5 = b_imagePoints[0][3] - (projectedPoint[0] / projectedPoint[2]);
        c_d = d5 * d5;
        d5 = b_imagePoints[1][3] - (projectedPoint[1] / projectedPoint[2]);
        c_d += d5 * d5;
        errors[e_i] = c_d;
      }
      ::ITER::coder::internal::c_minimum(errors, &b_ex, &iindx);
      for (int i20{0}; i20 < 3; i20++) {
        modelParams_t[i20] = Ts[(iindx + (Ts.size(0) * i20)) - 1];
        modelParams_R[i20][0] = b_Rs[(3 * i20) + (9 * (iindx - 1))];
        modelParams_R[i20][1] = b_Rs[((3 * i20) + (9 * (iindx - 1))) + 1];
        modelParams_R[i20][2] = b_Rs[((3 * i20) + (9 * (iindx - 1))) + 2];
      }
    }
    for (int i16{0}; i16 < 3; i16++) {
      b_modelParams_R[i16][0] = modelParams_R[i16][0];
      b_modelParams_R[i16][1] = modelParams_R[i16][1];
      b_modelParams_R[i16][2] = modelParams_R[i16][2];
      b_modelParams_R[i16][3] = modelParams_t[i16];
    }
    for (int i18{0}; i18 < 4; i18++) {
      double b_d1;
      double d;
      double d2;
      d = b_modelParams_R[0][i18];
      b_d1 = b_modelParams_R[1][i18];
      d2 = b_modelParams_R[2][i18];
      for (int i24{0}; i24 < 3; i24++) {
        cameraMatrix[i24][i18] =
            ((d * varargin_1[i24][0]) + (b_d1 * varargin_1[i24][1])) +
            (d2 * varargin_1[i24][2]);
      }
    }
    b_allPoints.set_size(c_loop_ub, b_loop_ub_tmp);
    for (int i21{0}; i21 < b_loop_ub_tmp; i21++) {
      for (int i23{0}; i23 < c_loop_ub; i23++) {
        b_allPoints[i23 + (b_allPoints.size(0) * i21)] =
            allPoints[i23 + (allPoints.size(0) * ((i4 + i21) + 1))];
      }
    }
    worldPointsHomog.set_size(
        result, input_sizes_idx_1 + (static_cast<int>(b_input_sizes_idx_1)));
    for (int i26{0}; i26 < input_sizes_idx_1; i26++) {
      for (int i28{0}; i28 < result; i28++) {
        worldPointsHomog[i28 + (worldPointsHomog.size(0) * i26)] =
            b_allPoints[i28 + (result * i26)];
      }
    }
    for (int i27{0}; i27 < e_loop_ub; i27++) {
      for (int i31{0}; i31 < result; i31++) {
        worldPointsHomog[i31 + (worldPointsHomog.size(0) * input_sizes_idx_1)] =
            1.0;
      }
    }
    mc = worldPointsHomog.size(0) - 1;
    inner = worldPointsHomog.size(1);
    projectedPointsHomog.set_size(worldPointsHomog.size(0), 3);
    for (int b_j{0}; b_j < 3; b_j++) {
      for (int g_i{0}; g_i <= mc; g_i++) {
        projectedPointsHomog[g_i + (projectedPointsHomog.size(0) * b_j)] = 0.0;
      }
      for (int b_k{0}; b_k < inner; b_k++) {
        for (int h_i{0}; h_i <= mc; h_i++) {
          projectedPointsHomog[h_i + (projectedPointsHomog.size(0) * b_j)] =
              projectedPointsHomog[h_i + (projectedPointsHomog.size(0) * b_j)] +
              (worldPointsHomog[h_i + (worldPointsHomog.size(0) * b_k)] *
               cameraMatrix[b_j][b_k]);
        }
      }
    }
    g_loop_ub = projectedPointsHomog.size(0);
    b_projectedPointsHomog.set_size(projectedPointsHomog.size(0), 2);
    for (int i32{0}; i32 < 2; i32++) {
      for (int i33{0}; i33 < g_loop_ub; i33++) {
        b_projectedPointsHomog[i33 + (b_projectedPointsHomog.size(0) * i32)] =
            projectedPointsHomog[i33 + (projectedPointsHomog.size(0) * i32)];
      }
    }
    h_loop_ub = projectedPointsHomog.size(0);
    c_projectedPointsHomog.set_size(projectedPointsHomog.size(0));
    for (int i34{0}; i34 < h_loop_ub; i34++) {
      c_projectedPointsHomog[i34] =
          projectedPointsHomog[i34 + (projectedPointsHomog.size(0) * 2)];
    }
    b_bsxfun(b_projectedPointsHomog, c_projectedPointsHomog, projectedPoints);
    diffs.set_size(d_loop_ub, 2);
    for (int i35{0}; i35 < 2; i35++) {
      for (int i36{0}; i36 < d_loop_ub; i36++) {
        diffs[i36 + (diffs.size(0) * i35)] =
            allPoints[i36 + (allPoints.size(0) * i35)] -
            projectedPoints[i36 + (projectedPoints.size(0) * i35)];
      }
    }
    z1.set_size(diffs.size(0), 2);
    for (int c_k{0}; c_k < 2; c_k++) {
      int i_N;
      i_N = z1.size(0);
      for (int d_k{0}; d_k < i_N; d_k++) {
        z1[d_k + (z1.size(0) * c_k)] =
            rt_powd_snf(diffs[d_k + (diffs.size(0) * c_k)], 2.0);
      }
    }
    sum(z1, b_dis);
    end = b_dis.size(0);
    for (int k_i{0}; k_i < end; k_i++) {
      if (b_dis[k_i] > 9.0) {
        b_dis[k_i] = 9.0;
      }
    }
    accDis = b_combineVectorElements(b_dis);
    if (accDis < bestDis) {
      double inlierProbability;
      int b_u1;
      int b_vlen;
      int d_y;
      int i_loop_ub;
      int j_loop_ub;
      bestDis = accDis;
      inliers.set_size(b_dis.size(0));
      i_loop_ub = b_dis.size(0);
      for (int i37{0}; i37 < i_loop_ub; i37++) {
        inliers[i37] = (b_dis[i37] < 9.0);
      }
      for (int i38{0}; i38 < 3; i38++) {
        bestModelParams_R[i38][0] = modelParams_R[i38][0];
        bestModelParams_R[i38][1] = modelParams_R[i38][1];
        bestModelParams_R[i38][2] = modelParams_R[i38][2];
        bestModelParams_t[i38] = modelParams_t[i38];
      }
      b_x.set_size(b_dis.size(0));
      j_loop_ub = b_dis.size(0);
      for (int i39{0}; i39 < j_loop_ub; i39++) {
        b_x[i39] = (b_dis[i39] < 9.0);
      }
      b_vlen = b_x.size(0);
      if (b_x.size(0) == 0) {
        d_y = 0;
      } else {
        int c_y;
        c_y = static_cast<int>(b_x[0]);
        for (int e_k{2}; e_k <= b_vlen; e_k++) {
          int e_y;
          e_y = c_y;
          if (b_vlen >= 2) {
            e_y = c_y + (static_cast<int>(b_x[e_k - 1]));
          }
          c_y = e_y;
        }
        d_y = c_y;
      }
      inlierProbability = rt_powd_snf(
          (static_cast<double>(d_y)) / (static_cast<double>(numPts)), 4.0);
      if (inlierProbability < 2.2204460492503131E-16) {
        b_u1 = MAX_int32_T;
      } else {
        double d8;
        int i40;
        d8 = std::ceil(-1.9999999999999996 /
                       std::log10(1.0 - inlierProbability));
        if (d8 < 2.147483648E+9) {
          i40 = static_cast<int>(d8);
        } else if (d8 >= 2.147483648E+9) {
          i40 = MAX_int32_T;
        } else {
          i40 = 0;
        }
        b_u1 = i40;
      }
      if (numTrials > b_u1) {
        numTrials = b_u1;
      }
    }
    idxTrial++;
  }
  if (inliers.size(0) != 0) {
    int vlen;
    int y;
    vlen = inliers.size(0);
    y = static_cast<int>(inliers[0]);
    for (int k{2}; k <= vlen; k++) {
      int b_y;
      b_y = y;
      if (vlen >= 2) {
        b_y = y + (static_cast<int>(inliers[k - 1]));
      }
      y = b_y;
    }
    if (y >= 4) {
      b_isFound = true;
    } else {
      b_isFound = false;
    }
  } else {
    b_isFound = false;
  }
  c_isFound = b_isFound;
  if (!b_isFound) {
    int f_loop_ub;
    inliers.set_size(allPoints.size(0));
    f_loop_ub = allPoints.size(0);
    if ((static_cast<int>(allPoints.size(0) < 4)) != 0) {
      for (int i7{0}; i7 < f_loop_ub; i7++) {
        inliers[i7] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i7 = 0; i7 < f_loop_ub; i7++) {
        inliers[i7] = false;
      }
    }
  }
  *isFound = c_isFound;
}

} // namespace ransac
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for msac.cpp
//
// [EOF]
//
