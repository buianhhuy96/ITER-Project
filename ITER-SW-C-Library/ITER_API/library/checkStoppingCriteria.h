//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: checkStoppingCriteria.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef CHECKSTOPPINGCRITERIA_H
#define CHECKSTOPPINGCRITERIA_H

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
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int b_checkStoppingCriteria(const double gradf[6], double relFactor,
                            double funDiff, const double b_x[6],
                            const double b_dx[6], int funcCount,
                            bool stepSuccessful, int *b_iter,
                            double projSteepestDescentInfNorm,
                            bool hasFiniteBounds);

int c_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor, double funDiff,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, bool stepSuccessful, int *b_iter,
                            double projSteepestDescentInfNorm,
                            bool hasFiniteBounds);

int checkStoppingCriteria(const double gradf[6], double relFactor,
                          const double b_x[6], int funcCount,
                          double projSteepestDescentInfNorm,
                          bool hasFiniteBounds);

int d_checkStoppingCriteria(double options_MaxFunctionEvaluations,
                            const ::coder::array<double, 1U> &gradf,
                            double relFactor,
                            const ::coder::array<double, 1U> &b_x,
                            const ::coder::array<double, 1U> &b_dx,
                            int funcCount, double projSteepestDescentInfNorm,
                            bool hasFiniteBounds);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for checkStoppingCriteria.h
//
// [EOF]
//
