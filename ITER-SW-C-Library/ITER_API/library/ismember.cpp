//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ismember.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ismember.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>
#include <string.h>

// Function Declarations
namespace ITER {
namespace coder {
static int b_bsearchni(int k, const ::coder::array<double, 2U> &b_x,
                       const ::coder::array<double, 2U> &s);

static int bsearchni(int k, const ::coder::array<double, 2U> &b_x,
                     const ::coder::array<double, 1U> &s);

} // namespace coder
} // namespace ITER

// Function Definitions
//
// Arguments    : int k
//                const ::coder::array<double, 2U> &b_x
//                const ::coder::array<double, 2U> &s
// Return Type  : int
//
namespace ITER {
namespace coder {
static int b_bsearchni(int k, const ::coder::array<double, 2U> &b_x,
                       const ::coder::array<double, 2U> &s)
{
  double e_x;
  int b_ihi;
  int b_ilo;
  int idx;
  bool exitg1;
  e_x = b_x[k - 1];
  b_ihi = s.size(1);
  idx = 0;
  b_ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ihi >= b_ilo)) {
    int imid;
    imid = (asr_s32(b_ilo, 1U) + asr_s32(b_ihi, 1U)) - 1;
    if (((b_ilo & 1) == 1) && ((b_ihi & 1) == 1)) {
      imid++;
    }
    if (e_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      bool p;
      if (std::isnan(s[imid])) {
        p = !std::isnan(e_x);
      } else if (std::isnan(e_x)) {
        p = false;
      } else {
        p = (e_x < s[imid]);
      }
      if (p) {
        b_ihi = imid;
      } else {
        b_ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    exitg1 = false;
    while ((!exitg1) && (idx > 0)) {
      if (e_x == s[idx - 1]) {
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
//                const ::coder::array<double, 2U> &b_x
//                const ::coder::array<double, 1U> &s
// Return Type  : int
//
static int bsearchni(int k, const ::coder::array<double, 2U> &b_x,
                     const ::coder::array<double, 1U> &s)
{
  double e_x;
  int b_ihi;
  int b_ilo;
  int idx;
  bool exitg1;
  e_x = b_x[k - 1];
  b_ihi = s.size(0);
  idx = 0;
  b_ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ihi >= b_ilo)) {
    int imid;
    imid = (asr_s32(b_ilo, 1U) + asr_s32(b_ihi, 1U)) - 1;
    if (((b_ilo & 1) == 1) && ((b_ihi & 1) == 1)) {
      imid++;
    }
    if (e_x == s[imid]) {
      idx = imid + 1;
      exitg1 = true;
    } else {
      bool p;
      if (std::isnan(s[imid])) {
        p = !std::isnan(e_x);
      } else if (std::isnan(e_x)) {
        p = false;
      } else {
        p = (e_x < s[imid]);
      }
      if (p) {
        b_ihi = imid;
      } else {
        b_ilo = imid + 2;
      }
    }
  }
  if (idx > 0) {
    idx--;
    exitg1 = false;
    while ((!exitg1) && (idx > 0)) {
      if (e_x == s[idx - 1]) {
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
// Arguments    : const double b_a[2]
//                const double s[2]
//                bool tf[2]
//                int loc[2]
// Return Type  : void
//
void b_local_ismember(const double b_a[2], const double s[2], bool tf[2],
                      int loc[2])
{
  double absx;
  double r;
  int b_i;
  int exponent;
  bool b_guard1{false};
  bool exitg1;
  bool guard1{false};
  tf[0] = false;
  loc[0] = 0;
  b_i = 0;
  guard1 = false;
  exitg1 = false;
  while ((!exitg1) && (b_i < 2)) {
    absx = std::abs(s[b_i] / 2.0);
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
    if (std::abs(s[b_i] - b_a[0]) < r) {
      guard1 = true;
      exitg1 = true;
    } else {
      b_guard1 = false;
      if (std::isinf(b_a[0])) {
        if (std::isinf(s[b_i])) {
          if ((b_a[0] > 0.0) == (s[b_i] > 0.0)) {
            guard1 = true;
            exitg1 = true;
          } else {
            b_guard1 = true;
          }
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }
      if (b_guard1) {
        b_i++;
        guard1 = false;
      }
    }
  }
  if (guard1) {
    tf[0] = true;
    loc[0] = b_i + 1;
  }
  tf[1] = false;
  loc[1] = 0;
  b_i = 0;
  guard1 = false;
  exitg1 = false;
  while ((!exitg1) && (b_i < 2)) {
    absx = std::abs(s[b_i] / 2.0);
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
    if (std::abs(s[b_i] - b_a[1]) < r) {
      guard1 = true;
      exitg1 = true;
    } else {
      b_guard1 = false;
      if (std::isinf(b_a[1])) {
        if (std::isinf(s[b_i])) {
          if ((b_a[1] > 0.0) == (s[b_i] > 0.0)) {
            guard1 = true;
            exitg1 = true;
          } else {
            b_guard1 = true;
          }
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }
      if (b_guard1) {
        b_i++;
        guard1 = false;
      }
    }
  }
  if (guard1) {
    tf[1] = true;
    loc[1] = b_i + 1;
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_a
//                const ::coder::array<double, 2U> &s
//                ::coder::array<bool, 2U> &tf
// Return Type  : void
//
void local_ismember(const ::coder::array<double, 2U> &b_a,
                    const ::coder::array<double, 2U> &s,
                    ::coder::array<bool, 2U> &tf)
{
  ::coder::array<double, 1U> ss;
  ::coder::array<int, 1U> b_ss;
  int exponent;
  int loop_ub;
  int na;
  int p_n;
  bool exitg1;
  bool guard1{false};
  na = b_a.size(1);
  tf.set_size(1, b_a.size(1));
  loop_ub = b_a.size(1);
  if ((static_cast<int>(b_a.size(1) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      tf[b_i] = false;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      tf[b_i] = false;
    }
  }
  guard1 = false;
  if (s.size(1) <= 4) {
    guard1 = true;
  } else {
    int h_n;
    int pmax;
    int pmin;
    h_n = s.size(1);
    pmax = 31;
    pmin = 0;
    exitg1 = false;
    while ((!exitg1) && ((pmax - pmin) > 1)) {
      int p;
      int pow2p;
      p = asr_s32(pmin + pmax, 1U);
      pow2p = ((static_cast<int>(1)) << (static_cast<unsigned int>(p)));
      if (pow2p == h_n) {
        pmax = p;
        exitg1 = true;
      } else if (pow2p > h_n) {
        pmax = p;
      } else {
        pmin = p;
      }
    }
    if (b_a.size(1) <= (pmax + 4)) {
      guard1 = true;
    } else {
      int b_k;
      bool y;
      y = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= (s.size(1) - 2))) {
        double v_idx_1;
        bool b_y;
        v_idx_1 = s[b_k + 1];
        if (s[b_k] <= v_idx_1) {
          b_y = true;
        } else if (std::isnan(v_idx_1)) {
          b_y = true;
        } else {
          b_y = false;
        }
        y = b_y;
        if (!b_y) {
          exitg1 = true;
        } else {
          b_k++;
        }
      }
      if (!y) {
        int b_loop_ub;
        int b_ub_loop;
        ss.set_size(s.size(1));
        b_loop_ub = s.size(1);
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int i1 = 0; i1 < b_loop_ub; i1++) {
          ss[i1] = s[i1];
        }
        internal::c_sort(ss, b_ss);
        b_ub_loop = b_a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(p_n)

        for (int d_k = 0; d_k <= b_ub_loop; d_k++) {
          p_n = bsearchni(d_k + 1, b_a, ss);
          if (p_n > 0) {
            tf[d_k] = true;
          }
        }
      } else {
        int ub_loop;
        ub_loop = b_a.size(1) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(p_n)

        for (int c_k = 0; c_k <= ub_loop; c_k++) {
          p_n = b_bsearchni(c_k + 1, b_a, s);
          if (p_n > 0) {
            tf[c_k] = true;
          }
        }
      }
    }
  }
  if (guard1) {
    for (int j{0}; j < na; j++) {
      int k;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= (s.size(1) - 1))) {
        double absx;
        double r;
        absx = std::abs(s[k] / 2.0);
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
        if (std::abs(s[k] - b_a[j]) < r) {
          tf[j] = true;
          exitg1 = true;
        } else if (std::isinf(b_a[j])) {
          if (std::isinf(s[k])) {
            if ((b_a[j] > 0.0) == (s[k] > 0.0)) {
              tf[j] = true;
              exitg1 = true;
            } else {
              k++;
            }
          } else {
            k++;
          }
        } else {
          k++;
        }
      }
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for ismember.cpp
//
// [EOF]
//
