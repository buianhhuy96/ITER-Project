//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeGradLag.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "computeGradLag.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <string.h>

// Function Definitions
//
// Arguments    : double workspace[8][15]
//                int nVar
//                const double grad[8]
//                int mIneq
//                int mEq
//                const int finiteFixed[8]
//                int mFixed
//                const int finiteLB[8]
//                int mLB
//                const int finiteUB[8]
//                int mUB
//                const double lambda[15]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void b_computeGradLag(double workspace[8][15], int nVar, const double grad[8],
                      int mIneq, int mEq, const int finiteFixed[8], int mFixed,
                      const int finiteLB[8], int mLB, const int finiteUB[8],
                      int mUB, const double lambda[15])
{
  int c_iL0;
  if ((static_cast<int>(nVar < 4)) != 0) {
    for (int b_i{0}; b_i < nVar; b_i++) {
      (&workspace[0][0])[b_i] = grad[b_i];
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < nVar; b_i++) {
      (&workspace[0][0])[b_i] = grad[b_i];
    }
  }
  for (int idx{0}; idx < mFixed; idx++) {
    int c_i;
    c_i = finiteFixed[idx];
    (&workspace[0][0])[c_i - 1] += lambda[idx];
  }
  c_iL0 = (mFixed + mEq) + mIneq;
  for (int b_idx{0}; b_idx < mLB; b_idx++) {
    int i1;
    i1 = finiteLB[b_idx];
    (&workspace[0][0])[i1 - 1] -= lambda[c_iL0 + b_idx];
  }
  c_iL0 += mLB;
  for (int c_idx{0}; c_idx < mUB; c_idx++) {
    int i2;
    i2 = finiteUB[c_idx];
    (&workspace[0][0])[i2 - 1] += lambda[c_iL0 + c_idx];
  }
}

//
// Arguments    : double workspace[8]
//                int nVar
//                const double grad[8]
//                int mIneq
//                int mEq
//                const int finiteFixed[8]
//                int mFixed
//                const int finiteLB[8]
//                int mLB
//                const int finiteUB[8]
//                int mUB
//                const double lambda[15]
// Return Type  : void
//
void computeGradLag(double workspace[8], int nVar, const double grad[8],
                    int mIneq, int mEq, const int finiteFixed[8], int mFixed,
                    const int finiteLB[8], int mLB, const int finiteUB[8],
                    int mUB, const double lambda[15])
{
  int c_iL0;
  if ((static_cast<int>(nVar < 4)) != 0) {
    if (0 <= (nVar - 1)) {
      (void)std::copy(&grad[0], &grad[nVar], &workspace[0]);
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < nVar; b_i++) {
      workspace[b_i] = grad[b_i];
    }
  }
  for (int idx{0}; idx < mFixed; idx++) {
    int c_i;
    c_i = finiteFixed[idx];
    workspace[c_i - 1] += lambda[idx];
  }
  c_iL0 = (mFixed + mEq) + mIneq;
  for (int b_idx{0}; b_idx < mLB; b_idx++) {
    int i1;
    i1 = finiteLB[b_idx];
    workspace[i1 - 1] -= lambda[c_iL0 + b_idx];
  }
  c_iL0 += mLB;
  for (int c_idx{0}; c_idx < mUB; c_idx++) {
    int i2;
    i2 = finiteUB[c_idx];
    workspace[i2 - 1] += lambda[c_iL0 + c_idx];
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for computeGradLag.cpp
//
// [EOF]
//
