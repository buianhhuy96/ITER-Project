//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "eml_setop.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Declarations
namespace ITER {
namespace coder {
static void skip_to_last_equal_row(int *k, const ::coder::array<int, 2U> &b_x);

static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &b_x,
                                       const ::coder::array<int, 2U> &perm);

} // namespace coder
} // namespace ITER

// Function Definitions
//
// Arguments    : int *k
//                const ::coder::array<int, 2U> &b_x
// Return Type  : void
//
namespace ITER {
namespace coder {
static void skip_to_last_equal_row(int *k, const ::coder::array<int, 2U> &b_x)
{
  int j;
  bool exitg2;
  j = (*k) - 1;
  exitg2 = false;
  while ((!exitg2) && ((*k) < b_x.size(0))) {
    int b_k;
    int exitg1;
    b_k = 0;
    do {
      exitg1 = 0;
      if (b_k <= (b_x.size(1) - 1)) {
        if (b_x[j + (b_x.size(0) * b_k)] == b_x[(*k) + (b_x.size(0) * b_k)]) {
          b_k++;
        } else {
          exitg1 = 1;
        }
      } else {
        (*k)++;
        exitg1 = 2;
      }
    } while (exitg1 == 0);
    if (exitg1 == 1) {
      exitg2 = true;
    }
  }
}

//
// Arguments    : int *k
//                const ::coder::array<double, 2U> &b_x
//                const ::coder::array<int, 2U> &perm
// Return Type  : double
//
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &b_x,
                                       const ::coder::array<int, 2U> &perm)
{
  double b_xk;
  int exponent;
  bool exitg1;
  b_xk = b_x[perm[(*k) - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && ((*k) < b_x.size(1))) {
    double absx;
    double d;
    double r;
    absx = std::abs(b_xk / 2.0);
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
    if (std::abs(b_xk - d) < r) {
      (*k)++;
    } else if (std::isinf(d)) {
      if (std::isinf(b_xk)) {
        if ((d > 0.0) == (b_xk > 0.0)) {
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
  return b_xk;
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &c_ib
// Return Type  : void
//
void b_do_vectors(const ::coder::array<double, 2U> &b_a,
                  const ::coder::array<double, 2U> &b,
                  ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                  ::coder::array<int, 1U> &c_ib)
{
  ::coder::array<int, 2U> aperm;
  ::coder::array<int, 2U> bperm;
  ::coder::array<int, 1U> b_ia;
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
  c_ib.set_size(0);
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
        double e_bk;
        double r;
        bool guard1{false};
        bool guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, b_a, aperm);
        ialast = b_ialast;
        b_iblast = iblast;
        e_bk = skip_to_last_equal_value(&b_iblast, b, bperm);
        iblast = b_iblast;
        absx = std::abs(e_bk / 2.0);
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
        if (std::abs(e_bk - ak) < r) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(e_bk)) {
            if ((ak > 0.0) == (e_bk > 0.0)) {
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
          if (std::isnan(e_bk)) {
            p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            p = false;
          } else {
            p = (ak < e_bk);
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
  if ((static_cast<int>((nia + 1) < 4)) != 0) {
    for (int k{0}; k <= nia; k++) {
      c[k] = b_a[ia[k] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= nia; k++) {
      c[k] = b_a[ia[k] - 1];
    }
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
// Arguments    : const ::coder::array<int, 2U> &b_a
//                const ::coder::array<int, 2U> &b
//                ::coder::array<int, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &c_ib
// Return Type  : void
//
void do_rows(const ::coder::array<int, 2U> &b_a,
             const ::coder::array<int, 2U> &b, ::coder::array<int, 2U> &c,
             ::coder::array<int, 1U> &ia, ::coder::array<int, 1U> &c_ib)
{
  int b_c;
  int b_i;
  int b_u0;
  int b_u1;
  int c_u1;
  int i2;
  int iafirst;
  int ialast;
  int ibfirst;
  int iblast;
  int loop_ub;
  int nacols;
  int nc;
  int ncmax;
  int u0;
  int y;
  nacols = b_a.size(1);
  u0 = b_a.size(0);
  b_u1 = b.size(0);
  if (u0 <= b_u1) {
    ncmax = u0;
  } else {
    ncmax = b_u1;
  }
  b_u0 = b_a.size(1);
  c_u1 = b.size(1);
  if (b_u0 <= c_u1) {
    y = b_u0;
  } else {
    y = c_u1;
  }
  c.set_size(ncmax, y);
  nc = 0;
  ia.set_size(ncmax);
  c_ib.set_size(ncmax);
  iafirst = 1;
  ibfirst = 1;
  ialast = 1;
  iblast = 1;
  int exitg2;
  do {
    exitg2 = 0;
    if (iafirst <= b_a.size(0)) {
      if (ibfirst <= b.size(0)) {
        int k;
        skip_to_last_equal_row(&ialast, b_a);
        skip_to_last_equal_row(&iblast, b);
        k = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (k <= (b_a.size(1) - 1)) {
            int i1;
            int i3;
            i1 = b_a[(iafirst + (b_a.size(0) * k)) - 1];
            i3 = b[(ibfirst + (b.size(0) * k)) - 1];
            if (i1 == i3) {
              k++;
            } else {
              if (i1 < i3) {
                ialast++;
                iafirst = ialast;
              } else {
                iblast++;
                ibfirst = iblast;
              }
              exitg1 = 1;
            }
          } else {
            nc++;
            for (int b_k{0}; b_k < nacols; b_k++) {
              c[(nc + (c.size(0) * b_k)) - 1] =
                  b_a[(iafirst + (b_a.size(0) * b_k)) - 1];
            }
            ia[nc - 1] = iafirst;
            c_ib[nc - 1] = ibfirst;
            ialast++;
            iafirst = ialast;
            iblast++;
            ibfirst = iblast;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        exitg2 = 1;
      }
    } else {
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  if (1 > nc) {
    b_i = 0;
  } else {
    b_i = nc;
  }
  ia.set_size(b_i);
  if (1 > nc) {
    i2 = 0;
  } else {
    i2 = nc;
  }
  c_ib.set_size(i2);
  if (1 > nc) {
    loop_ub = 0;
  } else {
    loop_ub = nc;
  }
  b_c = c.size(1) - 1;
  for (int i4{0}; i4 <= b_c; i4++) {
    for (int i5{0}; i5 < loop_ub; i5++) {
      c[i5 + (loop_ub * i4)] = c[i5 + (c.size(0) * i4)];
    }
  }
  c.set_size(loop_ub, b_c + 1);
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &c_ib
// Return Type  : void
//
void do_vectors(const ::coder::array<double, 2U> &b_a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                ::coder::array<int, 1U> &c_ib)
{
  ::coder::array<int, 2U> aperm;
  ::coder::array<int, 1U> b_ia;
  ::coder::array<int, 1U> bperm;
  int b_exponent;
  int b_ialast;
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
  c_ib.set_size(0);
  internal::sortIdx(b_a, aperm);
  internal::b_sortIdx(b, bperm);
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
        double c_r;
        double e_bk;
        int b_iblast;
        bool exitg2;
        bool guard1{false};
        bool guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, b_a, aperm);
        ialast = b_ialast;
        b_iblast = iblast;
        e_bk = b[bperm[iblast - 1] - 1];
        exitg2 = false;
        while ((!exitg2) && (b_iblast < b.size(0))) {
          double absx;
          double d;
          double r;
          absx = std::abs(e_bk / 2.0);
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
          d = b[bperm[b_iblast] - 1];
          if (std::abs(e_bk - d) < r) {
            b_iblast++;
          } else if (std::isinf(d)) {
            if (std::isinf(e_bk)) {
              if ((d > 0.0) == (e_bk > 0.0)) {
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
        b_absx = std::abs(e_bk / 2.0);
        if ((!std::isinf(b_absx)) && (!std::isnan(b_absx))) {
          if (b_absx <= 2.2250738585072014E-308) {
            c_r = 4.94065645841247E-324;
          } else {
            (void)frexp(b_absx, &b_exponent);
            c_r = std::ldexp(1.0, b_exponent - 53);
          }
        } else {
          c_r = rtNaN;
        }
        guard1 = false;
        guard2 = false;
        if (std::abs(e_bk - ak) < c_r) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(e_bk)) {
            if ((ak > 0.0) == (e_bk > 0.0)) {
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
          if (std::isnan(e_bk)) {
            p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            p = false;
          } else {
            p = (ak < e_bk);
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
  if ((static_cast<int>((nia + 1) < 4)) != 0) {
    for (int k{0}; k <= nia; k++) {
      c[k] = b_a[ia[k] - 1];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k <= nia; k++) {
      c[k] = b_a[ia[k] - 1];
    }
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

} // namespace coder
} // namespace ITER

//
// File trailer for eml_setop.cpp
//
// [EOF]
//
