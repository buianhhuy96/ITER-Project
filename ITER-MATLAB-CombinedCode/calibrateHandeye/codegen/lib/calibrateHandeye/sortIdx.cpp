//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
//

// Include Files
#include "sortIdx.h"
#include "calibrateHandeye_rtwutil.h"
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
    int iout;
    int j;
    int n_tmp;
    int p;
    int q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
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
        if ((q + 1) < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            b_x[iout] = xwork[j - 1];
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
    int iout;
    int j;
    int n_tmp;
    int p;
    int q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
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
        if ((q + 1) < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            b_x[iout] = xwork[j - 1];
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
    int iout;
    int j;
    int n_tmp;
    int p;
    int q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
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
        if ((q + 1) < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            b_x[iout] = xwork[j - 1];
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
//                int c_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<int, 1U> &xwork
// Return Type  : void
//
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int c_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(c_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = c_n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    tailOffset = bLen * 2;
    nPairs = asr_s32(nPairs, 1U);
    for (nTail = 0; nTail < nPairs; nTail++) {
      b_merge(idx, b_x, offset + (nTail * tailOffset), bLen, bLen, iwork,
              xwork);
    }
    bLen = tailOffset;
  }
  if (c_n > bLen) {
    b_merge(idx, b_x, offset, bLen, c_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<double, 1U> &b_x
//                int offset
//                int c_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
void c_merge_block(::coder::array<int, 1U> &idx,
                   ::coder::array<double, 1U> &b_x, int offset, int c_n,
                   int preSortLevel, ::coder::array<int, 1U> &iwork,
                   ::coder::array<double, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(c_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = c_n - tailOffset;
      if (nTail > bLen) {
        c_merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork,
                xwork);
      }
    }
    tailOffset = bLen * 2;
    nPairs = asr_s32(nPairs, 1U);
    for (nTail = 0; nTail < nPairs; nTail++) {
      c_merge(idx, b_x, offset + (nTail * tailOffset), bLen, bLen, iwork,
              xwork);
    }
    bLen = tailOffset;
  }
  if (c_n > bLen) {
    c_merge(idx, b_x, offset, bLen, c_n - bLen, iwork, xwork);
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
    int iout;
    int j;
    int n_tmp;
    int p;
    int q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
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
        if ((q + 1) < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (j = p + 1; j <= np; j++) {
            iout = q + j;
            idx[iout] = iwork[j - 1];
            b_x[iout] = xwork[j - 1];
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
//                int c_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<float, 1U> &xwork
// Return Type  : void
//
void merge_block(::coder::array<int, 1U> &idx, ::coder::array<float, 1U> &b_x,
                 int offset, int c_n, int preSortLevel,
                 ::coder::array<int, 1U> &iwork,
                 ::coder::array<float, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(c_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = c_n - tailOffset;
      if (nTail > bLen) {
        merge(idx, b_x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }
    tailOffset = bLen * 2;
    nPairs = asr_s32(nPairs, 1U);
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, b_x, offset + (nTail * tailOffset), bLen, bLen, iwork, xwork);
    }
    bLen = tailOffset;
  }
  if (c_n > bLen) {
    merge(idx, b_x, offset, bLen, c_n - bLen, iwork, xwork);
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
  int b_i;
  int c_i;
  int c_n;
  c_n = b_x.size(1) + 1;
  idx.set_size(1, b_x.size(1));
  b_i = b_x.size(1);
  for (c_i = 0; c_i < b_i; c_i++) {
    idx[c_i] = 0;
  }
  if (b_x.size(1) != 0) {
    double d;
    int k;
    bool guard1{false};
    iwork.set_size(b_x.size(1));
    c_i = b_x.size(1) - 1;
    for (k = 1; k <= c_i; k += 2) {
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
    b_i = 2;
    while (b_i < (c_n - 1)) {
      int i2;
      int j;
      int pEnd;
      i2 = b_i * 2;
      j = 1;
      pEnd = b_i + 1;
      while (pEnd < c_n) {
        int kEnd;
        int p;
        int q;
        int qEnd;
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > c_n) {
          qEnd = c_n;
        }
        k = 0;
        kEnd = qEnd - j;
        while ((k + 1) <= kEnd) {
          d = b_x[idx[q] - 1];
          c_i = idx[p - 1];
          guard1 = false;
          if (b_x[c_i - 1] <= d) {
            guard1 = true;
          } else if (std::isnan(d)) {
            guard1 = true;
          } else {
            iwork[k] = idx[q];
            q++;
            if ((q + 1) == qEnd) {
              while (p < pEnd) {
                k++;
                iwork[k] = idx[p - 1];
                p++;
              }
            }
          }
          if (guard1) {
            iwork[k] = c_i;
            p++;
            if (p == pEnd) {
              while ((q + 1) < qEnd) {
                k++;
                iwork[k] = idx[q];
                q++;
              }
            }
          }
          k++;
        }
        for (k = 0; k < kEnd; k++) {
          idx[(j + k) - 1] = iwork[k];
        }
        j = qEnd;
        pEnd = qEnd + b_i;
      }
      b_i = i2;
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
