//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: hasFiniteBounds.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef HASFINITEBOUNDS_H
#define HASFINITEBOUNDS_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
bool hasFiniteBounds(int b_nvar, ::coder::array<bool, 1U> &hasLB,
                     ::coder::array<bool, 1U> &hasUB,
                     const ::coder::array<double, 1U> &lb,
                     const ::coder::array<double, 1U> &ub);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for hasFiniteBounds.h
//
// [EOF]
//
