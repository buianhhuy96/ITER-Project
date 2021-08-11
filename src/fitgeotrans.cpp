//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fitgeotrans.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "fitgeotrans.h"
#include "calibrateHandeye_rtwutil.h"
#include "combineVectorElements.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rt_nonfinite.h"
#include "svd1.h"
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
namespace coder {
void findProjectiveTransform(const ::coder::array<double, 2U> &uv,
                             const ::coder::array<double, 2U> &xy,
                             projective2d *tform)
{
  array<double, 2U> b_X;
  array<double, 2U> b_r2;
  array<double, 2U> b_uv;
  array<double, 2U> b_xy;
  array<double, 1U> r;
  array<double, 1U> r1;
  array<double, 1U> u;
  array<double, 1U> v;
  array<double, 1U> x;
  array<double, 1U> y;
  double B[3][3];
  double Y[3][3];
  double b_tform[9];
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
    lastBlockLength = (uv.size(0) != 1);
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
  x.set_size(y.size(0));
  lastBlockLength = y.size(0);
  for (k = 0; k < lastBlockLength; k++) {
    x[k] = rt_powd_snf(y[k], 2.0);
  }
  sumOfPointDistancesFromOriginSquared = combineVectorElements(x);
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
  x.set_size(b_xy.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    x[firstBlockLength] = b_xy[firstBlockLength];
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
  v.set_size(b_uv.size(0));
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    v[firstBlockLength] = b_uv[firstBlockLength + b_uv.size(0)];
  }
  r.set_size(u.size(0));
  lastBlockLength = u.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength] = -u[firstBlockLength];
  }
  r1.set_size(v.size(0));
  lastBlockLength = v.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r1[firstBlockLength] = -v[firstBlockLength];
  }
  b_X.set_size(x.size(0) + b_xy.size(0), 8);
  lastBlockLength = x.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength] = x[firstBlockLength];
  }
  lastBlockLength = y.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + b_X.size(0)] = y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 2)] = 1.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 3)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 4)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 5)] = 0.0;
  }
  lastBlockLength = r.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 6)] =
        r[firstBlockLength] * x[firstBlockLength];
  }
  lastBlockLength = r.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + (b_X.size(0) * 7)] =
        r[firstBlockLength] * y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[firstBlockLength + x.size(0)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + b_X.size(0)] = 0.0;
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 2)] = 0.0;
  }
  lastBlockLength = x.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 3)] =
        x[firstBlockLength];
  }
  lastBlockLength = y.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 4)] =
        y[firstBlockLength];
  }
  lastBlockLength = b_xy.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 5)] = 1.0;
  }
  lastBlockLength = r1.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 6)] =
        r1[firstBlockLength] * x[firstBlockLength];
  }
  lastBlockLength = r1.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    b_X[(firstBlockLength + x.size(0)) + (b_X.size(0) * 7)] =
        r1[firstBlockLength] * y[firstBlockLength];
  }
  if (b_X.size(0) != 0) {
    boolean_T p;
    p = true;
    firstBlockLength = b_X.size(0);
    for (k = 0; k < 8; k++) {
      for (b_k = 0; b_k < firstBlockLength; b_k++) {
        sumOfPointDistancesFromOriginSquared = b_X[b_k + (b_X.size(0) * k)];
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
    if (p) {
      internal::c_svd(b_X, y);
    } else {
      b_r2.set_size(b_X.size(0), 8);
      lastBlockLength = b_X.size(0);
      for (firstBlockLength = 0; firstBlockLength < 8; firstBlockLength++) {
        for (r2 = 0; r2 < lastBlockLength; r2++) {
          b_r2[r2 + (b_r2.size(0) * firstBlockLength)] = 0.0;
        }
      }
      internal::c_svd(b_r2, r);
      y.set_size(r.size(0));
      lastBlockLength = r.size(0);
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
  r.set_size(u.size(0) + v.size(0));
  lastBlockLength = u.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength] = u[firstBlockLength];
  }
  lastBlockLength = v.size(0);
  for (firstBlockLength = 0; firstBlockLength < lastBlockLength;
       firstBlockLength++) {
    r[firstBlockLength + u.size(0)] = v[firstBlockLength];
  }
  mldivide(b_X, r);
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
      B[r2][firstBlockLength] =
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
      B[0][r2] - (B[0][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor = ((B[0][firstBlockLength] -
                  (B[0][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
                 (sumOfPointDistancesFromOriginSquared *
                  normMatrix2[1][firstBlockLength])) /
                normMatrix2[2][firstBlockLength];
  Y[0][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  Y[0][1] = sumOfPointDistancesFromOriginSquared;
  Y[0][0] = ((B[0][lastBlockLength] -
              (scaleFactor * normMatrix2[2][lastBlockLength])) -
             (sumOfPointDistancesFromOriginSquared *
              normMatrix2[1][lastBlockLength])) /
            normMatrix2[0][lastBlockLength];
  sumOfPointDistancesFromOriginSquared =
      B[1][r2] - (B[1][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor = ((B[1][firstBlockLength] -
                  (B[1][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
                 (sumOfPointDistancesFromOriginSquared *
                  normMatrix2[1][firstBlockLength])) /
                normMatrix2[2][firstBlockLength];
  Y[1][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  Y[1][1] = sumOfPointDistancesFromOriginSquared;
  Y[1][0] = ((B[1][lastBlockLength] -
              (scaleFactor * normMatrix2[2][lastBlockLength])) -
             (sumOfPointDistancesFromOriginSquared *
              normMatrix2[1][lastBlockLength])) /
            normMatrix2[0][lastBlockLength];
  sumOfPointDistancesFromOriginSquared =
      B[2][r2] - (B[2][lastBlockLength] * normMatrix2[0][r2]);
  scaleFactor = ((B[2][firstBlockLength] -
                  (B[2][lastBlockLength] * normMatrix2[0][firstBlockLength])) -
                 (sumOfPointDistancesFromOriginSquared *
                  normMatrix2[1][firstBlockLength])) /
                normMatrix2[2][firstBlockLength];
  Y[2][2] = scaleFactor;
  sumOfPointDistancesFromOriginSquared -= scaleFactor * normMatrix2[2][r2];
  sumOfPointDistancesFromOriginSquared /= normMatrix2[1][r2];
  Y[2][1] = sumOfPointDistancesFromOriginSquared;
  Y[2][0] = ((B[2][lastBlockLength] -
              (scaleFactor * normMatrix2[2][lastBlockLength])) -
             (sumOfPointDistancesFromOriginSquared *
              normMatrix2[1][lastBlockLength])) /
            normMatrix2[0][lastBlockLength];
  inv(Y, dv);
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

//
// File trailer for fitgeotrans.cpp
//
// [EOF]
//
