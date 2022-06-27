//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "imfilter.h"
#include "conv2AXPYValidCMP.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

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
  array<double, 1U> r;
  double d;
  double nRows;
  int b_i;
  int b_iy;
  int b_loop_ub;
  int b_ub_loop;
  int c_i;
  int c_temp;
  int d_i;
  int d_ix;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, r, b_i, loop_ub, c_i, d_ix, i2, c_temp, i3, b_loop_ub, i4)

  for (int b_ix = 0; b_ix <= ub_loop; b_ix++) {
    for (b_i = 0; b_i < tempRows; b_i++) {
      temp[b_i + (temp.size(0) * b_ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (c_i = 0; c_i < 29; c_i++) {
      d_ix = static_cast<int>(
          static_cast<unsigned int>((static_cast<unsigned int>(b_ix)) +
                                    (static_cast<unsigned int>(c_i))));
      r.set_size(loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        r[i2] = inImg[i2 + (inImg.size(0) * d_ix)] * hRow[c_i];
      }
      c_temp = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (i3 = 0; i3 <= c_temp; i3++) {
        b_temp[i3] = temp[i3 + (temp.size(0) * b_ix)] + r[i3];
      }
      b_loop_ub = b_temp.size(0);
      for (i4 = 0; i4 < b_loop_ub; i4++) {
        temp[i4 + (temp.size(0) * b_ix)] = b_temp[i4];
      }
    }
  }
  nRows = finalSize[0];
  b_ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1, b_iy,  \
                                                                    d, d_i)

  for (int c_ix = 0; c_ix <= b_ub_loop; c_ix++) {
    i1 = static_cast<int>(nRows);
    for (b_iy = 0; b_iy < i1; b_iy++) {
      d = 0.0;
      for (d_i = 0; d_i < 29; d_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(b_iy)) +
                      (static_cast<unsigned int>(d_i))))) +
                  (temp.size(0) * c_ix)] *
             hCol[d_i];
      }
      outImg[b_iy + (outImg.size(0) * c_ix)] = d;
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
  array<double, 1U> r;
  double d;
  double nRows;
  int b_i;
  int b_iy;
  int b_loop_ub;
  int b_ub_loop;
  int c_i;
  int c_temp;
  int d_i;
  int d_ix;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  int tempRows;
  int ub_loop;
  tempRows = inImg.size(0);
  outImg.set_size(static_cast<int>(finalSize[0]),
                  static_cast<int>(finalSize[1]));
  temp.set_size(inImg.size(0), static_cast<int>(finalSize[1]));
  ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_temp, r, b_i, loop_ub, c_i, d_ix, i2, c_temp, i3, b_loop_ub, i4)

  for (int b_ix = 0; b_ix <= ub_loop; b_ix++) {
    for (b_i = 0; b_i < tempRows; b_i++) {
      temp[b_i + (temp.size(0) * b_ix)] = 0.0;
    }
    loop_ub = inImg.size(0);
    for (c_i = 0; c_i < 15; c_i++) {
      d_ix = static_cast<int>(
          static_cast<unsigned int>((static_cast<unsigned int>(b_ix)) +
                                    (static_cast<unsigned int>(c_i))));
      r.set_size(loop_ub);
      for (i2 = 0; i2 < loop_ub; i2++) {
        r[i2] = inImg[i2 + (inImg.size(0) * d_ix)] * hRow[c_i];
      }
      c_temp = temp.size(0) - 1;
      b_temp.set_size(temp.size(0));
      for (i3 = 0; i3 <= c_temp; i3++) {
        b_temp[i3] = temp[i3 + (temp.size(0) * b_ix)] + r[i3];
      }
      b_loop_ub = b_temp.size(0);
      for (i4 = 0; i4 < b_loop_ub; i4++) {
        temp[i4 + (temp.size(0) * b_ix)] = b_temp[i4];
      }
    }
  }
  nRows = finalSize[0];
  b_ub_loop = (static_cast<int>(finalSize[1])) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1, b_iy,  \
                                                                    d, d_i)

  for (int c_ix = 0; c_ix <= b_ub_loop; c_ix++) {
    i1 = static_cast<int>(nRows);
    for (b_iy = 0; b_iy < i1; b_iy++) {
      d = 0.0;
      for (d_i = 0; d_i < 15; d_i++) {
        d += temp[(static_cast<int>(static_cast<unsigned int>(
                      (static_cast<unsigned int>(b_iy)) +
                      (static_cast<unsigned int>(d_i))))) +
                  (temp.size(0) * c_ix)] *
             hCol[d_i];
      }
      outImg[b_iy + (outImg.size(0) * c_ix)] = d;
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
  array<double, 2U> c_a;
  array<double, 1U> c;
  array<double, 1U> d_a;
  array<float, 2U> b_a;
  double pad[2];
  int d_loop_ub;
  int f_loop_ub;
  int i1;
  int i4;
  pad[0] = 0.0;
  pad[1] = 1.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int e_loop_ub;
    int loop_ub;
    padImage_outSize(varargin_1, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i1,        \
                                                                    d_loop_ub)

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      d_loop_ub = b_a.size(0);
      for (i1 = 0; i1 < d_loop_ub; i1++) {
        c_a[i1 + (c_a.size(0) * b_i)] =
            static_cast<double>(b_a[i1 + (b_a.size(0) * b_i)]);
      }
    }
    if (c_a.size(0) == 1) {
      int b_loop_ub;
      int c_loop_ub;
      int g_loop_ub;
      int h_loop_ub;
      int mc;
      b_loop_ub = c_a.size(1);
      d_a.set_size(c_a.size(1));
      c_loop_ub = c_a.size(1);
      if ((static_cast<int>(c_a.size(1) < 4)) != 0) {
        for (int i3{0}; i3 < b_loop_ub; i3++) {
          d_a[i3] = c_a[c_a.size(0) * i3];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i3 = 0; i3 < c_loop_ub; i3++) {
          d_a[i3] = c_a[c_a.size(0) * i3];
        }
      }
      if (d_a.size(0) < 2) {
        mc = 0;
      } else {
        mc = d_a.size(0) - 2;
      }
      c.set_size(mc);
      g_loop_ub = mc;
      if ((static_cast<int>(mc < 4)) != 0) {
        for (int i5{0}; i5 < mc; i5++) {
          c[i5] = 0.0;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i5 = 0; i5 < g_loop_ub; i5++) {
          c[i5] = 0.0;
        }
      }
      if (d_a.size(0) != 0) {
        if (mc != 0) {
          for (int c_ib{0}; c_ib < 3; c_ib++) {
            for (int c_i{0}; c_i < mc; c_i++) {
              c[c_i] = c[c_i] + (((2.0 - (static_cast<double>(c_ib))) - 1.0) *
                                 d_a[c_i + c_ib]);
            }
          }
        }
      }
      b.set_size(1, c.size(0));
      h_loop_ub = c.size(0);
      if ((static_cast<int>(c.size(0) < 4)) != 0) {
        for (int i6{0}; i6 < h_loop_ub; i6++) {
          b[b.size(0) * i6] = c[i6];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i6 = 0; i6 < h_loop_ub; i6++) {
          b[b.size(0) * i6] = c[i6];
        }
      }
    } else {
      internal::b_conv2AXPYValidCMP(c_a, b);
    }
    varargin_1.set_size(b.size(0), b.size(1));
    e_loop_ub = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4,        \
                                                                    f_loop_ub)

    for (int i2 = 0; i2 < e_loop_ub; i2++) {
      f_loop_ub = b.size(0);
      for (i4 = 0; i4 < f_loop_ub; i4++) {
        varargin_1[i4 + (varargin_1.size(0) * i2)] =
            static_cast<float>(b[i4 + (b.size(0) * i2)]);
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
  int outsize[2];
  int b_loop_ub;
  int c_i;
  int d_i;
  int e_i;
  int g_i;
  int h_i;
  int i10;
  int i11;
  int i12;
  int i13;
  int i3;
  int i6;
  int i7;
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    double sizeB_idx_0;
    double sizeB_idx_1;
    int loop_ub;
    int outsize_tmp;
    sizeB_idx_0 = (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]);
    sizeB_idx_1 = (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]);
    outsize_tmp = static_cast<int>(sizeB_idx_0);
    outsize[0] = static_cast<int>(sizeB_idx_0);
    b_a.set_size(outsize_tmp, static_cast<int>(sizeB_idx_1));
    loop_ub = static_cast<int>(sizeB_idx_1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i6,        \
                                                                    b_loop_ub)

    for (int i4 = 0; i4 < loop_ub; i4++) {
      b_loop_ub = outsize[0];
      for (i6 = 0; i6 < b_loop_ub; i6++) {
        b_a[i6 + (b_a.size(0) * i4)] = 0.0F;
      }
    }
  } else {
    int b_i;
    int b_i8;
    int i1;
    int i2;
    int i5;
    int i9;
    b_a.set_size(static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(0))) + (2.0 * pad[0]))),
                 static_cast<int>(static_cast<double>(
                     (static_cast<double>(a_tmp.size(1))) + (2.0 * pad[1]))));
    b_i = static_cast<int>(pad[1]);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(c_i, i3)

    for (int j = 0; j < b_i; j++) {
      i3 = b_a.size(0);
      for (c_i = 0; c_i < i3; c_i++) {
        b_a[c_i + (b_a.size(0) * j)] = 0.0F;
      }
    }
    i1 = (a_tmp.size(1) + (static_cast<int>(pad[1]))) + 1;
    i2 = b_a.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_i, i7)

    for (int b_j = i1; b_j <= i2; b_j++) {
      i7 = b_a.size(0);
      for (d_i = 0; d_i < i7; d_i++) {
        b_a[d_i + (b_a.size(0) * (b_j - 1))] = 0.0F;
      }
    }
    i5 = a_tmp.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_i, i10)

    for (int c_j = 0; c_j < i5; c_j++) {
      i10 = static_cast<int>(pad[0]);
      for (e_i = 0; e_i < i10; e_i++) {
        b_a[e_i + (b_a.size(0) * (c_j + (static_cast<int>(pad[1]))))] = 0.0F;
      }
    }
    b_i8 = a_tmp.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_i, i11,  \
                                                                    i12)

    for (int d_j = 0; d_j < b_i8; d_j++) {
      i12 = ((static_cast<int>(pad[0])) + a_tmp.size(0)) + 1;
      i11 = b_a.size(0);
      for (g_i = i12; g_i <= i11; g_i++) {
        b_a[(g_i + (b_a.size(0) * (d_j + (static_cast<int>(pad[1]))))) - 1] =
            0.0F;
      }
    }
    i9 = a_tmp.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(h_i, i13)

    for (int e_j = 0; e_j < i9; e_j++) {
      i13 = a_tmp.size(0);
      for (h_i = 0; h_i < i13; h_i++) {
        b_a[(h_i + (static_cast<int>(pad[0]))) +
            (b_a.size(0) * (e_j + (static_cast<int>(pad[1]))))] =
            a_tmp[h_i + (a_tmp.size(0) * e_j)];
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
