//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: CompactClassificationEnsemble.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPACTCLASSIFICATIONENSEMBLE_H
#define COMPACTCLASSIFICATIONENSEMBLE_H

// Include Files
#include "ITER_API_internal_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace ITER {
namespace coder {
namespace classreg {
namespace learning {
namespace classif {
class CompactClassificationEnsemble {
public:
  void predict(const ::coder::array<double, 2U> &Xin,
               ::coder::array<double, 1U> &labels,
               ::coder::array<double, 2U> &score) const;
  bool IsCached[100];
  double LearnerWeights[100];
  double ClassNames[2];
  int ClassNamesLength[2];
  coderutils::Transform ScoreTransform;
  double Prior[2];
  bool ClassLogicalIndices[2];
  double Cost[2][2];
};

} // namespace classif
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for CompactClassificationEnsemble.h
//
// [EOF]
//
