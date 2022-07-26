//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: countsort.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "countsort.h"
#include "rt_nonfinite.h"
#include <cstring>
#include <string.h>

// Function Definitions
//
// Arguments    : int b_x[15]
//                int xLen
//                int workspace[15]
//                int xMin
//                int xMax
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace utils {
void countsort(int b_x[15], int xLen, int workspace[15], int xMin, int xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int b_i;
    int i1;
    int idxEnd;
    int idxStart;
    int maxOffset;
    b_i = xMax - xMin;
    i1 = b_i;
    if ((static_cast<int>((b_i + 1) < 4)) != 0) {
      if (0 <= b_i) {
        (void)std::memset(
            &workspace[0], 0,
            (static_cast<unsigned int>(static_cast<int>(b_i + 1))) *
                (sizeof(int)));
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int idx = 0; idx <= i1; idx++) {
        workspace[idx] = 0;
      }
    }
    maxOffset = (xMax - xMin) - 1;
    for (int b_idx{0}; b_idx < xLen; b_idx++) {
      int i2;
      i2 = b_x[b_idx] - xMin;
      workspace[i2]++;
    }
    for (int c_idx{2}; c_idx <= (maxOffset + 2); c_idx++) {
      workspace[c_idx - 1] += workspace[c_idx - 2];
    }
    idxStart = 1;
    idxEnd = workspace[0];
    for (int idxW{0}; idxW <= maxOffset; idxW++) {
      for (int idxFill{idxStart}; idxFill <= idxEnd; idxFill++) {
        b_x[idxFill - 1] = idxW + xMin;
      }
      idxStart = workspace[idxW] + 1;
      idxEnd = workspace[idxW + 1];
    }
    if ((static_cast<int>(((idxEnd - idxStart) + 1) < 4)) != 0) {
      for (int d_idx{idxStart}; d_idx <= idxEnd; d_idx++) {
        b_x[d_idx - 1] = xMax;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int d_idx = idxStart; d_idx <= idxEnd; d_idx++) {
        b_x[d_idx - 1] = xMax;
      }
    }
  }
}

} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for countsort.cpp
//
// [EOF]
//
