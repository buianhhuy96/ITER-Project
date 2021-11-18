//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat1.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "cat1.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : ::coder::array<real_T, 2U> &b_ci
//                const ::coder::array<real_T, 1U> &beta
//                const ::coder::array<real_T, 1U> &delta
// Return Type  : void
//
namespace Codegen {
void b_binary_expand_op(::coder::array<real_T, 2U> &b_ci,
                        const ::coder::array<real_T, 1U> &beta,
                        const ::coder::array<real_T, 1U> &delta)
{
  ::coder::array<real_T, 1U> b_beta;
  ::coder::array<real_T, 1U> c_beta;
  int32_T b_i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (delta.size(0) == 1) {
    b_i = beta.size(0);
  } else {
    b_i = delta.size(0);
  }
  b_beta.set_size(b_i);
  stride_0_0 = static_cast<int32_T>(beta.size(0) != 1);
  stride_1_0 = static_cast<int32_T>(delta.size(0) != 1);
  if (delta.size(0) == 1) {
    loop_ub = beta.size(0);
  } else {
    loop_ub = delta.size(0);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_beta[b_i] = beta[b_i * stride_0_0] - delta[b_i * stride_1_0];
  }
  if (delta.size(0) == 1) {
    b_i = beta.size(0);
  } else {
    b_i = delta.size(0);
  }
  c_beta.set_size(b_i);
  stride_0_0 = static_cast<int32_T>(beta.size(0) != 1);
  stride_1_0 = static_cast<int32_T>(delta.size(0) != 1);
  if (delta.size(0) == 1) {
    loop_ub = beta.size(0);
  } else {
    loop_ub = delta.size(0);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_beta[b_i] = beta[b_i * stride_0_0] + delta[b_i * stride_1_0];
  }
  b_ci.set_size(b_beta.size(0), 2);
  loop_ub = b_beta.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_ci[b_i] = b_beta[b_i];
  }
  loop_ub = c_beta.size(0);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    b_ci[b_i + b_ci.size(0)] = c_beta[b_i];
  }
}

} // namespace Codegen

//
// File trailer for cat1.cpp
//
// [EOF]
//
