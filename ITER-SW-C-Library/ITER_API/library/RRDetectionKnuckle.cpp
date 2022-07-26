//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RRDetectionKnuckle.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "RRDetectionKnuckle.h"
#include "CompactClassificationEnsemble.h"
#include "ITER_API_data.h"
#include "ITER_API_initialize.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_types.h"
#include "MSERRegions.h"
#include "detectMSERFeatures.h"
#include "find.h"
#include "groupOverlapRegions.h"
#include "horzcatStructList.h"
#include "inv.h"
#include "mean.h"
#include "regionprops.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "wrapperNNOrdering.h"
#include "coder_array.h"
#include <string.h>

// Function Declarations
namespace ITER {
static void minus(::coder::array<double, 2U> &diffCentroids,
                  const ::coder::array<double, 2U> &allCentroid2D,
                  const ::coder::array<double, 2U> &meanAllCentroids);

}

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &diffCentroids
//                const ::coder::array<double, 2U> &allCentroid2D
//                const ::coder::array<double, 2U> &meanAllCentroids
// Return Type  : void
//
namespace ITER {
static void minus(::coder::array<double, 2U> &diffCentroids,
                  const ::coder::array<double, 2U> &allCentroid2D,
                  const ::coder::array<double, 2U> &meanAllCentroids)
{
  int aux_0_1;
  int aux_1_1;
  int b_i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (meanAllCentroids.size(1) == 1) {
    b_i = allCentroid2D.size(1);
  } else {
    b_i = meanAllCentroids.size(1);
  }
  diffCentroids.set_size(allCentroid2D.size(0), b_i);
  stride_0_1 = static_cast<int>(allCentroid2D.size(1) != 1);
  stride_1_1 = static_cast<int>(meanAllCentroids.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (meanAllCentroids.size(1) == 1) {
    loop_ub = allCentroid2D.size(1);
  } else {
    loop_ub = meanAllCentroids.size(1);
  }
  for (int i1{0}; i1 < loop_ub; i1++) {
    int b_loop_ub;
    b_loop_ub = allCentroid2D.size(0);
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      diffCentroids[i2 + (diffCentroids.size(0) * i1)] =
          allCentroid2D[i2 + (allCentroid2D.size(0) * aux_0_1)] -
          meanAllCentroids[aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

//
// Arguments    : const ::coder::array<unsigned char, 4U> &ImgVGA
//                const struct2_T *params
//                const double f_K[3][3]
//                ::coder::array<double, 2U> &markerCentroidsOrdered
//                int *err
// Return Type  : void
//
void RRDetectionKnuckle(const ::coder::array<unsigned char, 4U> &ImgVGA,
                        const struct2_T *params, const double f_K[3][3],
                        ::coder::array<double, 2U> &markerCentroidsOrdered,
                        int *err)
{
  coder::MSERRegions regions;
  coder::classreg::learning::classif::CompactClassificationEnsemble Mdl;
  ::coder::array<f_struct_T, 1U> stats_grey;
  ::coder::array<h_struct_T, 1U> stats;
  ::coder::array<double, 2U> A;
  ::coder::array<double, 2U> allCentroid2D;
  ::coder::array<double, 2U> allCentroids2D;
  ::coder::array<double, 2U> b_varargin_1;
  ::coder::array<double, 2U> c_varargin_1;
  ::coder::array<double, 2U> d_varargin_1;
  ::coder::array<double, 2U> diffCentroids;
  ::coder::array<double, 2U> e_x;
  ::coder::array<double, 2U> expl_temp;
  ::coder::array<double, 2U> markerCentroids;
  ::coder::array<double, 2U> meanAllCentroids;
  ::coder::array<double, 2U> properties;
  ::coder::array<double, 2U> score;
  ::coder::array<double, 2U> varargin_1;
  ::coder::array<double, 2U> y;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> c_properties;
  ::coder::array<double, 1U> label;
  ::coder::array<int, 2U> uniqueRegions_PixelList;
  ::coder::array<int, 1U> e_ii;
  ::coder::array<int, 1U> iidx;
  ::coder::array<int, 1U> r;
  ::coder::array<unsigned char, 2U> b_ImgVGA;
  ::coder::array<bool, 2U> BWImg;
  double fullImagePts[2][5];
  double fullMkCentroids[2][5];
  double e_B[3][3];
  double i_x[5];
  double b_params[2];
  int b_iidx[5];
  int b_iv[2];
  int b_result[2];
  int c_result[2];
  int b_err;
  int b_loop_ub;
  int cb_loop_ub;
  int f_loop_ub;
  int fb_loop_ub;
  int i1;
  int i24;
  int i27;
  int i3;
  int i34;
  int i37;
  int i41;
  int i42;
  int i44;
  int i46;
  int i51;
  int i53;
  int i54;
  int i56;
  int i7;
  int k;
  int k_i;
  int loop_ub;
  int m_i;
  int mb_loop_ub;
  int ob_loop_ub;
  int rb_loop_ub;
  int sb_loop_ub;
  int y_loop_ub;
  signed char o_I[2][2];
  if (!isInitialized_ITER_API) {
    ITER_API_initialize();
  }
  loop_ub = ImgVGA.size(0);
  b_ImgVGA.set_size(ImgVGA.size(0), ImgVGA.size(1));
  b_loop_ub = ImgVGA.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1)

  for (int b_i = 0; b_i < b_loop_ub; b_i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_ImgVGA[i1 + (b_ImgVGA.size(0) * b_i)] =
          ImgVGA[i1 + (ImgVGA.size(0) * b_i)];
    }
  }
  b_err = 0;
  //  Detect MSER
  b_params[0] = params->minArea;
  b_params[1] = params->maxArea;
  coder::detectMSERFeatures(b_ImgVGA, b_params, params->ThresholdDelta,
                            &regions);
  if ((regions.PixelList.size(0) == 0) || (regions.PixelList.size(1) == 0)) {
    markerCentroidsOrdered.set_size(0, 0);
    b_err = -101;
  } else {
    int ab_loop_ub;
    int b_input_sizes_idx_1;
    int b_j;
    int b_properties;
    int bb_loop_ub;
    int c_j;
    int c_loop_ub;
    int d_j;
    int d_loop_ub;
    int db_loop_ub;
    int e_loop_ub;
    int eb_loop_ub;
    int g_loop_ub;
    int g_x;
    int h_loop_ub;
    int h_n;
    int hb_loop_ub;
    int i14;
    int i17;
    int i20;
    int i22;
    int i26;
    int i29;
    int i32;
    int i9;
    int i_loop_ub;
    int inner;
    int input_sizes_idx_1;
    int j;
    int j_loop_ub;
    int jb_loop_ub;
    int k_loop_ub;
    int kb_loop_ub;
    int m_loop_ub;
    int mc;
    int o_loop_ub;
    int p_loop_ub;
    int p_n;
    int pb_loop_ub;
    int q_loop_ub;
    int q_n;
    int qb_loop_ub;
    int r_loop_ub;
    int result;
    int s_loop_ub;
    int s_n;
    int siz;
    int t_loop_ub;
    int u_loop_ub;
    int v_loop_ub;
    int w_loop_ub;
    int x_loop_ub;
    signed char c_input_sizes_idx_1;
    signed char d_input_sizes_idx_1;
    bool empty_non_axis_sizes;
    //  Group Overlappign Regions
    groupOverlapRegions(&regions, b_ImgVGA, uniqueRegions_PixelList, expl_temp);
    b_iv[0] = ImgVGA.size(0);
    BWImg.set_size(ImgVGA.size(0), ImgVGA.size(1));
    c_loop_ub = ImgVGA.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    f_loop_ub)

    for (int i2 = 0; i2 < c_loop_ub; i2++) {
      f_loop_ub = b_iv[0];
      for (i3 = 0; i3 < f_loop_ub; i3++) {
        BWImg[i3 + (BWImg.size(0) * i2)] = false;
      }
    }
    siz = ImgVGA.size(0);
    d_loop_ub = uniqueRegions_PixelList.size(0);
    r.set_size(uniqueRegions_PixelList.size(0));
    e_loop_ub = uniqueRegions_PixelList.size(0);
    if ((static_cast<int>(uniqueRegions_PixelList.size(0) < 4)) != 0) {
      for (int i4{0}; i4 < d_loop_ub; i4++) {
        r[i4] = uniqueRegions_PixelList[i4 + uniqueRegions_PixelList.size(0)] +
                (ImgVGA.size(0) * (uniqueRegions_PixelList[i4] - 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < e_loop_ub; i4++) {
        r[i4] = uniqueRegions_PixelList[i4 + uniqueRegions_PixelList.size(0)] +
                (siz * (uniqueRegions_PixelList[i4] - 1));
      }
    }
    g_loop_ub = r.size(0);
    for (int i5{0}; i5 < g_loop_ub; i5++) {
      BWImg[r[i5] - 1] = true;
    }
    // figure; imshow (BWImg, []);
    //  Filtering Candidates
    coder::regionprops(BWImg, stats);
    coder::b_regionprops(BWImg, b_ImgVGA, stats_grey);
    properties.set_size(stats.size(0), 8);
    h_loop_ub = stats.size(0);
    if ((static_cast<int>((stats.size(0) * 8) < 4)) != 0) {
      for (int i6{0}; i6 < 8; i6++) {
        for (i7 = 0; i7 < h_loop_ub; i7++) {
          properties[i7 + (properties.size(0) * i6)] = rtNaN;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7)

      for (int i6 = 0; i6 < 8; i6++) {
        for (i7 = 0; i7 < h_loop_ub; i7++) {
          properties[i7 + (properties.size(0) * i6)] = rtNaN;
        }
      }
    }
    i_loop_ub = stats.size(0);
    r.set_size(stats.size(0));
    j_loop_ub = stats.size(0);
    if ((static_cast<int>(stats.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 < i_loop_ub; b_i8++) {
        r[b_i8] = b_i8;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 < j_loop_ub; b_i8++) {
        r[b_i8] = b_i8;
      }
    }
    h_n = stats.size(0);
    if (stats.size(0) == 0) {
      i9 = 0;
    } else {
      i9 = stats.size(0);
    }
    varargin_1.set_size(1, i9);
    j = 0;
    for (int c_i{0}; c_i < h_n; c_i++) {
      varargin_1[varargin_1.size(0) * j] = stats[c_i].Area;
      j++;
    }
    k_loop_ub = r.size(0);
    for (int i10{0}; i10 < k_loop_ub; i10++) {
      properties[r[i10]] = varargin_1[i10];
    }
    b_properties = properties.size(0) - 1;
    c_properties.set_size(properties.size(0));
    m_loop_ub = properties.size(0) - 1;
    if ((static_cast<int>(properties.size(0) < 4)) != 0) {
      for (int i11{0}; i11 <= b_properties; i11++) {
        c_properties[i11] = properties[i11] / params->maxArea;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i11 = 0; i11 <= m_loop_ub; i11++) {
        c_properties[i11] = properties[i11] / params->maxArea;
      }
    }
    o_loop_ub = c_properties.size(0);
    if ((static_cast<int>(c_properties.size(0) < 4)) != 0) {
      for (int i12{0}; i12 < o_loop_ub; i12++) {
        properties[i12] = c_properties[i12];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i12 = 0; i12 < o_loop_ub; i12++) {
        properties[i12] = c_properties[i12];
      }
    }
    // properties(:,1) = [stats.Area]./mean([stats.Area]);
    p_loop_ub = properties.size(0);
    r.set_size(properties.size(0));
    q_loop_ub = properties.size(0);
    if ((static_cast<int>(properties.size(0) < 4)) != 0) {
      for (int i13{0}; i13 < p_loop_ub; i13++) {
        r[i13] = i13;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i13 = 0; i13 < q_loop_ub; i13++) {
        r[i13] = i13;
      }
    }
    p_n = stats.size(0);
    if (stats.size(0) == 0) {
      i14 = 0;
    } else {
      i14 = stats.size(0);
    }
    b_varargin_1.set_size(1, i14);
    b_j = 0;
    for (int d_i{0}; d_i < p_n; d_i++) {
      b_varargin_1[b_varargin_1.size(0) * b_j] = stats[d_i].Circularity;
      b_j++;
    }
    r_loop_ub = r.size(0);
    for (int i15{0}; i15 < r_loop_ub; i15++) {
      properties[r[i15] + properties.size(0)] = b_varargin_1[i15];
    }
    // (4*Area*pi)/(Perimeter2)
    // properties(:,3) = [stats.Solidity]; % Area/ConvexArea
    s_loop_ub = properties.size(0);
    r.set_size(properties.size(0));
    t_loop_ub = properties.size(0);
    if ((static_cast<int>(properties.size(0) < 4)) != 0) {
      for (int i16{0}; i16 < s_loop_ub; i16++) {
        r[i16] = i16;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i16 = 0; i16 < t_loop_ub; i16++) {
        r[i16] = i16;
      }
    }
    q_n = stats.size(0);
    if (stats.size(0) == 0) {
      i17 = 0;
    } else {
      i17 = stats.size(0);
    }
    c_varargin_1.set_size(1, i17);
    c_j = 0;
    for (int e_i{0}; e_i < q_n; e_i++) {
      c_varargin_1[c_varargin_1.size(0) * c_j] = stats[e_i].Extent;
      c_j++;
    }
    u_loop_ub = r.size(0);
    for (int i18{0}; i18 < u_loop_ub; i18++) {
      properties[r[i18] + (properties.size(0) * 3)] = c_varargin_1[i18];
    }
    //  Area/ bounding box Area
    v_loop_ub = properties.size(0);
    r.set_size(properties.size(0));
    w_loop_ub = properties.size(0);
    if ((static_cast<int>(properties.size(0) < 4)) != 0) {
      for (int i19{0}; i19 < v_loop_ub; i19++) {
        r[i19] = i19;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i19 = 0; i19 < w_loop_ub; i19++) {
        r[i19] = i19;
      }
    }
    s_n = stats_grey.size(0);
    if (stats_grey.size(0) == 0) {
      i20 = 0;
    } else {
      i20 = stats_grey.size(0);
    }
    d_varargin_1.set_size(1, i20);
    d_j = 0;
    for (int g_i{0}; g_i < s_n; g_i++) {
      d_varargin_1[d_varargin_1.size(0) * d_j] = stats_grey[g_i].MeanIntensity;
      d_j++;
    }
    x_loop_ub = r.size(0);
    for (int i21{0}; i21 < x_loop_ub; i21++) {
      properties[r[i21] + (properties.size(0) * 4)] = d_varargin_1[i21] / 255.0;
    }
    //  Feature: centroid with respect to average of centroids.
    coder::internal::horzcatStructList(stats_grey, varargin_1);
    if (varargin_1.size(0) == 0) {
      input_sizes_idx_1 = varargin_1.size(1);
    } else if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      input_sizes_idx_1 = varargin_1.size(1);
    } else {
      input_sizes_idx_1 = 0;
    }
    i22 = static_cast<int>(
        static_cast<double>((static_cast<double>(input_sizes_idx_1)) / 2.0));
    b_iv[1] = i22;
    allCentroid2D.set_size(i22, 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i24,       \
                                                                    y_loop_ub)

    for (int i23 = 0; i23 < 2; i23++) {
      y_loop_ub = b_iv[1];
      for (i24 = 0; i24 < y_loop_ub; i24++) {
        allCentroid2D[i24 + (allCentroid2D.size(0) * i23)] =
            varargin_1[i23 + (2 * i24)];
      }
    }
    coder::b_mean(allCentroid2D, meanAllCentroids);
    if (2 == meanAllCentroids.size(1)) {
      diffCentroids.set_size(allCentroid2D.size(0), 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i27, cb_loop_ub)

      for (int i25 = 0; i25 < 2; i25++) {
        cb_loop_ub = allCentroid2D.size(0);
        for (i27 = 0; i27 < cb_loop_ub; i27++) {
          diffCentroids[i27 + (diffCentroids.size(0) * i25)] =
              allCentroid2D[i27 + (allCentroid2D.size(0) * i25)] -
              meanAllCentroids[i25];
        }
      }
    } else {
      minus(diffCentroids, allCentroid2D, meanAllCentroids);
    }
    i26 = ImgVGA.size(1);
    ab_loop_ub = diffCentroids.size(0);
    bb_loop_ub = diffCentroids.size(0);
    if ((static_cast<int>(diffCentroids.size(0) < 4)) != 0) {
      for (int i28{0}; i28 < ab_loop_ub; i28++) {
        properties[i28 + (properties.size(0) * 6)] =
            diffCentroids[i28] / (static_cast<double>(i26));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i28 = 0; i28 < bb_loop_ub; i28++) {
        properties[i28 + (properties.size(0) * 6)] =
            diffCentroids[i28] / (static_cast<double>(i26));
      }
    }
    i29 = ImgVGA.size(1);
    db_loop_ub = diffCentroids.size(0);
    eb_loop_ub = diffCentroids.size(0);
    if ((static_cast<int>(diffCentroids.size(0) < 4)) != 0) {
      for (int i30{0}; i30 < db_loop_ub; i30++) {
        properties[i30 + (properties.size(0) * 7)] =
            diffCentroids[i30 + diffCentroids.size(0)] /
            (static_cast<double>(i29));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i30 = 0; i30 < eb_loop_ub; i30++) {
        properties[i30 + (properties.size(0) * 7)] =
            diffCentroids[i30 + diffCentroids.size(0)] /
            (static_cast<double>(i29));
      }
    }
    //  Classifies marker candidates into into Marker/ Not marker
    //  using templateTree Model in the file SVMIris.mat, and
    //  returns class labels in label.
    Mdl.ClassNames[0] = 0.0;
    Mdl.ClassNamesLength[0] = 1;
    Mdl.ClassLogicalIndices[0] = true;
    Mdl.ClassNames[1] = 1.0;
    Mdl.ClassNamesLength[1] = 1;
    Mdl.ClassLogicalIndices[1] = true;
    Mdl.ScoreTransform = coder::classreg::learning::coderutils::Identity;
    for (int h_i{0}; h_i < 100; h_i++) {
      Mdl.LearnerWeights[h_i] = 1.0;
      Mdl.IsCached[h_i] = false;
    }
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_ii = 0; c_ii < 2; c_ii++) {
      Mdl.Prior[c_ii] = dv[c_ii];
      o_I[c_ii][0] = 0;
      o_I[c_ii][1] = 0;
    }
    o_I[0][0] = 1;
    o_I[1][1] = 1;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i31 = 0; i31 < 2; i31++) {
      Mdl.Cost[i31][0] = 1.0 - (static_cast<double>(o_I[i31][0]));
      Mdl.Cost[i31][1] = 1.0 - (static_cast<double>(o_I[i31][1]));
    }
    Mdl.predict(properties, label, score);
    //
    coder::internal::horzcatStructList(stats_grey, varargin_1);
    if (varargin_1.size(0) == 0) {
      b_input_sizes_idx_1 = varargin_1.size(1);
    } else if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      b_input_sizes_idx_1 = varargin_1.size(1);
    } else {
      b_input_sizes_idx_1 = 0;
    }
    i32 = static_cast<int>(
        static_cast<double>((static_cast<double>(b_input_sizes_idx_1)) / 2.0));
    b_iv[1] = i32;
    allCentroids2D.set_size(i32, 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i34, fb_loop_ub)

    for (int i33 = 0; i33 < 2; i33++) {
      fb_loop_ub = b_iv[1];
      for (i34 = 0; i34 < fb_loop_ub; i34++) {
        allCentroids2D[i34 + (allCentroids2D.size(0) * i33)] =
            varargin_1[i33 + (2 * i34)];
      }
    }
    //  Which candidates were classified as markers?
    coder::eml_find(label, e_ii);
    //  Temporary solution for false positives: if more than 7, take the 7
    //  with highest score.
    if (e_ii.size(0) > 5) {
      int gb_loop_ub;
      int ib_loop_ub;
      gb_loop_ub = score.size(0);
      b_x.set_size(score.size(0));
      ib_loop_ub = score.size(0);
      if ((static_cast<int>(score.size(0) < 4)) != 0) {
        for (int i36{0}; i36 < gb_loop_ub; i36++) {
          b_x[i36] = score[i36 + score.size(0)];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i36 = 0; i36 < ib_loop_ub; i36++) {
          b_x[i36] = score[i36 + score.size(0)];
        }
      }
      coder::internal::e_sort(b_x, iidx);
      e_ii.set_size(5);
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i38 = 0; i38 < 5; i38++) {
        e_ii[i38] = iidx[i38];
      }
    }
    markerCentroids.set_size(e_ii.size(0), 2);
    hb_loop_ub = e_ii.size(0);
    if ((static_cast<int>((e_ii.size(0) * 2) < 4)) != 0) {
      for (int i35{0}; i35 < 2; i35++) {
        for (i37 = 0; i37 < hb_loop_ub; i37++) {
          markerCentroids[i37 + (markerCentroids.size(0) * i35)] =
              allCentroids2D[(e_ii[i37] + (allCentroids2D.size(0) * i35)) - 1];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i37)

      for (int i35 = 0; i35 < 2; i35++) {
        for (i37 = 0; i37 < hb_loop_ub; i37++) {
          markerCentroids[i37 + (markerCentroids.size(0) * i35)] =
              allCentroids2D[(e_ii[i37] + (allCentroids2D.size(0) * i35)) - 1];
        }
      }
    }
    if (e_ii.size(0) != 0) {
      result = e_ii.size(0);
    } else {
      result = 0;
    }
    empty_non_axis_sizes = (result == 0);
    if (empty_non_axis_sizes) {
      c_input_sizes_idx_1 = 2;
    } else if (e_ii.size(0) != 0) {
      c_input_sizes_idx_1 = 2;
    } else {
      c_input_sizes_idx_1 = 0;
    }
    if (empty_non_axis_sizes) {
      d_input_sizes_idx_1 = 1;
    } else if (e_ii.size(0) != 0) {
      d_input_sizes_idx_1 = 1;
    } else {
      d_input_sizes_idx_1 = 0;
    }
    b_result[0] = result;
    b_result[1] = static_cast<int>(c_input_sizes_idx_1);
    c_result[0] = result;
    c_result[1] = static_cast<int>(d_input_sizes_idx_1);
    A.set_size(result, (static_cast<int>(c_input_sizes_idx_1)) +
                           (static_cast<int>(d_input_sizes_idx_1)));
    jb_loop_ub = static_cast<int>(c_input_sizes_idx_1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i41, mb_loop_ub)

    for (int i39 = 0; i39 < jb_loop_ub; i39++) {
      mb_loop_ub = b_result[0];
      for (i41 = 0; i41 < mb_loop_ub; i41++) {
        A[i41 + (A.size(0) * i39)] = markerCentroids[i41 + (b_result[0] * i39)];
      }
    }
    kb_loop_ub = c_result[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i42, ob_loop_ub)

    for (int i40 = 0; i40 < kb_loop_ub; i40++) {
      ob_loop_ub = c_result[0];
      for (i42 = 0; i42 < ob_loop_ub; i42++) {
        A[i42 + (A.size(0) * b_result[1])] = 1.0;
      }
    }
    coder::inv(f_K, e_B);
    mc = A.size(0) - 1;
    inner = A.size(1);
    y.set_size(A.size(0), 3);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(k_i, k, m_i)

    for (int e_j = 0; e_j < 3; e_j++) {
      for (m_i = 0; m_i <= mc; m_i++) {
        y[m_i + (y.size(0) * e_j)] = 0.0;
      }
      for (k = 0; k < inner; k++) {
        for (k_i = 0; k_i <= mc; k_i++) {
          y[k_i + (y.size(0) * e_j)] = y[k_i + (y.size(0) * e_j)] +
                                       (A[k_i + (A.size(0) * k)] * e_B[e_j][k]);
        }
      }
    }
    //  normalize
    //  If detected markers less than expected, need pad with NANS
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i44)

    for (int i43 = 0; i43 < 2; i43++) {
      for (i44 = 0; i44 < 5; i44++) {
        fullImagePts[i43][i44] = rtNaN;
      }
    }
    e_x.set_size(y.size(0), 3);
    pb_loop_ub = y.size(0);
    if ((static_cast<int>((3 * y.size(0)) < 4)) != 0) {
      for (int i45{0}; i45 < 3; i45++) {
        for (i46 = 0; i46 < pb_loop_ub; i46++) {
          e_x[i46 + (e_x.size(0) * i45)] = y[i46 + (y.size(0) * i45)];
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i46)

      for (int i45 = 0; i45 < 3; i45++) {
        for (i46 = 0; i46 < pb_loop_ub; i46++) {
          e_x[i46 + (e_x.size(0) * i45)] = y[i46 + (y.size(0) * i45)];
        }
      }
    }
    g_x = e_x.size(0) - 1;
    qb_loop_ub = e_x.size(0);
    for (int i47{0}; i47 < 2; i47++) {
      for (int i48{0}; i48 < qb_loop_ub; i48++) {
        e_x[i48 + ((g_x + 1) * i47)] = e_x[i48 + (e_x.size(0) * i47)];
      }
    }
    e_x.set_size(g_x + 1, 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i51, rb_loop_ub)

    for (int i49 = 0; i49 < 2; i49++) {
      rb_loop_ub = e_x.size(0);
      for (i51 = 0; i51 < rb_loop_ub; i51++) {
        fullImagePts[i49][i51] = e_x[i51 + (e_x.size(0) * i49)];
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i53)

    for (int i50 = 0; i50 < 2; i50++) {
      for (i53 = 0; i53 < 5; i53++) {
        fullMkCentroids[i50][i53] = rtNaN;
      }
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    i54, sb_loop_ub)

    for (int i52 = 0; i52 < 2; i52++) {
      sb_loop_ub = markerCentroids.size(0);
      for (i54 = 0; i54 < sb_loop_ub; i54++) {
        fullMkCentroids[i52][i54] =
            markerCentroids[i54 + (markerCentroids.size(0) * i52)];
      }
    }
    wrapperNNOrdering(fullImagePts, i_x);
    coder::internal::f_sort(i_x, b_iidx);
    // Get correspondance from pipeline, not GT
    // {
    // nanRow = find(isnan (fullImagePts(:,1)));
    // IdxsOrdered(nanRow) = [];
    // markerCentroidsOrdered = zeros(size(fullMkCentroids (IdxsOrdered, :)));
    // markerCentroidsOrdered = fullMkCentroids (IdxsOrdered, :);
    //
    // markerCentroidsOrdered(estimatedLabels(nanRow),:) = NaN;
    // }
    markerCentroidsOrdered.set_size(5, 2);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i56)

    for (int i55 = 0; i55 < 2; i55++) {
      for (i56 = 0; i56 < 5; i56++) {
        markerCentroidsOrdered[i56 + (markerCentroidsOrdered.size(0) * i55)] =
            fullMkCentroids[i55][b_iidx[i56] - 1];
      }
    }
  }
  *err = b_err;
}

} // namespace ITER

//
// File trailer for RRDetectionKnuckle.cpp
//
// [EOF]
//
