//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "sort.h"
#include "ITER_API_rtwutil.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<int, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
namespace coder {
namespace internal {
void b_sort(::coder::array<int, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  array<int, 1U> b_idx;
  array<int, 1U> b_iwork;
  array<int, 1U> b_xwork;
  array<int, 1U> d_x;
  array<int, 1U> iidx;
  array<int, 1U> vwork;
  array<signed char, 1U> iwork;
  array<signed char, 1U> xwork;
  int c_iwork[256];
  int c_xwork[256];
  int idx4[4];
  int x4[4];
  int b_i;
  int dim;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    b_i = b_x.size(0);
  } else {
    b_i = 1;
  }
  vlen = b_i - 1;
  vwork.set_size(b_i);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (int k{0}; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    int loop_ub;
    for (int b_k{0}; b_k <= vlen; b_k++) {
      vwork[b_k] = b_x[j + (b_k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    loop_ub = vwork.size(0);
    for (int i1{0}; i1 < loop_ub; i1++) {
      iidx[i1] = 0;
    }
    if (vwork.size(0) != 0) {
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int h_loop_ub;
      int i_loop_ub;
      int nDone;
      int nLeft;
      int nQuartets;
      int preSortLevel;
      b_loop_ub = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        b_idx[i2] = 0;
      }
      c_loop_ub = vwork.size(0);
      d_x.set_size(vwork.size(0));
      for (int i4{0}; i4 < c_loop_ub; i4++) {
        d_x[i4] = vwork[i4];
      }
      for (int c_i{0}; c_i < 4; c_i++) {
        x4[c_i] = 0;
        idx4[c_i] = 0;
      }
      iwork.set_size(vwork.size(0));
      d_loop_ub = vwork.size(0);
      for (int i5{0}; i5 < d_loop_ub; i5++) {
        iwork[i5] = 0;
      }
      xwork.set_size(vwork.size(0));
      e_loop_ub = vwork.size(0);
      for (int i6{0}; i6 < e_loop_ub; i6++) {
        xwork[i6] = 0;
      }
      nQuartets = asr_s32(vwork.size(0), 2U);
      for (int b_j{0}; b_j < nQuartets; b_j++) {
        int b_i1;
        int b_i2;
        int b_i3;
        int b_i4;
        int b_x4_tmp;
        int c_x4_tmp;
        int d_i;
        int i11;
        int i12;
        int x4_tmp;
        d_i = b_j * 4;
        idx4[0] = d_i + 1;
        idx4[1] = d_i + 2;
        idx4[2] = d_i + 3;
        idx4[3] = d_i + 4;
        x4[0] = d_x[d_i];
        x4_tmp = d_x[d_i + 1];
        x4[1] = x4_tmp;
        b_x4_tmp = d_x[d_i + 2];
        x4[2] = b_x4_tmp;
        c_x4_tmp = d_x[d_i + 3];
        x4[3] = c_x4_tmp;
        if (d_x[d_i] <= x4_tmp) {
          b_i1 = 1;
          b_i2 = 2;
        } else {
          b_i1 = 2;
          b_i2 = 1;
        }
        if (b_x4_tmp <= c_x4_tmp) {
          b_i3 = 3;
          b_i4 = 4;
        } else {
          b_i3 = 4;
          b_i4 = 3;
        }
        i11 = x4[b_i1 - 1];
        i12 = x4[b_i3 - 1];
        if (i11 <= i12) {
          int i14;
          i14 = x4[b_i2 - 1];
          if (i14 <= i12) {
            perm[0] = static_cast<signed char>(b_i1);
            perm[1] = static_cast<signed char>(b_i2);
            perm[2] = static_cast<signed char>(b_i3);
            perm[3] = static_cast<signed char>(b_i4);
          } else if (i14 <= x4[b_i4 - 1]) {
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
          int i13;
          i13 = x4[b_i4 - 1];
          if (i11 <= i13) {
            if (x4[b_i2 - 1] <= i13) {
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
        b_idx[d_i] = idx4[perm[0] - 1];
        b_idx[d_i + 1] = idx4[perm[1] - 1];
        b_idx[d_i + 2] = idx4[perm[2] - 1];
        b_idx[d_i + 3] = idx4[perm[3] - 1];
        d_x[d_i] = x4[perm[0] - 1];
        d_x[d_i + 1] = x4[perm[1] - 1];
        d_x[d_i + 2] = x4[perm[2] - 1];
        d_x[d_i + 3] = x4[perm[3] - 1];
      }
      nDone = nQuartets * 4;
      nLeft = vwork.size(0) - nDone;
      if (nLeft > 0) {
        for (int d_k{0}; d_k < nLeft; d_k++) {
          int idx4_tmp;
          idx4_tmp = nDone + d_k;
          idx4[d_k] = idx4_tmp + 1;
          x4[d_k] = d_x[idx4_tmp];
        }
        for (int e_i{0}; e_i < 4; e_i++) {
          perm[e_i] = 0;
        }
        if (nLeft == 1) {
          perm[0] = 1;
        } else if (nLeft == 2) {
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
        for (int e_k{0}; e_k < nLeft; e_k++) {
          int b_idx_tmp;
          int idx_tmp;
          idx_tmp = (static_cast<int>(perm[e_k])) - 1;
          b_idx_tmp = nDone + e_k;
          b_idx[b_idx_tmp] = idx4[idx_tmp];
          d_x[b_idx_tmp] = x4[idx_tmp];
        }
      }
      f_loop_ub = iwork.size(0);
      b_iwork.set_size(iwork.size(0));
      for (int i7{0}; i7 < f_loop_ub; i7++) {
        b_iwork[i7] = 0;
      }
      g_loop_ub = xwork.size(0);
      b_xwork.set_size(xwork.size(0));
      for (int i8{0}; i8 < g_loop_ub; i8++) {
        b_xwork[i8] = 0;
      }
      preSortLevel = 2;
      if (vwork.size(0) > 1) {
        if (vwork.size(0) >= 256) {
          int b_nBlocks;
          int nLastBlock;
          int tailOffset;
          b_nBlocks = asr_s32(vwork.size(0), 8U);
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
              for (int f_k{0}; f_k < nPairs; f_k++) {
                int blockOffset;
                int iout;
                int p;
                int q;
                blockOffset = (offset + (f_k * bLen2)) + 1;
                for (int c_j{0}; c_j < bLen2; c_j++) {
                  int iwork_tmp;
                  iwork_tmp = blockOffset + c_j;
                  c_iwork[c_j] = b_idx[iwork_tmp];
                  c_xwork[c_j] = d_x[iwork_tmp];
                }
                p = 0;
                q = bLen;
                iout = blockOffset - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  iout++;
                  if (c_xwork[p] <= c_xwork[q]) {
                    b_idx[iout] = c_iwork[p];
                    d_x[iout] = c_xwork[p];
                    if ((p + 1) < bLen) {
                      p++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[iout] = c_iwork[q];
                    d_x[iout] = c_xwork[q];
                    if ((q + 1) < bLen2) {
                      q++;
                    } else {
                      int offset1;
                      offset1 = iout - p;
                      for (int d_j{p + 1}; d_j <= bLen; d_j++) {
                        int c_idx_tmp;
                        c_idx_tmp = offset1 + d_j;
                        b_idx[c_idx_tmp] = c_iwork[d_j - 1];
                        d_x[c_idx_tmp] = c_xwork[d_j - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          tailOffset = b_nBlocks * 256;
          nLastBlock = vwork.size(0) - tailOffset;
          if (nLastBlock > 0) {
            b_merge_block(b_idx, d_x, tailOffset, nLastBlock, 2, b_iwork,
                          b_xwork);
          }
          preSortLevel = 8;
        }
        b_merge_block(b_idx, d_x, 0, vwork.size(0), preSortLevel, b_iwork,
                      b_xwork);
      }
      h_loop_ub = b_idx.size(0);
      for (int i9{0}; i9 < h_loop_ub; i9++) {
        iidx[i9] = b_idx[i9];
      }
      i_loop_ub = d_x.size(0);
      for (int i10{0}; i10 < i_loop_ub; i10++) {
        vwork[i10] = d_x[i10];
      }
    }
    for (int c_k{0}; c_k <= vlen; c_k++) {
      int i3;
      i3 = j + (c_k * vstride);
      b_x[i3] = vwork[c_k];
      idx[i3] = iidx[c_k];
    }
  }
}

//
// Arguments    : ::coder::array<double, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void c_sort(::coder::array<double, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  array<double, 1U> d_x;
  array<double, 1U> vwork;
  array<double, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  double b_xwork[256];
  double x4[4];
  int b_iwork[256];
  int idx4[4];
  int b_i;
  int dim;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    b_i = b_x.size(0);
  } else {
    b_i = 1;
  }
  vlen = b_i - 1;
  vwork.set_size(b_i);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (int k{0}; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    int loop_ub;
    unsigned int unnamed_idx_0;
    for (int b_k{0}; b_k <= vlen; b_k++) {
      vwork[b_k] = b_x[j + (b_k * vstride)];
    }
    unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
    iidx.set_size(static_cast<int>(unnamed_idx_0));
    loop_ub = static_cast<int>(unnamed_idx_0);
    for (int i1{0}; i1 < loop_ub; i1++) {
      iidx[i1] = 0;
    }
    if (vwork.size(0) != 0) {
      int b_ib;
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int i4;
      int i6;
      int m;
      int nNaNs;
      int nNonNaN;
      int preSortLevel;
      int wOffset;
      b_loop_ub = static_cast<int>(unnamed_idx_0);
      b_idx.set_size(static_cast<int>(unnamed_idx_0));
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        b_idx[i2] = 0;
      }
      i4 = vwork.size(0);
      c_loop_ub = vwork.size(0);
      d_x.set_size(c_loop_ub);
      for (int i5{0}; i5 < c_loop_ub; i5++) {
        d_x[i5] = vwork[i5];
      }
      i6 = vwork.size(0);
      for (int c_i{0}; c_i < 4; c_i++) {
        x4[c_i] = 0.0;
        idx4[c_i] = 0;
      }
      iwork.set_size(static_cast<int>(unnamed_idx_0));
      d_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i7{0}; i7 < d_loop_ub; i7++) {
        iwork[i7] = 0;
      }
      unsigned int b_unnamed_idx_0;
      b_unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
      xwork.set_size(static_cast<int>(b_unnamed_idx_0));
      e_loop_ub = static_cast<int>(b_unnamed_idx_0);
      for (int i8{0}; i8 < e_loop_ub; i8++) {
        xwork[i8] = 0.0;
      }
      nNaNs = 0;
      b_ib = -1;
      for (int d_k{0}; d_k < i6; d_k++) {
        if (std::isnan(d_x[d_k])) {
          int idx_tmp;
          idx_tmp = (i6 - nNaNs) - 1;
          b_idx[idx_tmp] = d_k + 1;
          xwork[idx_tmp] = d_x[d_k];
          nNaNs++;
        } else {
          b_ib++;
          idx4[b_ib] = d_k + 1;
          x4[b_ib] = d_x[d_k];
          if ((b_ib + 1) == 4) {
            double b_d1;
            double d;
            int b_i1;
            int b_i2;
            int b_i3;
            int b_i4;
            int quartetOffset;
            quartetOffset = d_k - nNaNs;
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
            d_x[quartetOffset - 3] = x4[perm[0] - 1];
            d_x[quartetOffset - 2] = x4[perm[1] - 1];
            d_x[quartetOffset - 1] = x4[perm[2] - 1];
            d_x[quartetOffset] = x4[perm[3] - 1];
            b_ib = -1;
          }
        }
      }
      wOffset = (vwork.size(0) - nNaNs) - 1;
      if ((b_ib + 1) > 0) {
        for (int d_i{0}; d_i < 4; d_i++) {
          perm[d_i] = 0;
        }
        if ((b_ib + 1) == 1) {
          perm[0] = 1;
        } else if ((b_ib + 1) == 2) {
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
        for (int f_k{0}; f_k <= b_ib; f_k++) {
          int c_idx_tmp;
          int d_idx_tmp;
          c_idx_tmp = (static_cast<int>(perm[f_k])) - 1;
          d_idx_tmp = (wOffset - b_ib) + f_k;
          b_idx[d_idx_tmp] = idx4[c_idx_tmp];
          d_x[d_idx_tmp] = x4[c_idx_tmp];
        }
      }
      m = asr_s32(nNaNs, 1U) + 1;
      for (int e_k{0}; e_k <= (m - 2); e_k++) {
        int b_idx_tmp;
        int b_itmp;
        int itmp_tmp;
        itmp_tmp = (wOffset + e_k) + 1;
        b_itmp = b_idx[itmp_tmp];
        b_idx_tmp = (i6 - e_k) - 1;
        b_idx[itmp_tmp] = b_idx[b_idx_tmp];
        b_idx[b_idx_tmp] = b_itmp;
        d_x[itmp_tmp] = xwork[b_idx_tmp];
        d_x[b_idx_tmp] = xwork[itmp_tmp];
      }
      if ((nNaNs & 1) != 0) {
        int x_tmp;
        x_tmp = wOffset + m;
        d_x[x_tmp] = xwork[x_tmp];
      }
      nNonNaN = i4 - nNaNs;
      preSortLevel = 2;
      if (nNonNaN > 1) {
        if (i4 >= 256) {
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
                bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(
                            static_cast<int>(b_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
                for (int g_k{0}; g_k < nPairs; g_k++) {
                  int blockOffset;
                  int iout;
                  int p;
                  int q;
                  blockOffset = (offset + (g_k * bLen2)) + 1;
                  for (int b_j{0}; b_j < bLen2; b_j++) {
                    int iwork_tmp;
                    iwork_tmp = blockOffset + b_j;
                    b_iwork[b_j] = b_idx[iwork_tmp];
                    b_xwork[b_j] = d_x[iwork_tmp];
                  }
                  p = 0;
                  q = bLen;
                  iout = blockOffset - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    iout++;
                    if (b_xwork[p] <= b_xwork[q]) {
                      b_idx[iout] = b_iwork[p];
                      d_x[iout] = b_xwork[p];
                      if ((p + 1) < bLen) {
                        p++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[iout] = b_iwork[q];
                      d_x[iout] = b_xwork[q];
                      if ((q + 1) < bLen2) {
                        q++;
                      } else {
                        int offset1;
                        offset1 = iout - p;
                        for (int c_j{p + 1}; c_j <= bLen; c_j++) {
                          int e_idx_tmp;
                          e_idx_tmp = offset1 + c_j;
                          b_idx[e_idx_tmp] = b_iwork[c_j - 1];
                          d_x[e_idx_tmp] = b_xwork[c_j - 1];
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
              c_merge_block(b_idx, d_x, tailOffset, nLastBlock, 2, iwork,
                            xwork);
            }
            preSortLevel = 8;
          }
        }
        c_merge_block(b_idx, d_x, 0, nNonNaN, preSortLevel, iwork, xwork);
      }
      f_loop_ub = b_idx.size(0);
      for (int i9{0}; i9 < f_loop_ub; i9++) {
        iidx[i9] = b_idx[i9];
      }
      g_loop_ub = d_x.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        vwork[i10] = d_x[i10];
      }
    }
    for (int c_k{0}; c_k <= vlen; c_k++) {
      int i3;
      i3 = j + (c_k * vstride);
      b_x[i3] = vwork[c_k];
      idx[i3] = iidx[c_k];
    }
  }
}

//
// Arguments    : double b_x[4]
// Return Type  : void
//
void d_sort(double b_x[4])
{
  double x4[4];
  double xwork[4];
  int idx[4];
  int iwork[4];
  int b_ib;
  int m;
  int nNaNs;
  signed char idx4[4];
  signed char perm[4];
  for (int b_i{0}; b_i < 4; b_i++) {
    idx[b_i] = 0;
    x4[b_i] = 0.0;
    idx4[b_i] = 0;
    xwork[b_i] = 0.0;
  }
  nNaNs = 0;
  b_ib = 0;
  for (int k{0}; k < 4; k++) {
    if (std::isnan(b_x[k])) {
      idx[3 - nNaNs] = k + 1;
      xwork[3 - nNaNs] = b_x[k];
      nNaNs++;
    } else {
      b_ib++;
      idx4[b_ib - 1] = static_cast<signed char>(k + 1);
      x4[b_ib - 1] = b_x[k];
      if (b_ib == 4) {
        double b_d1;
        double d;
        int i1;
        int i2;
        int i3;
        int i4;
        int quartetOffset;
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }
        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }
        d = x4[i1 - 1];
        b_d1 = x4[i3 - 1];
        if (d <= b_d1) {
          double d3;
          d3 = x4[i2 - 1];
          if (d3 <= b_d1) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i2);
            perm[2] = static_cast<signed char>(i3);
            perm[3] = static_cast<signed char>(i4);
          } else if (d3 <= x4[i4 - 1]) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i2);
            perm[3] = static_cast<signed char>(i4);
          } else {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i4);
            perm[3] = static_cast<signed char>(i2);
          }
        } else {
          double d2;
          d2 = x4[i4 - 1];
          if (d <= d2) {
            if (x4[i2 - 1] <= d2) {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i2);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(i2);
            }
          } else {
            perm[0] = static_cast<signed char>(i3);
            perm[1] = static_cast<signed char>(i4);
            perm[2] = static_cast<signed char>(i1);
            perm[3] = static_cast<signed char>(i2);
          }
        }
        idx[quartetOffset - 3] = static_cast<int>(idx4[perm[0] - 1]);
        idx[quartetOffset - 2] = static_cast<int>(idx4[perm[1] - 1]);
        idx[quartetOffset - 1] = static_cast<int>(idx4[perm[2] - 1]);
        idx[quartetOffset] = static_cast<int>(idx4[perm[3] - 1]);
        b_x[quartetOffset - 3] = x4[perm[0] - 1];
        b_x[quartetOffset - 2] = x4[perm[1] - 1];
        b_x[quartetOffset - 1] = x4[perm[2] - 1];
        b_x[quartetOffset] = x4[perm[3] - 1];
        b_ib = 0;
      }
    }
  }
  if (b_ib > 0) {
    for (int c_i{0}; c_i < 4; c_i++) {
      perm[c_i] = 0;
    }
    if (b_ib == 1) {
      perm[0] = 1;
    } else if (b_ib == 2) {
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
    for (int c_k{0}; c_k < b_ib; c_k++) {
      int b_idx_tmp;
      int idx_tmp;
      idx_tmp = (static_cast<int>(perm[c_k])) - 1;
      b_idx_tmp = ((c_k - nNaNs) - b_ib) + 4;
      idx[b_idx_tmp] = static_cast<int>(idx4[idx_tmp]);
      b_x[b_idx_tmp] = x4[idx_tmp];
    }
  }
  m = asr_s32(nNaNs, 1U) + 4;
  for (int b_k{0}; b_k <= (m - 5); b_k++) {
    int b_itmp;
    int itmp_tmp;
    itmp_tmp = (b_k - nNaNs) + 4;
    b_itmp = idx[itmp_tmp];
    idx[itmp_tmp] = idx[3 - b_k];
    idx[3 - b_k] = b_itmp;
    b_x[itmp_tmp] = xwork[3 - b_k];
    b_x[3 - b_k] = xwork[itmp_tmp];
  }
  if ((nNaNs & 1) != 0) {
    int d_i;
    d_i = m - nNaNs;
    b_x[d_i] = xwork[d_i];
  }
  if ((4 - nNaNs) > 1) {
    int bLen;
    int b_nBlocks;
    for (int e_i{0}; e_i < 4; e_i++) {
      iwork[e_i] = 0;
    }
    b_nBlocks = asr_s32(4 - nNaNs, 2U);
    bLen = 4;
    while (b_nBlocks > 1) {
      int bLen2;
      int nPairs;
      if ((b_nBlocks & 1) != 0) {
        int nTail;
        int tailOffset;
        b_nBlocks--;
        tailOffset = bLen * b_nBlocks;
        nTail = 4 - (nNaNs + tailOffset);
        if (nTail > bLen) {
          d_merge(idx, b_x, tailOffset, bLen, nTail - bLen, iwork, xwork);
        }
      }
      bLen2 = bLen * 2;
      nPairs = asr_s32(b_nBlocks, 1U);
      for (int d_k{0}; d_k < nPairs; d_k++) {
        d_merge(idx, b_x, d_k * bLen2, bLen, bLen, iwork, xwork);
      }
      bLen = bLen2;
      b_nBlocks = nPairs;
    }
    if ((4 - nNaNs) > bLen) {
      d_merge(idx, b_x, 0, bLen, 4 - (nNaNs + bLen), iwork, xwork);
    }
  }
}

//
// Arguments    : ::coder::array<float, 1U> &b_x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void sort(::coder::array<float, 1U> &b_x, ::coder::array<int, 1U> &idx)
{
  array<float, 1U> d_x;
  array<float, 1U> vwork;
  array<float, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  float b_xwork[256];
  float x4[4];
  int b_iwork[256];
  int idx4[4];
  int b_i;
  int dim;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    b_i = b_x.size(0);
  } else {
    b_i = 1;
  }
  vlen = b_i - 1;
  vwork.set_size(b_i);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (int k{0}; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    int loop_ub;
    unsigned int unnamed_idx_0;
    for (int b_k{0}; b_k <= vlen; b_k++) {
      vwork[b_k] = b_x[j + (b_k * vstride)];
    }
    unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
    iidx.set_size(static_cast<int>(unnamed_idx_0));
    loop_ub = static_cast<int>(unnamed_idx_0);
    for (int i1{0}; i1 < loop_ub; i1++) {
      iidx[i1] = 0;
    }
    if (vwork.size(0) != 0) {
      int b_ib;
      int b_loop_ub;
      int c_loop_ub;
      int d_loop_ub;
      int e_loop_ub;
      int f_loop_ub;
      int g_loop_ub;
      int i4;
      int i6;
      int m;
      int nNaNs;
      int nNonNaN;
      int preSortLevel;
      int wOffset;
      b_loop_ub = static_cast<int>(unnamed_idx_0);
      b_idx.set_size(static_cast<int>(unnamed_idx_0));
      for (int i2{0}; i2 < b_loop_ub; i2++) {
        b_idx[i2] = 0;
      }
      i4 = vwork.size(0);
      c_loop_ub = vwork.size(0);
      d_x.set_size(c_loop_ub);
      for (int i5{0}; i5 < c_loop_ub; i5++) {
        d_x[i5] = vwork[i5];
      }
      i6 = vwork.size(0);
      for (int c_i{0}; c_i < 4; c_i++) {
        x4[c_i] = 0.0F;
        idx4[c_i] = 0;
      }
      iwork.set_size(static_cast<int>(unnamed_idx_0));
      d_loop_ub = static_cast<int>(unnamed_idx_0);
      for (int i7{0}; i7 < d_loop_ub; i7++) {
        iwork[i7] = 0;
      }
      unsigned int b_unnamed_idx_0;
      b_unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
      xwork.set_size(static_cast<int>(b_unnamed_idx_0));
      e_loop_ub = static_cast<int>(b_unnamed_idx_0);
      for (int i8{0}; i8 < e_loop_ub; i8++) {
        xwork[i8] = 0.0F;
      }
      nNaNs = 0;
      b_ib = -1;
      for (int d_k{0}; d_k < i6; d_k++) {
        if (std::isnan(d_x[d_k])) {
          int idx_tmp;
          idx_tmp = (i6 - nNaNs) - 1;
          b_idx[idx_tmp] = d_k + 1;
          xwork[idx_tmp] = d_x[d_k];
          nNaNs++;
        } else {
          b_ib++;
          idx4[b_ib] = d_k + 1;
          x4[b_ib] = d_x[d_k];
          if ((b_ib + 1) == 4) {
            float f;
            float f1;
            int b_i1;
            int b_i2;
            int b_i3;
            int b_i4;
            int quartetOffset;
            quartetOffset = d_k - nNaNs;
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
            d_x[quartetOffset - 3] = x4[perm[0] - 1];
            d_x[quartetOffset - 2] = x4[perm[1] - 1];
            d_x[quartetOffset - 1] = x4[perm[2] - 1];
            d_x[quartetOffset] = x4[perm[3] - 1];
            b_ib = -1;
          }
        }
      }
      wOffset = (vwork.size(0) - nNaNs) - 1;
      if ((b_ib + 1) > 0) {
        for (int d_i{0}; d_i < 4; d_i++) {
          perm[d_i] = 0;
        }
        if ((b_ib + 1) == 1) {
          perm[0] = 1;
        } else if ((b_ib + 1) == 2) {
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
        for (int f_k{0}; f_k <= b_ib; f_k++) {
          int c_idx_tmp;
          int d_idx_tmp;
          c_idx_tmp = (static_cast<int>(perm[f_k])) - 1;
          d_idx_tmp = (wOffset - b_ib) + f_k;
          b_idx[d_idx_tmp] = idx4[c_idx_tmp];
          d_x[d_idx_tmp] = x4[c_idx_tmp];
        }
      }
      m = asr_s32(nNaNs, 1U) + 1;
      for (int e_k{0}; e_k <= (m - 2); e_k++) {
        int b_idx_tmp;
        int b_itmp;
        int itmp_tmp;
        itmp_tmp = (wOffset + e_k) + 1;
        b_itmp = b_idx[itmp_tmp];
        b_idx_tmp = (i6 - e_k) - 1;
        b_idx[itmp_tmp] = b_idx[b_idx_tmp];
        b_idx[b_idx_tmp] = b_itmp;
        d_x[itmp_tmp] = xwork[b_idx_tmp];
        d_x[b_idx_tmp] = xwork[itmp_tmp];
      }
      if ((nNaNs & 1) != 0) {
        int x_tmp;
        x_tmp = wOffset + m;
        d_x[x_tmp] = xwork[x_tmp];
      }
      nNonNaN = i4 - nNaNs;
      preSortLevel = 2;
      if (nNonNaN > 1) {
        if (i4 >= 256) {
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
                bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(
                            static_cast<int>(b_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
                for (int k_k{0}; k_k < nPairs; k_k++) {
                  int blockOffset;
                  int iout;
                  int p;
                  int q;
                  blockOffset = (offset + (k_k * bLen2)) + 1;
                  for (int b_j{0}; b_j < bLen2; b_j++) {
                    int iwork_tmp;
                    iwork_tmp = blockOffset + b_j;
                    b_iwork[b_j] = b_idx[iwork_tmp];
                    b_xwork[b_j] = d_x[iwork_tmp];
                  }
                  p = 0;
                  q = bLen;
                  iout = blockOffset - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    iout++;
                    if (b_xwork[p] >= b_xwork[q]) {
                      b_idx[iout] = b_iwork[p];
                      d_x[iout] = b_xwork[p];
                      if ((p + 1) < bLen) {
                        p++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[iout] = b_iwork[q];
                      d_x[iout] = b_xwork[q];
                      if ((q + 1) < bLen2) {
                        q++;
                      } else {
                        int offset1;
                        offset1 = iout - p;
                        for (int c_j{p + 1}; c_j <= bLen; c_j++) {
                          int e_idx_tmp;
                          e_idx_tmp = offset1 + c_j;
                          b_idx[e_idx_tmp] = b_iwork[c_j - 1];
                          d_x[e_idx_tmp] = b_xwork[c_j - 1];
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
              merge_block(b_idx, d_x, tailOffset, nLastBlock, 2, iwork, xwork);
            }
            preSortLevel = 8;
          }
        }
        merge_block(b_idx, d_x, 0, nNonNaN, preSortLevel, iwork, xwork);
      }
      if ((nNaNs > 0) && (nNonNaN > 0)) {
        for (int g_k{0}; g_k < nNaNs; g_k++) {
          int xwork_tmp;
          xwork_tmp = nNonNaN + g_k;
          xwork[g_k] = d_x[xwork_tmp];
          iwork[g_k] = b_idx[xwork_tmp];
        }
        for (int i_k{nNonNaN}; i_k >= 1; i_k--) {
          int b_x_tmp;
          b_x_tmp = (nNaNs + i_k) - 1;
          d_x[b_x_tmp] = d_x[i_k - 1];
          b_idx[b_x_tmp] = b_idx[i_k - 1];
        }
        for (int j_k{0}; j_k < nNaNs; j_k++) {
          d_x[j_k] = xwork[j_k];
          b_idx[j_k] = iwork[j_k];
        }
      }
      f_loop_ub = b_idx.size(0);
      for (int i9{0}; i9 < f_loop_ub; i9++) {
        iidx[i9] = b_idx[i9];
      }
      g_loop_ub = d_x.size(0);
      for (int i10{0}; i10 < g_loop_ub; i10++) {
        vwork[i10] = d_x[i10];
      }
    }
    for (int c_k{0}; c_k <= vlen; c_k++) {
      int i3;
      i3 = j + (c_k * vstride);
      b_x[i3] = vwork[c_k];
      idx[i3] = iidx[c_k];
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//
