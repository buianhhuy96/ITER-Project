//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLambdaQP.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SORTLAMBDAQP_H
#define SORTLAMBDAQP_H

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
namespace parseoutput {
void sortLambdaQP(double lambda[15], int WorkingSet_nActiveConstr,
                  const int b_WorkingSet_sizes[5],
                  const int b_WorkingSet_isActiveIdx[6],
                  const int WorkingSet_Wid[15],
                  const int WorkingSet_Wlocalidx[15], double workspace[8][15]);

}
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for sortLambdaQP.h
//
// [EOF]
//
