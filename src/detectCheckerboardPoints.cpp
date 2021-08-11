//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboardPoints.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "detectCheckerboardPoints.h"
#include "Checkerboard.h"
#include "calibrateHandeye_rtwutil.h"
#include "detectCheckerboard.h"
#include "find_peaks.h"
#include "imfilter.h"
#include "isequal.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include "coder_array.h"
#include "libmwrgb2gray_tbb.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &b_I
//                ::coder::array<double, 2U> &imagePoints
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
void detectCheckerboardPoints(const ::coder::array<unsigned char, 3U> &b_I,
                              ::coder::array<double, 2U> &imagePoints,
                              double boardSize[2])
{
  vision::internal::calibration::checkerboard::Checkerboard lobj_0[6];
  vision::internal::calibration::checkerboard::Checkerboard *board0;
  vision::internal::calibration::checkerboard::Checkerboard *board45;
  array<double, 1U> s;
  array<float, 2U> I_45;
  array<float, 2U> I_45_x;
  array<float, 2U> I_45_y;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> c_I;
  array<float, 2U> points0;
  array<float, 2U> r;
  array<float, 2U> r1;
  array<float, 2U> x;
  array<float, 1U> b_I_45;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<unsigned char, 2U> Igray;
  double b_board0[2];
  double b_board45[2];
  int N;
  int b_N;
  int b_i;
  int i;
  Igray.set_size(b_I.size(0), b_I.size(1));
  rgb2gray_tbb_uint8(&b_I[0],
                     (static_cast<double>(b_I.size(0))) *
                         (static_cast<double>(b_I.size(1))),
                     &Igray[0], true);
  c_I.set_size(Igray.size(0), Igray.size(1));
  N = Igray.size(1);
  for (i = 0; i < N; i++) {
    b_N = Igray.size(0);
    for (b_i = 0; b_i < b_N; b_i++) {
      c_I[b_i + (c_I.size(0) * i)] =
          (static_cast<float>(Igray[b_i + (Igray.size(0) * i)])) / 255.0F;
    }
  }
  vision::internal::calibration::checkerboard::detectCheckerboard(
      c_I, imagePoints, boardSize);
  if ((imagePoints.size(0) == 0) || (imagePoints.size(1) == 0)) {
    int b_k;
    int k;
    boolean_T guard1{false};
    boolean_T guard2{false};
    Ig.set_size(c_I.size(0), c_I.size(1));
    N = c_I.size(1);
    for (i = 0; i < N; i++) {
      b_N = c_I.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] = c_I[b_i + (c_I.size(0) * i)];
      }
    }
    d_imfilter(Ig);
    Iy.set_size(Ig.size(0), Ig.size(1));
    N = Ig.size(1);
    for (i = 0; i < N; i++) {
      b_N = Ig.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        Iy[b_i + (Iy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
      }
    }
    imfilter(Iy);
    b_imfilter(Ig);
    Ixy.set_size(Ig.size(0), Ig.size(1));
    N = Ig.size(1);
    for (i = 0; i < N; i++) {
      b_N = Ig.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        Ixy[b_i + (Ixy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
      }
    }
    imfilter(Ixy);
    x.set_size(Ig.size(0), Ig.size(1));
    N = Ig.size(1);
    for (i = 0; i < N; i++) {
      b_N = Ig.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        x[b_i + (x.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)] * 0.707106769F;
      }
    }
    I_45.set_size(x.size(0), x.size(1));
    N = x.size(1);
    for (i = 0; i < N; i++) {
      b_N = x.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45[b_i + (I_45.size(0) * i)] =
            x[b_i + (x.size(0) * i)] +
            (Iy[b_i + (Iy.size(0) * i)] * 0.707106769F);
      }
    }
    I_45_x.set_size(I_45.size(0), I_45.size(1));
    N = I_45.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45_x[b_i + (I_45_x.size(0) * i)] = I_45[b_i + (I_45.size(0) * i)];
      }
    }
    b_imfilter(I_45_x);
    I_45_y.set_size(I_45.size(0), I_45.size(1));
    N = I_45.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45_y[b_i + (I_45_y.size(0) * i)] = I_45[b_i + (I_45.size(0) * i)];
      }
    }
    imfilter(I_45_y);
    N = I_45_x.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45_x.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45_x[b_i + (I_45_x.size(0) * i)] =
            (I_45_x[b_i + (I_45_x.size(0) * i)] * 0.707106769F) +
            (I_45_y[b_i + (I_45_y.size(0) * i)] * -0.707106769F);
      }
    }
    r.set_size(I_45.size(0), I_45.size(1));
    if ((I_45.size(0) != 0) && (I_45.size(1) != 0)) {
      i = I_45.size(1);
      for (k = 0; k < i; k++) {
        b_i = r.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          r[b_k + (r.size(0) * k)] = std::abs(I_45[b_k + (I_45.size(0) * k)]);
        }
      }
    }
    N = x.size(1);
    for (i = 0; i < N; i++) {
      b_N = x.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        x[b_i + (x.size(0) * i)] = x[b_i + (x.size(0) * i)] +
                                   (Iy[b_i + (Iy.size(0) * i)] * -0.707106769F);
      }
    }
    r1.set_size(x.size(0), x.size(1));
    if ((x.size(0) != 0) && (x.size(1) != 0)) {
      i = x.size(1);
      for (k = 0; k < i; k++) {
        b_i = r1.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          r1[b_k + (r1.size(0) * k)] = std::abs(x[b_k + (x.size(0) * k)]);
        }
      }
    }
    I_45_y.set_size(Ixy.size(0), Ixy.size(1));
    if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
      i = Ixy.size(1);
      for (k = 0; k < i; k++) {
        b_i = I_45_y.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          I_45_y[b_k + (I_45_y.size(0) * k)] =
              std::abs(Ixy[b_k + (Ixy.size(0) * k)]);
        }
      }
    }
    N = I_45_y.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45_y.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45_y[b_i + (I_45_y.size(0) * i)] =
            16.0F * I_45_y[b_i + (I_45_y.size(0) * i)];
      }
    }
    N = r.size(1);
    for (i = 0; i < N; i++) {
      b_N = r.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        r[b_i + (r.size(0) * i)] =
            6.0F * (r[b_i + (r.size(0) * i)] + r1[b_i + (r1.size(0) * i)]);
      }
    }
    I_45.set_size(I_45_y.size(0), I_45_y.size(1));
    N = I_45_y.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45_y.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45[b_i + (I_45.size(0) * i)] =
            I_45_y[b_i + (I_45_y.size(0) * i)] - r[b_i + (r.size(0) * i)];
      }
    }
    N = (I_45_y.size(0) * I_45_y.size(1)) - 1;
    b_N = 0;
    for (b_i = 0; b_i <= N; b_i++) {
      if ((I_45_y[b_i] - r[b_i]) < 0.0F) {
        b_N++;
      }
    }
    r2.set_size(b_N);
    b_N = 0;
    for (b_i = 0; b_i <= N; b_i++) {
      if ((I_45_y[b_i] - r[b_i]) < 0.0F) {
        r2[b_N] = b_i + 1;
        b_N++;
      }
    }
    N = r2.size(0);
    for (i = 0; i < N; i++) {
      I_45[r2[i] - 1] = 0.0F;
    }
    r.set_size(Ig.size(0), Ig.size(1));
    if ((Ig.size(0) != 0) && (Ig.size(1) != 0)) {
      i = Ig.size(1);
      for (k = 0; k < i; k++) {
        b_i = r.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          r[b_k + (r.size(0) * k)] = std::abs(Ig[b_k + (Ig.size(0) * k)]);
        }
      }
    }
    r1.set_size(Iy.size(0), Iy.size(1));
    if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
      i = Iy.size(1);
      for (k = 0; k < i; k++) {
        b_i = r1.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          r1[b_k + (r1.size(0) * k)] = std::abs(Iy[b_k + (Iy.size(0) * k)]);
        }
      }
    }
    I_45_y.set_size(I_45_x.size(0), I_45_x.size(1));
    if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
      i = I_45_x.size(1);
      for (k = 0; k < i; k++) {
        b_i = I_45_y.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          I_45_y[b_k + (I_45_y.size(0) * k)] =
              std::abs(I_45_x[b_k + (I_45_x.size(0) * k)]);
        }
      }
    }
    N = I_45_y.size(1);
    for (i = 0; i < N; i++) {
      b_N = I_45_y.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        I_45_y[b_i + (I_45_y.size(0) * i)] =
            (16.0F * I_45_y[b_i + (I_45_y.size(0) * i)]) -
            (6.0F * (r[b_i + (r.size(0) * i)] + r1[b_i + (r1.size(0) * i)]));
      }
    }
    N = (I_45_y.size(0) * I_45_y.size(1)) - 1;
    b_N = 0;
    for (b_i = 0; b_i <= N; b_i++) {
      if (I_45_y[b_i] < 0.0F) {
        b_N++;
      }
    }
    r3.set_size(b_N);
    b_N = 0;
    for (b_i = 0; b_i <= N; b_i++) {
      if (I_45_y[b_i] < 0.0F) {
        r3[b_N] = b_i + 1;
        b_N++;
      }
    }
    N = r3.size(0);
    for (i = 0; i < N; i++) {
      I_45_y[r3[i] - 1] = 0.0F;
    }
    Ix2.set_size(Ig.size(0), Ig.size(1));
    b_N = Ig.size(1);
    for (k = 0; k < b_N; k++) {
      N = Ix2.size(0);
      for (b_k = 0; b_k < N; b_k++) {
        Ix2[b_k + (Ix2.size(0) * k)] =
            rt_powf_snf(Ig[b_k + (Ig.size(0) * k)], 2.0F);
      }
    }
    Iy2.set_size(Iy.size(0), Iy.size(1));
    b_N = Iy.size(1);
    for (k = 0; k < b_N; k++) {
      N = Iy2.size(0);
      for (b_k = 0; b_k < N; b_k++) {
        Iy2[b_k + (Iy2.size(0) * k)] =
            rt_powf_snf(Iy[b_k + (Iy.size(0) * k)], 2.0F);
      }
    }
    c_imfilter(Ix2);
    c_imfilter(Iy2);
    N = Ig.size(1);
    for (i = 0; i < N; i++) {
      b_N = Ig.size(0);
      for (b_i = 0; b_i < b_N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] =
            Ig[b_i + (Ig.size(0) * i)] * Iy[b_i + (Iy.size(0) * i)];
      }
    }
    c_imfilter(Ig);
    vision::internal::calibration::checkerboard::find_peaks(I_45, points0);
    b_N = I_45.size(0);
    N = points0.size(0);
    s.set_size(points0.size(0));
    for (i = 0; i < N; i++) {
      s[i] = static_cast<double>(
          static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                           (b_N * ((static_cast<int>(points0[i])) - 1))));
    }
    b_I_45.set_size(s.size(0));
    N = s.size(0);
    for (i = 0; i < N; i++) {
      b_I_45[i] = I_45[(static_cast<int>(s[i])) - 1];
    }
    board0 = vision::internal::calibration::checkerboard::growCheckerboard(
        points0, b_I_45, Ix2, Iy2, Ig, 0.0, &lobj_0[0]);
    imagePoints.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
    vision::internal::calibration::checkerboard::find_peaks(I_45_y, points0);
    b_N = I_45_y.size(0);
    N = points0.size(0);
    s.set_size(points0.size(0));
    for (i = 0; i < N; i++) {
      s[i] = static_cast<double>(
          static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                           (b_N * ((static_cast<int>(points0[i])) - 1))));
    }
    b_I_45.set_size(s.size(0));
    N = s.size(0);
    for (i = 0; i < N; i++) {
      b_I_45[i] = I_45_y[(static_cast<int>(s[i])) - 1];
    }
    board45 = vision::internal::calibration::checkerboard::growCheckerboard(
        points0, b_I_45, Ix2, Iy2, Ig, 0.78539816339744828, &lobj_0[3]);
    guard1 = false;
    guard2 = false;
    if (board0->isValid) {
      if (board0->Energy <= board45->Energy) {
        guard2 = true;
      } else {
        b_board0[0] = static_cast<double>(board0->BoardIdx.size(0));
        b_board0[1] = static_cast<double>(board0->BoardIdx.size(1));
        b_board45[0] = static_cast<double>(board45->BoardIdx.size(0));
        b_board45[1] = static_cast<double>(board45->BoardIdx.size(1));
        if (isequal(b_board0, b_board45)) {
          b_N = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
          s.set_size(b_N);
          for (i = 0; i < b_N; i++) {
            s[i] = board0->BoardIdx[i];
          }
          N = 0;
          i = s.size(0);
          for (k = 0; k < i; k++) {
            if (s[k] != 0.0) {
              N++;
            }
          }
          b_N = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
          s.set_size(b_N);
          for (i = 0; i < b_N; i++) {
            s[i] = board45->BoardIdx[i];
          }
          b_N = 0;
          i = s.size(0);
          for (k = 0; k < i; k++) {
            if (s[k] != 0.0) {
              b_N++;
            }
          }
          if (N > b_N) {
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
      vision::internal::calibration::checkerboard::subPixelLocation(
          Ixy, imagePoints);
    }
    if (guard1 && (board45->isValid)) {
      board45 =
          vision::internal::calibration::checkerboard::orient(board45, c_I);
      vision::internal::calibration::checkerboard::toPoints(
          board45, imagePoints, boardSize);
      vision::internal::calibration::checkerboard::subPixelLocation(
          I_45_x, imagePoints);
    }
  }
}

} // namespace coder

//
// File trailer for detectCheckerboardPoints.cpp
//
// [EOF]
//
