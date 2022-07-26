//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLE.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SORTLE_H
#define SORTLE_H

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
namespace internal {
bool b_sortLE(const double e_v[2][5], int idx1, int idx2);

bool sortLE(const ::coder::array<int, 2U> &e_v,
            const ::coder::array<int, 2U> &dir, int idx1, int idx2);

} // namespace internal
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for sortLE.h
//
// [EOF]
//
