//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "calibrateHandeye_rtwutil.h"
#include "conv2AXPYValidCMP.h"
#include "detectCheckerboard.h"
#include "find_peaks.h"
#include "imfilter.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 2U> &e_I
//                ::coder::array<double, 2U> &c_imagePoints
//                double b_boardSize[2]
// Return Type  : void
//
namespace coder {
void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &e_I,
                              ::coder::array<double, 2U> &c_imagePoints,
                              double b_boardSize[2])
{
  static const double dv[15]{
      0.00043640742603817326, 0.0022162597803590169, 0.0087654774692430167,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430167,  0.0022162597803590169, 0.00043640742603818741};
  static const double dv1[15]{
      0.00043640742603817315, 0.0022162597803590169, 0.0087654774692430184,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430184,  0.0022162597803590156, 0.00043640742603817309};
  vision::internal::calibration::checkerboard::b_Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard *board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *board45;
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
  array<float, 2U> g_I;
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
  g_I.set_size(e_I.size(0), e_I.size(1));
  loop_ub = e_I.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = e_I.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      g_I[c_i + (g_I.size(0) * b_i)] =
          (static_cast<float>(e_I[c_i + (e_I.size(0) * b_i)])) / 255.0F;
    }
  }
  finalSize[0] = static_cast<double>(g_I.size(0));
  pad[0] = 7.0;
  finalSize[1] = static_cast<double>(g_I.size(1));
  pad[1] = 7.0;
  if ((g_I.size(0) == 0) || (g_I.size(1) == 0)) {
    Ig.set_size(g_I.size(0), g_I.size(1));
    loop_ub = g_I.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = g_I.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        Ig[c_i + (Ig.size(0) * b_i)] = g_I[c_i + (g_I.size(0) * b_i)];
      }
    }
  } else {
    padImage_outSize(g_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      d_N = b_a.size(0);
      for (c_i = 0; c_i < d_N; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    conv2_separable_valid(dv, dv1, c_a, finalSize, b);
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
    internal::conv2AXPYValidCMP(c_a, b);
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
    internal::conv2AXPYValidCMP(c_a, b);
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
    internal::conv2AXPYValidCMP(c_a, b);
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
          4.0F * I_45[c_i + (I_45.size(0) * b_i)];
    }
  }
  loop_ub = r.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_N = r.size(0);
    for (c_i = 0; c_i < d_N; c_i++) {
      r[c_i + (r.size(0) * b_i)] =
          3.0F * (r[c_i + (r.size(0) * b_i)] + b_a[c_i + (b_a.size(0) * b_i)]);
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
          (4.0F * I_45[c_i + (I_45.size(0) * b_i)]) -
          (3.0F *
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
    internal::c_conv2AXPYValidCMP(c_a, b);
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
    internal::c_conv2AXPYValidCMP(c_a, b);
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
    internal::c_conv2AXPYValidCMP(c_a, b);
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
  vision::internal::calibration::checkerboard::find_peaks(b_x, points0);
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
  board0 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, c_x, Ix2, Iy2, Ig, 0.0, &lobj_0[0]);
  c_imagePoints.set_size(0, 0);
  b_boardSize[0] = 0.0;
  b_boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(I_45, points0);
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
  board45 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, c_x, Ix2, Iy2, Ig, 0.78539816339744828, &lobj_0[3]);
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
    board0 = vision::internal::calibration::checkerboard::orient(board0, g_I);
    vision::internal::calibration::checkerboard::toPoints(board0, c_imagePoints,
                                                          b_boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, c_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    board45 = vision::internal::calibration::checkerboard::orient(board45, g_I);
    vision::internal::calibration::checkerboard::toPoints(
        board45, c_imagePoints, b_boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_x, c_imagePoints);
  }
  if ((c_imagePoints.size(0) == 0) || (c_imagePoints.size(1) == 0)) {
    vision::internal::calibration::checkerboard::detectCheckerboard(
        g_I, c_imagePoints, b_boardSize);
  }
}

} // namespace coder

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
