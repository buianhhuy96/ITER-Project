//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "sortIdx.h"
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace Codegen {
namespace coder {
namespace internal {
static void b_merge(::coder::array<int32_T, 1U> &idx,
                    ::coder::array<int32_T, 1U> &b_x, int32_T offset,
                    int32_T np, int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                    ::coder::array<int32_T, 1U> &xwork);

static void c_merge(::coder::array<int32_T, 1U> &idx,
                    ::coder::array<real_T, 1U> &b_x, int32_T offset, int32_T np,
                    int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                    ::coder::array<real_T, 1U> &xwork);

static void merge(::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real32_T, 1U> &b_x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real32_T, 1U> &xwork);

} // namespace internal
} // namespace coder
} // namespace Codegen

// Function Definitions
//
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<int32_T, 1U> &b_x
//                int32_T offset
//                int32_T np
//                int32_T nq
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<int32_T, 1U> &xwork
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
static void b_merge(::coder::array<int32_T, 1U> &idx,
                    ::coder::array<int32_T, 1U> &b_x, int32_T offset,
                    int32_T np, int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                    ::coder::array<int32_T, 1U> &xwork)
{
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
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
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<real_T, 1U> &b_x
//                int32_T offset
//                int32_T np
//                int32_T nq
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<real_T, 1U> &xwork
// Return Type  : void
//
static void c_merge(::coder::array<int32_T, 1U> &idx,
                    ::coder::array<real_T, 1U> &b_x, int32_T offset, int32_T np,
                    int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                    ::coder::array<real_T, 1U> &xwork)
{
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
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
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<real32_T, 1U> &b_x
//                int32_T offset
//                int32_T np
//                int32_T nq
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<real32_T, 1U> &xwork
// Return Type  : void
//
static void merge(::coder::array<int32_T, 1U> &idx,
                  ::coder::array<real32_T, 1U> &b_x, int32_T offset, int32_T np,
                  int32_T nq, ::coder::array<int32_T, 1U> &iwork,
                  ::coder::array<real32_T, 1U> &xwork)
{
  if (nq != 0) {
    int32_T iout;
    int32_T j;
    int32_T n_tmp;
    int32_T p;
    int32_T q;
    n_tmp = np + nq;
    for (j = 0; j < n_tmp; j++) {
      iout = offset + j;
      iwork[j] = idx[iout];
      xwork[j] = b_x[iout];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
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
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<int32_T, 1U> &b_x
//                int32_T offset
//                int32_T g_n
//                int32_T preSortLevel
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<int32_T, 1U> &xwork
// Return Type  : void
//
void b_merge_block(::coder::array<int32_T, 1U> &idx,
                   ::coder::array<int32_T, 1U> &b_x, int32_T offset,
                   int32_T g_n, int32_T preSortLevel,
                   ::coder::array<int32_T, 1U> &iwork,
                   ::coder::array<int32_T, 1U> &xwork)
{
  int32_T bLen;
  int32_T nPairs;
  nPairs = asr_s32(g_n, static_cast<uint32_T>(preSortLevel));
  bLen = ((static_cast<int32_T>(1)) << (static_cast<uint64_T>(preSortLevel)));
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = g_n - tailOffset;
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
  if (g_n > bLen) {
    b_merge(idx, b_x, offset, bLen, g_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<real_T, 1U> &b_x
//                int32_T offset
//                int32_T g_n
//                int32_T preSortLevel
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<real_T, 1U> &xwork
// Return Type  : void
//
void c_merge_block(::coder::array<int32_T, 1U> &idx,
                   ::coder::array<real_T, 1U> &b_x, int32_T offset, int32_T g_n,
                   int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                   ::coder::array<real_T, 1U> &xwork)
{
  int32_T bLen;
  int32_T nPairs;
  nPairs = asr_s32(g_n, static_cast<uint32_T>(preSortLevel));
  bLen = ((static_cast<int32_T>(1)) << (static_cast<uint64_T>(preSortLevel)));
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = g_n - tailOffset;
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
  if (g_n > bLen) {
    c_merge(idx, b_x, offset, bLen, g_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : ::coder::array<int32_T, 1U> &idx
//                ::coder::array<real32_T, 1U> &b_x
//                int32_T offset
//                int32_T g_n
//                int32_T preSortLevel
//                ::coder::array<int32_T, 1U> &iwork
//                ::coder::array<real32_T, 1U> &xwork
// Return Type  : void
//
void merge_block(::coder::array<int32_T, 1U> &idx,
                 ::coder::array<real32_T, 1U> &b_x, int32_T offset, int32_T g_n,
                 int32_T preSortLevel, ::coder::array<int32_T, 1U> &iwork,
                 ::coder::array<real32_T, 1U> &xwork)
{
  int32_T bLen;
  int32_T nPairs;
  nPairs = asr_s32(g_n, static_cast<uint32_T>(preSortLevel));
  bLen = ((static_cast<int32_T>(1)) << (static_cast<uint64_T>(preSortLevel)));
  while (nPairs > 1) {
    int32_T nTail;
    int32_T tailOffset;
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = g_n - tailOffset;
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
  if (g_n > bLen) {
    merge(idx, b_x, offset, bLen, g_n - bLen, iwork, xwork);
  }
}

//
// Arguments    : const ::coder::array<real_T, 2U> &b_x
//                ::coder::array<int32_T, 2U> &idx
// Return Type  : void
//
void sortIdx(const ::coder::array<real_T, 2U> &b_x,
             ::coder::array<int32_T, 2U> &idx)
{
  ::coder::array<int32_T, 1U> iwork;
  int32_T b_i;
  int32_T d_i;
  int32_T g_n;
  g_n = b_x.size(1) + 1;
  idx.set_size(1, b_x.size(1));
  b_i = b_x.size(1);
  for (d_i = 0; d_i < b_i; d_i++) {
    idx[d_i] = 0;
  }
  if (b_x.size(1) != 0) {
    real_T d;
    int32_T k;
    boolean_T guard1{false};
    iwork.set_size(b_x.size(1));
    d_i = b_x.size(1) - 1;
    for (k = 1; k <= d_i; k += 2) {
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
    while (b_i < (g_n - 1)) {
      int32_T i2;
      int32_T j;
      int32_T pEnd;
      i2 = b_i * 2;
      j = 1;
      pEnd = b_i + 1;
      while (pEnd < g_n) {
        int32_T kEnd;
        int32_T p;
        int32_T q;
        int32_T qEnd;
        p = j;
        q = pEnd - 1;
        qEnd = j + i2;
        if (qEnd > g_n) {
          qEnd = g_n;
        }
        k = 0;
        kEnd = qEnd - j;
        while ((k + 1) <= kEnd) {
          d = b_x[idx[q] - 1];
          d_i = idx[p - 1];
          guard1 = false;
          if (b_x[d_i - 1] <= d) {
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
            iwork[k] = d_i;
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
} // namespace Codegen

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
