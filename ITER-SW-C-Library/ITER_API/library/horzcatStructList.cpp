//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: horzcatStructList.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "horzcatStructList.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<f_struct_T, 1U> &structure
//                ::coder::array<double, 2U> &result
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace internal {
void horzcatStructList(const ::coder::array<f_struct_T, 1U> &structure,
                       ::coder::array<double, 2U> &result)
{
  int b_i;
  int h_n;
  int j;
  h_n = structure.size(0);
  if (structure.size(0) == 0) {
    b_i = 0;
  } else {
    b_i = structure.size(0) * 2;
  }
  result.set_size(1, b_i);
  j = 0;
  for (int c_i{0}; c_i < h_n; c_i++) {
    for (int i1{0}; i1 < 2; i1++) {
      result[result.size(0) * (i1 + j)] = structure[c_i].WeightedCentroid[i1];
    }
    j += 2;
  }
}

} // namespace internal
} // namespace coder
} // namespace ITER

//
// File trailer for horzcatStructList.cpp
//
// [EOF]
//
