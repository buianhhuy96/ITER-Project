//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "ImageTransformer.h"
#include "calibrateHandeye_rtwutil.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &b_I
//                const double intrinsicMatrix[3][3]
//                const double radialDist[3]
//                const double tangentialDist[2]
//                const double xBounds[2]
//                const double yBounds[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void b_ImageTransformer::update(const ::coder::array<unsigned char, 3U> &b_I,
                                const double intrinsicMatrix[3][3],
                                const double radialDist[3],
                                const double tangentialDist[2],
                                const double xBounds[2],
                                const double yBounds[2])
{
  static const char cv1[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char cv[5]{'u', 'i', 'n', 't', '8'};
  array<double, 2U> Y;
  array<double, 2U> b_X;
  array<double, 2U> b_y;
  array<double, 2U> centeredPoints;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> normalizedPoints;
  array<double, 2U> y;
  array<double, 1U> b_b;
  array<double, 1U> c_b;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xNorm;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  double b[2];
  double a;
  double k_idx_0;
  double k_idx_1;
  int i;
  int i1;
  int j;
  int loop_ub;
  int nx;
  int ny;
  boolean_T b_bool;
  boolean_T guard1{false};
  boolean_T guard2{false};
  boolean_T guard3{false};
  this->SizeOfImage.set_size(1, 3);
  this->SizeOfImage[0] = static_cast<double>(b_I.size(0));
  this->SizeOfImage[1] = static_cast<double>(b_I.size(1));
  this->SizeOfImage[2] = static_cast<double>(b_I.size(2));
  this->ClassOfImage.set_size(1, 5);
  for (i = 0; i < 5; i++) {
    this->ClassOfImage[i] = cv[i];
  }
  this->OutputView.set_size(1, 4);
  this->OutputView[0] = 's';
  this->OutputView[1] = 'a';
  this->OutputView[2] = 'm';
  this->OutputView[3] = 'e';
  this->XBounds[0] = xBounds[0];
  this->YBounds[0] = yBounds[0];
  this->XBounds[1] = xBounds[1];
  this->YBounds[1] = yBounds[1];
  a = this->XBounds[0];
  k_idx_0 = this->XBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(a)) {
    guard2 = true;
  } else if (std::isnan(k_idx_0)) {
    guard2 = true;
  } else if (k_idx_0 < a) {
    y.set_size(1, 0);
  } else if (std::isinf(a)) {
    guard3 = true;
  } else if (std::isinf(k_idx_0)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (a == k_idx_0) {
      y.set_size(1, 1);
      y[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }
  if (guard2) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  }
  if (guard1) {
    if (std::floor(a) == a) {
      loop_ub = static_cast<int>(std::floor(k_idx_0 - a));
      y.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        y[i] = a + (static_cast<double>(i));
      }
    } else {
      eml_float_colon(a, k_idx_0, y);
    }
  }
  a = this->YBounds[0];
  k_idx_0 = this->YBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(a)) {
    guard2 = true;
  } else if (std::isnan(k_idx_0)) {
    guard2 = true;
  } else if (k_idx_0 < a) {
    b_y.set_size(1, 0);
  } else if (std::isinf(a)) {
    guard3 = true;
  } else if (std::isinf(k_idx_0)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (a == k_idx_0) {
      b_y.set_size(1, 1);
      b_y[0] = rtNaN;
    } else {
      guard1 = true;
    }
  }
  if (guard2) {
    b_y.set_size(1, 1);
    b_y[0] = rtNaN;
  }
  if (guard1) {
    if (std::floor(a) == a) {
      loop_ub = static_cast<int>(std::floor(k_idx_0 - a));
      b_y.set_size(1, loop_ub + 1);
      for (i = 0; i <= loop_ub; i++) {
        b_y[i] = a + (static_cast<double>(i));
      }
    } else {
      eml_float_colon(a, k_idx_0, b_y);
    }
  }
  nx = y.size(1);
  ny = b_y.size(1);
  b_X.set_size(b_y.size(1), y.size(1));
  Y.set_size(b_y.size(1), y.size(1));
  if (y.size(1) != 0) {
    if (b_y.size(1) != 0) {
      for (j = 0; j < nx; j++) {
        for (loop_ub = 0; loop_ub < ny; loop_ub++) {
          b_X[loop_ub + (b_X.size(0) * j)] = y[j];
          Y[loop_ub + (Y.size(0) * j)] = b_y[loop_ub];
        }
      }
    }
  }
  nx = b_X.size(0) * b_X.size(1);
  ny = Y.size(0) * Y.size(1);
  normalizedPoints.set_size(nx, 2);
  for (i = 0; i < nx; i++) {
    normalizedPoints[i] = b_X[i];
  }
  for (i = 0; i < ny; i++) {
    normalizedPoints[i + normalizedPoints.size(0)] = Y[i];
  }
  b[0] = intrinsicMatrix[0][2];
  b[1] = intrinsicMatrix[1][2];
  centeredPoints.set_size(normalizedPoints.size(0), 2);
  if (normalizedPoints.size(0) != 0) {
    nx = (normalizedPoints.size(0) != 1);
    for (j = 0; j < 2; j++) {
      i = centeredPoints.size(0) - 1;
      for (ny = 0; ny <= i; ny++) {
        centeredPoints[ny + (centeredPoints.size(0) * j)] =
            normalizedPoints[(nx * ny) + (normalizedPoints.size(0) * j)] - b[j];
      }
    }
  }
  loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    yNorm[i] =
        centeredPoints[i + centeredPoints.size(0)] / intrinsicMatrix[1][1];
  }
  loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    xNorm[i] = centeredPoints[i] / intrinsicMatrix[0][0];
  }
  r2.set_size(xNorm.size(0));
  nx = xNorm.size(0);
  for (j = 0; j < nx; j++) {
    r2[j] = rt_powd_snf(xNorm[j], 2.0);
  }
  r4.set_size(yNorm.size(0));
  nx = yNorm.size(0);
  for (j = 0; j < nx; j++) {
    r4[j] = rt_powd_snf(yNorm[j], 2.0);
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r2[i] = r2[i] + r4[i];
  }
  r4.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = r2[i] * r2[i];
  }
  k_idx_0 = radialDist[0];
  k_idx_1 = radialDist[1];
  r4.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    r4[i] = ((k_idx_0 * r2[i]) + (k_idx_1 * r4[i])) +
            (radialDist[2] * (r2[i] * r4[i]));
  }
  xyProduct.set_size(xNorm.size(0));
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    xyProduct[i] = xNorm[i] * yNorm[i];
  }
  b_b.set_size(xNorm.size(0));
  nx = xNorm.size(0);
  for (j = 0; j < nx; j++) {
    b_b[j] = rt_powd_snf(xNorm[j], 2.0);
  }
  a = 2.0 * tangentialDist[0];
  c_b.set_size(yNorm.size(0));
  nx = yNorm.size(0);
  for (j = 0; j < nx; j++) {
    c_b[j] = rt_powd_snf(yNorm[j], 2.0);
  }
  k_idx_0 = 2.0 * tangentialDist[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  loop_ub = xNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    normalizedPoints[i] = xNorm[i];
  }
  loop_ub = yNorm.size(0);
  for (i = 0; i < loop_ub; i++) {
    normalizedPoints[i + normalizedPoints.size(0)] = yNorm[i];
  }
  distortedNormalizedPoints.set_size(normalizedPoints.size(0), 2);
  loop_ub = normalizedPoints.size(0);
  for (i = 0; i < loop_ub; i++) {
    k_idx_1 = normalizedPoints[i];
    distortedNormalizedPoints[i] = k_idx_1 + (k_idx_1 * r4[i]);
  }
  loop_ub = normalizedPoints.size(0);
  for (i = 0; i < loop_ub; i++) {
    k_idx_1 = normalizedPoints[i + normalizedPoints.size(0)];
    distortedNormalizedPoints[i + distortedNormalizedPoints.size(0)] =
        k_idx_1 + (k_idx_1 * r4[i]);
  }
  normalizedPoints.set_size(xyProduct.size(0), 2);
  loop_ub = xyProduct.size(0);
  for (i = 0; i < loop_ub; i++) {
    normalizedPoints[i] =
        (a * xyProduct[i]) + (tangentialDist[1] * (r2[i] + (2.0 * b_b[i])));
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    normalizedPoints[i + normalizedPoints.size(0)] =
        (tangentialDist[0] * (r2[i] + (2.0 * c_b[i]))) +
        (k_idx_0 * xyProduct[i]);
  }
  distortedNormalizedPoints.set_size(distortedNormalizedPoints.size(0), 2);
  for (i = 0; i < 2; i++) {
    loop_ub = distortedNormalizedPoints.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      distortedNormalizedPoints[i1 + (distortedNormalizedPoints.size(0) * i)] =
          distortedNormalizedPoints[i1 +
                                    (distortedNormalizedPoints.size(0) * i)] +
          normalizedPoints[i1 + (normalizedPoints.size(0) * i)];
    }
  }
  loop_ub = distortedNormalizedPoints.size(0);
  nx = distortedNormalizedPoints.size(0);
  centeredPoints.set_size(distortedNormalizedPoints.size(0), 2);
  for (i = 0; i < loop_ub; i++) {
    centeredPoints[i] =
        ((distortedNormalizedPoints[i] * intrinsicMatrix[0][0]) +
         intrinsicMatrix[0][2]) +
        (intrinsicMatrix[0][1] *
         distortedNormalizedPoints[i + distortedNormalizedPoints.size(0)]);
  }
  for (i = 0; i < nx; i++) {
    centeredPoints[i + centeredPoints.size(0)] =
        (distortedNormalizedPoints[i + distortedNormalizedPoints.size(0)] *
         intrinsicMatrix[1][1]) +
        intrinsicMatrix[1][2];
  }
  b_bool = false;
  if (this->ClassOfImage.size(1) == 6) {
    nx = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (nx < 6) {
        if (this->ClassOfImage[nx] != cv1[nx]) {
          exitg1 = 1;
        } else {
          nx++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    k_idx_0 = (this->YBounds[1] - this->YBounds[0]) + 1.0;
    k_idx_1 = (this->XBounds[1] - this->XBounds[0]) + 1.0;
    nx = static_cast<int>(k_idx_0);
    ny = static_cast<int>(k_idx_1);
    loop_ub = centeredPoints.size(0);
    yNorm.set_size(centeredPoints.size(0));
    for (i = 0; i < loop_ub; i++) {
      yNorm[i] = centeredPoints[i];
    }
    j = static_cast<int>(k_idx_0);
    this->XmapSingle.set_size(j, static_cast<int>(k_idx_1));
    for (i = 0; i < ny; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        this->XmapSingle[i1 + (this->XmapSingle.size(0) * i)] =
            static_cast<float>(yNorm[i1 + ((static_cast<int>(k_idx_0)) * i)]);
      }
    }
    loop_ub = centeredPoints.size(0);
    yNorm.set_size(centeredPoints.size(0));
    for (i = 0; i < loop_ub; i++) {
      yNorm[i] = centeredPoints[i + centeredPoints.size(0)];
    }
    this->YmapSingle.set_size(j, static_cast<int>(k_idx_1));
    for (i = 0; i < ny; i++) {
      for (i1 = 0; i1 < nx; i1++) {
        this->YmapSingle[i1 + (this->YmapSingle.size(0) * i)] =
            static_cast<float>(yNorm[i1 + ((static_cast<int>(k_idx_0)) * i)]);
      }
    }
  }
}

} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for ImageTransformer.cpp
//
// [EOF]
//
