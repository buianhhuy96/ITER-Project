//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hasFiniteBounds.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "hasFiniteBounds.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int b_nvar
//                ::coder::array<bool, 1U> &hasLB
//                ::coder::array<bool, 1U> &hasUB
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace utils {
bool hasFiniteBounds(int b_nvar, ::coder::array<bool, 1U> &hasLB,
                     ::coder::array<bool, 1U> &hasUB,
                     const ::coder::array<double, 1U> &lb,
                     const ::coder::array<double, 1U> &ub)
{
  int emptyLB;
  int emptyUB;
  int idx;
  bool hasBounds;
  hasBounds = false;
  idx = 0;
  emptyUB = static_cast<int>(static_cast<unsigned int>(
      (static_cast<unsigned int>(ub.size(0) == 0)) << 1UL));
  emptyLB = static_cast<int>(lb.size(0) == 0);
  switch ((static_cast<unsigned int>(emptyUB)) |
          (static_cast<unsigned int>(emptyLB))) {
  case 0U:
    while ((!hasBounds) && ((idx + 1) <= b_nvar)) {
      hasLB[idx] = ((!std::isinf(lb[idx])) && (!std::isnan(lb[idx])));
      hasUB[idx] = ((!std::isinf(ub[idx])) && (!std::isnan(ub[idx])));
      if (hasLB[idx]) {
        hasBounds = true;
      } else if (hasUB[idx]) {
        hasBounds = true;
      } else {
        /* no actions */
      }
      idx++;
    }
    while ((idx + 1) <= b_nvar) {
      hasLB[idx] = ((!std::isinf(lb[idx])) && (!std::isnan(lb[idx])));
      hasUB[idx] = ((!std::isinf(ub[idx])) && (!std::isnan(ub[idx])));
      idx++;
    }
    break;
  case 1U:
    while ((!hasBounds) && ((idx + 1) <= b_nvar)) {
      hasLB[idx] = false;
      hasUB[idx] = ((!std::isinf(ub[idx])) && (!std::isnan(ub[idx])));
      hasBounds = hasUB[idx];
      idx++;
    }
    while ((idx + 1) <= b_nvar) {
      hasLB[idx] = false;
      hasUB[idx] = ((!std::isinf(ub[idx])) && (!std::isnan(ub[idx])));
      idx++;
    }
    break;
  case 2U:
    while ((!hasBounds) && ((idx + 1) <= b_nvar)) {
      hasLB[idx] = ((!std::isinf(lb[idx])) && (!std::isnan(lb[idx])));
      hasUB[idx] = false;
      hasBounds = hasLB[idx];
      idx++;
    }
    while ((idx + 1) <= b_nvar) {
      hasLB[idx] = ((!std::isinf(lb[idx])) && (!std::isnan(lb[idx])));
      hasUB[idx] = false;
      idx++;
    }
    break;
  default:
    while ((idx + 1) <= b_nvar) {
      hasLB[idx] = false;
      hasUB[idx] = false;
      idx++;
    }
    break;
  }
  return hasBounds;
}

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for hasFiniteBounds.cpp
//
// [EOF]
//
