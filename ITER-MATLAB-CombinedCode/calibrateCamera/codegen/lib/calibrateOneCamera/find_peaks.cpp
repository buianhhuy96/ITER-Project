//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find_peaks.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "find_peaks.h"
#include "NeighborhoodProcessor.h"
#include "algbwmorph.h"
#include "calibrateOneCamera_internal_types.h"
#include "calibrateOneCamera_rtwutil.h"
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
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const ::coder::array<float, 2U> &metric,
                ::coder::array<float, 2U> &loc)
{
  images::internal::coder::NeighborhoodProcessor np;
  ::coder::array<unsigned int, 1U> b_idx;
  ::coder::array<int, 1U> b_ii;
  ::coder::array<int, 1U> vk;
  ::coder::array<bool, 2U> expl_temp_bw;
  ::coder::array<bool, 2U> last_aout;
  struct_T expl_temp;
  float maxMetric;
  unsigned int siz[2];
  int b_i;
  int idx;
  int k;
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
      b_i = idx + 1;
      for (k = b_i; k <= last; k++) {
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
    for (b_i = 0; b_i < 3; b_i++) {
      np.Neighborhood[b_i][0] = true;
      np.Neighborhood[b_i][1] = true;
      np.Neighborhood[b_i][2] = true;
    }
    np.Padding = 1.0;
    np.ProcessBorder = true;
    np.NeighborhoodCenter = 1.0;
    np.PadValue = 0.0;
    for (idx = 0; idx < 9; idx++) {
      np.ImageNeighborLinearOffsets[idx] = 0;
      np.NeighborLinearIndices[idx] = 0;
    }
    for (b_i = 0; b_i < 2; b_i++) {
      for (last = 0; last < 9; last++) {
        np.NeighborSubscriptOffsets[b_i][last] = 0;
      }
      siz[b_i] = static_cast<unsigned int>(metric.size(b_i));
    }
    expl_temp_bw.set_size(static_cast<int>(siz[0]), static_cast<int>(siz[1]));
    idx = static_cast<int>(siz[1]);
    for (b_i = 0; b_i < idx; b_i++) {
      k = static_cast<int>(siz[0]);
      for (last = 0; last < k; last++) {
        expl_temp_bw[last + (expl_temp_bw.size(0) * b_i)] = true;
      }
    }
    continuePropagation = true;
    while (continuePropagation) {
      last_aout.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
      idx = expl_temp_bw.size(1);
      for (b_i = 0; b_i < idx; b_i++) {
        k = expl_temp_bw.size(0);
        for (last = 0; last < k; last++) {
          last_aout[last + (last_aout.size(0) * b_i)] =
              expl_temp_bw[last + (expl_temp_bw.size(0) * b_i)];
        }
      }
      images::internal::coder::NeighborhoodProcessor::computeParameters(
          np.ImageSize, np.Neighborhood, np.ImageNeighborLinearOffsets,
          np.NeighborLinearIndices, np.NeighborSubscriptOffsets,
          np.InteriorStart, np.InteriorEnd);
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
    b_ii.set_size(last);
    last = 0;
    for (idx = 0; idx <= k; idx++) {
      if (metric[idx] < maxMetric) {
        b_ii[last] = idx + 1;
        last++;
      }
    }
    idx = b_ii.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      expl_temp_bw[b_ii[b_i] - 1] = false;
    }
    if ((expl_temp_bw.size(0) != 0) && (expl_temp_bw.size(1) != 0)) {
      do {
        last_aout.set_size(expl_temp_bw.size(0), expl_temp_bw.size(1));
        idx = expl_temp_bw.size(1);
        for (b_i = 0; b_i < idx; b_i++) {
          k = expl_temp_bw.size(0);
          for (last = 0; last < k; last++) {
            last_aout[last + (last_aout.size(0) * b_i)] =
                expl_temp_bw[last + (expl_temp_bw.size(0) * b_i)];
          }
        }
        images::internal::bwmorphApplyOnce(expl_temp_bw);
      } while (!b_isequal(last_aout, expl_temp_bw));
      //  the output is not changing anymore
    }
    idx = expl_temp_bw.size(1);
    for (b_i = 0; b_i < idx; b_i++) {
      expl_temp_bw[expl_temp_bw.size(0) * b_i] = false;
    }
    last = expl_temp_bw.size(0) - 1;
    idx = expl_temp_bw.size(1);
    for (b_i = 0; b_i < idx; b_i++) {
      expl_temp_bw[last + (expl_temp_bw.size(0) * b_i)] = false;
    }
    idx = expl_temp_bw.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      expl_temp_bw[b_i] = false;
    }
    last = expl_temp_bw.size(1) - 1;
    idx = expl_temp_bw.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      expl_temp_bw[b_i + (expl_temp_bw.size(0) * last)] = false;
    }
    last = expl_temp_bw.size(0) * expl_temp_bw.size(1);
    idx = 0;
    b_ii.set_size(last);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (last - 1))) {
      if (expl_temp_bw[k]) {
        idx++;
        b_ii[idx - 1] = k + 1;
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
        b_ii.set_size(0);
      }
    } else {
      if (1 > idx) {
        idx = 0;
      }
      b_ii.set_size(idx);
    }
    b_idx.set_size(b_ii.size(0));
    idx = b_ii.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      b_idx[b_i] = static_cast<unsigned int>(b_ii[b_i]);
    }
    loc.set_size(b_idx.size(0), 2);
    idx = b_idx.size(0);
    for (b_i = 0; b_i < 2; b_i++) {
      for (last = 0; last < idx; last++) {
        loc[last + (loc.size(0) * b_i)] = 0.0F;
      }
      siz[b_i] = static_cast<unsigned int>(metric.size(b_i));
    }
    b_ii.set_size(b_idx.size(0));
    idx = b_idx.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      b_ii[b_i] = (static_cast<int>(b_idx[b_i])) - 1;
    }
    vk.set_size(b_ii.size(0));
    idx = b_ii.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      vk[b_i] = div_s32(b_ii[b_i], static_cast<int>(siz[0]));
    }
    idx = b_ii.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      b_ii[b_i] = b_ii[b_i] - (vk[b_i] * (static_cast<int>(siz[0])));
    }
    idx = b_ii.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      loc[b_i + loc.size(0)] =
          static_cast<float>(static_cast<int>(b_ii[b_i] + 1));
    }
    idx = vk.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      loc[b_i] = static_cast<float>(static_cast<int>(vk[b_i] + 1));
    }
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

//
// File trailer for find_peaks.cpp
//
// [EOF]
//
