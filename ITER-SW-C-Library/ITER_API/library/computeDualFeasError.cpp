//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: computeDualFeasError.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "computeDualFeasError.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : int nVar
//                const double gradLag[8][15]
//                bool *gradOK
//                double *val
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace fminconsqp {
namespace stopping {
void b_computeDualFeasError(int nVar, const double gradLag[8][15], bool *gradOK,
                            double *val)
{
  int idx;
  bool exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (nVar - 1))) {
    *gradOK = ((!std::isinf((&gradLag[0][0])[idx])) &&
               (!std::isnan((&gradLag[0][0])[idx])));
    if (!(*gradOK)) {
      exitg1 = true;
    } else {
      *val = std::fmax(*val, std::abs((&gradLag[0][0])[idx]));
      idx++;
    }
  }
}

//
// Arguments    : int nVar
//                const double gradLag[8]
//                bool *gradOK
//                double *val
// Return Type  : void
//
void computeDualFeasError(int nVar, const double gradLag[8], bool *gradOK,
                          double *val)
{
  int idx;
  bool exitg1;
  *gradOK = true;
  *val = 0.0;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= (nVar - 1))) {
    *gradOK = ((!std::isinf(gradLag[idx])) && (!std::isnan(gradLag[idx])));
    if (!(*gradOK)) {
      exitg1 = true;
    } else {
      *val = std::fmax(*val, std::abs(gradLag[idx]));
      idx++;
    }
  }
}

} // namespace stopping
} // namespace fminconsqp
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for computeDualFeasError.cpp
//
// [EOF]
//
