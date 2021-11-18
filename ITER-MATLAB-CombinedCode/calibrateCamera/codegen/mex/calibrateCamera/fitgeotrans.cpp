//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fitgeotrans.cpp
//
// Code generation for function 'fitgeotrans'
//

// Include files
#include "fitgeotrans.h"
#include "calibrateCamera_data.h"
#include "det.h"
#include "inv.h"
#include "mldivide.h"
#include "normalizeControlPoints.h"
#include "projective2d.h"
#include "rank.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo kt_emlrtRSI{
    85,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo lt_emlrtRSI{
    86,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo mt_emlrtRSI{
    99,                        // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo nt_emlrtRSI{
    100,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo ot_emlrtRSI{
    103,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo pt_emlrtRSI{
    106,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo qt_emlrtRSI{
    113,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo rt_emlrtRSI{
    115,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo st_emlrtRSI{
    118,                       // lineNo
    "findProjectiveTransform", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pathName
};

static emlrtRSInfo au_emlrtRSI{
    11,     // lineNo
    "rank", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\matfun\\rank.m" // pathName
};

static emlrtRSInfo
    gv_emlrtRSI{
        113,                         // lineNo
        "projective2d/projective2d", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    hv_emlrtRSI{
        332,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRSInfo
    iv_emlrtRSI{
        338,                  // lineNo
        "projective2d/set.T", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pathName
    };

static emlrtRTEInfo
    vb_emlrtRTEI{
        338,                  // lineNo
        13,                   // colNo
        "projective2d/set.T", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\projective2d.m" // pName
    };

static emlrtECInfo bd_emlrtECI{
    -1,                        // nDims
    106,                       // lineNo
    1,                         // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    103,                       // lineNo
    23,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo cd_emlrtECI{
    -1,                        // nDims
    100,                       // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtECInfo dd_emlrtECI{
    -1,                        // nDims
    99,                        // lineNo
    48,                        // colNo
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtBCInfo ft_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    91,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtBCInfo gt_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    90,                        // lineNo
    10,                        // colNo
    "",                        // aName
    "findProjectiveTransform", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m", // pName
    0 // checkKind
};

static emlrtRTEInfo vp_emlrtRTEI{
    99,            // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo wp_emlrtRTEI{
    100,           // lineNo
    48,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo xp_emlrtRTEI{
    99,            // lineNo
    1,             // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

static emlrtRTEInfo yp_emlrtRTEI{
    106,           // lineNo
    13,            // colNo
    "fitgeotrans", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\fitgeotrans.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
void findProjectiveTransform(const emlrtStack *sp,
                             const ::coder::array<real_T, 2U> &uv,
                             const ::coder::array<real_T, 2U> &xy,
                             projective2d *tform)
{
  ::coder::array<real_T, 2U> b_X;
  ::coder::array<real_T, 2U> b_uv;
  ::coder::array<real_T, 2U> b_xy;
  ::coder::array<real_T, 1U> b_varargin_7;
  ::coder::array<real_T, 1U> b_varargin_8;
  ::coder::array<real_T, 1U> varargin_7;
  ::coder::array<real_T, 1U> varargin_8;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T Tvec[9];
  real_T b_Tvec[9];
  real_T normMatrix2[9];
  real_T b_tform;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T irank;
  int32_T loop_ub;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &kt_emlrtRSI;
  images::geotrans::internal::normalizeControlPoints(&st, uv, b_uv, tform->T);
  st.site = &lt_emlrtRSI;
  images::geotrans::internal::b_normalizeControlPoints(&st, xy, b_xy,
                                                       normMatrix2);
  if (1 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, b_xy.size(1), &gt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > b_xy.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, b_xy.size(1), &ft_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  varargin_8.set_size(&vp_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    varargin_8[i] = -b_uv[i];
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(varargin_8.size(0), b_xy.size(0), &dd_emlrtECI,
                             (emlrtCTX)sp);
  }
  irank = b_uv.size(0);
  b_varargin_8.set_size(&wp_emlrtRTEI, sp, b_uv.size(0));
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = -b_uv[i + b_uv.size(0)];
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtSizeEqCheck1DR2012b(b_varargin_8.size(0), b_xy.size(0), &cd_emlrtECI,
                             (emlrtCTX)sp);
  }
  st.site = &mt_emlrtRSI;
  varargin_7.set_size(&vp_emlrtRTEI, &st, varargin_8.size(0));
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_7[i] = varargin_8[i] * b_xy[i];
  }
  irank = varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    varargin_8[i] = varargin_8[i] * b_xy[i + b_xy.size(0)];
  }
  b_st.site = &kn_emlrtRSI;
  c_st.site = &ln_emlrtRSI;
  if (varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  st.site = &nt_emlrtRSI;
  b_varargin_7.set_size(&wp_emlrtRTEI, &st, b_varargin_8.size(0));
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_7[i] = b_varargin_8[i] * b_xy[i];
  }
  irank = b_varargin_8.size(0);
  for (i = 0; i < irank; i++) {
    b_varargin_8[i] = b_varargin_8[i] * b_xy[i + b_xy.size(0)];
  }
  b_st.site = &kn_emlrtRSI;
  c_st.site = &ln_emlrtRSI;
  if (b_varargin_7.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if (b_varargin_8.size(0) != b_xy.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  irank = b_xy.size(0);
  loop_ub = b_xy.size(0);
  b_loop_ub = b_xy.size(0);
  c_loop_ub = b_xy.size(0);
  b_X.set_size(&xp_emlrtRTEI, sp, b_xy.size(0) + b_xy.size(0), 8);
  for (i = 0; i < irank; i++) {
    b_X[i] = b_xy[i];
  }
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0)] = b_xy[i + b_xy.size(0)];
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 2] = 1.0;
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 3] = 0.0;
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 4] = 0.0;
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 5] = 0.0;
  }
  loop_ub = varargin_7.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 6] = varargin_7[i];
  }
  loop_ub = varargin_8.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + b_X.size(0) * 7] = varargin_8[i];
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[i + irank] = 0.0;
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0)] = 0.0;
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 2] = 0.0;
  }
  for (i = 0; i < b_loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 3] = b_xy[i];
  }
  for (i = 0; i < c_loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 4] = b_xy[i + b_xy.size(0)];
  }
  loop_ub = b_xy.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 5] = 1.0;
  }
  loop_ub = b_varargin_7.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 6] = b_varargin_7[i];
  }
  loop_ub = b_varargin_8.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_X[(i + irank) + b_X.size(0) * 7] = b_varargin_8[i];
  }
  st.site = &ot_emlrtRSI;
  b_st.site = &au_emlrtRSI;
  irank = local_rank(&b_st, b_X);
  if (irank < 8) {
    emlrtErrorWithMessageIdR2018a(sp, &wb_emlrtRTEI,
                                  "images:geotrans:requiredNonCollinearPoints",
                                  "images:geotrans:requiredNonCollinearPoints",
                                  5, 6, 4.0, 4, 10, "projective");
  }
  irank = b_uv.size(0);
  loop_ub = b_uv.size(0);
  varargin_7.set_size(&yp_emlrtRTEI, sp, b_uv.size(0) + b_uv.size(0));
  for (i = 0; i < irank; i++) {
    varargin_7[i] = b_uv[i];
  }
  for (i = 0; i < loop_ub; i++) {
    varargin_7[i + irank] = b_uv[i + b_uv.size(0)];
  }
  st.site = &pt_emlrtRSI;
  mldivide(&st, b_X, varargin_7);
  if (8 != varargin_7.size(0)) {
    emlrtSubAssignSizeCheck1dR2017a(8, varargin_7.size(0), &bd_emlrtECI,
                                    (emlrtCTX)sp);
  }
  for (i = 0; i < 8; i++) {
    Tvec[i] = varargin_7[i];
  }
  Tvec[8] = 1.0;
  for (i = 0; i < 3; i++) {
    real_T d;
    real_T d1;
    b_tform = Tvec[i];
    d = Tvec[i + 3];
    d1 = Tvec[i + 6];
    for (irank = 0; irank < 3; irank++) {
      b_Tvec[i + 3 * irank] =
          (b_tform * tform->T[3 * irank] + d * tform->T[3 * irank + 1]) +
          d1 * tform->T[3 * irank + 2];
    }
  }
  st.site = &qt_emlrtRSI;
  mldivide(&st, normMatrix2, b_Tvec, Tvec);
  st.site = &rt_emlrtRSI;
  inv(&st, Tvec, tform->T);
  b_tform = tform->T[8];
  for (i = 0; i < 9; i++) {
    tform->T[i] /= b_tform;
  }
  st.site = &st_emlrtRSI;
  b_st.site = &gv_emlrtRSI;
  c_st.site = &hv_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  p = true;
  irank = 0;
  exitg1 = false;
  while ((!exitg1) && (irank < 9)) {
    if ((!muDoubleScalarIsInf(tform->T[irank])) &&
        (!muDoubleScalarIsNaN(tform->T[irank]))) {
      irank++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &g_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:projective2d:set:T:expectedFinite", 3, 4, 1, "T");
  }
  d_st.site = &v_emlrtRSI;
  p = true;
  irank = 0;
  exitg1 = false;
  while ((!exitg1) && (irank < 9)) {
    if (!muDoubleScalarIsNaN(tform->T[irank])) {
      irank++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:projective2d:set:T:expectedNonNaN", 3, 4, 1, "T");
  }
  c_st.site = &iv_emlrtRSI;
  b_tform = det(&c_st, tform->T);
  if (b_tform == 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &vb_emlrtRTEI, "images:geotrans:singularTransformationMatrix",
        "images:geotrans:singularTransformationMatrix", 0);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder
} // namespace Codegen

// End of code generation (fitgeotrans.cpp)
