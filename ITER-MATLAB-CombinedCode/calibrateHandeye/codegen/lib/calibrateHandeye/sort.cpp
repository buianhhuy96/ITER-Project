//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sort.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
  array<int, 1U> c_x;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  array<int, 1U> vwork;
  array<int, 1U> xwork;
  int b_xwork[256];
  int c_iwork[256];
  int idx4[4];
  int x4[4];
  int dim;
  int k;
  int offset;
  int vlen;
  int vstride;
  signed char perm[4];
  dim = 0;
  if (b_x.size(0) != 1) {
    dim = -1;
  }
  if ((dim + 2) <= 1) {
    offset = b_x.size(0);
  } else {
    offset = 1;
  }
  vlen = offset - 1;
  vwork.set_size(offset);
  idx.set_size(b_x.size(0));
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= b_x.size(0);
  }
  for (int j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (offset = 0; offset < dim; offset++) {
      iidx[offset] = 0;
    }
    if (vwork.size(0) != 0) {
      int b_i;
      int b_j;
      int i1;
      int i2;
      int i4;
      int nLeft;
      int nQuartets;
      dim = vwork.size(0);
      b_idx.set_size(vwork.size(0));
      for (offset = 0; offset < dim; offset++) {
        b_idx[offset] = 0;
      }
      dim = vwork.size(0);
      c_x.set_size(vwork.size(0));
      for (offset = 0; offset < dim; offset++) {
        c_x[offset] = vwork[offset];
      }
      for (b_i = 0; b_i < 4; b_i++) {
        x4[b_i] = 0;
        idx4[b_i] = 0;
      }
      iwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (offset = 0; offset < dim; offset++) {
        iwork[offset] = 0;
      }
      xwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (offset = 0; offset < dim; offset++) {
        xwork[offset] = 0;
      }
      nQuartets = asr_s32(vwork.size(0), 2U);
      for (b_j = 0; b_j < nQuartets; b_j++) {
        b_i = b_j * 4;
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
        offset = x4[i1 - 1];
        nLeft = x4[dim - 1];
        if (offset <= nLeft) {
          offset = x4[i2 - 1];
          if (offset <= nLeft) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i2);
            perm[2] = static_cast<signed char>(dim);
            perm[3] = static_cast<signed char>(i4);
          } else if (offset <= x4[i4 - 1]) {
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
          if (offset <= nLeft) {
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
        for (b_i = 0; b_i < 4; b_i++) {
          perm[b_i] = 0;
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
        for (k = 0; k < nLeft; k++) {
          i1 = (static_cast<int>(perm[k])) - 1;
          dim = i4 + k;
          b_idx[dim] = idx4[i1];
          c_x[dim] = x4[i1];
        }
      }
      i4 = 2;
      if (vwork.size(0) > 1) {
        if (vwork.size(0) >= 256) {
          nQuartets = asr_s32(vwork.size(0), 8U);
          for (int b{0}; b < nQuartets; b++) {
            offset = (b * 256) - 1;
            for (int d_b{0}; d_b < 6; d_b++) {
              int bLen2;
              int nPairs;
              b_i =
                  ((static_cast<int>(1))
                   << (static_cast<unsigned long>(static_cast<int>(d_b + 2))));
              bLen2 = b_i * 2;
              nPairs = asr_s32(
                  256, static_cast<unsigned int>(static_cast<int>(d_b + 3)));
              for (k = 0; k < nPairs; k++) {
                i4 = (offset + (k * bLen2)) + 1;
                for (b_j = 0; b_j < bLen2; b_j++) {
                  dim = i4 + b_j;
                  c_iwork[b_j] = b_idx[dim];
                  b_xwork[b_j] = c_x[dim];
                }
                i2 = 0;
                nLeft = b_i;
                dim = i4 - 1;
                int exitg1;
                do {
                  exitg1 = 0;
                  dim++;
                  if (b_xwork[i2] <= b_xwork[nLeft]) {
                    b_idx[dim] = c_iwork[i2];
                    c_x[dim] = b_xwork[i2];
                    if ((i2 + 1) < b_i) {
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
                      for (b_j = i2 + 1; b_j <= b_i; b_j++) {
                        i1 = dim + b_j;
                        b_idx[i1] = c_iwork[b_j - 1];
                        c_x[i1] = b_xwork[b_j - 1];
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
        for (offset = 0; offset < dim; offset++) {
          b_iwork[offset] = iwork[offset];
        }
        dim = xwork.size(0);
        iwork.set_size(xwork.size(0));
        for (offset = 0; offset < dim; offset++) {
          iwork[offset] = xwork[offset];
        }
        b_merge_block(b_idx, c_x, 0, vwork.size(0), i4, b_iwork, iwork);
      }
      dim = b_idx.size(0);
      for (offset = 0; offset < dim; offset++) {
        iidx[offset] = b_idx[offset];
      }
      dim = c_x.size(0);
      for (offset = 0; offset < dim; offset++) {
        vwork[offset] = c_x[offset];
      }
    }
    for (k = 0; k <= vlen; k++) {
      offset = j + (k * vstride);
      b_x[offset] = vwork[k];
      idx[offset] = iidx[k];
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
  array<double, 1U> b_xwork;
  array<double, 1U> c_x;
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
  for (int j{0}; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    iidx.set_size(vwork.size(0));
    dim = vwork.size(0);
    for (bLen2 = 0; bLen2 < dim; bLen2++) {
      iidx[bLen2] = 0;
    }
    if (vwork.size(0) != 0) {
      int bLen;
      int i2;
      int i3;
      int i4;
      int ib;
      int idx_tmp;
      int nNonNaN;
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
      for (dim = 0; dim < 4; dim++) {
        x4[dim] = 0.0;
        idx4[dim] = 0;
      }
      iwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (ib = 0; ib < dim; ib++) {
        iwork[ib] = 0;
      }
      xwork.set_size(vwork.size(0));
      dim = vwork.size(0);
      for (ib = 0; ib < dim; ib++) {
        xwork[ib] = 0.0;
      }
      bLen = 0;
      ib = -1;
      for (k = 0; k < bLen2; k++) {
        if (std::isnan(c_x[k])) {
          idx_tmp = (bLen2 - bLen) - 1;
          b_idx[idx_tmp] = k + 1;
          xwork[idx_tmp] = c_x[k];
          bLen++;
        } else {
          ib++;
          idx4[ib] = k + 1;
          x4[ib] = c_x[k];
          if ((ib + 1) == 4) {
            double b_d1;
            double d;
            dim = k - bLen;
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
              b_d1 = x4[i4 - 1];
              if (d <= b_d1) {
                if (x4[i2 - 1] <= b_d1) {
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
            b_idx[dim - 3] = idx4[perm[0] - 1];
            b_idx[dim - 2] = idx4[perm[1] - 1];
            b_idx[dim - 1] = idx4[perm[2] - 1];
            b_idx[dim] = idx4[perm[3] - 1];
            c_x[dim - 3] = x4[perm[0] - 1];
            c_x[dim - 2] = x4[perm[1] - 1];
            c_x[dim - 1] = x4[perm[2] - 1];
            c_x[dim] = x4[perm[3] - 1];
            ib = -1;
          }
        }
      }
      i3 = (vwork.size(0) - bLen) - 1;
      if ((ib + 1) > 0) {
        for (dim = 0; dim < 4; dim++) {
          perm[dim] = 0;
        }
        if ((ib + 1) == 1) {
          perm[0] = 1;
        } else if ((ib + 1) == 2) {
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
        for (k = 0; k <= ib; k++) {
          idx_tmp = (static_cast<int>(perm[k])) - 1;
          dim = (i3 - ib) + k;
          b_idx[dim] = idx4[idx_tmp];
          c_x[dim] = x4[idx_tmp];
        }
      }
      dim = asr_s32(bLen, 1U) + 1;
      for (k = 0; k <= (dim - 2); k++) {
        ib = (i3 + k) + 1;
        i2 = b_idx[ib];
        idx_tmp = (bLen2 - k) - 1;
        b_idx[ib] = b_idx[idx_tmp];
        b_idx[idx_tmp] = i2;
        c_x[ib] = xwork[idx_tmp];
        c_x[idx_tmp] = xwork[ib];
      }
      if ((bLen & 1) != 0) {
        dim += i3;
        c_x[dim] = xwork[dim];
      }
      nNonNaN = vwork.size(0) - bLen;
      ib = 2;
      if (nNonNaN > 1) {
        if (vwork.size(0) >= 256) {
          int b_nBlocks;
          b_nBlocks = asr_s32(nNonNaN, 8U);
          if (b_nBlocks > 0) {
            for (int b{0}; b < b_nBlocks; b++) {
              i4 = (b * 256) - 1;
              for (int d_b{0}; d_b < 6; d_b++) {
                int nPairs;
                bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(
                            static_cast<int>(d_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<unsigned int>(static_cast<int>(d_b + 3)));
                for (k = 0; k < nPairs; k++) {
                  i2 = (i4 + (k * bLen2)) + 1;
                  for (ib = 0; ib < bLen2; ib++) {
                    dim = i2 + ib;
                    c_iwork[ib] = b_idx[dim];
                    c_xwork[ib] = c_x[dim];
                  }
                  i3 = 0;
                  ib = bLen;
                  dim = i2 - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (c_xwork[i3] <= c_xwork[ib]) {
                      b_idx[dim] = c_iwork[i3];
                      c_x[dim] = c_xwork[i3];
                      if ((i3 + 1) < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[dim] = c_iwork[ib];
                      c_x[dim] = c_xwork[ib];
                      if ((ib + 1) < bLen2) {
                        ib++;
                      } else {
                        dim -= i3;
                        for (ib = i3 + 1; ib <= bLen; ib++) {
                          idx_tmp = dim + ib;
                          b_idx[idx_tmp] = c_iwork[ib - 1];
                          c_x[idx_tmp] = c_xwork[ib - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = b_nBlocks * 256;
            ib = nNonNaN - dim;
            if (ib > 0) {
              c_merge_block(b_idx, c_x, dim, ib, 2, iwork, xwork);
            }
            ib = 8;
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
        c_merge_block(b_idx, c_x, 0, nNonNaN, ib, b_iwork, b_xwork);
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
// Arguments    : double b_x[4]
// Return Type  : void
//
void d_sort(double b_x[4])
{
  double x4[4];
  double xwork[4];
  int idx[4];
  int idx4[4];
  int i1;
  int i3;
  int ib;
  int k;
  int nNaNs;
  int quartetOffset;
  signed char perm[4];
  for (quartetOffset = 0; quartetOffset < 4; quartetOffset++) {
    idx[quartetOffset] = 0;
    x4[quartetOffset] = 0.0;
    idx4[quartetOffset] = 0;
    xwork[quartetOffset] = 0.0;
  }
  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 4; k++) {
    if (std::isnan(b_x[k])) {
      idx[3 - nNaNs] = k + 1;
      xwork[3 - nNaNs] = b_x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x[k];
      if (ib == 4) {
        double b_d1;
        double d;
        int i4;
        quartetOffset = k - nNaNs;
        if (x4[0] <= x4[1]) {
          i1 = 1;
          ib = 2;
        } else {
          i1 = 2;
          ib = 1;
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
          d = x4[ib - 1];
          if (d <= b_d1) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(ib);
            perm[2] = static_cast<signed char>(i3);
            perm[3] = static_cast<signed char>(i4);
          } else if (d <= x4[i4 - 1]) {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(ib);
            perm[3] = static_cast<signed char>(i4);
          } else {
            perm[0] = static_cast<signed char>(i1);
            perm[1] = static_cast<signed char>(i3);
            perm[2] = static_cast<signed char>(i4);
            perm[3] = static_cast<signed char>(ib);
          }
        } else {
          b_d1 = x4[i4 - 1];
          if (d <= b_d1) {
            if (x4[ib - 1] <= b_d1) {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(ib);
              perm[3] = static_cast<signed char>(i4);
            } else {
              perm[0] = static_cast<signed char>(i3);
              perm[1] = static_cast<signed char>(i1);
              perm[2] = static_cast<signed char>(i4);
              perm[3] = static_cast<signed char>(ib);
            }
          } else {
            perm[0] = static_cast<signed char>(i3);
            perm[1] = static_cast<signed char>(i4);
            perm[2] = static_cast<signed char>(i1);
            perm[3] = static_cast<signed char>(ib);
          }
        }
        idx[quartetOffset - 3] = idx4[perm[0] - 1];
        idx[quartetOffset - 2] = idx4[perm[1] - 1];
        idx[quartetOffset - 1] = idx4[perm[2] - 1];
        idx[quartetOffset] = idx4[perm[3] - 1];
        b_x[quartetOffset - 3] = x4[perm[0] - 1];
        b_x[quartetOffset - 2] = x4[perm[1] - 1];
        b_x[quartetOffset - 1] = x4[perm[2] - 1];
        b_x[quartetOffset] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }
  if (ib > 0) {
    for (quartetOffset = 0; quartetOffset < 4; quartetOffset++) {
      perm[quartetOffset] = 0;
    }
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
    for (k = 0; k < ib; k++) {
      quartetOffset = (static_cast<int>(perm[k])) - 1;
      i1 = ((k - nNaNs) - ib) + 4;
      idx[i1] = idx4[quartetOffset];
      b_x[i1] = x4[quartetOffset];
    }
  }
  quartetOffset = asr_s32(nNaNs, 1U) + 4;
  for (k = 0; k <= (quartetOffset - 5); k++) {
    i1 = (k - nNaNs) + 4;
    ib = idx[i1];
    idx[i1] = idx[3 - k];
    idx[3 - k] = ib;
    b_x[i1] = xwork[3 - k];
    b_x[3 - k] = xwork[i1];
  }
  if ((nNaNs & 1) != 0) {
    quartetOffset -= nNaNs;
    b_x[quartetOffset] = xwork[quartetOffset];
  }
  if ((4 - nNaNs) > 1) {
    for (quartetOffset = 0; quartetOffset < 4; quartetOffset++) {
      idx4[quartetOffset] = 0;
    }
    i3 = asr_s32(4 - nNaNs, 2U);
    ib = 4;
    while (i3 > 1) {
      if ((i3 & 1) != 0) {
        i3--;
        i1 = ib * i3;
        quartetOffset = 4 - (nNaNs + i1);
        if (quartetOffset > ib) {
          d_merge(idx, b_x, i1, ib, quartetOffset - ib, idx4, xwork);
        }
      }
      quartetOffset = ib * 2;
      i3 = asr_s32(i3, 1U);
      for (k = 0; k < i3; k++) {
        d_merge(idx, b_x, k * quartetOffset, ib, ib, idx4, xwork);
      }
      ib = quartetOffset;
    }
    if ((4 - nNaNs) > ib) {
      d_merge(idx, b_x, 0, ib, 4 - (nNaNs + ib), idx4, xwork);
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
  array<float, 1U> c_x;
  array<float, 1U> vwork;
  array<float, 1U> xwork;
  array<int, 1U> b_idx;
  array<int, 1U> iidx;
  array<int, 1U> iwork;
  float b_xwork[256];
  float x4[4];
  int b_iwork[256];
  int idx4[4];
  int bLen2;
  int dim;
  int k;
  int vlen;
  int vstride;
  signed char perm[4];
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
  for (int j{0}; j < vstride; j++) {
    unsigned int unnamed_idx_0;
    for (k = 0; k <= vlen; k++) {
      vwork[k] = b_x[j + (k * vstride)];
    }
    unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
    iidx.set_size(static_cast<int>(unnamed_idx_0));
    dim = static_cast<int>(unnamed_idx_0);
    for (bLen2 = 0; bLen2 < dim; bLen2++) {
      iidx[bLen2] = 0;
    }
    if (vwork.size(0) != 0) {
      int bLen;
      int i2;
      int i3;
      int i4;
      int ib;
      int idx_tmp;
      int nNaNs;
      int nNonNaN;
      dim = static_cast<int>(unnamed_idx_0);
      b_idx.set_size(static_cast<int>(unnamed_idx_0));
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        b_idx[bLen2] = 0;
      }
      dim = vwork.size(0);
      c_x.set_size(dim);
      for (bLen2 = 0; bLen2 < dim; bLen2++) {
        c_x[bLen2] = vwork[bLen2];
      }
      bLen2 = vwork.size(0);
      bLen = vwork.size(0);
      for (dim = 0; dim < 4; dim++) {
        x4[dim] = 0.0F;
        idx4[dim] = 0;
      }
      iwork.set_size(static_cast<int>(unnamed_idx_0));
      dim = static_cast<int>(unnamed_idx_0);
      for (ib = 0; ib < dim; ib++) {
        iwork[ib] = 0;
      }
      unnamed_idx_0 = static_cast<unsigned int>(vwork.size(0));
      xwork.set_size(static_cast<int>(unnamed_idx_0));
      dim = static_cast<int>(unnamed_idx_0);
      for (ib = 0; ib < dim; ib++) {
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
            dim = k - nNaNs;
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
            b_idx[dim - 3] = idx4[perm[0] - 1];
            b_idx[dim - 2] = idx4[perm[1] - 1];
            b_idx[dim - 1] = idx4[perm[2] - 1];
            b_idx[dim] = idx4[perm[3] - 1];
            c_x[dim - 3] = x4[perm[0] - 1];
            c_x[dim - 2] = x4[perm[1] - 1];
            c_x[dim - 1] = x4[perm[2] - 1];
            c_x[dim] = x4[perm[3] - 1];
            ib = -1;
          }
        }
      }
      i3 = (bLen - nNaNs) - 1;
      if ((ib + 1) > 0) {
        for (dim = 0; dim < 4; dim++) {
          perm[dim] = 0;
        }
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
          dim = (i3 - ib) + k;
          b_idx[dim] = idx4[idx_tmp];
          c_x[dim] = x4[idx_tmp];
        }
      }
      dim = asr_s32(nNaNs, 1U) + 1;
      for (k = 0; k <= (dim - 2); k++) {
        ib = (i3 + k) + 1;
        i2 = b_idx[ib];
        idx_tmp = (bLen - k) - 1;
        b_idx[ib] = b_idx[idx_tmp];
        b_idx[idx_tmp] = i2;
        c_x[ib] = xwork[idx_tmp];
        c_x[idx_tmp] = xwork[ib];
      }
      if ((nNaNs & 1) != 0) {
        dim += i3;
        c_x[dim] = xwork[dim];
      }
      nNonNaN = bLen2 - nNaNs;
      dim = 2;
      if (nNonNaN > 1) {
        if (bLen2 >= 256) {
          int b_nBlocks;
          b_nBlocks = asr_s32(nNonNaN, 8U);
          if (b_nBlocks > 0) {
            for (int b{0}; b < b_nBlocks; b++) {
              i4 = (b * 256) - 1;
              for (int d_b{0}; d_b < 6; d_b++) {
                int nPairs;
                bLen = ((static_cast<int>(1)) << (static_cast<unsigned long>(
                            static_cast<int>(d_b + 2))));
                bLen2 = bLen * 2;
                nPairs = asr_s32(
                    256, static_cast<unsigned int>(static_cast<int>(d_b + 3)));
                for (k = 0; k < nPairs; k++) {
                  i2 = (i4 + (k * bLen2)) + 1;
                  for (ib = 0; ib < bLen2; ib++) {
                    dim = i2 + ib;
                    b_iwork[ib] = b_idx[dim];
                    b_xwork[ib] = c_x[dim];
                  }
                  i3 = 0;
                  ib = bLen;
                  dim = i2 - 1;
                  int exitg1;
                  do {
                    exitg1 = 0;
                    dim++;
                    if (b_xwork[i3] >= b_xwork[ib]) {
                      b_idx[dim] = b_iwork[i3];
                      c_x[dim] = b_xwork[i3];
                      if ((i3 + 1) < bLen) {
                        i3++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx[dim] = b_iwork[ib];
                      c_x[dim] = b_xwork[ib];
                      if ((ib + 1) < bLen2) {
                        ib++;
                      } else {
                        dim -= i3;
                        for (ib = i3 + 1; ib <= bLen; ib++) {
                          idx_tmp = dim + ib;
                          b_idx[idx_tmp] = b_iwork[ib - 1];
                          c_x[idx_tmp] = b_xwork[ib - 1];
                        }
                        exitg1 = 1;
                      }
                    }
                  } while (exitg1 == 0);
                }
              }
            }
            dim = b_nBlocks * 256;
            ib = nNonNaN - dim;
            if (ib > 0) {
              merge_block(b_idx, c_x, dim, ib, 2, iwork, xwork);
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

} // namespace internal
} // namespace coder

//
// File trailer for sort.cpp
//
// [EOF]
//
