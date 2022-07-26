//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: driver.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef DRIVER_H
#define DRIVER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class anonymous_function;

}
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
double computeFirstOrderOpt(const ::coder::array<double, 1U> &gradf,
                            bool hasFiniteBounds,
                            const double *projSteepestDescentInfNorm);

void driver(anonymous_function *fun, double x0[6], double *resnorm,
            ::coder::array<double, 2U> &fCurrent, double *exitflag,
            double *output_iterations, double *output_funcCount,
            double *output_stepsize, double *output_firstorderopt,
            char output_algorithm[19], double lambda_lower[6],
            double lambda_upper[6], ::coder::array<double, 2U> &jacobian);

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for driver.h
//
// [EOF]
//
