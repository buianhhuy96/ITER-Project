//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "sortIdx.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace coder {
namespace internal {
static void b_merge(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                    int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                    ::coder::array<int, 1U> &xwork);

static void c_merge(::coder::array<int, 1U> &idx,
                    ::coder::array<double, 1U> &b_x, int offset, int np, int nq,
                    ::coder::array<int, 1U> &iwork,
                    ::coder::array<double, 1U> &xwork);

static void c_merge_block(::coder::array<int, 1U> &idx,
                          ::coder::array<double, 1U> &b_x, int offset, int h_n,
                          int preSortLevel, ::coder::array<int, 1U> &iwork,
                          ::coder::array<double, 1U> &xwork);

static void merge(::coder::array<int, 1U> &idx, ::coder::array<float, 1U> &b_x,
                  int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                  ::coder::array<float, 1U> &xwork);

static void merge_block(::coder::array<int, 1U> &idx,
                        ::coder::array<float, 1U> &b_x, int offset, int h_n,
                        int preSortLevel, ::coder::array<int, 1U> &iwork,
                        ::coder::array<float, 1U> &xwork);

} // namespace internal
} // namespace coder

// Function Definitions
//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<int, 1U> &b_x
//                int offset
//                int np
//                int nq
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<int, 1U> &xwork
// Return Type  : void
//
namespace coder {
namespace internal {
static void b_merge(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                    int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                    ::coder::array<int, 1U> &xwork)
{
  int i2;
  int i4;
  if ((np != 0) && (nq != 0)) {
    int b_q;
    int h_n;
    int i1;
    int iout;
    int n_tmp_tmp;
    int p;
    n_tmp_tmp = np + nq;
    h_n = n_tmp_tmp;
    if ((static_cast<int>(n_tmp_tmp < 4)) != 0) {
      for (int j{0}; j < n_tmp_tmp; j++) {
        int b_i;
        b_i = offset + j;
        iwork[j] = idx[b_i];
        xwork[j] = b_x[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

      for (int j = 0; j < h_n; j++) {
        i2 = offset + j;
        iwork[j] = idx[i2];
        xwork[j] = b_x[i2];
      }
    }
    p = 0;
    b_q = np;
    i1 = np + nq;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[b_q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[b_q];
        b_x[iout] = xwork[b_q];
        if ((b_q + 1) < i1) {
          b_q++;
        } else {
          int offset1;
          offset1 = iout - p;
          if ((static_cast<int>((np - p) < 4)) != 0) {
            for (int b_j{p + 1}; b_j <= np; b_j++) {
              int i3;
              i3 = offset1 + b_j;
              idx[i3] = iwork[b_j - 1];
              b_x[i3] = xwork[b_j - 1];
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

            for (int b_j = p + 1; b_j <= np; b_j++) {
              i4 = offset1 + b_j;
              idx[i4] = iwork[b_j - 1];
              b_x[i4] = xwork[b_j - 1];
            }
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<double, 1U> &b_x
//                int offset
//                int np
//                int nq
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
static void c_merge(::coder::array<int, 1U> &idx,
                    ::coder::array<double, 1U> &b_x, int offset, int np, int nq,
                    ::coder::array<int, 1U> &iwork,
                    ::coder::array<double, 1U> &xwork)
{
  int i2;
  int i4;
  if ((np != 0) && (nq != 0)) {
    int b_q;
    int h_n;
    int i1;
    int iout;
    int n_tmp_tmp;
    int p;
    n_tmp_tmp = np + nq;
    h_n = n_tmp_tmp;
    if ((static_cast<int>(n_tmp_tmp < 4)) != 0) {
      for (int j{0}; j < n_tmp_tmp; j++) {
        int b_i;
        b_i = offset + j;
        iwork[j] = idx[b_i];
        xwork[j] = b_x[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

      for (int j = 0; j < h_n; j++) {
        i2 = offset + j;
        iwork[j] = idx[i2];
        xwork[j] = b_x[i2];
      }
    }
    p = 0;
    b_q = np;
    i1 = np + nq;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[b_q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[b_q];
        b_x[iout] = xwork[b_q];
        if ((b_q + 1) < i1) {
          b_q++;
        } else {
          int offset1;
          offset1 = iout - p;
          if ((static_cast<int>((np - p) < 4)) != 0) {
            for (int b_j{p + 1}; b_j <= np; b_j++) {
              int i3;
              i3 = offset1 + b_j;
              idx[i3] = iwork[b_j - 1];
              b_x[i3] = xwork[b_j - 1];
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

            for (int b_j = p + 1; b_j <= np; b_j++) {
              i4 = offset1 + b_j;
              idx[i4] = iwork[b_j - 1];
              b_x[i4] = xwork[b_j - 1];
            }
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<double, 1U> &b_x
//                int offset
//                int h_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
static void c_merge_block(::coder::array<int, 1U> &idx,
                          ::coder::array<double, 1U> &b_x, int offset, int h_n,
                          int preSortLevel, ::coder::array<int, 1U> &iwork,
                          ::coder::array<double, 1U> &xwork)
{
  int bLen;
  int b_nBlocks;
  b_nBlocks = asr_s32(h_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (b_nBlocks > 1) {
    int bLen2;
    int nPairs;
    if ((b_nBlocks & 1) != 0) {
      int nTail;
      int tailOffset;
      b_nBlocks--;
      tailOffset = bLen * b_nBlocks;
      nTail = h_n - tailOffset;
      if (nTail > bLen) {
        c_merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    bLen2 = bLen * 2;
    nPairs = asr_s32(b_nBlocks, 1U);
    for (int k{0}; k < nPairs; k++) {
      c_merge(idx, b_x, offset + (k * bLen2), bLen, bLen, iwork, xwork);
    }
    bLen = bLen2;
    b_nBlocks = nPairs;
  }
  if (h_n > bLen) {
    c_merge(idx, b_x, offset, bLen, h_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<float, 1U> &b_x
//                int offset
//                int np
//                int nq
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<float, 1U> &xwork
// Return Type  : void
//
static void merge(::coder::array<int, 1U> &idx, ::coder::array<float, 1U> &b_x,
                  int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
                  ::coder::array<float, 1U> &xwork)
{
  int i2;
  int i4;
  if ((np != 0) && (nq != 0)) {
    int b_q;
    int h_n;
    int i1;
    int iout;
    int n_tmp_tmp;
    int p;
    n_tmp_tmp = np + nq;
    h_n = n_tmp_tmp;
    if ((static_cast<int>(n_tmp_tmp < 4)) != 0) {
      for (int j{0}; j < n_tmp_tmp; j++) {
        int b_i;
        b_i = offset + j;
        iwork[j] = idx[b_i];
        xwork[j] = b_x[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

      for (int j = 0; j < h_n; j++) {
        i2 = offset + j;
        iwork[j] = idx[i2];
        xwork[j] = b_x[i2];
      }
    }
    p = 0;
    b_q = np;
    i1 = np + nq;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[b_q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[b_q];
        b_x[iout] = xwork[b_q];
        if ((b_q + 1) < i1) {
          b_q++;
        } else {
          int offset1;
          offset1 = iout - p;
          if ((static_cast<int>((np - p) < 4)) != 0) {
            for (int b_j{p + 1}; b_j <= np; b_j++) {
              int i3;
              i3 = offset1 + b_j;
              idx[i3] = iwork[b_j - 1];
              b_x[i3] = xwork[b_j - 1];
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

            for (int b_j = p + 1; b_j <= np; b_j++) {
              i4 = offset1 + b_j;
              idx[i4] = iwork[b_j - 1];
              b_x[i4] = xwork[b_j - 1];
            }
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<float, 1U> &b_x
//                int offset
//                int h_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<float, 1U> &xwork
// Return Type  : void
//
static void merge_block(::coder::array<int, 1U> &idx,
                        ::coder::array<float, 1U> &b_x, int offset, int h_n,
                        int preSortLevel, ::coder::array<int, 1U> &iwork,
                        ::coder::array<float, 1U> &xwork)
{
  int bLen;
  int b_nBlocks;
  b_nBlocks = asr_s32(h_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (b_nBlocks > 1) {
    int bLen2;
    int nPairs;
    if ((b_nBlocks & 1) != 0) {
      int nTail;
      int tailOffset;
      b_nBlocks--;
      tailOffset = bLen * b_nBlocks;
      nTail = h_n - tailOffset;
      if (nTail > bLen) {
        merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }
    bLen2 = bLen * 2;
    nPairs = asr_s32(b_nBlocks, 1U);
    for (int k{0}; k < nPairs; k++) {
      merge(idx, b_x, offset + (k * bLen2), bLen, bLen, iwork, xwork);
    }
    bLen = bLen2;
    b_nBlocks = nPairs;
  }
  if (h_n > bLen) {
    merge(idx, b_x, offset, bLen, h_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<int, 1U> &b_x
//                int offset
//                int h_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<int, 1U> &xwork
// Return Type  : void
//
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int h_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork)
{
  int bLen;
  int b_nBlocks;
  b_nBlocks = asr_s32(h_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (b_nBlocks > 1) {
    int bLen2;
    int nPairs;
    if ((b_nBlocks & 1) != 0) {
      int nTail;
      int tailOffset;
      b_nBlocks--;
      tailOffset = bLen * b_nBlocks;
      nTail = h_n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    bLen2 = bLen * 2;
    nPairs = asr_s32(b_nBlocks, 1U);
    for (int k{0}; k < nPairs; k++) {
      b_merge(idx, b_x, offset + (k * bLen2), bLen, bLen, iwork, xwork);
    }
    bLen = bLen2;
    b_nBlocks = nPairs;
  }
  if (h_n > bLen) {
    b_merge(idx, b_x, offset, bLen, h_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<float, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void b_sortIdx(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  array<float, 1U> g_x;
  array<float, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> iwork;
  float b_xwork[256];
  float x4[4];
  int b_iwork[256];
  int idx4[4];
  int b_xwork_tmp;
  int e_idx_tmp;
  int f_idx_tmp;
  int loop_ub;
  unsigned int unnamed_idx_0;
  signed char perm[4];
  unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
  idx.set_size(static_cast<int>(unnamed_idx_0));
  loop_ub = static_cast<int>(unnamed_idx_0);
  if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  }
  if (b_x.size(0) != 0) {
    int b_loop_ub;
    int b_m;
    unsigned int b_unnamed_idx_0;
    int c_ib;
    int c_loop_ub;
    int d_loop_ub;
    int e_loop_ub;
    int f_loop_ub;
    int g_loop_ub;
    int h_loop_ub;
    int h_n;
    int i_loop_ub;
    int i_n;
    int nNaNs;
    int nNonNaN;
    int preSortLevel;
    int wOffset;
    b_loop_ub = static_cast<int>(unnamed_idx_0);
    b_idx.set_size(static_cast<int>(unnamed_idx_0));
    c_loop_ub = static_cast<int>(unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_idx[i1] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < c_loop_ub; i1++) {
        b_idx[i1] = 0;
      }
    }
    h_n = b_x.size(0);
    d_loop_ub = b_x.size(0);
    g_x.set_size(d_loop_ub);
    e_loop_ub = d_loop_ub;
    if ((static_cast<int>(d_loop_ub < 4)) != 0) {
      for (int i2{0}; i2 < d_loop_ub; i2++) {
        g_x[i2] = b_x[i2];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < e_loop_ub; i2++) {
        g_x[i2] = b_x[i2];
      }
    }
    i_n = b_x.size(0);
    for (int c_i{0}; c_i < 4; c_i++) {
      x4[c_i] = 0.0F;
      idx4[c_i] = 0;
    }
    iwork.set_size(static_cast<int>(unnamed_idx_0));
    f_loop_ub = static_cast<int>(unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
      for (int i3{0}; i3 < f_loop_ub; i3++) {
        iwork[i3] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < f_loop_ub; i3++) {
        iwork[i3] = 0;
      }
    }
    b_unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
    xwork.set_size(static_cast<int>(b_unnamed_idx_0));
    g_loop_ub = static_cast<int>(b_unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(b_unnamed_idx_0)) < 4)) != 0) {
      for (int i4{0}; i4 < g_loop_ub; i4++) {
        xwork[i4] = 0.0F;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < g_loop_ub; i4++) {
        xwork[i4] = 0.0F;
      }
    }
    nNaNs = 0;
    c_ib = -1;
    for (int k{0}; k < i_n; k++) {
      if (std::isnan(g_x[k])) {
        int idx_tmp;
        idx_tmp = (i_n - nNaNs) - 1;
        b_idx[idx_tmp] = k + 1;
        xwork[idx_tmp] = g_x[k];
        nNaNs++;
      } else {
        c_ib++;
        idx4[c_ib] = k + 1;
        x4[c_ib] = g_x[k];
        if ((c_ib + 1) == 4) {
          float f;
          float f1;
          int b_i1;
          int b_i2;
          int b_i3;
          int b_i4;
          int quartetOffset;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            b_i1 = 1;
            b_i2 = 2;
          } else {
            b_i1 = 2;
            b_i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            b_i3 = 3;
            b_i4 = 4;
          } else {
            b_i3 = 4;
            b_i4 = 3;
          }
          f = x4[b_i1 - 1];
          f1 = x4[b_i3 - 1];
          if (f >= f1) {
            float f3;
            f3 = x4[b_i2 - 1];
            if (f3 >= f1) {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i2);
              perm[2] = static_cast<signed char>(b_i3);
              perm[3] = static_cast<signed char>(b_i4);
            } else if (f3 >= x4[b_i4 - 1]) {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i3);
              perm[2] = static_cast<signed char>(b_i2);
              perm[3] = static_cast<signed char>(b_i4);
            } else {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i3);
              perm[2] = static_cast<signed char>(b_i4);
              perm[3] = static_cast<signed char>(b_i2);
            }
          } else {
            float b_f2;
            b_f2 = x4[b_i4 - 1];
            if (f >= b_f2) {
              if (x4[b_i2 - 1] >= b_f2) {
                perm[0] = static_cast<signed char>(b_i3);
                perm[1] = static_cast<signed char>(b_i1);
                perm[2] = static_cast<signed char>(b_i2);
                perm[3] = static_cast<signed char>(b_i4);
              } else {
                perm[0] = static_cast<signed char>(b_i3);
                perm[1] = static_cast<signed char>(b_i1);
                perm[2] = static_cast<signed char>(b_i4);
                perm[3] = static_cast<signed char>(b_i2);
              }
            } else {
              perm[0] = static_cast<signed char>(b_i3);
              perm[1] = static_cast<signed char>(b_i4);
              perm[2] = static_cast<signed char>(b_i1);
              perm[3] = static_cast<signed char>(b_i2);
            }
          }
          b_idx[quartetOffset - 3] = idx4[perm[0] - 1];
          b_idx[quartetOffset - 2] = idx4[perm[1] - 1];
          b_idx[quartetOffset - 1] = idx4[perm[2] - 1];
          b_idx[quartetOffset] = idx4[perm[3] - 1];
          g_x[quartetOffset - 3] = x4[perm[0] - 1];
          g_x[quartetOffset - 2] = x4[perm[1] - 1];
          g_x[quartetOffset - 1] = x4[perm[2] - 1];
          g_x[quartetOffset] = x4[perm[3] - 1];
          c_ib = -1;
        }
      }
    }
    wOffset = (b_x.size(0) - nNaNs) - 1;
    if ((c_ib + 1) > 0) {
      for (int d_i{0}; d_i < 4; d_i++) {
        perm[d_i] = 0;
      }
      if ((c_ib + 1) == 1) {
        perm[0] = 1;
      } else if ((c_ib + 1) == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      if ((static_cast<int>((c_ib + 1) < 4)) != 0) {
        for (int c_k{0}; c_k <= c_ib; c_k++) {
          int c_idx_tmp;
          int d_idx_tmp;
          c_idx_tmp = (static_cast<int>(perm[c_k])) - 1;
          d_idx_tmp = (wOffset - c_ib) + c_k;
          b_idx[d_idx_tmp] = idx4[c_idx_tmp];
          g_x[d_idx_tmp] = x4[c_idx_tmp];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_idx_tmp, \
                                                                    f_idx_tmp)

        for (int c_k = 0; c_k <= c_ib; c_k++) {
          e_idx_tmp = (static_cast<int>(perm[c_k])) - 1;
          f_idx_tmp = (wOffset - c_ib) + c_k;
          b_idx[f_idx_tmp] = idx4[e_idx_tmp];
          g_x[f_idx_tmp] = x4[e_idx_tmp];
        }
      }
    }
    b_m = asr_s32(nNaNs, 1U) + 1;
    for (int b_k{0}; b_k <= (b_m - 2); b_k++) {
      int b_idx_tmp;
      int b_itmp;
      int itmp_tmp;
      itmp_tmp = (wOffset + b_k) + 1;
      b_itmp = b_idx[itmp_tmp];
      b_idx_tmp = (i_n - b_k) - 1;
      b_idx[itmp_tmp] = b_idx[b_idx_tmp];
      b_idx[b_idx_tmp] = b_itmp;
      g_x[itmp_tmp] = xwork[b_idx_tmp];
      g_x[b_idx_tmp] = xwork[itmp_tmp];
    }
    if ((nNaNs & 1) != 0) {
      int x_tmp;
      x_tmp = wOffset + b_m;
      g_x[x_tmp] = xwork[x_tmp];
    }
    nNonNaN = h_n - nNaNs;
    preSortLevel = 2;
    if (nNonNaN > 1) {
      if (h_n >= 256) {
        int b_nBlocks;
        b_nBlocks = asr_s32(nNonNaN, 8U);
        if (b_nBlocks > 0) {
          int nLastBlock;
          int tailOffset;
          for (int b{0}; b < b_nBlocks; b++) {
            int offset;
            offset = (b * 256) - 1;
            for (int b_b{0}; b_b < 6; b_b++) {
              int bLen;
              int bLen2;
              int nPairs;
              bLen =
                  ((static_cast<int>(1))
                   << (static_cast<unsigned long>(static_cast<int>(b_b + 2))));
              bLen2 = bLen * 2;
              nPairs = asr_s32(
                  256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
              for (int h_k{0}; h_k < nPairs; h_k++) {
                int b_q;
                int blockOffset;
                int iout;
                int p;
                blockOffset = (offset + (h_k * bLen2)) + 1;
                for (int j{0}; j < bLen2; j++) {
                  int iwork_tmp;
                  iwork_tmp = blockOffset + j;
                  b_iwork[j] = b_idx[iwork_tmp];
                  b_xwork[j] = g_x[iwork_tmp];
                }
                p = 0;
                b_q = bLen;
                iout = blockOffset - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  iout++;
                  if (b_xwork[p] >= b_xwork[b_q]) {
                    b_idx[iout] = b_iwork[p];
                    g_x[iout] = b_xwork[p];
                    if ((p + 1) < bLen) {
                      p++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[iout] = b_iwork[b_q];
                    g_x[iout] = b_xwork[b_q];
                    if ((b_q + 1) < bLen2) {
                      b_q++;
                    } else {
                      int offset1;
                      offset1 = iout - p;
                      for (int b_j{p + 1}; b_j <= bLen; b_j++) {
                        int g_idx_tmp;
                        g_idx_tmp = offset1 + b_j;
                        b_idx[g_idx_tmp] = b_iwork[b_j - 1];
                        g_x[g_idx_tmp] = b_xwork[b_j - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          tailOffset = b_nBlocks * 256;
          nLastBlock = nNonNaN - tailOffset;
          if (nLastBlock > 0) {
            merge_block(b_idx, g_x, tailOffset, nLastBlock, 2, iwork, xwork);
          }
          preSortLevel = 8;
        }
      }
      merge_block(b_idx, g_x, 0, nNonNaN, preSortLevel, iwork, xwork);
    }
    if ((nNaNs > 0) && (nNonNaN > 0)) {
      if ((static_cast<int>(nNaNs < 4)) != 0) {
        for (int d_k{0}; d_k < nNaNs; d_k++) {
          int xwork_tmp;
          xwork_tmp = nNonNaN + d_k;
          xwork[d_k] = g_x[xwork_tmp];
          iwork[d_k] = b_idx[xwork_tmp];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(b_xwork_tmp)

        for (int d_k = 0; d_k < nNaNs; d_k++) {
          b_xwork_tmp = nNonNaN + d_k;
          xwork[d_k] = g_x[b_xwork_tmp];
          iwork[d_k] = b_idx[b_xwork_tmp];
        }
      }
      for (int e_k{nNonNaN}; e_k >= 1; e_k--) {
        int b_x_tmp;
        b_x_tmp = (nNaNs + e_k) - 1;
        g_x[b_x_tmp] = g_x[e_k - 1];
        b_idx[b_x_tmp] = b_idx[e_k - 1];
      }
      if ((static_cast<int>(nNaNs < 4)) != 0) {
        for (int g_k{0}; g_k < nNaNs; g_k++) {
          g_x[g_k] = xwork[g_k];
          b_idx[g_k] = iwork[g_k];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (int g_k = 0; g_k < nNaNs; g_k++) {
          g_x[g_k] = xwork[g_k];
          b_idx[g_k] = iwork[g_k];
        }
      }
    }
    h_loop_ub = b_idx.size(0);
    if ((static_cast<int>(b_idx.size(0) < 4)) != 0) {
      for (int i5{0}; i5 < h_loop_ub; i5++) {
        idx[i5] = b_idx[i5];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < h_loop_ub; i5++) {
        idx[i5] = b_idx[i5];
      }
    }
    i_loop_ub = g_x.size(0);
    if ((static_cast<int>(g_x.size(0) < 4)) != 0) {
      for (int i6{0}; i6 < i_loop_ub; i6++) {
        b_x[i6] = g_x[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < i_loop_ub; i6++) {
        b_x[i6] = g_x[i6];
      }
    }
  }
}

//
// Arguments    : ::coder::array<double, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void c_sortIdx(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  array<double, 1U> g_x;
  array<double, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> iwork;
  double b_xwork[256];
  double x4[4];
  int b_iwork[256];
  int idx4[4];
  int e_idx_tmp;
  int f_idx_tmp;
  int loop_ub;
  unsigned int unnamed_idx_0;
  signed char perm[4];
  unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
  idx.set_size(static_cast<int>(unnamed_idx_0));
  loop_ub = static_cast<int>(unnamed_idx_0);
  if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  }
  if (b_x.size(0) != 0) {
    int b_loop_ub;
    int b_m;
    unsigned int b_unnamed_idx_0;
    int c_ib;
    int c_loop_ub;
    int d_loop_ub;
    int e_loop_ub;
    int f_loop_ub;
    int g_loop_ub;
    int h_loop_ub;
    int h_n;
    int i_loop_ub;
    int i_n;
    int nNaNs;
    int nNonNaN;
    int preSortLevel;
    int wOffset;
    b_loop_ub = static_cast<int>(unnamed_idx_0);
    b_idx.set_size(static_cast<int>(unnamed_idx_0));
    c_loop_ub = static_cast<int>(unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
      for (int i1{0}; i1 < b_loop_ub; i1++) {
        b_idx[i1] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i1 = 0; i1 < c_loop_ub; i1++) {
        b_idx[i1] = 0;
      }
    }
    h_n = b_x.size(0);
    d_loop_ub = b_x.size(0);
    g_x.set_size(d_loop_ub);
    e_loop_ub = d_loop_ub;
    if ((static_cast<int>(d_loop_ub < 4)) != 0) {
      for (int i2{0}; i2 < d_loop_ub; i2++) {
        g_x[i2] = b_x[i2];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i2 = 0; i2 < e_loop_ub; i2++) {
        g_x[i2] = b_x[i2];
      }
    }
    i_n = b_x.size(0);
    for (int c_i{0}; c_i < 4; c_i++) {
      x4[c_i] = 0.0;
      idx4[c_i] = 0;
    }
    iwork.set_size(static_cast<int>(unnamed_idx_0));
    f_loop_ub = static_cast<int>(unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(unnamed_idx_0)) < 4)) != 0) {
      for (int i3{0}; i3 < f_loop_ub; i3++) {
        iwork[i3] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < f_loop_ub; i3++) {
        iwork[i3] = 0;
      }
    }
    b_unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
    xwork.set_size(static_cast<int>(b_unnamed_idx_0));
    g_loop_ub = static_cast<int>(b_unnamed_idx_0);
    if ((static_cast<int>((static_cast<int>(b_unnamed_idx_0)) < 4)) != 0) {
      for (int i4{0}; i4 < g_loop_ub; i4++) {
        xwork[i4] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < g_loop_ub; i4++) {
        xwork[i4] = 0.0;
      }
    }
    nNaNs = 0;
    c_ib = -1;
    for (int k{0}; k < i_n; k++) {
      if (std::isnan(g_x[k])) {
        int idx_tmp;
        idx_tmp = (i_n - nNaNs) - 1;
        b_idx[idx_tmp] = k + 1;
        xwork[idx_tmp] = g_x[k];
        nNaNs++;
      } else {
        c_ib++;
        idx4[c_ib] = k + 1;
        x4[c_ib] = g_x[k];
        if ((c_ib + 1) == 4) {
          double b_d1;
          double d;
          int b_i1;
          int b_i2;
          int b_i3;
          int b_i4;
          int quartetOffset;
          quartetOffset = k - nNaNs;
          if (x4[0] <= x4[1]) {
            b_i1 = 1;
            b_i2 = 2;
          } else {
            b_i1 = 2;
            b_i2 = 1;
          }
          if (x4[2] <= x4[3]) {
            b_i3 = 3;
            b_i4 = 4;
          } else {
            b_i3 = 4;
            b_i4 = 3;
          }
          d = x4[b_i1 - 1];
          b_d1 = x4[b_i3 - 1];
          if (d <= b_d1) {
            double d3;
            d3 = x4[b_i2 - 1];
            if (d3 <= b_d1) {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i2);
              perm[2] = static_cast<signed char>(b_i3);
              perm[3] = static_cast<signed char>(b_i4);
            } else if (d3 <= x4[b_i4 - 1]) {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i3);
              perm[2] = static_cast<signed char>(b_i2);
              perm[3] = static_cast<signed char>(b_i4);
            } else {
              perm[0] = static_cast<signed char>(b_i1);
              perm[1] = static_cast<signed char>(b_i3);
              perm[2] = static_cast<signed char>(b_i4);
              perm[3] = static_cast<signed char>(b_i2);
            }
          } else {
            double d2;
            d2 = x4[b_i4 - 1];
            if (d <= d2) {
              if (x4[b_i2 - 1] <= d2) {
                perm[0] = static_cast<signed char>(b_i3);
                perm[1] = static_cast<signed char>(b_i1);
                perm[2] = static_cast<signed char>(b_i2);
                perm[3] = static_cast<signed char>(b_i4);
              } else {
                perm[0] = static_cast<signed char>(b_i3);
                perm[1] = static_cast<signed char>(b_i1);
                perm[2] = static_cast<signed char>(b_i4);
                perm[3] = static_cast<signed char>(b_i2);
              }
            } else {
              perm[0] = static_cast<signed char>(b_i3);
              perm[1] = static_cast<signed char>(b_i4);
              perm[2] = static_cast<signed char>(b_i1);
              perm[3] = static_cast<signed char>(b_i2);
            }
          }
          b_idx[quartetOffset - 3] = idx4[perm[0] - 1];
          b_idx[quartetOffset - 2] = idx4[perm[1] - 1];
          b_idx[quartetOffset - 1] = idx4[perm[2] - 1];
          b_idx[quartetOffset] = idx4[perm[3] - 1];
          g_x[quartetOffset - 3] = x4[perm[0] - 1];
          g_x[quartetOffset - 2] = x4[perm[1] - 1];
          g_x[quartetOffset - 1] = x4[perm[2] - 1];
          g_x[quartetOffset] = x4[perm[3] - 1];
          c_ib = -1;
        }
      }
    }
    wOffset = (b_x.size(0) - nNaNs) - 1;
    if ((c_ib + 1) > 0) {
      for (int d_i{0}; d_i < 4; d_i++) {
        perm[d_i] = 0;
      }
      if ((c_ib + 1) == 1) {
        perm[0] = 1;
      } else if ((c_ib + 1) == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      if ((static_cast<int>((c_ib + 1) < 4)) != 0) {
        for (int c_k{0}; c_k <= c_ib; c_k++) {
          int c_idx_tmp;
          int d_idx_tmp;
          c_idx_tmp = (static_cast<int>(perm[c_k])) - 1;
          d_idx_tmp = (wOffset - c_ib) + c_k;
          b_idx[d_idx_tmp] = idx4[c_idx_tmp];
          g_x[d_idx_tmp] = x4[c_idx_tmp];
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(e_idx_tmp, \
                                                                    f_idx_tmp)

        for (int c_k = 0; c_k <= c_ib; c_k++) {
          e_idx_tmp = (static_cast<int>(perm[c_k])) - 1;
          f_idx_tmp = (wOffset - c_ib) + c_k;
          b_idx[f_idx_tmp] = idx4[e_idx_tmp];
          g_x[f_idx_tmp] = x4[e_idx_tmp];
        }
      }
    }
    b_m = asr_s32(nNaNs, 1U) + 1;
    for (int b_k{0}; b_k <= (b_m - 2); b_k++) {
      int b_idx_tmp;
      int b_itmp;
      int itmp_tmp;
      itmp_tmp = (wOffset + b_k) + 1;
      b_itmp = b_idx[itmp_tmp];
      b_idx_tmp = (i_n - b_k) - 1;
      b_idx[itmp_tmp] = b_idx[b_idx_tmp];
      b_idx[b_idx_tmp] = b_itmp;
      g_x[itmp_tmp] = xwork[b_idx_tmp];
      g_x[b_idx_tmp] = xwork[itmp_tmp];
    }
    if ((nNaNs & 1) != 0) {
      int x_tmp;
      x_tmp = wOffset + b_m;
      g_x[x_tmp] = xwork[x_tmp];
    }
    nNonNaN = h_n - nNaNs;
    preSortLevel = 2;
    if (nNonNaN > 1) {
      if (h_n >= 256) {
        int b_nBlocks;
        b_nBlocks = asr_s32(nNonNaN, 8U);
        if (b_nBlocks > 0) {
          int nLastBlock;
          int tailOffset;
          for (int b{0}; b < b_nBlocks; b++) {
            int offset;
            offset = (b * 256) - 1;
            for (int b_b{0}; b_b < 6; b_b++) {
              int bLen;
              int bLen2;
              int nPairs;
              bLen =
                  ((static_cast<int>(1))
                   << (static_cast<unsigned long>(static_cast<int>(b_b + 2))));
              bLen2 = bLen * 2;
              nPairs = asr_s32(
                  256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
              for (int d_k{0}; d_k < nPairs; d_k++) {
                int b_q;
                int blockOffset;
                int iout;
                int p;
                blockOffset = (offset + (d_k * bLen2)) + 1;
                for (int j{0}; j < bLen2; j++) {
                  int iwork_tmp;
                  iwork_tmp = blockOffset + j;
                  b_iwork[j] = b_idx[iwork_tmp];
                  b_xwork[j] = g_x[iwork_tmp];
                }
                p = 0;
                b_q = bLen;
                iout = blockOffset - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  iout++;
                  if (b_xwork[p] <= b_xwork[b_q]) {
                    b_idx[iout] = b_iwork[p];
                    g_x[iout] = b_xwork[p];
                    if ((p + 1) < bLen) {
                      p++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[iout] = b_iwork[b_q];
                    g_x[iout] = b_xwork[b_q];
                    if ((b_q + 1) < bLen2) {
                      b_q++;
                    } else {
                      int offset1;
                      offset1 = iout - p;
                      for (int b_j{p + 1}; b_j <= bLen; b_j++) {
                        int g_idx_tmp;
                        g_idx_tmp = offset1 + b_j;
                        b_idx[g_idx_tmp] = b_iwork[b_j - 1];
                        g_x[g_idx_tmp] = b_xwork[b_j - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          tailOffset = b_nBlocks * 256;
          nLastBlock = nNonNaN - tailOffset;
          if (nLastBlock > 0) {
            c_merge_block(b_idx, g_x, tailOffset, nLastBlock, 2, iwork, xwork);
          }
          preSortLevel = 8;
        }
      }
      c_merge_block(b_idx, g_x, 0, nNonNaN, preSortLevel, iwork, xwork);
    }
    h_loop_ub = b_idx.size(0);
    if ((static_cast<int>(b_idx.size(0) < 4)) != 0) {
      for (int i5{0}; i5 < h_loop_ub; i5++) {
        idx[i5] = b_idx[i5];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < h_loop_ub; i5++) {
        idx[i5] = b_idx[i5];
      }
    }
    i_loop_ub = g_x.size(0);
    if ((static_cast<int>(g_x.size(0) < 4)) != 0) {
      for (int i6{0}; i6 < i_loop_ub; i6++) {
        b_x[i6] = g_x[i6];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i6 = 0; i6 < i_loop_ub; i6++) {
        b_x[i6] = g_x[i6];
      }
    }
  }
}

//
// Arguments    : int idx[4]
//                double b_x[4]
//                int offset
//                int np
//                int nq
//                int iwork[4]
//                double xwork[4]
// Return Type  : void
//
void d_merge(int idx[4], double b_x[4], int offset, int np, int nq,
             int iwork[4], double xwork[4])
{
  int i2;
  int i4;
  if ((np != 0) && (nq != 0)) {
    int b_q;
    int h_n;
    int i1;
    int iout;
    int n_tmp_tmp;
    int p;
    n_tmp_tmp = np + nq;
    h_n = n_tmp_tmp;
    if ((static_cast<int>(n_tmp_tmp < 4)) != 0) {
      for (int j{0}; j < n_tmp_tmp; j++) {
        int b_i;
        b_i = offset + j;
        iwork[j] = idx[b_i];
        xwork[j] = b_x[b_i];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i2)

      for (int j = 0; j < h_n; j++) {
        i2 = offset + j;
        iwork[j] = idx[i2];
        xwork[j] = b_x[i2];
      }
    }
    p = 0;
    b_q = np;
    i1 = np + nq;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[b_q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[b_q];
        b_x[iout] = xwork[b_q];
        if ((b_q + 1) < i1) {
          b_q++;
        } else {
          int offset1;
          offset1 = iout - p;
          if ((static_cast<int>((np - p) < 4)) != 0) {
            for (int b_j{p + 1}; b_j <= np; b_j++) {
              int i3;
              i3 = offset1 + b_j;
              idx[i3] = iwork[b_j - 1];
              b_x[i3] = xwork[b_j - 1];
            }
          } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i4)

            for (int b_j = p + 1; b_j <= np; b_j++) {
              i4 = offset1 + b_j;
              idx[i4] = iwork[b_j - 1];
              b_x[i4] = xwork[b_j - 1];
            }
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<int, 2U> &idx
// Return Type  : void
//
void sortIdx(const ::coder::array<double, 2U> &b_x,
             ::coder::array<int, 2U> &idx)
{
  array<int, 1U> iwork;
  int h_n;
  int loop_ub;
  h_n = b_x.size(1) + 1;
  idx.set_size(1, b_x.size(1));
  loop_ub = b_x.size(1);
  if ((static_cast<int>(b_x.size(1) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  }
  if (b_x.size(1) != 0) {
    int c_i;
    int i1;
    bool guard1{false};
    iwork.set_size(b_x.size(1));
    i1 = b_x.size(1) - 1;
    for (int k{1}; k <= i1; k += 2) {
      double d;
      d = b_x[k];
      guard1 = false;
      if (b_x[k - 1] <= d) {
        guard1 = true;
      } else if (std::isnan(d)) {
        guard1 = true;
      } else {
        idx[k - 1] = k + 1;
        idx[k] = k;
      }
      if (guard1) {
        idx[k - 1] = k;
        idx[k] = k + 1;
      }
    }
    if ((b_x.size(1) & 1) != 0) {
      idx[b_x.size(1) - 1] = b_x.size(1);
    }
    c_i = 2;
    while (c_i < (h_n - 1)) {
      int i2;
      int j;
      int pEnd;
      i2 = c_i * 2;
      j = 1;
      pEnd = c_i + 1;
      while (pEnd < h_n) {
        int b_k;
        int b_q;
        int kEnd;
        int p;
        int qEnd;
        p = j;
        b_q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > h_n) {
          qEnd = h_n;
        }
        b_k = 0;
        kEnd = qEnd - j;
        while ((b_k + 1) <= kEnd) {
          double b_d1;
          int b_i2;
          b_d1 = b_x[idx[b_q] - 1];
          b_i2 = idx[p - 1];
          guard1 = false;
          if (b_x[b_i2 - 1] <= b_d1) {
            guard1 = true;
          } else if (std::isnan(b_d1)) {
            guard1 = true;
          } else {
            iwork[b_k] = idx[b_q];
            b_q++;
            if ((b_q + 1) == qEnd) {
              while (p < pEnd) {
                b_k++;
                iwork[b_k] = idx[p - 1];
                p++;
              }
            }
          }
          if (guard1) {
            iwork[b_k] = b_i2;
            p++;
            if (p == pEnd) {
              while ((b_q + 1) < qEnd) {
                b_k++;
                iwork[b_k] = idx[b_q];
                b_q++;
              }
            }
          }
          b_k++;
        }
        for (int c_k{0}; c_k < kEnd; c_k++) {
          idx[(j + c_k) - 1] = iwork[c_k];
        }
        j = qEnd;
        pEnd = qEnd + c_i;
      }
      c_i = i2;
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
