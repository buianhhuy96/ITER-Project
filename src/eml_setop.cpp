//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
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
                                       const ::coder::array<double, 2U> &x,
                                       const ::coder::array<int, 2U> &perm);

}

// Function Definitions
//
// Arguments    : int *k
//                const ::coder::array<double, 2U> &x
//                const ::coder::array<int, 2U> &perm
// Return Type  : double
//
namespace coder {
static double skip_to_last_equal_value(int *k,
                                       const ::coder::array<double, 2U> &x,
                                       const ::coder::array<int, 2U> &perm)
{
  double xk;
  int exponent;
  boolean_T exitg1;
  xk = x[perm[(*k) - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && ((*k) < x.size(1))) {
    double absx;
    double d;
    absx = std::abs(xk / 2.0);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        (void)frexp(absx, &exponent);
        absx = std::ldexp(1.0, exponent - 53);
      }
    } else {
      absx = rtNaN;
    }
    d = x[perm[*k] - 1];
    if (std::abs(xk - d) < absx) {
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
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &ib
// Return Type  : void
//
void do_vectors(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 2U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                ::coder::array<int, 1U> &ib)
{
  array<int, 2U> aperm;
  array<int, 2U> bperm;
  array<int, 1U> b_ia;
  int b_ialast;
  int exponent;
  int iafirst;
  int ialast;
  int iblast;
  int na;
  int nc;
  int nia;
  na = a.size(1);
  c.set_size(1, a.size(1));
  ia.set_size(a.size(1));
  ib.set_size(0);
  internal::sortIdx(a, aperm);
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
        double bk;
        boolean_T guard1{false};
        boolean_T guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, a, aperm);
        ialast = b_ialast;
        bk = skip_to_last_equal_value(&iblast, b, bperm);
        absx = std::abs(bk / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            absx = 4.94065645841247E-324;
          } else {
            (void)frexp(absx, &exponent);
            absx = std::ldexp(1.0, exponent - 53);
          }
        } else {
          absx = rtNaN;
        }
        guard1 = false;
        guard2 = false;
        if (std::abs(bk - ak) < absx) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(bk)) {
            if ((ak > 0.0) == (bk > 0.0)) {
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
          iblast++;
        }
        if (guard1) {
          boolean_T p;
          if (std::isnan(bk)) {
            p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            p = false;
          } else {
            p = (ak < bk);
          }
          if (p) {
            nc++;
            nia++;
            ia[nia] = aperm[iafirst];
            ialast = b_ialast + 1;
            iafirst = b_ialast;
          } else {
            iblast++;
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
    iblast = ialast;
    (void)skip_to_last_equal_value(&iblast, a, aperm);
    nc++;
    nia++;
    ia[nia] = aperm[iafirst];
    ialast = iblast + 1;
    iafirst = iblast;
  }
  if (a.size(1) > 0) {
    if (1 > (nia + 1)) {
      na = -1;
    } else {
      na = nia;
    }
    ia.set_size(na + 1);
  }
  internal::sort(ia, b_ia);
  for (iblast = 0; iblast <= nia; iblast++) {
    c[iblast] = a[ia[iblast] - 1];
  }
  if (a.size(1) > 0) {
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(c.size(0), nc);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 2U> &c
//                ::coder::array<int, 1U> &ia
//                ::coder::array<int, 1U> &ib
// Return Type  : void
//
void do_vectors(const ::coder::array<double, 2U> &a,
                const ::coder::array<double, 1U> &b,
                ::coder::array<double, 2U> &c, ::coder::array<int, 1U> &ia,
                ::coder::array<int, 1U> &ib)
{
  array<int, 2U> aperm;
  array<int, 1U> b_ia;
  array<int, 1U> bperm;
  array<int, 1U> iwork;
  array<int, 1U> r;
  double absx;
  int b_exponent;
  int b_i;
  int exponent;
  int i;
  int i2;
  int j;
  int k;
  int n;
  int na;
  int p;
  int pEnd;
  int q;
  na = a.size(1);
  c.set_size(1, a.size(1));
  ia.set_size(a.size(1));
  ib.set_size(0);
  internal::sortIdx(a, aperm);
  n = b.size(0) + 1;
  bperm.set_size(b.size(0));
  i = b.size(0);
  for (b_i = 0; b_i < i; b_i++) {
    bperm[b_i] = 0;
  }
  if (b.size(0) != 0) {
    boolean_T guard1{false};
    i = b.size(0);
    r.set_size(b.size(0));
    for (b_i = 0; b_i < i; b_i++) {
      r[b_i] = 0;
    }
    iwork.set_size(b.size(0));
    b_i = b.size(0) - 1;
    for (k = 1; k <= b_i; k += 2) {
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
    i = 2;
    while (i < (n - 1)) {
      i2 = i * 2;
      j = 1;
      pEnd = i + 1;
      while (pEnd < n) {
        int kEnd;
        int qEnd;
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > n) {
          qEnd = n;
        }
        k = 0;
        kEnd = qEnd - j;
        while ((k + 1) <= kEnd) {
          absx = b[r[q] - 1];
          b_i = r[p - 1];
          guard1 = false;
          if (b[b_i - 1] <= absx) {
            guard1 = true;
          } else if (std::isnan(absx)) {
            guard1 = true;
          } else {
            iwork[k] = r[q];
            q++;
            if ((q + 1) == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = r[p - 1];
                p++;
              }
            }
          }
          if (guard1) {
            iwork[k] = b_i;
            p++;
            if (p == pEnd) {
              while ((q + 1) < qEnd) {
                k++;
                iwork[k] = r[q];
                q++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          r[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
        pEnd = qEnd + i;
      }
      i = i2;
    }
    i = r.size(0);
    for (b_i = 0; b_i < i; b_i++) {
      bperm[b_i] = r[b_i];
    }
  }
  p = 0;
  q = -1;
  j = 0;
  pEnd = 1;
  i = 1;
  int exitg1;
  do {
    exitg1 = 0;
    if (pEnd <= na) {
      if (i <= b.size(0)) {
        double ak;
        double b_r;
        double bk;
        boolean_T b_guard1{false};
        boolean_T exitg2;
        boolean_T guard2{false};
        i2 = pEnd;
        ak = skip_to_last_equal_value(&i2, a, aperm);
        pEnd = i2;
        bk = b[bperm[i - 1] - 1];
        exitg2 = false;
        while ((!exitg2) && (i < b.size(0))) {
          absx = std::abs(bk / 2.0);
          if ((!std::isinf(absx)) && (!std::isnan(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              b_r = 4.94065645841247E-324;
            } else {
              (void)frexp(absx, &b_exponent);
              b_r = std::ldexp(1.0, b_exponent - 53);
            }
          } else {
            b_r = rtNaN;
          }
          absx = b[bperm[i] - 1];
          if (std::abs(bk - absx) < b_r) {
            i++;
          } else if (std::isinf(absx)) {
            if (std::isinf(bk)) {
              if ((absx > 0.0) == (bk > 0.0)) {
                i++;
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
        absx = std::abs(bk / 2.0);
        if ((!std::isinf(absx)) && (!std::isnan(absx))) {
          if (absx <= 2.2250738585072014E-308) {
            b_r = 4.94065645841247E-324;
          } else {
            (void)frexp(absx, &exponent);
            b_r = std::ldexp(1.0, exponent - 53);
          }
        } else {
          b_r = rtNaN;
        }
        b_guard1 = false;
        guard2 = false;
        if (std::abs(bk - ak) < b_r) {
          guard2 = true;
        } else if (std::isinf(ak)) {
          if (std::isinf(bk)) {
            if ((ak > 0.0) == (bk > 0.0)) {
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
          pEnd = i2 + 1;
          j = i2;
          i++;
        }
        if (b_guard1) {
          boolean_T b_p;
          if (std::isnan(bk)) {
            b_p = !std::isnan(ak);
          } else if (std::isnan(ak)) {
            b_p = false;
          } else {
            b_p = (ak < bk);
          }
          if (b_p) {
            p++;
            q++;
            ia[q] = aperm[j];
            pEnd = i2 + 1;
            j = i2;
          } else {
            i++;
          }
        }
      } else {
        exitg1 = 1;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  while (pEnd <= na) {
    i = pEnd;
    (void)skip_to_last_equal_value(&i, a, aperm);
    p++;
    q++;
    ia[q] = aperm[j];
    pEnd = i + 1;
    j = i;
  }
  if (a.size(1) > 0) {
    if (1 > (q + 1)) {
      b_i = -1;
    } else {
      b_i = q;
    }
    ia.set_size(b_i + 1);
  }
  internal::sort(ia, b_ia);
  for (k = 0; k <= q; k++) {
    c[k] = a[ia[k] - 1];
  }
  if (a.size(1) > 0) {
    if (1 > p) {
      p = 0;
    }
    c.set_size(c.size(0), p);
  }
}

} // namespace coder

//
// File trailer for eml_setop.cpp
//
// [EOF]
//
