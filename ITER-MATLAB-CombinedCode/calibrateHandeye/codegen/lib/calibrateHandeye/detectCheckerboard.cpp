//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "calibrateHandeye_rtwutil.h"
#include "cat.h"
#include "conv2AXPYValidCMP.h"
#include "find_peaks.h"
#include "flip.h"
#include "imfilter.h"
#include "isequal.h"
#include "mean.h"
#include "rot90.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double d_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : double d_X[4]
//                double g_Y[4]
//                double height
//                double width
//                ::coder::array<bool, 2U> &mask
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double d_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask)
{
  int b_i;
  int b_loop_ub_tmp;
  int i1;
  int i2;
  int loop_ub;
  int loop_ub_tmp;
  ::coder::internal::d_sort(d_X);
  ::coder::internal::d_sort(g_Y);
  loop_ub_tmp = static_cast<int>(height);
  b_loop_ub_tmp = static_cast<int>(width);
  mask.set_size(loop_ub_tmp, b_loop_ub_tmp);
  for (b_i = 0; b_i < b_loop_ub_tmp; b_i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      mask[i1 + (mask.size(0) * b_i)] = false;
    }
  }
  if (g_Y[1] > g_Y[2]) {
    b_i = 0;
    i1 = 0;
  } else {
    b_i = (static_cast<int>(g_Y[1])) - 1;
    i1 = static_cast<int>(g_Y[2]);
  }
  if (d_X[1] > d_X[2]) {
    loop_ub_tmp = 0;
    i2 = 0;
  } else {
    loop_ub_tmp = (static_cast<int>(d_X[1])) - 1;
    i2 = static_cast<int>(d_X[2]);
  }
  b_loop_ub_tmp = i1 - b_i;
  loop_ub = i2 - loop_ub_tmp;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
      mask[(b_i + i2) + (mask.size(0) * (loop_ub_tmp + i1))] = true;
    }
  }
}

//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float u1)
{
  float y;
  if ((std::isnan(u0)) || (std::isnan(u1))) {
    y = rtNaNF;
  } else if ((std::isinf(u0)) && (std::isinf(u1))) {
    int b_u0;
    int b_u1;
    if (u0 > 0.0F) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (u1 > 0.0F) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }
    y = std::atan2(static_cast<float>(b_u0), static_cast<float>(b_u1));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<float, 2U> &e_I
//                ::coder::array<double, 2U> &b_points
//                double b_boardSize[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<float, 2U> &e_I,
                        ::coder::array<double, 2U> &b_points,
                        double b_boardSize[2])
{
  static const double dv[29]{
      0.00021823147295907269, 0.00050740337669472686, 0.0011082708667872049,
      0.0022740241675853852,  0.0043832963079210854,  0.0079371242384296756,
      0.013501503141458728,   0.021575340587545226,   0.0323884223174645,
      0.04567499638225736,    0.06050953906221062,    0.0753053380745791,
      0.088040859838021152,   0.09669396810002269,    0.099763364132126942,
      0.09669396810002269,    0.088040859838021152,   0.0753053380745791,
      0.06050953906221062,    0.04567499638225736,    0.0323884223174645,
      0.021575340587545226,   0.013501503141458728,   0.0079371242384296756,
      0.0043832963079210854,  0.0022740241675853852,  0.0011082708667872049,
      0.00050740337669472686, 0.00021823147295905031};
  static const double dv1[29]{
      0.00021823147295907278, 0.00050740337669472676, 0.0011082708667872047,
      0.0022740241675853856,  0.0043832963079210854,  0.0079371242384296773,
      0.013501503141458728,   0.02157534058754523,    0.032388422317464506,
      0.045674996382257374,   0.060509539062210613,   0.075305338074579134,
      0.088040859838021152,   0.096693968100022676,   0.099763364132126955,
      0.096693968100022676,   0.088040859838021152,   0.075305338074579134,
      0.060509539062210613,   0.045674996382257374,   0.032388422317464506,
      0.02157534058754523,    0.013501503141458728,   0.0079371242384296773,
      0.0043832963079210854,  0.0022740241675853856,  0.0011082708667872047,
      0.00050740337669473586, 0.00021823147295907272};
  b_Checkerboard lobj_0[6];
  b_Checkerboard *board0;
  b_Checkerboard *board45;
  array<double, 2U> b;
  array<double, 2U> c_a;
  array<double, 1U> s;
  array<float, 2U> I_45;
  array<float, 2U> I_45_x;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> b_a;
  array<float, 2U> b_x;
  array<float, 2U> points0;
  array<float, 2U> r;
  array<float, 1U> c_x;
  array<int, 1U> r1;
  array<int, 1U> r2;
  double finalSize[2];
  double pad[2];
  int b_i;
  int c_i;
  int d_N;
  int k;
  int loop_ub;
  bool guard1{false};
  bool guard2{false};
  finalSize[0] = static_cast<double>(e_I.size(0));
  pad[0] = 14.0;
  finalSize[1] = static_cast<double>(e_I.size(1));
  pad[1] = 14.0;
  if ((e_I.size(0) == 0) || (e_I.size(1) == 0)) {
    Ig.set_size(e_I.size(0), e_I.size(1));
    loop_ub = e_I.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = e_I.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ig[c_i + (Ig.size(0) * b_i)] = e_I[c_i + (e_I.size(0) * b_i)];
      }
    }
  } else {
    padImage_outSize(e_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    b_conv2_separable_valid(dv, dv1, c_a, finalSize, b);
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ig[c_i + (Ig.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    Iy.set_size(Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = Ig.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Iy[c_i + (Iy.size(0) * b_i)] = Ig[c_i + (Ig.size(0) * b_i)];
      }
    }
  } else {
    padImage_outSize(Ig, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Iy.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Iy[c_i + (Iy.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  imfilter(Ig);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    Ixy.set_size(Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = Ig.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ixy[c_i + (Ixy.size(0) * b_i)] = Ig[c_i + (Ig.size(0) * b_i)];
      }
    }
  } else {
    padImage_outSize(Ig, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ixy[c_i + (Ixy.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  b_x.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = Ig.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      b_x[c_i + (b_x.size(0) * b_i)] =
          Ig[c_i + (Ig.size(0) * b_i)] * 0.707106769F;
    }
  }
  I_45.set_size(b_x.size(0), b_x.size(1));
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = b_x.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      I_45[c_i + (I_45.size(0) * b_i)] =
          b_x[c_i + (b_x.size(0) * b_i)] +
          (Iy[c_i + (Iy.size(0) * b_i)] * 0.707106769F);
    }
  }
  I_45_x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = I_45.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      I_45_x[c_i + (I_45_x.size(0) * b_i)] = I_45[c_i + (I_45.size(0) * b_i)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((I_45.size(0) == 0) || (I_45.size(1) == 0)) {
    b_a.set_size(I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = I_45.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        b_a[c_i + (b_a.size(0) * b_i)] = I_45[c_i + (I_45.size(0) * b_i)];
      }
    }
  } else {
    padImage_outSize(I_45, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::conv2AXPYValidCMP(c_a, b);
    b_a.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        b_a[c_i + (b_a.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  loop_ub = I_45_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = I_45_x.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      I_45_x[c_i + (I_45_x.size(0) * b_i)] =
          (I_45_x[c_i + (I_45_x.size(0) * b_i)] * 0.707106769F) +
          (b_a[c_i + (b_a.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = I_45.size(1);
  r.set_size(I_45.size(0), I_45.size(1));
  if ((I_45.size(0) != 0) && (I_45.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = r.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        r[loop_ub + (r.size(0) * k)] =
            std::abs(I_45[loop_ub + (I_45.size(0) * k)]);
      }
    }
  }
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = b_x.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      b_x[c_i + (b_x.size(0) * b_i)] =
          b_x[c_i + (b_x.size(0) * b_i)] +
          (Iy[c_i + (Iy.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = b_x.size(1);
  b_a.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = b_a.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        b_a[loop_ub + (b_a.size(0) * k)] =
            std::abs(b_x[loop_ub + (b_x.size(0) * k)]);
      }
    }
  }
  b_i = Ixy.size(1);
  I_45.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = I_45.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        I_45[loop_ub + (I_45.size(0) * k)] =
            std::abs(Ixy[loop_ub + (Ixy.size(0) * k)]);
      }
    }
  }
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = I_45.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      I_45[c_i + (I_45.size(0) * b_i)] =
          16.0F * I_45[c_i + (I_45.size(0) * b_i)];
    }
  }
  loop_ub = r.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = r.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      r[c_i + (r.size(0) * b_i)] =
          6.0F * (r[c_i + (r.size(0) * b_i)] + b_a[c_i + (b_a.size(0) * b_i)]);
    }
  }
  b_x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = I_45.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      b_x[c_i + (b_x.size(0) * b_i)] =
          I_45[c_i + (I_45.size(0) * b_i)] - r[c_i + (r.size(0) * b_i)];
    }
  }
  loop_ub = (I_45.size(0) * I_45.size(1)) - 1;
  d_N = 0;
  for (c_i = 0; c_i <= loop_ub; c_i++) {
    if ((I_45[c_i] - r[c_i]) < 0.0F) {
      d_N++;
    }
  }
  r1.set_size(d_N);
  d_N = 0;
  for (c_i = 0; c_i <= loop_ub; c_i++) {
    if ((I_45[c_i] - r[c_i]) < 0.0F) {
      r1[d_N] = c_i + 1;
      d_N++;
    }
  }
  loop_ub = r1.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_x[r1[b_i] - 1] = 0.0F;
  }
  b_i = Ig.size(1);
  r.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = r.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        r[loop_ub + (r.size(0) * k)] = std::abs(Ig[loop_ub + (Ig.size(0) * k)]);
      }
    }
  }
  b_i = Iy.size(1);
  b_a.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = b_a.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        b_a[loop_ub + (b_a.size(0) * k)] =
            std::abs(Iy[loop_ub + (Iy.size(0) * k)]);
      }
    }
  }
  b_i = I_45_x.size(1);
  I_45.set_size(I_45_x.size(0), I_45_x.size(1));
  if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
    for (k = 0; k < b_i; k++) {
      c_i = I_45.size(0);
      for (loop_ub = 0; loop_ub < c_i; loop_ub++) {
        I_45[loop_ub + (I_45.size(0) * k)] =
            std::abs(I_45_x[loop_ub + (I_45_x.size(0) * k)]);
      }
    }
  }
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = I_45.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      I_45[c_i + (I_45.size(0) * b_i)] =
          (16.0F * I_45[c_i + (I_45.size(0) * b_i)]) -
          (6.0F *
           (r[c_i + (r.size(0) * b_i)] + b_a[c_i + (b_a.size(0) * b_i)]));
    }
  }
  loop_ub = (I_45.size(0) * I_45.size(1)) - 1;
  d_N = 0;
  for (c_i = 0; c_i <= loop_ub; c_i++) {
    if (I_45[c_i] < 0.0F) {
      d_N++;
    }
  }
  r2.set_size(d_N);
  d_N = 0;
  for (c_i = 0; c_i <= loop_ub; c_i++) {
    if (I_45[c_i] < 0.0F) {
      r2[d_N] = c_i + 1;
      d_N++;
    }
  }
  loop_ub = r2.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    I_45[r2[b_i] - 1] = 0.0F;
  }
  b_i = Ig.size(1);
  Ix2.set_size(Ig.size(0), Ig.size(1));
  for (k = 0; k < b_i; k++) {
    d_N = Ix2.size(0);
    for (loop_ub = 0; loop_ub < d_N; loop_ub++) {
      Ix2[loop_ub + (Ix2.size(0) * k)] =
          rt_powf_snf(Ig[loop_ub + (Ig.size(0) * k)], 2.0F);
    }
  }
  b_i = Iy.size(1);
  Iy2.set_size(Iy.size(0), Iy.size(1));
  for (k = 0; k < b_i; k++) {
    d_N = Iy2.size(0);
    for (loop_ub = 0; loop_ub < d_N; loop_ub++) {
      Iy2[loop_ub + (Iy2.size(0) * k)] =
          rt_powf_snf(Iy[loop_ub + (Iy.size(0) * k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
    padImage_outSize(Ix2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ix2[c_i + (Ix2.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    padImage_outSize(Iy2, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Iy2[c_i + (Iy2.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = Ig.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      Ig[c_i + (Ig.size(0) * b_i)] =
          Ig[c_i + (Ig.size(0) * b_i)] * Iy[c_i + (Iy.size(0) * b_i)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    padImage_outSize(Ig, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    ::coder::internal::c_conv2AXPYValidCMP(c_a, b);
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ig[c_i + (Ig.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
  find_peaks(b_x, points0);
  d_N = b_x.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[b_i + points0.size(0)])) +
                         (d_N * ((static_cast<int>(points0[b_i])) - 1))));
  }
  c_x.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_x[b_i] = b_x[(static_cast<int>(s[b_i])) - 1];
  }
  board0 = growCheckerboard(points0, c_x, Ix2, Iy2, Ig, 0.0, &lobj_0[0]);
  b_points.set_size(0, 0);
  b_boardSize[0] = 0.0;
  b_boardSize[1] = 0.0;
  find_peaks(I_45, points0);
  d_N = I_45.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[b_i + points0.size(0)])) +
                         (d_N * ((static_cast<int>(points0[b_i])) - 1))));
  }
  c_x.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_x[b_i] = I_45[(static_cast<int>(s[b_i])) - 1];
  }
  board45 = growCheckerboard(points0, c_x, Ix2, Iy2, Ig, 0.78539816339744828,
                             &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      finalSize[0] = static_cast<double>(board0->BoardIdx.size(0));
      finalSize[1] = static_cast<double>(board0->BoardIdx.size(1));
      pad[0] = static_cast<double>(board45->BoardIdx.size(0));
      pad[1] = static_cast<double>(board45->BoardIdx.size(1));
      if (isequal(finalSize, pad)) {
        d_N = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(d_N);
        for (b_i = 0; b_i < d_N; b_i++) {
          s[b_i] = board0->BoardIdx[b_i];
        }
        c_i = 0;
        b_i = s.size(0);
        for (k = 0; k < b_i; k++) {
          if (s[k] != 0.0) {
            c_i++;
          }
        }
        d_N = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(d_N);
        for (b_i = 0; b_i < d_N; b_i++) {
          s[b_i] = board45->BoardIdx[b_i];
        }
        loop_ub = 0;
        b_i = s.size(0);
        for (k = 0; k < b_i; k++) {
          if (s[k] != 0.0) {
            loop_ub++;
          }
        }
        if (c_i > loop_ub) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }
  if (guard2) {
    board0 = orient(board0, e_I);
    toPoints(board0, b_points, b_boardSize);
    subPixelLocation(Ixy, b_points);
  }
  if (guard1 && (board45->isValid)) {
    board45 = orient(board45, e_I);
    toPoints(board45, b_points, b_boardSize);
    subPixelLocation(I_45_x, b_points);
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &b_points
//                const ::coder::array<float, 1U> &scores
//                const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                double theta
//                b_Checkerboard *b_iobj_0
// Return Type  : b_Checkerboard *
//
b_Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                 const ::coder::array<float, 1U> &scores,
                                 const ::coder::array<float, 2U> &Ix2,
                                 const ::coder::array<float, 2U> &Iy2,
                                 const ::coder::array<float, 2U> &Ixy,
                                 double theta, b_Checkerboard *b_iobj_0)
{
  static const float fv[2][2]{{0.707106769F, 0.707106769F},
                              {-0.707106769F, 0.707106769F}};
  b_Checkerboard *board;
  b_Checkerboard *currentBoard;
  b_Checkerboard *tmpBoard;
  array<double, 2U> b_seedIdx;
  array<double, 2U> seedIdx;
  array<float, 1U> b_x;
  array<int, 1U> iidx;
  float c_x[2];
  float v2[2];
  if (scores.size(0) == 0) {
    int b_i;
    b_iobj_0[0].isValid = false;
    b_iobj_0[0].Energy = rtInfF;
    b_iobj_0[0].IsDistortionHigh = false;
    board = &b_iobj_0[0];
    b_iobj_0[0].BoardIdx.set_size(1, 1);
    b_iobj_0[0].BoardIdx[0] = 0.0;
    b_iobj_0[0].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[0].BoardIdx[b_iobj_0[0].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[0].BoardIdx[(b_iobj_0[0].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[0].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[0].BoardCoords[0] = 0.0;
    b_iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (int i1{0}; i1 < 3; i1++) {
        b_iobj_0[0].BoardCoords[(b_iobj_0[0].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[0].BoardCoords.size(0) *
                                  b_iobj_0[0].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[0].BoardCoords[((b_iobj_0[0].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[0].BoardCoords.size(0) *
                                   b_iobj_0[0].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[0].Points.set_size(1, 1);
    b_iobj_0[0].Points[0] = 0.0F;
    b_iobj_0[0].Points.set_size(0, 2);
  } else {
    int b_i;
    int i1;
    int loop_ub;
    if (b_points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      seedIdx.set_size(1, b_points.size(0));
      loop_ub = b_points.size(0) - 1;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
      }
    }
    b_x.set_size(seedIdx.size(1));
    loop_ub = seedIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_x[b_i] = scores[(static_cast<int>(seedIdx[b_i])) - 1];
    }
    ::coder::internal::sort(b_x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    loop_ub = iidx.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_seedIdx[b_i] = static_cast<double>(
          static_cast<unsigned int>(seedIdx[iidx[b_i] - 1]));
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    loop_ub = b_seedIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      seedIdx[b_i] = b_seedIdx[b_i];
    }
    if (iidx.size(0) > 2000) {
      b_i = static_cast<int>(std::fmin(
          2000.0, std::round((static_cast<double>(seedIdx.size(1))) / 2.0)));
      if (1 > b_i) {
        loop_ub = 0;
      } else {
        loop_ub = b_i;
      }
      b_seedIdx.set_size(1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_seedIdx[b_i] =
            static_cast<double>(static_cast<unsigned int>(seedIdx[b_i]));
      }
      seedIdx.set_size(1, b_seedIdx.size(1));
      loop_ub = b_seedIdx.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        seedIdx[b_i] = b_seedIdx[b_i];
      }
    }
    b_iobj_0[1].isValid = false;
    b_iobj_0[1].Energy = rtInfF;
    b_iobj_0[1].IsDistortionHigh = false;
    board = &b_iobj_0[1];
    b_iobj_0[1].BoardIdx.set_size(1, 1);
    b_iobj_0[1].BoardIdx[0] = 0.0;
    b_iobj_0[1].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[1].BoardIdx[b_iobj_0[1].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[1].BoardIdx[(b_iobj_0[1].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[1].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[1].BoardCoords[0] = 0.0;
    b_iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_iobj_0[1].BoardCoords[(b_iobj_0[1].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[1].BoardCoords.size(0) *
                                  b_iobj_0[1].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[1].BoardCoords[((b_iobj_0[1].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[1].BoardCoords.size(0) *
                                   b_iobj_0[1].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[1].Points.set_size(1, 1);
    b_iobj_0[1].Points[0] = 0.0F;
    b_iobj_0[1].Points.set_size(0, 2);
    b_iobj_0[1].IsDistortionHigh = false;
    b_iobj_0[2].isValid = false;
    b_iobj_0[2].Energy = rtInfF;
    b_iobj_0[2].IsDistortionHigh = false;
    currentBoard = &b_iobj_0[2];
    b_iobj_0[2].BoardIdx.set_size(1, 1);
    b_iobj_0[2].BoardIdx[0] = 0.0;
    b_iobj_0[2].BoardIdx.set_size(3, 3);
    for (b_i = 0; b_i < 3; b_i++) {
      b_iobj_0[2].BoardIdx[b_iobj_0[2].BoardIdx.size(0) * b_i] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * b_i) + 1] = 0.0;
      b_iobj_0[2].BoardIdx[(b_iobj_0[2].BoardIdx.size(0) * b_i) + 2] = 0.0;
    }
    b_iobj_0[2].BoardCoords.set_size(1, 1, 1);
    b_iobj_0[2].BoardCoords[0] = 0.0;
    b_iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < 3; i1++) {
        b_iobj_0[2].BoardCoords[(b_iobj_0[2].BoardCoords.size(0) * i1) +
                                ((b_iobj_0[2].BoardCoords.size(0) *
                                  b_iobj_0[2].BoardCoords.size(1)) *
                                 b_i)] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  b_i)) +
                                1] = 0.0;
        b_iobj_0[2].BoardCoords[((b_iobj_0[2].BoardCoords.size(0) * i1) +
                                 ((b_iobj_0[2].BoardCoords.size(0) *
                                   b_iobj_0[2].BoardCoords.size(1)) *
                                  b_i)) +
                                2] = 0.0;
      }
    }
    b_iobj_0[2].Points.set_size(1, 1);
    b_iobj_0[2].Points[0] = 0.0F;
    b_iobj_0[2].Points.set_size(0, 2);
    b_iobj_0[2].IsDistortionHigh = false;
    b_i = seedIdx.size(1);
    for (int c_i{0}; c_i < b_i; c_i++) {
      double d;
      float ab;
      float adf;
      float b;
      float b_a;
      float c;
      float df;
      float tb;
      int sgn2;
      bool guard1{false};
      d = seedIdx[c_i];
      c_x[0] = std::round(
          b_points[(static_cast<int>(static_cast<unsigned int>(d))) - 1]);
      c_x[1] = std::round(
          b_points[((static_cast<int>(static_cast<unsigned int>(d))) +
                    b_points.size(0)) -
                   1]);
      b_a = Ix2[((static_cast<int>(c_x[1])) +
                 (Ix2.size(0) * ((static_cast<int>(c_x[0])) - 1))) -
                1];
      b = Ixy[((static_cast<int>(c_x[1])) +
               (Ixy.size(0) * ((static_cast<int>(c_x[0])) - 1))) -
              1];
      c = Iy2[((static_cast<int>(c_x[1])) +
               (Iy2.size(0) * ((static_cast<int>(c_x[0])) - 1))) -
              1];
      df = b_a - c;
      adf = std::abs(df);
      tb = b + b;
      ab = std::abs(tb);
      if (adf > ab) {
        b = adf * std::sqrt(rt_powf_snf(ab / adf, 2.0F) + 1.0F);
      } else if (adf < ab) {
        b = ab * std::sqrt(rt_powf_snf(adf / ab, 2.0F) + 1.0F);
      } else {
        b = ab * 1.41421354F;
      }
      if (df > 0.0F) {
        adf = df + b;
        sgn2 = 1;
      } else {
        adf = df - b;
        sgn2 = -1;
      }
      if (std::abs(adf) > ab) {
        b = (-tb) / adf;
        tb = 1.0F / std::sqrt((b * b) + 1.0F);
        df = b * tb;
      } else if (ab == 0.0F) {
        df = 1.0F;
        tb = 0.0F;
      } else {
        b = (-adf) / tb;
        df = 1.0F / std::sqrt((b * b) + 1.0F);
        tb = b * df;
      }
      if ((b_a + c) < 0.0F) {
        loop_ub = -1;
      } else {
        loop_ub = 1;
      }
      if (loop_ub == sgn2) {
        b = df;
        df = -tb;
        tb = b;
      }
      for (i1 = 0; i1 < 2; i1++) {
        b = fv[i1][0];
        adf = fv[i1][1];
        c_x[i1] = ((-tb) * b) + (df * adf);
        v2[i1] = (df * b) + (tb * adf);
      }
      guard1 = false;
      if ((static_cast<double>(std::abs(
              std::abs(std::abs(rt_atan2f_snf(c_x[1], c_x[0])) - 3.14159274F) -
              (static_cast<float>(theta))))) > 0.58904862254808621) {
        if (!((static_cast<double>(std::abs(
                  std::abs(std::abs(rt_atan2f_snf(v2[1], v2[0])) -
                           3.14159274F) -
                  (static_cast<float>(theta))))) > 0.58904862254808621)) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        currentBoard->initialize(
            static_cast<double>(static_cast<unsigned int>(d)), b_points, c_x,
            v2);
        if (currentBoard->isValid) {
          bool hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            int m_i;
            currentBoard->PreviousEnergy = currentBoard->Energy;
            m_i = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (m_i < 4) {
                if (!currentBoard->IsDirectionBad[m_i]) {
                  currentBoard->LastExpandDirection =
                      (static_cast<double>(m_i)) + 1.0;
                  currentBoard->expandBoardDirectionally(
                      (static_cast<double>(m_i)) + 1.0);
                  if (currentBoard->Energy < currentBoard->PreviousEnergy) {
                    exitg1 = 1;
                  } else {
                    currentBoard->Energy = currentBoard->PreviousEnergy;
                    switch (
                        static_cast<int>(currentBoard->LastExpandDirection)) {
                    case 1: {
                      int b_currentBoard;
                      int c_currentBoard;
                      int i2;
                      int i3;
                      int i4;
                      i1 = currentBoard->BoardIdx.size(0);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (i3 = 0; i3 <= b_currentBoard; i3++) {
                        sgn2 = i1 - i2;
                        for (i4 = 0; i4 < sgn2; i4++) {
                          currentBoard->BoardIdx[i4 + (sgn2 * i3)] =
                              currentBoard
                                  ->BoardIdx[((i2 + i4) +
                                              (currentBoard->BoardIdx.size(0) *
                                               i3)) +
                                             1];
                        }
                      }
                      currentBoard->BoardIdx.set_size(i1 - i2,
                                                      b_currentBoard + 1);
                      i1 = currentBoard->BoardCoords.size(0);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      loop_ub = b_currentBoard + 1;
                      for (i3 = 0; i3 <= c_currentBoard; i3++) {
                        for (i4 = 0; i4 < loop_ub; i4++) {
                          sgn2 = i1 - i2;
                          for (int i5{0}; i5 < sgn2; i5++) {
                            currentBoard
                                ->BoardCoords[(i5 + (sgn2 * i4)) +
                                              ((sgn2 * (b_currentBoard + 1)) *
                                               i3)] =
                                currentBoard->BoardCoords
                                    [(((i2 + i5) +
                                       (currentBoard->BoardCoords.size(0) *
                                        i4)) +
                                      ((currentBoard->BoardCoords.size(0) *
                                        currentBoard->BoardCoords.size(1)) *
                                       i3)) +
                                     1];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          i1 - i2, b_currentBoard + 1, c_currentBoard + 1);
                    } break;
                    case 2: {
                      int b_currentBoard;
                      int c_currentBoard;
                      int i2;
                      i1 = currentBoard->BoardIdx.size(0) - 2;
                      if (1 > (i1 + 1)) {
                        loop_ub = 0;
                      } else {
                        loop_ub = i1 + 1;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(1) - 1;
                      for (i1 = 0; i1 <= b_currentBoard; i1++) {
                        for (i2 = 0; i2 < loop_ub; i2++) {
                          currentBoard->BoardIdx[i2 + (loop_ub * i1)] =
                              currentBoard->BoardIdx
                                  [i2 + (currentBoard->BoardIdx.size(0) * i1)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(loop_ub,
                                                      b_currentBoard + 1);
                      i1 = currentBoard->BoardCoords.size(0) - 2;
                      if (1 > (i1 + 1)) {
                        loop_ub = 0;
                      } else {
                        loop_ub = i1 + 1;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(1) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 <= c_currentBoard; i1++) {
                        for (i2 = 0; i2 < sgn2; i2++) {
                          for (int i3{0}; i3 < loop_ub; i3++) {
                            currentBoard->BoardCoords
                                [(i3 + (loop_ub * i2)) +
                                 ((loop_ub * (b_currentBoard + 1)) * i1)] =
                                currentBoard->BoardCoords
                                    [(i3 + (currentBoard->BoardCoords.size(0) *
                                            i2)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i1)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          loop_ub, b_currentBoard + 1, c_currentBoard + 1);
                    } break;
                    case 3: {
                      int b_currentBoard;
                      int c_currentBoard;
                      int i2;
                      int i3;
                      i1 = currentBoard->BoardIdx.size(1);
                      if (2 > i1) {
                        i2 = 0;
                        i1 = 0;
                      } else {
                        i2 = 1;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      loop_ub = b_currentBoard + 1;
                      sgn2 = i1 - i2;
                      for (i1 = 0; i1 < sgn2; i1++) {
                        for (i3 = 0; i3 < loop_ub; i3++) {
                          currentBoard
                              ->BoardIdx[i3 + ((b_currentBoard + 1) * i1)] =
                              currentBoard
                                  ->BoardIdx[i3 +
                                             (currentBoard->BoardIdx.size(0) *
                                              (i2 + i1))];
                        }
                      }
                      currentBoard->BoardIdx.set_size(b_currentBoard + 1, sgn2);
                      i1 = currentBoard->BoardCoords.size(1);
                      if (2 > i1) {
                        i2 = -1;
                        i1 = -1;
                      } else {
                        i2 = 0;
                        i1--;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      loop_ub = b_currentBoard + 1;
                      for (i3 = 0; i3 <= c_currentBoard; i3++) {
                        sgn2 = i1 - i2;
                        for (int i4{0}; i4 < sgn2; i4++) {
                          for (int i5{0}; i5 < loop_ub; i5++) {
                            currentBoard->BoardCoords
                                [(i5 + ((b_currentBoard + 1) * i4)) +
                                 (((b_currentBoard + 1) * sgn2) * i3)] =
                                currentBoard->BoardCoords
                                    [(i5 + (currentBoard->BoardCoords.size(0) *
                                            ((i2 + i4) + 1))) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i3)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          b_currentBoard + 1, i1 - i2, c_currentBoard + 1);
                    } break;
                    case 4: {
                      int b_currentBoard;
                      int c_currentBoard;
                      int i2;
                      i1 = currentBoard->BoardIdx.size(1) - 2;
                      if (1 > (i1 + 1)) {
                        loop_ub = -1;
                      } else {
                        loop_ub = i1;
                      }
                      b_currentBoard = currentBoard->BoardIdx.size(0) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 <= loop_ub; i1++) {
                        for (i2 = 0; i2 < sgn2; i2++) {
                          currentBoard
                              ->BoardIdx[i2 + ((b_currentBoard + 1) * i1)] =
                              currentBoard->BoardIdx
                                  [i2 + (currentBoard->BoardIdx.size(0) * i1)];
                        }
                      }
                      currentBoard->BoardIdx.set_size(b_currentBoard + 1,
                                                      loop_ub + 1);
                      i1 = currentBoard->BoardCoords.size(1) - 2;
                      if (1 > (i1 + 1)) {
                        loop_ub = 0;
                      } else {
                        loop_ub = i1 + 1;
                      }
                      b_currentBoard = currentBoard->BoardCoords.size(0) - 1;
                      c_currentBoard = currentBoard->BoardCoords.size(2) - 1;
                      sgn2 = b_currentBoard + 1;
                      for (i1 = 0; i1 <= c_currentBoard; i1++) {
                        for (i2 = 0; i2 < loop_ub; i2++) {
                          for (int i3{0}; i3 < sgn2; i3++) {
                            currentBoard->BoardCoords
                                [(i3 + ((b_currentBoard + 1) * i2)) +
                                 (((b_currentBoard + 1) * loop_ub) * i1)] =
                                currentBoard->BoardCoords
                                    [(i3 + (currentBoard->BoardCoords.size(0) *
                                            i2)) +
                                     ((currentBoard->BoardCoords.size(0) *
                                       currentBoard->BoardCoords.size(1)) *
                                      i1)];
                          }
                        }
                      }
                      currentBoard->BoardCoords.set_size(
                          b_currentBoard + 1, loop_ub, c_currentBoard + 1);
                    } break;
                    default:
                      /* no actions */
                      break;
                    }
                    currentBoard->IsDirectionBad[m_i] = true;
                    m_i++;
                  }
                } else {
                  m_i++;
                }
              } else {
                hasExpanded = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (currentBoard->Energy < board->Energy) {
          tmpBoard = board;
          board = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
  }
  return board;
}

//
// Arguments    : b_Checkerboard *board
//                const ::coder::array<float, 2U> &e_I
// Return Type  : b_Checkerboard *
//
b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<float, 2U> &e_I)
{
  b_Checkerboard *b_board;
  array<double, 3U> r1;
  array<double, 3U> r4;
  array<double, 3U> r5;
  array<double, 2U> newBoardCoords1;
  array<double, 2U> newBoardCoords2;
  array<double, 2U> numRot;
  array<double, 2U> r;
  array<float, 1U> g_I;
  array<float, 1U> o_I;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<signed char, 2U> c_ii;
  array<bool, 3U> c_x;
  array<bool, 2U> nextSquareMask;
  array<bool, 2U> upperLeftMask;
  array<bool, 2U> y;
  double cornerIdx[4];
  double upperLeftPolyY[4];
  float b_x;
  b_board = board;
  b_x = b_board->Energy;
  if (!std::isinf(b_x)) {
    int b_i;
    int b_loop_ub;
    int i1;
    int loop_ub;
    int outsize_idx_1;
    bool b_y;
    bool exitg1;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                               b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(1) - 1;
      for (b_i = 0; b_i <= loop_ub; b_i++) {
        b_loop_ub = b_board->BoardIdx.size(0) - 1;
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
              b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
        }
      }
      rot90(newBoardCoords2, b_board->BoardIdx);
      loop_ub = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
              b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * b_i)];
        }
      }
      rot90(newBoardCoords2, newBoardCoords1);
      loop_ub = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
              b_board->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * b_i)) +
                                   (b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1))];
        }
      }
      rot90(newBoardCoords2, r);
      cat(newBoardCoords1, r, r1);
      b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
      loop_ub = r1.size(1);
      for (b_i = 0; b_i < 2; b_i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = r1.size(0);
          for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub; outsize_idx_1++) {
            b_board->BoardCoords[(outsize_idx_1 +
                                  (b_board->BoardCoords.size(0) * i1)) +
                                 ((b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)) *
                                  b_i)] =
                r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                   ((r1.size(0) * r1.size(1)) * b_i)];
          }
        }
      }
    }
    newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                             b_board->BoardIdx.size(1));
    loop_ub = b_board->BoardIdx.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b_board->BoardIdx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        newBoardCoords1[i1 + (newBoardCoords1.size(0) * b_i)] =
            b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
      }
    }
    outsize_idx_1 = newBoardCoords1.size(1);
    y.set_size(1, newBoardCoords1.size(1));
    for (b_i = 0; b_i < outsize_idx_1; b_i++) {
      y[b_i] = false;
    }
    outsize_idx_1 = newBoardCoords1.size(1);
    for (loop_ub = 0; loop_ub < outsize_idx_1; loop_ub++) {
      y[loop_ub] = true;
      b_loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub <= (newBoardCoords1.size(0) - 1))) {
        if (newBoardCoords1[b_loop_ub + (newBoardCoords1.size(0) * loop_ub)] ==
            0.0) {
          y[loop_ub] = false;
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
    }
    b_y = (y.size(1) != 0);
    if (b_y) {
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (y.size(1) - 1))) {
        if (!y[loop_ub]) {
          b_y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (b_y) {
      cornerIdx[0] = b_board->BoardCoords[0];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[2] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      cornerIdx[3] = b_board->BoardCoords[1];
      upperLeftPolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                               b_board->BoardCoords.size(1)];
      upperLeftPolyY[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                               (b_board->BoardCoords.size(0) *
                                                b_board->BoardCoords.size(1))];
      upperLeftPolyY[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      upperLeftPolyY[3] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                                b_board->BoardCoords.size(1)) +
                                               1];
      poly2RectMask(cornerIdx, upperLeftPolyY, static_cast<double>(e_I.size(0)),
                    static_cast<double>(e_I.size(1)), upperLeftMask);
      cornerIdx[0] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) * 2];
      cornerIdx[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) + 1];
      cornerIdx[3] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      upperLeftPolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                               (b_board->BoardCoords.size(0) *
                                                b_board->BoardCoords.size(1))];
      upperLeftPolyY[1] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) +
                               (b_board->BoardCoords.size(0) *
                                b_board->BoardCoords.size(1))];
      upperLeftPolyY[2] =
          b_board->BoardCoords[((b_board->BoardCoords.size(0) * 2) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      upperLeftPolyY[3] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      poly2RectMask(cornerIdx, upperLeftPolyY, static_cast<double>(e_I.size(0)),
                    static_cast<double>(e_I.size(1)), nextSquareMask);
      b_loop_ub = (upperLeftMask.size(0) * upperLeftMask.size(1)) - 1;
      outsize_idx_1 = 0;
      for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
        if (upperLeftMask[loop_ub]) {
          outsize_idx_1++;
        }
      }
      r2.set_size(outsize_idx_1);
      outsize_idx_1 = 0;
      for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
        if (upperLeftMask[loop_ub]) {
          r2[outsize_idx_1] = loop_ub + 1;
          outsize_idx_1++;
        }
      }
      b_loop_ub = (nextSquareMask.size(0) * nextSquareMask.size(1)) - 1;
      outsize_idx_1 = 0;
      for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
        if (nextSquareMask[loop_ub]) {
          outsize_idx_1++;
        }
      }
      r3.set_size(outsize_idx_1);
      outsize_idx_1 = 0;
      for (loop_ub = 0; loop_ub <= b_loop_ub; loop_ub++) {
        if (nextSquareMask[loop_ub]) {
          r3[outsize_idx_1] = loop_ub + 1;
          outsize_idx_1++;
        }
      }
      g_I.set_size(r2.size(0));
      loop_ub = r2.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        g_I[b_i] = e_I[r2[b_i] - 1];
      }
      o_I.set_size(r3.size(0));
      loop_ub = r3.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        o_I[b_i] = e_I[r3[b_i] - 1];
      }
      if (!(b_mean(g_I) < b_mean(o_I))) {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          b_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (i1 = 0; i1 <= b_loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
          }
        }
        b_rot90(newBoardCoords2, b_board->BoardIdx);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * b_i)];
          }
        }
        b_rot90(newBoardCoords2, newBoardCoords1);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * b_i)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(newBoardCoords2, r);
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (b_i = 0; b_i < 2; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.size(0);
            for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                 outsize_idx_1++) {
              b_board->BoardCoords[(outsize_idx_1 +
                                    (b_board->BoardCoords.size(0) * i1)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    b_i)] =
                  r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                     ((r1.size(0) * r1.size(1)) * b_i)];
            }
          }
        }
      }
    } else {
      cornerIdx[0] = b_board->BoardIdx[0];
      cornerIdx[1] = b_board->BoardIdx[b_board->BoardIdx.size(0) - 1];
      cornerIdx[2] = b_board->BoardIdx[(b_board->BoardIdx.size(0) +
                                        (b_board->BoardIdx.size(0) *
                                         (b_board->BoardIdx.size(1) - 1))) -
                                       1];
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) *
                                       (b_board->BoardIdx.size(1) - 1)];
      outsize_idx_1 = 0;
      c_ii.set_size(1, 1);
      b_loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub < 4)) {
        if (cornerIdx[b_loop_ub] != 0.0) {
          outsize_idx_1 = 1;
          c_ii[0] = static_cast<signed char>(b_loop_ub + 1);
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (outsize_idx_1 == 0) {
        c_ii.set_size(1, 0);
      }
      numRot.set_size(1, c_ii.size(1));
      loop_ub = c_ii.size(1);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        numRot[0] = (static_cast<double>(c_ii[0])) - 1.0;
      }
      if (c_ii.size(1) == 0) {
        numRot.set_size(1, 1);
        numRot[0] = 0.0;
      }
      y.set_size(1, 1);
      y[0] = (numRot[0] == 2.0);
      if (!y[0]) {
        if (c_isequal(numRot, 1.0)) {
          outsize_idx_1 = 1;
        } else if (c_isequal(numRot, 3.0)) {
          outsize_idx_1 = 2;
        } else {
          outsize_idx_1 = 0;
        }
        if (outsize_idx_1 != 0) {
          newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            b_loop_ub = b_board->BoardIdx.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              newBoardCoords1[i1 + (newBoardCoords1.size(0) * b_i)] =
                  b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(outsize_idx_1));
          b_board->BoardIdx.set_size(newBoardCoords1.size(0),
                                     newBoardCoords1.size(1));
          loop_ub = newBoardCoords1.size(1);
          for (b_i = 0; b_i < loop_ub; b_i++) {
            b_loop_ub = newBoardCoords1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)] =
                  newBoardCoords1[i1 + (newBoardCoords1.size(0) * b_i)];
            }
          }
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(loop_ub, b_loop_ub);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords1[i1 + (newBoardCoords1.size(0) * b_i)] =
                  b_board
                      ->BoardCoords[i1 + (b_board->BoardCoords.size(0) * b_i)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(outsize_idx_1));
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardCoords[(i1 +
                                        (b_board->BoardCoords.size(0) * b_i)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          flip(newBoardCoords2, static_cast<double>(outsize_idx_1));
          cat(newBoardCoords1, newBoardCoords2, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (b_i = 0; b_i < 2; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = r1.size(0);
              for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                   outsize_idx_1++) {
                b_board->BoardCoords[(outsize_idx_1 +
                                      (b_board->BoardCoords.size(0) * i1)) +
                                     ((b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)) *
                                      b_i)] =
                    r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                       ((r1.size(0) * r1.size(1)) * b_i)];
              }
            }
          }
        }
      } else {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (b_i = 0; b_i <= loop_ub; b_i++) {
          b_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (i1 = 0; i1 <= b_loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
          }
        }
        b_rot90(newBoardCoords2, b_board->BoardIdx);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * b_i)];
          }
        }
        b_rot90(newBoardCoords2, newBoardCoords1);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                b_board
                    ->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * b_i)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(newBoardCoords2, r);
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (b_i = 0; b_i < 2; b_i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.size(0);
            for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                 outsize_idx_1++) {
              b_board->BoardCoords[(outsize_idx_1 +
                                    (b_board->BoardCoords.size(0) * i1)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    b_i)] =
                  r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                     ((r1.size(0) * r1.size(1)) * b_i)];
            }
          }
        }
      }
    }
    outsize_idx_1 = b_board->BoardCoords.size(0);
    if (outsize_idx_1 == 0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub =
          static_cast<int>(std::fmod(static_cast<double>(outsize_idx_1), 2.0));
      if (b_loop_ub == 0) {
        b_loop_ub = 0;
      } else if (outsize_idx_1 < 0) {
        b_loop_ub += 2;
      } else {
        /* no actions */
      }
    }
    outsize_idx_1 = b_board->BoardCoords.size(1);
    if (outsize_idx_1 == 0) {
      loop_ub = 0;
    } else {
      loop_ub =
          static_cast<int>(std::fmod(static_cast<double>(outsize_idx_1), 2.0));
      if (loop_ub == 0) {
        loop_ub = 0;
      } else if (outsize_idx_1 < 0) {
        loop_ub += 2;
      } else {
        /* no actions */
      }
    }
    if ((b_loop_ub == 0) == (loop_ub == 0)) {
      loop_ub = b_board->BoardCoords.size(2);
      r4.set_size(1, 1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r4[b_i] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1)) *
                                       b_i];
      }
      outsize_idx_1 = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      loop_ub = b_board->BoardCoords.size(2);
      r5.set_size(1, 1, loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        r5[b_i] =
            b_board
                ->BoardCoords[((outsize_idx_1 + (b_board->BoardCoords.size(0) *
                                                 (b_loop_ub - 1))) +
                               ((b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1)) *
                                b_i)) -
                              1];
      }
      c_x.set_size(1, 1, r4.size(2));
      loop_ub = r4.size(2);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        c_x[b_i] = (r4[b_i] > r5[b_i]);
      }
      b_y = false;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (c_x.size(2) - 1))) {
        if (c_x[loop_ub]) {
          b_y = true;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (b_y) {
        double e_x;
        e_x = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                    (b_board->BoardCoords.size(0) *
                                     (b_board->BoardCoords.size(1) - 1))) -
                                   1];
        if (e_x != 0.0) {
          newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1) - 1;
          for (b_i = 0; b_i <= loop_ub; b_i++) {
            b_loop_ub = b_board->BoardIdx.size(0) - 1;
            for (i1 = 0; i1 <= b_loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * b_i)];
            }
          }
          b_rot90(newBoardCoords2, b_board->BoardIdx);
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                  b_board
                      ->BoardCoords[i1 + (b_board->BoardCoords.size(0) * b_i)];
            }
          }
          b_rot90(newBoardCoords2, newBoardCoords1);
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * b_i)] =
                  b_board->BoardCoords[(i1 +
                                        (b_board->BoardCoords.size(0) * b_i)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          b_rot90(newBoardCoords2, r);
          cat(newBoardCoords1, r, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (b_i = 0; b_i < 2; b_i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = r1.size(0);
              for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                   outsize_idx_1++) {
                b_board->BoardCoords[(outsize_idx_1 +
                                      (b_board->BoardCoords.size(0) * i1)) +
                                     ((b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)) *
                                      b_i)] =
                    r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                       ((r1.size(0) * r1.size(1)) * b_i)];
              }
            }
          }
        }
      }
    }
  }
  return b_board;
}

//
// Arguments    : const b_Checkerboard *b_this
//                ::coder::array<double, 2U> &b_points
//                double b_boardSize[2]
// Return Type  : void
//
void toPoints(const b_Checkerboard *b_this,
              ::coder::array<double, 2U> &b_points, double b_boardSize[2])
{
  array<double, 2U> c_x;
  array<bool, 1U> b_x;
  int b_i;
  int c_this;
  bool exitg1;
  bool y;
  c_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  b_x.set_size(c_this);
  for (b_i = 0; b_i < c_this; b_i++) {
    b_x[b_i] = (b_this->BoardIdx[b_i] == 0.0);
  }
  y = false;
  c_this = 0;
  exitg1 = false;
  while ((!exitg1) && (c_this <= (b_x.size(0) - 1))) {
    if (b_x[c_this]) {
      y = true;
      exitg1 = true;
    } else {
      c_this++;
    }
  }
  if (y) {
    b_points.set_size(0, 0);
    b_boardSize[0] = 0.0;
    b_boardSize[1] = 0.0;
  } else {
    double numPoints;
    int i1;
    int loop_ub;
    numPoints = (static_cast<double>(b_this->BoardCoords.size(0))) *
                (static_cast<double>(b_this->BoardCoords.size(1)));
    b_points.set_size(static_cast<int>(numPoints), 2);
    c_this = static_cast<int>(numPoints);
    for (b_i = 0; b_i < 2; b_i++) {
      for (i1 = 0; i1 < c_this; i1++) {
        b_points[i1 + (b_points.size(0) * b_i)] = 0.0;
      }
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    c_x.set_size(loop_ub, c_this);
    for (b_i = 0; b_i < c_this; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_x[i1 + (c_x.size(0) * b_i)] =
            b_this->BoardCoords[b_i + (b_this->BoardCoords.size(0) * i1)];
      }
    }
    c_this = c_x.size(0) * c_x.size(1);
    for (b_i = 0; b_i < c_this; b_i++) {
      b_points[b_i] = c_x[b_i];
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    c_x.set_size(loop_ub, c_this);
    for (b_i = 0; b_i < c_this; b_i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_x[i1 + (c_x.size(0) * b_i)] =
            b_this->BoardCoords[(b_i + (b_this->BoardCoords.size(0) * i1)) +
                                (b_this->BoardCoords.size(0) *
                                 b_this->BoardCoords.size(1))];
      }
    }
    c_this = c_x.size(0) * c_x.size(1);
    for (b_i = 0; b_i < c_this; b_i++) {
      b_points[b_i + b_points.size(0)] = c_x[b_i];
    }
    b_boardSize[0] = (static_cast<double>(b_this->BoardCoords.size(1))) + 1.0;
    b_boardSize[1] = (static_cast<double>(b_this->BoardCoords.size(0))) + 1.0;
  }
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

//
// File trailer for detectCheckerboard.cpp
//
// [EOF]
//
