//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_rand_mcg16807_stateful.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "eml_rand_mcg16807_stateful.h"
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace ITER {
void eml_rand_mcg16807_stateful_init()
{
  state = 1144108930U;
}

} // namespace ITER

//
// File trailer for eml_rand_mcg16807_stateful.cpp
//
// [EOF]
//
