//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// detectCheckerboard.cpp
//
// Code generation for function 'detectCheckerboard'
//

// Include files
#include "detectCheckerboard.h"
#include "Checkerboard.h"
#include "ComputeCamExtrinsics_mex_data.h"
#include "abs.h"
#include "any1.h"
#include "cat.h"
#include "eml_int_forloop_overflow_check.h"
#include "find_peaks.h"
#include "flip.h"
#include "ifWhileCond.h"
#include "imfilter.h"
#include "indexShapeCheck.h"
#include "mean.h"
#include "mod.h"
#include "power.h"
#include "rot90.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sub2ind.h"
#include "subPixelLocation.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo bg_emlrtRSI{
    78,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    85,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo dg_emlrtRSI{
    86,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo eg_emlrtRSI{
    118,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo fg_emlrtRSI{
    119,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gg_emlrtRSI{
    121,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo hg_emlrtRSI{
    128,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ig_emlrtRSI{
    129,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo vh_emlrtRSI{
    192,                  // lineNo
    "cornerOrientations", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo wh_emlrtRSI{
    200,                  // lineNo
    "cornerOrientations", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo sr_emlrtRSI{
    247,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo tr_emlrtRSI{
    251,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ur_emlrtRSI{
    252,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo vr_emlrtRSI{
    253,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo wr_emlrtRSI{
    258,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo xr_emlrtRSI{
    259,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo yr_emlrtRSI{
    260,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo as_emlrtRSI{
    270,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo bs_emlrtRSI{
    271,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo cs_emlrtRSI{
    280,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ds_emlrtRSI{
    281,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo es_emlrtRSI{
    282,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo fs_emlrtRSI{
    306,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gs_emlrtRSI{
    307,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo hs_emlrtRSI{
    308,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo is_emlrtRSI{
    309,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo rs_emlrtRSI{
    332,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ss_emlrtRSI{
    342,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ts_emlrtRSI{
    346,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ft_emlrtRSI{
    295,                // lineNo
    "getOriginInImage", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gt_emlrtRSI{
    314,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ht_emlrtRSI{
    315,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo it_emlrtRSI{
    316,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo jt_emlrtRSI{
    317,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo st_emlrtRSI{
    225,        // lineNo
    "toPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    88,                 // lineNo
    23,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    88,                 // lineNo
    25,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    121,                // lineNo
    67,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    85,                 // lineNo
    30,                 // colNo
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    85,                 // lineNo
    30,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ob_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    86,                 // lineNo
    19,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo pb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    121,                // lineNo
    75,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo qb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    152,                  // lineNo
    9,                    // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    152,                  // lineNo
    9,                    // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo rb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    152,                  // lineNo
    15,                   // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    152,                  // lineNo
    15,                   // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo sb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    153,                  // lineNo
    9,                    // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    153,                  // lineNo
    9,                    // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo tb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    153,                  // lineNo
    15,                   // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    153,                  // lineNo
    15,                   // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ub_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    154,                  // lineNo
    9,                    // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    154,                  // lineNo
    9,                    // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo vb_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    154,                  // lineNo
    15,                   // colNo
    "",                   // aName
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    154,                  // lineNo
    15,                   // colNo
    "cornerOrientations", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo wb_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    128,                // lineNo
    41,                 // colNo
    "",                 // aName
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtRTEInfo
    gb_emlrtRTEI{
        47,         // lineNo
        19,         // colNo
        "allOrAny", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pName
    };

static emlrtBCInfo dq_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    308,                  // lineNo
    47,                   // colNo
    "",                   // aName
    "rot90_checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo eq_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    307,                  // lineNo
    47,                   // colNo
    "",                   // aName
    "rot90_checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo fq_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    316,                 // lineNo
    46,                  // colNo
    "",                  // aName
    "flip_checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo gq_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    315,                 // lineNo
    46,                  // colNo
    "",                  // aName
    "flip_checkerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo hq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    341,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo iq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    341,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo jq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    341,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo kq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    55,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo lq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    52,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo mq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    49,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo nq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo oq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo pq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    340,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo qq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    339,                // lineNo
    43,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo rq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    339,                // lineNo
    40,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo sq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    339,                // lineNo
    37,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo tq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    338,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo uq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    338,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo vq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    338,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo wq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    55,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo xq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    52,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo yq_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    49,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ar_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo br_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo cr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    337,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo dr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    336,                // lineNo
    43,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo er_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    336,                // lineNo
    40,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo fr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    336,                // lineNo
    37,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo gr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    331,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo hr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    331,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ir_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    331,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo jr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    55,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo kr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    52,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo lr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    49,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo mr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo nr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo or_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    330,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo pr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    329,                // lineNo
    42,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo qr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    329,                // lineNo
    39,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo rr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    329,                // lineNo
    36,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo sr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    328,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo tr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    328,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ur_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    328,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo vr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    55,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo wr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    52,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo xr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    49,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo yr_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    28,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo as_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    25,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo bs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    327,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo cs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    326,                // lineNo
    42,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ds_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    326,                // lineNo
    39,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo es_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    326,                // lineNo
    36,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo fs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    292,                // lineNo
    45,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo gs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    291,                // lineNo
    54,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo hs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    291,                // lineNo
    31,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo is_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    291,                // lineNo
    29,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtRTEInfo
    vb_emlrtRTEI{
        44,         // lineNo
        19,         // colNo
        "allOrAny", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pName
    };

static emlrtBCInfo js_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    281,      // lineNo
    49,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtECInfo wc_emlrtECI{
    3,        // nDims
    280,      // lineNo
    20,       // colNo
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtBCInfo ks_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    280,      // lineNo
    70,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ls_emlrtBCI{
    0,           // iFirst
    MAX_int32_T, // iLast
    280,         // lineNo
    70,          // colNo
    "",          // aName
    "orient",    // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ms_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    280,      // lineNo
    65,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ns_emlrtBCI{
    0,           // iFirst
    MAX_int32_T, // iLast
    280,         // lineNo
    65,          // colNo
    "",          // aName
    "orient",    // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo os_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    280,      // lineNo
    40,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ps_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    280,      // lineNo
    38,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo qs_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    291,                // lineNo
    35,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo rs_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    291,                // lineNo
    35,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ss_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    292,                // lineNo
    5,                  // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ts_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    292,                // lineNo
    5,                  // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo us_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    292,                // lineNo
    30,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo vs_emlrtBCI{
    0,                  // iFirst
    MAX_int32_T,        // iLast
    292,                // lineNo
    30,                 // colNo
    "",                 // aName
    "getOriginInImage", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ws_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    281,      // lineNo
    39,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo xs_emlrtBCI{
    0,           // iFirst
    MAX_int32_T, // iLast
    281,         // lineNo
    39,          // colNo
    "",          // aName
    "orient",    // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ys_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    281,      // lineNo
    44,       // colNo
    "",       // aName
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo at_emlrtBCI{
    0,           // iFirst
    MAX_int32_T, // iLast
    281,         // lineNo
    44,          // colNo
    "",          // aName
    "orient",    // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo bt_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    346,                // lineNo
    18,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo ct_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    346,                // lineNo
    49,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo yf_emlrtDCI{
    358,             // lineNo
    6,               // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo dt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    358,             // lineNo
    6,               // colNo
    "",              // aName
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo ag_emlrtDCI{
    358,             // lineNo
    9,               // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo et_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    358,             // lineNo
    9,               // colNo
    "",              // aName
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo bg_emlrtDCI{
    358,             // lineNo
    13,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ft_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    358,             // lineNo
    13,              // colNo
    "",              // aName
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo cg_emlrtDCI{
    358,             // lineNo
    16,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo gt_emlrtBCI{
    -1,              // iFirst
    -1,              // iLast
    358,             // lineNo
    16,              // colNo
    "",              // aName
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtDCInfo dg_emlrtDCI{
    357,             // lineNo
    14,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtDCInfo eg_emlrtDCI{
    357,             // lineNo
    14,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    4                                                   // checkKind
};

static emlrtDCInfo fg_emlrtDCI{
    357,             // lineNo
    22,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtDCInfo gg_emlrtDCI{
    357,             // lineNo
    22,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    4                                                   // checkKind
};

static emlrtDCInfo hg_emlrtDCI{
    357,             // lineNo
    1,               // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ht_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    233,        // lineNo
    28,         // colNo
    "",         // aName
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo it_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    235,        // lineNo
    28,         // colNo
    "",         // aName
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtECInfo xc_emlrtECI{
    -1,         // nDims
    234,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtECInfo yc_emlrtECI{
    -1,         // nDims
    236,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtDCInfo ig_emlrtDCI{
    232,        // lineNo
    16,         // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtDCInfo jg_emlrtDCI{
    232,        // lineNo
    16,         // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    4                                                   // checkKind
};

static emlrtDCInfo kg_emlrtDCI{
    232,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtRTEInfo gf_emlrtRTEI{
    84,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo if_emlrtRTEI{
    86,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo jf_emlrtRTEI{
    88,                   // lineNo
    5,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo pp_emlrtRTEI{
    306,                  // lineNo
    24,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo qp_emlrtRTEI{
    307,                  // lineNo
    25,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo rp_emlrtRTEI{
    308,                  // lineNo
    25,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo sp_emlrtRTEI{
    309,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo tp_emlrtRTEI{
    251,                  // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo
    up_emlrtRTEI{
        13,    // lineNo
        5,     // colNo
        "all", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m" // pName
    };

static emlrtRTEInfo vp_emlrtRTEI{
    364,    // lineNo
    5,      // colNo
    "find", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

static emlrtRTEInfo wp_emlrtRTEI{
    258,                  // lineNo
    13,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo xp_emlrtRTEI{
    259,                  // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo yp_emlrtRTEI{
    242,                  // lineNo
    18,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo aq_emlrtRTEI{
    314,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo bq_emlrtRTEI{
    315,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo cq_emlrtRTEI{
    316,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo dq_emlrtRTEI{
    317,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo eq_emlrtRTEI{
    252,                  // lineNo
    17,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo fq_emlrtRTEI{
    346,                  // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo gq_emlrtRTEI{
    346,                  // lineNo
    47,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo hq_emlrtRTEI{
    280,                  // lineNo
    20,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo iq_emlrtRTEI{
    280,                  // lineNo
    47,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo lq_emlrtRTEI{
    357,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo nq_emlrtRTEI{
    225,                  // lineNo
    8,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo oq_emlrtRTEI{
    232,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo pq_emlrtRTEI{
    233,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo qq_emlrtRTEI{
    234,                  // lineNo
    8,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo rq_emlrtRTEI{
    235,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo sq_emlrtRTEI{
    236,                  // lineNo
    8,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo tq_emlrtRTEI{
    226,                  // lineNo
    5,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

// Function Declarations
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(const emlrtStack *sp, real_T b_X[4], real_T Y[4],
                          real_T height, real_T width,
                          ::coder::array<boolean_T, 2U> &mask);

}
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// Function Definitions
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static void poly2RectMask(const emlrtStack *sp, real_T b_X[4], real_T Y[4],
                          real_T height, real_T width,
                          ::coder::array<boolean_T, 2U> &mask)
{
  real_T d;
  real_T d1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T unnamed_idx_0;
  ::coder::internal::sort(b_X);
  ::coder::internal::sort(Y);
  if (!(height >= 0.0)) {
    emlrtNonNegativeCheckR2012b(height, &eg_emlrtDCI, (emlrtCTX)sp);
  }
  d = static_cast<int32_T>(muDoubleScalarFloor(height));
  if (height != d) {
    emlrtIntegerCheckR2012b(height, &dg_emlrtDCI, (emlrtCTX)sp);
  }
  mask.set_size(&lq_emlrtRTEI, sp, static_cast<int32_T>(height), mask.size(1));
  if (!(width >= 0.0)) {
    emlrtNonNegativeCheckR2012b(width, &gg_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = static_cast<int32_T>(muDoubleScalarFloor(width));
  if (width != d1) {
    emlrtIntegerCheckR2012b(width, &fg_emlrtDCI, (emlrtCTX)sp);
  }
  mask.set_size(&lq_emlrtRTEI, sp, mask.size(0), static_cast<int32_T>(width));
  if (height != d) {
    emlrtIntegerCheckR2012b(height, &hg_emlrtDCI, (emlrtCTX)sp);
  }
  if (width != d1) {
    emlrtIntegerCheckR2012b(width, &hg_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(height) * static_cast<int32_T>(width);
  for (i = 0; i < loop_ub; i++) {
    mask[i] = false;
  }
  if (Y[1] > Y[2]) {
    i = 0;
    i1 = 0;
  } else {
    if (Y[1] != static_cast<int32_T>(muDoubleScalarFloor(Y[1]))) {
      emlrtIntegerCheckR2012b(Y[1], &yf_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(Y[1]) < 1) ||
        (static_cast<int32_T>(Y[1]) > static_cast<int32_T>(height))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Y[1]), 1,
                                    static_cast<int32_T>(height), &dt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(Y[1]) - 1;
    if (Y[2] != static_cast<int32_T>(muDoubleScalarFloor(Y[2]))) {
      emlrtIntegerCheckR2012b(Y[2], &ag_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(Y[2]) < 1) ||
        (static_cast<int32_T>(Y[2]) > static_cast<int32_T>(height))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Y[2]), 1,
                                    static_cast<int32_T>(height), &et_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = static_cast<int32_T>(Y[2]);
  }
  if (b_X[1] > b_X[2]) {
    i2 = 0;
    i3 = 0;
  } else {
    if (b_X[1] != static_cast<int32_T>(muDoubleScalarFloor(b_X[1]))) {
      emlrtIntegerCheckR2012b(b_X[1], &bg_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(b_X[1]) < 1) ||
        (static_cast<int32_T>(b_X[1]) > static_cast<int32_T>(width))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_X[1]), 1,
                                    static_cast<int32_T>(width), &ft_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = static_cast<int32_T>(b_X[1]) - 1;
    if (b_X[2] != static_cast<int32_T>(muDoubleScalarFloor(b_X[2]))) {
      emlrtIntegerCheckR2012b(b_X[2], &cg_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(b_X[2]) < 1) ||
        (static_cast<int32_T>(b_X[2]) > static_cast<int32_T>(width))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_X[2]), 1,
                                    static_cast<int32_T>(width), &gt_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i3 = static_cast<int32_T>(b_X[2]);
  }
  unnamed_idx_0 = i1 - i;
  loop_ub = i3 - i2;
  for (i1 = 0; i1 < loop_ub; i1++) {
    for (i3 = 0; i3 < unnamed_idx_0; i3++) {
      mask[(i + i3) + mask.size(0) * (i2 + i1)] = true;
    }
  }
}

void detectCheckerboard(const emlrtStack *sp,
                        const ::coder::array<real32_T, 2U> &b_I,
                        ::coder::array<real_T, 2U> &points, real_T boardSize[2])
{
  static const real_T kernel[225]{
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      8.70638696167455E-5,    0.00044214681291224477, 0.0017487245678627389,
      0.005386450878047711,   0.012921423933516035,   0.0241403980280593,
      0.035124071876292441,   0.039800787712028794,   0.035124071876292441,
      0.0241403980280593,     0.012921423933516035,   0.005386450878047711,
      0.0017487245678627389,  0.00044214681291224477, 8.70638696167455E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7};
  static const real_T nonZeroKernel[225]{
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      8.70638696167455E-5,    0.00044214681291224477, 0.0017487245678627389,
      0.005386450878047711,   0.012921423933516035,   0.0241403980280593,
      0.035124071876292441,   0.039800787712028794,   0.035124071876292441,
      0.0241403980280593,     0.012921423933516035,   0.005386450878047711,
      0.0017487245678627389,  0.00044214681291224477, 8.70638696167455E-5,
      7.683359526380697E-5,   0.0003901931928827066,  0.0015432440146124519,
      0.0047535262158011791,  0.011403116598310359,   0.021303826486921609,
      0.030996884636986775,   0.035124071876292441,   0.030996884636986775,
      0.021303826486921609,   0.011403116598310359,   0.0047535262158011791,
      0.0015432440146124519,  0.0003901931928827066,  7.683359526380697E-5,
      5.2806906275779353E-5,  0.00026817559812550214, 0.0010606550658014767,
      0.0032670476045719718,  0.0078372397828220912,  0.014641891541684361,
      0.021303826486921609,   0.0241403980280593,     0.021303826486921609,
      0.014641891541684361,   0.0078372397828220912,  0.0032670476045719718,
      0.0010606550658014767,  0.00026817559812550214, 5.2806906275779353E-5,
      2.826550008884209E-5,   0.00014354405374659092, 0.000567727745686802,
      0.0017487245678627389,  0.0041949721617992137,  0.0078372397828220912,
      0.011403116598310359,   0.012921423933516035,   0.011403116598310359,
      0.0078372397828220912,  0.0041949721617992137,  0.0017487245678627389,
      0.000567727745686802,   0.00014354405374659092, 2.826550008884209E-5,
      1.1782813454257772E-5,  5.983806415764425E-5,   0.00023666413469452686,
      0.000728976855220688,   0.0017487245678627389,  0.0032670476045719718,
      0.0047535262158011791,  0.005386450878047711,   0.0047535262158011791,
      0.0032670476045719718,  0.0017487245678627389,  0.000728976855220688,
      0.00023666413469452686, 5.983806415764425E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  1.9426575170726439E-5,  7.683359526380697E-5,
      0.00023666413469452686, 0.000567727745686802,   0.0010606550658014767,
      0.0015432440146124519,  0.0017487245678627389,  0.0015432440146124519,
      0.0010606550658014767,  0.000567727745686802,   0.00023666413469452686,
      7.683359526380697E-5,   1.9426575170726439E-5,  3.8253194603479445E-6,
      9.6719222617840546E-7,  4.9118074140369968E-6,  1.9426575170726439E-5,
      5.983806415764425E-5,   0.00014354405374659092, 0.00026817559812550214,
      0.0003901931928827066,  0.00044214681291224477, 0.0003901931928827066,
      0.00026817559812550214, 0.00014354405374659092, 5.983806415764425E-5,
      1.9426575170726439E-5,  4.9118074140369968E-6,  9.6719222617840546E-7,
      1.9045144150126356E-7,  9.6719222617840546E-7,  3.8253194603479445E-6,
      1.1782813454257772E-5,  2.826550008884209E-5,   5.2806906275779353E-5,
      7.683359526380697E-5,   8.70638696167455E-5,    7.683359526380697E-5,
      5.2806906275779353E-5,  2.826550008884209E-5,   1.1782813454257772E-5,
      3.8253194603479445E-6,  9.6719222617840546E-7,  1.9045144150126356E-7};
  Checkerboard lobj_0[6];
  Checkerboard *board0;
  Checkerboard *board45;
  array<real_T, 1U> s;
  array<int32_T, 1U> r2;
  array<int32_T, 1U> r3;
  array<real32_T, 2U> I_45;
  array<real32_T, 2U> I_45_x;
  array<real32_T, 2U> Ig;
  array<real32_T, 2U> Ixy;
  array<real32_T, 2U> Iy;
  array<real32_T, 2U> a;
  array<real32_T, 2U> b;
  array<real32_T, 2U> cxy;
  array<real32_T, 2U> points0;
  array<real32_T, 2U> r;
  array<real32_T, 2U> r1;
  array<real32_T, 1U> b_points0;
  array<real32_T, 1U> c_points0;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T connDimsT[2];
  real_T outSizeT[2];
  real_T padSizeT[2];
  real_T startT[2];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T end;
  int32_T i;
  int32_T loop_ub;
  int32_T trueCount;
  boolean_T conn[225];
  boolean_T guard1{false};
  boolean_T guard2{false};
  boolean_T tooBig;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &wb_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  outSizeT[0] = b_I.size(0);
  startT[0] = 7.0;
  outSizeT[1] = b_I.size(1);
  startT[1] = 7.0;
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    Ig.set_size(&qd_emlrtRTEI, &b_st, b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = b_I[i];
    }
  } else {
    c_st.site = &uc_emlrtRSI;
    padImage(&c_st, b_I, startT, a);
    c_st.site = &vc_emlrtRSI;
    d_st.site = &fd_emlrtRSI;
    tooBig = true;
    if ((b_I.size(0) <= 65500) || (b_I.size(1) <= 65500)) {
      tooBig = false;
    }
    e_st.site = &gd_emlrtRSI;
    Ig.set_size(&pe_emlrtRTEI, &e_st, b_I.size(0), b_I.size(1));
    if (!tooBig) {
      padSizeT[0] = a.size(0);
      startT[0] = 15.0;
      padSizeT[1] = a.size(1);
      startT[1] = 15.0;
      ippfilter_real32(&a[0], &Ig[0], &outSizeT[0], 2.0, &padSizeT[0],
                       &kernel[0], &startT[0], true);
    } else {
      padSizeT[0] = a.size(0);
      padSizeT[1] = a.size(1);
      for (i = 0; i < 225; i++) {
        conn[i] = true;
      }
      connDimsT[0] = 15.0;
      connDimsT[1] = 15.0;
      imfilter_real32(&a[0], &Ig[0], 2.0, &outSizeT[0], 2.0, &padSizeT[0],
                      &nonZeroKernel[0], 225.0, &conn[0], 2.0, &connDimsT[0],
                      &startT[0], 2.0, true, true);
    }
  }
  Iy.set_size(&rd_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Iy[i] = Ig[i];
  }
  b_st.site = &nc_emlrtRSI;
  imfilter(&b_st, Iy);
  b_st.site = &oc_emlrtRSI;
  b_imfilter(&b_st, Ig);
  Ixy.set_size(&sd_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Ixy[i] = Ig[i];
  }
  b_st.site = &pc_emlrtRSI;
  imfilter(&b_st, Ixy);
  r.set_size(&td_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = Ig[i] * 0.707106769F;
  }
  I_45.set_size(&ud_emlrtRTEI, &st, Iy.size(0), Iy.size(1));
  loop_ub = Iy.size(0) * Iy.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = Iy[i] * 0.707106769F;
  }
  b_iv[0] = (*(int32_T(*)[2])r.size())[0];
  b_iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])I_45.size())[0];
  iv1[1] = (*(int32_T(*)[2])I_45.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &d_emlrtECI, &st);
  loop_ub = r.size(0) * r.size(1);
  I_45.set_size(&vd_emlrtRTEI, &st, r.size(0), r.size(1));
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = r[i] + I_45[i];
  }
  r1.set_size(&wd_emlrtRTEI, &st, Iy.size(0), Iy.size(1));
  loop_ub = Iy.size(0) * Iy.size(1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = Iy[i] * -0.707106769F;
  }
  b_iv[0] = (*(int32_T(*)[2])r.size())[0];
  b_iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &e_emlrtECI, &st);
  I_45_x.set_size(&xd_emlrtRTEI, &st, I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(0) * I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45[i];
  }
  b_st.site = &qc_emlrtRSI;
  b_imfilter(&b_st, I_45_x);
  a.set_size(&yd_emlrtRTEI, &st, I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(0) * I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = I_45[i];
  }
  b_st.site = &rc_emlrtRSI;
  imfilter(&b_st, a);
  loop_ub = I_45_x.size(0) * I_45_x.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45_x[i] * 0.707106769F;
  }
  loop_ub = a.size(0) * a.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = a[i] * -0.707106769F;
  }
  b_iv[0] = (*(int32_T(*)[2])I_45_x.size())[0];
  b_iv[1] = (*(int32_T(*)[2])I_45_x.size())[1];
  iv1[0] = (*(int32_T(*)[2])a.size())[0];
  iv1[1] = (*(int32_T(*)[2])a.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &f_emlrtECI, &st);
  loop_ub = I_45_x.size(0) * I_45_x.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45_x[i] + a[i];
  }
  b_st.site = &sc_emlrtRSI;
  b_abs(&b_st, I_45, a);
  I_45.set_size(&ae_emlrtRTEI, &st, r.size(0), r.size(1));
  loop_ub = r.size(0) * r.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = r[i] + r1[i];
  }
  b_st.site = &sc_emlrtRSI;
  b_abs(&b_st, I_45, r);
  b_iv[0] = (*(int32_T(*)[2])a.size())[0];
  b_iv[1] = (*(int32_T(*)[2])a.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &g_emlrtECI, &st);
  b_st.site = &sc_emlrtRSI;
  b_abs(&b_st, Ixy, b);
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    b[i] = 4.0F * b[i];
  }
  loop_ub = a.size(0) * a.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = 3.0F * (a[i] + r[i]);
  }
  b_iv[0] = (*(int32_T(*)[2])b.size())[0];
  b_iv[1] = (*(int32_T(*)[2])b.size())[1];
  iv1[0] = (*(int32_T(*)[2])a.size())[0];
  iv1[1] = (*(int32_T(*)[2])a.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &h_emlrtECI, &st);
  cxy.set_size(&be_emlrtRTEI, &st, b.size(0), b.size(1));
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    cxy[i] = b[i] - a[i];
  }
  end = b.size(0) * b.size(1) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (b[loop_ub] - a[loop_ub] < 0.0F) {
      trueCount++;
    }
  }
  r2.set_size(&ce_emlrtRTEI, &st, trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (b[loop_ub] - a[loop_ub] < 0.0F) {
      r2[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  trueCount = b.size(0) * b.size(1);
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    if ((r2[i] < 1) || (r2[i] > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &m_emlrtBCI, &st);
    }
    cxy[r2[i] - 1] = 0.0F;
  }
  b_st.site = &tc_emlrtRSI;
  b_abs(&b_st, Ig, r);
  b_st.site = &tc_emlrtRSI;
  b_abs(&b_st, Iy, r1);
  b_iv[0] = (*(int32_T(*)[2])r.size())[0];
  b_iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &i_emlrtECI, &st);
  b_st.site = &tc_emlrtRSI;
  b_abs(&b_st, I_45_x, b);
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    b[i] = 4.0F * b[i];
  }
  loop_ub = r.size(0) * r.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 3.0F * (r[i] + r1[i]);
  }
  b_iv[0] = (*(int32_T(*)[2])b.size())[0];
  b_iv[1] = (*(int32_T(*)[2])b.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &j_emlrtECI, &st);
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    b[i] = b[i] - r[i];
  }
  end = b.size(0) * b.size(1) - 1;
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (b[loop_ub] < 0.0F) {
      trueCount++;
    }
  }
  r3.set_size(&ce_emlrtRTEI, &st, trueCount);
  trueCount = 0;
  for (loop_ub = 0; loop_ub <= end; loop_ub++) {
    if (b[loop_ub] < 0.0F) {
      r3[trueCount] = loop_ub + 1;
      trueCount++;
    }
  }
  loop_ub = r3.size(0) - 1;
  trueCount = b.size(0) * b.size(1);
  for (i = 0; i <= loop_ub; i++) {
    if ((r3[i] < 1) || (r3[i] > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &n_emlrtBCI, &st);
    }
    b[r3[i] - 1] = 0.0F;
  }
  st.site = &xb_emlrtRSI;
  b_st.site = &ld_emlrtRSI;
  power(&b_st, Ig, a);
  b_st.site = &md_emlrtRSI;
  power(&b_st, Iy, I_45);
  b_iv[0] = (*(int32_T(*)[2])Ig.size())[0];
  b_iv[1] = (*(int32_T(*)[2])Ig.size())[1];
  iv1[0] = (*(int32_T(*)[2])Iy.size())[0];
  iv1[1] = (*(int32_T(*)[2])Iy.size())[1];
  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &k_emlrtECI, &st);
  b_st.site = &nd_emlrtRSI;
  c_imfilter(&b_st, a);
  b_st.site = &od_emlrtRSI;
  c_imfilter(&b_st, I_45);
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Ig[i] = Ig[i] * Iy[i];
  }
  b_st.site = &pd_emlrtRSI;
  c_imfilter(&b_st, Ig);
  st.site = &yb_emlrtRSI;
  find_peaks(&st, cxy, points0);
  st.site = &ac_emlrtRSI;
  loop_ub = points0.size(0);
  b_points0.set_size(&de_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = points0[i + points0.size(0)];
  }
  loop_ub = points0.size(0);
  c_points0.set_size(&ee_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    c_points0[i] = points0[i];
  }
  b_iv[0] = (*(int32_T(*)[2])cxy.size())[0];
  b_iv[1] = (*(int32_T(*)[2])cxy.size())[1];
  b_st.site = &vf_emlrtRSI;
  eml_sub2ind(&b_st, b_iv, b_points0, c_points0, r2);
  s.set_size(&fe_emlrtRTEI, &st, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = r2[i];
  }
  b_iv[0] = (*(int32_T(*)[2])cxy.size())[0];
  b_iv[1] = (*(int32_T(*)[2])cxy.size())[1];
  st.site = &ac_emlrtRSI;
  ::coder::internal::indexShapeCheck(&st, b_iv, s.size(0));
  trueCount = cxy.size(0) * cxy.size(1);
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    end = static_cast<int32_T>(s[i]);
    if ((end < 1) || (end > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &o_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  b_points0.set_size(&ge_emlrtRTEI, sp, s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = cxy[static_cast<int32_T>(s[i]) - 1];
  }
  st.site = &kc_emlrtRSI;
  board0 =
      growCheckerboard(&st, points0, b_points0, a, I_45, Ig, 0.0, &lobj_0[0]);
  points.set_size(&he_emlrtRTEI, sp, 0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  st.site = &bc_emlrtRSI;
  find_peaks(&st, b, points0);
  st.site = &cc_emlrtRSI;
  loop_ub = points0.size(0);
  b_points0.set_size(&ie_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = points0[i + points0.size(0)];
  }
  loop_ub = points0.size(0);
  c_points0.set_size(&je_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    c_points0[i] = points0[i];
  }
  b_iv[0] = (*(int32_T(*)[2])b.size())[0];
  b_iv[1] = (*(int32_T(*)[2])b.size())[1];
  b_st.site = &vf_emlrtRSI;
  eml_sub2ind(&b_st, b_iv, b_points0, c_points0, r2);
  s.set_size(&ke_emlrtRTEI, &st, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = r2[i];
  }
  b_iv[0] = (*(int32_T(*)[2])b.size())[0];
  b_iv[1] = (*(int32_T(*)[2])b.size())[1];
  st.site = &cc_emlrtRSI;
  ::coder::internal::indexShapeCheck(&st, b_iv, s.size(0));
  trueCount = b.size(0) * b.size(1);
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    end = static_cast<int32_T>(s[i]);
    if ((end < 1) || (end > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &p_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  b_points0.set_size(&le_emlrtRTEI, sp, s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = b[static_cast<int32_T>(s[i]) - 1];
  }
  st.site = &lc_emlrtRSI;
  board45 = growCheckerboard(&st, points0, b_points0, a, I_45, Ig,
                             0.78539816339744828, &lobj_0[3]);
  guard1 = false;
  guard2 = false;
  if (board0->isValid) {
    if (board0->Energy <= board45->Energy) {
      guard2 = true;
    } else {
      boolean_T exitg1;
      startT[0] = board0->BoardIdx.size(0);
      startT[1] = board0->BoardIdx.size(1);
      connDimsT[0] = board45->BoardIdx.size(0);
      connDimsT[1] = board45->BoardIdx.size(1);
      tooBig = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub < 2)) {
        if (startT[loop_ub] != connDimsT[loop_ub]) {
          tooBig = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (tooBig) {
        st.site = &dc_emlrtRSI;
        s.set_size(&me_emlrtRTEI, &st,
                   board0->BoardIdx.size(0) * board0->BoardIdx.size(1));
        loop_ub = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        for (i = 0; i < loop_ub; i++) {
          s[i] = board0->BoardIdx[i];
        }
        b_st.site = &bm_emlrtRSI;
        end = 0;
        i = s.size(0);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            end++;
          }
        }
        st.site = &dc_emlrtRSI;
        s.set_size(&ne_emlrtRTEI, &st,
                   board45->BoardIdx.size(0) * board45->BoardIdx.size(1));
        loop_ub = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        for (i = 0; i < loop_ub; i++) {
          s[i] = board45->BoardIdx[i];
        }
        b_st.site = &bm_emlrtRSI;
        trueCount = 0;
        i = s.size(0);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            trueCount++;
          }
        }
        if (end > trueCount) {
          guard2 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }
  if (guard2) {
    st.site = &ec_emlrtRSI;
    board0 = orient(&st, board0, b_I);
    st.site = &fc_emlrtRSI;
    toPoints(&st, board0, points, boardSize);
    st.site = &gc_emlrtRSI;
    subPixelLocation(&st, Ixy, points);
  }
  if (guard1 && board45->isValid) {
    st.site = &hc_emlrtRSI;
    board45 = orient(&st, board45, b_I);
    st.site = &ic_emlrtRSI;
    toPoints(&st, board45, points, boardSize);
    st.site = &jc_emlrtRSI;
    subPixelLocation(&st, I_45_x, points);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

Checkerboard *growCheckerboard(const emlrtStack *sp,
                               const ::coder::array<real32_T, 2U> &points,
                               const ::coder::array<real32_T, 1U> &scores,
                               const ::coder::array<real32_T, 2U> &Ix2,
                               const ::coder::array<real32_T, 2U> &Iy2,
                               const ::coder::array<real32_T, 2U> &Ixy,
                               real_T theta, Checkerboard *iobj_0)
{
  Checkerboard *board;
  Checkerboard *currentBoard;
  Checkerboard *tmpBoard;
  array<real_T, 2U> b_seedIdx;
  array<real_T, 2U> seedIdx;
  array<int32_T, 1U> iidx;
  array<real32_T, 1U> x;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_iv[2];
  real32_T b_x[2];
  real32_T v2[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (scores.size(0) == 0) {
    int32_T i;
    st.site = &bg_emlrtRSI;
    iobj_0[0].isValid = false;
    iobj_0[0].Energy = rtInfF;
    iobj_0[0].IsDistortionHigh = false;
    board = &iobj_0[0];
    iobj_0[0].BoardIdx.set_size(&kf_emlrtRTEI, &st, 1, 1);
    iobj_0[0].BoardIdx[0] = 0.0;
    iobj_0[0].BoardIdx.set_size(&lf_emlrtRTEI, &st, 3, 3);
    for (i = 0; i < 9; i++) {
      iobj_0[0].BoardIdx[i] = 0.0;
    }
    iobj_0[0].BoardCoords.set_size(&mf_emlrtRTEI, &st, 1, 1, 1);
    iobj_0[0].BoardCoords[0] = 0.0;
    iobj_0[0].BoardCoords.set_size(&nf_emlrtRTEI, &st, 3, 3, 2);
    for (i = 0; i < 18; i++) {
      iobj_0[0].BoardCoords[i] = 0.0;
    }
    iobj_0[0].Points.set_size(&of_emlrtRTEI, &st, 1, 1);
    iobj_0[0].Points[0] = 0.0F;
    iobj_0[0].Points.set_size(&pf_emlrtRTEI, &st, 0, 2);
  } else {
    int32_T b_i;
    int32_T i;
    int32_T sgn2;
    if (points.size(0) < 1) {
      seedIdx.set_size(&gf_emlrtRTEI, sp, 1, 0);
    } else {
      seedIdx.set_size(&gf_emlrtRTEI, sp, 1, points.size(0));
      sgn2 = points.size(0) - 1;
      for (i = 0; i <= sgn2; i++) {
        seedIdx[i] = static_cast<real_T>(i) + 1.0;
      }
    }
    b_iv[0] = (*(int32_T(*)[2])seedIdx.size())[0];
    b_iv[1] = (*(int32_T(*)[2])seedIdx.size())[1];
    st.site = &cg_emlrtRSI;
    ::coder::internal::indexShapeCheck(&st, scores.size(0), b_iv);
    st.site = &cg_emlrtRSI;
    sgn2 = seedIdx.size(1);
    for (i = 0; i < sgn2; i++) {
      b_i = static_cast<int32_T>(seedIdx[i]);
      if (seedIdx[i] != b_i) {
        emlrtIntegerCheckR2012b(seedIdx[i], &g_emlrtDCI, &st);
      }
      if (b_i > scores.size(0)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, scores.size(0), &nb_emlrtBCI,
                                      &st);
      }
    }
    x.set_size(&hf_emlrtRTEI, &st, seedIdx.size(1));
    sgn2 = seedIdx.size(1);
    for (i = 0; i < sgn2; i++) {
      x[i] = scores[static_cast<int32_T>(seedIdx[i]) - 1];
    }
    b_st.site = &kg_emlrtRSI;
    ::coder::internal::sort(&b_st, x, iidx);
    b_iv[0] = (*(int32_T(*)[2])seedIdx.size())[0];
    b_iv[1] = (*(int32_T(*)[2])seedIdx.size())[1];
    st.site = &dg_emlrtRSI;
    ::coder::internal::b_indexShapeCheck(&st, b_iv, iidx.size(0));
    b_seedIdx.set_size(&if_emlrtRTEI, sp, 1, iidx.size(0));
    sgn2 = iidx.size(0);
    for (i = 0; i < sgn2; i++) {
      if ((iidx[i] < 1) || (iidx[i] > seedIdx.size(1))) {
        emlrtDynamicBoundsCheckR2012b(iidx[i], 1, seedIdx.size(1), &ob_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_seedIdx[i] = static_cast<uint32_T>(seedIdx[iidx[i] - 1]);
    }
    seedIdx.set_size(&if_emlrtRTEI, sp, 1, b_seedIdx.size(1));
    sgn2 = b_seedIdx.size(1);
    for (i = 0; i < sgn2; i++) {
      seedIdx[i] = b_seedIdx[i];
    }
    if (iidx.size(0) > 2000) {
      sgn2 = static_cast<int32_T>(muDoubleScalarMin(
          2000.0,
          muDoubleScalarRound(static_cast<real_T>(seedIdx.size(1)) / 2.0)));
      if (1 > sgn2) {
        sgn2 = 0;
      } else {
        if (1 > seedIdx.size(1)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, seedIdx.size(1), &kb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (sgn2 > seedIdx.size(1)) {
          emlrtDynamicBoundsCheckR2012b(sgn2, 1, seedIdx.size(1), &lb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      b_seedIdx.set_size(&jf_emlrtRTEI, sp, 1, sgn2);
      for (i = 0; i < sgn2; i++) {
        b_seedIdx[i] = static_cast<uint32_T>(seedIdx[i]);
      }
      seedIdx.set_size(&jf_emlrtRTEI, sp, 1, b_seedIdx.size(1));
      sgn2 = b_seedIdx.size(1);
      for (i = 0; i < sgn2; i++) {
        seedIdx[i] = b_seedIdx[i];
      }
    }
    st.site = &eg_emlrtRSI;
    board = iobj_0[1].init(&st);
    st.site = &fg_emlrtRSI;
    currentBoard = iobj_0[2].init(&st);
    i = seedIdx.size(1);
    for (b_i = 0; b_i < i; b_i++) {
      real_T d;
      real_T d1;
      int32_T b_a;
      real32_T a;
      real32_T ab;
      real32_T adf;
      real32_T b;
      real32_T c;
      real32_T df;
      real32_T tb;
      if (b_i + 1 > seedIdx.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, seedIdx.size(1), &pb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      sgn2 = static_cast<int32_T>(static_cast<uint32_T>(seedIdx[b_i]));
      if (sgn2 > points.size(0)) {
        emlrtDynamicBoundsCheckR2012b(sgn2, 1, points.size(0), &mb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_x[0] = muSingleScalarRound(points[sgn2 - 1]);
      b_x[1] = muSingleScalarRound(points[(sgn2 + points.size(0)) - 1]);
      st.site = &gg_emlrtRSI;
      d = muSingleScalarRound(points[(sgn2 + points.size(0)) - 1]);
      if (static_cast<real_T>(b_x[1]) != static_cast<int32_T>(b_x[1])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[1]), &h_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d)) > Ix2.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d)), 1, Ix2.size(0),
            &qb_emlrtBCI, &st);
      }
      d1 = muSingleScalarRound(points[sgn2 - 1]);
      if (static_cast<real_T>(b_x[0]) != static_cast<int32_T>(b_x[0])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[0]), &i_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d1)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d1)) > Ix2.size(1))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d1)), 1, Ix2.size(1),
            &rb_emlrtBCI, &st);
      }
      a = Ix2[(static_cast<int32_T>(static_cast<real32_T>(
                   static_cast<int32_T>(static_cast<real32_T>(d)))) +
               Ix2.size(0) *
                   (static_cast<int32_T>(static_cast<real32_T>(
                        static_cast<int32_T>(static_cast<real32_T>(d1)))) -
                    1)) -
              1];
      if (static_cast<real_T>(b_x[1]) != static_cast<int32_T>(b_x[1])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[1]), &j_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d)) > Ixy.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d)), 1, Ixy.size(0),
            &sb_emlrtBCI, &st);
      }
      if (static_cast<real_T>(b_x[0]) != static_cast<int32_T>(b_x[0])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[0]), &k_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d1)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d1)) > Ixy.size(1))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d1)), 1, Ixy.size(1),
            &tb_emlrtBCI, &st);
      }
      b = Ixy[(static_cast<int32_T>(static_cast<real32_T>(
                   static_cast<int32_T>(static_cast<real32_T>(d)))) +
               Ixy.size(0) *
                   (static_cast<int32_T>(static_cast<real32_T>(
                        static_cast<int32_T>(static_cast<real32_T>(d1)))) -
                    1)) -
              1];
      if (static_cast<real_T>(b_x[1]) != static_cast<int32_T>(b_x[1])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[1]), &l_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d)) > Iy2.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d)), 1, Iy2.size(0),
            &ub_emlrtBCI, &st);
      }
      if (static_cast<real_T>(b_x[0]) != static_cast<int32_T>(b_x[0])) {
        emlrtIntegerCheckR2012b(static_cast<real_T>(b_x[0]), &m_emlrtDCI, &st);
      }
      if ((static_cast<int32_T>(static_cast<real32_T>(d1)) < 1) ||
          (static_cast<int32_T>(static_cast<real32_T>(d1)) > Iy2.size(1))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<real32_T>(d1)), 1, Iy2.size(1),
            &vb_emlrtBCI, &st);
      }
      c = Iy2[(static_cast<int32_T>(static_cast<real32_T>(
                   static_cast<int32_T>(static_cast<real32_T>(d)))) +
               Iy2.size(0) *
                   (static_cast<int32_T>(static_cast<real32_T>(
                        static_cast<int32_T>(static_cast<real32_T>(d1)))) -
                    1)) -
              1];
      df = a - c;
      adf = muSingleScalarAbs(df);
      tb = b + b;
      ab = muSingleScalarAbs(tb);
      if (adf > ab) {
        b = ab / adf;
        b = adf * muSingleScalarSqrt(b * b + 1.0F);
      } else if (adf < ab) {
        b = adf / ab;
        b = ab * muSingleScalarSqrt(b * b + 1.0F);
      } else {
        b = ab * 1.41421354F;
      }
      if (df > 0.0F) {
        adf = df + b;
        sgn2 = 1;
      } else {
        adf = df - b;
        sgn2 = -1;
      }
      if (muSingleScalarAbs(adf) > ab) {
        adf = -tb / adf;
        b_st.site = &vh_emlrtRSI;
        b = adf * adf + 1.0F;
        if (b < 0.0F) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &ab_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        df = 1.0F / muSingleScalarSqrt(b);
        b = adf * df;
      } else if (ab == 0.0F) {
        b = 1.0F;
        df = 0.0F;
      } else {
        adf = -adf / tb;
        b_st.site = &wh_emlrtRSI;
        b = adf * adf + 1.0F;
        if (b < 0.0F) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &ab_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        b = 1.0F / muSingleScalarSqrt(b);
        df = adf * b;
      }
      if (a + c < 0.0F) {
        b_a = -1;
      } else {
        b_a = 1;
      }
      if (b_a == sgn2) {
        adf = b;
        b = -df;
        df = adf;
      }
      b_x[0] = -df * 0.707106769F + b * 0.707106769F;
      adf = -df * -0.707106769F + b * 0.707106769F;
      b_x[1] = adf;
      v2[0] = b * 0.707106769F + df * 0.707106769F;
      b = b * -0.707106769F + df * 0.707106769F;
      v2[1] = b;
      if ((!(muSingleScalarAbs(
                 muSingleScalarAbs(
                     muSingleScalarAbs(muSingleScalarAtan2(adf, b_x[0])) -
                     3.14159274F) -
                 static_cast<real32_T>(theta)) > 0.58904862254808621)) ||
          (!(muSingleScalarAbs(
                 muSingleScalarAbs(
                     muSingleScalarAbs(muSingleScalarAtan2(b, v2[0])) -
                     3.14159274F) -
                 static_cast<real32_T>(theta)) > 0.58904862254808621))) {
        if (b_i + 1 > seedIdx.size(1)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, seedIdx.size(1),
                                        &wb_emlrtBCI, (emlrtCTX)sp);
        }
        st.site = &hg_emlrtRSI;
        currentBoard->initialize(
            &st, static_cast<real_T>(static_cast<uint32_T>(seedIdx[b_i])),
            points, b_x, v2);
        st.site = &ig_emlrtRSI;
        currentBoard->expandBoardFully(&st);
        if (currentBoard->Energy < board->Energy) {
          tmpBoard = board;
          board = currentBoard;
          currentBoard = tmpBoard;
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return board;
}

Checkerboard *orient(const emlrtStack *sp, Checkerboard *board,
                     const ::coder::array<real32_T, 2U> &b_I)
{
  Checkerboard *b_board;
  array<real_T, 3U> r;
  array<real_T, 3U> r1;
  array<real_T, 3U> r2;
  array<real_T, 2U> c_board;
  array<real_T, 2U> newBoardCoords1;
  array<real_T, 2U> newBoardCoords2;
  array<real_T, 2U> numRot;
  array<int32_T, 1U> r4;
  array<int32_T, 1U> r5;
  array<real32_T, 1U> c_I;
  array<int8_T, 2U> ii;
  array<boolean_T, 3U> r3;
  array<boolean_T, 2U> nextSquareMask;
  array<boolean_T, 2U> upperLeftMask;
  array<boolean_T, 2U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T cornerIdx[4];
  real_T upperLeftPolyY[4];
  int32_T b_iv[3];
  int32_T iv1[3];
  int32_T iv2[2];
  int32_T iv3[2];
  real32_T x;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  b_board = board;
  x = b_board->Energy;
  if (!muSingleScalarIsInf(x)) {
    int32_T i;
    int32_T i1;
    int32_T i2;
    int32_T loop_ub;
    int32_T npages;
    boolean_T exitg1;
    boolean_T p;
    boolean_T t;
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      st.site = &sr_emlrtRSI;
      c_board.set_size(&pp_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                       b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        c_board[i] = b_board->BoardIdx[i];
      }
      b_st.site = &fs_emlrtRSI;
      rot90(&b_st, c_board, b_board->BoardIdx);
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &eq_emlrtBCI, &st);
      }
      loop_ub = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(1);
      c_board.set_size(&qp_emlrtRTEI, &st, loop_ub, npages);
      for (i = 0; i < npages; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_board[i1 + c_board.size(0) * i] =
              b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
        }
      }
      b_st.site = &gs_emlrtRSI;
      rot90(&b_st, c_board, newBoardCoords1);
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &dq_emlrtBCI, &st);
      }
      loop_ub = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(1);
      c_board.set_size(&rp_emlrtRTEI, &st, loop_ub, npages);
      for (i = 0; i < npages; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_board[i1 + c_board.size(0) * i] =
              b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                   b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)];
        }
      }
      b_st.site = &hs_emlrtRSI;
      rot90(&b_st, c_board, newBoardCoords2);
      b_st.site = &is_emlrtRSI;
      cat(&b_st, newBoardCoords1, newBoardCoords2, r);
      b_board->BoardCoords.set_size(&sp_emlrtRTEI, &st, r.size(0), r.size(1),
                                    2);
      loop_ub = r.size(0) * r.size(1) * 2;
      for (i = 0; i < loop_ub; i++) {
        b_board->BoardCoords[i] = r[i];
      }
    }
    st.site = &tr_emlrtRSI;
    newBoardCoords1.set_size(&tp_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                             b_board->BoardIdx.size(1));
    loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      newBoardCoords1[i] = b_board->BoardIdx[i];
    }
    b_st.site = &gj_emlrtRSI;
    if ((newBoardCoords1.size(0) == 0) && (newBoardCoords1.size(1) == 0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &vb_emlrtRTEI, "Coder:toolbox:eml_all_or_any_specialEmpty",
          "Coder:toolbox:eml_all_or_any_specialEmpty", 0);
    }
    if ((newBoardCoords1.size(0) == 1) && (newBoardCoords1.size(1) != 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &gb_emlrtRTEI,
          "Coder:toolbox:eml_all_or_any_autoDimIncompatibility",
          "Coder:toolbox:eml_all_or_any_autoDimIncompatibility", 0);
    }
    y.set_size(&up_emlrtRTEI, &b_st, 1, newBoardCoords1.size(1));
    loop_ub = newBoardCoords1.size(1);
    for (i = 0; i < loop_ub; i++) {
      y[i] = true;
    }
    npages = newBoardCoords1.size(1);
    i2 = 0;
    c_st.site = &os_emlrtRSI;
    if ((1 <= newBoardCoords1.size(1)) &&
        (newBoardCoords1.size(1) > 2147483646)) {
      d_st.site = &ed_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (i = 0; i < npages; i++) {
      loop_ub = i2 + newBoardCoords1.size(0);
      i1 = i2 + 1;
      i2 += newBoardCoords1.size(0);
      c_st.site = &fj_emlrtRSI;
      if ((i1 <= loop_ub) && (loop_ub > 2147483646)) {
        d_st.site = &ed_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      exitg1 = false;
      while ((!exitg1) && (i1 <= loop_ub)) {
        if (newBoardCoords1[i1 - 1] == 0.0) {
          y[i] = false;
          exitg1 = true;
        } else {
          i1++;
        }
      }
    }
    st.site = &tr_emlrtRSI;
    if (::coder::internal::ifWhileCond(&st, y)) {
      real32_T b_y;
      st.site = &ur_emlrtRSI;
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &es_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &ds_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &cs_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &bs_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &as_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &yr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &xr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &wr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &vr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &ur_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &tr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &sr_emlrtBCI, &st);
      }
      cornerIdx[0] = b_board->BoardCoords[0];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[2] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      cornerIdx[3] = b_board->BoardCoords[1];
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &rr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &qr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &pr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &or_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &nr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &mr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &lr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &kr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &jr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &ir_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &hr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &gr_emlrtBCI, &st);
      }
      upperLeftPolyY[0] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                               b_board->BoardCoords.size(1)];
      upperLeftPolyY[1] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) +
                               b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)];
      upperLeftPolyY[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) +
                               1];
      upperLeftPolyY[3] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1) +
                               1];
      b_st.site = &rs_emlrtRSI;
      poly2RectMask(&b_st, cornerIdx, upperLeftPolyY,
                    static_cast<real_T>(b_I.size(0)),
                    static_cast<real_T>(b_I.size(1)), upperLeftMask);
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &fr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &er_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &dr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &cr_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (3 > i) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i, &br_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &ar_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &yq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (3 > i) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i, &xq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &wq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &vq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &uq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &tq_emlrtBCI, &st);
      }
      cornerIdx[0] = b_board->BoardCoords[b_board->BoardCoords.size(0)];
      cornerIdx[1] = b_board->BoardCoords[b_board->BoardCoords.size(0) * 2];
      cornerIdx[2] = b_board->BoardCoords[b_board->BoardCoords.size(0) * 2 + 1];
      cornerIdx[3] = b_board->BoardCoords[b_board->BoardCoords.size(0) + 1];
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &sq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &rq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &qq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &pq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (3 > i) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i, &oq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &nq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &mq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (3 > i) {
        emlrtDynamicBoundsCheckR2012b(3, 1, i, &lq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &kq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(0);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &jq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(1);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &iq_emlrtBCI, &st);
      }
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &hq_emlrtBCI, &st);
      }
      upperLeftPolyY[0] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) +
                               b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)];
      upperLeftPolyY[1] =
          b_board->BoardCoords[b_board->BoardCoords.size(0) * 2 +
                               b_board->BoardCoords.size(0) *
                                   b_board->BoardCoords.size(1)];
      upperLeftPolyY[2] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) * 2 +
                                b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) +
                               1];
      upperLeftPolyY[3] =
          b_board->BoardCoords[(b_board->BoardCoords.size(0) +
                                b_board->BoardCoords.size(0) *
                                    b_board->BoardCoords.size(1)) +
                               1];
      b_st.site = &ss_emlrtRSI;
      poly2RectMask(&b_st, cornerIdx, upperLeftPolyY,
                    static_cast<real_T>(b_I.size(0)),
                    static_cast<real_T>(b_I.size(1)), nextSquareMask);
      iv2[0] =
          (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[0];
      iv2[1] =
          (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[1];
      iv3[0] = (*(int32_T(*)[2])upperLeftMask.size())[0];
      iv3[1] = (*(int32_T(*)[2])upperLeftMask.size())[1];
      b_st.site = &ts_emlrtRSI;
      ::coder::internal::indexShapeCheck(&b_st, iv2, iv3);
      iv2[0] =
          (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[0];
      iv2[1] =
          (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[1];
      iv3[0] = (*(int32_T(*)[2])nextSquareMask.size())[0];
      iv3[1] = (*(int32_T(*)[2])nextSquareMask.size())[1];
      b_st.site = &ts_emlrtRSI;
      ::coder::internal::indexShapeCheck(&b_st, iv2, iv3);
      i2 = upperLeftMask.size(0) * upperLeftMask.size(1) - 1;
      npages = 0;
      for (i = 0; i <= i2; i++) {
        if (upperLeftMask[i]) {
          npages++;
        }
      }
      r4.set_size(&eq_emlrtRTEI, &st, npages);
      npages = 0;
      for (i = 0; i <= i2; i++) {
        if (upperLeftMask[i]) {
          r4[npages] = i + 1;
          npages++;
        }
      }
      i2 = nextSquareMask.size(0) * nextSquareMask.size(1) - 1;
      npages = 0;
      for (i = 0; i <= i2; i++) {
        if (nextSquareMask[i]) {
          npages++;
        }
      }
      r5.set_size(&eq_emlrtRTEI, &st, npages);
      npages = 0;
      for (i = 0; i <= i2; i++) {
        if (nextSquareMask[i]) {
          r5[npages] = i + 1;
          npages++;
        }
      }
      b_st.site = &ts_emlrtRSI;
      npages = b_I.size(0) * b_I.size(1);
      c_I.set_size(&fq_emlrtRTEI, &b_st, r4.size(0));
      loop_ub = r4.size(0);
      for (i = 0; i < loop_ub; i++) {
        if ((r4[i] < 1) || (r4[i] > npages)) {
          emlrtDynamicBoundsCheckR2012b(r4[i], 1, npages, &bt_emlrtBCI, &b_st);
        }
        c_I[i] = b_I[r4[i] - 1];
      }
      c_st.site = &ts_emlrtRSI;
      x = mean(&c_st, c_I);
      c_st.site = &nl_emlrtRSI;
      b_y = sumColumnB(x);
      b_st.site = &ts_emlrtRSI;
      npages = b_I.size(0) * b_I.size(1);
      c_I.set_size(&gq_emlrtRTEI, &b_st, r5.size(0));
      loop_ub = r5.size(0);
      for (i = 0; i < loop_ub; i++) {
        if ((r5[i] < 1) || (r5[i] > npages)) {
          emlrtDynamicBoundsCheckR2012b(r5[i], 1, npages, &ct_emlrtBCI, &b_st);
        }
        c_I[i] = b_I[r5[i] - 1];
      }
      c_st.site = &ts_emlrtRSI;
      x = mean(&c_st, c_I);
      c_st.site = &nl_emlrtRSI;
      x = sumColumnB(x);
      if (!(b_y < x)) {
        st.site = &vr_emlrtRSI;
        c_board.set_size(&pp_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                         b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          c_board[i] = b_board->BoardIdx[i];
        }
        b_st.site = &fs_emlrtRSI;
        b_rot90(&b_st, c_board, b_board->BoardIdx);
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &eq_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&qp_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
          }
        }
        b_st.site = &gs_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords1);
        i = b_board->BoardCoords.size(2);
        if (2 > i) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i, &dq_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&rp_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                     b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1)];
          }
        }
        b_st.site = &hs_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords2);
        b_st.site = &is_emlrtRSI;
        cat(&b_st, newBoardCoords1, newBoardCoords2, r);
        b_board->BoardCoords.set_size(&sp_emlrtRTEI, &st, r.size(0), r.size(1),
                                      2);
        loop_ub = r.size(0) * r.size(1) * 2;
        for (i = 0; i < loop_ub; i++) {
          b_board->BoardCoords[i] = r[i];
        }
      }
    } else {
      st.site = &wr_emlrtRSI;
      i = b_board->BoardIdx.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &is_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &hs_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &gs_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &fs_emlrtBCI, &st);
      }
      cornerIdx[0] = b_board->BoardIdx[0];
      i = b_board->BoardIdx.size(0);
      i1 = b_board->BoardIdx.size(0);
      if (i1 < 0) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, MAX_int32_T, &rs_emlrtBCI, &st);
      }
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qs_emlrtBCI, &st);
      }
      cornerIdx[1] = b_board->BoardIdx[i1 - 1];
      i = b_board->BoardIdx.size(0);
      i1 = b_board->BoardIdx.size(0);
      if (i1 < 0) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, MAX_int32_T, &ts_emlrtBCI, &st);
      }
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ss_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      npages = b_board->BoardIdx.size(1);
      if (npages < 0) {
        emlrtDynamicBoundsCheckR2012b(npages, 0, MAX_int32_T, &ts_emlrtBCI,
                                      &st);
      }
      if ((npages < 1) || (npages > i)) {
        emlrtDynamicBoundsCheckR2012b(npages, 1, i, &ss_emlrtBCI, &st);
      }
      cornerIdx[2] =
          b_board
              ->BoardIdx[(i1 + b_board->BoardIdx.size(0) * (npages - 1)) - 1];
      i = b_board->BoardIdx.size(1);
      i1 = b_board->BoardIdx.size(1);
      if (i1 < 0) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, MAX_int32_T, &vs_emlrtBCI, &st);
      }
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &us_emlrtBCI, &st);
      }
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) * (i1 - 1)];
      b_st.site = &ft_emlrtRSI;
      c_st.site = &nf_emlrtRSI;
      d_st.site = &of_emlrtRSI;
      npages = 0;
      ii.set_size(&vp_emlrtRTEI, &d_st, 1, 1);
      i2 = 0;
      exitg1 = false;
      while ((!exitg1) && (i2 < 4)) {
        if (cornerIdx[i2] != 0.0) {
          npages = 1;
          ii[0] = static_cast<int8_T>(i2 + 1);
          exitg1 = true;
        } else {
          i2++;
        }
      }
      if (npages == 0) {
        ii.set_size(&il_emlrtRTEI, &d_st, 1, 0);
      }
      numRot.set_size(&wp_emlrtRTEI, &st, 1, ii.size(1));
      loop_ub = ii.size(1);
      for (i = 0; i < loop_ub; i++) {
        numRot[0] = static_cast<real_T>(ii[0]) - 1.0;
      }
      if (ii.size(1) == 0) {
        numRot.set_size(&wp_emlrtRTEI, &st, 1, 1);
        numRot[0] = 0.0;
      }
      y.set_size(&xp_emlrtRTEI, sp, 1, 1);
      y[0] = (numRot[0] == 2.0);
      st.site = &xr_emlrtRSI;
      if (::coder::internal::ifWhileCond(&st, y)) {
        st.site = &yr_emlrtRSI;
        c_board.set_size(&pp_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                         b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          c_board[i] = b_board->BoardIdx[i];
        }
        b_st.site = &fs_emlrtRSI;
        b_rot90(&b_st, c_board, b_board->BoardIdx);
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &eq_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&qp_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
          }
        }
        b_st.site = &gs_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords1);
        i = b_board->BoardCoords.size(2);
        if (2 > i) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i, &dq_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&rp_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                     b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1)];
          }
        }
        b_st.site = &hs_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords2);
        b_st.site = &is_emlrtRSI;
        cat(&b_st, newBoardCoords1, newBoardCoords2, r);
        b_board->BoardCoords.set_size(&sp_emlrtRTEI, &st, r.size(0), r.size(1),
                                      2);
        loop_ub = r.size(0) * r.size(1) * 2;
        for (i = 0; i < loop_ub; i++) {
          b_board->BoardCoords[i] = r[i];
        }
      } else {
        p = (numRot.size(1) == 1);
        if (p && (numRot.size(1) != 0) && (!(numRot[0] == 1.0))) {
          p = false;
        }
        if (p) {
          i2 = 1;
        } else {
          p = (numRot.size(1) == 1);
          if (p && (numRot.size(1) != 0) && (!(numRot[0] == 3.0))) {
            p = false;
          }
          if (p) {
            i2 = 2;
          } else {
            i2 = 0;
          }
        }
        st.site = &as_emlrtRSI;
        if (i2 != 0) {
          st.site = &bs_emlrtRSI;
          newBoardCoords1.set_size(&yp_emlrtRTEI, &st,
                                   b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            newBoardCoords1[i] = b_board->BoardIdx[i];
          }
          b_st.site = &gt_emlrtRSI;
          flip(&b_st, newBoardCoords1, static_cast<real_T>(i2));
          b_board->BoardIdx.set_size(&aq_emlrtRTEI, &st,
                                     newBoardCoords1.size(0),
                                     newBoardCoords1.size(1));
          loop_ub = newBoardCoords1.size(0) * newBoardCoords1.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_board->BoardIdx[i] = newBoardCoords1[i];
          }
          i = b_board->BoardCoords.size(2);
          if (1 > i) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i, &gq_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(&bq_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords1[i1 + newBoardCoords1.size(0) * i] =
                  b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
            }
          }
          b_st.site = &ht_emlrtRSI;
          flip(&b_st, newBoardCoords1, static_cast<real_T>(i2));
          i = b_board->BoardCoords.size(2);
          if (2 > i) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i, &fq_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(&cq_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + newBoardCoords2.size(0) * i] =
                  b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                       b_board->BoardCoords.size(0) *
                                           b_board->BoardCoords.size(1)];
            }
          }
          b_st.site = &it_emlrtRSI;
          flip(&b_st, newBoardCoords2, static_cast<real_T>(i2));
          b_st.site = &jt_emlrtRSI;
          cat(&b_st, newBoardCoords1, newBoardCoords2, r);
          b_board->BoardCoords.set_size(&dq_emlrtRTEI, &st, r.size(0),
                                        r.size(1), 2);
          loop_ub = r.size(0) * r.size(1) * 2;
          for (i = 0; i < loop_ub; i++) {
            b_board->BoardCoords[i] = r[i];
          }
        }
      }
    }
    p = (b_mod(static_cast<real_T>(b_board->BoardCoords.size(0))) == 0.0);
    t = (b_mod(static_cast<real_T>(b_board->BoardCoords.size(1))) == 0.0);
    if (p == t) {
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &ps_emlrtBCI, (emlrtCTX)sp);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &os_emlrtBCI, (emlrtCTX)sp);
      }
      loop_ub = b_board->BoardCoords.size(2);
      r1.set_size(&hq_emlrtRTEI, sp, 1, 1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1) * i];
      }
      i = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(0);
      if (npages < 0) {
        emlrtDynamicBoundsCheckR2012b(npages, 0, MAX_int32_T, &ns_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if ((npages < 1) || (npages > i)) {
        emlrtDynamicBoundsCheckR2012b(npages, 1, i, &ms_emlrtBCI, (emlrtCTX)sp);
      }
      i = b_board->BoardCoords.size(1);
      i2 = b_board->BoardCoords.size(1);
      if (i2 < 0) {
        emlrtDynamicBoundsCheckR2012b(i2, 0, MAX_int32_T, &ls_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ks_emlrtBCI, (emlrtCTX)sp);
      }
      loop_ub = b_board->BoardCoords.size(2);
      r2.set_size(&iq_emlrtRTEI, sp, 1, 1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r2[i] = b_board->BoardCoords[((npages + b_board->BoardCoords.size(0) *
                                                    (i2 - 1)) +
                                      b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1) * i) -
                                     1];
      }
      b_iv[0] = (*(int32_T(*)[3])r1.size())[0];
      b_iv[1] = (*(int32_T(*)[3])r1.size())[1];
      b_iv[2] = (*(int32_T(*)[3])r1.size())[2];
      iv1[0] = (*(int32_T(*)[3])r2.size())[0];
      iv1[1] = (*(int32_T(*)[3])r2.size())[1];
      iv1[2] = (*(int32_T(*)[3])r2.size())[2];
      emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &wc_emlrtECI, (emlrtCTX)sp);
      r3.set_size(&hq_emlrtRTEI, sp, 1, 1, r1.size(2));
      loop_ub = r1.size(2);
      for (i = 0; i < loop_ub; i++) {
        r3[i] = (r1[i] > r2[i]);
      }
      st.site = &cs_emlrtRSI;
      if (d_any(&st, r3)) {
        real_T b_x;
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &js_emlrtBCI, (emlrtCTX)sp);
        }
        i = b_board->BoardCoords.size(0);
        i1 = b_board->BoardCoords.size(0);
        if (i1 < 0) {
          emlrtDynamicBoundsCheckR2012b(i1, 0, MAX_int32_T, &xs_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ws_emlrtBCI, (emlrtCTX)sp);
        }
        i = b_board->BoardCoords.size(1);
        npages = b_board->BoardCoords.size(1);
        if (npages < 0) {
          emlrtDynamicBoundsCheckR2012b(npages, 0, MAX_int32_T, &at_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if ((npages < 1) || (npages > i)) {
          emlrtDynamicBoundsCheckR2012b(npages, 1, i, &ys_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_x = b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) *
                                             (npages - 1)) -
                                   1];
        st.site = &ds_emlrtRSI;
        if (muDoubleScalarIsNaN(b_x)) {
          emlrtErrorWithMessageIdR2018a(&st, &u_emlrtRTEI,
                                        "MATLAB:nologicalnan",
                                        "MATLAB:nologicalnan", 0);
        }
        if (b_x != 0.0) {
          st.site = &es_emlrtRSI;
          c_board.set_size(&pp_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                           b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            c_board[i] = b_board->BoardIdx[i];
          }
          b_st.site = &fs_emlrtRSI;
          b_rot90(&b_st, c_board, b_board->BoardIdx);
          i = b_board->BoardCoords.size(2);
          if (1 > i) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i, &eq_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          c_board.set_size(&qp_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_board[i1 + c_board.size(0) * i] =
                  b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
            }
          }
          b_st.site = &gs_emlrtRSI;
          b_rot90(&b_st, c_board, newBoardCoords1);
          i = b_board->BoardCoords.size(2);
          if (2 > i) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i, &dq_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          c_board.set_size(&rp_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_board[i1 + c_board.size(0) * i] =
                  b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                       b_board->BoardCoords.size(0) *
                                           b_board->BoardCoords.size(1)];
            }
          }
          b_st.site = &hs_emlrtRSI;
          b_rot90(&b_st, c_board, newBoardCoords2);
          b_st.site = &is_emlrtRSI;
          cat(&b_st, newBoardCoords1, newBoardCoords2, r);
          b_board->BoardCoords.set_size(&sp_emlrtRTEI, &st, r.size(0),
                                        r.size(1), 2);
          loop_ub = r.size(0) * r.size(1) * 2;
          for (i = 0; i < loop_ub; i++) {
            b_board->BoardCoords[i] = r[i];
          }
        }
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return b_board;
}

void toPoints(const emlrtStack *sp, const Checkerboard *b_this,
              ::coder::array<real_T, 2U> &points, real_T boardSize[2])
{
  array<real_T, 2U> x;
  array<int32_T, 1U> r;
  array<boolean_T, 1U> d_this;
  emlrtStack st;
  int32_T c_this;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  c_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  d_this.set_size(&nq_emlrtRTEI, sp, c_this);
  for (i = 0; i < c_this; i++) {
    d_this[i] = (b_this->BoardIdx[i] == 0.0);
  }
  st.site = &st_emlrtRSI;
  if (b_any(&st, d_this)) {
    points.set_size(&tq_emlrtRTEI, sp, 0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    real_T numPoints;
    int32_T i1;
    int32_T loop_ub;
    numPoints = static_cast<real_T>(b_this->BoardCoords.size(0)) *
                static_cast<real_T>(b_this->BoardCoords.size(1));
    if (!(numPoints >= 0.0)) {
      emlrtNonNegativeCheckR2012b(numPoints, &jg_emlrtDCI, (emlrtCTX)sp);
    }
    if (numPoints != static_cast<int32_T>(numPoints)) {
      emlrtIntegerCheckR2012b(numPoints, &ig_emlrtDCI, (emlrtCTX)sp);
    }
    points.set_size(&oq_emlrtRTEI, sp, static_cast<int32_T>(numPoints), 2);
    if (numPoints != static_cast<int32_T>(numPoints)) {
      emlrtIntegerCheckR2012b(numPoints, &kg_emlrtDCI, (emlrtCTX)sp);
    }
    c_this = static_cast<int32_T>(numPoints) << 1;
    for (i = 0; i < c_this; i++) {
      points[i] = 0.0;
    }
    i = b_this->BoardCoords.size(2);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &ht_emlrtBCI, (emlrtCTX)sp);
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    x.set_size(&pq_emlrtRTEI, sp, loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1 + x.size(0) * i] =
            b_this->BoardCoords[i + b_this->BoardCoords.size(0) * i1];
      }
    }
    c_this = static_cast<int32_T>(numPoints);
    r.set_size(&qq_emlrtRTEI, sp, static_cast<int32_T>(numPoints));
    for (i = 0; i < c_this; i++) {
      r[i] = i;
    }
    c_this = x.size(0) * x.size(1);
    emlrtSubAssignSizeCheckR2012b(r.size(), 1, &c_this, 1, &xc_emlrtECI,
                                  (emlrtCTX)sp);
    c_this = x.size(0) * x.size(1);
    for (i = 0; i < c_this; i++) {
      points[r[i]] = x[i];
    }
    i = b_this->BoardCoords.size(2);
    if (2 > i) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i, &it_emlrtBCI, (emlrtCTX)sp);
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    x.set_size(&rq_emlrtRTEI, sp, loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1 + x.size(0) * i] =
            b_this->BoardCoords[(i + b_this->BoardCoords.size(0) * i1) +
                                b_this->BoardCoords.size(0) *
                                    b_this->BoardCoords.size(1)];
      }
    }
    c_this = points.size(0);
    r.set_size(&sq_emlrtRTEI, sp, points.size(0));
    for (i = 0; i < c_this; i++) {
      r[i] = i;
    }
    c_this = x.size(0) * x.size(1);
    emlrtSubAssignSizeCheckR2012b(r.size(), 1, &c_this, 1, &yc_emlrtECI,
                                  (emlrtCTX)sp);
    c_this = x.size(0) * x.size(1);
    for (i = 0; i < c_this; i++) {
      points[r[i] + points.size(0)] = x[i];
    }
    boardSize[0] = static_cast<real_T>(b_this->BoardCoords.size(1)) + 1.0;
    boardSize[1] = static_cast<real_T>(b_this->BoardCoords.size(0)) + 1.0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder

// End of code generation (detectCheckerboard.cpp)
