//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cntrlFinDiffInsideBnds.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef CNTRLFINDIFFINSIDEBNDS_H
#define CNTRLFINDIFFINSIDEBNDS_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace utils {
namespace FiniteDifferences {
namespace internal {
int cntrlFinDiffInsideBnds(double xC_i, double b_lb_i, double ub_i,
                           double *b_delta_i);

}
} // namespace FiniteDifferences
} // namespace utils
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for cntrlFinDiffInsideBnds.h
//
// [EOF]
//
