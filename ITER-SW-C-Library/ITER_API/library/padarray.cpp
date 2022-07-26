//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: padarray.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "padarray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                ::coder::array<double, 2U> &b
// Return Type  : void
//
namespace ITER {
namespace coder {
void padarray(const ::coder::array<double, 2U> &varargin_1,
              ::coder::array<double, 2U> &b)
{
  int outsize[2];
  int b_loop_ub;
  int d_i;
  int e_i;
  int g_i;
  int i10;
  int i11;
  int i3;
  int i6;
  int i9;
  if ((varargin_1.size(0) == 0) || (varargin_1.size(1) == 0)) {
    int loop_ub;
    outsize[0] = static_cast<int>(static_cast<unsigned int>(
        (static_cast<unsigned int>(varargin_1.size(0))) + 2U));
    b.set_size(static_cast<int>(static_cast<unsigned int>(
                   (static_cast<unsigned int>(varargin_1.size(0))) + 2U)),
               static_cast<int>(static_cast<unsigned int>(
                   (static_cast<unsigned int>(varargin_1.size(1))) + 2U)));
    loop_ub = static_cast<int>(static_cast<unsigned int>(
        (static_cast<unsigned int>(varargin_1.size(1))) + 2U));
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3,        \
                                                                    b_loop_ub)

    for (int i1 = 0; i1 < loop_ub; i1++) {
      b_loop_ub = outsize[0];
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        b[i3 + (b.size(0) * i1)] = 0.0;
      }
    }
  } else {
    int b_i;
    int b_i8;
    int i2;
    int i4;
    int i5;
    int i7;
    b.set_size(static_cast<int>(static_cast<unsigned int>(
                   (static_cast<unsigned int>(varargin_1.size(0))) + 2U)),
               static_cast<int>(static_cast<unsigned int>(
                   (static_cast<unsigned int>(varargin_1.size(1))) + 2U)));
    b_i = static_cast<int>(static_cast<unsigned int>(
        (static_cast<unsigned int>(varargin_1.size(0))) + 2U));
    if ((static_cast<int>((static_cast<int>(static_cast<unsigned int>(
                              (static_cast<unsigned int>(varargin_1.size(0))) +
                              2U))) < 4)) != 0) {
      for (int c_i{0}; c_i < b_i; c_i++) {
        b[c_i] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_i = 0; c_i < b_i; c_i++) {
        b[c_i] = 0.0;
      }
    }
    i2 = varargin_1.size(1) + 2;
    i4 = b.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(d_i, i6)

    for (int j = i2; j <= i4; j++) {
      i6 = b.size(0);
      for (d_i = 0; d_i < i6; d_i++) {
        b[d_i + (b.size(0) * (j - 1))] = 0.0;
      }
    }
    i5 = varargin_1.size(1);
    if ((static_cast<int>(varargin_1.size(1) < 4)) != 0) {
      for (int b_j{0}; b_j < i5; b_j++) {
        b[b.size(0) * (b_j + 1)] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_j = 0; b_j < i5; b_j++) {
        b[b.size(0) * (b_j + 1)] = 0.0;
      }
    }
    i7 = varargin_1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_i, i9,   \
                                                                    i10)

    for (int c_j = 0; c_j < i7; c_j++) {
      i10 = varargin_1.size(0) + 2;
      i9 = b.size(0);
      for (e_i = i10; e_i <= i9; e_i++) {
        b[(e_i + (b.size(0) * (c_j + 1))) - 1] = 0.0;
      }
    }
    b_i8 = varargin_1.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(g_i, i11)

    for (int d_j = 0; d_j < b_i8; d_j++) {
      i11 = varargin_1.size(0);
      for (g_i = 0; g_i < i11; g_i++) {
        b[(g_i + (b.size(0) * (d_j + 1))) + 1] =
            varargin_1[g_i + (varargin_1.size(0) * d_j)];
      }
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for padarray.cpp
//
// [EOF]
//
