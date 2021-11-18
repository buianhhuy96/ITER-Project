//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "imfilter.h"
#include "conv2AXPYValidCMP.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const double hCol[29]
//                const double hRow[29]
//                const ::coder::array<double, 2U> &inImg
//                const double finalSize[2]
//                ::coder::array<double, 2U> &outImg
// Return Type  : void
//
namespace Codegen {
namespace coder {
void b_conv2_separable_valid(const double hCol[29], const double hRow[29],
                             const ::coder::array<double, 2U> &inImg,
                             const double finalSize[2],
                             ::coder::array<double, 2U> &outImg)
{
  ::coder::array<double, 2U> temp;
  ::coder::array<double, 1U> b_temp;
  double d;
  double nRows;
  int b_i;
  int b_iy;
  int c_i;
  int ix;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, b_i, loop_ub, c_i, b_iy)

  for (ix = 0; ix <= ub_loop; ix++) {
    for (b_i = 0; b_i < tempRows; b_i++) {
      temp[b_i + (temp.size(0) * ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (c_i = 0; c_i < 29; c_i++) {
      b_iy = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(ix)) + (static_cast<unsigned int>(c_i))));
      b_temp.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_temp[b_i] = inImg[b_i + (inImg.size(0) * b_iy)] * hRow[c_i];
      }
      b_iy = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (b_i = 0; b_i <= b_iy; b_i++) {
        b_temp[b_i] = temp[b_i + (temp.size(0) * ix)] + b_temp[b_i];
      }
      b_iy = b_temp.size(0);
      for (b_i = 0; b_i < b_iy; b_i++) {
        temp[b_i + (temp.size(0) * ix)] = b_temp[b_i];
      }
    }
  }
  nRows = finalSize[0];
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i, b_iy, \
                                                                    d, c_i)

  for (ix = 0; ix <= ub_loop; ix++) {
    b_i = static_cast<int>(nRows);
    for (b_iy = 0; b_iy < b_i; b_iy++) {
      d = 0.0;
      for (c_i = 0; c_i < 29; c_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(b_iy)) +
                      (static_cast<unsigned int>(c_i))))) +
                  (temp.size(0) * ix)] *
             hCol[c_i];
      }
      outImg[b_iy + (outImg.size(0) * ix)] = d;
    }
  }
}

//
// Arguments    : const double hCol[15]
//                const double hRow[15]
//                const ::coder::array<double, 2U> &inImg
//                const double finalSize[2]
//                ::coder::array<double, 2U> &outImg
// Return Type  : void
//
void conv2_separable_valid(const double hCol[15], const double hRow[15],
                           const ::coder::array<double, 2U> &inImg,
                           const double finalSize[2],
                           ::coder::array<double, 2U> &outImg)
{
  ::coder::array<double, 2U> temp;
  ::coder::array<double, 1U> b_temp;
  double d;
  double nRows;
  int b_i;
  int b_iy;
  int c_i;
  int ix;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, b_i, loop_ub, c_i, b_iy)

  for (ix = 0; ix <= ub_loop; ix++) {
    for (b_i = 0; b_i < tempRows; b_i++) {
      temp[b_i + (temp.size(0) * ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (c_i = 0; c_i < 15; c_i++) {
      b_iy = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(ix)) + (static_cast<unsigned int>(c_i))));
      b_temp.set_size(loop_ub);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_temp[b_i] = inImg[b_i + (inImg.size(0) * b_iy)] * hRow[c_i];
      }
      b_iy = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (b_i = 0; b_i <= b_iy; b_i++) {
        b_temp[b_i] = temp[b_i + (temp.size(0) * ix)] + b_temp[b_i];
      }
      b_iy = b_temp.size(0);
      for (b_i = 0; b_i < b_iy; b_i++) {
        temp[b_i + (temp.size(0) * ix)] = b_temp[b_i];
      }
    }
  }
  nRows = finalSize[0];
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i, b_iy, \
                                                                    d, c_i)

  for (ix = 0; ix <= ub_loop; ix++) {
    b_i = static_cast<int>(nRows);
    for (b_iy = 0; b_iy < b_i; b_iy++) {
      d = 0.0;
      for (c_i = 0; c_i < 15; c_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(b_iy)) +
                      (static_cast<unsigned int>(c_i))))) +
                  (temp.size(0) * ix)] *
             hCol[c_i];
      }
      outImg[b_iy + (outImg.size(0) * ix)] = d;
    }
  }
}

//
// Arguments    : ::coder::array<float, 2U> &varargin_1
// Return Type  : void
//
void imfilter(::coder::array<float, 2U> &varargin_1)
{
  ::coder::array<double, 2U> b;
  ::coder::array<double, 2U> c_a;
  ::coder::array<double, 1U> c;
  ::coder::array<double, 1U> d_a;
  ::coder::array<float, 2U> b_a;
  double pad[2];
  pad[0] = 0.0;
  pad[1] = 1.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int b_i;
    int c_i;
    int loop_ub;
    int mc;
    padImage_outSize(varargin_1, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    mc = b_a.size(1);
    for (b_i = 0; b_i < mc; b_i++) {
      loop_ub = b_a.size(0);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        c_a[c_i + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[c_i + (b_a.size(0) * b_i)]);
      }
    }
    if (c_a.size(0) == 1) {
      mc = c_a.size(1);
      d_a.set_size(c_a.size(1));
      for (b_i = 0; b_i < mc; b_i++) {
        d_a[b_i] = c_a[c_a.size(0) * b_i];
      }
      if (d_a.size(0) < 2) {
        mc = 0;
      } else {
        mc = d_a.size(0) - 2;
      }
      c.set_size(mc);
      for (b_i = 0; b_i < mc; b_i++) {
        c[b_i] = 0.0;
      }
      if (d_a.size(0) != 0) {
        if (mc != 0) {
          for (loop_ub = 0; loop_ub < 3; loop_ub++) {
            for (c_i = 0; c_i < mc; c_i++) {
              c[c_i] =
                  c[c_i] + (((2.0 - (static_cast<double>(loop_ub))) - 1.0) *
                            d_a[c_i + loop_ub]);
            }
          }
        }
      }
      b.set_size(1, c.size(0));
      mc = c.size(0);
      for (b_i = 0; b_i < mc; b_i++) {
        b[b.size(0) * b_i] = c[b_i];
      }
    } else {
      internal::b_conv2AXPYValidCMP(c_a, b);
    }
    varargin_1.set_size(b.size(0), b.size(1));
    mc = b.size(1);
    for (b_i = 0; b_i < mc; b_i++) {
      loop_ub = b.size(0);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        varargin_1[c_i + (varargin_1.size(0) * b_i)] =
            static_cast<float>(b[c_i + (b.size(0) * b_i)]);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &a_tmp
//                const double pad[2]
//                ::coder::array<float, 2U> &b_a
// Return Type  : void
//
void padImage_outSize(const ::coder::array<float, 2U> &a_tmp,
                      const double pad[2], ::coder::array<float, 2U> &b_a)
{
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    int b_loop_ub;
    int loop_ub;
    loop_ub = static_cast<int>(static_cast<double>(
        (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0])));
    b_loop_ub = static_cast<int>(static_cast<double>(
        (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1])));
    b_a.set_size(static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]))),
                 static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]))));
    for (int b_i{0}; b_i < b_loop_ub; b_i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        b_a[i1 + (b_a.size(0) * b_i)] = 0.0F;
      }
    }
  } else {
    int b_i;
    int b_loop_ub;
    int c_i;
    int i1;
    int j;
    int loop_ub;
    b_a.set_size(static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]))),
                 static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]))));
    b_i = static_cast<int>(pad[1]);
    for (j = 0; j < b_i; j++) {
      i1 = b_a.size(0);
      for (c_i = 0; c_i < i1; c_i++) {
        b_a[c_i + (b_a.size(0) * j)] = 0.0F;
      }
    }
    i1 = (a_tmp.size(1) + (static_cast<int>(pad[1]))) + 1;
    loop_ub = b_a.size(1);
    for (j = i1; j <= loop_ub; j++) {
      b_loop_ub = b_a.size(0);
      for (c_i = 0; c_i < b_loop_ub; c_i++) {
        b_a[c_i + (b_a.size(0) * (j - 1))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = static_cast<int>(pad[0]);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        b_a[c_i + (b_a.size(0) * (j + b_i))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = ((static_cast<int>(pad[0])) + a_tmp.size(0)) + 1;
      b_loop_ub = b_a.size(0);
      for (c_i = loop_ub; c_i <= b_loop_ub; c_i++) {
        b_a[(c_i + (b_a.size(0) * (j + b_i))) - 1] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = a_tmp.size(0);
      for (c_i = 0; c_i < loop_ub; c_i++) {
        b_a[(c_i + (static_cast<int>(pad[0]))) + (b_a.size(0) * (j + b_i))] =
            a_tmp[c_i + (a_tmp.size(0) * j)];
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for imfilter.cpp
//
// [EOF]
//
