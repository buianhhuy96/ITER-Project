//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// normalizeControlPoints.cpp
//
// Code generation for function 'normalizeControlPoints'
//

// Include files
#include "normalizeControlPoints.h"
#include "calibrateOneCamera_v2_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "hypot.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo nl_emlrtRSI{
    53,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo ox_emlrtRSI{
    21,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo px_emlrtRSI{
    26,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo qx_emlrtRSI{
    28,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo rx_emlrtRSI{
    31,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo sx_emlrtRSI{
    41,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo tx_emlrtRSI{
    50,                 // lineNo
    "sumMatrixColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtBCInfo yt_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    28,                       // lineNo
    61,                       // colNo
    "",                       // aName
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m", // pName
    0                                     // checkKind
};

static emlrtBCInfo au_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    28,                       // lineNo
    74,                       // colNo
    "",                       // aName
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m", // pName
    0                                     // checkKind
};

static emlrtBCInfo bu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    48,                       // lineNo
    10,                       // colNo
    "",                       // aName
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m", // pName
    0                                     // checkKind
};

static emlrtBCInfo cu_emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    48,                       // lineNo
    24,                       // colNo
    "",                       // aName
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m", // pName
    0                                     // checkKind
};

static emlrtRTEInfo yr_emlrtRTEI{
    35,                    // lineNo
    20,                    // colNo
    "sumMatrixIncludeNaN", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pName
};

static emlrtRTEInfo as_emlrtRTEI{
    74,                      // lineNo
    9,                       // colNo
    "combineVectorElements", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pName
};

static emlrtRTEInfo bs_emlrtRTEI{
    21,                       // lineNo
    1,                        // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

static emlrtRTEInfo cs_emlrtRTEI{
    28,                       // lineNo
    51,                       // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

static emlrtRTEInfo ds_emlrtRTEI{
    28,                       // lineNo
    64,                       // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

// Function Definitions
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void normalizeControlPoints(const emlrtStack *sp,
                            const ::coder::array<real_T, 2U> &pts,
                            ::coder::array<real_T, 2U> &ptsNorm,
                            real_T normMatrixInv[9])
{
  array<real_T, 2U> cent;
  array<real_T, 1U> b_ptsNorm;
  array<real_T, 1U> c_ptsNorm;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  real_T s;
  int32_T acoef;
  int32_T bcoef;
  int32_T csz_idx_1;
  int32_T inb;
  int32_T ncols;
  int32_T nfb;
  int32_T nleft;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &ox_emlrtRSI;
  b_st.site = &il_emlrtRSI;
  c_st.site = &jl_emlrtRSI;
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    cent.set_size(&as_emlrtRTEI, &c_st, 1, pts.size(1));
    ncols = pts.size(1);
    for (nfb = 0; nfb < ncols; nfb++) {
      cent[nfb] = 0.0;
    }
  } else {
    d_st.site = &cr_emlrtRSI;
    e_st.site = &ll_emlrtRSI;
    cent.set_size(&yr_emlrtRTEI, &e_st, 1, pts.size(1));
    ncols = pts.size(1) - 1;
    if (pts.size(0) < 4096) {
      f_st.site = &sx_emlrtRSI;
      if (pts.size(1) > 2147483646) {
        g_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      for (acoef = 0; acoef <= ncols; acoef++) {
        f_st.site = &ml_emlrtRSI;
        cent[acoef] = sumColumnB(&f_st, pts, acoef + 1, pts.size(0));
      }
    } else {
      nfb = pts.size(0) / 4096;
      inb = nfb << 12;
      nleft = pts.size(0) - inb;
      f_st.site = &tx_emlrtRSI;
      if (pts.size(1) > 2147483646) {
        g_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      for (acoef = 0; acoef <= ncols; acoef++) {
        s = sumColumnB4(pts, acoef + 1, 1);
        f_st.site = &nl_emlrtRSI;
        for (bcoef = 2; bcoef <= nfb; bcoef++) {
          s += sumColumnB4(pts, acoef + 1, ((bcoef - 1) << 12) + 1);
        }
        if (nleft > 0) {
          f_st.site = &ol_emlrtRSI;
          s += sumColumnB(&f_st, pts, acoef + 1, nleft, inb + 1);
        }
        cent[acoef] = s;
      }
    }
  }
  cent.set_size(&bs_emlrtRTEI, &st, 1, cent.size(1));
  ncols = cent.size(1) - 1;
  for (nfb = 0; nfb <= ncols; nfb++) {
    cent[nfb] = cent[nfb] / static_cast<real_T>(pts.size(0));
  }
  st.site = &px_emlrtRSI;
  if (cent.size(1) == 1) {
    csz_idx_1 = pts.size(1);
  } else if (pts.size(1) == 1) {
    csz_idx_1 = cent.size(1);
  } else if (pts.size(1) == cent.size(1)) {
    csz_idx_1 = pts.size(1);
  } else {
    emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  ptsNorm.set_size(&ag_emlrtRTEI, &st, pts.size(0), csz_idx_1);
  if ((pts.size(0) != 0) && (csz_idx_1 != 0)) {
    b_st.site = &hi_emlrtRSI;
    acoef = (pts.size(1) != 1);
    bcoef = (cent.size(1) != 1);
    ncols = csz_idx_1 - 1;
    c_st.site = &ii_emlrtRSI;
    for (int32_T k{0}; k <= ncols; k++) {
      nfb = acoef * k;
      inb = bcoef * k;
      c_st.site = &ji_emlrtRSI;
      nleft = (pts.size(0) != 1);
      csz_idx_1 = ptsNorm.size(0) - 1;
      d_st.site = &ii_emlrtRSI;
      for (int32_T b_k{0}; b_k <= csz_idx_1; b_k++) {
        ptsNorm[b_k + ptsNorm.size(0) * k] =
            pts[nleft * b_k + pts.size(0) * nfb] - cent[inb];
      }
    }
  }
  st.site = &qx_emlrtRSI;
  if (1 > ptsNorm.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, ptsNorm.size(1), &yt_emlrtBCI, &st);
  }
  if (2 > ptsNorm.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, ptsNorm.size(1), &au_emlrtBCI, &st);
  }
  ncols = ptsNorm.size(0);
  b_ptsNorm.set_size(&cs_emlrtRTEI, &st, ptsNorm.size(0));
  for (nfb = 0; nfb < ncols; nfb++) {
    b_ptsNorm[nfb] = ptsNorm[nfb];
  }
  ncols = ptsNorm.size(0);
  c_ptsNorm.set_size(&ds_emlrtRTEI, &st, ptsNorm.size(0));
  for (nfb = 0; nfb < ncols; nfb++) {
    c_ptsNorm[nfb] = ptsNorm[nfb + ptsNorm.size(0)];
  }
  b_st.site = &qx_emlrtRSI;
  b_hypot(&b_st, b_ptsNorm, c_ptsNorm, r);
  b_st.site = &qx_emlrtRSI;
  power(&b_st, r, b_ptsNorm);
  b_st.site = &xo_emlrtRSI;
  c_st.site = &yo_emlrtRSI;
  d_st.site = &jl_emlrtRSI;
  if (b_ptsNorm.size(0) == 0) {
    s = 0.0;
  } else {
    e_st.site = &cr_emlrtRSI;
    f_st.site = &ll_emlrtRSI;
    s = sumMatrixColumns(&f_st, b_ptsNorm, b_ptsNorm.size(0));
  }
  if (s > 0.0) {
    st.site = &rx_emlrtRSI;
    st.site = &rx_emlrtRSI;
    s = muDoubleScalarSqrt(2.0 * static_cast<real_T>(pts.size(0))) /
        muDoubleScalarSqrt(s);
  } else {
    s = 1.0;
  }
  ncols = ptsNorm.size(0) * ptsNorm.size(1);
  for (nfb = 0; nfb < ncols; nfb++) {
    ptsNorm[nfb] = ptsNorm[nfb] * s;
  }
  if (1 > cent.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cent.size(1), &bu_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > cent.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, cent.size(1), &cu_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  normMatrixInv[0] = 1.0 / s;
  normMatrixInv[3] = 0.0;
  normMatrixInv[6] = 0.0;
  normMatrixInv[1] = 0.0;
  normMatrixInv[4] = 1.0 / s;
  normMatrixInv[7] = 0.0;
  normMatrixInv[2] = cent[0];
  normMatrixInv[5] = cent[1];
  normMatrixInv[8] = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace internal
} // namespace geotrans
} // namespace images
} // namespace coder

// End of code generation (normalizeControlPoints.cpp)
