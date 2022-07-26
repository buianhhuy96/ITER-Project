//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hasFiniteBounds.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef HASFINITEBOUNDS_H
#define HASFINITEBOUNDS_H

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
namespace utils {
bool b_hasFiniteBounds(int b_nvar, ::coder::array<bool, 1U> &hasLB,
                       ::coder::array<bool, 1U> &hasUB,
                       const ::coder::array<double, 1U> &lb,
                       const ::coder::array<double, 1U> &ub);

bool hasFiniteBounds(bool hasLB[6], bool hasUB[6]);

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for hasFiniteBounds.h
//
// [EOF]
//
