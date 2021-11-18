//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortIdx.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "sortIdx.h"
#include "calibrateOneCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace Codegen {
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

static void merge_block(::coder::array<int, 1U> &idx,
                        ::coder::array<float, 1U> &b_x, int offset, int g_n,
                        int preSortLevel, ::coder::array<int, 1U> &iwork,
                        ::coder::array<float, 1U> &xwork);

} // namespace internal
} // namespace coder
} // namespace Codegen

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
namespace Codegen {
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
//                ::coder::array<float, 1U> &b_x
//                int offset
//                int g_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<float, 1U> &xwork
// Return Type  : void
//
static void merge_block(::coder::array<int, 1U> &idx,
                        ::coder::array<float, 1U> &b_x, int offset, int g_n,
                        int preSortLevel, ::coder::array<int, 1U> &iwork,
                        ::coder::array<float, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(g_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
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
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<int, 1U> &b_x
//                int offset
//                int g_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<int, 1U> &xwork
// Return Type  : void
//
void b_merge_block(::coder::array<int, 1U> &idx, ::coder::array<int, 1U> &b_x,
                   int offset, int g_n, int preSortLevel,
                   ::coder::array<int, 1U> &iwork,
                   ::coder::array<int, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(g_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
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
// Arguments    : ::coder::array<float, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void b_sortIdx(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  ::coder::array<float, 1U> c_x;
  ::coder::array<float, 1U> xwork;
  ::coder::array<int, 1U> b_idx;
  ::coder::array<int, 1U> iwork;
  float b_xwork[256];
  float x4[4];
  int b_iwork[256];
  int idx4[4];
  int bLen2;
  int quartetOffset;
  unsigned int unnamed_idx_0;
  signed char perm[4];
  unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
  idx.set_size(static_cast<int>(unnamed_idx_0));
  quartetOffset = static_cast<int>(unnamed_idx_0);
  for (bLen2 = 0; bLen2 < quartetOffset; bLen2++) {
    idx[bLen2] = 0;
  }
  if (b_x.size(0) != 0) {
    int bLen;
    int i2;
    int i3;
    int i4;
    int ib;
    int idx_tmp;
    int k;
    int nNaNs;
    int nNonNaN;
    quartetOffset = static_cast<int>(unnamed_idx_0);
    b_idx.set_size(static_cast<int>(unnamed_idx_0));
    for (bLen2 = 0; bLen2 < quartetOffset; bLen2++) {
      b_idx[bLen2] = 0;
    }
    quartetOffset = b_x.size(0);
    c_x.set_size(quartetOffset);
    for (bLen2 = 0; bLen2 < quartetOffset; bLen2++) {
      c_x[bLen2] = b_x[bLen2];
    }
    bLen2 = b_x.size(0);
    bLen = b_x.size(0);
    x4[0] = 0.0F;
    idx4[0] = 0;
    x4[1] = 0.0F;
    idx4[1] = 0;
    x4[2] = 0.0F;
    idx4[2] = 0;
    x4[3] = 0.0F;
    idx4[3] = 0;
    iwork.set_size(static_cast<int>(unnamed_idx_0));
    quartetOffset = static_cast<int>(unnamed_idx_0);
    for (ib = 0; ib < quartetOffset; ib++) {
      iwork[ib] = 0;
    }
    unnamed_idx_0 = static_cast<unsigned int>(b_x.size(0));
    xwork.set_size(static_cast<int>(unnamed_idx_0));
    quartetOffset = static_cast<int>(unnamed_idx_0);
    for (ib = 0; ib < quartetOffset; ib++) {
      xwork[ib] = 0.0F;
    }
    nNaNs = 0;
    ib = -1;
    for (k = 0; k < bLen; k++) {
      if (std::isnan(c_x[k])) {
        idx_tmp = (bLen - nNaNs) - 1;
        b_idx[idx_tmp] = k + 1;
        xwork[idx_tmp] = c_x[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib] = k + 1;
        x4[ib] = c_x[k];
        if ((ib + 1) == 4) {
          float f;
          float f1;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            ib = 1;
            i2 = 2;
          } else {
            ib = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            i3 = 3;
            i4 = 4;
          } else {
            i3 = 4;
            i4 = 3;
          }
          f = x4[ib - 1];
          f1 = x4[i3 - 1];
          if (f >= f1) {
            f = x4[i2 - 1];
            if (f >= f1) {
              perm[0] = static_cast<signed char>(ib);
              perm[1] = static_cast<signed char>(i2);
              perm[2] = static_cast<signed char>(i3);
              perm[3] = static_cast<signed char>(i4);
            } else if (f >= x4[i4 - 1]) {
              perm[0] = static_cast<signed char>(ib);
              perm[1] = static_cast<signed char>(i3);
              perm[2] = static_cast<signed char>(i2);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(ib);
              perm[1] = static_cast<signed char>(i3);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(i2);
            }
          } else {
            f1 = x4[i4 - 1];
            if (f >= f1) {
              if (x4[i2 - 1] >= f1) {
                perm[0] = static_cast<signed char>(i3);
                perm[1] = static_cast<signed char>(ib);
                perm[2] = static_cast<signed char>(i2);
                perm[3] = static_cast<signed char>(i4);
              } else {
                perm[0] = static_cast<signed char>(i3);
                perm[1] = static_cast<signed char>(ib);
                perm[2] = static_cast<signed char>(i4);
                perm[3] = static_cast<signed char>(i2);
              }
            } else {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i4);
              perm[2] = static_cast<signed char>(ib);
              perm[3] = static_cast<signed char>(i2);
            }
          }
          b_idx[quartetOffset - 3] = idx4[perm[0] - 1];
          b_idx[quartetOffset - 2] = idx4[perm[1] - 1];
          b_idx[quartetOffset - 1] = idx4[perm[2] - 1];
          b_idx[quartetOffset] = idx4[perm[3] - 1];
          c_x[quartetOffset - 3] = x4[perm[0] - 1];
          c_x[quartetOffset - 2] = x4[perm[1] - 1];
          c_x[quartetOffset - 1] = x4[perm[2] - 1];
          c_x[quartetOffset] = x4[perm[3] - 1];
          ib = -1;
        }
      }
    }
    i3 = (bLen - nNaNs) - 1;
    if ((ib + 1) > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if ((ib + 1) == 1) {
        perm[0] = 1;
      } else if ((ib + 1) == 2) {
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
      for (k = 0; k <= ib; k++) {
        idx_tmp = (static_cast<int>(perm[k])) - 1;
        quartetOffset = (i3 - ib) + k;
        b_idx[quartetOffset] = idx4[idx_tmp];
        c_x[quartetOffset] = x4[idx_tmp];
      }
    }
    ib = asr_s32(nNaNs, 1U) + 1;
    for (k = 0; k <= (ib - 2); k++) {
      quartetOffset = (i3 + k) + 1;
      i2 = b_idx[quartetOffset];
      idx_tmp = (bLen - k) - 1;
      b_idx[quartetOffset] = b_idx[idx_tmp];
      b_idx[idx_tmp] = i2;
      c_x[quartetOffset] = xwork[idx_tmp];
      c_x[idx_tmp] = xwork[quartetOffset];
    }
    if ((nNaNs & 1) != 0) {
      quartetOffset = i3 + ib;
      c_x[quartetOffset] = xwork[quartetOffset];
    }
    nNonNaN = bLen2 - nNaNs;
    quartetOffset = 2;
    if (nNonNaN > 1) {
      if (bLen2 >= 256) {
        int b_nBlocks;
        b_nBlocks = asr_s32(nNonNaN, 8U);
        if (b_nBlocks > 0) {
          for (int b{0}; b < b_nBlocks; b++) {
            i4 = (b * 256) - 1;
            for (int b_b{0}; b_b < 6; b_b++) {
              int nPairs;
              bLen =
                  ((static_cast<int>(1))
                   << (static_cast<unsigned long>(static_cast<int>(b_b + 2))));
              bLen2 = bLen * 2;
              nPairs = asr_s32(
                  256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
              for (k = 0; k < nPairs; k++) {
                i2 = (i4 + (k * bLen2)) + 1;
                for (quartetOffset = 0; quartetOffset < bLen2;
                     quartetOffset++) {
                  ib = i2 + quartetOffset;
                  b_iwork[quartetOffset] = b_idx[ib];
                  b_xwork[quartetOffset] = c_x[ib];
                }
                i3 = 0;
                quartetOffset = bLen;
                ib = i2 - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (b_xwork[i3] >= b_xwork[quartetOffset]) {
                    b_idx[ib] = b_iwork[i3];
                    c_x[ib] = b_xwork[i3];
                    if ((i3 + 1) < bLen) {
                      i3++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[ib] = b_iwork[quartetOffset];
                    c_x[ib] = b_xwork[quartetOffset];
                    if ((quartetOffset + 1) < bLen2) {
                      quartetOffset++;
                    } else {
                      ib -= i3;
                      for (quartetOffset = i3 + 1; quartetOffset <= bLen;
                           quartetOffset++) {
                        idx_tmp = ib + quartetOffset;
                        b_idx[idx_tmp] = b_iwork[quartetOffset - 1];
                        c_x[idx_tmp] = b_xwork[quartetOffset - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          quartetOffset = b_nBlocks * 256;
          ib = nNonNaN - quartetOffset;
          if (ib > 0) {
            merge_block(b_idx, c_x, quartetOffset, ib, 2, iwork, xwork);
          }
          quartetOffset = 8;
        }
      }
      merge_block(b_idx, c_x, 0, nNonNaN, quartetOffset, iwork, xwork);
    }
    if ((nNaNs > 0) && (nNonNaN > 0)) {
      for (k = 0; k < nNaNs; k++) {
        quartetOffset = nNonNaN + k;
        xwork[k] = c_x[quartetOffset];
        iwork[k] = b_idx[quartetOffset];
      }
      for (k = nNonNaN; k >= 1; k--) {
        quartetOffset = (nNaNs + k) - 1;
        c_x[quartetOffset] = c_x[k - 1];
        b_idx[quartetOffset] = b_idx[k - 1];
      }
      for (k = 0; k < nNaNs; k++) {
        c_x[k] = xwork[k];
        b_idx[k] = iwork[k];
      }
    }
    quartetOffset = b_idx.size(0);
    for (bLen2 = 0; bLen2 < quartetOffset; bLen2++) {
      idx[bLen2] = b_idx[bLen2];
    }
    quartetOffset = c_x.size(0);
    for (bLen2 = 0; bLen2 < quartetOffset; bLen2++) {
      b_x[bLen2] = c_x[bLen2];
    }
  }
}

//
// Arguments    : ::coder::array<int, 1U> &idx
//                ::coder::array<double, 1U> &b_x
//                int offset
//                int g_n
//                int preSortLevel
//                ::coder::array<int, 1U> &iwork
//                ::coder::array<double, 1U> &xwork
// Return Type  : void
//
void c_merge_block(::coder::array<int, 1U> &idx,
                   ::coder::array<double, 1U> &b_x, int offset, int g_n,
                   int preSortLevel, ::coder::array<int, 1U> &iwork,
                   ::coder::array<double, 1U> &xwork)
{
  int bLen;
  int nPairs;
  nPairs = asr_s32(g_n, static_cast<unsigned int>(preSortLevel));
  bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(preSortLevel)));
  while (nPairs > 1) {
    int nTail;
    int tailOffset;
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
// Arguments    : const ::coder::array<double, 2U> &b_x
//                ::coder::array<int, 2U> &idx
// Return Type  : void
//
void sortIdx(const ::coder::array<double, 2U> &b_x,
             ::coder::array<int, 2U> &idx)
{
  ::coder::array<int, 1U> iwork;
  int b_i;
  int c_i;
  int g_n;
  g_n = b_x.size(1) + 1;
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
    while (b_i < (g_n - 1)) {
      int i2;
      int j;
      int pEnd;
      i2 = b_i * 2;
      j = 1;
      pEnd = b_i + 1;
      while (pEnd < g_n) {
        int kEnd;
        int p;
        int q;
        int qEnd;
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
} // namespace Codegen

//
// File trailer for sortIdx.cpp
//
// [EOF]
//
