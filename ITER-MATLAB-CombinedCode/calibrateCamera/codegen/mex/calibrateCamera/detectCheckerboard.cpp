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
#include "abs.h"
#include "any1.h"
#include "calibrateCamera_data.h"
#include "cat.h"
#include "eml_int_forloop_overflow_check.h"
#include "find_peaks.h"
#include "flip.h"
#include "ifWhileCond.h"
#include "imfilter.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "mean.h"
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
static emlrtRSInfo ef_emlrtRSI{
    78,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    85,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gf_emlrtRSI{
    86,                 // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    118,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    119,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    121,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo kf_emlrtRSI{
    128,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo lf_emlrtRSI{
    129,                // lineNo
    "growCheckerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo tg_emlrtRSI{
    192,                  // lineNo
    "cornerOrientations", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ug_emlrtRSI{
    200,                  // lineNo
    "cornerOrientations", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo sp_emlrtRSI{
    247,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo tp_emlrtRSI{
    251,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo up_emlrtRSI{
    252,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo vp_emlrtRSI{
    253,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo wp_emlrtRSI{
    258,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo xp_emlrtRSI{
    259,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo yp_emlrtRSI{
    260,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo aq_emlrtRSI{
    270,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo bq_emlrtRSI{
    271,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo cq_emlrtRSI{
    280,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo dq_emlrtRSI{
    281,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo eq_emlrtRSI{
    282,      // lineNo
    "orient", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo fq_emlrtRSI{
    306,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gq_emlrtRSI{
    307,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo hq_emlrtRSI{
    308,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo iq_emlrtRSI{
    309,                  // lineNo
    "rot90_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo rq_emlrtRSI{
    332,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo sq_emlrtRSI{
    342,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo tq_emlrtRSI{
    346,                // lineNo
    "isUpperLeftBlack", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo fr_emlrtRSI{
    314,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo gr_emlrtRSI{
    315,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo hr_emlrtRSI{
    316,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo ir_emlrtRSI{
    317,                 // lineNo
    "flip_checkerboard", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtRSInfo nr_emlrtRSI{
    225,        // lineNo
    "toPoints", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pathName
};

static emlrtBCInfo yb_emlrtBCI{
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

static emlrtBCInfo ac_emlrtBCI{
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

static emlrtBCInfo bc_emlrtBCI{
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

static emlrtDCInfo e_emlrtDCI{
    85,                 // lineNo
    30,                 // colNo
    "growCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo cc_emlrtBCI{
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

static emlrtBCInfo dc_emlrtBCI{
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

static emlrtBCInfo ec_emlrtBCI{
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

static emlrtBCInfo fc_emlrtBCI{
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

static emlrtBCInfo gc_emlrtBCI{
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

static emlrtBCInfo hc_emlrtBCI{
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

static emlrtBCInfo ic_emlrtBCI{
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

static emlrtBCInfo jc_emlrtBCI{
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

static emlrtBCInfo kc_emlrtBCI{
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

static emlrtBCInfo lc_emlrtBCI{
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
    bb_emlrtRTEI{
        47,         // lineNo
        19,         // colNo
        "allOrAny", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pName
    };

static emlrtBCInfo rp_emlrtBCI{
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

static emlrtBCInfo sp_emlrtBCI{
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

static emlrtBCInfo tp_emlrtBCI{
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

static emlrtBCInfo up_emlrtBCI{
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

static emlrtBCInfo vp_emlrtBCI{
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

static emlrtBCInfo wp_emlrtBCI{
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

static emlrtBCInfo xp_emlrtBCI{
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

static emlrtBCInfo yp_emlrtBCI{
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
    pb_emlrtRTEI{
        44,         // lineNo
        19,         // colNo
        "allOrAny", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pName
    };

static emlrtBCInfo aq_emlrtBCI{
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

static emlrtECInfo xc_emlrtECI{
    3,        // nDims
    280,      // lineNo
    20,       // colNo
    "orient", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtBCInfo bq_emlrtBCI{
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

static emlrtBCInfo cq_emlrtBCI{
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

static emlrtBCInfo dq_emlrtBCI{
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

static emlrtBCInfo eq_emlrtBCI{
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

static emlrtBCInfo fq_emlrtBCI{
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

static emlrtBCInfo gq_emlrtBCI{
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

static emlrtBCInfo hq_emlrtBCI{
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

static emlrtBCInfo iq_emlrtBCI{
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

static emlrtBCInfo jq_emlrtBCI{
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

static emlrtBCInfo kq_emlrtBCI{
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

static emlrtBCInfo lq_emlrtBCI{
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

static emlrtBCInfo mq_emlrtBCI{
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

static emlrtBCInfo nq_emlrtBCI{
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

static emlrtBCInfo oq_emlrtBCI{
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

static emlrtBCInfo pq_emlrtBCI{
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

static emlrtBCInfo qq_emlrtBCI{
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

static emlrtBCInfo rq_emlrtBCI{
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

static emlrtBCInfo sq_emlrtBCI{
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

static emlrtBCInfo tq_emlrtBCI{
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

static emlrtBCInfo uq_emlrtBCI{
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

static emlrtBCInfo vq_emlrtBCI{
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

static emlrtBCInfo wq_emlrtBCI{
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

static emlrtBCInfo xq_emlrtBCI{
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

static emlrtBCInfo yq_emlrtBCI{
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

static emlrtBCInfo ar_emlrtBCI{
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

static emlrtBCInfo br_emlrtBCI{
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

static emlrtBCInfo cr_emlrtBCI{
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

static emlrtBCInfo dr_emlrtBCI{
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

static emlrtBCInfo er_emlrtBCI{
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

static emlrtBCInfo fr_emlrtBCI{
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

static emlrtBCInfo gr_emlrtBCI{
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
    28,                 // colNo
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
    336,                // lineNo
    37,                 // colNo
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
    336,                // lineNo
    40,                 // colNo
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
    336,                // lineNo
    43,                 // colNo
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
    337,                // lineNo
    22,                 // colNo
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
    337,                // lineNo
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
    337,                // lineNo
    28,                 // colNo
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
    337,                // lineNo
    49,                 // colNo
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
    337,                // lineNo
    52,                 // colNo
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
    337,                // lineNo
    55,                 // colNo
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
    338,                // lineNo
    22,                 // colNo
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
    338,                // lineNo
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
    338,                // lineNo
    28,                 // colNo
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
    339,                // lineNo
    37,                 // colNo
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
    339,                // lineNo
    40,                 // colNo
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
    339,                // lineNo
    43,                 // colNo
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
    340,                // lineNo
    22,                 // colNo
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
    340,                // lineNo
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
    340,                // lineNo
    28,                 // colNo
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
    340,                // lineNo
    49,                 // colNo
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
    340,                // lineNo
    52,                 // colNo
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
    340,                // lineNo
    55,                 // colNo
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
    341,                // lineNo
    22,                 // colNo
    "",                 // aName
    "isUpperLeftBlack", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    0                                                   // checkKind
};

static emlrtBCInfo gs_emlrtBCI{
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

static emlrtBCInfo hs_emlrtBCI{
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

static emlrtBCInfo is_emlrtBCI{
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

static emlrtBCInfo js_emlrtBCI{
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

static emlrtDCInfo dd_emlrtDCI{
    358,             // lineNo
    6,               // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ks_emlrtBCI{
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

static emlrtDCInfo ed_emlrtDCI{
    358,             // lineNo
    9,               // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ls_emlrtBCI{
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

static emlrtDCInfo fd_emlrtDCI{
    358,             // lineNo
    13,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ms_emlrtBCI{
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

static emlrtDCInfo gd_emlrtDCI{
    358,             // lineNo
    16,              // colNo
    "poly2RectMask", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtBCInfo ns_emlrtBCI{
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

static emlrtBCInfo os_emlrtBCI{
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

static emlrtBCInfo ps_emlrtBCI{
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

static emlrtECInfo yc_emlrtECI{
    -1,         // nDims
    234,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtECInfo ad_emlrtECI{
    -1,         // nDims
    236,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtDCInfo hd_emlrtDCI{
    232,        // lineNo
    16,         // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtDCInfo id_emlrtDCI{
    232,        // lineNo
    1,          // colNo
    "toPoints", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m", // pName
    1                                                   // checkKind
};

static emlrtRTEInfo ue_emlrtRTEI{
    84,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo we_emlrtRTEI{
    86,                   // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo xe_emlrtRTEI{
    88,                   // lineNo
    5,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo go_emlrtRTEI{
    306,                  // lineNo
    24,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo ho_emlrtRTEI{
    307,                  // lineNo
    25,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo io_emlrtRTEI{
    308,                  // lineNo
    25,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo jo_emlrtRTEI{
    309,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo ko_emlrtRTEI{
    251,                  // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo
    lo_emlrtRTEI{
        13,    // lineNo
        5,     // colNo
        "all", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\all.m" // pName
    };

static emlrtRTEInfo mo_emlrtRTEI{
    242,                  // lineNo
    18,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo no_emlrtRTEI{
    314,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo oo_emlrtRTEI{
    315,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo po_emlrtRTEI{
    316,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo qo_emlrtRTEI{
    317,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo ro_emlrtRTEI{
    280,                  // lineNo
    20,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo so_emlrtRTEI{
    280,                  // lineNo
    47,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo vo_emlrtRTEI{
    322,                  // lineNo
    15,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo wo_emlrtRTEI{
    346,                  // lineNo
    16,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo xo_emlrtRTEI{
    346,                  // lineNo
    47,                   // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo yo_emlrtRTEI{
    357,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo bp_emlrtRTEI{
    225,                  // lineNo
    8,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo cp_emlrtRTEI{
    232,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo dp_emlrtRTEI{
    233,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo ep_emlrtRTEI{
    235,                  // lineNo
    1,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

static emlrtRTEInfo fp_emlrtRTEI{
    226,                  // lineNo
    5,                    // colNo
    "detectCheckerboard", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "calibration\\+checkerboard\\detectCheckerboard.m" // pName
};

// Function Declarations
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static boolean_T isUpperLeftBlack(const emlrtStack *sp,
                                  const Checkerboard *b_this,
                                  const ::coder::array<real32_T, 2U> &b_I);

static void poly2RectMask(const emlrtStack *sp, real_T b_X[4], real_T Y[4],
                          real_T height, real_T width,
                          ::coder::array<boolean_T, 2U> &mask);

} // namespace checkerboard
} // namespace calibration
} // namespace internal
} // namespace vision
} // namespace coder
} // namespace Codegen

// Function Definitions
namespace Codegen {
namespace coder {
namespace vision {
namespace internal {
namespace calibration {
namespace checkerboard {
static boolean_T isUpperLeftBlack(const emlrtStack *sp,
                                  const Checkerboard *b_this,
                                  const ::coder::array<real32_T, 2U> &b_I)
{
  ::coder::array<int32_T, 1U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<real32_T, 1U> c_I;
  ::coder::array<boolean_T, 2U> nextSquareMask;
  ::coder::array<boolean_T, 2U> upperLeftMask;
  emlrtStack b_st;
  emlrtStack st;
  real_T c_this[4];
  real_T d_this[4];
  int32_T iv[2];
  int32_T iv1[2];
  int32_T end;
  int32_T i;
  int32_T trueCount;
  real32_T x;
  real32_T y;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &kq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &lq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &mq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &nq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &oq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &pq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &qq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &rq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &sq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &tq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &uq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &vq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &wq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &xq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &yq_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ar_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &br_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &cr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &dr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &er_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &fr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &gr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &hr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &ir_emlrtBCI, (emlrtCTX)sp);
  }
  c_this[0] = b_this->BoardCoords[0];
  c_this[1] = b_this->BoardCoords[b_this->BoardCoords.size(0)];
  c_this[2] = b_this->BoardCoords[b_this->BoardCoords.size(0) + 1];
  c_this[3] = b_this->BoardCoords[1];
  d_this[0] = b_this->BoardCoords[b_this->BoardCoords.size(0) *
                                  b_this->BoardCoords.size(1)];
  d_this[1] = b_this->BoardCoords[b_this->BoardCoords.size(0) +
                                  b_this->BoardCoords.size(0) *
                                      b_this->BoardCoords.size(1)];
  d_this[2] = b_this->BoardCoords[(b_this->BoardCoords.size(0) +
                                   b_this->BoardCoords.size(0) *
                                       b_this->BoardCoords.size(1)) +
                                  1];
  d_this[3] = b_this->BoardCoords[b_this->BoardCoords.size(0) *
                                      b_this->BoardCoords.size(1) +
                                  1];
  st.site = &rq_emlrtRSI;
  poly2RectMask(&st, c_this, d_this, static_cast<real_T>(b_I.size(0)),
                static_cast<real_T>(b_I.size(1)), upperLeftMask);
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &jr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &kr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &lr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &mr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (3 > i) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i, &nr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &or_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &pr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (3 > i) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i, &qr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &rr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &sr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &tr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ur_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &vr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &wr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &xr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (1 > i) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i, &yr_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (3 > i) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i, &as_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &bs_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &cs_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (3 > i) {
    emlrtDynamicBoundsCheckR2012b(3, 1, i, &ds_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &es_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(0);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &fs_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(1);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &gs_emlrtBCI, (emlrtCTX)sp);
  }
  i = b_this->BoardCoords.size(2);
  if (2 > i) {
    emlrtDynamicBoundsCheckR2012b(2, 1, i, &hs_emlrtBCI, (emlrtCTX)sp);
  }
  c_this[0] = b_this->BoardCoords[b_this->BoardCoords.size(0)];
  c_this[1] = b_this->BoardCoords[b_this->BoardCoords.size(0) * 2];
  c_this[2] = b_this->BoardCoords[b_this->BoardCoords.size(0) * 2 + 1];
  c_this[3] = b_this->BoardCoords[b_this->BoardCoords.size(0) + 1];
  d_this[0] = b_this->BoardCoords[b_this->BoardCoords.size(0) +
                                  b_this->BoardCoords.size(0) *
                                      b_this->BoardCoords.size(1)];
  d_this[1] = b_this->BoardCoords[b_this->BoardCoords.size(0) * 2 +
                                  b_this->BoardCoords.size(0) *
                                      b_this->BoardCoords.size(1)];
  d_this[2] = b_this->BoardCoords[(b_this->BoardCoords.size(0) * 2 +
                                   b_this->BoardCoords.size(0) *
                                       b_this->BoardCoords.size(1)) +
                                  1];
  d_this[3] = b_this->BoardCoords[(b_this->BoardCoords.size(0) +
                                   b_this->BoardCoords.size(0) *
                                       b_this->BoardCoords.size(1)) +
                                  1];
  st.site = &sq_emlrtRSI;
  poly2RectMask(&st, c_this, d_this, static_cast<real_T>(b_I.size(0)),
                static_cast<real_T>(b_I.size(1)), nextSquareMask);
  iv[0] = (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[0];
  iv[1] = (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[1];
  iv1[0] = (*(int32_T(*)[2])upperLeftMask.size())[0];
  iv1[1] = (*(int32_T(*)[2])upperLeftMask.size())[1];
  st.site = &tq_emlrtRSI;
  ::Codegen::coder::internal::indexShapeCheck(&st, iv, iv1);
  iv[0] = (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[0];
  iv[1] = (*(int32_T(*)[2])((::coder::array<real32_T, 2U> *)&b_I)->size())[1];
  iv1[0] = (*(int32_T(*)[2])nextSquareMask.size())[0];
  iv1[1] = (*(int32_T(*)[2])nextSquareMask.size())[1];
  st.site = &tq_emlrtRSI;
  ::Codegen::coder::internal::indexShapeCheck(&st, iv, iv1);
  end = upperLeftMask.size(0) * upperLeftMask.size(1) - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (upperLeftMask[i]) {
      trueCount++;
    }
  }
  r.set_size(&vo_emlrtRTEI, sp, trueCount);
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (upperLeftMask[i]) {
      r[trueCount] = i + 1;
      trueCount++;
    }
  }
  end = nextSquareMask.size(0) * nextSquareMask.size(1) - 1;
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (nextSquareMask[i]) {
      trueCount++;
    }
  }
  r1.set_size(&vo_emlrtRTEI, sp, trueCount);
  trueCount = 0;
  for (i = 0; i <= end; i++) {
    if (nextSquareMask[i]) {
      r1[trueCount] = i + 1;
      trueCount++;
    }
  }
  st.site = &tq_emlrtRSI;
  trueCount = b_I.size(0) * b_I.size(1);
  c_I.set_size(&wo_emlrtRTEI, &st, r.size(0));
  end = r.size(0);
  for (i = 0; i < end; i++) {
    if ((r[i] < 1) || (r[i] > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(r[i], 1, trueCount, &is_emlrtBCI, &st);
    }
    c_I[i] = b_I[r[i] - 1];
  }
  b_st.site = &tq_emlrtRSI;
  x = mean(&b_st, c_I);
  y = sumColumnB(x);
  st.site = &tq_emlrtRSI;
  trueCount = b_I.size(0) * b_I.size(1);
  c_I.set_size(&xo_emlrtRTEI, &st, r1.size(0));
  end = r1.size(0);
  for (i = 0; i < end; i++) {
    if ((r1[i] < 1) || (r1[i] > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, trueCount, &js_emlrtBCI, &st);
    }
    c_I[i] = b_I[r1[i] - 1];
  }
  b_st.site = &tq_emlrtRSI;
  x = mean(&b_st, c_I);
  x = sumColumnB(x);
  tf = (y < x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return tf;
}

static void poly2RectMask(const emlrtStack *sp, real_T b_X[4], real_T Y[4],
                          real_T height, real_T width,
                          ::coder::array<boolean_T, 2U> &mask)
{
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T unnamed_idx_0;
  ::Codegen::coder::internal::sort(b_X);
  ::Codegen::coder::internal::sort(Y);
  mask.set_size(&yo_emlrtRTEI, sp, static_cast<int32_T>(height),
                static_cast<int32_T>(width));
  loop_ub = static_cast<int32_T>(height) * static_cast<int32_T>(width);
  for (i = 0; i < loop_ub; i++) {
    mask[i] = false;
  }
  if (Y[1] > Y[2]) {
    i = 0;
    i1 = 0;
  } else {
    if (Y[1] != static_cast<int32_T>(muDoubleScalarFloor(Y[1]))) {
      emlrtIntegerCheckR2012b(Y[1], &dd_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(Y[1]) < 1) ||
        (static_cast<int32_T>(Y[1]) > static_cast<int32_T>(height))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Y[1]), 1,
                                    static_cast<int32_T>(height), &ks_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(Y[1]) - 1;
    if (Y[2] != static_cast<int32_T>(muDoubleScalarFloor(Y[2]))) {
      emlrtIntegerCheckR2012b(Y[2], &ed_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(Y[2]) < 1) ||
        (static_cast<int32_T>(Y[2]) > static_cast<int32_T>(height))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Y[2]), 1,
                                    static_cast<int32_T>(height), &ls_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = static_cast<int32_T>(Y[2]);
  }
  if (b_X[1] > b_X[2]) {
    i2 = 0;
    i3 = 0;
  } else {
    if (b_X[1] != static_cast<int32_T>(muDoubleScalarFloor(b_X[1]))) {
      emlrtIntegerCheckR2012b(b_X[1], &fd_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(b_X[1]) < 1) ||
        (static_cast<int32_T>(b_X[1]) > static_cast<int32_T>(width))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_X[1]), 1,
                                    static_cast<int32_T>(width), &ms_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i2 = static_cast<int32_T>(b_X[1]) - 1;
    if (b_X[2] != static_cast<int32_T>(muDoubleScalarFloor(b_X[2]))) {
      emlrtIntegerCheckR2012b(b_X[2], &gd_emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(b_X[2]) < 1) ||
        (static_cast<int32_T>(b_X[2]) > static_cast<int32_T>(width))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_X[2]), 1,
                                    static_cast<int32_T>(width), &ns_emlrtBCI,
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
  ::coder::array<real_T, 1U> s;
  ::coder::array<int32_T, 1U> r2;
  ::coder::array<int32_T, 1U> r3;
  ::coder::array<real32_T, 2U> I_45;
  ::coder::array<real32_T, 2U> I_45_x;
  ::coder::array<real32_T, 2U> Ig;
  ::coder::array<real32_T, 2U> Ixy;
  ::coder::array<real32_T, 2U> Iy;
  ::coder::array<real32_T, 2U> a;
  ::coder::array<real32_T, 2U> b;
  ::coder::array<real32_T, 2U> cxy;
  ::coder::array<real32_T, 2U> points0;
  ::coder::array<real32_T, 2U> r;
  ::coder::array<real32_T, 2U> r1;
  ::coder::array<real32_T, 1U> b_points0;
  ::coder::array<real32_T, 1U> c_points0;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T connDimsT[2];
  real_T outSizeT[2];
  real_T padSizeT[2];
  real_T startT[2];
  int32_T iv[2];
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
  st.site = &kb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  outSizeT[0] = b_I.size(0);
  startT[0] = 7.0;
  outSizeT[1] = b_I.size(1);
  startT[1] = 7.0;
  if ((b_I.size(0) == 0) || (b_I.size(1) == 0)) {
    Ig.set_size(&jd_emlrtRTEI, &b_st, b_I.size(0), b_I.size(1));
    loop_ub = b_I.size(0) * b_I.size(1);
    for (i = 0; i < loop_ub; i++) {
      Ig[i] = b_I[i];
    }
  } else {
    c_st.site = &hc_emlrtRSI;
    padImage(&c_st, b_I, startT, a);
    c_st.site = &ic_emlrtRSI;
    d_st.site = &rc_emlrtRSI;
    tooBig = true;
    if ((b_I.size(0) <= 65500) || (b_I.size(1) <= 65500)) {
      tooBig = false;
    }
    e_st.site = &sc_emlrtRSI;
    Ig.set_size(&he_emlrtRTEI, &e_st, b_I.size(0), b_I.size(1));
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
  Iy.set_size(&kd_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Iy[i] = Ig[i];
  }
  b_st.site = &ac_emlrtRSI;
  imfilter(&b_st, Iy);
  b_st.site = &bc_emlrtRSI;
  b_imfilter(&b_st, Ig);
  Ixy.set_size(&ld_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Ixy[i] = Ig[i];
  }
  b_st.site = &cc_emlrtRSI;
  imfilter(&b_st, Ixy);
  r.set_size(&md_emlrtRTEI, &st, Ig.size(0), Ig.size(1));
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = Ig[i] * 0.707106769F;
  }
  I_45.set_size(&nd_emlrtRTEI, &st, Iy.size(0), Iy.size(1));
  loop_ub = Iy.size(0) * Iy.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = Iy[i] * 0.707106769F;
  }
  iv[0] = (*(int32_T(*)[2])r.size())[0];
  iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])I_45.size())[0];
  iv1[1] = (*(int32_T(*)[2])I_45.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &e_emlrtECI, &st);
  loop_ub = r.size(0) * r.size(1);
  I_45.set_size(&od_emlrtRTEI, &st, r.size(0), r.size(1));
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = r[i] + I_45[i];
  }
  r1.set_size(&pd_emlrtRTEI, &st, Iy.size(0), Iy.size(1));
  loop_ub = Iy.size(0) * Iy.size(1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = Iy[i] * -0.707106769F;
  }
  iv[0] = (*(int32_T(*)[2])r.size())[0];
  iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &f_emlrtECI, &st);
  I_45_x.set_size(&qd_emlrtRTEI, &st, I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(0) * I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45[i];
  }
  b_st.site = &dc_emlrtRSI;
  b_imfilter(&b_st, I_45_x);
  a.set_size(&rd_emlrtRTEI, &st, I_45.size(0), I_45.size(1));
  loop_ub = I_45.size(0) * I_45.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = I_45[i];
  }
  b_st.site = &ec_emlrtRSI;
  imfilter(&b_st, a);
  loop_ub = I_45_x.size(0) * I_45_x.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45_x[i] * 0.707106769F;
  }
  loop_ub = a.size(0) * a.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = a[i] * -0.707106769F;
  }
  iv[0] = (*(int32_T(*)[2])I_45_x.size())[0];
  iv[1] = (*(int32_T(*)[2])I_45_x.size())[1];
  iv1[0] = (*(int32_T(*)[2])a.size())[0];
  iv1[1] = (*(int32_T(*)[2])a.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &g_emlrtECI, &st);
  loop_ub = I_45_x.size(0) * I_45_x.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45_x[i] = I_45_x[i] + a[i];
  }
  b_st.site = &fc_emlrtRSI;
  b_abs(&b_st, I_45, a);
  I_45.set_size(&sd_emlrtRTEI, &st, r.size(0), r.size(1));
  loop_ub = r.size(0) * r.size(1);
  for (i = 0; i < loop_ub; i++) {
    I_45[i] = r[i] + r1[i];
  }
  b_st.site = &fc_emlrtRSI;
  b_abs(&b_st, I_45, r);
  iv[0] = (*(int32_T(*)[2])a.size())[0];
  iv[1] = (*(int32_T(*)[2])a.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &h_emlrtECI, &st);
  b_st.site = &fc_emlrtRSI;
  b_abs(&b_st, Ixy, b);
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    b[i] = 4.0F * b[i];
  }
  loop_ub = a.size(0) * a.size(1);
  for (i = 0; i < loop_ub; i++) {
    a[i] = 3.0F * (a[i] + r[i]);
  }
  iv[0] = (*(int32_T(*)[2])b.size())[0];
  iv[1] = (*(int32_T(*)[2])b.size())[1];
  iv1[0] = (*(int32_T(*)[2])a.size())[0];
  iv1[1] = (*(int32_T(*)[2])a.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &i_emlrtECI, &st);
  cxy.set_size(&td_emlrtRTEI, &st, b.size(0), b.size(1));
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
  r2.set_size(&ud_emlrtRTEI, &st, trueCount);
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
      emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &db_emlrtBCI, &st);
    }
    cxy[r2[i] - 1] = 0.0F;
  }
  b_st.site = &gc_emlrtRSI;
  b_abs(&b_st, Ig, r);
  b_st.site = &gc_emlrtRSI;
  b_abs(&b_st, Iy, r1);
  iv[0] = (*(int32_T(*)[2])r.size())[0];
  iv[1] = (*(int32_T(*)[2])r.size())[1];
  iv1[0] = (*(int32_T(*)[2])r1.size())[0];
  iv1[1] = (*(int32_T(*)[2])r1.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &j_emlrtECI, &st);
  b_st.site = &gc_emlrtRSI;
  b_abs(&b_st, I_45_x, b);
  loop_ub = b.size(0) * b.size(1);
  for (i = 0; i < loop_ub; i++) {
    b[i] = 4.0F * b[i];
  }
  loop_ub = r.size(0) * r.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 3.0F * (r[i] + r1[i]);
  }
  iv[0] = (*(int32_T(*)[2])b.size())[0];
  iv[1] = (*(int32_T(*)[2])b.size())[1];
  iv1[0] = (*(int32_T(*)[2])r.size())[0];
  iv1[1] = (*(int32_T(*)[2])r.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &k_emlrtECI, &st);
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
  r3.set_size(&ud_emlrtRTEI, &st, trueCount);
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
      emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &eb_emlrtBCI, &st);
    }
    b[r3[i] - 1] = 0.0F;
  }
  st.site = &lb_emlrtRSI;
  b_st.site = &ad_emlrtRSI;
  power(&b_st, Ig, a);
  b_st.site = &bd_emlrtRSI;
  power(&b_st, Iy, I_45);
  iv[0] = (*(int32_T(*)[2])Ig.size())[0];
  iv[1] = (*(int32_T(*)[2])Ig.size())[1];
  iv1[0] = (*(int32_T(*)[2])Iy.size())[0];
  iv1[1] = (*(int32_T(*)[2])Iy.size())[1];
  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &l_emlrtECI, &st);
  b_st.site = &cd_emlrtRSI;
  c_imfilter(&b_st, a);
  b_st.site = &dd_emlrtRSI;
  c_imfilter(&b_st, I_45);
  loop_ub = Ig.size(0) * Ig.size(1);
  for (i = 0; i < loop_ub; i++) {
    Ig[i] = Ig[i] * Iy[i];
  }
  b_st.site = &ed_emlrtRSI;
  c_imfilter(&b_st, Ig);
  st.site = &mb_emlrtRSI;
  find_peaks(&st, cxy, points0);
  st.site = &nb_emlrtRSI;
  loop_ub = points0.size(0);
  b_points0.set_size(&vd_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = points0[i + points0.size(0)];
  }
  loop_ub = points0.size(0);
  c_points0.set_size(&wd_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    c_points0[i] = points0[i];
  }
  iv[0] = (*(int32_T(*)[2])cxy.size())[0];
  iv[1] = (*(int32_T(*)[2])cxy.size())[1];
  b_st.site = &af_emlrtRSI;
  eml_sub2ind(&b_st, iv, b_points0, c_points0, r2);
  s.set_size(&xd_emlrtRTEI, &st, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = r2[i];
  }
  iv[0] = (*(int32_T(*)[2])cxy.size())[0];
  iv[1] = (*(int32_T(*)[2])cxy.size())[1];
  st.site = &nb_emlrtRSI;
  ::Codegen::coder::internal::indexShapeCheck(&st, iv, s.size(0));
  trueCount = cxy.size(0) * cxy.size(1);
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    end = static_cast<int32_T>(s[i]);
    if ((end < 1) || (end > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &fb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  b_points0.set_size(&yd_emlrtRTEI, sp, s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = cxy[static_cast<int32_T>(s[i]) - 1];
  }
  st.site = &wb_emlrtRSI;
  board0 =
      growCheckerboard(&st, points0, b_points0, a, I_45, Ig, 0.0, &lobj_0[0]);
  points.set_size(&ae_emlrtRTEI, sp, 0, 0);
  boardSize[0] = 0.0;
  boardSize[1] = 0.0;
  st.site = &ob_emlrtRSI;
  find_peaks(&st, b, points0);
  st.site = &pb_emlrtRSI;
  loop_ub = points0.size(0);
  b_points0.set_size(&be_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = points0[i + points0.size(0)];
  }
  loop_ub = points0.size(0);
  c_points0.set_size(&ce_emlrtRTEI, &st, points0.size(0));
  for (i = 0; i < loop_ub; i++) {
    c_points0[i] = points0[i];
  }
  iv[0] = (*(int32_T(*)[2])b.size())[0];
  iv[1] = (*(int32_T(*)[2])b.size())[1];
  b_st.site = &af_emlrtRSI;
  eml_sub2ind(&b_st, iv, b_points0, c_points0, r2);
  s.set_size(&de_emlrtRTEI, &st, r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = r2[i];
  }
  iv[0] = (*(int32_T(*)[2])b.size())[0];
  iv[1] = (*(int32_T(*)[2])b.size())[1];
  st.site = &pb_emlrtRSI;
  ::Codegen::coder::internal::indexShapeCheck(&st, iv, s.size(0));
  trueCount = b.size(0) * b.size(1);
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    end = static_cast<int32_T>(s[i]);
    if ((end < 1) || (end > trueCount)) {
      emlrtDynamicBoundsCheckR2012b(end, 1, trueCount, &gb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
  }
  b_points0.set_size(&ee_emlrtRTEI, sp, s.size(0));
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_points0[i] = b[static_cast<int32_T>(s[i]) - 1];
  }
  st.site = &xb_emlrtRSI;
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
        s.set_size(&fe_emlrtRTEI, sp,
                   board0->BoardIdx.size(0) * board0->BoardIdx.size(1));
        loop_ub = board0->BoardIdx.size(0) * board0->BoardIdx.size(1);
        for (i = 0; i < loop_ub; i++) {
          s[i] = board0->BoardIdx[i];
        }
        end = 0;
        i = s.size(0);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (s[loop_ub] != 0.0) {
            end++;
          }
        }
        s.set_size(&ge_emlrtRTEI, sp,
                   board45->BoardIdx.size(0) * board45->BoardIdx.size(1));
        loop_ub = board45->BoardIdx.size(0) * board45->BoardIdx.size(1);
        for (i = 0; i < loop_ub; i++) {
          s[i] = board45->BoardIdx[i];
        }
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
    st.site = &qb_emlrtRSI;
    board0 = orient(&st, board0, b_I);
    st.site = &rb_emlrtRSI;
    toPoints(&st, board0, points, boardSize);
    st.site = &sb_emlrtRSI;
    subPixelLocation(&st, Ixy, points);
  }
  if (guard1 && board45->isValid) {
    st.site = &tb_emlrtRSI;
    board45 = orient(&st, board45, b_I);
    st.site = &ub_emlrtRSI;
    toPoints(&st, board45, points, boardSize);
    st.site = &vb_emlrtRSI;
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
  ::coder::array<real_T, 2U> b_seedIdx;
  ::coder::array<real_T, 2U> seedIdx;
  ::coder::array<int32_T, 1U> iidx;
  ::coder::array<real32_T, 1U> x;
  emlrtStack b_st;
  emlrtStack st;
  int32_T iv[2];
  real32_T v1[2];
  real32_T v2[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (scores.size(0) == 0) {
    int32_T i;
    st.site = &ef_emlrtRSI;
    iobj_0[0].isValid = false;
    iobj_0[0].Energy = rtInfF;
    iobj_0[0].IsDistortionHigh = false;
    board = &iobj_0[0];
    iobj_0[0].BoardIdx.set_size(&ye_emlrtRTEI, &st, 1, 1);
    iobj_0[0].BoardIdx[0] = 0.0;
    iobj_0[0].BoardIdx.set_size(&af_emlrtRTEI, &st, 3, 3);
    for (i = 0; i < 9; i++) {
      iobj_0[0].BoardIdx[i] = 0.0;
    }
    iobj_0[0].BoardCoords.set_size(&bf_emlrtRTEI, &st, 1, 1, 1);
    iobj_0[0].BoardCoords[0] = 0.0;
    iobj_0[0].BoardCoords.set_size(&cf_emlrtRTEI, &st, 3, 3, 2);
    for (i = 0; i < 18; i++) {
      iobj_0[0].BoardCoords[i] = 0.0;
    }
    iobj_0[0].Points.set_size(&df_emlrtRTEI, &st, 1, 1);
    iobj_0[0].Points[0] = 0.0F;
    iobj_0[0].Points.set_size(&ef_emlrtRTEI, &st, 0, 2);
  } else {
    int32_T a;
    int32_T i;
    int32_T sgn2;
    if (points.size(0) < 1) {
      seedIdx.set_size(&ue_emlrtRTEI, sp, 1, 0);
    } else {
      seedIdx.set_size(&ue_emlrtRTEI, sp, 1, points.size(0));
      sgn2 = points.size(0) - 1;
      for (i = 0; i <= sgn2; i++) {
        seedIdx[i] = static_cast<real_T>(i) + 1.0;
      }
    }
    iv[0] = (*(int32_T(*)[2])seedIdx.size())[0];
    iv[1] = (*(int32_T(*)[2])seedIdx.size())[1];
    st.site = &ff_emlrtRSI;
    ::Codegen::coder::internal::indexShapeCheck(&st, scores.size(0), iv);
    st.site = &ff_emlrtRSI;
    sgn2 = seedIdx.size(1);
    for (i = 0; i < sgn2; i++) {
      a = static_cast<int32_T>(seedIdx[i]);
      if (seedIdx[i] != a) {
        emlrtIntegerCheckR2012b(seedIdx[i], &e_emlrtDCI, &st);
      }
      if (a > scores.size(0)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, scores.size(0), &cc_emlrtBCI, &st);
      }
    }
    x.set_size(&ve_emlrtRTEI, &st, seedIdx.size(1));
    sgn2 = seedIdx.size(1);
    for (i = 0; i < sgn2; i++) {
      x[i] = scores[static_cast<int32_T>(seedIdx[i]) - 1];
    }
    b_st.site = &nf_emlrtRSI;
    ::Codegen::coder::internal::sort(&b_st, x, iidx);
    iv[0] = (*(int32_T(*)[2])seedIdx.size())[0];
    iv[1] = (*(int32_T(*)[2])seedIdx.size())[1];
    st.site = &gf_emlrtRSI;
    ::Codegen::coder::internal::b_indexShapeCheck(&st, iv, iidx.size(0));
    b_seedIdx.set_size(&we_emlrtRTEI, sp, 1, iidx.size(0));
    sgn2 = iidx.size(0);
    for (i = 0; i < sgn2; i++) {
      if ((iidx[i] < 1) || (iidx[i] > seedIdx.size(1))) {
        emlrtDynamicBoundsCheckR2012b(iidx[i], 1, seedIdx.size(1), &dc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_seedIdx[i] = static_cast<uint32_T>(seedIdx[iidx[i] - 1]);
    }
    seedIdx.set_size(&we_emlrtRTEI, sp, 1, b_seedIdx.size(1));
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
          emlrtDynamicBoundsCheckR2012b(1, 1, seedIdx.size(1), &bc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (sgn2 > seedIdx.size(1)) {
          emlrtDynamicBoundsCheckR2012b(sgn2, 1, seedIdx.size(1), &ac_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      for (i = 0; i < sgn2; i++) {
        seedIdx[i] = static_cast<uint32_T>(seedIdx[i]);
      }
      seedIdx.set_size(&xe_emlrtRTEI, sp, 1, sgn2);
    }
    st.site = &hf_emlrtRSI;
    board = iobj_0[1].init(&st);
    st.site = &if_emlrtRSI;
    currentBoard = iobj_0[2].init(&st);
    i = seedIdx.size(1);
    for (int32_T b_i{0}; b_i < i; b_i++) {
      real_T d;
      real32_T ab;
      real32_T adf;
      real32_T b;
      real32_T b_a;
      real32_T c;
      real32_T df;
      real32_T tb;
      if (b_i + 1 > seedIdx.size(1)) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, seedIdx.size(1), &ec_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      a = static_cast<int32_T>(static_cast<uint32_T>(seedIdx[b_i]));
      if (a > points.size(0)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, points.size(0), &yb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &jf_emlrtRSI;
      d = seedIdx[b_i];
      a = static_cast<int32_T>(
          points[(static_cast<int32_T>(static_cast<uint32_T>(d)) +
                  points.size(0)) -
                 1]);
      if ((a < 1) || (a > Ix2.size(0))) {
        emlrtDynamicBoundsCheckR2012b(a, 1, Ix2.size(0), &fc_emlrtBCI, &st);
      }
      sgn2 = static_cast<int32_T>(
          points[static_cast<int32_T>(static_cast<uint32_T>(d)) - 1]);
      if ((sgn2 < 1) || (sgn2 > Ix2.size(1))) {
        emlrtDynamicBoundsCheckR2012b(sgn2, 1, Ix2.size(1), &gc_emlrtBCI, &st);
      }
      b_a = Ix2[(static_cast<int32_T>(static_cast<real32_T>(a)) +
                 Ix2.size(0) *
                     (static_cast<int32_T>(static_cast<real32_T>(sgn2)) - 1)) -
                1];
      if (a > Ixy.size(0)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, Ixy.size(0), &hc_emlrtBCI, &st);
      }
      if (sgn2 > Ixy.size(1)) {
        emlrtDynamicBoundsCheckR2012b(sgn2, 1, Ixy.size(1), &ic_emlrtBCI, &st);
      }
      b = Ixy[(static_cast<int32_T>(static_cast<real32_T>(a)) +
               Ixy.size(0) *
                   (static_cast<int32_T>(static_cast<real32_T>(sgn2)) - 1)) -
              1];
      if (a > Iy2.size(0)) {
        emlrtDynamicBoundsCheckR2012b(a, 1, Iy2.size(0), &jc_emlrtBCI, &st);
      }
      if (sgn2 > Iy2.size(1)) {
        emlrtDynamicBoundsCheckR2012b(sgn2, 1, Iy2.size(1), &kc_emlrtBCI, &st);
      }
      c = Iy2[(static_cast<int32_T>(static_cast<real32_T>(a)) +
               Iy2.size(0) *
                   (static_cast<int32_T>(static_cast<real32_T>(sgn2)) - 1)) -
              1];
      df = b_a - c;
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
        b_st.site = &tg_emlrtRSI;
        b = adf * adf + 1.0F;
        if (b < 0.0F) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        df = 1.0F / muSingleScalarSqrt(b);
        b = adf * df;
      } else if (ab == 0.0F) {
        b = 1.0F;
        df = 0.0F;
      } else {
        adf = -adf / tb;
        b_st.site = &ug_emlrtRSI;
        b = adf * adf + 1.0F;
        if (b < 0.0F) {
          emlrtErrorWithMessageIdR2018a(
              &b_st, &u_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        b = 1.0F / muSingleScalarSqrt(b);
        df = adf * b;
      }
      if (b_a + c < 0.0F) {
        a = -1;
      } else {
        a = 1;
      }
      if (a == sgn2) {
        adf = b;
        b = -df;
        df = adf;
      }
      v1[0] = -df * 0.707106769F + b * 0.707106769F;
      adf = -df * -0.707106769F + b * 0.707106769F;
      v1[1] = adf;
      v2[0] = b * 0.707106769F + df * 0.707106769F;
      b = b * -0.707106769F + df * 0.707106769F;
      v2[1] = b;
      if ((!(muSingleScalarAbs(
                 muSingleScalarAbs(
                     muSingleScalarAbs(muSingleScalarAtan2(adf, v1[0])) -
                     3.14159274F) -
                 static_cast<real32_T>(theta)) > 0.58904862254808621)) ||
          (!(muSingleScalarAbs(
                 muSingleScalarAbs(
                     muSingleScalarAbs(muSingleScalarAtan2(b, v2[0])) -
                     3.14159274F) -
                 static_cast<real32_T>(theta)) > 0.58904862254808621))) {
        if (b_i + 1 > seedIdx.size(1)) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, seedIdx.size(1),
                                        &lc_emlrtBCI, (emlrtCTX)sp);
        }
        st.site = &kf_emlrtRSI;
        currentBoard->initialize(
            &st, static_cast<real_T>(static_cast<uint32_T>(seedIdx[b_i])),
            points, v1, v2);
        st.site = &lf_emlrtRSI;
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
  ::coder::array<real_T, 3U> r;
  ::coder::array<real_T, 3U> r1;
  ::coder::array<real_T, 3U> r2;
  ::coder::array<real_T, 2U> c_board;
  ::coder::array<real_T, 2U> newBoardCoords1;
  ::coder::array<real_T, 2U> newBoardCoords2;
  ::coder::array<boolean_T, 3U> r3;
  ::coder::array<boolean_T, 2U> c_numRot_data;
  ::coder::array<boolean_T, 2U> y;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T cornerIdx[4];
  real_T numRot_data;
  int32_T iv[3];
  int32_T iv1[3];
  int32_T numRot_size[2];
  real32_T x;
  int8_T ii_data;
  boolean_T b_numRot_data;
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
    if (b_board->BoardCoords.size(0) < b_board->BoardCoords.size(1)) {
      st.site = &sp_emlrtRSI;
      c_board.set_size(&go_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                       b_board->BoardIdx.size(1));
      loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        c_board[i] = b_board->BoardIdx[i];
      }
      b_st.site = &fq_emlrtRSI;
      rot90(&b_st, c_board, b_board->BoardIdx);
      i = b_board->BoardCoords.size(2);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &sp_emlrtBCI, &st);
      }
      loop_ub = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(1);
      c_board.set_size(&ho_emlrtRTEI, &st, loop_ub, npages);
      for (i = 0; i < npages; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_board[i1 + c_board.size(0) * i] =
              b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
        }
      }
      b_st.site = &gq_emlrtRSI;
      rot90(&b_st, c_board, newBoardCoords1);
      i = b_board->BoardCoords.size(2);
      if (2 > i) {
        emlrtDynamicBoundsCheckR2012b(2, 1, i, &rp_emlrtBCI, &st);
      }
      loop_ub = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(1);
      c_board.set_size(&io_emlrtRTEI, &st, loop_ub, npages);
      for (i = 0; i < npages; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_board[i1 + c_board.size(0) * i] =
              b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                   b_board->BoardCoords.size(0) *
                                       b_board->BoardCoords.size(1)];
        }
      }
      b_st.site = &hq_emlrtRSI;
      rot90(&b_st, c_board, newBoardCoords2);
      b_st.site = &iq_emlrtRSI;
      cat(&b_st, newBoardCoords1, newBoardCoords2, r);
      b_board->BoardCoords.set_size(&jo_emlrtRTEI, &st, r.size(0), r.size(1),
                                    2);
      loop_ub = r.size(0) * r.size(1) * 2;
      for (i = 0; i < loop_ub; i++) {
        b_board->BoardCoords[i] = r[i];
      }
    }
    st.site = &tp_emlrtRSI;
    newBoardCoords1.set_size(&ko_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                             b_board->BoardIdx.size(1));
    loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1);
    for (i = 0; i < loop_ub; i++) {
      newBoardCoords1[i] = b_board->BoardIdx[i];
    }
    b_st.site = &ci_emlrtRSI;
    if ((newBoardCoords1.size(0) == 0) && (newBoardCoords1.size(1) == 0)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &pb_emlrtRTEI, "Coder:toolbox:eml_all_or_any_specialEmpty",
          "Coder:toolbox:eml_all_or_any_specialEmpty", 0);
    }
    if ((newBoardCoords1.size(0) == 1) && (newBoardCoords1.size(1) != 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &bb_emlrtRTEI,
          "Coder:toolbox:eml_all_or_any_autoDimIncompatibility",
          "Coder:toolbox:eml_all_or_any_autoDimIncompatibility", 0);
    }
    y.set_size(&lo_emlrtRTEI, &b_st, 1, newBoardCoords1.size(1));
    loop_ub = newBoardCoords1.size(1);
    for (i = 0; i < loop_ub; i++) {
      y[i] = true;
    }
    npages = newBoardCoords1.size(1);
    i2 = 0;
    c_st.site = &oq_emlrtRSI;
    if ((1 <= newBoardCoords1.size(1)) &&
        (newBoardCoords1.size(1) > 2147483646)) {
      d_st.site = &qc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (i = 0; i < npages; i++) {
      loop_ub = i2 + newBoardCoords1.size(0);
      i1 = i2 + 1;
      i2 += newBoardCoords1.size(0);
      c_st.site = &bi_emlrtRSI;
      if ((i1 <= loop_ub) && (loop_ub > 2147483646)) {
        d_st.site = &qc_emlrtRSI;
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
    st.site = &tp_emlrtRSI;
    if (::Codegen::coder::internal::ifWhileCond(&st, y)) {
      st.site = &up_emlrtRSI;
      if (!isUpperLeftBlack(&st, b_board, b_I)) {
        st.site = &vp_emlrtRSI;
        c_board.set_size(&go_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                         b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          c_board[i] = b_board->BoardIdx[i];
        }
        b_st.site = &fq_emlrtRSI;
        b_rot90(&b_st, c_board, b_board->BoardIdx);
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &sp_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&ho_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
          }
        }
        b_st.site = &gq_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords1);
        i = b_board->BoardCoords.size(2);
        if (2 > i) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i, &rp_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&io_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                     b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1)];
          }
        }
        b_st.site = &hq_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords2);
        b_st.site = &iq_emlrtRSI;
        cat(&b_st, newBoardCoords1, newBoardCoords2, r);
        b_board->BoardCoords.set_size(&jo_emlrtRTEI, &st, r.size(0), r.size(1),
                                      2);
        loop_ub = r.size(0) * r.size(1) * 2;
        for (i = 0; i < loop_ub; i++) {
          b_board->BoardCoords[i] = r[i];
        }
      }
    } else {
      st.site = &wp_emlrtRSI;
      i = b_board->BoardIdx.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &yp_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &xp_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &wp_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &vp_emlrtBCI, &st);
      }
      cornerIdx[0] = b_board->BoardIdx[0];
      i = b_board->BoardIdx.size(0);
      i1 = b_board->BoardIdx.size(0);
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &fq_emlrtBCI, &st);
      }
      cornerIdx[1] = b_board->BoardIdx[i1 - 1];
      i = b_board->BoardIdx.size(0);
      i1 = b_board->BoardIdx.size(0);
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &gq_emlrtBCI, &st);
      }
      i = b_board->BoardIdx.size(1);
      npages = b_board->BoardIdx.size(1);
      if ((npages < 1) || (npages > i)) {
        emlrtDynamicBoundsCheckR2012b(npages, 1, i, &gq_emlrtBCI, &st);
      }
      cornerIdx[2] =
          b_board
              ->BoardIdx[(i1 + b_board->BoardIdx.size(0) * (npages - 1)) - 1];
      i = b_board->BoardIdx.size(1);
      i1 = b_board->BoardIdx.size(1);
      if ((i1 < 1) || (i1 > i)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i, &hq_emlrtBCI, &st);
      }
      cornerIdx[3] = b_board->BoardIdx[b_board->BoardIdx.size(0) * (i1 - 1)];
      npages = 0;
      loop_ub = 1;
      i2 = 0;
      exitg1 = false;
      while ((!exitg1) && (i2 < 4)) {
        if (cornerIdx[i2] != 0.0) {
          npages = 1;
          ii_data = static_cast<int8_T>(i2 + 1);
          exitg1 = true;
        } else {
          i2++;
        }
      }
      if (npages == 0) {
        loop_ub = 0;
      }
      numRot_size[0] = 1;
      numRot_size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        numRot_data = static_cast<real_T>(ii_data) - 1.0;
      }
      if (loop_ub == 0) {
        numRot_size[0] = 1;
        numRot_size[1] = 1;
        numRot_data = 0.0;
      }
      b_numRot_data = (numRot_data == 2.0);
      c_numRot_data.set(&b_numRot_data, 1, 1);
      st.site = &xp_emlrtRSI;
      if (::Codegen::coder::internal::ifWhileCond(&st, c_numRot_data)) {
        st.site = &yp_emlrtRSI;
        c_board.set_size(&go_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                         b_board->BoardIdx.size(1));
        loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          c_board[i] = b_board->BoardIdx[i];
        }
        b_st.site = &fq_emlrtRSI;
        b_rot90(&b_st, c_board, b_board->BoardIdx);
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &sp_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&ho_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
          }
        }
        b_st.site = &gq_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords1);
        i = b_board->BoardCoords.size(2);
        if (2 > i) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i, &rp_emlrtBCI, &st);
        }
        loop_ub = b_board->BoardCoords.size(0);
        npages = b_board->BoardCoords.size(1);
        c_board.set_size(&io_emlrtRTEI, &st, loop_ub, npages);
        for (i = 0; i < npages; i++) {
          for (i1 = 0; i1 < loop_ub; i1++) {
            c_board[i1 + c_board.size(0) * i] =
                b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                     b_board->BoardCoords.size(0) *
                                         b_board->BoardCoords.size(1)];
          }
        }
        b_st.site = &hq_emlrtRSI;
        b_rot90(&b_st, c_board, newBoardCoords2);
        b_st.site = &iq_emlrtRSI;
        cat(&b_st, newBoardCoords1, newBoardCoords2, r);
        b_board->BoardCoords.set_size(&jo_emlrtRTEI, &st, r.size(0), r.size(1),
                                      2);
        loop_ub = r.size(0) * r.size(1) * 2;
        for (i = 0; i < loop_ub; i++) {
          b_board->BoardCoords[i] = r[i];
        }
      } else {
        if (isequal((real_T *)&numRot_data, numRot_size, 1.0)) {
          i2 = 1;
        } else if (isequal((real_T *)&numRot_data, numRot_size, 3.0)) {
          i2 = 2;
        } else {
          i2 = 0;
        }
        st.site = &aq_emlrtRSI;
        if (i2 != 0) {
          st.site = &bq_emlrtRSI;
          newBoardCoords1.set_size(&mo_emlrtRTEI, &st,
                                   b_board->BoardIdx.size(0),
                                   b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1);
          for (i = 0; i < loop_ub; i++) {
            newBoardCoords1[i] = b_board->BoardIdx[i];
          }
          b_st.site = &fr_emlrtRSI;
          flip(&b_st, newBoardCoords1, static_cast<real_T>(i2));
          b_board->BoardIdx.set_size(&no_emlrtRTEI, &st,
                                     newBoardCoords1.size(0),
                                     newBoardCoords1.size(1));
          loop_ub = newBoardCoords1.size(0) * newBoardCoords1.size(1);
          for (i = 0; i < loop_ub; i++) {
            b_board->BoardIdx[i] = newBoardCoords1[i];
          }
          i = b_board->BoardCoords.size(2);
          if (1 > i) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i, &up_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          newBoardCoords1.set_size(&oo_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords1[i1 + newBoardCoords1.size(0) * i] =
                  b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
            }
          }
          b_st.site = &gr_emlrtRSI;
          flip(&b_st, newBoardCoords1, static_cast<real_T>(i2));
          i = b_board->BoardCoords.size(2);
          if (2 > i) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i, &tp_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          newBoardCoords2.set_size(&po_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              newBoardCoords2[i1 + newBoardCoords2.size(0) * i] =
                  b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                       b_board->BoardCoords.size(0) *
                                           b_board->BoardCoords.size(1)];
            }
          }
          b_st.site = &hr_emlrtRSI;
          flip(&b_st, newBoardCoords2, static_cast<real_T>(i2));
          b_st.site = &ir_emlrtRSI;
          cat(&b_st, newBoardCoords1, newBoardCoords2, r);
          b_board->BoardCoords.set_size(&qo_emlrtRTEI, &st, r.size(0),
                                        r.size(1), 2);
          loop_ub = r.size(0) * r.size(1) * 2;
          for (i = 0; i < loop_ub; i++) {
            b_board->BoardCoords[i] = r[i];
          }
        }
      }
    }
    npages = b_board->BoardCoords.size(0);
    if (npages == 0) {
      i2 = 0;
    } else {
      i2 = static_cast<int32_T>(
          muDoubleScalarRem(static_cast<real_T>(npages), 2.0));
      if (i2 == 0) {
        i2 = 0;
      }
    }
    npages = b_board->BoardCoords.size(1);
    if (npages == 0) {
      npages = 0;
    } else {
      npages = static_cast<int32_T>(
          muDoubleScalarRem(static_cast<real_T>(npages), 2.0));
      if (npages == 0) {
        npages = 0;
      }
    }
    if ((i2 == 0) == (npages == 0)) {
      i = b_board->BoardCoords.size(0);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &eq_emlrtBCI, (emlrtCTX)sp);
      }
      i = b_board->BoardCoords.size(1);
      if (1 > i) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i, &dq_emlrtBCI, (emlrtCTX)sp);
      }
      loop_ub = b_board->BoardCoords.size(2);
      r1.set_size(&ro_emlrtRTEI, sp, 1, 1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r1[i] = b_board->BoardCoords[b_board->BoardCoords.size(0) *
                                     b_board->BoardCoords.size(1) * i];
      }
      i = b_board->BoardCoords.size(0);
      npages = b_board->BoardCoords.size(0);
      if ((npages < 1) || (npages > i)) {
        emlrtDynamicBoundsCheckR2012b(npages, 1, i, &cq_emlrtBCI, (emlrtCTX)sp);
      }
      i = b_board->BoardCoords.size(1);
      i2 = b_board->BoardCoords.size(1);
      if ((i2 < 1) || (i2 > i)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i, &bq_emlrtBCI, (emlrtCTX)sp);
      }
      loop_ub = b_board->BoardCoords.size(2);
      r2.set_size(&so_emlrtRTEI, sp, 1, 1, loop_ub);
      for (i = 0; i < loop_ub; i++) {
        r2[i] = b_board->BoardCoords[((npages + b_board->BoardCoords.size(0) *
                                                    (i2 - 1)) +
                                      b_board->BoardCoords.size(0) *
                                          b_board->BoardCoords.size(1) * i) -
                                     1];
      }
      iv[0] = (*(int32_T(*)[3])r1.size())[0];
      iv[1] = (*(int32_T(*)[3])r1.size())[1];
      iv[2] = (*(int32_T(*)[3])r1.size())[2];
      iv1[0] = (*(int32_T(*)[3])r2.size())[0];
      iv1[1] = (*(int32_T(*)[3])r2.size())[1];
      iv1[2] = (*(int32_T(*)[3])r2.size())[2];
      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &xc_emlrtECI, (emlrtCTX)sp);
      r3.set_size(&ro_emlrtRTEI, sp, 1, 1, r1.size(2));
      loop_ub = r1.size(2);
      for (i = 0; i < loop_ub; i++) {
        r3[i] = (r1[i] > r2[i]);
      }
      st.site = &cq_emlrtRSI;
      if (c_any(&st, r3)) {
        i = b_board->BoardCoords.size(2);
        if (1 > i) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i, &aq_emlrtBCI, (emlrtCTX)sp);
        }
        i = b_board->BoardCoords.size(0);
        i1 = b_board->BoardCoords.size(0);
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &iq_emlrtBCI, (emlrtCTX)sp);
        }
        i = b_board->BoardCoords.size(1);
        npages = b_board->BoardCoords.size(1);
        if ((npages < 1) || (npages > i)) {
          emlrtDynamicBoundsCheckR2012b(npages, 1, i, &jq_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        numRot_data = b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) *
                                                     (npages - 1)) -
                                           1];
        st.site = &dq_emlrtRSI;
        if (muDoubleScalarIsNaN(numRot_data)) {
          emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                        "MATLAB:nologicalnan",
                                        "MATLAB:nologicalnan", 0);
        }
        if (numRot_data != 0.0) {
          st.site = &eq_emlrtRSI;
          c_board.set_size(&go_emlrtRTEI, &st, b_board->BoardIdx.size(0),
                           b_board->BoardIdx.size(1));
          loop_ub = b_board->BoardIdx.size(0) * b_board->BoardIdx.size(1) - 1;
          for (i = 0; i <= loop_ub; i++) {
            c_board[i] = b_board->BoardIdx[i];
          }
          b_st.site = &fq_emlrtRSI;
          b_rot90(&b_st, c_board, b_board->BoardIdx);
          i = b_board->BoardCoords.size(2);
          if (1 > i) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i, &sp_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          c_board.set_size(&ho_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_board[i1 + c_board.size(0) * i] =
                  b_board->BoardCoords[i1 + b_board->BoardCoords.size(0) * i];
            }
          }
          b_st.site = &gq_emlrtRSI;
          b_rot90(&b_st, c_board, newBoardCoords1);
          i = b_board->BoardCoords.size(2);
          if (2 > i) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i, &rp_emlrtBCI, &st);
          }
          loop_ub = b_board->BoardCoords.size(0);
          npages = b_board->BoardCoords.size(1);
          c_board.set_size(&io_emlrtRTEI, &st, loop_ub, npages);
          for (i = 0; i < npages; i++) {
            for (i1 = 0; i1 < loop_ub; i1++) {
              c_board[i1 + c_board.size(0) * i] =
                  b_board->BoardCoords[(i1 + b_board->BoardCoords.size(0) * i) +
                                       b_board->BoardCoords.size(0) *
                                           b_board->BoardCoords.size(1)];
            }
          }
          b_st.site = &hq_emlrtRSI;
          b_rot90(&b_st, c_board, newBoardCoords2);
          b_st.site = &iq_emlrtRSI;
          cat(&b_st, newBoardCoords1, newBoardCoords2, r);
          b_board->BoardCoords.set_size(&jo_emlrtRTEI, &st, r.size(0),
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
  ::coder::array<real_T, 2U> x;
  ::coder::array<boolean_T, 1U> d_this;
  emlrtStack st;
  int32_T c_this;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  c_this = b_this->BoardIdx.size(0) * b_this->BoardIdx.size(1);
  d_this.set_size(&bp_emlrtRTEI, sp, c_this);
  for (i = 0; i < c_this; i++) {
    d_this[i] = (b_this->BoardIdx[i] == 0.0);
  }
  st.site = &nr_emlrtRSI;
  if (any(&st, d_this)) {
    points.set_size(&fp_emlrtRTEI, sp, 0, 0);
    boardSize[0] = 0.0;
    boardSize[1] = 0.0;
  } else {
    real_T numPoints;
    int32_T i1;
    numPoints = static_cast<real_T>(b_this->BoardCoords.size(0)) *
                static_cast<real_T>(b_this->BoardCoords.size(1));
    if (numPoints != static_cast<int32_T>(numPoints)) {
      emlrtIntegerCheckR2012b(numPoints, &hd_emlrtDCI, (emlrtCTX)sp);
    }
    points.set_size(&cp_emlrtRTEI, sp, static_cast<int32_T>(numPoints), 2);
    if (numPoints != static_cast<int32_T>(numPoints)) {
      emlrtIntegerCheckR2012b(numPoints, &id_emlrtDCI, (emlrtCTX)sp);
    }
    c_this = static_cast<int32_T>(numPoints) << 1;
    for (i = 0; i < c_this; i++) {
      points[i] = 0.0;
    }
    i = b_this->BoardCoords.size(2);
    if (1 > i) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i, &os_emlrtBCI, (emlrtCTX)sp);
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    x.set_size(&dp_emlrtRTEI, sp, loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1 + x.size(0) * i] =
            b_this->BoardCoords[i + b_this->BoardCoords.size(0) * i1];
      }
    }
    c_this = static_cast<int32_T>(numPoints);
    loop_ub = x.size(0) * x.size(1);
    emlrtSubAssignSizeCheckR2012b(&c_this, 1, &loop_ub, 1, &yc_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = x.size(0) * x.size(1);
    for (i = 0; i < loop_ub; i++) {
      points[i] = x[i];
    }
    i = b_this->BoardCoords.size(2);
    if (2 > i) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i, &ps_emlrtBCI, (emlrtCTX)sp);
    }
    c_this = b_this->BoardCoords.size(0);
    loop_ub = b_this->BoardCoords.size(1);
    x.set_size(&ep_emlrtRTEI, sp, loop_ub, c_this);
    for (i = 0; i < c_this; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        x[i1 + x.size(0) * i] =
            b_this->BoardCoords[(i + b_this->BoardCoords.size(0) * i1) +
                                b_this->BoardCoords.size(0) *
                                    b_this->BoardCoords.size(1)];
      }
    }
    loop_ub = x.size(0) * x.size(1);
    emlrtSubAssignSizeCheckR2012b(points.size(), 1, &loop_ub, 1, &ad_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = x.size(0) * x.size(1);
    for (i = 0; i < loop_ub; i++) {
      points[i + points.size(0)] = x[i];
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
} // namespace Codegen

// End of code generation (detectCheckerboard.cpp)
