//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_setop.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
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
namespace Codegen {
namespace coder {
static real_T skip_to_last_equal_value(int32_T *k,
                                       const ::coder::array<real_T, 2U> &b_x,
                                       const ::coder::array<int32_T, 2U> &perm);

}
} // namespace Codegen

// Function Definitions
//
// Arguments    : int32_T *k
//                const ::coder::array<real_T, 2U> &b_x
//                const ::coder::array<int32_T, 2U> &perm
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
static real_T skip_to_last_equal_value(int32_T *k,
                                       const ::coder::array<real_T, 2U> &b_x,
                                       const ::coder::array<int32_T, 2U> &perm)
{
  real_T xk;
  int32_T exponent;
  boolean_T exitg1;
  xk = b_x[perm[(*k) - 1] - 1];
  exitg1 = false;
  while ((!exitg1) && ((*k) < b_x.size(1))) {
    real_T absx;
    real_T d;
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
    d = b_x[perm[*k] - 1];
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
// Arguments    : const ::coder::array<real_T, 2U> &b_a
//                const ::coder::array<real_T, 2U> &b
//                ::coder::array<real_T, 2U> &c
//                ::coder::array<int32_T, 1U> &ia
//                int32_T *ib_size
// Return Type  : void
//
void b_do_vectors(const ::coder::array<real_T, 2U> &b_a,
                  const ::coder::array<real_T, 2U> &b,
                  ::coder::array<real_T, 2U> &c,
                  ::coder::array<int32_T, 1U> &ia, int32_T *ib_size)
{
  ::coder::array<int32_T, 2U> aperm;
  ::coder::array<int32_T, 2U> bperm;
  ::coder::array<int32_T, 1U> b_ia;
  int32_T b_ialast;
  int32_T exponent;
  int32_T iafirst;
  int32_T ialast;
  int32_T iblast;
  int32_T na;
  int32_T nc;
  int32_T nia;
  na = b_a.size(1);
  c.set_size(1, b_a.size(1));
  ia.set_size(b_a.size(1));
  *ib_size = 0;
  internal::sortIdx(b_a, aperm);
  internal::sortIdx(b, bperm);
  nc = 0;
  nia = -1;
  iafirst = 0;
  ialast = 1;
  iblast = 1;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (ialast <= na) {
      if (iblast <= b.size(1)) {
        real_T absx;
        real_T ak;
        real_T b_bk;
        boolean_T guard1{false};
        boolean_T guard2{false};
        b_ialast = ialast;
        ak = skip_to_last_equal_value(&b_ialast, b_a, aperm);
        ialast = b_ialast;
        b_bk = skip_to_last_equal_value(&iblast, b, bperm);
        absx = std::abs(b_bk / 2.0);
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
        if (std::abs(b_bk - ak) < absx) {
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
          iblast++;
        }
        if (guard1) {
          boolean_T p;
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
    (void)skip_to_last_equal_value(&iblast, b_a, aperm);
    nc++;
    nia++;
    ia[nia] = aperm[iafirst];
    ialast = iblast + 1;
    iafirst = iblast;
  }
  if (b_a.size(1) > 0) {
    if (1 > (nia + 1)) {
      na = 0;
    } else {
      na = nia + 1;
    }
    ia.set_size(na);
  }
  internal::b_sort(ia, b_ia);
  for (iblast = 0; iblast <= nia; iblast++) {
    c[iblast] = b_a[ia[iblast] - 1];
  }
  if (b_a.size(1) > 0) {
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(c.size(0), nc);
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &b_a
//                const ::coder::array<real_T, 1U> &b
//                ::coder::array<real_T, 2U> &c
//                ::coder::array<int32_T, 1U> &ia
//                int32_T *ib_size
// Return Type  : void
//
void do_vectors(const ::coder::array<real_T, 2U> &b_a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 2U> &c, ::coder::array<int32_T, 1U> &ia,
                int32_T *ib_size)
{
  ::coder::array<int32_T, 2U> aperm;
  ::coder::array<int32_T, 1U> b_ia;
  ::coder::array<int32_T, 1U> bperm;
  ::coder::array<int32_T, 1U> iwork;
  ::coder::array<int32_T, 1U> r;
  real_T d;
  int32_T b_exponent;
  int32_T b_i;
  int32_T d_i;
  int32_T exponent;
  int32_T g_n;
  int32_T i2;
  int32_T iafirst;
  int32_T ialast;
  int32_T k;
  int32_T na;
  int32_T nc;
  int32_T nia;
  na = b_a.size(1);
  c.set_size(1, b_a.size(1));
  ia.set_size(b_a.size(1));
  *ib_size = 0;
  internal::sortIdx(b_a, aperm);
  g_n = b.size(0) + 1;
  bperm.set_size(b.size(0));
  b_i = b.size(0);
  for (d_i = 0; d_i < b_i; d_i++) {
    bperm[d_i] = 0;
  }
  if (b.size(0) != 0) {
    boolean_T guard1{false};
    b_i = b.size(0);
    r.set_size(b.size(0));
    for (d_i = 0; d_i < b_i; d_i++) {
      r[d_i] = 0;
    }
    iwork.set_size(b.size(0));
    d_i = b.size(0) - 1;
    for (k = 1; k <= d_i; k += 2) {
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
    b_i = 2;
    while (b_i < (g_n - 1)) {
      i2 = b_i * 2;
      iafirst = 1;
      ialast = b_i + 1;
      while (ialast < g_n) {
        int32_T kEnd;
        int32_T qEnd;
        nc = iafirst;
        nia = ialast - 1;
        qEnd = iafirst + i2;
        if (qEnd > g_n) {
          qEnd = g_n;
        }
        k = 0;
        kEnd = qEnd - iafirst;
        while ((k + 1) <= kEnd) {
          d = b[r[nia] - 1];
          d_i = r[nc - 1];
          guard1 = false;
          if (b[d_i - 1] <= d) {
            guard1 = true;
          } else if (std::isnan(d)) {
            guard1 = true;
          } else {
            iwork[k] = r[nia];
            nia++;
            if ((nia + 1) == qEnd) {
              while (nc < ialast) {
                k++;
                iwork[k] = r[nc - 1];
                nc++;
              }
            }
          }
          if (guard1) {
            iwork[k] = d_i;
            nc++;
            if (nc == ialast) {
              while ((nia + 1) < qEnd) {
                k++;
                iwork[k] = r[nia];
                nia++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          r[(iafirst + k) - 1] = iwork[k];
        }
        iafirst = qEnd;
        ialast = qEnd + b_i;
      }
      b_i = i2;
    }
    b_i = r.size(0);
    for (d_i = 0; d_i < b_i; d_i++) {
      bperm[d_i] = r[d_i];
    }
  }
  nc = 0;
  nia = -1;
  iafirst = 0;
  ialast = 1;
  b_i = 1;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (ialast <= na) {
      if (b_i <= b.size(0)) {
        real_T absx;
        real_T ak;
        real_T b_bk;
        boolean_T b_guard1{false};
        boolean_T exitg2;
        boolean_T guard2{false};
        i2 = ialast;
        ak = skip_to_last_equal_value(&i2, b_a, aperm);
        ialast = i2;
        b_bk = b[bperm[b_i - 1] - 1];
        exitg2 = false;
        while ((!exitg2) && (b_i < b.size(0))) {
          absx = std::abs(b_bk / 2.0);
          if ((!std::isinf(absx)) && (!std::isnan(absx))) {
            if (absx <= 2.2250738585072014E-308) {
              absx = 4.94065645841247E-324;
            } else {
              (void)frexp(absx, &b_exponent);
              absx = std::ldexp(1.0, b_exponent - 53);
            }
          } else {
            absx = rtNaN;
          }
          d = b[bperm[b_i] - 1];
          if (std::abs(b_bk - d) < absx) {
            b_i++;
          } else if (std::isinf(d)) {
            if (std::isinf(b_bk)) {
              if ((d > 0.0) == (b_bk > 0.0)) {
                b_i++;
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
        absx = std::abs(b_bk / 2.0);
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
        b_guard1 = false;
        guard2 = false;
        if (std::abs(b_bk - ak) < absx) {
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
          ialast = i2 + 1;
          iafirst = i2;
          b_i++;
        }
        if (b_guard1) {
          boolean_T p;
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
            ialast = i2 + 1;
            iafirst = i2;
          } else {
            b_i++;
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
    b_i = ialast;
    (void)skip_to_last_equal_value(&b_i, b_a, aperm);
    nc++;
    nia++;
    ia[nia] = aperm[iafirst];
    ialast = b_i + 1;
    iafirst = b_i;
  }
  if (b_a.size(1) > 0) {
    if (1 > (nia + 1)) {
      d_i = 0;
    } else {
      d_i = nia + 1;
    }
    ia.set_size(d_i);
  }
  internal::b_sort(ia, b_ia);
  for (k = 0; k <= nia; k++) {
    c[k] = b_a[ia[k] - 1];
  }
  if (b_a.size(1) > 0) {
    if (1 > nc) {
      nc = 0;
    }
    c.set_size(c.size(0), nc);
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for eml_setop.cpp
//
// [EOF]
//
