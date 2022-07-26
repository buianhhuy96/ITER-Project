//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: projectBox.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "projectBox.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &b_dx
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const ::coder::array<bool, 1U> &hasLB
//                const ::coder::array<bool, 1U> &hasUB
// Return Type  : double
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
double b_projectBox(const ::coder::array<double, 1U> &b_x,
                    ::coder::array<double, 1U> &b_dx,
                    const ::coder::array<double, 1U> &lb,
                    const ::coder::array<double, 1U> &ub,
                    const ::coder::array<bool, 1U> &hasLB,
                    const ::coder::array<bool, 1U> &hasUB)
{
  double dxInfNorm;
  int h_n;
  h_n = b_dx.size(0) - 1;
  dxInfNorm = 0.0;
  if (b_x.size(0) == 0) {
    for (int c_i{0}; c_i <= h_n; c_i++) {
      if (hasLB[c_i]) {
        if (lb.size(0) > 0) {
          b_dx[c_i] = std::fmax(lb[c_i], b_dx[c_i]);
        }
      }
      if (hasUB[c_i]) {
        if (ub.size(0) > 0) {
          b_dx[c_i] = std::fmin(ub[c_i], b_dx[c_i]);
        }
      }
      dxInfNorm = std::fmax(dxInfNorm, std::abs(b_dx[c_i]));
    }
  } else {
    for (int b_i{0}; b_i <= h_n; b_i++) {
      if (hasLB[b_i]) {
        if (lb.size(0) > 0) {
          b_dx[b_i] = std::fmax(lb[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
      if (hasUB[b_i]) {
        if (ub.size(0) > 0) {
          b_dx[b_i] = std::fmin(ub[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
      dxInfNorm = std::fmax(dxInfNorm, std::abs(b_dx[b_i]));
    }
  }
  return dxInfNorm;
}

//
// Arguments    : ::coder::array<double, 1U> &b_dx
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const ::coder::array<bool, 1U> &hasLB
//                const ::coder::array<bool, 1U> &hasUB
// Return Type  : void
//
void c_projectBox(::coder::array<double, 1U> &b_dx,
                  const ::coder::array<double, 1U> &lb,
                  const ::coder::array<double, 1U> &ub,
                  const ::coder::array<bool, 1U> &hasLB,
                  const ::coder::array<bool, 1U> &hasUB)
{
  int h_n;
  h_n = b_dx.size(0);
  if ((static_cast<int>(h_n < 4)) != 0) {
    for (int b_i{0}; b_i < h_n; b_i++) {
      if (hasLB[b_i]) {
        if (lb.size(0) > 0) {
          b_dx[b_i] = std::fmax(lb[b_i], b_dx[b_i]);
        }
      }
      if (hasUB[b_i]) {
        if (ub.size(0) > 0) {
          b_dx[b_i] = std::fmin(ub[b_i], b_dx[b_i]);
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < h_n; b_i++) {
      if (hasLB[b_i]) {
        if (lb.size(0) > 0) {
          b_dx[b_i] = std::fmax(lb[b_i], b_dx[b_i]);
        }
      }
      if (hasUB[b_i]) {
        if (ub.size(0) > 0) {
          b_dx[b_i] = std::fmin(ub[b_i], b_dx[b_i]);
        }
      }
    }
  }
}

//
// Arguments    : double b_dx[6]
//                const bool hasLB[6]
//                const bool hasUB[6]
// Return Type  : void
//
void d_projectBox(double b_dx[6], const bool hasLB[6], const bool hasUB[6])
{
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int b_i = 0; b_i < 6; b_i++) {
    if (hasLB[b_i]) {
      b_dx[b_i] = std::fmax(-1.7976931348623157E+308, b_dx[b_i]);
    }
    if (hasUB[b_i]) {
      b_dx[b_i] = std::fmin(1.7976931348623157E+308, b_dx[b_i]);
    }
  }
}

//
// Arguments    : const double b_x[6]
//                double b_dx[6]
//                const bool hasLB[6]
//                const bool hasUB[6]
// Return Type  : double
//
double e_projectBox(const double b_x[6], double b_dx[6], const bool hasLB[6],
                    const bool hasUB[6])
{
  double dxInfNorm;
  dxInfNorm = 0.0;
  for (int b_i{0}; b_i < 6; b_i++) {
    if (hasLB[b_i]) {
      b_dx[b_i] = std::fmax(-1.7976931348623157E+308 - b_x[b_i], b_dx[b_i]);
    }
    if (hasUB[b_i]) {
      b_dx[b_i] = std::fmin(1.7976931348623157E+308 - b_x[b_i], b_dx[b_i]);
    }
    dxInfNorm = std::fmax(dxInfNorm, std::abs(b_dx[b_i]));
  }
  return dxInfNorm;
}

//
// Arguments    : const ::coder::array<double, 1U> &b_x
//                ::coder::array<double, 1U> &b_dx
//                const ::coder::array<double, 1U> &lb
//                const ::coder::array<double, 1U> &ub
//                const ::coder::array<bool, 1U> &hasLB
//                const ::coder::array<bool, 1U> &hasUB
// Return Type  : void
//
void projectBox(const ::coder::array<double, 1U> &b_x,
                ::coder::array<double, 1U> &b_dx,
                const ::coder::array<double, 1U> &lb,
                const ::coder::array<double, 1U> &ub,
                const ::coder::array<bool, 1U> &hasLB,
                const ::coder::array<bool, 1U> &hasUB)
{
  int h_n;
  h_n = b_dx.size(0) - 1;
  if (b_x.size(0) == 0) {
    if ((static_cast<int>((h_n + 1) < 4)) != 0) {
      for (int c_i{0}; c_i <= h_n; c_i++) {
        if (hasLB[c_i]) {
          if (lb.size(0) > 0) {
            b_dx[c_i] = std::fmax(lb[c_i], b_dx[c_i]);
          }
        }
        if (hasUB[c_i]) {
          if (ub.size(0) > 0) {
            b_dx[c_i] = std::fmin(ub[c_i], b_dx[c_i]);
          }
        }
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int c_i = 0; c_i <= h_n; c_i++) {
        if (hasLB[c_i]) {
          if (lb.size(0) > 0) {
            b_dx[c_i] = std::fmax(lb[c_i], b_dx[c_i]);
          }
        }
        if (hasUB[c_i]) {
          if (ub.size(0) > 0) {
            b_dx[c_i] = std::fmin(ub[c_i], b_dx[c_i]);
          }
        }
      }
    }
  } else if ((static_cast<int>((h_n + 1) < 4)) != 0) {
    for (int b_i{0}; b_i <= h_n; b_i++) {
      if (hasLB[b_i]) {
        if (lb.size(0) > 0) {
          b_dx[b_i] = std::fmax(lb[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
      if (hasUB[b_i]) {
        if (ub.size(0) > 0) {
          b_dx[b_i] = std::fmin(ub[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i <= h_n; b_i++) {
      if (hasLB[b_i]) {
        if (lb.size(0) > 0) {
          b_dx[b_i] = std::fmax(lb[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
      if (hasUB[b_i]) {
        if (ub.size(0) > 0) {
          b_dx[b_i] = std::fmin(ub[b_i] - b_x[b_i], b_dx[b_i]);
        }
      }
    }
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for projectBox.cpp
//
// [EOF]
//
