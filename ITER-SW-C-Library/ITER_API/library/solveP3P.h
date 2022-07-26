//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solveP3P.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef SOLVEP3P_H
#define SOLVEP3P_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace ITER {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
void solveP3P(const double imagePointsIn[2][4],
              const ::coder::array<double, 2U> &worldPointsIn,
              const double f_K[3][3], ::coder::array<double, 3U> &b_Rs,
              ::coder::array<double, 2U> &Ts);

}
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for solveP3P.h
//
// [EOF]
//
