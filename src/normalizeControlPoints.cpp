//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalizeControlPoints.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
  array<double, 1U> r;
  array<double, 1U> x;
  double sumOfPointDistancesFromOriginSquared;
  int N;
  int b_k;
  int firstBlockLength;
  int hi;
  int i;
  int k;
  int lastBlockLength;
  int nblocks;
  int offset;
  N = pts.size(0);
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    cent.set_size(1, pts.size(1));
    N = pts.size(1);
    for (i = 0; i < N; i++) {
      cent[i] = 0.0;
    }
  } else {
    cent.set_size(1, pts.size(1));
    i = pts.size(1);
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
    for (k = 0; k < i; k++) {
      cent[k] = pts[pts.size(0) * k];
      for (b_k = 2; b_k <= firstBlockLength; b_k++) {
        if (N >= 2) {
          cent[k] = cent[k] + pts[(b_k + (pts.size(0) * k)) - 1];
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
        for (b_k = 2; b_k <= hi; b_k++) {
          if (N >= 2) {
            sumOfPointDistancesFromOriginSquared +=
                pts[((offset + b_k) + (pts.size(0) * k)) - 1];
          }
        }
        cent[k] = cent[k] + sumOfPointDistancesFromOriginSquared;
      }
    }
  }
  cent.set_size(1, cent.size(1));
  N = cent.size(1);
  for (i = 0; i < N; i++) {
    cent[i] = cent[i] / (static_cast<double>(pts.size(0)));
  }
  N = cent.size(1);
  firstBlockLength = pts.size(1);
  if (N < firstBlockLength) {
    firstBlockLength = N;
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
  N = cent.size(1);
  firstBlockLength = pts.size(1);
  if (N < firstBlockLength) {
    firstBlockLength = N;
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
    lastBlockLength = (pts.size(1) != 1);
    offset = (cent.size(1) != 1);
    i = nblocks - 1;
    for (k = 0; k <= i; k++) {
      N = lastBlockLength * k;
      firstBlockLength = offset * k;
      nblocks = (pts.size(0) != 1);
      hi = ptsNorm.size(0) - 1;
      for (b_k = 0; b_k <= hi; b_k++) {
        ptsNorm[b_k + (ptsNorm.size(0) * k)] =
            pts[(nblocks * b_k) + (pts.size(0) * N)] - cent[firstBlockLength];
      }
    }
  }
  r.set_size(ptsNorm.size(0));
  N = ptsNorm.size(0);
  for (k = 0; k < N; k++) {
    r[k] = rt_hypotd_snf(ptsNorm[k], ptsNorm[k + ptsNorm.size(0)]);
  }
  x.set_size(r.size(0));
  N = r.size(0);
  for (k = 0; k < N; k++) {
    x[k] = rt_powd_snf(r[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    sumOfPointDistancesFromOriginSquared =
        std::sqrt(2.0 * (static_cast<double>(pts.size(0)))) /
        std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    sumOfPointDistancesFromOriginSquared = 1.0;
  }
  N = ptsNorm.size(1);
  for (i = 0; i < N; i++) {
    firstBlockLength = ptsNorm.size(0);
    for (hi = 0; hi < firstBlockLength; hi++) {
      ptsNorm[hi + (ptsNorm.size(0) * i)] =
          ptsNorm[hi + (ptsNorm.size(0) * i)] *
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
