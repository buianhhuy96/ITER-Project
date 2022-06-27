//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PresolveWorkingSet.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "PresolveWorkingSet.h"
#include "ITER_API_internal_types.h"
#include "RemoveDependentIneq_.h"
#include "computeQ_.h"
#include "countsort.h"
#include "feasibleX0ForWorkingSet.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : i_struct_T *solution
//                b_struct_T *memspace
//                j_struct_T *d_workingset
//                struct_T *c_qrmanager
//                const d_struct_T *options
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void PresolveWorkingSet(i_struct_T *solution, b_struct_T *memspace,
                        j_struct_T *d_workingset, struct_T *c_qrmanager,
                        const d_struct_T *options)
{
  int b_i;
  int mTotalWorkingEq;
  int mTotalWorkingEq_tmp_tmp;
  int mWorkingFixed;
  int nVar;
  solution->state = 82;
  nVar = d_workingset->nVar - 1;
  mWorkingFixed = d_workingset->nWConstr[0];
  mTotalWorkingEq_tmp_tmp =
      d_workingset->nWConstr[0] + d_workingset->nWConstr[1];
  mTotalWorkingEq = mTotalWorkingEq_tmp_tmp;
  b_i = 0;
  if (mTotalWorkingEq_tmp_tmp > 0) {
    double tol;
    int b_u1;
    int idxDiag;
    int nDepInd;
    int totalRank_tmp_tmp;
    int u0;
    bool exitg1;
    for (int idx_row{0}; idx_row < mTotalWorkingEq_tmp_tmp; idx_row++) {
      for (int idx_col{0}; idx_col <= nVar; idx_col++) {
        (&c_qrmanager->QR[0][0])[idx_row + (c_qrmanager->ldq * idx_col)] =
            d_workingset->ATwset[idx_col + (d_workingset->ldA * idx_row)];
      }
    }
    b_u1 = mTotalWorkingEq_tmp_tmp - d_workingset->nVar;
    if (0 >= b_u1) {
      nDepInd = 0;
    } else {
      nDepInd = b_u1;
    }
    if ((static_cast<int>((nVar + 1) < 4)) != 0) {
      if (0 <= nVar) {
        (void)std::memset(
            &c_qrmanager->jpvt[0], 0,
            (static_cast<unsigned int>(static_cast<int>(nVar + 1))) *
                (sizeof(int)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = 0; idx <= nVar; idx++) {
        c_qrmanager->jpvt[idx] = 0;
      }
    }
    if ((mTotalWorkingEq * d_workingset->nVar) == 0) {
      c_qrmanager->mrows = mTotalWorkingEq;
      c_qrmanager->ncols = d_workingset->nVar;
      c_qrmanager->minRowCol = 0;
    } else {
      int c_u1;
      int y;
      c_qrmanager->usedPivoting = true;
      c_qrmanager->mrows = mTotalWorkingEq;
      c_qrmanager->ncols = d_workingset->nVar;
      c_u1 = d_workingset->nVar;
      if (mTotalWorkingEq <= c_u1) {
        y = mTotalWorkingEq;
      } else {
        y = c_u1;
      }
      c_qrmanager->minRowCol = y;
      internal::lapack::c_xgeqp3(c_qrmanager->QR, mTotalWorkingEq,
                                 d_workingset->nVar, c_qrmanager->jpvt,
                                 c_qrmanager->tau);
    }
    tol = (100.0 * (static_cast<double>(d_workingset->nVar))) *
          2.2204460492503131E-16;
    u0 = d_workingset->nVar;
    if (u0 <= mTotalWorkingEq) {
      totalRank_tmp_tmp = u0;
    } else {
      totalRank_tmp_tmp = mTotalWorkingEq;
    }
    idxDiag = totalRank_tmp_tmp + (c_qrmanager->ldq * (totalRank_tmp_tmp - 1));
    exitg1 = false;
    while ((!exitg1) && (idxDiag > 0)) {
      if (std::abs((&c_qrmanager->QR[0][0])[idxDiag - 1]) < tol) {
        idxDiag = (idxDiag - c_qrmanager->ldq) - 1;
        nDepInd++;
      } else {
        exitg1 = true;
      }
    }
    if (nDepInd > 0) {
      int b_idx;
      QRManager::computeQ_(c_qrmanager, c_qrmanager->mrows);
      b_idx = 0;
      exitg1 = false;
      while ((!exitg1) && (b_idx <= (nDepInd - 1))) {
        double qtb;
        int b_ix;
        qtb = 0.0;
        b_ix = c_qrmanager->ldq * ((mTotalWorkingEq - b_idx) - 1);
        for (int b_k{0}; b_k < mTotalWorkingEq; b_k++) {
          qtb += (&c_qrmanager->Q[0][0])[b_ix + b_k] * d_workingset->bwset[b_k];
        }
        if (std::abs(qtb) >= tol) {
          nDepInd = -1;
          exitg1 = true;
        } else {
          b_idx++;
        }
      }
    }
    b_i = nDepInd;
    if (nDepInd > 0) {
      int i1;
      for (int b_idx_col{0}; b_idx_col < mTotalWorkingEq; b_idx_col++) {
        int ix0;
        int iy0;
        iy0 = c_qrmanager->ldq * b_idx_col;
        ix0 = d_workingset->ldA * b_idx_col;
        for (int k{0}; k <= nVar; k++) {
          (&c_qrmanager->QR[0][0])[iy0 + k] = d_workingset->ATwset[ix0 + k];
        }
      }
      if ((static_cast<int>(mWorkingFixed < 4)) != 0) {
        for (int c_idx{0}; c_idx < mWorkingFixed; c_idx++) {
          c_qrmanager->jpvt[c_idx] = 1;
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int c_idx = 0; c_idx < mWorkingFixed; c_idx++) {
          c_qrmanager->jpvt[c_idx] = 1;
        }
      }
      i1 = d_workingset->nWConstr[0] + 1;
      if ((static_cast<int>(((mTotalWorkingEq - i1) + 1) < 4)) != 0) {
        if (i1 <= mTotalWorkingEq) {
          (void)std::memset(&c_qrmanager->jpvt[i1 + -1], 0,
                            (static_cast<unsigned int>(
                                static_cast<int>((mTotalWorkingEq - i1) + 1))) *
                                (sizeof(int)));
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_idx = i1; d_idx <= mTotalWorkingEq; d_idx++) {
          c_qrmanager->jpvt[d_idx - 1] = 0;
        }
      }
      if ((d_workingset->nVar * mTotalWorkingEq) == 0) {
        c_qrmanager->mrows = d_workingset->nVar;
        c_qrmanager->ncols = mTotalWorkingEq;
        c_qrmanager->minRowCol = 0;
      } else {
        int b_u0;
        int b_y;
        c_qrmanager->usedPivoting = true;
        c_qrmanager->mrows = d_workingset->nVar;
        c_qrmanager->ncols = mTotalWorkingEq;
        b_u0 = d_workingset->nVar;
        if (b_u0 <= mTotalWorkingEq) {
          b_y = b_u0;
        } else {
          b_y = mTotalWorkingEq;
        }
        c_qrmanager->minRowCol = b_y;
        internal::lapack::c_xgeqp3(c_qrmanager->QR, d_workingset->nVar,
                                   mTotalWorkingEq, c_qrmanager->jpvt,
                                   c_qrmanager->tau);
      }
      if ((static_cast<int>(nDepInd < 4)) != 0) {
        for (int e_idx{0}; e_idx < nDepInd; e_idx++) {
          memspace->workspace_int[e_idx] =
              c_qrmanager->jpvt[(mTotalWorkingEq - nDepInd) + e_idx];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int e_idx = 0; e_idx < nDepInd; e_idx++) {
          memspace->workspace_int[e_idx] =
              c_qrmanager->jpvt[(mTotalWorkingEq - nDepInd) + e_idx];
        }
      }
      utils::countsort(memspace->workspace_int, nDepInd,
                       memspace->workspace_sort, 1, mTotalWorkingEq);
      for (int f_idx{nDepInd}; f_idx >= 1; f_idx--) {
        int i2;
        i2 = d_workingset->nWConstr[0] + d_workingset->nWConstr[1];
        if (i2 != 0) {
          int i3;
          i3 = memspace->workspace_int[f_idx - 1];
          if (i3 <= i2) {
            if ((d_workingset->nActiveConstr == i2) || (i3 == i2)) {
              d_workingset->mEqRemoved++;
              // A check that is always false is detected at compile-time.
              // Eliminating code that follows.
            } else {
              int TYPE;
              int i4;
              d_workingset->mEqRemoved++;
              TYPE = d_workingset->Wid[i3 - 1] - 1;
              // A check that is always false is detected at compile-time.
              // Eliminating code that follows.
              d_workingset->bwset[i3 - 1] = d_workingset->bwset[i2 - 1];
              d_workingset->Wid[i2 - 1] =
                  d_workingset->Wid[d_workingset->nActiveConstr - 1];
              d_workingset->Wlocalidx[i2 - 1] =
                  d_workingset->Wlocalidx[d_workingset->nActiveConstr - 1];
              i4 = d_workingset->nVar;
              for (int g_idx{0}; g_idx < i4; g_idx++) {
                d_workingset->ATwset[g_idx + (d_workingset->ldA * (i2 - 1))] =
                    d_workingset
                        ->ATwset[g_idx + (d_workingset->ldA *
                                          (d_workingset->nActiveConstr - 1))];
              }
              d_workingset->bwset[i2 - 1] =
                  d_workingset->bwset[d_workingset->nActiveConstr - 1];
              d_workingset->nActiveConstr--;
              d_workingset->nWConstr[TYPE]--;
            }
          }
        }
      }
    }
  }
  if ((b_i != -1) && (d_workingset->nActiveConstr <= c_qrmanager->ldq)) {
    bool guard1{false};
    bool okWorkingSet;
    RemoveDependentIneq_(d_workingset, c_qrmanager, memspace, 100.0);
    okWorkingSet = feasibleX0ForWorkingSet(
        memspace->workspace_double, solution->xstar, d_workingset, c_qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      bool b_okWorkingSet;
      RemoveDependentIneq_(d_workingset, c_qrmanager, memspace, 1000.0);
      b_okWorkingSet =
          feasibleX0ForWorkingSet(memspace->workspace_double, solution->xstar,
                                  d_workingset, c_qrmanager);
      if (!b_okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1 && ((d_workingset->nWConstr[0] + d_workingset->nWConstr[1]) ==
                   d_workingset->nVar)) {
      double constrViolation;
      constrViolation =
          WorkingSet::b_maxConstraintViolation(d_workingset, solution->xstar);
      if (constrViolation > options->ConstraintTolerance) {
        solution->state = -2;
      }
    }
  } else {
    int idxEndIneq;
    int idxStartIneq;
    solution->state = -3;
    idxStartIneq = (d_workingset->nWConstr[0] + d_workingset->nWConstr[1]) + 1;
    idxEndIneq = d_workingset->nActiveConstr;
    for (int idx_global{idxStartIneq}; idx_global <= idxEndIneq; idx_global++) {
      d_workingset->isActiveConstr
          [(d_workingset->isActiveIdx[d_workingset->Wid[idx_global - 1] - 1] +
            d_workingset->Wlocalidx[idx_global - 1]) -
           2] = false;
    }
    d_workingset->nWConstr[2] = 0;
    d_workingset->nWConstr[3] = 0;
    d_workingset->nWConstr[4] = 0;
    d_workingset->nActiveConstr =
        d_workingset->nWConstr[0] + d_workingset->nWConstr[1];
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for PresolveWorkingSet.cpp
//
// [EOF]
//
