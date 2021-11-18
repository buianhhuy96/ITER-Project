//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "eml_setop.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Declarations
namespace coder {
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &b_x,
                                       const ::coder::array<int, 2U> &perm);

}

// Function Definitions
//
// Arguments    : int *k
//                const ::coder::array<double, 2U> &b_x
//                const ::coder::array<int, 2U> &perm
// Return Type  : double
//
namespace coder {
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &b_x,
                                       const ::coder::array<int, 2U> &perm)
{
  double xk;
  int exponent;
  bool exitg1;
  xk = b_x[perm[(*k) - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && ((*k) < b_x.size(1))) {
    double absx;
    double d;
    double r;
    absx = std::abs(xk / 2.0);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        r = 4.94065645841247E-324;
      } else {
        (void)frexp(absx, &exponent);
        r = std::ldexp(1.0, exponent - 53);
      }
    } else {
      r = rtNaN;
    }
    d = b_x[perm[*k] - 1];
    if (std::abs(xk - d) < r) {
      (*k)++;
    } else if (std::isinf(d)) {
      if (std::isinf(xk)) {
        if ((d > 0.0) == (xk > 0.0)) {
          (*k)++;
        } else {
          exitg1 = true;
        }
      } else {
        exitg1 = true;
      }
    } else {
      exitg1 = true;
    }
  }
  return xk;
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &b_ib
// Return Type  : void
//
void b_do_vectors(const ::coder::array<double, 2U> &b_a,
                  const ::coder::array<double, 2U> &b,
                  ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                  ::coder::array<int, 1U> &b_ib)
{
  array<int, 2U> aperm;
  array<int, 2U> bperm;
  array<int, 1U> b_ia;
  int b_ialast;
  int b_iblast;
  int c_a;
  int exponent;
  int iafirst;
  int ialast;
  int iblast;
  int na;
  int nc;
  int nia;
  na = b_a.size(1);
  c.set_size(1, b_a.size(1));
  ia.set_size(b_a.size(1));
  b_ib.set_size(0);
  internal::sortIdx(b_a, aperm);
  internal::sortIdx(b, bperm);
  nc = 0;
  nia = -1;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  int exitg1;
  do {
    exitg1 = 0;
    if (ialast <= na) {
      if (iblast <= b.size(1)) {
        double absx;
        double ak;
        double b_bk;
        double r;
        bool guard1{false};
        bool guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, b_a, aperm);
        ialast = b_ialast;
        b_iblast = iblast;
        b_bk = skip_to_last_equal_value(&b_iblast, b, bperm);
        iblast = b_iblast;
        absx = std::abs(b_bk / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            r = 4.94065645841247E-324;
          } else {
            (void)frexp(absx, &exponent);
            r = std::ldexp(1.0, exponent - 53);
          }
        } else {
          r = rtNaN;
        }
        guard1 = false;
        guard2 = false;
        if (std::abs(b_bk - ak) < r) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(b_bk)) {
            if ((ak > 0.0) == (b_bk > 0.0)) {
              guard2 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
        if (guard2) {
          ialast = b_ialast + 1;
          iafirst = b_ialast;
          iblast = b_iblast + 1;
        }
        if (guard1) {
          bool p;
          if (std::isnan(b_bk)) {
            p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            p = false;
          } else {
            p = (ak < b_bk);
          }
          if (p) {
            nc++;
            nia++;
            ia[nia] = aperm[iafirst];
            ialast = b_ialast + 1;
            iafirst = b_ialast;
          } else {
            iblast = b_iblast + 1;
          }
        }
      } else {
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  while (ialast <= na) {
    c_a = ialast;
    (void)skip_to_last_equal_value(&c_a, b_a, aperm);
    nc++;
    nia++;
    ia[nia] = aperm[iafirst];
    ialast = c_a + 1;
    iafirst = c_a;
  }
  if (b_a.size(1) > 0) {
    int b_i;
    if (1 > (nia + 1)) {
      b_i = -1;
    } else {
      b_i = nia;
    }
    ia.set_size(b_i + 1);
  }
  internal::b_sort(ia, b_ia);
  for (int k{0}; k <= nia; k++) {
    c[k] = b_a[ia[k] - 1];
  }
  if (b_a.size(1) > 0) {
    int i1;
    if (1 > nc) {
      i1 = 0;
    } else {
      i1 = nc;
    }
    c.set_size(c.size(0), i1);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &b_ib
// Return Type  : void
//
void do_vectors(const ::coder::array<double, 2U> &b_a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                ::coder::array<int, 1U> &b_ib)
{
  array<int, 2U> aperm;
  array<int, 1U> b_ia;
  array<int, 1U> bperm;
  array<int, 1U> iwork;
  array<int, 1U> r;
  int b_exponent;
  int b_ialast;
  int c_a;
  int exponent;
  int h_n;
  int iafirst;
  int ialast;
  int iblast;
  int loop_ub;
  int na;
  int nc;
  int nia;
  na = b_a.size(1);
  c.set_size(1, b_a.size(1));
  ia.set_size(b_a.size(1));
  b_ib.set_size(0);
  internal::sortIdx(b_a, aperm);
  h_n = b.size(0) + 1;
  bperm.set_size(b.size(0));
  loop_ub = b.size(0);
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    bperm[b_i] = 0;
  }
  if (b.size(0) != 0) {
    int b_loop_ub;
    int c_i;
    int c_loop_ub;
    int i2;
    bool guard1{false};
    b_loop_ub = b.size(0);
    r.set_size(b.size(0));
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      r[i1] = 0;
    }
    iwork.set_size(b.size(0));
    i2 = b.size(0) - 1;
    for (int k{1}; k <= i2; k += 2) {
      guard1 = false;
      if (b[k - 1] <= b[k]) {
        guard1 = true;
      } else if (std::isnan(b[k])) {
        guard1 = true;
      } else {
        r[k - 1] = k + 1;
        r[k] = k;
      }
      if (guard1) {
        r[k - 1] = k;
        r[k] = k + 1;
      }
    }
    if ((b.size(0) & 1) != 0) {
      r[b.size(0) - 1] = b.size(0);
    }
    c_i = 2;
    while (c_i < (h_n - 1)) {
      int b_i2;
      int j;
      int pEnd;
      b_i2 = c_i * 2;
      j = 1;
      pEnd = c_i + 1;
      while (pEnd < h_n) {
        int c_k;
        int kEnd;
        int p;
        int q;
        int qEnd;
        p = j;
        q = pEnd - 1;
        qEnd = j + b_i2;
        if (qEnd > h_n) {
          qEnd = h_n;
        }
        c_k = 0;
        kEnd = qEnd - j;
        while ((c_k + 1) <= kEnd) {
          double b_d1;
          int i6;
          b_d1 = b[r[q] - 1];
          i6 = r[p - 1];
          guard1 = false;
          if (b[i6 - 1] <= b_d1) {
            guard1 = true;
          } else if (std::isnan(b_d1)) {
            guard1 = true;
          } else {
            iwork[c_k] = r[q];
            q++;
            if ((q + 1) == qEnd) {
              while (p < pEnd) {
                c_k++;
                iwork[c_k] = r[p - 1];
                p++;
              }
            }
          }
          if (guard1) {
            iwork[c_k] = i6;
            p++;
            if (p == pEnd) {
              while ((q + 1) < qEnd) {
                c_k++;
                iwork[c_k] = r[q];
                q++;
              }
            }
          }
          c_k++;
        }
        for (int d_k{0}; d_k < kEnd; d_k++) {
          r[(j + d_k) - 1] = iwork[d_k];
        }
        j = qEnd;
        pEnd = qEnd + c_i;
      }
      c_i = b_i2;
    }
    c_loop_ub = r.size(0);
    for (int i3{0}; i3 < c_loop_ub; i3++) {
      bperm[i3] = r[i3];
    }
  }
  nc = 0;
  nia = -1;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  int exitg1;
  do {
    exitg1 = 0;
    if (ialast <= na) {
      if (iblast <= b.size(0)) {
        double ak;
        double b_absx;
        double b_bk;
        double d_r;
        int b_iblast;
        bool b_guard1{false};
        bool exitg2;
        bool guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, b_a, aperm);
        ialast = b_ialast;
        b_iblast = iblast;
        b_bk = b[bperm[iblast - 1] - 1];
        exitg2 = false;
        while ((!exitg2) && (b_iblast < b.size(0))) {
          double absx;
          double c_r;
          double d;
          absx = std::abs(b_bk / 2.0);
          if ((!std::isinf(absx)) && (!std::isnan(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              c_r = 4.94065645841247E-324;
            } else {
              (void)frexp(absx, &exponent);
              c_r = std::ldexp(1.0, exponent - 53);
            }
          } else {
            c_r = rtNaN;
          }
          d = b[bperm[b_iblast] - 1];
          if (std::abs(b_bk - d) < c_r) {
            b_iblast++;
          } else if (std::isinf(d)) {
            if (std::isinf(b_bk)) {
              if ((d > 0.0) == (b_bk > 0.0)) {
                b_iblast++;
              } else {
                exitg2 = true;
              }
            } else {
              exitg2 = true;
            }
          } else {
            exitg2 = true;
          }
        }
        iblast = b_iblast;
        b_absx = std::abs(b_bk / 2.0);
        if ((!std::isinf(b_absx)) && (!std::isnan(b_absx))) {
          if (b_absx <= 2.2250738585072014E-308) {
            d_r = 4.94065645841247E-324;
          } else {
            (void)frexp(b_absx, &b_exponent);
            d_r = std::ldexp(1.0, b_exponent - 53);
          }
        } else {
          d_r = rtNaN;
        }
        b_guard1 = false;
        guard2 = false;
        if (std::abs(b_bk - ak) < d_r) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(b_bk)) {
            if ((ak > 0.0) == (b_bk > 0.0)) {
              guard2 = true;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }
        } else {
          b_guard1 = true;
        }
        if (guard2) {
          ialast = b_ialast + 1;
          iafirst = b_ialast;
          iblast = b_iblast + 1;
        }
        if (b_guard1) {
          bool b_p;
          if (std::isnan(b_bk)) {
            b_p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            b_p = false;
          } else {
            b_p = (ak < b_bk);
          }
          if (b_p) {
            nc++;
            nia++;
            ia[nia] = aperm[iafirst];
            ialast = b_ialast + 1;
            iafirst = b_ialast;
          } else {
            iblast = b_iblast + 1;
          }
        }
      } else {
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  while (ialast <= na) {
    c_a = ialast;
    (void)skip_to_last_equal_value(&c_a, b_a, aperm);
    nc++;
    nia++;
    ia[nia] = aperm[iafirst];
    ialast = c_a + 1;
    iafirst = c_a;
  }
  if (b_a.size(1) > 0) {
    int i4;
    if (1 > (nia + 1)) {
      i4 = -1;
    } else {
      i4 = nia;
    }
    ia.set_size(i4 + 1);
  }
  internal::b_sort(ia, b_ia);
  for (int b_k{0}; b_k <= nia; b_k++) {
    c[b_k] = b_a[ia[b_k] - 1];
  }
  if (b_a.size(1) > 0) {
    int i5;
    if (1 > nc) {
      i5 = 0;
    } else {
      i5 = nc;
    }
    c.set_size(c.size(0), i5);
  }
}

} // namespace coder

//
// File trailer for eml_setop.cpp
//
// [EOF]
//
