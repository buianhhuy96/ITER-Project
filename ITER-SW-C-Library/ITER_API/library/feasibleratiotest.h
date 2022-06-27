//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleratiotest.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef FEASIBLERATIOTEST_H
#define FEASIBLERATIOTEST_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void feasibleratiotest(
    const double solution_xstar[8], const double solution_searchDir[8],
    const double workspace[8][15], int workingset_nVar,
    const double workingset_lb[8], const double workingset_ub[8],
    const int workingset_indexLB[8], const int workingset_indexUB[8],
    const int workingset_sizes[5], const int workingset_isActiveIdx[6],
    const bool workingset_isActiveConstr[15], const int workingset_nWConstr[5],
    bool isPhaseOne, double tolcon, double *alpha, bool *newBlocking,
    int *constrType, int *constrIdx);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for feasibleratiotest.h
//
// [EOF]
//
