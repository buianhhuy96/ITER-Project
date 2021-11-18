//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ImageTransformer.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
// Arguments    : const ::coder::array<unsigned char, 3U> &e_I
//                const double b_intrinsicMatrix[3][3]
//                const double radialDist[3]
//                const double tangentialDist[2]
//                const double b_xBounds[2]
//                const double b_yBounds[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void b_ImageTransformer::update(const ::coder::array<unsigned char, 3U> &e_I,
                                const double b_intrinsicMatrix[3][3],
                                const double radialDist[3],
                                const double tangentialDist[2],
                                const double b_xBounds[2],
                                const double b_yBounds[2])
{
  static const char cv1[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char b_cv[5]{'u', 'i', 'n', 't', '8'};
  static const char b_outputView[4]{'s', 'a', 'm', 'e'};
  array<double, 2U> b_y;
  array<double, 2U> centeredPoints;
  array<double, 2U> d_X;
  array<double, 2U> distortedNormalizedPoints;
  array<double, 2U> g_Y;
  array<double, 2U> normalizedPoints;
  array<double, 2U> y;
  array<double, 1U> b;
  array<double, 1U> d_b;
  array<double, 1U> r2;
  array<double, 1U> r4;
  array<double, 1U> xNorm;
  array<double, 1U> xyProduct;
  array<double, 1U> yNorm;
  double center[2];
  double b_a;
  double k_idx_0;
  double k_idx_1;
  int b_i;
  int i1;
  int j;
  int loop_ub;
  int nx;
  int ny;
  bool b_bool;
  bool guard1{false};
  bool guard2{false};
  bool guard3{false};
  SizeOfImage.set_size(1, 3);
  SizeOfImage[0] = static_cast<double>(e_I.size(0));
  SizeOfImage[1] = static_cast<double>(e_I.size(1));
  SizeOfImage[2] = static_cast<double>(e_I.size(2));
  ClassOfImage.set_size(1, 5);
  for (b_i = 0; b_i < 5; b_i++) {
    ClassOfImage[b_i] = b_cv[b_i];
  }
  OutputView.set_size(1, 4);
  for (b_i = 0; b_i < 4; b_i++) {
    OutputView[b_i] = b_outputView[b_i];
  }
  XBounds[0] = b_xBounds[0];
  YBounds[0] = b_yBounds[0];
  XBounds[1] = b_xBounds[1];
  YBounds[1] = b_yBounds[1];
  b_a = XBounds[0];
  k_idx_0 = XBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(b_a)) {
    guard2 = true;
  } else if (std::isnan(k_idx_0)) {
    guard2 = true;
  } else if (k_idx_0 < b_a) {
    y.set_size(1, 0);
  } else if (std::isinf(b_a)) {
    guard3 = true;
  } else if (std::isinf(k_idx_0)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (b_a == k_idx_0) {
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
    if (std::floor(b_a) == b_a) {
      loop_ub = static_cast<int>(std::floor(k_idx_0 - b_a));
      y.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        y[b_i] = b_a + (static_cast<double>(b_i));
      }
    } else {
      eml_float_colon(b_a, k_idx_0, y);
    }
  }
  b_a = YBounds[0];
  k_idx_0 = YBounds[1];
  guard1 = false;
  guard2 = false;
  guard3 = false;
  if (std::isnan(b_a)) {
    guard2 = true;
  } else if (std::isnan(k_idx_0)) {
    guard2 = true;
  } else if (k_idx_0 < b_a) {
    b_y.set_size(1, 0);
  } else if (std::isinf(b_a)) {
    guard3 = true;
  } else if (std::isinf(k_idx_0)) {
    guard3 = true;
  } else {
    guard1 = true;
  }
  if (guard3) {
    if (b_a == k_idx_0) {
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
    if (std::floor(b_a) == b_a) {
      loop_ub = static_cast<int>(std::floor(k_idx_0 - b_a));
      b_y.set_size(1, loop_ub + 1);
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        b_y[b_i] = b_a + (static_cast<double>(b_i));
      }
    } else {
      eml_float_colon(b_a, k_idx_0, b_y);
    }
  }
  nx = y.size(1);
  ny = b_y.size(1);
  d_X.set_size(b_y.size(1), y.size(1));
  g_Y.set_size(b_y.size(1), y.size(1));
  if (y.size(1) != 0) {
    if (b_y.size(1) != 0) {
      for (j = 0; j < nx; j++) {
        for (loop_ub = 0; loop_ub < ny; loop_ub++) {
          d_X[loop_ub + (d_X.size(0) * j)] = y[j];
          g_Y[loop_ub + (g_Y.size(0) * j)] = b_y[loop_ub];
        }
      }
    }
  }
  nx = d_X.size(0) * d_X.size(1);
  ny = g_Y.size(0) * g_Y.size(1);
  normalizedPoints.set_size(nx, 2);
  for (b_i = 0; b_i < nx; b_i++) {
    normalizedPoints[b_i] = d_X[b_i];
  }
  for (b_i = 0; b_i < ny; b_i++) {
    normalizedPoints[b_i + normalizedPoints.size(0)] = g_Y[b_i];
  }
  center[0] = b_intrinsicMatrix[0][2];
  center[1] = b_intrinsicMatrix[1][2];
  centeredPoints.set_size(normalizedPoints.size(0), 2);
  if (normalizedPoints.size(0) != 0) {
    nx = static_cast<int>(normalizedPoints.size(0) != 1);
    for (j = 0; j < 2; j++) {
      b_i = centeredPoints.size(0) - 1;
      for (ny = 0; ny <= b_i; ny++) {
        centeredPoints[ny + (centeredPoints.size(0) * j)] =
            normalizedPoints[(nx * ny) + (normalizedPoints.size(0) * j)] -
            center[j];
      }
    }
  }
  loop_ub = centeredPoints.size(0);
  yNorm.set_size(centeredPoints.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    yNorm[b_i] =
        centeredPoints[b_i + centeredPoints.size(0)] / b_intrinsicMatrix[1][1];
  }
  loop_ub = centeredPoints.size(0);
  xNorm.set_size(centeredPoints.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    xNorm[b_i] = centeredPoints[b_i] / b_intrinsicMatrix[0][0];
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
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r2[b_i] = r2[b_i] + r4[b_i];
  }
  r4.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r4[b_i] = r2[b_i] * r2[b_i];
  }
  k_idx_0 = radialDist[0];
  k_idx_1 = radialDist[1];
  r4.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    r4[b_i] = ((k_idx_0 * r2[b_i]) + (k_idx_1 * r4[b_i])) +
              (radialDist[2] * (r2[b_i] * r4[b_i]));
  }
  xyProduct.set_size(xNorm.size(0));
  loop_ub = xNorm.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    xyProduct[b_i] = xNorm[b_i] * yNorm[b_i];
  }
  b.set_size(xNorm.size(0));
  nx = xNorm.size(0);
  for (j = 0; j < nx; j++) {
    b[j] = rt_powd_snf(xNorm[j], 2.0);
  }
  b_a = 2.0 * tangentialDist[0];
  d_b.set_size(yNorm.size(0));
  nx = yNorm.size(0);
  for (j = 0; j < nx; j++) {
    d_b[j] = rt_powd_snf(yNorm[j], 2.0);
  }
  k_idx_0 = 2.0 * tangentialDist[1];
  normalizedPoints.set_size(xNorm.size(0), 2);
  loop_ub = xNorm.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    normalizedPoints[b_i] = xNorm[b_i];
  }
  loop_ub = yNorm.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    normalizedPoints[b_i + normalizedPoints.size(0)] = yNorm[b_i];
  }
  distortedNormalizedPoints.set_size(normalizedPoints.size(0), 2);
  loop_ub = normalizedPoints.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    k_idx_1 = normalizedPoints[b_i];
    distortedNormalizedPoints[b_i] = k_idx_1 + (k_idx_1 * r4[b_i]);
  }
  loop_ub = normalizedPoints.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    k_idx_1 = normalizedPoints[b_i + normalizedPoints.size(0)];
    distortedNormalizedPoints[b_i + distortedNormalizedPoints.size(0)] =
        k_idx_1 + (k_idx_1 * r4[b_i]);
  }
  normalizedPoints.set_size(xyProduct.size(0), 2);
  loop_ub = xyProduct.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    normalizedPoints[b_i] = (b_a * xyProduct[b_i]) +
                            (tangentialDist[1] * (r2[b_i] + (2.0 * b[b_i])));
  }
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    normalizedPoints[b_i + normalizedPoints.size(0)] =
        (tangentialDist[0] * (r2[b_i] + (2.0 * d_b[b_i]))) +
        (k_idx_0 * xyProduct[b_i]);
  }
  distortedNormalizedPoints.set_size(distortedNormalizedPoints.size(0), 2);
  for (b_i = 0; b_i < 2; b_i++) {
    loop_ub = distortedNormalizedPoints.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      distortedNormalizedPoints[i1 +
                                (distortedNormalizedPoints.size(0) * b_i)] =
          distortedNormalizedPoints[i1 +
                                    (distortedNormalizedPoints.size(0) * b_i)] +
          normalizedPoints[i1 + (normalizedPoints.size(0) * b_i)];
    }
  }
  loop_ub = distortedNormalizedPoints.size(0);
  nx = distortedNormalizedPoints.size(0);
  centeredPoints.set_size(distortedNormalizedPoints.size(0), 2);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    centeredPoints[b_i] =
        ((distortedNormalizedPoints[b_i] * b_intrinsicMatrix[0][0]) +
         b_intrinsicMatrix[0][2]) +
        (b_intrinsicMatrix[0][1] *
         distortedNormalizedPoints[b_i + distortedNormalizedPoints.size(0)]);
  }
  for (b_i = 0; b_i < nx; b_i++) {
    centeredPoints[b_i + centeredPoints.size(0)] =
        (distortedNormalizedPoints[b_i + distortedNormalizedPoints.size(0)] *
         b_intrinsicMatrix[1][1]) +
        b_intrinsicMatrix[1][2];
  }
  b_bool = false;
  if (ClassOfImage.size(1) == 6) {
    nx = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (nx < 6) {
        if (ClassOfImage[nx] != cv1[nx]) {
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
    k_idx_0 = (YBounds[1] - YBounds[0]) + 1.0;
    k_idx_1 = (XBounds[1] - XBounds[0]) + 1.0;
    nx = static_cast<int>(k_idx_0);
    ny = static_cast<int>(k_idx_1);
    loop_ub = centeredPoints.size(0);
    yNorm.set_size(centeredPoints.size(0));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      yNorm[b_i] = centeredPoints[b_i];
    }
    j = static_cast<int>(k_idx_0);
    XmapSingle.set_size(j, static_cast<int>(k_idx_1));
    for (b_i = 0; b_i < ny; b_i++) {
      for (i1 = 0; i1 < nx; i1++) {
        XmapSingle[i1 + (XmapSingle.size(0) * b_i)] =
            static_cast<float>(yNorm[i1 + ((static_cast<int>(k_idx_0)) * b_i)]);
      }
    }
    loop_ub = centeredPoints.size(0);
    yNorm.set_size(centeredPoints.size(0));
    for (b_i = 0; b_i < loop_ub; b_i++) {
      yNorm[b_i] = centeredPoints[b_i + centeredPoints.size(0)];
    }
    YmapSingle.set_size(j, static_cast<int>(k_idx_1));
    for (b_i = 0; b_i < ny; b_i++) {
      for (i1 = 0; i1 < nx; i1++) {
        YmapSingle[i1 + (YmapSingle.size(0) * b_i)] =
            static_cast<float>(yNorm[i1 + ((static_cast<int>(k_idx_0)) * b_i)]);
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
