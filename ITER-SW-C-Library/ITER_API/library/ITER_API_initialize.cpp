//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_initialize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ITER_API_initialize.h"
#include "ITER_API_data.h"
#include "eml_rand.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "rt_nonfinite.h"
#include "subPixelLocation.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace ITER {
void ITER_API_initialize()
{
#if defined(_OPENMP)
  omp_init_nest_lock(&calibrateOneCamera_nestLockGlobal);
#endif
  state_not_empty_init();
  subPixelLocationImpl_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  isInitialized_ITER_API = true;
}

} // namespace ITER

//
// File trailer for ITER_API_initialize.cpp
//
// [EOF]
//
