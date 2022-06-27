//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ratiotest.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "ratiotest.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const double solution_xstar[8]
//                const double solution_searchDir[8]
//                const double workspace[8][15]
//                int workingset_nVar
//                const double workingset_lb[8]
//                const double workingset_ub[8]
//                const int workingset_indexLB[8]
//                const int workingset_indexUB[8]
//                const int workingset_sizes[5]
//                const int workingset_isActiveIdx[6]
//                const bool workingset_isActiveConstr[15]
//                const int workingset_nWConstr[5]
//                double tolcon
//                double *b_toldelta
//                double *alpha
//                bool *newBlocking
//                int *constrType
//                int *constrIdx
// Return Type  : void
//
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
               int *constrType, int *constrIdx)
{
  double alphaTemp;
  double b_p_max;
  double denomTol;
  double phaseOneCorrectionP;
  double phaseOneCorrectionX;
  double pk_corrected;
  double ratio;
  int totalIneq;
  int totalUB;
  totalIneq = workingset_sizes[2];
  totalUB = workingset_sizes[4];
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  b_p_max = 0.0;
  denomTol = 2.2204460492503131E-13 *
             internal::blas::h_xnrm2(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < workingset_sizes[2]) {
    for (int idx{0}; idx < totalIneq; idx++) {
      double d;
      d = (&workspace[0][0])[idx + 15];
      if ((d > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] + idx) - 1])) {
        alphaTemp =
            std::fmin(std::abs((&workspace[0][0])[idx] - (*b_toldelta)),
                      (tolcon - (&workspace[0][0])[idx]) + (*b_toldelta)) /
            d;
        if (alphaTemp <= (*alpha)) {
          if (std::abs((&workspace[0][0])[idx + 15]) > b_p_max) {
            *alpha = alphaTemp;
            *constrType = 3;
            *constrIdx = idx + 1;
            *newBlocking = true;
          }
        }
        alphaTemp = std::fmin(std::abs((&workspace[0][0])[idx]),
                              tolcon - (&workspace[0][0])[idx]) /
                    (&workspace[0][0])[idx + 15];
        if (alphaTemp < (*alpha)) {
          *alpha = alphaTemp;
          *constrType = 3;
          *constrIdx = idx + 1;
          *newBlocking = true;
          b_p_max = std::abs((&workspace[0][0])[idx + 15]);
        }
      }
    }
  }
  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    double b_d1;
    int b_i;
    int i1;
    phaseOneCorrectionX = 0.0 * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = 0.0 * solution_searchDir[workingset_nVar - 1];
    b_i = workingset_sizes[3];
    for (int b_idx{0}; b_idx <= (b_i - 2); b_idx++) {
      int i2;
      i2 = workingset_indexLB[b_idx];
      pk_corrected = (-solution_searchDir[i2 - 1]) - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] + b_idx) -
                                      1])) {
        double b_ratio_tmp;
        b_ratio_tmp = (-solution_xstar[i2 - 1]) - workingset_lb[i2 - 1];
        ratio = (b_ratio_tmp - (*b_toldelta)) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / pk_corrected;
        if (alphaTemp <= (*alpha)) {
          if (std::abs(pk_corrected) > b_p_max) {
            *alpha = alphaTemp;
            *constrType = 4;
            *constrIdx = b_idx + 1;
            *newBlocking = true;
          }
        }
        ratio = b_ratio_tmp - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / pk_corrected;
        if (alphaTemp < (*alpha)) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = b_idx + 1;
          *newBlocking = true;
          b_p_max = std::abs(pk_corrected);
        }
      }
    }
    i1 = workingset_indexLB[workingset_sizes[3] - 1] - 1;
    b_d1 = solution_searchDir[i1];
    if (((-b_d1) > denomTol) &&
        (!workingset_isActiveConstr
             [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      double ratio_tmp;
      ratio_tmp = (-solution_xstar[i1]) - workingset_lb[i1];
      ratio = ratio_tmp - (*b_toldelta);
      alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / (-b_d1);
      if (alphaTemp <= (*alpha)) {
        if (std::abs(b_d1) > b_p_max) {
          *alpha = alphaTemp;
          *constrType = 4;
          *constrIdx = workingset_sizes[3];
          *newBlocking = true;
        }
      }
      alphaTemp = std::fmin(std::abs(ratio_tmp), tolcon - ratio_tmp) / (-b_d1);
      if (alphaTemp < (*alpha)) {
        *alpha = alphaTemp;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        b_p_max = std::abs(solution_searchDir[i1]);
      }
    }
  }
  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    phaseOneCorrectionX = 0.0 * solution_xstar[workingset_nVar - 1];
    phaseOneCorrectionP = 0.0 * solution_searchDir[workingset_nVar - 1];
    for (int c_idx{0}; c_idx < totalUB; c_idx++) {
      int i3;
      i3 = workingset_indexUB[c_idx];
      pk_corrected = solution_searchDir[i3 - 1] - phaseOneCorrectionP;
      if ((pk_corrected > denomTol) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] + c_idx) -
                                      1])) {
        double c_ratio_tmp;
        c_ratio_tmp = solution_xstar[i3 - 1] - workingset_ub[i3 - 1];
        ratio = (c_ratio_tmp - (*b_toldelta)) - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / pk_corrected;
        if (alphaTemp <= (*alpha)) {
          if (std::abs(pk_corrected) > b_p_max) {
            *alpha = alphaTemp;
            *constrType = 5;
            *constrIdx = c_idx + 1;
            *newBlocking = true;
          }
        }
        ratio = c_ratio_tmp - phaseOneCorrectionX;
        alphaTemp = std::fmin(std::abs(ratio), tolcon - ratio) / pk_corrected;
        if (alphaTemp < (*alpha)) {
          *alpha = alphaTemp;
          *constrType = 5;
          *constrIdx = c_idx + 1;
          *newBlocking = true;
          b_p_max = std::abs(pk_corrected);
        }
      }
    }
  }
  *b_toldelta += 6.608625846508183E-7;
  if (b_p_max > 0.0) {
    *alpha = std::fmax(*alpha, 6.608625846508183E-7 / b_p_max);
  }
  if ((*newBlocking) && ((*alpha) > 1.0)) {
    *newBlocking = false;
  }
  *alpha = std::fmin(*alpha, 1.0);
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for ratiotest.cpp
//
// [EOF]
//
