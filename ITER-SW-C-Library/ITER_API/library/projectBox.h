//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: projectBox.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef PROJECTBOX_H
#define PROJECTBOX_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
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
                    const ::coder::array<bool, 1U> &hasUB);

void c_projectBox(::coder::array<double, 1U> &b_dx,
                  const ::coder::array<double, 1U> &lb,
                  const ::coder::array<double, 1U> &ub,
                  const ::coder::array<bool, 1U> &hasLB,
                  const ::coder::array<bool, 1U> &hasUB);

void d_projectBox(double b_dx[6], const bool hasLB[6], const bool hasUB[6]);

double e_projectBox(const double b_x[6], double b_dx[6], const bool hasLB[6],
                    const bool hasUB[6]);

void projectBox(const ::coder::array<double, 1U> &b_x,
                ::coder::array<double, 1U> &b_dx,
                const ::coder::array<double, 1U> &lb,
                const ::coder::array<double, 1U> &ub,
                const ::coder::array<bool, 1U> &hasLB,
                const ::coder::array<bool, 1U> &hasUB);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for projectBox.h
//
// [EOF]
//
