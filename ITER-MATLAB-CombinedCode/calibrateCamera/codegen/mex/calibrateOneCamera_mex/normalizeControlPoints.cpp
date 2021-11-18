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
#include "calibrateOneCamera_mex_data.h"
#include "hypot.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo kt_emlrtRSI{
    21,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo lt_emlrtRSI{
    28,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo mt_emlrtRSI{
    31,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtRSInfo nt_emlrtRSI{
    26,                       // lineNo
    "normalizeControlPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pathName
};

static emlrtBCInfo bt_emlrtBCI{
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

static emlrtBCInfo ct_emlrtBCI{
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

static emlrtBCInfo dt_emlrtBCI{
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

static emlrtBCInfo et_emlrtBCI{
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

static emlrtRTEInfo tp_emlrtRTEI{
    28,                       // lineNo
    51,                       // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

static emlrtRTEInfo up_emlrtRTEI{
    28,                       // lineNo
    64,                       // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

static emlrtRTEInfo vp_emlrtRTEI{
    43,                       // lineNo
    1,                        // colNo
    "normalizeControlPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+geotrans\\+"
    "internal\\normalizeControlPoints.m" // pName
};

// Function Definitions
namespace Codegen {
namespace coder {
namespace images {
namespace geotrans {
namespace internal {
void b_normalizeControlPoints(const emlrtStack *sp,
                              const ::coder::array<real_T, 2U> &pts,
                              ::coder::array<real_T, 2U> &ptsNorm,
                              real_T normMatrixInv[9])
{
  ::coder::array<real_T, 1U> b_ptsNorm;
  ::coder::array<real_T, 1U> c_ptsNorm;
  ::coder::array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T cent_data[2];
  real_T s;
  int32_T acoef;
  int32_T bcoef;
  int32_T cent_size_idx_1;
  int32_T csz_idx_1;
  int32_T i;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &kt_emlrtRSI;
  b_st.site = &wj_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  if ((pts.size(0) == 0) || (pts.size(1) == 0)) {
    cent_size_idx_1 = pts.size(1);
    ncols = pts.size(1);
    if (0 <= ncols - 1) {
      std::memset(&cent_data[0], 0, ncols * sizeof(real_T));
    }
  } else {
    d_st.site = &xo_emlrtRSI;
    e_st.site = &ak_emlrtRSI;
    cent_size_idx_1 = pts.size(1);
    ncols = pts.size(1) - 1;
    if (pts.size(0) < 4096) {
      for (acoef = 0; acoef <= ncols; acoef++) {
        f_st.site = &bk_emlrtRSI;
        cent_data[acoef] = sumColumnB(&f_st, pts, acoef + 1, pts.size(0));
      }
    } else {
      nfb = pts.size(0) / 4096;
      inb = nfb << 12;
      nleft = pts.size(0) - inb;
      for (acoef = 0; acoef <= ncols; acoef++) {
        s = sumColumnB4(pts, acoef + 1, 1);
        for (bcoef = 2; bcoef <= nfb; bcoef++) {
          s += sumColumnB4(pts, acoef + 1, ((bcoef - 1) << 12) + 1);
        }
        if (nleft > 0) {
          f_st.site = &dk_emlrtRSI;
          s += sumColumnB(&f_st, pts, acoef + 1, nleft, inb + 1);
        }
        cent_data[acoef] = s;
      }
    }
  }
  ncols = cent_size_idx_1 - 1;
  for (i = 0; i <= ncols; i++) {
    cent_data[i] /= static_cast<real_T>(pts.size(0));
  }
  st.site = &nt_emlrtRSI;
  if (cent_size_idx_1 == 1) {
    csz_idx_1 = pts.size(1);
  } else if (pts.size(1) == 1) {
    csz_idx_1 = cent_size_idx_1;
  } else if (pts.size(1) == cent_size_idx_1) {
    csz_idx_1 = pts.size(1);
  } else {
    emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  ptsNorm.set_size(&if_emlrtRTEI, &st, pts.size(0), csz_idx_1);
  if ((pts.size(0) != 0) && (csz_idx_1 != 0)) {
    acoef = (pts.size(1) != 1);
    bcoef = (cent_size_idx_1 != 1);
    i = csz_idx_1 - 1;
    for (csz_idx_1 = 0; csz_idx_1 <= i; csz_idx_1++) {
      ncols = acoef * csz_idx_1;
      nfb = bcoef * csz_idx_1;
      inb = (pts.size(0) != 1);
      nleft = ptsNorm.size(0) - 1;
      for (int32_T k{0}; k <= nleft; k++) {
        ptsNorm[k + ptsNorm.size(0) * csz_idx_1] =
            pts[inb * k + pts.size(0) * ncols] - cent_data[nfb];
      }
    }
  }
  if (1 > ptsNorm.size(1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, ptsNorm.size(1), &et_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > ptsNorm.size(1)) {
    emlrtDynamicBoundsCheckR2012b(2, 1, ptsNorm.size(1), &dt_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  ncols = ptsNorm.size(0);
  b_ptsNorm.set_size(&tp_emlrtRTEI, sp, ptsNorm.size(0));
  for (i = 0; i < ncols; i++) {
    b_ptsNorm[i] = ptsNorm[i];
  }
  ncols = ptsNorm.size(0);
  c_ptsNorm.set_size(&up_emlrtRTEI, sp, ptsNorm.size(0));
  for (i = 0; i < ncols; i++) {
    c_ptsNorm[i] = ptsNorm[i + ptsNorm.size(0)];
  }
  st.site = &lt_emlrtRSI;
  b_hypot(&st, b_ptsNorm, c_ptsNorm, r);
  st.site = &lt_emlrtRSI;
  power(&st, r, b_ptsNorm);
  st.site = &lt_emlrtRSI;
  s = sum(&st, b_ptsNorm);
  if (s > 0.0) {
    st.site = &mt_emlrtRSI;
    st.site = &mt_emlrtRSI;
    s = muDoubleScalarSqrt(2.0 * static_cast<real_T>(pts.size(0))) /
        muDoubleScalarSqrt(s);
  } else {
    s = 1.0;
  }
  ncols = ptsNorm.size(0) * ptsNorm.size(1);
  for (i = 0; i < ncols; i++) {
    ptsNorm[i] = ptsNorm[i] * s;
  }
  if (1 > cent_size_idx_1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, cent_size_idx_1, &ct_emlrtBCI,
                                  (emlrtCTX)sp);
  }
  if (2 > cent_size_idx_1) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &bt_emlrtBCI, (emlrtCTX)sp);
  }
  normMatrixInv[0] = 1.0 / s;
  normMatrixInv[3] = 0.0;
  normMatrixInv[6] = 0.0;
  normMatrixInv[1] = 0.0;
  normMatrixInv[4] = 1.0 / s;
  normMatrixInv[7] = 0.0;
  normMatrixInv[2] = cent_data[0];
  normMatrixInv[5] = cent_data[1];
  normMatrixInv[8] = 1.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void normalizeControlPoints(const emlrtStack *sp,
                            const ::coder::array<real_T, 2U> &pts,
                            ::coder::array<real_T, 2U> &ptsNorm,
                            real_T normMatrixInv[9])
{
  ::coder::array<real_T, 1U> b_ptsNorm;
  ::coder::array<real_T, 1U> c_ptsNorm;
  ::coder::array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T cent[2];
  real_T s;
  int32_T col;
  int32_T inb;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &kt_emlrtRSI;
  b_st.site = &wj_emlrtRSI;
  c_st.site = &xj_emlrtRSI;
  if (pts.size(0) == 0) {
    cent[0] = 0.0;
    cent[1] = 0.0;
  } else {
    d_st.site = &xo_emlrtRSI;
    e_st.site = &ak_emlrtRSI;
    if (pts.size(0) < 4096) {
      f_st.site = &bk_emlrtRSI;
      cent[0] = sumColumnB(&f_st, pts, 1, pts.size(0));
      f_st.site = &bk_emlrtRSI;
      cent[1] = sumColumnB(&f_st, pts, 2, pts.size(0));
    } else {
      nfb = pts.size(0) / 4096;
      inb = nfb << 12;
      nleft = pts.size(0) - inb;
      for (col = 0; col < 2; col++) {
        s = sumColumnB4(pts, col + 1, 1);
        for (int32_T ib{2}; ib <= nfb; ib++) {
          s += sumColumnB4(pts, col + 1, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          f_st.site = &dk_emlrtRSI;
          s += sumColumnB(&f_st, pts, col + 1, nleft, inb + 1);
        }
        cent[col] = s;
      }
    }
  }
  cent[0] /= static_cast<real_T>(pts.size(0));
  cent[1] /= static_cast<real_T>(pts.size(0));
  ptsNorm.set_size(&if_emlrtRTEI, sp, pts.size(0), 2);
  if (pts.size(0) != 0) {
    nfb = (pts.size(0) != 1);
    for (inb = 0; inb < 2; inb++) {
      col = ptsNorm.size(0) - 1;
      for (nleft = 0; nleft <= col; nleft++) {
        ptsNorm[nleft + ptsNorm.size(0) * inb] =
            pts[nfb * nleft + pts.size(0) * inb] - cent[inb];
      }
    }
  }
  nfb = ptsNorm.size(0);
  b_ptsNorm.set_size(&tp_emlrtRTEI, sp, ptsNorm.size(0));
  for (col = 0; col < nfb; col++) {
    b_ptsNorm[col] = ptsNorm[col];
  }
  nfb = ptsNorm.size(0);
  c_ptsNorm.set_size(&up_emlrtRTEI, sp, ptsNorm.size(0));
  for (col = 0; col < nfb; col++) {
    c_ptsNorm[col] = ptsNorm[col + ptsNorm.size(0)];
  }
  st.site = &lt_emlrtRSI;
  b_hypot(&st, b_ptsNorm, c_ptsNorm, r);
  st.site = &lt_emlrtRSI;
  power(&st, r, b_ptsNorm);
  st.site = &lt_emlrtRSI;
  s = sum(&st, b_ptsNorm);
  if (s > 0.0) {
    st.site = &mt_emlrtRSI;
    st.site = &mt_emlrtRSI;
    s = muDoubleScalarSqrt(2.0 * static_cast<real_T>(pts.size(0))) /
        muDoubleScalarSqrt(s);
  } else {
    s = 1.0;
  }
  nfb = ptsNorm.size(0) * 2;
  ptsNorm.set_size(&vp_emlrtRTEI, sp, ptsNorm.size(0), 2);
  for (col = 0; col < nfb; col++) {
    ptsNorm[col] = ptsNorm[col] * s;
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
} // namespace Codegen

// End of code generation (normalizeControlPoints.cpp)
