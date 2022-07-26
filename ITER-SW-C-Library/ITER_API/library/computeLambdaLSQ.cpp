//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeLambdaLSQ.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeLambdaLSQ.h"
#include "ITER_API_internal_types.h"
#include "computeQ_.h"
#include "rt_nonfinite.h"
#include "xgemv.h"
#include "xgeqp3.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : int nVar
//                int mConstr
//                struct_T *b_QRManager
//                const double ATwset[120]
//                int ldA
//                const double grad[8]
//                double lambdaLSQ[15]
//                double workspace[8][15]
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void computeLambdaLSQ(int nVar, int mConstr, struct_T *b_QRManager,
                      const double ATwset[120], int ldA, const double grad[8],
                      double lambdaLSQ[15], double workspace[8][15])
{
  double tol;
  int b_i;
  int fullRank_R;
  int iQR_diag;
  int minDim;
  int rankR;
  int y;
  bool exitg1;
  bool guard1{false};
  if ((static_cast<int>(mConstr < 4)) != 0) {
    if (0 <= (mConstr - 1)) {
      (void)std::memset(&lambdaLSQ[0], 0,
                        (static_cast<unsigned int>(mConstr)) *
                            (sizeof(double)));
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < mConstr; k++) {
      lambdaLSQ[k] = 0.0;
    }
  }
  b_i = nVar * mConstr;
  guard1 = false;
  if (b_i > 0) {
    for (int idx{0}; idx < mConstr; idx++) {
      int ix0;
      int iy0;
      ix0 = ldA * idx;
      iy0 = b_QRManager->ldq * idx;
      for (int b_k{0}; b_k < nVar; b_k++) {
        (&b_QRManager->QR[0][0])[iy0 + b_k] = ATwset[ix0 + b_k];
      }
    }
    guard1 = true;
  } else if (b_i == 0) {
    b_QRManager->mrows = nVar;
    b_QRManager->ncols = mConstr;
    b_QRManager->minRowCol = 0;
  } else {
    guard1 = true;
  }
  if (guard1) {
    int b_y;
    b_QRManager->usedPivoting = true;
    b_QRManager->mrows = nVar;
    b_QRManager->ncols = mConstr;
    if (nVar <= mConstr) {
      b_y = nVar;
    } else {
      b_y = mConstr;
    }
    b_QRManager->minRowCol = b_y;
    ::ITER::coder::internal::lapack::c_xgeqp3(
        b_QRManager->QR, nVar, mConstr, b_QRManager->jpvt, b_QRManager->tau);
  }
  QRManager::computeQ_(b_QRManager, b_QRManager->mrows);
  ::ITER::coder::internal::blas::d_xgemv(nVar, nVar, b_QRManager->Q,
                                         b_QRManager->ldq, grad, workspace);
  if (nVar >= mConstr) {
    y = nVar;
  } else {
    y = mConstr;
  }
  tol = std::abs((&b_QRManager->QR[0][0])[0]) *
        std::fmin(1.4901161193847656E-8,
                  (static_cast<double>(y)) * 2.2204460492503131E-16);
  if (nVar <= mConstr) {
    fullRank_R = nVar;
  } else {
    fullRank_R = mConstr;
  }
  rankR = 0;
  iQR_diag = 0;
  exitg1 = false;
  while ((!exitg1) && (rankR < fullRank_R)) {
    if (std::abs((&b_QRManager->QR[0][0])[iQR_diag]) > tol) {
      rankR++;
      iQR_diag = (iQR_diag + b_QRManager->ldq) + 1;
    } else {
      exitg1 = true;
    }
  }
  if (rankR != 0) {
    for (int j{rankR}; j >= 1; j--) {
      int jjA;
      jjA = (j + ((j - 1) * b_QRManager->ldq)) - 1;
      (&workspace[0][0])[j - 1] /= (&b_QRManager->QR[0][0])[jjA];
      for (int c_i{0}; c_i <= (j - 2); c_i++) {
        int c_ix;
        c_ix = (j - c_i) - 2;
        (&workspace[0][0])[c_ix] -= (&workspace[0][0])[j - 1] *
                                    (&b_QRManager->QR[0][0])[(jjA - c_i) - 1];
      }
    }
  }
  if (mConstr <= fullRank_R) {
    minDim = mConstr;
  } else {
    minDim = fullRank_R;
  }
  for (int b_idx{0}; b_idx < minDim; b_idx++) {
    lambdaLSQ[b_QRManager->jpvt[b_idx] - 1] = (&workspace[0][0])[b_idx];
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computeLambdaLSQ.cpp
//
// [EOF]
//
