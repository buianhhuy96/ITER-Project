//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlartg.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef XZLARTG_H
#define XZLARTG_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
void b_xzlartg(const creal_T f, const creal_T g, double *b_cs, creal_T *b_sn);

void xzlartg(const creal_T f, const creal_T g, double *b_cs, creal_T *b_sn,
             creal_T *r);

} // namespace reflapack
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzlartg.h
//
// [EOF]
//
