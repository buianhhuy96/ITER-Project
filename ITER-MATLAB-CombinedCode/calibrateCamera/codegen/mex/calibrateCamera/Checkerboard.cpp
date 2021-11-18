//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Checkerboard.cpp
//
// Code generation for function 'Checkerboard'
//

// Include files
#include "Checkerboard.h"
#include "all.h"
#include "any1.h"
#include "bsxfun.h"
#include "calibrateCamera_data.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_setop.h"
#include "find.h"
#include "hypot.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "ismember.h"
#include "mean.h"
#include "polyfit.h"
#include "polyval.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "squeeze.h"
#include "sum.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo vg_emlrtRSI{ 74,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wg_emlrtRSI{ 75,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xg_emlrtRSI{ 78,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yg_emlrtRSI{ 79,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ah_emlrtRSI{ 80,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bh_emlrtRSI{ 81,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ch_emlrtRSI{ 83,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dh_emlrtRSI{ 103,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo eh_emlrtRSI{ 104,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fh_emlrtRSI{ 105,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gh_emlrtRSI{ 106,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hh_emlrtRSI{ 107,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ih_emlrtRSI{ 117,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nh_emlrtRSI{ 231,   // lineNo
  "Checkerboard/findNeighbor",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oh_emlrtRSI{ 244,   // lineNo
  "Checkerboard/findNeighbor",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo th_emlrtRSI{ 34,    // lineNo
  "rdivide_helper",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_helper.m"// pathName
};

static emlrtRSInfo uh_emlrtRSI{ 51,    // lineNo
  "div",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m"// pathName
};

static emlrtRSInfo vh_emlrtRSI{ 17,    // lineNo
  "min",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName
};

static emlrtRSInfo wh_emlrtRSI{ 40,    // lineNo
  "minOrMax",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo xh_emlrtRSI{ 90,    // lineNo
  "minimum",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo yh_emlrtRSI{ 169,   // lineNo
  "unaryMinOrMax",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo di_emlrtRSI{ 136,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ei_emlrtRSI{ 144,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fi_emlrtRSI{ 145,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gi_emlrtRSI{ 146,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ii_emlrtRSI{ 153,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ji_emlrtRSI{ 154,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ki_emlrtRSI{ 155,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mi_emlrtRSI{ 177,   // lineNo
  "Checkerboard/expandBoardFully",     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ni_emlrtRSI{ 263,   // lineNo
  "Checkerboard/expandBoardOnce",      // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oi_emlrtRSI{ 268,   // lineNo
  "Checkerboard/expandBoardOnce",      // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pi_emlrtRSI{ 305,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qi_emlrtRSI{ 306,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ri_emlrtRSI{ 307,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo si_emlrtRSI{ 308,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ti_emlrtRSI{ 314,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ui_emlrtRSI{ 315,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vi_emlrtRSI{ 317,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wi_emlrtRSI{ 318,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xi_emlrtRSI{ 322,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yi_emlrtRSI{ 324,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo aj_emlrtRSI{ 325,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bj_emlrtRSI{ 326,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo cj_emlrtRSI{ 327,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dj_emlrtRSI{ 333,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ej_emlrtRSI{ 334,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fj_emlrtRSI{ 336,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gj_emlrtRSI{ 338,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hj_emlrtRSI{ 343,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ij_emlrtRSI{ 344,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jj_emlrtRSI{ 345,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo kj_emlrtRSI{ 346,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lj_emlrtRSI{ 352,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mj_emlrtRSI{ 353,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nj_emlrtRSI{ 355,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oj_emlrtRSI{ 356,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pj_emlrtRSI{ 360,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qj_emlrtRSI{ 362,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rj_emlrtRSI{ 363,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sj_emlrtRSI{ 364,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tj_emlrtRSI{ 365,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo uj_emlrtRSI{ 371,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vj_emlrtRSI{ 372,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wj_emlrtRSI{ 374,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xj_emlrtRSI{ 376,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yj_emlrtRSI{ 425,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ak_emlrtRSI{ 441,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bk_emlrtRSI{ 451,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ck_emlrtRSI{ 455,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dk_emlrtRSI{ 478,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ek_emlrtRSI{ 504,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fk_emlrtRSI{ 505,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tk_emlrtRSI{ 575,   // lineNo
  "Checkerboard/fitPolyCurve",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dm_emlrtRSI{ 636,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo em_emlrtRSI{ 637,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fm_emlrtRSI{ 639,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gm_emlrtRSI{ 640,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hm_emlrtRSI{ 645,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo im_emlrtRSI{ 650,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jm_emlrtRSI{ 652,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo km_emlrtRSI{ 662,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lm_emlrtRSI{ 663,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mm_emlrtRSI{ 665,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nm_emlrtRSI{ 667,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo om_emlrtRSI{ 19,    // lineNo
  "setdiff",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\setdiff.m"// pathName
};

static emlrtRSInfo pm_emlrtRSI{ 70,    // lineNo
  "eml_setop",                         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"// pathName
};

static emlrtRSInfo hn_emlrtRSI{ 117,   // lineNo
  "colon",                             // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pathName
};

static emlrtRSInfo tn_emlrtRSI{ 15,    // lineNo
  "min",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName
};

static emlrtRSInfo un_emlrtRSI{ 46,    // lineNo
  "minOrMax",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo vn_emlrtRSI{ 92,    // lineNo
  "minimum",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo wn_emlrtRSI{ 204,   // lineNo
  "unaryMinOrMax",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo xn_emlrtRSI{ 893,   // lineNo
  "minRealVectorOmitNaN",              // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo yn_emlrtRSI{ 387,   // lineNo
  "Checkerboard/predictPointsVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ao_emlrtRSI{ 388,   // lineNo
  "Checkerboard/predictPointsVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo eo_emlrtRSI{ 590,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fo_emlrtRSI{ 597,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo go_emlrtRSI{ 600,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ho_emlrtRSI{ 601,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo io_emlrtRSI{ 602,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jo_emlrtRSI{ 604,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ko_emlrtRSI{ 38,    // lineNo
  "ismember",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m"// pathName
};

static emlrtRSInfo vo_emlrtRSI{ 743,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wo_emlrtRSI{ 744,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xo_emlrtRSI{ 746,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yo_emlrtRSI{ 749,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ap_emlrtRSI{ 759,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bp_emlrtRSI{ 767,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo cp_emlrtRSI{ 774,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dp_emlrtRSI{ 837,   // lineNo
  "Checkerboard/arrayFind",            // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ep_emlrtRSI{ 443,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fp_emlrtRSI{ 508,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gp_emlrtRSI{ 509,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ip_emlrtRSI{ 578,   // lineNo
  "Checkerboard/fitPolyCurve",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jp_emlrtRSI{ 401,   // lineNo
  "Checkerboard/predictPointsHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo kp_emlrtRSI{ 402,   // lineNo
  "Checkerboard/predictPointsHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lp_emlrtRSI{ 788,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mp_emlrtRSI{ 789,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo np_emlrtRSI{ 791,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo op_emlrtRSI{ 794,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pp_emlrtRSI{ 804,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qp_emlrtRSI{ 812,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rp_emlrtRSI{ 819,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtBCInfo mc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  34,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  27,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo o_emlrtECI{ -1,     // nDims
  68,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo rc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ad_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI{ 88,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo p_emlrtECI{ -1,     // nDims
  89,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo hd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI{ 90,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo q_emlrtECI{ -1,     // nDims
  91,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo md_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI{ 92,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo r_emlrtECI{ -1,     // nDims
  93,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo rd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI{ 94,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo td_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo s_emlrtECI{ -1,     // nDims
  95,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo t_emlrtECI{ 2,      // nDims
  98,                                  // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo u_emlrtECI{ 2,      // nDims
  99,                                  // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo v_emlrtECI{ 2,      // nDims
  100,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo w_emlrtECI{ 2,      // nDims
  101,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo x_emlrtECI{ 2,      // nDims
  103,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo y_emlrtECI{ 2,      // nDims
  104,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo yd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ae_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ab_emlrtECI{ 2,     // nDims
  105,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo be_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ce_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo bb_emlrtECI{ 2,     // nDims
  106,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo de_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ee_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ge_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI{ 112,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo he_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ie_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo je_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo cb_emlrtECI{ -1,    // nDims
  112,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ke_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo le_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI{ 113,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo db_emlrtECI{ -1,    // nDims
  113,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo pe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI{ 114,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo re_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo se_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo te_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo eb_emlrtECI{ -1,    // nDims
  114,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ue_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ve_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI{ 115,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo we_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ye_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo fb_emlrtECI{ -1,    // nDims
  115,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo x_emlrtRTEI{ 15,   // lineNo
  27,                                  // colNo
  "assertCompatibleDims",              // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\assertCompatibleDims.m"// pName
};

static emlrtECInfo gb_emlrtECI{ -1,    // nDims
  235,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo hb_emlrtECI{ -1,    // nDims
  235,                                 // lineNo
  38,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo af_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI{ 238,    // lineNo
  19,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo bf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  19,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  241,                                 // lineNo
  19,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo df_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  231,                                 // lineNo
  81,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ef_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  231,                                 // lineNo
  75,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ff_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo if_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ib_emlrtECI{ 2,     // nDims
  158,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo jb_emlrtECI{ 2,     // nDims
  157,                                 // lineNo
  19,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo lf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo of_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo kb_emlrtECI{ 2,     // nDims
  149,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo lb_emlrtECI{ 2,     // nDims
  148,                                 // lineNo
  19,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo pf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI{ 252,    // lineNo
  36,                                  // colNo
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI{ 279,    // lineNo
  20,                                  // colNo
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  281,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  281,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  282,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  282,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  285,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  285,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  286,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  286,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  289,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ag_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  289,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  290,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  290,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  293,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  293,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  294,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  294,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  311,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ig_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  349,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  368,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  330,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo mb_emlrtECI{ 2,     // nDims
  389,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ng_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  401,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo og_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  402,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo nb_emlrtECI{ 2,     // nDims
  403,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo pg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  401,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI{ 401,    // lineNo
  46,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  402,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI{ 402,    // lineNo
  46,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo rg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI{ 387,    // lineNo
  43,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI{ 388,    // lineNo
  43,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo tg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  311,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ug_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  349,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  368,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  330,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  441,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  441,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ob_emlrtECI{ -1,    // nDims
  480,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ah_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo pb_emlrtECI{ 2,     // nDims
  503,                                 // lineNo
  30,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ch_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo qb_emlrtECI{ 2,     // nDims
  504,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo gh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ih_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo rb_emlrtECI{ 2,     // nDims
  505,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo kh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ph_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  575,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  575,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  576,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo th_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  576,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  105,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  105,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  575,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ai_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  576,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ci_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo di_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ei_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  480,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  662,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo sb_emlrtECI{ 2,     // nDims
  663,                                 // lineNo
  45,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo gi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  639,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI{ 639,    // lineNo
  48,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  670,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ii_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  654,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ji_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  654,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ki_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  668,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo li_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  663,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  597,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ni_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  599,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  601,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  601,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  599,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ri_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  600,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI{ 600,    // lineNo
  52,                                  // colNo
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo si_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  602,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ti_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  603,                                 // lineNo
  23,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ui_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo tb_emlrtECI{ -1,    // nDims
  679,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo ub_emlrtECI{ -1,    // nDims
  680,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo vb_emlrtECI{ -1,    // nDims
  686,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo wb_emlrtECI{ -1,    // nDims
  688,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo xi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  686,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI{ 678,    // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo x_emlrtDCI{ 682,    // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI{ 678,    // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI{ 682,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo yi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  686,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo aj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  686,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo xb_emlrtECI{ 3,     // nDims
  766,                                 // lineNo
  29,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo bj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  92,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  85,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ej_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo yb_emlrtECI{ 3,     // nDims
  764,                                 // lineNo
  27,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  91,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ij_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  83,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  763,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  757,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  749,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  749,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ac_emlrtECI{ 3,     // nDims
  746,                                 // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo tj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  88,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo bc_emlrtECI{ 3,     // nDims
  744,                                 // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo vj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  86,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo cc_emlrtECI{ 2,     // nDims
  738,                                 // lineNo
  24,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo yj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  739,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ak_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ck_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  93,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ek_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  49,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo bb_emlrtDCI{ 503,   // lineNo
  44,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ik_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  78,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI{ 503,   // lineNo
  74,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI{ 504,   // lineNo
  58,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  102,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI{ 504,   // lineNo
  98,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI{ 505,   // lineNo
  58,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  102,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI{ 505,   // lineNo
  98,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo nk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ok_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  526,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  556,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  694,                                 // lineNo
  22,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo dc_emlrtECI{ -1,    // nDims
  694,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo xk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  695,                                 // lineNo
  24,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ec_emlrtECI{ -1,    // nDims
  695,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo yk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo fc_emlrtECI{ -1,    // nDims
  701,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo al_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  703,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo gc_emlrtECI{ -1,    // nDims
  703,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo bl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI{ 693,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ib_emlrtDCI{ 697,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo jb_emlrtDCI{ 693,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo kb_emlrtDCI{ 697,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo cl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo lb_emlrtDCI{ 766,   // lineNo
  85,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo el_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  89,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo mb_emlrtDCI{ 766,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo nb_emlrtDCI{ 765,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ob_emlrtDCI{ 764,   // lineNo
  83,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pb_emlrtDCI{ 764,   // lineNo
  44,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo il_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI{ 757,   // lineNo
  41,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  757,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rb_emlrtDCI{ 746,   // lineNo
  88,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  92,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sb_emlrtDCI{ 746,   // lineNo
  50,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ll_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo tb_emlrtDCI{ 745,   // lineNo
  42,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ml_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ub_emlrtDCI{ 744,   // lineNo
  86,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo nl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  90,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo vb_emlrtDCI{ 744,   // lineNo
  48,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ol_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo wb_emlrtDCI{ 739,   // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  739,                                 // lineNo
  35,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI{ 738,   // lineNo
  68,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ql_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI{ 738,   // lineNo
  38,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo rl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  443,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  443,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ul_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo hc_emlrtECI{ -1,    // nDims
  507,                                 // lineNo
  30,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  69,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  109,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo am_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ic_emlrtECI{ -1,    // nDims
  508,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo bm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  69,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  109,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo em_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo jc_emlrtECI{ -1,    // nDims
  509,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo im_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo km_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo om_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo um_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo kc_emlrtECI{ -1,    // nDims
  709,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo lc_emlrtECI{ -1,    // nDims
  710,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo mc_emlrtECI{ -1,    // nDims
  716,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo nc_emlrtECI{ -1,    // nDims
  718,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ym_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ac_emlrtDCI{ 708,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo bc_emlrtDCI{ 713,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cc_emlrtDCI{ 708,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo dc_emlrtDCI{ 712,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo an_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo oc_emlrtECI{ 3,     // nDims
  811,                                 // lineNo
  29,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo cn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  85,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo en_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo pc_emlrtECI{ 3,     // nDims
  809,                                 // lineNo
  27,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo gn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo in_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  94,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  83,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ln_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  808,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  802,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo on_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  794,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  794,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo qc_emlrtECI{ 3,     // nDims
  791,                                 // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo un_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  97,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo rc_emlrtECI{ 3,     // nDims
  789,                                 // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo sc_emlrtECI{ -1,    // nDims
  783,                                 // lineNo
  24,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ao_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  784,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo co_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo do_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  86,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo go_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ho_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  88,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo io_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ec_emlrtDCI{ 507,   // lineNo
  46,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  80,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo fc_emlrtDCI{ 507,   // lineNo
  76,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ko_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  73,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gc_emlrtDCI{ 508,   // lineNo
  69,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  113,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hc_emlrtDCI{ 508,   // lineNo
  109,                                 // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  73,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ic_emlrtDCI{ 509,   // lineNo
  69,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo no_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  113,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jc_emlrtDCI{ 509,   // lineNo
  109,                                 // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo oo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo po_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ro_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo so_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo to_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  724,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo tc_emlrtECI{ -1,    // nDims
  724,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  725,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo uc_emlrtECI{ -1,    // nDims
  725,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo xo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo vc_emlrtECI{ -1,    // nDims
  731,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo yo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  733,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo wc_emlrtECI{ -1,    // nDims
  733,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ap_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kc_emlrtDCI{ 723,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo lc_emlrtDCI{ 728,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo mc_emlrtDCI{ 723,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo nc_emlrtDCI{ 727,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo bp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo oc_emlrtDCI{ 811,   // lineNo
  95,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo dp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  99,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pc_emlrtDCI{ 811,   // lineNo
  55,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ep_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qc_emlrtDCI{ 810,   // lineNo
  57,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  61,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rc_emlrtDCI{ 809,   // lineNo
  94,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sc_emlrtDCI{ 809,   // lineNo
  53,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo tc_emlrtDCI{ 802,   // lineNo
  44,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ip_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  802,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo uc_emlrtDCI{ 791,   // lineNo
  97,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  101,                                 // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo vc_emlrtDCI{ 791,   // lineNo
  59,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  63,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo wc_emlrtDCI{ 790,   // lineNo
  51,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo xc_emlrtDCI{ 789,   // lineNo
  95,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  99,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo yc_emlrtDCI{ 789,   // lineNo
  57,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo np_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  61,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ad_emlrtDCI{ 784,   // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo op_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  784,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo bd_emlrtDCI{ 783,   // lineNo
  70,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo cd_emlrtDCI{ 783,   // lineNo
  40,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gu_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hu_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo md_emlrtDCI{ 833,   // lineNo
  33,                                  // colNo
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo iu_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo ff_emlrtRTEI{ 60,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gf_emlrtRTEI{ 61,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hf_emlrtRTEI{ 63,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo if_emlrtRTEI{ 64,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jf_emlrtRTEI{ 65,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kf_emlrtRTEI{ 66,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lf_emlrtRTEI{ 68,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nf_emlrtRTEI{ 75,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo of_emlrtRTEI{ 75,  // lineNo
  56,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pf_emlrtRTEI{ 83,  // lineNo
  20,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qf_emlrtRTEI{ 88,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rf_emlrtRTEI{ 89,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sf_emlrtRTEI{ 90,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tf_emlrtRTEI{ 91,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uf_emlrtRTEI{ 92,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vf_emlrtRTEI{ 93,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wf_emlrtRTEI{ 94,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xf_emlrtRTEI{ 95,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yf_emlrtRTEI{ 98,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ag_emlrtRTEI{ 99,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bg_emlrtRTEI{ 100, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cg_emlrtRTEI{ 101, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dg_emlrtRTEI{ 103, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eg_emlrtRTEI{ 104, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fg_emlrtRTEI{ 105, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gg_emlrtRTEI{ 106, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hg_emlrtRTEI{ 107, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ig_emlrtRTEI{ 112, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jg_emlrtRTEI{ 112, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kg_emlrtRTEI{ 113, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lg_emlrtRTEI{ 113, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mg_emlrtRTEI{ 114, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ng_emlrtRTEI{ 114, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo og_emlrtRTEI{ 115, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pg_emlrtRTEI{ 115, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rg_emlrtRTEI{ 90,  // lineNo
  5,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"// pName
};

static emlrtRTEInfo sg_emlrtRTEI{ 76,  // lineNo
  9,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"// pName
};

static emlrtRTEInfo tg_emlrtRTEI{ 235, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ug_emlrtRTEI{ 235, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vg_emlrtRTEI{ 238, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wg_emlrtRTEI{ 227, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xg_emlrtRTEI{ 238, // lineNo
  19,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yg_emlrtRTEI{ 136, // lineNo
  20,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ah_emlrtRTEI{ 144, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bh_emlrtRTEI{ 145, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ch_emlrtRTEI{ 146, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dh_emlrtRTEI{ 148, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eh_emlrtRTEI{ 148, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fh_emlrtRTEI{ 149, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gh_emlrtRTEI{ 153, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hh_emlrtRTEI{ 154, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ih_emlrtRTEI{ 155, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jh_emlrtRTEI{ 157, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kh_emlrtRTEI{ 157, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lh_emlrtRTEI{ 158, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mh_emlrtRTEI{ 281, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nh_emlrtRTEI{ 282, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oh_emlrtRTEI{ 285, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ph_emlrtRTEI{ 286, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qh_emlrtRTEI{ 289, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rh_emlrtRTEI{ 290, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sh_emlrtRTEI{ 293, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo th_emlrtRTEI{ 294, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uh_emlrtRTEI{ 360, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vh_emlrtRTEI{ 401, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wh_emlrtRTEI{ 402, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xh_emlrtRTEI{ 403, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yh_emlrtRTEI{ 374, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ai_emlrtRTEI{ 374, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bi_emlrtRTEI{ 375, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ci_emlrtRTEI{ 387, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo di_emlrtRTEI{ 388, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ei_emlrtRTEI{ 389, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fi_emlrtRTEI{ 317, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gi_emlrtRTEI{ 317, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hi_emlrtRTEI{ 322, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ii_emlrtRTEI{ 336, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ji_emlrtRTEI{ 336, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ki_emlrtRTEI{ 337, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo li_emlrtRTEI{ 355, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mi_emlrtRTEI{ 355, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ni_emlrtRTEI{ 503, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oi_emlrtRTEI{ 503, // lineNo
  60,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pi_emlrtRTEI{ 425, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qi_emlrtRTEI{ 504, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ri_emlrtRTEI{ 504, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo si_emlrtRTEI{ 505, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ti_emlrtRTEI{ 505, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ui_emlrtRTEI{ 428, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vi_emlrtRTEI{ 433, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wi_emlrtRTEI{ 441, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xi_emlrtRTEI{ 575, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yi_emlrtRTEI{ 576, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo aj_emlrtRTEI{ 414, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gj_emlrtRTEI{ 28,  // lineNo
  9,                                   // colNo
  "colon",                             // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pName
};

static emlrtRTEInfo hj_emlrtRTEI{ 70,  // lineNo
  35,                                  // colNo
  "eml_setop",                         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"// pName
};

static emlrtRTEInfo ij_emlrtRTEI{ 639, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jj_emlrtRTEI{ 640, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kj_emlrtRTEI{ 640, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lj_emlrtRTEI{ 642, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mj_emlrtRTEI{ 672, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nj_emlrtRTEI{ 631, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oj_emlrtRTEI{ 670, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pj_emlrtRTEI{ 645, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qj_emlrtRTEI{ 652, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rj_emlrtRTEI{ 652, // lineNo
  61,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sj_emlrtRTEI{ 652, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tj_emlrtRTEI{ 650, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uj_emlrtRTEI{ 650, // lineNo
  45,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vj_emlrtRTEI{ 650, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wj_emlrtRTEI{ 654, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xj_emlrtRTEI{ 660, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yj_emlrtRTEI{ 662, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ak_emlrtRTEI{ 663, // lineNo
  45,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bk_emlrtRTEI{ 667, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ck_emlrtRTEI{ 668, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sk_emlrtRTEI{ 587, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tk_emlrtRTEI{ 39,  // lineNo
  5,                                   // colNo
  "find",                              // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"// pName
};

static emlrtRTEInfo uk_emlrtRTEI{ 597, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vk_emlrtRTEI{ 600, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wk_emlrtRTEI{ 601, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xk_emlrtRTEI{ 601, // lineNo
  44,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yk_emlrtRTEI{ 585, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo al_emlrtRTEI{ 602, // lineNo
  44,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cl_emlrtRTEI{ 678, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dl_emlrtRTEI{ 682, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo el_emlrtRTEI{ 677, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fl_emlrtRTEI{ 686, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gl_emlrtRTEI{ 738, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hl_emlrtRTEI{ 738, // lineNo
  54,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo il_emlrtRTEI{ 739, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jl_emlrtRTEI{ 737, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kl_emlrtRTEI{ 744, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ll_emlrtRTEI{ 744, // lineNo
  69,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ml_emlrtRTEI{ 745, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nl_emlrtRTEI{ 745, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ol_emlrtRTEI{ 746, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pl_emlrtRTEI{ 746, // lineNo
  71,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ql_emlrtRTEI{ 749, // lineNo
  35,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rl_emlrtRTEI{ 749, // lineNo
  46,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sl_emlrtRTEI{ 749, // lineNo
  65,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tl_emlrtRTEI{ 749, // lineNo
  78,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ul_emlrtRTEI{ 757, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vl_emlrtRTEI{ 764, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wl_emlrtRTEI{ 764, // lineNo
  66,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xl_emlrtRTEI{ 765, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yl_emlrtRTEI{ 764, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo am_emlrtRTEI{ 766, // lineNo
  29,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bm_emlrtRTEI{ 766, // lineNo
  68,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cm_emlrtRTEI{ 766, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dm_emlrtRTEI{ 770, // lineNo
  57,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo em_emlrtRTEI{ 770, // lineNo
  73,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fm_emlrtRTEI{ 768, // lineNo
  57,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gm_emlrtRTEI{ 768, // lineNo
  73,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hm_emlrtRTEI{ 693, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo im_emlrtRTEI{ 697, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jm_emlrtRTEI{ 692, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo km_emlrtRTEI{ 701, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lm_emlrtRTEI{ 507, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mm_emlrtRTEI{ 507, // lineNo
  60,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nm_emlrtRTEI{ 508, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo om_emlrtRTEI{ 508, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pm_emlrtRTEI{ 509, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qm_emlrtRTEI{ 509, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rm_emlrtRTEI{ 430, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sm_emlrtRTEI{ 443, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tm_emlrtRTEI{ 578, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo um_emlrtRTEI{ 579, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wm_emlrtRTEI{ 708, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xm_emlrtRTEI{ 712, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ym_emlrtRTEI{ 707, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo an_emlrtRTEI{ 716, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bn_emlrtRTEI{ 783, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cn_emlrtRTEI{ 783, // lineNo
  54,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dn_emlrtRTEI{ 784, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo en_emlrtRTEI{ 782, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fn_emlrtRTEI{ 789, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gn_emlrtRTEI{ 789, // lineNo
  69,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hn_emlrtRTEI{ 790, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo in_emlrtRTEI{ 791, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jn_emlrtRTEI{ 791, // lineNo
  71,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kn_emlrtRTEI{ 794, // lineNo
  35,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ln_emlrtRTEI{ 794, // lineNo
  46,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mn_emlrtRTEI{ 794, // lineNo
  65,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nn_emlrtRTEI{ 794, // lineNo
  78,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo on_emlrtRTEI{ 802, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pn_emlrtRTEI{ 809, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qn_emlrtRTEI{ 809, // lineNo
  66,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rn_emlrtRTEI{ 810, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sn_emlrtRTEI{ 809, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tn_emlrtRTEI{ 811, // lineNo
  29,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo un_emlrtRTEI{ 811, // lineNo
  68,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vn_emlrtRTEI{ 811, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wn_emlrtRTEI{ 815, // lineNo
  57,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xn_emlrtRTEI{ 815, // lineNo
  73,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yn_emlrtRTEI{ 813, // lineNo
  57,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ao_emlrtRTEI{ 813, // lineNo
  73,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bo_emlrtRTEI{ 443, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo co_emlrtRTEI{ 723, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo do_emlrtRTEI{ 727, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eo_emlrtRTEI{ 722, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fo_emlrtRTEI{ 731, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wr_emlrtRTEI{ 833, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xr_emlrtRTEI{ 835, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yr_emlrtRTEI{ 837, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo as_emlrtRTEI{ 837, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

// Function Definitions
namespace Codegen
{
  namespace coder
  {
    namespace vision
    {
      namespace internal
      {
        namespace calibration
        {
          namespace checkerboard
          {
            void Checkerboard::arrayFind(const emlrtStack *sp, const ::coder::
              array<boolean_T, 2U> &arr, ::coder::array<real_T, 2U> &matchedIdx)
            {
              ::coder::array<int32_T, 2U> b_ii;
              ::coder::array<int8_T, 2U> matchArr;
              ::coder::array<boolean_T, 2U> x;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack st;
              int32_T idx;
              int32_T ii;
              int32_T nx;
              boolean_T b_x[3];
              boolean_T exitg1;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              c_st.prev = &b_st;
              c_st.tls = b_st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              matchArr.set_size(&wr_emlrtRTEI, sp, 1, matchArr.size(1));
              if (arr.size(1) - 2 < 0) {
                emlrtNonNegativeCheckR2012b(static_cast<real_T>(arr.size(1) - 2),
                  &md_emlrtDCI, (emlrtCTX)sp);
              }

              matchArr.set_size(&wr_emlrtRTEI, sp, matchArr.size(0), arr.size(1)
                                - 2);
              ii = arr.size(1);
              for (idx = 0; idx <= ii - 3; idx++) {
                boolean_T y;
                if (idx + 1 > arr.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(idx + 1, 1, arr.size(1),
                    &gu_emlrtBCI, (emlrtCTX)sp);
                }

                if (idx + 3 > arr.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(idx + 3, 1, arr.size(1),
                    &hu_emlrtBCI, (emlrtCTX)sp);
                }

                b_ii.set_size(&xr_emlrtRTEI, sp, 1, 3);
                for (nx = 0; nx < 3; nx++) {
                  b_ii[nx] = arr[idx + nx];
                }

                b_x[0] = (b_ii[0] == 1);
                b_x[1] = (b_ii[1] == 1);
                b_x[2] = (b_ii[2] == 1);
                y = true;
                nx = 0;
                exitg1 = false;
                while ((!exitg1) && (nx < 3)) {
                  if (!b_x[nx]) {
                    y = false;
                    exitg1 = true;
                  } else {
                    nx++;
                  }
                }

                if (idx + 1 > matchArr.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(idx + 1, 1, matchArr.size(1),
                    &iu_emlrtBCI, (emlrtCTX)sp);
                }

                matchArr[idx] = static_cast<int8_T>(y);
              }

              st.site = &dp_emlrtRSI;
              x.set_size(&yr_emlrtRTEI, &st, 1, matchArr.size(1));
              nx = matchArr.size(1);
              for (ii = 0; ii < nx; ii++) {
                x[ii] = (matchArr[ii] == 1);
              }

              b_st.site = &se_emlrtRSI;
              nx = x.size(1);
              c_st.site = &te_emlrtRSI;
              idx = 0;
              b_ii.set_size(&vm_emlrtRTEI, &c_st, 1, x.size(1));
              ii = 0;
              exitg1 = false;
              while ((!exitg1) && (ii <= nx - 1)) {
                if (x[ii]) {
                  idx++;
                  b_ii[idx - 1] = ii + 1;
                  if (idx >= nx) {
                    exitg1 = true;
                  } else {
                    ii++;
                  }
                } else {
                  ii++;
                }
              }

              if (idx > x.size(1)) {
                emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
                  "Coder:builtins:AssertionFailed",
                  "Coder:builtins:AssertionFailed", 0);
              }

              if (x.size(1) == 1) {
                if (idx == 0) {
                  b_ii.set_size(&tk_emlrtRTEI, &c_st, 1, 0);
                }
              } else {
                if (1 > idx) {
                  idx = 0;
                }

                b_ii.set_size(&tk_emlrtRTEI, &c_st, b_ii.size(0), idx);
              }

              matchedIdx.set_size(&as_emlrtRTEI, &st, 1, b_ii.size(1));
              nx = b_ii.size(1);
              for (ii = 0; ii < nx; ii++) {
                matchedIdx[ii] = b_ii[ii];
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::b_fitPolynomialIndices(const emlrtStack *sp, ::
              coder::array<real_T, 2U> &newIndices) const
            {
              ::coder::array<real_T, 2U> b_index;
              ::coder::array<real_T, 2U> c_this;
              ::coder::array<real_T, 2U> removedIdx;
              ::coder::array<real_T, 1U> r3;
              ::coder::array<real_T, 1U> r5;
              ::coder::array<int32_T, 2U> ii;
              ::coder::array<int32_T, 1U> r2;
              ::coder::array<int32_T, 1U> r4;
              ::coder::array<int32_T, 1U> r6;
              ::coder::array<int32_T, 1U> r7;
              ::coder::array<boolean_T, 1U> r;
              ::coder::array<boolean_T, 1U> r1;
              emlrtStack b_st;
              emlrtStack st;
              real_T currCurve_data[5];
              real_T coordsToUse[2];
              real_T currPt[2];
              real_T currRad;
              real_T x;
              int32_T currCurve_size[2];
              int32_T b_i;
              int32_T end;
              int32_T i;
              int32_T loop_ub;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              st.site = &yj_emlrtRSI;
              i = BoardIdx.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ul_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(0);
              r.set_size(&lm_emlrtRTEI, &st, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[i] > 0.0);
              }

              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &vl_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&mm_emlrtRTEI, &st, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[i + BoardIdx.size(0)] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &hc_emlrtECI,
                  &st);
              }

              i = BoardCoords.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &wl_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &xl_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r2.set_size(&pi_emlrtRTEI, &st, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r2[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(0);
              r3.set_size(&nm_emlrtRTEI, &st, r2.size(0));
              loop_ub = r2.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r2[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r2[i], 1, b_i, &pm_emlrtBCI, &st);
                }

                r3[i] = BoardCoords[(r2[i] + BoardCoords.size(0)) - 1];
              }

              i = BoardCoords.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &yl_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &am_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r4.set_size(&pi_emlrtRTEI, &st, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r4[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(0);
              r5.set_size(&om_emlrtRTEI, &st, r4.size(0));
              loop_ub = r4.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r4[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r4[i], 1, b_i, &qm_emlrtBCI, &st);
                }

                r5[i] = BoardCoords[r4[i] - 1];
              }

              if (r3.size(0) != r5.size(0)) {
                emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &ic_emlrtECI,
                  &st);
              }

              loop_ub = r3.size(0);
              for (i = 0; i < loop_ub; i++) {
                r3[i] = r3[i] - r5[i];
              }

              b_st.site = &fp_emlrtRSI;
              x = mean(&b_st, r3);
              i = BoardCoords.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &bm_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &cm_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r6.set_size(&pi_emlrtRTEI, &st, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r6[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(0);
              r3.set_size(&pm_emlrtRTEI, &st, r6.size(0));
              loop_ub = r6.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r6[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r6[i], 1, b_i, &rm_emlrtBCI, &st);
                }

                r3[i] = BoardCoords[((r6[i] + BoardCoords.size(0)) +
                                     BoardCoords.size(0) * BoardCoords.size(1))
                  - 1];
              }

              i = BoardCoords.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &dm_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &em_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r7.set_size(&pi_emlrtRTEI, &st, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r7[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(0);
              r5.set_size(&qm_emlrtRTEI, &st, r7.size(0));
              loop_ub = r7.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r7[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r7[i], 1, b_i, &sm_emlrtBCI, &st);
                }

                r5[i] = BoardCoords[(r7[i] + BoardCoords.size(0) *
                                     BoardCoords.size(1)) - 1];
              }

              if (r3.size(0) != r5.size(0)) {
                emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &jc_emlrtECI,
                  &st);
              }

              loop_ub = r3.size(0);
              for (i = 0; i < loop_ub; i++) {
                r3[i] = r3[i] - r5[i];
              }

              b_st.site = &gp_emlrtRSI;
              currRad = mean(&b_st, r3);
              if (muDoubleScalarAbs(x) > muDoubleScalarAbs(currRad)) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }

              newIndices.set_size(&rm_emlrtRTEI, sp, 1, BoardCoords.size(0));
              loop_ub = BoardCoords.size(0);
              for (i = 0; i < loop_ub; i++) {
                newIndices[i] = 0.0;
              }

              removedIdx.set_size(&vi_emlrtRTEI, sp, 1, 0);
              i = BoardCoords.size(0);
              for (int32_T j{0}; j < i; j++) {
                int32_T i1;
                int32_T i2;
                st.site = &ep_emlrtRSI;
                i1 = BoardCoords.size(0);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &sl_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(2);
                i2 = static_cast<int32_T>(coordsToUse[0]);
                if (i2 > i1) {
                  emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &tl_emlrtBCI, &st);
                }

                loop_ub = BoardCoords.size(1);
                b_index.set_size(&sm_emlrtRTEI, &st, 1, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_index[i1] = BoardCoords[(j + BoardCoords.size(0) * i1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                }

                b_st.site = &se_emlrtRSI;
                b_eml_find(&b_st, b_index, ii);
                if (ii.size(1) >= 2) {
                  real_T currCoord;
                  real_T refCoordValue;
                  int32_T b_this;
                  int32_T coordDist_tmp;
                  int32_T n;
                  boolean_T exitg1;
                  st.site = &bk_emlrtRSI;
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &km_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(1);
                  end = ii[0];
                  if ((end < 1) || (end > i1)) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i1, &jm_emlrtBCI, &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &im_emlrtBCI, &st);
                  }

                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &hm_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(1);
                  end = ii[1];
                  if ((end < 1) || (end > i1)) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i1, &gm_emlrtBCI, &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fm_emlrtBCI, &st);
                  }

                  coordDist_tmp = ii[0];
                  x = (BoardCoords[(j + BoardCoords.size(0) * (ii[0] - 1)) +
                       BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)] -
                       BoardCoords[(j + BoardCoords.size(0) * (ii[1] - 1)) +
                       BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)]) /
                    (static_cast<real_T>(ii[1]) - static_cast<real_T>
                     (coordDist_tmp));
                  st.site = &ck_emlrtRSI;
                  n = 0;
                  i1 = ii.size(1);
                  for (end = 0; end < i1; end++) {
                    if (ii[end] != 0) {
                      n++;
                    }
                  }

                  b_i = BoardCoords.size(1);
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &lm_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &mm_emlrtBCI, &st);
                  }

                  b_this = BoardCoords.size(1);
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &nm_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  end = static_cast<int32_T>(coordsToUse[1]);
                  if (end > i1) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i1, &om_emlrtBCI, &st);
                  }

                  b_index.set_size(&tm_emlrtRTEI, &st, 1, ii.size(1));
                  loop_ub = ii.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > b_i)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, b_i, &tm_emlrtBCI,
                        &st);
                    }

                    b_index[i1] = BoardCoords[(j + BoardCoords.size(0) * (ii[i1]
                      - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * (i2 -
                      1)];
                  }

                  c_this.set_size(&um_emlrtRTEI, &st, 1, ii.size(1));
                  loop_ub = ii.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > b_this)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, b_this,
                        &um_emlrtBCI, &st);
                    }

                    c_this[i1] = BoardCoords[(j + BoardCoords.size(0) * (ii[i1]
                      - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * (
                      static_cast<int32_T>(coordsToUse[1]) - 1)];
                  }

                  if (n > 5) {
                    n = 4;
                  } else {
                    n = 2;
                  }

                  b_st.site = &ip_emlrtRSI;
                  polyfit(&b_st, b_index, c_this, static_cast<real_T>(n),
                          currCurve_data, currCurve_size);
                  currRad = x / 4.0;
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &vm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if ((ii[0] < 1) || (ii[0] > i1)) {
                    emlrtDynamicBoundsCheckR2012b(ii[0], 1, i1, &wm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &xm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  refCoordValue = BoardCoords[(j + BoardCoords.size(0) * (ii[0]
                    - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (muDoubleScalarAbs(currCoord -
                           refCoordValue) < static_cast<real_T>(coordDist_tmp) *
                                       1.5 * muDoubleScalarAbs(x))) {
                    boolean_T exitg2;
                    boolean_T p;
                    p = true;
                    end = 0;
                    exitg2 = false;
                    while ((!exitg2) && (end < 2)) {
                      if (static_cast<int32_T>(coordsToUse[end]) != end + 1) {
                        p = false;
                        exitg2 = true;
                      } else {
                        end++;
                      }
                    }

                    if (p) {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = currCoord;
                      currPt[1] = y;
                    } else {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    st.site = &dk_emlrtRSI;
                    findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                       currCurve_data, currCurve_size,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      if (1 != b_index.size(1)) {
                        emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                          &ob_emlrtECI, (emlrtCTX)sp);
                      }

                      if ((j + 1 < 1) || (j + 1 > newIndices.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(j + 1, 1, newIndices.size
                          (1), &ei_emlrtBCI, (emlrtCTX)sp);
                      }

                      newIndices[j] = b_index[0];
                      i1 = removedIdx.size(1);
                      loop_ub = b_index.size(1);
                      removedIdx.set_size(&aj_emlrtRTEI, sp, removedIdx.size(0),
                                          removedIdx.size(1) + b_index.size(1));
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        removedIdx[i1 + i2] = b_index[i2];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::b_fitPolynomialIndices(const emlrtStack *sp,
              const ::coder::array<real_T, 2U> &idx, ::coder::array<real_T, 2U>
              &newIndices) const
            {
              ::coder::array<real_T, 2U> c_this;
              ::coder::array<real_T, 2U> d_this;
              ::coder::array<real_T, 2U> removedIdx;
              ::coder::array<real_T, 2U> validIdx;
              ::coder::array<real_T, 1U> r3;
              ::coder::array<real_T, 1U> r5;
              ::coder::array<int32_T, 2U> ii;
              ::coder::array<int32_T, 1U> r2;
              ::coder::array<int32_T, 1U> r4;
              ::coder::array<int32_T, 1U> r6;
              ::coder::array<int32_T, 1U> r7;
              ::coder::array<boolean_T, 1U> r;
              ::coder::array<boolean_T, 1U> r1;
              emlrtStack b_st;
              emlrtStack st;
              real_T currCurve_data[5];
              real_T coordsToUse[2];
              real_T currPt[2];
              real_T b_x;
              real_T x;
              int32_T currCurve_size[2];
              int32_T b_idx;
              int32_T b_this;
              int32_T c_idx;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              int32_T trueCount;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              st.site = &yj_emlrtRSI;
              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &io_emlrtBCI,
                  &st);
              }

              i = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &ec_emlrtDCI, &st);
              }

              i1 = BoardIdx.size(1);
              b_idx = static_cast<int32_T>(idx[0]);
              if ((b_idx < 1) || (b_idx > i1)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1,
                  i1, &ul_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(0);
              r.set_size(&lm_emlrtRTEI, &st, loop_ub);
              for (i1 = 0; i1 < loop_ub; i1++) {
                r[i1] = (BoardIdx[i1 + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &jo_emlrtBCI,
                  &st);
              }

              i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &fc_emlrtDCI, &st);
              }

              i2 = BoardIdx.size(1);
              c_idx = static_cast<int32_T>(idx[1]);
              if ((c_idx < 1) || (c_idx > i2)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i2, &vl_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&mm_emlrtRTEI, &st, loop_ub);
              for (i2 = 0; i2 < loop_ub; i2++) {
                r1[i2] = (BoardIdx[i2 + BoardIdx.size(0) * (c_idx - 1)] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &hc_emlrtECI,
                  &st);
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ko_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (1 > i2) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i2, &xl_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  trueCount++;
                }
              }

              r2.set_size(&pi_emlrtRTEI, &st, trueCount);
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  r2[trueCount] = loop_ub + 1;
                  trueCount++;
                }
              }

              b_this = BoardCoords.size(0);
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &gc_emlrtDCI, &st);
              }

              i2 = BoardCoords.size(1);
              if (c_idx > i2) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i2, &wl_emlrtBCI, &st);
              }

              r3.set_size(&nm_emlrtRTEI, &st, r2.size(0));
              loop_ub = r2.size(0);
              for (i2 = 0; i2 < loop_ub; i2++) {
                if (r2[i2] > b_this) {
                  emlrtDynamicBoundsCheckR2012b(r2[i2], 1, b_this, &pm_emlrtBCI,
                    &st);
                }

                r3[i2] = BoardCoords[(r2[i2] + BoardCoords.size(0) * (c_idx - 1))
                  - 1];
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &lo_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (1 > i2) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i2, &am_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  trueCount++;
                }
              }

              r4.set_size(&pi_emlrtRTEI, &st, trueCount);
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  r4[trueCount] = loop_ub + 1;
                  trueCount++;
                }
              }

              b_this = BoardCoords.size(0);
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &hc_emlrtDCI, &st);
              }

              i2 = BoardCoords.size(1);
              if (b_idx > i2) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1,
                  i2, &yl_emlrtBCI, &st);
              }

              r5.set_size(&om_emlrtRTEI, &st, r4.size(0));
              loop_ub = r4.size(0);
              for (i2 = 0; i2 < loop_ub; i2++) {
                if (r4[i2] > b_this) {
                  emlrtDynamicBoundsCheckR2012b(r4[i2], 1, b_this, &qm_emlrtBCI,
                    &st);
                }

                r5[i2] = BoardCoords[(r4[i2] + BoardCoords.size(0) * (b_idx - 1))
                  - 1];
              }

              if (r3.size(0) != r5.size(0)) {
                emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &ic_emlrtECI,
                  &st);
              }

              loop_ub = r3.size(0);
              for (i2 = 0; i2 < loop_ub; i2++) {
                r3[i2] = r3[i2] - r5[i2];
              }

              b_st.site = &fp_emlrtRSI;
              x = mean(&b_st, r3);
              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &mo_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (2 > i2) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i2, &cm_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  trueCount++;
                }
              }

              r6.set_size(&pi_emlrtRTEI, &st, trueCount);
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  r6[trueCount] = loop_ub + 1;
                  trueCount++;
                }
              }

              b_this = BoardCoords.size(0);
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &ic_emlrtDCI, &st);
              }

              i1 = BoardCoords.size(1);
              if (c_idx > i1) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i1, &bm_emlrtBCI, &st);
              }

              r3.set_size(&pm_emlrtRTEI, &st, r6.size(0));
              loop_ub = r6.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                if (r6[i1] > b_this) {
                  emlrtDynamicBoundsCheckR2012b(r6[i1], 1, b_this, &rm_emlrtBCI,
                    &st);
                }

                r3[i1] = BoardCoords[((r6[i1] + BoardCoords.size(0) * (c_idx - 1))
                                      + BoardCoords.size(0) * BoardCoords.size(1))
                  - 1];
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &no_emlrtBCI,
                  &st);
              }

              i1 = BoardCoords.size(2);
              if (2 > i1) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i1, &em_emlrtBCI, &st);
              }

              end = r.size(0) - 1;
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  trueCount++;
                }
              }

              r7.set_size(&pi_emlrtRTEI, &st, trueCount);
              trueCount = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (r[loop_ub] && r1[loop_ub]) {
                  r7[trueCount] = loop_ub + 1;
                  trueCount++;
                }
              }

              b_this = BoardCoords.size(0);
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &jc_emlrtDCI, &st);
              }

              i = BoardCoords.size(1);
              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1, i,
                  &dm_emlrtBCI, &st);
              }

              r5.set_size(&qm_emlrtRTEI, &st, r7.size(0));
              loop_ub = r7.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r7[i] > b_this) {
                  emlrtDynamicBoundsCheckR2012b(r7[i], 1, b_this, &sm_emlrtBCI,
                    &st);
                }

                r5[i] = BoardCoords[((r7[i] + BoardCoords.size(0) * (b_idx - 1))
                                     + BoardCoords.size(0) * BoardCoords.size(1))
                  - 1];
              }

              if (r3.size(0) != r5.size(0)) {
                emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &jc_emlrtECI,
                  &st);
              }

              loop_ub = r3.size(0);
              for (i = 0; i < loop_ub; i++) {
                r3[i] = r3[i] - r5[i];
              }

              b_st.site = &gp_emlrtRSI;
              b_x = mean(&b_st, r3);
              if (muDoubleScalarAbs(x) > muDoubleScalarAbs(b_x)) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }

              newIndices.set_size(&rm_emlrtRTEI, sp, 1, BoardCoords.size(0));
              loop_ub = BoardCoords.size(0);
              for (i = 0; i < loop_ub; i++) {
                newIndices[i] = 0.0;
              }

              removedIdx.set_size(&vi_emlrtRTEI, sp, 1, 0);
              i = BoardCoords.size(0);
              for (int32_T j{0}; j < i; j++) {
                st.site = &ep_emlrtRSI;
                i1 = BoardCoords.size(0);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &sl_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(2);
                i2 = static_cast<int32_T>(coordsToUse[0]);
                if (i2 > i1) {
                  emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &tl_emlrtBCI, &st);
                }

                loop_ub = BoardCoords.size(1);
                c_this.set_size(&sm_emlrtRTEI, &st, 1, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  c_this[i1] = BoardCoords[(j + BoardCoords.size(0) * i1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                }

                b_st.site = &se_emlrtRSI;
                b_eml_find(&b_st, c_this, ii);
                validIdx.set_size(&bo_emlrtRTEI, &st, 1, ii.size(1));
                loop_ub = ii.size(1);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  validIdx[i1] = ii[i1];
                }

                if (validIdx.size(1) >= 2) {
                  real_T currCoord;
                  real_T currRad;
                  real_T refCoordValue;
                  boolean_T exitg1;
                  st.site = &bk_emlrtRSI;
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &tk_emlrtBCI, &st);
                  }

                  if (idx[0] == 1.0) {
                    i1 = BoardCoords.size(0);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &km_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    b_idx = static_cast<int32_T>(validIdx[0]);
                    if ((b_idx < 1) || (b_idx > i1)) {
                      emlrtDynamicBoundsCheckR2012b(b_idx, 1, i1, &jm_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &im_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(0);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &hm_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    trueCount = static_cast<int32_T>(validIdx[1]);
                    if ((trueCount < 1) || (trueCount > i1)) {
                      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1,
                        &gm_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fm_emlrtBCI, &st);
                    }

                    x = b_idx;
                    b_x = (BoardCoords[(j + BoardCoords.size(0) * (b_idx - 1)) +
                           BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)]
                           - BoardCoords[(j + BoardCoords.size(0) * (trueCount -
                             1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                           (i2 - 1)]) / static_cast<real_T>(trueCount - b_idx);
                  } else {
                    i1 = BoardCoords.size(0);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &to_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    trueCount = static_cast<int32_T>(validIdx[validIdx.size(1) -
                      1]);
                    if ((trueCount < 1) || (trueCount > i1)) {
                      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1,
                        &so_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ro_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(0);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &qo_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    if (validIdx.size(1) - 1 > validIdx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(validIdx.size(1) - 1, 1,
                        validIdx.size(1), &uo_emlrtBCI, &st);
                    }

                    trueCount = static_cast<int32_T>(validIdx[validIdx.size(1) -
                      2]);
                    if ((trueCount < 1) || (trueCount > i1)) {
                      emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1,
                        &po_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &oo_emlrtBCI, &st);
                    }

                    x = (static_cast<real_T>(BoardCoords.size(1)) - static_cast<
                         real_T>(static_cast<int32_T>(validIdx[validIdx.size(1)
                           - 1]))) + 1.0;
                    b_idx = static_cast<int32_T>(validIdx[validIdx.size(1) - 1]);
                    if (validIdx.size(1) - 1 > validIdx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(validIdx.size(1) - 1, 1,
                        validIdx.size(1), &vk_emlrtBCI, &st);
                    }

                    b_x = (BoardCoords[(j + BoardCoords.size(0) *
                                        (static_cast<int32_T>
                                         (validIdx[validIdx.size(1) - 1]) - 1))
                           + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)]
                           - BoardCoords[(j + BoardCoords.size(0) * (
                             static_cast<int32_T>(validIdx[validIdx.size(1) - 2])
                             - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                           (i2 - 1)]) / (static_cast<real_T>(static_cast<int32_T>
                      (validIdx[validIdx.size(1) - 1])) - static_cast<real_T>(
                      static_cast<int32_T>(validIdx[validIdx.size(1) - 2])));
                  }

                  st.site = &ck_emlrtRSI;
                  c_idx = 0;
                  i1 = validIdx.size(1);
                  for (trueCount = 0; trueCount < i1; trueCount++) {
                    if (static_cast<int32_T>(validIdx[trueCount]) != 0) {
                      c_idx++;
                    }
                  }

                  b_this = BoardCoords.size(1);
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &lm_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &mm_emlrtBCI, &st);
                  }

                  end = BoardCoords.size(1);
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &nm_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  trueCount = static_cast<int32_T>(coordsToUse[1]);
                  if (trueCount > i1) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &om_emlrtBCI,
                      &st);
                  }

                  c_this.set_size(&tm_emlrtRTEI, &st, 1, validIdx.size(1));
                  loop_ub = validIdx.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    trueCount = static_cast<int32_T>(validIdx[i1]);
                    if ((trueCount < 1) || (trueCount > b_this)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                        (validIdx[i1]), 1, b_this, &tm_emlrtBCI, &st);
                    }

                    c_this[i1] = BoardCoords[(j + BoardCoords.size(0) *
                      (trueCount - 1)) + BoardCoords.size(0) * BoardCoords.size
                      (1) * (static_cast<int32_T>(coordsToUse[0]) - 1)];
                  }

                  d_this.set_size(&um_emlrtRTEI, &st, 1, validIdx.size(1));
                  loop_ub = validIdx.size(1);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    trueCount = static_cast<int32_T>(validIdx[i1]);
                    if ((trueCount < 1) || (trueCount > end)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                        (validIdx[i1]), 1, end, &um_emlrtBCI, &st);
                    }

                    d_this[i1] = BoardCoords[(j + BoardCoords.size(0) *
                      (trueCount - 1)) + BoardCoords.size(0) * BoardCoords.size
                      (1) * (static_cast<int32_T>(coordsToUse[1]) - 1)];
                  }

                  if (c_idx > 5) {
                    c_idx = 4;
                  } else {
                    c_idx = 2;
                  }

                  b_st.site = &ip_emlrtRSI;
                  polyfit(&b_st, c_this, d_this, static_cast<real_T>(c_idx),
                          currCurve_data, currCurve_size);
                  currRad = b_x / 4.0;
                  i1 = BoardCoords.size(0);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &vm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if ((b_idx < 1) || (b_idx > i1)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i1, &wm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &xm_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  refCoordValue = BoardCoords[(j + BoardCoords.size(0) * (b_idx
                    - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (muDoubleScalarAbs(currCoord -
                           refCoordValue) < x * 1.5 * muDoubleScalarAbs(b_x))) {
                    boolean_T exitg2;
                    boolean_T p;
                    p = true;
                    trueCount = 0;
                    exitg2 = false;
                    while ((!exitg2) && (trueCount < 2)) {
                      if (static_cast<int32_T>(coordsToUse[trueCount]) !=
                          trueCount + 1) {
                        p = false;
                        exitg2 = true;
                      } else {
                        trueCount++;
                      }
                    }

                    if (p) {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve_data[trueCount + 1];
                      }

                      currPt[0] = currCoord;
                      currPt[1] = y;
                    } else {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve_data[trueCount + 1];
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    st.site = &dk_emlrtRSI;
                    findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                       currCurve_data, currCurve_size,
                                       coordsToUse, removedIdx, validIdx);
                    if (validIdx.size(1) != 0) {
                      if (1 != validIdx.size(1)) {
                        emlrtSubAssignSizeCheck1dR2017a(1, validIdx.size(1),
                          &ob_emlrtECI, (emlrtCTX)sp);
                      }

                      if ((j + 1 < 1) || (j + 1 > newIndices.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(j + 1, 1, newIndices.size
                          (1), &ei_emlrtBCI, (emlrtCTX)sp);
                      }

                      newIndices[j] = validIdx[0];
                      i1 = removedIdx.size(1);
                      loop_ub = validIdx.size(1);
                      removedIdx.set_size(&aj_emlrtRTEI, sp, removedIdx.size(0),
                                          removedIdx.size(1) + validIdx.size(1));
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        removedIdx[i1 + i2] = validIdx[i2];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            real32_T Checkerboard::computeInitialEnergy(const emlrtStack *sp)
              const
            {
              ::coder::array<real32_T, 2U> col1;
              ::coder::array<real32_T, 2U> col2;
              ::coder::array<real32_T, 2U> row3;
              ::coder::array<boolean_T, 1U> b_this;
              emlrtStack st;
              int32_T iv[2];
              int32_T iv1[2];
              int32_T i;
              int32_T idx;
              real32_T x[3];
              real32_T e;
              st.prev = sp;
              st.tls = sp->tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              idx = BoardIdx.size(0) * BoardIdx.size(1);
              b_this.set_size(&yg_emlrtRTEI, sp, idx);
              for (i = 0; i < idx; i++) {
                b_this[i] = (BoardIdx[i] < 0.0);
              }

              st.site = &di_emlrtRSI;
              if (any(&st, b_this)) {
                e = rtInfF;
              } else {
                real_T d;
                int32_T c_this;
                int32_T loop_ub;
                real32_T b_ex;
                real32_T boardSize;
                real32_T ex;
                boolean_T exitg1;
                st.site = &ei_emlrtRSI;
                i = BoardIdx.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &gf_emlrtBCI, &st);
                }

                idx = BoardIdx.size(1);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                col1.set_size(&ah_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[0];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0)];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                st.site = &fi_emlrtRSI;
                i = BoardIdx.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &gf_emlrtBCI, &st);
                }

                idx = BoardIdx.size(1);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                col2.set_size(&bh_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) + 1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2 + 1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                st.site = &gi_emlrtRSI;
                i = BoardIdx.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &gf_emlrtBCI, &st);
                }

                idx = BoardIdx.size(1);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                row3.set_size(&ch_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) + 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &ff_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2 + 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])row3.size())[0];
                iv1[1] = (*(int32_T (*)[2])row3.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &lb_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col2.size(1);
                col2.set_size(&dh_emlrtRTEI, sp, 3, col2.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col2[i] = 2.0F * col2[i];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])col2.size())[0];
                iv1[1] = (*(int32_T (*)[2])col2.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &lb_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col1.size(1);
                col2.set_size(&eh_emlrtRTEI, sp, 3, col1.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col2[i] = (col1[i] + row3[i]) - col2[i];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])row3.size())[0];
                iv1[1] = (*(int32_T (*)[2])row3.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &kb_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col1.size(1);
                col1.set_size(&fh_emlrtRTEI, sp, 3, col1.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col1[i] = col1[i] - row3[i];
                }

                if (1 > col2.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, col2.size(1), &of_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (2 > col2.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, col2.size(1), &nf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (1 > col1.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, col1.size(1), &mf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (2 > col1.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, col1.size(1), &lf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                x[0] = muSingleScalarHypot(col2[0], col2[3]) /
                  muSingleScalarHypot(col1[0], col1[3]);
                x[1] = muSingleScalarHypot(col2[1], col2[4]) /
                  muSingleScalarHypot(col1[1], col1[4]);
                x[2] = muSingleScalarHypot(col2[2], col2[5]) /
                  muSingleScalarHypot(col1[2], col1[5]);
                if (!muSingleScalarIsNaN(x[0])) {
                  idx = 1;
                } else {
                  idx = 0;
                  c_this = 2;
                  exitg1 = false;
                  while ((!exitg1) && (c_this < 4)) {
                    if (!muSingleScalarIsNaN(x[c_this - 1])) {
                      idx = c_this;
                      exitg1 = true;
                    } else {
                      c_this++;
                    }
                  }
                }

                if (idx == 0) {
                  ex = x[0];
                } else {
                  ex = x[idx - 1];
                  idx++;
                  for (c_this = idx; c_this < 4; c_this++) {
                    boardSize = x[c_this - 1];
                    if (ex < boardSize) {
                      ex = boardSize;
                    }
                  }
                }

                st.site = &ii_emlrtRSI;
                i = BoardIdx.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ff_emlrtBCI, &st);
                }

                idx = BoardIdx.size(0);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                col1.set_size(&gh_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[0];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col1[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                st.site = &ji_emlrtRSI;
                i = BoardIdx.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &ff_emlrtBCI, &st);
                }

                idx = BoardIdx.size(0);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                col2.set_size(&hh_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0)];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) + 1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) + 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  col2[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                st.site = &ki_emlrtRSI;
                i = BoardIdx.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &ff_emlrtBCI, &st);
                }

                idx = BoardIdx.size(0);
                c_this = Points.size(0);
                loop_ub = Points.size(1);
                row3.set_size(&ih_emlrtRTEI, &st, 3, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  if (1 > idx) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0)
                                        * i) - 1];
                  if (2 > idx) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2 + 1];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i + 1] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                  if (3 > idx) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &gf_emlrtBCI, &st);
                  }

                  d = BoardIdx[BoardIdx.size(0) * 2 + 2];
                  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                    emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
                  }

                  if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                       c_this)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                      c_this, &pf_emlrtBCI, &st);
                  }

                  row3[3 * i + 2] = Points[(static_cast<int32_T>(d) +
                    Points.size(0) * i) - 1];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])row3.size())[0];
                iv1[1] = (*(int32_T (*)[2])row3.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &jb_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col2.size(1);
                col2.set_size(&jh_emlrtRTEI, sp, 3, col2.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col2[i] = 2.0F * col2[i];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])col2.size())[0];
                iv1[1] = (*(int32_T (*)[2])col2.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &jb_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col1.size(1);
                col2.set_size(&kh_emlrtRTEI, sp, 3, col1.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col2[i] = (col1[i] + row3[i]) - col2[i];
                }

                iv[0] = (*(int32_T (*)[2])col1.size())[0];
                iv[1] = (*(int32_T (*)[2])col1.size())[1];
                iv1[0] = (*(int32_T (*)[2])row3.size())[0];
                iv1[1] = (*(int32_T (*)[2])row3.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &ib_emlrtECI,
                  (emlrtCTX)sp);
                loop_ub = 3 * col1.size(1);
                col1.set_size(&lh_emlrtRTEI, sp, 3, col1.size(1));
                for (i = 0; i < loop_ub; i++) {
                  col1[i] = col1[i] - row3[i];
                }

                if (1 > col2.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, col2.size(1), &kf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (2 > col2.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, col2.size(1), &jf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (1 > col1.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, col1.size(1), &if_emlrtBCI,
                    (emlrtCTX)sp);
                }

                if (2 > col1.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, col1.size(1), &hf_emlrtBCI,
                    (emlrtCTX)sp);
                }

                x[0] = muSingleScalarHypot(col2[0], col2[3]) /
                  muSingleScalarHypot(col1[0], col1[3]);
                x[1] = muSingleScalarHypot(col2[1], col2[4]) /
                  muSingleScalarHypot(col1[1], col1[4]);
                x[2] = muSingleScalarHypot(col2[2], col2[5]) /
                  muSingleScalarHypot(col1[2], col1[5]);
                if (!muSingleScalarIsNaN(x[0])) {
                  idx = 1;
                } else {
                  idx = 0;
                  c_this = 2;
                  exitg1 = false;
                  while ((!exitg1) && (c_this < 4)) {
                    if (!muSingleScalarIsNaN(x[c_this - 1])) {
                      idx = c_this;
                      exitg1 = true;
                    } else {
                      c_this++;
                    }
                  }
                }

                if (idx == 0) {
                  b_ex = x[0];
                } else {
                  b_ex = x[idx - 1];
                  idx++;
                  for (c_this = idx; c_this < 4; c_this++) {
                    boardSize = x[c_this - 1];
                    if (b_ex < boardSize) {
                      b_ex = boardSize;
                    }
                  }
                }

                boardSize = static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1));
                e = boardSize * muSingleScalarMax(muSingleScalarMax(0.0F, ex),
                  b_ex) - boardSize;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return e;
            }

            real32_T Checkerboard::computeNewEnergyHorizontal(const emlrtStack
              *sp, real32_T oldEnergy) const
            {
              ptrdiff_t incx_t;
              ptrdiff_t n_t;
              ::coder::array<real_T, 3U> denom;
              ::coder::array<real_T, 3U> num;
              ::coder::array<real_T, 3U> r10;
              ::coder::array<real_T, 3U> r4;
              ::coder::array<real_T, 3U> r6;
              ::coder::array<real_T, 3U> r7;
              ::coder::array<real_T, 3U> r9;
              ::coder::array<real_T, 2U> b_denom;
              ::coder::array<real_T, 2U> b_num;
              ::coder::array<real_T, 2U> validNewColIdx;
              ::coder::array<real_T, 1U> b_y;
              ::coder::array<real_T, 1U> c_num;
              ::coder::array<real_T, 1U> d_num;
              ::coder::array<real_T, 1U> x;
              ::coder::array<int32_T, 1U> r11;
              ::coder::array<int32_T, 1U> r12;
              ::coder::array<int32_T, 1U> r3;
              ::coder::array<int32_T, 1U> r5;
              ::coder::array<int32_T, 1U> r8;
              ::coder::array<boolean_T, 2U> b_this;
              ::coder::array<boolean_T, 1U> r;
              ::coder::array<boolean_T, 1U> r1;
              ::coder::array<boolean_T, 1U> r2;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack i_st;
              emlrtStack st;
              real_T ex;
              real_T y;
              int32_T iv[3];
              int32_T iv1[3];
              int32_T a;
              int32_T b_i;
              int32_T i;
              int32_T i1;
              int32_T idx;
              int32_T last;
              int32_T loop_ub;
              real32_T newEnergy;
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
              i = BoardIdx.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &co_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(0);
              r.set_size(&bn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[i] > 0.0);
              }

              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &bo_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&cn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[i + BoardIdx.size(0)] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &sc_emlrtECI,
                  (emlrtCTX)sp);
              }

              loop_ub = r.size(0);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (r[i] && r1[i]);
              }

              i = BoardIdx.size(1);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &ao_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&dn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[i + BoardIdx.size(0) * 2] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &sc_emlrtECI,
                  (emlrtCTX)sp);
              }

              newEnergy = 0.0F;
              r2.set_size(&bn_emlrtRTEI, sp, r.size(0));
              loop_ub = r.size(0);
              for (i = 0; i < loop_ub; i++) {
                r2[i] = (r[i] && r1[i]);
              }

              st.site = &lp_emlrtRSI;
              if (any(&st, r2)) {
                i = BoardCoords.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &yn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r3.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r3[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = BoardCoords.size(2);
                r4.set_size(&fn_emlrtRTEI, sp, r3.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r3.size(0);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r3[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r3[i1], 1, last,
                        &do_emlrtBCI, (emlrtCTX)sp);
                    }

                    r4[i1 + r4.size(0) * i] = BoardCoords[(r3[i1] +
                      BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                  }
                }

                i = BoardCoords.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &xn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r5.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r5[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = BoardCoords.size(2);
                r6.set_size(&gn_emlrtRTEI, sp, r5.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r5.size(0);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r5[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r5[i1], 1, last,
                        &eo_emlrtBCI, (emlrtCTX)sp);
                    }

                    r6[i1 + r6.size(0) * i] = BoardCoords[((r5[i1] +
                      BoardCoords.size(0) * 2) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r6.size())[0];
                iv1[1] = (*(int32_T (*)[3])r6.size())[1];
                iv1[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rc_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardCoords.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &wn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r8.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r8[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = r8.size(0);
                for (i = 0; i < loop_ub; i++) {
                  if (r8[i] > last) {
                    emlrtDynamicBoundsCheckR2012b(r8[i], 1, last, &fo_emlrtBCI,
                      (emlrtCTX)sp);
                  }
                }

                loop_ub = BoardCoords.size(2);
                r9.set_size(&hn_emlrtRTEI, sp, r8.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r8.size(0);
                  for (i1 = 0; i1 < idx; i1++) {
                    r9[i1 + r9.size(0) * i] = 2.0 * BoardCoords[((r8[i1] +
                      BoardCoords.size(0)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r9.size())[0];
                iv1[1] = (*(int32_T (*)[3])r9.size())[1];
                iv1[2] = (*(int32_T (*)[3])r9.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rc_emlrtECI,
                  (emlrtCTX)sp);
                r10.set_size(&fn_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
                loop_ub = r4.size(0) * r4.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r10[i] = (r4[i] + r6[i]) - r9[i];
                }

                st.site = &mp_emlrtRSI;
                b_squeeze(&st, r10, b_num);
                i = BoardCoords.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &vn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r11.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r11[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = BoardCoords.size(2);
                r4.set_size(&in_emlrtRTEI, sp, r11.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r11.size(0);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r11[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r11[i1], 1, last,
                        &go_emlrtBCI, (emlrtCTX)sp);
                    }

                    r4[i1 + r4.size(0) * i] = BoardCoords[(r11[i1] +
                      BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                  }
                }

                i = BoardCoords.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &un_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r12.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r12[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = BoardCoords.size(2);
                r6.set_size(&jn_emlrtRTEI, sp, r12.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r12.size(0);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r12[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r12[i1], 1, last,
                        &ho_emlrtBCI, (emlrtCTX)sp);
                    }

                    r6[i1 + r6.size(0) * i] = BoardCoords[((r12[i1] +
                      BoardCoords.size(0) * 2) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r6.size())[0];
                iv1[1] = (*(int32_T (*)[3])r6.size())[1];
                iv1[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &qc_emlrtECI,
                  (emlrtCTX)sp);
                r9.set_size(&in_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
                loop_ub = r4.size(0) * r4.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r9[i] = r4[i] - r6[i];
                }

                st.site = &np_emlrtRSI;
                b_squeeze(&st, r9, b_denom);
                if (b_num.size(1) > 1) {
                  if (1 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                      &tn_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (2 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                      &sn_emlrtBCI, (emlrtCTX)sp);
                  }

                  st.site = &op_emlrtRSI;
                  loop_ub = b_num.size(0);
                  c_num.set_size(&kn_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_num[i];
                  }

                  loop_ub = b_num.size(0);
                  d_num.set_size(&ln_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_num[i + b_num.size(0)];
                  }

                  b_st.site = &op_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, x);
                  loop_ub = b_denom.size(0);
                  c_num.set_size(&mn_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_denom[i];
                  }

                  loop_ub = b_denom.size(0);
                  d_num.set_size(&nn_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_denom[i + b_denom.size(0)];
                  }

                  b_st.site = &op_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, b_y);
                  b_st.site = &th_emlrtRSI;
                  c_st.site = &uh_emlrtRSI;
                  if (x.size(0) != b_y.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                      "MATLAB:dimagree", "MATLAB:dimagree", 0);
                  }

                  loop_ub = x.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    x[i] = x[i] / b_y[i];
                  }

                  st.site = &op_emlrtRSI;
                  b_st.site = &td_emlrtRSI;
                  c_st.site = &ud_emlrtRSI;
                  d_st.site = &vd_emlrtRSI;
                  if (x.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &wd_emlrtRSI;
                  f_st.site = &xd_emlrtRSI;
                  last = x.size(0);
                  if (x.size(0) <= 2) {
                    if (x.size(0) == 1) {
                      ex = x[0];
                    } else if ((x[0] < x[1]) || (muDoubleScalarIsNaN(x[0]) &&
                                (!muDoubleScalarIsNaN(x[1])))) {
                      ex = x[1];
                    } else {
                      ex = x[0];
                    }
                  } else {
                    g_st.site = &ae_emlrtRSI;
                    if (!muDoubleScalarIsNaN(x[0])) {
                      idx = 1;
                    } else {
                      boolean_T exitg1;
                      idx = 0;
                      h_st.site = &be_emlrtRSI;
                      if (x.size(0) > 2147483646) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      loop_ub = 2;
                      exitg1 = false;
                      while ((!exitg1) && (loop_ub <= last)) {
                        if (!muDoubleScalarIsNaN(x[loop_ub - 1])) {
                          idx = loop_ub;
                          exitg1 = true;
                        } else {
                          loop_ub++;
                        }
                      }
                    }

                    if (idx == 0) {
                      ex = x[0];
                    } else {
                      g_st.site = &yd_emlrtRSI;
                      ex = x[idx - 1];
                      a = idx + 1;
                      h_st.site = &ce_emlrtRSI;
                      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      for (loop_ub = a; loop_ub <= last; loop_ub++) {
                        y = x[loop_ub - 1];
                        if (ex < y) {
                          ex = y;
                        }
                      }
                    }
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  i = b_num.size(0) * b_num.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &rn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_num.size(0) * b_num.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &qn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &pn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &on_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (muDoubleScalarHypot(b_num[0], b_num[1]) /
                     muDoubleScalarHypot(b_denom[0], b_denom[1])));
                }
              }

              i = BoardIdx.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &nn_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(0);
              b_this.set_size(&on_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[i] > 0.0);
              }

              st.site = &pp_emlrtRSI;
              Checkerboard::arrayFind(&st, b_this, validNewColIdx);
              if (validNewColIdx.size(1) != 0) {
                i = validNewColIdx.size(1);
                for (b_i = 0; b_i < i; b_i++) {
                  if (b_i + 1 > validNewColIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validNewColIdx.size(1), &mn_emlrtBCI, (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &kn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  last = static_cast<int32_T>(validNewColIdx[b_i]);
                  if ((last < 1) || (last > i1)) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i1, &ln_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  num.set_size(&pn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    num[i1] = BoardCoords[(last + BoardCoords.size(0) *
                      BoardCoords.size(1) * i1) - 1];
                  }

                  i1 = BoardCoords.size(1);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &in_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  idx = static_cast<int32_T>(validNewColIdx[b_i] + 2.0);
                  if ((idx < 1) || (idx > i1)) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &jn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r7.set_size(&qn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    r7[i1] = BoardCoords[(idx + BoardCoords.size(0) *
                                          BoardCoords.size(1) * i1) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])num.size())[0];
                  iv[1] = (*(int32_T (*)[3])num.size())[1];
                  iv[2] = (*(int32_T (*)[3])num.size())[2];
                  iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                  iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                  iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pc_emlrtECI,
                    (emlrtCTX)sp);
                  i1 = BoardCoords.size(1);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &gn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  a = static_cast<int32_T>(validNewColIdx[b_i] + 1.0);
                  if ((a < 1) || (a > i1)) {
                    emlrtDynamicBoundsCheckR2012b(a, 1, i1, &hn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&rn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    denom[i1] = 2.0 * BoardCoords[(a + BoardCoords.size(0) *
                      BoardCoords.size(1) * i1) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])num.size())[0];
                  iv[1] = (*(int32_T (*)[3])num.size())[1];
                  iv[2] = (*(int32_T (*)[3])num.size())[2];
                  iv1[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv1[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv1[2] = (*(int32_T (*)[3])denom.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pc_emlrtECI,
                    (emlrtCTX)sp);
                  num.set_size(&sn_emlrtRTEI, sp, 1, 1, num.size(2));
                  loop_ub = num.size(2) - 1;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    num[i1] = (num[i1] + r7[i1]) - denom[i1];
                  }

                  i1 = BoardCoords.size(1);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &en_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  if (last > i1) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i1, &fn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&tn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    denom[i1] = BoardCoords[(last + BoardCoords.size(0) *
                      BoardCoords.size(1) * i1) - 1];
                  }

                  i1 = BoardCoords.size(1);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &cn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  if (idx > i1) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &dn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r7.set_size(&un_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    r7[i1] = BoardCoords[(idx + BoardCoords.size(0) *
                                          BoardCoords.size(1) * i1) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv[2] = (*(int32_T (*)[3])denom.size())[2];
                  iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                  iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                  iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &oc_emlrtECI,
                    (emlrtCTX)sp);
                  denom.set_size(&vn_emlrtRTEI, sp, 1, 1, denom.size(2));
                  loop_ub = denom.size(2) - 1;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    denom[i1] = denom[i1] - r7[i1];
                  }

                  st.site = &qp_emlrtRSI;
                  if (muSingleScalarIsNaN(newEnergy)) {
                    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                      "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                  }

                  if (newEnergy != 0.0F) {
                    x.set_size(&yn_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = num[i1];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&ao_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = denom[i1];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(newEnergy,
                      static_cast<real32_T>(ex / y));
                  } else {
                    x.set_size(&wn_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = num[i1];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&xn_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = denom[i1];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(oldEnergy,
                      static_cast<real32_T>(ex / y));
                  }
                }
              }

              st.site = &rp_emlrtRSI;
              if (muSingleScalarIsNaN(newEnergy)) {
                emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                  "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
              }

              if (newEnergy != 0.0F) {
                newEnergy = newEnergy * static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1)) - static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1));
              } else {
                newEnergy = rtInfF;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return newEnergy;
            }

            real32_T Checkerboard::computeNewEnergyHorizontal(const emlrtStack
              *sp, const ::coder::array<real_T, 2U> &idx, real32_T oldEnergy)
              const
            {
              ptrdiff_t incx_t;
              ptrdiff_t n_t;
              ::coder::array<real_T, 3U> denom;
              ::coder::array<real_T, 3U> num;
              ::coder::array<real_T, 3U> r10;
              ::coder::array<real_T, 3U> r4;
              ::coder::array<real_T, 3U> r6;
              ::coder::array<real_T, 3U> r7;
              ::coder::array<real_T, 3U> r9;
              ::coder::array<real_T, 2U> b_denom;
              ::coder::array<real_T, 2U> b_num;
              ::coder::array<real_T, 2U> validNewColIdx;
              ::coder::array<real_T, 1U> b_y;
              ::coder::array<real_T, 1U> c_num;
              ::coder::array<real_T, 1U> d_num;
              ::coder::array<real_T, 1U> x;
              ::coder::array<int32_T, 1U> r11;
              ::coder::array<int32_T, 1U> r12;
              ::coder::array<int32_T, 1U> r3;
              ::coder::array<int32_T, 1U> r5;
              ::coder::array<int32_T, 1U> r8;
              ::coder::array<boolean_T, 2U> b_this;
              ::coder::array<boolean_T, 1U> r;
              ::coder::array<boolean_T, 1U> r1;
              ::coder::array<boolean_T, 1U> r2;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack i_st;
              emlrtStack st;
              real_T ex;
              real_T y;
              int32_T iv[3];
              int32_T iv1[3];
              int32_T b_i;
              int32_T b_idx;
              int32_T b_loop_ub;
              int32_T c_idx;
              int32_T d_idx;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T i3;
              int32_T last;
              int32_T loop_ub;
              real32_T newEnergy;
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
              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &qp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(1);
              i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &cd_emlrtDCI, (emlrtCTX)sp);
              }

              b_idx = static_cast<int32_T>(idx[0]);
              if ((b_idx < 1) || (b_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &co_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0);
              r.set_size(&bn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[i + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &pp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(1);
              i2 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
              if (idx[1] != i2) {
                emlrtIntegerCheckR2012b(idx[1], &bd_emlrtDCI, (emlrtCTX)sp);
              }

              c_idx = static_cast<int32_T>(idx[1]);
              if ((c_idx < 1) || (c_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &bo_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&cn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[i + BoardIdx.size(0) * (c_idx - 1)] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &sc_emlrtECI,
                  (emlrtCTX)sp);
              }

              loop_ub = r.size(0);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (r[i] && r1[i]);
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &op_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(1);
              i3 = static_cast<int32_T>(muDoubleScalarFloor(idx[2]));
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &ad_emlrtDCI, (emlrtCTX)sp);
              }

              d_idx = static_cast<int32_T>(idx[2]);
              if ((d_idx < 1) || (d_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &ao_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0);
              r1.set_size(&dn_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[i + BoardIdx.size(0) * (d_idx - 1)] > 0.0);
              }

              if (r.size(0) != r1.size(0)) {
                emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &sc_emlrtECI,
                  (emlrtCTX)sp);
              }

              newEnergy = 0.0F;
              r2.set_size(&bn_emlrtRTEI, sp, r.size(0));
              loop_ub = r.size(0);
              for (i = 0; i < loop_ub; i++) {
                r2[i] = (r[i] && r1[i]);
              }

              st.site = &lp_emlrtRSI;
              if (any(&st, r2)) {
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &np_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r3.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r3[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                i = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &yc_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &yn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r4.set_size(&fn_emlrtRTEI, sp, r3.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r3.size(0);
                  for (end = 0; end < b_loop_ub; end++) {
                    if (r3[end] > last) {
                      emlrtDynamicBoundsCheckR2012b(r3[end], 1, last,
                        &do_emlrtBCI, (emlrtCTX)sp);
                    }

                    r4[end + r4.size(0) * i] = BoardCoords[((r3[end] +
                      BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                if (3 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &mp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r5.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r5[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                i = BoardCoords.size(1);
                if (idx[2] != i3) {
                  emlrtIntegerCheckR2012b(idx[2], &xc_emlrtDCI, (emlrtCTX)sp);
                }

                if (d_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &xn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r6.set_size(&gn_emlrtRTEI, sp, r5.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r5.size(0);
                  for (end = 0; end < b_loop_ub; end++) {
                    if (r5[end] > last) {
                      emlrtDynamicBoundsCheckR2012b(r5[end], 1, last,
                        &eo_emlrtBCI, (emlrtCTX)sp);
                    }

                    r6[end + r6.size(0) * i] = BoardCoords[((r5[end] +
                      BoardCoords.size(0) * (d_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r6.size())[0];
                iv1[1] = (*(int32_T (*)[3])r6.size())[1];
                iv1[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rc_emlrtECI,
                  (emlrtCTX)sp);
                if (2 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &lp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r8.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r8[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                loop_ub = r8.size(0);
                for (i = 0; i < loop_ub; i++) {
                  if (r8[i] > last) {
                    emlrtDynamicBoundsCheckR2012b(r8[i], 1, last, &fo_emlrtBCI,
                      (emlrtCTX)sp);
                  }
                }

                i = BoardCoords.size(1);
                if (idx[1] != i2) {
                  emlrtIntegerCheckR2012b(idx[1], &wc_emlrtDCI, (emlrtCTX)sp);
                }

                if (c_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &wn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r9.set_size(&hn_emlrtRTEI, sp, r8.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r8.size(0);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    r9[i2 + r9.size(0) * i] = 2.0 * BoardCoords[((r8[i2] +
                      BoardCoords.size(0) * (c_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r9.size())[0];
                iv1[1] = (*(int32_T (*)[3])r9.size())[1];
                iv1[2] = (*(int32_T (*)[3])r9.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &rc_emlrtECI,
                  (emlrtCTX)sp);
                r10.set_size(&fn_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
                loop_ub = r4.size(0) * r4.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r10[i] = (r4[i] + r6[i]) - r9[i];
                }

                st.site = &mp_emlrtRSI;
                b_squeeze(&st, r10, b_num);
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &kp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r11.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r11[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                i = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &vc_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &vn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r4.set_size(&in_emlrtRTEI, sp, r11.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r11.size(0);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    if (r11[i2] > last) {
                      emlrtDynamicBoundsCheckR2012b(r11[i2], 1, last,
                        &go_emlrtBCI, (emlrtCTX)sp);
                    }

                    r4[i2 + r4.size(0) * i] = BoardCoords[((r11[i2] +
                      BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                if (3 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &jp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = r.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    last++;
                  }
                }

                r12.set_size(&en_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (r[b_i] && r1[b_i]) {
                    r12[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(0);
                i = BoardCoords.size(1);
                if (idx[2] != i3) {
                  emlrtIntegerCheckR2012b(idx[2], &uc_emlrtDCI, (emlrtCTX)sp);
                }

                if (d_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &un_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r6.set_size(&jn_emlrtRTEI, sp, r12.size(0), 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r12.size(0);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    if (r12[i2] > last) {
                      emlrtDynamicBoundsCheckR2012b(r12[i2], 1, last,
                        &ho_emlrtBCI, (emlrtCTX)sp);
                    }

                    r6[i2 + r6.size(0) * i] = BoardCoords[((r12[i2] +
                      BoardCoords.size(0) * (d_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                iv[0] = (*(int32_T (*)[3])r4.size())[0];
                iv[1] = (*(int32_T (*)[3])r4.size())[1];
                iv[2] = (*(int32_T (*)[3])r4.size())[2];
                iv1[0] = (*(int32_T (*)[3])r6.size())[0];
                iv1[1] = (*(int32_T (*)[3])r6.size())[1];
                iv1[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &qc_emlrtECI,
                  (emlrtCTX)sp);
                r9.set_size(&in_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
                loop_ub = r4.size(0) * r4.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r9[i] = r4[i] - r6[i];
                }

                st.site = &np_emlrtRSI;
                b_squeeze(&st, r9, b_denom);
                if (b_num.size(1) > 1) {
                  if (1 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                      &tn_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (2 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                      &sn_emlrtBCI, (emlrtCTX)sp);
                  }

                  st.site = &op_emlrtRSI;
                  loop_ub = b_num.size(0);
                  c_num.set_size(&kn_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_num[i];
                  }

                  loop_ub = b_num.size(0);
                  d_num.set_size(&ln_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_num[i + b_num.size(0)];
                  }

                  b_st.site = &op_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, x);
                  loop_ub = b_denom.size(0);
                  c_num.set_size(&mn_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_denom[i];
                  }

                  loop_ub = b_denom.size(0);
                  d_num.set_size(&nn_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_denom[i + b_denom.size(0)];
                  }

                  b_st.site = &op_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, b_y);
                  b_st.site = &th_emlrtRSI;
                  c_st.site = &uh_emlrtRSI;
                  if (x.size(0) != b_y.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                      "MATLAB:dimagree", "MATLAB:dimagree", 0);
                  }

                  loop_ub = x.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    x[i] = x[i] / b_y[i];
                  }

                  st.site = &op_emlrtRSI;
                  b_st.site = &td_emlrtRSI;
                  c_st.site = &ud_emlrtRSI;
                  d_st.site = &vd_emlrtRSI;
                  if (x.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &wd_emlrtRSI;
                  f_st.site = &xd_emlrtRSI;
                  last = x.size(0);
                  if (x.size(0) <= 2) {
                    if (x.size(0) == 1) {
                      ex = x[0];
                    } else if ((x[0] < x[1]) || (muDoubleScalarIsNaN(x[0]) &&
                                (!muDoubleScalarIsNaN(x[1])))) {
                      ex = x[1];
                    } else {
                      ex = x[0];
                    }
                  } else {
                    g_st.site = &ae_emlrtRSI;
                    if (!muDoubleScalarIsNaN(x[0])) {
                      c_idx = 1;
                    } else {
                      boolean_T exitg1;
                      c_idx = 0;
                      h_st.site = &be_emlrtRSI;
                      if (x.size(0) > 2147483646) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      b_loop_ub = 2;
                      exitg1 = false;
                      while ((!exitg1) && (b_loop_ub <= last)) {
                        if (!muDoubleScalarIsNaN(x[b_loop_ub - 1])) {
                          c_idx = b_loop_ub;
                          exitg1 = true;
                        } else {
                          b_loop_ub++;
                        }
                      }
                    }

                    if (c_idx == 0) {
                      ex = x[0];
                    } else {
                      g_st.site = &yd_emlrtRSI;
                      ex = x[c_idx - 1];
                      end = c_idx + 1;
                      h_st.site = &ce_emlrtRSI;
                      if ((c_idx + 1 <= x.size(0)) && (x.size(0) > 2147483646))
                      {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      for (b_loop_ub = end; b_loop_ub <= last; b_loop_ub++) {
                        y = x[b_loop_ub - 1];
                        if (ex < y) {
                          ex = y;
                        }
                      }
                    }
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  i = b_num.size(0) * b_num.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &rn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_num.size(0) * b_num.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &qn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &pn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &on_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (muDoubleScalarHypot(b_num[0], b_num[1]) /
                     muDoubleScalarHypot(b_denom[0], b_denom[1])));
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &ip_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(1);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &tc_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &nn_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0);
              b_this.set_size(&on_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[i + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
              }

              st.site = &pp_emlrtRSI;
              Checkerboard::arrayFind(&st, b_this, validNewColIdx);
              if (validNewColIdx.size(1) != 0) {
                i = validNewColIdx.size(1);
                for (b_i = 0; b_i < i; b_i++) {
                  if (b_i + 1 > validNewColIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validNewColIdx.size(1), &mn_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &hp_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  last = static_cast<int32_T>(validNewColIdx[b_i]);
                  if ((last < 1) || (last > i2)) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i2, &ln_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &sc_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &kn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  num.set_size(&pn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    num[i2] = BoardCoords[((last + BoardCoords.size(0) * (b_idx
                      - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) -
                      1];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &gp_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  end = static_cast<int32_T>(validNewColIdx[b_i] + 2.0);
                  if ((end < 1) || (end > i2)) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i2, &jn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &rc_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &in_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r7.set_size(&qn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    r7[i2] = BoardCoords[((end + BoardCoords.size(0) * (b_idx -
                      1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])num.size())[0];
                  iv[1] = (*(int32_T (*)[3])num.size())[1];
                  iv[2] = (*(int32_T (*)[3])num.size())[2];
                  iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                  iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                  iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pc_emlrtECI,
                    (emlrtCTX)sp);
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &fp_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  b_loop_ub = static_cast<int32_T>(validNewColIdx[b_i] + 1.0);
                  if ((b_loop_ub < 1) || (b_loop_ub > i2)) {
                    emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i2, &hn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &qc_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &gn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&rn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    denom[i2] = 2.0 * BoardCoords[((b_loop_ub + BoardCoords.size
                      (0) * (b_idx - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i2) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])num.size())[0];
                  iv[1] = (*(int32_T (*)[3])num.size())[1];
                  iv[2] = (*(int32_T (*)[3])num.size())[2];
                  iv1[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv1[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv1[2] = (*(int32_T (*)[3])denom.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &pc_emlrtECI,
                    (emlrtCTX)sp);
                  num.set_size(&sn_emlrtRTEI, sp, 1, 1, num.size(2));
                  loop_ub = num.size(2) - 1;
                  for (i2 = 0; i2 <= loop_ub; i2++) {
                    num[i2] = (num[i2] + r7[i2]) - denom[i2];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &ep_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (last > i2) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i2, &fn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &pc_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &en_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&tn_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    denom[i2] = BoardCoords[((last + BoardCoords.size(0) *
                      (b_idx - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i2) - 1];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &dp_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (end > i2) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i2, &dn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &oc_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &cn_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r7.set_size(&un_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    r7[i2] = BoardCoords[((end + BoardCoords.size(0) * (b_idx -
                      1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                  }

                  iv[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv[2] = (*(int32_T (*)[3])denom.size())[2];
                  iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                  iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                  iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &oc_emlrtECI,
                    (emlrtCTX)sp);
                  denom.set_size(&vn_emlrtRTEI, sp, 1, 1, denom.size(2));
                  loop_ub = denom.size(2) - 1;
                  for (i2 = 0; i2 <= loop_ub; i2++) {
                    denom[i2] = denom[i2] - r7[i2];
                  }

                  st.site = &qp_emlrtRSI;
                  if (muSingleScalarIsNaN(newEnergy)) {
                    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                      "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                  }

                  if (newEnergy != 0.0F) {
                    x.set_size(&yn_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = num[i2];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&ao_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = denom[i2];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(newEnergy,
                      static_cast<real32_T>(ex / y));
                  } else {
                    x.set_size(&wn_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = num[i2];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&xn_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = denom[i2];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(oldEnergy,
                      static_cast<real32_T>(ex / y));
                  }
                }
              }

              st.site = &rp_emlrtRSI;
              if (muSingleScalarIsNaN(newEnergy)) {
                emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                  "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
              }

              if (newEnergy != 0.0F) {
                newEnergy = newEnergy * static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1)) - static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1));
              } else {
                newEnergy = rtInfF;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return newEnergy;
            }

            real32_T Checkerboard::computeNewEnergyVertical(const emlrtStack *sp,
              real32_T oldEnergy) const
            {
              ptrdiff_t incx_t;
              ptrdiff_t n_t;
              ::coder::array<real_T, 3U> b;
              ::coder::array<real_T, 3U> denom;
              ::coder::array<real_T, 3U> num;
              ::coder::array<real_T, 3U> r3;
              ::coder::array<real_T, 3U> r5;
              ::coder::array<real_T, 3U> r6;
              ::coder::array<real_T, 3U> r8;
              ::coder::array<real_T, 2U> b_denom;
              ::coder::array<real_T, 2U> b_num;
              ::coder::array<real_T, 2U> validNewRowIdx;
              ::coder::array<real_T, 1U> b_y;
              ::coder::array<real_T, 1U> c_num;
              ::coder::array<real_T, 1U> d_num;
              ::coder::array<real_T, 1U> x;
              ::coder::array<int32_T, 2U> r10;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r4;
              ::coder::array<int32_T, 2U> r7;
              ::coder::array<int32_T, 2U> r9;
              ::coder::array<boolean_T, 2U> b_this;
              ::coder::array<boolean_T, 2U> r;
              ::coder::array<boolean_T, 2U> r1;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack i_st;
              emlrtStack st;
              real_T ex;
              real_T y;
              int32_T iv2[3];
              int32_T iv3[3];
              int32_T iv[2];
              int32_T iv1[2];
              int32_T a;
              int32_T b_i;
              int32_T i;
              int32_T i1;
              int32_T idx;
              int32_T last;
              int32_T loop_ub;
              real32_T newEnergy;
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
              i = BoardIdx.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &bk_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(1);
              b_this.set_size(&gl_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
              }

              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &ak_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&hl_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[BoardIdx.size(0) * i + 1] > 0.0);
              }

              iv[0] = (*(int32_T (*)[2])b_this.size())[0];
              iv[1] = (*(int32_T (*)[2])b_this.size())[1];
              iv1[0] = (*(int32_T (*)[2])r.size())[0];
              iv1[1] = (*(int32_T (*)[2])r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &cc_emlrtECI, (emlrtCTX)
                sp);
              b_this.set_size(&gl_emlrtRTEI, sp, 1, b_this.size(1));
              loop_ub = b_this.size(1) - 1;
              for (i = 0; i <= loop_ub; i++) {
                b_this[i] = (b_this[i] && r[i]);
              }

              i = BoardIdx.size(0);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &yj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&il_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[BoardIdx.size(0) * i + 2] > 0.0);
              }

              iv[0] = (*(int32_T (*)[2])b_this.size())[0];
              iv[1] = (*(int32_T (*)[2])b_this.size())[1];
              iv1[0] = (*(int32_T (*)[2])r.size())[0];
              iv1[1] = (*(int32_T (*)[2])r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &cc_emlrtECI, (emlrtCTX)
                sp);
              newEnergy = 0.0F;
              r1.set_size(&gl_emlrtRTEI, sp, 1, b_this.size(1));
              loop_ub = b_this.size(1);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (b_this[i] && r[i]);
              }

              st.site = &vo_emlrtRSI;
              if (b_any(&st, r1)) {
                i = BoardCoords.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &xj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r2.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r2[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                loop_ub = BoardCoords.size(2);
                r3.set_size(&kl_emlrtRTEI, sp, 1, r2.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r2.size(1);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r2[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r2[i1], 1, last,
                        &ck_emlrtBCI, (emlrtCTX)sp);
                    }

                    r3[i1 + r3.size(1) * i] = BoardCoords[BoardCoords.size(0) *
                      (r2[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i];
                  }
                }

                i = BoardCoords.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &wj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r4.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r4[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                loop_ub = BoardCoords.size(2);
                r5.set_size(&ll_emlrtRTEI, sp, 1, r4.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r4.size(1);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r4[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r4[i1], 1, last,
                        &dk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r5[i1 + r5.size(1) * i] = BoardCoords[(BoardCoords.size(0) *
                      (r4[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i) + 2];
                  }
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])r5.size())[0];
                iv3[1] = (*(int32_T (*)[3])r5.size())[1];
                iv3[2] = (*(int32_T (*)[3])r5.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &bc_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardCoords.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &vj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r7.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r7[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                loop_ub = BoardCoords.size(2);
                b.set_size(&ml_emlrtRTEI, sp, 1, r7.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r7.size(1);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r7[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r7[i1], 1, last,
                        &ek_emlrtBCI, (emlrtCTX)sp);
                    }

                    b[i1 + b.size(1) * i] = BoardCoords[(BoardCoords.size(0) *
                      (r7[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i) + 1];
                  }
                }

                loop_ub = b.size(1) * b.size(2);
                b.set_size(&nl_emlrtRTEI, sp, 1, b.size(1), b.size(2));
                for (i = 0; i < loop_ub; i++) {
                  b[i] = 2.0 * b[i];
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])b.size())[0];
                iv3[1] = (*(int32_T (*)[3])b.size())[1];
                iv3[2] = (*(int32_T (*)[3])b.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &bc_emlrtECI,
                  (emlrtCTX)sp);
                r8.set_size(&kl_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
                loop_ub = r3.size(1) * r3.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r8[i] = (r3[i] + r5[i]) - b[i];
                }

                st.site = &wo_emlrtRSI;
                squeeze(&st, r8, b_num);
                i = BoardCoords.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &uj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r9.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r9[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                loop_ub = BoardCoords.size(2);
                r3.set_size(&ol_emlrtRTEI, sp, 1, r9.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r9.size(1);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r9[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r9[i1], 1, last,
                        &fk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r3[i1 + r3.size(1) * i] = BoardCoords[BoardCoords.size(0) *
                      (r9[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i];
                  }
                }

                i = BoardCoords.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &tj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                idx = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r10.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= idx; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r10[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                loop_ub = BoardCoords.size(2);
                r5.set_size(&pl_emlrtRTEI, sp, 1, r10.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  idx = r10.size(1);
                  for (i1 = 0; i1 < idx; i1++) {
                    if (r10[i1] > last) {
                      emlrtDynamicBoundsCheckR2012b(r10[i1], 1, last,
                        &gk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r5[i1 + r5.size(1) * i] = BoardCoords[(BoardCoords.size(0) *
                      (r10[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i) + 2];
                  }
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])r5.size())[0];
                iv3[1] = (*(int32_T (*)[3])r5.size())[1];
                iv3[2] = (*(int32_T (*)[3])r5.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &ac_emlrtECI,
                  (emlrtCTX)sp);
                r8.set_size(&ol_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
                loop_ub = r3.size(1) * r3.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r8[i] = r3[i] - r5[i];
                }

                st.site = &xo_emlrtRSI;
                squeeze(&st, r8, b_denom);
                if (b_num.size(1) > 1) {
                  if (1 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                      &sj_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (2 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                      &rj_emlrtBCI, (emlrtCTX)sp);
                  }

                  st.site = &yo_emlrtRSI;
                  loop_ub = b_num.size(0);
                  c_num.set_size(&ql_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_num[i];
                  }

                  loop_ub = b_num.size(0);
                  d_num.set_size(&rl_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_num[i + b_num.size(0)];
                  }

                  b_st.site = &yo_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, x);
                  loop_ub = b_denom.size(0);
                  c_num.set_size(&sl_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_denom[i];
                  }

                  loop_ub = b_denom.size(0);
                  d_num.set_size(&tl_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_denom[i + b_denom.size(0)];
                  }

                  b_st.site = &yo_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, b_y);
                  b_st.site = &th_emlrtRSI;
                  c_st.site = &uh_emlrtRSI;
                  if (x.size(0) != b_y.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                      "MATLAB:dimagree", "MATLAB:dimagree", 0);
                  }

                  loop_ub = x.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    x[i] = x[i] / b_y[i];
                  }

                  st.site = &yo_emlrtRSI;
                  b_st.site = &td_emlrtRSI;
                  c_st.site = &ud_emlrtRSI;
                  d_st.site = &vd_emlrtRSI;
                  if (x.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &wd_emlrtRSI;
                  f_st.site = &xd_emlrtRSI;
                  last = x.size(0);
                  if (x.size(0) <= 2) {
                    if (x.size(0) == 1) {
                      ex = x[0];
                    } else if ((x[0] < x[1]) || (muDoubleScalarIsNaN(x[0]) &&
                                (!muDoubleScalarIsNaN(x[1])))) {
                      ex = x[1];
                    } else {
                      ex = x[0];
                    }
                  } else {
                    g_st.site = &ae_emlrtRSI;
                    if (!muDoubleScalarIsNaN(x[0])) {
                      idx = 1;
                    } else {
                      boolean_T exitg1;
                      idx = 0;
                      h_st.site = &be_emlrtRSI;
                      if (x.size(0) > 2147483646) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      loop_ub = 2;
                      exitg1 = false;
                      while ((!exitg1) && (loop_ub <= last)) {
                        if (!muDoubleScalarIsNaN(x[loop_ub - 1])) {
                          idx = loop_ub;
                          exitg1 = true;
                        } else {
                          loop_ub++;
                        }
                      }
                    }

                    if (idx == 0) {
                      ex = x[0];
                    } else {
                      g_st.site = &yd_emlrtRSI;
                      ex = x[idx - 1];
                      a = idx + 1;
                      h_st.site = &ce_emlrtRSI;
                      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      for (loop_ub = a; loop_ub <= last; loop_ub++) {
                        y = x[loop_ub - 1];
                        if (ex < y) {
                          ex = y;
                        }
                      }
                    }
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  i = b_num.size(0) * b_num.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &qj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_num.size(0) * b_num.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &pj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &oj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &nj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (muDoubleScalarHypot(b_num[0], b_num[1]) /
                     muDoubleScalarHypot(b_denom[0], b_denom[1])));
                }
              }

              i = BoardIdx.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &mj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardIdx.size(1);
              b_this.set_size(&ul_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
              }

              st.site = &ap_emlrtRSI;
              Checkerboard::arrayFind(&st, b_this, validNewRowIdx);
              if (validNewRowIdx.size(1) != 0) {
                i = validNewRowIdx.size(1);
                for (b_i = 0; b_i < i; b_i++) {
                  if (b_i + 1 > validNewRowIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validNewRowIdx.size(1), &lj_emlrtBCI, (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(0);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &kj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  last = static_cast<int32_T>(validNewRowIdx[b_i]);
                  if ((last < 1) || (last > i1)) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i1, &jj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  num.set_size(&vl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    num[i1] = BoardCoords[BoardCoords.size(0) * (last - 1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }

                  i1 = BoardCoords.size(0);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ij_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  idx = static_cast<int32_T>(validNewRowIdx[b_i] + 2.0);
                  if ((idx < 1) || (idx > i1)) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &hj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r6.set_size(&wl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    r6[i1] = BoardCoords[BoardCoords.size(0) * (idx - 1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }

                  iv2[0] = (*(int32_T (*)[3])num.size())[0];
                  iv2[1] = (*(int32_T (*)[3])num.size())[1];
                  iv2[2] = (*(int32_T (*)[3])num.size())[2];
                  iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                  iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                  iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &yb_emlrtECI,
                    (emlrtCTX)sp);
                  i1 = BoardCoords.size(0);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &gj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  a = static_cast<int32_T>(validNewRowIdx[b_i] + 1.0);
                  if ((a < 1) || (a > i1)) {
                    emlrtDynamicBoundsCheckR2012b(a, 1, i1, &fj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&xl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    denom[i1] = 2.0 * BoardCoords[BoardCoords.size(0) * (a - 1)
                      + BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }

                  iv2[0] = (*(int32_T (*)[3])num.size())[0];
                  iv2[1] = (*(int32_T (*)[3])num.size())[1];
                  iv2[2] = (*(int32_T (*)[3])num.size())[2];
                  iv3[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv3[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv3[2] = (*(int32_T (*)[3])denom.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &yb_emlrtECI,
                    (emlrtCTX)sp);
                  num.set_size(&yl_emlrtRTEI, sp, 1, 1, num.size(2));
                  loop_ub = num.size(2) - 1;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    num[i1] = (num[i1] + r6[i1]) - denom[i1];
                  }

                  i1 = BoardCoords.size(0);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ej_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if (last > i1) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i1, &dj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&am_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    denom[i1] = BoardCoords[BoardCoords.size(0) * (last - 1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }

                  i1 = BoardCoords.size(0);
                  if (1 > i1) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i1, &cj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if (idx > i1) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, i1, &bj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r6.set_size(&bm_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    r6[i1] = BoardCoords[BoardCoords.size(0) * (idx - 1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }

                  iv2[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv2[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv2[2] = (*(int32_T (*)[3])denom.size())[2];
                  iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                  iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                  iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI,
                    (emlrtCTX)sp);
                  denom.set_size(&cm_emlrtRTEI, sp, 1, 1, denom.size(2));
                  loop_ub = denom.size(2) - 1;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    denom[i1] = denom[i1] - r6[i1];
                  }

                  st.site = &bp_emlrtRSI;
                  if (muSingleScalarIsNaN(newEnergy)) {
                    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                      "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                  }

                  if (newEnergy != 0.0F) {
                    x.set_size(&fm_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = num[i1];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&gm_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = denom[i1];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(newEnergy,
                      static_cast<real32_T>(ex / y));
                  } else {
                    x.set_size(&dm_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = num[i1];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&em_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      x[i1] = denom[i1];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(oldEnergy,
                      static_cast<real32_T>(ex / y));
                  }
                }
              }

              st.site = &cp_emlrtRSI;
              if (muSingleScalarIsNaN(newEnergy)) {
                emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                  "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
              }

              if (newEnergy != 0.0F) {
                newEnergy = newEnergy * static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1)) - static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1));
              } else {
                newEnergy = rtInfF;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return newEnergy;
            }

            real32_T Checkerboard::computeNewEnergyVertical(const emlrtStack *sp,
              const ::coder::array<real_T, 2U> &idx, real32_T oldEnergy) const
            {
              ptrdiff_t incx_t;
              ptrdiff_t n_t;
              ::coder::array<real_T, 3U> b;
              ::coder::array<real_T, 3U> denom;
              ::coder::array<real_T, 3U> num;
              ::coder::array<real_T, 3U> r3;
              ::coder::array<real_T, 3U> r5;
              ::coder::array<real_T, 3U> r6;
              ::coder::array<real_T, 3U> r8;
              ::coder::array<real_T, 2U> b_denom;
              ::coder::array<real_T, 2U> b_num;
              ::coder::array<real_T, 2U> validNewRowIdx;
              ::coder::array<real_T, 1U> b_y;
              ::coder::array<real_T, 1U> c_num;
              ::coder::array<real_T, 1U> d_num;
              ::coder::array<real_T, 1U> x;
              ::coder::array<int32_T, 2U> r10;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r4;
              ::coder::array<int32_T, 2U> r7;
              ::coder::array<int32_T, 2U> r9;
              ::coder::array<boolean_T, 2U> b_this;
              ::coder::array<boolean_T, 2U> r;
              ::coder::array<boolean_T, 2U> r1;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack i_st;
              emlrtStack st;
              real_T ex;
              real_T y;
              int32_T iv2[3];
              int32_T iv3[3];
              int32_T iv[2];
              int32_T iv1[2];
              int32_T b_i;
              int32_T b_idx;
              int32_T b_loop_ub;
              int32_T c_idx;
              int32_T d_idx;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T i3;
              int32_T last;
              int32_T loop_ub;
              real32_T newEnergy;
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
              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &rl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0);
              i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &yb_emlrtDCI, (emlrtCTX)sp);
              }

              b_idx = static_cast<int32_T>(idx[0]);
              if ((b_idx < 1) || (b_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &bk_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(1);
              b_this.set_size(&gl_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[(b_idx + BoardIdx.size(0) * i) - 1] > 0.0);
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ql_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0);
              i2 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
              if (idx[1] != i2) {
                emlrtIntegerCheckR2012b(idx[1], &xb_emlrtDCI, (emlrtCTX)sp);
              }

              c_idx = static_cast<int32_T>(idx[1]);
              if ((c_idx < 1) || (c_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &ak_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&hl_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[(c_idx + BoardIdx.size(0) * i) - 1] > 0.0);
              }

              iv[0] = (*(int32_T (*)[2])b_this.size())[0];
              iv[1] = (*(int32_T (*)[2])b_this.size())[1];
              iv1[0] = (*(int32_T (*)[2])r.size())[0];
              iv1[1] = (*(int32_T (*)[2])r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &cc_emlrtECI, (emlrtCTX)
                sp);
              b_this.set_size(&gl_emlrtRTEI, sp, 1, b_this.size(1));
              loop_ub = b_this.size(1) - 1;
              for (i = 0; i <= loop_ub; i++) {
                b_this[i] = (b_this[i] && r[i]);
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &pl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0);
              i3 = static_cast<int32_T>(muDoubleScalarFloor(idx[2]));
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &wb_emlrtDCI, (emlrtCTX)sp);
              }

              d_idx = static_cast<int32_T>(idx[2]);
              if ((d_idx < 1) || (d_idx > i)) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &yj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&il_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[(d_idx + BoardIdx.size(0) * i) - 1] > 0.0);
              }

              iv[0] = (*(int32_T (*)[2])b_this.size())[0];
              iv[1] = (*(int32_T (*)[2])b_this.size())[1];
              iv1[0] = (*(int32_T (*)[2])r.size())[0];
              iv1[1] = (*(int32_T (*)[2])r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &cc_emlrtECI, (emlrtCTX)
                sp);
              newEnergy = 0.0F;
              r1.set_size(&gl_emlrtRTEI, sp, 1, b_this.size(1));
              loop_ub = b_this.size(1);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (b_this[i] && r[i]);
              }

              st.site = &vo_emlrtRSI;
              if (b_any(&st, r1)) {
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &ol_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r2.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r2[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                i = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &vb_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &xj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r3.set_size(&kl_emlrtRTEI, sp, 1, r2.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r2.size(1);
                  for (end = 0; end < b_loop_ub; end++) {
                    if (r2[end] > last) {
                      emlrtDynamicBoundsCheckR2012b(r2[end], 1, last,
                        &ck_emlrtBCI, (emlrtCTX)sp);
                    }

                    r3[end + r3.size(1) * i] = BoardCoords[((b_idx +
                      BoardCoords.size(0) * (r2[end] - 1)) + BoardCoords.size(0)
                      * BoardCoords.size(1) * i) - 1];
                  }
                }

                if (3 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &nl_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r4.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r4[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                i = BoardCoords.size(0);
                if (idx[2] != i3) {
                  emlrtIntegerCheckR2012b(idx[2], &ub_emlrtDCI, (emlrtCTX)sp);
                }

                if (d_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &wj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r5.set_size(&ll_emlrtRTEI, sp, 1, r4.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r4.size(1);
                  for (end = 0; end < b_loop_ub; end++) {
                    if (r4[end] > last) {
                      emlrtDynamicBoundsCheckR2012b(r4[end], 1, last,
                        &dk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r5[end + r5.size(1) * i] = BoardCoords[((d_idx +
                      BoardCoords.size(0) * (r4[end] - 1)) + BoardCoords.size(0)
                      * BoardCoords.size(1) * i) - 1];
                  }
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])r5.size())[0];
                iv3[1] = (*(int32_T (*)[3])r5.size())[1];
                iv3[2] = (*(int32_T (*)[3])r5.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &bc_emlrtECI,
                  (emlrtCTX)sp);
                if (2 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ml_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r7.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r7[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                i = BoardCoords.size(0);
                if (idx[1] != i2) {
                  emlrtIntegerCheckR2012b(idx[1], &tb_emlrtDCI, (emlrtCTX)sp);
                }

                if (c_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &vj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                b.set_size(&ml_emlrtRTEI, sp, 1, r7.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r7.size(1);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    if (r7[i2] > last) {
                      emlrtDynamicBoundsCheckR2012b(r7[i2], 1, last,
                        &ek_emlrtBCI, (emlrtCTX)sp);
                    }

                    b[i2 + b.size(1) * i] = BoardCoords[((c_idx +
                      BoardCoords.size(0) * (r7[i2] - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                loop_ub = b.size(1) * b.size(2);
                b.set_size(&nl_emlrtRTEI, sp, 1, b.size(1), b.size(2));
                for (i = 0; i < loop_ub; i++) {
                  b[i] = 2.0 * b[i];
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])b.size())[0];
                iv3[1] = (*(int32_T (*)[3])b.size())[1];
                iv3[2] = (*(int32_T (*)[3])b.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &bc_emlrtECI,
                  (emlrtCTX)sp);
                r8.set_size(&kl_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
                loop_ub = r3.size(1) * r3.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r8[i] = (r3[i] + r5[i]) - b[i];
                }

                st.site = &wo_emlrtRSI;
                squeeze(&st, r8, b_num);
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &ll_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r9.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r9[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                i = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &sb_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &uj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r3.set_size(&ol_emlrtRTEI, sp, 1, r9.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r9.size(1);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    if (r9[i2] > last) {
                      emlrtDynamicBoundsCheckR2012b(r9[i2], 1, last,
                        &fk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r3[i2 + r3.size(1) * i] = BoardCoords[((b_idx +
                      BoardCoords.size(0) * (r9[i2] - 1)) + BoardCoords.size(0) *
                      BoardCoords.size(1) * i) - 1];
                  }
                }

                if (3 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &kl_emlrtBCI,
                    (emlrtCTX)sp);
                }

                end = b_this.size(1) - 1;
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    last++;
                  }
                }

                r10.set_size(&jl_emlrtRTEI, sp, 1, last);
                last = 0;
                for (b_i = 0; b_i <= end; b_i++) {
                  if (b_this[b_i] && r[b_i]) {
                    r10[last] = b_i + 1;
                    last++;
                  }
                }

                last = BoardCoords.size(1);
                i = BoardCoords.size(0);
                if (idx[2] != i3) {
                  emlrtIntegerCheckR2012b(idx[2], &rb_emlrtDCI, (emlrtCTX)sp);
                }

                if (d_idx > i) {
                  emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &tj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r5.set_size(&pl_emlrtRTEI, sp, 1, r10.size(1), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r10.size(1);
                  for (i2 = 0; i2 < b_loop_ub; i2++) {
                    if (r10[i2] > last) {
                      emlrtDynamicBoundsCheckR2012b(r10[i2], 1, last,
                        &gk_emlrtBCI, (emlrtCTX)sp);
                    }

                    r5[i2 + r5.size(1) * i] = BoardCoords[((d_idx +
                      BoardCoords.size(0) * (r10[i2] - 1)) + BoardCoords.size(0)
                      * BoardCoords.size(1) * i) - 1];
                  }
                }

                iv2[0] = (*(int32_T (*)[3])r3.size())[0];
                iv2[1] = (*(int32_T (*)[3])r3.size())[1];
                iv2[2] = (*(int32_T (*)[3])r3.size())[2];
                iv3[0] = (*(int32_T (*)[3])r5.size())[0];
                iv3[1] = (*(int32_T (*)[3])r5.size())[1];
                iv3[2] = (*(int32_T (*)[3])r5.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &ac_emlrtECI,
                  (emlrtCTX)sp);
                r8.set_size(&ol_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
                loop_ub = r3.size(1) * r3.size(2);
                for (i = 0; i < loop_ub; i++) {
                  r8[i] = r3[i] - r5[i];
                }

                st.site = &xo_emlrtRSI;
                squeeze(&st, r8, b_denom);
                if (b_num.size(1) > 1) {
                  if (1 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                      &sj_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (2 > b_denom.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                      &rj_emlrtBCI, (emlrtCTX)sp);
                  }

                  st.site = &yo_emlrtRSI;
                  loop_ub = b_num.size(0);
                  c_num.set_size(&ql_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_num[i];
                  }

                  loop_ub = b_num.size(0);
                  d_num.set_size(&rl_emlrtRTEI, &st, b_num.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_num[i + b_num.size(0)];
                  }

                  b_st.site = &yo_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, x);
                  loop_ub = b_denom.size(0);
                  c_num.set_size(&sl_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    c_num[i] = b_denom[i];
                  }

                  loop_ub = b_denom.size(0);
                  d_num.set_size(&tl_emlrtRTEI, &st, b_denom.size(0));
                  for (i = 0; i < loop_ub; i++) {
                    d_num[i] = b_denom[i + b_denom.size(0)];
                  }

                  b_st.site = &yo_emlrtRSI;
                  b_hypot(&b_st, c_num, d_num, b_y);
                  b_st.site = &th_emlrtRSI;
                  c_st.site = &uh_emlrtRSI;
                  if (x.size(0) != b_y.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                      "MATLAB:dimagree", "MATLAB:dimagree", 0);
                  }

                  loop_ub = x.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    x[i] = x[i] / b_y[i];
                  }

                  st.site = &yo_emlrtRSI;
                  b_st.site = &td_emlrtRSI;
                  c_st.site = &ud_emlrtRSI;
                  d_st.site = &vd_emlrtRSI;
                  if (x.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &wd_emlrtRSI;
                  f_st.site = &xd_emlrtRSI;
                  last = x.size(0);
                  if (x.size(0) <= 2) {
                    if (x.size(0) == 1) {
                      ex = x[0];
                    } else if ((x[0] < x[1]) || (muDoubleScalarIsNaN(x[0]) &&
                                (!muDoubleScalarIsNaN(x[1])))) {
                      ex = x[1];
                    } else {
                      ex = x[0];
                    }
                  } else {
                    g_st.site = &ae_emlrtRSI;
                    if (!muDoubleScalarIsNaN(x[0])) {
                      c_idx = 1;
                    } else {
                      boolean_T exitg1;
                      c_idx = 0;
                      h_st.site = &be_emlrtRSI;
                      if (x.size(0) > 2147483646) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      b_loop_ub = 2;
                      exitg1 = false;
                      while ((!exitg1) && (b_loop_ub <= last)) {
                        if (!muDoubleScalarIsNaN(x[b_loop_ub - 1])) {
                          c_idx = b_loop_ub;
                          exitg1 = true;
                        } else {
                          b_loop_ub++;
                        }
                      }
                    }

                    if (c_idx == 0) {
                      ex = x[0];
                    } else {
                      g_st.site = &yd_emlrtRSI;
                      ex = x[c_idx - 1];
                      end = c_idx + 1;
                      h_st.site = &ce_emlrtRSI;
                      if ((c_idx + 1 <= x.size(0)) && (x.size(0) > 2147483646))
                      {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      for (b_loop_ub = end; b_loop_ub <= last; b_loop_ub++) {
                        y = x[b_loop_ub - 1];
                        if (ex < y) {
                          ex = y;
                        }
                      }
                    }
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  i = b_num.size(0) * b_num.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &qj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_num.size(0) * b_num.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &pj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &oj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = b_denom.size(0) * b_denom.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &nj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (muDoubleScalarHypot(b_num[0], b_num[1]) /
                     muDoubleScalarHypot(b_denom[0], b_denom[1])));
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &jl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &qb_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &mj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(1);
              b_this.set_size(&ul_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_this[i] = (BoardIdx[(b_idx + BoardIdx.size(0) * i) - 1] > 0.0);
              }

              st.site = &ap_emlrtRSI;
              Checkerboard::arrayFind(&st, b_this, validNewRowIdx);
              if (validNewRowIdx.size(1) != 0) {
                i = validNewRowIdx.size(1);
                for (b_i = 0; b_i < i; b_i++) {
                  if (b_i + 1 > validNewRowIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validNewRowIdx.size(1), &lj_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &il_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &pb_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &kj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  last = static_cast<int32_T>(validNewRowIdx[b_i]);
                  if ((last < 1) || (last > i2)) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i2, &jj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  num.set_size(&vl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    num[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (last
                      - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) -
                      1];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &hl_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &ob_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &ij_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  end = static_cast<int32_T>(validNewRowIdx[b_i] + 2.0);
                  if ((end < 1) || (end > i2)) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i2, &hj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r6.set_size(&wl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    r6[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (end -
                      1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                  }

                  iv2[0] = (*(int32_T (*)[3])num.size())[0];
                  iv2[1] = (*(int32_T (*)[3])num.size())[1];
                  iv2[2] = (*(int32_T (*)[3])num.size())[2];
                  iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                  iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                  iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &yb_emlrtECI,
                    (emlrtCTX)sp);
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &gl_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &nb_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &gj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  b_loop_ub = static_cast<int32_T>(validNewRowIdx[b_i] + 1.0);
                  if ((b_loop_ub < 1) || (b_loop_ub > i2)) {
                    emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i2, &fj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&xl_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    denom[i2] = 2.0 * BoardCoords[((b_idx + BoardCoords.size(0) *
                      (b_loop_ub - 1)) + BoardCoords.size(0) * BoardCoords.size
                      (1) * i2) - 1];
                  }

                  iv2[0] = (*(int32_T (*)[3])num.size())[0];
                  iv2[1] = (*(int32_T (*)[3])num.size())[1];
                  iv2[2] = (*(int32_T (*)[3])num.size())[2];
                  iv3[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv3[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv3[2] = (*(int32_T (*)[3])denom.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &yb_emlrtECI,
                    (emlrtCTX)sp);
                  num.set_size(&yl_emlrtRTEI, sp, 1, 1, num.size(2));
                  loop_ub = num.size(2) - 1;
                  for (i2 = 0; i2 <= loop_ub; i2++) {
                    num[i2] = (num[i2] + r6[i2]) - denom[i2];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &fl_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &mb_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &ej_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (last > i2) {
                    emlrtDynamicBoundsCheckR2012b(last, 1, i2, &dj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  denom.set_size(&am_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    denom[i2] = BoardCoords[((b_idx + BoardCoords.size(0) *
                      (last - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                      i2) - 1];
                  }

                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &el_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(0);
                  if (idx[0] != i1) {
                    emlrtIntegerCheckR2012b(idx[0], &lb_emlrtDCI, (emlrtCTX)sp);
                  }

                  if (b_idx > i2) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &cj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i2 = BoardCoords.size(1);
                  if (end > i2) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i2, &bj_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r6.set_size(&bm_emlrtRTEI, sp, 1, 1, loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    r6[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (end -
                      1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                  }

                  iv2[0] = (*(int32_T (*)[3])denom.size())[0];
                  iv2[1] = (*(int32_T (*)[3])denom.size())[1];
                  iv2[2] = (*(int32_T (*)[3])denom.size())[2];
                  iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                  iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                  iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                  emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI,
                    (emlrtCTX)sp);
                  denom.set_size(&cm_emlrtRTEI, sp, 1, 1, denom.size(2));
                  loop_ub = denom.size(2) - 1;
                  for (i2 = 0; i2 <= loop_ub; i2++) {
                    denom[i2] = denom[i2] - r6[i2];
                  }

                  st.site = &bp_emlrtRSI;
                  if (muSingleScalarIsNaN(newEnergy)) {
                    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                      "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                  }

                  if (newEnergy != 0.0F) {
                    x.set_size(&fm_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = num[i2];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&gm_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = denom[i2];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(newEnergy,
                      static_cast<real32_T>(ex / y));
                  } else {
                    x.set_size(&dm_emlrtRTEI, sp, num.size(2));
                    loop_ub = num.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = num[i2];
                    }

                    if (num.size(2) == 0) {
                      ex = 0.0;
                    } else {
                      n_t = (ptrdiff_t)num.size(2);
                      incx_t = (ptrdiff_t)1;
                      ex = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    x.set_size(&em_emlrtRTEI, sp, denom.size(2));
                    loop_ub = denom.size(2);
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      x[i2] = denom[i2];
                    }

                    if (denom.size(2) == 0) {
                      y = 0.0;
                    } else {
                      n_t = (ptrdiff_t)denom.size(2);
                      incx_t = (ptrdiff_t)1;
                      y = dnrm2(&n_t, &(x.data())[0], &incx_t);
                    }

                    newEnergy = muSingleScalarMax(oldEnergy,
                      static_cast<real32_T>(ex / y));
                  }
                }
              }

              st.site = &cp_emlrtRSI;
              if (muSingleScalarIsNaN(newEnergy)) {
                emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                  "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
              }

              if (newEnergy != 0.0F) {
                newEnergy = newEnergy * static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1)) - static_cast<real32_T>(BoardIdx.size(0) *
                  BoardIdx.size(1));
              } else {
                newEnergy = rtInfF;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return newEnergy;
            }

            void Checkerboard::expandBoardDirectionally(const emlrtStack *sp,
              real_T direction)
            {
              ::coder::array<real_T, 3U> b_this;
              ::coder::array<real_T, 3U> r;
              ::coder::array<real_T, 2U> b_p2;
              ::coder::array<real_T, 2U> idx;
              ::coder::array<real_T, 2U> newIndices;
              ::coder::array<real_T, 2U> newIndicesLinear;
              ::coder::array<real_T, 2U> p1;
              ::coder::array<real_T, 2U> p2;
              emlrtStack b_st;
              emlrtStack st;
              int32_T iv[2];
              int32_T iv1[2];
              real32_T oldEnergy;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              oldEnergy = (Energy + static_cast<real32_T>(BoardIdx.size(0) *
                BoardIdx.size(1))) / static_cast<real32_T>(BoardIdx.size(0) *
                BoardIdx.size(1));
              switch (static_cast<int32_T>(direction)) {
               case 1:
                {
                  int32_T i;
                  int32_T loop_ub;
                  if (IsDistortionHigh) {
                    st.site = &pi_emlrtRSI;
                    fitPolynomialIndices(&st, newIndices);
                    st.site = &qi_emlrtRSI;
                    if (!b_all(&st, newIndices)) {
                      int32_T b_loop_ub;
                      int32_T i1;
                      int32_T numCols;
                      st.site = &ri_emlrtRSI;
                      i = BoardCoords.size(0);
                      if (2 > i) {
                        emlrtDynamicBoundsCheckR2012b(2, 1, i, &lg_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(1);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&ci_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(1) * i] = BoardCoords
                            [(BoardCoords.size(0) * i1 + BoardCoords.size(0) *
                              BoardCoords.size(1) * i) + 1];
                        }
                      }

                      b_st.site = &yn_emlrtRSI;
                      squeeze(&b_st, b_this, p1);
                      i = BoardCoords.size(0);
                      if (1 > i) {
                        emlrtDynamicBoundsCheckR2012b(1, 1, i, &mg_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(1);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&di_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(1) * i] =
                            BoardCoords[BoardCoords.size(0) * i1 +
                            BoardCoords.size(0) * BoardCoords.size(1) * i];
                        }
                      }

                      b_st.site = &ao_emlrtRSI;
                      squeeze(&b_st, b_this, p2);
                      iv[0] = (*(int32_T (*)[2])p2.size())[0];
                      iv[1] = (*(int32_T (*)[2])p2.size())[1];
                      iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                      iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &mb_emlrtECI,
                        &st);
                      b_p2.set_size(&ei_emlrtRTEI, sp, p2.size(0), p2.size(1));
                      loop_ub = p2.size(0) * p2.size(1);
                      for (i = 0; i < loop_ub; i++) {
                        b_p2[i] = (p2[i] + p2[i]) - p1[i];
                      }

                      st.site = &si_emlrtRSI;
                      findClosestIndices(&st, b_p2, newIndicesLinear);
                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if ((newIndices[b_loop_ub] == 0.0) && (b_loop_ub + 1 >
                             newIndicesLinear.size(1))) {
                          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                            newIndicesLinear.size(1), &hg_emlrtBCI, (emlrtCTX)sp);
                        }
                      }

                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if (newIndices[b_loop_ub] == 0.0) {
                          if (b_loop_ub + 1 > newIndices.size(1)) {
                            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                              newIndices.size(1), &tg_emlrtBCI, (emlrtCTX)sp);
                          }

                          newIndices[b_loop_ub] = newIndicesLinear[b_loop_ub];
                        }
                      }
                    }
                  } else {
                    int32_T b_loop_ub;
                    int32_T i1;
                    st.site = &ti_emlrtRSI;
                    i = BoardCoords.size(0);
                    if (2 > i) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, i, &lg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&ci_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords
                          [(BoardCoords.size(0) * i1 + BoardCoords.size(0) *
                            BoardCoords.size(1) * i) + 1];
                      }
                    }

                    b_st.site = &yn_emlrtRSI;
                    squeeze(&b_st, b_this, p1);
                    i = BoardCoords.size(0);
                    if (1 > i) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, i, &mg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&di_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] =
                          BoardCoords[BoardCoords.size(0) * i1 +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &ao_emlrtRSI;
                    squeeze(&b_st, b_this, p2);
                    iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &mb_emlrtECI, &st);
                    b_p2.set_size(&ei_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &ui_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndices);
                  }

                  st.site = &vi_emlrtRSI;
                  expandBoardUp(&st, newIndices, p1, r);
                  BoardIdx.set_size(&fi_emlrtRTEI, sp, p1.size(0), p1.size(1));
                  loop_ub = p1.size(0) * p1.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    BoardIdx[i] = p1[i];
                  }

                  BoardCoords.set_size(&gi_emlrtRTEI, sp, r.size(0), r.size(1),
                                       r.size(2));
                  loop_ub = r.size(0) * r.size(1) * r.size(2);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[i] = r[i];
                  }

                  st.site = &wi_emlrtRSI;
                  oldEnergy = computeNewEnergyVertical(&st, oldEnergy);
                }
                break;

               case 2:
                {
                  int32_T i;
                  int32_T loop_ub;
                  int32_T numCols;
                  numCols = BoardCoords.size(0);
                  st.site = &xi_emlrtRSI;
                  if (numCols < static_cast<real_T>(numCols) - 2.0) {
                    idx.set_size(&hi_emlrtRTEI, &st, 1, 0);
                  } else {
                    loop_ub = static_cast<int32_T>(-((static_cast<real_T>
                      (numCols) - 2.0) - static_cast<real_T>(numCols)));
                    idx.set_size(&hi_emlrtRTEI, &st, 1, loop_ub + 1);
                    for (i = 0; i <= loop_ub; i++) {
                      idx[i] = static_cast<real_T>(numCols) - static_cast<real_T>
                        (i);
                    }
                  }

                  if (IsDistortionHigh) {
                    st.site = &yi_emlrtRSI;
                    fitPolynomialIndices(&st, idx, newIndices);
                    st.site = &aj_emlrtRSI;
                    if (!b_all(&st, newIndices)) {
                      int32_T b_loop_ub;
                      int32_T i1;
                      st.site = &bj_emlrtRSI;
                      if (2 > idx.size(1)) {
                        emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                          &rg_emlrtBCI, &st);
                      }

                      if (idx[1] != static_cast<int32_T>(idx[1])) {
                        emlrtIntegerCheckR2012b(idx[1], &s_emlrtDCI, &st);
                      }

                      i = BoardCoords.size(0);
                      numCols = static_cast<int32_T>(idx[1]);
                      if ((numCols < 1) || (numCols > i)) {
                        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                          1, i, &lg_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(1);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&ci_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(1) * i] = BoardCoords
                            [((numCols + BoardCoords.size(0) * i1) +
                              BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                        }
                      }

                      b_st.site = &yn_emlrtRSI;
                      squeeze(&b_st, b_this, p1);
                      if (1 > idx.size(1)) {
                        emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                          &sg_emlrtBCI, &st);
                      }

                      if (idx[0] != static_cast<int32_T>(idx[0])) {
                        emlrtIntegerCheckR2012b(idx[0], &t_emlrtDCI, &st);
                      }

                      i = BoardCoords.size(0);
                      numCols = static_cast<int32_T>(idx[0]);
                      if ((numCols < 1) || (numCols > i)) {
                        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                          1, i, &mg_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(1);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&di_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(1) * i] = BoardCoords
                            [((numCols + BoardCoords.size(0) * i1) +
                              BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                        }
                      }

                      b_st.site = &ao_emlrtRSI;
                      squeeze(&b_st, b_this, p2);
                      iv[0] = (*(int32_T (*)[2])p2.size())[0];
                      iv[1] = (*(int32_T (*)[2])p2.size())[1];
                      iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                      iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &mb_emlrtECI,
                        &st);
                      b_p2.set_size(&ei_emlrtRTEI, sp, p2.size(0), p2.size(1));
                      loop_ub = p2.size(0) * p2.size(1);
                      for (i = 0; i < loop_ub; i++) {
                        b_p2[i] = (p2[i] + p2[i]) - p1[i];
                      }

                      st.site = &cj_emlrtRSI;
                      findClosestIndices(&st, b_p2, newIndicesLinear);
                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if ((newIndices[b_loop_ub] == 0.0) && (b_loop_ub + 1 >
                             newIndicesLinear.size(1))) {
                          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                            newIndicesLinear.size(1), &kg_emlrtBCI, (emlrtCTX)sp);
                        }
                      }

                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if (newIndices[b_loop_ub] == 0.0) {
                          if (b_loop_ub + 1 > newIndices.size(1)) {
                            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                              newIndices.size(1), &wg_emlrtBCI, (emlrtCTX)sp);
                          }

                          newIndices[b_loop_ub] = newIndicesLinear[b_loop_ub];
                        }
                      }
                    }
                  } else {
                    int32_T b_loop_ub;
                    int32_T i1;
                    st.site = &dj_emlrtRSI;
                    if (2 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                        &rg_emlrtBCI, &st);
                    }

                    numCols = static_cast<int32_T>(idx[1]);
                    if (idx[1] != numCols) {
                      emlrtIntegerCheckR2012b(idx[1], &s_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(0);
                    if ((numCols < 1) || (numCols > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                        1, i, &lg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&ci_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords[((numCols
                          + BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i) - 1];
                      }
                    }

                    b_st.site = &yn_emlrtRSI;
                    squeeze(&b_st, b_this, p1);
                    if (1 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                        &sg_emlrtBCI, &st);
                    }

                    numCols = static_cast<int32_T>(idx[0]);
                    if (idx[0] != numCols) {
                      emlrtIntegerCheckR2012b(idx[0], &t_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(0);
                    if ((numCols < 1) || (numCols > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                        1, i, &mg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&di_emlrtRTEI, &st, 1, loop_ub, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords[((numCols
                          + BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i) - 1];
                      }
                    }

                    b_st.site = &ao_emlrtRSI;
                    squeeze(&b_st, b_this, p2);
                    iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &mb_emlrtECI, &st);
                    b_p2.set_size(&ei_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &ej_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndices);
                  }

                  st.site = &fj_emlrtRSI;
                  expandBoardDown(&st, newIndices, p1, r);
                  BoardIdx.set_size(&ii_emlrtRTEI, sp, p1.size(0), p1.size(1));
                  loop_ub = p1.size(0) * p1.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    BoardIdx[i] = p1[i];
                  }

                  BoardCoords.set_size(&ji_emlrtRTEI, sp, r.size(0), r.size(1),
                                       r.size(2));
                  loop_ub = r.size(0) * r.size(1) * r.size(2);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[i] = r[i];
                  }

                  idx.set_size(&ki_emlrtRTEI, sp, 1, idx.size(1));
                  loop_ub = idx.size(1) - 1;
                  for (i = 0; i <= loop_ub; i++) {
                    idx[i] = idx[i] + 1.0;
                  }

                  st.site = &gj_emlrtRSI;
                  oldEnergy = computeNewEnergyVertical(&st, idx, oldEnergy);
                }
                break;

               case 3:
                {
                  int32_T i;
                  int32_T loop_ub;
                  if (IsDistortionHigh) {
                    st.site = &hj_emlrtRSI;
                    b_fitPolynomialIndices(&st, newIndices);
                    st.site = &ij_emlrtRSI;
                    if (!b_all(&st, newIndices)) {
                      int32_T b_loop_ub;
                      int32_T i1;
                      int32_T numCols;
                      st.site = &jj_emlrtRSI;
                      i = BoardCoords.size(1);
                      if (2 > i) {
                        emlrtDynamicBoundsCheckR2012b(2, 1, i, &ng_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(0);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&vh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                            BoardCoords.size(0)) + BoardCoords.size(0) *
                            BoardCoords.size(1) * i];
                        }
                      }

                      b_st.site = &jp_emlrtRSI;
                      b_squeeze(&b_st, b_this, p1);
                      i = BoardCoords.size(1);
                      if (1 > i) {
                        emlrtDynamicBoundsCheckR2012b(1, 1, i, &og_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(0);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&wh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(0) * i] = BoardCoords[i1 +
                            BoardCoords.size(0) * BoardCoords.size(1) * i];
                        }
                      }

                      b_st.site = &kp_emlrtRSI;
                      b_squeeze(&b_st, b_this, p2);
                      iv[0] = (*(int32_T (*)[2])p2.size())[0];
                      iv[1] = (*(int32_T (*)[2])p2.size())[1];
                      iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                      iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &nb_emlrtECI,
                        &st);
                      b_p2.set_size(&xh_emlrtRTEI, sp, p2.size(0), p2.size(1));
                      loop_ub = p2.size(0) * p2.size(1);
                      for (i = 0; i < loop_ub; i++) {
                        b_p2[i] = (p2[i] + p2[i]) - p1[i];
                      }

                      st.site = &kj_emlrtRSI;
                      findClosestIndices(&st, b_p2, newIndicesLinear);
                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if ((newIndices[b_loop_ub] == 0.0) && (b_loop_ub + 1 >
                             newIndicesLinear.size(1))) {
                          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                            newIndicesLinear.size(1), &ig_emlrtBCI, (emlrtCTX)sp);
                        }
                      }

                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if (newIndices[b_loop_ub] == 0.0) {
                          if (b_loop_ub + 1 > newIndices.size(1)) {
                            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                              newIndices.size(1), &ug_emlrtBCI, (emlrtCTX)sp);
                          }

                          newIndices[b_loop_ub] = newIndicesLinear[b_loop_ub];
                        }
                      }
                    }
                  } else {
                    int32_T b_loop_ub;
                    int32_T i1;
                    st.site = &lj_emlrtRSI;
                    i = BoardCoords.size(1);
                    if (2 > i) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, i, &ng_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&vh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0)) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &jp_emlrtRSI;
                    b_squeeze(&b_st, b_this, p1);
                    i = BoardCoords.size(1);
                    if (1 > i) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, i, &og_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&wh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[i1 +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &kp_emlrtRSI;
                    b_squeeze(&b_st, b_this, p2);
                    iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &nb_emlrtECI, &st);
                    b_p2.set_size(&xh_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &mj_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndices);
                  }

                  st.site = &nj_emlrtRSI;
                  expandBoardLeft(&st, newIndices, p1, r);
                  BoardIdx.set_size(&li_emlrtRTEI, sp, p1.size(0), p1.size(1));
                  loop_ub = p1.size(0) * p1.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    BoardIdx[i] = p1[i];
                  }

                  BoardCoords.set_size(&mi_emlrtRTEI, sp, r.size(0), r.size(1),
                                       r.size(2));
                  loop_ub = r.size(0) * r.size(1) * r.size(2);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[i] = r[i];
                  }

                  st.site = &oj_emlrtRSI;
                  oldEnergy = computeNewEnergyHorizontal(&st, oldEnergy);
                }
                break;

               default:
                {
                  int32_T i;
                  int32_T loop_ub;
                  int32_T numCols;
                  numCols = BoardCoords.size(1);
                  st.site = &pj_emlrtRSI;
                  if (numCols < static_cast<real_T>(numCols) - 2.0) {
                    idx.set_size(&uh_emlrtRTEI, &st, 1, 0);
                  } else {
                    loop_ub = static_cast<int32_T>(-((static_cast<real_T>
                      (numCols) - 2.0) - static_cast<real_T>(numCols)));
                    idx.set_size(&uh_emlrtRTEI, &st, 1, loop_ub + 1);
                    for (i = 0; i <= loop_ub; i++) {
                      idx[i] = static_cast<real_T>(numCols) - static_cast<real_T>
                        (i);
                    }
                  }

                  if (IsDistortionHigh) {
                    st.site = &qj_emlrtRSI;
                    b_fitPolynomialIndices(&st, idx, newIndices);
                    st.site = &rj_emlrtRSI;
                    if (!b_all(&st, newIndices)) {
                      int32_T b_loop_ub;
                      int32_T i1;
                      st.site = &sj_emlrtRSI;
                      if (2 > idx.size(1)) {
                        emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                          &pg_emlrtBCI, &st);
                      }

                      if (idx[1] != static_cast<int32_T>(idx[1])) {
                        emlrtIntegerCheckR2012b(idx[1], &q_emlrtDCI, &st);
                      }

                      i = BoardCoords.size(1);
                      numCols = static_cast<int32_T>(idx[1]);
                      if ((numCols < 1) || (numCols > i)) {
                        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                          1, i, &ng_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(0);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&vh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                            BoardCoords.size(0) * (numCols - 1)) +
                            BoardCoords.size(0) * BoardCoords.size(1) * i];
                        }
                      }

                      b_st.site = &jp_emlrtRSI;
                      b_squeeze(&b_st, b_this, p1);
                      if (1 > idx.size(1)) {
                        emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                          &qg_emlrtBCI, &st);
                      }

                      if (idx[0] != static_cast<int32_T>(idx[0])) {
                        emlrtIntegerCheckR2012b(idx[0], &r_emlrtDCI, &st);
                      }

                      i = BoardCoords.size(1);
                      numCols = static_cast<int32_T>(idx[0]);
                      if ((numCols < 1) || (numCols > i)) {
                        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                          1, i, &og_emlrtBCI, &st);
                      }

                      loop_ub = BoardCoords.size(0);
                      b_loop_ub = BoardCoords.size(2);
                      b_this.set_size(&wh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                      for (i = 0; i < b_loop_ub; i++) {
                        for (i1 = 0; i1 < loop_ub; i1++) {
                          b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                            BoardCoords.size(0) * (numCols - 1)) +
                            BoardCoords.size(0) * BoardCoords.size(1) * i];
                        }
                      }

                      b_st.site = &kp_emlrtRSI;
                      b_squeeze(&b_st, b_this, p2);
                      iv[0] = (*(int32_T (*)[2])p2.size())[0];
                      iv[1] = (*(int32_T (*)[2])p2.size())[1];
                      iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                      iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &nb_emlrtECI,
                        &st);
                      b_p2.set_size(&xh_emlrtRTEI, sp, p2.size(0), p2.size(1));
                      loop_ub = p2.size(0) * p2.size(1);
                      for (i = 0; i < loop_ub; i++) {
                        b_p2[i] = (p2[i] + p2[i]) - p1[i];
                      }

                      st.site = &tj_emlrtRSI;
                      findClosestIndices(&st, b_p2, newIndicesLinear);
                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if ((newIndices[b_loop_ub] == 0.0) && (b_loop_ub + 1 >
                             newIndicesLinear.size(1))) {
                          emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                            newIndicesLinear.size(1), &jg_emlrtBCI, (emlrtCTX)sp);
                        }
                      }

                      numCols = newIndices.size(1);
                      for (b_loop_ub = 0; b_loop_ub < numCols; b_loop_ub++) {
                        if (newIndices[b_loop_ub] == 0.0) {
                          if (b_loop_ub + 1 > newIndices.size(1)) {
                            emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1,
                              newIndices.size(1), &vg_emlrtBCI, (emlrtCTX)sp);
                          }

                          newIndices[b_loop_ub] = newIndicesLinear[b_loop_ub];
                        }
                      }
                    }
                  } else {
                    int32_T b_loop_ub;
                    int32_T i1;
                    st.site = &uj_emlrtRSI;
                    if (2 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                        &pg_emlrtBCI, &st);
                    }

                    numCols = static_cast<int32_T>(idx[1]);
                    if (idx[1] != numCols) {
                      emlrtIntegerCheckR2012b(idx[1], &q_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(1);
                    if ((numCols < 1) || (numCols > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                        1, i, &ng_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&vh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0) * (numCols - 1)) +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &jp_emlrtRSI;
                    b_squeeze(&b_st, b_this, p1);
                    if (1 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                        &qg_emlrtBCI, &st);
                    }

                    numCols = static_cast<int32_T>(idx[0]);
                    if (idx[0] != numCols) {
                      emlrtIntegerCheckR2012b(idx[0], &r_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(1);
                    if ((numCols < 1) || (numCols > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                        1, i, &og_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    b_loop_ub = BoardCoords.size(2);
                    b_this.set_size(&wh_emlrtRTEI, &st, loop_ub, 1, b_loop_ub);
                    for (i = 0; i < b_loop_ub; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0) * (numCols - 1)) +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &kp_emlrtRSI;
                    b_squeeze(&b_st, b_this, p2);
                    iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &nb_emlrtECI, &st);
                    b_p2.set_size(&xh_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &vj_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndices);
                  }

                  st.site = &wj_emlrtRSI;
                  expandBoardRight(&st, newIndices, p1, r);
                  BoardIdx.set_size(&yh_emlrtRTEI, sp, p1.size(0), p1.size(1));
                  loop_ub = p1.size(0) * p1.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    BoardIdx[i] = p1[i];
                  }

                  BoardCoords.set_size(&ai_emlrtRTEI, sp, r.size(0), r.size(1),
                                       r.size(2));
                  loop_ub = r.size(0) * r.size(1) * r.size(2);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[i] = r[i];
                  }

                  idx.set_size(&bi_emlrtRTEI, sp, 1, idx.size(1));
                  loop_ub = idx.size(1) - 1;
                  for (i = 0; i <= loop_ub; i++) {
                    idx[i] = idx[i] + 1.0;
                  }

                  st.site = &xj_emlrtRSI;
                  oldEnergy = computeNewEnergyHorizontal(&st, idx, oldEnergy);
                }
                break;
              }

              Energy = oldEnergy;
              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::expandBoardDown(const emlrtStack *sp, const ::
              coder::array<real_T, 2U> &indices, ::coder::array<real_T, 2U>
              &newBoard, ::coder::array<real_T, 3U> &newBoardCoords) const
            {
              ::coder::array<real_T, 2U> r1;
              ::coder::array<int32_T, 2U> r;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              real_T d;
              int32_T iv1[3];
              int32_T iv[2];
              int32_T b_loop_ub;
              int32_T b_this;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &hb_emlrtDCI, (emlrtCTX)sp);
              }

              newBoard.set_size(&hm_emlrtRTEI, sp, static_cast<int32_T>(d),
                                BoardIdx.size(1));
              d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &jb_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = static_cast<int32_T>(d) * BoardIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i] = 0.0;
              }

              i = BoardIdx.size(0) + 1;
              i1 = BoardIdx.size(0) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &wk_emlrtBCI, (emlrtCTX)
                  sp);
              }

              iv[0] = 1;
              iv[1] = BoardIdx.size(1);
              emlrtSubAssignSizeCheckR2012b(&iv[0], 2, ((::coder::array<real_T,
                2U> *)&indices)->size(), 2, &dc_emlrtECI, (emlrtCTX)sp);
              b_this = BoardIdx.size(0);
              loop_ub = indices.size(1);
              for (i = 0; i < loop_ub; i++) {
                newBoard[b_this + newBoard.size(0) * i] = indices[i];
              }

              if (1 > newBoard.size(0) - 1) {
                i = 0;
              } else {
                if ((newBoard.size(0) - 1 < 1) || (newBoard.size(0) - 1 >
                     newBoard.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(newBoard.size(0) - 1, 1,
                    newBoard.size(0), &xk_emlrtBCI, (emlrtCTX)sp);
                }

                i = newBoard.size(0) - 1;
              }

              iv[0] = i;
              iv[1] = newBoard.size(1);
              emlrtSubAssignSizeCheckR2012b(&iv[0], 2, ((::coder::array<real_T,
                2U> *)&BoardIdx)->size(), 2, &ec_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = BoardIdx.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoard[i1 + newBoard.size(0) * i] = BoardIdx[i1 +
                    BoardIdx.size(0) * i];
                }
              }

              d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &ib_emlrtDCI, (emlrtCTX)sp);
              }

              newBoardCoords.set_size(&im_emlrtRTEI, sp, static_cast<int32_T>(d),
                BoardCoords.size(1), BoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &kb_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = static_cast<int32_T>(d) * BoardCoords.size(1) *
                BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                newBoardCoords[i] = 0.0;
              }

              i = BoardCoords.size(0) + 1;
              i1 = BoardCoords.size(0) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &yk_emlrtBCI, (emlrtCTX)
                  sp);
              }

              end = indices.size(1);
              for (loop_ub = 0; loop_ub < end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  i = BoardCoords.size(1);
                  if (loop_ub + 1 > i) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i,
                      &bl_emlrtBCI, (emlrtCTX)sp);
                  }
                }
              }

              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r.set_size(&jm_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              b_this = Points.size(0);
              loop_ub = Points.size(1);
              r1.set_size(&km_emlrtRTEI, sp, r.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r[i1] > indices.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i1], 1, indices.size(1),
                      &dl_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(indices[r[i1] - 1]);
                  if ((i2 < 1) || (i2 > b_this)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &cl_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r1[i1 + r1.size(0) * i] = Points[(i2 + Points.size(0) * i) - 1];
                }
              }

              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r2.set_size(&jm_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r2[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              iv1[0] = 1;
              iv1[1] = r2.size(1);
              iv1[2] = BoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r1.size(), 2,
                &fc_emlrtECI, (emlrtCTX)sp);
              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r3.set_size(&jm_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r3[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              iv1[1] = r3.size(1);
              iv1[2] = BoardCoords.size(2);
              b_this = BoardCoords.size(0);
              loop_ub = iv1[2];
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = iv1[1];
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoardCoords[(b_this + newBoardCoords.size(0) * (r3[i1] - 1))
                    + newBoardCoords.size(0) * newBoardCoords.size(1) * i] =
                    r1[i1 + iv1[1] * i];
                }
              }

              if (1 > newBoardCoords.size(0) - 1) {
                i = 0;
              } else {
                if ((newBoardCoords.size(0) - 1 < 1) || (newBoardCoords.size(0)
                     - 1 > newBoardCoords.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(newBoardCoords.size(0) - 1, 1,
                    newBoardCoords.size(0), &al_emlrtBCI, (emlrtCTX)sp);
                }

                i = newBoardCoords.size(0) - 1;
              }

              iv1[0] = i;
              iv1[1] = newBoardCoords.size(1);
              iv1[2] = newBoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
                3U> *)&BoardCoords)->size(), 3, &gc_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = BoardCoords.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  end = BoardCoords.size(0);
                  for (i2 = 0; i2 < end; i2++) {
                    newBoardCoords[(i2 + newBoardCoords.size(0) * i1) +
                      newBoardCoords.size(0) * newBoardCoords.size(1) * i] =
                      BoardCoords[(i2 + BoardCoords.size(0) * i1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i];
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::expandBoardLeft(const emlrtStack *sp, const ::
              coder::array<real_T, 2U> &indices, ::coder::array<real_T, 2U>
              &newBoard, ::coder::array<real_T, 3U> &newBoardCoords) const
            {
              ::coder::array<real_T, 2U> r1;
              ::coder::array<int32_T, 2U> r;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              real_T d;
              int32_T b_newBoardCoords[3];
              int32_T b_newBoard[2];
              int32_T b_loop_ub;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              int32_T trueCount;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              newBoard.set_size(&wm_emlrtRTEI, sp, BoardIdx.size(0),
                                newBoard.size(1));
              d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &ac_emlrtDCI, (emlrtCTX)sp);
              }

              newBoard.set_size(&wm_emlrtRTEI, sp, newBoard.size(0),
                                static_cast<int32_T>(d));
              d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &cc_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0) * static_cast<int32_T>(d);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i] = 0.0;
              }

              emlrtSubAssignSizeCheckR2012b(((::coder::array<real_T, 2U> *)
                &BoardIdx)->size(), 1, ((::coder::array<real_T, 2U> *)&indices
                )->size(), 2, &kc_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardIdx.size(0);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i] = indices[i];
              }

              if (2 > newBoard.size(1)) {
                i = 0;
                i1 = 0;
              } else {
                i = 1;
                i1 = newBoard.size(1);
              }

              b_newBoard[0] = newBoard.size(0);
              b_newBoard[1] = i1 - i;
              emlrtSubAssignSizeCheckR2012b(&b_newBoard[0], 2, ((::coder::array<
                real_T, 2U> *)&BoardIdx)->size(), 2, &lc_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardIdx.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_loop_ub = BoardIdx.size(0);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  newBoard[i2 + newBoard.size(0) * (i + i1)] = BoardIdx[i2 +
                    BoardIdx.size(0) * i1];
                }
              }

              newBoardCoords.set_size(&xm_emlrtRTEI, sp, BoardCoords.size(0),
                newBoardCoords.size(1), newBoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &bc_emlrtDCI, (emlrtCTX)sp);
              }

              newBoardCoords.set_size(&xm_emlrtRTEI, sp, newBoardCoords.size(0),
                static_cast<int32_T>(d), BoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &dc_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(0) * static_cast<int32_T>(d) *
                BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                newBoardCoords[i] = 0.0;
              }

              loop_ub = indices.size(1);
              for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  i = BoardCoords.size(0);
                  if (b_loop_ub + 1 > i) {
                    emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, i,
                      &ym_emlrtBCI, (emlrtCTX)sp);
                  }
                }
              }

              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r.set_size(&ym_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              trueCount = Points.size(0);
              loop_ub = Points.size(1);
              r1.set_size(&an_emlrtRTEI, sp, r.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r[i1] > indices.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i1], 1, indices.size(1),
                      &bn_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(indices[r[i1] - 1]);
                  if ((i2 < 1) || (i2 > trueCount)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, trueCount, &an_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r1[i1 + r1.size(0) * i] = Points[(i2 + Points.size(0) * i) - 1];
                }
              }

              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r2.set_size(&ym_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r2[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              b_newBoardCoords[0] = r2.size(1);
              b_newBoardCoords[1] = 1;
              b_newBoardCoords[2] = BoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&b_newBoardCoords[0], 3, r1.size(),
                2, &mc_emlrtECI, (emlrtCTX)sp);
              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r3.set_size(&ym_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r3[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              b_newBoardCoords[0] = r3.size(1);
              b_newBoardCoords[2] = BoardCoords.size(2);
              loop_ub = b_newBoardCoords[2];
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = b_newBoardCoords[0];
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoardCoords[(r3[i1] + newBoardCoords.size(0) *
                                  newBoardCoords.size(1) * i) - 1] = r1[i1 +
                    b_newBoardCoords[0] * i];
                }
              }

              if (2 > newBoardCoords.size(1)) {
                i = 0;
                i1 = 0;
              } else {
                i = 1;
                i1 = newBoardCoords.size(1);
              }

              b_newBoardCoords[0] = newBoardCoords.size(0);
              b_newBoardCoords[1] = i1 - i;
              b_newBoardCoords[2] = newBoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&b_newBoardCoords[0], 3, ((::coder::
                array<real_T, 3U> *)&BoardCoords)->size(), 3, &nc_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = BoardCoords.size(2);
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_loop_ub = BoardCoords.size(1);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  trueCount = BoardCoords.size(0);
                  for (int32_T i3{0}; i3 < trueCount; i3++) {
                    newBoardCoords[(i3 + newBoardCoords.size(0) * (i + i2)) +
                      newBoardCoords.size(0) * newBoardCoords.size(1) * i1] =
                      BoardCoords[(i3 + BoardCoords.size(0) * i2) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::expandBoardRight(const emlrtStack *sp, const ::
              coder::array<real_T, 2U> &indices, ::coder::array<real_T, 2U>
              &newBoard, ::coder::array<real_T, 3U> &newBoardCoords) const
            {
              ::coder::array<real_T, 2U> r1;
              ::coder::array<int32_T, 2U> r;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              real_T d;
              int32_T b_newBoardCoords[3];
              int32_T b_newBoard[2];
              int32_T b_loop_ub;
              int32_T b_this;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              newBoard.set_size(&co_emlrtRTEI, sp, BoardIdx.size(0),
                                newBoard.size(1));
              d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &kc_emlrtDCI, (emlrtCTX)sp);
              }

              newBoard.set_size(&co_emlrtRTEI, sp, newBoard.size(0),
                                static_cast<int32_T>(d));
              d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &mc_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = BoardIdx.size(0) * static_cast<int32_T>(d);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i] = 0.0;
              }

              i = BoardIdx.size(1) + 1;
              i1 = BoardIdx.size(1) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &vo_emlrtBCI, (emlrtCTX)
                  sp);
              }

              emlrtSubAssignSizeCheckR2012b(((::coder::array<real_T, 2U> *)
                &BoardIdx)->size(), 1, ((::coder::array<real_T, 2U> *)&indices
                )->size(), 2, &tc_emlrtECI, (emlrtCTX)sp);
              b_this = BoardIdx.size(1);
              loop_ub = BoardIdx.size(0);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i + newBoard.size(0) * b_this] = indices[i];
              }

              if (1 > newBoard.size(1) - 1) {
                i = 0;
              } else {
                if ((newBoard.size(1) - 1 < 1) || (newBoard.size(1) - 1 >
                     newBoard.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(newBoard.size(1) - 1, 1,
                    newBoard.size(1), &wo_emlrtBCI, (emlrtCTX)sp);
                }

                i = newBoard.size(1) - 1;
              }

              b_newBoard[0] = newBoard.size(0);
              b_newBoard[1] = i;
              emlrtSubAssignSizeCheckR2012b(&b_newBoard[0], 2, ((::coder::array<
                real_T, 2U> *)&BoardIdx)->size(), 2, &uc_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = BoardIdx.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoard[i1 + newBoard.size(0) * i] = BoardIdx[i1 +
                    BoardIdx.size(0) * i];
                }
              }

              newBoardCoords.set_size(&do_emlrtRTEI, sp, BoardCoords.size(0),
                newBoardCoords.size(1), newBoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &lc_emlrtDCI, (emlrtCTX)sp);
              }

              newBoardCoords.set_size(&do_emlrtRTEI, sp, newBoardCoords.size(0),
                static_cast<int32_T>(d), BoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &nc_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(0) * static_cast<int32_T>(d) *
                BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                newBoardCoords[i] = 0.0;
              }

              end = indices.size(1);
              for (loop_ub = 0; loop_ub < end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  i = BoardCoords.size(0);
                  if (loop_ub + 1 > i) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, i,
                      &ap_emlrtBCI, (emlrtCTX)sp);
                  }
                }
              }

              i = BoardCoords.size(1) + 1;
              i1 = BoardCoords.size(1) + 1;
              if ((i1 < 1) || (i1 > i)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, i, &xo_emlrtBCI, (emlrtCTX)
                  sp);
              }

              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r.set_size(&eo_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              b_this = Points.size(0);
              loop_ub = Points.size(1);
              r1.set_size(&fo_emlrtRTEI, sp, r.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r[i1] > indices.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i1], 1, indices.size(1),
                      &cp_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(indices[r[i1] - 1]);
                  if ((i2 < 1) || (i2 > b_this)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, b_this, &bp_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r1[i1 + r1.size(0) * i] = Points[(i2 + Points.size(0) * i) - 1];
                }
              }

              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r2.set_size(&eo_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r2[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              b_newBoardCoords[0] = r2.size(1);
              b_newBoardCoords[1] = 1;
              b_newBoardCoords[2] = BoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&b_newBoardCoords[0], 3, r1.size(),
                2, &vc_emlrtECI, (emlrtCTX)sp);
              end = indices.size(1) - 1;
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  b_this++;
                }
              }

              r3.set_size(&eo_emlrtRTEI, sp, 1, b_this);
              b_this = 0;
              for (loop_ub = 0; loop_ub <= end; loop_ub++) {
                if (indices[loop_ub] > 0.0) {
                  r3[b_this] = loop_ub + 1;
                  b_this++;
                }
              }

              b_newBoardCoords[0] = r3.size(1);
              b_newBoardCoords[2] = BoardCoords.size(2);
              b_this = BoardCoords.size(1);
              loop_ub = b_newBoardCoords[2];
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = b_newBoardCoords[0];
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoardCoords[((r3[i1] + newBoardCoords.size(0) * b_this) +
                                  newBoardCoords.size(0) * newBoardCoords.size(1)
                                  * i) - 1] = r1[i1 + b_newBoardCoords[0] * i];
                }
              }

              if (1 > newBoardCoords.size(1) - 1) {
                i = 0;
              } else {
                if ((newBoardCoords.size(1) - 1 < 1) || (newBoardCoords.size(1)
                     - 1 > newBoardCoords.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(newBoardCoords.size(1) - 1, 1,
                    newBoardCoords.size(1), &yo_emlrtBCI, (emlrtCTX)sp);
                }

                i = newBoardCoords.size(1) - 1;
              }

              b_newBoardCoords[0] = newBoardCoords.size(0);
              b_newBoardCoords[1] = i;
              b_newBoardCoords[2] = newBoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&b_newBoardCoords[0], 3, ((::coder::
                array<real_T, 3U> *)&BoardCoords)->size(), 3, &wc_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = BoardCoords.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  end = BoardCoords.size(0);
                  for (i2 = 0; i2 < end; i2++) {
                    newBoardCoords[(i2 + newBoardCoords.size(0) * i1) +
                      newBoardCoords.size(0) * newBoardCoords.size(1) * i] =
                      BoardCoords[(i2 + BoardCoords.size(0) * i1) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i];
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::expandBoardUp(const emlrtStack *sp, const ::coder::
              array<real_T, 2U> &indices, ::coder::array<real_T, 2U> &newBoard, ::
              coder::array<real_T, 3U> &newBoardCoords) const
            {
              ::coder::array<real_T, 2U> r1;
              ::coder::array<int32_T, 2U> r;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              real_T d;
              int32_T iv1[3];
              int32_T iv[2];
              int32_T b_loop_ub;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              int32_T trueCount;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &w_emlrtDCI, (emlrtCTX)sp);
              }

              newBoard.set_size(&cl_emlrtRTEI, sp, static_cast<int32_T>(d),
                                BoardIdx.size(1));
              d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &y_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = static_cast<int32_T>(d) * BoardIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                newBoard[i] = 0.0;
              }

              iv[0] = 1;
              iv[1] = BoardIdx.size(1);
              emlrtSubAssignSizeCheckR2012b(&iv[0], 2, ((::coder::array<real_T,
                2U> *)&indices)->size(), 2, &tb_emlrtECI, (emlrtCTX)sp);
              loop_ub = indices.size(1);
              for (i = 0; i < loop_ub; i++) {
                newBoard[newBoard.size(0) * i] = indices[i];
              }

              if (2 > newBoard.size(0)) {
                i = 0;
                i1 = 0;
              } else {
                i = 1;
                i1 = newBoard.size(0);
              }

              iv[0] = i1 - i;
              iv[1] = newBoard.size(1);
              emlrtSubAssignSizeCheckR2012b(&iv[0], 2, ((::coder::array<real_T,
                2U> *)&BoardIdx)->size(), 2, &ub_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardIdx.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_loop_ub = BoardIdx.size(0);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  newBoard[(i + i2) + newBoard.size(0) * i1] = BoardIdx[i2 +
                    BoardIdx.size(0) * i1];
                }
              }

              d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &x_emlrtDCI, (emlrtCTX)sp);
              }

              newBoardCoords.set_size(&dl_emlrtRTEI, sp, static_cast<int32_T>(d),
                BoardCoords.size(1), BoardCoords.size(2));
              d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
              if (d != static_cast<int32_T>(d)) {
                emlrtIntegerCheckR2012b(d, &ab_emlrtDCI, (emlrtCTX)sp);
              }

              loop_ub = static_cast<int32_T>(d) * BoardCoords.size(1) *
                BoardCoords.size(2);
              for (i = 0; i < loop_ub; i++) {
                newBoardCoords[i] = 0.0;
              }

              loop_ub = indices.size(1);
              for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  i = BoardCoords.size(1);
                  if (b_loop_ub + 1 > i) {
                    emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, i,
                      &xi_emlrtBCI, (emlrtCTX)sp);
                  }
                }
              }

              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r.set_size(&el_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              trueCount = Points.size(0);
              loop_ub = Points.size(1);
              r1.set_size(&fl_emlrtRTEI, sp, r.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r[i1] > indices.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i1], 1, indices.size(1),
                      &aj_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(indices[r[i1] - 1]);
                  if ((i2 < 1) || (i2 > trueCount)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, trueCount, &yi_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r1[i1 + r1.size(0) * i] = Points[(i2 + Points.size(0) * i) - 1];
                }
              }

              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r2.set_size(&el_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r2[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              iv1[0] = 1;
              iv1[1] = r2.size(1);
              iv1[2] = BoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r1.size(), 2,
                &vb_emlrtECI, (emlrtCTX)sp);
              loop_ub = indices.size(1) - 1;
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  trueCount++;
                }
              }

              r3.set_size(&el_emlrtRTEI, sp, 1, trueCount);
              trueCount = 0;
              for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
                if (indices[b_loop_ub] > 0.0) {
                  r3[trueCount] = b_loop_ub + 1;
                  trueCount++;
                }
              }

              iv1[1] = r3.size(1);
              iv1[2] = BoardCoords.size(2);
              loop_ub = iv1[2];
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = iv1[1];
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  newBoardCoords[newBoardCoords.size(0) * (r3[i1] - 1) +
                    newBoardCoords.size(0) * newBoardCoords.size(1) * i] = r1[i1
                    + iv1[1] * i];
                }
              }

              if (2 > newBoardCoords.size(0)) {
                i = 0;
                i1 = 0;
              } else {
                i = 1;
                i1 = newBoardCoords.size(0);
              }

              iv1[0] = i1 - i;
              iv1[1] = newBoardCoords.size(1);
              iv1[2] = newBoardCoords.size(2);
              emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
                3U> *)&BoardCoords)->size(), 3, &wb_emlrtECI, (emlrtCTX)sp);
              loop_ub = BoardCoords.size(2);
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_loop_ub = BoardCoords.size(1);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  trueCount = BoardCoords.size(0);
                  for (int32_T i3{0}; i3 < trueCount; i3++) {
                    newBoardCoords[((i + i3) + newBoardCoords.size(0) * i2) +
                      newBoardCoords.size(0) * newBoardCoords.size(1) * i1] =
                      BoardCoords[(i3 + BoardCoords.size(0) * i2) +
                      BoardCoords.size(0) * BoardCoords.size(1) * i1];
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::findClosestIndices(const emlrtStack *sp, const ::
              coder::array<real_T, 2U> &predictedPoints, ::coder::array<real_T,
              2U> &indices) const
            {
              ::coder::array<real_T, 2U> remIdx;
              ::coder::array<real_T, 2U> y;
              ::coder::array<real_T, 1U> b_this;
              ::coder::array<int32_T, 2U> r;
              ::coder::array<int32_T, 1U> ii;
              ::coder::array<real32_T, 2U> a;
              ::coder::array<real32_T, 2U> diffs;
              ::coder::array<real32_T, 1U> b_diffs;
              ::coder::array<real32_T, 1U> c_diffs;
              ::coder::array<real32_T, 1U> dists;
              ::coder::array<uint32_T, 1U> validPredictions;
              ::coder::array<boolean_T, 2U> distIdx;
              ::coder::array<boolean_T, 1U> x;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack st;
              int32_T iv[2];
              int32_T c_this;
              int32_T i;
              int32_T i1;
              int32_T i3;
              int32_T loop_ub;
              int32_T nx;
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
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              indices.set_size(&sk_emlrtRTEI, sp, 1, predictedPoints.size(0));
              nx = predictedPoints.size(0);
              for (i = 0; i < nx; i++) {
                indices[i] = 0.0;
              }

              nx = Points.size(0);
              if (nx < 1) {
                y.set_size(&gj_emlrtRTEI, sp, 1, 0);
              } else {
                y.set_size(&gj_emlrtRTEI, sp, 1, nx);
                nx--;
                for (i = 0; i <= nx; i++) {
                  y[i] = static_cast<real_T>(i) + 1.0;
                }
              }

              st.site = &eo_emlrtRSI;
              b_st.site = &om_emlrtRSI;
              nx = BoardIdx.size(0) * BoardIdx.size(1);
              b_this = BoardIdx.reshape(nx);
              c_st.site = &pm_emlrtRSI;
              do_vectors(&c_st, y, b_this, remIdx, ii, &nx);
              if (remIdx.size(1) != 0) {
                int32_T bcoef;
                int32_T idx;
                boolean_T exitg1;
                if (1 > predictedPoints.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, predictedPoints.size(1),
                    &mi_emlrtBCI, (emlrtCTX)sp);
                }

                st.site = &fo_emlrtRSI;
                nx = predictedPoints.size(0);
                x.set_size(&rc_emlrtRTEI, &st, predictedPoints.size(0));
                for (i = 0; i < nx; i++) {
                  x[i] = muDoubleScalarIsNaN(predictedPoints[i]);
                }

                nx = x.size(0);
                for (i = 0; i < nx; i++) {
                  x[i] = !x[i];
                }

                b_st.site = &se_emlrtRSI;
                nx = x.size(0);
                c_st.site = &te_emlrtRSI;
                idx = 0;
                ii.set_size(&re_emlrtRTEI, &c_st, x.size(0));
                d_st.site = &ve_emlrtRSI;
                if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                  e_st.site = &qc_emlrtRSI;
                  check_forloop_overflow_error(&e_st);
                }

                bcoef = 0;
                exitg1 = false;
                while ((!exitg1) && (bcoef <= nx - 1)) {
                  if (x[bcoef]) {
                    idx++;
                    ii[idx - 1] = bcoef + 1;
                    if (idx >= nx) {
                      exitg1 = true;
                    } else {
                      bcoef++;
                    }
                  } else {
                    bcoef++;
                  }
                }

                if (idx > x.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &q_emlrtRTEI,
                    "Coder:builtins:AssertionFailed",
                    "Coder:builtins:AssertionFailed", 0);
                }

                if (x.size(0) == 1) {
                  if (idx == 0) {
                    ii.set_size(&tk_emlrtRTEI, &c_st, 0);
                  }
                } else {
                  if (1 > idx) {
                    i = 0;
                  } else {
                    i = idx;
                  }

                  iv[0] = 1;
                  iv[1] = i;
                  d_st.site = &we_emlrtRSI;
                  ::Codegen::coder::internal::indexShapeCheck(&d_st, ii.size(0),
                    iv);
                  ii.set_size(&tk_emlrtRTEI, &c_st, i);
                }

                validPredictions.set_size(&uk_emlrtRTEI, &st, ii.size(0));
                nx = ii.size(0);
                for (i = 0; i < nx; i++) {
                  validPredictions[i] = static_cast<uint32_T>(ii[i]);
                }

                i = validPredictions.size(0);
                if (0 <= validPredictions.size(0) - 1) {
                  c_this = Points.size(0);
                  loop_ub = Points.size(1);
                  i1 = predictedPoints.size(1);
                }

                for (int32_T b_i{0}; b_i < i; b_i++) {
                  int32_T i2;
                  int32_T i4;
                  int32_T k;
                  if (b_i + 1 > validPredictions.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validPredictions.size(0), &qi_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(validPredictions[b_i]);
                  if (i2 > predictedPoints.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, predictedPoints.size(0),
                      &ni_emlrtBCI, (emlrtCTX)sp);
                  }

                  st.site = &go_emlrtRSI;
                  a.set_size(&vk_emlrtRTEI, &st, remIdx.size(1), loop_ub);
                  for (i2 = 0; i2 < loop_ub; i2++) {
                    nx = remIdx.size(1);
                    for (i4 = 0; i4 < nx; i4++) {
                      if (remIdx[i4] != static_cast<int32_T>(muDoubleScalarFloor
                           (remIdx[i4]))) {
                        emlrtIntegerCheckR2012b(remIdx[i4], &v_emlrtDCI, &st);
                      }

                      bcoef = static_cast<int32_T>(remIdx[i4]);
                      if ((bcoef < 1) || (bcoef > c_this)) {
                        emlrtDynamicBoundsCheckR2012b(bcoef, 1, c_this,
                          &ri_emlrtBCI, &st);
                      }

                      a[i4 + a.size(0) * i2] = Points[(bcoef + Points.size(0) *
                        i2) - 1];
                    }
                  }

                  if (i1 == 1) {
                    i3 = a.size(1);
                  } else if (a.size(1) == 1) {
                    i3 = predictedPoints.size(1);
                  } else if (predictedPoints.size(1) == a.size(1)) {
                    i3 = a.size(1);
                  } else {
                    emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
                      "MATLAB:bsxfun:arrayDimensionsMustMatch",
                      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
                  }

                  diffs.set_size(&mf_emlrtRTEI, &st, a.size(0), i3);
                  if (i3 != 0) {
                    nx = (a.size(1) != 1);
                    bcoef = (predictedPoints.size(1) != 1);
                    i2 = i3 - 1;
                    for (k = 0; k <= i2; k++) {
                      int32_T acoef;
                      int32_T varargin_3;
                      idx = nx * k;
                      varargin_3 = bcoef * k;
                      acoef = (a.size(0) != 1);
                      i4 = diffs.size(0) - 1;
                      for (int32_T b_k{0}; b_k <= i4; b_k++) {
                        diffs[b_k + diffs.size(0) * k] = a[acoef * b_k + a.size
                          (0) * idx] - static_cast<real32_T>(predictedPoints[(
                          static_cast<int32_T>(validPredictions[b_i]) +
                          predictedPoints.size(0) * varargin_3) - 1]);
                      }
                    }
                  }

                  if (1 > diffs.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, diffs.size(1),
                      &oi_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (2 > diffs.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, diffs.size(1),
                      &pi_emlrtBCI, (emlrtCTX)sp);
                  }

                  nx = diffs.size(0);
                  b_diffs.set_size(&wk_emlrtRTEI, sp, diffs.size(0));
                  for (i2 = 0; i2 < nx; i2++) {
                    b_diffs[i2] = diffs[i2];
                  }

                  nx = diffs.size(0);
                  c_diffs.set_size(&xk_emlrtRTEI, sp, diffs.size(0));
                  for (i2 = 0; i2 < nx; i2++) {
                    c_diffs[i2] = diffs[i2 + diffs.size(0)];
                  }

                  st.site = &ho_emlrtRSI;
                  b_hypot(&st, b_diffs, c_diffs, dists);
                  bcoef = indices.size(1) - 1;
                  nx = 0;
                  for (idx = 0; idx <= bcoef; idx++) {
                    if (indices[idx] > 0.0) {
                      nx++;
                    }
                  }

                  r.set_size(&yk_emlrtRTEI, sp, 1, nx);
                  nx = 0;
                  for (idx = 0; idx <= bcoef; idx++) {
                    if (indices[idx] > 0.0) {
                      r[nx] = idx + 1;
                      nx++;
                    }
                  }

                  st.site = &io_emlrtRSI;
                  nx = r.size(1);
                  for (i2 = 0; i2 < nx; i2++) {
                    if ((r[i2] < 1) || (r[i2] > indices.size(1))) {
                      emlrtDynamicBoundsCheckR2012b(r[i2], 1, indices.size(1),
                        &si_emlrtBCI, &st);
                    }
                  }

                  y.set_size(&al_emlrtRTEI, &st, 1, r.size(1));
                  nx = r.size(1);
                  for (i2 = 0; i2 < nx; i2++) {
                    y[i2] = indices[r[i2] - 1];
                  }

                  b_st.site = &ko_emlrtRSI;
                  local_ismember(&b_st, remIdx, y, distIdx);
                  bcoef = distIdx.size(1);
                  for (idx = 0; idx < bcoef; idx++) {
                    if (distIdx[idx]) {
                      if (idx + 1 > dists.size(0)) {
                        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, dists.size(0),
                          &ti_emlrtBCI, (emlrtCTX)sp);
                      }

                      dists[idx] = rtInfF;
                    }
                  }

                  st.site = &jo_emlrtRSI;
                  b_st.site = &vh_emlrtRSI;
                  c_st.site = &wh_emlrtRSI;
                  d_st.site = &xh_emlrtRSI;
                  if (dists.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &yh_emlrtRSI;
                  nx = dists.size(0);
                  if (dists.size(0) <= 2) {
                    if (dists.size(0) == 1) {
                      idx = 1;
                    } else if ((dists[0] > dists[1]) || (muSingleScalarIsNaN
                                (dists[0]) && (!muSingleScalarIsNaN(dists[1]))))
                    {
                      idx = 2;
                    } else {
                      idx = 1;
                    }
                  } else {
                    f_st.site = &ae_emlrtRSI;
                    if (!muSingleScalarIsNaN(dists[0])) {
                      idx = 1;
                    } else {
                      idx = 0;
                      g_st.site = &be_emlrtRSI;
                      if (dists.size(0) > 2147483646) {
                        h_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&h_st);
                      }

                      k = 2;
                      exitg1 = false;
                      while ((!exitg1) && (k <= nx)) {
                        if (!muSingleScalarIsNaN(dists[k - 1])) {
                          idx = k;
                          exitg1 = true;
                        } else {
                          k++;
                        }
                      }
                    }

                    if (idx == 0) {
                      idx = 1;
                    } else {
                      real32_T ex;
                      f_st.site = &yd_emlrtRSI;
                      ex = dists[idx - 1];
                      bcoef = idx + 1;
                      g_st.site = &ce_emlrtRSI;
                      if ((idx + 1 <= dists.size(0)) && (dists.size(0) >
                           2147483646)) {
                        h_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&h_st);
                      }

                      for (k = bcoef; k <= nx; k++) {
                        real32_T f;
                        f = dists[k - 1];
                        if (ex > f) {
                          ex = f;
                          idx = k;
                        }
                      }
                    }
                  }

                  if ((idx < 1) || (idx > remIdx.size(1))) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, remIdx.size(1),
                      &ui_emlrtBCI, (emlrtCTX)sp);
                  }

                  if (b_i + 1 > validPredictions.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                      validPredictions.size(0), &wi_emlrtBCI, (emlrtCTX)sp);
                  }

                  i2 = static_cast<int32_T>(validPredictions[b_i]);
                  if (i2 > indices.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, indices.size(1),
                      &vi_emlrtBCI, (emlrtCTX)sp);
                  }

                  indices[i2 - 1] = remIdx[idx - 1];
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::findClosestOnCurve(const emlrtStack *sp, const
              real_T predictedPoint[2], real_T radius, const real_T curve_data[],
              const int32_T curve_size[2], const real_T coordsToUse[2], const ::
              coder::array<real_T, 2U> &removedIdx, ::coder::array<real_T, 2U>
              &idx) const
            {
              ::coder::array<real_T, 2U> dataPts;
              ::coder::array<real_T, 2U> firstCoord;
              ::coder::array<real_T, 2U> r;
              ::coder::array<real_T, 2U> remIdx;
              ::coder::array<real_T, 1U> b_this;
              ::coder::array<real_T, 1U> c_idx;
              ::coder::array<real_T, 1U> dist;
              ::coder::array<real_T, 1U> varargin_2;
              ::coder::array<int32_T, 1U> ii;
              ::coder::array<int32_T, 1U> r1;
              ::coder::array<real32_T, 2U> b_dataPts;
              ::coder::array<real32_T, 2U> b_queryPts;
              ::coder::array<real32_T, 2U> currPt;
              ::coder::array<real32_T, 2U> diffs;
              ::coder::array<real32_T, 2U> queryPts;
              ::coder::array<real32_T, 1U> b_diffs;
              ::coder::array<real32_T, 1U> c_diffs;
              ::coder::array<real32_T, 1U> dists;
              ::coder::array<boolean_T, 1U> s;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack i_st;
              emlrtStack st;
              int32_T iv[2];
              int32_T iv1[2];
              int32_T b_idx;
              int32_T b_loop_ub;
              int32_T i;
              int32_T i1;
              int32_T last;
              int32_T loop_ub;
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
              last = Points.size(0);
              if (last < 1) {
                firstCoord.set_size(&gj_emlrtRTEI, sp, 1, 0);
              } else {
                firstCoord.set_size(&gj_emlrtRTEI, sp, 1, last);
                loop_ub = last - 1;
                for (i = 0; i <= loop_ub; i++) {
                  firstCoord[i] = static_cast<real_T>(i) + 1.0;
                }
              }

              st.site = &dm_emlrtRSI;
              b_st.site = &om_emlrtRSI;
              last = BoardIdx.size(0) * BoardIdx.size(1);
              b_this = BoardIdx.reshape(last);
              c_st.site = &pm_emlrtRSI;
              do_vectors(&c_st, firstCoord, b_this, remIdx, ii, &last);
              st.site = &em_emlrtRSI;
              b_st.site = &om_emlrtRSI;
              firstCoord.set_size(&hj_emlrtRTEI, &b_st, 1, remIdx.size(1));
              loop_ub = remIdx.size(0) * remIdx.size(1) - 1;
              for (i = 0; i <= loop_ub; i++) {
                firstCoord[i] = remIdx[i];
              }

              c_st.site = &pm_emlrtRSI;
              do_vectors(&c_st, firstCoord, removedIdx, remIdx, ii, &last);
              last = Points.size(0);
              loop_ub = Points.size(1);
              queryPts.set_size(&ij_emlrtRTEI, sp, remIdx.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = remIdx.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (remIdx[i1] != static_cast<int32_T>(muDoubleScalarFloor
                       (remIdx[i1]))) {
                    emlrtIntegerCheckR2012b(remIdx[i1], &u_emlrtDCI, (emlrtCTX)
                      sp);
                  }

                  b_idx = static_cast<int32_T>(remIdx[i1]);
                  if ((b_idx < 1) || (b_idx > last)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, last, &gi_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  queryPts[i1 + queryPts.size(0) * i] = Points[(b_idx +
                    Points.size(0) * i) - 1];
                }
              }

              st.site = &fm_emlrtRSI;
              bsxfun(&st, queryPts, predictedPoint, diffs);
              loop_ub = diffs.size(0);
              b_diffs.set_size(&jj_emlrtRTEI, sp, diffs.size(0));
              for (i = 0; i < loop_ub; i++) {
                b_diffs[i] = diffs[i];
              }

              loop_ub = diffs.size(0);
              c_diffs.set_size(&kj_emlrtRTEI, sp, diffs.size(0));
              for (i = 0; i < loop_ub; i++) {
                c_diffs[i] = diffs[i + diffs.size(0)];
              }

              st.site = &gm_emlrtRSI;
              b_hypot(&st, b_diffs, c_diffs, dists);
              s.set_size(&lj_emlrtRTEI, sp, dists.size(0));
              loop_ub = dists.size(0);
              for (i = 0; i < loop_ub; i++) {
                s[i] = (dists[i] < radius);
              }

              last = 0;
              i = s.size(0);
              for (loop_ub = 0; loop_ub < i; loop_ub++) {
                if (s[loop_ub]) {
                  last++;
                }
              }

              if (last > 1) {
                real_T a;
                real_T a_tmp;
                int32_T b_i;
                boolean_T exitg1;
                st.site = &hm_emlrtRSI;
                a_tmp = predictedPoint[static_cast<int32_T>(coordsToUse[0]) - 1];
                a = a_tmp - radius;
                a_tmp += radius;
                if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(a_tmp)) {
                  firstCoord.set_size(&pj_emlrtRTEI, &st, 1, 1);
                  firstCoord[0] = rtNaN;
                } else if (a_tmp < a) {
                  firstCoord.set_size(&pj_emlrtRTEI, &st, 1, 0);
                } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(a_tmp))
                           && (a == a_tmp)) {
                  firstCoord.set_size(&pj_emlrtRTEI, &st, 1, 1);
                  firstCoord[0] = rtNaN;
                } else if (muDoubleScalarFloor(a) == a) {
                  loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_tmp - a));
                  firstCoord.set_size(&pj_emlrtRTEI, &st, 1, loop_ub + 1);
                  for (i = 0; i <= loop_ub; i++) {
                    firstCoord[i] = a + static_cast<real_T>(i);
                  }
                } else {
                  b_st.site = &hn_emlrtRSI;
                  eml_float_colon(&b_st, a, a_tmp, firstCoord);
                }

                if (isequal(coordsToUse)) {
                  st.site = &im_emlrtRSI;
                  c_idx.set_size(&tj_emlrtRTEI, &st, firstCoord.size(1));
                  loop_ub = firstCoord.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    c_idx[i] = firstCoord[i];
                  }

                  b_st.site = &im_emlrtRSI;
                  polyval(&b_st, curve_data, curve_size, firstCoord, r);
                  varargin_2.set_size(&uj_emlrtRTEI, &st, r.size(1));
                  loop_ub = r.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    varargin_2[i] = r[i];
                  }

                  b_st.site = &kn_emlrtRSI;
                  c_st.site = &ln_emlrtRSI;
                  if (varargin_2.size(0) != c_idx.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                      "MATLAB:catenate:matrixDimensionMismatch",
                      "MATLAB:catenate:matrixDimensionMismatch", 0);
                  }

                  dataPts.set_size(&vj_emlrtRTEI, &b_st, c_idx.size(0), 2);
                  loop_ub = c_idx.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    dataPts[i] = c_idx[i];
                  }

                  loop_ub = varargin_2.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    dataPts[i + dataPts.size(0)] = varargin_2[i];
                  }
                } else {
                  st.site = &jm_emlrtRSI;
                  b_st.site = &jm_emlrtRSI;
                  polyval(&b_st, curve_data, curve_size, firstCoord, r);
                  c_idx.set_size(&qj_emlrtRTEI, &st, r.size(1));
                  loop_ub = r.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    c_idx[i] = r[i];
                  }

                  varargin_2.set_size(&rj_emlrtRTEI, &st, firstCoord.size(1));
                  loop_ub = firstCoord.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    varargin_2[i] = firstCoord[i];
                  }

                  b_st.site = &kn_emlrtRSI;
                  c_st.site = &ln_emlrtRSI;
                  if (varargin_2.size(0) != c_idx.size(0)) {
                    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                      "MATLAB:catenate:matrixDimensionMismatch",
                      "MATLAB:catenate:matrixDimensionMismatch", 0);
                  }

                  dataPts.set_size(&sj_emlrtRTEI, &b_st, c_idx.size(0), 2);
                  loop_ub = c_idx.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    dataPts[i] = c_idx[i];
                  }

                  loop_ub = varargin_2.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    dataPts[i + dataPts.size(0)] = varargin_2[i];
                  }
                }

                b_loop_ub = dists.size(0) - 1;
                last = 0;
                for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                  if (dists[b_i] < radius) {
                    last++;
                  }
                }

                r1.set_size(&nj_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                  if (dists[b_i] < radius) {
                    r1[last] = b_i + 1;
                    last++;
                  }
                }

                last = Points.size(0);
                loop_ub = Points.size(1);
                queryPts.set_size(&wj_emlrtRTEI, sp, r1.size(0), loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_loop_ub = r1.size(0);
                  for (i1 = 0; i1 < b_loop_ub; i1++) {
                    if (r1[i1] > remIdx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(r1[i1], 1, remIdx.size(1),
                        &ji_emlrtBCI, (emlrtCTX)sp);
                    }

                    b_idx = static_cast<int32_T>(remIdx[r1[i1] - 1]);
                    if ((b_idx < 1) || (b_idx > last)) {
                      emlrtDynamicBoundsCheckR2012b(b_idx, 1, last, &ii_emlrtBCI,
                        (emlrtCTX)sp);
                    }

                    queryPts[i1 + queryPts.size(0) * i] = Points[(b_idx +
                      Points.size(0) * i) - 1];
                  }
                }

                dist.set_size(&xj_emlrtRTEI, sp, queryPts.size(0));
                i = queryPts.size(0);
                for (b_i = 0; b_i < i; b_i++) {
                  real32_T ex;
                  if (b_i + 1 > queryPts.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, queryPts.size(0),
                      &fi_emlrtBCI, (emlrtCTX)sp);
                  }

                  loop_ub = queryPts.size(1);
                  b_queryPts.set_size(&yj_emlrtRTEI, sp, 1, queryPts.size(1));
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_queryPts[i1] = queryPts[b_i + queryPts.size(0) * i1];
                  }

                  st.site = &km_emlrtRSI;
                  repmat(&st, b_queryPts, static_cast<real_T>(dataPts.size(0)),
                         currPt);
                  iv[0] = (*(int32_T (*)[2])dataPts.size())[0];
                  iv[1] = (*(int32_T (*)[2])dataPts.size())[1];
                  iv1[0] = (*(int32_T (*)[2])currPt.size())[0];
                  iv1[1] = (*(int32_T (*)[2])currPt.size())[1];
                  emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &sb_emlrtECI,
                    (emlrtCTX)sp);
                  st.site = &lm_emlrtRSI;
                  b_dataPts.set_size(&ak_emlrtRTEI, &st, dataPts.size(0), 2);
                  loop_ub = dataPts.size(0) * 2;
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    b_dataPts[i1] = static_cast<real32_T>(dataPts[i1]) -
                      currPt[i1];
                  }

                  b_st.site = &lm_emlrtRSI;
                  b_power(&b_st, b_dataPts, diffs);
                  b_st.site = &lm_emlrtRSI;
                  sum(&b_st, diffs, b_diffs);
                  b_st.site = &tn_emlrtRSI;
                  c_st.site = &un_emlrtRSI;
                  d_st.site = &vn_emlrtRSI;
                  if (b_diffs.size(0) < 1) {
                    emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                      "Coder:toolbox:eml_min_or_max_varDimZero",
                      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }

                  e_st.site = &wn_emlrtRSI;
                  f_st.site = &xn_emlrtRSI;
                  last = b_diffs.size(0);
                  if (b_diffs.size(0) <= 2) {
                    if (b_diffs.size(0) == 1) {
                      ex = b_diffs[0];
                    } else if ((b_diffs[0] > b_diffs[1]) || (muSingleScalarIsNaN
                                (b_diffs[0]) && (!muSingleScalarIsNaN(b_diffs[1]))))
                    {
                      ex = b_diffs[1];
                    } else {
                      ex = b_diffs[0];
                    }
                  } else {
                    g_st.site = &ae_emlrtRSI;
                    if (!muSingleScalarIsNaN(b_diffs[0])) {
                      b_idx = 1;
                    } else {
                      b_idx = 0;
                      h_st.site = &be_emlrtRSI;
                      if (b_diffs.size(0) > 2147483646) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      loop_ub = 2;
                      exitg1 = false;
                      while ((!exitg1) && (loop_ub <= last)) {
                        if (!muSingleScalarIsNaN(b_diffs[loop_ub - 1])) {
                          b_idx = loop_ub;
                          exitg1 = true;
                        } else {
                          loop_ub++;
                        }
                      }
                    }

                    if (b_idx == 0) {
                      ex = b_diffs[0];
                    } else {
                      g_st.site = &yd_emlrtRSI;
                      ex = b_diffs[b_idx - 1];
                      b_loop_ub = b_idx + 1;
                      h_st.site = &ce_emlrtRSI;
                      if ((b_idx + 1 <= b_diffs.size(0)) && (b_diffs.size(0) >
                           2147483646)) {
                        i_st.site = &qc_emlrtRSI;
                        check_forloop_overflow_error(&i_st);
                      }

                      for (loop_ub = b_loop_ub; loop_ub <= last; loop_ub++) {
                        real32_T f;
                        f = b_diffs[loop_ub - 1];
                        if (ex > f) {
                          ex = f;
                        }
                      }
                    }
                  }

                  st.site = &lm_emlrtRSI;
                  if (ex < 0.0F) {
                    emlrtErrorWithMessageIdR2018a(&st, &u_emlrtRTEI,
                      "Coder:toolbox:ElFunDomainError",
                      "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
                  }

                  ex = muSingleScalarSqrt(ex);
                  if (b_i + 1 > dist.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dist.size(0),
                      &li_emlrtBCI, (emlrtCTX)sp);
                  }

                  dist[b_i] = ex;
                }

                st.site = &mm_emlrtRSI;
                b_st.site = &vh_emlrtRSI;
                c_st.site = &wh_emlrtRSI;
                d_st.site = &xh_emlrtRSI;
                if (dist.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &yh_emlrtRSI;
                last = dist.size(0);
                if (dist.size(0) <= 2) {
                  if (dist.size(0) == 1) {
                    b_idx = 1;
                  } else if ((dist[0] > dist[1]) || (muDoubleScalarIsNaN(dist[0])
                              && (!muDoubleScalarIsNaN(dist[1])))) {
                    b_idx = 2;
                  } else {
                    b_idx = 1;
                  }
                } else {
                  f_st.site = &ae_emlrtRSI;
                  if (!muDoubleScalarIsNaN(dist[0])) {
                    b_idx = 1;
                  } else {
                    b_idx = 0;
                    g_st.site = &be_emlrtRSI;
                    if (dist.size(0) > 2147483646) {
                      h_st.site = &qc_emlrtRSI;
                      check_forloop_overflow_error(&h_st);
                    }

                    loop_ub = 2;
                    exitg1 = false;
                    while ((!exitg1) && (loop_ub <= last)) {
                      if (!muDoubleScalarIsNaN(dist[loop_ub - 1])) {
                        b_idx = loop_ub;
                        exitg1 = true;
                      } else {
                        loop_ub++;
                      }
                    }
                  }

                  if (b_idx == 0) {
                    b_idx = 1;
                  } else {
                    f_st.site = &yd_emlrtRSI;
                    a_tmp = dist[b_idx - 1];
                    b_loop_ub = b_idx + 1;
                    g_st.site = &ce_emlrtRSI;
                    if ((b_idx + 1 <= dist.size(0)) && (dist.size(0) >
                         2147483646)) {
                      h_st.site = &qc_emlrtRSI;
                      check_forloop_overflow_error(&h_st);
                    }

                    for (loop_ub = b_loop_ub; loop_ub <= last; loop_ub++) {
                      a = dist[loop_ub - 1];
                      if (a_tmp > a) {
                        a_tmp = a;
                        b_idx = loop_ub;
                      }
                    }
                  }
                }

                st.site = &nm_emlrtRSI;
                s.set_size(&lj_emlrtRTEI, &st, dists.size(0));
                loop_ub = dists.size(0);
                for (i = 0; i < loop_ub; i++) {
                  s[i] = (dists[i] < radius);
                }

                b_st.site = &se_emlrtRSI;
                c_eml_find(&b_st, s, static_cast<real_T>(b_idx), ii);
                c_idx.set_size(&bk_emlrtRTEI, &st, ii.size(0));
                loop_ub = ii.size(0);
                for (i = 0; i < loop_ub; i++) {
                  c_idx[i] = ii[i];
                }

                idx.set_size(&ck_emlrtRTEI, sp, 1, 1);
                if (c_idx.size(0) < 1) {
                  emlrtDynamicBoundsCheckR2012b(c_idx.size(0), 1, c_idx.size(0),
                    &ki_emlrtBCI, (emlrtCTX)sp);
                }

                i = static_cast<int32_T>(c_idx[c_idx.size(0) - 1]);
                if ((i < 1) || (i > remIdx.size(1))) {
                  emlrtDynamicBoundsCheckR2012b(i, 1, remIdx.size(1),
                    &ki_emlrtBCI, (emlrtCTX)sp);
                }

                idx[0] = remIdx[i - 1];
              } else {
                s.set_size(&lj_emlrtRTEI, sp, dists.size(0));
                loop_ub = dists.size(0);
                for (i = 0; i < loop_ub; i++) {
                  s[i] = (dists[i] < radius);
                }

                last = 0;
                i = s.size(0);
                for (loop_ub = 0; loop_ub < i; loop_ub++) {
                  if (s[loop_ub]) {
                    last++;
                  }
                }

                if (last == 1) {
                  int32_T b_i;
                  b_loop_ub = dists.size(0) - 1;
                  last = 0;
                  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                    if (dists[b_i] < radius) {
                      last++;
                    }
                  }

                  r1.set_size(&nj_emlrtRTEI, sp, last);
                  last = 0;
                  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                    if (dists[b_i] < radius) {
                      r1[last] = b_i + 1;
                      last++;
                    }
                  }

                  idx.set_size(&oj_emlrtRTEI, sp, 1, r1.size(0));
                  loop_ub = r1.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    if (r1[i] > remIdx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(r1[i], 1, remIdx.size(1),
                        &hi_emlrtBCI, (emlrtCTX)sp);
                    }

                    idx[i] = remIdx[r1[i] - 1];
                  }
                } else {
                  idx.set_size(&mj_emlrtRTEI, sp, 1, 0);
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            real_T Checkerboard::findNeighbor(const emlrtStack *sp, const ::
              coder::array<real32_T, 2U> &pointVectors, const ::coder::array<
              real32_T, 1U> &euclideanDists, const real32_T v[2]) const
            {
              ptrdiff_t k_t;
              ptrdiff_t lda_t;
              ptrdiff_t ldb_t;
              ptrdiff_t ldc_t;
              ptrdiff_t m_t;
              ptrdiff_t n_t;
              ::coder::array<int32_T, 1U> r1;
              ::coder::array<int32_T, 1U> r2;
              ::coder::array<real32_T, 1U> angleCosines;
              ::coder::array<real32_T, 1U> dists;
              ::coder::array<boolean_T, 2U> r;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack st;
              real_T neighborIdx;
              int32_T end;
              int32_T i;
              int32_T last;
              real32_T alpha1;
              real32_T beta1;
              char_T TRANSA1;
              char_T TRANSB1;
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
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              st.site = &nh_emlrtRSI;
              b_st.site = &qh_emlrtRSI;
              if (pointVectors.size(1) != 2) {
                if ((pointVectors.size(0) == 1) && (pointVectors.size(1) == 1))
                {
                  emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
                    "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                    "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
                } else {
                  emlrtErrorWithMessageIdR2018a(&b_st, &ab_emlrtRTEI,
                    "MATLAB:innerdim", "MATLAB:innerdim", 0);
                }
              }

              b_st.site = &ph_emlrtRSI;
              if (pointVectors.size(0) == 0) {
                angleCosines.set_size(&rg_emlrtRTEI, &b_st, 0);
              } else {
                c_st.site = &rh_emlrtRSI;
                d_st.site = &sh_emlrtRSI;
                TRANSB1 = 'T';
                TRANSA1 = 'N';
                alpha1 = 1.0F;
                beta1 = 0.0F;
                m_t = (ptrdiff_t)pointVectors.size(0);
                n_t = (ptrdiff_t)1;
                k_t = (ptrdiff_t)2;
                lda_t = (ptrdiff_t)pointVectors.size(0);
                ldb_t = (ptrdiff_t)1;
                ldc_t = (ptrdiff_t)pointVectors.size(0);
                angleCosines.set_size(&qg_emlrtRTEI, &d_st, pointVectors.size(0));
                sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((::coder::
                         array<real32_T, 2U> *)&pointVectors)->data())[0],
                      &lda_t, (real32_T *)&v[0], &ldb_t, &beta1,
                      &(angleCosines.data())[0], &ldc_t);
              }

              alpha1 = muSingleScalarHypot(v[0], v[1]);
              dists.set_size(&sg_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = euclideanDists[i] * alpha1;
              }

              st.site = &nh_emlrtRSI;
              b_st.site = &th_emlrtRSI;
              c_st.site = &uh_emlrtRSI;
              if (angleCosines.size(0) != dists.size(0)) {
                emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                  "MATLAB:dimagree", "MATLAB:dimagree", 0);
              }

              last = angleCosines.size(0);
              for (i = 0; i < last; i++) {
                angleCosines[i] = angleCosines[i] / dists[i];
              }

              dists.set_size(&tg_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = 1.5F * euclideanDists[i];
              }

              if (dists.size(0) != angleCosines.size(0)) {
                emlrtSizeEqCheck1DR2012b(dists.size(0), angleCosines.size(0),
                  &hb_emlrtECI, (emlrtCTX)sp);
              }

              last = dists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = dists[i] * (1.0F - angleCosines[i]);
              }

              if (euclideanDists.size(0) != dists.size(0)) {
                emlrtSizeEqCheck1DR2012b(euclideanDists.size(0), dists.size(0),
                  &gb_emlrtECI, (emlrtCTX)sp);
              }

              dists.set_size(&ug_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = euclideanDists[i] + dists[i];
              }

              r.set_size(&vg_emlrtRTEI, sp, BoardIdx.size(0), BoardIdx.size(1));
              last = BoardIdx.size(0) * BoardIdx.size(1);
              for (i = 0; i < last; i++) {
                r[i] = (BoardIdx[i] > 0.0);
              }

              end = r.size(0) * r.size(1) - 1;
              last = 0;
              for (i = 0; i <= end; i++) {
                if (r[i]) {
                  last++;
                }
              }

              r1.set_size(&wg_emlrtRTEI, sp, last);
              last = 0;
              for (i = 0; i <= end; i++) {
                if (r[i]) {
                  r1[last] = i + 1;
                  last++;
                }
              }

              end = BoardIdx.size(0) * BoardIdx.size(1);
              r2.set_size(&xg_emlrtRTEI, sp, r1.size(0));
              last = r1.size(0);
              for (i = 0; i < last; i++) {
                real_T d;
                if ((r1[i] < 1) || (r1[i] > end)) {
                  emlrtDynamicBoundsCheckR2012b(r1[i], 1, end, &af_emlrtBCI,
                    (emlrtCTX)sp);
                }

                d = BoardIdx[r1[i] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &n_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     dists.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    dists.size(0), &bf_emlrtBCI, (emlrtCTX)sp);
                }

                r2[i] = static_cast<int32_T>(d);
              }

              last = r2.size(0);
              for (i = 0; i < last; i++) {
                dists[r2[i] - 1] = rtInfF;
              }

              end = angleCosines.size(0);
              for (i = 0; i < end; i++) {
                if (angleCosines[i] < 0.0F) {
                  if (i + 1 > dists.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(i + 1, 1, dists.size(0),
                      &cf_emlrtBCI, (emlrtCTX)sp);
                  }

                  dists[i] = rtInfF;
                }
              }

              st.site = &oh_emlrtRSI;
              b_st.site = &vh_emlrtRSI;
              c_st.site = &wh_emlrtRSI;
              d_st.site = &xh_emlrtRSI;
              if (dists.size(0) < 1) {
                emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                  "Coder:toolbox:eml_min_or_max_varDimZero",
                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
              }

              e_st.site = &yh_emlrtRSI;
              last = dists.size(0);
              if (dists.size(0) <= 2) {
                if (dists.size(0) == 1) {
                  alpha1 = dists[0];
                  end = 1;
                } else if ((dists[0] > dists[1]) || (muSingleScalarIsNaN(dists[0])
                            && (!muSingleScalarIsNaN(dists[1])))) {
                  alpha1 = dists[1];
                  end = 2;
                } else {
                  alpha1 = dists[0];
                  end = 1;
                }
              } else {
                int32_T k;
                f_st.site = &ae_emlrtRSI;
                if (!muSingleScalarIsNaN(dists[0])) {
                  end = 1;
                } else {
                  boolean_T exitg1;
                  end = 0;
                  g_st.site = &be_emlrtRSI;
                  if (dists.size(0) > 2147483646) {
                    h_st.site = &qc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  k = 2;
                  exitg1 = false;
                  while ((!exitg1) && (k <= last)) {
                    if (!muSingleScalarIsNaN(dists[k - 1])) {
                      end = k;
                      exitg1 = true;
                    } else {
                      k++;
                    }
                  }
                }

                if (end == 0) {
                  alpha1 = dists[0];
                  end = 1;
                } else {
                  f_st.site = &yd_emlrtRSI;
                  alpha1 = dists[end - 1];
                  i = end + 1;
                  g_st.site = &ce_emlrtRSI;
                  if ((end + 1 <= dists.size(0)) && (dists.size(0) > 2147483646))
                  {
                    h_st.site = &qc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (k = i; k <= last; k++) {
                    beta1 = dists[k - 1];
                    if (alpha1 > beta1) {
                      alpha1 = beta1;
                      end = k;
                    }
                  }
                }
              }

              neighborIdx = end;
              if (muSingleScalarIsInf(alpha1)) {
                neighborIdx = -1.0;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return neighborIdx;
            }

            real_T Checkerboard::findNeighbor(const emlrtStack *sp, const ::
              coder::array<real32_T, 2U> &pointVectors, const ::coder::array<
              real32_T, 1U> &euclideanDists, const ::coder::array<real32_T, 2U>
              &v) const
            {
              ptrdiff_t k_t;
              ptrdiff_t lda_t;
              ptrdiff_t ldb_t;
              ptrdiff_t ldc_t;
              ptrdiff_t m_t;
              ptrdiff_t n_t;
              ::coder::array<int32_T, 1U> r1;
              ::coder::array<int32_T, 1U> r2;
              ::coder::array<real32_T, 1U> angleCosines;
              ::coder::array<real32_T, 1U> dists;
              ::coder::array<boolean_T, 2U> r;
              emlrtStack b_st;
              emlrtStack c_st;
              emlrtStack d_st;
              emlrtStack e_st;
              emlrtStack f_st;
              emlrtStack g_st;
              emlrtStack h_st;
              emlrtStack st;
              real_T neighborIdx;
              int32_T end;
              int32_T i;
              int32_T last;
              real32_T alpha1;
              real32_T beta1;
              char_T TRANSA1;
              char_T TRANSB1;
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
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              if (1 > v.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, v.size(1), &ef_emlrtBCI,
                  (emlrtCTX)sp);
              }

              if (2 > v.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, v.size(1), &df_emlrtBCI,
                  (emlrtCTX)sp);
              }

              st.site = &nh_emlrtRSI;
              b_st.site = &qh_emlrtRSI;
              if (pointVectors.size(1) != v.size(1)) {
                if (((pointVectors.size(0) == 1) && (pointVectors.size(1) == 1))
                    || (v.size(1) == 1)) {
                  emlrtErrorWithMessageIdR2018a(&b_st, &y_emlrtRTEI,
                    "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                    "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
                } else {
                  emlrtErrorWithMessageIdR2018a(&b_st, &ab_emlrtRTEI,
                    "MATLAB:innerdim", "MATLAB:innerdim", 0);
                }
              }

              b_st.site = &ph_emlrtRSI;
              if ((pointVectors.size(0) == 0) || (pointVectors.size(1) == 0) ||
                  (v.size(1) == 0)) {
                angleCosines.set_size(&rg_emlrtRTEI, &b_st, pointVectors.size(0));
                last = pointVectors.size(0);
                for (i = 0; i < last; i++) {
                  angleCosines[i] = 0.0F;
                }
              } else {
                c_st.site = &rh_emlrtRSI;
                d_st.site = &sh_emlrtRSI;
                TRANSB1 = 'T';
                TRANSA1 = 'N';
                alpha1 = 1.0F;
                beta1 = 0.0F;
                m_t = (ptrdiff_t)pointVectors.size(0);
                n_t = (ptrdiff_t)1;
                k_t = (ptrdiff_t)pointVectors.size(1);
                lda_t = (ptrdiff_t)pointVectors.size(0);
                ldb_t = (ptrdiff_t)1;
                ldc_t = (ptrdiff_t)pointVectors.size(0);
                angleCosines.set_size(&qg_emlrtRTEI, &d_st, pointVectors.size(0));
                sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((::coder::
                         array<real32_T, 2U> *)&pointVectors)->data())[0],
                      &lda_t, (real32_T *)&v[0], &ldb_t, &beta1,
                      &(angleCosines.data())[0], &ldc_t);
              }

              alpha1 = muSingleScalarHypot(v[0], v[1]);
              dists.set_size(&sg_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = euclideanDists[i] * alpha1;
              }

              st.site = &nh_emlrtRSI;
              b_st.site = &th_emlrtRSI;
              c_st.site = &uh_emlrtRSI;
              if (angleCosines.size(0) != dists.size(0)) {
                emlrtErrorWithMessageIdR2018a(&c_st, &x_emlrtRTEI,
                  "MATLAB:dimagree", "MATLAB:dimagree", 0);
              }

              last = angleCosines.size(0);
              for (i = 0; i < last; i++) {
                angleCosines[i] = angleCosines[i] / dists[i];
              }

              dists.set_size(&tg_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = 1.5F * euclideanDists[i];
              }

              if (dists.size(0) != angleCosines.size(0)) {
                emlrtSizeEqCheck1DR2012b(dists.size(0), angleCosines.size(0),
                  &hb_emlrtECI, (emlrtCTX)sp);
              }

              last = dists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = dists[i] * (1.0F - angleCosines[i]);
              }

              if (euclideanDists.size(0) != dists.size(0)) {
                emlrtSizeEqCheck1DR2012b(euclideanDists.size(0), dists.size(0),
                  &gb_emlrtECI, (emlrtCTX)sp);
              }

              dists.set_size(&ug_emlrtRTEI, sp, euclideanDists.size(0));
              last = euclideanDists.size(0);
              for (i = 0; i < last; i++) {
                dists[i] = euclideanDists[i] + dists[i];
              }

              r.set_size(&vg_emlrtRTEI, sp, BoardIdx.size(0), BoardIdx.size(1));
              last = BoardIdx.size(0) * BoardIdx.size(1);
              for (i = 0; i < last; i++) {
                r[i] = (BoardIdx[i] > 0.0);
              }

              end = r.size(0) * r.size(1) - 1;
              last = 0;
              for (i = 0; i <= end; i++) {
                if (r[i]) {
                  last++;
                }
              }

              r1.set_size(&wg_emlrtRTEI, sp, last);
              last = 0;
              for (i = 0; i <= end; i++) {
                if (r[i]) {
                  r1[last] = i + 1;
                  last++;
                }
              }

              end = BoardIdx.size(0) * BoardIdx.size(1);
              r2.set_size(&xg_emlrtRTEI, sp, r1.size(0));
              last = r1.size(0);
              for (i = 0; i < last; i++) {
                real_T d;
                if ((r1[i] < 1) || (r1[i] > end)) {
                  emlrtDynamicBoundsCheckR2012b(r1[i], 1, end, &af_emlrtBCI,
                    (emlrtCTX)sp);
                }

                d = BoardIdx[r1[i] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &n_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     dists.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    dists.size(0), &bf_emlrtBCI, (emlrtCTX)sp);
                }

                r2[i] = static_cast<int32_T>(d);
              }

              last = r2.size(0);
              for (i = 0; i < last; i++) {
                dists[r2[i] - 1] = rtInfF;
              }

              end = angleCosines.size(0);
              for (i = 0; i < end; i++) {
                if (angleCosines[i] < 0.0F) {
                  if (i + 1 > dists.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(i + 1, 1, dists.size(0),
                      &cf_emlrtBCI, (emlrtCTX)sp);
                  }

                  dists[i] = rtInfF;
                }
              }

              st.site = &oh_emlrtRSI;
              b_st.site = &vh_emlrtRSI;
              c_st.site = &wh_emlrtRSI;
              d_st.site = &xh_emlrtRSI;
              if (dists.size(0) < 1) {
                emlrtErrorWithMessageIdR2018a(&d_st, &o_emlrtRTEI,
                  "Coder:toolbox:eml_min_or_max_varDimZero",
                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
              }

              e_st.site = &yh_emlrtRSI;
              last = dists.size(0);
              if (dists.size(0) <= 2) {
                if (dists.size(0) == 1) {
                  alpha1 = dists[0];
                  end = 1;
                } else if ((dists[0] > dists[1]) || (muSingleScalarIsNaN(dists[0])
                            && (!muSingleScalarIsNaN(dists[1])))) {
                  alpha1 = dists[1];
                  end = 2;
                } else {
                  alpha1 = dists[0];
                  end = 1;
                }
              } else {
                int32_T k;
                f_st.site = &ae_emlrtRSI;
                if (!muSingleScalarIsNaN(dists[0])) {
                  end = 1;
                } else {
                  boolean_T exitg1;
                  end = 0;
                  g_st.site = &be_emlrtRSI;
                  if (dists.size(0) > 2147483646) {
                    h_st.site = &qc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  k = 2;
                  exitg1 = false;
                  while ((!exitg1) && (k <= last)) {
                    if (!muSingleScalarIsNaN(dists[k - 1])) {
                      end = k;
                      exitg1 = true;
                    } else {
                      k++;
                    }
                  }
                }

                if (end == 0) {
                  alpha1 = dists[0];
                  end = 1;
                } else {
                  f_st.site = &yd_emlrtRSI;
                  alpha1 = dists[end - 1];
                  i = end + 1;
                  g_st.site = &ce_emlrtRSI;
                  if ((end + 1 <= dists.size(0)) && (dists.size(0) > 2147483646))
                  {
                    h_st.site = &qc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (k = i; k <= last; k++) {
                    beta1 = dists[k - 1];
                    if (alpha1 > beta1) {
                      alpha1 = beta1;
                      end = k;
                    }
                  }
                }
              }

              neighborIdx = end;
              if (muSingleScalarIsInf(alpha1)) {
                neighborIdx = -1.0;
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
              return neighborIdx;
            }

            void Checkerboard::fitPolynomialIndices(const emlrtStack *sp, ::
              coder::array<real_T, 2U> &newIndices) const
            {
              ::coder::array<real_T, 2U> b_index;
              ::coder::array<real_T, 2U> b_removedIdx;
              ::coder::array<real_T, 2U> removedIdx;
              ::coder::array<real_T, 1U> b_this;
              ::coder::array<real_T, 1U> d_this;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              ::coder::array<int32_T, 2U> r4;
              ::coder::array<int32_T, 2U> r5;
              ::coder::array<int32_T, 1U> ii;
              ::coder::array<boolean_T, 2U> r;
              ::coder::array<boolean_T, 2U> r1;
              emlrtStack b_st;
              emlrtStack st;
              real_T currCurve_data[5];
              real_T coordsToUse[2];
              real_T currPt[2];
              real_T currRad;
              real_T x;
              int32_T currCurve_size[2];
              int32_T iv[2];
              int32_T b_i;
              int32_T end;
              int32_T i;
              int32_T loop_ub;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              st.site = &yj_emlrtRSI;
              i = BoardIdx.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ah_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&ni_emlrtRTEI, &st, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
              }

              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &bh_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(1);
              r1.set_size(&oi_emlrtRTEI, &st, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r1[i] = (BoardIdx[BoardIdx.size(0) * i + 1] > 0.0);
              }

              currCurve_size[0] = (*(int32_T (*)[2])r.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])r.size())[1];
              iv[0] = (*(int32_T (*)[2])r1.size())[0];
              iv[1] = (*(int32_T (*)[2])r1.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &pb_emlrtECI,
                &st);
              i = BoardCoords.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &ch_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &dh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r2.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r2[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              removedIdx.set_size(&qi_emlrtRTEI, &st, 1, r2.size(1));
              loop_ub = r2.size(1);
              for (i = 0; i < loop_ub; i++) {
                if (r2[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r2[i], 1, b_i, &uh_emlrtBCI, &st);
                }

                removedIdx[i] = BoardCoords[BoardCoords.size(0) * (r2[i] - 1) +
                  1];
              }

              i = BoardCoords.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &eh_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &fh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r3.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r3[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              b_index.set_size(&ri_emlrtRTEI, &st, 1, r3.size(1));
              loop_ub = r3.size(1);
              for (i = 0; i < loop_ub; i++) {
                if (r3[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r3[i], 1, b_i, &vh_emlrtBCI, &st);
                }

                b_index[i] = BoardCoords[BoardCoords.size(0) * (r3[i] - 1)];
              }

              currCurve_size[0] = (*(int32_T (*)[2])removedIdx.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])removedIdx.size())[1];
              iv[0] = (*(int32_T (*)[2])b_index.size())[0];
              iv[1] = (*(int32_T (*)[2])b_index.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &qb_emlrtECI,
                &st);
              b_removedIdx.set_size(&qi_emlrtRTEI, &st, 1, removedIdx.size(1));
              loop_ub = removedIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_removedIdx[i] = removedIdx[i] - b_index[i];
              }

              b_st.site = &ek_emlrtRSI;
              x = mean(&b_st, b_removedIdx);
              i = BoardCoords.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &gh_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &hh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r4.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r4[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              removedIdx.set_size(&si_emlrtRTEI, &st, 1, r4.size(1));
              loop_ub = r4.size(1);
              for (i = 0; i < loop_ub; i++) {
                if (r4[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r4[i], 1, b_i, &wh_emlrtBCI, &st);
                }

                removedIdx[i] = BoardCoords[(BoardCoords.size(0) * (r4[i] - 1) +
                  BoardCoords.size(0) * BoardCoords.size(1)) + 1];
              }

              i = BoardCoords.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ih_emlrtBCI, &st);
              }

              i = BoardCoords.size(2);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &jh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r5.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r5[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              b_index.set_size(&ti_emlrtRTEI, &st, 1, r5.size(1));
              loop_ub = r5.size(1);
              for (i = 0; i < loop_ub; i++) {
                if (r5[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r5[i], 1, b_i, &xh_emlrtBCI, &st);
                }

                b_index[i] = BoardCoords[BoardCoords.size(0) * (r5[i] - 1) +
                  BoardCoords.size(0) * BoardCoords.size(1)];
              }

              currCurve_size[0] = (*(int32_T (*)[2])removedIdx.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])removedIdx.size())[1];
              iv[0] = (*(int32_T (*)[2])b_index.size())[0];
              iv[1] = (*(int32_T (*)[2])b_index.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &rb_emlrtECI,
                &st);
              b_removedIdx.set_size(&si_emlrtRTEI, &st, 1, removedIdx.size(1));
              loop_ub = removedIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_removedIdx[i] = removedIdx[i] - b_index[i];
              }

              b_st.site = &fk_emlrtRSI;
              currRad = mean(&b_st, b_removedIdx);
              if (muDoubleScalarAbs(x) > muDoubleScalarAbs(currRad)) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }

              newIndices.set_size(&ui_emlrtRTEI, sp, 1, BoardCoords.size(1));
              loop_ub = BoardCoords.size(1);
              for (i = 0; i < loop_ub; i++) {
                newIndices[i] = 0.0;
              }

              removedIdx.set_size(&vi_emlrtRTEI, sp, 1, 0);
              i = BoardCoords.size(1);
              for (int32_T j{0}; j < i; j++) {
                int32_T i1;
                int32_T i2;
                st.site = &ak_emlrtRSI;
                i1 = BoardCoords.size(1);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &xg_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(2);
                i2 = static_cast<int32_T>(coordsToUse[0]);
                if (i2 > i1) {
                  emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &yg_emlrtBCI, &st);
                }

                loop_ub = BoardCoords.size(0);
                b_this.set_size(&wi_emlrtRTEI, &st, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_this[i1] = BoardCoords[(i1 + BoardCoords.size(0) * j) +
                    BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                }

                b_st.site = &se_emlrtRSI;
                b_eml_find(&b_st, b_this, ii);
                if (ii.size(0) >= 2) {
                  real_T currCoord;
                  real_T refCoordValue;
                  int32_T c_this;
                  int32_T n;
                  boolean_T exitg1;
                  st.site = &bk_emlrtRSI;
                  i1 = BoardCoords.size(0);
                  if ((ii[0] < 1) || (ii[0] > i1)) {
                    emlrtDynamicBoundsCheckR2012b(ii[0], 1, i1, &ph_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &oh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &nh_emlrtBCI, &st);
                  }

                  i1 = BoardCoords.size(0);
                  if ((ii[1] < 1) || (ii[1] > i1)) {
                    emlrtDynamicBoundsCheckR2012b(ii[1], 1, i1, &mh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &lh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &kh_emlrtBCI, &st);
                  }

                  x = (BoardCoords[((ii[0] + BoardCoords.size(0) * j) +
                                    BoardCoords.size(0) * BoardCoords.size(1) *
                                    (i2 - 1)) - 1] - BoardCoords[((ii[1] +
                         BoardCoords.size(0) * j) + BoardCoords.size(0) *
                        BoardCoords.size(1) * (i2 - 1)) - 1]) /
                    (static_cast<real_T>(ii[1]) - static_cast<real_T>(ii[0]));
                  st.site = &ck_emlrtRSI;
                  n = 0;
                  i1 = ii.size(0);
                  for (end = 0; end < i1; end++) {
                    if (ii[end] != 0) {
                      n++;
                    }
                  }

                  b_i = BoardCoords.size(0);
                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &qh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &rh_emlrtBCI, &st);
                  }

                  c_this = BoardCoords.size(0);
                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &sh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  end = static_cast<int32_T>(coordsToUse[1]);
                  if (end > i1) {
                    emlrtDynamicBoundsCheckR2012b(end, 1, i1, &th_emlrtBCI, &st);
                  }

                  b_this.set_size(&xi_emlrtRTEI, &st, ii.size(0));
                  loop_ub = ii.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > b_i)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, b_i, &yh_emlrtBCI,
                        &st);
                    }

                    b_this[i1] = BoardCoords[((ii[i1] + BoardCoords.size(0) * j)
                      + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)) -
                      1];
                  }

                  d_this.set_size(&yi_emlrtRTEI, &st, ii.size(0));
                  loop_ub = ii.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > c_this)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, c_this,
                        &ai_emlrtBCI, &st);
                    }

                    d_this[i1] = BoardCoords[((ii[i1] + BoardCoords.size(0) * j)
                      + BoardCoords.size(0) * BoardCoords.size(1) * (
                      static_cast<int32_T>(coordsToUse[1]) - 1)) - 1];
                  }

                  if (n > 5) {
                    n = 4;
                  } else {
                    n = 2;
                  }

                  b_st.site = &tk_emlrtRSI;
                  polyfit(&b_st, b_this, d_this, static_cast<real_T>(n),
                          currCurve_data, currCurve_size);
                  currRad = x / 4.0;
                  i1 = BoardCoords.size(0);
                  if ((ii[0] < 1) || (ii[0] > i1)) {
                    emlrtDynamicBoundsCheckR2012b(ii[0], 1, i1, &bi_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &ci_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &di_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  refCoordValue = BoardCoords[((ii[0] + BoardCoords.size(0) * j)
                    + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)) - 1];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (muDoubleScalarAbs(currCoord -
                           refCoordValue) < static_cast<real_T>(ii[0]) * 1.5 *
                                       muDoubleScalarAbs(x))) {
                    boolean_T exitg2;
                    boolean_T p;
                    p = true;
                    end = 0;
                    exitg2 = false;
                    while ((!exitg2) && (end < 2)) {
                      if (static_cast<int32_T>(coordsToUse[end]) != end + 1) {
                        p = false;
                        exitg2 = true;
                      } else {
                        end++;
                      }
                    }

                    if (p) {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = currCoord;
                      currPt[1] = y;
                    } else {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    st.site = &dk_emlrtRSI;
                    findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                       currCurve_data, currCurve_size,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      if (1 != b_index.size(1)) {
                        emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                          &ob_emlrtECI, (emlrtCTX)sp);
                      }

                      if ((j + 1 < 1) || (j + 1 > newIndices.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(j + 1, 1, newIndices.size
                          (1), &ei_emlrtBCI, (emlrtCTX)sp);
                      }

                      newIndices[j] = b_index[0];
                      i1 = removedIdx.size(1);
                      loop_ub = b_index.size(1);
                      removedIdx.set_size(&aj_emlrtRTEI, sp, removedIdx.size(0),
                                          removedIdx.size(1) + b_index.size(1));
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        removedIdx[i1 + i2] = b_index[i2];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::fitPolynomialIndices(const emlrtStack *sp, const ::
              coder::array<real_T, 2U> &idx, ::coder::array<real_T, 2U>
              &newIndices) const
            {
              ::coder::array<real_T, 2U> b_index;
              ::coder::array<real_T, 2U> b_removedIdx;
              ::coder::array<real_T, 2U> removedIdx;
              ::coder::array<real_T, 1U> b_this;
              ::coder::array<real_T, 1U> c_this;
              ::coder::array<int32_T, 2U> r2;
              ::coder::array<int32_T, 2U> r3;
              ::coder::array<int32_T, 2U> r4;
              ::coder::array<int32_T, 2U> r5;
              ::coder::array<int32_T, 1U> ii;
              ::coder::array<boolean_T, 2U> r;
              ::coder::array<boolean_T, 2U> r1;
              emlrtStack b_st;
              emlrtStack st;
              real_T currCurve_data[5];
              real_T coordsToUse[2];
              real_T currPt[2];
              real_T b_x;
              real_T x;
              int32_T currCurve_size[2];
              int32_T iv[2];
              int32_T b_i;
              int32_T b_idx;
              int32_T c_idx;
              int32_T end;
              int32_T i;
              int32_T i1;
              int32_T i2;
              int32_T loop_ub;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              st.site = &yj_emlrtRSI;
              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &hk_emlrtBCI,
                  &st);
              }

              i = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &bb_emlrtDCI, &st);
              }

              i1 = BoardIdx.size(0);
              b_idx = static_cast<int32_T>(idx[0]);
              if ((b_idx < 1) || (b_idx > i1)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1,
                  i1, &ah_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(1);
              r.set_size(&ni_emlrtRTEI, &st, 1, loop_ub);
              for (i1 = 0; i1 < loop_ub; i1++) {
                r[i1] = (BoardIdx[(b_idx + BoardIdx.size(0) * i1) - 1] > 0.0);
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ik_emlrtBCI,
                  &st);
              }

              i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &cb_emlrtDCI, &st);
              }

              i2 = BoardIdx.size(0);
              c_idx = static_cast<int32_T>(idx[1]);
              if ((c_idx < 1) || (c_idx > i2)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i2, &bh_emlrtBCI, &st);
              }

              loop_ub = BoardIdx.size(1);
              r1.set_size(&oi_emlrtRTEI, &st, 1, loop_ub);
              for (i2 = 0; i2 < loop_ub; i2++) {
                r1[i2] = (BoardIdx[(c_idx + BoardIdx.size(0) * i2) - 1] > 0.0);
              }

              currCurve_size[0] = (*(int32_T (*)[2])r.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])r.size())[1];
              iv[0] = (*(int32_T (*)[2])r1.size())[0];
              iv[1] = (*(int32_T (*)[2])r1.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &pb_emlrtECI,
                &st);
              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &jk_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (1 > i2) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i2, &dh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r2.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r2[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &db_emlrtDCI, &st);
              }

              i2 = BoardCoords.size(0);
              if (c_idx > i2) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i2, &ch_emlrtBCI, &st);
              }

              removedIdx.set_size(&qi_emlrtRTEI, &st, 1, r2.size(1));
              loop_ub = r2.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                if (r2[i2] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r2[i2], 1, b_i, &uh_emlrtBCI,
                    &st);
                }

                removedIdx[i2] = BoardCoords[(c_idx + BoardCoords.size(0) *
                  (r2[i2] - 1)) - 1];
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &kk_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (1 > i2) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i2, &fh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r3.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r3[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &eb_emlrtDCI, &st);
              }

              i2 = BoardCoords.size(0);
              if (b_idx > i2) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1,
                  i2, &eh_emlrtBCI, &st);
              }

              b_index.set_size(&ri_emlrtRTEI, &st, 1, r3.size(1));
              loop_ub = r3.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                if (r3[i2] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r3[i2], 1, b_i, &vh_emlrtBCI,
                    &st);
                }

                b_index[i2] = BoardCoords[(b_idx + BoardCoords.size(0) * (r3[i2]
                  - 1)) - 1];
              }

              currCurve_size[0] = (*(int32_T (*)[2])removedIdx.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])removedIdx.size())[1];
              iv[0] = (*(int32_T (*)[2])b_index.size())[0];
              iv[1] = (*(int32_T (*)[2])b_index.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &qb_emlrtECI,
                &st);
              b_removedIdx.set_size(&qi_emlrtRTEI, &st, 1, removedIdx.size(1));
              loop_ub = removedIdx.size(1);
              for (i2 = 0; i2 < loop_ub; i2++) {
                b_removedIdx[i2] = removedIdx[i2] - b_index[i2];
              }

              b_st.site = &ek_emlrtRSI;
              x = mean(&b_st, b_removedIdx);
              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &lk_emlrtBCI,
                  &st);
              }

              i2 = BoardCoords.size(2);
              if (2 > i2) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i2, &hh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r4.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r4[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              if (idx[1] != i1) {
                emlrtIntegerCheckR2012b(idx[1], &fb_emlrtDCI, &st);
              }

              i1 = BoardCoords.size(0);
              if (c_idx > i1) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]), 1,
                  i1, &gh_emlrtBCI, &st);
              }

              removedIdx.set_size(&si_emlrtRTEI, &st, 1, r4.size(1));
              loop_ub = r4.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                if (r4[i1] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r4[i1], 1, b_i, &wh_emlrtBCI,
                    &st);
                }

                removedIdx[i1] = BoardCoords[((c_idx + BoardCoords.size(0) *
                  (r4[i1] - 1)) + BoardCoords.size(0) * BoardCoords.size(1)) - 1];
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &mk_emlrtBCI,
                  &st);
              }

              i1 = BoardCoords.size(2);
              if (2 > i1) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i1, &jh_emlrtBCI, &st);
              }

              end = r.size(1) - 1;
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  loop_ub++;
                }
              }

              r5.set_size(&pi_emlrtRTEI, &st, 1, loop_ub);
              loop_ub = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r5[loop_ub] = b_i + 1;
                  loop_ub++;
                }
              }

              b_i = BoardCoords.size(1);
              if (idx[0] != i) {
                emlrtIntegerCheckR2012b(idx[0], &gb_emlrtDCI, &st);
              }

              i = BoardCoords.size(0);
              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]), 1, i,
                  &ih_emlrtBCI, &st);
              }

              b_index.set_size(&ti_emlrtRTEI, &st, 1, r5.size(1));
              loop_ub = r5.size(1);
              for (i = 0; i < loop_ub; i++) {
                if (r5[i] > b_i) {
                  emlrtDynamicBoundsCheckR2012b(r5[i], 1, b_i, &xh_emlrtBCI, &st);
                }

                b_index[i] = BoardCoords[((b_idx + BoardCoords.size(0) * (r5[i]
                  - 1)) + BoardCoords.size(0) * BoardCoords.size(1)) - 1];
              }

              currCurve_size[0] = (*(int32_T (*)[2])removedIdx.size())[0];
              currCurve_size[1] = (*(int32_T (*)[2])removedIdx.size())[1];
              iv[0] = (*(int32_T (*)[2])b_index.size())[0];
              iv[1] = (*(int32_T (*)[2])b_index.size())[1];
              emlrtSizeEqCheckNDR2012b(&currCurve_size[0], &iv[0], &rb_emlrtECI,
                &st);
              b_removedIdx.set_size(&si_emlrtRTEI, &st, 1, removedIdx.size(1));
              loop_ub = removedIdx.size(1);
              for (i = 0; i < loop_ub; i++) {
                b_removedIdx[i] = removedIdx[i] - b_index[i];
              }

              b_st.site = &fk_emlrtRSI;
              b_x = mean(&b_st, b_removedIdx);
              if (muDoubleScalarAbs(x) > muDoubleScalarAbs(b_x)) {
                coordsToUse[0] = 1.0;
                coordsToUse[1] = 2.0;
              } else {
                coordsToUse[0] = 2.0;
                coordsToUse[1] = 1.0;
              }

              newIndices.set_size(&ui_emlrtRTEI, sp, 1, BoardCoords.size(1));
              loop_ub = BoardCoords.size(1);
              for (i = 0; i < loop_ub; i++) {
                newIndices[i] = 0.0;
              }

              removedIdx.set_size(&vi_emlrtRTEI, sp, 1, 0);
              i = BoardCoords.size(1);
              for (int32_T j{0}; j < i; j++) {
                st.site = &ak_emlrtRSI;
                i1 = BoardCoords.size(1);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &xg_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(2);
                i2 = static_cast<int32_T>(coordsToUse[0]);
                if (i2 > i1) {
                  emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &yg_emlrtBCI, &st);
                }

                loop_ub = BoardCoords.size(0);
                b_this.set_size(&wi_emlrtRTEI, &st, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_this[i1] = BoardCoords[(i1 + BoardCoords.size(0) * j) +
                    BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)];
                }

                b_st.site = &se_emlrtRSI;
                b_eml_find(&b_st, b_this, ii);
                if (ii.size(0) >= 2) {
                  real_T currCoord;
                  real_T currRad;
                  real_T refCoordValue;
                  boolean_T exitg1;
                  st.site = &bk_emlrtRSI;
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &tk_emlrtBCI, &st);
                  }

                  if (idx[0] == 1.0) {
                    i1 = BoardCoords.size(0);
                    if ((ii[0] < 1) || (ii[0] > i1)) {
                      emlrtDynamicBoundsCheckR2012b(ii[0], 1, i1, &ph_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &oh_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &nh_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(0);
                    if ((ii[1] < 1) || (ii[1] > i1)) {
                      emlrtDynamicBoundsCheckR2012b(ii[1], 1, i1, &mh_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &lh_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &kh_emlrtBCI, &st);
                    }

                    x = ii[0];
                    b_idx = ii[0];
                    b_x = (BoardCoords[((ii[0] + BoardCoords.size(0) * j) +
                                        BoardCoords.size(0) * BoardCoords.size(1)
                                        * (i2 - 1)) - 1] - BoardCoords[((ii[1] +
                             BoardCoords.size(0) * j) + BoardCoords.size(0) *
                            BoardCoords.size(1) * (i2 - 1)) - 1]) / (
                      static_cast<real_T>(ii[1]) - static_cast<real_T>(ii[0]));
                  } else {
                    i1 = BoardCoords.size(0);
                    loop_ub = ii[ii.size(0) - 1];
                    if ((loop_ub < 1) || (loop_ub > i1)) {
                      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &sk_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &rk_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &qk_emlrtBCI, &st);
                    }

                    i1 = BoardCoords.size(0);
                    if (ii.size(0) - 1 > ii.size(0)) {
                      emlrtDynamicBoundsCheckR2012b(ii.size(0) - 1, 1, ii.size(0),
                        &uk_emlrtBCI, &st);
                    }

                    loop_ub = ii[ii.size(0) - 2];
                    if ((loop_ub < 1) || (loop_ub > i1)) {
                      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &pk_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(1);
                    if ((j + 1 < 1) || (j + 1 > i1)) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &ok_emlrtBCI,
                        &st);
                    }

                    i1 = BoardCoords.size(2);
                    if (i2 > i1) {
                      emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &nk_emlrtBCI, &st);
                    }

                    x = (static_cast<real_T>(BoardCoords.size(0)) - static_cast<
                         real_T>(ii[ii.size(0) - 1])) + 1.0;
                    b_idx = ii[ii.size(0) - 1];
                    if (ii.size(0) - 1 > ii.size(0)) {
                      emlrtDynamicBoundsCheckR2012b(ii.size(0) - 1, 1, ii.size(0),
                        &vk_emlrtBCI, &st);
                    }

                    b_x = (BoardCoords[((ii[ii.size(0) - 1] + BoardCoords.size(0)
                                         * j) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * (i2 - 1)) - 1] -
                           BoardCoords[((ii[ii.size(0) - 2] + BoardCoords.size(0)
                                         * j) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * (i2 - 1)) - 1]) /
                      (static_cast<real_T>(ii[ii.size(0) - 1]) -
                       static_cast<real_T>(ii[ii.size(0) - 2]));
                  }

                  st.site = &ck_emlrtRSI;
                  c_idx = 0;
                  i1 = ii.size(0);
                  for (end = 0; end < i1; end++) {
                    if (ii[end] != 0) {
                      c_idx++;
                    }
                  }

                  b_i = BoardCoords.size(0);
                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &qh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &rh_emlrtBCI, &st);
                  }

                  end = BoardCoords.size(0);
                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &sh_emlrtBCI,
                      &st);
                  }

                  i1 = BoardCoords.size(2);
                  loop_ub = static_cast<int32_T>(coordsToUse[1]);
                  if (loop_ub > i1) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &th_emlrtBCI,
                      &st);
                  }

                  b_this.set_size(&xi_emlrtRTEI, &st, ii.size(0));
                  loop_ub = ii.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > b_i)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, b_i, &yh_emlrtBCI,
                        &st);
                    }

                    b_this[i1] = BoardCoords[((ii[i1] + BoardCoords.size(0) * j)
                      + BoardCoords.size(0) * BoardCoords.size(1) * (
                      static_cast<int32_T>(coordsToUse[0]) - 1)) - 1];
                  }

                  c_this.set_size(&yi_emlrtRTEI, &st, ii.size(0));
                  loop_ub = ii.size(0);
                  for (i1 = 0; i1 < loop_ub; i1++) {
                    if ((ii[i1] < 1) || (ii[i1] > end)) {
                      emlrtDynamicBoundsCheckR2012b(ii[i1], 1, end, &ai_emlrtBCI,
                        &st);
                    }

                    c_this[i1] = BoardCoords[((ii[i1] + BoardCoords.size(0) * j)
                      + BoardCoords.size(0) * BoardCoords.size(1) * (
                      static_cast<int32_T>(coordsToUse[1]) - 1)) - 1];
                  }

                  if (c_idx > 5) {
                    c_idx = 4;
                  } else {
                    c_idx = 2;
                  }

                  b_st.site = &tk_emlrtRSI;
                  polyfit(&b_st, b_this, c_this, static_cast<real_T>(c_idx),
                          currCurve_data, currCurve_size);
                  currRad = b_x / 4.0;
                  i1 = BoardCoords.size(0);
                  if ((b_idx < 1) || (b_idx > i1)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx, 1, i1, &bi_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(1);
                  if ((j + 1 < 1) || (j + 1 > i1)) {
                    emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &ci_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i1 = BoardCoords.size(2);
                  if (i2 > i1) {
                    emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &di_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  refCoordValue = BoardCoords[((b_idx + BoardCoords.size(0) * j)
                    + BoardCoords.size(0) * BoardCoords.size(1) * (i2 - 1)) - 1];
                  currCoord = currRad + refCoordValue;
                  exitg1 = false;
                  while ((!exitg1) && (muDoubleScalarAbs(currCoord -
                           refCoordValue) < x * 1.5 * muDoubleScalarAbs(b_x))) {
                    boolean_T exitg2;
                    boolean_T p;
                    p = true;
                    end = 0;
                    exitg2 = false;
                    while ((!exitg2) && (end < 2)) {
                      if (static_cast<int32_T>(coordsToUse[end]) != end + 1) {
                        p = false;
                        exitg2 = true;
                      } else {
                        end++;
                      }
                    }

                    if (p) {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = currCoord;
                      currPt[1] = y;
                    } else {
                      real_T y;
                      y = currCurve_data[0];
                      i1 = currCurve_size[1];
                      for (end = 0; end <= i1 - 2; end++) {
                        y = currCoord * y + currCurve_data[end + 1];
                      }

                      currPt[0] = y;
                      currPt[1] = currCoord;
                    }

                    st.site = &dk_emlrtRSI;
                    findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                       currCurve_data, currCurve_size,
                                       coordsToUse, removedIdx, b_index);
                    if (b_index.size(1) != 0) {
                      if (1 != b_index.size(1)) {
                        emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                          &ob_emlrtECI, (emlrtCTX)sp);
                      }

                      if ((j + 1 < 1) || (j + 1 > newIndices.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(j + 1, 1, newIndices.size
                          (1), &ei_emlrtBCI, (emlrtCTX)sp);
                      }

                      newIndices[j] = b_index[0];
                      i1 = removedIdx.size(1);
                      loop_ub = b_index.size(1);
                      removedIdx.set_size(&aj_emlrtRTEI, sp, removedIdx.size(0),
                                          removedIdx.size(1) + b_index.size(1));
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        removedIdx[i1 + i2] = b_index[i2];
                      }

                      exitg1 = true;
                    } else {
                      currCoord += currRad;
                    }
                  }
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }

            void Checkerboard::expandBoardFully(const emlrtStack *sp)
            {
              emlrtStack b_st;
              emlrtStack st;
              st.prev = sp;
              st.tls = sp->tls;
              b_st.prev = &st;
              b_st.tls = st.tls;
              if (isValid) {
                boolean_T hasExpanded;
                hasExpanded = true;
                while (hasExpanded) {
                  int32_T i;
                  st.site = &mi_emlrtRSI;
                  PreviousEnergy = Energy;
                  i = 0;
                  int32_T exitg1;
                  do {
                    exitg1 = 0;
                    if (i < 4) {
                      if (!IsDirectionBad[i]) {
                        LastExpandDirection = static_cast<real_T>(i) + 1.0;
                        b_st.site = &ni_emlrtRSI;
                        expandBoardDirectionally(&b_st, static_cast<real_T>(i) +
                          1.0);
                        if (Energy < PreviousEnergy) {
                          exitg1 = 1;
                        } else {
                          b_st.site = &oi_emlrtRSI;
                          Energy = PreviousEnergy;
                          if (LastExpandDirection != static_cast<int32_T>
                              (muDoubleScalarFloor(LastExpandDirection))) {
                            emlrtIntegerCheckR2012b(LastExpandDirection,
                              &p_emlrtDCI, &b_st);
                          }

                          switch (static_cast<int32_T>(LastExpandDirection)) {
                           case 1:
                            {
                              int32_T b_i;
                              int32_T b_this;
                              int32_T c_this;
                              int32_T i1;
                              int32_T i2;
                              int32_T i3;
                              int32_T loop_ub;
                              int32_T loop_ub_tmp;
                              b_i = BoardIdx.size(0);
                              if (2 > b_i) {
                                i1 = -1;
                                b_i = -1;
                              } else {
                                i1 = BoardIdx.size(0);
                                if (2 > i1) {
                                  emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                    &qf_emlrtBCI, &b_st);
                                }

                                i1 = 0;
                                i2 = BoardIdx.size(0);
                                if (b_i > i2) {
                                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                    &rf_emlrtBCI, &b_st);
                                }

                                b_i--;
                              }

                              b_this = BoardIdx.size(1) - 1;
                              for (i2 = 0; i2 <= b_this; i2++) {
                                loop_ub_tmp = b_i - i1;
                                for (i3 = 0; i3 < loop_ub_tmp; i3++) {
                                  BoardIdx[i3 + loop_ub_tmp * i2] = BoardIdx
                                    [((i1 + i3) + BoardIdx.size(0) * i2) + 1];
                                }
                              }

                              BoardIdx.set_size(&mh_emlrtRTEI, &b_st, b_i - i1,
                                                b_this + 1);
                              b_i = BoardCoords.size(0);
                              if (2 > b_i) {
                                i1 = -1;
                                b_i = -1;
                              } else {
                                i1 = BoardCoords.size(0);
                                if (2 > i1) {
                                  emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                    &sf_emlrtBCI, &b_st);
                                }

                                i1 = 0;
                                i2 = BoardCoords.size(0);
                                if (b_i > i2) {
                                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                    &tf_emlrtBCI, &b_st);
                                }

                                b_i--;
                              }

                              b_this = BoardCoords.size(1) - 1;
                              c_this = BoardCoords.size(2) - 1;
                              loop_ub = BoardCoords.size(1);
                              for (i2 = 0; i2 <= c_this; i2++) {
                                for (i3 = 0; i3 < loop_ub; i3++) {
                                  loop_ub_tmp = b_i - i1;
                                  for (int32_T i4{0}; i4 < loop_ub_tmp; i4++) {
                                    BoardCoords[(i4 + loop_ub_tmp * i3) +
                                      loop_ub_tmp * (b_this + 1) * i2] =
                                      BoardCoords[(((i1 + i4) + BoardCoords.size
                                                    (0) * i3) + BoardCoords.size
                                                   (0) * BoardCoords.size(1) *
                                                   i2) + 1];
                                  }
                                }
                              }

                              BoardCoords.set_size(&nh_emlrtRTEI, &b_st, b_i -
                                                   i1, b_this + 1, c_this + 1);
                            }
                            break;

                           case 2:
                            {
                              real_T d;
                              int32_T b_i;
                              int32_T b_this;
                              int32_T c_this;
                              int32_T i1;
                              int32_T loop_ub;
                              int32_T loop_ub_tmp;
                              d = static_cast<real_T>(BoardIdx.size(0)) - 1.0;
                              if (1.0 > d) {
                                loop_ub = 0;
                              } else {
                                b_i = BoardIdx.size(0);
                                if (1 > b_i) {
                                  emlrtDynamicBoundsCheckR2012b(1, 1, b_i,
                                    &uf_emlrtBCI, &b_st);
                                }

                                b_i = BoardIdx.size(0);
                                loop_ub = static_cast<int32_T>(d);
                                if (loop_ub > b_i) {
                                  emlrtDynamicBoundsCheckR2012b
                                    (static_cast<int32_T>(d), 1, b_i,
                                     &vf_emlrtBCI, &b_st);
                                }
                              }

                              b_this = BoardIdx.size(1) - 1;
                              for (b_i = 0; b_i <= b_this; b_i++) {
                                for (i1 = 0; i1 < loop_ub; i1++) {
                                  BoardIdx[i1 + loop_ub * b_i] = BoardIdx[i1 +
                                    BoardIdx.size(0) * b_i];
                                }
                              }

                              BoardIdx.set_size(&oh_emlrtRTEI, &b_st, loop_ub,
                                                b_this + 1);
                              d = static_cast<real_T>(BoardCoords.size(0)) - 1.0;
                              if (1.0 > d) {
                                loop_ub = 0;
                              } else {
                                b_i = BoardCoords.size(0);
                                if (1 > b_i) {
                                  emlrtDynamicBoundsCheckR2012b(1, 1, b_i,
                                    &wf_emlrtBCI, &b_st);
                                }

                                b_i = BoardCoords.size(0);
                                loop_ub = static_cast<int32_T>(d);
                                if (loop_ub > b_i) {
                                  emlrtDynamicBoundsCheckR2012b
                                    (static_cast<int32_T>(d), 1, b_i,
                                     &xf_emlrtBCI, &b_st);
                                }
                              }

                              b_this = BoardCoords.size(1) - 1;
                              c_this = BoardCoords.size(2) - 1;
                              loop_ub_tmp = BoardCoords.size(1);
                              for (b_i = 0; b_i <= c_this; b_i++) {
                                for (i1 = 0; i1 < loop_ub_tmp; i1++) {
                                  for (int32_T i2{0}; i2 < loop_ub; i2++) {
                                    BoardCoords[(i2 + loop_ub * i1) + loop_ub *
                                      (b_this + 1) * b_i] = BoardCoords[(i2 +
                                      BoardCoords.size(0) * i1) +
                                      BoardCoords.size(0) * BoardCoords.size(1) *
                                      b_i];
                                  }
                                }
                              }

                              BoardCoords.set_size(&ph_emlrtRTEI, &b_st, loop_ub,
                                                   b_this + 1, c_this + 1);
                            }
                            break;

                           case 3:
                            {
                              int32_T b_i;
                              int32_T b_this;
                              int32_T c_this;
                              int32_T i1;
                              int32_T i2;
                              int32_T loop_ub;
                              int32_T loop_ub_tmp;
                              b_i = BoardIdx.size(1);
                              if (2 > b_i) {
                                i1 = 0;
                                b_i = 0;
                              } else {
                                i1 = BoardIdx.size(1);
                                if (2 > i1) {
                                  emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                    &yf_emlrtBCI, &b_st);
                                }

                                i1 = 1;
                                i2 = BoardIdx.size(1);
                                if (b_i > i2) {
                                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                    &ag_emlrtBCI, &b_st);
                                }
                              }

                              b_this = BoardIdx.size(0) - 1;
                              loop_ub = BoardIdx.size(0);
                              loop_ub_tmp = b_i - i1;
                              for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
                                for (i2 = 0; i2 < loop_ub; i2++) {
                                  BoardIdx[i2 + (b_this + 1) * b_i] =
                                    BoardIdx[i2 + BoardIdx.size(0) * (i1 + b_i)];
                                }
                              }

                              BoardIdx.set_size(&qh_emlrtRTEI, &b_st, b_this + 1,
                                                loop_ub_tmp);
                              b_i = BoardCoords.size(1);
                              if (2 > b_i) {
                                i1 = -1;
                                b_i = -1;
                              } else {
                                i1 = BoardCoords.size(1);
                                if (2 > i1) {
                                  emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                    &bg_emlrtBCI, &b_st);
                                }

                                i1 = 0;
                                i2 = BoardCoords.size(1);
                                if (b_i > i2) {
                                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                    &cg_emlrtBCI, &b_st);
                                }

                                b_i--;
                              }

                              b_this = BoardCoords.size(0) - 1;
                              c_this = BoardCoords.size(2) - 1;
                              loop_ub = BoardCoords.size(0);
                              for (i2 = 0; i2 <= c_this; i2++) {
                                loop_ub_tmp = b_i - i1;
                                for (int32_T i3{0}; i3 < loop_ub_tmp; i3++) {
                                  for (int32_T i4{0}; i4 < loop_ub; i4++) {
                                    BoardCoords[(i4 + (b_this + 1) * i3) +
                                      (b_this + 1) * loop_ub_tmp * i2] =
                                      BoardCoords[(i4 + BoardCoords.size(0) *
                                                   ((i1 + i3) + 1)) +
                                      BoardCoords.size(0) * BoardCoords.size(1) *
                                      i2];
                                  }
                                }
                              }

                              BoardCoords.set_size(&rh_emlrtRTEI, &b_st, b_this
                                                   + 1, b_i - i1, c_this + 1);
                            }
                            break;

                           case 4:
                            {
                              real_T d;
                              int32_T b_i;
                              int32_T b_this;
                              int32_T c_this;
                              int32_T i1;
                              int32_T loop_ub;
                              int32_T loop_ub_tmp;
                              d = static_cast<real_T>(BoardIdx.size(1)) - 1.0;
                              if (1.0 > d) {
                                loop_ub = 0;
                              } else {
                                b_i = BoardIdx.size(1);
                                if (1 > b_i) {
                                  emlrtDynamicBoundsCheckR2012b(1, 1, b_i,
                                    &dg_emlrtBCI, &b_st);
                                }

                                b_i = BoardIdx.size(1);
                                loop_ub = static_cast<int32_T>(d);
                                if (loop_ub > b_i) {
                                  emlrtDynamicBoundsCheckR2012b
                                    (static_cast<int32_T>(d), 1, b_i,
                                     &eg_emlrtBCI, &b_st);
                                }
                              }

                              b_this = BoardIdx.size(0) - 1;
                              loop_ub_tmp = BoardIdx.size(0);
                              for (b_i = 0; b_i < loop_ub; b_i++) {
                                for (i1 = 0; i1 < loop_ub_tmp; i1++) {
                                  BoardIdx[i1 + (b_this + 1) * b_i] =
                                    BoardIdx[i1 + BoardIdx.size(0) * b_i];
                                }
                              }

                              BoardIdx.set_size(&sh_emlrtRTEI, &b_st, b_this + 1,
                                                loop_ub);
                              d = static_cast<real_T>(BoardCoords.size(1)) - 1.0;
                              if (1.0 > d) {
                                loop_ub = 0;
                              } else {
                                b_i = BoardCoords.size(1);
                                if (1 > b_i) {
                                  emlrtDynamicBoundsCheckR2012b(1, 1, b_i,
                                    &fg_emlrtBCI, &b_st);
                                }

                                b_i = BoardCoords.size(1);
                                loop_ub = static_cast<int32_T>(d);
                                if (loop_ub > b_i) {
                                  emlrtDynamicBoundsCheckR2012b
                                    (static_cast<int32_T>(d), 1, b_i,
                                     &gg_emlrtBCI, &b_st);
                                }
                              }

                              b_this = BoardCoords.size(0) - 1;
                              c_this = BoardCoords.size(2) - 1;
                              loop_ub_tmp = BoardCoords.size(0);
                              for (b_i = 0; b_i <= c_this; b_i++) {
                                for (i1 = 0; i1 < loop_ub; i1++) {
                                  for (int32_T i2{0}; i2 < loop_ub_tmp; i2++) {
                                    BoardCoords[(i2 + (b_this + 1) * i1) +
                                      (b_this + 1) * loop_ub * b_i] =
                                      BoardCoords[(i2 + BoardCoords.size(0) * i1)
                                      + BoardCoords.size(0) * BoardCoords.size(1)
                                      * b_i];
                                  }
                                }
                              }

                              BoardCoords.set_size(&th_emlrtRTEI, &b_st, b_this
                                                   + 1, loop_ub, c_this + 1);
                            }
                            break;
                          }

                          IsDirectionBad[i] = true;
                          i++;
                        }
                      } else {
                        i++;
                      }
                    } else {
                      hasExpanded = false;
                      exitg1 = 1;
                    }
                  } while (exitg1 == 0);
                }
              }
            }

            Checkerboard *Checkerboard::init(const emlrtStack *sp)
            {
              Checkerboard *this_;
              int32_T i;
              this_ = this;
              this_->isValid = false;
              this_->Energy = rtInfF;
              this_->IsDistortionHigh = false;
              this_->BoardIdx.set_size(&ye_emlrtRTEI, sp, 1, 1);
              this_->BoardIdx[0] = 0.0;
              this_->BoardIdx.set_size(&af_emlrtRTEI, sp, 3, 3);
              for (i = 0; i < 9; i++) {
                this_->BoardIdx[i] = 0.0;
              }

              this_->BoardCoords.set_size(&bf_emlrtRTEI, sp, 1, 1, 1);
              this_->BoardCoords[0] = 0.0;
              this_->BoardCoords.set_size(&cf_emlrtRTEI, sp, 3, 3, 2);
              for (i = 0; i < 18; i++) {
                this_->BoardCoords[i] = 0.0;
              }

              this_->Points.set_size(&df_emlrtRTEI, sp, 1, 1);
              this_->Points[0] = 0.0F;
              this_->Points.set_size(&ef_emlrtRTEI, sp, 0, 2);
              this_->IsDistortionHigh = false;
              return this_;
            }

            void Checkerboard::initialize(const emlrtStack *sp, real_T seedIdx,
              const ::coder::array<real32_T, 2U> &points, const real32_T v1[2],
              const real32_T v2[2])
            {
              ::coder::array<real_T, 2U> r1;
              ::coder::array<int32_T, 1U> r;
              ::coder::array<real32_T, 2U> b_r;
              ::coder::array<real32_T, 2U> center;
              ::coder::array<real32_T, 2U> d;
              ::coder::array<real32_T, 2U> l;
              ::coder::array<real32_T, 2U> pointVectors;
              ::coder::array<real32_T, 2U> u;
              ::coder::array<real32_T, 1U> b_pointVectors;
              ::coder::array<real32_T, 1U> c_pointVectors;
              ::coder::array<real32_T, 1U> euclideanDists;
              ::coder::array<boolean_T, 1U> b_this;
              emlrtStack st;
              int32_T iv[3];
              int32_T iv1[2];
              int32_T iv2[2];
              int32_T csz_idx_1;
              int32_T i;
              int32_T loop_ub;
              real32_T b_v1[2];
              st.prev = sp;
              st.tls = sp->tls;
              emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
              BoardIdx.set_size(&ff_emlrtRTEI, sp, 1, 1);
              BoardIdx[0] = 0.0;
              BoardIdx.set_size(&gf_emlrtRTEI, sp, 3, 3);
              for (i = 0; i < 9; i++) {
                BoardIdx[i] = 0.0;
              }

              IsDirectionBad[0] = false;
              IsDirectionBad[1] = false;
              IsDirectionBad[2] = false;
              IsDirectionBad[3] = false;
              BoardCoords.set_size(&hf_emlrtRTEI, sp, 1, 1, 1);
              BoardCoords[0] = 0.0;
              BoardCoords.set_size(&if_emlrtRTEI, sp, 3, 3, 2);
              for (i = 0; i < 18; i++) {
                BoardCoords[i] = 0.0;
              }

              Points.set_size(&jf_emlrtRTEI, sp, points.size(0), 2);
              loop_ub = points.size(0) * 2;
              for (i = 0; i < loop_ub; i++) {
                Points[i] = points[i];
              }

              i = Points.size(0);
              if ((static_cast<int32_T>(seedIdx) < 1) || (static_cast<int32_T>
                   (seedIdx) > i)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(seedIdx), 1,
                  i, &mc_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = Points.size(1);
              center.set_size(&kf_emlrtRTEI, sp, 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                center[i] = Points[(static_cast<int32_T>(seedIdx) + Points.size
                                    (0) * i) - 1];
              }

              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &nc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &oc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              BoardIdx[BoardIdx.size(0) + 1] = seedIdx;
              i = BoardCoords.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &pc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardCoords.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &qc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardCoords.size(2);
              r.set_size(&lf_emlrtRTEI, sp, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                r[i] = i;
              }

              iv[0] = 1;
              iv[1] = 1;
              iv[2] = r.size(0);
              emlrtSubAssignSizeCheckR2012b(&iv[0], 3, center.size(), 2,
                &o_emlrtECI, (emlrtCTX)sp);
              loop_ub = r.size(0);
              for (i = 0; i < loop_ub; i++) {
                BoardCoords[(BoardCoords.size(0) + BoardCoords.size(0) *
                             BoardCoords.size(1) * r[i]) + 1] = center[i];
              }

              LastExpandDirection = 1.0;
              PreviousEnergy = rtInfF;
              isValid = false;
              st.site = &vg_emlrtRSI;
              if (center.size(1) == 1) {
                csz_idx_1 = Points.size(1);
              } else if (Points.size(1) == 1) {
                csz_idx_1 = center.size(1);
              } else if (Points.size(1) == center.size(1)) {
                csz_idx_1 = Points.size(1);
              } else {
                emlrtErrorWithMessageIdR2018a(&st, &v_emlrtRTEI,
                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
              }

              pointVectors.set_size(&mf_emlrtRTEI, &st, Points.size(0),
                                    csz_idx_1);
              if ((Points.size(0) != 0) && (csz_idx_1 != 0)) {
                int32_T acoef;
                int32_T bcoef;
                acoef = (Points.size(1) != 1);
                bcoef = (center.size(1) != 1);
                i = csz_idx_1 - 1;
                for (int32_T k{0}; k <= i; k++) {
                  int32_T b_acoef;
                  int32_T i1;
                  loop_ub = acoef * k;
                  csz_idx_1 = bcoef * k;
                  b_acoef = (Points.size(0) != 1);
                  i1 = pointVectors.size(0) - 1;
                  for (int32_T b_k{0}; b_k <= i1; b_k++) {
                    pointVectors[b_k + pointVectors.size(0) * k] =
                      Points[b_acoef * b_k + Points.size(0) * loop_ub] -
                      center[csz_idx_1];
                  }
                }
              }

              if (1 > pointVectors.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, pointVectors.size(1),
                  &rc_emlrtBCI, (emlrtCTX)sp);
              }

              if (2 > pointVectors.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, pointVectors.size(1),
                  &sc_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = pointVectors.size(0);
              b_pointVectors.set_size(&nf_emlrtRTEI, sp, pointVectors.size(0));
              for (i = 0; i < loop_ub; i++) {
                b_pointVectors[i] = pointVectors[i];
              }

              loop_ub = pointVectors.size(0);
              c_pointVectors.set_size(&of_emlrtRTEI, sp, pointVectors.size(0));
              for (i = 0; i < loop_ub; i++) {
                c_pointVectors[i] = pointVectors[i + pointVectors.size(0)];
              }

              st.site = &wg_emlrtRSI;
              b_hypot(&st, b_pointVectors, c_pointVectors, euclideanDists);
              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &tc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardIdx.size(1);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &uc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              st.site = &xg_emlrtRSI;
              BoardIdx[BoardIdx.size(0) * 2 + 1] = findNeighbor(&st,
                pointVectors, euclideanDists, v1);
              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &vc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardIdx.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &wc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              b_v1[0] = -v1[0];
              b_v1[1] = -v1[1];
              st.site = &yg_emlrtRSI;
              BoardIdx[1] = findNeighbor(&st, pointVectors, euclideanDists, b_v1);
              i = BoardIdx.size(0);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &xc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &yc_emlrtBCI, (emlrtCTX)
                  sp);
              }

              st.site = &ah_emlrtRSI;
              BoardIdx[BoardIdx.size(0) + 2] = findNeighbor(&st, pointVectors,
                euclideanDists, v2);
              i = BoardIdx.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ad_emlrtBCI, (emlrtCTX)
                  sp);
              }

              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &bd_emlrtBCI, (emlrtCTX)
                  sp);
              }

              b_v1[0] = -v2[0];
              b_v1[1] = -v2[1];
              st.site = &bh_emlrtRSI;
              BoardIdx[BoardIdx.size(0)] = findNeighbor(&st, pointVectors,
                euclideanDists, b_v1);
              csz_idx_1 = BoardIdx.size(0) * BoardIdx.size(1);
              b_this.set_size(&pf_emlrtRTEI, sp, csz_idx_1);
              for (i = 0; i < csz_idx_1; i++) {
                b_this[i] = (BoardIdx[i] < 0.0);
              }

              st.site = &ch_emlrtRSI;
              if (any(&st, b_this)) {
                isValid = false;
              } else {
                i = BoardIdx.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &cd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &dd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                if (BoardIdx[BoardIdx.size(0) * 2 + 1] != static_cast<int32_T>
                    (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2 + 1]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2 + 1],
                    &f_emlrtDCI, (emlrtCTX)sp);
                }

                i = Points.size(0);
                csz_idx_1 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2 +
                  1]);
                if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                    (BoardIdx[BoardIdx.size(0) * 2 + 1]), 1, i, &ed_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                b_r.set_size(&qf_emlrtRTEI, sp, 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  b_r[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                }

                i = BoardCoords.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &fd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardCoords.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &gd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&rf_emlrtRTEI, sp, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  r[i] = i;
                }

                iv[0] = 1;
                iv[1] = 1;
                iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&iv[0], 3, b_r.size(), 2,
                  &p_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[(BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                               BoardCoords.size(1) * r[i]) + 1] = b_r[i];
                }

                i = BoardIdx.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &hd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &id_emlrtBCI, (emlrtCTX)
                    sp);
                }

                if (BoardIdx[1] != static_cast<int32_T>(muDoubleScalarFloor
                     (BoardIdx[1]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[1], &g_emlrtDCI, (emlrtCTX)sp);
                }

                i = Points.size(0);
                csz_idx_1 = static_cast<int32_T>(BoardIdx[1]);
                if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(BoardIdx[1]),
                    1, i, &jd_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                l.set_size(&sf_emlrtRTEI, sp, 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  l[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                }

                i = BoardCoords.size(0);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &kd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardCoords.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ld_emlrtBCI, (emlrtCTX)
                    sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&tf_emlrtRTEI, sp, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  r[i] = i;
                }

                iv[0] = 1;
                iv[1] = 1;
                iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&iv[0], 3, l.size(), 2,
                  &q_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) * r[i] +
                    1] = l[i];
                }

                i = BoardIdx.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &md_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &nd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                if (BoardIdx[BoardIdx.size(0) + 2] != static_cast<int32_T>
                    (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) + 2]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) + 2],
                    &h_emlrtDCI, (emlrtCTX)sp);
                }

                i = Points.size(0);
                csz_idx_1 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 2]);
                if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                    (BoardIdx[BoardIdx.size(0) + 2]), 1, i, &od_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                d.set_size(&uf_emlrtRTEI, sp, 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  d[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                }

                i = BoardCoords.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &pd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardCoords.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &qd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&vf_emlrtRTEI, sp, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  r[i] = i;
                }

                iv[0] = 1;
                iv[1] = 1;
                iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&iv[0], 3, d.size(), 2,
                  &r_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[(BoardCoords.size(0) + BoardCoords.size(0) *
                               BoardCoords.size(1) * r[i]) + 2] = d[i];
                }

                i = BoardIdx.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &rd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &sd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                if (BoardIdx[BoardIdx.size(0)] != static_cast<int32_T>
                    (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0)]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0)],
                    &i_emlrtDCI, (emlrtCTX)sp);
                }

                i = Points.size(0);
                csz_idx_1 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0)]);
                if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                    (BoardIdx[BoardIdx.size(0)]), 1, i, &td_emlrtBCI, (emlrtCTX)
                    sp);
                }

                loop_ub = Points.size(1);
                u.set_size(&wf_emlrtRTEI, sp, 1, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  u[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                }

                i = BoardCoords.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ud_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardCoords.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &vd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&xf_emlrtRTEI, sp, loop_ub);
                for (i = 0; i < loop_ub; i++) {
                  r[i] = i;
                }

                iv[0] = 1;
                iv[1] = 1;
                iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&iv[0], 3, u.size(), 2,
                  &s_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[BoardCoords.size(0) + BoardCoords.size(0) *
                    BoardCoords.size(1) * r[i]] = u[i];
                }

                iv1[0] = (*(int32_T (*)[2])u.size())[0];
                iv1[1] = (*(int32_T (*)[2])u.size())[1];
                iv2[0] = (*(int32_T (*)[2])center.size())[0];
                iv2[1] = (*(int32_T (*)[2])center.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &t_emlrtECI,
                  (emlrtCTX)sp);
                u.set_size(&yf_emlrtRTEI, sp, 1, u.size(1));
                loop_ub = u.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  u[i] = u[i] - center[i];
                }

                iv1[0] = (*(int32_T (*)[2])d.size())[0];
                iv1[1] = (*(int32_T (*)[2])d.size())[1];
                iv2[0] = (*(int32_T (*)[2])center.size())[0];
                iv2[1] = (*(int32_T (*)[2])center.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &u_emlrtECI,
                  (emlrtCTX)sp);
                d.set_size(&ag_emlrtRTEI, sp, 1, d.size(1));
                loop_ub = d.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  d[i] = d[i] - center[i];
                }

                iv1[0] = (*(int32_T (*)[2])b_r.size())[0];
                iv1[1] = (*(int32_T (*)[2])b_r.size())[1];
                iv2[0] = (*(int32_T (*)[2])center.size())[0];
                iv2[1] = (*(int32_T (*)[2])center.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &v_emlrtECI,
                  (emlrtCTX)sp);
                b_r.set_size(&bg_emlrtRTEI, sp, 1, b_r.size(1));
                loop_ub = b_r.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  b_r[i] = b_r[i] - center[i];
                }

                iv1[0] = (*(int32_T (*)[2])l.size())[0];
                iv1[1] = (*(int32_T (*)[2])l.size())[1];
                iv2[0] = (*(int32_T (*)[2])center.size())[0];
                iv2[1] = (*(int32_T (*)[2])center.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &w_emlrtECI,
                  (emlrtCTX)sp);
                l.set_size(&cg_emlrtRTEI, sp, 1, l.size(1));
                loop_ub = l.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  l[i] = l[i] - center[i];
                }

                iv1[0] = (*(int32_T (*)[2])u.size())[0];
                iv1[1] = (*(int32_T (*)[2])u.size())[1];
                iv2[0] = (*(int32_T (*)[2])l.size())[0];
                iv2[1] = (*(int32_T (*)[2])l.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &x_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardIdx.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &wd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &xd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                center.set_size(&dg_emlrtRTEI, sp, 1, u.size(1));
                loop_ub = u.size(1);
                for (i = 0; i < loop_ub; i++) {
                  center[i] = u[i] + l[i];
                }

                st.site = &dh_emlrtRSI;
                BoardIdx[0] = findNeighbor(&st, pointVectors, euclideanDists,
                  center);
                iv1[0] = (*(int32_T (*)[2])d.size())[0];
                iv1[1] = (*(int32_T (*)[2])d.size())[1];
                iv2[0] = (*(int32_T (*)[2])l.size())[0];
                iv2[1] = (*(int32_T (*)[2])l.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &y_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardIdx.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &yd_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ae_emlrtBCI, (emlrtCTX)
                    sp);
                }

                center.set_size(&eg_emlrtRTEI, sp, 1, d.size(1));
                loop_ub = d.size(1);
                for (i = 0; i < loop_ub; i++) {
                  center[i] = d[i] + l[i];
                }

                st.site = &eh_emlrtRSI;
                BoardIdx[2] = findNeighbor(&st, pointVectors, euclideanDists,
                  center);
                iv1[0] = (*(int32_T (*)[2])d.size())[0];
                iv1[1] = (*(int32_T (*)[2])d.size())[1];
                iv2[0] = (*(int32_T (*)[2])b_r.size())[0];
                iv2[1] = (*(int32_T (*)[2])b_r.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &ab_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardIdx.size(0);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &be_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &ce_emlrtBCI, (emlrtCTX)
                    sp);
                }

                center.set_size(&fg_emlrtRTEI, sp, 1, d.size(1));
                loop_ub = d.size(1);
                for (i = 0; i < loop_ub; i++) {
                  center[i] = d[i] + b_r[i];
                }

                st.site = &fh_emlrtRSI;
                BoardIdx[BoardIdx.size(0) * 2 + 2] = findNeighbor(&st,
                  pointVectors, euclideanDists, center);
                iv1[0] = (*(int32_T (*)[2])u.size())[0];
                iv1[1] = (*(int32_T (*)[2])u.size())[1];
                iv2[0] = (*(int32_T (*)[2])b_r.size())[0];
                iv2[1] = (*(int32_T (*)[2])b_r.size())[1];
                emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &bb_emlrtECI,
                  (emlrtCTX)sp);
                i = BoardIdx.size(0);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &de_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = BoardIdx.size(1);
                if (3 > i) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, i, &ee_emlrtBCI, (emlrtCTX)
                    sp);
                }

                center.set_size(&gg_emlrtRTEI, sp, 1, u.size(1));
                loop_ub = u.size(1);
                for (i = 0; i < loop_ub; i++) {
                  center[i] = u[i] + b_r[i];
                }

                st.site = &gh_emlrtRSI;
                BoardIdx[BoardIdx.size(0) * 2] = findNeighbor(&st, pointVectors,
                  euclideanDists, center);
                csz_idx_1 = BoardIdx.size(0) * BoardIdx.size(1);
                b_this.set_size(&hg_emlrtRTEI, sp, csz_idx_1);
                for (i = 0; i < csz_idx_1; i++) {
                  b_this[i] = (BoardIdx[i] > 0.0);
                }

                st.site = &hh_emlrtRSI;
                isValid = all(&st, b_this);
                if (isValid) {
                  i = BoardCoords.size(0);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ie_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardCoords.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &je_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r.set_size(&ig_emlrtRTEI, sp, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r[i] = i;
                  }

                  i = BoardIdx.size(0);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &fe_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardIdx.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ge_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  if (BoardIdx[0] != static_cast<int32_T>(muDoubleScalarFloor
                       (BoardIdx[0]))) {
                    emlrtIntegerCheckR2012b(BoardIdx[0], &j_emlrtDCI, (emlrtCTX)
                      sp);
                  }

                  i = Points.size(0);
                  csz_idx_1 = static_cast<int32_T>(BoardIdx[0]);
                  if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(BoardIdx
                      [0]), 1, i, &he_emlrtBCI, (emlrtCTX)sp);
                  }

                  loop_ub = Points.size(1);
                  r1.set_size(&jg_emlrtRTEI, sp, 1, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r1[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                  }

                  iv[0] = 1;
                  iv[1] = 1;
                  iv[2] = r.size(0);
                  emlrtSubAssignSizeCheckR2012b(&iv[0], 3, r1.size(), 2,
                    &cb_emlrtECI, (emlrtCTX)sp);
                  loop_ub = r.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) * r[i]]
                      = r1[i];
                  }

                  i = BoardCoords.size(0);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &ne_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardCoords.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &oe_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r.set_size(&kg_emlrtRTEI, sp, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r[i] = i;
                  }

                  i = BoardIdx.size(0);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &ke_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardIdx.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &le_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  if (BoardIdx[2] != static_cast<int32_T>(muDoubleScalarFloor
                       (BoardIdx[2]))) {
                    emlrtIntegerCheckR2012b(BoardIdx[2], &k_emlrtDCI, (emlrtCTX)
                      sp);
                  }

                  i = Points.size(0);
                  csz_idx_1 = static_cast<int32_T>(BoardIdx[2]);
                  if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(BoardIdx
                      [2]), 1, i, &me_emlrtBCI, (emlrtCTX)sp);
                  }

                  loop_ub = Points.size(1);
                  r1.set_size(&lg_emlrtRTEI, sp, 1, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r1[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                  }

                  iv[0] = 1;
                  iv[1] = 1;
                  iv[2] = r.size(0);
                  emlrtSubAssignSizeCheckR2012b(&iv[0], 3, r1.size(), 2,
                    &db_emlrtECI, (emlrtCTX)sp);
                  loop_ub = r.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) * r[i]
                      + 2] = r1[i];
                  }

                  i = BoardCoords.size(0);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &se_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardCoords.size(1);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &te_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r.set_size(&mg_emlrtRTEI, sp, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r[i] = i;
                  }

                  i = BoardIdx.size(0);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &pe_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardIdx.size(1);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &qe_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  if (BoardIdx[BoardIdx.size(0) * 2 + 2] != static_cast<int32_T>
                      (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2 + 2])))
                  {
                    emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2 + 2],
                      &l_emlrtDCI, (emlrtCTX)sp);
                  }

                  i = Points.size(0);
                  csz_idx_1 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2
                    + 2]);
                  if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                      (BoardIdx[BoardIdx.size(0) * 2 + 2]), 1, i, &re_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = Points.size(1);
                  r1.set_size(&ng_emlrtRTEI, sp, 1, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r1[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                  }

                  iv[0] = 1;
                  iv[1] = 1;
                  iv[2] = r.size(0);
                  emlrtSubAssignSizeCheckR2012b(&iv[0], 3, r1.size(), 2,
                    &eb_emlrtECI, (emlrtCTX)sp);
                  loop_ub = r.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[(BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                                 BoardCoords.size(1) * r[i]) + 2] = r1[i];
                  }

                  i = BoardCoords.size(0);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &xe_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardCoords.size(1);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &ye_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = BoardCoords.size(2);
                  r.set_size(&og_emlrtRTEI, sp, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r[i] = i;
                  }

                  i = BoardIdx.size(0);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ue_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  i = BoardIdx.size(1);
                  if (3 > i) {
                    emlrtDynamicBoundsCheckR2012b(3, 1, i, &ve_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  if (BoardIdx[BoardIdx.size(0) * 2] != static_cast<int32_T>
                      (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2]))) {
                    emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2],
                      &m_emlrtDCI, (emlrtCTX)sp);
                  }

                  i = Points.size(0);
                  csz_idx_1 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2]);
                  if ((csz_idx_1 < 1) || (csz_idx_1 > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>
                      (BoardIdx[BoardIdx.size(0) * 2]), 1, i, &we_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  loop_ub = Points.size(1);
                  r1.set_size(&pg_emlrtRTEI, sp, 1, loop_ub);
                  for (i = 0; i < loop_ub; i++) {
                    r1[i] = Points[(csz_idx_1 + Points.size(0) * i) - 1];
                  }

                  iv[0] = 1;
                  iv[1] = 1;
                  iv[2] = r.size(0);
                  emlrtSubAssignSizeCheckR2012b(&iv[0], 3, r1.size(), 2,
                    &fb_emlrtECI, (emlrtCTX)sp);
                  loop_ub = r.size(0);
                  for (i = 0; i < loop_ub; i++) {
                    BoardCoords[BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                      BoardCoords.size(1) * r[i]] = r1[i];
                  }

                  st.site = &ih_emlrtRSI;
                  Energy = computeInitialEnergy(&st);
                  if (IsDistortionHigh) {
                    loop_ub = -5;
                  } else {
                    loop_ub = -7;
                  }

                  isValid = (static_cast<real_T>(Energy) < loop_ub);
                }
              }

              emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            }
          }
        }
      }
    }
  }
}

// End of code generation (Checkerboard.cpp)
