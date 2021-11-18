//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find_peaks.cpp
//
// Code generation for function 'find_peaks'
//

// Include files
#include "find_peaks.h"
#include "algbwmorph.h"
#include "calibrateOneCamera_v2_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "imregionalmax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo yd_emlrtRSI{
    13,           // lineNo
    "find_peaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    8,           // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
    9,           // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    13,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    17,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    26,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo fe_emlrtRSI{
    28,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo
    xe_emlrtRSI{
        77,        // lineNo
        "bwmorph", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwmorph.m" // pathName
    };

static emlrtRSInfo ye_emlrtRSI{
    33,           // lineNo
    "algbwmorph", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo af_emlrtRSI{
    36,           // lineNo
    "algbwmorph", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    9,         // lineNo
    "isequal", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\isequal.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    34,                 // lineNo
    "eml_isequal_core", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\private\\eml_"
    "isequal_core.m" // pathName
};

static emlrtRSInfo pf_emlrtRSI{
    19,        // lineNo
    "ind2sub", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pathName
};

static emlrtRSInfo qf_emlrtRSI{
    40,                   // lineNo
    "ind2sub_indexClass", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pathName
};

static emlrtBCInfo cb_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    20,          // lineNo
    8,           // colNo
    "",          // aName
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m", // pName
    0                        // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    21,          // lineNo
    8,           // colNo
    "",          // aName
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m", // pName
    0                        // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    22,          // lineNo
    11,          // colNo
    "",          // aName
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m", // pName
    0                        // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    23,          // lineNo
    11,          // colNo
    "",          // aName
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m", // pName
    0                        // checkKind
};

static emlrtECInfo j_emlrtECI{
    -1,          // nDims
    28,          // lineNo
    6,           // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,          // nDims
    28,          // lineNo
    17,          // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    40,                   // lineNo
    15,                   // colNo
    "ind2sub_indexClass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtBCInfo gb_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    16,          // lineNo
    5,           // colNo
    "",          // aName
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m", // pName
    0                        // checkKind
};

static emlrtRTEInfo ve_emlrtRTEI{
    13,           // lineNo
    11,           // colNo
    "find_peaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pName
};

static emlrtRTEInfo we_emlrtRTEI{
    32,           // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo xe_emlrtRTEI{
    26,          // lineNo
    5,           // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtRTEInfo ye_emlrtRTEI{
    13,           // lineNo
    5,            // colNo
    "find_peaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pName
};

static emlrtRTEInfo af_emlrtRTEI{
    44,        // lineNo
    5,         // colNo
    "ind2sub", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtRTEInfo bf_emlrtRTEI{
    21,        // lineNo
    5,         // colNo
    "ind2sub", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtRTEInfo cf_emlrtRTEI{
    28,          // lineNo
    10,          // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtRTEInfo df_emlrtRTEI{
    28,          // lineNo
    21,          // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtRSInfo
    vfb_emlrtRSI{
        19,            // lineNo
        "indexDivide", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\indexDivide.m" // pathName
    };

// Function Declarations
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

// Function Definitions
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(nullptr, (emlrtCTX)sp);
  } else {
    uint32_T b_denominator;
    uint32_T b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<uint32_T>(numerator) + 1U;
    } else {
      b_numerator = static_cast<uint32_T>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<uint32_T>(denominator) + 1U;
    } else {
      b_denominator = static_cast<uint32_T>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int32_T>(b_numerator);
    } else {
      quotient = static_cast<int32_T>(b_numerator);
    }
  }
  return quotient;
}

namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
void find_peaks(const emlrtStack *sp,
                const ::coder::array<real32_T, 2U> &metric,
                ::coder::array<real32_T, 2U> &loc)
{
  array<int32_T, 1U> b_idx;
  array<int32_T, 1U> ii;
  array<int32_T, 1U> vk;
  array<boolean_T, 2U> bw;
  array<boolean_T, 2U> last_aout;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  real32_T maxMetric;
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
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &yd_emlrtRSI;
  b_st.site = &ae_emlrtRSI;
  c_st.site = &ge_emlrtRSI;
  d_st.site = &he_emlrtRSI;
  e_st.site = &ie_emlrtRSI;
  if (metric.size(0) * metric.size(1) < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &q_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  f_st.site = &je_emlrtRSI;
  g_st.site = &ke_emlrtRSI;
  last = metric.size(0) * metric.size(1);
  if (metric.size(0) * metric.size(1) <= 2) {
    if (metric.size(0) * metric.size(1) == 0) {
      maxMetric = rtNaNF;
    } else if (metric.size(0) * metric.size(1) == 1) {
      maxMetric = metric[0];
    } else if ((metric[0] < metric[metric.size(0) * metric.size(1) - 1]) ||
               (muSingleScalarIsNaN(metric[0]) &&
                (!muSingleScalarIsNaN(
                    metric[metric.size(0) * metric.size(1) - 1])))) {
      maxMetric = metric[metric.size(0) * metric.size(1) - 1];
    } else {
      maxMetric = metric[0];
    }
  } else {
    h_st.site = &le_emlrtRSI;
    if (!muSingleScalarIsNaN(metric[0])) {
      idx = 1;
    } else {
      idx = 0;
      i_st.site = &ne_emlrtRSI;
      if ((2 <= metric.size(0) * metric.size(1)) &&
          (metric.size(0) * metric.size(1) > 2147483646)) {
        j_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muSingleScalarIsNaN(metric[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxMetric = metric[0];
    } else {
      h_st.site = &me_emlrtRSI;
      maxMetric = metric[idx - 1];
      a = idx + 1;
      i_st.site = &oe_emlrtRSI;
      if ((idx + 1 <= metric.size(0) * metric.size(1)) &&
          (metric.size(0) * metric.size(1) > 2147483646)) {
        j_st.site = &yc_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      for (k = a; k <= last; k++) {
        if (maxMetric < metric[k - 1]) {
          maxMetric = metric[k - 1];
        }
      }
    }
  }
  b_st.site = &be_emlrtRSI;
  c_st.site = &pe_emlrtRSI;
  if (maxMetric <= 4.94065645841247E-324) {
    loc.set_size(&ye_emlrtRTEI, &st, 0, 2);
  } else {
    uint32_T siz_idx_0;
    uint32_T unnamed_idx_0;
    b_st.site = &ce_emlrtRSI;
    imregionalmax(&b_st, metric, bw);
    maxMetric *= 0.15F;
    idx = metric.size(0) * metric.size(1) - 1;
    last = 0;
    for (a = 0; a <= idx; a++) {
      if (metric[a] < maxMetric) {
        last++;
      }
    }
    ii.set_size(&ve_emlrtRTEI, &st, last);
    last = 0;
    for (a = 0; a <= idx; a++) {
      if (metric[a] < maxMetric) {
        ii[last] = a + 1;
        last++;
      }
    }
    last = ii.size(0) - 1;
    idx = bw.size(0) * bw.size(1);
    for (a = 0; a <= last; a++) {
      if ((ii[a] < 1) || (ii[a] > idx)) {
        emlrtDynamicBoundsCheckR2012b(ii[a], 1, idx, &gb_emlrtBCI, &st);
      }
      bw[ii[a] - 1] = false;
    }
    b_st.site = &de_emlrtRSI;
    if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
      c_st.site = &xe_emlrtRSI;
      do {
        last_aout.set_size(&we_emlrtRTEI, &c_st, bw.size(0), bw.size(1));
        last = bw.size(0) * bw.size(1);
        for (a = 0; a < last; a++) {
          last_aout[a] = bw[a];
        }
        d_st.site = &ye_emlrtRSI;
        images::internal::bwmorphApplyOnce(&d_st, bw);
        d_st.site = &af_emlrtRSI;
        e_st.site = &hf_emlrtRSI;
        f_st.site = &if_emlrtRSI;
        p = false;
        if ((last_aout.size(0) == bw.size(0)) &&
            (last_aout.size(1) == bw.size(1))) {
          p = true;
        }
        if (p && ((last_aout.size(0) != 0) && (last_aout.size(1) != 0)) &&
            ((bw.size(0) != 0) && (bw.size(1) != 0))) {
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= bw.size(0) * bw.size(1) - 1)) {
            if (last_aout[k] != bw[k]) {
              p = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
      } while (!p);
      //  the output is not changing anymore
    }
    if (1 > bw.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, bw.size(0), &cb_emlrtBCI, &st);
    }
    last = bw.size(1);
    for (a = 0; a < last; a++) {
      bw[bw.size(0) * a] = false;
    }
    idx = bw.size(0);
    if (bw.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(bw.size(0), 1, bw.size(0), &db_emlrtBCI,
                                    &st);
    }
    last = bw.size(1);
    for (a = 0; a < last; a++) {
      bw[(idx + bw.size(0) * a) - 1] = false;
    }
    if (1 > bw.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, bw.size(1), &eb_emlrtBCI, &st);
    }
    last = bw.size(0);
    for (a = 0; a < last; a++) {
      bw[a] = false;
    }
    idx = bw.size(1);
    if (bw.size(1) < 1) {
      emlrtDynamicBoundsCheckR2012b(bw.size(1), 1, bw.size(1), &fb_emlrtBCI,
                                    &st);
    }
    last = bw.size(0);
    for (a = 0; a < last; a++) {
      bw[a + bw.size(0) * (idx - 1)] = false;
    }
    b_st.site = &ee_emlrtRSI;
    c_st.site = &jf_emlrtRSI;
    eml_find(&c_st, bw, ii);
    b_idx.set_size(&xe_emlrtRTEI, &b_st, ii.size(0));
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      b_idx[a] = ii[a];
    }
    unnamed_idx_0 = static_cast<uint32_T>(b_idx.size(0));
    loc.set_size(&ye_emlrtRTEI, &st, b_idx.size(0), 2);
    last = b_idx.size(0) << 1;
    for (a = 0; a < last; a++) {
      loc[a] = 0.0F;
    }
    b_st.site = &fe_emlrtRSI;
    siz_idx_0 = static_cast<uint32_T>(metric.size(0));
    c_st.site = &pf_emlrtRSI;
    last = metric.size(0) * metric.size(1);
    d_st.site = &qf_emlrtRSI;
    k = 0;
    int32_T exitg2;
    do {
      exitg2 = 0;
      if (k <= ii.size(0) - 1) {
        if ((ii[k] >= 1) && (ii[k] <= last)) {
          k++;
        } else {
          p = false;
          exitg2 = 1;
        }
      } else {
        p = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&c_st, &r_emlrtRTEI,
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange",
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      ii[a] = ii[a] - 1;
    }
    vk.set_size(&af_emlrtRTEI, &c_st, ii.size(0));
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      d_st.site = &vfb_emlrtRSI;
      vk[a] = div_s32(&d_st, ii[a], static_cast<int32_T>(siz_idx_0));
    }
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      ii[a] = ii[a] - vk[a] * static_cast<int32_T>(siz_idx_0);
    }
    b_idx.set_size(&bf_emlrtRTEI, &b_st, ii.size(0));
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      b_idx[a] = ii[a] + 1;
    }
    last = vk.size(0);
    for (a = 0; a < last; a++) {
      vk[a] = vk[a] + 1;
    }
    last = static_cast<int32_T>(unnamed_idx_0);
    ii.set_size(&cf_emlrtRTEI, &st, static_cast<int32_T>(unnamed_idx_0));
    for (a = 0; a < last; a++) {
      ii[a] = a;
    }
    emlrtSubAssignSizeCheckR2012b(ii.size(), 1, b_idx.size(), 1, &j_emlrtECI,
                                  &st);
    last = b_idx.size(0);
    for (a = 0; a < last; a++) {
      loc[ii[a] + loc.size(0)] = static_cast<real32_T>(b_idx[a]);
    }
    last = loc.size(0);
    ii.set_size(&df_emlrtRTEI, &st, loc.size(0));
    for (a = 0; a < last; a++) {
      ii[a] = a;
    }
    emlrtSubAssignSizeCheckR2012b(ii.size(), 1, vk.size(), 1, &k_emlrtECI, &st);
    last = vk.size(0);
    for (a = 0; a < last; a++) {
      loc[ii[a]] = static_cast<real32_T>(vk[a]);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (find_peaks.cpp)
