//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "find_peaks.h"
#include "ITER_API_rtwutil.h"
#include "algbwmorph.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimregionalmax.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &metric
//                ::coder::array<float, 2U> &loc
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const ::coder::array<float, 2U> &metric,
                ::coder::array<float, 2U> &loc)
{
  ::coder::array<int, 1U> b_vk;
  ::coder::array<unsigned int, 1U> c_idx;
  ::coder::array<int, 1U> c_ii;
  ::coder::array<int, 1U> e_v1;
  ::coder::array<int, 1U> r;
  ::coder::array<bool, 2U> b_bw;
  ::coder::array<bool, 2U> last_aout;
  double connSizeT[2];
  double imSizeT[2];
  float maxMetric;
  unsigned int siz[2];
  int i12;
  int last;
  bool conn[3][3];
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
      float b_ex;
      int b_i;
      b_ex = metric[idx - 1];
      b_i = idx + 1;
      for (int b_k{b_i}; b_k <= last; b_k++) {
        if (b_ex < metric[b_k - 1]) {
          b_ex = metric[b_k - 1];
        }
      }
      maxMetric = b_ex;
    }
  }
  if ((static_cast<double>(maxMetric)) <= 4.94065645841247E-324) {
    loc.set_size(0, 2);
  } else {
    float threshold;
    int b_idx;
    int b_loop_ub;
    int b_nx;
    int b_siz;
    int c_bw;
    int c_siz;
    int d_bw;
    int d_siz;
    int e_bw;
    int e_ii;
    int e_loop_ub;
    int end;
    int f_bw;
    int f_loop_ub;
    int g_loop_ub;
    int h_loop_ub;
    int i_loop_ub;
    int j_loop_ub;
    int k_loop_ub;
    int loop_ub;
    int m_loop_ub;
    int o_loop_ub;
    int p_loop_ub;
    int partialTrueCount;
    int siz_tmp_tmp;
    int trueCount;
    b_bw.set_size(metric.size(0), metric.size(1));
    imSizeT[0] = static_cast<double>(metric.size(0));
    imSizeT[1] = static_cast<double>(metric.size(1));
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int i1 = 0; i1 < 3; i1++) {
      conn[i1][0] = true;
      conn[i1][1] = true;
      conn[i1][2] = true;
    }
    connSizeT[0] = 3.0;
    connSizeT[1] = 3.0;
    imregionalmax_real32(&metric[0], &b_bw[0], 2.0, &imSizeT[0], &conn[0][0],
                         2.0, &connSizeT[0]);
    threshold = 0.15F * maxMetric;
    end = (metric.size(0) * metric.size(1)) - 1;
    trueCount = 0;
    for (int c_i{0}; c_i <= end; c_i++) {
      if (metric[c_i] < threshold) {
        trueCount++;
      }
    }
    r.set_size(trueCount);
    partialTrueCount = 0;
    for (int d_i{0}; d_i <= end; d_i++) {
      if (metric[d_i] < threshold) {
        r[partialTrueCount] = d_i + 1;
        partialTrueCount++;
      }
    }
    loop_ub = r.size(0);
    for (int i2{0}; i2 < loop_ub; i2++) {
      b_bw[r[i2] - 1] = false;
    }
    if ((b_bw.size(0) != 0) && (b_bw.size(1) != 0)) {
      int c_loop_ub;
      bool b_p;
      do {
        bool p;
        last_aout.set_size(b_bw.size(0), b_bw.size(1));
        c_loop_ub = b_bw.size(1);
        for (int i4{0}; i4 < c_loop_ub; i4++) {
          int d_loop_ub;
          d_loop_ub = b_bw.size(0);
          for (int i5{0}; i5 < d_loop_ub; i5++) {
            last_aout[i5 + (last_aout.size(0) * i4)] =
                b_bw[i5 + (b_bw.size(0) * i4)];
          }
        }
        images::internal::bwmorphApplyOnce(b_bw);
        p = false;
        if (last_aout.size(0) == b_bw.size(0)) {
          if (last_aout.size(1) == b_bw.size(1)) {
            p = true;
          }
        }
        b_p = p;
        if (p) {
          if ((last_aout.size(0) != 0) && (last_aout.size(1) != 0)) {
            if ((b_bw.size(0) != 0) && (b_bw.size(1) != 0)) {
              int c_k;
              b_p = true;
              c_k = 0;
              exitg1 = false;
              while ((!exitg1) && (c_k <= (last_aout.size(1) - 1))) {
                int d_k;
                bool exitg2;
                d_k = 0;
                exitg2 = false;
                while ((!exitg2) && (d_k <= (last_aout.size(0) - 1))) {
                  if (last_aout[d_k + (last_aout.size(0) * c_k)] !=
                      b_bw[d_k + (b_bw.size(0) * c_k)]) {
                    b_p = false;
                    exitg2 = true;
                  } else {
                    d_k++;
                  }
                }
                if (!b_p) {
                  exitg1 = true;
                } else {
                  c_k++;
                }
              }
            }
          }
        }
      } while (!b_p);
      //  the output is not changing anymore
    }
    b_loop_ub = b_bw.size(1);
    if ((static_cast<int>(b_bw.size(1) < 4)) != 0) {
      for (int i3{0}; i3 < b_loop_ub; i3++) {
        b_bw[b_bw.size(0) * i3] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < b_loop_ub; i3++) {
        b_bw[b_bw.size(0) * i3] = false;
      }
    }
    c_bw = b_bw.size(0) - 1;
    d_bw = b_bw.size(0) - 1;
    e_loop_ub = b_bw.size(1);
    if ((static_cast<int>(b_bw.size(1) < 4)) != 0) {
      for (int i6{0}; i6 < e_loop_ub; i6++) {
        b_bw[c_bw + (b_bw.size(0) * i6)] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < e_loop_ub; i6++) {
        b_bw[d_bw + (b_bw.size(0) * i6)] = false;
      }
    }
    f_loop_ub = b_bw.size(0);
    if ((static_cast<int>(b_bw.size(0) < 4)) != 0) {
      for (int i7{0}; i7 < f_loop_ub; i7++) {
        b_bw[i7] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i7 = 0; i7 < f_loop_ub; i7++) {
        b_bw[i7] = false;
      }
    }
    e_bw = b_bw.size(1) - 1;
    f_bw = b_bw.size(1) - 1;
    g_loop_ub = b_bw.size(0);
    if ((static_cast<int>(b_bw.size(0) < 4)) != 0) {
      for (int b_i8{0}; b_i8 < g_loop_ub; b_i8++) {
        b_bw[b_i8 + (b_bw.size(0) * e_bw)] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_i8 = 0; b_i8 < g_loop_ub; b_i8++) {
        b_bw[b_i8 + (b_bw.size(0) * f_bw)] = false;
      }
    }
    b_nx = b_bw.size(0) * b_bw.size(1);
    b_idx = 0;
    c_ii.set_size(b_nx);
    e_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (e_ii <= (b_nx - 1))) {
      if (b_bw[e_ii]) {
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
      int i9;
      if (1 > b_idx) {
        i9 = 0;
      } else {
        i9 = b_idx;
      }
      c_ii.set_size(i9);
    }
    c_idx.set_size(c_ii.size(0));
    h_loop_ub = c_ii.size(0);
    if ((static_cast<int>(c_ii.size(0) < 4)) != 0) {
      for (int i10{0}; i10 < h_loop_ub; i10++) {
        c_idx[i10] = static_cast<unsigned int>(c_ii[i10]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i10 = 0; i10 < h_loop_ub; i10++) {
        c_idx[i10] = static_cast<unsigned int>(c_ii[i10]);
      }
    }
    loc.set_size(c_idx.size(0), 2);
    i_loop_ub = c_idx.size(0);
    if ((static_cast<int>((c_idx.size(0) * 2) < 4)) != 0) {
      for (int i11{0}; i11 < 2; i11++) {
        for (i12 = 0; i12 < i_loop_ub; i12++) {
          loc[i12 + (loc.size(0) * i11)] = 0.0F;
        }
        siz[i11] = static_cast<unsigned int>(metric.size(i11));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i12)

      for (int i11 = 0; i11 < 2; i11++) {
        for (i12 = 0; i12 < i_loop_ub; i12++) {
          loc[i12 + (loc.size(0) * i11)] = 0.0F;
        }
        siz[i11] = static_cast<unsigned int>(metric.size(i11));
      }
    }
    e_v1.set_size(c_idx.size(0));
    j_loop_ub = c_idx.size(0);
    if ((static_cast<int>(c_idx.size(0) < 4)) != 0) {
      for (int i13{0}; i13 < j_loop_ub; i13++) {
        e_v1[i13] = (static_cast<int>(c_idx[i13])) - 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i13 = 0; i13 < j_loop_ub; i13++) {
        e_v1[i13] = (static_cast<int>(c_idx[i13])) - 1;
      }
    }
    siz_tmp_tmp = static_cast<int>(siz[0]);
    b_siz = static_cast<int>(siz[0]);
    b_vk.set_size(e_v1.size(0));
    k_loop_ub = e_v1.size(0);
    if ((static_cast<int>(e_v1.size(0) < 4)) != 0) {
      for (int i14{0}; i14 < k_loop_ub; i14++) {
        b_vk[i14] = div_s32(e_v1[i14], siz_tmp_tmp);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i14 = 0; i14 < k_loop_ub; i14++) {
        b_vk[i14] = div_s32(e_v1[i14], b_siz);
      }
    }
    c_siz = static_cast<int>(siz[0]);
    d_siz = static_cast<int>(siz[0]);
    m_loop_ub = e_v1.size(0);
    if ((static_cast<int>(e_v1.size(0) < 4)) != 0) {
      for (int i15{0}; i15 < m_loop_ub; i15++) {
        e_v1[i15] = e_v1[i15] - (b_vk[i15] * c_siz);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i15 = 0; i15 < m_loop_ub; i15++) {
        e_v1[i15] = e_v1[i15] - (b_vk[i15] * d_siz);
      }
    }
    o_loop_ub = e_v1.size(0);
    if ((static_cast<int>(e_v1.size(0) < 4)) != 0) {
      for (int i16{0}; i16 < o_loop_ub; i16++) {
        loc[i16 + loc.size(0)] =
            static_cast<float>(static_cast<int>(e_v1[i16] + 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i16 = 0; i16 < o_loop_ub; i16++) {
        loc[i16 + loc.size(0)] =
            static_cast<float>(static_cast<int>(e_v1[i16] + 1));
      }
    }
    p_loop_ub = b_vk.size(0);
    if ((static_cast<int>(b_vk.size(0) < 4)) != 0) {
      for (int i17{0}; i17 < p_loop_ub; i17++) {
        loc[i17] = static_cast<float>(static_cast<int>(b_vk[i17] + 1));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i17 = 0; i17 < p_loop_ub; i17++) {
        loc[i17] = static_cast<float>(static_cast<int>(b_vk[i17] + 1));
      }
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

//
// File trailer for find_peaks.cpp
//
// [EOF]
//
