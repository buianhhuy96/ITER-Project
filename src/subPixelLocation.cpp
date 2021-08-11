//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: subPixelLocation.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "subPixelLocation.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>

// Variable Definitions
static double X[25][6];

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &metric
//                ::coder::array<double, 2U> &loc
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void subPixelLocation(const ::coder::array<float, 2U> &metric,
                      ::coder::array<double, 2U> &loc)
{
  array<double, 2U> b_loc;
  array<float, 2U> b_metric;
  array<float, 2U> subPixelLoc;
  array<boolean_T, 1U> x;
  float beta[6];
  int i;
  i = loc.size(0);
  for (int id{0}; id < i; id++) {
    int i1;
    int loop_ub;
    boolean_T exitg1;
    boolean_T guard1{false};
    boolean_T y;
    loop_ub = loc.size(1);
    b_loc.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_loc[i1] = loc[id + (loc.size(0) * i1)];
    }
    loop_ub = loc.size(1);
    x.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      x[i1] = (b_loc[i1] < 3.0);
    }
    y = false;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= (x.size(0) - 1))) {
      if (!x[loop_ub]) {
        loop_ub++;
      } else {
        y = true;
        exitg1 = true;
      }
    }
    guard1 = false;
    if (y) {
      guard1 = true;
    } else if (loc[id] >
               (((static_cast<double>(metric.size(1))) - 2.0) - 1.0)) {
      guard1 = true;
    } else if (loc[id + loc.size(0)] >
               (((static_cast<double>(metric.size(0))) - 2.0) - 1.0)) {
      guard1 = true;
    } else {
      float b_x;
      float b_y;
      int b_loop_ub;
      int i2;
      int i3;
      int i4;
      boolean_T guard2{false};
      if ((loc[id + loc.size(0)] - 2.0) > (loc[id + loc.size(0)] + 2.0)) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (static_cast<int>(
                 static_cast<double>(loc[id + loc.size(0)] - 2.0))) -
             1;
        i2 = static_cast<int>(static_cast<double>(loc[id + loc.size(0)] + 2.0));
      }
      if ((loc[id] - 2.0) > (loc[id] + 2.0)) {
        i3 = 0;
        i4 = 0;
      } else {
        i3 = (static_cast<int>(static_cast<double>(loc[id] - 2.0))) - 1;
        i4 = static_cast<int>(static_cast<double>(loc[id] + 2.0));
      }
      loop_ub = i2 - i1;
      b_loop_ub = i4 - i3;
      b_metric.set_size(loop_ub, b_loop_ub);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        for (i4 = 0; i4 < loop_ub; i4++) {
          b_metric[i4 + (b_metric.size(0) * i2)] =
              metric[(i1 + i4) + (metric.size(0) * (i3 + i2))];
        }
      }
      for (i1 = 0; i1 < 6; i1++) {
        b_y = 0.0F;
        for (i2 = 0; i2 < 25; i2++) {
          b_y += (static_cast<float>(X[i2][i1])) * b_metric[i2];
        }
        beta[i1] = b_y;
      }
      b_y = ((4.0F * beta[0]) * beta[1]) - rt_powf_snf(beta[4], 2.0F);
      b_x = (-(((2.0F * beta[1]) * beta[2]) - (beta[3] * beta[4]))) / b_y;
      b_y = (-(((2.0F * beta[0]) * beta[3]) - (beta[2] * beta[4]))) / b_y;
      guard2 = false;
      if ((std::isinf(b_x)) || (std::isnan(b_x))) {
        guard2 = true;
      } else if (std::abs(b_x) > 2.0F) {
        guard2 = true;
      } else if ((std::isinf(b_y)) || (std::isnan(b_y))) {
        guard2 = true;
      } else if (std::abs(b_y) > 2.0F) {
        guard2 = true;
      } else {
        /* no actions */
      }
      if (guard2) {
        b_x = 0.0F;
        b_y = 0.0F;
      }
      subPixelLoc.set_size(1, 2);
      subPixelLoc[0] = (static_cast<float>(b_loc[0])) + b_x;
      subPixelLoc[1] = (static_cast<float>(b_loc[1])) + b_y;
    }
    if (guard1) {
      subPixelLoc.set_size(1, b_loc.size(1));
      loop_ub = b_loc.size(1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        subPixelLoc[i1] = static_cast<float>(b_loc[i1]);
      }
    }
    loop_ub = subPixelLoc.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      loc[id + (loc.size(0) * i1)] = static_cast<double>(subPixelLoc[i1]);
    }
  }
}

//
// Arguments    : void
// Return Type  : void
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
void subPixelLocationImpl_init()
{
  static const double dv[25][6]{{0.028571428571428574, 0.028571428571428574,
                                 -0.04, -0.04, 0.04, -0.0742857142857143},
                                {0.028571428571428574, -0.014285714285714285,
                                 -0.04, -0.02, 0.02, 0.01142857142857142},
                                {0.028571428571428574, -0.028571428571428571,
                                 -0.04, 0.0, 0.0, 0.039999999999999994},
                                {0.028571428571428574, -0.014285714285714285,
                                 -0.04, 0.02, -0.02, 0.01142857142857142},
                                {0.028571428571428574, 0.028571428571428574,
                                 -0.04, 0.04, -0.04, -0.0742857142857143},
                                {-0.014285714285714287, 0.028571428571428571,
                                 -0.02, -0.04, 0.02, 0.011428571428571429},
                                {-0.014285714285714285, -0.014285714285714284,
                                 -0.02, -0.02, 0.01, 0.097142857142857142},
                                {-0.01428571428571429, -0.028571428571428574,
                                 -0.02, 0.0, 0.0, 0.12571428571428572},
                                {-0.014285714285714285, -0.014285714285714284,
                                 -0.02, 0.02, -0.01, 0.097142857142857142},
                                {-0.014285714285714287, 0.028571428571428571,
                                 -0.02, 0.04, -0.02, 0.011428571428571429},
                                {-0.028571428571428574, 0.028571428571428571,
                                 0.0, -0.04, 0.0, 0.040000000000000008},
                                {-0.028571428571428574, -0.014285714285714287,
                                 0.0, -0.02, 0.0, 0.12571428571428572},
                                {-0.028571428571428574, -0.028571428571428574,
                                 0.0, 0.0, 0.0, 0.1542857142857143},
                                {-0.028571428571428574, -0.014285714285714287,
                                 0.0, 0.02, 0.0, 0.12571428571428572},
                                {-0.028571428571428574, 0.028571428571428571,
                                 0.0, 0.04, 0.0, 0.040000000000000008},
                                {-0.014285714285714287, 0.028571428571428571,
                                 0.02, -0.04, -0.02, 0.011428571428571429},
                                {-0.014285714285714285, -0.014285714285714284,
                                 0.02, -0.02, -0.01, 0.097142857142857142},
                                {-0.01428571428571429, -0.028571428571428574,
                                 0.02, 0.0, 0.0, 0.12571428571428572},
                                {-0.014285714285714285, -0.014285714285714284,
                                 0.02, 0.02, 0.01, 0.097142857142857142},
                                {-0.014285714285714287, 0.028571428571428571,
                                 0.02, 0.04, 0.02, 0.011428571428571429},
                                {0.028571428571428574, 0.028571428571428574,
                                 0.04, -0.04, -0.04, -0.0742857142857143},
                                {0.028571428571428574, -0.014285714285714285,
                                 0.04, -0.02, -0.02, 0.01142857142857142},
                                {0.028571428571428574, -0.028571428571428571,
                                 0.04, 0.0, 0.0, 0.039999999999999994},
                                {0.028571428571428574, -0.014285714285714285,
                                 0.04, 0.02, 0.02, 0.01142857142857142},
                                {0.028571428571428574, 0.028571428571428574,
                                 0.04, 0.04, 0.04, -0.0742857142857143}};
  (void)std::copy(&dv[0][0], (&dv[0][0]) + 150U, &X[0][0]);
}

//
// File trailer for subPixelLocation.cpp
//
// [EOF]
//
