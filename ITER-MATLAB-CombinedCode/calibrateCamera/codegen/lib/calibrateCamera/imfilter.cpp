//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imfilter.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "imfilter.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real32_T, 2U> &varargin_1
// Return Type  : void
//
namespace Codegen {
namespace coder {
void b_imfilter(::coder::array<real32_T, 2U> &varargin_1)
{
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> c_a;
  ::coder::array<real_T, 1U> c;
  ::coder::array<real_T, 1U> d_a;
  ::coder::array<real32_T, 2U> b_a;
  real_T pad[2];
  pad[0] = 0.0;
  pad[1] = 1.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int32_T b_i;
    int32_T d_i;
    int32_T loop_ub;
    int32_T mc;
    padImage_outSize(varargin_1, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      mc = b_a.size(0);
      for (d_i = 0; d_i < mc; d_i++) {
        c_a[d_i + (c_a.size(0) * b_i)] =
            static_cast<real_T>(b_a[d_i + (b_a.size(0) * b_i)]);
      }
    }
    if (c_a.size(0) == 1) {
      loop_ub = c_a.size(1);
      d_a.set_size(c_a.size(1));
      for (b_i = 0; b_i < loop_ub; b_i++) {
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
            for (d_i = 0; d_i < mc; d_i++) {
              c[d_i] =
                  c[d_i] + (((2.0 - (static_cast<real_T>(loop_ub))) - 1.0) *
                            d_a[d_i + loop_ub]);
            }
          }
        }
      }
      b.set_size(1, c.size(0));
      loop_ub = c.size(0);
      for (b_i = 0; b_i < loop_ub; b_i++) {
        b[b.size(0) * b_i] = c[b_i];
      }
    } else {
      int32_T ma;
      int32_T nc;
      ma = c_a.size(0);
      if (c_a.size(1) < 2) {
        nc = 0;
      } else {
        nc = c_a.size(1) - 2;
      }
      b.set_size(c_a.size(0), nc);
      for (b_i = 0; b_i < nc; b_i++) {
        loop_ub = c_a.size(0);
        for (d_i = 0; d_i < loop_ub; d_i++) {
          b[d_i + (b.size(0) * b_i)] = 0.0;
        }
      }
      if ((c_a.size(0) != 0) && (c_a.size(1) != 0)) {
        if (nc != 0) {
          for (mc = 0; mc < nc; mc++) {
            for (loop_ub = 0; loop_ub < 3; loop_ub++) {
              for (d_i = 0; d_i < ma; d_i++) {
                b[d_i + (b.size(0) * mc)] =
                    b[d_i + (b.size(0) * mc)] +
                    (((2.0 - (static_cast<real_T>(loop_ub))) - 1.0) *
                     c_a[d_i + (c_a.size(0) * (mc + loop_ub))]);
              }
            }
          }
        }
      }
    }
    varargin_1.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      mc = b.size(0);
      for (d_i = 0; d_i < mc; d_i++) {
        varargin_1[d_i + (varargin_1.size(0) * b_i)] =
            static_cast<real32_T>(b[d_i + (b.size(0) * b_i)]);
      }
    }
  }
}

//
// Arguments    : ::coder::array<real32_T, 2U> &varargin_1
// Return Type  : void
//
void c_imfilter(::coder::array<real32_T, 2U> &varargin_1)
{
  static const real_T b_b[7][7]{
      {0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
       0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
       0.0013419653598432805},
      {0.0040765308179236169, 0.012383407207635906, 0.02411958376255428,
       0.030121714902657252, 0.02411958376255428, 0.012383407207635906,
       0.0040765308179236169},
      {0.0079399978434782879, 0.02411958376255428, 0.046978534350396596,
       0.058669089490849466, 0.046978534350396596, 0.02411958376255428,
       0.0079399978434782879},
      {0.0099158573267036573, 0.030121714902657252, 0.058669089490849466,
       0.073268826056005834, 0.058669089490849466, 0.030121714902657252,
       0.0099158573267036573},
      {0.0079399978434782879, 0.02411958376255428, 0.046978534350396596,
       0.058669089490849466, 0.046978534350396596, 0.02411958376255428,
       0.0079399978434782879},
      {0.0040765308179236169, 0.012383407207635906, 0.02411958376255428,
       0.030121714902657252, 0.02411958376255428, 0.012383407207635906,
       0.0040765308179236169},
      {0.0013419653598432805, 0.0040765308179236169, 0.0079399978434782879,
       0.0099158573267036573, 0.0079399978434782879, 0.0040765308179236169,
       0.0013419653598432805}};
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> c_a;
  ::coder::array<real32_T, 2U> b_a;
  real_T pad[2];
  pad[0] = 3.0;
  pad[1] = 3.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T ib;
    int32_T loop_ub;
    int32_T mc;
    int32_T nc;
    padImage_outSize(varargin_1, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (ib = 0; ib < loop_ub; ib++) {
      b_loop_ub = b_a.size(0);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        c_a[b_i + (c_a.size(0) * ib)] =
            static_cast<real_T>(b_a[b_i + (b_a.size(0) * ib)]);
      }
    }
    if (c_a.size(0) < 6) {
      mc = 0;
    } else {
      mc = c_a.size(0) - 6;
    }
    if (c_a.size(1) < 6) {
      nc = 0;
    } else {
      nc = c_a.size(1) - 6;
    }
    b.set_size(mc, nc);
    for (ib = 0; ib < nc; ib++) {
      for (b_i = 0; b_i < mc; b_i++) {
        b[b_i + (b.size(0) * ib)] = 0.0;
      }
    }
    if ((c_a.size(0) != 0) && (c_a.size(1) != 0)) {
      if ((mc != 0) && (nc != 0)) {
        for (loop_ub = 0; loop_ub < nc; loop_ub++) {
          for (b_loop_ub = 0; b_loop_ub < 7; b_loop_ub++) {
            for (ib = 0; ib < 7; ib++) {
              for (b_i = 0; b_i < mc; b_i++) {
                b[b_i + (b.size(0) * loop_ub)] =
                    b[b_i + (b.size(0) * loop_ub)] +
                    (b_b[6 - b_loop_ub][6 - ib] *
                     c_a[(b_i + ib) + (c_a.size(0) * (loop_ub + b_loop_ub))]);
              }
            }
          }
        }
      }
    }
    varargin_1.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (ib = 0; ib < loop_ub; ib++) {
      b_loop_ub = b.size(0);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        varargin_1[b_i + (varargin_1.size(0) * ib)] =
            static_cast<real32_T>(b[b_i + (b.size(0) * ib)]);
      }
    }
  }
}

//
// Arguments    : ::coder::array<real32_T, 2U> &varargin_1
// Return Type  : void
//
void imfilter(::coder::array<real32_T, 2U> &varargin_1)
{
  ::coder::array<real_T, 2U> b;
  ::coder::array<real_T, 2U> c_a;
  ::coder::array<real32_T, 2U> b_a;
  real_T pad[2];
  pad[0] = 1.0;
  pad[1] = 0.0;
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T d_i;
    int32_T loop_ub;
    int32_T mc;
    int32_T na;
    padImage_outSize(varargin_1, pad, b_a);
    c_a.set_size(b_a.size(0), b_a.size(1));
    loop_ub = b_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b_a.size(0);
      for (d_i = 0; d_i < b_loop_ub; d_i++) {
        c_a[d_i + (c_a.size(0) * b_i)] =
            static_cast<real_T>(b_a[d_i + (b_a.size(0) * b_i)]);
      }
    }
    na = c_a.size(1);
    mc = c_a.size(0);
    b.set_size(c_a.size(0) - 2, c_a.size(1));
    loop_ub = c_a.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = c_a.size(0) - 2;
      for (d_i = 0; d_i < b_loop_ub; d_i++) {
        b[d_i + (b.size(0) * b_i)] = 0.0;
      }
    }
    if (c_a.size(1) != 0) {
      if ((c_a.size(0) - 2) != 0) {
        for (loop_ub = 0; loop_ub < na; loop_ub++) {
          for (b_loop_ub = 0; b_loop_ub < 3; b_loop_ub++) {
            for (b_i = 0; b_i <= (mc - 3); b_i++) {
              b[b_i + (b.size(0) * loop_ub)] =
                  b[b_i + (b.size(0) * loop_ub)] +
                  (((2.0 - (static_cast<real_T>(b_loop_ub))) - 1.0) *
                   c_a[(b_i + b_loop_ub) + (c_a.size(0) * loop_ub)]);
            }
          }
        }
      }
    }
    varargin_1.set_size(b.size(0), b.size(1));
    loop_ub = b.size(1);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_loop_ub = b.size(0);
      for (d_i = 0; d_i < b_loop_ub; d_i++) {
        varargin_1[d_i + (varargin_1.size(0) * b_i)] =
            static_cast<real32_T>(b[d_i + (b.size(0) * b_i)]);
      }
    }
  }
}

//
// Arguments    : const ::coder::array<real32_T, 2U> &a_tmp
//                const real_T pad[2]
//                ::coder::array<real32_T, 2U> &b_a
// Return Type  : void
//
void padImage_outSize(const ::coder::array<real32_T, 2U> &a_tmp,
                      const real_T pad[2], ::coder::array<real32_T, 2U> &b_a)
{
  if ((a_tmp.size(0) == 0) || (a_tmp.size(1) == 0)) {
    int32_T b_loop_ub;
    int32_T loop_ub;
    loop_ub = static_cast<int32_T>(static_cast<real_T>(
        (static_cast<real_T>(a_tmp.size(0))) + (2.0 * pad[0])));
    b_loop_ub = static_cast<int32_T>(static_cast<real_T>(
        (static_cast<real_T>(a_tmp.size(1))) + (2.0 * pad[1])));
    b_a.set_size(static_cast<int32_T>(static_cast<real_T>(
                     (static_cast<real_T>(a_tmp.size(0))) + (2.0 * pad[0]))),
                 static_cast<int32_T>(static_cast<real_T>(
                     (static_cast<real_T>(a_tmp.size(1))) + (2.0 * pad[1]))));
    for (int32_T b_i{0}; b_i < b_loop_ub; b_i++) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        b_a[i1 + (b_a.size(0) * b_i)] = 0.0F;
      }
    }
  } else {
    int32_T b_i;
    int32_T b_loop_ub;
    int32_T d_i;
    int32_T i1;
    int32_T j;
    int32_T loop_ub;
    b_a.set_size(static_cast<int32_T>(static_cast<real_T>(
                     (static_cast<real_T>(a_tmp.size(0))) + (2.0 * pad[0]))),
                 static_cast<int32_T>(static_cast<real_T>(
                     (static_cast<real_T>(a_tmp.size(1))) + (2.0 * pad[1]))));
    b_i = static_cast<int32_T>(pad[1]);
    for (j = 0; j < b_i; j++) {
      i1 = b_a.size(0);
      for (d_i = 0; d_i < i1; d_i++) {
        b_a[d_i + (b_a.size(0) * j)] = 0.0F;
      }
    }
    i1 = (a_tmp.size(1) + (static_cast<int32_T>(pad[1]))) + 1;
    loop_ub = b_a.size(1);
    for (j = i1; j <= loop_ub; j++) {
      b_loop_ub = b_a.size(0);
      for (d_i = 0; d_i < b_loop_ub; d_i++) {
        b_a[d_i + (b_a.size(0) * (j - 1))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = static_cast<int32_T>(pad[0]);
      for (d_i = 0; d_i < loop_ub; d_i++) {
        b_a[d_i + (b_a.size(0) * (j + b_i))] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = ((static_cast<int32_T>(pad[0])) + a_tmp.size(0)) + 1;
      b_loop_ub = b_a.size(0);
      for (d_i = loop_ub; d_i <= b_loop_ub; d_i++) {
        b_a[(d_i + (b_a.size(0) * (j + b_i))) - 1] = 0.0F;
      }
    }
    i1 = a_tmp.size(1);
    for (j = 0; j < i1; j++) {
      loop_ub = a_tmp.size(0);
      for (d_i = 0; d_i < loop_ub; d_i++) {
        b_a[(d_i + (static_cast<int32_T>(pad[0]))) +
            (b_a.size(0) * (j + b_i))] = a_tmp[d_i + (a_tmp.size(0) * j)];
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
