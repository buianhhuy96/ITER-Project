//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: compute_deltax.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "compute_deltax.h"
#include "ITER_API_internal_types.h"
#include "factor.h"
#include "fullColLDL2_.h"
#include "ixamax.h"
#include "rt_nonfinite.h"
#include "solve.h"
#include "solve1.h"
#include "xgemm.h"
#include "xpotrf.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : const double H[7][7]
//                i_struct_T *solution
//                b_struct_T *memspace
//                const struct_T *c_qrmanager
//                s_struct_T *c_cholmanager
//                const r_struct_T *b_objective
//                bool alwaysPositiveDef
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
void compute_deltax(const double H[7][7], i_struct_T *solution,
                    b_struct_T *memspace, const struct_T *c_qrmanager,
                    s_struct_T *c_cholmanager, const r_struct_T *b_objective,
                    bool alwaysPositiveDef)
{
  int i4;
  int idx_row;
  int mNull;
  int mNull_tmp_tmp;
  int nVar;
  int nVar_tmp_tmp;
  nVar_tmp_tmp = c_qrmanager->mrows - 1;
  nVar = nVar_tmp_tmp;
  mNull_tmp_tmp = c_qrmanager->mrows - c_qrmanager->ncols;
  mNull = mNull_tmp_tmp;
  if (mNull_tmp_tmp <= 0) {
    if ((static_cast<int>((nVar_tmp_tmp + 1) < 4)) != 0) {
      if (0 <= nVar_tmp_tmp) {
        (void)std::memset(
            &solution->searchDir[0], 0,
            (static_cast<unsigned int>(static_cast<int>(nVar_tmp_tmp + 1))) *
                (sizeof(double)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_idx = 0; b_idx <= nVar; b_idx++) {
        solution->searchDir[b_idx] = 0.0;
      }
    }
  } else {
    if ((static_cast<int>((nVar_tmp_tmp + 1) < 4)) != 0) {
      for (int idx{0}; idx <= nVar_tmp_tmp; idx++) {
        solution->searchDir[idx] = -b_objective->grad[idx];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = 0; idx <= nVar; idx++) {
        solution->searchDir[idx] = -b_objective->grad[idx];
      }
    }
    if (c_qrmanager->ncols <= 0) {
      switch (b_objective->objtype) {
      case 5:
        break;
      case 3: {
        if (alwaysPositiveDef) {
          c_cholmanager->ndims = c_qrmanager->mrows;
          for (int d_idx{0}; d_idx <= nVar; d_idx++) {
            int ix0;
            int iy0;
            ix0 = (nVar + 1) * d_idx;
            iy0 = c_cholmanager->ldm * d_idx;
            for (int k{0}; k <= nVar; k++) {
              (&c_cholmanager->FMat[0][0])[iy0 + k] = (&H[0][0])[ix0 + k];
            }
          }
          c_cholmanager->info = internal::lapack::xpotrf(
              c_qrmanager->mrows, c_cholmanager->FMat, c_cholmanager->ldm);
        } else {
          DynamicRegCholManager::factor(c_cholmanager, H, c_qrmanager->mrows,
                                        c_qrmanager->mrows);
        }
        if (c_cholmanager->info != 0) {
          solution->state = -6;
        } else if (alwaysPositiveDef) {
          CholManager::solve(c_cholmanager, solution->searchDir);
        } else {
          DynamicRegCholManager::solve(c_cholmanager, solution->searchDir);
        }
      } break;
      case 4: {
        if (alwaysPositiveDef) {
          int nVarOrig;
          nVarOrig = b_objective->b_nvar;
          c_cholmanager->ndims = b_objective->b_nvar;
          for (int e_idx{0}; e_idx < nVarOrig; e_idx++) {
            int b_ix0;
            int b_iy0;
            b_ix0 = nVarOrig * e_idx;
            b_iy0 = c_cholmanager->ldm * e_idx;
            for (int b_k{0}; b_k < nVarOrig; b_k++) {
              (&c_cholmanager->FMat[0][0])[b_iy0 + b_k] =
                  (&H[0][0])[b_ix0 + b_k];
            }
          }
          c_cholmanager->info = internal::lapack::xpotrf(
              b_objective->b_nvar, c_cholmanager->FMat, c_cholmanager->ldm);
          if (c_cholmanager->info != 0) {
            solution->state = -6;
          } else {
            double b_a;
            int c_ix0;
            int i2;
            CholManager::solve(c_cholmanager, solution->searchDir);
            b_a = 1.0 / b_objective->beta;
            c_ix0 = b_objective->b_nvar + 1;
            i2 = c_qrmanager->mrows;
            if ((static_cast<int>(((i2 - c_ix0) + 1) < 4)) != 0) {
              for (int c_k{c_ix0}; c_k <= i2; c_k++) {
                solution->searchDir[c_k - 1] *= b_a;
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int c_k = c_ix0; c_k <= i2; c_k++) {
                solution->searchDir[c_k - 1] *= b_a;
              }
            }
          }
        }
      } break;
      default:
        /* no actions */
        break;
      }
    } else {
      int nullStartIdx;
      int nullStartIdx_tmp;
      nullStartIdx_tmp = (c_qrmanager->ldq * c_qrmanager->ncols) + 1;
      nullStartIdx = nullStartIdx_tmp;
      if (b_objective->objtype == 5) {
        int b_m;
        int c_m;
        int d_lda;
        for (int c_idx{0}; c_idx < mNull; c_idx++) {
          (&memspace->workspace_double[0][0])[c_idx] =
              -(&c_qrmanager->Q[0][0])[nVar + (c_qrmanager->ldq *
                                               (c_qrmanager->ncols + c_idx))];
        }
        b_m = c_qrmanager->mrows - 1;
        c_m = b_m;
        d_lda = c_qrmanager->ldq;
        if (c_qrmanager->mrows != 0) {
          int b_ix;
          int i3;
          int iac;
          if ((static_cast<int>((b_m + 1) < 4)) != 0) {
            if (0 <= b_m) {
              (void)std::memset(
                  &solution->searchDir[0], 0,
                  (static_cast<unsigned int>(static_cast<int>(b_m + 1))) *
                      (sizeof(double)));
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

            for (int b_iy = 0; b_iy <= c_m; b_iy++) {
              solution->searchDir[b_iy] = 0.0;
            }
          }
          b_ix = 0;
          i3 = nullStartIdx + (c_qrmanager->ldq * (mNull - 1));
          iac = nullStartIdx;
          while (((d_lda > 0) && (iac <= i3)) || ((d_lda < 0) && (iac >= i3))) {
            int i5;
            i5 = iac + c_m;
            for (int ia{iac}; ia <= i5; ia++) {
              int i9;
              i9 = ia - iac;
              solution->searchDir[i9] +=
                  (&c_qrmanager->Q[0][0])[ia - 1] *
                  (&memspace->workspace_double[0][0])[b_ix];
            }
            b_ix++;
            iac += d_lda;
          }
        }
      } else {
        if (b_objective->objtype == 3) {
          int b_i;
          b_i = c_qrmanager->mrows - c_qrmanager->ncols;
          internal::blas::xgemm(c_qrmanager->mrows, b_i, c_qrmanager->mrows, H,
                                c_qrmanager->mrows, c_qrmanager->Q,
                                nullStartIdx_tmp, c_qrmanager->ldq,
                                memspace->workspace_double);
          internal::blas::b_xgemm(b_i, b_i, c_qrmanager->mrows, c_qrmanager->Q,
                                  nullStartIdx_tmp, c_qrmanager->ldq,
                                  memspace->workspace_double,
                                  c_cholmanager->FMat, c_cholmanager->ldm);
        } else if (alwaysPositiveDef) {
          int b_mNull;
          int i1;
          int nVars;
          int nullStart;
          nVars = c_qrmanager->mrows;
          i1 = c_qrmanager->mrows - c_qrmanager->ncols;
          b_mNull = i1;
          nullStart = nullStartIdx_tmp;
          internal::blas::xgemm(b_objective->b_nvar, i1, b_objective->b_nvar, H,
                                b_objective->b_nvar, c_qrmanager->Q,
                                nullStartIdx_tmp, c_qrmanager->ldq,
                                memspace->workspace_double);
#pragma omp parallel for num_threads(omp_get_max_threads()) private(idx_row, i4)

          for (int idx_col = 0; idx_col < b_mNull; idx_col++) {
            i4 = b_objective->b_nvar + 1;
            for (idx_row = i4; idx_row <= nVars; idx_row++) {
              memspace->workspace_double[idx_col][idx_row - 1] =
                  b_objective->beta *
                  c_qrmanager->Q[idx_col + c_qrmanager->ncols][idx_row - 1];
            }
          }
          internal::blas::b_xgemm(b_mNull, b_mNull, c_qrmanager->mrows,
                                  c_qrmanager->Q, nullStart, c_qrmanager->ldq,
                                  memspace->workspace_double,
                                  c_cholmanager->FMat, c_cholmanager->ldm);
        } else {
          /* no actions */
        }
        if (alwaysPositiveDef) {
          c_cholmanager->ndims = mNull;
          c_cholmanager->info = internal::lapack::xpotrf(
              mNull, c_cholmanager->FMat, c_cholmanager->ldm);
        } else {
          double SCALED_REG_PRIMAL;
          int A_maxDiag_idx;
          SCALED_REG_PRIMAL =
              (1.4901161193847656E-8 * c_cholmanager->scaleFactor) *
              (static_cast<double>(mNull));
          c_cholmanager->ndims = mNull;
          A_maxDiag_idx = internal::blas::ixamax(mNull, c_cholmanager->FMat,
                                                 c_cholmanager->ldm + 1) -
                          1;
          c_cholmanager->regTol_ = std::fmax(
              std::abs((&c_cholmanager
                             ->FMat[0][0])[A_maxDiag_idx + (c_cholmanager->ldm *
                                                            A_maxDiag_idx)]) *
                  2.2204460492503131E-16,
              std::abs(SCALED_REG_PRIMAL));
          DynamicRegCholManager::fullColLDL2_(c_cholmanager, mNull,
                                              SCALED_REG_PRIMAL);
          if (c_cholmanager->ConvexCheck) {
            int f_idx;
            f_idx = 0;
            int exitg1;
            do {
              exitg1 = 0;
              if (f_idx <= (mNull - 1)) {
                if ((&c_cholmanager->FMat[0][0])[f_idx + (c_cholmanager->ldm *
                                                          f_idx)] <= 0.0) {
                  c_cholmanager->info = (-f_idx) - 1;
                  exitg1 = 1;
                } else {
                  f_idx++;
                }
              } else {
                c_cholmanager->ConvexCheck = false;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          }
        }
        if (c_cholmanager->info != 0) {
          solution->state = -6;
        } else {
          int e_lda;
          int f_lda;
          e_lda = c_qrmanager->ldq;
          if (c_qrmanager->mrows != 0) {
            int b_iac;
            int d_iy;
            int i7;
            if ((static_cast<int>(mNull < 4)) != 0) {
              for (int c_iy{0}; c_iy < mNull; c_iy++) {
                (&memspace->workspace_double[0][0])[c_iy] = 0.0;
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int c_iy = 0; c_iy < mNull; c_iy++) {
                (&memspace->workspace_double[0][0])[c_iy] = 0.0;
              }
            }
            d_iy = 0;
            i7 = nullStartIdx + (c_qrmanager->ldq * (mNull - 1));
            b_iac = nullStartIdx;
            while (((e_lda > 0) && (b_iac <= i7)) ||
                   ((e_lda < 0) && (b_iac >= i7))) {
              double c;
              int i10;
              c = 0.0;
              i10 = b_iac + nVar;
              for (int b_ia{b_iac}; b_ia <= i10; b_ia++) {
                c += (&c_qrmanager->Q[0][0])[b_ia - 1] *
                     b_objective->grad[b_ia - b_iac];
              }
              (&memspace->workspace_double[0][0])[d_iy] += -c;
              d_iy++;
              b_iac += e_lda;
            }
          }
          if (alwaysPositiveDef) {
            int i_n;
            int u_n;
            i_n = c_cholmanager->ndims;
            if (c_cholmanager->ndims != 0) {
              for (int b_j{0}; b_j < i_n; b_j++) {
                double temp;
                int jA;
                jA = b_j * c_cholmanager->ldm;
                temp = (&memspace->workspace_double[0][0])[b_j];
                for (int d_i{0}; d_i < b_j; d_i++) {
                  temp -= (&c_cholmanager->FMat[0][0])[jA + d_i] *
                          (&memspace->workspace_double[0][0])[d_i];
                }
                (&memspace->workspace_double[0][0])[b_j] =
                    temp / (&c_cholmanager->FMat[0][0])[jA + b_j];
              }
            }
            u_n = c_cholmanager->ndims;
            if (c_cholmanager->ndims != 0) {
              for (int c_j{u_n}; c_j >= 1; c_j--) {
                int b_jjA;
                b_jjA = (c_j + ((c_j - 1) * c_cholmanager->ldm)) - 1;
                (&memspace->workspace_double[0][0])[c_j - 1] /=
                    (&c_cholmanager->FMat[0][0])[b_jjA];
                for (int e_i{0}; e_i <= (c_j - 2); e_i++) {
                  int d_ix;
                  d_ix = (c_j - e_i) - 2;
                  (&memspace->workspace_double[0][0])[d_ix] -=
                      (&memspace->workspace_double[0][0])[c_j - 1] *
                      (&c_cholmanager->FMat[0][0])[(b_jjA - e_i) - 1];
                }
              }
            }
          } else {
            int h_n;
            int i6;
            int v_n;
            h_n = c_cholmanager->ndims - 2;
            if (c_cholmanager->ndims != 0) {
              for (int j{0}; j <= (h_n + 1); j++) {
                int b_i8;
                int jjA;
                jjA = j + (j * c_cholmanager->ldm);
                b_i8 = h_n - j;
                for (int c_i{0}; c_i <= b_i8; c_i++) {
                  int c_ix;
                  c_ix = (j + c_i) + 1;
                  (&memspace->workspace_double[0][0])[c_ix] -=
                      (&memspace->workspace_double[0][0])[j] *
                      (&c_cholmanager->FMat[0][0])[(jjA + c_i) + 1];
                }
              }
            }
            i6 = c_cholmanager->ndims;
            for (int g_idx{0}; g_idx < i6; g_idx++) {
              (&memspace->workspace_double[0][0])[g_idx] /=
                  (&c_cholmanager
                        ->FMat[0][0])[g_idx + (c_cholmanager->ldm * g_idx)];
            }
            v_n = c_cholmanager->ndims;
            if (c_cholmanager->ndims != 0) {
              for (int d_j{v_n}; d_j >= 1; d_j--) {
                double b_temp;
                int b_jA;
                int i11;
                b_jA = (d_j - 1) * c_cholmanager->ldm;
                b_temp = (&memspace->workspace_double[0][0])[d_j - 1];
                i11 = d_j + 1;
                for (int g_i{v_n}; g_i >= i11; g_i--) {
                  b_temp -= (&c_cholmanager->FMat[0][0])[(b_jA + g_i) - 1] *
                            (&memspace->workspace_double[0][0])[g_i - 1];
                }
                (&memspace->workspace_double[0][0])[d_j - 1] = b_temp;
              }
            }
          }
          f_lda = c_qrmanager->ldq;
          if (c_qrmanager->mrows != 0) {
            int c_iac;
            int e_ix;
            int i12;
            if ((static_cast<int>((nVar + 1) < 4)) != 0) {
              if (0 <= nVar) {
                (void)std::memset(
                    &solution->searchDir[0], 0,
                    (static_cast<unsigned int>(static_cast<int>(nVar + 1))) *
                        (sizeof(double)));
              }
            } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

              for (int e_iy = 0; e_iy <= nVar; e_iy++) {
                solution->searchDir[e_iy] = 0.0;
              }
            }
            e_ix = 0;
            i12 = nullStartIdx + (c_qrmanager->ldq * (mNull - 1));
            c_iac = nullStartIdx;
            while (((f_lda > 0) && (c_iac <= i12)) ||
                   ((f_lda < 0) && (c_iac >= i12))) {
              int i13;
              i13 = c_iac + nVar;
              for (int c_ia{c_iac}; c_ia <= i13; c_ia++) {
                int i14;
                i14 = c_ia - c_iac;
                solution->searchDir[i14] +=
                    (&c_qrmanager->Q[0][0])[c_ia - 1] *
                    (&memspace->workspace_double[0][0])[e_ix];
              }
              e_ix++;
              c_iac += f_lda;
            }
          }
        }
      }
    }
  }
}

} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for compute_deltax.cpp
//
// [EOF]
//
