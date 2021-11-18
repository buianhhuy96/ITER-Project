//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: subPixelLocation.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "subPixelLocation.h"
#include "ITER_API_v2_rtwutil.h"
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
  array<bool, 1U> b_x;
  float beta[6];
  int b_i;
  b_i = loc.size(0);
  for (int id{0}; id < b_i; id++) {
    int b_loop_ub;
    int c_loop_ub;
    int k;
    int loop_ub;
    bool exitg1;
    bool guard1{false};
    bool y;
    loop_ub = loc.size(1);
    b_loc.set_size(1, loop_ub);
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_loc[i1] = loc[id + (loc.size(0) * i1)];
    }
    b_loop_ub = loc.size(1);
    b_x.set_size(b_loop_ub);
    for (int i2{0}; i2 < b_loop_ub; i2++) {
      b_x[i2] = (b_loc[i2] < 3.0);
    }
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
      if (b_x[k]) {
        y = true;
        exitg1 = true;
      } else {
        k++;
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
      float b_y;
      float c_x;
      int e_loop_ub;
      int f_loop_ub;
      int i3;
      int i4;
      int i7;
      int i8;
      bool guard2{false};
      if ((loc[id + loc.size(0)] - 2.0) > (loc[id + loc.size(0)] + 2.0)) {
        i3 = 0;
        i4 = 0;
      } else {
        i3 = (static_cast<int>(
                 static_cast<double>(loc[id + loc.size(0)] - 2.0))) -
             1;
        i4 = static_cast<int>(static_cast<double>(loc[id + loc.size(0)] + 2.0));
      }
      if ((loc[id] - 2.0) > (loc[id] + 2.0)) {
        i7 = 0;
        i8 = 0;
      } else {
        i7 = (static_cast<int>(static_cast<double>(loc[id] - 2.0))) - 1;
        i8 = static_cast<int>(static_cast<double>(loc[id] + 2.0));
      }
      e_loop_ub = i4 - i3;
      f_loop_ub = i8 - i7;
      b_metric.set_size(e_loop_ub, f_loop_ub);
      for (int i9{0}; i9 < f_loop_ub; i9++) {
        for (int i11{0}; i11 < e_loop_ub; i11++) {
          b_metric[i11 + (b_metric.size(0) * i9)] =
              metric[(i3 + i11) + (metric.size(0) * (i7 + i9))];
        }
      }
      for (int i10{0}; i10 < 6; i10++) {
        float f;
        f = 0.0F;
        for (int i12{0}; i12 < 25; i12++) {
          f += (static_cast<float>(X[i12][i10])) * b_metric[i12];
        }
        beta[i10] = f;
      }
      float x_tmp;
      x_tmp = ((4.0F * beta[0]) * beta[1]) - rt_powf_snf(beta[4], 2.0F);
      c_x = (-(((2.0F * beta[1]) * beta[2]) - (beta[3] * beta[4]))) / x_tmp;
      b_y = (-(((2.0F * beta[0]) * beta[3]) - (beta[2] * beta[4]))) / x_tmp;
      guard2 = false;
      if ((std::isinf(c_x)) || (std::isnan(c_x))) {
        guard2 = true;
      } else if (std::abs(c_x) > 2.0F) {
        guard2 = true;
      } else if ((std::isinf(b_y)) || (std::isnan(b_y))) {
        guard2 = true;
      } else if (std::abs(b_y) > 2.0F) {
        guard2 = true;
      } else {
        /* no actions */
      }
      if (guard2) {
        c_x = 0.0F;
        b_y = 0.0F;
      }
      subPixelLoc.set_size(1, 2);
      subPixelLoc[0] = (static_cast<float>(b_loc[0])) + c_x;
      subPixelLoc[1] = (static_cast<float>(b_loc[1])) + b_y;
    }
    if (guard1) {
      int d_loop_ub;
      subPixelLoc.set_size(1, b_loc.size(1));
      d_loop_ub = b_loc.size(1);
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        subPixelLoc[i6] = static_cast<float>(b_loc[i6]);
      }
    }
    c_loop_ub = subPixelLoc.size(1);
    for (int i5{0}; i5 < c_loop_ub; i5++) {
      loc[id + (loc.size(0) * i5)] = static_cast<double>(subPixelLoc[i5]);
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
