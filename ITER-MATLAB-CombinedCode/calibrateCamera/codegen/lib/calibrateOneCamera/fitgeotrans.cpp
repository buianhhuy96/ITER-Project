//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "fitgeotrans.h"
#include "calibrateOneCamera_rtwutil.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &uv
//                const ::coder::array<double, 2U> &xy
//                projective2d *tform
// Return Type  : void
//
namespace Codegen {
namespace coder {
void findProjectiveTransform(const ::coder::array<double, 2U> &uv,
                             const ::coder::array<double, 2U> &xy,
                             projective2d *tform)
{
  ::coder::array<double, 2U> b_uv;
  ::coder::array<double, 2U> b_xy;
  ::coder::array<double, 2U> d_X;
  ::coder::array<double, 1U> b_v;
  ::coder::array<double, 1U> b_x;
  ::coder::array<double, 1U> r;
  ::coder::array<double, 1U> r1;
  ::coder::array<double, 1U> u;
  ::coder::array<double, 1U> y;
  double b_tform[9];
  double c_B[3][3];
  double d_Y[3][3];
  double dv[3][3];
  double normMatrix2[3][3];
  double cent[2];
  double scaleFactor;
  double sumOfPointDistancesFromOriginSquared;
  int b_k;
  int exponent;
  int firstBlockLength;
  int k;
  int lastBlockLength;
  int nblocks;
  int r2;
  r2 = uv.size(0);
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
        if (r2 >= 2) {
          cent[k] += uv[(b_k + (uv.size(0) * k)) - 1];
        }
      }
      for (int ib{2}; ib <= nblocks; ib++) {
        int hi;
        int offset;
        offset = (ib - 1) * 1024;
        sumOfPointDistancesFromOriginSquared = uv[offset + (uv.size(0) * k)];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        for (b_k = 2; b_k <= hi; b_k++) {
          if (r2 >= 2) {
            sumOfPointDistancesFromOriginSquared +=
                uv[((offset + b_k) + (uv.size(0) * k)) - 1];
          }
        }
        cent[k] += sumOfPointDistancesFromOriginSquared;
      }
    }
  }
  cent[0] /= static_cast<double>(uv.size(0));
  cent[1] /= static_cast<double>(uv.size(0));
  b_uv.set_size(uv.size(0), 2);
  if (uv.size(0) != 0) {
    lastBlockLength = static_cast<int>(uv.size(0) != 1);
    for (k = 0; k < 2; k++) {
      firstBlockLength = b_uv.size(0) - 1;
      for (b_k = 0; b_k <= firstBlockLength; b_k++) {
        b_uv[b_k + (b_uv.size(0) * k)] =
            uv[(lastBlockLength * b_k) + (uv.size(0) * k)] - cent[k];
      }
    }
  }
  y.set_size(b_uv.size(0));
  lastBlockLength = b_uv.size(0);
  for (k = 0; k < lastBlockLength; k++) {
    y[k] = rt_hypotd_snf(b_uv[k], b_uv[k + b_uv.size(0)]);
  }
  b_x.set_size(y.size(0));
  lastBlockLength = y.size(0);
  for (k = 0; k < lastBlockLength; k++) {
    b_x[k] = rt_powd_snf(y[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(b_x);
  if (sumOfPointDistancesFromOriginSquared > 0.0) {
    scaleFactor = std::sqrt(2.0 * (static_cast<double>(uv.size(0)))) /
                  std::sqrt(sumOfPointDistancesFromOriginSquared);
  } else {
    scaleFactor = 1.0;
  }
  b_uv.set_size(b_uv.size(0), 2);
  for (firstBlockLength = 0; firstBlockLength < 2; firstBlockLength++) {
    lastBlockLength = b_uv.size(0);
    for (r2 = 0; r2 < lastBlockLength; r2++) {
      b_uv[r2 + (b_uv.size(0) * firstBlockLength)] =
          b_uv[r2 + (b_uv.size(0) * firstBlockLength)] * scaleFactor;
    }
  }
  images::geotrans::internal::normalizeControlPoints(xy, b_xy, normMatrix2);
  lastBlockLength = b_xy.size(0);
  b_x.set_size(b_xy.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_x[firstBlockLength] = b_xy[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  y.set_size(b_xy.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    y[firstBlockLength] = b_xy[firstBlockLength + b_xy.size(0)];
  }
  lastBlockLength = b_uv.size(0);
  u.set_size(b_uv.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    u[firstBlockLength] = b_uv[firstBlockLength];
  }
  lastBlockLength = b_uv.size(0);
  b_v.set_size(b_uv.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_v[firstBlockLength] = b_uv[firstBlockLength + b_uv.size(0)];
  }
  r.set_size(u.size(0));
  lastBlockLength = u.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength] = -u[firstBlockLength];
  }
  r1.set_size(b_v.size(0));
  lastBlockLength = b_v.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r1[firstBlockLength] = -b_v[firstBlockLength];
  }
  d_X.set_size(b_x.size(0) + b_xy.size(0), 8);
  lastBlockLength = b_x.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength] = b_x[firstBlockLength];
  }
  lastBlockLength = y.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + d_X.size(0)] = y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 2)] = 1.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 3)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 4)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 5)] = 0.0;
  }
  lastBlockLength = r.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 6)] =
        r[firstBlockLength] * b_x[firstBlockLength];
  }
  lastBlockLength = r.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + (d_X.size(0) * 7)] =
        r[firstBlockLength] * y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[firstBlockLength + b_x.size(0)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + d_X.size(0)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 2)] = 0.0;
  }
  lastBlockLength = b_x.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 3)] =
        b_x[firstBlockLength];
  }
  lastBlockLength = y.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 4)] =
        y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 5)] = 1.0;
  }
  lastBlockLength = r1.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 6)] =
        r1[firstBlockLength] * b_x[firstBlockLength];
  }
  lastBlockLength = r1.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    d_X[(firstBlockLength + b_x.size(0)) + (d_X.size(0) * 7)] =
        r1[firstBlockLength] * y[firstBlockLength];
  }
  if (d_X.size(0) != 0) {
    bool p;
    p = true;
    firstBlockLength = d_X.size(0);
    for (k = 0; k < 8; k++) {
      for (b_k = 0; b_k < firstBlockLength; b_k++) {
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
        static_cast<int>(std::fmin(static_cast<double>(d_X.size(0)), 8.0));
    if (p) {
      internal::svd(d_X, y);
    } else {
      y.set_size(lastBlockLength);
      for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
           firstBlockLength++) {
        y[firstBlockLength] = rtNaN;
      }
    }
    sumOfPointDistancesFromOriginSquared = std::abs(y[0]);
    if ((!std::isinf(sumOfPointDistancesFromOriginSquared)) &&
        (!std::isnan(sumOfPointDistancesFromOriginSquared))) {
      if (!(sumOfPointDistancesFromOriginSquared <= 2.2250738585072014E-308)) {
        (void)frexp(sumOfPointDistancesFromOriginSquared, &exponent);
      }
    }
  }
  r.set_size(u.size(0) + b_v.size(0));
  lastBlockLength = u.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength] = u[firstBlockLength];
  }
  lastBlockLength = b_v.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength + u.size(0)] = b_v[firstBlockLength];
  }
  mldivide(d_X, r);
  for (firstBlockLength = 0; firstBlockLength < 8; firstBlockLength++) {
    (&tform->T[0][0])[firstBlockLength] = r[firstBlockLength];
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
  for (firstBlockLength = 0; firstBlockLength < 3; firstBlockLength++) {
    double d;
    sumOfPointDistancesFromOriginSquared = tform->T[0][firstBlockLength];
    scaleFactor = tform->T[1][firstBlockLength];
    d = tform->T[2][firstBlockLength];
    for (r2 = 0; r2 < 3; r2++) {
      c_B[r2][firstBlockLength] =
          ((sumOfPointDistancesFromOriginSquared * dv[r2][0]) +
           (scaleFactor * dv[r2][1])) +
          (d * dv[r2][2]);
    }
  }
  lastBlockLength = 0;
  r2 = 1;
  firstBlockLength = 2;
  sumOfPointDistancesFromOriginSquared = std::abs(normMatrix2[0][0]);
  scaleFactor = std::abs(normMatrix2[0][1]);
  if (scaleFactor > sumOfPointDistancesFromOriginSquared) {
    sumOfPointDistancesFromOriginSquared = scaleFactor;
    lastBlockLength = 1;
    r2 = 0;
  }
  if (std::abs(normMatrix2[0][2]) > sumOfPointDistancesFromOriginSquared) {
    lastBlockLength = 2;
    r2 = 1;
    firstBlockLength = 0;
  }
  normMatrix2[0][r2] /= normMatrix2[0][lastBlockLength];
  normMatrix2[0][firstBlockLength] /= normMatrix2[0][lastBlockLength];
  normMatrix2[1][r2] -= normMatrix2[0][r2] * normMatrix2[1][lastBlockLength];
  normMatrix2[1][firstBlockLength] -=
      normMatrix2[0][firstBlockLength] * normMatrix2[1][lastBlockLength];
  normMatrix2[2][r2] -= normMatrix2[0][r2] * normMatrix2[2][lastBlockLength];
  normMatrix2[2][firstBlockLength] -=
      normMatrix2[0][firstBlockLength] * normMatrix2[2][lastBlockLength];
  if (std::abs(normMatrix2[1][firstBlockLength]) >
      std::abs(normMatrix2[1][r2])) {
    nblocks = r2;
    r2 = firstBlockLength;
    firstBlockLength = nblocks;
  }
  normMatrix2[1][firstBlockLength] /= normMatrix2[1][r2];
  normMatrix2[2][firstBlockLength] -=
      normMatrix2[1][firstBlockLength] * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared =
      c_B[0][r2] - (c_B[0][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor =
      ((c_B[0][firstBlockLength] -
        (c_B[0][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[2][firstBlockLength];
  d_Y[0][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  d_Y[0][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[0][0] = ((c_B[0][lastBlockLength] -
                (scaleFactor * normMatrix2[2][lastBlockLength])) -
               (sumOfPointDistancesFromOriginSquared *
                normMatrix2[1][lastBlockLength])) /
              normMatrix2[0][lastBlockLength];
  sumOfPointDistancesFromOriginSquared =
      c_B[1][r2] - (c_B[1][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor =
      ((c_B[1][firstBlockLength] -
        (c_B[1][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[2][firstBlockLength];
  d_Y[1][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  d_Y[1][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[1][0] = ((c_B[1][lastBlockLength] -
                (scaleFactor * normMatrix2[2][lastBlockLength])) -
               (sumOfPointDistancesFromOriginSquared *
                normMatrix2[1][lastBlockLength])) /
              normMatrix2[0][lastBlockLength];
  sumOfPointDistancesFromOriginSquared =
      c_B[2][r2] - (c_B[2][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor =
      ((c_B[2][firstBlockLength] -
        (c_B[2][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
       (sumOfPointDistancesFromOriginSquared *
        normMatrix2[1][firstBlockLength])) /
      normMatrix2[2][firstBlockLength];
  d_Y[2][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  d_Y[2][1] = sumOfPointDistancesFromOriginSquared;
  d_Y[2][0] = ((c_B[2][lastBlockLength] -
                (scaleFactor * normMatrix2[2][lastBlockLength])) -
               (sumOfPointDistancesFromOriginSquared *
                normMatrix2[1][lastBlockLength])) /
              normMatrix2[0][lastBlockLength];
  inv(d_Y, dv);
  for (firstBlockLength = 0; firstBlockLength < 9; firstBlockLength++) {
    sumOfPointDistancesFromOriginSquared = (&dv[0][0])[firstBlockLength];
    (&tform->T[0][0])[firstBlockLength] = sumOfPointDistancesFromOriginSquared;
    b_tform[firstBlockLength] = sumOfPointDistancesFromOriginSquared;
  }
  sumOfPointDistancesFromOriginSquared = (&tform->T[0][0])[8];
  for (firstBlockLength = 0; firstBlockLength < 3; firstBlockLength++) {
    normMatrix2[firstBlockLength][0] =
        b_tform[3 * firstBlockLength] / sumOfPointDistancesFromOriginSquared;
    normMatrix2[firstBlockLength][1] = b_tform[(3 * firstBlockLength) + 1] /
                                       sumOfPointDistancesFromOriginSquared;
    normMatrix2[firstBlockLength][2] = b_tform[(3 * firstBlockLength) + 2] /
                                       sumOfPointDistancesFromOriginSquared;
  }
  for (firstBlockLength = 0; firstBlockLength < 9; firstBlockLength++) {
    (&tform->T[0][0])[firstBlockLength] =
        (&normMatrix2[0][0])[firstBlockLength];
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
