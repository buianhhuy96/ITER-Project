//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ismember.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "ismember.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Declarations
namespace coder {
static int bsearchni(int k, const ::coder::array<double, 2U> &x,
                     const ::coder::array<double, 2U> &s);

static int bsearchni(int k, const ::coder::array<double, 2U> &x,
                     const ::coder::array<double, 1U> &s);

} // namespace coder

// Function Definitions
//
// Arguments    : int k
//                const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &s
// Return Type  : int
//
namespace coder {
static int bsearchni(int k, const ::coder::array<double, 2U> &x,
                     const ::coder::array<double, 2U> &s)
{
  double b_x;
  int idx;
  int ihi;
  int ilo;
  boolean_T exitg1;
  b_x = x[k - 1];
  ihi = s.size(1);
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int imid;
    imid = (asr_s32(ilo, 1U) + asr_s32(ihi, 1U)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }
    if (b_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      boolean_T p;
      if (std::isnan(s[imid])) {
        p = !std::isnan(b_x);
      } else if (std::isnan(b_x)) {
        p = false;
      } else {
        p = (b_x < s[imid]);
      }
      if (p) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    exitg1 = false;
    while ((!exitg1) && (idx > 0)) {
      if (b_x == s[idx - 1]) {
        idx--;
      } else {
        exitg1 = true;
      }
    }
    idx++;
  }
  return idx;
}

//
// Arguments    : int k
//                const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 1U> &s
// Return Type  : int
//
static int bsearchni(int k, const ::coder::array<double, 2U> &x,
                     const ::coder::array<double, 1U> &s)
{
  double b_x;
  int idx;
  int ihi;
  int ilo;
  boolean_T exitg1;
  b_x = x[k - 1];
  ihi = s.size(0);
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (ihi >= ilo)) {
    int imid;
    imid = (asr_s32(ilo, 1U) + asr_s32(ihi, 1U)) - 1;
    if (((ilo & 1) == 1) && ((ihi & 1) == 1)) {
      imid++;
    }
    if (b_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      boolean_T p;
      if (std::isnan(s[imid])) {
        p = !std::isnan(b_x);
      } else if (std::isnan(b_x)) {
        p = false;
      } else {
        p = (b_x < s[imid]);
      }
      if (p) {
        ihi = imid;
      } else {
        ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    exitg1 = false;
    while ((!exitg1) && (idx > 0)) {
      if (b_x == s[idx - 1]) {
        idx--;
      } else {
        exitg1 = true;
      }
    }
    idx++;
  }
  return idx;
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 2U> &s
//                ::coder::array<boolean_T, 2U> &tf
// Return Type  : void
//
void local_ismember(const ::coder::array<double, 2U> &a,
                    const ::coder::array<double, 2U> &s,
                    ::coder::array<boolean_T, 2U> &tf)
{
  array<double, 1U> ss;
  array<int, 1U> b_ss;
  double absx;
  int exponent;
  int k;
  int loop_ub;
  int n;
  int na;
  int pmax;
  boolean_T exitg1;
  boolean_T guard1{false};
  na = a.size(1);
  loop_ub = a.size(1);
  tf.set_size(1, a.size(1));
  for (pmax = 0; pmax < loop_ub; pmax++) {
    tf[pmax] = false;
  }
  guard1 = false;
  if (s.size(1) <= 4) {
    guard1 = true;
  } else {
    int pmin;
    loop_ub = s.size(1);
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && ((pmax - pmin) > 1)) {
      int p;
      int pow2p;
      p = asr_s32(pmin + pmax, 1U);
      pow2p = ((static_cast<int>(1)) << (static_cast<unsigned long long>(p)));
      if (pow2p == loop_ub) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > loop_ub) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
    if (a.size(1) <= (pmax + 4)) {
      guard1 = true;
    } else {
      boolean_T y;
      y = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (s.size(1) - 2))) {
        absx = s[loop_ub + 1];
        if (s[loop_ub] <= absx) {
          y = true;
        } else if (std::isnan(absx)) {
          y = true;
        } else {
          y = false;
        }
        if (!y) {
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (!y) {
        ss.set_size(s.size(1));
        loop_ub = s.size(1);
        for (pmax = 0; pmax < loop_ub; pmax++) {
          ss[pmax] = s[pmax];
        }
        internal::sort(ss, b_ss);
        loop_ub = a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n, k)

        for (k = 0; k <= loop_ub; k++) {
          n = bsearchni(k + 1, a, ss);
          if (n > 0) {
            tf[k] = true;
          }
        }
      } else {
        loop_ub = a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(n, k)

        for (k = 0; k <= loop_ub; k++) {
          n = bsearchni(k + 1, a, s);
          if (n > 0) {
            tf[k] = true;
          }
        }
      }
    }
  }
  if (guard1) {
    for (pmax = 0; pmax < na; pmax++) {
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= (s.size(1) - 1))) {
        absx = std::abs(s[loop_ub] / 2.0);
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
        if (std::abs(s[loop_ub] - a[pmax]) < absx) {
          tf[pmax] = true;
          exitg1 = true;
        } else if (std::isinf(a[pmax])) {
          if (std::isinf(s[loop_ub])) {
            if ((a[pmax] > 0.0) == (s[loop_ub] > 0.0)) {
              tf[pmax] = true;
              exitg1 = true;
            } else {
              loop_ub++;
            }
          } else {
            loop_ub++;
          }
        } else {
          loop_ub++;
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for ismember.cpp
//
// [EOF]
//
