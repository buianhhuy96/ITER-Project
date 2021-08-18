//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2AXPYValidCMP.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
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
  array<double, 1U> cj;
  int b_i;
  int jb;
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
    c.set_size(a.size(0), nc);
    nc--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(cj, b_i, jb)

    for (int j = 0; j <= nc; j++) {
      cj.set_size(mc);
      for (b_i = 0; b_i < mc; b_i++) {
        cj[b_i] = 0.0;
      }
      for (jb = 0; jb < 3; jb++) {
        for (b_i = 0; b_i < mc; b_i++) {
          cj[b_i] = cj[b_i] + (((2.0 - (static_cast<double>(jb))) - 1.0) *
                               a[b_i + (a.size(0) * (j + jb))]);
        }
      }
      jb = cj.size(0);
      for (b_i = 0; b_i < jb; b_i++) {
        c[b_i + (c.size(0) * j)] = cj[b_i];
      }
    }
  }
  if (guard1) {
    c.set_size(a.size(0), nc);
    for (int i{0}; i < nc; i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * i)] = 0.0;
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
  array<double, 1U> cj;
  double bij;
  int b_i;
  int ib;
  int jb;
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
    c.set_size(mc, nc);
    nc--;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    cj, bij, ib, jb, b_i)

    for (int j = 0; j <= nc; j++) {
      cj.set_size(mc);
      for (ib = 0; ib < mc; ib++) {
        cj[ib] = 0.0;
      }
      for (jb = 0; jb < 7; jb++) {
        for (ib = 0; ib < 7; ib++) {
          bij = b[6 - jb][6 - ib];
          for (b_i = 0; b_i < mc; b_i++) {
            cj[b_i] = cj[b_i] + (bij * a[(b_i + ib) + (a.size(0) * (j + jb))]);
          }
        }
      }
      jb = cj.size(0);
      for (ib = 0; ib < jb; ib++) {
        c[ib + (c.size(0) * j)] = cj[ib];
      }
    }
  }
  if (guard1) {
    c.set_size(mc, nc);
    for (int i{0}; i < nc; i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * i)] = 0.0;
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
  array<double, 1U> cj;
  int b_i;
  int ib;
  int mc;
  int ub_loop;
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
    c.set_size(mc, a.size(1));
    ub_loop = a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(cj, b_i, ib)

    for (int j = 0; j <= ub_loop; j++) {
      cj.set_size(mc);
      for (b_i = 0; b_i < mc; b_i++) {
        cj[b_i] = 0.0;
      }
      for (ib = 0; ib < 3; ib++) {
        for (b_i = 0; b_i < mc; b_i++) {
          cj[b_i] = cj[b_i] + (((2.0 - (static_cast<double>(ib))) - 1.0) *
                               a[(b_i + ib) + (a.size(0) * j)]);
        }
      }
      ib = cj.size(0);
      for (b_i = 0; b_i < ib; b_i++) {
        c[b_i + (c.size(0) * j)] = cj[b_i];
      }
    }
  }
  if (guard1) {
    c.set_size(mc, a.size(1));
    ub_loop = a.size(1);
    for (int i{0}; i < ub_loop; i++) {
      for (int i1{0}; i1 < mc; i1++) {
        c[i1 + (c.size(0) * i)] = 0.0;
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
