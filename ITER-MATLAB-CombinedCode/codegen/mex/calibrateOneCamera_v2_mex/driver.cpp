//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// driver.cpp
//
// Code generation for function 'driver'
//

// Include files
#include "driver.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateOneCamera_v2.h"
#include "calibrateOneCamera_v2_mex_data.h"
#include "calibrateOneCamera_v2_mex_internal_types.h"
#include "calibrateOneCamera_v2_mex_internal_types1.h"
#include "calibrateOneCamera_v2_mex_internal_types11.h"
#include "calibrateOneCamera_v2_mex_types.h"
#include "checkFinite.h"
#include "checkStoppingCriteria.h"
#include "eml_int_forloop_overflow_check.h"
#include "factoryConstruct.h"
#include "hasFiniteBounds.h"
#include "jacobianFiniteDifference.h"
#include "linearLeastSquares.h"
#include "norm.h"
#include "power.h"
#include "projectBox.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xcopy.h"
#include "xdot.h"
#include "xgemv.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ed_emlrtRSI{
    44,       // lineNo
    "mpower", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" // pathName
};

static emlrtRSInfo tcb_emlrtRSI{
    1,        // lineNo
    "driver", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pathName
};

static emlrtRSInfo
    ifb_emlrtRSI{
        29,         // lineNo
        "minOrMax", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    jfb_emlrtRSI{
        58,         // lineNo
        "maximum2", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo kfb_emlrtRSI{
    63,               // lineNo
    "binaryMinOrMax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\binaryMinOrMax.m" // pathName
};

static emlrtRSInfo lfb_emlrtRSI{
    188,        // lineNo
    "flatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" // pathName
};

static emlrtECInfo bd_emlrtECI{
    -1,       // nDims
    1,        // lineNo
    1,        // colNo
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pName
};

static emlrtBCInfo ju_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    1,        // lineNo
    1,        // colNo
    "",       // aName
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p", // pName
    0                               // checkKind
};

static emlrtRTEInfo ic_emlrtRTEI{
    1,        // lineNo
    1,        // colNo
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pName
};

static emlrtDCInfo qg_emlrtDCI{
    1,        // lineNo
    1,        // colNo
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p", // pName
    4                               // checkKind
};

static emlrtBCInfo ku_emlrtBCI{
    1,        // iFirst
    0,        // iLast
    1,        // lineNo
    1,        // colNo
    "",       // aName
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p", // pName
    0                               // checkKind
};

static emlrtRTEInfo ev_emlrtRTEI{
    53,                // lineNo
    36,                // colNo
    "function_handle", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pName
};

// Function Declarations
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
static real_T computeFirstOrderOpt(const ::coder::array<real_T, 1U> &gradf,
                                   boolean_T hasFiniteBounds,
                                   const real_T *projSteepestDescentInfNorm);

}
} // namespace coder
} // namespace optim
} // namespace coder

// Function Definitions
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
static real_T computeFirstOrderOpt(const ::coder::array<real_T, 1U> &gradf,
                                   boolean_T hasFiniteBounds,
                                   const real_T *projSteepestDescentInfNorm)
{
  real_T firstOrderOpt;
  if (hasFiniteBounds) {
    real_T b;
    b = c_norm(gradf);
    if ((muDoubleScalarAbs(*projSteepestDescentInfNorm - b) <
         2.2204460492503131E-16 *
             muDoubleScalarMax(*projSteepestDescentInfNorm, b)) ||
        (b == 0.0)) {
      firstOrderOpt = *projSteepestDescentInfNorm;
    } else {
      firstOrderOpt =
          *projSteepestDescentInfNorm * *projSteepestDescentInfNorm / b;
    }
  } else {
    firstOrderOpt = c_norm(gradf);
  }
  return firstOrderOpt;
}

void driver(const emlrtStack *sp, const anonymous_function *fun,
            const ::coder::array<real_T, 1U> &x0, ::coder::array<real_T, 1U> &x,
            real_T *resnorm, ::coder::array<real_T, 1U> &fCurrent,
            real_T *exitflag, real_T *output_iterations,
            real_T *output_funcCount, real_T *output_stepsize,
            real_T *output_firstorderopt, char_T output_algorithm[19],
            ::coder::array<real_T, 1U> &lambda_lower,
            ::coder::array<real_T, 1U> &lambda_upper,
            ::coder::array<real_T, 2U> &jacobian)
{
  static const char_T b_cv[19]{'l', 'e', 'v', 'e', 'n', 'b', 'e', 'r', 'g', '-',
                               'm', 'a', 'r', 'q', 'u', 'a', 'r', 'd', 't'};
  static const char_T t8_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                                 'a', 'r', 'd'};
  b_anonymous_function b_this;
  array<real_T, 2U> augJacobian;
  array<real_T, 1U> TypicalX;
  array<real_T, 1U> c_finiteDifferenceRunTimeOption;
  array<real_T, 1U> d_finiteDifferenceRunTimeOption;
  array<real_T, 1U> dx;
  array<real_T, 1U> fNew;
  array<real_T, 1U> f_temp;
  array<real_T, 1U> gradf;
  array<real_T, 1U> rhs;
  array<real_T, 1U> scaleFactors;
  array<real_T, 1U> xp;
  array<int32_T, 1U> r;
  array<int32_T, 1U> r1;
  array<boolean_T, 1U> hasLB;
  array<boolean_T, 1U> hasUB;
  array<boolean_T, 1U> indActive;
  d_struct_T FiniteDifferences;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  real_T b_gamma;
  real_T funDiff;
  real_T projSteepestDescentInfNorm;
  real_T relFactor;
  real_T resnormNew;
  int32_T b_iv[2];
  int32_T b_exitflag;
  int32_T funcCount;
  int32_T i;
  int32_T iter;
  int32_T loop_ub;
  int32_T m;
  int32_T m_temp;
  int32_T n;
  int32_T nx;
  int32_T options_MaxFunctionEvaluations;
  boolean_T evalOK;
  boolean_T exitg1;
  boolean_T hasFiniteBounds;
  boolean_T stepSuccessful;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  for (i = 0; i < 19; i++) {
    output_algorithm[i] = b_cv[i];
  }
  n = x0.size(0);
  indActive.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    indActive[i] = false;
  }
  gradf.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  st.site = &tcb_emlrtRSI;
  dx.set_size(&ic_emlrtRTEI, &st, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    dx[i] = rtInf;
  }
  funDiff = rtInf;
  scaleFactors.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    scaleFactors[i] = 1.0;
  }
  iter = 0;
  options_MaxFunctionEvaluations = 200 * x0.size(0);
  TypicalX.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    TypicalX[i] = 1.0;
  }
  hasLB.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  hasUB.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  st.site = &tcb_emlrtRSI;
  hasFiniteBounds = utils::hasFiniteBounds(&st, x0.size(0), hasLB, hasUB);
  if (!hasFiniteBounds) {
    x.set_size(&ic_emlrtRTEI, sp, x0.size(0));
    loop_ub = x0.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[i] = x0[i];
    }
  } else {
    x.set_size(&ic_emlrtRTEI, sp, x0.size(0));
    loop_ub = x0.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[i] = x0[i];
    }
    f_temp.set_size(&ic_emlrtRTEI, sp, x0.size(0));
    loop_ub = x0.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = 0.0;
    }
    st.site = &tcb_emlrtRSI;
    projectBox(&st, f_temp, x, hasLB, hasUB);
    if (x.size(0) != x0.size(0)) {
      emlrtSizeEqCheck1DR2012b(x.size(0), x0.size(0), &bd_emlrtECI,
                               (emlrtCTX)sp);
    }
    f_temp.set_size(&ic_emlrtRTEI, sp, x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = x[i] - x0[i];
    }
    st.site = &tcb_emlrtRSI;
    if (c_norm(f_temp) > 0.0) {
      st.site = &tcb_emlrtRSI;
      internal::e_warning(&st);
    }
  }
  st.site = &tcb_emlrtRSI;
  b_st.site = &rcb_emlrtRSI;
  calibrateOneCamera_v2_anonFcn1(&b_st, &fun->workspace.initialParams,
                                 fun->workspace.world_points,
                                 fun->workspace.image_points, x, f_temp);
  m_temp = f_temp.size(0);
  jacobian.set_size(&ic_emlrtRTEI, sp, f_temp.size(0), x0.size(0));
  m = f_temp.size(0) - 1;
  fCurrent.set_size(&ic_emlrtRTEI, sp, f_temp.size(0));
  fNew.set_size(&ic_emlrtRTEI, sp, f_temp.size(0));
  st.site = &tcb_emlrtRSI;
  if ((1 <= f_temp.size(0)) && (f_temp.size(0) > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (nx = 0; nx <= m; nx++) {
    if (nx + 1 > f_temp.size(0)) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, f_temp.size(0), &ju_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (nx + 1 > fCurrent.size(0)) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, fCurrent.size(0), &ju_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    fCurrent[nx] = f_temp[nx];
  }
  i = f_temp.size(0) + x0.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &qg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  augJacobian.set_size(&ic_emlrtRTEI, sp, i, x0.size(0));
  if (1 > f_temp.size(0)) {
    loop_ub = 0;
  } else {
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &ju_emlrtBCI, (emlrtCTX)sp);
    }
    if (f_temp.size(0) > i) {
      emlrtDynamicBoundsCheckR2012b(f_temp.size(0), 1, i, &ju_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    loop_ub = f_temp.size(0);
  }
  r.set_size(&ic_emlrtRTEI, sp, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = x0.size(0);
  r1.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  for (i = 0; i < loop_ub; i++) {
    r1[i] = i;
  }
  b_iv[0] = r.size(0);
  b_iv[1] = r1.size(0);
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, jacobian.size(), 2, &bd_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    nx = jacobian.size(0);
    for (b_exitflag = 0; b_exitflag < nx; b_exitflag++) {
      augJacobian[r[b_exitflag] + augJacobian.size(0) * r1[i]] =
          jacobian[b_exitflag + jacobian.size(0) * i];
    }
  }
  i = f_temp.size(0) + x0.size(0);
  if (i < 0) {
    emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &qg_emlrtDCI,
                                (emlrtCTX)sp);
  }
  rhs.set_size(&ic_emlrtRTEI, sp, i);
  st.site = &tcb_emlrtRSI;
  *resnorm = internal::blas::xdot(f_temp.size(0), fCurrent, fCurrent);
  st.site = &tcb_emlrtRSI;
  evalOK = validate::checkFinite(&st, fCurrent, f_temp.size(0));
  if (!evalOK) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ic_emlrtRTEI, "optim_codegen:common:NonFiniteInitialObjective",
        "optim_codegen:common:NonFiniteInitialObjective", 0);
  }
  b_this.workspace.fun = *fun;
  st.site = &tcb_emlrtRSI;
  utils::FiniteDifferences::factoryConstruct(
      &st, &b_this, x0.size(0), f_temp.size(0), t8_FiniteDifferenceType,
      &FiniteDifferences);
  c_finiteDifferenceRunTimeOption.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    c_finiteDifferenceRunTimeOption[i] = 1.0;
  }
  d_finiteDifferenceRunTimeOption.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    d_finiteDifferenceRunTimeOption[i] = 1.4901161193847656E-8;
  }
  st.site = &tcb_emlrtRSI;
  jacobianFiniteDifference(
      &st, augJacobian, fCurrent, x, t8_FiniteDifferenceType, TypicalX,
      &FiniteDifferences, c_finiteDifferenceRunTimeOption,
      d_finiteDifferenceRunTimeOption, &funcCount, &evalOK);
  b_gamma = 0.01;
  st.site = &tcb_emlrtRSI;
  if ((1 <= x0.size(0)) && (x0.size(0) > 2147483646)) {
    b_st.site = &yc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (nx = 0; nx < n; nx++) {
    st.site = &tcb_emlrtRSI;
    internal::blas::xcopy(&st, n, augJacobian,
                          ((m_temp + n) * (nx + 1) - n) + 1);
    i = (m_temp + nx) + 1;
    if ((i < 1) || (i > augJacobian.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, augJacobian.size(0), &ju_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (nx + 1 > augJacobian.size(1)) {
      emlrtDynamicBoundsCheckR2012b(nx + 1, 1, augJacobian.size(1),
                                    &ju_emlrtBCI, (emlrtCTX)sp);
    }
    augJacobian[(i + augJacobian.size(0) * nx) - 1] = 0.1;
    st.site = &tcb_emlrtRSI;
    internal::blas::xcopy(m_temp, augJacobian, (m_temp + n) * nx + 1, jacobian,
                          m_temp * nx + 1);
  }
  st.site = &tcb_emlrtRSI;
  evalOK = validate::checkFinite(&st, augJacobian, f_temp.size(0) + x0.size(0),
                                 x0.size(0));
  if (!evalOK) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ic_emlrtRTEI, "optim_codegen:common:NonFiniteInitialJacobian",
        "optim_codegen:common:NonFiniteInitialJacobian", 0);
  }
  st.site = &tcb_emlrtRSI;
  internal::blas::xgemv(f_temp.size(0), x0.size(0), jacobian, f_temp.size(0),
                        fCurrent, gradf);
  f_temp.set_size(&ic_emlrtRTEI, sp, gradf.size(0));
  loop_ub = gradf.size(0);
  for (i = 0; i < loop_ub; i++) {
    f_temp[i] = -gradf[i];
  }
  st.site = &tcb_emlrtRSI;
  projSteepestDescentInfNorm = b_projectBox(&st, x, f_temp, hasLB, hasUB);
  st.site = &tcb_emlrtRSI;
  resnormNew =
      computeFirstOrderOpt(gradf, hasFiniteBounds, &projSteepestDescentInfNorm);
  relFactor = muDoubleScalarMax(resnormNew, 1.4901161193847656E-8);
  stepSuccessful = true;
  st.site = &tcb_emlrtRSI;
  b_exitflag = checkStoppingCriteria(
      static_cast<real_T>(options_MaxFunctionEvaluations), gradf, relFactor, x,
      dx, funcCount, projSteepestDescentInfNorm, hasFiniteBounds);
  exitg1 = false;
  while ((!exitg1) && (b_exitflag == -5)) {
    boolean_T guard1{false};
    f_temp.set_size(&ic_emlrtRTEI, sp, fCurrent.size(0));
    loop_ub = fCurrent.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = -fCurrent[i];
    }
    st.site = &tcb_emlrtRSI;
    internal::blas::xcopy(m_temp, f_temp, rhs);
    st.site = &tcb_emlrtRSI;
    internal::blas::xcopy(&st, n, rhs, m_temp + 1);
    if (hasFiniteBounds) {
      st.site = &tcb_emlrtRSI;
      b_st.site = &tcb_emlrtRSI;
      power(&b_st, scaleFactors, f_temp);
      b_st.site = &ge_emlrtRSI;
      c_st.site = &ifb_emlrtRSI;
      d_st.site = &jfb_emlrtRSI;
      e_st.site = &kfb_emlrtRSI;
      f_st.site = &od_emlrtRSI;
      g_st.site = &pd_emlrtRSI;
      h_st.site = &rd_emlrtRSI;
      g_st.site = &qd_emlrtRSI;
      h_st.site = &td_emlrtRSI;
      i_st.site = &sd_emlrtRSI;
      xp.set_size(&ef_emlrtRTEI, &i_st, f_temp.size(0));
      nx = f_temp.size(0);
      h_st.site = &lfb_emlrtRSI;
      if ((1 <= f_temp.size(0)) && (f_temp.size(0) > 2147483646)) {
        i_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        xp[loop_ub] =
            muDoubleScalarMax(2.2204460492503131E-16, f_temp[loop_ub]);
      }
      st.site = &tcb_emlrtRSI;
      f_temp.set_size(&ic_emlrtRTEI, &st, gradf.size(0));
      loop_ub = gradf.size(0);
      for (i = 0; i < loop_ub; i++) {
        f_temp[i] = -gradf[i] / (b_gamma + 1.0);
      }
      b_st.site = &ti_emlrtRSI;
      c_st.site = &ui_emlrtRSI;
      if (f_temp.size(0) != xp.size(0)) {
        emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI, "MATLAB:dimagree",
                                      "MATLAB:dimagree", 0);
      }
      loop_ub = f_temp.size(0);
      for (i = 0; i < loop_ub; i++) {
        f_temp[i] = f_temp[i] / xp[i];
      }
      st.site = &tcb_emlrtRSI;
      projSteepestDescentInfNorm = b_projectBox(&st, x, f_temp, hasLB, hasUB);
      st.site = &tcb_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (nx = 0; nx < n; nx++) {
        if (nx + 1 > hasLB.size(0)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, hasLB.size(0), &ju_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (hasLB[nx]) {
          if (nx + 1 > x.size(0)) {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, x.size(0), &ju_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, 0, &ku_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (nx + 1 > hasUB.size(0)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, hasUB.size(0), &ju_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (hasUB[nx]) {
          if (nx + 1 > indActive.size(0)) {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, indActive.size(0),
                                          &ju_emlrtBCI, (emlrtCTX)sp);
          }
          if (indActive[nx]) {
            if (nx + 1 > indActive.size(0)) {
              emlrtDynamicBoundsCheckR2012b(nx + 1, 1, indActive.size(0),
                                            &ju_emlrtBCI, (emlrtCTX)sp);
            }
            indActive[nx] = true;
          } else {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, 0, &ku_emlrtBCI,
                                          (emlrtCTX)sp);
          }
        }
        if (nx + 1 > indActive.size(0)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, indActive.size(0),
                                        &ju_emlrtBCI, (emlrtCTX)sp);
        }
        if (indActive[nx]) {
          st.site = &tcb_emlrtRSI;
          internal::blas::xcopy(&st, m_temp, augJacobian,
                                (m_temp + n) * nx + 1);
        }
      }
    }
    st.site = &tcb_emlrtRSI;
    linearLeastSquares(&st, augJacobian, rhs, dx, m_temp + n, n);
    if (hasFiniteBounds) {
      st.site = &tcb_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (nx = 0; nx < n; nx++) {
        if (nx + 1 > indActive.size(0)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, indActive.size(0),
                                        &ju_emlrtBCI, (emlrtCTX)sp);
        }
        if (indActive[nx]) {
          st.site = &tcb_emlrtRSI;
          if (nx + 1 > n) {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, n, &ju_emlrtBCI, &st);
          }
          b_st.site = &ed_emlrtRSI;
          c_st.site = &fd_emlrtRSI;
          if (nx + 1 > gradf.size(0)) {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, gradf.size(0),
                                          &ju_emlrtBCI, (emlrtCTX)sp);
          }
          if (nx + 1 > dx.size(0)) {
            emlrtDynamicBoundsCheckR2012b(nx + 1, 1, dx.size(0), &ju_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          dx[nx] = -gradf[nx] / (b_gamma + 1.0);
        }
      }
      if (x.size(0) != dx.size(0)) {
        emlrtSizeEqCheck1DR2012b(x.size(0), dx.size(0), &bd_emlrtECI,
                                 (emlrtCTX)sp);
      }
      xp.set_size(&ic_emlrtRTEI, sp, x.size(0));
      loop_ub = x.size(0);
      for (i = 0; i < loop_ub; i++) {
        xp[i] = x[i] + dx[i];
      }
      st.site = &tcb_emlrtRSI;
      c_projectBox(&st, xp, hasLB, hasUB);
    } else {
      if (x.size(0) != dx.size(0)) {
        emlrtSizeEqCheck1DR2012b(x.size(0), dx.size(0), &bd_emlrtECI,
                                 (emlrtCTX)sp);
      }
      xp.set_size(&ic_emlrtRTEI, sp, x.size(0));
      loop_ub = x.size(0);
      for (i = 0; i < loop_ub; i++) {
        xp[i] = x[i] + dx[i];
      }
    }
    st.site = &tcb_emlrtRSI;
    b_st.site = &rcb_emlrtRSI;
    calibrateOneCamera_v2_anonFcn1(&b_st, &fun->workspace.initialParams,
                                   fun->workspace.world_points,
                                   fun->workspace.image_points, xp, f_temp);
    st.site = &tcb_emlrtRSI;
    if ((1 <= m_temp) && (m_temp > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (nx = 0; nx <= m; nx++) {
      if (nx + 1 > f_temp.size(0)) {
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, f_temp.size(0), &ju_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (nx + 1 > fNew.size(0)) {
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, fNew.size(0), &ju_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      fNew[nx] = f_temp[nx];
    }
    st.site = &tcb_emlrtRSI;
    resnormNew = internal::blas::xdot(m_temp, fNew, fNew);
    st.site = &tcb_emlrtRSI;
    evalOK = validate::checkFinite(&st, fNew, m_temp);
    funcCount++;
    guard1 = false;
    if ((resnormNew < *resnorm) && evalOK) {
      iter++;
      funDiff = muDoubleScalarAbs(resnormNew - *resnorm) / *resnorm;
      *resnorm = resnormNew;
      fCurrent.set_size(&ic_emlrtRTEI, sp, fNew.size(0));
      loop_ub = fNew.size(0);
      for (i = 0; i < loop_ub; i++) {
        fCurrent[i] = fNew[i];
      }
      st.site = &tcb_emlrtRSI;
      evalOK = b_jacobianFiniteDifference(
          &st, augJacobian, fCurrent, &funcCount, xp, t8_FiniteDifferenceType,
          TypicalX, &FiniteDifferences, c_finiteDifferenceRunTimeOption,
          d_finiteDifferenceRunTimeOption);
      st.site = &tcb_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (nx = 0; nx < n; nx++) {
        st.site = &tcb_emlrtRSI;
        internal::blas::xcopy(m_temp, augJacobian, (m_temp + n) * nx + 1,
                              jacobian, m_temp * nx + 1);
      }
      if (evalOK) {
        if (x.size(0) != xp.size(0)) {
          emlrtSubAssignSizeCheck1dR2017a(x.size(0), xp.size(0), &bd_emlrtECI,
                                          (emlrtCTX)sp);
        }
        x.set_size(&ic_emlrtRTEI, sp, xp.size(0));
        loop_ub = xp.size(0);
        for (i = 0; i < loop_ub; i++) {
          x[i] = xp[i];
        }
        if (stepSuccessful) {
          b_gamma *= 0.1;
        }
        stepSuccessful = true;
        guard1 = true;
      } else {
        b_exitflag = 2;
        st.site = &tcb_emlrtRSI;
        internal::blas::xcopy(&st, m_temp * n, jacobian);
        exitg1 = true;
      }
    } else {
      b_gamma *= 10.0;
      stepSuccessful = false;
      if (1 > m_temp) {
        loop_ub = 0;
      } else {
        if (1 > augJacobian.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, augJacobian.size(0), &ju_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (m_temp > augJacobian.size(0)) {
          emlrtDynamicBoundsCheckR2012b(m_temp, 1, augJacobian.size(0),
                                        &ju_emlrtBCI, (emlrtCTX)sp);
        }
        loop_ub = m_temp;
      }
      r.set_size(&ic_emlrtRTEI, sp, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r[i] = i;
      }
      loop_ub = augJacobian.size(1);
      r1.set_size(&ic_emlrtRTEI, sp, augJacobian.size(1));
      for (i = 0; i < loop_ub; i++) {
        r1[i] = i;
      }
      b_iv[0] = r.size(0);
      b_iv[1] = r1.size(0);
      emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, jacobian.size(), 2,
                                    &bd_emlrtECI, (emlrtCTX)sp);
      loop_ub = jacobian.size(1);
      for (i = 0; i < loop_ub; i++) {
        nx = jacobian.size(0);
        for (b_exitflag = 0; b_exitflag < nx; b_exitflag++) {
          augJacobian[r[b_exitflag] + augJacobian.size(0) * r1[i]] =
              jacobian[b_exitflag + jacobian.size(0) * i];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      st.site = &tcb_emlrtRSI;
      if (b_gamma < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &x_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      resnormNew = muDoubleScalarSqrt(b_gamma);
      st.site = &tcb_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (nx = 0; nx < n; nx++) {
        st.site = &tcb_emlrtRSI;
        internal::blas::xcopy(&st, n, augJacobian,
                              ((m_temp + n) * (nx + 1) - n) + 1);
        i = (m_temp + nx) + 1;
        if ((i < 1) || (i > augJacobian.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, augJacobian.size(0), &ju_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (nx + 1 > augJacobian.size(1)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, augJacobian.size(1),
                                        &ju_emlrtBCI, (emlrtCTX)sp);
        }
        augJacobian[(i + augJacobian.size(0) * nx) - 1] = resnormNew;
      }
      st.site = &tcb_emlrtRSI;
      internal::blas::xgemv(m_temp, n, jacobian, m_temp, fCurrent, gradf);
      f_temp.set_size(&ic_emlrtRTEI, sp, gradf.size(0));
      loop_ub = gradf.size(0);
      for (i = 0; i < loop_ub; i++) {
        f_temp[i] = -gradf[i];
      }
      st.site = &tcb_emlrtRSI;
      projSteepestDescentInfNorm = b_projectBox(&st, x, f_temp, hasLB, hasUB);
      st.site = &tcb_emlrtRSI;
      b_exitflag = b_checkStoppingCriteria(
          static_cast<real_T>(options_MaxFunctionEvaluations), gradf, relFactor,
          funDiff, x, dx, funcCount, stepSuccessful, &iter,
          projSteepestDescentInfNorm, hasFiniteBounds);
      if (b_exitflag != -5) {
        exitg1 = true;
      }
    }
  }
  st.site = &tcb_emlrtRSI;
  *output_firstorderopt =
      computeFirstOrderOpt(gradf, hasFiniteBounds, &projSteepestDescentInfNorm);
  st.site = &tcb_emlrtRSI;
  *output_stepsize = b_norm(dx);
  lambda_lower.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    lambda_lower[i] = 0.0;
  }
  lambda_upper.set_size(&ic_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    lambda_upper[i] = 0.0;
  }
  if (hasFiniteBounds) {
    st.site = &tcb_emlrtRSI;
    b_st.site = &tcb_emlrtRSI;
    power(&b_st, scaleFactors, f_temp);
    b_st.site = &ge_emlrtRSI;
    c_st.site = &ifb_emlrtRSI;
    d_st.site = &jfb_emlrtRSI;
    e_st.site = &kfb_emlrtRSI;
    f_st.site = &od_emlrtRSI;
    g_st.site = &pd_emlrtRSI;
    h_st.site = &rd_emlrtRSI;
    g_st.site = &qd_emlrtRSI;
    h_st.site = &td_emlrtRSI;
    i_st.site = &sd_emlrtRSI;
    xp.set_size(&ef_emlrtRTEI, &i_st, f_temp.size(0));
    nx = f_temp.size(0);
    h_st.site = &lfb_emlrtRSI;
    if ((1 <= f_temp.size(0)) && (f_temp.size(0) > 2147483646)) {
      i_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&i_st);
    }
    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      xp[loop_ub] = muDoubleScalarMax(2.2204460492503131E-16, f_temp[loop_ub]);
    }
    st.site = &tcb_emlrtRSI;
    f_temp.set_size(&ic_emlrtRTEI, &st, gradf.size(0));
    loop_ub = gradf.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = -gradf[i] / (b_gamma + 1.0);
    }
    b_st.site = &ti_emlrtRSI;
    c_st.site = &ui_emlrtRSI;
    if (f_temp.size(0) != xp.size(0)) {
      emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI, "MATLAB:dimagree",
                                    "MATLAB:dimagree", 0);
    }
    loop_ub = f_temp.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = f_temp[i] / xp[i];
    }
    st.site = &tcb_emlrtRSI;
    b_projectBox(&st, x, f_temp, hasLB, hasUB);
    st.site = &tcb_emlrtRSI;
    if ((1 <= x0.size(0)) && (x0.size(0) > 2147483646)) {
      b_st.site = &yc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (nx = 0; nx < n; nx++) {
      if (nx + 1 > hasLB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, hasLB.size(0), &ju_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (hasLB[nx]) {
        if (nx + 1 > x.size(0)) {
          emlrtDynamicBoundsCheckR2012b(nx + 1, 1, x.size(0), &ju_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, 0, &ku_emlrtBCI, (emlrtCTX)sp);
      }
      if (nx + 1 > hasUB.size(0)) {
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, hasUB.size(0), &ju_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (hasUB[nx]) {
        emlrtDynamicBoundsCheckR2012b(nx + 1, 1, 0, &ku_emlrtBCI, (emlrtCTX)sp);
      }
    }
  }
  *exitflag = b_exitflag;
  *output_iterations = iter;
  *output_funcCount = funcCount;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void driver_anonFcn1(const emlrtStack *sp, const anonymous_function *fun,
                     const ::coder::array<real_T, 1U> &x,
                     ::coder::array<real_T, 1U> &varargout_2)
{
  array<real_T, 2U> b_fun;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &tcb_emlrtRSI;
  b_st.site = &rcb_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 5);
  b_fun.set_size(&ev_emlrtRTEI, &b_st, fun->workspace.world_points.size(0),
                 fun->workspace.world_points.size(1));
  nx = fun->workspace.world_points.size(0) *
           fun->workspace.world_points.size(1) -
       1;
  for (n = 0; n <= nx; n++) {
    b_fun[n] = fun->workspace.world_points[n];
  }
  c_st.site = &vcb_emlrtRSI;
  reprojectWrapper(&c_st, x, &fun->workspace.initialParams, b_fun,
                   fun->workspace.image_points, varargout_2);
  st.site = &tcb_emlrtRSI;
  nx = varargout_2.size(0);
  b_st.site = &lp_emlrtRSI;
  n = varargout_2.size(0);
  if (1 > varargout_2.size(0)) {
    n = 1;
  }
  nx = muIntScalarMax_sint32(nx, n);
  if (varargout_2.size(0) > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &qb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (1 > nx) {
    emlrtErrorWithMessageIdR2018a(&st, &qb_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder

// End of code generation (driver.cpp)
