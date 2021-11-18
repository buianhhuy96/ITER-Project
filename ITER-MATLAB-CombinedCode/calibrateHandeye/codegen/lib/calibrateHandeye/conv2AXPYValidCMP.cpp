//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2AXPYValidCMP.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "conv2AXPYValidCMP.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
namespace internal {
void b_conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
                         ::coder::array<double, 2U> &c)
{
  array<double, 1U> b_cj;
  int c_i;
  int jb;
  int mc;
  int nc;
  bool guard1{false};
  mc = b_a.size(0);
  if (b_a.size(1) < 2) {
    nc = 0;
  } else {
    nc = b_a.size(1) - 2;
  }
  guard1 = false;
  if ((b_a.size(0) == 0) || (b_a.size(1) == 0)) {
    guard1 = true;
  } else if (nc == 0) {
    guard1 = true;
  } else {
    c.set_size(b_a.size(0), nc);
    nc--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_cj, c_i, \
                                                                    jb)

    for (int j = 0; j <= nc; j++) {
      b_cj.set_size(mc);
      for (c_i = 0; c_i < mc; c_i++) {
        b_cj[c_i] = 0.0;
      }
      for (jb = 0; jb < 3; jb++) {
        for (c_i = 0; c_i < mc; c_i++) {
          b_cj[c_i] = b_cj[c_i] + (((2.0 - (static_cast<double>(jb))) - 1.0) *
                                   b_a[c_i + (b_a.size(0) * (j + jb))]);
        }
      }
      jb = b_cj.size(0);
      for (c_i = 0; c_i < jb; c_i++) {
        c[c_i + (c.size(0) * j)] = b_cj[c_i];
      }
    }
  }
  if (guard1) {
    c.set_size(b_a.size(0), nc);
    for (int b_i{0}; b_i < nc; b_i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * b_i)] = 0.0;
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void c_conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
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
  int c_i;
  int ib;
  int jb;
  int mc;
  int nc;
  bool guard1{false};
  if (b_a.size(0) < 6) {
    mc = 0;
  } else {
    mc = b_a.size(0) - 6;
  }
  if (b_a.size(1) < 6) {
    nc = 0;
  } else {
    nc = b_a.size(1) - 6;
  }
  guard1 = false;
  if ((b_a.size(0) == 0) || (b_a.size(1) == 0)) {
    guard1 = true;
  } else if ((mc == 0) || (nc == 0)) {
    guard1 = true;
  } else {
    c.set_size(mc, nc);
    nc--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    b_cj, bij, ib, jb, c_i)

    for (int j = 0; j <= nc; j++) {
      b_cj.set_size(mc);
      for (ib = 0; ib < mc; ib++) {
        b_cj[ib] = 0.0;
      }
      for (jb = 0; jb < 7; jb++) {
        for (ib = 0; ib < 7; ib++) {
          bij = b[6 - jb][6 - ib];
          for (c_i = 0; c_i < mc; c_i++) {
            b_cj[c_i] =
                b_cj[c_i] + (bij * b_a[(c_i + ib) + (b_a.size(0) * (j + jb))]);
          }
        }
      }
      jb = b_cj.size(0);
      for (ib = 0; ib < jb; ib++) {
        c[ib + (c.size(0) * j)] = b_cj[ib];
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
// Arguments    : const ::coder::array<double, 2U> &b_a
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
void conv2AXPYValidCMP(const ::coder::array<double, 2U> &b_a,
                       ::coder::array<double, 2U> &c)
{
  array<double, 1U> b_cj;
  int c_i;
  int ib;
  int mc;
  int ub_loop;
  bool guard1{false};
  if (b_a.size(0) < 2) {
    mc = 0;
  } else {
    mc = b_a.size(0) - 2;
  }
  guard1 = false;
  if ((b_a.size(0) == 0) || (b_a.size(1) == 0)) {
    guard1 = true;
  } else if (mc == 0) {
    guard1 = true;
  } else {
    c.set_size(mc, b_a.size(1));
    ub_loop = b_a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_cj, c_i, \
                                                                    ib)

    for (int j = 0; j <= ub_loop; j++) {
      b_cj.set_size(mc);
      for (c_i = 0; c_i < mc; c_i++) {
        b_cj[c_i] = 0.0;
      }
      for (ib = 0; ib < 3; ib++) {
        for (c_i = 0; c_i < mc; c_i++) {
          b_cj[c_i] = b_cj[c_i] + (((2.0 - (static_cast<double>(ib))) - 1.0) *
                                   b_a[(c_i + ib) + (b_a.size(0) * j)]);
        }
      }
      ib = b_cj.size(0);
      for (c_i = 0; c_i < ib; c_i++) {
        c[c_i + (c.size(0) * j)] = b_cj[c_i];
      }
    }
  }
  if (guard1) {
    c.set_size(mc, b_a.size(1));
    ub_loop = b_a.size(1);
    for (int b_i{0}; b_i < ub_loop; b_i++) {
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
