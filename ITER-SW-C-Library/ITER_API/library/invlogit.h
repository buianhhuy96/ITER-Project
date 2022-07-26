//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: invlogit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

#ifndef INVLOGIT_H
#define INVLOGIT_H

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
namespace classreg {
namespace learning {
namespace coder {
namespace transform {
void b_invlogit(const ::coder::array<double, 2U> &b_in,
                ::coder::array<double, 2U> &out);

}
} // namespace coder
} // namespace learning
} // namespace classreg
} // namespace coder
} // namespace ITER

#endif
//
// File trailer for invlogit.h
//
// [EOF]
//
