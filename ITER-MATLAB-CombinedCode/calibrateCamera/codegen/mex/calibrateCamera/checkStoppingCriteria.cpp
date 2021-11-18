//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// checkStoppingCriteria.cpp
//
// Code generation for function 'checkStoppingCriteria'
//

// Include files
#include "checkStoppingCriteria.h"
#include "calibrateCamera_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
int32_T b_checkStoppingCriteria(real_T options_MaxFunctionEvaluations,
                                const ::coder::array<real_T, 1U> &gradf,
                                real_T relFactor, real_T funDiff,
                                const ::coder::array<real_T, 1U> &x,
                                const ::coder::array<real_T, 1U> &dx,
                                int32_T funcCount, boolean_T stepSuccessful,
                                int32_T *iter)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T i;
  normGradF = 0.0;
  i = gradf.size(0);
  for (int32_T k{0}; k < i; k++) {
    absx = muDoubleScalarAbs(gradf[k]);
    if (muDoubleScalarIsNaN(absx) || (absx > normGradF)) {
      normGradF = absx;
    }
  }
  if (normGradF <= 1.0E-10 * relFactor) {
    exitflag = 1;
  } else if (funcCount >= options_MaxFunctionEvaluations) {
    exitflag = 0;
  } else if (*iter >= 400) {
    exitflag = 0;
  } else {
    if (dx.size(0) == 0) {
      normGradF = 0.0;
    } else {
      n_t = (ptrdiff_t)dx.size(0);
      incx_t = (ptrdiff_t)1;
      normGradF = dnrm2(&n_t, &(((::coder::array<real_T, 1U> *)&dx)->data())[0],
                        &incx_t);
    }
    if (x.size(0) == 0) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)x.size(0);
      incx_t = (ptrdiff_t)1;
      absx = dnrm2(&n_t, &(((::coder::array<real_T, 1U> *)&x)->data())[0],
                   &incx_t);
    }
    if (normGradF < 1.0E-6 * (absx + 1.4901161193847656E-8)) {
      exitflag = 4;
      if (!stepSuccessful) {
        (*iter)++;
      }
    } else if (funDiff <= 1.0E-6) {
      exitflag = 3;
    } else {
      exitflag = -5;
    }
  }
  return exitflag;
}

int32_T checkStoppingCriteria(real_T options_MaxFunctionEvaluations,
                              const ::coder::array<real_T, 1U> &gradf,
                              real_T relFactor,
                              const ::coder::array<real_T, 1U> &x,
                              const ::coder::array<real_T, 1U> &dx,
                              int32_T funcCount)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T absx;
  real_T normGradF;
  int32_T exitflag;
  int32_T i;
  normGradF = 0.0;
  i = gradf.size(0);
  for (int32_T k{0}; k < i; k++) {
    absx = muDoubleScalarAbs(gradf[k]);
    if (muDoubleScalarIsNaN(absx) || (absx > normGradF)) {
      normGradF = absx;
    }
  }
  if (normGradF <= 1.0E-10 * relFactor) {
    exitflag = 1;
  } else if (funcCount >= options_MaxFunctionEvaluations) {
    exitflag = 0;
  } else {
    if (dx.size(0) == 0) {
      normGradF = 0.0;
    } else {
      n_t = (ptrdiff_t)dx.size(0);
      incx_t = (ptrdiff_t)1;
      normGradF = dnrm2(&n_t, &(((::coder::array<real_T, 1U> *)&dx)->data())[0],
                        &incx_t);
    }
    if (x.size(0) == 0) {
      absx = 0.0;
    } else {
      n_t = (ptrdiff_t)x.size(0);
      incx_t = (ptrdiff_t)1;
      absx = dnrm2(&n_t, &(((::coder::array<real_T, 1U> *)&x)->data())[0],
                   &incx_t);
    }
    if (normGradF < 1.0E-6 * (absx + 1.4901161193847656E-8)) {
      exitflag = 4;
    } else {
      exitflag = -5;
    }
  }
  return exitflag;
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (checkStoppingCriteria.cpp)
