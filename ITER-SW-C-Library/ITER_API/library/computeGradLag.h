//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGradLag.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef COMPUTEGRADLAG_H
#define COMPUTEGRADLAG_H

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
namespace fminconsqp {
namespace stopping {
void b_computeGradLag(double workspace[8][15], int nVar, const double grad[8],
                      int mIneq, int mEq, const int finiteFixed[8], int mFixed,
                      const int finiteLB[8], int mLB, const int finiteUB[8],
                      int mUB, const double lambda[15]);

void computeGradLag(double workspace[8], int nVar, const double grad[8],
                    int mIneq, int mEq, const int finiteFixed[8], int mFixed,
                    const int finiteLB[8], int mLB, const int finiteUB[8],
                    int mUB, const double lambda[15]);

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for computeGradLag.h
//
// [EOF]
//
