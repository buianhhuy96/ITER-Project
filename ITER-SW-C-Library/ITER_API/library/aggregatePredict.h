//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: aggregatePredict.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

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
void aggregatePredict(const ::coder::array<double, 2U> &d_X,
                      ::coder::array<double, 2U> &score,
                      const double b_learnerWeights[100],
                      const bool b_isCached[100], const double b_classNames[2],
                      const bool b_classlogicalindices[2],
                      const bool learners[100],
                      const ::coder::array<bool, 2U> &useObsForLearner);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for aggregatePredict.h
//
// [EOF]
//
