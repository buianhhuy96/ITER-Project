//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "repmat.h"
#include "ITER_API_internal_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : double varargin_1
//                ::coder::array<f_struct_T, 1U> &b
// Return Type  : void
//
namespace ITER {
namespace coder {
void b_repmat(double varargin_1, ::coder::array<f_struct_T, 1U> &b)
{
  f_struct_T s;
  int loop_ub;
  int loop_ub_tmp;
  s.MinIntensity = 0U;
  s.MeanIntensity = 0.0;
  s.MaxIntensity = 0U;
  s.WeightedCentroid[0] = 0.0;
  s.WeightedCentroid[1] = 0.0;
  loop_ub_tmp = static_cast<int>(varargin_1);
  b.set_size(loop_ub_tmp);
  loop_ub = static_cast<int>(varargin_1);
  if ((static_cast<int>((static_cast<int>(varargin_1)) < 4)) != 0) {
    for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
      b[b_i] = s;
    }
  } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

    for (int b_i = 0; b_i < loop_ub; b_i++) {
      b[b_i] = s;
    }
  }
}

//
// Arguments    : const h_struct_T *b_a
//                double varargin_1
//                ::coder::array<h_struct_T, 1U> &b
// Return Type  : void
//
void repmat(const h_struct_T *b_a, double varargin_1,
            ::coder::array<h_struct_T, 1U> &b)
{
  int loop_ub_tmp;
  loop_ub_tmp = static_cast<int>(varargin_1);
  b.set_size(loop_ub_tmp);
  for (int b_i{0}; b_i < loop_ub_tmp; b_i++) {
    b[b_i] = *b_a;
  }
}

} // namespace coder
} // namespace ITER

//
// File trailer for repmat.cpp
//
// [EOF]
//
