//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: RemoveDependentIneq_.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "RemoveDependentIneq_.h"
#include "ITER_API_internal_types.h"
#include "countsort.h"
#include "removeConstr.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : j_struct_T *d_workingset
//                struct_T *c_qrmanager
//                b_struct_T *memspace
//                double tolfactor
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
void RemoveDependentIneq_(j_struct_T *d_workingset, struct_T *c_qrmanager,
                          b_struct_T *memspace, double tolfactor)
{
  int nActiveConstr;
  int nFixedConstr;
  int nVar;
  nActiveConstr = d_workingset->nActiveConstr;
  nFixedConstr = d_workingset->nWConstr[0] + d_workingset->nWConstr[1];
  nVar = d_workingset->nVar;
  if (((d_workingset->nWConstr[2] + d_workingset->nWConstr[3]) +
       d_workingset->nWConstr[4]) > 0) {
    double tol;
    int b_i;
    int c_idx;
    int i1;
    int nDepIneq;
    tol = (tolfactor * (static_cast<double>(d_workingset->nVar))) *
          2.2204460492503131E-16;
    if ((static_cast<int>(nFixedConstr < 4)) != 0) {
      for (int idx{0}; idx < nFixedConstr; idx++) {
        c_qrmanager->jpvt[idx] = 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = 0; idx < nFixedConstr; idx++) {
        c_qrmanager->jpvt[idx] = 1;
      }
    }
    b_i = nFixedConstr + 1;
    if ((static_cast<int>((nActiveConstr - nFixedConstr) < 4)) != 0) {
      if (b_i <= nActiveConstr) {
        (void)std::memset(&c_qrmanager->jpvt[b_i + -1], 0,
                          (static_cast<unsigned int>(
                              static_cast<int>((nActiveConstr - b_i) + 1))) *
                              (sizeof(int)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_idx = b_i; b_idx <= nActiveConstr; b_idx++) {
        c_qrmanager->jpvt[b_idx - 1] = 0;
      }
    }
    i1 = d_workingset->nActiveConstr;
    for (int idx_col{0}; idx_col < i1; idx_col++) {
      int ix0;
      int iy0;
      iy0 = c_qrmanager->ldq * idx_col;
      ix0 = d_workingset->ldA * idx_col;
      for (int k{0}; k < nVar; k++) {
        (&c_qrmanager->QR[0][0])[iy0 + k] = d_workingset->ATwset[ix0 + k];
      }
    }
    if ((d_workingset->nVar * d_workingset->nActiveConstr) == 0) {
      c_qrmanager->mrows = d_workingset->nVar;
      c_qrmanager->ncols = d_workingset->nActiveConstr;
      c_qrmanager->minRowCol = 0;
    } else {
      int b_u1;
      int u0;
      int y;
      c_qrmanager->usedPivoting = true;
      c_qrmanager->mrows = d_workingset->nVar;
      c_qrmanager->ncols = d_workingset->nActiveConstr;
      u0 = d_workingset->nVar;
      b_u1 = d_workingset->nActiveConstr;
      if (u0 <= b_u1) {
        y = u0;
      } else {
        y = b_u1;
      }
      c_qrmanager->minRowCol = y;
      internal::lapack::c_xgeqp3(c_qrmanager->QR, d_workingset->nVar,
                                 d_workingset->nActiveConstr, c_qrmanager->jpvt,
                                 c_qrmanager->tau);
    }
    nDepIneq = 0;
    c_idx = d_workingset->nActiveConstr - 1;
    while ((c_idx + 1) > nVar) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = c_qrmanager->jpvt[c_idx];
      c_idx--;
    }
    if ((c_idx + 1) <= d_workingset->nVar) {
      int idxDiag;
      bool exitg1;
      idxDiag = c_idx + (c_qrmanager->ldq * c_idx);
      exitg1 = false;
      while ((!exitg1) && ((c_idx + 1) > nFixedConstr)) {
        if (std::abs((&c_qrmanager->QR[0][0])[idxDiag]) < tol) {
          nDepIneq++;
          memspace->workspace_int[nDepIneq - 1] = c_qrmanager->jpvt[c_idx];
          c_idx--;
          idxDiag = (idxDiag - c_qrmanager->ldq) - 1;
        } else {
          exitg1 = true;
        }
      }
    }
    utils::countsort(memspace->workspace_int, nDepIneq,
                     memspace->workspace_sort, nFixedConstr + 1,
                     d_workingset->nActiveConstr);
    for (int d_idx{nDepIneq}; d_idx >= 1; d_idx--) {
      WorkingSet::removeConstr(d_workingset,
                               memspace->workspace_int[d_idx - 1]);
    }
  }
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for RemoveDependentIneq_.cpp
//
// [EOF]
//
