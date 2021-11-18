//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "normalizeControlPoints.h"
#include "calibrateCamera_rtwutil.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &pts
//                ::coder::array<real_T, 2U> &ptsNorm
//                real_T normMatrixInv[3][3]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void normalizeControlPoints(const ::coder::array<real_T, 2U> &pts,
                            ::coder::array<real_T, 2U> &ptsNorm,
                            real_T normMatrixInv[3][3])
{
  ::coder::array<real_T, 1U> r;
  ::coder::array<real_T, 1U> y;
  real_T cent_data[2];
  real_T sumOfPointDistancesFromOriginSquared;
  int32_T b_hi;
  int32_T b_i;
  int32_T b_k;
  int32_T cent_size_idx_1;
  int32_T firstBlockLength;
  int32_T h_N;
  int32_T k;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T offset;
  h_N = pts.size(0);
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    cent_size_idx_1 = pts.size(1);
    firstBlockLength = pts.size(1);
    if (0 <= (firstBlockLength - 1)) {
      (void)std::memset(&cent_data[0], 0,
                        (static_cast<uint32_T>(firstBlockLength)) *
                            (sizeof(real_T)));
    }
  } else {
    cent_size_idx_1 = pts.size(1);
    b_i = pts.size(1);
    if (pts.size(0) <= 1024) {
      firstBlockLength = pts.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = pts.size(0) / 1024;
      lastBlockLength = pts.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (k = 0; k < b_i; k++) {
      cent_data[k] = pts[pts.size(0) * k];
      for (b_k = 2; b_k <= firstBlockLength; b_k++) {
        if (h_N >= 2) {
          cent_data[k] += pts[(b_k + (pts.size(0) * k)) - 1];
        }
      }
      for (int32_T ib{2}; ib <= nblocks; ib++) {
        offset = (ib - 1) * 1024;
        sumOfPointDistancesFromOriginSquared = pts[offset + (pts.size(0) * k)];
        if (ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (b_k = 2; b_k <= b_hi; b_k++) {
          if (h_N >= 2) {
            sumOfPointDistancesFromOriginSquared +=
                pts[((offset + b_k) + (pts.size(0) * k)) - 1];
          }
        }
        cent_data[k] += sumOfPointDistancesFromOriginSquared;
      }
    }
  }
  for (b_i = 0; b_i < cent_size_idx_1; b_i++) {
    cent_data[b_i] /= static_cast<real_T>(pts.size(0));
  }
  h_N = pts.size(1);
  if (cent_size_idx_1 <= h_N) {
    h_N = cent_size_idx_1;
  }
  if (cent_size_idx_1 == 1) {
    firstBlockLength = pts.size(1);
  } else if (pts.size(1) == 1) {
    firstBlockLength = cent_size_idx_1;
  } else if (pts.size(1) == cent_size_idx_1) {
    firstBlockLength = pts.size(1);
  } else {
    firstBlockLength = h_N;
  }
  h_N = pts.size(1);
  if (cent_size_idx_1 <= h_N) {
    h_N = cent_size_idx_1;
  }
  if (cent_size_idx_1 == 1) {
    h_N = pts.size(1);
  } else if (pts.size(1) == 1) {
    h_N = cent_size_idx_1;
  } else if (pts.size(1) == cent_size_idx_1) {
    h_N = pts.size(1);
  } else {
    /* no actions */
  }
  ptsNorm.set_size(pts.size(0), h_N);
  if ((pts.size(0) != 0) && (firstBlockLength != 0)) {
    offset = static_cast<int32_T>(pts.size(1) != 1);
    lastBlockLength = static_cast<int32_T>(cent_size_idx_1 != 1);
    b_i = firstBlockLength - 1;
    for (k = 0; k <= b_i; k++) {
      h_N = offset * k;
      firstBlockLength = lastBlockLength * k;
      nblocks = static_cast<int32_T>(pts.size(0) != 1);
      b_hi = ptsNorm.size(0) - 1;
      for (b_k = 0; b_k <= b_hi; b_k++) {
        ptsNorm[b_k + (ptsNorm.size(0) * k)] =
            pts[(nblocks * b_k) + (pts.size(0) * h_N)] -
            cent_data[firstBlockLength];
      }
    }
  }
  r.set_size(ptsNorm.size(0));
  h_N = ptsNorm.size(0);
  for (k = 0; k < h_N; k++) {
    r[k] = rt_hypotd_snf(ptsNorm[k], ptsNorm[k + ptsNorm.size(0)]);
  }
  y.set_size(r.size(0));
  h_N = r.size(0);
  for (k = 0; k < h_N; k++) {
    y[k] = rt_powd_snf(r[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(y);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    sumOfPointDistancesFromOriginSquared =
        std::sqrt(2.0 * (static_cast<real_T>(pts.size(0)))) /
        std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    sumOfPointDistancesFromOriginSquared = 1.0;
  }
  firstBlockLength = ptsNorm.size(1);
  for (b_i = 0; b_i < firstBlockLength; b_i++) {
    h_N = ptsNorm.size(0);
    for (b_hi = 0; b_hi < h_N; b_hi++) {
      ptsNorm[b_hi + (ptsNorm.size(0) * b_i)] =
          ptsNorm[b_hi + (ptsNorm.size(0) * b_i)] *
          sumOfPointDistancesFromOriginSquared;
    }
  }
  normMatrixInv[0][0] = 1.0 / sumOfPointDistancesFromOriginSquared;
  normMatrixInv[1][0] = 0.0;
  normMatrixInv[2][0] = 0.0;
  normMatrixInv[0][1] = 0.0;
  normMatrixInv[1][1] = 1.0 / sumOfPointDistancesFromOriginSquared;
  normMatrixInv[2][1] = 0.0;
  normMatrixInv[0][2] = cent_data[0];
  normMatrixInv[1][2] = cent_data[1];
  normMatrixInv[2][2] = 1.0;
}

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder
} // namespace Codegen

//
// File trailer for normalizeControlPoints.cpp
//
// [EOF]
//
