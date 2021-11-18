//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2AXPYValidCMP.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 26-Oct-2021 15:20:59
//

// Include Files
#include "conv2AXPYValidCMP.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void b_conv2AXPYValidCMP(const ::coder::array<double, 2U> &a,
                         ::coder::array<double, 2U> &c)
{
  array<double, 1U> b_cj;
  int c_i;
  int i2;
  int i3;
  int jb;
  int loop_ub;
  int mc;
  int nc;
  bool guard1{false};
  mc = a.size(0);
  if (a.size(1) < 2) {
    nc = 0;
  } else {
    nc = a.size(1) - 2;
  }
  guard1 = false;
  if ((a.size(0) == 0) || (a.size(1) == 0)) {
    guard1 = true;
  } else if (nc == 0) {
    guard1 = true;
  } else {
    int ub_loop;
    c.set_size(a.size(0), nc);
    ub_loop = nc - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_cj, i2, jb, loop_ub, c_i, i3)

    for (int j = 0; j <= ub_loop; j++) {
      b_cj.set_size(mc);
      for (i2 = 0; i2 < mc; i2++) {
        b_cj[i2] = 0.0;
      }
      for (jb = 0; jb < 3; jb++) {
        for (c_i = 0; c_i < mc; c_i++) {
          b_cj[c_i] = b_cj[c_i] + (((2.0 - (static_cast<double>(jb))) - 1.0) *
                                   a[c_i + (a.size(0) * (j + jb))]);
        }
      }
      loop_ub = b_cj.size(0);
      for (i3 = 0; i3 < loop_ub; i3++) {
        c[i3 + (c.size(0) * j)] = b_cj[i3];
      }
    }
  }
  if (guard1) {
    c.set_size(a.size(0), nc);
    for (int b_i{0}; b_i < nc; b_i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * b_i)] = 0.0;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void c_conv2AXPYValidCMP(const ::coder::array<double, 2U> &a,
                         ::coder::array<double, 2U> &c)
{
  static const double b[7][7]{
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
  array<double, 1U> b_cj;
  double bij;
  int b_ib;
  int c_i;
  int i2;
  int i3;
  int jb;
  int loop_ub;
  int mc;
  int nc;
  bool guard1{false};
  if (a.size(0) < 6) {
    mc = 0;
  } else {
    mc = a.size(0) - 6;
  }
  if (a.size(1) < 6) {
    nc = 0;
  } else {
    nc = a.size(1) - 6;
  }
  guard1 = false;
  if ((a.size(0) == 0) || (a.size(1) == 0)) {
    guard1 = true;
  } else if ((mc == 0) || (nc == 0)) {
    guard1 = true;
  } else {
    int ub_loop;
    c.set_size(mc, nc);
    ub_loop = nc - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_cj, bij, i2, jb, loop_ub, b_ib, c_i, i3)

    for (int j = 0; j <= ub_loop; j++) {
      b_cj.set_size(mc);
      for (i2 = 0; i2 < mc; i2++) {
        b_cj[i2] = 0.0;
      }
      for (jb = 0; jb < 7; jb++) {
        for (b_ib = 0; b_ib < 7; b_ib++) {
          bij = b[6 - jb][6 - b_ib];
          for (c_i = 0; c_i < mc; c_i++) {
            b_cj[c_i] =
                b_cj[c_i] + (bij * a[(c_i + b_ib) + (a.size(0) * (j + jb))]);
          }
        }
      }
      loop_ub = b_cj.size(0);
      for (i3 = 0; i3 < loop_ub; i3++) {
        c[i3 + (c.size(0) * j)] = b_cj[i3];
      }
    }
  }
  if (guard1) {
    c.set_size(mc, nc);
    for (int b_i{0}; b_i < nc; b_i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * b_i)] = 0.0;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void conv2AXPYValidCMP(const ::coder::array<double, 2U> &a,
                       ::coder::array<double, 2U> &c)
{
  array<double, 1U> b_cj;
  int b_ib;
  int b_loop_ub;
  int c_i;
  int i2;
  int i3;
  int mc;
  bool guard1{false};
  if (a.size(0) < 2) {
    mc = 0;
  } else {
    mc = a.size(0) - 2;
  }
  guard1 = false;
  if ((a.size(0) == 0) || (a.size(1) == 0)) {
    guard1 = true;
  } else if (mc == 0) {
    guard1 = true;
  } else {
    int ub_loop;
    c.set_size(mc, a.size(1));
    ub_loop = a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_cj, i2, b_ib, b_loop_ub, c_i, i3)

    for (int j = 0; j <= ub_loop; j++) {
      b_cj.set_size(mc);
      for (i2 = 0; i2 < mc; i2++) {
        b_cj[i2] = 0.0;
      }
      for (b_ib = 0; b_ib < 3; b_ib++) {
        for (c_i = 0; c_i < mc; c_i++) {
          b_cj[c_i] = b_cj[c_i] + (((2.0 - (static_cast<double>(b_ib))) - 1.0) *
                                   a[(c_i + b_ib) + (a.size(0) * j)]);
        }
      }
      b_loop_ub = b_cj.size(0);
      for (i3 = 0; i3 < b_loop_ub; i3++) {
        c[i3 + (c.size(0) * j)] = b_cj[i3];
      }
    }
  }
  if (guard1) {
    int loop_ub;
    c.set_size(mc, a.size(1));
    loop_ub = a.size(1);
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * b_i)] = 0.0;
      }
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for conv2AXPYValidCMP.cpp
//
// [EOF]
//
