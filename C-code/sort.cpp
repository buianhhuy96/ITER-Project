//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "sort.h"
#include "calibrateHandeye_rtwutil.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : ::coder::array<float, 1U> &x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
namespace coder {
namespace internal {
void sort(::coder::array<float, 1U> &x, ::coder::array<int, 1U> &idx)
{
  array<float, 1U> vwork;
  array<int, 1U> iidx;
  int dim;
  int i;
  int k;
  int vlen;
  int vstride;
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    i = x.size(0);
  } else {
    i = 1;
  }
  vlen = i - 1;
  vwork.set_size(i);
  idx.set_size(x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  for (dim = 0; dim < vstride; dim++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[dim + (k * vstride)];
    }
    sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i = dim + (k * vstride);
      x[i] = vwork[k];
      idx[i] = iidx[k];
    }
  }
}

//
// Arguments    : ::coder::array<int, 1U> &x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void sort(::coder::array<int, 1U> &x, ::coder::array<int, 1U> &idx)
{
  array<int, 1U> b_idx;
  array<int, 1U> b_iwork;
  array<int, 1U> b_x;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  array<int, 1U> vwork;
  array<int, 1U> xwork;
  int b_xwork[256];
  int c_iwork[256];
  int idx4[4];
  int x4[4];
  int bLen;
  int dim;
  int k;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    bLen = x.size(0);
  } else {
    bLen = 1;
  }
  vlen = bLen - 1;
  vwork.set_size(bLen);
  idx.set_size(x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen = 0; bLen < dim; bLen++) {
      iidx[bLen] = 0;
    }
    if (vwork.size(0) != 0) {
      int b_j;
      int i;
      int i1;
      int i2;
      int i4;
      int nLeft;
      int nQuartets;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        b_idx[bLen] = 0;
      }
      dim = vwork.size(0);
      b_x.set_size(vwork.size(0));
      for (bLen = 0; bLen < dim; bLen++) {
        b_x[bLen] = vwork[bLen];
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
      for (b_j = 0; b_j < nQuartets; b_j++) {
        i = b_j * 4;
        idx4[0] = i + 1;
        idx4[1] = i + 2;
        idx4[2] = i + 3;
        idx4[3] = i + 4;
        x4[0] = b_x[i];
        dim = b_x[i + 1];
        x4[1] = dim;
        i4 = b_x[i + 2];
        x4[2] = i4;
        nLeft = b_x[i + 3];
        x4[3] = nLeft;
        if (b_x[i] <= dim) {
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
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i2);
            perm[2] = static_cast<signed char>(dim);
            perm[3] = static_cast<signed char>(i4);
          } else if (bLen <= x4[i4 - 1]) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(dim);
            perm[2] = static_cast<signed char>(i2);
            perm[3] = static_cast<signed char>(i4);
          } else {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(dim);
            perm[2] = static_cast<signed char>(i4);
            perm[3] = static_cast<signed char>(i2);
          }
        } else {
          nLeft = x4[i4 - 1];
          if (bLen <= nLeft) {
            if (x4[i2 - 1] <= nLeft) {
              perm[0] = static_cast<signed char>(dim);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i2);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(dim);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(i2);
            }
          } else {
            perm[0] = static_cast<signed char>(dim);
            perm[1] = static_cast<signed char>(i4);
            perm[2] = static_cast<signed char>(i1);
            perm[3] = static_cast<signed char>(i2);
          }
        }
        b_idx[i] = idx4[perm[0] - 1];
        b_idx[i + 1] = idx4[perm[1] - 1];
        b_idx[i + 2] = idx4[perm[2] - 1];
        b_idx[i + 3] = idx4[perm[3] - 1];
        b_x[i] = x4[perm[0] - 1];
        b_x[i + 1] = x4[perm[1] - 1];
        b_x[i + 2] = x4[perm[2] - 1];
        b_x[i + 3] = x4[perm[3] - 1];
      }
      i4 = nQuartets * 4;
      nLeft = vwork.size(0) - i4;
      if (nLeft > 0) {
        for (k = 0; k < nLeft; k++) {
          dim = i4 + k;
          idx4[k] = dim + 1;
          x4[k] = b_x[dim];
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
          i1 = (static_cast<int>(perm[k])) - 1;
          dim = i4 + k;
          b_idx[dim] = idx4[i1];
          b_x[dim] = x4[i1];
        }
      }
      i4 = 2;
      if (vwork.size(0) > 1) {
        if (vwork.size(0) >= 256) {
          nQuartets = asr_s32(vwork.size(0), 8U);
          for (int b{0}; b < nQuartets; b++) {
            i = (b * 256) - 1;
            for (int b_b{0}; b_b < 6; b_b++) {
              int bLen2;
              int nPairs;
              bLen =
                  ((static_cast<int>(1))
                   << (static_cast<unsigned long>(static_cast<int>(b_b + 2))));
              bLen2 = bLen * 2;
              nPairs = asr_s32(
                  256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
              for (k = 0; k < nPairs; k++) {
                i4 = (i + (k * bLen2)) + 1;
                for (b_j = 0; b_j < bLen2; b_j++) {
                  dim = i4 + b_j;
                  c_iwork[b_j] = b_idx[dim];
                  b_xwork[b_j] = b_x[dim];
                }
                i2 = 0;
                nLeft = bLen;
                dim = i4 - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  dim++;
                  if (b_xwork[i2] <= b_xwork[nLeft]) {
                    b_idx[dim] = c_iwork[i2];
                    b_x[dim] = b_xwork[i2];
                    if ((i2 + 1) < bLen) {
                      i2++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    b_idx[dim] = c_iwork[nLeft];
                    b_x[dim] = b_xwork[nLeft];
                    if ((nLeft + 1) < bLen2) {
                      nLeft++;
                    } else {
                      dim -= i2;
                      for (b_j = i2 + 1; b_j <= bLen; b_j++) {
                        i1 = dim + b_j;
                        b_idx[i1] = c_iwork[b_j - 1];
                        b_x[i1] = b_xwork[b_j - 1];
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
            merge_block(b_idx, b_x, dim, i4, 2, iwork, xwork);
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
        merge_block(b_idx, b_x, 0, vwork.size(0), i4, b_iwork, iwork);
      }
      dim = b_idx.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        iidx[bLen] = b_idx[bLen];
      }
      dim = b_x.size(0);
      for (bLen = 0; bLen < dim; bLen++) {
        vwork[bLen] = b_x[bLen];
      }
    }
    for (k = 0; k <= vlen; k++) {
      bLen = j + (k * vstride);
      x[bLen] = vwork[k];
      idx[bLen] = iidx[k];
    }
  }
}

//
// Arguments    : ::coder::array<double, 1U> &x
//                ::coder::array<int, 1U> &idx
// Return Type  : void
//
void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx)
{
  array<double, 1U> b_x;
  array<double, 1U> b_xwork;
  array<double, 1U> vwork;
  array<double, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> b_iwork;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  double c_xwork[256];
  double x4[4];
  int c_iwork[256];
  int idx4[4];
  int bLen2;
  int dim;
  int k;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    bLen2 = x.size(0);
  } else {
    bLen2 = 1;
  }
  vlen = bLen2 - 1;
  vwork.set_size(bLen2);
  idx.set_size(x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen2 = 0; bLen2 < dim; bLen2++) {
      iidx[bLen2] = 0;
    }
    if (vwork.size(0) != 0) {
      int bLen;
      int i1;
      int i2;
      int i3;
      int i4;
      int idx_tmp;
      int nNonNaN;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        b_idx[bLen2] = 0;
      }
      dim = vwork.size(0);
      b_x.set_size(vwork.size(0));
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        b_x[bLen2] = vwork[bLen2];
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
        if (std::isnan(b_x[k])) {
          idx_tmp = (bLen2 - bLen) - 1;
          b_idx[idx_tmp] = k + 1;
          xwork[idx_tmp] = b_x[k];
          bLen++;
        } else {
          dim++;
          idx4[dim] = k + 1;
          x4[dim] = b_x[k];
          if ((dim + 1) == 4) {
            double d;
            double d1;
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
            d1 = x4[i3 - 1];
            if (d <= d1) {
              d = x4[i2 - 1];
              if (d <= d1) {
                perm[0] = static_cast<signed char>(i1);
                perm[1] = static_cast<signed char>(i2);
                perm[2] = static_cast<signed char>(i3);
                perm[3] = static_cast<signed char>(i4);
              } else if (d <= x4[i4 - 1]) {
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
              d1 = x4[i4 - 1];
              if (d <= d1) {
                if (x4[i2 - 1] <= d1) {
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
            b_idx[dim - 3] = idx4[perm[0] - 1];
            b_idx[dim - 2] = idx4[perm[1] - 1];
            b_idx[dim - 1] = idx4[perm[2] - 1];
            b_idx[dim] = idx4[perm[3] - 1];
            b_x[dim - 3] = x4[perm[0] - 1];
            b_x[dim - 2] = x4[perm[1] - 1];
            b_x[dim - 1] = x4[perm[2] - 1];
            b_x[dim] = x4[perm[3] - 1];
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
          idx_tmp = (static_cast<int>(perm[k])) - 1;
          i1 = (i3 - dim) + k;
          b_idx[i1] = idx4[idx_tmp];
          b_x[i1] = x4[idx_tmp];
        }
      }
      dim = asr_s32(bLen, 1U) + 1;
      for (k = 0; k <= (dim - 2); k++) {
        i1 = (i3 + k) + 1;
        i2 = b_idx[i1];
        idx_tmp = (bLen2 - k) - 1;
        b_idx[i1] = b_idx[idx_tmp];
        b_idx[idx_tmp] = i2;
        b_x[i1] = xwork[idx_tmp];
        b_x[idx_tmp] = xwork[i1];
      }
      if ((bLen & 1) != 0) {
        dim += i3;
        b_x[dim] = xwork[dim];
      }
      nNonNaN = vwork.size(0) - bLen;
      i1 = 2;
      if (nNonNaN > 1) {
        if (vwork.size(0) >= 256) {
          int nBlocks;
          nBlocks = asr_s32(nNonNaN, 8U);
          if (nBlocks > 0) {
            for (int b{0}; b < nBlocks; b++) {
              i4 = (b * 256) - 1;
              for (int b_b{0}; b_b < 6; b_b++) {
                int nPairs;
                bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(
                            static_cast<int>(b_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<unsigned int>(static_cast<int>(b_b + 3)));
                for (k = 0; k < nPairs; k++) {
                  i2 = (i4 + (k * bLen2)) + 1;
                  for (i1 = 0; i1 < bLen2; i1++) {
                    dim = i2 + i1;
                    c_iwork[i1] = b_idx[dim];
                    c_xwork[i1] = b_x[dim];
                  }
                  i3 = 0;
                  i1 = bLen;
                  dim = i2 - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (c_xwork[i3] <= c_xwork[i1]) {
                      b_idx[dim] = c_iwork[i3];
                      b_x[dim] = c_xwork[i3];
                      if ((i3 + 1) < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[dim] = c_iwork[i1];
                      b_x[dim] = c_xwork[i1];
                      if ((i1 + 1) < bLen2) {
                        i1++;
                      } else {
                        dim -= i3;
                        for (i1 = i3 + 1; i1 <= bLen; i1++) {
                          idx_tmp = dim + i1;
                          b_idx[idx_tmp] = c_iwork[i1 - 1];
                          b_x[idx_tmp] = c_xwork[i1 - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = nBlocks * 256;
            i1 = nNonNaN - dim;
            if (i1 > 0) {
              merge_block(b_idx, b_x, dim, i1, 2, iwork, xwork);
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
        merge_block(b_idx, b_x, 0, nNonNaN, i1, b_iwork, b_xwork);
      }
      dim = b_idx.size(0);
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        iidx[bLen2] = b_idx[bLen2];
      }
      dim = b_x.size(0);
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        vwork[bLen2] = b_x[bLen2];
      }
    }
    for (k = 0; k <= vlen; k++) {
      bLen2 = j + (k * vstride);
      x[bLen2] = vwork[k];
      idx[bLen2] = iidx[k];
    }
  }
}

//
// Arguments    : double x[4]
// Return Type  : void
//
void sort(double x[4])
{
  double x4[4];
  double xwork[4];
  int i2;
  int i3;
  int ib;
  int nNaNs;
  signed char perm[4];
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
  if (std::isnan(x[0])) {
    xwork[3] = x[0];
    nNaNs = 1;
  } else {
    ib = 1;
    x4[0] = x[0];
  }
  if (std::isnan(x[1])) {
    xwork[3 - nNaNs] = x[1];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[1];
  }
  if (std::isnan(x[2])) {
    xwork[3 - nNaNs] = x[2];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[2];
  }
  if (std::isnan(x[3])) {
    xwork[3 - nNaNs] = x[3];
    nNaNs++;
  } else {
    ib++;
    x4[ib - 1] = x[3];
    if (ib == 4) {
      double d;
      double d1;
      int i4;
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
      d1 = x4[i3 - 1];
      if (d <= d1) {
        d = x4[i2 - 1];
        if (d <= d1) {
          perm[0] = static_cast<signed char>(ib);
          perm[1] = static_cast<signed char>(i2);
          perm[2] = static_cast<signed char>(i3);
          perm[3] = static_cast<signed char>(i4);
        } else if (d <= x4[i4 - 1]) {
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
        d1 = x4[i4 - 1];
        if (d <= d1) {
          if (x4[i2 - 1] <= d1) {
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
      x[-nNaNs] = x4[perm[0] - 1];
      x[1 - nNaNs] = x4[perm[1] - 1];
      x[2 - nNaNs] = x4[perm[2] - 1];
      x[3 - nNaNs] = x4[perm[3] - 1];
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
      x[((i3 - nNaNs) - ib) + 4] = x4[perm[i3] - 1];
    }
  }
  ib = asr_s32(nNaNs, 1U) + 4;
  for (i3 = 0; i3 <= (ib - 5); i3++) {
    i2 = (i3 - nNaNs) + 4;
    x[i2] = xwork[3 - i3];
    x[3 - i3] = xwork[i2];
  }
  if ((nNaNs & 1) != 0) {
    ib -= nNaNs;
    x[ib] = xwork[ib];
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//
