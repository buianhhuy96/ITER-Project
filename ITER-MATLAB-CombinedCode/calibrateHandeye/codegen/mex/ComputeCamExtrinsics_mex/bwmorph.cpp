//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// bwmorph.cpp
//
// Code generation for function 'bwmorph'
//

// Include files
#include "bwmorph.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "algbwmorph.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    af_emlrtRSI{
        77,        // lineNo
        "bwmorph", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\eml\\bwmorph.m" // pathName
    };

static emlrtRSInfo bf_emlrtRSI{
    33,           // lineNo
    "algbwmorph", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pathName
};

static emlrtRTEInfo hv_emlrtRTEI{
    32,           // lineNo
    9,            // colNo
    "algbwmorph", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\images\\images\\+images\\+"
    "internal\\algbwmorph.m" // pName
};

// Function Definitions
namespace coder {
void bwmorph(const emlrtStack *sp, ::coder::array<boolean_T, 2U> &bwin)
{
  array<boolean_T, 2U> last_aout;
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
    st.site = &af_emlrtRSI;
    int32_T loop_ub;
    boolean_T p;
    do {
      last_aout.set_size(&hv_emlrtRTEI, &st, bwin.size(0), bwin.size(1));
      loop_ub = bwin.size(0) * bwin.size(1);
      for (int32_T i{0}; i < loop_ub; i++) {
        last_aout[i] = bwin[i];
      }
      b_st.site = &bf_emlrtRSI;
      images::internal::bwmorphApplyOnce(&b_st, bwin);
      p = false;
      if ((last_aout.size(0) == bwin.size(0)) &&
          (last_aout.size(1) == bwin.size(1))) {
        p = true;
      }
      if (p && ((last_aout.size(0) != 0) && (last_aout.size(1) != 0)) &&
          ((bwin.size(0) != 0) && (bwin.size(1) != 0))) {
        boolean_T exitg1;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= bwin.size(0) * bwin.size(1) - 1)) {
          if (last_aout[loop_ub] != bwin[loop_ub]) {
            p = false;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }
    } while (!p);
    //  the output is not changing anymore
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (bwmorph.cpp)
