//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: feasibleX0ForWorkingSet.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "feasibleX0ForWorkingSet.h"
#include "ITER_API_internal_types.h"
#include "computeQ_.h"
#include "factorQR.h"
#include "maxConstraintViolation.h"
#include "rt_nonfinite.h"
#include "xzgeqp3.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double workspace[8][15]
//                double xCurrent[8]
//                const j_struct_T *d_workingset
//                struct_T *c_qrmanager
// Return Type  : bool
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace initialize {
bool feasibleX0ForWorkingSet(double workspace[8][15], double xCurrent[8],
                             const j_struct_T *d_workingset,
                             struct_T *c_qrmanager)
{
  double c_B[8][15];
  int b_i8;
  int i3;
  int mWConstr;
  int nVar;
  bool nonDegenerateWset;
  mWConstr = d_workingset->nActiveConstr;
  nVar = d_workingset->nVar;
  nonDegenerateWset = true;
  if (mWConstr != 0) {
    int c_idx;
    int d_lda;
    if ((static_cast<int>(mWConstr < 4)) != 0) {
      for (int idx{0}; idx < mWConstr; idx++) {
        workspace[0][idx] = d_workingset->bwset[idx];
        workspace[1][idx] = d_workingset->bwset[idx];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = 0; idx < mWConstr; idx++) {
        workspace[0][idx] = d_workingset->bwset[idx];
        workspace[1][idx] = d_workingset->bwset[idx];
      }
    }
    d_lda = d_workingset->ldA;
    if ((nVar != 0) && (mWConstr != 0)) {
      int b_i;
      int b_iy;
      int iac;
      b_iy = 0;
      b_i = (d_workingset->ldA * (mWConstr - 1)) + 1;
      iac = 1;
      while (((d_lda > 0) && (iac <= b_i)) || ((d_lda < 0) && (iac >= b_i))) {
        double c;
        int i1;
        c = 0.0;
        i1 = (iac + nVar) - 1;
        for (int ia{iac}; ia <= i1; ia++) {
          c += d_workingset->ATwset[ia - 1] * xCurrent[ia - iac];
        }
        (&workspace[0][0])[b_iy] += -c;
        b_iy++;
        iac += d_lda;
      }
    }
    if (mWConstr >= nVar) {
      int ldq;
      for (int idx_col{0}; idx_col < nVar; idx_col++) {
        int offsetQR;
        offsetQR = c_qrmanager->ldq * idx_col;
        for (int idx_row{0}; idx_row < mWConstr; idx_row++) {
          (&c_qrmanager->QR[0][0])[idx_row + offsetQR] =
              d_workingset->ATwset[idx_col + (d_workingset->ldA * idx_row)];
        }
      }
      if ((mWConstr * nVar) == 0) {
        c_qrmanager->mrows = mWConstr;
        c_qrmanager->ncols = nVar;
        c_qrmanager->minRowCol = 0;
      } else {
        int i7;
        int minmn;
        c_qrmanager->usedPivoting = false;
        c_qrmanager->mrows = mWConstr;
        c_qrmanager->ncols = nVar;
        if ((static_cast<int>(nVar < 4)) != 0) {
          for (int b_idx{0}; b_idx < nVar; b_idx++) {
            c_qrmanager->jpvt[b_idx] = b_idx + 1;
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (int b_idx = 0; b_idx < nVar; b_idx++) {
            c_qrmanager->jpvt[b_idx] = b_idx + 1;
          }
        }
        if (mWConstr <= nVar) {
          i7 = mWConstr;
        } else {
          i7 = nVar;
        }
        c_qrmanager->minRowCol = i7;
        minmn = i7;
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int d_i = 0; d_i < 15; d_i++) {
          c_qrmanager->tau[d_i] = 0.0;
        }
        if (minmn >= 1) {
          internal::reflapack::qrf(c_qrmanager->QR, mWConstr, nVar, minmn,
                                   c_qrmanager->tau);
        }
      }
      QRManager::computeQ_(c_qrmanager, c_qrmanager->mrows);
      ldq = c_qrmanager->ldq;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_i8)

      for (int i4 = 0; i4 < 8; i4++) {
        for (b_i8 = 0; b_i8 < 15; b_i8++) {
          c_B[i4][b_i8] = workspace[i4][b_i8];
        }
      }
      if (nVar != 0) {
        int c_br;
        for (int d_cr{0}; d_cr <= 15; d_cr += 15) {
          int i10;
          int i12;
          i10 = d_cr + 1;
          i12 = d_cr + nVar;
          for (int b_ic{i10}; b_ic <= i12; b_ic++) {
            (&workspace[0][0])[b_ic - 1] = 0.0;
          }
        }
        c_br = -1;
        for (int e_cr{0}; e_cr <= 15; e_cr += 15) {
          int b_ar;
          int i14;
          int i17;
          b_ar = -1;
          i14 = e_cr + 1;
          i17 = e_cr + nVar;
          for (int d_ic{i14}; d_ic <= i17; d_ic++) {
            double b_temp;
            b_temp = 0.0;
            for (int w{0}; w < mWConstr; w++) {
              b_temp += (&c_qrmanager->Q[0][0])[(w + b_ar) + 1] *
                        (&c_B[0][0])[(w + c_br) + 1];
            }
            (&workspace[0][0])[d_ic - 1] += b_temp;
            b_ar += ldq;
          }
          c_br += 15;
        }
      }
      for (int b_j{0}; b_j < 2; b_j++) {
        int b_jBcol;
        b_jBcol = (15 * b_j) - 1;
        for (int c_k{nVar}; c_k >= 1; c_k--) {
          double d;
          int i16;
          int kAcol;
          kAcol = (ldq * (c_k - 1)) - 1;
          i16 = c_k + b_jBcol;
          d = (&workspace[0][0])[i16];
          if (d != 0.0) {
            (&workspace[0][0])[i16] = d / (&c_qrmanager->QR[0][0])[c_k + kAcol];
            for (int e_i{0}; e_i <= (c_k - 2); e_i++) {
              int i18;
              i18 = (e_i + b_jBcol) + 1;
              (&workspace[0][0])[i18] -=
                  (&workspace[0][0])[i16] *
                  (&c_qrmanager->QR[0][0])[(e_i + kAcol) + 1];
            }
          }
        }
      }
    } else {
      int ldq;
      QRManager::factorQR(c_qrmanager, d_workingset->ATwset, nVar, mWConstr,
                          d_workingset->ldA);
      QRManager::computeQ_(c_qrmanager, c_qrmanager->minRowCol);
      ldq = c_qrmanager->ldq;
      for (int j{0}; j < 2; j++) {
        int jBcol;
        jBcol = 15 * j;
        for (int c_i{0}; c_i < mWConstr; c_i++) {
          double temp;
          int iAcol;
          int temp_tmp;
          iAcol = ldq * c_i;
          temp_tmp = c_i + jBcol;
          temp = (&workspace[0][0])[temp_tmp];
          for (int k{0}; k < c_i; k++) {
            temp -= (&c_qrmanager->QR[0][0])[k + iAcol] *
                    (&workspace[0][0])[k + jBcol];
          }
          (&workspace[0][0])[temp_tmp] =
              temp / (&c_qrmanager->QR[0][0])[c_i + iAcol];
        }
      }
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

      for (int i2 = 0; i2 < 8; i2++) {
        for (i3 = 0; i3 < 15; i3++) {
          c_B[i2][i3] = workspace[i2][i3];
        }
      }
      if (nVar != 0) {
        int b_br;
        for (int b_cr{0}; b_cr <= 15; b_cr += 15) {
          int i5;
          int i6;
          i5 = b_cr + 1;
          i6 = b_cr + nVar;
          for (int ic{i5}; ic <= i6; ic++) {
            (&workspace[0][0])[ic - 1] = 0.0;
          }
        }
        b_br = 0;
        for (int c_cr{0}; c_cr <= 15; c_cr += 15) {
          int ar;
          int i11;
          int i9;
          ar = -1;
          i9 = b_br + 1;
          i11 = b_br + mWConstr;
          for (int c_ib{i9}; c_ib <= i11; c_ib++) {
            int i13;
            int i15;
            i13 = c_cr + 1;
            i15 = c_cr + nVar;
            for (int c_ic{i13}; c_ic <= i15; c_ic++) {
              (&workspace[0][0])[c_ic - 1] +=
                  (&c_B[0][0])[c_ib - 1] *
                  (&c_qrmanager->Q[0][0])[(ar + c_ic) - c_cr];
            }
            ar += ldq;
          }
          b_br += 15;
        }
      }
    }
    c_idx = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (c_idx <= (nVar - 1)) {
        if ((std::isinf(workspace[0][c_idx])) ||
            (std::isnan(workspace[0][c_idx]))) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else if ((std::isinf(workspace[1][c_idx])) ||
                   (std::isnan(workspace[1][c_idx]))) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          c_idx++;
        }
      } else {
        double constrViolation_basicX;
        double constrViolation_minnormX;
        if (nVar >= 1) {
          int ixlast;
          ixlast = nVar - 1;
          for (int b_k{0}; b_k <= ixlast; b_k++) {
            (&workspace[0][0])[b_k] += xCurrent[b_k];
          }
        }
        constrViolation_minnormX =
            WorkingSet::maxConstraintViolation(d_workingset, workspace, 1);
        constrViolation_basicX =
            WorkingSet::maxConstraintViolation(d_workingset, workspace, 16);
        if ((constrViolation_minnormX <= 2.2204460492503131E-16) ||
            (constrViolation_minnormX < constrViolation_basicX)) {
          for (int e_k{0}; e_k < nVar; e_k++) {
            xCurrent[e_k] = (&workspace[0][0])[e_k];
          }
        } else {
          for (int d_k{0}; d_k < nVar; d_k++) {
            xCurrent[d_k] = (&workspace[0][0])[d_k + 15];
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return nonDegenerateWset;
}

} // namespace initialize
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for feasibleX0ForWorkingSet.cpp
//
// [EOF]
//
