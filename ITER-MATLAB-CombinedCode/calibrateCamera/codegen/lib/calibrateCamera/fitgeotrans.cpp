//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "fitgeotrans.h"
#include "calibrateCamera_rtwutil.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &uv
//                const ::coder::array<real_T, 2U> &xy
//                projective2d *tform
// Return Type  : void
//
namespace Codegen {
namespace coder {
void findProjectiveTransform(const ::coder::array<real_T, 2U> &uv,
                             const ::coder::array<real_T, 2U> &xy,
                             projective2d *tform)
{
  ::coder::array<real_T, 2U> b_uv;
  ::coder::array<real_T, 2U> b_xy;
  ::coder::array<real_T, 2U> d_X;
  ::coder::array<real_T, 1U> r;
  ::coder::array<real_T, 1U> y;
  real_T A_data[64];
  real_T b_tform[9];
  real_T c_B[3][3];
  real_T d_Y[3][3];
  real_T dv[3][3];
  real_T normMatrix2[3][3];
  real_T s_data[8];
  real_T cent[2];
  real_T s;
  real_T scaleFactor;
  real_T sumOfPointDistancesFromOriginSquared;
  int32_T b_hi;
  int32_T b_i;
  int32_T b_k;
  int32_T exponent;
  int32_T firstBlockLength;
  int32_T ib;
  int32_T k;
  int32_T lastBlockLength;
  int32_T nblocks;
  int32_T offset;
  int32_T rtemp;
  int8_T ipiv[8];
  boolean_T guard1{false};
  rtemp = uv.size(0);
  if (uv.size(0) == 0) {
    cent[0] = 0.0;
    cent[1] = 0.0;
  } else {
    if (uv.size(0) <= 1024) {
      firstBlockLength = uv.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = uv.size(0) / 1024;
      lastBlockLength = uv.size(0) - (nblocks * 1024);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    for (k = 0; k < 2; k++) {
      cent[k] = uv[uv.size(0) * k];
      for (b_k = 2; b_k <= firstBlockLength; b_k++) {
        if (rtemp >= 2) {
          cent[k] += uv[(b_k + (uv.size(0) * k)) - 1];
        }
      }
      for (ib = 2; ib <= nblocks; ib++) {
        offset = (ib - 1) * 1024;
        sumOfPointDistancesFromOriginSquared = uv[offset + (uv.size(0) * k)];
        if (ib == nblocks) {
          b_hi = lastBlockLength;
        } else {
          b_hi = 1024;
        }
        for (b_k = 2; b_k <= b_hi; b_k++) {
          if (rtemp >= 2) {
            sumOfPointDistancesFromOriginSquared +=
                uv[((offset + b_k) + (uv.size(0) * k)) - 1];
          }
        }
        cent[k] += sumOfPointDistancesFromOriginSquared;
      }
    }
  }
  cent[0] /= static_cast<real_T>(uv.size(0));
  cent[1] /= static_cast<real_T>(uv.size(0));
  b_uv.set_size(uv.size(0), 2);
  if (uv.size(0) != 0) {
    firstBlockLength = static_cast<int32_T>(uv.size(0) != 1);
    for (k = 0; k < 2; k++) {
      b_i = b_uv.size(0) - 1;
      for (b_k = 0; b_k <= b_i; b_k++) {
        b_uv[b_k + (b_uv.size(0) * k)] =
            uv[(firstBlockLength * b_k) + (uv.size(0) * k)] - cent[k];
      }
    }
  }
  r.set_size(b_uv.size(0));
  firstBlockLength = b_uv.size(0);
  for (k = 0; k < firstBlockLength; k++) {
    r[k] = rt_hypotd_snf(b_uv[k], b_uv[k + b_uv.size(0)]);
  }
  y.set_size(r.size(0));
  firstBlockLength = r.size(0);
  for (k = 0; k < firstBlockLength; k++) {
    y[k] = rt_powd_snf(r[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(y);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    scaleFactor = std::sqrt(2.0 * (static_cast<real_T>(uv.size(0)))) /
                  std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    scaleFactor = 1.0;
  }
  b_uv.set_size(b_uv.size(0), 2);
  for (b_i = 0; b_i < 2; b_i++) {
    firstBlockLength = b_uv.size(0);
    for (lastBlockLength = 0; lastBlockLength < firstBlockLength;
         lastBlockLength++) {
      b_uv[lastBlockLength + (b_uv.size(0) * b_i)] =
          b_uv[lastBlockLength + (b_uv.size(0) * b_i)] * scaleFactor;
    }
  }
  images::geotrans::internal::normalizeControlPoints(xy, b_xy, normMatrix2);
  firstBlockLength = b_uv.size(0);
  r.set_size(b_uv.size(0));
  for (b_i = 0; b_i < firstBlockLength; b_i++) {
    r[b_i] = -b_uv[b_i];
  }
  firstBlockLength = b_uv.size(0);
  y.set_size(b_uv.size(0));
  for (b_i = 0; b_i < firstBlockLength; b_i++) {
    y[b_i] = -b_uv[b_i + b_uv.size(0)];
  }
  firstBlockLength = b_xy.size(0);
  nblocks = b_xy.size(0);
  lastBlockLength = b_xy.size(0);
  rtemp = b_xy.size(0);
  d_X.set_size(b_xy.size(0) + b_xy.size(0), 8);
  for (b_i = 0; b_i < firstBlockLength; b_i++) {
    d_X[b_i] = b_xy[b_i];
  }
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + d_X.size(0)] = b_xy[b_i + b_xy.size(0)];
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 2)] = 1.0;
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 3)] = 0.0;
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 4)] = 0.0;
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 5)] = 0.0;
  }
  nblocks = r.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 6)] = r[b_i] * b_xy[b_i];
  }
  nblocks = r.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + (d_X.size(0) * 7)] = r[b_i] * b_xy[b_i + b_xy.size(0)];
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[b_i + firstBlockLength] = 0.0;
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[(b_i + firstBlockLength) + d_X.size(0)] = 0.0;
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 2)] = 0.0;
  }
  for (b_i = 0; b_i < lastBlockLength; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 3)] = b_xy[b_i];
  }
  for (b_i = 0; b_i < rtemp; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 4)] =
        b_xy[b_i + b_xy.size(0)];
  }
  nblocks = b_xy.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 5)] = 1.0;
  }
  nblocks = y.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 6)] = y[b_i] * b_xy[b_i];
  }
  nblocks = y.size(0);
  for (b_i = 0; b_i < nblocks; b_i++) {
    d_X[(b_i + firstBlockLength) + (d_X.size(0) * 7)] =
        y[b_i] * b_xy[b_i + b_xy.size(0)];
  }
  if (d_X.size(0) != 0) {
    boolean_T p;
    p = true;
    b_i = d_X.size(0);
    for (k = 0; k < 8; k++) {
      for (b_k = 0; b_k < b_i; b_k++) {
        sumOfPointDistancesFromOriginSquared = d_X[b_k + (d_X.size(0) * k)];
        if (p) {
          if ((std::isinf(sumOfPointDistancesFromOriginSquared)) ||
              (std::isnan(sumOfPointDistancesFromOriginSquared))) {
            p = false;
          }
        } else {
          p = false;
        }
      }
    }
    lastBlockLength =
        static_cast<int32_T>(std::fmin(static_cast<real_T>(d_X.size(0)), 8.0));
    if (p) {
      internal::svd(d_X, s_data, &firstBlockLength);
    } else {
      for (b_i = 0; b_i < lastBlockLength; b_i++) {
        s_data[b_i] = rtNaN;
      }
    }
    sumOfPointDistancesFromOriginSquared = std::abs(s_data[0]);
    if ((!std::isinf(sumOfPointDistancesFromOriginSquared)) &&
        (!std::isnan(sumOfPointDistancesFromOriginSquared))) {
      if (!(sumOfPointDistancesFromOriginSquared <= 2.2250738585072014E-308)) {
        (void)frexp(sumOfPointDistancesFromOriginSquared, &exponent);
      }
    }
  }
  firstBlockLength = b_uv.size(0);
  nblocks = b_uv.size(0);
  r.set_size(b_uv.size(0) + b_uv.size(0));
  for (b_i = 0; b_i < firstBlockLength; b_i++) {
    r[b_i] = b_uv[b_i];
  }
  for (b_i = 0; b_i < nblocks; b_i++) {
    r[b_i + firstBlockLength] = b_uv[b_i + b_uv.size(0)];
  }
  guard1 = false;
  if (d_X.size(0) == 0) {
    guard1 = true;
  } else if (r.size(0) == 0) {
    guard1 = true;
  } else if (d_X.size(0) == 8) {
    for (b_i = 0; b_i < 8; b_i++) {
      for (lastBlockLength = 0; lastBlockLength < 8; lastBlockLength++) {
        A_data[lastBlockLength + (8 * b_i)] =
            d_X[lastBlockLength + (d_X.size(0) * b_i)];
      }
      ipiv[b_i] = static_cast<int8_T>(b_i + 1);
    }
    for (b_k = 0; b_k < 7; b_k++) {
      int8_T i1;
      b_hi = 6 - b_k;
      ib = b_k * 9;
      offset = ib + 2;
      lastBlockLength = 8 - b_k;
      nblocks = 0;
      sumOfPointDistancesFromOriginSquared = std::abs(A_data[ib]);
      for (k = 2; k <= lastBlockLength; k++) {
        s = std::abs(A_data[(ib + k) - 1]);
        if (s > sumOfPointDistancesFromOriginSquared) {
          nblocks = k - 1;
          sumOfPointDistancesFromOriginSquared = s;
        }
      }
      if (A_data[ib + nblocks] != 0.0) {
        if (nblocks != 0) {
          rtemp = b_k + nblocks;
          ipiv[b_k] = static_cast<int8_T>(rtemp + 1);
          for (k = 0; k < 8; k++) {
            nblocks = k * 8;
            firstBlockLength = b_k + nblocks;
            sumOfPointDistancesFromOriginSquared = A_data[firstBlockLength];
            b_i = rtemp + nblocks;
            A_data[firstBlockLength] = A_data[b_i];
            A_data[b_i] = sumOfPointDistancesFromOriginSquared;
          }
        }
        b_i = (ib - b_k) + 8;
        for (rtemp = offset; rtemp <= b_i; rtemp++) {
          A_data[rtemp - 1] /= A_data[ib];
        }
      }
      nblocks = ib;
      for (rtemp = 0; rtemp <= b_hi; rtemp++) {
        sumOfPointDistancesFromOriginSquared = A_data[(ib + (rtemp * 8)) + 8];
        if (sumOfPointDistancesFromOriginSquared != 0.0) {
          b_i = nblocks + 10;
          lastBlockLength = (nblocks - b_k) + 16;
          for (firstBlockLength = b_i; firstBlockLength <= lastBlockLength;
               firstBlockLength++) {
            A_data[firstBlockLength - 1] +=
                A_data[((ib + firstBlockLength) - nblocks) - 9] *
                (-sumOfPointDistancesFromOriginSquared);
          }
        }
        nblocks += 8;
      }
      i1 = ipiv[b_k];
      if ((static_cast<int32_T>(i1)) != (b_k + 1)) {
        sumOfPointDistancesFromOriginSquared = r[b_k];
        firstBlockLength = (static_cast<int32_T>(i1)) - 1;
        r[b_k] = r[firstBlockLength];
        r[firstBlockLength] = sumOfPointDistancesFromOriginSquared;
      }
    }
    for (k = 0; k < 8; k++) {
      firstBlockLength = k * 8;
      if (r[k] != 0.0) {
        b_i = k + 2;
        for (rtemp = b_i; rtemp < 9; rtemp++) {
          r[rtemp - 1] =
              r[rtemp - 1] - (r[k] * A_data[(rtemp + firstBlockLength) - 1]);
        }
      }
    }
    for (k = 7; k >= 0; k--) {
      firstBlockLength = k * 8;
      if (r[k] != 0.0) {
        r[k] = r[k] / A_data[k + firstBlockLength];
        for (rtemp = 0; rtemp < k; rtemp++) {
          r[rtemp] = r[rtemp] - (r[k] * A_data[rtemp + firstBlockLength]);
        }
      }
    }
  } else {
    internal::b_qrsolve(d_X, r, s_data);
    r.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      r[b_i] = s_data[b_i];
    }
  }
  if (guard1) {
    r.set_size(8);
    for (b_i = 0; b_i < 8; b_i++) {
      r[b_i] = 0.0;
    }
  }
  for (b_i = 0; b_i < 8; b_i++) {
    (&tform->T[0][0])[b_i] = r[b_i];
  }
  (&tform->T[0][0])[8] = 1.0;
  dv[0][0] = 1.0 / scaleFactor;
  dv[1][0] = 0.0;
  dv[2][0] = 0.0;
  dv[0][1] = 0.0;
  dv[1][1] = 1.0 / scaleFactor;
  dv[2][1] = 0.0;
  dv[0][2] = cent[0];
  dv[1][2] = cent[1];
  dv[2][2] = 1.0;
  for (b_i = 0; b_i < 3; b_i++) {
    sumOfPointDistancesFromOriginSquared = tform->T[0][b_i];
    s = tform->T[1][b_i];
    scaleFactor = tform->T[2][b_i];
    for (lastBlockLength = 0; lastBlockLength < 3; lastBlockLength++) {
      c_B[lastBlockLength][b_i] =
          ((sumOfPointDistancesFromOriginSquared * dv[lastBlockLength][0]) +
           (s * dv[lastBlockLength][1])) +
          (scaleFactor * dv[lastBlockLength][2]);
    }
  }
  firstBlockLength = 0;
  nblocks = 1;
  lastBlockLength = 2;
  sumOfPointDistancesFromOriginSquared = std::abs(normMatrix2[0][0]);
  s = std::abs(normMatrix2[0][1]);
  if (s > sumOfPointDistancesFromOriginSquared) {
    sumOfPointDistancesFromOriginSquared = s;
    firstBlockLength = 1;
    nblocks = 0;
  }
  if (std::abs(normMatrix2[0][2]) > sumOfPointDistancesFromOriginSquared) {
    firstBlockLength = 2;
    nblocks = 1;
    lastBlockLength = 0;
  }
  normMatrix2[0][nblocks] /= normMatrix2[0][firstBlockLength];
  normMatrix2[0][lastBlockLength] /= normMatrix2[0][firstBlockLength];
  normMatrix2[1][nblocks] -=
      normMatrix2[0][nblocks] * normMatrix2[1][firstBlockLength];
  normMatrix2[1][lastBlockLength] -=
      normMatrix2[0][lastBlockLength] * normMatrix2[1][firstBlockLength];
  normMatrix2[2][nblocks] -=
      normMatrix2[0][nblocks] * normMatrix2[2][firstBlockLength];
  normMatrix2[2][lastBlockLength] -=
      normMatrix2[0][lastBlockLength] * normMatrix2[2][firstBlockLength];
  if (std::abs(normMatrix2[1][lastBlockLength]) >
      std::abs(normMatrix2[1][nblocks])) {
    rtemp = nblocks;
    nblocks = lastBlockLength;
    lastBlockLength = rtemp;
  }
  normMatrix2[1][lastBlockLength] /= normMatrix2[1][nblocks];
  normMatrix2[2][lastBlockLength] -=
      normMatrix2[1][lastBlockLength] * normMatrix2[2][nblocks];
  sumOfPointDistancesFromOriginSquared =
      c_B[0][nblocks] - (c_B[0][firstBlockLength] * normMatrix2[0][nblocks]);
  s = ((c_B[0][lastBlockLength] -
        (c_B[0][firstBlockLength] * normMatrix2[0][lastBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][lastBlockLength])) /
      normMatrix2[2][lastBlockLength];
  d_Y[0][2] = s;
  sumOfPointDistancesFromOriginSquared -= s * normMatrix2[2][nblocks];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][nblocks];
  d_Y[0][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[0][0] =
      ((c_B[0][firstBlockLength] - (s * normMatrix2[2][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[0][firstBlockLength];
  sumOfPointDistancesFromOriginSquared =
      c_B[1][nblocks] - (c_B[1][firstBlockLength] * normMatrix2[0][nblocks]);
  s = ((c_B[1][lastBlockLength] -
        (c_B[1][firstBlockLength] * normMatrix2[0][lastBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][lastBlockLength])) /
      normMatrix2[2][lastBlockLength];
  d_Y[1][2] = s;
  sumOfPointDistancesFromOriginSquared -= s * normMatrix2[2][nblocks];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][nblocks];
  d_Y[1][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[1][0] =
      ((c_B[1][firstBlockLength] - (s * normMatrix2[2][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[0][firstBlockLength];
  sumOfPointDistancesFromOriginSquared =
      c_B[2][nblocks] - (c_B[2][firstBlockLength] * normMatrix2[0][nblocks]);
  s = ((c_B[2][lastBlockLength] -
        (c_B[2][firstBlockLength] * normMatrix2[0][lastBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][lastBlockLength])) /
      normMatrix2[2][lastBlockLength];
  d_Y[2][2] = s;
  sumOfPointDistancesFromOriginSquared -= s * normMatrix2[2][nblocks];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][nblocks];
  d_Y[2][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[2][0] =
      ((c_B[2][firstBlockLength] - (s * normMatrix2[2][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[0][firstBlockLength];
  inv(d_Y, dv);
  for (b_i = 0; b_i < 9; b_i++) {
    sumOfPointDistancesFromOriginSquared = (&dv[0][0])[b_i];
    (&tform->T[0][0])[b_i] = sumOfPointDistancesFromOriginSquared;
    b_tform[b_i] = sumOfPointDistancesFromOriginSquared;
  }
  sumOfPointDistancesFromOriginSquared = (&tform->T[0][0])[8];
  for (b_i = 0; b_i < 3; b_i++) {
    normMatrix2[b_i][0] =
        b_tform[3 * b_i] / sumOfPointDistancesFromOriginSquared;
    normMatrix2[b_i][1] =
        b_tform[(3 * b_i) + 1] / sumOfPointDistancesFromOriginSquared;
    normMatrix2[b_i][2] =
        b_tform[(3 * b_i) + 2] / sumOfPointDistancesFromOriginSquared;
  }
  for (b_i = 0; b_i < 9; b_i++) {
    (&tform->T[0][0])[b_i] = (&normMatrix2[0][0])[b_i];
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
