//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeLambdaLSQ.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef COMPUTELAMBDALSQ_H
#define COMPUTELAMBDALSQ_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void computeLambdaLSQ(int nVar, int mConstr, struct_T *b_QRManager,
                      const double ATwset[120], int ldA, const double grad[8],
                      double lambdaLSQ[15], double workspace[8][15]);

}
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for computeLambdaLSQ.h
//
// [EOF]
//
