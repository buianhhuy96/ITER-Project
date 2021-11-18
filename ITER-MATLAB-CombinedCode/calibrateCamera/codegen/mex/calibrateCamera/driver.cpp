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
#include "CalculateCost.h"
#include "anonymous_function.h"
#include "anonymous_function1.h"
#include "calibrateCamera.h"
#include "calibrateCamera_data.h"
#include "calibrateCamera_internal_types.h"
#include "calibrateCamera_internal_types1.h"
#include "calibrateCamera_internal_types11.h"
#include "calibrateCamera_internal_types2.h"
#include "calibrateCamera_types.h"
#include "checkFinite.h"
#include "checkStoppingCriteria.h"
#include "eml_int_forloop_overflow_check.h"
#include "factoryConstruct.h"
#include "jacobianFiniteDifference.h"
#include "linearLeastSquares.h"
#include "projectBox.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "xdot.h"
#include "xgemv.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo co_emlrtRSI{
    29,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo uy_emlrtRSI{
    1,        // lineNo
    "driver", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pathName
};

static emlrtRSInfo jab_emlrtRSI{
    44,      // lineNo
    "xcopy", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xcopy."
    "m" // pathName
};

static emlrtRTEInfo ac_emlrtRTEI{
    1,        // lineNo
    1,        // colNo
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pName
};

static emlrtBCInfo vt_emlrtBCI{
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

static emlrtECInfo rd_emlrtECI{
    -1,       // nDims
    1,        // lineNo
    1,        // colNo
    "driver", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\optim\\+optim\\+coder\\+"
    "levenbergMarquardt\\driver.p" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace optim {
namespace coder {
namespace levenbergMarquardt {
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
  static const char_T t7_FiniteDifferenceType[7]{'f', 'o', 'r', 'w',
                                                 'a', 'r', 'd'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  b_anonymous_function b_this;
  ::coder::array<real_T, 2U> augJacobian;
  ::coder::array<real_T, 1U> TypicalX;
  ::coder::array<real_T, 1U> c_finiteDifferenceRunTimeOption;
  ::coder::array<real_T, 1U> d_finiteDifferenceRunTimeOption;
  ::coder::array<real_T, 1U> dx;
  ::coder::array<real_T, 1U> fNew;
  ::coder::array<real_T, 1U> f_temp;
  ::coder::array<real_T, 1U> gradf;
  ::coder::array<real_T, 1U> rhs;
  ::coder::array<real_T, 1U> xp;
  ::coder::array<boolean_T, 1U> hasLB;
  ::coder::array<boolean_T, 1U> hasUB;
  d_struct_T FiniteDifferences;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T absx;
  real_T b_gamma;
  real_T funDiff;
  real_T resnormNew;
  int32_T iv[2];
  int32_T funcCount;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T iter;
  int32_T loop_ub;
  int32_T m;
  int32_T m_temp;
  int32_T n;
  int32_T options_MaxFunctionEvaluations;
  boolean_T evalOK;
  boolean_T exitg1;
  boolean_T stepSuccessful;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  for (i = 0; i < 19; i++) {
    output_algorithm[i] = b_cv[i];
  }
  n = x0.size(0);
  gradf.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  dx.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    dx[i] = rtInf;
  }
  funDiff = rtInf;
  iter = 0;
  options_MaxFunctionEvaluations = 200 * x0.size(0);
  TypicalX.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    TypicalX[i] = 1.0;
  }
  hasLB.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  hasUB.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  st.site = &uy_emlrtRSI;
  for (idx = 1; idx <= x0.size(0); idx++) {
    if ((idx < 1) || (idx > hasLB.size(0))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, hasLB.size(0), &wt_emlrtBCI, &st);
    }
    hasLB[idx - 1] = false;
    if (idx > hasUB.size(0)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, hasUB.size(0), &wt_emlrtBCI, &st);
    }
    hasUB[idx - 1] = false;
  }
  x.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = x0[i];
  }
  st.site = &uy_emlrtRSI;
  b_st.site = &sy_emlrtRSI;
  calibrateCamera_anonFcn1(&b_st, &fun->workspace.calibration.CameraParameters,
                           fun->workspace.calibration.PatternPositions,
                           fun->workspace.calibration.ImagePoints,
                           fun->workspace.genPoints, fun->workspace.detPoints,
                           x0, f_temp);
  m_temp = f_temp.size(0);
  jacobian.set_size(&ac_emlrtRTEI, sp, f_temp.size(0), x0.size(0));
  m = f_temp.size(0);
  fCurrent.set_size(&ac_emlrtRTEI, sp, f_temp.size(0));
  fNew.set_size(&ac_emlrtRTEI, sp, f_temp.size(0));
  st.site = &uy_emlrtRSI;
  if ((1 <= f_temp.size(0)) && (f_temp.size(0) > 2147483646)) {
    b_st.site = &qc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (idx = 0; idx < m; idx++) {
    if (idx + 1 > f_temp.size(0)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, f_temp.size(0), &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (idx + 1 > fCurrent.size(0)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, fCurrent.size(0), &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    fCurrent[idx] = f_temp[idx];
  }
  augJacobian.set_size(&ac_emlrtRTEI, sp, f_temp.size(0) + x0.size(0),
                       x0.size(0));
  if (1 > f_temp.size(0)) {
    i = 0;
  } else {
    if (f_temp.size(0) > augJacobian.size(0)) {
      emlrtDynamicBoundsCheckR2012b(f_temp.size(0), 1, augJacobian.size(0),
                                    &vt_emlrtBCI, (emlrtCTX)sp);
    }
    i = f_temp.size(0);
  }
  iv[0] = i;
  iv[1] = x0.size(0);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, jacobian.size(), 2, &rd_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    idx = jacobian.size(0);
    for (i1 = 0; i1 < idx; i1++) {
      augJacobian[i1 + augJacobian.size(0) * i] =
          jacobian[i1 + jacobian.size(0) * i];
    }
  }
  rhs.set_size(&ac_emlrtRTEI, sp, f_temp.size(0) + x0.size(0));
  *resnorm = internal::blas::xdot(f_temp.size(0), fCurrent, fCurrent);
  st.site = &uy_emlrtRSI;
  evalOK = validate::checkFinite(&st, fCurrent, f_temp.size(0));
  if (!evalOK) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ac_emlrtRTEI, "optim_codegen:common:NonFiniteInitialObjective",
        "optim_codegen:common:NonFiniteInitialObjective", 0);
  }
  b_this.workspace.fun = *fun;
  st.site = &uy_emlrtRSI;
  utils::FiniteDifferences::factoryConstruct(
      &st, &b_this, x0.size(0), f_temp.size(0), t7_FiniteDifferenceType,
      &FiniteDifferences);
  c_finiteDifferenceRunTimeOption.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    c_finiteDifferenceRunTimeOption[i] = 1.0;
  }
  d_finiteDifferenceRunTimeOption.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    d_finiteDifferenceRunTimeOption[i] = 1.4901161193847656E-8;
  }
  st.site = &uy_emlrtRSI;
  jacobianFiniteDifference(
      &st, augJacobian, fCurrent, x0, t7_FiniteDifferenceType, TypicalX,
      &FiniteDifferences, c_finiteDifferenceRunTimeOption,
      d_finiteDifferenceRunTimeOption, &funcCount, &evalOK);
  b_gamma = 0.01;
  st.site = &uy_emlrtRSI;
  for (idx = 0; idx < n; idx++) {
    st.site = &uy_emlrtRSI;
    internal::blas::xcopy(&st, n, augJacobian,
                          ((m_temp + n) * (idx + 1) - n) + 1);
    i = (m_temp + idx) + 1;
    if ((i < 1) || (i > augJacobian.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, augJacobian.size(0), &vt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (idx + 1 > augJacobian.size(1)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, augJacobian.size(1),
                                    &vt_emlrtBCI, (emlrtCTX)sp);
    }
    augJacobian[(i + augJacobian.size(0) * idx) - 1] = 0.1;
    st.site = &uy_emlrtRSI;
    if (m_temp >= 1) {
      b_st.site = &jab_emlrtRSI;
      n_t = (ptrdiff_t)m_temp;
      incx_t = (ptrdiff_t)1;
      incy_t = (ptrdiff_t)1;
      dcopy(&n_t, &augJacobian[(m_temp + n) * idx], &incx_t,
            &jacobian[m_temp * idx], &incy_t);
    }
  }
  st.site = &uy_emlrtRSI;
  evalOK = validate::checkFinite(&st, augJacobian, f_temp.size(0) + x0.size(0),
                                 x0.size(0));
  if (!evalOK) {
    emlrtErrorWithMessageIdR2018a(
        sp, &ac_emlrtRTEI, "optim_codegen:common:NonFiniteInitialJacobian",
        "optim_codegen:common:NonFiniteInitialJacobian", 0);
  }
  st.site = &uy_emlrtRSI;
  internal::blas::xgemv(f_temp.size(0), x0.size(0), jacobian, f_temp.size(0),
                        fCurrent, gradf);
  f_temp.set_size(&ac_emlrtRTEI, sp, gradf.size(0));
  loop_ub = gradf.size(0);
  for (i = 0; i < loop_ub; i++) {
    f_temp[i] = -gradf[i];
  }
  st.site = &uy_emlrtRSI;
  projectBox(&st, f_temp, hasLB, hasUB);
  resnormNew = 0.0;
  i = gradf.size(0);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    absx = muDoubleScalarAbs(gradf[loop_ub]);
    if (muDoubleScalarIsNaN(absx) || (absx > resnormNew)) {
      resnormNew = absx;
    }
  }
  absx = muDoubleScalarMax(resnormNew, 1.4901161193847656E-8);
  stepSuccessful = true;
  st.site = &uy_emlrtRSI;
  idx =
      checkStoppingCriteria(static_cast<real_T>(options_MaxFunctionEvaluations),
                            gradf, absx, x0, dx, funcCount);
  exitg1 = false;
  while ((!exitg1) && (idx == -5)) {
    boolean_T guard1{false};
    f_temp.set_size(&ac_emlrtRTEI, sp, fCurrent.size(0));
    loop_ub = fCurrent.size(0);
    for (i = 0; i < loop_ub; i++) {
      f_temp[i] = -fCurrent[i];
    }
    st.site = &uy_emlrtRSI;
    internal::blas::xcopy(m_temp, f_temp, rhs);
    st.site = &uy_emlrtRSI;
    internal::blas::xcopy(&st, n, rhs, m_temp + 1);
    st.site = &uy_emlrtRSI;
    linearLeastSquares(&st, augJacobian, rhs, dx, m_temp + n, n);
    if (x.size(0) != dx.size(0)) {
      emlrtSizeEqCheck1DR2012b(x.size(0), dx.size(0), &rd_emlrtECI,
                               (emlrtCTX)sp);
    }
    xp.set_size(&ac_emlrtRTEI, sp, x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      xp[i] = x[i] + dx[i];
    }
    st.site = &uy_emlrtRSI;
    b_st.site = &sy_emlrtRSI;
    covrtLogFcn(&emlrtCoverageInstance, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
    c_st.site = &wy_emlrtRSI;
    CalculateCost(&c_st, xp, &fun->workspace.calibration.CameraParameters,
                  fun->workspace.calibration.PatternPositions,
                  fun->workspace.calibration.ImagePoints,
                  fun->workspace.genPoints, fun->workspace.detPoints, f_temp);
    st.site = &uy_emlrtRSI;
    if ((1 <= m_temp) && (m_temp > 2147483646)) {
      b_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (idx = 0; idx < m; idx++) {
      if (idx + 1 > f_temp.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, f_temp.size(0), &vt_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (idx + 1 > fNew.size(0)) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, fNew.size(0), &vt_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      fNew[idx] = f_temp[idx];
    }
    resnormNew = internal::blas::xdot(m_temp, fNew, fNew);
    st.site = &uy_emlrtRSI;
    evalOK = validate::checkFinite(&st, fNew, m_temp);
    funcCount++;
    guard1 = false;
    if ((resnormNew < *resnorm) && evalOK) {
      iter++;
      funDiff = muDoubleScalarAbs(resnormNew - *resnorm) / *resnorm;
      *resnorm = resnormNew;
      fCurrent.set_size(&ac_emlrtRTEI, sp, fNew.size(0));
      loop_ub = fNew.size(0);
      for (i = 0; i < loop_ub; i++) {
        fCurrent[i] = fNew[i];
      }
      st.site = &uy_emlrtRSI;
      evalOK = b_jacobianFiniteDifference(
          &st, augJacobian, fCurrent, &funcCount, xp, t7_FiniteDifferenceType,
          TypicalX, &FiniteDifferences, c_finiteDifferenceRunTimeOption,
          d_finiteDifferenceRunTimeOption);
      st.site = &uy_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx = 0; idx < n; idx++) {
        st.site = &uy_emlrtRSI;
        if (m_temp >= 1) {
          b_st.site = &jab_emlrtRSI;
          n_t = (ptrdiff_t)m_temp;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)1;
          dcopy(&n_t, &augJacobian[(m_temp + n) * idx], &incx_t,
                &jacobian[m_temp * idx], &incy_t);
        }
      }
      if (evalOK) {
        if (x.size(0) != xp.size(0)) {
          emlrtSubAssignSizeCheck1dR2017a(x.size(0), xp.size(0), &rd_emlrtECI,
                                          (emlrtCTX)sp);
        }
        x.set_size(&ac_emlrtRTEI, sp, xp.size(0));
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
        idx = 2;
        st.site = &uy_emlrtRSI;
        internal::blas::xcopy(&st, m_temp * n, jacobian);
        exitg1 = true;
      }
    } else {
      b_gamma *= 10.0;
      stepSuccessful = false;
      if (1 > m) {
        i = 0;
      } else {
        if ((m_temp < 1) || (m_temp > augJacobian.size(0))) {
          emlrtDynamicBoundsCheckR2012b(m_temp, 1, augJacobian.size(0),
                                        &vt_emlrtBCI, (emlrtCTX)sp);
        }
        i = m_temp;
      }
      iv[0] = i;
      iv[1] = augJacobian.size(1);
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, jacobian.size(), 2, &rd_emlrtECI,
                                    (emlrtCTX)sp);
      loop_ub = jacobian.size(1);
      for (i = 0; i < loop_ub; i++) {
        idx = jacobian.size(0);
        for (i1 = 0; i1 < idx; i1++) {
          augJacobian[i1 + augJacobian.size(0) * i] =
              jacobian[i1 + jacobian.size(0) * i];
        }
      }
      guard1 = true;
    }
    if (guard1) {
      st.site = &uy_emlrtRSI;
      if (b_gamma < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      resnormNew = muDoubleScalarSqrt(b_gamma);
      st.site = &uy_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        b_st.site = &qc_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (idx = 0; idx < n; idx++) {
        st.site = &uy_emlrtRSI;
        internal::blas::xcopy(&st, n, augJacobian,
                              ((m_temp + n) * (idx + 1) - n) + 1);
        i = (m_temp + idx) + 1;
        if ((i < 1) || (i > augJacobian.size(0))) {
          emlrtDynamicBoundsCheckR2012b(i, 1, augJacobian.size(0), &vt_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (idx + 1 > augJacobian.size(1)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, augJacobian.size(1),
                                        &vt_emlrtBCI, (emlrtCTX)sp);
        }
        augJacobian[(i + augJacobian.size(0) * idx) - 1] = resnormNew;
      }
      st.site = &uy_emlrtRSI;
      internal::blas::xgemv(m_temp, n, jacobian, m_temp, fCurrent, gradf);
      f_temp.set_size(&ac_emlrtRTEI, sp, gradf.size(0));
      loop_ub = gradf.size(0);
      for (i = 0; i < loop_ub; i++) {
        f_temp[i] = -gradf[i];
      }
      st.site = &uy_emlrtRSI;
      projectBox(&st, f_temp, hasLB, hasUB);
      st.site = &uy_emlrtRSI;
      idx = b_checkStoppingCriteria(
          static_cast<real_T>(options_MaxFunctionEvaluations), gradf, absx,
          funDiff, x, dx, funcCount, stepSuccessful, &iter);
      if (idx != -5) {
        exitg1 = true;
      }
    }
  }
  resnormNew = 0.0;
  i = gradf.size(0);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    absx = muDoubleScalarAbs(gradf[loop_ub]);
    if (muDoubleScalarIsNaN(absx) || (absx > resnormNew)) {
      resnormNew = absx;
    }
  }
  if (dx.size(0) == 0) {
    *output_stepsize = 0.0;
  } else {
    n_t = (ptrdiff_t)dx.size(0);
    incx_t = (ptrdiff_t)1;
    *output_stepsize = dnrm2(&n_t, &(dx.data())[0], &incx_t);
  }
  lambda_lower.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    lambda_lower[i] = 0.0;
  }
  lambda_upper.set_size(&ac_emlrtRTEI, sp, x0.size(0));
  loop_ub = x0.size(0);
  for (i = 0; i < loop_ub; i++) {
    lambda_upper[i] = 0.0;
  }
  *exitflag = idx;
  *output_iterations = iter;
  *output_funcCount = funcCount;
  *output_firstorderopt = resnormNew;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void driver_anonFcn1(const emlrtStack *sp, const anonymous_function *fun,
                     const ::coder::array<real_T, 1U> &x,
                     ::coder::array<real_T, 1U> &varargout_2)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T n;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uy_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sy_emlrtRSI;
  covrtLogFcn(&emlrtCoverageInstance, 0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
  c_st.site = &wy_emlrtRSI;
  CalculateCost(&c_st, x, &fun->workspace.calibration.CameraParameters,
                fun->workspace.calibration.PatternPositions,
                fun->workspace.calibration.ImagePoints,
                fun->workspace.genPoints, fun->workspace.detPoints,
                varargout_2);
  st.site = &uy_emlrtRSI;
  nx = varargout_2.size(0);
  b_st.site = &co_emlrtRSI;
  n = varargout_2.size(0);
  if (1 > varargout_2.size(0)) {
    n = 1;
  }
  if (varargout_2.size(0) > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &ob_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
}

} // namespace levenbergMarquardt
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace Codegen

// End of code generation (driver.cpp)
