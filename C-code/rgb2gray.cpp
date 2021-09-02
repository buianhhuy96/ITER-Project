//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rgb2gray.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "rgb2gray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const ::coder::array<unsigned char, 3U> &b_X
//                ::coder::array<unsigned char, 2U> &b_I
// Return Type  : void
//
namespace coder {
void rgb2gray(const ::coder::array<unsigned char, 3U> &b_X,
              ::coder::array<unsigned char, 2U> &b_I)
{
  double sizeI;
  int X_idx_0;
  int i;
  int ub_loop;
  b_I.set_size(b_X.size(0), b_X.size(1));
  sizeI = (static_cast<double>(
              static_cast<int>((b_X.size(0) * b_X.size(1)) * b_X.size(2)))) /
          3.0;
  ub_loop = (static_cast<int>(sizeI)) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(X_idx_0, i)

  for (i = 0; i <= ub_loop; i++) {
    X_idx_0 = static_cast<int>(b_X[i]);
    b_I[i] = static_cast<unsigned char>(std::round(
        (((static_cast<double>(X_idx_0)) * 0.29893602129377539) +
         ((static_cast<double>(
              b_X[(static_cast<int>(static_cast<double>(
                      ((static_cast<double>(i)) + 1.0) + sizeI))) -
                  1])) *
          0.58704307445112125)) +
        ((static_cast<double>(
             b_X[(static_cast<int>(static_cast<double>(
                     ((static_cast<double>(i)) + 1.0) + (2.0 * sizeI)))) -
                 1])) *
         0.11402090425510336)));
  }
}

} // namespace coder

//
// File trailer for rgb2gray.cpp
//
// [EOF]
//
