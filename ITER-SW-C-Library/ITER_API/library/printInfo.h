//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: printInfo.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef PRINTINFO_H
#define PRINTINFO_H

// Include Files
#include "rtwtypes.h"
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
namespace qpactiveset {
namespace display {
void printInfo(bool newBlocking, int PROBLEM_TYPE, double alpha,
               double stepNorm, int activeConstrChangedType,
               int localActiveConstrIdx, int activeSetChangeID,
               double solution_fstar, double solution_firstorderopt,
               double solution_maxConstr, int solution_iterations,
               const int workingset_indexLB[8], const int workingset_indexUB[8],
               int b_workingset_nActiveConstr);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for printInfo.h
//
// [EOF]
//
