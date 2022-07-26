//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calculateReprErr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "calculateReprErr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &b_x
//                const ::coder::array<double, 2U> &projectedPoints_Cam1
//                const ::coder::array<double, 2U> &imagePointsTmp
// Return Type  : void
//
namespace ITER {
void c_binary_expand_op(::coder::array<double, 2U> &b_x,
                        const ::coder::array<double, 2U> &projectedPoints_Cam1,
                        const ::coder::array<double, 2U> &imagePointsTmp)
{
  int b_i;
  int i1;
  int i3;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  b_i = imagePointsTmp.size(0);
  if (b_i == 1) {
    i1 = projectedPoints_Cam1.size(0);
  } else {
    i1 = b_i;
  }
  b_x.set_size(i1, 2);
  stride_0_0 = static_cast<int>(projectedPoints_Cam1.size(0) != 1);
  stride_1_0 = static_cast<int>(b_i != 1);
  if (b_i == 1) {
    loop_ub = projectedPoints_Cam1.size(0);
  } else {
    loop_ub = b_i;
  }
  if ((static_cast<int>((loop_ub * 2) < 4)) != 0) {
    for (int i2{0}; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_x[i3 + (b_x.size(0) * i2)] =
            projectedPoints_Cam1[(i3 * stride_0_0) +
                                 (projectedPoints_Cam1.size(0) * i2)] -
            imagePointsTmp[(i3 * stride_1_0) + (imagePointsTmp.size(0) * i2)];
      }
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads()) private(i3)

    for (int i2 = 0; i2 < 2; i2++) {
      for (i3 = 0; i3 < loop_ub; i3++) {
        b_x[i3 + (b_x.size(0) * i2)] =
            projectedPoints_Cam1[(i3 * stride_0_0) +
                                 (projectedPoints_Cam1.size(0) * i2)] -
            imagePointsTmp[(i3 * stride_1_0) + (imagePointsTmp.size(0) * i2)];
      }
    }
  }
}

} // namespace ITER

//
// File trailer for calculateReprErr.cpp
//
// [EOF]
//
