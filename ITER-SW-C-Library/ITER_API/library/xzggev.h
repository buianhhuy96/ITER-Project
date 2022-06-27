//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzggev.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XZGGEV_H
#define XZGGEV_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
void xzggev(creal_T A[4][4], int *info, creal_T alpha1[4], creal_T beta1[4],
            creal_T V[4][4]);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzggev.h
//
// [EOF]
//
