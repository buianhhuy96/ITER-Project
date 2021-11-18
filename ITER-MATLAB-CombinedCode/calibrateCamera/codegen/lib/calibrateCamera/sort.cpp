//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "sort.h"
#include "calibrateCamera_rtwutil.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<int32_T, 1U> &b_x
//                ::coder::array<int32_T, 1U> &idx
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
void b_sort(::coder::array<int32_T, 1U> &b_x, ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<int32_T, 1U> b_idx;
  ::coder::array<int32_T, 1U> b_iwork;
  ::coder::array<int32_T, 1U> c_x;
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<int32_T, 1U> iwork;
  ::coder::array<int32_T, 1U> vwork;
  ::coder::array<int32_T, 1U> xwork;
  int32_T b_xwork[256];
  int32_T c_iwork[256];
  int32_T idx4[4];
  int32_T x4[4];
  int32_T bLen;
  int32_T dim;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  int8_T perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    bLen = b_x.size(0);
  } else {
    bLen = 1;
  }
  vlen = bLen - 1;
  vwork.set_size(bLen);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int32_T j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen = 0; bLen < dim; bLen++) {
      iidx[bLen] = 0;
    }
    if (vwork.size(0) != 0) {
      int32_T b_i;
      int32_T c_j;
      int32_T i1;
      int32_T i2;
      int32_T i4;
      int32_T nLeft;
      int32_T nQuartets;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        b_idx[bLen] = 0;
      }
      dim = vwork.size(0);
      c_x.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        c_x[bLen] = vwork[bLen];
      }
      x4[0] = 0;
      idx4[0] = 0;
      x4[1] = 0;
      idx4[1] = 0;
      x4[2] = 0;
      idx4[2] = 0;
      x4[3] = 0;
      idx4[3] = 0;
      iwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        iwork[bLen] = 0;
      }
      xwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        xwork[bLen] = 0;
      }
      nQuartets = asr_s32(vwork.size(0), 2U);
      for (c_j = 0; c_j < nQuartets; c_j++) {
        b_i = c_j * 4;
        idx4[0] = b_i + 1;
        idx4[1] = b_i + 2;
        idx4[2] = b_i + 3;
        idx4[3] = b_i + 4;
        x4[0] = c_x[b_i];
        dim = c_x[b_i + 1];
        x4[1] = dim;
        i4 = c_x[b_i + 2];
        x4[2] = i4;
        nLeft = c_x[b_i + 3];
        x4[3] = nLeft;
        if (c_x[b_i] <= dim) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }
        if (i4 <= nLeft) {
          dim = 3;
          i4 = 4;
        } else {
          dim = 4;
          i4 = 3;
        }
        bLen = x4[i1 - 1];
        nLeft = x4[dim - 1];
        if (bLen <= nLeft) {
          bLen = x4[i2 - 1];
          if (bLen <= nLeft) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(i2);
            perm[2] = static_cast<int8_T>(dim);
            perm[3] = static_cast<int8_T>(i4);
          } else if (bLen <= x4[i4 - 1]) {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(dim);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i1);
            perm[1] = static_cast<int8_T>(dim);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          nLeft = x4[i4 - 1];
          if (bLen <= nLeft) {
            if (x4[i2 - 1] <= nLeft) {
              perm[0] = static_cast<int8_T>(dim);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i2);
              perm[3] = static_cast<int8_T>(i4);
            } else {
              perm[0] = static_cast<int8_T>(dim);
              perm[1] = static_cast<int8_T>(i1);
              perm[2] = static_cast<int8_T>(i4);
              perm[3] = static_cast<int8_T>(i2);
            }
          } else {
            perm[0] = static_cast<int8_T>(dim);
            perm[1] = static_cast<int8_T>(i4);
            perm[2] = static_cast<int8_T>(i1);
            perm[3] = static_cast<int8_T>(i2);
          }
        }
        b_idx[b_i] = idx4[perm[0] - 1];
        b_idx[b_i + 1] = idx4[perm[1] - 1];
        b_idx[b_i + 2] = idx4[perm[2] - 1];
        b_idx[b_i + 3] = idx4[perm[3] - 1];
        c_x[b_i] = x4[perm[0] - 1];
        c_x[b_i + 1] = x4[perm[1] - 1];
        c_x[b_i + 2] = x4[perm[2] - 1];
        c_x[b_i + 3] = x4[perm[3] - 1];
      }
      i4 = nQuartets * 4;
      nLeft = vwork.size(0) - i4;
      if (nLeft > 0) {
        for (k = 0; k < nLeft; k++) {
          dim = i4 + k;
          idx4[k] = dim + 1;
          x4[k] = c_x[dim];
        }
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
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
        for (k = 0; k < nLeft; k++) {
          i1 = (static_cast<int32_T>(perm[k])) - 1;
          dim = i4 + k;
          b_idx[dim] = idx4[i1];
          c_x[dim] = x4[i1];
        }
      }
      i4 = 2;
      if (vwork.size(0) > 1) {
        if (vwork.size(0) >= 256) {
          nQuartets = asr_s32(vwork.size(0), 8U);
          for (int32_T b{0}; b < nQuartets; b++) {
            b_i = (b * 256) - 1;
            for (int32_T b_b{0}; b_b < 6; b_b++) {
              int32_T bLen2;
              int32_T nPairs;
              bLen =
                  ((static_cast<int32_T>(1))
                   << (static_cast<uint64_T>(static_cast<int32_T>(b_b + 2))));
              bLen2 = bLen * 2;
              nPairs = asr_s32(
                  256, static_cast<uint32_T>(static_cast<int32_T>(b_b + 3)));
              for (k = 0; k < nPairs; k++) {
                i4 = (b_i + (k * bLen2)) + 1;
                for (c_j = 0; c_j < bLen2; c_j++) {
                  dim = i4 + c_j;
                  c_iwork[c_j] = b_idx[dim];
                  b_xwork[c_j] = c_x[dim];
                }
                i2 = 0;
                nLeft = bLen;
                dim = i4 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  dim++;
                  if (b_xwork[i2] <= b_xwork[nLeft]) {
                    b_idx[dim] = c_iwork[i2];
                    c_x[dim] = b_xwork[i2];
                    if ((i2 + 1) < bLen) {
                      i2++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[dim] = c_iwork[nLeft];
                    c_x[dim] = b_xwork[nLeft];
                    if ((nLeft + 1) < bLen2) {
                      nLeft++;
                    } else {
                      dim -= i2;
                      for (c_j = i2 + 1; c_j <= bLen; c_j++) {
                        i1 = dim + c_j;
                        b_idx[i1] = c_iwork[c_j - 1];
                        c_x[i1] = b_xwork[c_j - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          dim = nQuartets * 256;
          i4 = vwork.size(0) - dim;
          if (i4 > 0) {
            b_merge_block(b_idx, c_x, dim, i4, 2, iwork, xwork);
          }
          i4 = 8;
        }
        dim = iwork.size(0);
        b_iwork.set_size(iwork.size(0));
        for (bLen = 0; bLen < dim; bLen++) {
          b_iwork[bLen] = iwork[bLen];
        }
        dim = xwork.size(0);
        iwork.set_size(xwork.size(0));
        for (bLen = 0; bLen < dim; bLen++) {
          iwork[bLen] = xwork[bLen];
        }
        b_merge_block(b_idx, c_x, 0, vwork.size(0), i4, b_iwork, iwork);
      }
      dim = b_idx.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        iidx[bLen] = b_idx[bLen];
      }
      dim = c_x.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        vwork[bLen] = c_x[bLen];
      }
    }
    for (k = 0; k <= vlen; k++) {
      bLen = j + (k * vstride);
      b_x[bLen] = vwork[k];
      idx[bLen] = iidx[k];
    }
  }
}

//
// Arguments    : ::coder::array<real_T, 1U> &b_x
//                ::coder::array<int32_T, 1U> &idx
// Return Type  : void
//
void c_sort(::coder::array<real_T, 1U> &b_x, ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<real_T, 1U> b_xwork;
  ::coder::array<real_T, 1U> c_x;
  ::coder::array<real_T, 1U> vwork;
  ::coder::array<real_T, 1U> xwork;
  ::coder::array<int32_T, 1U> b_idx;
  ::coder::array<int32_T, 1U> b_iwork;
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<int32_T, 1U> iwork;
  real_T c_xwork[256];
  real_T x4[4];
  int32_T c_iwork[256];
  int32_T idx4[4];
  int32_T bLen2;
  int32_T dim;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  int8_T perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    bLen2 = b_x.size(0);
  } else {
    bLen2 = 1;
  }
  vlen = bLen2 - 1;
  vwork.set_size(bLen2);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int32_T j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen2 = 0; bLen2 < dim; bLen2++) {
      iidx[bLen2] = 0;
    }
    if (vwork.size(0) != 0) {
      int32_T bLen;
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T idx_tmp;
      int32_T nNonNaN;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        b_idx[bLen2] = 0;
      }
      dim = vwork.size(0);
      c_x.set_size(vwork.size(0));
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        c_x[bLen2] = vwork[bLen2];
      }
      bLen2 = vwork.size(0);
      x4[0] = 0.0;
      idx4[0] = 0;
      x4[1] = 0.0;
      idx4[1] = 0;
      x4[2] = 0.0;
      idx4[2] = 0;
      x4[3] = 0.0;
      idx4[3] = 0;
      iwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (i1 = 0; i1 < dim; i1++) {
        iwork[i1] = 0;
      }
      xwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (i1 = 0; i1 < dim; i1++) {
        xwork[i1] = 0.0;
      }
      bLen = 0;
      dim = -1;
      for (k = 0; k < bLen2; k++) {
        if (std::isnan(c_x[k])) {
          idx_tmp = (bLen2 - bLen) - 1;
          b_idx[idx_tmp] = k + 1;
          xwork[idx_tmp] = c_x[k];
          bLen++;
        } else {
          dim++;
          idx4[dim] = k + 1;
          x4[dim] = c_x[k];
          if ((dim + 1) == 4) {
            real_T b_d1;
            real_T d;
            dim = k - bLen;
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
              d = x4[i2 - 1];
              if (d <= b_d1) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i2);
                perm[2] = static_cast<int8_T>(i3);
                perm[3] = static_cast<int8_T>(i4);
              } else if (d <= x4[i4 - 1]) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              b_d1 = x4[i4 - 1];
              if (d <= b_d1) {
                if (x4[i2 - 1] <= b_d1) {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i2);
                  perm[3] = static_cast<int8_T>(i4);
                } else {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i4);
                  perm[3] = static_cast<int8_T>(i2);
                }
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(i4);
                perm[2] = static_cast<int8_T>(i1);
                perm[3] = static_cast<int8_T>(i2);
              }
            }
            b_idx[dim - 3] = idx4[perm[0] - 1];
            b_idx[dim - 2] = idx4[perm[1] - 1];
            b_idx[dim - 1] = idx4[perm[2] - 1];
            b_idx[dim] = idx4[perm[3] - 1];
            c_x[dim - 3] = x4[perm[0] - 1];
            c_x[dim - 2] = x4[perm[1] - 1];
            c_x[dim - 1] = x4[perm[2] - 1];
            c_x[dim] = x4[perm[3] - 1];
            dim = -1;
          }
        }
      }
      i3 = (vwork.size(0) - bLen) - 1;
      if ((dim + 1) > 0) {
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if ((dim + 1) == 1) {
          perm[0] = 1;
        } else if ((dim + 1) == 2) {
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
        for (k = 0; k <= dim; k++) {
          idx_tmp = (static_cast<int32_T>(perm[k])) - 1;
          i1 = (i3 - dim) + k;
          b_idx[i1] = idx4[idx_tmp];
          c_x[i1] = x4[idx_tmp];
        }
      }
      dim = asr_s32(bLen, 1U) + 1;
      for (k = 0; k <= (dim - 2); k++) {
        i1 = (i3 + k) + 1;
        i2 = b_idx[i1];
        idx_tmp = (bLen2 - k) - 1;
        b_idx[i1] = b_idx[idx_tmp];
        b_idx[idx_tmp] = i2;
        c_x[i1] = xwork[idx_tmp];
        c_x[idx_tmp] = xwork[i1];
      }
      if ((bLen & 1) != 0) {
        dim += i3;
        c_x[dim] = xwork[dim];
      }
      nNonNaN = vwork.size(0) - bLen;
      i1 = 2;
      if (nNonNaN > 1) {
        if (vwork.size(0) >= 256) {
          int32_T b_nBlocks;
          b_nBlocks = asr_s32(nNonNaN, 8U);
          if (b_nBlocks > 0) {
            for (int32_T b{0}; b < b_nBlocks; b++) {
              i4 = (b * 256) - 1;
              for (int32_T b_b{0}; b_b < 6; b_b++) {
                int32_T nPairs;
                bLen =
                    ((static_cast<int32_T>(1))
                     << (static_cast<uint64_T>(static_cast<int32_T>(b_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<uint32_T>(static_cast<int32_T>(b_b + 3)));
                for (k = 0; k < nPairs; k++) {
                  i2 = (i4 + (k * bLen2)) + 1;
                  for (i1 = 0; i1 < bLen2; i1++) {
                    dim = i2 + i1;
                    c_iwork[i1] = b_idx[dim];
                    c_xwork[i1] = c_x[dim];
                  }
                  i3 = 0;
                  i1 = bLen;
                  dim = i2 - 1;
                  int32_T exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (c_xwork[i3] <= c_xwork[i1]) {
                      b_idx[dim] = c_iwork[i3];
                      c_x[dim] = c_xwork[i3];
                      if ((i3 + 1) < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[dim] = c_iwork[i1];
                      c_x[dim] = c_xwork[i1];
                      if ((i1 + 1) < bLen2) {
                        i1++;
                      } else {
                        dim -= i3;
                        for (i1 = i3 + 1; i1 <= bLen; i1++) {
                          idx_tmp = dim + i1;
                          b_idx[idx_tmp] = c_iwork[i1 - 1];
                          c_x[idx_tmp] = c_xwork[i1 - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = b_nBlocks * 256;
            i1 = nNonNaN - dim;
            if (i1 > 0) {
              c_merge_block(b_idx, c_x, dim, i1, 2, iwork, xwork);
            }
            i1 = 8;
          }
        }
        dim = iwork.size(0);
        b_iwork.set_size(iwork.size(0));
        for (bLen2 = 0; bLen2 < dim; bLen2++) {
          b_iwork[bLen2] = iwork[bLen2];
        }
        b_xwork.set_size(xwork.size(0));
        dim = xwork.size(0);
        for (bLen2 = 0; bLen2 < dim; bLen2++) {
          b_xwork[bLen2] = xwork[bLen2];
        }
        c_merge_block(b_idx, c_x, 0, nNonNaN, i1, b_iwork, b_xwork);
      }
      dim = b_idx.size(0);
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        iidx[bLen2] = b_idx[bLen2];
      }
      dim = c_x.size(0);
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        vwork[bLen2] = c_x[bLen2];
      }
    }
    for (k = 0; k <= vlen; k++) {
      bLen2 = j + (k * vstride);
      b_x[bLen2] = vwork[k];
      idx[bLen2] = iidx[k];
    }
  }
}

//
// Arguments    : real_T b_x[4]
// Return Type  : void
//
void d_sort(real_T b_x[4])
{
  real_T x4[4];
  real_T xwork[4];
  int32_T i2;
  int32_T i3;
  int32_T ib;
  int32_T nNaNs;
  int8_T perm[4];
  x4[0] = 0.0;
  xwork[0] = 0.0;
  x4[1] = 0.0;
  xwork[1] = 0.0;
  x4[2] = 0.0;
  xwork[2] = 0.0;
  x4[3] = 0.0;
  xwork[3] = 0.0;
  nNaNs = 0;
  ib = 0;
  if (std::isnan(b_x[0])) {
    xwork[3] = b_x[0];
    nNaNs = 1;
  } else {
    ib = 1;
    x4[0] = b_x[0];
  }
  if (std::isnan(b_x[1])) {
    xwork[3 - nNaNs] = b_x[1];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = b_x[1];
  }
  if (std::isnan(b_x[2])) {
    xwork[3 - nNaNs] = b_x[2];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = b_x[2];
  }
  if (std::isnan(b_x[3])) {
    xwork[3 - nNaNs] = b_x[3];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = b_x[3];
    if (ib == 4) {
      real_T b_d1;
      real_T d;
      int32_T i4;
      if (x4[0] <= x4[1]) {
        ib = 1;
        i2 = 2;
      } else {
        ib = 2;
        i2 = 1;
      }
      if (x4[2] <= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }
      d = x4[ib - 1];
      b_d1 = x4[i3 - 1];
      if (d <= b_d1) {
        d = x4[i2 - 1];
        if (d <= b_d1) {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i2);
          perm[2] = static_cast<int8_T>(i3);
          perm[3] = static_cast<int8_T>(i4);
        } else if (d <= x4[i4 - 1]) {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i2);
          perm[3] = static_cast<int8_T>(i4);
        } else {
          perm[0] = static_cast<int8_T>(ib);
          perm[1] = static_cast<int8_T>(i3);
          perm[2] = static_cast<int8_T>(i4);
          perm[3] = static_cast<int8_T>(i2);
        }
      } else {
        b_d1 = x4[i4 - 1];
        if (d <= b_d1) {
          if (x4[i2 - 1] <= b_d1) {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(ib);
            perm[2] = static_cast<int8_T>(i2);
            perm[3] = static_cast<int8_T>(i4);
          } else {
            perm[0] = static_cast<int8_T>(i3);
            perm[1] = static_cast<int8_T>(ib);
            perm[2] = static_cast<int8_T>(i4);
            perm[3] = static_cast<int8_T>(i2);
          }
        } else {
          perm[0] = static_cast<int8_T>(i3);
          perm[1] = static_cast<int8_T>(i4);
          perm[2] = static_cast<int8_T>(ib);
          perm[3] = static_cast<int8_T>(i2);
        }
      }
      b_x[-nNaNs] = x4[perm[0] - 1];
      b_x[1 - nNaNs] = x4[perm[1] - 1];
      b_x[2 - nNaNs] = x4[perm[2] - 1];
      b_x[3 - nNaNs] = x4[perm[3] - 1];
      ib = 0;
    }
  }
  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
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
    for (i3 = 0; i3 < ib; i3++) {
      b_x[((i3 - nNaNs) - ib) + 4] = x4[perm[i3] - 1];
    }
  }
  ib = asr_s32(nNaNs, 1U) + 4;
  for (i3 = 0; i3 <= (ib - 5); i3++) {
    i2 = (i3 - nNaNs) + 4;
    b_x[i2] = xwork[3 - i3];
    b_x[3 - i3] = xwork[i2];
  }
  if ((nNaNs & 1) != 0) {
    ib -= nNaNs;
    b_x[ib] = xwork[ib];
  }
}

//
// Arguments    : ::coder::array<real32_T, 1U> &b_x
//                ::coder::array<int32_T, 1U> &idx
// Return Type  : void
//
void sort(::coder::array<real32_T, 1U> &b_x, ::coder::array<int32_T, 1U> &idx)
{
  ::coder::array<int32_T, 1U> b_idx;
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<int32_T, 1U> iwork;
  ::coder::array<real32_T, 1U> c_x;
  ::coder::array<real32_T, 1U> vwork;
  ::coder::array<real32_T, 1U> xwork;
  int32_T b_iwork[256];
  int32_T idx4[4];
  int32_T bLen;
  int32_T dim;
  int32_T k;
  int32_T vlen;
  int32_T vstride;
  real32_T b_xwork[256];
  real32_T x4[4];
  int8_T perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    bLen = b_x.size(0);
  } else {
    bLen = 1;
  }
  vlen = bLen - 1;
  vwork.set_size(bLen);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int32_T j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen = 0; bLen < dim; bLen++) {
      iidx[bLen] = 0;
    }
    if (vwork.size(0) != 0) {
      int32_T i1;
      int32_T i2;
      int32_T i3;
      int32_T i4;
      int32_T idx_tmp;
      int32_T nNaNs;
      int32_T nNonNaN;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        b_idx[bLen] = 0;
      }
      dim = vwork.size(0);
      c_x.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        c_x[bLen] = vwork[bLen];
      }
      bLen = vwork.size(0);
      x4[0] = 0.0F;
      idx4[0] = 0;
      x4[1] = 0.0F;
      idx4[1] = 0;
      x4[2] = 0.0F;
      idx4[2] = 0;
      x4[3] = 0.0F;
      idx4[3] = 0;
      iwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (i1 = 0; i1 < dim; i1++) {
        iwork[i1] = 0;
      }
      xwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (i1 = 0; i1 < dim; i1++) {
        xwork[i1] = 0.0F;
      }
      nNaNs = 0;
      dim = -1;
      for (k = 0; k < bLen; k++) {
        if (std::isnan(c_x[k])) {
          idx_tmp = (bLen - nNaNs) - 1;
          b_idx[idx_tmp] = k + 1;
          xwork[idx_tmp] = c_x[k];
          nNaNs++;
        } else {
          dim++;
          idx4[dim] = k + 1;
          x4[dim] = c_x[k];
          if ((dim + 1) == 4) {
            real32_T f;
            real32_T f1;
            dim = k - nNaNs;
            if (x4[0] >= x4[1]) {
              i1 = 1;
              i2 = 2;
            } else {
              i1 = 2;
              i2 = 1;
            }
            if (x4[2] >= x4[3]) {
              i3 = 3;
              i4 = 4;
            } else {
              i3 = 4;
              i4 = 3;
            }
            f = x4[i1 - 1];
            f1 = x4[i3 - 1];
            if (f >= f1) {
              f = x4[i2 - 1];
              if (f >= f1) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i2);
                perm[2] = static_cast<int8_T>(i3);
                perm[3] = static_cast<int8_T>(i4);
              } else if (f >= x4[i4 - 1]) {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i2);
                perm[3] = static_cast<int8_T>(i4);
              } else {
                perm[0] = static_cast<int8_T>(i1);
                perm[1] = static_cast<int8_T>(i3);
                perm[2] = static_cast<int8_T>(i4);
                perm[3] = static_cast<int8_T>(i2);
              }
            } else {
              f1 = x4[i4 - 1];
              if (f >= f1) {
                if (x4[i2 - 1] >= f1) {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i2);
                  perm[3] = static_cast<int8_T>(i4);
                } else {
                  perm[0] = static_cast<int8_T>(i3);
                  perm[1] = static_cast<int8_T>(i1);
                  perm[2] = static_cast<int8_T>(i4);
                  perm[3] = static_cast<int8_T>(i2);
                }
              } else {
                perm[0] = static_cast<int8_T>(i3);
                perm[1] = static_cast<int8_T>(i4);
                perm[2] = static_cast<int8_T>(i1);
                perm[3] = static_cast<int8_T>(i2);
              }
            }
            b_idx[dim - 3] = idx4[perm[0] - 1];
            b_idx[dim - 2] = idx4[perm[1] - 1];
            b_idx[dim - 1] = idx4[perm[2] - 1];
            b_idx[dim] = idx4[perm[3] - 1];
            c_x[dim - 3] = x4[perm[0] - 1];
            c_x[dim - 2] = x4[perm[1] - 1];
            c_x[dim - 1] = x4[perm[2] - 1];
            c_x[dim] = x4[perm[3] - 1];
            dim = -1;
          }
        }
      }
      i3 = (vwork.size(0) - nNaNs) - 1;
      if ((dim + 1) > 0) {
        perm[1] = 0;
        perm[2] = 0;
        perm[3] = 0;
        if ((dim + 1) == 1) {
          perm[0] = 1;
        } else if ((dim + 1) == 2) {
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
        for (k = 0; k <= dim; k++) {
          idx_tmp = (static_cast<int32_T>(perm[k])) - 1;
          i1 = (i3 - dim) + k;
          b_idx[i1] = idx4[idx_tmp];
          c_x[i1] = x4[idx_tmp];
        }
      }
      dim = asr_s32(nNaNs, 1U) + 1;
      for (k = 0; k <= (dim - 2); k++) {
        i1 = (i3 + k) + 1;
        i2 = b_idx[i1];
        idx_tmp = (bLen - k) - 1;
        b_idx[i1] = b_idx[idx_tmp];
        b_idx[idx_tmp] = i2;
        c_x[i1] = xwork[idx_tmp];
        c_x[idx_tmp] = xwork[i1];
      }
      if ((nNaNs & 1) != 0) {
        dim += i3;
        c_x[dim] = xwork[dim];
      }
      nNonNaN = vwork.size(0) - nNaNs;
      dim = 2;
      if (nNonNaN > 1) {
        if (vwork.size(0) >= 256) {
          int32_T b_nBlocks;
          b_nBlocks = asr_s32(nNonNaN, 8U);
          if (b_nBlocks > 0) {
            for (int32_T b{0}; b < b_nBlocks; b++) {
              i4 = (b * 256) - 1;
              for (int32_T b_b{0}; b_b < 6; b_b++) {
                int32_T bLen2;
                int32_T nPairs;
                bLen =
                    ((static_cast<int32_T>(1))
                     << (static_cast<uint64_T>(static_cast<int32_T>(b_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<uint32_T>(static_cast<int32_T>(b_b + 3)));
                for (k = 0; k < nPairs; k++) {
                  i2 = (i4 + (k * bLen2)) + 1;
                  for (i1 = 0; i1 < bLen2; i1++) {
                    dim = i2 + i1;
                    b_iwork[i1] = b_idx[dim];
                    b_xwork[i1] = c_x[dim];
                  }
                  i3 = 0;
                  i1 = bLen;
                  dim = i2 - 1;
                  int32_T exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (b_xwork[i3] >= b_xwork[i1]) {
                      b_idx[dim] = b_iwork[i3];
                      c_x[dim] = b_xwork[i3];
                      if ((i3 + 1) < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[dim] = b_iwork[i1];
                      c_x[dim] = b_xwork[i1];
                      if ((i1 + 1) < bLen2) {
                        i1++;
                      } else {
                        dim -= i3;
                        for (i1 = i3 + 1; i1 <= bLen; i1++) {
                          idx_tmp = dim + i1;
                          b_idx[idx_tmp] = b_iwork[i1 - 1];
                          c_x[idx_tmp] = b_xwork[i1 - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = b_nBlocks * 256;
            i1 = nNonNaN - dim;
            if (i1 > 0) {
              merge_block(b_idx, c_x, dim, i1, 2, iwork, xwork);
            }
            dim = 8;
          }
        }
        merge_block(b_idx, c_x, 0, nNonNaN, dim, iwork, xwork);
      }
      if ((nNaNs > 0) && (nNonNaN > 0)) {
        for (k = 0; k < nNaNs; k++) {
          dim = nNonNaN + k;
          xwork[k] = c_x[dim];
          iwork[k] = b_idx[dim];
        }
        for (k = nNonNaN; k >= 1; k--) {
          dim = (nNaNs + k) - 1;
          c_x[dim] = c_x[k - 1];
          b_idx[dim] = b_idx[k - 1];
        }
        for (k = 0; k < nNaNs; k++) {
          c_x[k] = xwork[k];
          b_idx[k] = iwork[k];
        }
      }
      dim = b_idx.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        iidx[bLen] = b_idx[bLen];
      }
      dim = c_x.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        vwork[bLen] = c_x[bLen];
      }
    }
    for (k = 0; k <= vlen; k++) {
      bLen = j + (k * vstride);
      b_x[bLen] = vwork[k];
      idx[bLen] = iidx[k];
    }
  }
}

} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for sort.cpp
//
// [EOF]
//
