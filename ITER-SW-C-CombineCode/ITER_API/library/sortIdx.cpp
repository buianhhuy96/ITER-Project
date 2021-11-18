//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "sortIdx.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

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

static void merge(::coder::array<int, 1U> &idx, ::coder::array<float, 1U> &b_x,
                  int offset, int np, int nq, ::coder::array<int, 1U> &iwork,
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
  if ((np != 0) && (nq != 0)) {
    int g_n_tmp;
    int iout;
    int p;
    int q;
    g_n_tmp = np + nq;
    for (int j{0}; j < g_n_tmp; j++) {
      int b_i;
      b_i = offset + j;
      iwork[j] = idx[b_i];
      xwork[j] = b_x[b_i];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        b_x[iout] = xwork[q];
        if ((q + 1) < g_n_tmp) {
          q++;
        } else {
          int offset1;
          offset1 = iout - p;
          for (int b_j{p + 1}; b_j <= np; b_j++) {
            int i1;
            i1 = offset1 + b_j;
            idx[i1] = iwork[b_j - 1];
            b_x[i1] = xwork[b_j - 1];
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
  if ((np != 0) && (nq != 0)) {
    int g_n_tmp;
    int iout;
    int p;
    int q;
    g_n_tmp = np + nq;
    for (int j{0}; j < g_n_tmp; j++) {
      int b_i;
      b_i = offset + j;
      iwork[j] = idx[b_i];
      xwork[j] = b_x[b_i];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        b_x[iout] = xwork[q];
        if ((q + 1) < g_n_tmp) {
          q++;
        } else {
          int offset1;
          offset1 = iout - p;
          for (int b_j{p + 1}; b_j <= np; b_j++) {
            int i1;
            i1 = offset1 + b_j;
            idx[i1] = iwork[b_j - 1];
            b_x[i1] = xwork[b_j - 1];
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
  if ((np != 0) && (nq != 0)) {
    int g_n_tmp;
    int iout;
    int p;
    int q;
    g_n_tmp = np + nq;
    for (int j{0}; j < g_n_tmp; j++) {
      int b_i;
      b_i = offset + j;
      iwork[j] = idx[b_i];
      xwork[j] = b_x[b_i];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        b_x[iout] = xwork[q];
        if ((q + 1) < g_n_tmp) {
          q++;
        } else {
          int offset1;
          offset1 = iout - p;
          for (int b_j{p + 1}; b_j <= np; b_j++) {
            int i1;
            i1 = offset1 + b_j;
            idx[i1] = iwork[b_j - 1];
            b_x[i1] = xwork[b_j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
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
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<double, 1U> &b_x
//                int offset
//                int h_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
void c_merge_block(::coder::array<int, 1U> &idx,
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
  if ((np != 0) && (nq != 0)) {
    int g_n_tmp;
    int iout;
    int p;
    int q;
    g_n_tmp = np + nq;
    for (int j{0}; j < g_n_tmp; j++) {
      int b_i;
      b_i = offset + j;
      iwork[j] = idx[b_i];
      xwork[j] = b_x[b_i];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        b_x[iout] = xwork[p];
        if ((p + 1) < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        b_x[iout] = xwork[q];
        if ((q + 1) < g_n_tmp) {
          q++;
        } else {
          int offset1;
          offset1 = iout - p;
          for (int b_j{p + 1}; b_j <= np; b_j++) {
            int i1;
            i1 = offset1 + b_j;
            idx[i1] = iwork[b_j - 1];
            b_x[i1] = xwork[b_j - 1];
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
void merge_block(::coder::array<int, 1U> &idx, ::coder::array<float, 1U> &b_x,
                 int offset, int h_n, int preSortLevel,
                 ::coder::array<int, 1U> &iwork,
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
  for (int b_i{0}; b_i < loop_ub; b_i++) {
    idx[b_i] = 0;
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
        int kEnd;
        int p;
        int q;
        int qEnd;
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > h_n) {
          qEnd = h_n;
        }
        b_k = 0;
        kEnd = qEnd - j;
        while ((b_k + 1) <= kEnd) {
          double b_d1;
          int b_i2;
          b_d1 = b_x[idx[q] - 1];
          b_i2 = idx[p - 1];
          guard1 = false;
          if (b_x[b_i2 - 1] <= b_d1) {
            guard1 = true;
          } else if (std::isnan(b_d1)) {
            guard1 = true;
          } else {
            iwork[b_k] = idx[q];
            q++;
            if ((q + 1) == qEnd) {
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
              while ((q + 1) < qEnd) {
                b_k++;
                iwork[b_k] = idx[q];
                q++;
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
