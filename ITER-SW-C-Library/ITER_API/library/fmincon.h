//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fmincon.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef FMINCON_H
#define FMINCON_H

// Include Files
#include "rtwtypes.h"
#if defined(_OPENMP) 
#include "omp.h"
#endif
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace ITER {
namespace coder {
class b_anonymous_function;

}
} // namespace ITER

// Function Declarations
namespace ITER {
namespace coder {
void fmincon(const b_anonymous_function *fun, const double x0[7],
             double b_x[7]);

}
} // namespace ITER

#endif
//
// File trailer for fmincon.h
//
// [EOF]
//
