//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "ITER_API_rtwutil.h"
#include "cat.h"
#include "flip.h"
#include "isequal.h"
#include "mean.h"
#include "rot90.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void cornerOrientations(const ::coder::array<float, 2U> &Ix2,
                               const ::coder::array<float, 2U> &Iy2,
                               const ::coder::array<float, 2U> &Ixy,
                               const float p[2], float b_v1[2], float v2[2]);

static void poly2RectMask(double d_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float b_u1);

// Function Definitions
//
// Arguments    : const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                const float p[2]
//                float b_v1[2]
//                float v2[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void cornerOrientations(const ::coder::array<float, 2U> &Ix2,
                               const ::coder::array<float, 2U> &Iy2,
                               const ::coder::array<float, 2U> &Ixy,
                               const float p[2], float b_v1[2], float v2[2])
{
  static const float b_fv[2][2]{{0.707106769F, 0.707106769F},
                                {-0.707106769F, 0.707106769F}};
  float b_cs1[2];
  float b_sn1[2];
  float ab;
  float adf;
  float b;
  float b_a;
  float b_cs;
  float b_f2;
  float b_tn;
  float c;
  float cs1;
  float df;
  float f;
  float f1;
  float f3;
  float rt;
  float sn1;
  float tb;
  int c_a;
  int sgn2;
  b_a = Ix2[((static_cast<int>(p[1])) +
             (Ix2.size(0) * ((static_cast<int>(p[0])) - 1))) -
            1];
  b = Ixy[((static_cast<int>(p[1])) +
           (Ixy.size(0) * ((static_cast<int>(p[0])) - 1))) -
          1];
  c = Iy2[((static_cast<int>(p[1])) +
           (Iy2.size(0) * ((static_cast<int>(p[0])) - 1))) -
          1];
  df = b_a - c;
  adf = std::abs(df);
  tb = b + b;
  ab = std::abs(tb);
  if (adf > ab) {
    rt = adf * std::sqrt(rt_powf_snf(ab / adf, 2.0F) + 1.0F);
  } else if (adf < ab) {
    rt = ab * std::sqrt(rt_powf_snf(adf / ab, 2.0F) + 1.0F);
  } else {
    rt = ab * 1.41421354F;
  }
  if (df > 0.0F) {
    b_cs = df + rt;
    sgn2 = 1;
  } else {
    b_cs = df - rt;
    sgn2 = -1;
  }
  if (std::abs(b_cs) > ab) {
    float b_ct;
    b_ct = (-tb) / b_cs;
    sn1 = 1.0F / std::sqrt((b_ct * b_ct) + 1.0F);
    cs1 = b_ct * sn1;
  } else if (ab == 0.0F) {
    cs1 = 1.0F;
    sn1 = 0.0F;
  } else {
    b_tn = (-b_cs) / tb;
    cs1 = 1.0F / std::sqrt((b_tn * b_tn) + 1.0F);
    sn1 = b_tn * cs1;
  }
  if ((b_a + c) < 0.0F) {
    c_a = -1;
  } else {
    c_a = 1;
  }
  if (c_a == sgn2) {
    b_tn = cs1;
    cs1 = -sn1;
    sn1 = b_tn;
  }
  b_sn1[0] = -sn1;
  b_sn1[1] = cs1;
  b_cs1[0] = cs1;
  b_cs1[1] = sn1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(f, f1,     \
                                                                    b_f2, f3)

  for (int b_i = 0; b_i < 2; b_i++) {
    b_f2 = b_fv[b_i][0];
    f3 = b_fv[b_i][1];
    f1 = (b_sn1[0] * b_f2) + (b_sn1[1] * f3);
    f = (b_cs1[0] * b_f2) + (b_cs1[1] * f3);
    v2[b_i] = f;
    b_v1[b_i] = f1;
  }
}

//
// Arguments    : double d_X[4]
//                double g_Y[4]
//                double height
//                double width
//                ::coder::array<bool, 2U> &mask
// Return Type  : void
//
static void poly2RectMask(double d_X[4], double g_Y[4], double height,
                          double width, ::coder::array<bool, 2U> &mask)
{
  int b_height[2];
  int b_iv[2];
  int b_loop_ub;
  int c_loop_ub;
  int d_loop_ub;
  int height_tmp;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i7;
  int loop_ub;
  ::coder::internal::d_sort(d_X);
  ::coder::internal::d_sort(g_Y);
  height_tmp = static_cast<int>(height);
  b_height[0] = static_cast<int>(height);
  mask.set_size(height_tmp, static_cast<int>(width));
  loop_ub = static_cast<int>(width);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2,        \
                                                                    b_loop_ub)

  for (int b_i = 0; b_i < loop_ub; b_i++) {
    b_loop_ub = b_height[0];
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      mask[i2 + (mask.size(0) * b_i)] = false;
    }
  }
  if (g_Y[1] > g_Y[2]) {
    i1 = 0;
    i3 = 0;
  } else {
    i1 = (static_cast<int>(g_Y[1])) - 1;
    i3 = static_cast<int>(g_Y[2]);
  }
  if (d_X[1] > d_X[2]) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = (static_cast<int>(d_X[1])) - 1;
    i5 = static_cast<int>(d_X[2]);
  }
  b_iv[0] = i3 - i1;
  b_iv[1] = i5 - i4;
  c_loop_ub = b_iv[1];
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i7,        \
                                                                    d_loop_ub)

  for (int i6 = 0; i6 < c_loop_ub; i6++) {
    d_loop_ub = b_iv[0];
    for (i7 = 0; i7 < d_loop_ub; i7++) {
      mask[(i1 + i7) + (mask.size(0) * (i4 + i6))] = true;
    }
  }
}

//
// Arguments    : float u0
//                float b_u1
// Return Type  : float
//
} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float b_u1)
{
  float y;
  if ((std::isnan(u0)) || (std::isnan(b_u1))) {
    y = rtNaNF;
  } else if ((std::isinf(u0)) && (std::isinf(b_u1))) {
    int b_u0;
    int c_u1;
    if (u0 > 0.0F) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }
    if (b_u1 > 0.0F) {
      c_u1 = 1;
    } else {
      c_u1 = -1;
    }
    y = std::atan2(static_cast<float>(b_u0), static_cast<float>(c_u1));
  } else if (b_u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, b_u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<float, 2U> &b_points
//                const ::coder::array<float, 1U> &scores
//                const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                double theta
//                b_Checkerboard *c_iobj_0
// Return Type  : b_Checkerboard *
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
b_Checkerboard *b_growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                   const ::coder::array<float, 1U> &scores,
                                   const ::coder::array<float, 2U> &Ix2,
                                   const ::coder::array<float, 2U> &Iy2,
                                   const ::coder::array<float, 2U> &Ixy,
                                   double theta, b_Checkerboard *c_iobj_0)
{
  b_Checkerboard *board;
  b_Checkerboard *currentBoard;
  b_Checkerboard *previousBoard;
  b_Checkerboard *tmpBoard;
  array<double, 2U> b_seedIdx;
  array<double, 2U> seedIdx;
  array<float, 1U> b_x;
  array<int, 1U> iidx;
  float b_v1[2];
  float g_x[2];
  float v2[2];
  if (scores.size(0) == 0) {
    c_iobj_0[0].isValid = false;
    c_iobj_0[0].Energy = rtInfF;
    c_iobj_0[0].IsDistortionHigh = false;
    board = &c_iobj_0[0];
    c_iobj_0[0].BoardIdx.set_size(1, 1);
    c_iobj_0[0].BoardIdx[0] = 0.0;
    c_iobj_0[0].BoardIdx.set_size(3, 3);
    for (int i2{0}; i2 < 3; i2++) {
      c_iobj_0[0].BoardIdx[c_iobj_0[0].BoardIdx.size(0) * i2] = 0.0;
      c_iobj_0[0].BoardIdx[(c_iobj_0[0].BoardIdx.size(0) * i2) + 1] = 0.0;
      c_iobj_0[0].BoardIdx[(c_iobj_0[0].BoardIdx.size(0) * i2) + 2] = 0.0;
    }
    c_iobj_0[0].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[0].BoardCoords[0] = 0.0;
    c_iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (int i3{0}; i3 < 2; i3++) {
      for (int i5{0}; i5 < 3; i5++) {
        c_iobj_0[0].BoardCoords[(c_iobj_0[0].BoardCoords.size(0) * i5) +
                                ((c_iobj_0[0].BoardCoords.size(0) *
                                  c_iobj_0[0].BoardCoords.size(1)) *
                                 i3)] = 0.0;
        c_iobj_0[0].BoardCoords[((c_iobj_0[0].BoardCoords.size(0) * i5) +
                                 ((c_iobj_0[0].BoardCoords.size(0) *
                                   c_iobj_0[0].BoardCoords.size(1)) *
                                  i3)) +
                                1] = 0.0;
        c_iobj_0[0].BoardCoords[((c_iobj_0[0].BoardCoords.size(0) * i5) +
                                 ((c_iobj_0[0].BoardCoords.size(0) *
                                   c_iobj_0[0].BoardCoords.size(1)) *
                                  i3)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[0].Points.set_size(1, 1);
    c_iobj_0[0].Points[0] = 0.0F;
    c_iobj_0[0].Points.set_size(0, 2);
  } else {
    int b_loop_ub;
    int c_loop_ub;
    int d_loop_ub;
    int i16;
    if (b_points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      int loop_ub;
      seedIdx.set_size(1, b_points.size(0));
      loop_ub = b_points.size(0) - 1;
      if ((static_cast<int>(b_points.size(0) < 4)) != 0) {
        for (int b_i{0}; b_i <= loop_ub; b_i++) {
          seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i = 0; b_i <= loop_ub; b_i++) {
          seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
        }
      }
    }
    b_x.set_size(seedIdx.size(1));
    b_loop_ub = seedIdx.size(1);
    if ((static_cast<int>(seedIdx.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_x[i1] = scores[(static_cast<int>(seedIdx[i1])) - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1] = scores[(static_cast<int>(seedIdx[i1])) - 1];
      }
    }
    ::coder::internal::sort(b_x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    c_loop_ub = iidx.size(0);
    if ((static_cast<int>(iidx.size(0) < 4)) != 0) {
      for (int i4{0}; i4 < c_loop_ub; i4++) {
        b_seedIdx[i4] = static_cast<double>(
            static_cast<unsigned int>(seedIdx[iidx[i4] - 1]));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < c_loop_ub; i4++) {
        b_seedIdx[i4] = static_cast<double>(
            static_cast<unsigned int>(seedIdx[iidx[i4] - 1]));
      }
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    d_loop_ub = b_seedIdx.size(1);
    if ((static_cast<int>(b_seedIdx.size(1) < 4)) != 0) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        seedIdx[i6] = b_seedIdx[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < d_loop_ub; i6++) {
        seedIdx[i6] = b_seedIdx[i6];
      }
    }
    if (iidx.size(0) > 2000) {
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int i7;
      i7 = static_cast<int>(std::fmin(
          2000.0, std::round((static_cast<double>(seedIdx.size(1))) / 2.0)));
      if (1 > i7) {
        e_loop_ub = 0;
      } else {
        e_loop_ub = i7;
      }
      b_seedIdx.set_size(1, e_loop_ub);
      f_loop_ub = e_loop_ub;
      if ((static_cast<int>(e_loop_ub < 4)) != 0) {
        for (int b_i8{0}; b_i8 < e_loop_ub; b_i8++) {
          b_seedIdx[b_i8] =
              static_cast<double>(static_cast<unsigned int>(seedIdx[b_i8]));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
          b_seedIdx[b_i8] =
              static_cast<double>(static_cast<unsigned int>(seedIdx[b_i8]));
        }
      }
      seedIdx.set_size(1, b_seedIdx.size(1));
      g_loop_ub = b_seedIdx.size(1);
      if ((static_cast<int>(b_seedIdx.size(1) < 4)) != 0) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          seedIdx[i11] = b_seedIdx[i11];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i11 = 0; i11 < g_loop_ub; i11++) {
          seedIdx[i11] = b_seedIdx[i11];
        }
      }
    }
    c_iobj_0[1].isValid = false;
    c_iobj_0[1].Energy = rtInfF;
    c_iobj_0[1].IsDistortionHigh = false;
    previousBoard = &c_iobj_0[1];
    c_iobj_0[1].BoardIdx.set_size(1, 1);
    c_iobj_0[1].BoardIdx[0] = 0.0;
    c_iobj_0[1].BoardIdx.set_size(3, 3);
    for (int i9{0}; i9 < 3; i9++) {
      c_iobj_0[1].BoardIdx[c_iobj_0[1].BoardIdx.size(0) * i9] = 0.0;
      c_iobj_0[1].BoardIdx[(c_iobj_0[1].BoardIdx.size(0) * i9) + 1] = 0.0;
      c_iobj_0[1].BoardIdx[(c_iobj_0[1].BoardIdx.size(0) * i9) + 2] = 0.0;
    }
    c_iobj_0[1].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[1].BoardCoords[0] = 0.0;
    c_iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (int i10{0}; i10 < 2; i10++) {
      for (int i12{0}; i12 < 3; i12++) {
        c_iobj_0[1].BoardCoords[(c_iobj_0[1].BoardCoords.size(0) * i12) +
                                ((c_iobj_0[1].BoardCoords.size(0) *
                                  c_iobj_0[1].BoardCoords.size(1)) *
                                 i10)] = 0.0;
        c_iobj_0[1].BoardCoords[((c_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((c_iobj_0[1].BoardCoords.size(0) *
                                   c_iobj_0[1].BoardCoords.size(1)) *
                                  i10)) +
                                1] = 0.0;
        c_iobj_0[1].BoardCoords[((c_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((c_iobj_0[1].BoardCoords.size(0) *
                                   c_iobj_0[1].BoardCoords.size(1)) *
                                  i10)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[1].Points.set_size(1, 1);
    c_iobj_0[1].Points[0] = 0.0F;
    c_iobj_0[1].Points.set_size(0, 2);
    c_iobj_0[1].IsDistortionHigh = false;
    c_iobj_0[2].isValid = false;
    c_iobj_0[2].Energy = rtInfF;
    c_iobj_0[2].IsDistortionHigh = false;
    currentBoard = &c_iobj_0[2];
    c_iobj_0[2].BoardIdx.set_size(1, 1);
    c_iobj_0[2].BoardIdx[0] = 0.0;
    c_iobj_0[2].BoardIdx.set_size(3, 3);
    for (int i13{0}; i13 < 3; i13++) {
      c_iobj_0[2].BoardIdx[c_iobj_0[2].BoardIdx.size(0) * i13] = 0.0;
      c_iobj_0[2].BoardIdx[(c_iobj_0[2].BoardIdx.size(0) * i13) + 1] = 0.0;
      c_iobj_0[2].BoardIdx[(c_iobj_0[2].BoardIdx.size(0) * i13) + 2] = 0.0;
    }
    c_iobj_0[2].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[2].BoardCoords[0] = 0.0;
    c_iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (int i14{0}; i14 < 2; i14++) {
      for (int i15{0}; i15 < 3; i15++) {
        c_iobj_0[2].BoardCoords[(c_iobj_0[2].BoardCoords.size(0) * i15) +
                                ((c_iobj_0[2].BoardCoords.size(0) *
                                  c_iobj_0[2].BoardCoords.size(1)) *
                                 i14)] = 0.0;
        c_iobj_0[2].BoardCoords[((c_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((c_iobj_0[2].BoardCoords.size(0) *
                                   c_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                1] = 0.0;
        c_iobj_0[2].BoardCoords[((c_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((c_iobj_0[2].BoardCoords.size(0) *
                                   c_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[2].Points.set_size(1, 1);
    c_iobj_0[2].Points[0] = 0.0F;
    c_iobj_0[2].Points.set_size(0, 2);
    c_iobj_0[2].IsDistortionHigh = false;
    i16 = seedIdx.size(1);
    for (int c_i{0}; c_i < i16; c_i++) {
      double d;
      bool guard1{false};
      d = seedIdx[c_i];
      g_x[0] = std::round(
          b_points[(static_cast<int>(static_cast<unsigned int>(d))) - 1]);
      g_x[1] = std::round(
          b_points[((static_cast<int>(static_cast<unsigned int>(d))) +
                    b_points.size(0)) -
                   1]);
      cornerOrientations(Ix2, Iy2, Ixy, g_x, b_v1, v2);
      guard1 = false;
      if ((static_cast<double>(
              std::abs(std::abs(std::abs(rt_atan2f_snf(b_v1[1], b_v1[0])) -
                                3.14159274F) -
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
            static_cast<double>(static_cast<unsigned int>(d)), b_points, b_v1,
            v2);
        if (currentBoard->isValid) {
          bool hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            hasExpanded = currentBoard->expandBoardOnce();
          }
        }
        if (currentBoard->Energy < previousBoard->Energy) {
          tmpBoard = previousBoard;
          previousBoard = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
    board = previousBoard;
    if (previousBoard->isValid) {
      previousBoard->expandPartialBoard();
    }
  }
  return board;
}

//
// Arguments    : const ::coder::array<float, 2U> &b_points
//                const ::coder::array<float, 1U> &scores
//                const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                double theta
//                b_Checkerboard *c_iobj_0
// Return Type  : b_Checkerboard *
//
b_Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &b_points,
                                 const ::coder::array<float, 1U> &scores,
                                 const ::coder::array<float, 2U> &Ix2,
                                 const ::coder::array<float, 2U> &Iy2,
                                 const ::coder::array<float, 2U> &Ixy,
                                 double theta, b_Checkerboard *c_iobj_0)
{
  b_Checkerboard *board;
  b_Checkerboard *currentBoard;
  b_Checkerboard *previousBoard;
  b_Checkerboard *tmpBoard;
  array<double, 2U> b_seedIdx;
  array<double, 2U> seedIdx;
  array<float, 1U> b_x;
  array<int, 1U> iidx;
  float b_v1[2];
  float g_x[2];
  float v2[2];
  if (scores.size(0) == 0) {
    c_iobj_0[0].isValid = false;
    c_iobj_0[0].Energy = rtInfF;
    c_iobj_0[0].IsDistortionHigh = false;
    board = &c_iobj_0[0];
    c_iobj_0[0].BoardIdx.set_size(1, 1);
    c_iobj_0[0].BoardIdx[0] = 0.0;
    c_iobj_0[0].BoardIdx.set_size(3, 3);
    for (int i2{0}; i2 < 3; i2++) {
      c_iobj_0[0].BoardIdx[c_iobj_0[0].BoardIdx.size(0) * i2] = 0.0;
      c_iobj_0[0].BoardIdx[(c_iobj_0[0].BoardIdx.size(0) * i2) + 1] = 0.0;
      c_iobj_0[0].BoardIdx[(c_iobj_0[0].BoardIdx.size(0) * i2) + 2] = 0.0;
    }
    c_iobj_0[0].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[0].BoardCoords[0] = 0.0;
    c_iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (int i3{0}; i3 < 2; i3++) {
      for (int i5{0}; i5 < 3; i5++) {
        c_iobj_0[0].BoardCoords[(c_iobj_0[0].BoardCoords.size(0) * i5) +
                                ((c_iobj_0[0].BoardCoords.size(0) *
                                  c_iobj_0[0].BoardCoords.size(1)) *
                                 i3)] = 0.0;
        c_iobj_0[0].BoardCoords[((c_iobj_0[0].BoardCoords.size(0) * i5) +
                                 ((c_iobj_0[0].BoardCoords.size(0) *
                                   c_iobj_0[0].BoardCoords.size(1)) *
                                  i3)) +
                                1] = 0.0;
        c_iobj_0[0].BoardCoords[((c_iobj_0[0].BoardCoords.size(0) * i5) +
                                 ((c_iobj_0[0].BoardCoords.size(0) *
                                   c_iobj_0[0].BoardCoords.size(1)) *
                                  i3)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[0].Points.set_size(1, 1);
    c_iobj_0[0].Points[0] = 0.0F;
    c_iobj_0[0].Points.set_size(0, 2);
  } else {
    int b_loop_ub;
    int c_loop_ub;
    int d_loop_ub;
    int i16;
    if (b_points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      int loop_ub;
      seedIdx.set_size(1, b_points.size(0));
      loop_ub = b_points.size(0) - 1;
      if ((static_cast<int>(b_points.size(0) < 4)) != 0) {
        for (int b_i{0}; b_i <= loop_ub; b_i++) {
          seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i = 0; b_i <= loop_ub; b_i++) {
          seedIdx[b_i] = (static_cast<double>(b_i)) + 1.0;
        }
      }
    }
    b_x.set_size(seedIdx.size(1));
    b_loop_ub = seedIdx.size(1);
    if ((static_cast<int>(seedIdx.size(1) < 4)) != 0) {
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_x[i1] = scores[(static_cast<int>(seedIdx[i1])) - 1];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        b_x[i1] = scores[(static_cast<int>(seedIdx[i1])) - 1];
      }
    }
    ::coder::internal::sort(b_x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    c_loop_ub = iidx.size(0);
    if ((static_cast<int>(iidx.size(0) < 4)) != 0) {
      for (int i4{0}; i4 < c_loop_ub; i4++) {
        b_seedIdx[i4] = static_cast<double>(
            static_cast<unsigned int>(seedIdx[iidx[i4] - 1]));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < c_loop_ub; i4++) {
        b_seedIdx[i4] = static_cast<double>(
            static_cast<unsigned int>(seedIdx[iidx[i4] - 1]));
      }
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    d_loop_ub = b_seedIdx.size(1);
    if ((static_cast<int>(b_seedIdx.size(1) < 4)) != 0) {
      for (int i6{0}; i6 < d_loop_ub; i6++) {
        seedIdx[i6] = b_seedIdx[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < d_loop_ub; i6++) {
        seedIdx[i6] = b_seedIdx[i6];
      }
    }
    if (iidx.size(0) > 2000) {
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int i7;
      i7 = static_cast<int>(std::fmin(
          2000.0, std::round((static_cast<double>(seedIdx.size(1))) / 2.0)));
      if (1 > i7) {
        e_loop_ub = 0;
      } else {
        e_loop_ub = i7;
      }
      b_seedIdx.set_size(1, e_loop_ub);
      f_loop_ub = e_loop_ub;
      if ((static_cast<int>(e_loop_ub < 4)) != 0) {
        for (int b_i8{0}; b_i8 < e_loop_ub; b_i8++) {
          b_seedIdx[b_i8] =
              static_cast<double>(static_cast<unsigned int>(seedIdx[b_i8]));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int b_i8 = 0; b_i8 < f_loop_ub; b_i8++) {
          b_seedIdx[b_i8] =
              static_cast<double>(static_cast<unsigned int>(seedIdx[b_i8]));
        }
      }
      seedIdx.set_size(1, b_seedIdx.size(1));
      g_loop_ub = b_seedIdx.size(1);
      if ((static_cast<int>(b_seedIdx.size(1) < 4)) != 0) {
        for (int i11{0}; i11 < g_loop_ub; i11++) {
          seedIdx[i11] = b_seedIdx[i11];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i11 = 0; i11 < g_loop_ub; i11++) {
          seedIdx[i11] = b_seedIdx[i11];
        }
      }
    }
    c_iobj_0[1].isValid = false;
    c_iobj_0[1].Energy = rtInfF;
    c_iobj_0[1].IsDistortionHigh = false;
    previousBoard = &c_iobj_0[1];
    c_iobj_0[1].BoardIdx.set_size(1, 1);
    c_iobj_0[1].BoardIdx[0] = 0.0;
    c_iobj_0[1].BoardIdx.set_size(3, 3);
    for (int i9{0}; i9 < 3; i9++) {
      c_iobj_0[1].BoardIdx[c_iobj_0[1].BoardIdx.size(0) * i9] = 0.0;
      c_iobj_0[1].BoardIdx[(c_iobj_0[1].BoardIdx.size(0) * i9) + 1] = 0.0;
      c_iobj_0[1].BoardIdx[(c_iobj_0[1].BoardIdx.size(0) * i9) + 2] = 0.0;
    }
    c_iobj_0[1].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[1].BoardCoords[0] = 0.0;
    c_iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (int i10{0}; i10 < 2; i10++) {
      for (int i12{0}; i12 < 3; i12++) {
        c_iobj_0[1].BoardCoords[(c_iobj_0[1].BoardCoords.size(0) * i12) +
                                ((c_iobj_0[1].BoardCoords.size(0) *
                                  c_iobj_0[1].BoardCoords.size(1)) *
                                 i10)] = 0.0;
        c_iobj_0[1].BoardCoords[((c_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((c_iobj_0[1].BoardCoords.size(0) *
                                   c_iobj_0[1].BoardCoords.size(1)) *
                                  i10)) +
                                1] = 0.0;
        c_iobj_0[1].BoardCoords[((c_iobj_0[1].BoardCoords.size(0) * i12) +
                                 ((c_iobj_0[1].BoardCoords.size(0) *
                                   c_iobj_0[1].BoardCoords.size(1)) *
                                  i10)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[1].Points.set_size(1, 1);
    c_iobj_0[1].Points[0] = 0.0F;
    c_iobj_0[1].Points.set_size(0, 2);
    c_iobj_0[1].IsDistortionHigh = false;
    c_iobj_0[2].isValid = false;
    c_iobj_0[2].Energy = rtInfF;
    c_iobj_0[2].IsDistortionHigh = false;
    currentBoard = &c_iobj_0[2];
    c_iobj_0[2].BoardIdx.set_size(1, 1);
    c_iobj_0[2].BoardIdx[0] = 0.0;
    c_iobj_0[2].BoardIdx.set_size(3, 3);
    for (int i13{0}; i13 < 3; i13++) {
      c_iobj_0[2].BoardIdx[c_iobj_0[2].BoardIdx.size(0) * i13] = 0.0;
      c_iobj_0[2].BoardIdx[(c_iobj_0[2].BoardIdx.size(0) * i13) + 1] = 0.0;
      c_iobj_0[2].BoardIdx[(c_iobj_0[2].BoardIdx.size(0) * i13) + 2] = 0.0;
    }
    c_iobj_0[2].BoardCoords.set_size(1, 1, 1);
    c_iobj_0[2].BoardCoords[0] = 0.0;
    c_iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (int i14{0}; i14 < 2; i14++) {
      for (int i15{0}; i15 < 3; i15++) {
        c_iobj_0[2].BoardCoords[(c_iobj_0[2].BoardCoords.size(0) * i15) +
                                ((c_iobj_0[2].BoardCoords.size(0) *
                                  c_iobj_0[2].BoardCoords.size(1)) *
                                 i14)] = 0.0;
        c_iobj_0[2].BoardCoords[((c_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((c_iobj_0[2].BoardCoords.size(0) *
                                   c_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                1] = 0.0;
        c_iobj_0[2].BoardCoords[((c_iobj_0[2].BoardCoords.size(0) * i15) +
                                 ((c_iobj_0[2].BoardCoords.size(0) *
                                   c_iobj_0[2].BoardCoords.size(1)) *
                                  i14)) +
                                2] = 0.0;
      }
    }
    c_iobj_0[2].Points.set_size(1, 1);
    c_iobj_0[2].Points[0] = 0.0F;
    c_iobj_0[2].Points.set_size(0, 2);
    c_iobj_0[2].IsDistortionHigh = false;
    i16 = seedIdx.size(1);
    for (int c_i{0}; c_i < i16; c_i++) {
      double d;
      bool guard1{false};
      d = seedIdx[c_i];
      g_x[0] = std::round(
          b_points[(static_cast<int>(static_cast<unsigned int>(d))) - 1]);
      g_x[1] = std::round(
          b_points[((static_cast<int>(static_cast<unsigned int>(d))) +
                    b_points.size(0)) -
                   1]);
      cornerOrientations(Ix2, Iy2, Ixy, g_x, b_v1, v2);
      guard1 = false;
      if ((static_cast<double>(
              std::abs(std::abs(std::abs(rt_atan2f_snf(b_v1[1], b_v1[0])) -
                                3.14159274F) -
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
            static_cast<double>(static_cast<unsigned int>(d)), b_points, b_v1,
            v2);
        if (currentBoard->isValid) {
          bool hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            hasExpanded = currentBoard->expandBoardOnce();
          }
        }
        if (currentBoard->Energy < previousBoard->Energy) {
          tmpBoard = previousBoard;
          previousBoard = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
    board = previousBoard;
  }
  return board;
}

//
// Arguments    : b_Checkerboard *board
//                const ::coder::array<float, 2U> &o_I
// Return Type  : b_Checkerboard *
//
b_Checkerboard *orient(b_Checkerboard *board,
                       const ::coder::array<float, 2U> &o_I)
{
  b_Checkerboard *b_board;
  array<double, 3U> r1;
  array<double, 3U> r6;
  array<double, 3U> r7;
  array<double, 2U> c_board;
  array<double, 2U> d_board;
  array<double, 2U> e_board;
  array<double, 2U> g_x;
  array<double, 2U> h_board;
  array<double, 2U> i_board;
  array<double, 2U> newBoardCoords1;
  array<double, 2U> newBoardCoords2;
  array<double, 2U> numRot;
  array<double, 2U> r;
  array<double, 2U> r3;
  array<double, 2U> r5;
  array<double, 2U> r8;
  array<double, 2U> r9;
  array<float, 1U> fb_I;
  array<float, 1U> p_I;
  array<int, 1U> r2;
  array<int, 1U> r4;
  array<signed char, 2U> c_ii;
  array<bool, 3U> p_x;
  array<bool, 2U> j_x;
  array<bool, 2U> nextSquareMask;
  array<bool, 2U> upperLeftMask;
  array<bool, 2U> y;
  double cornerIdx[4];
  double nextSquarePolyX[4];
  double nextSquarePolyY[4];
  double upperLeftPolyX[4];
  double upperLeftPolyY[4];
  float b_x;
  b_board = board;
  b_x = b_board->Energy;
  if (!std::isinf(b_x)) {
    int b_hi;
    int b_loop_ub;
    int b_r;
    int d_r;
    int g_loop_ub;
    int k_x;
    int o_x;
    int szy_idx_1;
    bool b_y;
    bool exitg1;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      int e_loop_ub;
      int f_loop_ub;
      int h_loop_ub;
      int i_loop_ub;
      int j_loop_ub;
      int loop_ub;
      c_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(1) - 1;
      for (int b_i{0}; b_i <= loop_ub; b_i++) {
        int c_loop_ub;
        c_loop_ub = b_board->BoardIdx.size(0) - 1;
        for (int i2{0}; i2 <= c_loop_ub; i2++) {
          c_board[i2 + (c_board.size(0) * b_i)] =
              b_board->BoardIdx[i2 + (b_board->BoardIdx.size(0) * b_i)];
        }
      }
      rot90(c_board, b_board->BoardIdx);
      e_loop_ub = b_board->BoardCoords.size(0);
      f_loop_ub = b_board->BoardCoords.size(1);
      d_board.set_size(e_loop_ub, f_loop_ub);
      for (int i4{0}; i4 < f_loop_ub; i4++) {
        for (int i6{0}; i6 < e_loop_ub; i6++) {
          d_board[i6 + (d_board.size(0) * i4)] =
              b_board->BoardCoords[i6 + (b_board->BoardCoords.size(0) * i4)];
        }
      }
      rot90(d_board, newBoardCoords1);
      h_loop_ub = b_board->BoardCoords.size(0);
      i_loop_ub = b_board->BoardCoords.size(1);
      d_board.set_size(h_loop_ub, i_loop_ub);
      for (int i7{0}; i7 < i_loop_ub; i7++) {
        for (int b_i8{0}; b_i8 < h_loop_ub; b_i8++) {
          d_board[b_i8 + (d_board.size(0) * i7)] =
              b_board
                  ->BoardCoords[(b_i8 + (b_board->BoardCoords.size(0) * i7)) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))];
        }
      }
      rot90(d_board, r);
      cat(newBoardCoords1, r, r1);
      b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
      j_loop_ub = r1.size(1);
      for (int i9{0}; i9 < 2; i9++) {
        for (int i10{0}; i10 < j_loop_ub; i10++) {
          int k_loop_ub;
          k_loop_ub = r1.size(0);
          for (int i11{0}; i11 < k_loop_ub; i11++) {
            b_board->BoardCoords[(i11 + (b_board->BoardCoords.size(0) * i10)) +
                                 ((b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)) *
                                  i9)] = r1[(i11 + (r1.size(0) * i10)) +
                                            ((r1.size(0) * r1.size(1)) * i9)];
          }
        }
      }
    }
    g_x.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
    b_loop_ub = b_board->BoardIdx.size(1);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      int d_loop_ub;
      d_loop_ub = b_board->BoardIdx.size(0);
      for (int i3{0}; i3 < d_loop_ub; i3++) {
        g_x[i3 + (g_x.size(0) * i1)] =
            b_board->BoardIdx[i3 + (b_board->BoardIdx.size(0) * i1)];
      }
    }
    szy_idx_1 = g_x.size(1);
    y.set_size(1, g_x.size(1));
    g_loop_ub = g_x.size(1);
    if ((static_cast<int>(g_x.size(1) < 4)) != 0) {
      for (int i5{0}; i5 < szy_idx_1; i5++) {
        y[i5] = false;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < g_loop_ub; i5++) {
        y[i5] = false;
      }
    }
    b_hi = g_x.size(1);
    for (int k{0}; k < b_hi; k++) {
      int b_k;
      y[k] = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= (g_x.size(0) - 1))) {
        if (g_x[b_k + (g_x.size(0) * k)] == 0.0) {
          y[k] = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }
    b_y = (y.size(1) != 0);
    if (b_y) {
      int c_k;
      c_k = 0;
      exitg1 = false;
      while ((!exitg1) && (c_k <= (y.size(1) - 1))) {
        if (!y[c_k]) {
          b_y = false;
          exitg1 = true;
        } else {
          c_k++;
        }
      }
    }
    if (b_y) {
      int b_end;
      int b_partialTrueCount;
      int b_trueCount;
      int bb_loop_ub;
      int end;
      int gb_loop_ub;
      int partialTrueCount;
      int trueCount;
      upperLeftPolyX[0] = b_board->BoardCoords[0];
      upperLeftPolyX[1] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      upperLeftPolyX[2] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      upperLeftPolyX[3] = b_board->BoardCoords[1];
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
      poly2RectMask(upperLeftPolyX, upperLeftPolyY,
                    static_cast<double>(o_I.size(0)),
                    static_cast<double>(o_I.size(1)), upperLeftMask);
      nextSquarePolyX[0] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      nextSquarePolyX[1] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) * 2];
      nextSquarePolyX[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) + 1];
      nextSquarePolyX[3] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      nextSquarePolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) +
                                                (b_board->BoardCoords.size(0) *
                                                 b_board->BoardCoords.size(1))];
      nextSquarePolyY[1] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2) +
                               (b_board->BoardCoords.size(0) *
                                b_board->BoardCoords.size(1))];
      nextSquarePolyY[2] =
          b_board->BoardCoords[((b_board->BoardCoords.size(0) * 2) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      nextSquarePolyY[3] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                (b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1))) +
                               1];
      poly2RectMask(nextSquarePolyX, nextSquarePolyY,
                    static_cast<double>(o_I.size(0)),
                    static_cast<double>(o_I.size(1)), nextSquareMask);
      end = (upperLeftMask.size(0) * upperLeftMask.size(1)) - 1;
      trueCount = 0;
      for (int c_i{0}; c_i <= end; c_i++) {
        if (upperLeftMask[c_i]) {
          trueCount++;
        }
      }
      r2.set_size(trueCount);
      partialTrueCount = 0;
      for (int d_i{0}; d_i <= end; d_i++) {
        if (upperLeftMask[d_i]) {
          r2[partialTrueCount] = d_i + 1;
          partialTrueCount++;
        }
      }
      b_end = (nextSquareMask.size(0) * nextSquareMask.size(1)) - 1;
      b_trueCount = 0;
      for (int e_i{0}; e_i <= b_end; e_i++) {
        if (nextSquareMask[e_i]) {
          b_trueCount++;
        }
      }
      r4.set_size(b_trueCount);
      b_partialTrueCount = 0;
      for (int g_i{0}; g_i <= b_end; g_i++) {
        if (nextSquareMask[g_i]) {
          r4[b_partialTrueCount] = g_i + 1;
          b_partialTrueCount++;
        }
      }
      p_I.set_size(r2.size(0));
      bb_loop_ub = r2.size(0);
      if ((static_cast<int>(r2.size(0) < 4)) != 0) {
        for (int i24{0}; i24 < bb_loop_ub; i24++) {
          p_I[i24] = o_I[r2[i24] - 1];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i24 = 0; i24 < bb_loop_ub; i24++) {
          p_I[i24] = o_I[r2[i24] - 1];
        }
      }
      fb_I.set_size(r4.size(0));
      gb_loop_ub = r4.size(0);
      if ((static_cast<int>(r4.size(0) < 4)) != 0) {
        for (int i30{0}; i30 < gb_loop_ub; i30++) {
          fb_I[i30] = o_I[r4[i30] - 1];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i30 = 0; i30 < gb_loop_ub; i30++) {
          fb_I[i30] = o_I[r4[i30] - 1];
        }
      }
      if (!(b_mean(p_I) < b_mean(fb_I))) {
        int mb_loop_ub;
        int pb_loop_ub;
        int rb_loop_ub;
        int sb_loop_ub;
        int tb_loop_ub;
        int xb_loop_ub;
        h_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
        mb_loop_ub = b_board->BoardIdx.size(1) - 1;
        for (int i35{0}; i35 <= mb_loop_ub; i35++) {
          int ob_loop_ub;
          ob_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (int i38{0}; i38 <= ob_loop_ub; i38++) {
            h_board[i38 + (h_board.size(0) * i35)] =
                b_board->BoardIdx[i38 + (b_board->BoardIdx.size(0) * i35)];
          }
        }
        b_rot90(h_board, b_board->BoardIdx);
        pb_loop_ub = b_board->BoardCoords.size(0);
        rb_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(pb_loop_ub, rb_loop_ub);
        for (int i40{0}; i40 < rb_loop_ub; i40++) {
          for (int i41{0}; i41 < pb_loop_ub; i41++) {
            d_board[i41 + (d_board.size(0) * i40)] =
                b_board
                    ->BoardCoords[i41 + (b_board->BoardCoords.size(0) * i40)];
          }
        }
        b_rot90(d_board, newBoardCoords1);
        sb_loop_ub = b_board->BoardCoords.size(0);
        tb_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(sb_loop_ub, tb_loop_ub);
        for (int i42{0}; i42 < tb_loop_ub; i42++) {
          for (int i44{0}; i44 < sb_loop_ub; i44++) {
            d_board[i44 + (d_board.size(0) * i42)] =
                b_board
                    ->BoardCoords[(i44 + (b_board->BoardCoords.size(0) * i42)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(d_board, r8);
        cat(newBoardCoords1, r8, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        xb_loop_ub = r1.size(1);
        for (int i46{0}; i46 < 2; i46++) {
          for (int i48{0}; i48 < xb_loop_ub; i48++) {
            int ac_loop_ub;
            ac_loop_ub = r1.size(0);
            for (int i50{0}; i50 < ac_loop_ub; i50++) {
              b_board
                  ->BoardCoords[(i50 + (b_board->BoardCoords.size(0) * i48)) +
                                ((b_board->BoardCoords.size(0) *
                                  b_board->BoardCoords.size(1)) *
                                 i46)] = r1[(i50 + (r1.size(0) * i48)) +
                                            ((r1.size(0) * r1.size(1)) * i46)];
            }
          }
        }
      }
    } else {
      int e_ii;
      int idx;
      int m_loop_ub;
      cornerIdx[0] = b_board->BoardIdx[0];
      cornerIdx[1] = b_board->BoardIdx[b_board->BoardIdx.size(0) - 1];
      cornerIdx[2] = b_board->BoardIdx[(b_board->BoardIdx.size(0) +
                                        (b_board->BoardIdx.size(0) *
                                         (b_board->BoardIdx.size(1) - 1))) -
                                       1];
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) *
                                       (b_board->BoardIdx.size(1) - 1)];
      idx = 0;
      c_ii.set_size(1, 1);
      e_ii = 0;
      exitg1 = false;
      while ((!exitg1) && (e_ii < 4)) {
        if (cornerIdx[e_ii] != 0.0) {
          idx = 1;
          c_ii[0] = static_cast<signed char>(e_ii + 1);
          exitg1 = true;
        } else {
          e_ii++;
        }
      }
      if (idx == 0) {
        c_ii.set_size(1, 0);
      }
      numRot.set_size(1, c_ii.size(1));
      m_loop_ub = c_ii.size(1);
      for (int i12{0}; i12 < m_loop_ub; i12++) {
        numRot[0] = (static_cast<double>(c_ii[0])) - 1.0;
      }
      if (c_ii.size(1) == 0) {
        numRot.set_size(1, 1);
        numRot[0] = 0.0;
      }
      j_x.set_size(1, 1);
      j_x[0] = (numRot[0] == 2.0);
      if (!j_x[0]) {
        int direction;
        if (c_isequal(numRot, 1.0)) {
          direction = 1;
        } else if (c_isequal(numRot, 3.0)) {
          direction = 2;
        } else {
          direction = 0;
        }
        if (direction != 0) {
          int ab_loop_ub;
          int eb_loop_ub;
          int fb_loop_ub;
          int kb_loop_ub;
          int r_loop_ub;
          int u_loop_ub;
          int x_loop_ub;
          r3.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
          r_loop_ub = b_board->BoardIdx.size(1);
          for (int i15{0}; i15 < r_loop_ub; i15++) {
            int t_loop_ub;
            t_loop_ub = b_board->BoardIdx.size(0);
            for (int i17{0}; i17 < t_loop_ub; i17++) {
              r3[i17 + (r3.size(0) * i15)] =
                  b_board->BoardIdx[i17 + (b_board->BoardIdx.size(0) * i15)];
            }
          }
          flip(r3, static_cast<double>(direction));
          b_board->BoardIdx.set_size(r3.size(0), r3.size(1));
          u_loop_ub = r3.size(1);
          for (int i19{0}; i19 < u_loop_ub; i19++) {
            int y_loop_ub;
            y_loop_ub = r3.size(0);
            for (int i21{0}; i21 < y_loop_ub; i21++) {
              b_board->BoardIdx[i21 + (b_board->BoardIdx.size(0) * i19)] =
                  r3[i21 + (r3.size(0) * i19)];
            }
          }
          x_loop_ub = b_board->BoardCoords.size(0);
          ab_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(x_loop_ub, ab_loop_ub);
          for (int i23{0}; i23 < ab_loop_ub; i23++) {
            for (int i26{0}; i26 < x_loop_ub; i26++) {
              newBoardCoords1[i26 + (newBoardCoords1.size(0) * i23)] =
                  b_board
                      ->BoardCoords[i26 + (b_board->BoardCoords.size(0) * i23)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(direction));
          eb_loop_ub = b_board->BoardCoords.size(0);
          fb_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(eb_loop_ub, fb_loop_ub);
          for (int i29{0}; i29 < fb_loop_ub; i29++) {
            for (int i32{0}; i32 < eb_loop_ub; i32++) {
              newBoardCoords2[i32 + (newBoardCoords2.size(0) * i29)] =
                  b_board->BoardCoords[(i32 +
                                        (b_board->BoardCoords.size(0) * i29)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          flip(newBoardCoords2, static_cast<double>(direction));
          cat(newBoardCoords1, newBoardCoords2, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          kb_loop_ub = r1.size(1);
          for (int i34{0}; i34 < 2; i34++) {
            for (int i37{0}; i37 < kb_loop_ub; i37++) {
              int qb_loop_ub;
              qb_loop_ub = r1.size(0);
              for (int i39{0}; i39 < qb_loop_ub; i39++) {
                b_board
                    ->BoardCoords[(i39 + (b_board->BoardCoords.size(0) * i37)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i34)] =
                    r1[(i39 + (r1.size(0) * i37)) +
                       ((r1.size(0) * r1.size(1)) * i34)];
              }
            }
          }
        }
      } else {
        int db_loop_ub;
        int o_loop_ub;
        int q_loop_ub;
        int s_loop_ub;
        int v_loop_ub;
        int w_loop_ub;
        e_board.set_size(b_board->BoardIdx.size(0), b_board->BoardIdx.size(1));
        o_loop_ub = b_board->BoardIdx.size(1) - 1;
        for (int i13{0}; i13 <= o_loop_ub; i13++) {
          int p_loop_ub;
          p_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (int i14{0}; i14 <= p_loop_ub; i14++) {
            e_board[i14 + (e_board.size(0) * i13)] =
                b_board->BoardIdx[i14 + (b_board->BoardIdx.size(0) * i13)];
          }
        }
        b_rot90(e_board, b_board->BoardIdx);
        q_loop_ub = b_board->BoardCoords.size(0);
        s_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(q_loop_ub, s_loop_ub);
        for (int i16{0}; i16 < s_loop_ub; i16++) {
          for (int i18{0}; i18 < q_loop_ub; i18++) {
            d_board[i18 + (d_board.size(0) * i16)] =
                b_board
                    ->BoardCoords[i18 + (b_board->BoardCoords.size(0) * i16)];
          }
        }
        b_rot90(d_board, newBoardCoords1);
        v_loop_ub = b_board->BoardCoords.size(0);
        w_loop_ub = b_board->BoardCoords.size(1);
        d_board.set_size(v_loop_ub, w_loop_ub);
        for (int i20{0}; i20 < w_loop_ub; i20++) {
          for (int i22{0}; i22 < v_loop_ub; i22++) {
            d_board[i22 + (d_board.size(0) * i20)] =
                b_board
                    ->BoardCoords[(i22 + (b_board->BoardCoords.size(0) * i20)) +
                                  (b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(d_board, r5);
        cat(newBoardCoords1, r5, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        db_loop_ub = r1.size(1);
        for (int i27{0}; i27 < 2; i27++) {
          for (int i28{0}; i28 < db_loop_ub; i28++) {
            int ib_loop_ub;
            ib_loop_ub = r1.size(0);
            for (int i33{0}; i33 < ib_loop_ub; i33++) {
              b_board
                  ->BoardCoords[(i33 + (b_board->BoardCoords.size(0) * i28)) +
                                ((b_board->BoardCoords.size(0) *
                                  b_board->BoardCoords.size(1)) *
                                 i27)] = r1[(i33 + (r1.size(0) * i28)) +
                                            ((r1.size(0) * r1.size(1)) * i27)];
            }
          }
        }
      }
    }
    k_x = b_board->BoardCoords.size(0);
    if (k_x == 0) {
      b_r = 0;
    } else {
      b_r = static_cast<int>(std::fmod(static_cast<double>(k_x), 2.0));
      if (b_r == 0) {
        b_r = 0;
      } else if (k_x < 0) {
        b_r += 2;
      } else {
        /* no actions */
      }
    }
    o_x = b_board->BoardCoords.size(1);
    if (o_x == 0) {
      d_r = 0;
    } else {
      d_r = static_cast<int>(std::fmod(static_cast<double>(o_x), 2.0));
      if (d_r == 0) {
        d_r = 0;
      } else if (o_x < 0) {
        d_r += 2;
      } else {
        /* no actions */
      }
    }
    if ((b_r == 0) == (d_r == 0)) {
      int cb_loop_ub;
      int d_k;
      int f_board;
      int g_board;
      int hb_loop_ub;
      int jb_loop_ub;
      bool c_y;
      cb_loop_ub = b_board->BoardCoords.size(2);
      r6.set_size(1, 1, cb_loop_ub);
      for (int i25{0}; i25 < cb_loop_ub; i25++) {
        r6[i25] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1)) *
                                       i25];
      }
      f_board = b_board->BoardCoords.size(0);
      g_board = b_board->BoardCoords.size(1);
      hb_loop_ub = b_board->BoardCoords.size(2);
      r7.set_size(1, 1, hb_loop_ub);
      for (int i31{0}; i31 < hb_loop_ub; i31++) {
        r7[i31] =
            b_board->BoardCoords[((f_board + (b_board->BoardCoords.size(0) *
                                              (g_board - 1))) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i31)) -
                                 1];
      }
      p_x.set_size(1, 1, r6.size(2));
      jb_loop_ub = r6.size(2);
      if ((static_cast<int>(r6.size(2) < 4)) != 0) {
        for (int i36{0}; i36 < jb_loop_ub; i36++) {
          p_x[i36] = (r6[i36] > r7[i36]);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i36 = 0; i36 < jb_loop_ub; i36++) {
          p_x[i36] = (r6[i36] > r7[i36]);
        }
      }
      c_y = false;
      d_k = 0;
      exitg1 = false;
      while ((!exitg1) && (d_k <= (p_x.size(2) - 1))) {
        if (p_x[d_k]) {
          c_y = true;
          exitg1 = true;
        } else {
          d_k++;
        }
      }
      if (c_y) {
        double q_x;
        q_x = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                    (b_board->BoardCoords.size(0) *
                                     (b_board->BoardCoords.size(1) - 1))) -
                                   1];
        if (q_x != 0.0) {
          int bc_loop_ub;
          int cc_loop_ub;
          int dc_loop_ub;
          int ub_loop_ub;
          int wb_loop_ub;
          int yb_loop_ub;
          i_board.set_size(b_board->BoardIdx.size(0),
                           b_board->BoardIdx.size(1));
          ub_loop_ub = b_board->BoardIdx.size(1) - 1;
          for (int i43{0}; i43 <= ub_loop_ub; i43++) {
            int vb_loop_ub;
            vb_loop_ub = b_board->BoardIdx.size(0) - 1;
            for (int i45{0}; i45 <= vb_loop_ub; i45++) {
              i_board[i45 + (i_board.size(0) * i43)] =
                  b_board->BoardIdx[i45 + (b_board->BoardIdx.size(0) * i43)];
            }
          }
          b_rot90(i_board, b_board->BoardIdx);
          wb_loop_ub = b_board->BoardCoords.size(0);
          yb_loop_ub = b_board->BoardCoords.size(1);
          d_board.set_size(wb_loop_ub, yb_loop_ub);
          for (int i47{0}; i47 < yb_loop_ub; i47++) {
            for (int i49{0}; i49 < wb_loop_ub; i49++) {
              d_board[i49 + (d_board.size(0) * i47)] =
                  b_board
                      ->BoardCoords[i49 + (b_board->BoardCoords.size(0) * i47)];
            }
          }
          b_rot90(d_board, newBoardCoords1);
          bc_loop_ub = b_board->BoardCoords.size(0);
          cc_loop_ub = b_board->BoardCoords.size(1);
          d_board.set_size(bc_loop_ub, cc_loop_ub);
          for (int i51{0}; i51 < cc_loop_ub; i51++) {
            for (int i52{0}; i52 < bc_loop_ub; i52++) {
              d_board[i52 + (d_board.size(0) * i51)] =
                  b_board->BoardCoords[(i52 +
                                        (b_board->BoardCoords.size(0) * i51)) +
                                       (b_board->BoardCoords.size(0) *
                                        b_board->BoardCoords.size(1))];
            }
          }
          b_rot90(d_board, r9);
          cat(newBoardCoords1, r9, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          dc_loop_ub = r1.size(1);
          for (int i53{0}; i53 < 2; i53++) {
            for (int i54{0}; i54 < dc_loop_ub; i54++) {
              int ec_loop_ub;
              ec_loop_ub = r1.size(0);
              for (int i55{0}; i55 < ec_loop_ub; i55++) {
                b_board
                    ->BoardCoords[(i55 + (b_board->BoardCoords.size(0) * i54)) +
                                  ((b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) *
                                   i53)] =
                    r1[(i55 + (r1.size(0) * i54)) +
                       ((r1.size(0) * r1.size(1)) * i53)];
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
//                double boardSize[2]
// Return Type  : void
//
void toPoints(const b_Checkerboard *b_this,
              ::coder::array<double, 2U> &b_points, double boardSize[2])
{
  array<double, 2U> g_x;
  array<double, 2U> y;
  array<bool, 1U> b_x;
  int d_this;
  int i2;
  int i5;
  int i9;
  int k;
  int loop_ub;
  bool exitg1;
  bool varargout_1;
  d_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  b_x.set_size(d_this);
  loop_ub = d_this;
  if ((static_cast<int>(d_this < 4)) != 0) {
    for (int b_i{0}; b_i < d_this; b_i++) {
      b_x[b_i] = (b_this->BoardIdx[b_i] == 0.0);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      b_x[b_i] = (b_this->BoardIdx[b_i] == 0.0);
    }
  }
  varargout_1 = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= (b_x.size(0) - 1))) {
    if (b_x[k]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (varargout_1) {
    b_points.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    double numPoints;
    int b_loop_ub;
    int b_y;
    int c_loop_ub;
    int d_loop_ub;
    int e_loop_ub;
    int f_loop_ub;
    int g_loop_ub;
    int h_loop_ub;
    int i3;
    int i7;
    int j_x;
    numPoints = (static_cast<double>(b_this->BoardCoords.size(0))) *
                (static_cast<double>(b_this->BoardCoords.size(1)));
    b_points.set_size(static_cast<int>(numPoints), 2);
    b_loop_ub = static_cast<int>(numPoints);
    if ((static_cast<int>(
            ((static_cast<int>(static_cast<double>(
                 (static_cast<double>(b_this->BoardCoords.size(0))) *
                 (static_cast<double>(b_this->BoardCoords.size(1)))))) *
             2) < 4)) != 0) {
      for (int i1{0}; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_points[i2 + (b_points.size(0) * i1)] = 0.0;
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

      for (int i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_points[i2 + (b_points.size(0) * i1)] = 0.0;
        }
      }
    }
    i3 = b_this->BoardCoords.size(0);
    c_loop_ub = b_this->BoardCoords.size(1);
    g_x.set_size(c_loop_ub, i3);
    d_loop_ub = i3;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i5)

    for (int i4 = 0; i4 < d_loop_ub; i4++) {
      for (i5 = 0; i5 < c_loop_ub; i5++) {
        g_x[i5 + (g_x.size(0) * i4)] =
            b_this->BoardCoords[i4 + (b_this->BoardCoords.size(0) * i5)];
      }
    }
    j_x = g_x.size(0) * g_x.size(1);
    e_loop_ub = j_x;
    if ((static_cast<int>(j_x < 4)) != 0) {
      for (int i6{0}; i6 < j_x; i6++) {
        b_points[i6] = g_x[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < e_loop_ub; i6++) {
        b_points[i6] = g_x[i6];
      }
    }
    i7 = b_this->BoardCoords.size(0);
    f_loop_ub = b_this->BoardCoords.size(1);
    y.set_size(f_loop_ub, i7);
    g_loop_ub = i7;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i9)

    for (int b_i8 = 0; b_i8 < g_loop_ub; b_i8++) {
      for (i9 = 0; i9 < f_loop_ub; i9++) {
        y[i9 + (y.size(0) * b_i8)] =
            b_this->BoardCoords[(b_i8 + (b_this->BoardCoords.size(0) * i9)) +
                                (b_this->BoardCoords.size(0) *
                                 b_this->BoardCoords.size(1))];
      }
    }
    b_y = y.size(0) * y.size(1);
    h_loop_ub = b_y;
    if ((static_cast<int>(b_y < 4)) != 0) {
      for (int i10{0}; i10 < b_y; i10++) {
        b_points[i10 + b_points.size(0)] = y[i10];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i10 = 0; i10 < h_loop_ub; i10++) {
        b_points[i10 + b_points.size(0)] = y[i10];
      }
    }
    boardSize[0] = (static_cast<double>(b_this->BoardCoords.size(1))) + 1.0;
    boardSize[1] = (static_cast<double>(b_this->BoardCoords.size(0))) + 1.0;
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
