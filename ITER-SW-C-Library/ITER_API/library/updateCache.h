//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: updateCache.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef UPDATECACHE_H
#define UPDATECACHE_H

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
namespace classreg {
namespace learning {
namespace coder {
namespace ensembleutils {
void updateCache(const ::coder::array<double, 2U> &learnerscore,
                 ::coder::array<double, 2U> &cachedScore,
                 ::coder::array<double, 1U> &cachedWeights, bool *cached,
                 double learnerWeight, const char combinerName[15],
                 const ::coder::array<bool, 1U> &obsIndices,
                 ::coder::array<double, 2U> &score);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for updateCache.h
//
// [EOF]
//
