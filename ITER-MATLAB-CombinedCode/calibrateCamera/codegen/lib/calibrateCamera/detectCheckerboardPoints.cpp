//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "calibrateCamera_rtwutil.h"
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
// Arguments    : const ::coder::array<uint8_T, 2U> &g_I
//                ::coder::array<real_T, 2U> &b_imagePoints
//                real_T boardSize[2]
// Return Type  : void
//
namespace Codegen {
namespace coder {
void detectCheckerboardPoints(const ::coder::array<uint8_T, 2U> &g_I,
                              ::coder::array<real_T, 2U> &b_imagePoints,
                              real_T boardSize[2])
{
  static const real_T dv[15]{
      0.00043640742603817315, 0.0022162597803590169, 0.0087654774692430184,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430184,  0.0022162597803590156, 0.00043640742603817309};
  static const real_T hCol[15]{
      0.00043640742603817326, 0.0022162597803590169, 0.0087654774692430167,
      0.026999571389573731,   0.064768604754149334,  0.12100368400046491,
      0.17605932135785024,    0.19950134764464325,   0.17605932135785024,
      0.12100368400046491,    0.064768604754149334,  0.026999571389573731,
      0.0087654774692430167,  0.0022162597803590169, 0.00043640742603818741};
  vision::internal::calibration::checkerboard::b_Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::b_Checkerboard *board0;
  vision::internal::calibration::checkerboard::b_Checkerboard *board45;
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> c_a;
  ::coder::array<real_T, 2U> temp;
  ::coder::array<real_T, 1U> s;
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<real32_T, 2U> I_45;
  ::coder::array<real32_T, 2U> I_45_x;
  ::coder::array<real32_T, 2U> Ig;
  ::coder::array<real32_T, 2U> Ixy;
  ::coder::array<real32_T, 2U> Iy;
  ::coder::array<real32_T, 2U> b_a;
  ::coder::array<real32_T, 2U> b_x;
  ::coder::array<real32_T, 2U> b_y;
  ::coder::array<real32_T, 2U> h_I;
  ::coder::array<real32_T, 2U> points0;
  ::coder::array<real32_T, 2U> y;
  ::coder::array<real32_T, 1U> d_a;
  real_T b_board45[2];
  real_T pad[2];
  int32_T b_i;
  int32_T b_ix;
  int32_T b_loop_ub;
  int32_T d_i;
  int32_T h_N;
  int32_T i1;
  int32_T loop_ub;
  boolean_T guard1{false};
  boolean_T guard2{false};
  h_I.set_size(g_I.size(0), g_I.size(1));
  loop_ub = g_I.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = g_I.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      h_I[i1 + (h_I.size(0) * b_i)] =
          (static_cast<real32_T>(g_I[i1 + (g_I.size(0) * b_i)])) / 255.0F;
    }
  }
  pad[0] = 7.0;
  pad[1] = 7.0;
  if ((h_I.size(0) == 0) || (h_I.size(1) == 0)) {
    Ig.set_size(h_I.size(0), h_I.size(1));
    loop_ub = h_I.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = h_I.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Ig[i1 + (Ig.size(0) * b_i)] = h_I[i1 + (h_I.size(0) * b_i)];
      }
    }
  } else {
    int32_T ix;
    padImage_outSize(h_I, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b_a.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        c_a[i1 + (c_a.size(0) * b_i)] =
            static_cast<real_T>(b_a[i1 + (b_a.size(0) * b_i)]);
      }
    }
    b.set_size(h_I.size(0), h_I.size(1));
    temp.set_size(c_a.size(0), h_I.size(1));
    b_i = h_I.size(1);
    loop_ub = c_a.size(0);
    i1 = c_a.size(0);
    b_loop_ub = c_a.size(0);
    for (ix = 0; ix < b_i; ix++) {
      int32_T i2;
      for (i2 = 0; i2 < loop_ub; i2++) {
        temp[i2 + (temp.size(0) * ix)] = 0.0;
      }
      for (d_i = 0; d_i < 15; d_i++) {
        b_ix = static_cast<int32_T>(static_cast<uint32_T>(
            (static_cast<uint32_T>(ix)) + (static_cast<uint32_T>(d_i))));
        s.set_size(i1);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          s[i2] = c_a[i2 + (c_a.size(0) * b_ix)] * dv[d_i];
        }
        h_N = temp.size(0) - 1;
        s.set_size(temp.size(0));
        for (i2 = 0; i2 <= h_N; i2++) {
          s[i2] = temp[i2 + (temp.size(0) * ix)] + s[i2];
        }
        h_N = s.size(0);
        for (i2 = 0; i2 < h_N; i2++) {
          temp[i2 + (temp.size(0) * ix)] = s[i2];
        }
      }
    }
    b_i = h_I.size(1);
    for (ix = 0; ix < b_i; ix++) {
      i1 = h_I.size(0);
      for (h_N = 0; h_N < i1; h_N++) {
        real_T d;
        d = 0.0;
        for (d_i = 0; d_i < 15; d_i++) {
          d += temp[(static_cast<int32_T>(
                        static_cast<uint32_T>((static_cast<uint32_T>(h_N)) +
                                              (static_cast<uint32_T>(d_i))))) +
                    (temp.size(0) * ix)] *
               hCol[d_i];
        }
        b[h_N + (b.size(0) * ix)] = d;
      }
    }
    Ig.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Ig[i1 + (Ig.size(0) * b_i)] =
            static_cast<real32_T>(b[i1 + (b.size(0) * b_i)]);
      }
    }
  }
  Iy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Iy[i1 + (Iy.size(0) * b_i)] = Ig[i1 + (Ig.size(0) * b_i)];
    }
  }
  imfilter(Iy);
  b_imfilter(Ig);
  Ixy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Ixy[i1 + (Ixy.size(0) * b_i)] = Ig[i1 + (Ig.size(0) * b_i)];
    }
  }
  imfilter(Ixy);
  b_x.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_x[i1 + (b_x.size(0) * b_i)] =
          Ig[i1 + (Ig.size(0) * b_i)] * 0.707106769F;
    }
  }
  I_45.set_size(b_x.size(0), b_x.size(1));
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45[i1 + (I_45.size(0) * b_i)] =
          b_x[i1 + (b_x.size(0) * b_i)] +
          (Iy[i1 + (Iy.size(0) * b_i)] * 0.707106769F);
    }
  }
  I_45_x.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45_x[i1 + (I_45_x.size(0) * b_i)] = I_45[i1 + (I_45.size(0) * b_i)];
    }
  }
  b_imfilter(I_45_x);
  b_a.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_a[i1 + (b_a.size(0) * b_i)] = I_45[i1 + (I_45.size(0) * b_i)];
    }
  }
  imfilter(b_a);
  loop_ub = I_45_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = I_45_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      I_45_x[i1 + (I_45_x.size(0) * b_i)] =
          (I_45_x[i1 + (I_45_x.size(0) * b_i)] * 0.707106769F) +
          (b_a[i1 + (b_a.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = Ixy.size(1);
  y.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        y[b_ix + (y.size(0) * loop_ub)] =
            std::abs(Ixy[b_ix + (Ixy.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + (y.size(0) * b_i)] = 4.0F * y[i1 + (y.size(0) * b_i)];
    }
  }
  b_i = I_45.size(1);
  b_y.set_size(I_45.size(0), I_45.size(1));
  if ((I_45.size(0) != 0) && (I_45.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = b_y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        b_y[b_ix + (b_y.size(0) * loop_ub)] =
            std::abs(I_45[b_ix + (I_45.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = b_x.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_x.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_x[i1 + (b_x.size(0) * b_i)] =
          b_x[i1 + (b_x.size(0) * b_i)] +
          (Iy[i1 + (Iy.size(0) * b_i)] * -0.707106769F);
    }
  }
  b_i = b_x.size(1);
  I_45.set_size(b_x.size(0), b_x.size(1));
  if ((b_x.size(0) != 0) && (b_x.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = I_45.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        I_45[b_ix + (I_45.size(0) * loop_ub)] =
            std::abs(b_x[b_ix + (b_x.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = b_y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_y[i1 + (b_y.size(0) * b_i)] = 3.0F * (b_y[i1 + (b_y.size(0) * b_i)] +
                                              I_45[i1 + (I_45.size(0) * b_i)]);
    }
  }
  b_a.set_size(y.size(0), y.size(1));
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_a[i1 + (b_a.size(0) * b_i)] =
          y[i1 + (y.size(0) * b_i)] - b_y[i1 + (b_y.size(0) * b_i)];
    }
  }
  b_ix = (y.size(0) * y.size(1)) - 1;
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if ((y[d_i] - b_y[d_i]) < 0.0F) {
      h_N++;
    }
  }
  r.set_size(h_N);
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if ((y[d_i] - b_y[d_i]) < 0.0F) {
      r[h_N] = d_i + 1;
      h_N++;
    }
  }
  loop_ub = r.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_a[r[b_i] - 1] = 0.0F;
  }
  b_i = I_45_x.size(1);
  y.set_size(I_45_x.size(0), I_45_x.size(1));
  if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        y[b_ix + (y.size(0) * loop_ub)] =
            std::abs(I_45_x[b_ix + (I_45_x.size(0) * loop_ub)]);
      }
    }
  }
  b_i = Ig.size(1);
  b_y.set_size(Ig.size(0), Ig.size(1));
  if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = b_y.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        b_y[b_ix + (b_y.size(0) * loop_ub)] =
            std::abs(Ig[b_ix + (Ig.size(0) * loop_ub)]);
      }
    }
  }
  b_i = Iy.size(1);
  I_45.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
      i1 = I_45.size(0);
      for (b_ix = 0; b_ix < i1; b_ix++) {
        I_45[b_ix + (I_45.size(0) * loop_ub)] =
            std::abs(Iy[b_ix + (Iy.size(0) * loop_ub)]);
      }
    }
  }
  loop_ub = y.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = y.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      y[i1 + (y.size(0) * b_i)] = (4.0F * y[i1 + (y.size(0) * b_i)]) -
                                  (3.0F * (b_y[i1 + (b_y.size(0) * b_i)] +
                                           I_45[i1 + (I_45.size(0) * b_i)]));
    }
  }
  b_ix = (y.size(0) * y.size(1)) - 1;
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if (y[d_i] < 0.0F) {
      h_N++;
    }
  }
  r1.set_size(h_N);
  h_N = 0;
  for (d_i = 0; d_i <= b_ix; d_i++) {
    if (y[d_i] < 0.0F) {
      r1[h_N] = d_i + 1;
      h_N++;
    }
  }
  loop_ub = r1.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    y[r1[b_i] - 1] = 0.0F;
  }
  b_i = Ig.size(1);
  b_y.set_size(Ig.size(0), Ig.size(1));
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    h_N = b_y.size(0);
    for (b_ix = 0; b_ix < h_N; b_ix++) {
      b_y[b_ix + (b_y.size(0) * loop_ub)] =
          rt_powf_snf(Ig[b_ix + (Ig.size(0) * loop_ub)], 2.0F);
    }
  }
  c_imfilter(b_y);
  b_i = Iy.size(1);
  I_45.set_size(Iy.size(0), Iy.size(1));
  for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
    h_N = I_45.size(0);
    for (b_ix = 0; b_ix < h_N; b_ix++) {
      I_45[b_ix + (I_45.size(0) * loop_ub)] =
          rt_powf_snf(Iy[b_ix + (Iy.size(0) * loop_ub)], 2.0F);
    }
  }
  c_imfilter(I_45);
  loop_ub = Ig.size(1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = Ig.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Ig[i1 + (Ig.size(0) * b_i)] =
          Ig[i1 + (Ig.size(0) * b_i)] * Iy[i1 + (Iy.size(0) * b_i)];
    }
  }
  c_imfilter(Ig);
  vision::internal::calibration::checkerboard::find_peaks(b_a, points0);
  h_N = b_a.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<real_T>(static_cast<int32_T>(
        (static_cast<int32_T>(points0[b_i + points0.size(0)])) +
        (h_N * ((static_cast<int32_T>(points0[b_i])) - 1))));
  }
  d_a.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_a[b_i] = b_a[(static_cast<int32_T>(s[b_i])) - 1];
  }
  board0 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, d_a, b_y, I_45, Ig, 0.0, &lobj_0[0]);
  b_imagePoints.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  vision::internal::calibration::checkerboard::find_peaks(y, points0);
  h_N = y.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (b_i = 0; b_i < loop_ub; b_i++) {
    s[b_i] = static_cast<real_T>(static_cast<int32_T>(
        (static_cast<int32_T>(points0[b_i + points0.size(0)])) +
        (h_N * ((static_cast<int32_T>(points0[b_i])) - 1))));
  }
  d_a.set_size(s.size(0));
  loop_ub = s.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    d_a[b_i] = y[(static_cast<int32_T>(s[b_i])) - 1];
  }
  board45 = vision::internal::calibration::checkerboard::growCheckerboard(
      points0, d_a, b_y, I_45, Ig, 0.78539816339744828, &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      pad[0] = static_cast<real_T>(board0->BoardIdx.size(0));
      pad[1] = static_cast<real_T>(board0->BoardIdx.size(1));
      b_board45[0] = static_cast<real_T>(board45->BoardIdx.size(0));
      b_board45[1] = static_cast<real_T>(board45->BoardIdx.size(1));
      if (isequal(pad, b_board45)) {
        h_N = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        s.set_size(h_N);
        for (b_i = 0; b_i < h_N; b_i++) {
          s[b_i] = board0->BoardIdx[b_i];
        }
        b_loop_ub = 0;
        b_i = s.size(0);
        for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            b_loop_ub++;
          }
        }
        h_N = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        s.set_size(h_N);
        for (b_i = 0; b_i < h_N; b_i++) {
          s[b_i] = board45->BoardIdx[b_i];
        }
        b_ix = 0;
        b_i = s.size(0);
        for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            b_ix++;
          }
        }
        if (b_loop_ub > b_ix) {
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
    board0 = vision::internal::calibration::checkerboard::orient(board0, h_I);
    vision::internal::calibration::checkerboard::toPoints(board0, b_imagePoints,
                                                          boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        Ixy, b_imagePoints);
  }
  if (guard1 && (board45->isValid)) {
    board45 = vision::internal::calibration::checkerboard::orient(board45, h_I);
    vision::internal::calibration::checkerboard::toPoints(
        board45, b_imagePoints, boardSize);
    vision::internal::calibration::checkerboard::subPixelLocation(
        I_45_x, b_imagePoints);
  }
  if ((b_imagePoints.size(0) == 0) || (b_imagePoints.size(1) == 0)) {
    vision::internal::calibration::checkerboard::detectCheckerboard(
        h_I, b_imagePoints, boardSize);
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
