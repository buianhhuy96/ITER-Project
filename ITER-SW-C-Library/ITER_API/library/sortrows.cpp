//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortrows.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "sortrows.h"
#include "rt_nonfinite.h"
#include "sortLE.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<int, 2U> &y
// Return Type  : void
//
namespace ITER {
namespace coder {
void sortrows(::coder::array<int, 2U> &y)
{
  ::coder::array<int, 2U> col;
  ::coder::array<int, 1U> idx;
  ::coder::array<int, 1U> iwork;
  ::coder::array<int, 1U> ycol;
  int h_n;
  int loop_ub;
  int m;
  int p_n;
  int q_n;
  int y_idx_0;
  h_n = y.size(1);
  col.set_size(1, y.size(1));
  if ((static_cast<int>(h_n < 4)) != 0) {
    for (int k{0}; k < h_n; k++) {
      col[k] = k + 1;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int k = 0; k < h_n; k++) {
      col[k] = k + 1;
    }
  }
  p_n = y.size(0) + 1;
  y_idx_0 = y.size(0);
  idx.set_size(y_idx_0);
  loop_ub = y_idx_0;
  if ((static_cast<int>(y_idx_0 < 4)) != 0) {
    for (int b_i{0}; b_i < y_idx_0; b_i++) {
      idx[b_i] = 0;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      idx[b_i] = 0;
    }
  }
  if ((y.size(0) == 0) || (y.size(1) == 0)) {
    if ((static_cast<int>((p_n - 1) < 4)) != 0) {
      for (int b_k{0}; b_k <= (p_n - 2); b_k++) {
        idx[b_k] = b_k + 1;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int b_k = 0; b_k <= (p_n - 2); b_k++) {
        idx[b_k] = b_k + 1;
      }
    }
  } else {
    int c_i;
    int i1;
    iwork.set_size(y.size(0));
    i1 = y.size(0) - 1;
    for (int c_k{1}; c_k <= i1; c_k += 2) {
      if (internal::sortLE(y, col, c_k, c_k + 1)) {
        idx[c_k - 1] = c_k;
        idx[c_k] = c_k + 1;
      } else {
        idx[c_k - 1] = c_k + 1;
        idx[c_k] = c_k;
      }
    }
    if ((y.size(0) & 1) != 0) {
      idx[y.size(0) - 1] = y.size(0);
    }
    c_i = 2;
    while (c_i < (p_n - 1)) {
      int b_j;
      int i2;
      int pEnd;
      i2 = c_i * 2;
      b_j = 1;
      pEnd = c_i + 1;
      while (pEnd < p_n) {
        int b_kEnd;
        int b_q;
        int d_k;
        int p;
        int qEnd;
        p = b_j;
        b_q = pEnd;
        qEnd = b_j + i2;
        if (qEnd > p_n) {
          qEnd = p_n;
        }
        d_k = 0;
        b_kEnd = qEnd - b_j;
        while ((d_k + 1) <= b_kEnd) {
          int b_i2;
          int i3;
          b_i2 = idx[b_q - 1];
          i3 = idx[p - 1];
          if (internal::sortLE(y, col, i3, b_i2)) {
            iwork[d_k] = i3;
            p++;
            if (p == pEnd) {
              while (b_q < qEnd) {
                d_k++;
                iwork[d_k] = idx[b_q - 1];
                b_q++;
              }
            }
          } else {
            iwork[d_k] = b_i2;
            b_q++;
            if (b_q == qEnd) {
              while (p < pEnd) {
                d_k++;
                iwork[d_k] = idx[p - 1];
                p++;
              }
            }
          }
          d_k++;
        }
        for (int e_k{0}; e_k < b_kEnd; e_k++) {
          idx[(b_j + e_k) - 1] = iwork[e_k];
        }
        b_j = qEnd;
        pEnd = qEnd + c_i;
      }
      c_i = i2;
    }
  }
  m = y.size(0) - 1;
  q_n = y.size(1);
  ycol.set_size(y.size(0));
  for (int j{0}; j < q_n; j++) {
    for (int d_i{0}; d_i <= m; d_i++) {
      ycol[d_i] = y[(idx[d_i] + (y.size(0) * j)) - 1];
    }
    for (int e_i{0}; e_i <= m; e_i++) {
      y[e_i + (y.size(0) * j)] = ycol[e_i];
    }
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for sortrows.cpp
//
// [EOF]
//
