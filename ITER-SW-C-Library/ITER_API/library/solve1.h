//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solve1.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

#ifndef SOLVE1_H
#define SOLVE1_H

// Include Files
#include "rtwtypes.h"
#include "omp.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct s_struct_T;

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace DynamicRegCholManager {
void solve(const s_struct_T *obj, double rhs[8]);

}
} // namespace coder
} // namespace optim
} // namespace coder

#endif
//
// File trailer for solve1.h
//
// [EOF]
//
