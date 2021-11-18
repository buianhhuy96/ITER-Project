//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rgb2gray.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

// Include Files
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &d_X
//                ::coder::array<unsigned char, 2U> &e_I
// Return Type  : void
//
namespace Codegen {
namespace coder {
void rgb2gray(const ::coder::array<unsigned char, 3U> &d_X,
              ::coder::array<unsigned char, 2U> &e_I)
{
  double sizeI;
  int X_idx_0;
  int ub_loop;
  e_I.set_size(d_X.size(0), d_X.size(1));
  sizeI = (static_cast<double>(
              static_cast<int>((d_X.size(0) * d_X.size(1)) * d_X.size(2)))) /
          3.0;
  ub_loop = (static_cast<int>(sizeI)) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(X_idx_0)

  for (int b_i = 0; b_i <= ub_loop; b_i++) {
    X_idx_0 = static_cast<int>(d_X[b_i]);
    e_I[b_i] = static_cast<unsigned char>(std::round(
        (((static_cast<double>(X_idx_0)) * 0.29893602129377539) +
         ((static_cast<double>(
              d_X[(static_cast<int>(static_cast<double>(
                      ((static_cast<double>(b_i)) + 1.0) + sizeI))) -
                  1])) *
          0.58704307445112125)) +
        ((static_cast<double>(
             d_X[(static_cast<int>(static_cast<double>(
                     ((static_cast<double>(b_i)) + 1.0) + (2.0 * sizeI)))) -
                 1])) *
         0.11402090425510336)));
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for rgb2gray.cpp
//
// [EOF]
//
