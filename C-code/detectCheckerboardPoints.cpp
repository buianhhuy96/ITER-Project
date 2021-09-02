//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
// Arguments    : const ::coder::array<unsigned char, 2U> &b_I
//                ::coder::array<double, 2U> &imagePoints
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
void detectCheckerboardPoints(const ::coder::array<unsigned char, 2U> &b_I,
                              ::coder::array<double, 2U> &imagePoints,
                              double boardSize[2])
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
  vision::internal::calibration::checkerboard::Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::Checkerboard *board0;
  vision::internal::calibration::checkerboard::Checkerboard *board45;
  array<double, 2U> b;
  array<double, 2U> b_a;
  array<double, 1U> s;
  array<float, 2U> I_45;
  array<float, 2U> I_45_x;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> a;
  array<float, 2U> c_I;
  array<float, 2U> points0;
  array<float, 2U> r;
  array<float, 2U> x;
  array<float, 1U> b_x;
  array<int, 1U> r1;
  array<int, 1U> r2;
  double finalSize[2];
  double pad[2];
  int N;
  int b_i;
  int i;
  int k;
  int loop_ub;
  bool guard1{false};
  bool guard2{false};
  c_I.set_size(b_I.size(0), b_I.size(1));
  loop_ub = b_I.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = b_I.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      c_I[b_i + (c_I.size(0) * i)] =
          (static_cast<float>(b_I[b_i + (b_I.size(0) * i)])) / 255.0F;
    }
  }
  finalSize[0] = static_cast<double>(c_I.size(0));
  pad[0] = 7.0;
  finalSize[1] = static_cast<double>(c_I.size(1));
  pad[1] = 7.0;
  if ((c_I.size(0) == 0) || (c_I.size(1) == 0)) {
    Ig.set_size(c_I.size(0), c_I.size(1));
    loop_ub = c_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = c_I.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] = c_I[b_i + (c_I.size(0) * i)];
      }
    }
  } else {
    padImage_outSize(c_I, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    conv2_separable_valid(dv, dv1, b_a, finalSize, b);
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    Iy.set_size(Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = Ig.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Iy[b_i + (Iy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
      }
    }
  } else {
    padImage_outSize(Ig, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    Iy.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Iy[b_i + (Iy.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  imfilter(Ig);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((Ig.size(0) == 0) || (Ig.size(1) == 0)) {
    Ixy.set_size(Ig.size(0), Ig.size(1));
    loop_ub = Ig.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = Ig.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ixy[b_i + (Ixy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
      }
    }
  } else {
    padImage_outSize(Ig, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    Ixy.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ixy[b_i + (Ixy.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  x.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = Ig.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      x[b_i + (x.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)] * 0.707106769F;
    }
  }
  I_45.set_size(x.size(0), x.size(1));
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = x.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45[b_i + (I_45.size(0) * i)] =
          x[b_i + (x.size(0) * i)] +
          (Iy[b_i + (Iy.size(0) * i)] * 0.707106769F);
    }
  }
  I_45_x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45_x[b_i + (I_45_x.size(0) * i)] = I_45[b_i + (I_45.size(0) * i)];
    }
  }
  imfilter(I_45_x);
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((I_45.size(0) == 0) || (I_45.size(1) == 0)) {
    a.set_size(I_45.size(0), I_45.size(1));
    loop_ub = I_45.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = I_45.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        a[b_i + (a.size(0) * i)] = I_45[b_i + (I_45.size(0) * i)];
      }
    }
  } else {
    padImage_outSize(I_45, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::conv2AXPYValidCMP(b_a, b);
    a.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        a[b_i + (a.size(0) * i)] = static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  loop_ub = I_45_x.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45_x.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45_x[b_i + (I_45_x.size(0) * i)] =
          (I_45_x[b_i + (I_45_x.size(0) * i)] * 0.707106769F) +
          (a[b_i + (a.size(0) * i)] * -0.707106769F);
    }
  }
  i = I_45.size(1);
  r.set_size(I_45.size(0), I_45.size(1));
  if ((I_45.size(0) != 0) && (I_45.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = r.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        r[loop_ub + (r.size(0) * k)] =
            std::abs(I_45[loop_ub + (I_45.size(0) * k)]);
      }
    }
  }
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = x.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      x[b_i + (x.size(0) * i)] = x[b_i + (x.size(0) * i)] +
                                 (Iy[b_i + (Iy.size(0) * i)] * -0.707106769F);
    }
  }
  i = x.size(1);
  a.set_size(x.size(0), x.size(1));
  if ((x.size(0) != 0) && (x.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = a.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        a[loop_ub + (a.size(0) * k)] = std::abs(x[loop_ub + (x.size(0) * k)]);
      }
    }
  }
  i = Ixy.size(1);
  I_45.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = I_45.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        I_45[loop_ub + (I_45.size(0) * k)] =
            std::abs(Ixy[loop_ub + (Ixy.size(0) * k)]);
      }
    }
  }
  loop_ub = I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45[b_i + (I_45.size(0) * i)] = 4.0F * I_45[b_i + (I_45.size(0) * i)];
    }
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = r.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      r[b_i + (r.size(0) * i)] =
          3.0F * (r[b_i + (r.size(0) * i)] + a[b_i + (a.size(0) * i)]);
    }
  }
  x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      x[b_i + (x.size(0) * i)] =
          I_45[b_i + (I_45.size(0) * i)] - r[b_i + (r.size(0) * i)];
    }
  }
  loop_ub = (I_45.size(0) * I_45.size(1)) - 1;
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if ((I_45[b_i] - r[b_i]) < 0.0F) {
      N++;
    }
  }
  r1.set_size(N);
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if ((I_45[b_i] - r[b_i]) < 0.0F) {
      r1[N] = b_i + 1;
      N++;
    }
  }
  loop_ub = r1.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[r1[i] - 1] = 0.0F;
  }
  i = Ig.size(1);
  r.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = r.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        r[loop_ub + (r.size(0) * k)] = std::abs(Ig[loop_ub + (Ig.size(0) * k)]);
      }
    }
  }
  i = Iy.size(1);
  a.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = a.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        a[loop_ub + (a.size(0) * k)] = std::abs(Iy[loop_ub + (Iy.size(0) * k)]);
      }
    }
  }
  i = I_45_x.size(1);
  I_45.set_size(I_45_x.size(0), I_45_x.size(1));
  if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = I_45.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        I_45[loop_ub + (I_45.size(0) * k)] =
            std::abs(I_45_x[loop_ub + (I_45_x.size(0) * k)]);
      }
    }
  }
  loop_ub = I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45[b_i + (I_45.size(0) * i)] =
          (4.0F * I_45[b_i + (I_45.size(0) * i)]) -
          (3.0F * (r[b_i + (r.size(0) * i)] + a[b_i + (a.size(0) * i)]));
    }
  }
  loop_ub = (I_45.size(0) * I_45.size(1)) - 1;
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (I_45[b_i] < 0.0F) {
      N++;
    }
  }
  r2.set_size(N);
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (I_45[b_i] < 0.0F) {
      r2[N] = b_i + 1;
      N++;
    }
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    I_45[r2[i] - 1] = 0.0F;
  }
  i = Ig.size(1);
  Ix2.set_size(Ig.size(0), Ig.size(1));
  for (k = 0; k < i; k++) {
    N = Ix2.size(0);
    for (loop_ub = 0; loop_ub < N; loop_ub++) {
      Ix2[loop_ub + (Ix2.size(0) * k)] =
          rt_powf_snf(Ig[loop_ub + (Ig.size(0) * k)], 2.0F);
    }
  }
  i = Iy.size(1);
  Iy2.set_size(Iy.size(0), Iy.size(1));
  for (k = 0; k < i; k++) {
    N = Iy2.size(0);
    for (loop_ub = 0; loop_ub < N; loop_ub++) {
      Iy2[loop_ub + (Iy2.size(0) * k)] =
          rt_powf_snf(Iy[loop_ub + (Iy.size(0) * k)], 2.0F);
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ix2.size(0) != 0) && (Ix2.size(1) != 0)) {
    padImage_outSize(Ix2, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    Ix2.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ix2[b_i + (Ix2.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Iy2.size(0) != 0) && (Iy2.size(1) != 0)) {
    padImage_outSize(Iy2, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    Iy2.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Iy2[b_i + (Iy2.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  loop_ub = Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = Ig.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      Ig[b_i + (Ig.size(0) * i)] =
          Ig[b_i + (Ig.size(0) * i)] * Iy[b_i + (Iy.size(0) * i)];
    }
  }
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    padImage_outSize(Ig, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    loop_ub = a.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = a.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    internal::c_conv2AXPYValidCMP(b_a, b);
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
  vision::internal::calibration::checkerboard::find_peaks(x, points0);
  N = x.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    s[i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                         (N * ((static_cast<int>(points0[i])) - 1))));
  }
  b_x.set_size(s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = x[(static_cast<int>(s[i])) - 1];
  }
  board0 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, b_x, Ix2, Iy2, Ig, 0.0, &lobj_0[0]);
  imagePoints.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(I_45, points0);
  N = I_45.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    s[i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                         (N * ((static_cast<int>(points0[i])) - 1))));
  }
  b_x.set_size(s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_x[i] = I_45[(static_cast<int>(s[i])) - 1];
  }
  board45 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, b_x, Ix2, Iy2, Ig, 0.78539816339744828, &lobj_0[3]);
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
        N = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(N);
        for (i = 0; i < N; i++) {
          s[i] = board0->BoardIdx[i];
        }
        b_i = 0;
        i = s.size(0);
        for (k = 0; k < i; k++) {
          if (s[k] != 0.0) {
            b_i++;
          }
        }
        N = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(N);
        for (i = 0; i < N; i++) {
          s[i] = board45->BoardIdx[i];
        }
        loop_ub = 0;
        i = s.size(0);
        for (k = 0; k < i; k++) {
          if (s[k] != 0.0) {
            loop_ub++;
          }
        }
        if (b_i > loop_ub) {
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
    board0 = vision::internal::calibration::checkerboard::orient(board0, c_I);
    vision::internal::calibration::checkerboard::toPoints(board0, imagePoints,
                                                          boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(Ixy,
                                                                  imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    board45 = vision::internal::calibration::checkerboard::orient(board45, c_I);
    vision::internal::calibration::checkerboard::toPoints(board45, imagePoints,
                                                          boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(I_45_x,
                                                                  imagePoints);
  }
  if ((imagePoints.size(0) == 0) || (imagePoints.size(1) == 0)) {
    vision::internal::calibration::checkerboard::detectCheckerboard(
        c_I, imagePoints, boardSize);
  }
}

} // namespace coder

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
