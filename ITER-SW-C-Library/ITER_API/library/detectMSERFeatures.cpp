//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectMSERFeatures.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "detectMSERFeatures.h"
#include "ITER_API_rtwutil.h"
#include "MSERRegions.h"
#include "combineVectorElements.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "detectMserCore_api.hpp"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 2U> &o_I
//                const double varargin_2[2]
//                double varargin_4
//                MSERRegions *regions
// Return Type  : void
//
namespace ITER {
namespace coder {
void detectMSERFeatures(const ::coder::array<unsigned char, 2U> &o_I,
                        const double varargin_2[2], double varargin_4,
                        MSERRegions *regions)
{
  void *ptrRegions;
  ::coder::array<double, 2U> ellipseStruct_Centroid;
  ::coder::array<double, 2U> y;
  ::coder::array<int, 2U> b_pixelList;
  ::coder::array<int, 2U> thisRegion;
  ::coder::array<int, 1U> b_x;
  ::coder::array<int, 1U> b_y;
  ::coder::array<int, 1U> e_x;
  ::coder::array<int, 1U> r;
  ::coder::array<int, 1U> r1;
  ::coder::array<unsigned char, 2U> Iu8;
  float params_maxVariation;
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int i1;
  int i7;
  int loop_ub;
  int numRegions;
  int numTotalPts;
  int params_delta;
  int params_maxArea;
  int params_minArea;
  int startIdx;
  int xsubs_idx_1;
  short ysubs_idx_1;
  if (((varargin_4 * 255.0) / 100.0) < 1.0) {
    params_delta = (int32_T)(1.0);
  } else {
    params_delta = (int32_T)((varargin_4 * 255.0) / 100.0);
  }
  params_minArea = (int32_T)(varargin_2[0]);
  params_maxArea = (int32_T)(varargin_2[1]);
  params_maxVariation = (real32_T)(0.25);
  Iu8.set_size(o_I.size(0), o_I.size(1));
  loop_ub = o_I.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = o_I.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Iu8[i1 + (Iu8.size(0) * b_i)] = o_I[i1 + (o_I.size(0) * b_i)];
    }
  }
  ptrRegions = NULL;
  numTotalPts = 0;
  numRegions = 0;
  if ((o_I.size(0) == 0) || (o_I.size(1) == 0)) {
    b_pixelList.set_size(0, 2);
    regions->Lengths.set_size(0);
  } else {
    detectMser_compute(&Iu8[0], o_I.size(0), o_I.size(1), false, params_delta,
                       params_minArea, params_maxArea, params_maxVariation,
                       0.2F, 200, 1.0, 0.003, 5, &numTotalPts, &numRegions,
                       &ptrRegions);
    b_pixelList.set_size(numTotalPts, 2);
    regions->Lengths.set_size(numRegions);
    detectMser_assignOutput(ptrRegions, numTotalPts, &b_pixelList[0],
                            &(regions->Lengths.data())[0]);
  }
  regions->PixelList.set_size(b_pixelList.size(0), 2);
  regions->Centroid.set_size(regions->Lengths.size(0), 2);
  c_loop_ub = regions->Lengths.size(0);
  regions->Axes.set_size(regions->Lengths.size(0), 2);
  d_loop_ub = regions->Lengths.size(0);
  e_loop_ub = b_pixelList.size(0);
  for (int i2{0}; i2 < 2; i2++) {
    for (int i3{0}; i3 < e_loop_ub; i3++) {
      regions->PixelList[i3 + (regions->PixelList.size(0) * i2)] =
          b_pixelList[i3 + (b_pixelList.size(0) * i2)];
    }
    for (int i5{0}; i5 < c_loop_ub; i5++) {
      regions->Centroid[i5 + (regions->Centroid.size(0) * i2)] = 0.0F;
    }
    for (int i6{0}; i6 < d_loop_ub; i6++) {
      regions->Axes[i6 + (regions->Axes.size(0) * i2)] = 0.0F;
    }
  }
  regions->Orientation.set_size(regions->Lengths.size(0));
  f_loop_ub = regions->Lengths.size(0);
  for (int i4{0}; i4 < f_loop_ub; i4++) {
    regions->Orientation[i4] = 0.0F;
  }
  startIdx = 1;
  i7 = regions->Lengths.size(0);
  for (int idx{0}; idx < i7; idx++) {
    double a_tmp;
    double b_common_tmp;
    double b_ellipseStruct_Centroid;
    double c_ellipseStruct_Centroid;
    double common_tmp;
    double den;
    double ellipseStruct_Axes_idx_0_tmp;
    double ellipseStruct_Orientation;
    double num;
    double uxx;
    double uxy;
    double uyy;
    int b_i8;
    int b_q1;
    int b_qY;
    int c_q1;
    int c_qY;
    int g_loop_ub;
    int h_loop_ub;
    int i9;
    int loop_ub_tmp;
    int qY;
    b_q1 = regions->Lengths[idx];
    if ((startIdx < 0) && (b_q1 < (MIN_int32_T - startIdx))) {
      qY = MIN_int32_T;
    } else if ((startIdx > 0) && (b_q1 > (MAX_int32_T - startIdx))) {
      qY = MAX_int32_T;
    } else {
      qY = startIdx + b_q1;
    }
    if (qY < -2147483647) {
      b_qY = MIN_int32_T;
    } else {
      b_qY = qY - 1;
    }
    if (startIdx > b_qY) {
      b_i8 = -1;
      i9 = -1;
    } else {
      b_i8 = startIdx - 2;
      i9 = b_qY - 1;
    }
    g_loop_ub = i9 - b_i8;
    thisRegion.set_size(g_loop_ub, 2);
    for (int i10{0}; i10 < 2; i10++) {
      for (int i11{0}; i11 < g_loop_ub; i11++) {
        thisRegion[i11 + (thisRegion.size(0) * i10)] =
            b_pixelList[((b_i8 + i11) + (b_pixelList.size(0) * i10)) + 1];
      }
    }
    if (g_loop_ub == 0) {
      y.set_size(1, 2);
      for (int i12{0}; i12 < 2; i12++) {
        y[i12] = 0.0;
      }
    } else {
      int firstBlockLength;
      int lastBlockLength;
      int nblocks;
      y.set_size(1, 2);
      if (g_loop_ub <= 1024) {
        firstBlockLength = g_loop_ub;
        lastBlockLength = 0;
        nblocks = 1;
      } else {
        firstBlockLength = 1024;
        nblocks = g_loop_ub / 1024;
        lastBlockLength = g_loop_ub - (nblocks * 1024);
        if (lastBlockLength > 0) {
          nblocks++;
        } else {
          lastBlockLength = 1024;
        }
      }
      for (int k{0}; k < 2; k++) {
        y[k] = static_cast<double>(
            b_pixelList[(b_i8 + (b_pixelList.size(0) * k)) + 1]);
        for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
          if (g_loop_ub >= 2) {
            ysubs_idx_1 = static_cast<short>(k + 1);
            y[k] = y[k] +
                   (static_cast<double>(
                       b_pixelList[(b_i8 + b_k) + (b_pixelList.size(0) * k)]));
          }
        }
        if (2 <= nblocks) {
          xsubs_idx_1 = k + 1;
          ysubs_idx_1 = static_cast<short>(k + 1);
        }
        for (int c_ib{2}; c_ib <= nblocks; c_ib++) {
          double b_bsum;
          int b_hi;
          int bsum_tmp;
          bsum_tmp = b_i8 + ((c_ib - 1) * 1024);
          b_bsum =
              static_cast<double>(b_pixelList[(bsum_tmp + (b_pixelList.size(0) *
                                                           (xsubs_idx_1 - 1))) +
                                              1]);
          if (c_ib == nblocks) {
            b_hi = lastBlockLength;
          } else {
            b_hi = 1024;
          }
          for (int c_k{2}; c_k <= b_hi; c_k++) {
            double c_bsum;
            c_bsum = b_bsum;
            if (g_loop_ub >= 2) {
              c_bsum =
                  b_bsum +
                  (static_cast<double>(b_pixelList[(bsum_tmp + c_k) +
                                                   (b_pixelList.size(0) * k)]));
            }
            b_bsum = c_bsum;
          }
          y[(static_cast<int>(ysubs_idx_1)) - 1] =
              y[(static_cast<int>(ysubs_idx_1)) - 1] + b_bsum;
        }
      }
    }
    ellipseStruct_Centroid.set_size(1, 2);
    for (int i13{0}; i13 < 2; i13++) {
      ellipseStruct_Centroid[i13] = y[i13] / (static_cast<double>(g_loop_ub));
    }
    b_ellipseStruct_Centroid = ellipseStruct_Centroid[0];
    loop_ub_tmp = g_loop_ub - 1;
    b_x.set_size(g_loop_ub);
    for (int i14{0}; i14 <= loop_ub_tmp; i14++) {
      double d;
      int i16;
      d = std::round((static_cast<double>(thisRegion[i14])) -
                     b_ellipseStruct_Centroid);
      if (d < 2.147483648E+9) {
        if (d >= -2.147483648E+9) {
          i16 = static_cast<int>(d);
        } else {
          i16 = MIN_int32_T;
        }
      } else if (d >= 2.147483648E+9) {
        i16 = MAX_int32_T;
      } else {
        i16 = 0;
      }
      b_x[i14] = i16;
    }
    c_ellipseStruct_Centroid = ellipseStruct_Centroid[1];
    b_y.set_size(g_loop_ub);
    for (int i15{0}; i15 <= loop_ub_tmp; i15++) {
      double b_d1;
      int i17;
      int saturatedUnaryMinus;
      b_d1 = std::round(
          (static_cast<double>(thisRegion[i15 + thisRegion.size(0)])) -
          c_ellipseStruct_Centroid);
      if (b_d1 < 2.147483648E+9) {
        if (b_d1 >= -2.147483648E+9) {
          i17 = static_cast<int>(b_d1);
        } else {
          i17 = MIN_int32_T;
        }
      } else if (b_d1 >= 2.147483648E+9) {
        i17 = MAX_int32_T;
      } else {
        i17 = 0;
      }
      if (i17 <= MIN_int32_T) {
        saturatedUnaryMinus = MAX_int32_T;
      } else {
        saturatedUnaryMinus = -i17;
      }
      b_y[i15] = saturatedUnaryMinus;
    }
    b_power(b_x, r);
    uxx = (c_combineVectorElements(r) / (static_cast<double>(b_x.size(0)))) +
          0.083333333333333329;
    b_power(b_y, r1);
    uyy = (c_combineVectorElements(r1) / (static_cast<double>(b_x.size(0)))) +
          0.083333333333333329;
    e_x.set_size(b_x.size(0));
    h_loop_ub = b_x.size(0);
    for (int i18{0}; i18 < h_loop_ub; i18++) {
      e_x[i18] = mul_s32_sat(b_x[i18], b_y[i18]);
    }
    uxy = c_combineVectorElements(e_x) / (static_cast<double>(b_x.size(0)));
    a_tmp = uxx - uyy;
    common_tmp = 4.0 * (uxy * uxy);
    b_common_tmp = std::sqrt((a_tmp * a_tmp) + common_tmp);
    ellipseStruct_Axes_idx_0_tmp = uxx + uyy;
    if (uyy > uxx) {
      double b_a_tmp;
      b_a_tmp = uyy - uxx;
      num = b_a_tmp + std::sqrt((b_a_tmp * b_a_tmp) + common_tmp);
      den = 2.0 * uxy;
    } else {
      num = 2.0 * uxy;
      den = a_tmp + b_common_tmp;
    }
    if ((num == 0.0) && (den == 0.0)) {
      ellipseStruct_Orientation = 0.0;
    } else {
      ellipseStruct_Orientation = std::atan(num / den);
    }
    regions->Centroid[idx] = static_cast<float>(ellipseStruct_Centroid[0]);
    regions->Axes[idx] = static_cast<float>(static_cast<double>(
        2.8284271247461903 *
        std::sqrt(ellipseStruct_Axes_idx_0_tmp + b_common_tmp)));
    regions->Centroid[idx + regions->Centroid.size(0)] =
        static_cast<float>(ellipseStruct_Centroid[1]);
    regions->Axes[idx + regions->Axes.size(0)] =
        static_cast<float>(static_cast<double>(
            2.8284271247461903 *
            std::sqrt(ellipseStruct_Axes_idx_0_tmp - b_common_tmp)));
    regions->Orientation[idx] = static_cast<float>(ellipseStruct_Orientation);
    c_q1 = regions->Lengths[idx];
    if ((startIdx < 0) && (c_q1 < (MIN_int32_T - startIdx))) {
      c_qY = MIN_int32_T;
    } else if ((startIdx > 0) && (c_q1 > (MAX_int32_T - startIdx))) {
      c_qY = MAX_int32_T;
    } else {
      c_qY = startIdx + c_q1;
    }
    startIdx = c_qY;
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for detectMSERFeatures.cpp
//
// [EOF]
//
