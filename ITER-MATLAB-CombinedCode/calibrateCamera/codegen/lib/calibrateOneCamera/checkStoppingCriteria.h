//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingCriteria.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 25-Oct-2021 12:51:07
//

#ifndef CHECKSTOPPINGCRITERIA_H
#define CHECKSTOPPINGCRITERIA_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int b_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor, double funDiff,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, bool stepSuccessful, int *iter);

int checkStoppingCriteria(double options_MaxFunctionEvaluations,
                          const ::coder::array<double, 1U> &gradf,
                          double relFactor,
                          const ::coder::array<double, 1U> &b_x,
                          const ::coder::array<double, 1U> &b_dx,
                          int funcCount);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

#endif
//
// File trailer for checkStoppingCriteria.h
//
// [EOF]
//
