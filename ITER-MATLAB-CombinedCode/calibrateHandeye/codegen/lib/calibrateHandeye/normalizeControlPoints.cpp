//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "normalizeControlPoints.h"
#include "calibrateHandeye_rtwutil.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &pts
//                ::coder::array<double, 2U> &ptsNorm
//                double normMatrixInv[3][3]
// Return Type  : void
//
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void normalizeControlPoints(const ::coder::array<double, 2U> &pts,
                            ::coder::array<double, 2U> &ptsNorm,
                            double normMatrixInv[3][3])
{
  array<double, 2U> cent;
  array<double, 1U> b_x;
  array<double, 1U> r;
  double sumOfPointDistancesFromOriginSquared;
  int b_i;
  int c_k;
  int d_N;
  int firstBlockLength;
  int hi;
  int k;
  int lastBlockLength;
  int nblocks;
  int offset;
  d_N = pts.size(0);
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    cent.set_size(1, pts.size(1));
    d_N = pts.size(1);
    for (b_i = 0; b_i < d_N; b_i++) {
      cent[b_i] = 0.0;
    }
  } else {
    cent.set_size(1, pts.size(1));
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
      cent[k] = pts[pts.size(0) * k];
      for (c_k = 2; c_k <= firstBlockLength; c_k++) {
        if (d_N >= 2) {
          cent[k] = cent[k] + pts[(c_k + (pts.size(0) * k)) - 1];
        }
      }
      for (int ib{2}; ib <= nblocks; ib++) {
        offset = (ib - 1) * 1024;
        sumOfPointDistancesFromOriginSquared = pts[offset + (pts.size(0) * k)];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (c_k = 2; c_k <= hi; c_k++) {
          if (d_N >= 2) {
            sumOfPointDistancesFromOriginSquared +=
                pts[((offset + c_k) + (pts.size(0) * k)) - 1];
          }
        }
        cent[k] = cent[k] + sumOfPointDistancesFromOriginSquared;
      }
    }
  }
  cent.set_size(1, cent.size(1));
  d_N = cent.size(1);
  for (b_i = 0; b_i < d_N; b_i++) {
    cent[b_i] = cent[b_i] / (static_cast<double>(pts.size(0)));
  }
  d_N = cent.size(1);
  firstBlockLength = pts.size(1);
  if (d_N <= firstBlockLength) {
    firstBlockLength = d_N;
  }
  if (cent.size(1) == 1) {
    nblocks = pts.size(1);
  } else if (pts.size(1) == 1) {
    nblocks = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    nblocks = pts.size(1);
  } else {
    nblocks = firstBlockLength;
  }
  d_N = cent.size(1);
  firstBlockLength = pts.size(1);
  if (d_N <= firstBlockLength) {
    firstBlockLength = d_N;
  }
  if (cent.size(1) == 1) {
    firstBlockLength = pts.size(1);
  } else if (pts.size(1) == 1) {
    firstBlockLength = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    firstBlockLength = pts.size(1);
  } else {
    /* no actions */
  }
  ptsNorm.set_size(pts.size(0), firstBlockLength);
  if ((pts.size(0) != 0) && (nblocks != 0)) {
    lastBlockLength = static_cast<int>(pts.size(1) != 1);
    offset = static_cast<int>(cent.size(1) != 1);
    b_i = nblocks - 1;
    for (k = 0; k <= b_i; k++) {
      d_N = lastBlockLength * k;
      firstBlockLength = offset * k;
      nblocks = static_cast<int>(pts.size(0) != 1);
      hi = ptsNorm.size(0) - 1;
      for (c_k = 0; c_k <= hi; c_k++) {
        ptsNorm[c_k + (ptsNorm.size(0) * k)] =
            pts[(nblocks * c_k) + (pts.size(0) * d_N)] - cent[firstBlockLength];
      }
    }
  }
  r.set_size(ptsNorm.size(0));
  d_N = ptsNorm.size(0);
  for (k = 0; k < d_N; k++) {
    r[k] = rt_hypotd_snf(ptsNorm[k], ptsNorm[k + ptsNorm.size(0)]);
  }
  b_x.set_size(r.size(0));
  d_N = r.size(0);
  for (k = 0; k < d_N; k++) {
    b_x[k] = rt_powd_snf(r[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(b_x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    sumOfPointDistancesFromOriginSquared =
        std::sqrt(2.0 * (static_cast<double>(pts.size(0)))) /
        std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    sumOfPointDistancesFromOriginSquared = 1.0;
  }
  d_N = ptsNorm.size(1);
  for (b_i = 0; b_i < d_N; b_i++) {
    firstBlockLength = ptsNorm.size(0);
    for (hi = 0; hi < firstBlockLength; hi++) {
      ptsNorm[hi + (ptsNorm.size(0) * b_i)] =
          ptsNorm[hi + (ptsNorm.size(0) * b_i)] *
          sumOfPointDistancesFromOriginSquared;
    }
  }
  normMatrixInv[0][0] = 1.0 / sumOfPointDistancesFromOriginSquared;
  normMatrixInv[1][0] = 0.0;
  normMatrixInv[2][0] = 0.0;
  normMatrixInv[0][1] = 0.0;
  normMatrixInv[1][1] = 1.0 / sumOfPointDistancesFromOriginSquared;
  normMatrixInv[2][1] = 0.0;
  normMatrixInv[0][2] = cent[0];
  normMatrixInv[1][2] = cent[1];
  normMatrixInv[2][2] = 1.0;
}

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder

//
// File trailer for normalizeControlPoints.cpp
//
// [EOF]
//
