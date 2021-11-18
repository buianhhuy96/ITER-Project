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
#include "calibrateOneCamera_mex_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "eps.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "libmwimregionalmax.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo dd_emlrtRSI{
    13,           // lineNo
    "find_peaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    8,           // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    9,           // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    13,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    17,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    26,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    28,          // lineNo
    "findPeaks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    14,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo vd_emlrtRSI{
    28,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo wd_emlrtRSI{
    35,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    37,              // lineNo
    "imregionalmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    27,                            // lineNo
    "getBinaryConnectivityMatrix", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\getBinaryConnectivityMatrix.m" // pathName
};

static emlrtRSInfo
    be_emlrtRSI{
        77,        // lineNo
        "bwmorph", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwmorph.m" // pathName
    };

static emlrtRSInfo ce_emlrtRSI{
    33,           // lineNo
    "algbwmorph", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRSInfo pe_emlrtRSI{
    19,        // lineNo
    "ind2sub", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pathName
};

static emlrtRTEInfo n_emlrtRTEI{
    40,                   // lineNo
    15,                   // colNo
    "ind2sub_indexClass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtECInfo j_emlrtECI{
    -1,          // nDims
    28,          // lineNo
    17,          // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,          // nDims
    28,          // lineNo
    6,           // colNo
    "findPeaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\findPeaks.m" // pName
};

static emlrtBCInfo pb_emlrtBCI{
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

static emlrtBCInfo qb_emlrtBCI{
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

static emlrtBCInfo rb_emlrtBCI{
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

static emlrtBCInfo sb_emlrtBCI{
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

static emlrtBCInfo tb_emlrtBCI{
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

static emlrtRTEInfo ie_emlrtRTEI{
    35,              // lineNo
    28,              // colNo
    "imregionalmax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\imregionalmax.m" // pName
};

static emlrtRTEInfo je_emlrtRTEI{
    13,           // lineNo
    11,           // colNo
    "find_peaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pName
};

static emlrtRTEInfo ke_emlrtRTEI{
    32,           // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

static emlrtRTEInfo le_emlrtRTEI{
    13,           // lineNo
    5,            // colNo
    "find_peaks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\find_peaks.m" // pName
};

static emlrtRTEInfo me_emlrtRTEI{
    44,        // lineNo
    5,         // colNo
    "ind2sub", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtRSInfo
    nbb_emlrtRSI{
        19,            // lineNo
        "indexDivide", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\indexDivide.m" // pathName
    };

// Function Declarations
namespace Codegen {
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

}

// Function Definitions
namespace Codegen {
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
  ::coder::array<int32_T, 1U> ii;
  ::coder::array<int32_T, 1U> vk;
  ::coder::array<boolean_T, 2U> bw;
  ::coder::array<boolean_T, 2U> last_aout;
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
  real_T connSizeT[2];
  real_T imSizeT[2];
  int32_T a;
  int32_T idx;
  int32_T k;
  int32_T last;
  real32_T maxMetric;
  boolean_T conn[9];
  boolean_T exitg1;
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
  st.site = &dd_emlrtRSI;
  b_st.site = &ed_emlrtRSI;
  c_st.site = &kd_emlrtRSI;
  d_st.site = &ld_emlrtRSI;
  e_st.site = &md_emlrtRSI;
  if (metric.size(0) * metric.size(1) < 1) {
    emlrtErrorWithMessageIdR2018a(&e_st, &o_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  f_st.site = &nd_emlrtRSI;
  g_st.site = &od_emlrtRSI;
  last = metric.size(0) * metric.size(1);
  if (metric.size(0) * metric.size(1) <= 2) {
    if (metric.size(0) * metric.size(1) == 1) {
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
    h_st.site = &qd_emlrtRSI;
    if (!muSingleScalarIsNaN(metric[0])) {
      idx = 1;
    } else {
      idx = 0;
      i_st.site = &rd_emlrtRSI;
      if ((2 <= metric.size(0) * metric.size(1)) &&
          (metric.size(0) * metric.size(1) > 2147483646)) {
        j_st.site = &hc_emlrtRSI;
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
      h_st.site = &pd_emlrtRSI;
      maxMetric = metric[idx - 1];
      a = idx + 1;
      i_st.site = &sd_emlrtRSI;
      if ((idx + 1 <= metric.size(0) * metric.size(1)) &&
          (metric.size(0) * metric.size(1) > 2147483646)) {
        j_st.site = &hc_emlrtRSI;
        check_forloop_overflow_error(&j_st);
      }
      for (k = a; k <= last; k++) {
        if (maxMetric < metric[k - 1]) {
          maxMetric = metric[k - 1];
        }
      }
    }
  }
  b_st.site = &fd_emlrtRSI;
  if (maxMetric <= eps()) {
    loc.set_size(&le_emlrtRTEI, &st, 0, 2);
  } else {
    boolean_T p;
    b_st.site = &gd_emlrtRSI;
    c_st.site = &ud_emlrtRSI;
    d_st.site = &p_emlrtRSI;
    p = true;
    a = metric.size(0) * metric.size(1);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= a - 1)) {
      if (!muSingleScalarIsNaN(metric[k])) {
        k++;
      } else {
        p = false;
        exitg1 = true;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
          "MATLAB:imregionalmax:expectedNonNaN", 3, 4, 18,
          "input number 1, I,");
    }
    c_st.site = &vd_emlrtRSI;
    d_st.site = &yd_emlrtRSI;
    c_st.site = &wd_emlrtRSI;
    a = metric.size(0) * metric.size(1);
    for (k = 0; k < a; k++) {
      if (muSingleScalarIsNaN(metric[k])) {
        emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
                                      "MATLAB:nologicalnan",
                                      "MATLAB:nologicalnan", 0);
      }
    }
    bw.set_size(&ie_emlrtRTEI, &b_st, metric.size(0), metric.size(1));
    c_st.site = &xd_emlrtRSI;
    imSizeT[0] = metric.size(0);
    imSizeT[1] = metric.size(1);
    for (a = 0; a < 9; a++) {
      conn[a] = true;
    }
    connSizeT[0] = 3.0;
    connSizeT[1] = 3.0;
    imregionalmax_real32(&metric[0], &bw[0], 2.0, &imSizeT[0], &conn[0], 2.0,
                         &connSizeT[0]);
    maxMetric *= 0.15F;
    idx = metric.size(0) * metric.size(1) - 1;
    last = 0;
    for (a = 0; a <= idx; a++) {
      if (metric[a] < maxMetric) {
        last++;
      }
    }
    ii.set_size(&je_emlrtRTEI, &st, last);
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
        emlrtDynamicBoundsCheckR2012b(ii[a], 1, idx, &tb_emlrtBCI, &st);
      }
      bw[ii[a] - 1] = false;
    }
    b_st.site = &hd_emlrtRSI;
    if ((bw.size(0) != 0) && (bw.size(1) != 0)) {
      c_st.site = &be_emlrtRSI;
      do {
        last_aout.set_size(&ke_emlrtRTEI, &c_st, bw.size(0), bw.size(1));
        last = bw.size(0) * bw.size(1);
        for (a = 0; a < last; a++) {
          last_aout[a] = bw[a];
        }
        d_st.site = &ce_emlrtRSI;
        images::internal::bwmorphApplyOnce(&d_st, bw);
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
      emlrtDynamicBoundsCheckR2012b(1, 1, bw.size(0), &sb_emlrtBCI, &st);
    }
    last = bw.size(1);
    for (a = 0; a < last; a++) {
      bw[bw.size(0) * a] = false;
    }
    idx = bw.size(0);
    if (bw.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(bw.size(0), 1, bw.size(0), &rb_emlrtBCI,
                                    &st);
    }
    last = bw.size(1);
    for (a = 0; a < last; a++) {
      bw[(idx + bw.size(0) * a) - 1] = false;
    }
    if (1 > bw.size(1)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, bw.size(1), &qb_emlrtBCI, &st);
    }
    last = bw.size(0);
    for (a = 0; a < last; a++) {
      bw[a] = false;
    }
    idx = bw.size(1);
    if (bw.size(1) < 1) {
      emlrtDynamicBoundsCheckR2012b(bw.size(1), 1, bw.size(1), &pb_emlrtBCI,
                                    &st);
    }
    last = bw.size(0);
    for (a = 0; a < last; a++) {
      bw[a + bw.size(0) * (idx - 1)] = false;
    }
    b_st.site = &id_emlrtRSI;
    c_st.site = &je_emlrtRSI;
    eml_find(&c_st, bw, ii);
    imSizeT[0] = ii.size(0);
    loc.set_size(&le_emlrtRTEI, &st, ii.size(0), 2);
    last = ii.size(0) << 1;
    for (a = 0; a < last; a++) {
      loc[a] = 0.0F;
    }
    b_st.site = &jd_emlrtRSI;
    connSizeT[0] = metric.size(0);
    c_st.site = &pe_emlrtRSI;
    last = metric.size(0) * metric.size(1);
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= ii.size(0) - 1)) {
      if (ii[k] > last) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &n_emlrtRTEI, "Coder:MATLAB:ind2sub_IndexOutOfRange",
            "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      } else {
        k++;
      }
    }
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      ii[a] = ii[a] - 1;
    }
    vk.set_size(&me_emlrtRTEI, &c_st, ii.size(0));
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      d_st.site = &nbb_emlrtRSI;
      vk[a] =
          div_s32(&d_st, ii[a],
                  static_cast<int32_T>(static_cast<uint32_T>(connSizeT[0])));
    }
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      ii[a] = ii[a] -
              vk[a] * static_cast<int32_T>(static_cast<uint32_T>(connSizeT[0]));
    }
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      ii[a] = ii[a] + 1;
    }
    last = vk.size(0);
    for (a = 0; a < last; a++) {
      vk[a] = vk[a] + 1;
    }
    idx = static_cast<int32_T>(imSizeT[0]);
    emlrtSubAssignSizeCheckR2012b(&idx, 1, ii.size(), 1, &k_emlrtECI, &st);
    last = ii.size(0);
    for (a = 0; a < last; a++) {
      loc[a + loc.size(0)] = static_cast<real32_T>(ii[a]);
    }
    emlrtSubAssignSizeCheckR2012b(loc.size(), 1, vk.size(), 1, &j_emlrtECI,
                                  &st);
    last = vk.size(0);
    for (a = 0; a < last; a++) {
      loc[a] = static_cast<real32_T>(vk[a]);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// End of code generation (find_peaks.cpp)
