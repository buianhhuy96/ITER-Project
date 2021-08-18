//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "find_peaks.h"
#include "NeighborhoodProcessor.h"
#include "algbwmorph.h"
#include "calibrateHandeye_internal_types.h"
#include "calibrateHandeye_rtwutil.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

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
  array<unsigned int, 1U> b_idx;
  array<int, 1U> ii;
  array<int, 1U> vk;
  array<bool, 2U> expl_temp_bw;
  array<bool, 2U> last_aout;
  struct_T expl_temp;
  float maxMetric;
  int b_np[2];
  unsigned int siz[2];
  int i;
  int idx;
  int k;
  int last;
  bool c_np[3][3];
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
    if (!std::isnan(metric[0])) {
      idx = 1;
    } else {
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
      maxMetric = metric[idx - 1];
      i = idx + 1;
      for (k = i; k <= last; k++) {
        if (maxMetric < metric[k - 1]) {
          maxMetric = metric[k - 1];
        }
      }
    }
  }
  if ((static_cast<double>(maxMetric)) <= 4.94065645841247E-324) {
    loc.set_size(0, 2);
  } else {
    bool continuePropagation;
    np.ImageSize[0] = metric.size(0);
    np.ImageSize[1] = metric.size(1);
    for (i = 0; i < 3; i++) {
      np.Neighborhood[i][0] = true;
      np.Neighborhood[i][1] = true;
      np.Neighborhood[i][2] = true;
    }
    np.Padding = 1.0;
    np.ProcessBorder = true;
    np.NeighborhoodCenter = 1.0;
    np.PadValue = 0.0;
    for (idx = 0; idx < 9; idx++) {
      np.ImageNeighborLinearOffsets[idx] = 0;
      np.NeighborLinearIndices[idx] = 0;
    }
    for (i = 0; i < 2; i++) {
      for (last = 0; last < 9; last++) {
        np.NeighborSubscriptOffsets[i][last] = 0;
      }
      siz[i] = static_cast<unsigned int>(metric.size(i));
    }
    expl_temp_bw.set_size(static_cast<int>(siz[0]), static_cast<int>(siz[1]));
    idx = static_cast<int>(siz[1]);
    for (i = 0; i < idx; i++) {
      k = static_cast<int>(siz[0]);
      for (last = 0; last < k; last++) {
        expl_temp_bw[last + (expl_temp_bw.size(0) * i)] = true;
      }
    }
    continuePropagation = true;
    while (continuePropagation) {
      last_aout.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
      idx = expl_temp_bw.size(1);
      for (i = 0; i < idx; i++) {
        k = expl_temp_bw.size(0);
        for (last = 0; last < k; last++) {
          last_aout[last + (last_aout.size(0) * i)] =
              expl_temp_bw[last + (expl_temp_bw.size(0) * i)];
        }
      }
      b_np[0] = np.ImageSize[0];
      b_np[1] = np.ImageSize[1];
      for (int i1{0}; i1 < 3; i1++) {
        for (int i2{0}; i2 < 3; i2++) {
          c_np[i1][i2] = np.Neighborhood[i1][i2];
        }
      }
      images::internal::coder::NeighborhoodProcessor::computeParameters(
          b_np, c_np, np.ImageNeighborLinearOffsets, np.NeighborLinearIndices,
          np.NeighborSubscriptOffsets, np.InteriorStart, np.InteriorEnd);
      expl_temp.bw = expl_temp_bw;
      np.process2D(metric, expl_temp_bw, &expl_temp);
      continuePropagation = !b_isequal(last_aout, expl_temp_bw);
    }
    maxMetric *= 0.15F;
    k = (metric.size(0) * metric.size(1)) - 1;
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        last++;
      }
    }
    ii.set_size(last);
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        ii[last] = idx + 1;
        last++;
      }
    }
    idx = ii.size(0);
    for (i = 0; i < idx; i++) {
      expl_temp_bw[ii[i] - 1] = false;
    }
    if ((expl_temp_bw.size(0) != 0) && (expl_temp_bw.size(1) != 0)) {
      do {
        last_aout.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
        idx = expl_temp_bw.size(1);
        for (i = 0; i < idx; i++) {
          k = expl_temp_bw.size(0);
          for (last = 0; last < k; last++) {
            last_aout[last + (last_aout.size(0) * i)] =
                expl_temp_bw[last + (expl_temp_bw.size(0) * i)];
          }
        }
        images::internal::bwmorphApplyOnce(expl_temp_bw);
      } while (!b_isequal(last_aout, expl_temp_bw));
      //  the output is not changing anymore
    }
    idx = expl_temp_bw.size(1);
    for (i = 0; i < idx; i++) {
      expl_temp_bw[expl_temp_bw.size(0) * i] = false;
    }
    last = expl_temp_bw.size(0) - 1;
    idx = expl_temp_bw.size(1);
    for (i = 0; i < idx; i++) {
      expl_temp_bw[last + (expl_temp_bw.size(0) * i)] = false;
    }
    idx = expl_temp_bw.size(0);
    for (i = 0; i < idx; i++) {
      expl_temp_bw[i] = false;
    }
    last = expl_temp_bw.size(1) - 1;
    idx = expl_temp_bw.size(0);
    for (i = 0; i < idx; i++) {
      expl_temp_bw[i + (expl_temp_bw.size(0) * last)] = false;
    }
    last = expl_temp_bw.size(0) * expl_temp_bw.size(1);
    idx = 0;
    ii.set_size(last);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (last - 1))) {
      if (expl_temp_bw[k]) {
        idx++;
        ii[idx - 1] = k + 1;
        if (idx >= last) {
          exitg1 = true;
        } else {
          k++;
        }
      } else {
        k++;
      }
    }
    if (last == 1) {
      if (idx == 0) {
        ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      ii.set_size(idx);
    }
    b_idx.set_size(ii.size(0));
    idx = ii.size(0);
    for (i = 0; i < idx; i++) {
      b_idx[i] = static_cast<unsigned int>(ii[i]);
    }
    loc.set_size(b_idx.size(0), 2);
    idx = b_idx.size(0);
    for (i = 0; i < 2; i++) {
      for (last = 0; last < idx; last++) {
        loc[last + (loc.size(0) * i)] = 0.0F;
      }
      siz[i] = static_cast<unsigned int>(metric.size(i));
    }
    ii.set_size(b_idx.size(0));
    idx = b_idx.size(0);
    for (i = 0; i < idx; i++) {
      ii[i] = (static_cast<int>(b_idx[i])) - 1;
    }
    vk.set_size(ii.size(0));
    idx = ii.size(0);
    for (i = 0; i < idx; i++) {
      vk[i] = div_s32(ii[i], static_cast<int>(siz[0]));
    }
    idx = ii.size(0);
    for (i = 0; i < idx; i++) {
      ii[i] = ii[i] - (vk[i] * (static_cast<int>(siz[0])));
    }
    idx = ii.size(0);
    for (i = 0; i < idx; i++) {
      loc[i + loc.size(0)] = static_cast<float>(static_cast<int>(ii[i] + 1));
    }
    idx = vk.size(0);
    for (i = 0; i < idx; i++) {
      loc[i] = static_cast<float>(static_cast<int>(vk[i] + 1));
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
