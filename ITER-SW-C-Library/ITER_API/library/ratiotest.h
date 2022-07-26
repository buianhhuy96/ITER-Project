//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ratiotest.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef RATIOTEST_H
#define RATIOTEST_H

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
void ratiotest(const double solution_xstar[8],
               const double solution_searchDir[8],
               const double workspace[8][15], int workingset_nVar,
               const double workingset_lb[8], const double workingset_ub[8],
               const int workingset_indexLB[8], const int workingset_indexUB[8],
               const int workingset_sizes[5],
               const int workingset_isActiveIdx[6],
               const bool workingset_isActiveConstr[15],
               const int workingset_nWConstr[5], double tolcon,
               double *b_toldelta, double *alpha, bool *newBlocking,
               int *constrType, int *constrIdx);

}
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for ratiotest.h
//
// [EOF]
//
