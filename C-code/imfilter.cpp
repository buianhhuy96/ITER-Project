//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
namespace coder {
void b_conv2_separable_valid(const double hCol[29], const double hRow[29],
                             const ::coder::array<double, 2U> &inImg,
                             const double finalSize[2],
                             ::coder::array<double, 2U> &outImg)
{
  array<double, 2U> temp;
  array<double, 1U> b_temp;
  double d;
  double nRows;
  int b_i;
  int i;
  int ix;
  int iy;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, i, loop_ub, b_i, iy)

  for (ix = 0; ix <= ub_loop; ix++) {
    for (i = 0; i < tempRows; i++) {
      temp[i + (temp.size(0) * ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (b_i = 0; b_i < 29; b_i++) {
      iy = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(ix)) + (static_cast<unsigned int>(b_i))));
      b_temp.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_temp[i] = inImg[i + (inImg.size(0) * iy)] * hRow[b_i];
      }
      iy = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (i = 0; i <= iy; i++) {
        b_temp[i] = temp[i + (temp.size(0) * ix)] + b_temp[i];
      }
      iy = b_temp.size(0);
      for (i = 0; i < iy; i++) {
        temp[i + (temp.size(0) * ix)] = b_temp[i];
      }
    }
  }
  nRows = finalSize[0];
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i, iy, d,  \
                                                                    b_i)

  for (ix = 0; ix <= ub_loop; ix++) {
    i = static_cast<int>(nRows);
    for (iy = 0; iy < i; iy++) {
      d = 0.0;
      for (b_i = 0; b_i < 29; b_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(iy)) +
                      (static_cast<unsigned int>(b_i))))) +
                  (temp.size(0) * ix)] *
             hCol[b_i];
      }
      outImg[iy + (outImg.size(0) * ix)] = d;
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
  array<double, 2U> temp;
  array<double, 1U> b_temp;
  double d;
  double nRows;
  int b_i;
  int i;
  int ix;
  int iy;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, i, loop_ub, b_i, iy)

  for (ix = 0; ix <= ub_loop; ix++) {
    for (i = 0; i < tempRows; i++) {
      temp[i + (temp.size(0) * ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (b_i = 0; b_i < 15; b_i++) {
      iy = static_cast<int>(static_cast<unsigned int>(
          (static_cast<unsigned int>(ix)) + (static_cast<unsigned int>(b_i))));
      b_temp.set_size(loop_ub);
      for (i = 0; i < loop_ub; i++) {
        b_temp[i] = inImg[i + (inImg.size(0) * iy)] * hRow[b_i];
      }
      iy = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (i = 0; i <= iy; i++) {
        b_temp[i] = temp[i + (temp.size(0) * ix)] + b_temp[i];
      }
      iy = b_temp.size(0);
      for (i = 0; i < iy; i++) {
        temp[i + (temp.size(0) * ix)] = b_temp[i];
      }
    }
  }
  nRows = finalSize[0];
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i, iy, d,  \
                                                                    b_i)

  for (ix = 0; ix <= ub_loop; ix++) {
    i = static_cast<int>(nRows);
    for (iy = 0; iy < i; iy++) {
      d = 0.0;
      for (b_i = 0; b_i < 15; b_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(iy)) +
                      (static_cast<unsigned int>(b_i))))) +
                  (temp.size(0) * ix)] *
             hCol[b_i];
      }
      outImg[iy + (outImg.size(0) * ix)] = d;
    }
  }
}

//
// Arguments    : ::coder::array<float, 2U> &varargin_1
// Return Type  : void
//
void imfilter(::coder::array<float, 2U> &varargin_1)
{
  array<double, 2U> b;
  array<double, 2U> b_a;
  array<double, 1U> c;
  array<double, 1U> c_a;
  array<float, 2U> a;
  double pad[2];
  pad[0] = 0.0;
  pad[1] = 1.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int b_i;
    int i;
    int loop_ub;
    int mc;
    padImage_outSize(varargin_1, pad, a);
    b_a.set_size(a.size(0), a.size(1));
    mc = a.size(1);
    for (i = 0; i < mc; i++) {
      loop_ub = a.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b_a[b_i + (b_a.size(0) * i)] =
            static_cast<double>(a[b_i + (a.size(0) * i)]);
      }
    }
    if (b_a.size(0) == 1) {
      mc = b_a.size(1);
      c_a.set_size(b_a.size(1));
      for (i = 0; i < mc; i++) {
        c_a[i] = b_a[b_a.size(0) * i];
      }
      if (c_a.size(0) < 2) {
        mc = 0;
      } else {
        mc = c_a.size(0) - 2;
      }
      c.set_size(mc);
      for (i = 0; i < mc; i++) {
        c[i] = 0.0;
      }
      if (c_a.size(0) != 0) {
        if (mc != 0) {
          for (loop_ub = 0; loop_ub < 3; loop_ub++) {
            for (b_i = 0; b_i < mc; b_i++) {
              c[b_i] =
                  c[b_i] + (((2.0 - (static_cast<double>(loop_ub))) - 1.0) *
                            c_a[b_i + loop_ub]);
            }
          }
        }
      }
      b.set_size(1, c.size(0));
      mc = c.size(0);
      for (i = 0; i < mc; i++) {
        b[b.size(0) * i] = c[i];
      }
    } else {
      internal::b_conv2AXPYValidCMP(b_a, b);
    }
    varargin_1.set_size(b.size(0), b.size(1));
    mc = b.size(1);
    for (i = 0; i < mc; i++) {
      loop_ub = b.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        varargin_1[b_i + (varargin_1.size(0) * i)] =
            static_cast<float>(b[b_i + (b.size(0) * i)]);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<float, 2U> &a_tmp
//                const double pad[2]
//                ::coder::array<float, 2U> &a
// Return Type  : void
//
void padImage_outSize(const ::coder::array<float, 2U> &a_tmp,
                      const double pad[2], ::coder::array<float, 2U> &a)
{
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    int b_loop_ub;
    int loop_ub;
    loop_ub = static_cast<int>(static_cast<double>(
        (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0])));
    b_loop_ub = static_cast<int>(static_cast<double>(
        (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1])));
    a.set_size(static_cast<int>(static_cast<double>(
                   (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]))),
               static_cast<int>(static_cast<double>(
                   (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]))));
    for (int i{0}; i < b_loop_ub; i++) {
      for (int i1{0}; i1 < loop_ub; i1++) {
        a[i1 + (a.size(0) * i)] = 0.0F;
      }
    }
  } else {
    int b_i;
    int b_loop_ub;
    int i;
    int i1;
    int j;
    int loop_ub;
    a.set_size(static_cast<int>(static_cast<double>(
                   (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]))),
               static_cast<int>(static_cast<double>(
                   (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]))));
    i = static_cast<int>(pad[1]);
    for (j = 0; j < i; j++) {
      i1 = a.size(0);
      for (b_i = 0; b_i < i1; b_i++) {
        a[b_i + (a.size(0) * j)] = 0.0F;
      }
    }
    i1 = (a_tmp.size(1) + (static_cast<int>(pad[1]))) + 1;
    loop_ub = a.size(1);
    for (j = i1; j <= loop_ub; j++) {
      b_loop_ub = a.size(0);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        a[b_i + (a.size(0) * (j - 1))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = static_cast<int>(pad[0]);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        a[b_i + (a.size(0) * (j + i))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = ((static_cast<int>(pad[0])) + a_tmp.size(0)) + 1;
      b_loop_ub = a.size(0);
      for (b_i = loop_ub; b_i <= b_loop_ub; b_i++) {
        a[(b_i + (a.size(0) * (j + i))) - 1] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = a_tmp.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        a[(b_i + (static_cast<int>(pad[0]))) + (a.size(0) * (j + i))] =
            a_tmp[b_i + (a_tmp.size(0) * j)];
      }
    }
  }
}

} // namespace coder

//
// File trailer for imfilter.cpp
//
// [EOF]
//
