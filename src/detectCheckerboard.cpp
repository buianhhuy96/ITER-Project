//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: detectCheckerboard.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "calibrateHandeye_rtwutil.h"
#include "cat.h"
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
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double b_X[4], double Y[4], double height,
                          double width, ::coder::array<boolean_T, 2U> &mask);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
static float rt_atan2f_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : double b_X[4]
//                double Y[4]
//                double height
//                double width
//                ::coder::array<boolean_T, 2U> &mask
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(double b_X[4], double Y[4], double height,
                          double width, ::coder::array<boolean_T, 2U> &mask)
{
  int b_loop_ub_tmp;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int loop_ub_tmp;
  ::coder::internal::sort(b_X);
  ::coder::internal::sort(Y);
  loop_ub_tmp = static_cast<int>(height);
  b_loop_ub_tmp = static_cast<int>(width);
  mask.set_size(loop_ub_tmp, b_loop_ub_tmp);
  for (i = 0; i < b_loop_ub_tmp; i++) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      mask[i1 + (mask.size(0) * i)] = false;
    }
  }
  if (Y[1] > Y[2]) {
    i = 0;
    i1 = 0;
  } else {
    i = (static_cast<int>(Y[1])) - 1;
    i1 = static_cast<int>(Y[2]);
  }
  if (b_X[1] > b_X[2]) {
    loop_ub_tmp = 0;
    i2 = 0;
  } else {
    loop_ub_tmp = (static_cast<int>(b_X[1])) - 1;
    i2 = static_cast<int>(b_X[2]);
  }
  b_loop_ub_tmp = i1 - i;
  loop_ub = i2 - loop_ub_tmp;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
      mask[(i + i2) + (mask.size(0) * (loop_ub_tmp + i1))] = true;
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
// Arguments    : const ::coder::array<float, 2U> &b_I
//                ::coder::array<double, 2U> &points
//                double boardSize[2]
// Return Type  : void
//
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void detectCheckerboard(const ::coder::array<float, 2U> &b_I,
                        ::coder::array<double, 2U> &points, double boardSize[2])
{
  static const double kernel[15][15]{
      {1.9045144150126356E-7, 9.6719222617840546E-7, 3.8253194603479445E-6,
       1.1782813454257772E-5, 2.826550008884209E-5, 5.2806906275779353E-5,
       7.683359526380697E-5, 8.70638696167455E-5, 7.683359526380697E-5,
       5.2806906275779353E-5, 2.826550008884209E-5, 1.1782813454257772E-5,
       3.8253194603479445E-6, 9.6719222617840546E-7, 1.9045144150126356E-7},
      {9.6719222617840546E-7, 4.9118074140369968E-6, 1.9426575170726439E-5,
       5.983806415764425E-5, 0.00014354405374659092, 0.00026817559812550214,
       0.0003901931928827066, 0.00044214681291224477, 0.0003901931928827066,
       0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
       1.9426575170726439E-5, 4.9118074140369968E-6, 9.6719222617840546E-7},
      {3.8253194603479445E-6, 1.9426575170726439E-5, 7.683359526380697E-5,
       0.00023666413469452686, 0.000567727745686802, 0.0010606550658014767,
       0.0015432440146124519, 0.0017487245678627389, 0.0015432440146124519,
       0.0010606550658014767, 0.000567727745686802, 0.00023666413469452686,
       7.683359526380697E-5, 1.9426575170726439E-5, 3.8253194603479445E-6},
      {1.1782813454257772E-5, 5.983806415764425E-5, 0.00023666413469452686,
       0.000728976855220688, 0.0017487245678627389, 0.0032670476045719718,
       0.0047535262158011791, 0.005386450878047711, 0.0047535262158011791,
       0.0032670476045719718, 0.0017487245678627389, 0.000728976855220688,
       0.00023666413469452686, 5.983806415764425E-5, 1.1782813454257772E-5},
      {2.826550008884209E-5, 0.00014354405374659092, 0.000567727745686802,
       0.0017487245678627389, 0.0041949721617992137, 0.0078372397828220912,
       0.011403116598310359, 0.012921423933516035, 0.011403116598310359,
       0.0078372397828220912, 0.0041949721617992137, 0.0017487245678627389,
       0.000567727745686802, 0.00014354405374659092, 2.826550008884209E-5},
      {5.2806906275779353E-5, 0.00026817559812550214, 0.0010606550658014767,
       0.0032670476045719718, 0.0078372397828220912, 0.014641891541684361,
       0.021303826486921609, 0.0241403980280593, 0.021303826486921609,
       0.014641891541684361, 0.0078372397828220912, 0.0032670476045719718,
       0.0010606550658014767, 0.00026817559812550214, 5.2806906275779353E-5},
      {7.683359526380697E-5, 0.0003901931928827066, 0.0015432440146124519,
       0.0047535262158011791, 0.011403116598310359, 0.021303826486921609,
       0.030996884636986775, 0.035124071876292441, 0.030996884636986775,
       0.021303826486921609, 0.011403116598310359, 0.0047535262158011791,
       0.0015432440146124519, 0.0003901931928827066, 7.683359526380697E-5},
      {8.70638696167455E-5, 0.00044214681291224477, 0.0017487245678627389,
       0.005386450878047711, 0.012921423933516035, 0.0241403980280593,
       0.035124071876292441, 0.039800787712028794, 0.035124071876292441,
       0.0241403980280593, 0.012921423933516035, 0.005386450878047711,
       0.0017487245678627389, 0.00044214681291224477, 8.70638696167455E-5},
      {7.683359526380697E-5, 0.0003901931928827066, 0.0015432440146124519,
       0.0047535262158011791, 0.011403116598310359, 0.021303826486921609,
       0.030996884636986775, 0.035124071876292441, 0.030996884636986775,
       0.021303826486921609, 0.011403116598310359, 0.0047535262158011791,
       0.0015432440146124519, 0.0003901931928827066, 7.683359526380697E-5},
      {5.2806906275779353E-5, 0.00026817559812550214, 0.0010606550658014767,
       0.0032670476045719718, 0.0078372397828220912, 0.014641891541684361,
       0.021303826486921609, 0.0241403980280593, 0.021303826486921609,
       0.014641891541684361, 0.0078372397828220912, 0.0032670476045719718,
       0.0010606550658014767, 0.00026817559812550214, 5.2806906275779353E-5},
      {2.826550008884209E-5, 0.00014354405374659092, 0.000567727745686802,
       0.0017487245678627389, 0.0041949721617992137, 0.0078372397828220912,
       0.011403116598310359, 0.012921423933516035, 0.011403116598310359,
       0.0078372397828220912, 0.0041949721617992137, 0.0017487245678627389,
       0.000567727745686802, 0.00014354405374659092, 2.826550008884209E-5},
      {1.1782813454257772E-5, 5.983806415764425E-5, 0.00023666413469452686,
       0.000728976855220688, 0.0017487245678627389, 0.0032670476045719718,
       0.0047535262158011791, 0.005386450878047711, 0.0047535262158011791,
       0.0032670476045719718, 0.0017487245678627389, 0.000728976855220688,
       0.00023666413469452686, 5.983806415764425E-5, 1.1782813454257772E-5},
      {3.8253194603479445E-6, 1.9426575170726439E-5, 7.683359526380697E-5,
       0.00023666413469452686, 0.000567727745686802, 0.0010606550658014767,
       0.0015432440146124519, 0.0017487245678627389, 0.0015432440146124519,
       0.0010606550658014767, 0.000567727745686802, 0.00023666413469452686,
       7.683359526380697E-5, 1.9426575170726439E-5, 3.8253194603479445E-6},
      {9.6719222617840546E-7, 4.9118074140369968E-6, 1.9426575170726439E-5,
       5.983806415764425E-5, 0.00014354405374659092, 0.00026817559812550214,
       0.0003901931928827066, 0.00044214681291224477, 0.0003901931928827066,
       0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
       1.9426575170726439E-5, 4.9118074140369968E-6, 9.6719222617840546E-7},
      {1.9045144150126356E-7, 9.6719222617840546E-7, 3.8253194603479445E-6,
       1.1782813454257772E-5, 2.826550008884209E-5, 5.2806906275779353E-5,
       7.683359526380697E-5, 8.70638696167455E-5, 7.683359526380697E-5,
       5.2806906275779353E-5, 2.826550008884209E-5, 1.1782813454257772E-5,
       3.8253194603479445E-6, 9.6719222617840546E-7, 1.9045144150126356E-7}};
  static const double nonZeroKernel[225]{
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      8.70638696167455E-5,    0.00044214681291224477, 0.0017487245678627389,
      0.005386450878047711,   0.012921423933516035,   0.0241403980280593,
      0.035124071876292441,   0.039800787712028794,   0.035124071876292441,
      0.0241403980280593,     0.012921423933516035,   0.005386450878047711,
      0.0017487245678627389,  0.00044214681291224477, 8.70638696167455E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7};
  Checkerboard lobj_0[6];
  Checkerboard *board0;
  Checkerboard *board45;
  array<double, 1U> s;
  array<float, 2U> I_45;
  array<float, 2U> I_45_x;
  array<float, 2U> Ig;
  array<float, 2U> Ix2;
  array<float, 2U> Ixy;
  array<float, 2U> Iy;
  array<float, 2U> Iy2;
  array<float, 2U> a;
  array<float, 2U> points0;
  array<float, 2U> r;
  array<float, 2U> r1;
  array<float, 2U> x;
  array<float, 1U> b_I_45;
  array<int, 1U> r2;
  array<int, 1U> r3;
  double connDimsT[2];
  double outSizeT[2];
  double padSizeT[2];
  double startT[2];
  int N;
  int b_i;
  int i;
  int k;
  int loop_ub;
  boolean_T conn[15][15];
  boolean_T guard1{false};
  boolean_T guard2{false};
  outSizeT[0] = static_cast<double>(b_I.size(0));
  startT[0] = 7.0;
  outSizeT[1] = static_cast<double>(b_I.size(1));
  startT[1] = 7.0;
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    Ig.set_size(b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      N = b_I.size(0);
      for (b_i = 0; b_i < N; b_i++) {
        Ig[b_i + (Ig.size(0) * i)] = b_I[b_i + (b_I.size(0) * i)];
      }
    }
  } else {
    boolean_T tooBig;
    padImage(b_I, startT, a);
    tooBig = (b_I.size(0) > 65500);
    if (tooBig) {
      if (b_I.size(1) <= 65500) {
        tooBig = false;
      }
    } else {
      tooBig = false;
    }
    Ig.set_size(b_I.size(0), b_I.size(1));
    if (!tooBig) {
      padSizeT[0] = static_cast<double>(a.size(0));
      startT[0] = 15.0;
      padSizeT[1] = static_cast<double>(a.size(1));
      startT[1] = 15.0;
      ippfilter_real32(&a[0], &Ig[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &kernel[0][0], &startT[0], true);
    } else {
      padSizeT[0] = static_cast<double>(a.size(0));
      padSizeT[1] = static_cast<double>(a.size(1));
      for (i = 0; i < 15; i++) {
        for (b_i = 0; b_i < 15; b_i++) {
          conn[i][b_i] = true;
        }
      }
      connDimsT[0] = 15.0;
      connDimsT[1] = 15.0;
      imfilter_real32(&a[0], &Ig[0], 2.0, &outSizeT[0], 2.0, &padSizeT[0],
                      &nonZeroKernel[0], 225.0, &conn[0][0], 2.0, &connDimsT[0],
                      &startT[0], 2.0, true, true);
    }
  }
  Iy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = Ig.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      Iy[b_i + (Iy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
    }
  }
  imfilter(Iy);
  b_imfilter(Ig);
  Ixy.set_size(Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = Ig.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      Ixy[b_i + (Ixy.size(0) * i)] = Ig[b_i + (Ig.size(0) * i)];
    }
  }
  imfilter(Ixy);
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
  b_imfilter(I_45_x);
  a.set_size(I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = I_45.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      a[b_i + (a.size(0) * i)] = I_45[b_i + (I_45.size(0) * i)];
    }
  }
  imfilter(a);
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
  r1.set_size(x.size(0), x.size(1));
  if ((x.size(0) != 0) && (x.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = r1.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        r1[loop_ub + (r1.size(0) * k)] = std::abs(x[loop_ub + (x.size(0) * k)]);
      }
    }
  }
  i = Ixy.size(1);
  a.set_size(Ixy.size(0), Ixy.size(1));
  if ((Ixy.size(0) != 0) && (Ixy.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = a.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        a[loop_ub + (a.size(0) * k)] =
            std::abs(Ixy[loop_ub + (Ixy.size(0) * k)]);
      }
    }
  }
  loop_ub = a.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = a.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      a[b_i + (a.size(0) * i)] = 4.0F * a[b_i + (a.size(0) * i)];
    }
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = r.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      r[b_i + (r.size(0) * i)] =
          3.0F * (r[b_i + (r.size(0) * i)] + r1[b_i + (r1.size(0) * i)]);
    }
  }
  I_45.set_size(a.size(0), a.size(1));
  loop_ub = a.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = a.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      I_45[b_i + (I_45.size(0) * i)] =
          a[b_i + (a.size(0) * i)] - r[b_i + (r.size(0) * i)];
    }
  }
  loop_ub = (a.size(0) * a.size(1)) - 1;
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if ((a[b_i] - r[b_i]) < 0.0F) {
      N++;
    }
  }
  r2.set_size(N);
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if ((a[b_i] - r[b_i]) < 0.0F) {
      r2[N] = b_i + 1;
      N++;
    }
  }
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    I_45[r2[i] - 1] = 0.0F;
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
  r1.set_size(Iy.size(0), Iy.size(1));
  if ((Iy.size(0) != 0) && (Iy.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = r1.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        r1[loop_ub + (r1.size(0) * k)] =
            std::abs(Iy[loop_ub + (Iy.size(0) * k)]);
      }
    }
  }
  i = I_45_x.size(1);
  a.set_size(I_45_x.size(0), I_45_x.size(1));
  if ((I_45_x.size(0) != 0) && (I_45_x.size(1) != 0)) {
    for (k = 0; k < i; k++) {
      b_i = a.size(0);
      for (loop_ub = 0; loop_ub < b_i; loop_ub++) {
        a[loop_ub + (a.size(0) * k)] =
            std::abs(I_45_x[loop_ub + (I_45_x.size(0) * k)]);
      }
    }
  }
  loop_ub = a.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = a.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      a[b_i + (a.size(0) * i)] =
          (4.0F * a[b_i + (a.size(0) * i)]) -
          (3.0F * (r[b_i + (r.size(0) * i)] + r1[b_i + (r1.size(0) * i)]));
    }
  }
  loop_ub = (a.size(0) * a.size(1)) - 1;
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (a[b_i] < 0.0F) {
      N++;
    }
  }
  r3.set_size(N);
  N = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (a[b_i] < 0.0F) {
      r3[N] = b_i + 1;
      N++;
    }
  }
  loop_ub = r3.size(0);
  for (i = 0; i < loop_ub; i++) {
    a[r3[i] - 1] = 0.0F;
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
  c_imfilter(Ix2);
  c_imfilter(Iy2);
  loop_ub = Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    N = Ig.size(0);
    for (b_i = 0; b_i < N; b_i++) {
      Ig[b_i + (Ig.size(0) * i)] =
          Ig[b_i + (Ig.size(0) * i)] * Iy[b_i + (Iy.size(0) * i)];
    }
  }
  c_imfilter(Ig);
  find_peaks(I_45, points0);
  N = I_45.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    s[i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                         (N * ((static_cast<int>(points0[i])) - 1))));
  }
  b_I_45.set_size(s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_I_45[i] = I_45[(static_cast<int>(s[i])) - 1];
  }
  board0 = growCheckerboard(points0, b_I_45, Ix2, Iy2, Ig, 0.0, &lobj_0[0]);
  points.set_size(0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  find_peaks(a, points0);
  N = a.size(0);
  loop_ub = points0.size(0);
  s.set_size(points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    s[i] = static_cast<double>(
        static_cast<int>((static_cast<int>(points0[i + points0.size(0)])) +
                         (N * ((static_cast<int>(points0[i])) - 1))));
  }
  b_I_45.set_size(s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_I_45[i] = a[(static_cast<int>(s[i])) - 1];
  }
  board45 = growCheckerboard(points0, b_I_45, Ix2, Iy2, Ig, 0.78539816339744828,
                             &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      outSizeT[0] = static_cast<double>(board0->BoardIdx.size(0));
      outSizeT[1] = static_cast<double>(board0->BoardIdx.size(1));
      startT[0] = static_cast<double>(board45->BoardIdx.size(0));
      startT[1] = static_cast<double>(board45->BoardIdx.size(1));
      if (isequal(outSizeT, startT)) {
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
    board0 = orient(board0, b_I);
    toPoints(board0, points, boardSize);
    subPixelLocation(Ixy, points);
  }
  if (guard1 && (board45->isValid)) {
    board45 = orient(board45, b_I);
    toPoints(board45, points, boardSize);
    subPixelLocation(I_45_x, points);
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &points
//                const ::coder::array<float, 1U> &scores
//                const ::coder::array<float, 2U> &Ix2
//                const ::coder::array<float, 2U> &Iy2
//                const ::coder::array<float, 2U> &Ixy
//                double theta
//                Checkerboard *iobj_0
// Return Type  : Checkerboard *
//
Checkerboard *growCheckerboard(const ::coder::array<float, 2U> &points,
                               const ::coder::array<float, 1U> &scores,
                               const ::coder::array<float, 2U> &Ix2,
                               const ::coder::array<float, 2U> &Iy2,
                               const ::coder::array<float, 2U> &Ixy,
                               double theta, Checkerboard *iobj_0)
{
  Checkerboard *board;
  Checkerboard *currentBoard;
  Checkerboard *tmpBoard;
  array<double, 2U> b_seedIdx;
  array<double, 2U> seedIdx;
  array<float, 1U> x;
  array<int, 1U> iidx;
  float b_x[2];
  float v2[2];
  if (scores.size(0) == 0) {
    int i;
    iobj_0[2].isValid = false;
    iobj_0[2].Energy = rtInfF;
    iobj_0[2].IsDistortionHigh = false;
    board = &iobj_0[2];
    iobj_0[2].BoardIdx.set_size(1, 1);
    iobj_0[2].BoardIdx[0] = 0.0;
    iobj_0[2].BoardIdx.set_size(3, 3);
    for (i = 0; i < 3; i++) {
      iobj_0[2].BoardIdx[iobj_0[2].BoardIdx.size(0) * i] = 0.0;
      iobj_0[2].BoardIdx[(iobj_0[2].BoardIdx.size(0) * i) + 1] = 0.0;
      iobj_0[2].BoardIdx[(iobj_0[2].BoardIdx.size(0) * i) + 2] = 0.0;
    }
    iobj_0[2].BoardCoords.set_size(1, 1, 1);
    iobj_0[2].BoardCoords[0] = 0.0;
    iobj_0[2].BoardCoords.set_size(3, 3, 2);
    for (i = 0; i < 2; i++) {
      for (int i1{0}; i1 < 3; i1++) {
        iobj_0[2].BoardCoords[(iobj_0[2].BoardCoords.size(0) * i1) +
                              ((iobj_0[2].BoardCoords.size(0) *
                                iobj_0[2].BoardCoords.size(1)) *
                               i)] = 0.0;
        iobj_0[2].BoardCoords[((iobj_0[2].BoardCoords.size(0) * i1) +
                               ((iobj_0[2].BoardCoords.size(0) *
                                 iobj_0[2].BoardCoords.size(1)) *
                                i)) +
                              1] = 0.0;
        iobj_0[2].BoardCoords[((iobj_0[2].BoardCoords.size(0) * i1) +
                               ((iobj_0[2].BoardCoords.size(0) *
                                 iobj_0[2].BoardCoords.size(1)) *
                                i)) +
                              2] = 0.0;
      }
    }
    iobj_0[2].Points.set_size(1, 1);
    iobj_0[2].Points[0] = 0.0F;
    iobj_0[2].Points.set_size(0, 2);
  } else {
    int i;
    int i1;
    int loop_ub;
    if (points.size(0) < 1) {
      seedIdx.set_size(1, 0);
    } else {
      seedIdx.set_size(1, points.size(0));
      loop_ub = points.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        seedIdx[i] = (static_cast<double>(i)) + 1.0;
      }
    }
    x.set_size(seedIdx.size(1));
    loop_ub = seedIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      x[i] = scores[(static_cast<int>(seedIdx[i])) - 1];
    }
    ::coder::internal::sort(x, iidx);
    b_seedIdx.set_size(1, iidx.size(0));
    loop_ub = iidx.size(0);
    for (i = 0; i < loop_ub; i++) {
      b_seedIdx[i] =
          static_cast<double>(static_cast<unsigned int>(seedIdx[iidx[i] - 1]));
    }
    seedIdx.set_size(1, b_seedIdx.size(1));
    loop_ub = b_seedIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      seedIdx[i] = b_seedIdx[i];
    }
    if (iidx.size(0) > 2000) {
      i = static_cast<int>(std::fmin(
          2000.0, std::round((static_cast<double>(seedIdx.size(1))) / 2.0)));
      if (1 > i) {
        loop_ub = 0;
      } else {
        loop_ub = i;
      }
      b_seedIdx.set_size(1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_seedIdx[i] =
            static_cast<double>(static_cast<unsigned int>(seedIdx[i]));
      }
      seedIdx.set_size(1, b_seedIdx.size(1));
      loop_ub = b_seedIdx.size(1);
      for (i = 0; i < loop_ub; i++) {
        seedIdx[i] = b_seedIdx[i];
      }
    }
    iobj_0[0].isValid = false;
    iobj_0[0].Energy = rtInfF;
    iobj_0[0].IsDistortionHigh = false;
    board = &iobj_0[0];
    iobj_0[0].BoardIdx.set_size(1, 1);
    iobj_0[0].BoardIdx[0] = 0.0;
    iobj_0[0].BoardIdx.set_size(3, 3);
    for (i = 0; i < 3; i++) {
      iobj_0[0].BoardIdx[iobj_0[0].BoardIdx.size(0) * i] = 0.0;
      iobj_0[0].BoardIdx[(iobj_0[0].BoardIdx.size(0) * i) + 1] = 0.0;
      iobj_0[0].BoardIdx[(iobj_0[0].BoardIdx.size(0) * i) + 2] = 0.0;
    }
    iobj_0[0].BoardCoords.set_size(1, 1, 1);
    iobj_0[0].BoardCoords[0] = 0.0;
    iobj_0[0].BoardCoords.set_size(3, 3, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < 3; i1++) {
        iobj_0[0].BoardCoords[(iobj_0[0].BoardCoords.size(0) * i1) +
                              ((iobj_0[0].BoardCoords.size(0) *
                                iobj_0[0].BoardCoords.size(1)) *
                               i)] = 0.0;
        iobj_0[0].BoardCoords[((iobj_0[0].BoardCoords.size(0) * i1) +
                               ((iobj_0[0].BoardCoords.size(0) *
                                 iobj_0[0].BoardCoords.size(1)) *
                                i)) +
                              1] = 0.0;
        iobj_0[0].BoardCoords[((iobj_0[0].BoardCoords.size(0) * i1) +
                               ((iobj_0[0].BoardCoords.size(0) *
                                 iobj_0[0].BoardCoords.size(1)) *
                                i)) +
                              2] = 0.0;
      }
    }
    iobj_0[0].Points.set_size(1, 1);
    iobj_0[0].Points[0] = 0.0F;
    iobj_0[0].Points.set_size(0, 2);
    iobj_0[0].IsDistortionHigh = false;
    iobj_0[1].isValid = false;
    iobj_0[1].Energy = rtInfF;
    iobj_0[1].IsDistortionHigh = false;
    currentBoard = &iobj_0[1];
    iobj_0[1].BoardIdx.set_size(1, 1);
    iobj_0[1].BoardIdx[0] = 0.0;
    iobj_0[1].BoardIdx.set_size(3, 3);
    for (i = 0; i < 3; i++) {
      iobj_0[1].BoardIdx[iobj_0[1].BoardIdx.size(0) * i] = 0.0;
      iobj_0[1].BoardIdx[(iobj_0[1].BoardIdx.size(0) * i) + 1] = 0.0;
      iobj_0[1].BoardIdx[(iobj_0[1].BoardIdx.size(0) * i) + 2] = 0.0;
    }
    iobj_0[1].BoardCoords.set_size(1, 1, 1);
    iobj_0[1].BoardCoords[0] = 0.0;
    iobj_0[1].BoardCoords.set_size(3, 3, 2);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < 3; i1++) {
        iobj_0[1].BoardCoords[(iobj_0[1].BoardCoords.size(0) * i1) +
                              ((iobj_0[1].BoardCoords.size(0) *
                                iobj_0[1].BoardCoords.size(1)) *
                               i)] = 0.0;
        iobj_0[1].BoardCoords[((iobj_0[1].BoardCoords.size(0) * i1) +
                               ((iobj_0[1].BoardCoords.size(0) *
                                 iobj_0[1].BoardCoords.size(1)) *
                                i)) +
                              1] = 0.0;
        iobj_0[1].BoardCoords[((iobj_0[1].BoardCoords.size(0) * i1) +
                               ((iobj_0[1].BoardCoords.size(0) *
                                 iobj_0[1].BoardCoords.size(1)) *
                                i)) +
                              2] = 0.0;
      }
    }
    iobj_0[1].Points.set_size(1, 1);
    iobj_0[1].Points[0] = 0.0F;
    iobj_0[1].Points.set_size(0, 2);
    iobj_0[1].IsDistortionHigh = false;
    i = seedIdx.size(1);
    for (int b_i{0}; b_i < i; b_i++) {
      double d;
      float a;
      float ab;
      float adf;
      float b;
      float c;
      float df;
      float tb;
      int sgn2;
      boolean_T guard1{false};
      d = seedIdx[b_i];
      b_x[0] = std::round(
          points[(static_cast<int>(static_cast<unsigned int>(d))) - 1]);
      b_x[1] =
          std::round(points[((static_cast<int>(static_cast<unsigned int>(d))) +
                             points.size(0)) -
                            1]);
      a = Ix2[((static_cast<int>(b_x[1])) +
               (Ix2.size(0) * ((static_cast<int>(b_x[0])) - 1))) -
              1];
      b = Ixy[((static_cast<int>(b_x[1])) +
               (Ixy.size(0) * ((static_cast<int>(b_x[0])) - 1))) -
              1];
      c = Iy2[((static_cast<int>(b_x[1])) +
               (Iy2.size(0) * ((static_cast<int>(b_x[0])) - 1))) -
              1];
      df = a - c;
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
      if ((a + c) < 0.0F) {
        loop_ub = -1;
      } else {
        loop_ub = 1;
      }
      if (loop_ub == sgn2) {
        b = df;
        df = -tb;
        tb = b;
      }
      b_x[0] = ((-tb) * 0.707106769F) + (df * 0.707106769F);
      adf = ((-tb) * -0.707106769F) + (df * 0.707106769F);
      b_x[1] = adf;
      v2[0] = (df * 0.707106769F) + (tb * 0.707106769F);
      b = (df * -0.707106769F) + (tb * 0.707106769F);
      v2[1] = b;
      guard1 = false;
      if ((static_cast<double>(std::abs(
              std::abs(std::abs(rt_atan2f_snf(adf, b_x[0])) - 3.14159274F) -
              (static_cast<float>(theta))))) > 0.58904862254808621) {
        if (!((static_cast<double>(std::abs(
                  std::abs(std::abs(rt_atan2f_snf(b, v2[0])) - 3.14159274F) -
                  (static_cast<float>(theta))))) > 0.58904862254808621)) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        currentBoard->initialize(
            static_cast<double>(static_cast<unsigned int>(d)), points, b_x, v2);
        if (currentBoard->isValid) {
          boolean_T hasExpanded;
          hasExpanded = true;
          while (hasExpanded) {
            int c_i;
            currentBoard->PreviousEnergy = currentBoard->Energy;
            c_i = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (c_i < 4) {
                if (!currentBoard->IsDirectionBad[c_i]) {
                  currentBoard->LastExpandDirection =
                      (static_cast<double>(c_i)) + 1.0;
                  currentBoard->expandBoardDirectionally(
                      (static_cast<double>(c_i)) + 1.0);
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
                    currentBoard->IsDirectionBad[c_i] = true;
                    c_i++;
                  }
                } else {
                  c_i++;
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
// Arguments    : Checkerboard *board
//                const ::coder::array<float, 2U> &b_I
// Return Type  : Checkerboard *
//
Checkerboard *orient(Checkerboard *board, const ::coder::array<float, 2U> &b_I)
{
  Checkerboard *b_board;
  array<double, 3U> r1;
  array<double, 3U> r4;
  array<double, 3U> r5;
  array<double, 2U> newBoardCoords1;
  array<double, 2U> newBoardCoords2;
  array<double, 2U> numRot;
  array<double, 2U> r;
  array<float, 1U> c_I;
  array<float, 1U> d_I;
  array<int, 1U> r2;
  array<int, 1U> r3;
  array<signed char, 2U> ii;
  array<boolean_T, 3U> b_x;
  array<boolean_T, 2U> nextSquareMask;
  array<boolean_T, 2U> upperLeftMask;
  array<boolean_T, 2U> y;
  double cornerIdx[4];
  double upperLeftPolyY[4];
  float x;
  b_board = board;
  x = b_board->Energy;
  if (!std::isinf(x)) {
    int b_loop_ub;
    int i;
    int i1;
    int loop_ub;
    int outsize_idx_1;
    boolean_T b_y;
    boolean_T exitg1;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                               b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_loop_ub = b_board->BoardIdx.size(0) - 1;
        for (i1 = 0; i1 <= b_loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
              b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
        }
      }
      rot90(newBoardCoords2, b_board->BoardIdx);
      loop_ub = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
              b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * i)];
        }
      }
      rot90(newBoardCoords2, newBoardCoords1);
      loop_ub = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      newBoardCoords2.set_size(loop_ub, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
              b_board->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * i)) +
                                   (b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1))];
        }
      }
      rot90(newBoardCoords2, r);
      cat(newBoardCoords1, r, r1);
      b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
      loop_ub = r1.size(1);
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          b_loop_ub = r1.size(0);
          for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub; outsize_idx_1++) {
            b_board->BoardCoords[(outsize_idx_1 +
                                  (b_board->BoardCoords.size(0) * i1)) +
                                 ((b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)) *
                                  i)] = r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                                           ((r1.size(0) * r1.size(1)) * i)];
          }
        }
      }
    }
    newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                             b_board->BoardIdx.size(1));
    loop_ub = b_board->BoardIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_loop_ub = b_board->BoardIdx.size(0);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        newBoardCoords1[i1 + (newBoardCoords1.size(0) * i)] =
            b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
      }
    }
    outsize_idx_1 = newBoardCoords1.size(1);
    y.set_size(1, newBoardCoords1.size(1));
    for (i = 0; i < outsize_idx_1; i++) {
      y[i] = false;
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
      poly2RectMask(cornerIdx, upperLeftPolyY, static_cast<double>(b_I.size(0)),
                    static_cast<double>(b_I.size(1)), upperLeftMask);
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
      poly2RectMask(cornerIdx, upperLeftPolyY, static_cast<double>(b_I.size(0)),
                    static_cast<double>(b_I.size(1)), nextSquareMask);
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
      c_I.set_size(r2.size(0));
      loop_ub = r2.size(0);
      for (i = 0; i < loop_ub; i++) {
        c_I[i] = b_I[r2[i] - 1];
      }
      d_I.set_size(r3.size(0));
      loop_ub = r3.size(0);
      for (i = 0; i < loop_ub; i++) {
        d_I[i] = b_I[r3[i] - 1];
      }
      if (!(mean(c_I) < mean(d_I))) {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          b_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (i1 = 0; i1 <= b_loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
          }
        }
        b_rot90(newBoardCoords2, b_board->BoardIdx);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * i)];
          }
        }
        b_rot90(newBoardCoords2, newBoardCoords1);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * i)) +
                                     (b_board->BoardCoords.size(0) *
                                      b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(newBoardCoords2, r);
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.size(0);
            for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                 outsize_idx_1++) {
              b_board->BoardCoords[(outsize_idx_1 +
                                    (b_board->BoardCoords.size(0) * i1)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    i)] =
                  r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                     ((r1.size(0) * r1.size(1)) * i)];
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
      ii.set_size(1, 1);
      b_loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (b_loop_ub < 4)) {
        if (cornerIdx[b_loop_ub] != 0.0) {
          outsize_idx_1 = 1;
          ii[0] = static_cast<signed char>(b_loop_ub + 1);
          exitg1 = true;
        } else {
          b_loop_ub++;
        }
      }
      if (outsize_idx_1 == 0) {
        ii.set_size(1, 0);
      }
      numRot.set_size(1, ii.size(1));
      loop_ub = ii.size(1);
      for (i = 0; i < loop_ub; i++) {
        numRot[0] = (static_cast<double>(ii[0])) - 1.0;
      }
      if (ii.size(1) == 0) {
        numRot.set_size(1, 1);
        numRot[0] = 0.0;
      }
      y.set_size(1, 1);
      y[0] = (numRot[0] == 2.0);
      if (!y[0]) {
        if (isequal(numRot, 1.0)) {
          outsize_idx_1 = 1;
        } else if (isequal(numRot, 3.0)) {
          outsize_idx_1 = 2;
        } else {
          outsize_idx_1 = 0;
        }
        if (outsize_idx_1 != 0) {
          newBoardCoords1.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = b_board->BoardIdx.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              newBoardCoords1[i1 + (newBoardCoords1.size(0) * i)] =
                  b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(outsize_idx_1));
          b_board->BoardIdx.set_size(newBoardCoords1.size(0),
                                     newBoardCoords1.size(1));
          loop_ub = newBoardCoords1.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_loop_ub = newBoardCoords1.size(0);
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)] =
                  newBoardCoords1[i1 + (newBoardCoords1.size(0) * i)];
            }
          }
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(loop_ub, b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords1[i1 + (newBoardCoords1.size(0) * i)] =
                  b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * i)];
            }
          }
          flip(newBoardCoords1, static_cast<double>(outsize_idx_1));
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                  b_board
                      ->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * i)) +
                                    (b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1))];
            }
          }
          flip(newBoardCoords2, static_cast<double>(outsize_idx_1));
          cat(newBoardCoords1, newBoardCoords2, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (i = 0; i < 2; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = r1.size(0);
              for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                   outsize_idx_1++) {
                b_board->BoardCoords[(outsize_idx_1 +
                                      (b_board->BoardCoords.size(0) * i1)) +
                                     ((b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)) *
                                      i)] =
                    r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                       ((r1.size(0) * r1.size(1)) * i)];
              }
            }
          }
        }
      } else {
        newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                 b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          b_loop_ub = b_board->BoardIdx.size(0) - 1;
          for (i1 = 0; i1 <= b_loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
          }
        }
        b_rot90(newBoardCoords2, b_board->BoardIdx);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * i)];
          }
        }
        b_rot90(newBoardCoords2, newBoardCoords1);
        loop_ub = b_board->BoardCoords.size(0);
        b_loop_ub = b_board->BoardCoords.size(1);
        newBoardCoords2.set_size(loop_ub, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                b_board->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * i)) +
                                     (b_board->BoardCoords.size(0) *
                                      b_board->BoardCoords.size(1))];
          }
        }
        b_rot90(newBoardCoords2, r);
        cat(newBoardCoords1, r, r1);
        b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
        loop_ub = r1.size(1);
        for (i = 0; i < 2; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_loop_ub = r1.size(0);
            for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                 outsize_idx_1++) {
              b_board->BoardCoords[(outsize_idx_1 +
                                    (b_board->BoardCoords.size(0) * i1)) +
                                   ((b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1)) *
                                    i)] =
                  r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                     ((r1.size(0) * r1.size(1)) * i)];
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
      for (i = 0; i < loop_ub; i++) {
        r4[i] = b_board->BoardCoords[(b_board->BoardCoords.size(0) *
                                      b_board->BoardCoords.size(1)) *
                                     i];
      }
      outsize_idx_1 = b_board->BoardCoords.size(0);
      b_loop_ub = b_board->BoardCoords.size(1);
      loop_ub = b_board->BoardCoords.size(2);
      r5.set_size(1, 1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r5[i] =
            b_board
                ->BoardCoords[((outsize_idx_1 + (b_board->BoardCoords.size(0) *
                                                 (b_loop_ub - 1))) +
                               ((b_board->BoardCoords.size(0) *
                                 b_board->BoardCoords.size(1)) *
                                i)) -
                              1];
      }
      b_x.set_size(1, 1, r4.size(2));
      loop_ub = r4.size(2);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = (r4[i] > r5[i]);
      }
      b_y = false;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (b_x.size(2) - 1))) {
        if (!b_x[loop_ub]) {
          loop_ub++;
        } else {
          b_y = true;
          exitg1 = true;
        }
      }
      if (b_y) {
        double c_x;
        c_x = b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                    (b_board->BoardCoords.size(0) *
                                     (b_board->BoardCoords.size(1) - 1))) -
                                   1];
        if (c_x != 0.0) {
          newBoardCoords2.set_size(b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            b_loop_ub = b_board->BoardIdx.size(0) - 1;
            for (i1 = 0; i1 <= b_loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                  b_board->BoardIdx[i1 + (b_board->BoardIdx.size(0) * i)];
            }
          }
          b_rot90(newBoardCoords2, b_board->BoardIdx);
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                  b_board->BoardCoords[i1 + (b_board->BoardCoords.size(0) * i)];
            }
          }
          b_rot90(newBoardCoords2, newBoardCoords1);
          loop_ub = b_board->BoardCoords.size(0);
          b_loop_ub = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(loop_ub, b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + (newBoardCoords2.size(0) * i)] =
                  b_board
                      ->BoardCoords[(i1 + (b_board->BoardCoords.size(0) * i)) +
                                    (b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1))];
            }
          }
          b_rot90(newBoardCoords2, r);
          cat(newBoardCoords1, r, r1);
          b_board->BoardCoords.set_size(r1.size(0), r1.size(1), 2);
          loop_ub = r1.size(1);
          for (i = 0; i < 2; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_loop_ub = r1.size(0);
              for (outsize_idx_1 = 0; outsize_idx_1 < b_loop_ub;
                   outsize_idx_1++) {
                b_board->BoardCoords[(outsize_idx_1 +
                                      (b_board->BoardCoords.size(0) * i1)) +
                                     ((b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)) *
                                      i)] =
                    r1[(outsize_idx_1 + (r1.size(0) * i1)) +
                       ((r1.size(0) * r1.size(1)) * i)];
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
// Arguments    : const Checkerboard *b_this
//                ::coder::array<double, 2U> &points
//                double boardSize[2]
// Return Type  : void
//
void toPoints(const Checkerboard *b_this, ::coder::array<double, 2U> &points,
              double boardSize[2])
{
  array<double, 2U> b_x;
  array<boolean_T, 1U> x;
  int c_this;
  int i;
  boolean_T exitg1;
  boolean_T y;
  c_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  x.set_size(c_this);
  for (i = 0; i < c_this; i++) {
    x[i] = (b_this->BoardIdx[i] == 0.0);
  }
  y = false;
  c_this = 0;
  exitg1 = false;
  while ((!exitg1) && (c_this <= (x.size(0) - 1))) {
    if (!x[c_this]) {
      c_this++;
    } else {
      y = true;
      exitg1 = true;
    }
  }
  if (y) {
    points.set_size(0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    double numPoints;
    int i1;
    int loop_ub;
    numPoints = (static_cast<double>(b_this->BoardCoords.size(0))) *
                (static_cast<double>(b_this->BoardCoords.size(1)));
    points.set_size(static_cast<int>(numPoints), 2);
    c_this = static_cast<int>(numPoints);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < c_this; i1++) {
        points[i1 + (points.size(0) * i)] = 0.0;
      }
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    b_x.set_size(loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x[i1 + (b_x.size(0) * i)] =
            b_this->BoardCoords[i + (b_this->BoardCoords.size(0) * i1)];
      }
    }
    c_this = b_x.size(0) * b_x.size(1);
    for (i = 0; i < c_this; i++) {
      points[i] = b_x[i];
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    b_x.set_size(loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x[i1 + (b_x.size(0) * i)] =
            b_this->BoardCoords[(i + (b_this->BoardCoords.size(0) * i1)) +
                                (b_this->BoardCoords.size(0) *
                                 b_this->BoardCoords.size(1))];
      }
    }
    c_this = b_x.size(0) * b_x.size(1);
    for (i = 0; i < c_this; i++) {
      points[i + points.size(0)] = b_x[i];
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
