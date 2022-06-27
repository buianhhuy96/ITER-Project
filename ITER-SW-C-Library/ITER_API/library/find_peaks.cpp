//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "find_peaks.h"
#include "ITER_API_internal_types.h"
#include "ITER_API_rtwutil.h"
#include "NeighborhoodProcessor.h"
#include "algbwmorph.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &metric
//                ::coder::array<float, 2U> &loc
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const ::coder::array<float, 2U> &metric,
                ::coder::array<float, 2U> &loc)
{
  images::internal::coder::NeighborhoodProcessor np;
  array<int, 1U> b_v1;
  array<int, 1U> b_vk;
  array<unsigned int, 1U> c_idx;
  array<int, 1U> c_ii;
  array<int, 1U> r;
  array<bool, 2U> bwpre;
  array<bool, 2U> expl_temp_bw;
  array<bool, 2U> last_aout;
  e_struct_T expl_temp;
  float maxMetric;
  unsigned int siz[2];
  unsigned int uv[2];
  int i18;
  int i3;
  int last;
  bool exitg1;
  last = metric.size(0) * metric.size(1);
  if ((metric.size(0) * metric.size(1)) <= 2) {
    if ((metric.size(0) * metric.size(1)) == 0) {
      maxMetric = rtNaNF;
    } else if ((metric.size(0) * metric.size(1)) == 1) {
      maxMetric = metric[0];
    } else if (metric[0] < metric[(metric.size(0) * metric.size(1)) - 1]) {
      maxMetric = metric[(metric.size(0) * metric.size(1)) - 1];
    } else if (std::isnan(metric[0])) {
      if (!std::isnan(metric[(metric.size(0) * metric.size(1)) - 1])) {
        maxMetric = metric[(metric.size(0) * metric.size(1)) - 1];
      } else {
        maxMetric = metric[0];
      }
    } else {
      maxMetric = metric[0];
    }
  } else {
    int idx;
    if (!std::isnan(metric[0])) {
      idx = 1;
    } else {
      int k;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(metric[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxMetric = metric[0];
    } else {
      float ex;
      int b_i;
      ex = metric[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        if (ex < metric[b_k - 1]) {
          ex = metric[b_k - 1];
        }
      }
      maxMetric = ex;
    }
  }
  if ((static_cast<double>(maxMetric)) <= 4.94065645841247E-324) {
    loc.set_size(0, 2);
  } else {
    float threshold;
    int b_expl_temp;
    int b_idx;
    int b_nx;
    int b_siz;
    int c_expl_temp;
    int c_siz;
    int d_siz;
    int e_ii;
    int e_loop_ub;
    int end;
    int f_loop_ub;
    int h_loop_ub;
    int j_loop_ub;
    int k_loop_ub;
    int loop_ub;
    int m_loop_ub;
    int o_loop_ub;
    int p_loop_ub;
    int partialTrueCount;
    int q_loop_ub;
    int r_loop_ub;
    int s_loop_ub;
    int siz_tmp_tmp;
    int t_loop_ub;
    int trueCount;
    bool continuePropagation;
    np.ImageSize[0] = metric.size(0);
    np.ImageSize[1] = metric.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < 3; i1++) {
      np.Neighborhood[i1][0] = true;
      np.Neighborhood[i1][1] = true;
      np.Neighborhood[i1][2] = true;
    }
    np.Padding = 1.0;
    np.ProcessBorder = true;
    np.NeighborhoodCenter = 1.0;
    np.PadValue = 0.0;
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int c_i = 0; c_i < 9; c_i++) {
      np.ImageNeighborLinearOffsets[c_i] = 0;
      np.NeighborLinearIndices[c_i] = 0;
    }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

    for (int i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < 9; i3++) {
        np.NeighborSubscriptOffsets[i2][i3] = 0;
      }
      uv[i2] = static_cast<unsigned int>(metric.size(i2));
    }
    expl_temp_bw.set_size(static_cast<int>(uv[0]), static_cast<int>(uv[1]));
    loop_ub = static_cast<int>(uv[1]);
    for (int i4{0}; i4 < loop_ub; i4++) {
      int b_loop_ub;
      b_loop_ub = static_cast<int>(uv[0]);
      for (int i5{0}; i5 < b_loop_ub; i5++) {
        expl_temp_bw[i5 + (expl_temp_bw.size(0) * i4)] = true;
      }
    }
    continuePropagation = true;
    while (continuePropagation) {
      int c_loop_ub;
      bwpre.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
      c_loop_ub = expl_temp_bw.size(1);
      for (int i6{0}; i6 < c_loop_ub; i6++) {
        int d_loop_ub;
        d_loop_ub = expl_temp_bw.size(0);
        for (int i7{0}; i7 < d_loop_ub; i7++) {
          bwpre[i7 + (bwpre.size(0) * i6)] =
              expl_temp_bw[i7 + (expl_temp_bw.size(0) * i6)];
        }
      }
      images::internal::coder::NeighborhoodProcessor::computeParameters(
          np.ImageSize, np.Neighborhood, np.ImageNeighborLinearOffsets,
          np.NeighborLinearIndices, np.NeighborSubscriptOffsets,
          np.InteriorStart, np.InteriorEnd);
      expl_temp.bw = expl_temp_bw;
      np.process2D(metric, expl_temp_bw, &expl_temp);
      continuePropagation = !b_isequal(bwpre, expl_temp_bw);
    }
    threshold = 0.15F * maxMetric;
    end = (metric.size(0) * metric.size(1)) - 1;
    trueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if (metric[d_i] < threshold) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int e_i{0}; e_i <= end; e_i++) {
      if (metric[e_i] < threshold) {
        r[partialTrueCount] = e_i + 1;
        partialTrueCount++;
      }
    }
    e_loop_ub = r.size(0);
    for (int b_i8{0}; b_i8 < e_loop_ub; b_i8++) {
      expl_temp_bw[r[b_i8] - 1] = false;
    }
    if ((expl_temp_bw.size(0) != 0) && (expl_temp_bw.size(1) != 0)) {
      int g_loop_ub;
      do {
        last_aout.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
        g_loop_ub = expl_temp_bw.size(1);
        for (int i10{0}; i10 < g_loop_ub; i10++) {
          int i_loop_ub;
          i_loop_ub = expl_temp_bw.size(0);
          for (int i12{0}; i12 < i_loop_ub; i12++) {
            last_aout[i12 + (last_aout.size(0) * i10)] =
                expl_temp_bw[i12 + (expl_temp_bw.size(0) * i10)];
          }
        }
        images::internal::bwmorphApplyOnce(expl_temp_bw);
      } while (!b_isequal(last_aout, expl_temp_bw));
      //  the output is not changing anymore
    }
    f_loop_ub = expl_temp_bw.size(1);
    for (int i9{0}; i9 < f_loop_ub; i9++) {
      expl_temp_bw[expl_temp_bw.size(0) * i9] = false;
    }
    b_expl_temp = expl_temp_bw.size(0) - 1;
    h_loop_ub = expl_temp_bw.size(1);
    for (int i11{0}; i11 < h_loop_ub; i11++) {
      expl_temp_bw[b_expl_temp + (expl_temp_bw.size(0) * i11)] = false;
    }
    j_loop_ub = expl_temp_bw.size(0);
    for (int i13{0}; i13 < j_loop_ub; i13++) {
      expl_temp_bw[i13] = false;
    }
    c_expl_temp = expl_temp_bw.size(1) - 1;
    k_loop_ub = expl_temp_bw.size(0);
    for (int i14{0}; i14 < k_loop_ub; i14++) {
      expl_temp_bw[i14 + (expl_temp_bw.size(0) * c_expl_temp)] = false;
    }
    b_nx = expl_temp_bw.size(0) * expl_temp_bw.size(1);
    b_idx = 0;
    c_ii.set_size(b_nx);
    e_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (e_ii <= (b_nx - 1))) {
      if (expl_temp_bw[e_ii]) {
        b_idx++;
        c_ii[b_idx - 1] = e_ii + 1;
        if (b_idx >= b_nx) {
          exitg1 = true;
        } else {
          e_ii++;
        }
      } else {
        e_ii++;
      }
    }
    if (b_nx == 1) {
      if (b_idx == 0) {
        c_ii.set_size(0);
      }
    } else {
      int i15;
      if (1 > b_idx) {
        i15 = 0;
      } else {
        i15 = b_idx;
      }
      c_ii.set_size(i15);
    }
    c_idx.set_size(c_ii.size(0));
    m_loop_ub = c_ii.size(0);
    if ((static_cast<int>(c_ii.size(0) < 4)) != 0) {
      for (int i16{0}; i16 < m_loop_ub; i16++) {
        c_idx[i16] = static_cast<unsigned int>(c_ii[i16]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i16 = 0; i16 < m_loop_ub; i16++) {
        c_idx[i16] = static_cast<unsigned int>(c_ii[i16]);
      }
    }
    loc.set_size(c_idx.size(0), 2);
    o_loop_ub = c_idx.size(0);
    if ((static_cast<int>((c_idx.size(0) * 2) < 4)) != 0) {
      for (int i17{0}; i17 < 2; i17++) {
        for (i18 = 0; i18 < o_loop_ub; i18++) {
          loc[i18 + (loc.size(0) * i17)] = 0.0F;
        }
        siz[i17] = static_cast<unsigned int>(metric.size(i17));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i18)

      for (int i17 = 0; i17 < 2; i17++) {
        for (i18 = 0; i18 < o_loop_ub; i18++) {
          loc[i18 + (loc.size(0) * i17)] = 0.0F;
        }
        siz[i17] = static_cast<unsigned int>(metric.size(i17));
      }
    }
    b_v1.set_size(c_idx.size(0));
    p_loop_ub = c_idx.size(0);
    if ((static_cast<int>(c_idx.size(0) < 4)) != 0) {
      for (int i19{0}; i19 < p_loop_ub; i19++) {
        b_v1[i19] = (static_cast<int>(c_idx[i19])) - 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i19 = 0; i19 < p_loop_ub; i19++) {
        b_v1[i19] = (static_cast<int>(c_idx[i19])) - 1;
      }
    }
    siz_tmp_tmp = static_cast<int>(siz[0]);
    b_siz = static_cast<int>(siz[0]);
    b_vk.set_size(b_v1.size(0));
    q_loop_ub = b_v1.size(0);
    if ((static_cast<int>(b_v1.size(0) < 4)) != 0) {
      for (int i20{0}; i20 < q_loop_ub; i20++) {
        b_vk[i20] = div_s32(b_v1[i20], siz_tmp_tmp);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i20 = 0; i20 < q_loop_ub; i20++) {
        b_vk[i20] = div_s32(b_v1[i20], b_siz);
      }
    }
    c_siz = static_cast<int>(siz[0]);
    d_siz = static_cast<int>(siz[0]);
    r_loop_ub = b_v1.size(0);
    if ((static_cast<int>(b_v1.size(0) < 4)) != 0) {
      for (int i21{0}; i21 < r_loop_ub; i21++) {
        b_v1[i21] = b_v1[i21] - (b_vk[i21] * c_siz);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i21 = 0; i21 < r_loop_ub; i21++) {
        b_v1[i21] = b_v1[i21] - (b_vk[i21] * d_siz);
      }
    }
    s_loop_ub = b_v1.size(0);
    if ((static_cast<int>(b_v1.size(0) < 4)) != 0) {
      for (int i22{0}; i22 < s_loop_ub; i22++) {
        loc[i22 + loc.size(0)] =
            static_cast<float>(static_cast<int>(b_v1[i22] + 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i22 = 0; i22 < s_loop_ub; i22++) {
        loc[i22 + loc.size(0)] =
            static_cast<float>(static_cast<int>(b_v1[i22] + 1));
      }
    }
    t_loop_ub = b_vk.size(0);
    if ((static_cast<int>(b_vk.size(0) < 4)) != 0) {
      for (int i23{0}; i23 < t_loop_ub; i23++) {
        loc[i23] = static_cast<float>(static_cast<int>(b_vk[i23] + 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i23 = 0; i23 < t_loop_ub; i23++) {
        loc[i23] = static_cast<float>(static_cast<int>(b_vk[i23] + 1));
      }
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for find_peaks.cpp
//
// [EOF]
//
