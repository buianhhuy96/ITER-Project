//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: groupOverlapRegions.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "groupOverlapRegions.h"
#include "MSERRegions.h"
#include "combineVectorElements.h"
#include "eml_setop.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "sortrows.h"
#include "unique.h"
#include "coder_array.h"
#include "libmwbwlookup_tbb.h"
#include "libmwddist.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const coder::MSERRegions *regions
//                const ::coder::array<unsigned char, 2U> &ImgVGA
//                ::coder::array<int, 2U> &uniqueRegions_PixelList
//                ::coder::array<double, 2U> &uniqueRegions_Lengths
// Return Type  : void
//
namespace ITER {
void groupOverlapRegions(const coder::MSERRegions *regions,
                         const ::coder::array<unsigned char, 2U> &ImgVGA,
                         ::coder::array<int, 2U> &uniqueRegions_PixelList,
                         ::coder::array<double, 2U> &uniqueRegions_Lengths)
{
  static const double weights[3][3]{
      {1.0, 1.0, 1.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0}};
  static const bool lut[512]{
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  true,  true,  true,  true,  true,  true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  true,  true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  true,  true,  true,
      true,  true,  true,  true,  true,  true,  false, false, true,  true,
      false, false};
  ::coder::array<double, 1U> groups;
  ::coder::array<double, 1U> r;
  ::coder::array<float, 2U> b_D;
  ::coder::array<int, 2U> array1;
  ::coder::array<int, 2U> c;
  ::coder::array<int, 2U> c_f1;
  ::coder::array<int, 2U> f1;
  ::coder::array<int, 2U> r1;
  ::coder::array<int, 2U> r2;
  ::coder::array<int, 2U> regionPixelListGroup;
  ::coder::array<unsigned int, 2U> sizes;
  ::coder::array<int, 2U> varargin_1;
  ::coder::array<int, 1U> b_lengths1;
  ::coder::array<int, 1U> b_regions;
  ::coder::array<int, 1U> c_ib;
  ::coder::array<int, 1U> c_ii;
  ::coder::array<int, 1U> ia;
  ::coder::array<int, 1U> lengths1;
  ::coder::array<int, 1U> r3;
  ::coder::array<signed char, 2U> binaryImage;
  ::coder::array<bool, 2U> BW;
  ::coder::array<bool, 2U> bwout;
  ::coder::array<bool, 2U> dilatedImage;
  ::coder::array<bool, 1U> b_groups;
  double b_dv[2];
  double b_dv1[2];
  double sizeIn[2];
  double groupNum;
  int b_loop_ub;
  int c_loop_ub;
  int f_loop_ub;
  int g_loop_ub;
  int h_loop_ub;
  int i2;
  int i6;
  int i_loop_ub;
  int j_loop_ub;
  int loop_ub;
  bool conn[3][3];
  lengths1.set_size(regions->Lengths.size(0) + 1);
  lengths1[0] = 1;
  loop_ub = regions->Lengths.size(0);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    lengths1[b_i + 1] = regions->Lengths[b_i];
  }
  // i=55
  // pixelList(sum(lengths1(1:i)):sum(lengths(1:i)))
  groups.set_size(regions->Lengths.size(0));
  b_loop_ub = regions->Lengths.size(0);
  if ((static_cast<int>(regions->Lengths.size(0) < 4)) != 0) {
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      groups[i1] = rtNaN;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < b_loop_ub; i1++) {
      groups[i1] = rtNaN;
    }
  }
  // 55
  groupNum = 0.0;
  i2 = regions->Lengths.size(0);
  for (int c_i{0}; c_i < i2; c_i++) {
    double b_d1;
    double d;
    int d_loop_ub;
    int e_loop_ub;
    int i10;
    int i5;
    int i7;
    if (std::isnan(groups[c_i])) {
      groupNum++;
      groups[c_i] = groupNum;
    }
    b_lengths1.set_size(c_i + 1);
    b_regions.set_size(c_i + 1);
    for (int i3{0}; i3 <= c_i; i3++) {
      b_lengths1[i3] = lengths1[i3];
      b_regions[i3] = regions->Lengths[i3];
    }
    d = coder::c_combineVectorElements(b_lengths1);
    b_d1 = coder::c_combineVectorElements(b_regions);
    if (d > b_d1) {
      i5 = 0;
      i7 = 0;
    } else {
      i5 = (static_cast<int>(d)) - 1;
      i7 = static_cast<int>(b_d1);
    }
    d_loop_ub = regions->PixelList.size(1);
    e_loop_ub = i7 - i5;
    array1.set_size(e_loop_ub, regions->PixelList.size(1));
    for (int i9{0}; i9 < d_loop_ub; i9++) {
      for (int i11{0}; i11 < e_loop_ub; i11++) {
        array1[i11 + (array1.size(0) * i9)] =
            regions->PixelList[(i5 + i11) + (regions->PixelList.size(0) * i9)];
      }
    }
    i10 = regions->Lengths.size(0);
    for (int j{0}; j < i10; j++) {
      double d2;
      double d3;
      int i15;
      int i17;
      int o_loop_ub;
      int q_loop_ub;
      int r_loop_ub;
      b_lengths1.set_size(j + 1);
      b_regions.set_size(j + 1);
      for (int i14{0}; i14 <= j; i14++) {
        b_lengths1[i14] = lengths1[i14];
        b_regions[i14] = regions->Lengths[i14];
      }
      d2 = coder::c_combineVectorElements(b_lengths1);
      d3 = coder::c_combineVectorElements(b_regions);
      if (d2 > d3) {
        i15 = 0;
        i17 = 0;
      } else {
        i15 = (static_cast<int>(d2)) - 1;
        i17 = static_cast<int>(d3);
      }
      o_loop_ub = array1.size(1);
      varargin_1.set_size(array1.size(0), array1.size(1));
      for (int i19{0}; i19 < o_loop_ub; i19++) {
        int p_loop_ub;
        p_loop_ub = array1.size(0);
        for (int i20{0}; i20 < p_loop_ub; i20++) {
          varargin_1[i20 + (varargin_1.size(0) * i19)] =
              array1[i20 + (array1.size(0) * i19)];
        }
      }
      coder::sortrows(varargin_1);
      q_loop_ub = regions->PixelList.size(1);
      r_loop_ub = i17 - i15;
      f1.set_size(r_loop_ub, regions->PixelList.size(1));
      for (int i23{0}; i23 < q_loop_ub; i23++) {
        for (int i24{0}; i24 < r_loop_ub; i24++) {
          f1[i24 + (f1.size(0) * i23)] =
              regions
                  ->PixelList[(i15 + i24) + (regions->PixelList.size(0) * i23)];
        }
      }
      coder::sortrows(f1);
      coder::do_rows(varargin_1, f1, c, ia, c_ib);
      if ((c.size(0) * c.size(1)) > 1) {
        if (std::isnan(groups[j])) {
          //  && abs(size(array1,1)-size(array2,1))< 200
          groups[j] = groupNum;
        }
      }
    }
  }
  uniqueRegions_PixelList.set_size(0, 2);
  // indexes = [];
  coder::unique_vector(groups, r);
  sizes.set_size(1, r.size(0));
  c_loop_ub = r.size(0);
  if ((static_cast<int>(r.size(0) < 4)) != 0) {
    for (int i4{0}; i4 < c_loop_ub; i4++) {
      sizes[i4] = 0U;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i4 = 0; i4 < c_loop_ub; i4++) {
      sizes[i4] = 0U;
    }
  }
  coder::unique_vector(groups, r);
  i6 = r.size(0);
  if (0 <= (r.size(0) - 1)) {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i8 = 0; b_i8 < 3; b_i8++) {
      conn[b_i8][0] = true;
      conn[b_i8][1] = true;
      conn[b_i8][2] = true;
    }
  }
  if (0 <= (i6 - 1)) {
    f_loop_ub = groups.size(0);
    g_loop_ub = regions->PixelList.size(1);
    h_loop_ub = ImgVGA.size(0);
    i_loop_ub = ImgVGA.size(1);
  }
  for (int group{0}; group < i6; group++) {
    double d4;
    double d5;
    int b_istop;
    int end;
    int i21;
    int i22;
    int istop;
    int k_loop_ub;
    int m_loop_ub;
    int partialTrueCount;
    int s_loop_ub;
    int siz_idx_0;
    int t_loop_ub;
    int trueCount;
    int u_loop_ub;
    int v_loop_ub;
    int w_loop_ub;
    int y_loop_ub;
    unsigned char b_ex;
    unsigned char c_ex;
    b_groups.set_size(groups.size(0));
    for (int i12{0}; i12 < f_loop_ub; i12++) {
      b_groups[i12] = (groups[i12] == ((static_cast<double>(group)) + 1.0));
    }
    coder::b_eml_find(b_groups, c_ii);
    if (1 > c_ii[0]) {
      k_loop_ub = 0;
    } else {
      k_loop_ub = c_ii[0];
    }
    if (1 > c_ii[0]) {
      m_loop_ub = 0;
    } else {
      m_loop_ub = c_ii[0];
    }
    b_lengths1.set_size(k_loop_ub);
    for (int i16{0}; i16 < k_loop_ub; i16++) {
      b_lengths1[i16] = lengths1[i16];
    }
    d4 = coder::c_combineVectorElements(b_lengths1);
    b_regions.set_size(m_loop_ub);
    for (int i18{0}; i18 < m_loop_ub; i18++) {
      b_regions[i18] = regions->Lengths[i18];
    }
    d5 = coder::c_combineVectorElements(b_regions);
    if (d4 > d5) {
      i21 = 0;
      i22 = 0;
    } else {
      i21 = (static_cast<int>(d4)) - 1;
      i22 = static_cast<int>(d5);
    }
    s_loop_ub = i22 - i21;
    regionPixelListGroup.set_size(regions->PixelList.size(1), s_loop_ub);
    for (int i25{0}; i25 < s_loop_ub; i25++) {
      for (int i26{0}; i26 < g_loop_ub; i26++) {
        regionPixelListGroup[i26 + (regionPixelListGroup.size(0) * i25)] =
            regions
                ->PixelList[(i21 + i25) + (regions->PixelList.size(0) * i26)];
      }
    }
    siz_idx_0 = ImgVGA.size(0);
    t_loop_ub = regionPixelListGroup.size(1);
    r1.set_size(1, regionPixelListGroup.size(1));
    for (int i27{0}; i27 < t_loop_ub; i27++) {
      r1[i27] =
          regionPixelListGroup[(regionPixelListGroup.size(0) * i27) + 1] +
          (siz_idx_0 *
           (regionPixelListGroup[regionPixelListGroup.size(0) * i27] - 1));
    }
    binaryImage.set_size(ImgVGA.size(0), ImgVGA.size(1));
    for (int i28{0}; i28 < i_loop_ub; i28++) {
      for (int i29{0}; i29 < h_loop_ub; i29++) {
        binaryImage[i29 + (binaryImage.size(0) * i28)] = 0;
      }
    }
    siz_idx_0 = ImgVGA.size(0);
    u_loop_ub = regionPixelListGroup.size(1);
    r2.set_size(1, regionPixelListGroup.size(1));
    for (int i30{0}; i30 < u_loop_ub; i30++) {
      r2[i30] =
          regionPixelListGroup[(regionPixelListGroup.size(0) * i30) + 1] +
          (siz_idx_0 *
           (regionPixelListGroup[regionPixelListGroup.size(0) * i30] - 1));
    }
    v_loop_ub = r2.size(1);
    for (int i31{0}; i31 < v_loop_ub; i31++) {
      binaryImage[r2[i31] - 1] = 1;
    }
    // dilatedImage = imdilate(binaryImage, true(3));
    // dilatedImage = bwmorph(binaryImage,'dilate');
    BW.set_size(binaryImage.size(0), binaryImage.size(1));
    w_loop_ub = binaryImage.size(1);
    for (int i32{0}; i32 < w_loop_ub; i32++) {
      int x_loop_ub;
      x_loop_ub = binaryImage.size(0);
      for (int i33{0}; i33 < x_loop_ub; i33++) {
        BW[i33 + (BW.size(0) * i32)] =
            (binaryImage[i33 + (binaryImage.size(0) * i32)] != 0);
      }
    }
    b_D.set_size(BW.size(0), BW.size(1));
    b_dv[0] = static_cast<double>(BW.size(0));
    b_dv1[0] = 3.0;
    b_dv[1] = static_cast<double>(BW.size(1));
    b_dv1[1] = 3.0;
    ddist32_boolean(&BW[0], &b_dv[0], 2.0, &conn[0][0], &b_dv1[0], 2.0,
                    &weights[0][0], &b_D[0], NULL);
    dilatedImage.set_size(b_D.size(0), b_D.size(1));
    y_loop_ub = b_D.size(1);
    for (int i34{0}; i34 < y_loop_ub; i34++) {
      int ab_loop_ub;
      ab_loop_ub = b_D.size(0);
      for (int i35{0}; i35 < ab_loop_ub; i35++) {
        dilatedImage[i35 + (dilatedImage.size(0) * i34)] =
            (b_D[i35 + (b_D.size(0) * i34)] == 1.0F);
      }
    }
    if ((dilatedImage.size(0) != 0) && (dilatedImage.size(1) != 0)) {
      int bb_loop_ub;
      bwout.set_size(dilatedImage.size(0), dilatedImage.size(1));
      sizeIn[0] = static_cast<double>(dilatedImage.size(0));
      sizeIn[1] = static_cast<double>(dilatedImage.size(1));
      bwlookup_tbb_boolean(&dilatedImage[0], &sizeIn[0], 2.0, &lut[0], 512.0,
                           &bwout[0]);
      dilatedImage.set_size(bwout.size(0), bwout.size(1));
      bb_loop_ub = bwout.size(1);
      for (int i36{0}; i36 < bb_loop_ub; i36++) {
        int cb_loop_ub;
        cb_loop_ub = bwout.size(0);
        for (int i37{0}; i37 < cb_loop_ub; i37++) {
          dilatedImage[i37 + (dilatedImage.size(0) * i36)] =
              bwout[i37 + (bwout.size(0) * i36)];
        }
      }
    }
    end = (dilatedImage.size(0) * dilatedImage.size(1)) - 1;
    trueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if (dilatedImage[d_i]) {
        trueCount++;
      }
    }
    r3.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (dilatedImage[e_i]) {
        r3[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    istop = r1.size(1);
    b_ex = 0U;
    if (r1.size(1) >= 1) {
      b_ex = ImgVGA[r1[0] - 1];
      for (int k{2}; k <= istop; k++) {
        int i38;
        i38 = r1[k - 1] - 1;
        if (b_ex < ImgVGA[i38]) {
          b_ex = ImgVGA[i38];
        }
      }
    }
    b_istop = r3.size(0);
    c_ex = 0U;
    if (r3.size(0) >= 1) {
      c_ex = ImgVGA[r3[0] - 1];
      for (int b_k{2}; b_k <= b_istop; b_k++) {
        int i39;
        i39 = r3[b_k - 1] - 1;
        if (c_ex > ImgVGA[i39]) {
          c_ex = ImgVGA[i39];
        }
      }
    }
    if (b_ex > c_ex) {
      int db_loop_ub;
      int eb_loop_ub;
      int i43;
      int i45;
      // Keep only bright on dark polarity
      // regionPixelListUnique{numel(indexes)+1} = regionPixelListGroup; %
      // keeping first element in each group, meaning smallest area
      // regionPixelListUniqueSerial(end:end+size(regionPixelListGroup,2)-1, :)
      // = regionPixelListGroup';
      if (1 > (uniqueRegions_PixelList.size(0) - 1)) {
        db_loop_ub = 0;
      } else {
        db_loop_ub = uniqueRegions_PixelList.size(0) - 1;
      }
      c_f1.set_size(db_loop_ub, 2);
      for (int i40{0}; i40 < 2; i40++) {
        for (int i41{0}; i41 < db_loop_ub; i41++) {
          c_f1[i41 + (c_f1.size(0) * i40)] =
              uniqueRegions_PixelList[i41 +
                                      (uniqueRegions_PixelList.size(0) * i40)];
        }
      }
      f1.set_size(regionPixelListGroup.size(1), regionPixelListGroup.size(0));
      eb_loop_ub = regionPixelListGroup.size(0);
      for (int i42{0}; i42 < eb_loop_ub; i42++) {
        int fb_loop_ub;
        fb_loop_ub = regionPixelListGroup.size(1);
        for (int i44{0}; i44 < fb_loop_ub; i44++) {
          f1[i44 + (f1.size(0) * i42)] =
              regionPixelListGroup[i42 + (regionPixelListGroup.size(0) * i44)];
        }
      }
      uniqueRegions_PixelList.set_size(db_loop_ub + f1.size(0), 2);
      i43 = c_f1.size(0);
      i45 = f1.size(0);
      for (int c_k{0}; c_k < 2; c_k++) {
        for (int b_j{0}; b_j < i43; b_j++) {
          uniqueRegions_PixelList[b_j +
                                  (uniqueRegions_PixelList.size(0) * c_k)] =
              c_f1[b_j + (c_f1.size(0) * c_k)];
        }
        for (int c_j{0}; c_j < i45; c_j++) {
          uniqueRegions_PixelList[(i43 + c_j) +
                                  (uniqueRegions_PixelList.size(0) * c_k)] =
              f1[c_j + (f1.size(0) * c_k)];
        }
      }
      sizes[group] = static_cast<unsigned int>(regionPixelListGroup.size(1));
      // indexes = [indexes, idx(1)];
    }
  }
  uniqueRegions_Lengths.set_size(1, sizes.size(1));
  j_loop_ub = sizes.size(1);
  if ((static_cast<int>(sizes.size(1) < 4)) != 0) {
    for (int i13{0}; i13 < j_loop_ub; i13++) {
      uniqueRegions_Lengths[i13] = static_cast<double>(sizes[i13]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i13 = 0; i13 < j_loop_ub; i13++) {
      uniqueRegions_Lengths[i13] = static_cast<double>(sizes[i13]);
    }
  }
}

} // namespace ITER

//
// File trailer for groupOverlapRegions.cpp
//
// [EOF]
//
