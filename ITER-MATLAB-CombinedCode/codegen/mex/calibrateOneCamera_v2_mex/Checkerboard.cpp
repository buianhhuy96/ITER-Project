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
#include "calibrateOneCamera_v2_mex_data.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_setop.h"
#include "find.h"
#include "hypot.h"
#include "indexShapeCheck.h"
#include "isequal.h"
#include "ismember.h"
#include "mean.h"
#include "norm.h"
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
static emlrtRSInfo th_emlrtRSI{ 74,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo uh_emlrtRSI{ 75,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vh_emlrtRSI{ 78,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wh_emlrtRSI{ 79,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xh_emlrtRSI{ 80,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yh_emlrtRSI{ 81,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ai_emlrtRSI{ 83,    // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bi_emlrtRSI{ 103,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ci_emlrtRSI{ 104,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo di_emlrtRSI{ 105,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ei_emlrtRSI{ 106,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fi_emlrtRSI{ 107,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gi_emlrtRSI{ 117,   // lineNo
  "Checkerboard/initialize",           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ni_emlrtRSI{ 231,   // lineNo
  "Checkerboard/findNeighbor",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oi_emlrtRSI{ 244,   // lineNo
  "Checkerboard/findNeighbor",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vi_emlrtRSI{ 17,    // lineNo
  "min",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName
};

static emlrtRSInfo wi_emlrtRSI{ 40,    // lineNo
  "minOrMax",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo xi_emlrtRSI{ 90,    // lineNo
  "minimum",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo yi_emlrtRSI{ 169,   // lineNo
  "unaryMinOrMax",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo cj_emlrtRSI{ 136,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dj_emlrtRSI{ 144,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ej_emlrtRSI{ 145,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fj_emlrtRSI{ 146,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hj_emlrtRSI{ 153,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ij_emlrtRSI{ 154,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jj_emlrtRSI{ 155,   // lineNo
  "Checkerboard/computeInitialEnergy", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lj_emlrtRSI{ 177,   // lineNo
  "Checkerboard/expandBoardFully",     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mj_emlrtRSI{ 263,   // lineNo
  "Checkerboard/expandBoardOnce",      // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nj_emlrtRSI{ 268,   // lineNo
  "Checkerboard/expandBoardOnce",      // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oj_emlrtRSI{ 305,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pj_emlrtRSI{ 306,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qj_emlrtRSI{ 307,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rj_emlrtRSI{ 308,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sj_emlrtRSI{ 314,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tj_emlrtRSI{ 315,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo uj_emlrtRSI{ 317,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vj_emlrtRSI{ 318,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wj_emlrtRSI{ 322,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xj_emlrtRSI{ 324,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yj_emlrtRSI{ 325,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ak_emlrtRSI{ 326,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bk_emlrtRSI{ 327,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ck_emlrtRSI{ 333,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dk_emlrtRSI{ 334,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ek_emlrtRSI{ 336,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fk_emlrtRSI{ 338,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gk_emlrtRSI{ 343,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hk_emlrtRSI{ 344,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ik_emlrtRSI{ 345,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jk_emlrtRSI{ 346,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo kk_emlrtRSI{ 352,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lk_emlrtRSI{ 353,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mk_emlrtRSI{ 355,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nk_emlrtRSI{ 356,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ok_emlrtRSI{ 360,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pk_emlrtRSI{ 362,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qk_emlrtRSI{ 363,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rk_emlrtRSI{ 364,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sk_emlrtRSI{ 365,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tk_emlrtRSI{ 371,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo uk_emlrtRSI{ 372,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vk_emlrtRSI{ 374,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wk_emlrtRSI{ 376,   // lineNo
  "Checkerboard/expandBoardDirectionally",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xk_emlrtRSI{ 425,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yk_emlrtRSI{ 441,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo al_emlrtRSI{ 451,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo bl_emlrtRSI{ 455,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo cl_emlrtRSI{ 472,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dl_emlrtRSI{ 474,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo el_emlrtRSI{ 478,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fl_emlrtRSI{ 490,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gl_emlrtRSI{ 504,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hl_emlrtRSI{ 505,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo xl_emlrtRSI{ 575,   // lineNo
  "Checkerboard/fitPolyCurve",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jn_emlrtRSI{ 636,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo kn_emlrtRSI{ 637,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ln_emlrtRSI{ 639,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mn_emlrtRSI{ 640,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nn_emlrtRSI{ 644,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo on_emlrtRSI{ 645,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pn_emlrtRSI{ 650,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qn_emlrtRSI{ 652,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rn_emlrtRSI{ 662,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sn_emlrtRSI{ 663,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tn_emlrtRSI{ 665,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo un_emlrtRSI{ 667,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vn_emlrtRSI{ 669,   // lineNo
  "Checkerboard/findClosestOnCurve",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo wn_emlrtRSI{ 19,    // lineNo
  "setdiff",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\setdiff.m"// pathName
};

static emlrtRSInfo xn_emlrtRSI{ 70,    // lineNo
  "eml_setop",                         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"// pathName
};

static emlrtRSInfo dp_emlrtRSI{ 15,    // lineNo
  "min",                               // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"// pathName
};

static emlrtRSInfo ep_emlrtRSI{ 46,    // lineNo
  "minOrMax",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo fp_emlrtRSI{ 92,    // lineNo
  "minimum",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"// pathName
};

static emlrtRSInfo gp_emlrtRSI{ 204,   // lineNo
  "unaryMinOrMax",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo hp_emlrtRSI{ 893,   // lineNo
  "minRealVectorOmitNaN",              // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+internal\\unaryMinOrMax.m"// pathName
};

static emlrtRSInfo ip_emlrtRSI{ 387,   // lineNo
  "Checkerboard/predictPointsVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jp_emlrtRSI{ 388,   // lineNo
  "Checkerboard/predictPointsVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo np_emlrtRSI{ 590,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo op_emlrtRSI{ 597,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pp_emlrtRSI{ 600,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qp_emlrtRSI{ 601,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rp_emlrtRSI{ 602,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sp_emlrtRSI{ 604,   // lineNo
  "Checkerboard/findClosestIndices",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tp_emlrtRSI{ 38,    // lineNo
  "ismember",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\ismember.m"// pathName
};

static emlrtRSInfo lq_emlrtRSI{ 743,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mq_emlrtRSI{ 744,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nq_emlrtRSI{ 746,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo oq_emlrtRSI{ 749,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo pq_emlrtRSI{ 759,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo qq_emlrtRSI{ 767,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo rq_emlrtRSI{ 768,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo sq_emlrtRSI{ 770,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo tq_emlrtRSI{ 774,   // lineNo
  "Checkerboard/computeNewEnergyVertical",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo uq_emlrtRSI{ 835,   // lineNo
  "Checkerboard/arrayFind",            // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo vq_emlrtRSI{ 837,   // lineNo
  "Checkerboard/arrayFind",            // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo yq_emlrtRSI{ 443,   // lineNo
  "Checkerboard/fitPolynomialIndices", // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ar_emlrtRSI{ 508,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo br_emlrtRSI{ 509,   // lineNo
  "Checkerboard/findIndependentVar",   // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo dr_emlrtRSI{ 578,   // lineNo
  "Checkerboard/fitPolyCurve",         // fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo er_emlrtRSI{ 401,   // lineNo
  "Checkerboard/predictPointsHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo fr_emlrtRSI{ 402,   // lineNo
  "Checkerboard/predictPointsHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo gr_emlrtRSI{ 788,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo hr_emlrtRSI{ 789,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo ir_emlrtRSI{ 791,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo jr_emlrtRSI{ 794,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo kr_emlrtRSI{ 804,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo lr_emlrtRSI{ 812,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo mr_emlrtRSI{ 813,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo nr_emlrtRSI{ 815,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtRSInfo or_emlrtRSI{ 819,   // lineNo
  "Checkerboard/computeNewEnergyHorizontal",// fcnName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pathName
};

static emlrtECInfo l_emlrtECI{ -1,     // nDims
  115,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yb_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI{ 115,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ac_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  115,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo m_emlrtECI{ -1,     // nDims
  114,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo cc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ec_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI{ 114,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  114,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo n_emlrtECI{ -1,     // nDims
  113,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo hc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ic_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI{ 113,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  113,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo o_emlrtECI{ -1,     // nDims
  112,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo mc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI{ 112,    // lineNo
  53,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  112,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  106,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo p_emlrtECI{ 2,      // nDims
  106,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo tc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  105,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo q_emlrtECI{ 2,      // nDims
  105,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo vc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  104,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo r_emlrtECI{ 2,      // nDims
  104,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo xc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yc_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  103,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo s_emlrtECI{ 2,      // nDims
  103,                                 // lineNo
  86,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo t_emlrtECI{ 2,      // nDims
  101,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo u_emlrtECI{ 2,      // nDims
  100,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo v_emlrtECI{ 2,      // nDims
  99,                                  // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo w_emlrtECI{ 2,      // nDims
  98,                                  // lineNo
  21,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo x_emlrtECI{ -1,     // nDims
  95,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ad_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  95,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI{ 94,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo dd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ed_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  94,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo y_emlrtECI{ -1,     // nDims
  93,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  93,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo s_emlrtDCI{ 92,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo id_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  92,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ab_emlrtECI{ -1,    // nDims
  91,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo kd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ld_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  91,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo md_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo t_emlrtDCI{ 90,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo nd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo od_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  90,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo bb_emlrtECI{ -1,    // nDims
  89,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo pd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  89,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo u_emlrtDCI{ 88,     // lineNo
  29,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo td_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  88,                                  // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ud_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  81,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yd_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ae_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  79,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo be_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ce_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  78,                                  // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo de_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ee_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  75,                                  // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo cb_emlrtECI{ -1,    // nDims
  68,                                  // lineNo
  13,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ge_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  68,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo he_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ie_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  67,                                  // lineNo
  27,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo je_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  66,                                  // lineNo
  34,                                  // colNo
  "",                                  // aName
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo v_emlrtDCI{ 66,     // lineNo
  34,                                  // colNo
  "Checkerboard/initialize",           // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo w_emlrtDCI{ 60,     // lineNo
  34,                                  // colNo
  "bsxfun",                            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m",// pName
  4                                    // checkKind
};

static emlrtECInfo db_emlrtECI{ -1,    // nDims
  235,                                 // lineNo
  38,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo eb_emlrtECI{ -1,    // nDims
  235,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ke_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo x_emlrtDCI{ 238,    // lineNo
  19,                                  // colNo
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo le_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  238,                                 // lineNo
  19,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo me_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  241,                                 // lineNo
  19,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ne_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  231,                                 // lineNo
  75,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  231,                                 // lineNo
  81,                                  // colNo
  "",                                  // aName
  "Checkerboard/findNeighbor",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo re_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  161,                                 // lineNo
  32,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo se_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo te_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ue_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ve_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  159,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo fb_emlrtECI{ 2,     // nDims
  158,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo gb_emlrtECI{ 2,     // nDims
  157,                                 // lineNo
  19,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo we_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xe_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ye_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo af_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  150,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo hb_emlrtECI{ 2,     // nDims
  149,                                 // lineNo
  21,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo ib_emlrtECI{ 2,     // nDims
  148,                                 // lineNo
  19,                                  // colNo
  "Checkerboard/computeInitialEnergy", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo bf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  252,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo y_emlrtDCI{ 252,    // lineNo
  36,                                  // colNo
  "Checkerboard/getPoints",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ab_emlrtDCI{ 279,   // lineNo
  20,                                  // colNo
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo cf_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  281,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo df_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  281,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ef_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  281,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ff_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  282,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  282,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  282,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo if_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  285,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  285,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  285,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lf_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  286,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  286,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  286,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo of_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  289,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  289,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  289,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rf_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  290,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  290,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  290,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uf_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  293,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  293,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  293,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xf_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  294,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yf_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  294,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ag_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  294,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/undoLastExpansion",    // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bg_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  300,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cg_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  300,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo bb_emlrtDCI{ 301,   // lineNo
  20,                                  // colNo
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo dg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  311,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  349,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  330,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  368,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ig_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  43,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo jb_emlrtECI{ 2,     // nDims
  389,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo jg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  401,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  402,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo kb_emlrtECI{ 2,     // nDims
  403,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo lg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  387,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo cb_emlrtDCI{ 387,   // lineNo
  43,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  388,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo db_emlrtDCI{ 388,   // lineNo
  43,                                  // colNo
  "Checkerboard/predictPointsVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ng_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  401,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo eb_emlrtDCI{ 401,   // lineNo
  46,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo og_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  402,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo fb_emlrtDCI{ 402,   // lineNo
  46,                                  // colNo
  "Checkerboard/predictPointsHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  311,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  349,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  330,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  368,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDirectionally",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ug_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  529,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yg_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  528,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo lb_emlrtECI{ 2,     // nDims
  505,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ah_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ch_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo mb_emlrtECI{ 2,     // nDims
  504,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo eh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo nb_emlrtECI{ 2,     // nDims
  503,                                 // lineNo
  30,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ih_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ob_emlrtECI{ -1,    // nDims
  480,                                 // lineNo
  25,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo kh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  441,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  441,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gb_emlrtDCI{ 428,   // lineNo
  38,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo mh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  105,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ph_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  105,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hb_emlrtDCI{ 428,   // lineNo
  17,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo qh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  462,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo th_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  480,                                 // lineNo
  36,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ib_emlrtDCI{ 575,   // lineNo
  65,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo uh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  575,                                 // lineNo
  65,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jb_emlrtDCI{ 575,   // lineNo
  74,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo vh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  575,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  576,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kb_emlrtDCI{ 576,   // lineNo
  57,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo xh_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  576,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
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

static emlrtDCInfo lb_emlrtDCI{ 575,   // lineNo
  55,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
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
  662,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo pb_emlrtECI{ 2,     // nDims
  663,                                 // lineNo
  45,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ci_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  639,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo nb_emlrtDCI{ 639,   // lineNo
  48,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo di_emlrtBCI{ 1,     // iFirst
  2,                                   // iLast
  645,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ob_emlrtDCI{ 645,   // lineNo
  45,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ei_emlrtBCI{ 1,     // iFirst
  2,                                   // iLast
  645,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pb_emlrtDCI{ 645,   // lineNo
  87,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo fi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  670,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  654,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qb_emlrtDCI{ 654,   // lineNo
  40,                                  // colNo
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  654,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ii_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  668,                                 // lineNo
  17,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ji_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  663,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestOnCurve",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ki_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  601,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo li_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  601,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  599,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ni_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  597,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  599,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  600,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sb_emlrtDCI{ 600,   // lineNo
  52,                                  // colNo
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  602,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ri_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  603,                                 // lineNo
  23,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo si_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ti_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  29,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ui_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  607,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findClosestIndices",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  679,                                 // lineNo
  22,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo qb_emlrtECI{ -1,    // nDims
  679,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo rb_emlrtECI{ -1,    // nDims
  680,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo wi_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  686,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo sb_emlrtECI{ -1,    // nDims
  686,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo tb_emlrtECI{ -1,    // nDims
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

static emlrtDCInfo tb_emlrtDCI{ 678,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ub_emlrtDCI{ 678,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo vb_emlrtDCI{ 678,   // lineNo
  56,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo wb_emlrtDCI{ 682,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo xb_emlrtDCI{ 682,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo yb_emlrtDCI{ 683,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ac_emlrtDCI{ 683,   // lineNo
  44,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo bc_emlrtDCI{ 678,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cc_emlrtDCI{ 678,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo dc_emlrtDCI{ 682,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ec_emlrtDCI{ 682,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
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

static emlrtDCInfo fc_emlrtDCI{ 686,   // lineNo
  58,                                  // colNo
  "Checkerboard/expandBoardUp",        // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
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

static emlrtBCInfo bj_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  775,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cj_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  775,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ub_emlrtECI{ 3,     // nDims
  766,                                 // lineNo
  29,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo dj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  92,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gc_emlrtDCI{ 766,   // lineNo
  92,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ej_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  85,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hc_emlrtDCI{ 766,   // lineNo
  54,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo vb_emlrtECI{ 3,     // nDims
  764,                                 // lineNo
  27,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo hj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ic_emlrtDCI{ 765,   // lineNo
  54,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ij_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  91,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jc_emlrtDCI{ 764,   // lineNo
  91,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  83,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kc_emlrtDCI{ 764,   // lineNo
  52,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  763,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  757,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo sj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  752,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  749,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  749,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo wb_emlrtECI{ 3,     // nDims
  746,                                 // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo vj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  88,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo xb_emlrtECI{ 3,     // nDims
  744,                                 // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo xj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yj_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  86,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ak_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo yb_emlrtECI{ 2,     // nDims
  738,                                 // lineNo
  24,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo bk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  739,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ck_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ek_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  93,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  49,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo hk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ik_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo kk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ok_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  542,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  526,                                 // lineNo
  20,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo lc_emlrtDCI{ 505,   // lineNo
  98,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  102,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo mc_emlrtDCI{ 505,   // lineNo
  58,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo rk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  505,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo nc_emlrtDCI{ 504,   // lineNo
  98,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  102,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo oc_emlrtDCI{ 504,   // lineNo
  58,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo tk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  504,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pc_emlrtDCI{ 503,   // lineNo
  74,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo uk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  78,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qc_emlrtDCI{ 503,   // lineNo
  44,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo vk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  503,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  543,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  556,                                 // lineNo
  67,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yk_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  694,                                 // lineNo
  22,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ac_emlrtECI{ -1,    // nDims
  694,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo al_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  695,                                 // lineNo
  22,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  695,                                 // lineNo
  24,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo bc_emlrtECI{ -1,    // nDims
  695,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo cl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo cc_emlrtECI{ -1,    // nDims
  701,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo dl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  703,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo el_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  703,                                 // lineNo
  30,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo dc_emlrtECI{ -1,    // nDims
  703,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rc_emlrtDCI{ 693,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo sc_emlrtDCI{ 693,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo tc_emlrtDCI{ 693,   // lineNo
  56,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo uc_emlrtDCI{ 697,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo vc_emlrtDCI{ 697,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo wc_emlrtDCI{ 698,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo xc_emlrtDCI{ 698,   // lineNo
  44,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo yc_emlrtDCI{ 693,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ad_emlrtDCI{ 693,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo bd_emlrtDCI{ 697,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo cd_emlrtDCI{ 697,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo gl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo dd_emlrtDCI{ 701,   // lineNo
  60,                                  // colNo
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  701,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardDown",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ed_emlrtDCI{ 766,   // lineNo
  85,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo il_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  89,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo fd_emlrtDCI{ 766,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo jl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  766,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo gd_emlrtDCI{ 765,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo kl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  765,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo hd_emlrtDCI{ 764,   // lineNo
  83,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ll_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo id_emlrtDCI{ 764,   // lineNo
  44,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ml_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  764,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jd_emlrtDCI{ 757,   // lineNo
  41,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo nl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  757,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kd_emlrtDCI{ 746,   // lineNo
  88,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ol_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  92,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ld_emlrtDCI{ 746,   // lineNo
  50,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  746,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo md_emlrtDCI{ 745,   // lineNo
  42,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ql_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  745,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo nd_emlrtDCI{ 744,   // lineNo
  86,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo rl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  90,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo od_emlrtDCI{ 744,   // lineNo
  48,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  744,                                 // lineNo
  52,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pd_emlrtDCI{ 739,   // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo tl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  739,                                 // lineNo
  35,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qd_emlrtDCI{ 738,   // lineNo
  68,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ul_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rd_emlrtDCI{ 738,   // lineNo
  38,                                  // colNo
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo vl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  738,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyVertical",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  62,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yl_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  532,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo am_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo cm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  531,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo ec_emlrtECI{ -1,    // nDims
  509,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo dm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo em_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  109,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo fm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  69,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo fc_emlrtECI{ -1,    // nDims
  508,                                 // lineNo
  41,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo hm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  116,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo im_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  109,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo km_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  69,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo gc_emlrtECI{ -1,    // nDims
  507,                                 // lineNo
  30,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo lm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  443,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo om_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  443,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sd_emlrtDCI{ 430,   // lineNo
  38,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
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

static emlrtDCInfo td_emlrtDCI{ 430,   // lineNo
  17,                                  // colNo
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo tm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  54,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo um_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  56,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  464,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolynomialIndices", // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ud_emlrtDCI{ 578,   // lineNo
  55,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo wm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo vd_emlrtDCI{ 578,   // lineNo
  74,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo xm_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ym_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo wd_emlrtDCI{ 579,   // lineNo
  57,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo an_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  578,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo xd_emlrtDCI{ 578,   // lineNo
  64,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo cn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  579,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo yd_emlrtDCI{ 579,   // lineNo
  47,                                  // colNo
  "Checkerboard/fitPolyCurve",         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo dn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  709,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo hc_emlrtECI{ -1,    // nDims
  709,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo ic_emlrtECI{ -1,    // nDims
  710,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo en_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo jc_emlrtECI{ -1,    // nDims
  716,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtECInfo kc_emlrtECI{ -1,    // nDims
  718,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ae_emlrtDCI{ 708,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo be_emlrtDCI{ 708,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo ce_emlrtDCI{ 708,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo de_emlrtDCI{ 712,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ee_emlrtDCI{ 713,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo fe_emlrtDCI{ 713,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ge_emlrtDCI{ 713,   // lineNo
  48,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo he_emlrtDCI{ 708,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ie_emlrtDCI{ 708,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo je_emlrtDCI{ 712,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ke_emlrtDCI{ 712,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo gn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo le_emlrtDCI{ 716,   // lineNo
  58,                                  // colNo
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo hn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  716,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardLeft",      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo in_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  820,                                 // lineNo
  64,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jn_emlrtBCI{ 0,     // iFirst
  MAX_int32_T,                         // iLast
  820,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo lc_emlrtECI{ 3,     // nDims
  811,                                 // lineNo
  29,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo kn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ln_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  85,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo me_emlrtDCI{ 811,   // lineNo
  85,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo nn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ne_emlrtDCI{ 811,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtECInfo mc_emlrtECI{ 3,     // nDims
  809,                                 // lineNo
  27,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo on_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo pn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo oe_emlrtDCI{ 810,   // lineNo
  46,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  94,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo rn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  83,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pe_emlrtDCI{ 809,   // lineNo
  83,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  53,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo tn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qe_emlrtDCI{ 809,   // lineNo
  44,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo un_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  808,                                 // lineNo
  46,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  802,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo wn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  76,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo xn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  66,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo yn_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  47,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ao_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  797,                                 // lineNo
  39,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo bo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  794,                                 // lineNo
  87,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo co_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  794,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo nc_emlrtECI{ 3,     // nDims
  791,                                 // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo do_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  97,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo eo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo oc_emlrtECI{ 3,     // nDims
  789,                                 // lineNo
  31,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  51,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo go_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  95,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ho_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo pc_emlrtECI{ -1,    // nDims
  783,                                 // lineNo
  24,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo io_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  784,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  70,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ko_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  40,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo lo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo mo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  86,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo no_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo oo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo po_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  88,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo qo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ro_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo so_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  42,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo to_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  72,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo uo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  58,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo vo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  547,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo re_emlrtDCI{ 509,   // lineNo
  109,                                 // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo wo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  113,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo se_emlrtDCI{ 509,   // lineNo
  69,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo xo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  509,                                 // lineNo
  73,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo te_emlrtDCI{ 508,   // lineNo
  109,                                 // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo yo_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  113,                                 // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ue_emlrtDCI{ 508,   // lineNo
  69,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo ap_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  508,                                 // lineNo
  73,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo ve_emlrtDCI{ 507,   // lineNo
  76,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo bp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  80,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo we_emlrtDCI{ 507,   // lineNo
  46,                                  // colNo
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo cp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  507,                                 // lineNo
  50,                                  // colNo
  "",                                  // aName
  "Checkerboard/findIndependentVar",   // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  548,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/findSearchParams",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ep_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  724,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo qc_emlrtECI{ -1,    // nDims
  724,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo fp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  725,                                 // lineNo
  25,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo gp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  725,                                 // lineNo
  27,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo rc_emlrtECI{ -1,    // nDims
  725,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo hp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  38,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo sc_emlrtECI{ -1,    // nDims
  731,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo ip_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  733,                                 // lineNo
  31,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo jp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  733,                                 // lineNo
  33,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtECInfo tc_emlrtECI{ -1,    // nDims
  733,                                 // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtBCInfo kp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  28,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo xe_emlrtDCI{ 723,   // lineNo
  30,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ye_emlrtDCI{ 723,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo af_emlrtDCI{ 723,   // lineNo
  54,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo bf_emlrtDCI{ 727,   // lineNo
  36,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo cf_emlrtDCI{ 728,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo df_emlrtDCI{ 728,   // lineNo
  17,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ef_emlrtDCI{ 728,   // lineNo
  48,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo ff_emlrtDCI{ 723,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo gf_emlrtDCI{ 723,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtDCInfo hf_emlrtDCI{ 727,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtDCInfo if_emlrtDCI{ 727,   // lineNo
  13,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo lp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  60,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo jf_emlrtDCI{ 731,   // lineNo
  60,                                  // colNo
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo mp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  731,                                 // lineNo
  68,                                  // colNo
  "",                                  // aName
  "Checkerboard/expandBoardRight",     // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo kf_emlrtDCI{ 811,   // lineNo
  95,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo np_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  99,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo lf_emlrtDCI{ 811,   // lineNo
  55,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo op_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  811,                                 // lineNo
  59,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo mf_emlrtDCI{ 810,   // lineNo
  57,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo pp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  810,                                 // lineNo
  61,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo nf_emlrtDCI{ 809,   // lineNo
  94,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo qp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  98,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo of_emlrtDCI{ 809,   // lineNo
  53,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo rp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  809,                                 // lineNo
  57,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo pf_emlrtDCI{ 802,   // lineNo
  44,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo sp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  802,                                 // lineNo
  48,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo qf_emlrtDCI{ 791,   // lineNo
  97,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo tp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  101,                                 // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo rf_emlrtDCI{ 791,   // lineNo
  59,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo up_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  791,                                 // lineNo
  63,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo sf_emlrtDCI{ 790,   // lineNo
  51,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo vp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  790,                                 // lineNo
  55,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo tf_emlrtDCI{ 789,   // lineNo
  95,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo wp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  99,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo uf_emlrtDCI{ 789,   // lineNo
  57,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo xp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  789,                                 // lineNo
  61,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo vf_emlrtDCI{ 784,   // lineNo
  33,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo yp_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  784,                                 // lineNo
  37,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo wf_emlrtDCI{ 783,   // lineNo
  70,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo aq_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  74,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo xf_emlrtDCI{ 783,   // lineNo
  40,                                  // colNo
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  1                                    // checkKind
};

static emlrtBCInfo bq_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  783,                                 // lineNo
  44,                                  // colNo
  "",                                  // aName
  "Checkerboard/computeNewEnergyHorizontal",// fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo dx_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  41,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtBCInfo ex_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  45,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtDCInfo dh_emlrtDCI{ 833,   // lineNo
  33,                                  // colNo
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  4                                    // checkKind
};

static emlrtBCInfo fx_emlrtBCI{ -1,    // iFirst
  -1,                                  // iLast
  835,                                 // lineNo
  26,                                  // colNo
  "",                                  // aName
  "Checkerboard/arrayFind",            // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m",// pName
  0                                    // checkKind
};

static emlrtRTEInfo bg_emlrtRTEI{ 60,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cg_emlrtRTEI{ 61,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dg_emlrtRTEI{ 63,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eg_emlrtRTEI{ 64,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fg_emlrtRTEI{ 65,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gg_emlrtRTEI{ 66,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hg_emlrtRTEI{ 68,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jg_emlrtRTEI{ 75,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kg_emlrtRTEI{ 75,  // lineNo
  56,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lg_emlrtRTEI{ 83,  // lineNo
  20,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mg_emlrtRTEI{ 88,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ng_emlrtRTEI{ 89,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo og_emlrtRTEI{ 90,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pg_emlrtRTEI{ 91,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qg_emlrtRTEI{ 92,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rg_emlrtRTEI{ 93,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sg_emlrtRTEI{ 94,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tg_emlrtRTEI{ 95,  // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ug_emlrtRTEI{ 98,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vg_emlrtRTEI{ 99,  // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wg_emlrtRTEI{ 100, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xg_emlrtRTEI{ 101, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yg_emlrtRTEI{ 103, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ah_emlrtRTEI{ 104, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bh_emlrtRTEI{ 105, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ch_emlrtRTEI{ 106, // lineNo
  86,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dh_emlrtRTEI{ 107, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eh_emlrtRTEI{ 112, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fh_emlrtRTEI{ 112, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gh_emlrtRTEI{ 113, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hh_emlrtRTEI{ 113, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ih_emlrtRTEI{ 114, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jh_emlrtRTEI{ 114, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kh_emlrtRTEI{ 115, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lh_emlrtRTEI{ 115, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oh_emlrtRTEI{ 76,  // lineNo
  9,                                   // colNo
  "eml_mtimes_helper",                 // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"// pName
};

static emlrtRTEInfo ph_emlrtRTEI{ 235, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qh_emlrtRTEI{ 235, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rh_emlrtRTEI{ 238, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sh_emlrtRTEI{ 227, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo th_emlrtRTEI{ 238, // lineNo
  19,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uh_emlrtRTEI{ 136, // lineNo
  20,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vh_emlrtRTEI{ 144, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wh_emlrtRTEI{ 145, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xh_emlrtRTEI{ 146, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yh_emlrtRTEI{ 148, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ai_emlrtRTEI{ 148, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bi_emlrtRTEI{ 149, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ci_emlrtRTEI{ 153, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo di_emlrtRTEI{ 154, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ei_emlrtRTEI{ 155, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fi_emlrtRTEI{ 157, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gi_emlrtRTEI{ 157, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hi_emlrtRTEI{ 158, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ii_emlrtRTEI{ 281, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ji_emlrtRTEI{ 282, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ki_emlrtRTEI{ 285, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo li_emlrtRTEI{ 286, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mi_emlrtRTEI{ 289, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ni_emlrtRTEI{ 290, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oi_emlrtRTEI{ 293, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pi_emlrtRTEI{ 294, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qi_emlrtRTEI{ 387, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ri_emlrtRTEI{ 388, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo si_emlrtRTEI{ 389, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ti_emlrtRTEI{ 317, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ui_emlrtRTEI{ 317, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vi_emlrtRTEI{ 322, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wi_emlrtRTEI{ 336, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xi_emlrtRTEI{ 336, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yi_emlrtRTEI{ 337, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo aj_emlrtRTEI{ 401, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bj_emlrtRTEI{ 402, // lineNo
  26,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cj_emlrtRTEI{ 403, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dj_emlrtRTEI{ 355, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ej_emlrtRTEI{ 355, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fj_emlrtRTEI{ 360, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gj_emlrtRTEI{ 374, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hj_emlrtRTEI{ 374, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ij_emlrtRTEI{ 375, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jj_emlrtRTEI{ 503, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kj_emlrtRTEI{ 503, // lineNo
  60,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lj_emlrtRTEI{ 425, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mj_emlrtRTEI{ 504, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nj_emlrtRTEI{ 504, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oj_emlrtRTEI{ 505, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pj_emlrtRTEI{ 505, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qj_emlrtRTEI{ 428, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rj_emlrtRTEI{ 433, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sj_emlrtRTEI{ 441, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tj_emlrtRTEI{ 441, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uj_emlrtRTEI{ 414, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vj_emlrtRTEI{ 575, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wj_emlrtRTEI{ 576, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ek_emlrtRTEI{ 70,  // lineNo
  35,                                  // colNo
  "eml_setop",                         // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"// pName
};

static emlrtRTEInfo fk_emlrtRTEI{ 639, // lineNo
  36,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gk_emlrtRTEI{ 640, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hk_emlrtRTEI{ 640, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ik_emlrtRTEI{ 642, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jk_emlrtRTEI{ 672, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kk_emlrtRTEI{ 631, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lk_emlrtRTEI{ 670, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mk_emlrtRTEI{ 645, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nk_emlrtRTEI{ 652, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ok_emlrtRTEI{ 652, // lineNo
  61,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pk_emlrtRTEI{ 652, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qk_emlrtRTEI{ 650, // lineNo
  32,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rk_emlrtRTEI{ 650, // lineNo
  45,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sk_emlrtRTEI{ 650, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tk_emlrtRTEI{ 654, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uk_emlrtRTEI{ 660, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vk_emlrtRTEI{ 662, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wk_emlrtRTEI{ 663, // lineNo
  45,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xk_emlrtRTEI{ 667, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yk_emlrtRTEI{ 668, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ql_emlrtRTEI{ 587, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sl_emlrtRTEI{ 597, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tl_emlrtRTEI{ 600, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ul_emlrtRTEI{ 601, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vl_emlrtRTEI{ 601, // lineNo
  44,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wl_emlrtRTEI{ 585, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xl_emlrtRTEI{ 602, // lineNo
  44,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo am_emlrtRTEI{ 678, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bm_emlrtRTEI{ 679, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cm_emlrtRTEI{ 680, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dm_emlrtRTEI{ 680, // lineNo
  29,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo em_emlrtRTEI{ 682, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fm_emlrtRTEI{ 686, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gm_emlrtRTEI{ 677, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hm_emlrtRTEI{ 686, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo im_emlrtRTEI{ 688, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jm_emlrtRTEI{ 688, // lineNo
  35,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo km_emlrtRTEI{ 688, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lm_emlrtRTEI{ 738, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mm_emlrtRTEI{ 738, // lineNo
  54,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nm_emlrtRTEI{ 739, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo om_emlrtRTEI{ 737, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pm_emlrtRTEI{ 744, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qm_emlrtRTEI{ 744, // lineNo
  69,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rm_emlrtRTEI{ 745, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sm_emlrtRTEI{ 745, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tm_emlrtRTEI{ 746, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo um_emlrtRTEI{ 746, // lineNo
  71,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vm_emlrtRTEI{ 749, // lineNo
  35,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wm_emlrtRTEI{ 749, // lineNo
  46,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xm_emlrtRTEI{ 749, // lineNo
  65,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ym_emlrtRTEI{ 749, // lineNo
  78,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo an_emlrtRTEI{ 757, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bn_emlrtRTEI{ 764, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cn_emlrtRTEI{ 764, // lineNo
  66,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dn_emlrtRTEI{ 765, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo en_emlrtRTEI{ 764, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fn_emlrtRTEI{ 766, // lineNo
  29,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gn_emlrtRTEI{ 766, // lineNo
  68,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hn_emlrtRTEI{ 766, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo in_emlrtRTEI{ 693, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jn_emlrtRTEI{ 694, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kn_emlrtRTEI{ 695, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ln_emlrtRTEI{ 695, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mn_emlrtRTEI{ 697, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo nn_emlrtRTEI{ 701, // lineNo
  43,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo on_emlrtRTEI{ 692, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pn_emlrtRTEI{ 701, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qn_emlrtRTEI{ 703, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rn_emlrtRTEI{ 703, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sn_emlrtRTEI{ 703, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tn_emlrtRTEI{ 507, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo un_emlrtRTEI{ 507, // lineNo
  60,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vn_emlrtRTEI{ 508, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wn_emlrtRTEI{ 508, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xn_emlrtRTEI{ 509, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yn_emlrtRTEI{ 509, // lineNo
  81,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ao_emlrtRTEI{ 430, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bo_emlrtRTEI{ 443, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo co_emlrtRTEI{ 443, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo eo_emlrtRTEI{ 578, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fo_emlrtRTEI{ 579, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo go_emlrtRTEI{ 708, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ho_emlrtRTEI{ 709, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo io_emlrtRTEI{ 710, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jo_emlrtRTEI{ 710, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ko_emlrtRTEI{ 712, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lo_emlrtRTEI{ 716, // lineNo
  41,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mo_emlrtRTEI{ 707, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo no_emlrtRTEI{ 716, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo oo_emlrtRTEI{ 718, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo po_emlrtRTEI{ 718, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qo_emlrtRTEI{ 718, // lineNo
  38,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ro_emlrtRTEI{ 783, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo so_emlrtRTEI{ 783, // lineNo
  54,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo to_emlrtRTEI{ 784, // lineNo
  17,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo uo_emlrtRTEI{ 782, // lineNo
  30,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vo_emlrtRTEI{ 789, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wo_emlrtRTEI{ 789, // lineNo
  69,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xo_emlrtRTEI{ 790, // lineNo
  23,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yo_emlrtRTEI{ 791, // lineNo
  33,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ap_emlrtRTEI{ 791, // lineNo
  71,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo bp_emlrtRTEI{ 794, // lineNo
  35,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo cp_emlrtRTEI{ 794, // lineNo
  46,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo dp_emlrtRTEI{ 794, // lineNo
  65,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ep_emlrtRTEI{ 794, // lineNo
  78,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo fp_emlrtRTEI{ 802, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo gp_emlrtRTEI{ 809, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo hp_emlrtRTEI{ 809, // lineNo
  66,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ip_emlrtRTEI{ 810, // lineNo
  27,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo jp_emlrtRTEI{ 809, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo kp_emlrtRTEI{ 811, // lineNo
  29,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo lp_emlrtRTEI{ 811, // lineNo
  68,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo mp_emlrtRTEI{ 811, // lineNo
  21,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo np_emlrtRTEI{ 723, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo op_emlrtRTEI{ 724, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo pp_emlrtRTEI{ 725, // lineNo
  22,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo qp_emlrtRTEI{ 725, // lineNo
  25,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo rp_emlrtRTEI{ 727, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo sp_emlrtRTEI{ 731, // lineNo
  43,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo tp_emlrtRTEI{ 722, // lineNo
  47,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo up_emlrtRTEI{ 731, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo vp_emlrtRTEI{ 733, // lineNo
  28,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wp_emlrtRTEI{ 733, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xp_emlrtRTEI{ 733, // lineNo
  40,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo wx_emlrtRTEI{ 833, // lineNo
  24,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo xx_emlrtRTEI{ 835, // lineNo
  37,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo yx_emlrtRTEI{ 837, // lineNo
  31,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

static emlrtRTEInfo ay_emlrtRTEI{ 837, // lineNo
  13,                                  // colNo
  "Checkerboard",                      // fName
  "C:\\Program Files\\MATLAB\\R2021a\\toolbox\\vision\\vision\\+vision\\+internal\\+calibration\\+checkerboard\\Checkerboard.m"// pName
};

// Function Definitions
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
            array<int32_T, 2U> b_ii;
            array<int8_T, 2U> matchArr;
            array<boolean_T, 2U> x;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack st;
            int32_T idx;
            int32_T ii;
            int32_T nx;
            boolean_T b_arr[3];
            boolean_T exitg1;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            c_st.prev = &b_st;
            c_st.tls = b_st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            matchArr.set_size(&wx_emlrtRTEI, sp, 1, matchArr.size(1));
            if (arr.size(1) - 2 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(arr.size(1) - 2),
                &dh_emlrtDCI, (emlrtCTX)sp);
            }

            matchArr.set_size(&wx_emlrtRTEI, sp, matchArr.size(0), arr.size(1) -
                              2);
            ii = arr.size(1);
            for (idx = 0; idx <= ii - 3; idx++) {
              if (idx + 1 > arr.size(1)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, arr.size(1),
                  &dx_emlrtBCI, (emlrtCTX)sp);
              }

              if (idx + 3 > arr.size(1)) {
                emlrtDynamicBoundsCheckR2012b(idx + 3, 1, arr.size(1),
                  &ex_emlrtBCI, (emlrtCTX)sp);
              }

              b_ii.set_size(&xx_emlrtRTEI, sp, 1, 3);
              for (nx = 0; nx < 3; nx++) {
                b_ii[nx] = arr[idx + nx];
              }

              b_arr[0] = (b_ii[0] == 1);
              b_arr[1] = (b_ii[1] == 1);
              b_arr[2] = (b_ii[2] == 1);
              if (idx + 1 > matchArr.size(1)) {
                emlrtDynamicBoundsCheckR2012b(idx + 1, 1, matchArr.size(1),
                  &fx_emlrtBCI, (emlrtCTX)sp);
              }

              st.site = &uq_emlrtRSI;
              matchArr[idx] = static_cast<int8_T>(c_all(b_arr));
            }

            st.site = &vq_emlrtRSI;
            x.set_size(&yx_emlrtRTEI, &st, 1, matchArr.size(1));
            nx = matchArr.size(1);
            for (ii = 0; ii < nx; ii++) {
              x[ii] = (matchArr[ii] == 1);
            }

            b_st.site = &jf_emlrtRSI;
            nx = x.size(1);
            c_st.site = &kf_emlrtRSI;
            idx = 0;
            b_ii.set_size(&do_emlrtRTEI, &c_st, 1, x.size(1));
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
              emlrtErrorWithMessageIdR2018a(&c_st, &t_emlrtRTEI,
                "Coder:builtins:AssertionFailed",
                "Coder:builtins:AssertionFailed", 0);
            }

            if (x.size(1) == 1) {
              if (idx == 0) {
                b_ii.set_size(&rl_emlrtRTEI, &c_st, 1, 0);
              }
            } else {
              if (1 > idx) {
                idx = 0;
              }

              b_ii.set_size(&rl_emlrtRTEI, &c_st, b_ii.size(0), idx);
            }

            matchedIdx.set_size(&ay_emlrtRTEI, &st, 1, b_ii.size(1));
            nx = b_ii.size(1);
            for (ii = 0; ii < nx; ii++) {
              matchedIdx[ii] = b_ii[ii];
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::b_fitPolynomialIndices(const emlrtStack *sp, ::
            coder::array<real_T, 2U> &newIndices) const
          {
            array<real_T, 2U> b_index;
            array<real_T, 2U> currCurve;
            array<real_T, 2U> removedIdx;
            array<real_T, 2U> validIdx;
            array<real_T, 1U> r3;
            array<real_T, 1U> r5;
            array<int32_T, 2U> ii;
            array<int32_T, 1U> r2;
            array<int32_T, 1U> r4;
            array<int32_T, 1U> r6;
            array<int32_T, 1U> r7;
            array<boolean_T, 1U> r;
            array<boolean_T, 1U> r1;
            emlrtStack b_st;
            emlrtStack st;
            real_T coordsToUse[2];
            real_T currPt[2];
            real_T currRad;
            real_T x;
            real_T y;
            int32_T b_i;
            int32_T i;
            int32_T loop_ub;
            int32_T trueCount;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            st.site = &xk_emlrtRSI;
            i = BoardIdx.size(1);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &mm_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&tn_emlrtRTEI, &st, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[i] > 0.0);
            }

            i = BoardIdx.size(1);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &lm_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&un_emlrtRTEI, &st, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0)] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &gc_emlrtECI, &st);
            }

            loop_ub = r.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r2.set_size(&lj_emlrtRTEI, &st, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r2[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(1);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &km_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &jm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            r3.set_size(&vn_emlrtRTEI, &st, r2.size(0));
            loop_ub = r2.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r2[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &pm_emlrtBCI,
                  &st);
              }

              r3[i] = BoardCoords[(r2[i] + BoardCoords.size(0)) - 1];
            }

            loop_ub = r.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r4.set_size(&lj_emlrtRTEI, &st, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r4[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(1);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &im_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &hm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            r5.set_size(&wn_emlrtRTEI, &st, r4.size(0));
            loop_ub = r4.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r4[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &qm_emlrtBCI,
                  &st);
              }

              r5[i] = BoardCoords[r4[i] - 1];
            }

            if (r3.size(0) != r5.size(0)) {
              emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &fc_emlrtECI, &st);
            }

            loop_ub = r3.size(0);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = r3[i] - r5[i];
            }

            b_st.site = &ar_emlrtRSI;
            x = mean(&b_st, r3);
            loop_ub = r.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r6.set_size(&lj_emlrtRTEI, &st, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r6[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(1);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &gm_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &fm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            r3.set_size(&xn_emlrtRTEI, &st, r6.size(0));
            loop_ub = r6.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r6[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r6[i], 1, trueCount, &rm_emlrtBCI,
                  &st);
              }

              r3[i] = BoardCoords[((r6[i] + BoardCoords.size(0)) +
                                   BoardCoords.size(0) * BoardCoords.size(1)) -
                1];
            }

            loop_ub = r.size(0) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r7.set_size(&lj_emlrtRTEI, &st, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r7[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(1);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &em_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &dm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            r5.set_size(&yn_emlrtRTEI, &st, r7.size(0));
            loop_ub = r7.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r7[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r7[i], 1, trueCount, &sm_emlrtBCI,
                  &st);
              }

              r5[i] = BoardCoords[(r7[i] + BoardCoords.size(0) *
                                   BoardCoords.size(1)) - 1];
            }

            if (r3.size(0) != r5.size(0)) {
              emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &ec_emlrtECI, &st);
            }

            loop_ub = r3.size(0);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = r3[i] - r5[i];
            }

            b_st.site = &br_emlrtRSI;
            currRad = mean(&b_st, r3);
            if (muDoubleScalarAbs(x) > muDoubleScalarAbs(currRad)) {
              coordsToUse[0] = 1.0;
              coordsToUse[1] = 2.0;
            } else {
              coordsToUse[0] = 2.0;
              coordsToUse[1] = 1.0;
            }

            newIndices.set_size(&ao_emlrtRTEI, sp, 1, newIndices.size(1));
            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &sd_emlrtDCI,
                (emlrtCTX)sp);
            }

            newIndices.set_size(&ao_emlrtRTEI, sp, newIndices.size(0), i);
            loop_ub = BoardCoords.size(0);
            if (loop_ub < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(loop_ub),
                &td_emlrtDCI, (emlrtCTX)sp);
            }

            for (i = 0; i < loop_ub; i++) {
              newIndices[i] = 0.0;
            }

            removedIdx.set_size(&rj_emlrtRTEI, sp, 1, 0);
            i = BoardCoords.size(0);
            for (int32_T j{0}; j < i; j++) {
              int32_T i1;
              st.site = &yq_emlrtRSI;
              i1 = BoardCoords.size(0);
              if ((j + 1 < 1) || (j + 1 > i1)) {
                emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &om_emlrtBCI, &st);
              }

              i1 = BoardCoords.size(2);
              b_i = static_cast<int32_T>(coordsToUse[0]);
              if (b_i > i1) {
                emlrtDynamicBoundsCheckR2012b(b_i, 1, i1, &nm_emlrtBCI, &st);
              }

              loop_ub = BoardCoords.size(1);
              validIdx.set_size(&bo_emlrtRTEI, &st, 1, loop_ub);
              for (i1 = 0; i1 < loop_ub; i1++) {
                validIdx[i1] = BoardCoords[(j + BoardCoords.size(0) * i1) +
                  BoardCoords.size(0) * BoardCoords.size(1) * (b_i - 1)];
              }

              b_st.site = &jf_emlrtRSI;
              b_eml_find(&b_st, validIdx, ii);
              validIdx.set_size(&co_emlrtRTEI, &st, 1, ii.size(1));
              loop_ub = ii.size(1);
              for (i1 = 0; i1 < loop_ub; i1++) {
                validIdx[i1] = ii[i1];
              }

              if (validIdx.size(1) >= 2) {
                real_T currCoord;
                real_T refCoordValue;
                boolean_T exitg1;
                st.site = &al_emlrtRSI;
                i1 = BoardCoords.size(0);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &cm_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(1);
                trueCount = static_cast<int32_T>(validIdx[0]);
                if ((trueCount < 1) || (trueCount > i1)) {
                  emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &bm_emlrtBCI,
                    &st);
                }

                i1 = BoardCoords.size(2);
                if (b_i > i1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i1, &am_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(0);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &yl_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(1);
                loop_ub = static_cast<int32_T>(validIdx[1]);
                if ((loop_ub < 1) || (loop_ub > i1)) {
                  emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &xl_emlrtBCI,
                    &st);
                }

                i1 = BoardCoords.size(2);
                if (b_i > i1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i1, &wl_emlrtBCI, &st);
                }

                x = (BoardCoords[(j + BoardCoords.size(0) * (trueCount - 1)) +
                     BoardCoords.size(0) * BoardCoords.size(1) * (b_i - 1)] -
                     BoardCoords[(j + BoardCoords.size(0) * (loop_ub - 1)) +
                     BoardCoords.size(0) * BoardCoords.size(1) * (b_i - 1)]) /
                  static_cast<real_T>(loop_ub - trueCount);
                st.site = &bl_emlrtRSI;
                fitPolyCurve(&st, validIdx, static_cast<real_T>(j) + 1.0,
                             coordsToUse, currCurve);
                currRad = x / 4.0;
                i1 = BoardCoords.size(0);
                if ((j + 1 < 1) || (j + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(j + 1, 1, i1, &tm_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if (trueCount > i1) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx[0]),
                    1, i1, &um_emlrtBCI, (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(2);
                if (b_i > i1) {
                  emlrtDynamicBoundsCheckR2012b(b_i, 1, i1, &vm_emlrtBCI,
                    (emlrtCTX)sp);
                }

                refCoordValue = BoardCoords[(j + BoardCoords.size(0) *
                  (trueCount - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                  (b_i - 1)];
                currCoord = currRad + refCoordValue;
                exitg1 = false;
                while ((!exitg1) && (muDoubleScalarAbs(currCoord - refCoordValue)
                                     < static_cast<real_T>(static_cast<int32_T>
                         (validIdx[0])) * 1.5 * muDoubleScalarAbs(x))) {
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
                    st.site = &cl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      i1 = currCurve.size(1);
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = currCoord;
                    currPt[1] = y;
                  } else {
                    st.site = &dl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      i1 = currCurve.size(1);
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = y;
                    currPt[1] = currCoord;
                  }

                  st.site = &el_emlrtRSI;
                  findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                     currCurve, coordsToUse, removedIdx, b_index);
                  if (b_index.size(1) != 0) {
                    if (1 != b_index.size(1)) {
                      emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                        &ob_emlrtECI, (emlrtCTX)sp);
                    }

                    if ((j + 1 < 1) || (j + 1 > newIndices.size(1))) {
                      emlrtDynamicBoundsCheckR2012b(j + 1, 1, newIndices.size(1),
                        &th_emlrtBCI, (emlrtCTX)sp);
                    }

                    newIndices[j] = b_index[0];
                    i1 = removedIdx.size(1);
                    loop_ub = b_index.size(1);
                    removedIdx.set_size(&uj_emlrtRTEI, sp, removedIdx.size(0),
                                        removedIdx.size(1) + b_index.size(1));
                    for (b_i = 0; b_i < loop_ub; b_i++) {
                      removedIdx[i1 + b_i] = b_index[b_i];
                    }

                    exitg1 = true;
                  } else {
                    currCoord += currRad;
                  }
                }
              }
            }

            st.site = &fl_emlrtRSI;
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::b_fitPolynomialIndices(const emlrtStack *sp, const ::
            coder::array<real_T, 2U> &idx, ::coder::array<real_T, 2U>
            &newIndices) const
          {
            array<real_T, 2U> currCurve;
            array<real_T, 2U> removedIdx;
            array<real_T, 2U> validIdx;
            array<real_T, 1U> r3;
            array<real_T, 1U> r5;
            array<int32_T, 2U> ii;
            array<int32_T, 1U> r2;
            array<int32_T, 1U> r4;
            array<int32_T, 1U> r6;
            array<int32_T, 1U> r7;
            array<boolean_T, 1U> r;
            array<boolean_T, 1U> r1;
            emlrtStack b_st;
            emlrtStack st;
            real_T coordsToUse[2];
            real_T currPt[2];
            real_T b_x;
            real_T x;
            real_T y;
            int32_T b_i;
            int32_T b_idx;
            int32_T c_idx;
            int32_T end;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            int32_T trueCount;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            st.site = &xk_emlrtRSI;
            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &cp_emlrtBCI, &st);
            }

            i = BoardIdx.size(1);
            b_i = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &we_emlrtDCI, &st);
            }

            b_idx = static_cast<int32_T>(idx[0]);
            if ((b_idx < 1) || (b_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &mm_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&tn_emlrtRTEI, &st, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[i + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &bp_emlrtBCI, &st);
            }

            i = BoardIdx.size(1);
            i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &ve_emlrtDCI, &st);
            }

            c_idx = static_cast<int32_T>(idx[1]);
            if ((c_idx < 1) || (c_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &lm_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&un_emlrtRTEI, &st, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0) * (c_idx - 1)] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &gc_emlrtECI, &st);
            }

            end = r.size(0) - 1;
            trueCount = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r2.set_size(&lj_emlrtRTEI, &st, trueCount);
            loop_ub = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                r2[loop_ub] = i + 1;
                loop_ub++;
              }
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ap_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &jm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            i = BoardCoords.size(1);
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &ue_emlrtDCI, &st);
            }

            if (c_idx > i) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &km_emlrtBCI, &st);
            }

            r3.set_size(&vn_emlrtRTEI, &st, r2.size(0));
            loop_ub = r2.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r2[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &pm_emlrtBCI,
                  &st);
              }

              r3[i] = BoardCoords[(r2[i] + BoardCoords.size(0) * (c_idx - 1)) -
                1];
            }

            end = r.size(0) - 1;
            trueCount = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r4.set_size(&lj_emlrtRTEI, &st, trueCount);
            loop_ub = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                r4[loop_ub] = i + 1;
                loop_ub++;
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &yo_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &hm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            i = BoardCoords.size(1);
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &te_emlrtDCI, &st);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &im_emlrtBCI, &st);
            }

            r5.set_size(&wn_emlrtRTEI, &st, r4.size(0));
            loop_ub = r4.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r4[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &qm_emlrtBCI,
                  &st);
              }

              r5[i] = BoardCoords[(r4[i] + BoardCoords.size(0) * (b_idx - 1)) -
                1];
            }

            if (r3.size(0) != r5.size(0)) {
              emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &fc_emlrtECI, &st);
            }

            loop_ub = r3.size(0);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = r3[i] - r5[i];
            }

            b_st.site = &ar_emlrtRSI;
            x = mean(&b_st, r3);
            end = r.size(0) - 1;
            trueCount = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r6.set_size(&lj_emlrtRTEI, &st, trueCount);
            loop_ub = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                r6[loop_ub] = i + 1;
                loop_ub++;
              }
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &xo_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &fm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            i = BoardCoords.size(1);
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &se_emlrtDCI, &st);
            }

            if (c_idx > i) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &gm_emlrtBCI, &st);
            }

            r3.set_size(&xn_emlrtRTEI, &st, r6.size(0));
            loop_ub = r6.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r6[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r6[i], 1, trueCount, &rm_emlrtBCI,
                  &st);
              }

              r3[i] = BoardCoords[((r6[i] + BoardCoords.size(0) * (c_idx - 1)) +
                                   BoardCoords.size(0) * BoardCoords.size(1)) -
                1];
            }

            end = r.size(0) - 1;
            trueCount = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r7.set_size(&lj_emlrtRTEI, &st, trueCount);
            loop_ub = 0;
            for (i = 0; i <= end; i++) {
              if (r[i] && r1[i]) {
                r7[loop_ub] = i + 1;
                loop_ub++;
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &wo_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &dm_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(0);
            i = BoardCoords.size(1);
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &re_emlrtDCI, &st);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &em_emlrtBCI, &st);
            }

            r5.set_size(&yn_emlrtRTEI, &st, r7.size(0));
            loop_ub = r7.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (r7[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r7[i], 1, trueCount, &sm_emlrtBCI,
                  &st);
              }

              r5[i] = BoardCoords[((r7[i] + BoardCoords.size(0) * (b_idx - 1)) +
                                   BoardCoords.size(0) * BoardCoords.size(1)) -
                1];
            }

            if (r3.size(0) != r5.size(0)) {
              emlrtSizeEqCheck1DR2012b(r3.size(0), r5.size(0), &ec_emlrtECI, &st);
            }

            loop_ub = r3.size(0);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = r3[i] - r5[i];
            }

            b_st.site = &br_emlrtRSI;
            b_x = mean(&b_st, r3);
            if (muDoubleScalarAbs(x) > muDoubleScalarAbs(b_x)) {
              coordsToUse[0] = 1.0;
              coordsToUse[1] = 2.0;
            } else {
              coordsToUse[0] = 2.0;
              coordsToUse[1] = 1.0;
            }

            newIndices.set_size(&ao_emlrtRTEI, sp, 1, newIndices.size(1));
            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &sd_emlrtDCI,
                (emlrtCTX)sp);
            }

            newIndices.set_size(&ao_emlrtRTEI, sp, newIndices.size(0), i);
            loop_ub = BoardCoords.size(0);
            if (loop_ub < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(loop_ub),
                &td_emlrtDCI, (emlrtCTX)sp);
            }

            for (i = 0; i < loop_ub; i++) {
              newIndices[i] = 0.0;
            }

            removedIdx.set_size(&rj_emlrtRTEI, sp, 1, 0);
            i = BoardCoords.size(0);
            for (end = 0; end < i; end++) {
              st.site = &yq_emlrtRSI;
              b_i = BoardCoords.size(0);
              if ((end + 1 < 1) || (end + 1 > b_i)) {
                emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &om_emlrtBCI, &st);
              }

              b_i = BoardCoords.size(2);
              i1 = static_cast<int32_T>(coordsToUse[0]);
              if (i1 > b_i) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &nm_emlrtBCI, &st);
              }

              loop_ub = BoardCoords.size(1);
              validIdx.set_size(&bo_emlrtRTEI, &st, 1, loop_ub);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                validIdx[b_i] = BoardCoords[(end + BoardCoords.size(0) * b_i) +
                  BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1)];
              }

              b_st.site = &jf_emlrtRSI;
              b_eml_find(&b_st, validIdx, ii);
              validIdx.set_size(&co_emlrtRTEI, &st, 1, ii.size(1));
              loop_ub = ii.size(1);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                validIdx[b_i] = ii[b_i];
              }

              if (validIdx.size(1) >= 2) {
                real_T currCoord;
                real_T currRad;
                real_T refCoordValue;
                boolean_T exitg1;
                st.site = &al_emlrtRSI;
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &pk_emlrtBCI,
                    &st);
                }

                if (idx[0] == 1.0) {
                  b_i = BoardCoords.size(0);
                  if ((end + 1 < 1) || (end + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &cm_emlrtBCI,
                      &st);
                  }

                  b_i = BoardCoords.size(1);
                  loop_ub = static_cast<int32_T>(validIdx[0]);
                  if ((loop_ub < 1) || (loop_ub > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_i, &bm_emlrtBCI,
                      &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &am_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(0);
                  if ((end + 1 < 1) || (end + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &yl_emlrtBCI,
                      &st);
                  }

                  b_i = BoardCoords.size(1);
                  trueCount = static_cast<int32_T>(validIdx[1]);
                  if ((trueCount < 1) || (trueCount > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i,
                      &xl_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &wl_emlrtBCI, &st);
                  }

                  x = loop_ub;
                  b_x = (BoardCoords[(end + BoardCoords.size(0) * (loop_ub - 1))
                         + BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1)]
                         - BoardCoords[(end + BoardCoords.size(0) * (trueCount -
                           1)) + BoardCoords.size(0) * BoardCoords.size(1) * (i1
                          - 1)]) / static_cast<real_T>(trueCount - loop_ub);
                } else {
                  b_i = BoardCoords.size(0);
                  if ((end + 1 < 1) || (end + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &vo_emlrtBCI,
                      &st);
                  }

                  b_i = BoardCoords.size(1);
                  trueCount = static_cast<int32_T>(validIdx[validIdx.size(1) - 1]);
                  if ((trueCount < 1) || (trueCount > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i,
                      &uo_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &to_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(0);
                  if ((end + 1 < 1) || (end + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &so_emlrtBCI,
                      &st);
                  }

                  b_i = BoardCoords.size(1);
                  if (validIdx.size(1) - 1 > validIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(validIdx.size(1) - 1, 1,
                      validIdx.size(1), &dp_emlrtBCI, &st);
                  }

                  trueCount = static_cast<int32_T>(validIdx[validIdx.size(1) - 2]);
                  if ((trueCount < 1) || (trueCount > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i,
                      &ro_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &qo_emlrtBCI, &st);
                  }

                  x = (static_cast<real_T>(BoardCoords.size(1)) -
                       static_cast<real_T>(static_cast<int32_T>
                        (validIdx[validIdx.size(1) - 1]))) + 1.0;
                  loop_ub = static_cast<int32_T>(validIdx[validIdx.size(1) - 1]);
                  if (validIdx.size(1) - 1 > validIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(validIdx.size(1) - 1, 1,
                      validIdx.size(1), &xk_emlrtBCI, &st);
                  }

                  b_x = (BoardCoords[(end + BoardCoords.size(0) *
                                      (static_cast<int32_T>
                                       (validIdx[validIdx.size(1) - 1]) - 1)) +
                         BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1)] -
                         BoardCoords[(end + BoardCoords.size(0) *
                                      (static_cast<int32_T>
                                       (validIdx[validIdx.size(1) - 2]) - 1)) +
                         BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1)]) /
                    (static_cast<real_T>(static_cast<int32_T>
                      (validIdx[validIdx.size(1) - 1])) - static_cast<real_T>(
                      static_cast<int32_T>(validIdx[validIdx.size(1) - 2])));
                }

                st.site = &bl_emlrtRSI;
                fitPolyCurve(&st, validIdx, static_cast<real_T>(end) + 1.0,
                             coordsToUse, currCurve);
                currRad = b_x / 4.0;
                b_i = BoardCoords.size(0);
                if ((end + 1 < 1) || (end + 1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(end + 1, 1, b_i, &tm_emlrtBCI,
                    (emlrtCTX)sp);
                }

                b_i = BoardCoords.size(1);
                if ((loop_ub < 1) || (loop_ub > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_i, &um_emlrtBCI,
                    (emlrtCTX)sp);
                }

                b_i = BoardCoords.size(2);
                if (i1 > b_i) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &vm_emlrtBCI,
                    (emlrtCTX)sp);
                }

                refCoordValue = BoardCoords[(end + BoardCoords.size(0) *
                  (loop_ub - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                  (i1 - 1)];
                currCoord = currRad + refCoordValue;
                exitg1 = false;
                while ((!exitg1) && (muDoubleScalarAbs(currCoord - refCoordValue)
                                     < x * 1.5 * muDoubleScalarAbs(b_x))) {
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
                    st.site = &cl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      b_i = currCurve.size(1);
                      for (trueCount = 0; trueCount <= b_i - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = currCoord;
                    currPt[1] = y;
                  } else {
                    st.site = &dl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      b_i = currCurve.size(1);
                      for (trueCount = 0; trueCount <= b_i - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = y;
                    currPt[1] = currCoord;
                  }

                  st.site = &el_emlrtRSI;
                  findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                     currCurve, coordsToUse, removedIdx,
                                     validIdx);
                  if (validIdx.size(1) != 0) {
                    if (1 != validIdx.size(1)) {
                      emlrtSubAssignSizeCheck1dR2017a(1, validIdx.size(1),
                        &ob_emlrtECI, (emlrtCTX)sp);
                    }

                    if ((end + 1 < 1) || (end + 1 > newIndices.size(1))) {
                      emlrtDynamicBoundsCheckR2012b(end + 1, 1, newIndices.size
                        (1), &th_emlrtBCI, (emlrtCTX)sp);
                    }

                    newIndices[end] = validIdx[0];
                    b_i = removedIdx.size(1);
                    loop_ub = validIdx.size(1);
                    removedIdx.set_size(&uj_emlrtRTEI, sp, removedIdx.size(0),
                                        removedIdx.size(1) + validIdx.size(1));
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      removedIdx[b_i + i1] = validIdx[i1];
                    }

                    exitg1 = true;
                  } else {
                    currCoord += currRad;
                  }
                }
              }
            }

            st.site = &fl_emlrtRSI;
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          real32_T Checkerboard::computeInitialEnergy(const emlrtStack *sp)
            const
          {
            array<real32_T, 2U> col1;
            array<real32_T, 2U> col2;
            array<real32_T, 2U> row3;
            array<boolean_T, 1U> b_this;
            emlrtStack st;
            int32_T b_iv[2];
            int32_T iv1[2];
            int32_T i;
            int32_T idx;
            real32_T x[3];
            real32_T e;
            st.prev = sp;
            st.tls = sp->tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            idx = BoardIdx.size(0) * BoardIdx.size(1);
            b_this.set_size(&uh_emlrtRTEI, sp, idx);
            for (i = 0; i < idx; i++) {
              b_this[i] = (BoardIdx[i] < 0.0);
            }

            st.site = &cj_emlrtRSI;
            if (b_any(&st, b_this)) {
              e = rtInfF;
            } else {
              real_T d;
              int32_T c_this;
              int32_T loop_ub;
              real32_T b_ex;
              real32_T ex;
              real32_T f;
              boolean_T exitg1;
              st.site = &dj_emlrtRSI;
              i = BoardIdx.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &qe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(1);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              col1.set_size(&vh_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[0];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0)];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              st.site = &ej_emlrtRSI;
              i = BoardIdx.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &qe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(1);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              col2.set_size(&wh_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) + 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2 + 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              st.site = &fj_emlrtRSI;
              i = BoardIdx.size(0);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &qe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(1);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              row3.set_size(&xh_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) + 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &pe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2 + 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])row3.size())[0];
              iv1[1] = (*(int32_T (*)[2])row3.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &ib_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col2.size(1);
              col2.set_size(&yh_emlrtRTEI, sp, 3, col2.size(1));
              for (i = 0; i < loop_ub; i++) {
                col2[i] = 2.0F * col2[i];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])col2.size())[0];
              iv1[1] = (*(int32_T (*)[2])col2.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &ib_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col1.size(1);
              col2.set_size(&ai_emlrtRTEI, sp, 3, col1.size(1));
              for (i = 0; i < loop_ub; i++) {
                col2[i] = (col1[i] + row3[i]) - col2[i];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])row3.size())[0];
              iv1[1] = (*(int32_T (*)[2])row3.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &hb_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col1.size(1);
              col1.set_size(&bi_emlrtRTEI, sp, 3, col1.size(1));
              for (i = 0; i < loop_ub; i++) {
                col1[i] = col1[i] - row3[i];
              }

              if (1 > col2.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, col2.size(1), &af_emlrtBCI,
                  (emlrtCTX)sp);
              }

              if (2 > col2.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, col2.size(1), &ye_emlrtBCI,
                  (emlrtCTX)sp);
              }

              x[0] = muSingleScalarHypot(col2[0], col2[3]);
              x[1] = muSingleScalarHypot(col2[1], col2[4]);
              x[2] = muSingleScalarHypot(col2[2], col2[5]);
              if (1 > col1.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, col1.size(1), &xe_emlrtBCI,
                  (emlrtCTX)sp);
              }

              if (2 > col1.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, col1.size(1), &we_emlrtBCI,
                  (emlrtCTX)sp);
              }

              x[0] /= muSingleScalarHypot(col1[0], col1[3]);
              x[1] /= muSingleScalarHypot(col1[1], col1[4]);
              x[2] /= muSingleScalarHypot(col1[2], col1[5]);
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
                  f = x[c_this - 1];
                  if (ex < f) {
                    ex = f;
                  }
                }
              }

              st.site = &hj_emlrtRSI;
              i = BoardIdx.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &pe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(0);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              col1.set_size(&ci_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[0];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col1[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              st.site = &ij_emlrtRSI;
              i = BoardIdx.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &pe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(0);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              col2.set_size(&di_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0)];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) + 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) + 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                col2[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              st.site = &jj_emlrtRSI;
              i = BoardIdx.size(1);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &pe_emlrtBCI, &st);
              }

              idx = BoardIdx.size(0);
              c_this = Points.size(0);
              loop_ub = Points.size(1);
              row3.set_size(&ei_emlrtRTEI, &st, 3, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                if (1 > idx) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i] = Points[(static_cast<int32_T>(d) + Points.size(0) *
                                      i) - 1];
                if (2 > idx) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, 1, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2 + 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i + 1] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
                if (3 > idx) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, 2, &qe_emlrtBCI, &st);
                }

                d = BoardIdx[BoardIdx.size(0) * 2 + 2];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &y_emlrtDCI, &st);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     c_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    c_this, &bf_emlrtBCI, &st);
                }

                row3[3 * i + 2] = Points[(static_cast<int32_T>(d) + Points.size
                  (0) * i) - 1];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])row3.size())[0];
              iv1[1] = (*(int32_T (*)[2])row3.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &gb_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col2.size(1);
              col2.set_size(&fi_emlrtRTEI, sp, 3, col2.size(1));
              for (i = 0; i < loop_ub; i++) {
                col2[i] = 2.0F * col2[i];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])col2.size())[0];
              iv1[1] = (*(int32_T (*)[2])col2.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &gb_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col1.size(1);
              col2.set_size(&gi_emlrtRTEI, sp, 3, col1.size(1));
              for (i = 0; i < loop_ub; i++) {
                col2[i] = (col1[i] + row3[i]) - col2[i];
              }

              b_iv[0] = (*(int32_T (*)[2])col1.size())[0];
              b_iv[1] = (*(int32_T (*)[2])col1.size())[1];
              iv1[0] = (*(int32_T (*)[2])row3.size())[0];
              iv1[1] = (*(int32_T (*)[2])row3.size())[1];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &fb_emlrtECI,
                (emlrtCTX)sp);
              loop_ub = 3 * col1.size(1);
              col1.set_size(&hi_emlrtRTEI, sp, 3, col1.size(1));
              for (i = 0; i < loop_ub; i++) {
                col1[i] = col1[i] - row3[i];
              }

              if (1 > col2.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, col2.size(1), &ve_emlrtBCI,
                  (emlrtCTX)sp);
              }

              if (2 > col2.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, col2.size(1), &ue_emlrtBCI,
                  (emlrtCTX)sp);
              }

              x[0] = muSingleScalarHypot(col2[0], col2[3]);
              x[1] = muSingleScalarHypot(col2[1], col2[4]);
              x[2] = muSingleScalarHypot(col2[2], col2[5]);
              if (1 > col1.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, col1.size(1), &te_emlrtBCI,
                  (emlrtCTX)sp);
              }

              if (2 > col1.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, col1.size(1), &se_emlrtBCI,
                  (emlrtCTX)sp);
              }

              x[0] /= muSingleScalarHypot(col1[0], col1[3]);
              x[1] /= muSingleScalarHypot(col1[1], col1[4]);
              x[2] /= muSingleScalarHypot(col1[2], col1[5]);
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
                  f = x[c_this - 1];
                  if (b_ex < f) {
                    b_ex = f;
                  }
                }
              }

              i = BoardIdx.size(0) * BoardIdx.size(1);
              if (i < 0) {
                emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &re_emlrtBCI,
                  (emlrtCTX)sp);
              }

              e = static_cast<real32_T>(i) * muSingleScalarMax(muSingleScalarMax
                (0.0F, ex), b_ex) - static_cast<real32_T>(i);
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            return e;
          }

          real32_T Checkerboard::computeNewEnergyHorizontal(const emlrtStack *sp,
            real32_T oldEnergy) const
          {
            array<real_T, 3U> denom;
            array<real_T, 3U> num;
            array<real_T, 3U> r10;
            array<real_T, 3U> r4;
            array<real_T, 3U> r6;
            array<real_T, 3U> r7;
            array<real_T, 3U> r9;
            array<real_T, 2U> b_denom;
            array<real_T, 2U> b_num;
            array<real_T, 2U> validNewColIdx;
            array<real_T, 1U> c_num;
            array<real_T, 1U> d_num;
            array<real_T, 1U> x;
            array<real_T, 1U> y;
            array<int32_T, 1U> r11;
            array<int32_T, 1U> r12;
            array<int32_T, 1U> r3;
            array<int32_T, 1U> r5;
            array<int32_T, 1U> r8;
            array<boolean_T, 2U> b_this;
            array<boolean_T, 1U> r;
            array<boolean_T, 1U> r1;
            array<boolean_T, 1U> r2;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack i_st;
            emlrtStack st;
            real_T d;
            real_T ex;
            int32_T b_iv[3];
            int32_T iv1[3];
            int32_T a;
            int32_T b_i;
            int32_T b_loop_ub;
            int32_T i;
            int32_T i1;
            int32_T idx;
            int32_T k;
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
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &ko_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&ro_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[i] > 0.0);
            }

            i = BoardIdx.size(1);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &jo_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&so_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0)] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &pc_emlrtECI,
                (emlrtCTX)sp);
            }

            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (r[i] && r1[i]);
            }

            i = BoardIdx.size(1);
            if (3 > i) {
              emlrtDynamicBoundsCheckR2012b(3, 1, i, &io_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&to_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0) * 2] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &pc_emlrtECI,
                (emlrtCTX)sp);
            }

            newEnergy = 0.0F;
            r2.set_size(&ro_emlrtRTEI, sp, r.size(0));
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              r2[i] = (r[i] && r1[i]);
            }

            st.site = &gr_emlrtRSI;
            if (b_any(&st, r2)) {
              idx = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r3.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r3[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ho_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(0);
              loop_ub = BoardCoords.size(2);
              r4.set_size(&vo_emlrtRTEI, sp, r3.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r3.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r3[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r3[i1], 1, last, &lo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r4[i1 + r4.size(0) * i] = BoardCoords[(r3[i1] +
                    BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                }
              }

              idx = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r5.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r5[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(1);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &go_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(0);
              loop_ub = BoardCoords.size(2);
              r6.set_size(&wo_emlrtRTEI, sp, r5.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r5.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r5[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r5[i1], 1, last, &mo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r6[i1 + r6.size(0) * i] = BoardCoords[((r5[i1] +
                    BoardCoords.size(0) * 2) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r6.size())[0];
              iv1[1] = (*(int32_T (*)[3])r6.size())[1];
              iv1[2] = (*(int32_T (*)[3])r6.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &oc_emlrtECI,
                (emlrtCTX)sp);
              idx = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r8.set_size(&uo_emlrtRTEI, sp, last);
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
                  emlrtDynamicBoundsCheckR2012b(r8[i], 1, last, &no_emlrtBCI,
                    (emlrtCTX)sp);
                }
              }

              i = BoardCoords.size(1);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &fo_emlrtBCI, (emlrtCTX)
                  sp);
              }

              loop_ub = BoardCoords.size(2);
              r9.set_size(&xo_emlrtRTEI, sp, r8.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r8.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  r9[i1 + r9.size(0) * i] = 2.0 * BoardCoords[((r8[i1] +
                    BoardCoords.size(0)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r9.size())[0];
              iv1[1] = (*(int32_T (*)[3])r9.size())[1];
              iv1[2] = (*(int32_T (*)[3])r9.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &oc_emlrtECI,
                (emlrtCTX)sp);
              r10.set_size(&vo_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
              loop_ub = r4.size(0) * r4.size(2);
              for (i = 0; i < loop_ub; i++) {
                r10[i] = (r4[i] + r6[i]) - r9[i];
              }

              st.site = &hr_emlrtRSI;
              b_squeeze(&st, r10, b_num);
              idx = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r11.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r11[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(1);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &eo_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(0);
              loop_ub = BoardCoords.size(2);
              r4.set_size(&yo_emlrtRTEI, sp, r11.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r11.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r11[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r11[i1], 1, last, &oo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r4[i1 + r4.size(0) * i] = BoardCoords[(r11[i1] +
                    BoardCoords.size(0) * BoardCoords.size(1) * i) - 1];
                }
              }

              idx = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r12.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r12[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(1);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &do_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(0);
              loop_ub = BoardCoords.size(2);
              r6.set_size(&ap_emlrtRTEI, sp, r12.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r12.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r12[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r12[i1], 1, last, &po_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r6[i1 + r6.size(0) * i] = BoardCoords[((r12[i1] +
                    BoardCoords.size(0) * 2) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r6.size())[0];
              iv1[1] = (*(int32_T (*)[3])r6.size())[1];
              iv1[2] = (*(int32_T (*)[3])r6.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nc_emlrtECI,
                (emlrtCTX)sp);
              r9.set_size(&yo_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
              loop_ub = r4.size(0) * r4.size(2);
              for (i = 0; i < loop_ub; i++) {
                r9[i] = r4[i] - r6[i];
              }

              st.site = &ir_emlrtRSI;
              b_squeeze(&st, r9, b_denom);
              if (b_num.size(1) > 1) {
                st.site = &jr_emlrtRSI;
                loop_ub = b_num.size(0);
                c_num.set_size(&bp_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_num[i];
                }

                loop_ub = b_num.size(0);
                d_num.set_size(&cp_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_num[i + b_num.size(0)];
                }

                b_st.site = &jr_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, x);
                if (1 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                    &co_emlrtBCI, &st);
                }

                if (2 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                    &bo_emlrtBCI, &st);
                }

                loop_ub = b_denom.size(0);
                c_num.set_size(&dp_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_denom[i];
                }

                loop_ub = b_denom.size(0);
                d_num.set_size(&ep_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_denom[i + b_denom.size(0)];
                }

                b_st.site = &jr_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, y);
                b_st.site = &ti_emlrtRSI;
                c_st.site = &ui_emlrtRSI;
                if (x.size(0) != y.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                    "MATLAB:dimagree", "MATLAB:dimagree", 0);
                }

                loop_ub = x.size(0);
                for (i = 0; i < loop_ub; i++) {
                  x[i] = x[i] / y[i];
                }

                st.site = &jr_emlrtRSI;
                b_st.site = &ge_emlrtRSI;
                c_st.site = &he_emlrtRSI;
                d_st.site = &ie_emlrtRSI;
                if (x.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &je_emlrtRSI;
                f_st.site = &ke_emlrtRSI;
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
                  g_st.site = &le_emlrtRSI;
                  if (!muDoubleScalarIsNaN(x[0])) {
                    idx = 1;
                  } else {
                    boolean_T exitg1;
                    idx = 0;
                    h_st.site = &ne_emlrtRSI;
                    if (x.size(0) > 2147483646) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    k = 2;
                    exitg1 = false;
                    while ((!exitg1) && (k <= last)) {
                      if (!muDoubleScalarIsNaN(x[k - 1])) {
                        idx = k;
                        exitg1 = true;
                      } else {
                        k++;
                      }
                    }
                  }

                  if (idx == 0) {
                    ex = x[0];
                  } else {
                    g_st.site = &me_emlrtRSI;
                    ex = x[idx - 1];
                    a = idx + 1;
                    h_st.site = &oe_emlrtRSI;
                    if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    for (k = a; k <= last; k++) {
                      d = x[k - 1];
                      if (ex < d) {
                        ex = d;
                      }
                    }
                  }
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (ex));
              } else {
                i = b_num.size(0) * b_num.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ao_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_num.size(0) * b_num.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &yn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &xn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &wn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (muDoubleScalarHypot(b_num[0], b_num[1]) / muDoubleScalarHypot
                   (b_denom[0], b_denom[1])));
              }
            }

            i = BoardIdx.size(1);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &vn_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(0);
            b_this.set_size(&fp_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[i] > 0.0);
            }

            st.site = &kr_emlrtRSI;
            Checkerboard::arrayFind(&st, b_this, validNewColIdx);
            if (validNewColIdx.size(1) != 0) {
              int32_T c_loop_ub;
              int32_T d_loop_ub;
              i = validNewColIdx.size(1);
              loop_ub = BoardCoords.size(2);
              b_loop_ub = BoardCoords.size(2);
              k = BoardCoords.size(2);
              c_loop_ub = BoardCoords.size(2);
              d_loop_ub = BoardCoords.size(2);
              for (b_i = 0; b_i < i; b_i++) {
                real_T d1;
                if (b_i + 1 > validNewColIdx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validNewColIdx.size
                    (1), &un_emlrtBCI, (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &sn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(0);
                idx = static_cast<int32_T>(muDoubleScalarFloor
                  (validNewColIdx[b_i]));
                if (validNewColIdx[b_i] != idx) {
                  emlrtIntegerCheckR2012b(validNewColIdx[b_i], &qe_emlrtDCI,
                    (emlrtCTX)sp);
                }

                a = static_cast<int32_T>(validNewColIdx[b_i]);
                if ((a < 1) || (a > i1)) {
                  emlrtDynamicBoundsCheckR2012b(a, 1, i1, &tn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                num.set_size(&gp_emlrtRTEI, sp, 1, 1, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  num[i1] = BoardCoords[(a + BoardCoords.size(0) *
                    BoardCoords.size(1) * i1) - 1];
                }

                i1 = BoardCoords.size(1);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &qn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(0);
                d = validNewColIdx[b_i] + 2.0;
                ex = static_cast<int32_T>(muDoubleScalarFloor(d));
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &pe_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i1,
                    &rn_emlrtBCI, (emlrtCTX)sp);
                }

                r7.set_size(&hp_emlrtRTEI, sp, 1, 1, b_loop_ub);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  r7[i1] = BoardCoords[(static_cast<int32_T>(d) +
                                        BoardCoords.size(0) * BoardCoords.size(1)
                                        * i1) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])num.size())[0];
                b_iv[1] = (*(int32_T (*)[3])num.size())[1];
                b_iv[2] = (*(int32_T (*)[3])num.size())[2];
                iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mc_emlrtECI,
                  (emlrtCTX)sp);
                i1 = BoardCoords.size(0);
                d1 = validNewColIdx[b_i] + 1.0;
                if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
                  emlrtIntegerCheckR2012b(d1, &oe_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1, i1,
                    &pn_emlrtBCI, (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &on_emlrtBCI,
                    (emlrtCTX)sp);
                }

                last = static_cast<int32_T>(validNewColIdx[b_i] + 1.0);
                denom.set_size(&ip_emlrtRTEI, sp, 1, 1, k);
                for (i1 = 0; i1 < k; i1++) {
                  denom[i1] = 2.0 * BoardCoords[(last + BoardCoords.size(0) *
                    BoardCoords.size(1) * i1) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])num.size())[0];
                b_iv[1] = (*(int32_T (*)[3])num.size())[1];
                b_iv[2] = (*(int32_T (*)[3])num.size())[2];
                iv1[0] = (*(int32_T (*)[3])denom.size())[0];
                iv1[1] = (*(int32_T (*)[3])denom.size())[1];
                iv1[2] = (*(int32_T (*)[3])denom.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mc_emlrtECI,
                  (emlrtCTX)sp);
                num.set_size(&jp_emlrtRTEI, sp, 1, 1, num.size(2));
                last = num.size(2) - 1;
                for (i1 = 0; i1 <= last; i1++) {
                  num[i1] = (num[i1] + r7[i1]) - denom[i1];
                }

                i1 = BoardCoords.size(1);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &mn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(0);
                if (validNewColIdx[b_i] != idx) {
                  emlrtIntegerCheckR2012b(validNewColIdx[b_i], &ne_emlrtDCI,
                    (emlrtCTX)sp);
                }

                if (a > i1) {
                  emlrtDynamicBoundsCheckR2012b(a, 1, i1, &nn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                denom.set_size(&kp_emlrtRTEI, sp, 1, 1, c_loop_ub);
                for (i1 = 0; i1 < c_loop_ub; i1++) {
                  denom[i1] = BoardCoords[(a + BoardCoords.size(0) *
                    BoardCoords.size(1) * i1) - 1];
                }

                i1 = BoardCoords.size(1);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &kn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(0);
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &me_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i1,
                    &ln_emlrtBCI, (emlrtCTX)sp);
                }

                r7.set_size(&lp_emlrtRTEI, sp, 1, 1, d_loop_ub);
                for (i1 = 0; i1 < d_loop_ub; i1++) {
                  r7[i1] = BoardCoords[(static_cast<int32_T>(d) +
                                        BoardCoords.size(0) * BoardCoords.size(1)
                                        * i1) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])denom.size())[0];
                b_iv[1] = (*(int32_T (*)[3])denom.size())[1];
                b_iv[2] = (*(int32_T (*)[3])denom.size())[2];
                iv1[0] = (*(int32_T (*)[3])r7.size())[0];
                iv1[1] = (*(int32_T (*)[3])r7.size())[1];
                iv1[2] = (*(int32_T (*)[3])r7.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &lc_emlrtECI,
                  (emlrtCTX)sp);
                denom.set_size(&mp_emlrtRTEI, sp, 1, 1, denom.size(2));
                last = denom.size(2) - 1;
                for (i1 = 0; i1 <= last; i1++) {
                  denom[i1] = denom[i1] - r7[i1];
                }

                st.site = &lr_emlrtRSI;
                if (muSingleScalarIsNaN(newEnergy)) {
                  emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                    "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                }

                if (newEnergy != 0.0F) {
                  a = num.size(2);
                  last = denom.size(2);
                  c_num = num.reshape(a);
                  d_num = denom.reshape(last);
                  st.site = &mr_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(newEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  a = num.size(2);
                  last = denom.size(2);
                  c_num = num.reshape(a);
                  d_num = denom.reshape(last);
                  st.site = &nr_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                }
              }
            }

            st.site = &or_emlrtRSI;
            if (muSingleScalarIsNaN(newEnergy)) {
              emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if (newEnergy != 0.0F) {
              last = BoardIdx.size(0) * BoardIdx.size(1);
              if (last < 0) {
                emlrtDynamicBoundsCheckR2012b(last, 0, MAX_int32_T, &jn_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0) * BoardIdx.size(1);
              if (i < 0) {
                emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &in_emlrtBCI,
                  (emlrtCTX)sp);
              }

              newEnergy = newEnergy * static_cast<real32_T>(last) - static_cast<
                real32_T>(i);
            } else {
              newEnergy = rtInfF;
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            return newEnergy;
          }

          real32_T Checkerboard::computeNewEnergyHorizontal(const emlrtStack *sp,
            const ::coder::array<real_T, 2U> &idx, real32_T oldEnergy) const
          {
            array<real_T, 3U> denom;
            array<real_T, 3U> num;
            array<real_T, 3U> r10;
            array<real_T, 3U> r4;
            array<real_T, 3U> r6;
            array<real_T, 3U> r8;
            array<real_T, 3U> r9;
            array<real_T, 2U> b_denom;
            array<real_T, 2U> b_num;
            array<real_T, 2U> validNewColIdx;
            array<real_T, 1U> c_num;
            array<real_T, 1U> d_num;
            array<real_T, 1U> x;
            array<real_T, 1U> y;
            array<int32_T, 1U> r11;
            array<int32_T, 1U> r12;
            array<int32_T, 1U> r3;
            array<int32_T, 1U> r5;
            array<int32_T, 1U> r7;
            array<boolean_T, 2U> b_this;
            array<boolean_T, 1U> r;
            array<boolean_T, 1U> r1;
            array<boolean_T, 1U> r2;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack i_st;
            emlrtStack st;
            real_T d;
            real_T ex;
            int32_T b_iv[3];
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
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &bq_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
            if (idx[0] != i1) {
              emlrtIntegerCheckR2012b(idx[0], &xf_emlrtDCI, (emlrtCTX)sp);
            }

            b_idx = static_cast<int32_T>(idx[0]);
            if ((b_idx < 1) || (b_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &ko_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&ro_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[i + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &aq_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            i2 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
            if (idx[1] != i2) {
              emlrtIntegerCheckR2012b(idx[1], &wf_emlrtDCI, (emlrtCTX)sp);
            }

            c_idx = static_cast<int32_T>(idx[1]);
            if ((c_idx < 1) || (c_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &jo_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&so_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0) * (c_idx - 1)] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &pc_emlrtECI,
                (emlrtCTX)sp);
            }

            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (r[i] && r1[i]);
            }

            if (3 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &yp_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            i3 = static_cast<int32_T>(muDoubleScalarFloor(idx[2]));
            if (idx[2] != i3) {
              emlrtIntegerCheckR2012b(idx[2], &vf_emlrtDCI, (emlrtCTX)sp);
            }

            d_idx = static_cast<int32_T>(idx[2]);
            if ((d_idx < 1) || (d_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &io_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(0);
            r1.set_size(&to_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[i + BoardIdx.size(0) * (d_idx - 1)] > 0.0);
            }

            if (r.size(0) != r1.size(0)) {
              emlrtSizeEqCheck1DR2012b(r.size(0), r1.size(0), &pc_emlrtECI,
                (emlrtCTX)sp);
            }

            newEnergy = 0.0F;
            r2.set_size(&ro_emlrtRTEI, sp, r.size(0));
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              r2[i] = (r[i] && r1[i]);
            }

            st.site = &gr_emlrtRSI;
            if (b_any(&st, r2)) {
              end = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r3.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r3[last] = b_i + 1;
                  last++;
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &xp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(0);
              i = BoardCoords.size(1);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &uf_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &ho_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r4.set_size(&vo_emlrtRTEI, sp, r3.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r3.size(0);
                for (end = 0; end < b_loop_ub; end++) {
                  if (r3[end] > last) {
                    emlrtDynamicBoundsCheckR2012b(r3[end], 1, last, &lo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r4[end + r4.size(0) * i] = BoardCoords[((r3[end] +
                    BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              end = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r5.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r5[last] = b_i + 1;
                  last++;
                }
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &wp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(0);
              i = BoardCoords.size(1);
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &tf_emlrtDCI, (emlrtCTX)sp);
              }

              if (d_idx > i) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &go_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r6.set_size(&wo_emlrtRTEI, sp, r5.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r5.size(0);
                for (end = 0; end < b_loop_ub; end++) {
                  if (r5[end] > last) {
                    emlrtDynamicBoundsCheckR2012b(r5[end], 1, last, &mo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r6[end + r6.size(0) * i] = BoardCoords[((r5[end] +
                    BoardCoords.size(0) * (d_idx - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r6.size())[0];
              iv1[1] = (*(int32_T (*)[3])r6.size())[1];
              iv1[2] = (*(int32_T (*)[3])r6.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &oc_emlrtECI,
                (emlrtCTX)sp);
              end = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r7.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r7[last] = b_i + 1;
                  last++;
                }
              }

              last = BoardCoords.size(0);
              loop_ub = r7.size(0);
              for (i = 0; i < loop_ub; i++) {
                if (r7[i] > last) {
                  emlrtDynamicBoundsCheckR2012b(r7[i], 1, last, &no_emlrtBCI,
                    (emlrtCTX)sp);
                }
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &vp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardCoords.size(1);
              if (idx[1] != i2) {
                emlrtIntegerCheckR2012b(idx[1], &sf_emlrtDCI, (emlrtCTX)sp);
              }

              if (c_idx > i) {
                emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &fo_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r9.set_size(&xo_emlrtRTEI, sp, r7.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r7.size(0);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  r9[i2 + r9.size(0) * i] = 2.0 * BoardCoords[((r7[i2] +
                    BoardCoords.size(0) * (c_idx - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r9.size())[0];
              iv1[1] = (*(int32_T (*)[3])r9.size())[1];
              iv1[2] = (*(int32_T (*)[3])r9.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &oc_emlrtECI,
                (emlrtCTX)sp);
              r10.set_size(&vo_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
              loop_ub = r4.size(0) * r4.size(2);
              for (i = 0; i < loop_ub; i++) {
                r10[i] = (r4[i] + r6[i]) - r9[i];
              }

              st.site = &hr_emlrtRSI;
              b_squeeze(&st, r10, b_num);
              end = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r11.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r11[last] = b_i + 1;
                  last++;
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &up_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(0);
              i = BoardCoords.size(1);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &rf_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &eo_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r4.set_size(&yo_emlrtRTEI, sp, r11.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r11.size(0);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  if (r11[i2] > last) {
                    emlrtDynamicBoundsCheckR2012b(r11[i2], 1, last, &oo_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r4[i2 + r4.size(0) * i] = BoardCoords[((r11[i2] +
                    BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              end = r.size(0) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  last++;
                }
              }

              r12.set_size(&uo_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (r[b_i] && r1[b_i]) {
                  r12[last] = b_i + 1;
                  last++;
                }
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &tp_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(0);
              i = BoardCoords.size(1);
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &qf_emlrtDCI, (emlrtCTX)sp);
              }

              if (d_idx > i) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &do_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r6.set_size(&ap_emlrtRTEI, sp, r12.size(0), 1, loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r12.size(0);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  if (r12[i2] > last) {
                    emlrtDynamicBoundsCheckR2012b(r12[i2], 1, last, &po_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r6[i2 + r6.size(0) * i] = BoardCoords[((r12[i2] +
                    BoardCoords.size(0) * (d_idx - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              b_iv[0] = (*(int32_T (*)[3])r4.size())[0];
              b_iv[1] = (*(int32_T (*)[3])r4.size())[1];
              b_iv[2] = (*(int32_T (*)[3])r4.size())[2];
              iv1[0] = (*(int32_T (*)[3])r6.size())[0];
              iv1[1] = (*(int32_T (*)[3])r6.size())[1];
              iv1[2] = (*(int32_T (*)[3])r6.size())[2];
              emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nc_emlrtECI,
                (emlrtCTX)sp);
              r9.set_size(&yo_emlrtRTEI, sp, r4.size(0), 1, r4.size(2));
              loop_ub = r4.size(0) * r4.size(2);
              for (i = 0; i < loop_ub; i++) {
                r9[i] = r4[i] - r6[i];
              }

              st.site = &ir_emlrtRSI;
              b_squeeze(&st, r9, b_denom);
              if (b_num.size(1) > 1) {
                st.site = &jr_emlrtRSI;
                loop_ub = b_num.size(0);
                c_num.set_size(&bp_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_num[i];
                }

                loop_ub = b_num.size(0);
                d_num.set_size(&cp_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_num[i + b_num.size(0)];
                }

                b_st.site = &jr_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, x);
                if (1 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                    &co_emlrtBCI, &st);
                }

                if (2 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                    &bo_emlrtBCI, &st);
                }

                loop_ub = b_denom.size(0);
                c_num.set_size(&dp_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_denom[i];
                }

                loop_ub = b_denom.size(0);
                d_num.set_size(&ep_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_denom[i + b_denom.size(0)];
                }

                b_st.site = &jr_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, y);
                b_st.site = &ti_emlrtRSI;
                c_st.site = &ui_emlrtRSI;
                if (x.size(0) != y.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                    "MATLAB:dimagree", "MATLAB:dimagree", 0);
                }

                loop_ub = x.size(0);
                for (i = 0; i < loop_ub; i++) {
                  x[i] = x[i] / y[i];
                }

                st.site = &jr_emlrtRSI;
                b_st.site = &ge_emlrtRSI;
                c_st.site = &he_emlrtRSI;
                d_st.site = &ie_emlrtRSI;
                if (x.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &je_emlrtRSI;
                f_st.site = &ke_emlrtRSI;
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
                  g_st.site = &le_emlrtRSI;
                  if (!muDoubleScalarIsNaN(x[0])) {
                    c_idx = 1;
                  } else {
                    boolean_T exitg1;
                    c_idx = 0;
                    h_st.site = &ne_emlrtRSI;
                    if (x.size(0) > 2147483646) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    d_idx = 2;
                    exitg1 = false;
                    while ((!exitg1) && (d_idx <= last)) {
                      if (!muDoubleScalarIsNaN(x[d_idx - 1])) {
                        c_idx = d_idx;
                        exitg1 = true;
                      } else {
                        d_idx++;
                      }
                    }
                  }

                  if (c_idx == 0) {
                    ex = x[0];
                  } else {
                    g_st.site = &me_emlrtRSI;
                    ex = x[c_idx - 1];
                    end = c_idx + 1;
                    h_st.site = &oe_emlrtRSI;
                    if ((c_idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    for (d_idx = end; d_idx <= last; d_idx++) {
                      d = x[d_idx - 1];
                      if (ex < d) {
                        ex = d;
                      }
                    }
                  }
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (ex));
              } else {
                i = b_num.size(0) * b_num.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &ao_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_num.size(0) * b_num.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &yn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &xn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &wn_emlrtBCI, (emlrtCTX)
                    sp);
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (muDoubleScalarHypot(b_num[0], b_num[1]) / muDoubleScalarHypot
                   (b_denom[0], b_denom[1])));
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &sp_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            if (idx[0] != i1) {
              emlrtIntegerCheckR2012b(idx[0], &pf_emlrtDCI, (emlrtCTX)sp);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &vn_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(0);
            b_this.set_size(&fp_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[i + BoardIdx.size(0) * (b_idx - 1)] > 0.0);
            }

            st.site = &kr_emlrtRSI;
            Checkerboard::arrayFind(&st, b_this, validNewColIdx);
            if (validNewColIdx.size(1) != 0) {
              int32_T c_loop_ub;
              int32_T d_loop_ub;
              i = validNewColIdx.size(1);
              loop_ub = BoardCoords.size(2);
              b_loop_ub = BoardCoords.size(2);
              d_idx = BoardCoords.size(2);
              c_loop_ub = BoardCoords.size(2);
              d_loop_ub = BoardCoords.size(2);
              for (b_i = 0; b_i < i; b_i++) {
                real_T d1;
                if (b_i + 1 > validNewColIdx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validNewColIdx.size
                    (1), &un_emlrtBCI, (emlrtCTX)sp);
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &rp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                i3 = static_cast<int32_T>(muDoubleScalarFloor(validNewColIdx[b_i]));
                if (validNewColIdx[b_i] != i3) {
                  emlrtIntegerCheckR2012b(validNewColIdx[b_i], &qe_emlrtDCI,
                    (emlrtCTX)sp);
                }

                end = static_cast<int32_T>(validNewColIdx[b_i]);
                if ((end < 1) || (end > i2)) {
                  emlrtDynamicBoundsCheckR2012b(end, 1, i2, &tn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &of_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &sn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                num.set_size(&gp_emlrtRTEI, sp, 1, 1, loop_ub);
                for (i2 = 0; i2 < loop_ub; i2++) {
                  num[i2] = BoardCoords[((end + BoardCoords.size(0) * (b_idx - 1))
                    + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &qp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                d = validNewColIdx[b_i] + 2.0;
                ex = static_cast<int32_T>(muDoubleScalarFloor(d));
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &pe_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i2,
                    &rn_emlrtBCI, (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &nf_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &qn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                r8.set_size(&hp_emlrtRTEI, sp, 1, 1, b_loop_ub);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  r8[i2] = BoardCoords[((static_cast<int32_T>(d) +
                    BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * i2) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])num.size())[0];
                b_iv[1] = (*(int32_T (*)[3])num.size())[1];
                b_iv[2] = (*(int32_T (*)[3])num.size())[2];
                iv1[0] = (*(int32_T (*)[3])r8.size())[0];
                iv1[1] = (*(int32_T (*)[3])r8.size())[1];
                iv1[2] = (*(int32_T (*)[3])r8.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mc_emlrtECI,
                  (emlrtCTX)sp);
                i2 = BoardCoords.size(0);
                d1 = validNewColIdx[b_i] + 1.0;
                if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
                  emlrtIntegerCheckR2012b(d1, &oe_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1, i2,
                    &pn_emlrtBCI, (emlrtCTX)sp);
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &pp_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &mf_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &on_emlrtBCI,
                    (emlrtCTX)sp);
                }

                last = static_cast<int32_T>(validNewColIdx[b_i] + 1.0);
                denom.set_size(&ip_emlrtRTEI, sp, 1, 1, d_idx);
                for (i2 = 0; i2 < d_idx; i2++) {
                  denom[i2] = 2.0 * BoardCoords[((last + BoardCoords.size(0) *
                    (b_idx - 1)) + BoardCoords.size(0) * BoardCoords.size(1) *
                    i2) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])num.size())[0];
                b_iv[1] = (*(int32_T (*)[3])num.size())[1];
                b_iv[2] = (*(int32_T (*)[3])num.size())[2];
                iv1[0] = (*(int32_T (*)[3])denom.size())[0];
                iv1[1] = (*(int32_T (*)[3])denom.size())[1];
                iv1[2] = (*(int32_T (*)[3])denom.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mc_emlrtECI,
                  (emlrtCTX)sp);
                num.set_size(&jp_emlrtRTEI, sp, 1, 1, num.size(2));
                last = num.size(2) - 1;
                for (i2 = 0; i2 <= last; i2++) {
                  num[i2] = (num[i2] + r8[i2]) - denom[i2];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &op_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (validNewColIdx[b_i] != i3) {
                  emlrtIntegerCheckR2012b(validNewColIdx[b_i], &ne_emlrtDCI,
                    (emlrtCTX)sp);
                }

                if (end > i2) {
                  emlrtDynamicBoundsCheckR2012b(end, 1, i2, &nn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &lf_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &mn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                denom.set_size(&kp_emlrtRTEI, sp, 1, 1, c_loop_ub);
                for (i2 = 0; i2 < c_loop_ub; i2++) {
                  denom[i2] = BoardCoords[((end + BoardCoords.size(0) * (b_idx -
                    1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &np_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &me_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i2,
                    &ln_emlrtBCI, (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &kf_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &kn_emlrtBCI,
                    (emlrtCTX)sp);
                }

                r8.set_size(&lp_emlrtRTEI, sp, 1, 1, d_loop_ub);
                for (i2 = 0; i2 < d_loop_ub; i2++) {
                  r8[i2] = BoardCoords[((static_cast<int32_T>(d) +
                    BoardCoords.size(0) * (b_idx - 1)) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * i2) - 1];
                }

                b_iv[0] = (*(int32_T (*)[3])denom.size())[0];
                b_iv[1] = (*(int32_T (*)[3])denom.size())[1];
                b_iv[2] = (*(int32_T (*)[3])denom.size())[2];
                iv1[0] = (*(int32_T (*)[3])r8.size())[0];
                iv1[1] = (*(int32_T (*)[3])r8.size())[1];
                iv1[2] = (*(int32_T (*)[3])r8.size())[2];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &lc_emlrtECI,
                  (emlrtCTX)sp);
                denom.set_size(&mp_emlrtRTEI, sp, 1, 1, denom.size(2));
                last = denom.size(2) - 1;
                for (i2 = 0; i2 <= last; i2++) {
                  denom[i2] = denom[i2] - r8[i2];
                }

                st.site = &lr_emlrtRSI;
                if (muSingleScalarIsNaN(newEnergy)) {
                  emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                    "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                }

                if (newEnergy != 0.0F) {
                  c_idx = num.size(2);
                  end = denom.size(2);
                  c_num = num.reshape(c_idx);
                  d_num = denom.reshape(end);
                  st.site = &mr_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(newEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  c_idx = num.size(2);
                  end = denom.size(2);
                  c_num = num.reshape(c_idx);
                  d_num = denom.reshape(end);
                  st.site = &nr_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                }
              }
            }

            st.site = &or_emlrtRSI;
            if (muSingleScalarIsNaN(newEnergy)) {
              emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if (newEnergy != 0.0F) {
              last = BoardIdx.size(0) * BoardIdx.size(1);
              if (last < 0) {
                emlrtDynamicBoundsCheckR2012b(last, 0, MAX_int32_T, &jn_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0) * BoardIdx.size(1);
              if (i < 0) {
                emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &in_emlrtBCI,
                  (emlrtCTX)sp);
              }

              newEnergy = newEnergy * static_cast<real32_T>(last) - static_cast<
                real32_T>(i);
            } else {
              newEnergy = rtInfF;
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            return newEnergy;
          }

          real32_T Checkerboard::computeNewEnergyVertical(const emlrtStack *sp,
            real32_T oldEnergy) const
          {
            array<real_T, 3U> b;
            array<real_T, 3U> denom;
            array<real_T, 3U> num;
            array<real_T, 3U> r3;
            array<real_T, 3U> r5;
            array<real_T, 3U> r6;
            array<real_T, 3U> r8;
            array<real_T, 2U> b_denom;
            array<real_T, 2U> b_num;
            array<real_T, 2U> validNewRowIdx;
            array<real_T, 1U> c_num;
            array<real_T, 1U> d_num;
            array<real_T, 1U> x;
            array<real_T, 1U> y;
            array<int32_T, 2U> r10;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r7;
            array<int32_T, 2U> r9;
            array<boolean_T, 2U> b_this;
            array<boolean_T, 2U> r;
            array<boolean_T, 2U> r1;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack i_st;
            emlrtStack st;
            real_T d;
            real_T ex;
            int32_T iv2[3];
            int32_T iv3[3];
            int32_T b_iv[2];
            int32_T iv1[2];
            int32_T a;
            int32_T b_i;
            int32_T b_loop_ub;
            int32_T i;
            int32_T i1;
            int32_T idx;
            int32_T k;
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
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &dk_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            b_this.set_size(&lm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
            }

            i = BoardIdx.size(0);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ck_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&mm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[BoardIdx.size(0) * i + 1] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])b_this.size())[0];
            b_iv[1] = (*(int32_T (*)[2])b_this.size())[1];
            iv1[0] = (*(int32_T (*)[2])r.size())[0];
            iv1[1] = (*(int32_T (*)[2])r.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &yb_emlrtECI, (emlrtCTX)
              sp);
            b_this.set_size(&lm_emlrtRTEI, sp, 1, b_this.size(1));
            loop_ub = b_this.size(1) - 1;
            for (i = 0; i <= loop_ub; i++) {
              b_this[i] = (b_this[i] && r[i]);
            }

            i = BoardIdx.size(0);
            if (3 > i) {
              emlrtDynamicBoundsCheckR2012b(3, 1, i, &bk_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&nm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[BoardIdx.size(0) * i + 2] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])b_this.size())[0];
            b_iv[1] = (*(int32_T (*)[2])b_this.size())[1];
            iv1[0] = (*(int32_T (*)[2])r.size())[0];
            iv1[1] = (*(int32_T (*)[2])r.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &yb_emlrtECI, (emlrtCTX)
              sp);
            newEnergy = 0.0F;
            r1.set_size(&lm_emlrtRTEI, sp, 1, b_this.size(1));
            loop_ub = b_this.size(1);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (b_this[i] && r[i]);
            }

            st.site = &lq_emlrtRSI;
            if (c_any(&st, r1)) {
              idx = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r2.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r2[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &ak_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(1);
              loop_ub = BoardCoords.size(2);
              r3.set_size(&pm_emlrtRTEI, sp, 1, r2.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r2.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r2[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r2[i1], 1, last, &ek_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r3[i1 + r3.size(1) * i] = BoardCoords[BoardCoords.size(0) *
                    (r2[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) * i];
                }
              }

              idx = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r4.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r4[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(0);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &yj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(1);
              loop_ub = BoardCoords.size(2);
              r5.set_size(&qm_emlrtRTEI, sp, 1, r4.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r4.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r4[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r4[i1], 1, last, &fk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r5[i1 + r5.size(1) * i] = BoardCoords[(BoardCoords.size(0) *
                    (r4[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) * i)
                    + 2];
                }
              }

              iv2[0] = (*(int32_T (*)[3])r3.size())[0];
              iv2[1] = (*(int32_T (*)[3])r3.size())[1];
              iv2[2] = (*(int32_T (*)[3])r3.size())[2];
              iv3[0] = (*(int32_T (*)[3])r5.size())[0];
              iv3[1] = (*(int32_T (*)[3])r5.size())[1];
              iv3[2] = (*(int32_T (*)[3])r5.size())[2];
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI, (emlrtCTX)
                sp);
              idx = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r7.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r7[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(0);
              if (2 > i) {
                emlrtDynamicBoundsCheckR2012b(2, 1, i, &xj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(1);
              loop_ub = BoardCoords.size(2);
              b.set_size(&rm_emlrtRTEI, sp, 1, r7.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r7.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r7[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r7[i1], 1, last, &gk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  b[i1 + b.size(1) * i] = BoardCoords[(BoardCoords.size(0) *
                    (r7[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) * i)
                    + 1];
                }
              }

              loop_ub = b.size(1) * b.size(2);
              b.set_size(&sm_emlrtRTEI, sp, 1, b.size(1), b.size(2));
              for (i = 0; i < loop_ub; i++) {
                b[i] = 2.0 * b[i];
              }

              iv2[0] = (*(int32_T (*)[3])r3.size())[0];
              iv2[1] = (*(int32_T (*)[3])r3.size())[1];
              iv2[2] = (*(int32_T (*)[3])r3.size())[2];
              iv3[0] = (*(int32_T (*)[3])b.size())[0];
              iv3[1] = (*(int32_T (*)[3])b.size())[1];
              iv3[2] = (*(int32_T (*)[3])b.size())[2];
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI, (emlrtCTX)
                sp);
              r8.set_size(&pm_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
              loop_ub = r3.size(1) * r3.size(2);
              for (i = 0; i < loop_ub; i++) {
                r8[i] = (r3[i] + r5[i]) - b[i];
              }

              st.site = &mq_emlrtRSI;
              squeeze(&st, r8, b_num);
              idx = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r9.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r9[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(0);
              if (1 > i) {
                emlrtDynamicBoundsCheckR2012b(1, 1, i, &wj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(1);
              loop_ub = BoardCoords.size(2);
              r3.set_size(&tm_emlrtRTEI, sp, 1, r9.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r9.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r9[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r9[i1], 1, last, &hk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r3[i1 + r3.size(1) * i] = BoardCoords[BoardCoords.size(0) *
                    (r9[i1] - 1) + BoardCoords.size(0) * BoardCoords.size(1) * i];
                }
              }

              idx = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r10.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= idx; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r10[last] = b_i + 1;
                  last++;
                }
              }

              i = BoardCoords.size(0);
              if (3 > i) {
                emlrtDynamicBoundsCheckR2012b(3, 1, i, &vj_emlrtBCI, (emlrtCTX)
                  sp);
              }

              last = BoardCoords.size(1);
              loop_ub = BoardCoords.size(2);
              r5.set_size(&um_emlrtRTEI, sp, 1, r10.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r10.size(1);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r10[i1] > last) {
                    emlrtDynamicBoundsCheckR2012b(r10[i1], 1, last, &ik_emlrtBCI,
                      (emlrtCTX)sp);
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
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &wb_emlrtECI, (emlrtCTX)
                sp);
              r8.set_size(&tm_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
              loop_ub = r3.size(1) * r3.size(2);
              for (i = 0; i < loop_ub; i++) {
                r8[i] = r3[i] - r5[i];
              }

              st.site = &nq_emlrtRSI;
              squeeze(&st, r8, b_denom);
              if (b_num.size(1) > 1) {
                st.site = &oq_emlrtRSI;
                loop_ub = b_num.size(0);
                c_num.set_size(&vm_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_num[i];
                }

                loop_ub = b_num.size(0);
                d_num.set_size(&wm_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_num[i + b_num.size(0)];
                }

                b_st.site = &oq_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, x);
                if (1 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                    &uj_emlrtBCI, &st);
                }

                if (2 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                    &tj_emlrtBCI, &st);
                }

                loop_ub = b_denom.size(0);
                c_num.set_size(&xm_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_denom[i];
                }

                loop_ub = b_denom.size(0);
                d_num.set_size(&ym_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_denom[i + b_denom.size(0)];
                }

                b_st.site = &oq_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, y);
                b_st.site = &ti_emlrtRSI;
                c_st.site = &ui_emlrtRSI;
                if (x.size(0) != y.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                    "MATLAB:dimagree", "MATLAB:dimagree", 0);
                }

                loop_ub = x.size(0);
                for (i = 0; i < loop_ub; i++) {
                  x[i] = x[i] / y[i];
                }

                st.site = &oq_emlrtRSI;
                b_st.site = &ge_emlrtRSI;
                c_st.site = &he_emlrtRSI;
                d_st.site = &ie_emlrtRSI;
                if (x.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &je_emlrtRSI;
                f_st.site = &ke_emlrtRSI;
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
                  g_st.site = &le_emlrtRSI;
                  if (!muDoubleScalarIsNaN(x[0])) {
                    idx = 1;
                  } else {
                    boolean_T exitg1;
                    idx = 0;
                    h_st.site = &ne_emlrtRSI;
                    if (x.size(0) > 2147483646) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    k = 2;
                    exitg1 = false;
                    while ((!exitg1) && (k <= last)) {
                      if (!muDoubleScalarIsNaN(x[k - 1])) {
                        idx = k;
                        exitg1 = true;
                      } else {
                        k++;
                      }
                    }
                  }

                  if (idx == 0) {
                    ex = x[0];
                  } else {
                    g_st.site = &me_emlrtRSI;
                    ex = x[idx - 1];
                    a = idx + 1;
                    h_st.site = &oe_emlrtRSI;
                    if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    for (k = a; k <= last; k++) {
                      d = x[k - 1];
                      if (ex < d) {
                        ex = d;
                      }
                    }
                  }
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (ex));
              } else {
                i = b_num.size(0) * b_num.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &sj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_num.size(0) * b_num.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &rj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &qj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &pj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (muDoubleScalarHypot(b_num[0], b_num[1]) / muDoubleScalarHypot
                   (b_denom[0], b_denom[1])));
              }
            }

            i = BoardIdx.size(0);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &oj_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            b_this.set_size(&an_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
            }

            st.site = &pq_emlrtRSI;
            Checkerboard::arrayFind(&st, b_this, validNewRowIdx);
            if (validNewRowIdx.size(1) != 0) {
              int32_T c_loop_ub;
              int32_T d_loop_ub;
              i = validNewRowIdx.size(1);
              loop_ub = BoardCoords.size(2);
              b_loop_ub = BoardCoords.size(2);
              k = BoardCoords.size(2);
              c_loop_ub = BoardCoords.size(2);
              d_loop_ub = BoardCoords.size(2);
              for (b_i = 0; b_i < i; b_i++) {
                real_T d1;
                if (b_i + 1 > validNewRowIdx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validNewRowIdx.size
                    (1), &nj_emlrtBCI, (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(0);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &mj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                idx = static_cast<int32_T>(muDoubleScalarFloor
                  (validNewRowIdx[b_i]));
                if (validNewRowIdx[b_i] != idx) {
                  emlrtIntegerCheckR2012b(validNewRowIdx[b_i], &kc_emlrtDCI,
                    (emlrtCTX)sp);
                }

                a = static_cast<int32_T>(validNewRowIdx[b_i]);
                if ((a < 1) || (a > i1)) {
                  emlrtDynamicBoundsCheckR2012b(a, 1, i1, &lj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                num.set_size(&bn_emlrtRTEI, sp, 1, 1, loop_ub);
                for (i1 = 0; i1 < loop_ub; i1++) {
                  num[i1] = BoardCoords[BoardCoords.size(0) * (a - 1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * i1];
                }

                i1 = BoardCoords.size(0);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &kj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                d = validNewRowIdx[b_i] + 2.0;
                ex = static_cast<int32_T>(muDoubleScalarFloor(d));
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &jc_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i1,
                    &jj_emlrtBCI, (emlrtCTX)sp);
                }

                r6.set_size(&cn_emlrtRTEI, sp, 1, 1, b_loop_ub);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  r6[i1] = BoardCoords[BoardCoords.size(0) *
                    (static_cast<int32_T>(d) - 1) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i1];
                }

                iv2[0] = (*(int32_T (*)[3])num.size())[0];
                iv2[1] = (*(int32_T (*)[3])num.size())[1];
                iv2[2] = (*(int32_T (*)[3])num.size())[2];
                iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &vb_emlrtECI,
                  (emlrtCTX)sp);
                i1 = BoardCoords.size(0);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ij_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                d1 = validNewRowIdx[b_i] + 1.0;
                if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
                  emlrtIntegerCheckR2012b(d1, &ic_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1, i1,
                    &hj_emlrtBCI, (emlrtCTX)sp);
                }

                last = static_cast<int32_T>(validNewRowIdx[b_i] + 1.0);
                denom.set_size(&dn_emlrtRTEI, sp, 1, 1, k);
                for (i1 = 0; i1 < k; i1++) {
                  denom[i1] = 2.0 * BoardCoords[BoardCoords.size(0) * (last - 1)
                    + BoardCoords.size(0) * BoardCoords.size(1) * i1];
                }

                iv2[0] = (*(int32_T (*)[3])num.size())[0];
                iv2[1] = (*(int32_T (*)[3])num.size())[1];
                iv2[2] = (*(int32_T (*)[3])num.size())[2];
                iv3[0] = (*(int32_T (*)[3])denom.size())[0];
                iv3[1] = (*(int32_T (*)[3])denom.size())[1];
                iv3[2] = (*(int32_T (*)[3])denom.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &vb_emlrtECI,
                  (emlrtCTX)sp);
                num.set_size(&en_emlrtRTEI, sp, 1, 1, num.size(2));
                last = num.size(2) - 1;
                for (i1 = 0; i1 <= last; i1++) {
                  num[i1] = (num[i1] + r6[i1]) - denom[i1];
                }

                i1 = BoardCoords.size(0);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &gj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if (validNewRowIdx[b_i] != idx) {
                  emlrtIntegerCheckR2012b(validNewRowIdx[b_i], &hc_emlrtDCI,
                    (emlrtCTX)sp);
                }

                if (a > i1) {
                  emlrtDynamicBoundsCheckR2012b(a, 1, i1, &fj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                denom.set_size(&fn_emlrtRTEI, sp, 1, 1, c_loop_ub);
                for (i1 = 0; i1 < c_loop_ub; i1++) {
                  denom[i1] = BoardCoords[BoardCoords.size(0) * (a - 1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * i1];
                }

                i1 = BoardCoords.size(0);
                if (1 > i1) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i1, &ej_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &gc_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i1,
                    &dj_emlrtBCI, (emlrtCTX)sp);
                }

                r6.set_size(&gn_emlrtRTEI, sp, 1, 1, d_loop_ub);
                for (i1 = 0; i1 < d_loop_ub; i1++) {
                  r6[i1] = BoardCoords[BoardCoords.size(0) *
                    (static_cast<int32_T>(d) - 1) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i1];
                }

                iv2[0] = (*(int32_T (*)[3])denom.size())[0];
                iv2[1] = (*(int32_T (*)[3])denom.size())[1];
                iv2[2] = (*(int32_T (*)[3])denom.size())[2];
                iv3[0] = (*(int32_T (*)[3])r6.size())[0];
                iv3[1] = (*(int32_T (*)[3])r6.size())[1];
                iv3[2] = (*(int32_T (*)[3])r6.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &ub_emlrtECI,
                  (emlrtCTX)sp);
                denom.set_size(&hn_emlrtRTEI, sp, 1, 1, denom.size(2));
                last = denom.size(2) - 1;
                for (i1 = 0; i1 <= last; i1++) {
                  denom[i1] = denom[i1] - r6[i1];
                }

                st.site = &qq_emlrtRSI;
                if (muSingleScalarIsNaN(newEnergy)) {
                  emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                    "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                }

                if (newEnergy != 0.0F) {
                  a = num.size(2);
                  last = denom.size(2);
                  c_num = num.reshape(a);
                  d_num = denom.reshape(last);
                  st.site = &rq_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(newEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  a = num.size(2);
                  last = denom.size(2);
                  c_num = num.reshape(a);
                  d_num = denom.reshape(last);
                  st.site = &sq_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                }
              }
            }

            st.site = &tq_emlrtRSI;
            if (muSingleScalarIsNaN(newEnergy)) {
              emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if (newEnergy != 0.0F) {
              last = BoardIdx.size(0) * BoardIdx.size(1);
              if (last < 0) {
                emlrtDynamicBoundsCheckR2012b(last, 0, MAX_int32_T, &cj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0) * BoardIdx.size(1);
              if (i < 0) {
                emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &bj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              newEnergy = newEnergy * static_cast<real32_T>(last) - static_cast<
                real32_T>(i);
            } else {
              newEnergy = rtInfF;
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            return newEnergy;
          }

          real32_T Checkerboard::computeNewEnergyVertical(const emlrtStack *sp,
            const ::coder::array<real_T, 2U> &idx, real32_T oldEnergy) const
          {
            array<real_T, 3U> b;
            array<real_T, 3U> denom;
            array<real_T, 3U> num;
            array<real_T, 3U> r3;
            array<real_T, 3U> r5;
            array<real_T, 3U> r7;
            array<real_T, 3U> r8;
            array<real_T, 2U> b_denom;
            array<real_T, 2U> b_num;
            array<real_T, 2U> validNewRowIdx;
            array<real_T, 1U> c_num;
            array<real_T, 1U> d_num;
            array<real_T, 1U> x;
            array<real_T, 1U> y;
            array<int32_T, 2U> r10;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r6;
            array<int32_T, 2U> r9;
            array<boolean_T, 2U> b_this;
            array<boolean_T, 2U> r;
            array<boolean_T, 2U> r1;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack i_st;
            emlrtStack st;
            real_T d;
            real_T ex;
            int32_T iv2[3];
            int32_T iv3[3];
            int32_T b_iv[2];
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
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &vl_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(0);
            i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
            if (idx[0] != i1) {
              emlrtIntegerCheckR2012b(idx[0], &rd_emlrtDCI, (emlrtCTX)sp);
            }

            b_idx = static_cast<int32_T>(idx[0]);
            if ((b_idx < 1) || (b_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &dk_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(1);
            b_this.set_size(&lm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[(b_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ul_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(0);
            i2 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
            if (idx[1] != i2) {
              emlrtIntegerCheckR2012b(idx[1], &qd_emlrtDCI, (emlrtCTX)sp);
            }

            c_idx = static_cast<int32_T>(idx[1]);
            if ((c_idx < 1) || (c_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &ck_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&mm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[(c_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])b_this.size())[0];
            b_iv[1] = (*(int32_T (*)[2])b_this.size())[1];
            iv1[0] = (*(int32_T (*)[2])r.size())[0];
            iv1[1] = (*(int32_T (*)[2])r.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &yb_emlrtECI, (emlrtCTX)
              sp);
            b_this.set_size(&lm_emlrtRTEI, sp, 1, b_this.size(1));
            loop_ub = b_this.size(1) - 1;
            for (i = 0; i <= loop_ub; i++) {
              b_this[i] = (b_this[i] && r[i]);
            }

            if (3 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &tl_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(0);
            i3 = static_cast<int32_T>(muDoubleScalarFloor(idx[2]));
            if (idx[2] != i3) {
              emlrtIntegerCheckR2012b(idx[2], &pd_emlrtDCI, (emlrtCTX)sp);
            }

            d_idx = static_cast<int32_T>(idx[2]);
            if ((d_idx < 1) || (d_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &bk_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&nm_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[(d_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])b_this.size())[0];
            b_iv[1] = (*(int32_T (*)[2])b_this.size())[1];
            iv1[0] = (*(int32_T (*)[2])r.size())[0];
            iv1[1] = (*(int32_T (*)[2])r.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &yb_emlrtECI, (emlrtCTX)
              sp);
            newEnergy = 0.0F;
            r1.set_size(&lm_emlrtRTEI, sp, 1, b_this.size(1));
            loop_ub = b_this.size(1);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (b_this[i] && r[i]);
            }

            st.site = &lq_emlrtRSI;
            if (c_any(&st, r1)) {
              end = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r2.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r2[last] = b_i + 1;
                  last++;
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &sl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(1);
              i = BoardCoords.size(0);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &od_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &ak_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r3.set_size(&pm_emlrtRTEI, sp, 1, r2.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r2.size(1);
                for (end = 0; end < b_loop_ub; end++) {
                  if (r2[end] > last) {
                    emlrtDynamicBoundsCheckR2012b(r2[end], 1, last, &ek_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r3[end + r3.size(1) * i] = BoardCoords[((b_idx +
                    BoardCoords.size(0) * (r2[end] - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              end = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r4.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r4[last] = b_i + 1;
                  last++;
                }
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &rl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(1);
              i = BoardCoords.size(0);
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &nd_emlrtDCI, (emlrtCTX)sp);
              }

              if (d_idx > i) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &yj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r5.set_size(&qm_emlrtRTEI, sp, 1, r4.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r4.size(1);
                for (end = 0; end < b_loop_ub; end++) {
                  if (r4[end] > last) {
                    emlrtDynamicBoundsCheckR2012b(r4[end], 1, last, &fk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r5[end + r5.size(1) * i] = BoardCoords[((d_idx +
                    BoardCoords.size(0) * (r4[end] - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              iv2[0] = (*(int32_T (*)[3])r3.size())[0];
              iv2[1] = (*(int32_T (*)[3])r3.size())[1];
              iv2[2] = (*(int32_T (*)[3])r3.size())[2];
              iv3[0] = (*(int32_T (*)[3])r5.size())[0];
              iv3[1] = (*(int32_T (*)[3])r5.size())[1];
              iv3[2] = (*(int32_T (*)[3])r5.size())[2];
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI, (emlrtCTX)
                sp);
              end = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r6.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r6[last] = b_i + 1;
                  last++;
                }
              }

              if (2 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &ql_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(1);
              i = BoardCoords.size(0);
              if (idx[1] != i2) {
                emlrtIntegerCheckR2012b(idx[1], &md_emlrtDCI, (emlrtCTX)sp);
              }

              if (c_idx > i) {
                emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &xj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              b.set_size(&rm_emlrtRTEI, sp, 1, r6.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r6.size(1);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  if (r6[i2] > last) {
                    emlrtDynamicBoundsCheckR2012b(r6[i2], 1, last, &gk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  b[i2 + b.size(1) * i] = BoardCoords[((c_idx + BoardCoords.size
                    (0) * (r6[i2] - 1)) + BoardCoords.size(0) * BoardCoords.size
                    (1) * i) - 1];
                }
              }

              loop_ub = b.size(1) * b.size(2);
              b.set_size(&sm_emlrtRTEI, sp, 1, b.size(1), b.size(2));
              for (i = 0; i < loop_ub; i++) {
                b[i] = 2.0 * b[i];
              }

              iv2[0] = (*(int32_T (*)[3])r3.size())[0];
              iv2[1] = (*(int32_T (*)[3])r3.size())[1];
              iv2[2] = (*(int32_T (*)[3])r3.size())[2];
              iv3[0] = (*(int32_T (*)[3])b.size())[0];
              iv3[1] = (*(int32_T (*)[3])b.size())[1];
              iv3[2] = (*(int32_T (*)[3])b.size())[2];
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &xb_emlrtECI, (emlrtCTX)
                sp);
              r8.set_size(&pm_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
              loop_ub = r3.size(1) * r3.size(2);
              for (i = 0; i < loop_ub; i++) {
                r8[i] = (r3[i] + r5[i]) - b[i];
              }

              st.site = &mq_emlrtRSI;
              squeeze(&st, r8, b_num);
              end = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r9.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r9[last] = b_i + 1;
                  last++;
                }
              }

              if (1 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &pl_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(1);
              i = BoardCoords.size(0);
              if (idx[0] != i1) {
                emlrtIntegerCheckR2012b(idx[0], &ld_emlrtDCI, (emlrtCTX)sp);
              }

              if (b_idx > i) {
                emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &wj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r3.set_size(&tm_emlrtRTEI, sp, 1, r9.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r9.size(1);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  if (r9[i2] > last) {
                    emlrtDynamicBoundsCheckR2012b(r9[i2], 1, last, &hk_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r3[i2 + r3.size(1) * i] = BoardCoords[((b_idx +
                    BoardCoords.size(0) * (r9[i2] - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              end = b_this.size(1) - 1;
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  last++;
                }
              }

              r10.set_size(&om_emlrtRTEI, sp, 1, last);
              last = 0;
              for (b_i = 0; b_i <= end; b_i++) {
                if (b_this[b_i] && r[b_i]) {
                  r10[last] = b_i + 1;
                  last++;
                }
              }

              if (3 > idx.size(1)) {
                emlrtDynamicBoundsCheckR2012b(3, 1, idx.size(1), &ol_emlrtBCI,
                  (emlrtCTX)sp);
              }

              last = BoardCoords.size(1);
              i = BoardCoords.size(0);
              if (idx[2] != i3) {
                emlrtIntegerCheckR2012b(idx[2], &kd_emlrtDCI, (emlrtCTX)sp);
              }

              if (d_idx > i) {
                emlrtDynamicBoundsCheckR2012b(d_idx, 1, i, &vj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r5.set_size(&um_emlrtRTEI, sp, 1, r10.size(1), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r10.size(1);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  if (r10[i2] > last) {
                    emlrtDynamicBoundsCheckR2012b(r10[i2], 1, last, &ik_emlrtBCI,
                      (emlrtCTX)sp);
                  }

                  r5[i2 + r5.size(1) * i] = BoardCoords[((d_idx +
                    BoardCoords.size(0) * (r10[i2] - 1)) + BoardCoords.size(0) *
                    BoardCoords.size(1) * i) - 1];
                }
              }

              iv2[0] = (*(int32_T (*)[3])r3.size())[0];
              iv2[1] = (*(int32_T (*)[3])r3.size())[1];
              iv2[2] = (*(int32_T (*)[3])r3.size())[2];
              iv3[0] = (*(int32_T (*)[3])r5.size())[0];
              iv3[1] = (*(int32_T (*)[3])r5.size())[1];
              iv3[2] = (*(int32_T (*)[3])r5.size())[2];
              emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &wb_emlrtECI, (emlrtCTX)
                sp);
              r8.set_size(&tm_emlrtRTEI, sp, 1, r3.size(1), r3.size(2));
              loop_ub = r3.size(1) * r3.size(2);
              for (i = 0; i < loop_ub; i++) {
                r8[i] = r3[i] - r5[i];
              }

              st.site = &nq_emlrtRSI;
              squeeze(&st, r8, b_denom);
              if (b_num.size(1) > 1) {
                st.site = &oq_emlrtRSI;
                loop_ub = b_num.size(0);
                c_num.set_size(&vm_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_num[i];
                }

                loop_ub = b_num.size(0);
                d_num.set_size(&wm_emlrtRTEI, &st, b_num.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_num[i + b_num.size(0)];
                }

                b_st.site = &oq_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, x);
                if (1 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, b_denom.size(1),
                    &uj_emlrtBCI, &st);
                }

                if (2 > b_denom.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, b_denom.size(1),
                    &tj_emlrtBCI, &st);
                }

                loop_ub = b_denom.size(0);
                c_num.set_size(&xm_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  c_num[i] = b_denom[i];
                }

                loop_ub = b_denom.size(0);
                d_num.set_size(&ym_emlrtRTEI, &st, b_denom.size(0));
                for (i = 0; i < loop_ub; i++) {
                  d_num[i] = b_denom[i + b_denom.size(0)];
                }

                b_st.site = &oq_emlrtRSI;
                b_hypot(&b_st, c_num, d_num, y);
                b_st.site = &ti_emlrtRSI;
                c_st.site = &ui_emlrtRSI;
                if (x.size(0) != y.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                    "MATLAB:dimagree", "MATLAB:dimagree", 0);
                }

                loop_ub = x.size(0);
                for (i = 0; i < loop_ub; i++) {
                  x[i] = x[i] / y[i];
                }

                st.site = &oq_emlrtRSI;
                b_st.site = &ge_emlrtRSI;
                c_st.site = &he_emlrtRSI;
                d_st.site = &ie_emlrtRSI;
                if (x.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &je_emlrtRSI;
                f_st.site = &ke_emlrtRSI;
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
                  g_st.site = &le_emlrtRSI;
                  if (!muDoubleScalarIsNaN(x[0])) {
                    c_idx = 1;
                  } else {
                    boolean_T exitg1;
                    c_idx = 0;
                    h_st.site = &ne_emlrtRSI;
                    if (x.size(0) > 2147483646) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    d_idx = 2;
                    exitg1 = false;
                    while ((!exitg1) && (d_idx <= last)) {
                      if (!muDoubleScalarIsNaN(x[d_idx - 1])) {
                        c_idx = d_idx;
                        exitg1 = true;
                      } else {
                        d_idx++;
                      }
                    }
                  }

                  if (c_idx == 0) {
                    ex = x[0];
                  } else {
                    g_st.site = &me_emlrtRSI;
                    ex = x[c_idx - 1];
                    end = c_idx + 1;
                    h_st.site = &oe_emlrtRSI;
                    if ((c_idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                      i_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&i_st);
                    }

                    for (d_idx = end; d_idx <= last; d_idx++) {
                      d = x[d_idx - 1];
                      if (ex < d) {
                        ex = d;
                      }
                    }
                  }
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (ex));
              } else {
                i = b_num.size(0) * b_num.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &sj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_num.size(0) * b_num.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &rj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (1 > i) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, i, &qj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                i = b_denom.size(0) * b_denom.size(1);
                if (2 > i) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, i, &pj_emlrtBCI, (emlrtCTX)
                    sp);
                }

                newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                  (muDoubleScalarHypot(b_num[0], b_num[1]) / muDoubleScalarHypot
                   (b_denom[0], b_denom[1])));
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &nl_emlrtBCI,
                (emlrtCTX)sp);
            }

            i = BoardIdx.size(0);
            if (idx[0] != i1) {
              emlrtIntegerCheckR2012b(idx[0], &jd_emlrtDCI, (emlrtCTX)sp);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &oj_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardIdx.size(1);
            b_this.set_size(&an_emlrtRTEI, sp, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_this[i] = (BoardIdx[(b_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            st.site = &pq_emlrtRSI;
            Checkerboard::arrayFind(&st, b_this, validNewRowIdx);
            if (validNewRowIdx.size(1) != 0) {
              int32_T c_loop_ub;
              int32_T d_loop_ub;
              i = validNewRowIdx.size(1);
              loop_ub = BoardCoords.size(2);
              b_loop_ub = BoardCoords.size(2);
              d_idx = BoardCoords.size(2);
              c_loop_ub = BoardCoords.size(2);
              d_loop_ub = BoardCoords.size(2);
              for (b_i = 0; b_i < i; b_i++) {
                real_T d1;
                if (b_i + 1 > validNewRowIdx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, validNewRowIdx.size
                    (1), &nj_emlrtBCI, (emlrtCTX)sp);
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &ml_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &id_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &mj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                i3 = static_cast<int32_T>(muDoubleScalarFloor(validNewRowIdx[b_i]));
                if (validNewRowIdx[b_i] != i3) {
                  emlrtIntegerCheckR2012b(validNewRowIdx[b_i], &kc_emlrtDCI,
                    (emlrtCTX)sp);
                }

                end = static_cast<int32_T>(validNewRowIdx[b_i]);
                if ((end < 1) || (end > i2)) {
                  emlrtDynamicBoundsCheckR2012b(end, 1, i2, &lj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                num.set_size(&bn_emlrtRTEI, sp, 1, 1, loop_ub);
                for (i2 = 0; i2 < loop_ub; i2++) {
                  num[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (end - 1))
                    + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &ll_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &hd_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &kj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                d = validNewRowIdx[b_i] + 2.0;
                ex = static_cast<int32_T>(muDoubleScalarFloor(d));
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &jc_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i2,
                    &jj_emlrtBCI, (emlrtCTX)sp);
                }

                r7.set_size(&cn_emlrtRTEI, sp, 1, 1, b_loop_ub);
                for (i2 = 0; i2 < b_loop_ub; i2++) {
                  r7[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (
                    static_cast<int32_T>(d) - 1)) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * i2) - 1];
                }

                iv2[0] = (*(int32_T (*)[3])num.size())[0];
                iv2[1] = (*(int32_T (*)[3])num.size())[1];
                iv2[2] = (*(int32_T (*)[3])num.size())[2];
                iv3[0] = (*(int32_T (*)[3])r7.size())[0];
                iv3[1] = (*(int32_T (*)[3])r7.size())[1];
                iv3[2] = (*(int32_T (*)[3])r7.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &vb_emlrtECI,
                  (emlrtCTX)sp);
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &kl_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &gd_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &ij_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                d1 = validNewRowIdx[b_i] + 1.0;
                if (d1 != static_cast<int32_T>(muDoubleScalarFloor(d1))) {
                  emlrtIntegerCheckR2012b(d1, &ic_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d1) < 1) || (static_cast<int32_T>(d1) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d1), 1, i2,
                    &hj_emlrtBCI, (emlrtCTX)sp);
                }

                last = static_cast<int32_T>(validNewRowIdx[b_i] + 1.0);
                denom.set_size(&dn_emlrtRTEI, sp, 1, 1, d_idx);
                for (i2 = 0; i2 < d_idx; i2++) {
                  denom[i2] = 2.0 * BoardCoords[((b_idx + BoardCoords.size(0) *
                    (last - 1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2)
                    - 1];
                }

                iv2[0] = (*(int32_T (*)[3])num.size())[0];
                iv2[1] = (*(int32_T (*)[3])num.size())[1];
                iv2[2] = (*(int32_T (*)[3])num.size())[2];
                iv3[0] = (*(int32_T (*)[3])denom.size())[0];
                iv3[1] = (*(int32_T (*)[3])denom.size())[1];
                iv3[2] = (*(int32_T (*)[3])denom.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &vb_emlrtECI,
                  (emlrtCTX)sp);
                num.set_size(&en_emlrtRTEI, sp, 1, 1, num.size(2));
                last = num.size(2) - 1;
                for (i2 = 0; i2 <= last; i2++) {
                  num[i2] = (num[i2] + r7[i2]) - denom[i2];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &jl_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &fd_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &gj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (validNewRowIdx[b_i] != i3) {
                  emlrtIntegerCheckR2012b(validNewRowIdx[b_i], &hc_emlrtDCI,
                    (emlrtCTX)sp);
                }

                if (end > i2) {
                  emlrtDynamicBoundsCheckR2012b(end, 1, i2, &fj_emlrtBCI,
                    (emlrtCTX)sp);
                }

                denom.set_size(&fn_emlrtRTEI, sp, 1, 1, c_loop_ub);
                for (i2 = 0; i2 < c_loop_ub; i2++) {
                  denom[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (end -
                    1)) + BoardCoords.size(0) * BoardCoords.size(1) * i2) - 1];
                }

                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &il_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(0);
                if (idx[0] != i1) {
                  emlrtIntegerCheckR2012b(idx[0], &ed_emlrtDCI, (emlrtCTX)sp);
                }

                if (b_idx > i2) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, i2, &ej_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i2 = BoardCoords.size(1);
                if (d != ex) {
                  emlrtIntegerCheckR2012b(d, &gc_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     i2)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, i2,
                    &dj_emlrtBCI, (emlrtCTX)sp);
                }

                r7.set_size(&gn_emlrtRTEI, sp, 1, 1, d_loop_ub);
                for (i2 = 0; i2 < d_loop_ub; i2++) {
                  r7[i2] = BoardCoords[((b_idx + BoardCoords.size(0) * (
                    static_cast<int32_T>(d) - 1)) + BoardCoords.size(0) *
                                        BoardCoords.size(1) * i2) - 1];
                }

                iv2[0] = (*(int32_T (*)[3])denom.size())[0];
                iv2[1] = (*(int32_T (*)[3])denom.size())[1];
                iv2[2] = (*(int32_T (*)[3])denom.size())[2];
                iv3[0] = (*(int32_T (*)[3])r7.size())[0];
                iv3[1] = (*(int32_T (*)[3])r7.size())[1];
                iv3[2] = (*(int32_T (*)[3])r7.size())[2];
                emlrtSizeEqCheckNDR2012b(&iv2[0], &iv3[0], &ub_emlrtECI,
                  (emlrtCTX)sp);
                denom.set_size(&hn_emlrtRTEI, sp, 1, 1, denom.size(2));
                last = denom.size(2) - 1;
                for (i2 = 0; i2 <= last; i2++) {
                  denom[i2] = denom[i2] - r7[i2];
                }

                st.site = &qq_emlrtRSI;
                if (muSingleScalarIsNaN(newEnergy)) {
                  emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                    "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
                }

                if (newEnergy != 0.0F) {
                  c_idx = num.size(2);
                  end = denom.size(2);
                  c_num = num.reshape(c_idx);
                  d_num = denom.reshape(end);
                  st.site = &rq_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(newEnergy, static_cast<real32_T>
                    (ex));
                } else {
                  c_idx = num.size(2);
                  end = denom.size(2);
                  c_num = num.reshape(c_idx);
                  d_num = denom.reshape(end);
                  st.site = &sq_emlrtRSI;
                  ex = b_norm(c_num) / b_norm(d_num);
                  newEnergy = muSingleScalarMax(oldEnergy, static_cast<real32_T>
                    (ex));
                }
              }
            }

            st.site = &tq_emlrtRSI;
            if (muSingleScalarIsNaN(newEnergy)) {
              emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
                "MATLAB:nologicalnan", "MATLAB:nologicalnan", 0);
            }

            if (newEnergy != 0.0F) {
              last = BoardIdx.size(0) * BoardIdx.size(1);
              if (last < 0) {
                emlrtDynamicBoundsCheckR2012b(last, 0, MAX_int32_T, &cj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              i = BoardIdx.size(0) * BoardIdx.size(1);
              if (i < 0) {
                emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &bj_emlrtBCI,
                  (emlrtCTX)sp);
              }

              newEnergy = newEnergy * static_cast<real32_T>(last) - static_cast<
                real32_T>(i);
            } else {
              newEnergy = rtInfF;
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
            return newEnergy;
          }

          void Checkerboard::expandBoardDirectionally(const emlrtStack *sp,
            real_T direction)
          {
            array<real_T, 3U> b_this;
            array<real_T, 3U> r;
            array<real_T, 2U> b_p2;
            array<real_T, 2U> idx;
            array<real_T, 2U> newIndices;
            array<real_T, 2U> newIndicesLinear;
            array<real_T, 2U> p1;
            array<real_T, 2U> p2;
            emlrtStack b_st;
            emlrtStack st;
            int32_T b_iv[2];
            int32_T iv1[2];
            int32_T i;
            int32_T numRows;
            real32_T oldEnergy;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            i = BoardIdx.size(0) * BoardIdx.size(1);
            if (i < 0) {
              emlrtDynamicBoundsCheckR2012b(i, 0, MAX_int32_T, &bg_emlrtBCI,
                (emlrtCTX)sp);
            }

            numRows = BoardIdx.size(0) * BoardIdx.size(1);
            if (numRows < 0) {
              emlrtDynamicBoundsCheckR2012b(numRows, 0, MAX_int32_T,
                &cg_emlrtBCI, (emlrtCTX)sp);
            }

            oldEnergy = (Energy + static_cast<real32_T>(i)) /
              static_cast<real32_T>(numRows);
            if (direction != static_cast<int32_T>(muDoubleScalarFloor(direction)))
            {
              emlrtIntegerCheckR2012b(direction, &bb_emlrtDCI, (emlrtCTX)sp);
            }

            switch (static_cast<int32_T>(direction)) {
             case 1:
              {
                int32_T loop_ub;
                if (IsDistortionHigh) {
                  st.site = &oj_emlrtRSI;
                  fitPolynomialIndices(&st, newIndices);
                  st.site = &pj_emlrtRSI;
                  if (!b_all(&st, newIndices)) {
                    int32_T b_i;
                    int32_T i1;
                    st.site = &qj_emlrtRSI;
                    i = BoardCoords.size(0);
                    if (2 > i) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, i, &hg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&qi_emlrtRTEI, &st, 1, loop_ub, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords
                          [(BoardCoords.size(0) * i1 + BoardCoords.size(0) *
                            BoardCoords.size(1) * i) + 1];
                      }
                    }

                    b_st.site = &ip_emlrtRSI;
                    squeeze(&b_st, b_this, p1);
                    i = BoardCoords.size(0);
                    if (1 > i) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, i, &ig_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&ri_emlrtRTEI, &st, 1, loop_ub, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] =
                          BoardCoords[BoardCoords.size(0) * i1 +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &jp_emlrtRSI;
                    squeeze(&b_st, b_this, p2);
                    b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &jb_emlrtECI,
                      &st);
                    b_p2.set_size(&si_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &rj_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndicesLinear);
                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if ((newIndices[b_i] == 0.0) && (b_i + 1 >
                           newIndicesLinear.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                          newIndicesLinear.size(1), &dg_emlrtBCI, (emlrtCTX)sp);
                      }
                    }

                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if (newIndices[b_i] == 0.0) {
                        if (b_i + 1 > newIndices.size(1)) {
                          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                            newIndices.size(1), &pg_emlrtBCI, (emlrtCTX)sp);
                        }

                        newIndices[b_i] = newIndicesLinear[b_i];
                      }
                    }
                  }
                } else {
                  int32_T i1;
                  st.site = &sj_emlrtRSI;
                  i = BoardCoords.size(0);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &hg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(1);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&qi_emlrtRTEI, &st, 1, loop_ub, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(1) * i] = BoardCoords
                        [(BoardCoords.size(0) * i1 + BoardCoords.size(0) *
                          BoardCoords.size(1) * i) + 1];
                    }
                  }

                  b_st.site = &ip_emlrtRSI;
                  squeeze(&b_st, b_this, p1);
                  i = BoardCoords.size(0);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &ig_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(1);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&ri_emlrtRTEI, &st, 1, loop_ub, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(1) * i] =
                        BoardCoords[BoardCoords.size(0) * i1 + BoardCoords.size
                        (0) * BoardCoords.size(1) * i];
                    }
                  }

                  b_st.site = &jp_emlrtRSI;
                  squeeze(&b_st, b_this, p2);
                  b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                  b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                  iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                  iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &jb_emlrtECI, &st);
                  b_p2.set_size(&si_emlrtRTEI, sp, p2.size(0), p2.size(1));
                  loop_ub = p2.size(0) * p2.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    b_p2[i] = (p2[i] + p2[i]) - p1[i];
                  }

                  st.site = &tj_emlrtRSI;
                  findClosestIndices(&st, b_p2, newIndices);
                }

                st.site = &uj_emlrtRSI;
                expandBoardUp(&st, newIndices, p1, r);
                BoardIdx.set_size(&ti_emlrtRTEI, sp, p1.size(0), p1.size(1));
                loop_ub = p1.size(0) * p1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  BoardIdx[i] = p1[i];
                }

                BoardCoords.set_size(&ui_emlrtRTEI, sp, r.size(0), r.size(1),
                                     r.size(2));
                loop_ub = r.size(0) * r.size(1) * r.size(2);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[i] = r[i];
                }

                st.site = &vj_emlrtRSI;
                oldEnergy = computeNewEnergyVertical(&st, oldEnergy);
              }
              break;

             case 2:
              {
                int32_T loop_ub;
                numRows = BoardCoords.size(0);
                st.site = &wj_emlrtRSI;
                if (numRows < static_cast<real_T>(numRows) - 2.0) {
                  idx.set_size(&vi_emlrtRTEI, &st, 1, 0);
                } else {
                  loop_ub = static_cast<int32_T>(-((static_cast<real_T>(numRows)
                    - 2.0) - static_cast<real_T>(numRows)));
                  idx.set_size(&vi_emlrtRTEI, &st, 1, loop_ub + 1);
                  for (i = 0; i <= loop_ub; i++) {
                    idx[i] = static_cast<real_T>(numRows) - static_cast<real_T>
                      (i);
                  }
                }

                if (IsDistortionHigh) {
                  st.site = &xj_emlrtRSI;
                  fitPolynomialIndices(&st, idx, newIndices);
                  st.site = &yj_emlrtRSI;
                  if (!b_all(&st, newIndices)) {
                    int32_T b_i;
                    int32_T i1;
                    st.site = &ak_emlrtRSI;
                    if (2 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                        &lg_emlrtBCI, &st);
                    }

                    if (idx[1] != static_cast<int32_T>(idx[1])) {
                      emlrtIntegerCheckR2012b(idx[1], &cb_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(0);
                    b_i = static_cast<int32_T>(idx[1]);
                    if ((b_i < 1) || (b_i > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                        1, i, &hg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&qi_emlrtRTEI, &st, 1, loop_ub, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords[((b_i +
                          BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i) - 1];
                      }
                    }

                    b_st.site = &ip_emlrtRSI;
                    squeeze(&b_st, b_this, p1);
                    if (1 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                        &mg_emlrtBCI, &st);
                    }

                    if (idx[0] != static_cast<int32_T>(idx[0])) {
                      emlrtIntegerCheckR2012b(idx[0], &db_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(0);
                    b_i = static_cast<int32_T>(idx[0]);
                    if ((b_i < 1) || (b_i > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                        1, i, &ig_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(1);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&ri_emlrtRTEI, &st, 1, loop_ub, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(1) * i] = BoardCoords[((b_i +
                          BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i) - 1];
                      }
                    }

                    b_st.site = &jp_emlrtRSI;
                    squeeze(&b_st, b_this, p2);
                    b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &jb_emlrtECI,
                      &st);
                    b_p2.set_size(&si_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &bk_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndicesLinear);
                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if ((newIndices[b_i] == 0.0) && (b_i + 1 >
                           newIndicesLinear.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                          newIndicesLinear.size(1), &fg_emlrtBCI, (emlrtCTX)sp);
                      }
                    }

                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if (newIndices[b_i] == 0.0) {
                        if (b_i + 1 > newIndices.size(1)) {
                          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                            newIndices.size(1), &rg_emlrtBCI, (emlrtCTX)sp);
                        }

                        newIndices[b_i] = newIndicesLinear[b_i];
                      }
                    }
                  }
                } else {
                  int32_T b_i;
                  int32_T i1;
                  st.site = &ck_emlrtRSI;
                  if (2 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                      &lg_emlrtBCI, &st);
                  }

                  b_i = static_cast<int32_T>(idx[1]);
                  if (idx[1] != b_i) {
                    emlrtIntegerCheckR2012b(idx[1], &cb_emlrtDCI, &st);
                  }

                  i = BoardCoords.size(0);
                  if ((b_i < 1) || (b_i > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                      1, i, &hg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(1);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&qi_emlrtRTEI, &st, 1, loop_ub, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(1) * i] = BoardCoords[((b_i +
                        BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                        BoardCoords.size(1) * i) - 1];
                    }
                  }

                  b_st.site = &ip_emlrtRSI;
                  squeeze(&b_st, b_this, p1);
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &mg_emlrtBCI, &st);
                  }

                  b_i = static_cast<int32_T>(idx[0]);
                  if (idx[0] != b_i) {
                    emlrtIntegerCheckR2012b(idx[0], &db_emlrtDCI, &st);
                  }

                  i = BoardCoords.size(0);
                  if ((b_i < 1) || (b_i > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                      1, i, &ig_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(1);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&ri_emlrtRTEI, &st, 1, loop_ub, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(1) * i] = BoardCoords[((b_i +
                        BoardCoords.size(0) * i1) + BoardCoords.size(0) *
                        BoardCoords.size(1) * i) - 1];
                    }
                  }

                  b_st.site = &jp_emlrtRSI;
                  squeeze(&b_st, b_this, p2);
                  b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                  b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                  iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                  iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &jb_emlrtECI, &st);
                  b_p2.set_size(&si_emlrtRTEI, sp, p2.size(0), p2.size(1));
                  loop_ub = p2.size(0) * p2.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    b_p2[i] = (p2[i] + p2[i]) - p1[i];
                  }

                  st.site = &dk_emlrtRSI;
                  findClosestIndices(&st, b_p2, newIndices);
                }

                st.site = &ek_emlrtRSI;
                expandBoardDown(&st, newIndices, p1, r);
                BoardIdx.set_size(&wi_emlrtRTEI, sp, p1.size(0), p1.size(1));
                loop_ub = p1.size(0) * p1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  BoardIdx[i] = p1[i];
                }

                BoardCoords.set_size(&xi_emlrtRTEI, sp, r.size(0), r.size(1),
                                     r.size(2));
                loop_ub = r.size(0) * r.size(1) * r.size(2);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[i] = r[i];
                }

                idx.set_size(&yi_emlrtRTEI, sp, 1, idx.size(1));
                loop_ub = idx.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  idx[i] = idx[i] + 1.0;
                }

                st.site = &fk_emlrtRSI;
                oldEnergy = computeNewEnergyVertical(&st, idx, oldEnergy);
              }
              break;

             case 3:
              {
                int32_T loop_ub;
                if (IsDistortionHigh) {
                  st.site = &gk_emlrtRSI;
                  b_fitPolynomialIndices(&st, newIndices);
                  st.site = &hk_emlrtRSI;
                  if (!b_all(&st, newIndices)) {
                    int32_T b_i;
                    int32_T i1;
                    st.site = &ik_emlrtRSI;
                    i = BoardCoords.size(1);
                    if (2 > i) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, i, &jg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&aj_emlrtRTEI, &st, loop_ub, 1, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0)) + BoardCoords.size(0) *
                          BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &er_emlrtRSI;
                    b_squeeze(&b_st, b_this, p1);
                    i = BoardCoords.size(1);
                    if (1 > i) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, i, &kg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&bj_emlrtRTEI, &st, loop_ub, 1, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[i1 +
                          BoardCoords.size(0) * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &fr_emlrtRSI;
                    b_squeeze(&b_st, b_this, p2);
                    b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &kb_emlrtECI,
                      &st);
                    b_p2.set_size(&cj_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &jk_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndicesLinear);
                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if ((newIndices[b_i] == 0.0) && (b_i + 1 >
                           newIndicesLinear.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                          newIndicesLinear.size(1), &eg_emlrtBCI, (emlrtCTX)sp);
                      }
                    }

                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if (newIndices[b_i] == 0.0) {
                        if (b_i + 1 > newIndices.size(1)) {
                          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                            newIndices.size(1), &qg_emlrtBCI, (emlrtCTX)sp);
                        }

                        newIndices[b_i] = newIndicesLinear[b_i];
                      }
                    }
                  }
                } else {
                  int32_T i1;
                  st.site = &kk_emlrtRSI;
                  i = BoardCoords.size(1);
                  if (2 > i) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, i, &jg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(0);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&aj_emlrtRTEI, &st, loop_ub, 1, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                        BoardCoords.size(0)) + BoardCoords.size(0) *
                        BoardCoords.size(1) * i];
                    }
                  }

                  b_st.site = &er_emlrtRSI;
                  b_squeeze(&b_st, b_this, p1);
                  i = BoardCoords.size(1);
                  if (1 > i) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, i, &kg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(0);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&bj_emlrtRTEI, &st, loop_ub, 1, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(0) * i] = BoardCoords[i1 +
                        BoardCoords.size(0) * BoardCoords.size(1) * i];
                    }
                  }

                  b_st.site = &fr_emlrtRSI;
                  b_squeeze(&b_st, b_this, p2);
                  b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                  b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                  iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                  iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &kb_emlrtECI, &st);
                  b_p2.set_size(&cj_emlrtRTEI, sp, p2.size(0), p2.size(1));
                  loop_ub = p2.size(0) * p2.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    b_p2[i] = (p2[i] + p2[i]) - p1[i];
                  }

                  st.site = &lk_emlrtRSI;
                  findClosestIndices(&st, b_p2, newIndices);
                }

                st.site = &mk_emlrtRSI;
                expandBoardLeft(&st, newIndices, p1, r);
                BoardIdx.set_size(&dj_emlrtRTEI, sp, p1.size(0), p1.size(1));
                loop_ub = p1.size(0) * p1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  BoardIdx[i] = p1[i];
                }

                BoardCoords.set_size(&ej_emlrtRTEI, sp, r.size(0), r.size(1),
                                     r.size(2));
                loop_ub = r.size(0) * r.size(1) * r.size(2);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[i] = r[i];
                }

                st.site = &nk_emlrtRSI;
                oldEnergy = computeNewEnergyHorizontal(&st, oldEnergy);
              }
              break;

             case 4:
              {
                int32_T loop_ub;
                numRows = BoardCoords.size(1);
                st.site = &ok_emlrtRSI;
                if (numRows < static_cast<real_T>(numRows) - 2.0) {
                  idx.set_size(&fj_emlrtRTEI, &st, 1, 0);
                } else {
                  loop_ub = static_cast<int32_T>(-((static_cast<real_T>(numRows)
                    - 2.0) - static_cast<real_T>(numRows)));
                  idx.set_size(&fj_emlrtRTEI, &st, 1, loop_ub + 1);
                  for (i = 0; i <= loop_ub; i++) {
                    idx[i] = static_cast<real_T>(numRows) - static_cast<real_T>
                      (i);
                  }
                }

                if (IsDistortionHigh) {
                  st.site = &pk_emlrtRSI;
                  b_fitPolynomialIndices(&st, idx, newIndices);
                  st.site = &qk_emlrtRSI;
                  if (!b_all(&st, newIndices)) {
                    int32_T b_i;
                    int32_T i1;
                    st.site = &rk_emlrtRSI;
                    if (2 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                        &ng_emlrtBCI, &st);
                    }

                    if (idx[1] != static_cast<int32_T>(idx[1])) {
                      emlrtIntegerCheckR2012b(idx[1], &eb_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(1);
                    b_i = static_cast<int32_T>(idx[1]);
                    if ((b_i < 1) || (b_i > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                        1, i, &jg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&aj_emlrtRTEI, &st, loop_ub, 1, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0) * (b_i - 1)) + BoardCoords.size(0)
                          * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &er_emlrtRSI;
                    b_squeeze(&b_st, b_this, p1);
                    if (1 > idx.size(1)) {
                      emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                        &og_emlrtBCI, &st);
                    }

                    if (idx[0] != static_cast<int32_T>(idx[0])) {
                      emlrtIntegerCheckR2012b(idx[0], &fb_emlrtDCI, &st);
                    }

                    i = BoardCoords.size(1);
                    b_i = static_cast<int32_T>(idx[0]);
                    if ((b_i < 1) || (b_i > i)) {
                      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                        1, i, &kg_emlrtBCI, &st);
                    }

                    loop_ub = BoardCoords.size(0);
                    numRows = BoardCoords.size(2);
                    b_this.set_size(&bj_emlrtRTEI, &st, loop_ub, 1, numRows);
                    for (i = 0; i < numRows; i++) {
                      for (i1 = 0; i1 < loop_ub; i1++) {
                        b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                          BoardCoords.size(0) * (b_i - 1)) + BoardCoords.size(0)
                          * BoardCoords.size(1) * i];
                      }
                    }

                    b_st.site = &fr_emlrtRSI;
                    b_squeeze(&b_st, b_this, p2);
                    b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                    b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                    iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                    iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                    emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &kb_emlrtECI,
                      &st);
                    b_p2.set_size(&cj_emlrtRTEI, sp, p2.size(0), p2.size(1));
                    loop_ub = p2.size(0) * p2.size(1);
                    for (i = 0; i < loop_ub; i++) {
                      b_p2[i] = (p2[i] + p2[i]) - p1[i];
                    }

                    st.site = &sk_emlrtRSI;
                    findClosestIndices(&st, b_p2, newIndicesLinear);
                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if ((newIndices[b_i] == 0.0) && (b_i + 1 >
                           newIndicesLinear.size(1))) {
                        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                          newIndicesLinear.size(1), &gg_emlrtBCI, (emlrtCTX)sp);
                      }
                    }

                    numRows = newIndices.size(1);
                    for (b_i = 0; b_i < numRows; b_i++) {
                      if (newIndices[b_i] == 0.0) {
                        if (b_i + 1 > newIndices.size(1)) {
                          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                            newIndices.size(1), &sg_emlrtBCI, (emlrtCTX)sp);
                        }

                        newIndices[b_i] = newIndicesLinear[b_i];
                      }
                    }
                  }
                } else {
                  int32_T b_i;
                  int32_T i1;
                  st.site = &tk_emlrtRSI;
                  if (2 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1),
                      &ng_emlrtBCI, &st);
                  }

                  b_i = static_cast<int32_T>(idx[1]);
                  if (idx[1] != b_i) {
                    emlrtIntegerCheckR2012b(idx[1], &eb_emlrtDCI, &st);
                  }

                  i = BoardCoords.size(1);
                  if ((b_i < 1) || (b_i > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[1]),
                      1, i, &jg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(0);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&aj_emlrtRTEI, &st, loop_ub, 1, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                        BoardCoords.size(0) * (b_i - 1)) + BoardCoords.size(0) *
                        BoardCoords.size(1) * i];
                    }
                  }

                  b_st.site = &er_emlrtRSI;
                  b_squeeze(&b_st, b_this, p1);
                  if (1 > idx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1),
                      &og_emlrtBCI, &st);
                  }

                  b_i = static_cast<int32_T>(idx[0]);
                  if (idx[0] != b_i) {
                    emlrtIntegerCheckR2012b(idx[0], &fb_emlrtDCI, &st);
                  }

                  i = BoardCoords.size(1);
                  if ((b_i < 1) || (b_i > i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(idx[0]),
                      1, i, &kg_emlrtBCI, &st);
                  }

                  loop_ub = BoardCoords.size(0);
                  numRows = BoardCoords.size(2);
                  b_this.set_size(&bj_emlrtRTEI, &st, loop_ub, 1, numRows);
                  for (i = 0; i < numRows; i++) {
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      b_this[i1 + b_this.size(0) * i] = BoardCoords[(i1 +
                        BoardCoords.size(0) * (b_i - 1)) + BoardCoords.size(0) *
                        BoardCoords.size(1) * i];
                    }
                  }

                  b_st.site = &fr_emlrtRSI;
                  b_squeeze(&b_st, b_this, p2);
                  b_iv[0] = (*(int32_T (*)[2])p2.size())[0];
                  b_iv[1] = (*(int32_T (*)[2])p2.size())[1];
                  iv1[0] = (*(int32_T (*)[2])p1.size())[0];
                  iv1[1] = (*(int32_T (*)[2])p1.size())[1];
                  emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &kb_emlrtECI, &st);
                  b_p2.set_size(&cj_emlrtRTEI, sp, p2.size(0), p2.size(1));
                  loop_ub = p2.size(0) * p2.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    b_p2[i] = (p2[i] + p2[i]) - p1[i];
                  }

                  st.site = &uk_emlrtRSI;
                  findClosestIndices(&st, b_p2, newIndices);
                }

                st.site = &vk_emlrtRSI;
                expandBoardRight(&st, newIndices, p1, r);
                BoardIdx.set_size(&gj_emlrtRTEI, sp, p1.size(0), p1.size(1));
                loop_ub = p1.size(0) * p1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  BoardIdx[i] = p1[i];
                }

                BoardCoords.set_size(&hj_emlrtRTEI, sp, r.size(0), r.size(1),
                                     r.size(2));
                loop_ub = r.size(0) * r.size(1) * r.size(2);
                for (i = 0; i < loop_ub; i++) {
                  BoardCoords[i] = r[i];
                }

                idx.set_size(&ij_emlrtRTEI, sp, 1, idx.size(1));
                loop_ub = idx.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  idx[i] = idx[i] + 1.0;
                }

                st.site = &wk_emlrtRSI;
                oldEnergy = computeNewEnergyHorizontal(&st, idx, oldEnergy);
              }
              break;

             default:
              oldEnergy = rtInfF;
              break;
            }

            Energy = oldEnergy;
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::expandBoardDown(const emlrtStack *sp, const ::coder::
            array<real_T, 2U> &indices, ::coder::array<real_T, 2U> &newBoard, ::
            coder::array<real_T, 3U> &newBoardCoords) const
          {
            array<real_T, 2U> r3;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> r;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r6;
            real_T d;
            int32_T iv1[3];
            int32_T b_iv[2];
            int32_T b_loop_ub;
            int32_T b_this;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &sc_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &rc_emlrtDCI, (emlrtCTX)sp);
            }

            newBoard.set_size(&in_emlrtRTEI, sp, static_cast<int32_T>(d),
                              newBoard.size(1));
            i = BoardIdx.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &tc_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoard.set_size(&in_emlrtRTEI, sp, newBoard.size(0), i);
            d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &ad_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &yc_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ad_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = static_cast<int32_T>(d) * i;
            for (i = 0; i < loop_ub; i++) {
              newBoard[i] = 0.0;
            }

            i = BoardIdx.size(0) + 1;
            i1 = BoardIdx.size(0) + 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &yk_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&jn_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            b_iv[0] = 1;
            b_iv[1] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&indices)->size(), 2, &ac_emlrtECI, (emlrtCTX)sp);
            b_this = BoardIdx.size(0);
            loop_ub = indices.size(1);
            for (i = 0; i < loop_ub; i++) {
              newBoard[b_this + newBoard.size(0) * r[i]] = indices[i];
            }

            if (1 > newBoard.size(0) - 1) {
              loop_ub = 0;
            } else {
              if (1 > newBoard.size(0)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, newBoard.size(0),
                  &al_emlrtBCI, (emlrtCTX)sp);
              }

              if ((newBoard.size(0) - 1 < 1) || (newBoard.size(0) - 1 >
                   newBoard.size(0))) {
                emlrtDynamicBoundsCheckR2012b(newBoard.size(0) - 1, 1,
                  newBoard.size(0), &bl_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = newBoard.size(0) - 1;
            }

            r.set_size(&kn_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = newBoard.size(1);
            r1.set_size(&ln_emlrtRTEI, sp, newBoard.size(1));
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            b_iv[0] = r.size(0);
            b_iv[1] = r1.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&BoardIdx)->size(), 2, &bc_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardIdx.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoard[r[i1] + newBoard.size(0) * r1[i]] = BoardIdx[i1 +
                  BoardIdx.size(0) * i];
              }
            }

            d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &vc_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &uc_emlrtDCI, (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&mn_emlrtRTEI, sp, static_cast<int32_T>(d),
              newBoardCoords.size(1), newBoardCoords.size(2));
            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &wc_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&mn_emlrtRTEI, sp, newBoardCoords.size(0), i,
              newBoardCoords.size(2));
            i = BoardCoords.size(2);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &xc_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&mn_emlrtRTEI, sp, newBoardCoords.size(0),
              newBoardCoords.size(1), i);
            d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &cd_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &bd_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &cd_emlrtDCI,
                (emlrtCTX)sp);
            }

            i1 = BoardCoords.size(2);
            if (i1 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &cd_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = static_cast<int32_T>(d) * i * i1;
            for (i = 0; i < loop_ub; i++) {
              newBoardCoords[i] = 0.0;
            }

            i = BoardCoords.size(0) + 1;
            i1 = BoardCoords.size(0) + 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &cl_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = indices.size(1);
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                i = BoardCoords.size(1);
                if (b_loop_ub + 1 > i) {
                  emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, i,
                    &fl_emlrtBCI, (emlrtCTX)sp);
                }
              }
            }

            loop_ub = BoardCoords.size(2);
            r.set_size(&nn_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r2.set_size(&on_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r2[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            b_this = Points.size(0);
            loop_ub = Points.size(1);
            r3.set_size(&pn_emlrtRTEI, sp, r2.size(1), loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = r2.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                if (r2[i1] > indices.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(r2[i1], 1, indices.size(1),
                    &hl_emlrtBCI, (emlrtCTX)sp);
                }

                d = indices[r2[i1] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &dd_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     b_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    b_this, &gl_emlrtBCI, (emlrtCTX)sp);
                }

                r3[i1 + r3.size(0) * i] = Points[(static_cast<int32_T>(d) +
                  Points.size(0) * i) - 1];
              }
            }

            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r4.set_size(&on_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r4[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            iv1[0] = 1;
            iv1[1] = r4.size(1);
            iv1[2] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r3.size(), 2, &cc_emlrtECI,
              (emlrtCTX)sp);
            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r5.set_size(&on_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r5[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            iv1[1] = r5.size(1);
            b_this = BoardCoords.size(0);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = iv1[1];
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoardCoords[(b_this + newBoardCoords.size(0) * (r5[i1] - 1))
                  + newBoardCoords.size(0) * newBoardCoords.size(1) * r[i]] =
                  r3[i1 + iv1[1] * i];
              }
            }

            if (1 > newBoardCoords.size(0) - 1) {
              loop_ub = 0;
            } else {
              if (1 > newBoardCoords.size(0)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, newBoardCoords.size(0),
                  &dl_emlrtBCI, (emlrtCTX)sp);
              }

              if ((newBoardCoords.size(0) - 1 < 1) || (newBoardCoords.size(0) -
                   1 > newBoardCoords.size(0))) {
                emlrtDynamicBoundsCheckR2012b(newBoardCoords.size(0) - 1, 1,
                  newBoardCoords.size(0), &el_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = newBoardCoords.size(0) - 1;
            }

            r.set_size(&qn_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = newBoardCoords.size(1);
            r1.set_size(&rn_emlrtRTEI, sp, newBoardCoords.size(1));
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            loop_ub = newBoardCoords.size(2);
            r6.set_size(&sn_emlrtRTEI, sp, newBoardCoords.size(2));
            for (i = 0; i < loop_ub; i++) {
              r6[i] = i;
            }

            iv1[0] = r.size(0);
            iv1[1] = r1.size(0);
            iv1[2] = r6.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
              3U> *)&BoardCoords)->size(), 3, &dc_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardCoords.size(2);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardCoords.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                b_this = BoardCoords.size(0);
                for (int32_T i2{0}; i2 < b_this; i2++) {
                  newBoardCoords[(r[i2] + newBoardCoords.size(0) * r1[i1]) +
                    newBoardCoords.size(0) * newBoardCoords.size(1) * r6[i]] =
                    BoardCoords[(i2 + BoardCoords.size(0) * i1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * i];
                }
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::expandBoardLeft(const emlrtStack *sp, const ::coder::
            array<real_T, 2U> &indices, ::coder::array<real_T, 2U> &newBoard, ::
            coder::array<real_T, 3U> &newBoardCoords) const
          {
            array<real_T, 2U> r3;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> r;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r6;
            real_T d;
            int32_T iv1[3];
            int32_T b_iv[2];
            int32_T b_loop_ub;
            int32_T i;
            int32_T i1;
            int32_T i2;
            int32_T loop_ub;
            int32_T trueCount;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            i = BoardIdx.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ae_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoard.set_size(&go_emlrtRTEI, sp, i, newBoard.size(1));
            d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &ce_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &be_emlrtDCI, (emlrtCTX)sp);
            }

            newBoard.set_size(&go_emlrtRTEI, sp, newBoard.size(0),
                              static_cast<int32_T>(d));
            i = BoardIdx.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &he_emlrtDCI,
                (emlrtCTX)sp);
            }

            d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &he_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &ie_emlrtDCI, (emlrtCTX)sp);
            }

            loop_ub = i * static_cast<int32_T>(d);
            for (i = 0; i < loop_ub; i++) {
              newBoard[i] = 0.0;
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&ho_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            i = BoardIdx.size(1) + 1;
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &dn_emlrtBCI, (emlrtCTX)sp);
            }

            emlrtSubAssignSizeCheckR2012b(r.size(), 1, ((::coder::array<real_T,
              2U> *)&indices)->size(), 2, &hc_emlrtECI, (emlrtCTX)sp);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              newBoard[r[i]] = indices[i];
            }

            if (2 > newBoard.size(1)) {
              i = 0;
              i1 = 0;
            } else {
              i = 1;
              i1 = newBoard.size(1);
            }

            loop_ub = newBoard.size(0);
            r.set_size(&io_emlrtRTEI, sp, newBoard.size(0));
            for (i2 = 0; i2 < loop_ub; i2++) {
              r[i2] = i2;
            }

            loop_ub = i1 - i;
            r1.set_size(&jo_emlrtRTEI, sp, loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r1[i1] = i + i1;
            }

            b_iv[0] = r.size(0);
            b_iv[1] = r1.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&BoardIdx)->size(), 2, &ic_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardIdx.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoard[r[i1] + newBoard.size(0) * r1[i]] = BoardIdx[i1 +
                  BoardIdx.size(0) * i];
              }
            }

            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &de_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&ko_emlrtRTEI, sp, i, newBoardCoords.size(1),
              newBoardCoords.size(2));
            d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &fe_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &ee_emlrtDCI, (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&ko_emlrtRTEI, sp, newBoardCoords.size(0),
              static_cast<int32_T>(d), newBoardCoords.size(2));
            i = BoardCoords.size(2);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ge_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&ko_emlrtRTEI, sp, newBoardCoords.size(0),
              newBoardCoords.size(1), i);
            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &je_emlrtDCI,
                (emlrtCTX)sp);
            }

            d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &je_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &ke_emlrtDCI, (emlrtCTX)sp);
            }

            i1 = BoardCoords.size(2);
            if (i1 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &je_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = i * static_cast<int32_T>(d) * i1;
            for (i = 0; i < loop_ub; i++) {
              newBoardCoords[i] = 0.0;
            }

            loop_ub = indices.size(1);
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                i = BoardCoords.size(0);
                if (b_loop_ub + 1 > i) {
                  emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, i,
                    &fn_emlrtBCI, (emlrtCTX)sp);
                }
              }
            }

            i = BoardCoords.size(1) + 1;
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &en_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardCoords.size(2);
            r.set_size(&lo_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r2.set_size(&mo_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r2[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            trueCount = Points.size(0);
            loop_ub = Points.size(1);
            r3.set_size(&no_emlrtRTEI, sp, r2.size(1), loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = r2.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                if (r2[i1] > indices.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(r2[i1], 1, indices.size(1),
                    &hn_emlrtBCI, (emlrtCTX)sp);
                }

                d = indices[r2[i1] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &le_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     trueCount)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    trueCount, &gn_emlrtBCI, (emlrtCTX)sp);
                }

                r3[i1 + r3.size(0) * i] = Points[(static_cast<int32_T>(d) +
                  Points.size(0) * i) - 1];
              }
            }

            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r4.set_size(&mo_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r4[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            iv1[0] = r4.size(1);
            iv1[1] = 1;
            iv1[2] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r3.size(), 2, &jc_emlrtECI,
              (emlrtCTX)sp);
            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r5.set_size(&mo_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r5[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            iv1[0] = r5.size(1);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = iv1[0];
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoardCoords[(r5[i1] + newBoardCoords.size(0) *
                                newBoardCoords.size(1) * r[i]) - 1] = r3[i1 +
                  iv1[0] * i];
              }
            }

            if (2 > newBoardCoords.size(1)) {
              i = 0;
              i1 = 0;
            } else {
              i = 1;
              i1 = newBoardCoords.size(1);
            }

            loop_ub = newBoardCoords.size(0);
            r.set_size(&oo_emlrtRTEI, sp, newBoardCoords.size(0));
            for (i2 = 0; i2 < loop_ub; i2++) {
              r[i2] = i2;
            }

            loop_ub = i1 - i;
            r1.set_size(&po_emlrtRTEI, sp, loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r1[i1] = i + i1;
            }

            loop_ub = newBoardCoords.size(2);
            r6.set_size(&qo_emlrtRTEI, sp, newBoardCoords.size(2));
            for (i = 0; i < loop_ub; i++) {
              r6[i] = i;
            }

            iv1[0] = r.size(0);
            iv1[1] = r1.size(0);
            iv1[2] = r6.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
              3U> *)&BoardCoords)->size(), 3, &kc_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardCoords.size(2);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardCoords.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                trueCount = BoardCoords.size(0);
                for (i2 = 0; i2 < trueCount; i2++) {
                  newBoardCoords[(r[i2] + newBoardCoords.size(0) * r1[i1]) +
                    newBoardCoords.size(0) * newBoardCoords.size(1) * r6[i]] =
                    BoardCoords[(i2 + BoardCoords.size(0) * i1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * i];
                }
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::expandBoardRight(const emlrtStack *sp, const ::
            coder::array<real_T, 2U> &indices, ::coder::array<real_T, 2U>
            &newBoard, ::coder::array<real_T, 3U> &newBoardCoords) const
          {
            array<real_T, 2U> r3;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> r;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r6;
            real_T d;
            int32_T iv1[3];
            int32_T b_iv[2];
            int32_T b_loop_ub;
            int32_T b_this;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            i = BoardIdx.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &xe_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoard.set_size(&np_emlrtRTEI, sp, i, newBoard.size(1));
            d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &af_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &ye_emlrtDCI, (emlrtCTX)sp);
            }

            newBoard.set_size(&np_emlrtRTEI, sp, newBoard.size(0),
                              static_cast<int32_T>(d));
            i = BoardIdx.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ff_emlrtDCI,
                (emlrtCTX)sp);
            }

            d = static_cast<real_T>(BoardIdx.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &ff_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &gf_emlrtDCI, (emlrtCTX)sp);
            }

            loop_ub = i * static_cast<int32_T>(d);
            for (i = 0; i < loop_ub; i++) {
              newBoard[i] = 0.0;
            }

            loop_ub = BoardIdx.size(0);
            r.set_size(&op_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            i = BoardIdx.size(1) + 1;
            i1 = BoardIdx.size(1) + 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &ep_emlrtBCI, (emlrtCTX)sp);
            }

            emlrtSubAssignSizeCheckR2012b(r.size(), 1, ((::coder::array<real_T,
              2U> *)&indices)->size(), 2, &qc_emlrtECI, (emlrtCTX)sp);
            b_this = BoardIdx.size(1);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              newBoard[r[i] + newBoard.size(0) * b_this] = indices[i];
            }

            if (1 > newBoard.size(1) - 1) {
              loop_ub = 0;
            } else {
              if (1 > newBoard.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, newBoard.size(1),
                  &fp_emlrtBCI, (emlrtCTX)sp);
              }

              if ((newBoard.size(1) - 1 < 1) || (newBoard.size(1) - 1 >
                   newBoard.size(1))) {
                emlrtDynamicBoundsCheckR2012b(newBoard.size(1) - 1, 1,
                  newBoard.size(1), &gp_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = newBoard.size(1) - 1;
            }

            b_loop_ub = newBoard.size(0);
            r.set_size(&pp_emlrtRTEI, sp, newBoard.size(0));
            for (i = 0; i < b_loop_ub; i++) {
              r[i] = i;
            }

            r1.set_size(&qp_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            b_iv[0] = r.size(0);
            b_iv[1] = r1.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&BoardIdx)->size(), 2, &rc_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardIdx.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoard[r[i1] + newBoard.size(0) * r1[i]] = BoardIdx[i1 +
                  BoardIdx.size(0) * i];
              }
            }

            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &bf_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&rp_emlrtRTEI, sp, i, newBoardCoords.size(1),
              newBoardCoords.size(2));
            d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &df_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &cf_emlrtDCI, (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&rp_emlrtRTEI, sp, newBoardCoords.size(0),
              static_cast<int32_T>(d), newBoardCoords.size(2));
            i = BoardCoords.size(2);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ef_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&rp_emlrtRTEI, sp, newBoardCoords.size(0),
              newBoardCoords.size(1), i);
            i = BoardCoords.size(0);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &hf_emlrtDCI,
                (emlrtCTX)sp);
            }

            d = static_cast<real_T>(BoardCoords.size(1)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &hf_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &if_emlrtDCI, (emlrtCTX)sp);
            }

            i1 = BoardCoords.size(2);
            if (i1 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &hf_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = i * static_cast<int32_T>(d) * i1;
            for (i = 0; i < loop_ub; i++) {
              newBoardCoords[i] = 0.0;
            }

            loop_ub = indices.size(1);
            for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                i = BoardCoords.size(0);
                if (b_loop_ub + 1 > i) {
                  emlrtDynamicBoundsCheckR2012b(b_loop_ub + 1, 1, i,
                    &kp_emlrtBCI, (emlrtCTX)sp);
                }
              }
            }

            i = BoardCoords.size(1) + 1;
            i1 = BoardCoords.size(1) + 1;
            if ((i1 < 1) || (i1 > i)) {
              emlrtDynamicBoundsCheckR2012b(i1, 1, i, &hp_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardCoords.size(2);
            r.set_size(&sp_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r2.set_size(&tp_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r2[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            b_this = Points.size(0);
            loop_ub = Points.size(1);
            r3.set_size(&up_emlrtRTEI, sp, r2.size(1), loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = r2.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                if (r2[i1] > indices.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(r2[i1], 1, indices.size(1),
                    &mp_emlrtBCI, (emlrtCTX)sp);
                }

                d = indices[r2[i1] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &jf_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     b_this)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    b_this, &lp_emlrtBCI, (emlrtCTX)sp);
                }

                r3[i1 + r3.size(0) * i] = Points[(static_cast<int32_T>(d) +
                  Points.size(0) * i) - 1];
              }
            }

            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r4.set_size(&tp_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r4[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            iv1[0] = r4.size(1);
            iv1[1] = 1;
            iv1[2] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r3.size(), 2, &sc_emlrtECI,
              (emlrtCTX)sp);
            loop_ub = indices.size(1) - 1;
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                b_this++;
              }
            }

            r5.set_size(&tp_emlrtRTEI, sp, 1, b_this);
            b_this = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r5[b_this] = b_loop_ub + 1;
                b_this++;
              }
            }

            iv1[0] = r5.size(1);
            b_this = BoardCoords.size(1);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = iv1[0];
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoardCoords[((r5[i1] + newBoardCoords.size(0) * b_this) +
                                newBoardCoords.size(0) * newBoardCoords.size(1) *
                                r[i]) - 1] = r3[i1 + iv1[0] * i];
              }
            }

            if (1 > newBoardCoords.size(1) - 1) {
              loop_ub = 0;
            } else {
              if (1 > newBoardCoords.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, newBoardCoords.size(1),
                  &ip_emlrtBCI, (emlrtCTX)sp);
              }

              if ((newBoardCoords.size(1) - 1 < 1) || (newBoardCoords.size(1) -
                   1 > newBoardCoords.size(1))) {
                emlrtDynamicBoundsCheckR2012b(newBoardCoords.size(1) - 1, 1,
                  newBoardCoords.size(1), &jp_emlrtBCI, (emlrtCTX)sp);
              }

              loop_ub = newBoardCoords.size(1) - 1;
            }

            b_loop_ub = newBoardCoords.size(0);
            r.set_size(&vp_emlrtRTEI, sp, newBoardCoords.size(0));
            for (i = 0; i < b_loop_ub; i++) {
              r[i] = i;
            }

            r1.set_size(&wp_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            loop_ub = newBoardCoords.size(2);
            r6.set_size(&xp_emlrtRTEI, sp, newBoardCoords.size(2));
            for (i = 0; i < loop_ub; i++) {
              r6[i] = i;
            }

            iv1[0] = r.size(0);
            iv1[1] = r1.size(0);
            iv1[2] = r6.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
              3U> *)&BoardCoords)->size(), 3, &tc_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardCoords.size(2);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardCoords.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                b_this = BoardCoords.size(0);
                for (int32_T i2{0}; i2 < b_this; i2++) {
                  newBoardCoords[(r[i2] + newBoardCoords.size(0) * r1[i1]) +
                    newBoardCoords.size(0) * newBoardCoords.size(1) * r6[i]] =
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
            array<real_T, 2U> r3;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> r;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r6;
            real_T d;
            int32_T iv1[3];
            int32_T b_iv[2];
            int32_T b_loop_ub;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            int32_T trueCount;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &ub_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &tb_emlrtDCI, (emlrtCTX)sp);
            }

            newBoard.set_size(&am_emlrtRTEI, sp, static_cast<int32_T>(d),
                              newBoard.size(1));
            i = BoardIdx.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &vb_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoard.set_size(&am_emlrtRTEI, sp, newBoard.size(0), i);
            d = static_cast<real_T>(BoardIdx.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &cc_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &bc_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardIdx.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &cc_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = static_cast<int32_T>(d) * i;
            for (i = 0; i < loop_ub; i++) {
              newBoard[i] = 0.0;
            }

            i = BoardIdx.size(0) + 1;
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &vi_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&bm_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            b_iv[0] = 1;
            b_iv[1] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&indices)->size(), 2, &qb_emlrtECI, (emlrtCTX)sp);
            loop_ub = indices.size(1);
            for (i = 0; i < loop_ub; i++) {
              newBoard[newBoard.size(0) * r[i]] = indices[i];
            }

            if (2 > newBoard.size(0)) {
              i = 0;
              i1 = 0;
            } else {
              i = 1;
              i1 = newBoard.size(0);
            }

            loop_ub = i1 - i;
            r.set_size(&cm_emlrtRTEI, sp, loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i + i1;
            }

            loop_ub = newBoard.size(1);
            r1.set_size(&dm_emlrtRTEI, sp, newBoard.size(1));
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            b_iv[0] = r.size(0);
            b_iv[1] = r1.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, ((::coder::array<real_T,
              2U> *)&BoardIdx)->size(), 2, &rb_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardIdx.size(0);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoard[r[i1] + newBoard.size(0) * r1[i]] = BoardIdx[i1 +
                  BoardIdx.size(0) * i];
              }
            }

            d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &xb_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &wb_emlrtDCI, (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&em_emlrtRTEI, sp, static_cast<int32_T>(d),
              newBoardCoords.size(1), newBoardCoords.size(2));
            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &yb_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&em_emlrtRTEI, sp, newBoardCoords.size(0), i,
              newBoardCoords.size(2));
            i = BoardCoords.size(2);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ac_emlrtDCI,
                (emlrtCTX)sp);
            }

            newBoardCoords.set_size(&em_emlrtRTEI, sp, newBoardCoords.size(0),
              newBoardCoords.size(1), i);
            d = static_cast<real_T>(BoardCoords.size(0)) + 1.0;
            if (!(d >= 0.0)) {
              emlrtNonNegativeCheckR2012b(d, &ec_emlrtDCI, (emlrtCTX)sp);
            }

            if (d != static_cast<int32_T>(d)) {
              emlrtIntegerCheckR2012b(d, &dc_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &ec_emlrtDCI,
                (emlrtCTX)sp);
            }

            i1 = BoardCoords.size(2);
            if (i1 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i1), &ec_emlrtDCI,
                (emlrtCTX)sp);
            }

            loop_ub = static_cast<int32_T>(d) * i * i1;
            for (i = 0; i < loop_ub; i++) {
              newBoardCoords[i] = 0.0;
            }

            i = BoardCoords.size(0) + 1;
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &wi_emlrtBCI, (emlrtCTX)sp);
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

            loop_ub = BoardCoords.size(2);
            r.set_size(&fm_emlrtRTEI, sp, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = i;
            }

            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r2.set_size(&gm_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r2[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            trueCount = Points.size(0);
            loop_ub = Points.size(1);
            r3.set_size(&hm_emlrtRTEI, sp, r2.size(1), loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = r2.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                if (r2[i1] > indices.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(r2[i1], 1, indices.size(1),
                    &aj_emlrtBCI, (emlrtCTX)sp);
                }

                d = indices[r2[i1] - 1];
                if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                  emlrtIntegerCheckR2012b(d, &fc_emlrtDCI, (emlrtCTX)sp);
                }

                if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                     trueCount)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                    trueCount, &yi_emlrtBCI, (emlrtCTX)sp);
                }

                r3[i1 + r3.size(0) * i] = Points[(static_cast<int32_T>(d) +
                  Points.size(0) * i) - 1];
              }
            }

            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r4.set_size(&gm_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r4[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            iv1[0] = 1;
            iv1[1] = r4.size(1);
            iv1[2] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, r3.size(), 2, &sb_emlrtECI,
              (emlrtCTX)sp);
            loop_ub = indices.size(1) - 1;
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                trueCount++;
              }
            }

            r5.set_size(&gm_emlrtRTEI, sp, 1, trueCount);
            trueCount = 0;
            for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
              if (indices[b_loop_ub] > 0.0) {
                r5[trueCount] = b_loop_ub + 1;
                trueCount++;
              }
            }

            iv1[1] = r5.size(1);
            loop_ub = r.size(0);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = iv1[1];
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                newBoardCoords[newBoardCoords.size(0) * (r5[i1] - 1) +
                  newBoardCoords.size(0) * newBoardCoords.size(1) * r[i]] =
                  r3[i1 + iv1[1] * i];
              }
            }

            if (2 > newBoardCoords.size(0)) {
              i = 0;
              i1 = 0;
            } else {
              i = 1;
              i1 = newBoardCoords.size(0);
            }

            loop_ub = i1 - i;
            r.set_size(&im_emlrtRTEI, sp, loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i + i1;
            }

            loop_ub = newBoardCoords.size(1);
            r1.set_size(&jm_emlrtRTEI, sp, newBoardCoords.size(1));
            for (i = 0; i < loop_ub; i++) {
              r1[i] = i;
            }

            loop_ub = newBoardCoords.size(2);
            r6.set_size(&km_emlrtRTEI, sp, newBoardCoords.size(2));
            for (i = 0; i < loop_ub; i++) {
              r6[i] = i;
            }

            iv1[0] = r.size(0);
            iv1[1] = r1.size(0);
            iv1[2] = r6.size(0);
            emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, ((::coder::array<real_T,
              3U> *)&BoardCoords)->size(), 3, &tb_emlrtECI, (emlrtCTX)sp);
            loop_ub = BoardCoords.size(2);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = BoardCoords.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                trueCount = BoardCoords.size(0);
                for (int32_T i2{0}; i2 < trueCount; i2++) {
                  newBoardCoords[(r[i2] + newBoardCoords.size(0) * r1[i1]) +
                    newBoardCoords.size(0) * newBoardCoords.size(1) * r6[i]] =
                    BoardCoords[(i2 + BoardCoords.size(0) * i1) +
                    BoardCoords.size(0) * BoardCoords.size(1) * i];
                }
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::findClosestIndices(const emlrtStack *sp, const ::
            coder::array<real_T, 2U> &predictedPoints, ::coder::array<real_T, 2U>
            &indices) const
          {
            array<real_T, 2U> remIdx;
            array<real_T, 2U> y;
            array<real_T, 1U> b_this;
            array<int32_T, 2U> r;
            array<int32_T, 1U> ib;
            array<int32_T, 1U> ii;
            array<real32_T, 2U> a;
            array<real32_T, 2U> diffs;
            array<real32_T, 1U> b_diffs;
            array<real32_T, 1U> c_diffs;
            array<real32_T, 1U> dists;
            array<uint32_T, 1U> validPredictions;
            array<boolean_T, 2U> distIdx;
            array<boolean_T, 1U> x;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack st;
            int32_T b_iv[2];
            int32_T c_this;
            int32_T i;
            int32_T i1;
            int32_T i2;
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
            indices.set_size(&ql_emlrtRTEI, sp, 1, predictedPoints.size(0));
            nx = predictedPoints.size(0);
            for (i = 0; i < nx; i++) {
              indices[i] = 0.0;
            }

            nx = Points.size(0);
            if (nx < 1) {
              y.set_size(&dk_emlrtRTEI, sp, 1, 0);
            } else {
              y.set_size(&dk_emlrtRTEI, sp, 1, nx);
              nx--;
              for (i = 0; i <= nx; i++) {
                y[i] = static_cast<real_T>(i) + 1.0;
              }
            }

            st.site = &np_emlrtRSI;
            b_st.site = &wn_emlrtRSI;
            nx = BoardIdx.size(0) * BoardIdx.size(1);
            b_this = BoardIdx.reshape(nx);
            c_st.site = &xn_emlrtRSI;
            do_vectors(&c_st, y, b_this, remIdx, ii, ib);
            if (remIdx.size(1) != 0) {
              int32_T acoef;
              int32_T idx;
              boolean_T exitg1;
              st.site = &op_emlrtRSI;
              if (1 > predictedPoints.size(1)) {
                emlrtDynamicBoundsCheckR2012b(1, 1, predictedPoints.size(1),
                  &ni_emlrtBCI, &st);
              }

              b_st.site = &jf_emlrtRSI;
              nx = predictedPoints.size(0);
              x.set_size(&ye_emlrtRTEI, &b_st, predictedPoints.size(0));
              for (i = 0; i < nx; i++) {
                x[i] = muDoubleScalarIsNaN(predictedPoints[i]);
              }

              nx = x.size(0);
              for (i = 0; i < nx; i++) {
                x[i] = !x[i];
              }

              nx = x.size(0);
              c_st.site = &kf_emlrtRSI;
              idx = 0;
              ii.set_size(&nf_emlrtRTEI, &c_st, x.size(0));
              d_st.site = &mf_emlrtRSI;
              if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
                e_st.site = &yc_emlrtRSI;
                check_forloop_overflow_error(&e_st);
              }

              acoef = 0;
              exitg1 = false;
              while ((!exitg1) && (acoef <= nx - 1)) {
                if (x[acoef]) {
                  idx++;
                  ii[idx - 1] = acoef + 1;
                  if (idx >= nx) {
                    exitg1 = true;
                  } else {
                    acoef++;
                  }
                } else {
                  acoef++;
                }
              }

              if (idx > x.size(0)) {
                emlrtErrorWithMessageIdR2018a(&c_st, &t_emlrtRTEI,
                  "Coder:builtins:AssertionFailed",
                  "Coder:builtins:AssertionFailed", 0);
              }

              if (x.size(0) == 1) {
                if (idx == 0) {
                  ii.set_size(&rl_emlrtRTEI, &c_st, 0);
                }
              } else {
                if (1 > idx) {
                  i = 0;
                } else {
                  i = idx;
                }

                b_iv[0] = 1;
                b_iv[1] = i;
                d_st.site = &nf_emlrtRSI;
                ::coder::internal::indexShapeCheck(&d_st, ii.size(0), b_iv);
                ii.set_size(&rl_emlrtRTEI, &c_st, i);
              }

              validPredictions.set_size(&sl_emlrtRTEI, &st, ii.size(0));
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
                int32_T k;
                int32_T varargin_2;
                if (b_i + 1 > validPredictions.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                    validPredictions.size(0), &oi_emlrtBCI, (emlrtCTX)sp);
                }

                varargin_2 = static_cast<int32_T>(validPredictions[b_i]);
                if (varargin_2 > predictedPoints.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(varargin_2, 1,
                    predictedPoints.size(0), &mi_emlrtBCI, (emlrtCTX)sp);
                }

                st.site = &pp_emlrtRSI;
                a.set_size(&tl_emlrtRTEI, &st, remIdx.size(1), loop_ub);
                for (varargin_2 = 0; varargin_2 < loop_ub; varargin_2++) {
                  nx = remIdx.size(1);
                  for (idx = 0; idx < nx; idx++) {
                    if (remIdx[idx] != static_cast<int32_T>(muDoubleScalarFloor
                         (remIdx[idx]))) {
                      emlrtIntegerCheckR2012b(remIdx[idx], &sb_emlrtDCI, &st);
                    }

                    acoef = static_cast<int32_T>(remIdx[idx]);
                    if ((acoef < 1) || (acoef > c_this)) {
                      emlrtDynamicBoundsCheckR2012b(acoef, 1, c_this,
                        &pi_emlrtBCI, &st);
                    }

                    a[idx + a.size(0) * varargin_2] = Points[(acoef +
                      Points.size(0) * varargin_2) - 1];
                  }
                }

                if (i1 == 1) {
                  i2 = a.size(1);
                } else if (a.size(1) == 1) {
                  i2 = predictedPoints.size(1);
                } else if (predictedPoints.size(1) == a.size(1)) {
                  i2 = a.size(1);
                } else {
                  emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
                    "MATLAB:bsxfun:arrayDimensionsMustMatch",
                    "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
                }

                diffs.set_size(&ig_emlrtRTEI, &st, a.size(0), i2);
                if (i2 != 0) {
                  b_st.site = &hi_emlrtRSI;
                  acoef = (a.size(1) != 1);
                  idx = (predictedPoints.size(1) != 1);
                  nx = i2 - 1;
                  c_st.site = &ii_emlrtRSI;
                  for (k = 0; k <= nx; k++) {
                    int32_T b;
                    int32_T b_acoef;
                    int32_T varargin_3;
                    varargin_2 = acoef * k;
                    varargin_3 = idx * k;
                    c_st.site = &ji_emlrtRSI;
                    b_acoef = (a.size(0) != 1);
                    b = diffs.size(0) - 1;
                    d_st.site = &ii_emlrtRSI;
                    for (int32_T b_k{0}; b_k <= b; b_k++) {
                      diffs[b_k + diffs.size(0) * k] = a[b_acoef * b_k + a.size
                        (0) * varargin_2] - static_cast<real32_T>
                        (predictedPoints[(static_cast<int32_T>
                                          (validPredictions[b_i]) +
                                          predictedPoints.size(0) * varargin_3)
                         - 1]);
                    }
                  }
                }

                if (1 > diffs.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, diffs.size(1),
                    &li_emlrtBCI, (emlrtCTX)sp);
                }

                if (2 > diffs.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(2, 1, diffs.size(1),
                    &ki_emlrtBCI, (emlrtCTX)sp);
                }

                nx = diffs.size(0);
                b_diffs.set_size(&ul_emlrtRTEI, sp, diffs.size(0));
                for (varargin_2 = 0; varargin_2 < nx; varargin_2++) {
                  b_diffs[varargin_2] = diffs[varargin_2];
                }

                nx = diffs.size(0);
                c_diffs.set_size(&vl_emlrtRTEI, sp, diffs.size(0));
                for (varargin_2 = 0; varargin_2 < nx; varargin_2++) {
                  c_diffs[varargin_2] = diffs[varargin_2 + diffs.size(0)];
                }

                st.site = &qp_emlrtRSI;
                b_hypot(&st, b_diffs, c_diffs, dists);
                acoef = indices.size(1) - 1;
                nx = 0;
                for (idx = 0; idx <= acoef; idx++) {
                  if (indices[idx] > 0.0) {
                    nx++;
                  }
                }

                r.set_size(&wl_emlrtRTEI, sp, 1, nx);
                nx = 0;
                for (idx = 0; idx <= acoef; idx++) {
                  if (indices[idx] > 0.0) {
                    r[nx] = idx + 1;
                    nx++;
                  }
                }

                st.site = &rp_emlrtRSI;
                nx = r.size(1);
                for (varargin_2 = 0; varargin_2 < nx; varargin_2++) {
                  if ((r[varargin_2] < 1) || (r[varargin_2] > indices.size(1)))
                  {
                    emlrtDynamicBoundsCheckR2012b(r[varargin_2], 1, indices.size
                      (1), &qi_emlrtBCI, &st);
                  }
                }

                y.set_size(&xl_emlrtRTEI, &st, 1, r.size(1));
                nx = r.size(1);
                for (varargin_2 = 0; varargin_2 < nx; varargin_2++) {
                  y[varargin_2] = indices[r[varargin_2] - 1];
                }

                b_st.site = &tp_emlrtRSI;
                local_ismember(&b_st, remIdx, y, distIdx);
                acoef = distIdx.size(1);
                for (idx = 0; idx < acoef; idx++) {
                  if (distIdx[idx]) {
                    if (idx + 1 > dists.size(0)) {
                      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, dists.size(0),
                        &ri_emlrtBCI, (emlrtCTX)sp);
                    }

                    dists[idx] = rtInfF;
                  }
                }

                st.site = &sp_emlrtRSI;
                b_st.site = &vi_emlrtRSI;
                c_st.site = &wi_emlrtRSI;
                d_st.site = &xi_emlrtRSI;
                if (dists.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &yi_emlrtRSI;
                nx = dists.size(0);
                if (dists.size(0) <= 2) {
                  if (dists.size(0) == 1) {
                    idx = 1;
                  } else if ((dists[0] > dists[1]) || (muSingleScalarIsNaN
                              (dists[0]) && (!muSingleScalarIsNaN(dists[1])))) {
                    idx = 2;
                  } else {
                    idx = 1;
                  }
                } else {
                  f_st.site = &le_emlrtRSI;
                  if (!muSingleScalarIsNaN(dists[0])) {
                    idx = 1;
                  } else {
                    idx = 0;
                    g_st.site = &ne_emlrtRSI;
                    if (dists.size(0) > 2147483646) {
                      h_st.site = &yc_emlrtRSI;
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
                    f_st.site = &me_emlrtRSI;
                    ex = dists[idx - 1];
                    acoef = idx + 1;
                    g_st.site = &oe_emlrtRSI;
                    if ((idx + 1 <= dists.size(0)) && (dists.size(0) >
                         2147483646)) {
                      h_st.site = &yc_emlrtRSI;
                      check_forloop_overflow_error(&h_st);
                    }

                    for (k = acoef; k <= nx; k++) {
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
                    &si_emlrtBCI, (emlrtCTX)sp);
                }

                if (b_i + 1 > validPredictions.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1,
                    validPredictions.size(0), &ui_emlrtBCI, (emlrtCTX)sp);
                }

                varargin_2 = static_cast<int32_T>(validPredictions[b_i]);
                if (varargin_2 > indices.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(varargin_2, 1, indices.size(1),
                    &ti_emlrtBCI, (emlrtCTX)sp);
                }

                indices[varargin_2 - 1] = remIdx[idx - 1];
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::findClosestOnCurve(const emlrtStack *sp, const
            real_T predictedPoint[2], real_T radius, const ::coder::array<real_T,
            2U> &curve, const real_T coordsToUse[2], const ::coder::array<real_T,
            2U> &removedIdx, ::coder::array<real_T, 2U> &idx) const
          {
            array<real_T, 2U> dataPts;
            array<real_T, 2U> firstCoord;
            array<real_T, 2U> r1;
            array<real_T, 2U> remIdx;
            array<real_T, 1U> b_this;
            array<real_T, 1U> c_idx;
            array<real_T, 1U> dist;
            array<real_T, 1U> varargin_2;
            array<int32_T, 1U> ib;
            array<int32_T, 1U> ii;
            array<int32_T, 1U> r;
            array<real32_T, 2U> b_dataPts;
            array<real32_T, 2U> b_queryPts;
            array<real32_T, 2U> currPt;
            array<real32_T, 2U> diffs;
            array<real32_T, 2U> queryPts;
            array<real32_T, 1U> b_diffs;
            array<real32_T, 1U> c_diffs;
            array<real32_T, 1U> dists;
            array<boolean_T, 1U> s;
            emlrtStack b_st;
            emlrtStack c_st;
            emlrtStack d_st;
            emlrtStack e_st;
            emlrtStack f_st;
            emlrtStack g_st;
            emlrtStack h_st;
            emlrtStack i_st;
            emlrtStack st;
            real_T b_dv[2];
            int32_T b_iv[2];
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
              firstCoord.set_size(&dk_emlrtRTEI, sp, 1, 0);
            } else {
              firstCoord.set_size(&dk_emlrtRTEI, sp, 1, last);
              loop_ub = last - 1;
              for (i = 0; i <= loop_ub; i++) {
                firstCoord[i] = static_cast<real_T>(i) + 1.0;
              }
            }

            st.site = &jn_emlrtRSI;
            b_st.site = &wn_emlrtRSI;
            last = BoardIdx.size(0) * BoardIdx.size(1);
            b_this = BoardIdx.reshape(last);
            c_st.site = &xn_emlrtRSI;
            do_vectors(&c_st, firstCoord, b_this, remIdx, ii, ib);
            st.site = &kn_emlrtRSI;
            b_st.site = &wn_emlrtRSI;
            firstCoord.set_size(&ek_emlrtRTEI, &b_st, 1, remIdx.size(1));
            loop_ub = remIdx.size(0) * remIdx.size(1) - 1;
            for (i = 0; i <= loop_ub; i++) {
              firstCoord[i] = remIdx[i];
            }

            c_st.site = &xn_emlrtRSI;
            do_vectors(&c_st, firstCoord, removedIdx, remIdx, ii, ib);
            last = Points.size(0);
            loop_ub = Points.size(1);
            queryPts.set_size(&fk_emlrtRTEI, sp, remIdx.size(1), loop_ub);
            for (i = 0; i < loop_ub; i++) {
              b_loop_ub = remIdx.size(1);
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                if (remIdx[i1] != static_cast<int32_T>(muDoubleScalarFloor
                     (remIdx[i1]))) {
                  emlrtIntegerCheckR2012b(remIdx[i1], &nb_emlrtDCI, (emlrtCTX)sp);
                }

                b_idx = static_cast<int32_T>(remIdx[i1]);
                if ((b_idx < 1) || (b_idx > last)) {
                  emlrtDynamicBoundsCheckR2012b(b_idx, 1, last, &ci_emlrtBCI,
                    (emlrtCTX)sp);
                }

                queryPts[i1 + queryPts.size(0) * i] = Points[(b_idx +
                  Points.size(0) * i) - 1];
              }
            }

            st.site = &ln_emlrtRSI;
            bsxfun(&st, queryPts, predictedPoint, diffs);
            loop_ub = diffs.size(0);
            b_diffs.set_size(&gk_emlrtRTEI, sp, diffs.size(0));
            for (i = 0; i < loop_ub; i++) {
              b_diffs[i] = diffs[i];
            }

            loop_ub = diffs.size(0);
            c_diffs.set_size(&hk_emlrtRTEI, sp, diffs.size(0));
            for (i = 0; i < loop_ub; i++) {
              c_diffs[i] = diffs[i + diffs.size(0)];
            }

            st.site = &mn_emlrtRSI;
            b_hypot(&st, b_diffs, c_diffs, dists);
            st.site = &nn_emlrtRSI;
            b_st.site = &vl_emlrtRSI;
            s.set_size(&ik_emlrtRTEI, &b_st, dists.size(0));
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
              st.site = &on_emlrtRSI;
              i = static_cast<int32_T>(muDoubleScalarFloor(coordsToUse[0]));
              if (coordsToUse[0] != i) {
                emlrtIntegerCheckR2012b(coordsToUse[0], &ob_emlrtDCI, &st);
              }

              if ((coordsToUse[0] < 1.0) || (coordsToUse[0] > 2.0)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[0]),
                  1, 2, &di_emlrtBCI, &st);
              }

              last = static_cast<int32_T>(coordsToUse[0]);
              a_tmp = predictedPoint[last - 1];
              a = a_tmp - radius;
              if (last != i) {
                emlrtIntegerCheckR2012b(coordsToUse[0], &pb_emlrtDCI, &st);
              }

              if ((coordsToUse[0] < 1.0) || (coordsToUse[0] > 2.0)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[0]),
                  1, 2, &ei_emlrtBCI, &st);
              }

              a_tmp += radius;
              if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(a_tmp)) {
                firstCoord.set_size(&mk_emlrtRTEI, &st, 1, 1);
                firstCoord[0] = rtNaN;
              } else if (a_tmp < a) {
                firstCoord.set_size(&mk_emlrtRTEI, &st, 1, 0);
              } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(a_tmp)) &&
                         (a == a_tmp)) {
                firstCoord.set_size(&mk_emlrtRTEI, &st, 1, 1);
                firstCoord[0] = rtNaN;
              } else if (muDoubleScalarFloor(a) == a) {
                loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_tmp - a));
                firstCoord.set_size(&mk_emlrtRTEI, &st, 1, loop_ub + 1);
                for (i = 0; i <= loop_ub; i++) {
                  firstCoord[i] = a + static_cast<real_T>(i);
                }
              } else {
                b_st.site = &qo_emlrtRSI;
                eml_float_colon(&b_st, a, a_tmp, firstCoord);
              }

              b_dv[0] = 1.0;
              b_dv[1] = 2.0;
              if (isequal(coordsToUse, b_dv)) {
                st.site = &pn_emlrtRSI;
                c_idx.set_size(&qk_emlrtRTEI, &st, firstCoord.size(1));
                loop_ub = firstCoord.size(1);
                for (i = 0; i < loop_ub; i++) {
                  c_idx[i] = firstCoord[i];
                }

                b_st.site = &pn_emlrtRSI;
                polyval(&b_st, curve, firstCoord, r1);
                varargin_2.set_size(&rk_emlrtRTEI, &st, r1.size(1));
                loop_ub = r1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  varargin_2[i] = r1[i];
                }

                b_st.site = &to_emlrtRSI;
                c_st.site = &uo_emlrtRSI;
                if (varargin_2.size(0) != c_idx.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                    "MATLAB:catenate:matrixDimensionMismatch",
                    "MATLAB:catenate:matrixDimensionMismatch", 0);
                }

                dataPts.set_size(&sk_emlrtRTEI, &b_st, c_idx.size(0), 2);
                loop_ub = c_idx.size(0);
                for (i = 0; i < loop_ub; i++) {
                  dataPts[i] = c_idx[i];
                }

                loop_ub = varargin_2.size(0);
                for (i = 0; i < loop_ub; i++) {
                  dataPts[i + dataPts.size(0)] = varargin_2[i];
                }
              } else {
                st.site = &qn_emlrtRSI;
                b_st.site = &qn_emlrtRSI;
                polyval(&b_st, curve, firstCoord, r1);
                c_idx.set_size(&nk_emlrtRTEI, &st, r1.size(1));
                loop_ub = r1.size(1);
                for (i = 0; i < loop_ub; i++) {
                  c_idx[i] = r1[i];
                }

                varargin_2.set_size(&ok_emlrtRTEI, &st, firstCoord.size(1));
                loop_ub = firstCoord.size(1);
                for (i = 0; i < loop_ub; i++) {
                  varargin_2[i] = firstCoord[i];
                }

                b_st.site = &to_emlrtRSI;
                c_st.site = &uo_emlrtRSI;
                if (varargin_2.size(0) != c_idx.size(0)) {
                  emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                    "MATLAB:catenate:matrixDimensionMismatch",
                    "MATLAB:catenate:matrixDimensionMismatch", 0);
                }

                dataPts.set_size(&pk_emlrtRTEI, &b_st, c_idx.size(0), 2);
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

              r.set_size(&kk_emlrtRTEI, sp, last);
              last = 0;
              for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                if (dists[b_i] < radius) {
                  r[last] = b_i + 1;
                  last++;
                }
              }

              last = Points.size(0);
              loop_ub = Points.size(1);
              queryPts.set_size(&tk_emlrtRTEI, sp, r.size(0), loop_ub);
              for (i = 0; i < loop_ub; i++) {
                b_loop_ub = r.size(0);
                for (i1 = 0; i1 < b_loop_ub; i1++) {
                  if (r[i1] > remIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i1], 1, remIdx.size(1),
                      &hi_emlrtBCI, (emlrtCTX)sp);
                  }

                  a_tmp = remIdx[r[i1] - 1];
                  if (a_tmp != static_cast<int32_T>(muDoubleScalarFloor(a_tmp)))
                  {
                    emlrtIntegerCheckR2012b(a_tmp, &qb_emlrtDCI, (emlrtCTX)sp);
                  }

                  if ((static_cast<int32_T>(a_tmp) < 1) || (static_cast<int32_T>
                       (a_tmp) > last)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a_tmp), 1,
                      last, &gi_emlrtBCI, (emlrtCTX)sp);
                  }

                  queryPts[i1 + queryPts.size(0) * i] = Points
                    [(static_cast<int32_T>(a_tmp) + Points.size(0) * i) - 1];
                }
              }

              dist.set_size(&uk_emlrtRTEI, sp, queryPts.size(0));
              i = queryPts.size(0);
              for (b_i = 0; b_i < i; b_i++) {
                real32_T ex;
                if (b_i + 1 > queryPts.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, queryPts.size(0),
                    &bi_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = queryPts.size(1);
                b_queryPts.set_size(&vk_emlrtRTEI, sp, 1, queryPts.size(1));
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_queryPts[i1] = queryPts[b_i + queryPts.size(0) * i1];
                }

                st.site = &rn_emlrtRSI;
                repmat(&st, b_queryPts, static_cast<real_T>(dataPts.size(0)),
                       currPt);
                b_iv[0] = (*(int32_T (*)[2])dataPts.size())[0];
                b_iv[1] = (*(int32_T (*)[2])dataPts.size())[1];
                iv1[0] = (*(int32_T (*)[2])currPt.size())[0];
                iv1[1] = (*(int32_T (*)[2])currPt.size())[1];
                emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &pb_emlrtECI,
                  (emlrtCTX)sp);
                st.site = &sn_emlrtRSI;
                b_dataPts.set_size(&wk_emlrtRTEI, &st, dataPts.size(0), 2);
                loop_ub = dataPts.size(0) * 2;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_dataPts[i1] = static_cast<real32_T>(dataPts[i1]) - currPt[i1];
                }

                b_st.site = &sn_emlrtRSI;
                b_power(&b_st, b_dataPts, diffs);
                b_st.site = &sn_emlrtRSI;
                sum(&b_st, diffs, b_diffs);
                b_st.site = &dp_emlrtRSI;
                c_st.site = &ep_emlrtRSI;
                d_st.site = &fp_emlrtRSI;
                if (b_diffs.size(0) < 1) {
                  emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                    "Coder:toolbox:eml_min_or_max_varDimZero",
                    "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                }

                e_st.site = &gp_emlrtRSI;
                f_st.site = &hp_emlrtRSI;
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
                  g_st.site = &le_emlrtRSI;
                  if (!muSingleScalarIsNaN(b_diffs[0])) {
                    b_idx = 1;
                  } else {
                    b_idx = 0;
                    h_st.site = &ne_emlrtRSI;
                    if (b_diffs.size(0) > 2147483646) {
                      i_st.site = &yc_emlrtRSI;
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
                    g_st.site = &me_emlrtRSI;
                    ex = b_diffs[b_idx - 1];
                    b_loop_ub = b_idx + 1;
                    h_st.site = &oe_emlrtRSI;
                    if ((b_idx + 1 <= b_diffs.size(0)) && (b_diffs.size(0) >
                         2147483646)) {
                      i_st.site = &yc_emlrtRSI;
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

                st.site = &sn_emlrtRSI;
                if (ex < 0.0F) {
                  emlrtErrorWithMessageIdR2018a(&st, &x_emlrtRTEI,
                    "Coder:toolbox:ElFunDomainError",
                    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
                }

                ex = muSingleScalarSqrt(ex);
                if (b_i + 1 > dist.size(0)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, dist.size(0),
                    &ji_emlrtBCI, (emlrtCTX)sp);
                }

                dist[b_i] = ex;
              }

              st.site = &tn_emlrtRSI;
              b_st.site = &vi_emlrtRSI;
              c_st.site = &wi_emlrtRSI;
              d_st.site = &xi_emlrtRSI;
              if (dist.size(0) < 1) {
                emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                  "Coder:toolbox:eml_min_or_max_varDimZero",
                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
              }

              e_st.site = &yi_emlrtRSI;
              last = dist.size(0);
              if (dist.size(0) <= 2) {
                if (dist.size(0) == 1) {
                  b_idx = 1;
                } else if ((dist[0] > dist[1]) || (muDoubleScalarIsNaN(dist[0]) &&
                            (!muDoubleScalarIsNaN(dist[1])))) {
                  b_idx = 2;
                } else {
                  b_idx = 1;
                }
              } else {
                f_st.site = &le_emlrtRSI;
                if (!muDoubleScalarIsNaN(dist[0])) {
                  b_idx = 1;
                } else {
                  b_idx = 0;
                  g_st.site = &ne_emlrtRSI;
                  if (dist.size(0) > 2147483646) {
                    h_st.site = &yc_emlrtRSI;
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
                  f_st.site = &me_emlrtRSI;
                  a = dist[b_idx - 1];
                  b_loop_ub = b_idx + 1;
                  g_st.site = &oe_emlrtRSI;
                  if ((b_idx + 1 <= dist.size(0)) && (dist.size(0) > 2147483646))
                  {
                    h_st.site = &yc_emlrtRSI;
                    check_forloop_overflow_error(&h_st);
                  }

                  for (loop_ub = b_loop_ub; loop_ub <= last; loop_ub++) {
                    a_tmp = dist[loop_ub - 1];
                    if (a > a_tmp) {
                      a = a_tmp;
                      b_idx = loop_ub;
                    }
                  }
                }
              }

              st.site = &un_emlrtRSI;
              s.set_size(&ik_emlrtRTEI, &st, dists.size(0));
              loop_ub = dists.size(0);
              for (i = 0; i < loop_ub; i++) {
                s[i] = (dists[i] < radius);
              }

              b_st.site = &jf_emlrtRSI;
              c_eml_find(&b_st, s, static_cast<real_T>(b_idx), ii);
              c_idx.set_size(&xk_emlrtRTEI, &st, ii.size(0));
              loop_ub = ii.size(0);
              for (i = 0; i < loop_ub; i++) {
                c_idx[i] = ii[i];
              }

              idx.set_size(&yk_emlrtRTEI, sp, 1, 1);
              if (c_idx.size(0) < 1) {
                emlrtDynamicBoundsCheckR2012b(c_idx.size(0), 1, c_idx.size(0),
                  &ii_emlrtBCI, (emlrtCTX)sp);
              }

              i = static_cast<int32_T>(c_idx[c_idx.size(0) - 1]);
              if ((i < 1) || (i > remIdx.size(1))) {
                emlrtDynamicBoundsCheckR2012b(i, 1, remIdx.size(1), &ii_emlrtBCI,
                  (emlrtCTX)sp);
              }

              idx[0] = remIdx[i - 1];
            } else {
              st.site = &vn_emlrtRSI;
              b_st.site = &vl_emlrtRSI;
              s.set_size(&ik_emlrtRTEI, &b_st, dists.size(0));
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

                r.set_size(&kk_emlrtRTEI, sp, last);
                last = 0;
                for (b_i = 0; b_i <= b_loop_ub; b_i++) {
                  if (dists[b_i] < radius) {
                    r[last] = b_i + 1;
                    last++;
                  }
                }

                idx.set_size(&lk_emlrtRTEI, sp, 1, r.size(0));
                loop_ub = r.size(0);
                for (i = 0; i < loop_ub; i++) {
                  if (r[i] > remIdx.size(1)) {
                    emlrtDynamicBoundsCheckR2012b(r[i], 1, remIdx.size(1),
                      &fi_emlrtBCI, (emlrtCTX)sp);
                  }

                  idx[i] = remIdx[r[i] - 1];
                }
              } else {
                idx.set_size(&jk_emlrtRTEI, sp, 1, 0);
              }
            }

            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          real_T Checkerboard::findNeighbor(const emlrtStack *sp, const ::coder::
            array<real32_T, 2U> &pointVectors, const ::coder::array<real32_T, 1U>
            &euclideanDists, const real32_T v[2]) const
          {
            ptrdiff_t k_t;
            ptrdiff_t lda_t;
            ptrdiff_t ldb_t;
            ptrdiff_t ldc_t;
            ptrdiff_t m_t;
            ptrdiff_t n_t;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r2;
            array<real32_T, 1U> angleCosines;
            array<real32_T, 1U> dists;
            array<boolean_T, 2U> r;
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
            st.site = &ni_emlrtRSI;
            b_st.site = &qi_emlrtRSI;
            if (pointVectors.size(1) != 2) {
              if ((pointVectors.size(0) == 1) && (pointVectors.size(1) == 1)) {
                emlrtErrorWithMessageIdR2018a(&b_st, &bb_emlrtRTEI,
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
              } else {
                emlrtErrorWithMessageIdR2018a(&b_st, &cb_emlrtRTEI,
                  "MATLAB:innerdim", "MATLAB:innerdim", 0);
              }
            }

            b_st.site = &pi_emlrtRSI;
            if (pointVectors.size(0) == 0) {
              angleCosines.set_size(&nh_emlrtRTEI, &b_st, pointVectors.size(0));
              last = pointVectors.size(0);
              for (i = 0; i < last; i++) {
                angleCosines[i] = 0.0F;
              }
            } else {
              c_st.site = &ri_emlrtRSI;
              d_st.site = &si_emlrtRSI;
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
              angleCosines.set_size(&mh_emlrtRTEI, &d_st, pointVectors.size(0));
              sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((::coder::
                       array<real32_T, 2U> *)&pointVectors)->data())[0], &lda_t,
                    (real32_T *)&v[0], &ldb_t, &beta1, &(angleCosines.data())[0],
                    &ldc_t);
            }

            alpha1 = muSingleScalarHypot(v[0], v[1]);
            dists.set_size(&oh_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = euclideanDists[i] * alpha1;
            }

            st.site = &ni_emlrtRSI;
            b_st.site = &ti_emlrtRSI;
            c_st.site = &ui_emlrtRSI;
            if (angleCosines.size(0) != dists.size(0)) {
              emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                "MATLAB:dimagree", "MATLAB:dimagree", 0);
            }

            last = angleCosines.size(0);
            for (i = 0; i < last; i++) {
              angleCosines[i] = angleCosines[i] / dists[i];
            }

            dists.set_size(&ph_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = 1.5F * euclideanDists[i];
            }

            if (dists.size(0) != angleCosines.size(0)) {
              emlrtSizeEqCheck1DR2012b(dists.size(0), angleCosines.size(0),
                &db_emlrtECI, (emlrtCTX)sp);
            }

            last = dists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = dists[i] * (1.0F - angleCosines[i]);
            }

            if (euclideanDists.size(0) != dists.size(0)) {
              emlrtSizeEqCheck1DR2012b(euclideanDists.size(0), dists.size(0),
                &eb_emlrtECI, (emlrtCTX)sp);
            }

            dists.set_size(&qh_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = euclideanDists[i] + dists[i];
            }

            r.set_size(&rh_emlrtRTEI, sp, BoardIdx.size(0), BoardIdx.size(1));
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

            r1.set_size(&sh_emlrtRTEI, sp, last);
            last = 0;
            for (i = 0; i <= end; i++) {
              if (r[i]) {
                r1[last] = i + 1;
                last++;
              }
            }

            end = BoardIdx.size(0) * BoardIdx.size(1);
            r2.set_size(&th_emlrtRTEI, sp, r1.size(0));
            last = r1.size(0);
            for (i = 0; i < last; i++) {
              real_T d;
              if ((r1[i] < 1) || (r1[i] > end)) {
                emlrtDynamicBoundsCheckR2012b(r1[i], 1, end, &ke_emlrtBCI,
                  (emlrtCTX)sp);
              }

              d = BoardIdx[r1[i] - 1];
              if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                emlrtIntegerCheckR2012b(d, &x_emlrtDCI, (emlrtCTX)sp);
              }

              if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                   dists.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                  dists.size(0), &le_emlrtBCI, (emlrtCTX)sp);
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
                    &me_emlrtBCI, (emlrtCTX)sp);
                }

                dists[i] = rtInfF;
              }
            }

            st.site = &oi_emlrtRSI;
            b_st.site = &vi_emlrtRSI;
            c_st.site = &wi_emlrtRSI;
            d_st.site = &xi_emlrtRSI;
            if (dists.size(0) < 1) {
              emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                "Coder:toolbox:eml_min_or_max_varDimZero",
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
            }

            e_st.site = &yi_emlrtRSI;
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
              f_st.site = &le_emlrtRSI;
              if (!muSingleScalarIsNaN(dists[0])) {
                end = 1;
              } else {
                boolean_T exitg1;
                end = 0;
                g_st.site = &ne_emlrtRSI;
                if (dists.size(0) > 2147483646) {
                  h_st.site = &yc_emlrtRSI;
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
                f_st.site = &me_emlrtRSI;
                alpha1 = dists[end - 1];
                i = end + 1;
                g_st.site = &oe_emlrtRSI;
                if ((end + 1 <= dists.size(0)) && (dists.size(0) > 2147483646))
                {
                  h_st.site = &yc_emlrtRSI;
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

          real_T Checkerboard::findNeighbor(const emlrtStack *sp, const ::coder::
            array<real32_T, 2U> &pointVectors, const ::coder::array<real32_T, 1U>
            &euclideanDists, const ::coder::array<real32_T, 2U> &v) const
          {
            ptrdiff_t k_t;
            ptrdiff_t lda_t;
            ptrdiff_t ldb_t;
            ptrdiff_t ldc_t;
            ptrdiff_t m_t;
            ptrdiff_t n_t;
            array<int32_T, 1U> r1;
            array<int32_T, 1U> r2;
            array<real32_T, 1U> angleCosines;
            array<real32_T, 1U> dists;
            array<boolean_T, 2U> r;
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
            st.site = &ni_emlrtRSI;
            b_st.site = &qi_emlrtRSI;
            if (pointVectors.size(1) != v.size(1)) {
              if (((pointVectors.size(0) == 1) && (pointVectors.size(1) == 1)) ||
                  (v.size(1) == 1)) {
                emlrtErrorWithMessageIdR2018a(&b_st, &bb_emlrtRTEI,
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion",
                  "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
              } else {
                emlrtErrorWithMessageIdR2018a(&b_st, &cb_emlrtRTEI,
                  "MATLAB:innerdim", "MATLAB:innerdim", 0);
              }
            }

            b_st.site = &pi_emlrtRSI;
            if ((pointVectors.size(0) == 0) || (pointVectors.size(1) == 0) ||
                (v.size(1) == 0)) {
              angleCosines.set_size(&nh_emlrtRTEI, &b_st, pointVectors.size(0));
              last = pointVectors.size(0);
              for (i = 0; i < last; i++) {
                angleCosines[i] = 0.0F;
              }
            } else {
              c_st.site = &ri_emlrtRSI;
              d_st.site = &si_emlrtRSI;
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
              angleCosines.set_size(&mh_emlrtRTEI, &d_st, pointVectors.size(0));
              sgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &(((::coder::
                       array<real32_T, 2U> *)&pointVectors)->data())[0], &lda_t,
                    (real32_T *)&v[0], &ldb_t, &beta1, &(angleCosines.data())[0],
                    &ldc_t);
            }

            if (1 > v.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, v.size(1), &ne_emlrtBCI,
                (emlrtCTX)sp);
            }

            if (2 > v.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, v.size(1), &oe_emlrtBCI,
                (emlrtCTX)sp);
            }

            alpha1 = muSingleScalarHypot(v[0], v[1]);
            dists.set_size(&oh_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = euclideanDists[i] * alpha1;
            }

            st.site = &ni_emlrtRSI;
            b_st.site = &ti_emlrtRSI;
            c_st.site = &ui_emlrtRSI;
            if (angleCosines.size(0) != dists.size(0)) {
              emlrtErrorWithMessageIdR2018a(&c_st, &db_emlrtRTEI,
                "MATLAB:dimagree", "MATLAB:dimagree", 0);
            }

            last = angleCosines.size(0);
            for (i = 0; i < last; i++) {
              angleCosines[i] = angleCosines[i] / dists[i];
            }

            dists.set_size(&ph_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = 1.5F * euclideanDists[i];
            }

            if (dists.size(0) != angleCosines.size(0)) {
              emlrtSizeEqCheck1DR2012b(dists.size(0), angleCosines.size(0),
                &db_emlrtECI, (emlrtCTX)sp);
            }

            last = dists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = dists[i] * (1.0F - angleCosines[i]);
            }

            if (euclideanDists.size(0) != dists.size(0)) {
              emlrtSizeEqCheck1DR2012b(euclideanDists.size(0), dists.size(0),
                &eb_emlrtECI, (emlrtCTX)sp);
            }

            dists.set_size(&qh_emlrtRTEI, sp, euclideanDists.size(0));
            last = euclideanDists.size(0);
            for (i = 0; i < last; i++) {
              dists[i] = euclideanDists[i] + dists[i];
            }

            r.set_size(&rh_emlrtRTEI, sp, BoardIdx.size(0), BoardIdx.size(1));
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

            r1.set_size(&sh_emlrtRTEI, sp, last);
            last = 0;
            for (i = 0; i <= end; i++) {
              if (r[i]) {
                r1[last] = i + 1;
                last++;
              }
            }

            end = BoardIdx.size(0) * BoardIdx.size(1);
            r2.set_size(&th_emlrtRTEI, sp, r1.size(0));
            last = r1.size(0);
            for (i = 0; i < last; i++) {
              real_T d;
              if ((r1[i] < 1) || (r1[i] > end)) {
                emlrtDynamicBoundsCheckR2012b(r1[i], 1, end, &ke_emlrtBCI,
                  (emlrtCTX)sp);
              }

              d = BoardIdx[r1[i] - 1];
              if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
                emlrtIntegerCheckR2012b(d, &x_emlrtDCI, (emlrtCTX)sp);
              }

              if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) >
                   dists.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                  dists.size(0), &le_emlrtBCI, (emlrtCTX)sp);
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
                    &me_emlrtBCI, (emlrtCTX)sp);
                }

                dists[i] = rtInfF;
              }
            }

            st.site = &oi_emlrtRSI;
            b_st.site = &vi_emlrtRSI;
            c_st.site = &wi_emlrtRSI;
            d_st.site = &xi_emlrtRSI;
            if (dists.size(0) < 1) {
              emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                "Coder:toolbox:eml_min_or_max_varDimZero",
                "Coder:toolbox:eml_min_or_max_varDimZero", 0);
            }

            e_st.site = &yi_emlrtRSI;
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
              f_st.site = &le_emlrtRSI;
              if (!muSingleScalarIsNaN(dists[0])) {
                end = 1;
              } else {
                boolean_T exitg1;
                end = 0;
                g_st.site = &ne_emlrtRSI;
                if (dists.size(0) > 2147483646) {
                  h_st.site = &yc_emlrtRSI;
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
                f_st.site = &me_emlrtRSI;
                alpha1 = dists[end - 1];
                i = end + 1;
                g_st.site = &oe_emlrtRSI;
                if ((end + 1 <= dists.size(0)) && (dists.size(0) > 2147483646))
                {
                  h_st.site = &yc_emlrtRSI;
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

          void Checkerboard::fitPolyCurve(const emlrtStack *sp, const ::coder::
            array<real_T, 1U> &validIdx, real_T currIdx, const real_T
            coordsToUse[2], ::coder::array<real_T, 2U> &curveCoeff) const
          {
            array<real_T, 1U> c_this;
            array<real_T, 1U> d_this;
            emlrtStack st;
            int32_T b_this;
            int32_T i;
            int32_T i1;
            int32_T k;
            int32_T loop_ub;
            int32_T n;
            st.prev = sp;
            st.tls = sp->tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            n = 0;
            i = validIdx.size(0);
            for (k = 0; k < i; k++) {
              if (validIdx[k] != 0.0) {
                n++;
              }
            }

            k = BoardCoords.size(0);
            if (currIdx != static_cast<int32_T>(muDoubleScalarFloor(currIdx))) {
              emlrtIntegerCheckR2012b(currIdx, &ib_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(1);
            if ((static_cast<int32_T>(currIdx) < 1) || (static_cast<int32_T>
                 (currIdx) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(currIdx), 1, i,
                &uh_emlrtBCI, (emlrtCTX)sp);
            }

            if (coordsToUse[0] != static_cast<int32_T>(muDoubleScalarFloor
                 (coordsToUse[0]))) {
              emlrtIntegerCheckR2012b(coordsToUse[0], &jb_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(2);
            if ((static_cast<int32_T>(coordsToUse[0]) < 1) ||
                (static_cast<int32_T>(coordsToUse[0]) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[0]),
                1, i, &vh_emlrtBCI, (emlrtCTX)sp);
            }

            b_this = BoardCoords.size(0);
            i = BoardCoords.size(1);
            if ((static_cast<int32_T>(currIdx) < 1) || (static_cast<int32_T>
                 (currIdx) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(currIdx), 1, i,
                &wh_emlrtBCI, (emlrtCTX)sp);
            }

            if (coordsToUse[1] != static_cast<int32_T>(muDoubleScalarFloor
                 (coordsToUse[1]))) {
              emlrtIntegerCheckR2012b(coordsToUse[1], &kb_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(2);
            if ((static_cast<int32_T>(coordsToUse[1]) < 1) ||
                (static_cast<int32_T>(coordsToUse[1]) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[1]),
                1, i, &xh_emlrtBCI, (emlrtCTX)sp);
            }

            c_this.set_size(&vj_emlrtRTEI, sp, validIdx.size(0));
            loop_ub = validIdx.size(0);
            for (i = 0; i < loop_ub; i++) {
              if (validIdx[i] != static_cast<int32_T>(muDoubleScalarFloor
                   (validIdx[i]))) {
                emlrtIntegerCheckR2012b(validIdx[i], &lb_emlrtDCI, (emlrtCTX)sp);
              }

              i1 = static_cast<int32_T>(validIdx[i]);
              if ((i1 < 1) || (i1 > k)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, k, &yh_emlrtBCI, (emlrtCTX)
                  sp);
              }

              c_this[i] = BoardCoords[((i1 + BoardCoords.size(0) * (static_cast<
                int32_T>(currIdx) - 1)) + BoardCoords.size(0) * BoardCoords.size
                (1) * (static_cast<int32_T>(coordsToUse[0]) - 1)) - 1];
            }

            d_this.set_size(&wj_emlrtRTEI, sp, validIdx.size(0));
            loop_ub = validIdx.size(0);
            for (i = 0; i < loop_ub; i++) {
              i1 = static_cast<int32_T>(validIdx[i]);
              if ((i1 < 1) || (i1 > b_this)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx[i]),
                  1, b_this, &ai_emlrtBCI, (emlrtCTX)sp);
              }

              d_this[i] = BoardCoords[((i1 + BoardCoords.size(0) *
                (static_cast<int32_T>(currIdx) - 1)) + BoardCoords.size(0) *
                BoardCoords.size(1) * (static_cast<int32_T>(coordsToUse[1]) - 1))
                - 1];
            }

            if (n > 5) {
              n = 4;
            } else {
              n = 2;
            }

            st.site = &xl_emlrtRSI;
            polyfit(&st, c_this, d_this, static_cast<real_T>(n), curveCoeff);
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::fitPolyCurve(const emlrtStack *sp, const ::coder::
            array<real_T, 2U> &validIdx, real_T currIdx, const real_T
            coordsToUse[2], ::coder::array<real_T, 2U> &curveCoeff) const
          {
            array<real_T, 2U> c_this;
            array<real_T, 2U> d_this;
            emlrtStack st;
            int32_T b_this;
            int32_T i;
            int32_T i1;
            int32_T k;
            int32_T loop_ub;
            int32_T n;
            st.prev = sp;
            st.tls = sp->tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            n = 0;
            i = validIdx.size(1);
            for (k = 0; k < i; k++) {
              if (validIdx[k] != 0.0) {
                n++;
              }
            }

            k = BoardCoords.size(1);
            if (currIdx != static_cast<int32_T>(muDoubleScalarFloor(currIdx))) {
              emlrtIntegerCheckR2012b(currIdx, &ud_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(0);
            if ((static_cast<int32_T>(currIdx) < 1) || (static_cast<int32_T>
                 (currIdx) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(currIdx), 1, i,
                &wm_emlrtBCI, (emlrtCTX)sp);
            }

            if (coordsToUse[0] != static_cast<int32_T>(muDoubleScalarFloor
                 (coordsToUse[0]))) {
              emlrtIntegerCheckR2012b(coordsToUse[0], &vd_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(2);
            if ((static_cast<int32_T>(coordsToUse[0]) < 1) ||
                (static_cast<int32_T>(coordsToUse[0]) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[0]),
                1, i, &xm_emlrtBCI, (emlrtCTX)sp);
            }

            b_this = BoardCoords.size(1);
            i = BoardCoords.size(0);
            if ((static_cast<int32_T>(currIdx) < 1) || (static_cast<int32_T>
                 (currIdx) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(currIdx), 1, i,
                &ym_emlrtBCI, (emlrtCTX)sp);
            }

            if (coordsToUse[1] != static_cast<int32_T>(muDoubleScalarFloor
                 (coordsToUse[1]))) {
              emlrtIntegerCheckR2012b(coordsToUse[1], &wd_emlrtDCI, (emlrtCTX)sp);
            }

            i = BoardCoords.size(2);
            if ((static_cast<int32_T>(coordsToUse[1]) < 1) ||
                (static_cast<int32_T>(coordsToUse[1]) > i)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(coordsToUse[1]),
                1, i, &an_emlrtBCI, (emlrtCTX)sp);
            }

            c_this.set_size(&eo_emlrtRTEI, sp, 1, validIdx.size(1));
            loop_ub = validIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (validIdx[i] != static_cast<int32_T>(muDoubleScalarFloor
                   (validIdx[i]))) {
                emlrtIntegerCheckR2012b(validIdx[i], &xd_emlrtDCI, (emlrtCTX)sp);
              }

              i1 = static_cast<int32_T>(validIdx[i]);
              if ((i1 < 1) || (i1 > k)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, k, &bn_emlrtBCI, (emlrtCTX)
                  sp);
              }

              c_this[i] = BoardCoords[((static_cast<int32_T>(currIdx) +
                BoardCoords.size(0) * (i1 - 1)) + BoardCoords.size(0) *
                BoardCoords.size(1) * (static_cast<int32_T>(coordsToUse[0]) - 1))
                - 1];
            }

            d_this.set_size(&fo_emlrtRTEI, sp, 1, validIdx.size(1));
            loop_ub = validIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (validIdx[i] != static_cast<int32_T>(muDoubleScalarFloor
                   (validIdx[i]))) {
                emlrtIntegerCheckR2012b(validIdx[i], &yd_emlrtDCI, (emlrtCTX)sp);
              }

              i1 = static_cast<int32_T>(validIdx[i]);
              if ((i1 < 1) || (i1 > b_this)) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, b_this, &cn_emlrtBCI,
                  (emlrtCTX)sp);
              }

              d_this[i] = BoardCoords[((static_cast<int32_T>(currIdx) +
                BoardCoords.size(0) * (i1 - 1)) + BoardCoords.size(0) *
                BoardCoords.size(1) * (static_cast<int32_T>(coordsToUse[1]) - 1))
                - 1];
            }

            if (n > 5) {
              n = 4;
            } else {
              n = 2;
            }

            st.site = &dr_emlrtRSI;
            polyfit(&st, c_this, d_this, static_cast<real_T>(n), curveCoeff);
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::fitPolynomialIndices(const emlrtStack *sp, ::coder::
            array<real_T, 2U> &newIndices) const
          {
            array<real_T, 2U> b_index;
            array<real_T, 2U> currCurve;
            array<real_T, 2U> removedIdx;
            array<real_T, 1U> validIdx;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r3;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> ii;
            array<boolean_T, 2U> r;
            array<boolean_T, 2U> r1;
            emlrtStack b_st;
            emlrtStack st;
            real_T coordsToUse[2];
            real_T currPt[2];
            real_T currRad;
            real_T x;
            real_T y;
            int32_T b_iv[2];
            int32_T iv1[2];
            int32_T b_i;
            int32_T i;
            int32_T loop_ub;
            int32_T trueCount;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            st.site = &xk_emlrtRSI;
            i = BoardIdx.size(0);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &jh_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&jj_emlrtRTEI, &st, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[BoardIdx.size(0) * i] > 0.0);
            }

            i = BoardIdx.size(0);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ih_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(1);
            r1.set_size(&kj_emlrtRTEI, &st, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[BoardIdx.size(0) * i + 1] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])r.size())[0];
            b_iv[1] = (*(int32_T (*)[2])r.size())[1];
            iv1[0] = (*(int32_T (*)[2])r1.size())[0];
            iv1[1] = (*(int32_T (*)[2])r1.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nb_emlrtECI, &st);
            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r2.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r2[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(0);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &hh_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &gh_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            removedIdx.set_size(&mj_emlrtRTEI, &st, 1, r2.size(1));
            loop_ub = r2.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r2[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &mh_emlrtBCI,
                  &st);
              }

              removedIdx[i] = BoardCoords[BoardCoords.size(0) * (r2[i] - 1) + 1];
            }

            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r3.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r3[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(0);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &fh_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &eh_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            currCurve.set_size(&nj_emlrtRTEI, &st, 1, r3.size(1));
            loop_ub = r3.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r3[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &nh_emlrtBCI,
                  &st);
              }

              currCurve[i] = BoardCoords[BoardCoords.size(0) * (r3[i] - 1)];
            }

            b_iv[0] = (*(int32_T (*)[2])removedIdx.size())[0];
            b_iv[1] = (*(int32_T (*)[2])removedIdx.size())[1];
            iv1[0] = (*(int32_T (*)[2])currCurve.size())[0];
            iv1[1] = (*(int32_T (*)[2])currCurve.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mb_emlrtECI, &st);
            b_index.set_size(&mj_emlrtRTEI, &st, 1, removedIdx.size(1));
            loop_ub = removedIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_index[i] = removedIdx[i] - currCurve[i];
            }

            b_st.site = &gl_emlrtRSI;
            x = mean(&b_st, b_index);
            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r4.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r4[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(0);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &dh_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ch_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            removedIdx.set_size(&oj_emlrtRTEI, &st, 1, r4.size(1));
            loop_ub = r4.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r4[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &oh_emlrtBCI,
                  &st);
              }

              removedIdx[i] = BoardCoords[(BoardCoords.size(0) * (r4[i] - 1) +
                BoardCoords.size(0) * BoardCoords.size(1)) + 1];
            }

            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                trueCount++;
              }
            }

            r5.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (b_i = 0; b_i <= loop_ub; b_i++) {
              if (r[b_i] && r1[b_i]) {
                r5[trueCount] = b_i + 1;
                trueCount++;
              }
            }

            i = BoardCoords.size(0);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &bh_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ah_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            currCurve.set_size(&pj_emlrtRTEI, &st, 1, r5.size(1));
            loop_ub = r5.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r5[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r5[i], 1, trueCount, &ph_emlrtBCI,
                  &st);
              }

              currCurve[i] = BoardCoords[BoardCoords.size(0) * (r5[i] - 1) +
                BoardCoords.size(0) * BoardCoords.size(1)];
            }

            b_iv[0] = (*(int32_T (*)[2])removedIdx.size())[0];
            b_iv[1] = (*(int32_T (*)[2])removedIdx.size())[1];
            iv1[0] = (*(int32_T (*)[2])currCurve.size())[0];
            iv1[1] = (*(int32_T (*)[2])currCurve.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &lb_emlrtECI, &st);
            b_index.set_size(&oj_emlrtRTEI, &st, 1, removedIdx.size(1));
            loop_ub = removedIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_index[i] = removedIdx[i] - currCurve[i];
            }

            b_st.site = &hl_emlrtRSI;
            currRad = mean(&b_st, b_index);
            if (muDoubleScalarAbs(x) > muDoubleScalarAbs(currRad)) {
              coordsToUse[0] = 1.0;
              coordsToUse[1] = 2.0;
            } else {
              coordsToUse[0] = 2.0;
              coordsToUse[1] = 1.0;
            }

            newIndices.set_size(&qj_emlrtRTEI, sp, 1, newIndices.size(1));
            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &gb_emlrtDCI,
                (emlrtCTX)sp);
            }

            newIndices.set_size(&qj_emlrtRTEI, sp, newIndices.size(0), i);
            loop_ub = BoardCoords.size(1);
            if (loop_ub < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(loop_ub),
                &hb_emlrtDCI, (emlrtCTX)sp);
            }

            for (i = 0; i < loop_ub; i++) {
              newIndices[i] = 0.0;
            }

            removedIdx.set_size(&rj_emlrtRTEI, sp, 1, 0);
            i = BoardCoords.size(1);
            for (b_i = 0; b_i < i; b_i++) {
              int32_T i1;
              st.site = &yk_emlrtRSI;
              i1 = BoardCoords.size(1);
              if ((b_i + 1 < 1) || (b_i + 1 > i1)) {
                emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &lh_emlrtBCI, &st);
              }

              i1 = BoardCoords.size(2);
              trueCount = static_cast<int32_T>(coordsToUse[0]);
              if (trueCount > i1) {
                emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &kh_emlrtBCI,
                  &st);
              }

              loop_ub = BoardCoords.size(0);
              validIdx.set_size(&sj_emlrtRTEI, &st, loop_ub);
              for (i1 = 0; i1 < loop_ub; i1++) {
                validIdx[i1] = BoardCoords[(i1 + BoardCoords.size(0) * b_i) +
                  BoardCoords.size(0) * BoardCoords.size(1) * (trueCount - 1)];
              }

              b_st.site = &jf_emlrtRSI;
              b_eml_find(&b_st, validIdx, ii);
              validIdx.set_size(&tj_emlrtRTEI, &st, ii.size(0));
              loop_ub = ii.size(0);
              for (i1 = 0; i1 < loop_ub; i1++) {
                validIdx[i1] = ii[i1];
              }

              if (validIdx.size(0) >= 2) {
                real_T currCoord;
                real_T refCoordValue;
                boolean_T exitg1;
                st.site = &al_emlrtRSI;
                i1 = BoardCoords.size(0);
                if ((static_cast<int32_T>(validIdx[0]) < 1) ||
                    (static_cast<int32_T>(validIdx[0]) > i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx[0]),
                    1, i1, &yg_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(1);
                if ((b_i + 1 < 1) || (b_i + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &xg_emlrtBCI,
                    &st);
                }

                i1 = BoardCoords.size(2);
                if (trueCount > i1) {
                  emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &wg_emlrtBCI,
                    &st);
                }

                i1 = BoardCoords.size(0);
                if ((static_cast<int32_T>(validIdx[1]) < 1) ||
                    (static_cast<int32_T>(validIdx[1]) > i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx[1]),
                    1, i1, &vg_emlrtBCI, &st);
                }

                i1 = BoardCoords.size(1);
                if ((b_i + 1 < 1) || (b_i + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &ug_emlrtBCI,
                    &st);
                }

                i1 = BoardCoords.size(2);
                if (trueCount > i1) {
                  emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &tg_emlrtBCI,
                    &st);
                }

                x = (BoardCoords[((static_cast<int32_T>(validIdx[0]) +
                                   BoardCoords.size(0) * b_i) + BoardCoords.size
                                  (0) * BoardCoords.size(1) * (trueCount - 1)) -
                     1] - BoardCoords[((static_cast<int32_T>(validIdx[1]) +
                       BoardCoords.size(0) * b_i) + BoardCoords.size(0) *
                      BoardCoords.size(1) * (trueCount - 1)) - 1]) / (validIdx[1]
                  - validIdx[0]);
                st.site = &bl_emlrtRSI;
                fitPolyCurve(&st, validIdx, static_cast<real_T>(b_i) + 1.0,
                             coordsToUse, currCurve);
                currRad = x / 4.0;
                i1 = BoardCoords.size(0);
                if ((static_cast<int32_T>(validIdx[0]) < 1) ||
                    (static_cast<int32_T>(validIdx[0]) > i1)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx[0]),
                    1, i1, &qh_emlrtBCI, (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(1);
                if ((b_i + 1 < 1) || (b_i + 1 > i1)) {
                  emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &rh_emlrtBCI,
                    (emlrtCTX)sp);
                }

                i1 = BoardCoords.size(2);
                if (trueCount > i1) {
                  emlrtDynamicBoundsCheckR2012b(trueCount, 1, i1, &sh_emlrtBCI,
                    (emlrtCTX)sp);
                }

                refCoordValue = BoardCoords[((static_cast<int32_T>(validIdx[0])
                  + BoardCoords.size(0) * b_i) + BoardCoords.size(0) *
                  BoardCoords.size(1) * (trueCount - 1)) - 1];
                currCoord = currRad + refCoordValue;
                exitg1 = false;
                while ((!exitg1) && (muDoubleScalarAbs(currCoord - refCoordValue)
                                     < validIdx[0] * 1.5 * muDoubleScalarAbs(x)))
                {
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
                    st.site = &cl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      i1 = currCurve.size(1);
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = currCoord;
                    currPt[1] = y;
                  } else {
                    st.site = &dl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      i1 = currCurve.size(1);
                      for (trueCount = 0; trueCount <= i1 - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = y;
                    currPt[1] = currCoord;
                  }

                  st.site = &el_emlrtRSI;
                  findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                     currCurve, coordsToUse, removedIdx, b_index);
                  if (b_index.size(1) != 0) {
                    if (1 != b_index.size(1)) {
                      emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                        &ob_emlrtECI, (emlrtCTX)sp);
                    }

                    if ((b_i + 1 < 1) || (b_i + 1 > newIndices.size(1))) {
                      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, newIndices.size
                        (1), &th_emlrtBCI, (emlrtCTX)sp);
                    }

                    newIndices[b_i] = b_index[0];
                    i1 = removedIdx.size(1);
                    loop_ub = b_index.size(1);
                    removedIdx.set_size(&uj_emlrtRTEI, sp, removedIdx.size(0),
                                        removedIdx.size(1) + b_index.size(1));
                    for (trueCount = 0; trueCount < loop_ub; trueCount++) {
                      removedIdx[i1 + trueCount] = b_index[trueCount];
                    }

                    exitg1 = true;
                  } else {
                    currCoord += currRad;
                  }
                }
              }
            }

            st.site = &fl_emlrtRSI;
            emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
          }

          void Checkerboard::fitPolynomialIndices(const emlrtStack *sp, const ::
            coder::array<real_T, 2U> &idx, ::coder::array<real_T, 2U>
            &newIndices) const
          {
            array<real_T, 2U> b_index;
            array<real_T, 2U> currCurve;
            array<real_T, 2U> removedIdx;
            array<real_T, 1U> validIdx;
            array<int32_T, 2U> r2;
            array<int32_T, 2U> r3;
            array<int32_T, 2U> r4;
            array<int32_T, 2U> r5;
            array<int32_T, 1U> ii;
            array<boolean_T, 2U> r;
            array<boolean_T, 2U> r1;
            emlrtStack b_st;
            emlrtStack st;
            real_T coordsToUse[2];
            real_T currPt[2];
            real_T b_x;
            real_T x;
            real_T y;
            int32_T b_iv[2];
            int32_T iv1[2];
            int32_T b_i;
            int32_T b_idx;
            int32_T c_idx;
            int32_T i;
            int32_T i1;
            int32_T loop_ub;
            int32_T trueCount;
            st.prev = sp;
            st.tls = sp->tls;
            b_st.prev = &st;
            b_st.tls = st.tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            st.site = &xk_emlrtRSI;
            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &vk_emlrtBCI, &st);
            }

            i = BoardIdx.size(0);
            b_i = static_cast<int32_T>(muDoubleScalarFloor(idx[0]));
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &qc_emlrtDCI, &st);
            }

            b_idx = static_cast<int32_T>(idx[0]);
            if ((b_idx < 1) || (b_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &jh_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(1);
            r.set_size(&jj_emlrtRTEI, &st, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r[i] = (BoardIdx[(b_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &uk_emlrtBCI, &st);
            }

            i = BoardIdx.size(0);
            i1 = static_cast<int32_T>(muDoubleScalarFloor(idx[1]));
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &pc_emlrtDCI, &st);
            }

            c_idx = static_cast<int32_T>(idx[1]);
            if ((c_idx < 1) || (c_idx > i)) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &ih_emlrtBCI, &st);
            }

            loop_ub = BoardIdx.size(1);
            r1.set_size(&kj_emlrtRTEI, &st, 1, loop_ub);
            for (i = 0; i < loop_ub; i++) {
              r1[i] = (BoardIdx[(c_idx + BoardIdx.size(0) * i) - 1] > 0.0);
            }

            b_iv[0] = (*(int32_T (*)[2])r.size())[0];
            b_iv[1] = (*(int32_T (*)[2])r.size())[1];
            iv1[0] = (*(int32_T (*)[2])r1.size())[0];
            iv1[1] = (*(int32_T (*)[2])r1.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &nb_emlrtECI, &st);
            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r2.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                r2[trueCount] = i + 1;
                trueCount++;
              }
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &tk_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &gh_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            i = BoardCoords.size(0);
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &oc_emlrtDCI, &st);
            }

            if (c_idx > i) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &hh_emlrtBCI, &st);
            }

            removedIdx.set_size(&mj_emlrtRTEI, &st, 1, r2.size(1));
            loop_ub = r2.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r2[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r2[i], 1, trueCount, &mh_emlrtBCI,
                  &st);
              }

              removedIdx[i] = BoardCoords[(c_idx + BoardCoords.size(0) * (r2[i]
                - 1)) - 1];
            }

            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r3.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                r3[trueCount] = i + 1;
                trueCount++;
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &sk_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (1 > i) {
              emlrtDynamicBoundsCheckR2012b(1, 1, i, &eh_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            i = BoardCoords.size(0);
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &nc_emlrtDCI, &st);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &fh_emlrtBCI, &st);
            }

            currCurve.set_size(&nj_emlrtRTEI, &st, 1, r3.size(1));
            loop_ub = r3.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r3[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r3[i], 1, trueCount, &nh_emlrtBCI,
                  &st);
              }

              currCurve[i] = BoardCoords[(b_idx + BoardCoords.size(0) * (r3[i] -
                1)) - 1];
            }

            b_iv[0] = (*(int32_T (*)[2])removedIdx.size())[0];
            b_iv[1] = (*(int32_T (*)[2])removedIdx.size())[1];
            iv1[0] = (*(int32_T (*)[2])currCurve.size())[0];
            iv1[1] = (*(int32_T (*)[2])currCurve.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &mb_emlrtECI, &st);
            b_index.set_size(&mj_emlrtRTEI, &st, 1, removedIdx.size(1));
            loop_ub = removedIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_index[i] = removedIdx[i] - currCurve[i];
            }

            b_st.site = &gl_emlrtRSI;
            x = mean(&b_st, b_index);
            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r4.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                r4[trueCount] = i + 1;
                trueCount++;
              }
            }

            if (2 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, idx.size(1), &rk_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ch_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            i = BoardCoords.size(0);
            if (idx[1] != i1) {
              emlrtIntegerCheckR2012b(idx[1], &mc_emlrtDCI, &st);
            }

            if (c_idx > i) {
              emlrtDynamicBoundsCheckR2012b(c_idx, 1, i, &dh_emlrtBCI, &st);
            }

            removedIdx.set_size(&oj_emlrtRTEI, &st, 1, r4.size(1));
            loop_ub = r4.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r4[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r4[i], 1, trueCount, &oh_emlrtBCI,
                  &st);
              }

              removedIdx[i] = BoardCoords[((c_idx + BoardCoords.size(0) * (r4[i]
                - 1)) + BoardCoords.size(0) * BoardCoords.size(1)) - 1];
            }

            loop_ub = r.size(1) - 1;
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                trueCount++;
              }
            }

            r5.set_size(&lj_emlrtRTEI, &st, 1, trueCount);
            trueCount = 0;
            for (i = 0; i <= loop_ub; i++) {
              if (r[i] && r1[i]) {
                r5[trueCount] = i + 1;
                trueCount++;
              }
            }

            if (1 > idx.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &qk_emlrtBCI, &st);
            }

            i = BoardCoords.size(2);
            if (2 > i) {
              emlrtDynamicBoundsCheckR2012b(2, 1, i, &ah_emlrtBCI, &st);
            }

            trueCount = BoardCoords.size(1);
            i = BoardCoords.size(0);
            if (idx[0] != b_i) {
              emlrtIntegerCheckR2012b(idx[0], &lc_emlrtDCI, &st);
            }

            if (b_idx > i) {
              emlrtDynamicBoundsCheckR2012b(b_idx, 1, i, &bh_emlrtBCI, &st);
            }

            currCurve.set_size(&pj_emlrtRTEI, &st, 1, r5.size(1));
            loop_ub = r5.size(1);
            for (i = 0; i < loop_ub; i++) {
              if (r5[i] > trueCount) {
                emlrtDynamicBoundsCheckR2012b(r5[i], 1, trueCount, &ph_emlrtBCI,
                  &st);
              }

              currCurve[i] = BoardCoords[((b_idx + BoardCoords.size(0) * (r5[i]
                - 1)) + BoardCoords.size(0) * BoardCoords.size(1)) - 1];
            }

            b_iv[0] = (*(int32_T (*)[2])removedIdx.size())[0];
            b_iv[1] = (*(int32_T (*)[2])removedIdx.size())[1];
            iv1[0] = (*(int32_T (*)[2])currCurve.size())[0];
            iv1[1] = (*(int32_T (*)[2])currCurve.size())[1];
            emlrtSizeEqCheckNDR2012b(&b_iv[0], &iv1[0], &lb_emlrtECI, &st);
            b_index.set_size(&oj_emlrtRTEI, &st, 1, removedIdx.size(1));
            loop_ub = removedIdx.size(1);
            for (i = 0; i < loop_ub; i++) {
              b_index[i] = removedIdx[i] - currCurve[i];
            }

            b_st.site = &hl_emlrtRSI;
            b_x = mean(&b_st, b_index);
            if (muDoubleScalarAbs(x) > muDoubleScalarAbs(b_x)) {
              coordsToUse[0] = 1.0;
              coordsToUse[1] = 2.0;
            } else {
              coordsToUse[0] = 2.0;
              coordsToUse[1] = 1.0;
            }

            newIndices.set_size(&qj_emlrtRTEI, sp, 1, newIndices.size(1));
            i = BoardCoords.size(1);
            if (i < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(i), &gb_emlrtDCI,
                (emlrtCTX)sp);
            }

            newIndices.set_size(&qj_emlrtRTEI, sp, newIndices.size(0), i);
            loop_ub = BoardCoords.size(1);
            if (loop_ub < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(loop_ub),
                &hb_emlrtDCI, (emlrtCTX)sp);
            }

            for (i = 0; i < loop_ub; i++) {
              newIndices[i] = 0.0;
            }

            removedIdx.set_size(&rj_emlrtRTEI, sp, 1, 0);
            i = BoardCoords.size(1);
            for (b_idx = 0; b_idx < i; b_idx++) {
              st.site = &yk_emlrtRSI;
              b_i = BoardCoords.size(1);
              if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i, &lh_emlrtBCI,
                  &st);
              }

              b_i = BoardCoords.size(2);
              i1 = static_cast<int32_T>(coordsToUse[0]);
              if (i1 > b_i) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &kh_emlrtBCI, &st);
              }

              loop_ub = BoardCoords.size(0);
              validIdx.set_size(&sj_emlrtRTEI, &st, loop_ub);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                validIdx[b_i] = BoardCoords[(b_i + BoardCoords.size(0) * b_idx)
                  + BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1)];
              }

              b_st.site = &jf_emlrtRSI;
              b_eml_find(&b_st, validIdx, ii);
              validIdx.set_size(&tj_emlrtRTEI, &st, ii.size(0));
              loop_ub = ii.size(0);
              for (b_i = 0; b_i < loop_ub; b_i++) {
                validIdx[b_i] = ii[b_i];
              }

              if (validIdx.size(0) >= 2) {
                real_T currCoord;
                real_T currRad;
                real_T refCoordValue;
                boolean_T exitg1;
                st.site = &al_emlrtRSI;
                if (1 > idx.size(1)) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, idx.size(1), &pk_emlrtBCI,
                    &st);
                }

                if (idx[0] == 1.0) {
                  b_i = BoardCoords.size(0);
                  if ((static_cast<int32_T>(validIdx[0]) < 1) ||
                      (static_cast<int32_T>(validIdx[0]) > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx
                      [0]), 1, b_i, &yg_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(1);
                  if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i,
                      &xg_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &wg_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(0);
                  if ((static_cast<int32_T>(validIdx[1]) < 1) ||
                      (static_cast<int32_T>(validIdx[1]) > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(validIdx
                      [1]), 1, b_i, &vg_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(1);
                  if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i,
                      &ug_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &tg_emlrtBCI, &st);
                  }

                  x = validIdx[0];
                  trueCount = static_cast<int32_T>(validIdx[0]);
                  b_x = (BoardCoords[((static_cast<int32_T>(validIdx[0]) +
                                       BoardCoords.size(0) * b_idx) +
                                      BoardCoords.size(0) * BoardCoords.size(1) *
                                      (i1 - 1)) - 1] - BoardCoords[((
                           static_cast<int32_T>(validIdx[1]) + BoardCoords.size
                           (0) * b_idx) + BoardCoords.size(0) * BoardCoords.size
                          (1) * (i1 - 1)) - 1]) / (validIdx[1] - validIdx[0]);
                } else {
                  b_i = BoardCoords.size(0);
                  trueCount = static_cast<int32_T>(validIdx[validIdx.size(0) - 1]);
                  if ((trueCount < 1) || (trueCount > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i,
                      &ok_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(1);
                  if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i,
                      &nk_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &mk_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(0);
                  if (validIdx.size(0) - 1 > validIdx.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(validIdx.size(0) - 1, 1,
                      validIdx.size(0), &wk_emlrtBCI, &st);
                  }

                  trueCount = static_cast<int32_T>(validIdx[validIdx.size(0) - 2]);
                  if ((trueCount < 1) || (trueCount > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i,
                      &lk_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(1);
                  if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                    emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i,
                      &kk_emlrtBCI, &st);
                  }

                  b_i = BoardCoords.size(2);
                  if (i1 > b_i) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &jk_emlrtBCI, &st);
                  }

                  x = (static_cast<real_T>(BoardCoords.size(0)) -
                       validIdx[validIdx.size(0) - 1]) + 1.0;
                  trueCount = static_cast<int32_T>(validIdx[validIdx.size(0) - 1]);
                  if (validIdx.size(0) - 1 > validIdx.size(0)) {
                    emlrtDynamicBoundsCheckR2012b(validIdx.size(0) - 1, 1,
                      validIdx.size(0), &xk_emlrtBCI, &st);
                  }

                  b_x = (BoardCoords[((static_cast<int32_T>
                                       (validIdx[validIdx.size(0) - 1]) +
                                       BoardCoords.size(0) * b_idx) +
                                      BoardCoords.size(0) * BoardCoords.size(1) *
                                      (i1 - 1)) - 1] - BoardCoords[((
                           static_cast<int32_T>(validIdx[validIdx.size(0) - 2])
                           + BoardCoords.size(0) * b_idx) + BoardCoords.size(0) *
                          BoardCoords.size(1) * (i1 - 1)) - 1]) /
                    (validIdx[validIdx.size(0) - 1] - validIdx[validIdx.size(0)
                     - 2]);
                }

                st.site = &bl_emlrtRSI;
                fitPolyCurve(&st, validIdx, static_cast<real_T>(b_idx) + 1.0,
                             coordsToUse, currCurve);
                currRad = b_x / 4.0;
                b_i = BoardCoords.size(0);
                if ((trueCount < 1) || (trueCount > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(trueCount, 1, b_i, &qh_emlrtBCI,
                    (emlrtCTX)sp);
                }

                b_i = BoardCoords.size(1);
                if ((b_idx + 1 < 1) || (b_idx + 1 > b_i)) {
                  emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1, b_i, &rh_emlrtBCI,
                    (emlrtCTX)sp);
                }

                b_i = BoardCoords.size(2);
                if (i1 > b_i) {
                  emlrtDynamicBoundsCheckR2012b(i1, 1, b_i, &sh_emlrtBCI,
                    (emlrtCTX)sp);
                }

                refCoordValue = BoardCoords[((trueCount + BoardCoords.size(0) *
                  b_idx) + BoardCoords.size(0) * BoardCoords.size(1) * (i1 - 1))
                  - 1];
                currCoord = currRad + refCoordValue;
                exitg1 = false;
                while ((!exitg1) && (muDoubleScalarAbs(currCoord - refCoordValue)
                                     < x * 1.5 * muDoubleScalarAbs(b_x))) {
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
                    st.site = &cl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      b_i = currCurve.size(1);
                      for (trueCount = 0; trueCount <= b_i - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = currCoord;
                    currPt[1] = y;
                  } else {
                    st.site = &dl_emlrtRSI;
                    if (currCurve.size(1) != 0) {
                      y = currCurve[0];
                      b_i = currCurve.size(1);
                      for (trueCount = 0; trueCount <= b_i - 2; trueCount++) {
                        y = currCoord * y + currCurve[trueCount + 1];
                      }
                    }

                    currPt[0] = y;
                    currPt[1] = currCoord;
                  }

                  st.site = &el_emlrtRSI;
                  findClosestOnCurve(&st, currPt, muDoubleScalarAbs(currRad),
                                     currCurve, coordsToUse, removedIdx, b_index);
                  if (b_index.size(1) != 0) {
                    if (1 != b_index.size(1)) {
                      emlrtSubAssignSizeCheck1dR2017a(1, b_index.size(1),
                        &ob_emlrtECI, (emlrtCTX)sp);
                    }

                    if ((b_idx + 1 < 1) || (b_idx + 1 > newIndices.size(1))) {
                      emlrtDynamicBoundsCheckR2012b(b_idx + 1, 1,
                        newIndices.size(1), &th_emlrtBCI, (emlrtCTX)sp);
                    }

                    newIndices[b_idx] = b_index[0];
                    b_i = removedIdx.size(1);
                    loop_ub = b_index.size(1);
                    removedIdx.set_size(&uj_emlrtRTEI, sp, removedIdx.size(0),
                                        removedIdx.size(1) + b_index.size(1));
                    for (i1 = 0; i1 < loop_ub; i1++) {
                      removedIdx[b_i + i1] = b_index[i1];
                    }

                    exitg1 = true;
                  } else {
                    currCoord += currRad;
                  }
                }
              }
            }

            st.site = &fl_emlrtRSI;
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
                st.site = &lj_emlrtRSI;
                PreviousEnergy = Energy;
                i = 0;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  if (i < 4) {
                    if (!IsDirectionBad[i]) {
                      LastExpandDirection = static_cast<real_T>(i) + 1.0;
                      b_st.site = &mj_emlrtRSI;
                      expandBoardDirectionally(&b_st, static_cast<real_T>(i) +
                        1.0);
                      if (Energy < PreviousEnergy) {
                        exitg1 = 1;
                      } else {
                        b_st.site = &nj_emlrtRSI;
                        Energy = PreviousEnergy;
                        if (LastExpandDirection != static_cast<int32_T>
                            (muDoubleScalarFloor(LastExpandDirection))) {
                          emlrtIntegerCheckR2012b(LastExpandDirection,
                            &ab_emlrtDCI, &b_st);
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
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &cf_emlrtBCI, &b_st);
                            }

                            if (2 > b_i) {
                              i1 = -1;
                              b_i = -1;
                            } else {
                              i1 = BoardIdx.size(0);
                              if (2 > i1) {
                                emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                  &df_emlrtBCI, &b_st);
                              }

                              i1 = 0;
                              i2 = BoardIdx.size(0);
                              if (b_i > i2) {
                                emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                  &ef_emlrtBCI, &b_st);
                              }

                              b_i--;
                            }

                            b_this = BoardIdx.size(1) - 1;
                            for (i2 = 0; i2 <= b_this; i2++) {
                              loop_ub_tmp = b_i - i1;
                              for (i3 = 0; i3 < loop_ub_tmp; i3++) {
                                BoardIdx[i3 + loop_ub_tmp * i2] = BoardIdx[((i1
                                  + i3) + BoardIdx.size(0) * i2) + 1];
                              }
                            }

                            BoardIdx.set_size(&ii_emlrtRTEI, &b_st, b_i - i1,
                                              b_this + 1);
                            b_i = BoardCoords.size(0);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &ff_emlrtBCI, &b_st);
                            }

                            if (2 > b_i) {
                              i1 = -1;
                              b_i = -1;
                            } else {
                              i1 = BoardCoords.size(0);
                              if (2 > i1) {
                                emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                  &gf_emlrtBCI, &b_st);
                              }

                              i1 = 0;
                              i2 = BoardCoords.size(0);
                              if (b_i > i2) {
                                emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                  &hf_emlrtBCI, &b_st);
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
                                    BoardCoords[(((i1 + i4) + BoardCoords.size(0)
                                                  * i3) + BoardCoords.size(0) *
                                                 BoardCoords.size(1) * i2) + 1];
                                }
                              }
                            }

                            BoardCoords.set_size(&ji_emlrtRTEI, &b_st, b_i - i1,
                                                 b_this + 1, c_this + 1);
                          }
                          break;

                         case 2:
                          {
                            int32_T b_i;
                            int32_T b_this;
                            int32_T c_this;
                            int32_T i1;
                            int32_T loop_ub;
                            int32_T loop_ub_tmp;
                            b_i = BoardIdx.size(0);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &if_emlrtBCI, &b_st);
                            }

                            if (1 > b_i - 1) {
                              loop_ub = 0;
                            } else {
                              i1 = BoardIdx.size(0);
                              if (1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(1, 1, i1,
                                  &jf_emlrtBCI, &b_st);
                              }

                              i1 = BoardIdx.size(0);
                              if (b_i - 1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(b_i - 1, 1, i1,
                                  &kf_emlrtBCI, &b_st);
                              }

                              loop_ub = b_i - 1;
                            }

                            b_this = BoardIdx.size(1) - 1;
                            for (b_i = 0; b_i <= b_this; b_i++) {
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                BoardIdx[i1 + loop_ub * b_i] = BoardIdx[i1 +
                                  BoardIdx.size(0) * b_i];
                              }
                            }

                            BoardIdx.set_size(&ki_emlrtRTEI, &b_st, loop_ub,
                                              b_this + 1);
                            b_i = BoardCoords.size(0);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &lf_emlrtBCI, &b_st);
                            }

                            if (1 > b_i - 1) {
                              loop_ub = 0;
                            } else {
                              i1 = BoardCoords.size(0);
                              if (1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(1, 1, i1,
                                  &mf_emlrtBCI, &b_st);
                              }

                              i1 = BoardCoords.size(0);
                              if (b_i - 1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(b_i - 1, 1, i1,
                                  &nf_emlrtBCI, &b_st);
                              }

                              loop_ub = b_i - 1;
                            }

                            b_this = BoardCoords.size(1) - 1;
                            c_this = BoardCoords.size(2) - 1;
                            loop_ub_tmp = BoardCoords.size(1);
                            for (b_i = 0; b_i <= c_this; b_i++) {
                              for (i1 = 0; i1 < loop_ub_tmp; i1++) {
                                for (int32_T i2{0}; i2 < loop_ub; i2++) {
                                  BoardCoords[(i2 + loop_ub * i1) + loop_ub *
                                    (b_this + 1) * b_i] = BoardCoords[(i2 +
                                    BoardCoords.size(0) * i1) + BoardCoords.size
                                    (0) * BoardCoords.size(1) * b_i];
                                }
                              }
                            }

                            BoardCoords.set_size(&li_emlrtRTEI, &b_st, loop_ub,
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
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &of_emlrtBCI, &b_st);
                            }

                            if (2 > b_i) {
                              i1 = 0;
                              b_i = 0;
                            } else {
                              i1 = BoardIdx.size(1);
                              if (2 > i1) {
                                emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                  &pf_emlrtBCI, &b_st);
                              }

                              i1 = 1;
                              i2 = BoardIdx.size(1);
                              if (b_i > i2) {
                                emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                  &qf_emlrtBCI, &b_st);
                              }
                            }

                            b_this = BoardIdx.size(0) - 1;
                            loop_ub = BoardIdx.size(0);
                            loop_ub_tmp = b_i - i1;
                            for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
                              for (i2 = 0; i2 < loop_ub; i2++) {
                                BoardIdx[i2 + (b_this + 1) * b_i] = BoardIdx[i2
                                  + BoardIdx.size(0) * (i1 + b_i)];
                              }
                            }

                            BoardIdx.set_size(&mi_emlrtRTEI, &b_st, b_this + 1,
                                              loop_ub_tmp);
                            b_i = BoardCoords.size(1);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &rf_emlrtBCI, &b_st);
                            }

                            if (2 > b_i) {
                              i1 = -1;
                              b_i = -1;
                            } else {
                              i1 = BoardCoords.size(1);
                              if (2 > i1) {
                                emlrtDynamicBoundsCheckR2012b(2, 1, i1,
                                  &sf_emlrtBCI, &b_st);
                              }

                              i1 = 0;
                              i2 = BoardCoords.size(1);
                              if (b_i > i2) {
                                emlrtDynamicBoundsCheckR2012b(b_i, 1, i2,
                                  &tf_emlrtBCI, &b_st);
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
                                  BoardCoords[(i4 + (b_this + 1) * i3) + (b_this
                                    + 1) * loop_ub_tmp * i2] = BoardCoords[(i4 +
                                    BoardCoords.size(0) * ((i1 + i3) + 1)) +
                                    BoardCoords.size(0) * BoardCoords.size(1) *
                                    i2];
                                }
                              }
                            }

                            BoardCoords.set_size(&ni_emlrtRTEI, &b_st, b_this +
                                                 1, b_i - i1, c_this + 1);
                          }
                          break;

                         case 4:
                          {
                            int32_T b_i;
                            int32_T b_this;
                            int32_T c_this;
                            int32_T i1;
                            int32_T loop_ub;
                            int32_T loop_ub_tmp;
                            b_i = BoardIdx.size(1);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &uf_emlrtBCI, &b_st);
                            }

                            if (1 > b_i - 1) {
                              loop_ub = 0;
                            } else {
                              i1 = BoardIdx.size(1);
                              if (1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(1, 1, i1,
                                  &vf_emlrtBCI, &b_st);
                              }

                              i1 = BoardIdx.size(1);
                              if (b_i - 1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(b_i - 1, 1, i1,
                                  &wf_emlrtBCI, &b_st);
                              }

                              loop_ub = b_i - 1;
                            }

                            b_this = BoardIdx.size(0) - 1;
                            loop_ub_tmp = BoardIdx.size(0);
                            for (b_i = 0; b_i < loop_ub; b_i++) {
                              for (i1 = 0; i1 < loop_ub_tmp; i1++) {
                                BoardIdx[i1 + (b_this + 1) * b_i] = BoardIdx[i1
                                  + BoardIdx.size(0) * b_i];
                              }
                            }

                            BoardIdx.set_size(&oi_emlrtRTEI, &b_st, b_this + 1,
                                              loop_ub);
                            b_i = BoardCoords.size(1);
                            if (b_i < 0) {
                              emlrtDynamicBoundsCheckR2012b(b_i, 0, MAX_int32_T,
                                &xf_emlrtBCI, &b_st);
                            }

                            if (1 > b_i - 1) {
                              loop_ub = 0;
                            } else {
                              i1 = BoardCoords.size(1);
                              if (1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(1, 1, i1,
                                  &yf_emlrtBCI, &b_st);
                              }

                              i1 = BoardCoords.size(1);
                              if (b_i - 1 > i1) {
                                emlrtDynamicBoundsCheckR2012b(b_i - 1, 1, i1,
                                  &ag_emlrtBCI, &b_st);
                              }

                              loop_ub = b_i - 1;
                            }

                            b_this = BoardCoords.size(0) - 1;
                            c_this = BoardCoords.size(2) - 1;
                            loop_ub_tmp = BoardCoords.size(0);
                            for (b_i = 0; b_i <= c_this; b_i++) {
                              for (i1 = 0; i1 < loop_ub; i1++) {
                                for (int32_T i2{0}; i2 < loop_ub_tmp; i2++) {
                                  BoardCoords[(i2 + (b_this + 1) * i1) + (b_this
                                    + 1) * loop_ub * b_i] = BoardCoords[(i2 +
                                    BoardCoords.size(0) * i1) + BoardCoords.size
                                    (0) * BoardCoords.size(1) * b_i];
                                }
                              }
                            }

                            BoardCoords.set_size(&pi_emlrtRTEI, &b_st, b_this +
                                                 1, loop_ub, c_this + 1);
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
            this_->BoardIdx.set_size(&uf_emlrtRTEI, sp, 1, 1);
            this_->BoardIdx[0] = 0.0;
            this_->BoardIdx.set_size(&vf_emlrtRTEI, sp, 3, 3);
            for (i = 0; i < 9; i++) {
              this_->BoardIdx[i] = 0.0;
            }

            this_->BoardCoords.set_size(&wf_emlrtRTEI, sp, 1, 1, 1);
            this_->BoardCoords[0] = 0.0;
            this_->BoardCoords.set_size(&xf_emlrtRTEI, sp, 3, 3, 2);
            for (i = 0; i < 18; i++) {
              this_->BoardCoords[i] = 0.0;
            }

            this_->Points.set_size(&yf_emlrtRTEI, sp, 1, 1);
            this_->Points[0] = 0.0F;
            this_->Points.set_size(&ag_emlrtRTEI, sp, 0, 2);
            this_->IsDistortionHigh = false;
            return this_;
          }

          void Checkerboard::initialize(const emlrtStack *sp, real_T seedIdx,
            const ::coder::array<real32_T, 2U> &points, const real32_T v1[2],
            const real32_T v2[2])
          {
            array<real_T, 2U> r1;
            array<int32_T, 1U> r;
            array<real32_T, 2U> b_r;
            array<real32_T, 2U> center;
            array<real32_T, 2U> d;
            array<real32_T, 2U> l;
            array<real32_T, 2U> pointVectors;
            array<real32_T, 2U> u;
            array<real32_T, 1U> b_pointVectors;
            array<real32_T, 1U> c_pointVectors;
            array<real32_T, 1U> euclideanDists;
            array<boolean_T, 1U> b_this;
            emlrtStack st;
            int32_T b_iv[3];
            int32_T iv1[2];
            int32_T iv2[2];
            int32_T acoef;
            int32_T csz_idx_0;
            int32_T csz_idx_1;
            int32_T loop_ub;
            real32_T b_v1[2];
            st.prev = sp;
            st.tls = sp->tls;
            emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
            BoardIdx.set_size(&bg_emlrtRTEI, sp, 1, 1);
            BoardIdx[0] = 0.0;
            BoardIdx.set_size(&cg_emlrtRTEI, sp, 3, 3);
            for (acoef = 0; acoef < 9; acoef++) {
              BoardIdx[acoef] = 0.0;
            }

            IsDirectionBad[0] = false;
            IsDirectionBad[1] = false;
            IsDirectionBad[2] = false;
            IsDirectionBad[3] = false;
            BoardCoords.set_size(&dg_emlrtRTEI, sp, 1, 1, 1);
            BoardCoords[0] = 0.0;
            BoardCoords.set_size(&eg_emlrtRTEI, sp, 3, 3, 2);
            for (acoef = 0; acoef < 18; acoef++) {
              BoardCoords[acoef] = 0.0;
            }

            Points.set_size(&fg_emlrtRTEI, sp, points.size(0), 2);
            loop_ub = points.size(0) * 2;
            for (acoef = 0; acoef < loop_ub; acoef++) {
              Points[acoef] = points[acoef];
            }

            acoef = Points.size(0);
            if (seedIdx != static_cast<int32_T>(muDoubleScalarFloor(seedIdx))) {
              emlrtIntegerCheckR2012b(seedIdx, &v_emlrtDCI, (emlrtCTX)sp);
            }

            if ((static_cast<int32_T>(seedIdx) < 1) || (static_cast<int32_T>
                 (seedIdx) > acoef)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(seedIdx), 1,
                acoef, &je_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = Points.size(1);
            center.set_size(&gg_emlrtRTEI, sp, 1, loop_ub);
            for (acoef = 0; acoef < loop_ub; acoef++) {
              center[acoef] = Points[(static_cast<int32_T>(seedIdx) +
                Points.size(0) * acoef) - 1];
            }

            acoef = BoardIdx.size(0);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ie_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardIdx.size(1);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &he_emlrtBCI, (emlrtCTX)
                sp);
            }

            BoardIdx[BoardIdx.size(0) + 1] = seedIdx;
            acoef = BoardCoords.size(0);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ge_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardCoords.size(1);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &fe_emlrtBCI, (emlrtCTX)
                sp);
            }

            loop_ub = BoardCoords.size(2);
            r.set_size(&hg_emlrtRTEI, sp, loop_ub);
            for (acoef = 0; acoef < loop_ub; acoef++) {
              r[acoef] = acoef;
            }

            b_iv[0] = 1;
            b_iv[1] = 1;
            b_iv[2] = r.size(0);
            emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, center.size(), 2,
              &cb_emlrtECI, (emlrtCTX)sp);
            loop_ub = r.size(0);
            for (acoef = 0; acoef < loop_ub; acoef++) {
              BoardCoords[(BoardCoords.size(0) + BoardCoords.size(0) *
                           BoardCoords.size(1) * r[acoef]) + 1] = center[acoef];
            }

            LastExpandDirection = 1.0;
            PreviousEnergy = rtInfF;
            isValid = false;
            st.site = &th_emlrtRSI;
            csz_idx_0 = Points.size(0);
            if (center.size(1) == 1) {
              csz_idx_1 = Points.size(1);
            } else if (Points.size(1) == 1) {
              csz_idx_1 = center.size(1);
            } else if (Points.size(1) == center.size(1)) {
              csz_idx_1 = Points.size(1);
            } else {
              emlrtErrorWithMessageIdR2018a(&st, &y_emlrtRTEI,
                "MATLAB:bsxfun:arrayDimensionsMustMatch",
                "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
            }

            if (csz_idx_0 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(csz_idx_0),
                &w_emlrtDCI, &st);
            }

            if (csz_idx_1 < 0) {
              emlrtNonNegativeCheckR2012b(static_cast<real_T>(csz_idx_1),
                &w_emlrtDCI, &st);
            }

            pointVectors.set_size(&ig_emlrtRTEI, &st, csz_idx_0, csz_idx_1);
            if ((csz_idx_0 != 0) && (csz_idx_1 != 0)) {
              int32_T b_acoef;
              int32_T bcoef;
              b_acoef = (Points.size(1) != 1);
              bcoef = (center.size(1) != 1);
              csz_idx_0 = csz_idx_1 - 1;
              for (int32_T k{0}; k <= csz_idx_0; k++) {
                int32_T b;
                loop_ub = b_acoef * k;
                csz_idx_1 = bcoef * k;
                acoef = (Points.size(0) != 1);
                b = pointVectors.size(0) - 1;
                for (int32_T b_k{0}; b_k <= b; b_k++) {
                  pointVectors[b_k + pointVectors.size(0) * k] = Points[acoef *
                    b_k + Points.size(0) * loop_ub] - center[csz_idx_1];
                }
              }
            }

            if (1 > pointVectors.size(1)) {
              emlrtDynamicBoundsCheckR2012b(1, 1, pointVectors.size(1),
                &ee_emlrtBCI, (emlrtCTX)sp);
            }

            if (2 > pointVectors.size(1)) {
              emlrtDynamicBoundsCheckR2012b(2, 1, pointVectors.size(1),
                &de_emlrtBCI, (emlrtCTX)sp);
            }

            loop_ub = pointVectors.size(0);
            b_pointVectors.set_size(&jg_emlrtRTEI, sp, pointVectors.size(0));
            for (acoef = 0; acoef < loop_ub; acoef++) {
              b_pointVectors[acoef] = pointVectors[acoef];
            }

            loop_ub = pointVectors.size(0);
            c_pointVectors.set_size(&kg_emlrtRTEI, sp, pointVectors.size(0));
            for (acoef = 0; acoef < loop_ub; acoef++) {
              c_pointVectors[acoef] = pointVectors[acoef + pointVectors.size(0)];
            }

            st.site = &uh_emlrtRSI;
            b_hypot(&st, b_pointVectors, c_pointVectors, euclideanDists);
            acoef = BoardIdx.size(0);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ce_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardIdx.size(1);
            if (3 > acoef) {
              emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &be_emlrtBCI, (emlrtCTX)
                sp);
            }

            st.site = &vh_emlrtRSI;
            BoardIdx[BoardIdx.size(0) * 2 + 1] = findNeighbor(&st, pointVectors,
              euclideanDists, v1);
            acoef = BoardIdx.size(0);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ae_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardIdx.size(1);
            if (1 > acoef) {
              emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &yd_emlrtBCI, (emlrtCTX)
                sp);
            }

            b_v1[0] = -v1[0];
            b_v1[1] = -v1[1];
            st.site = &wh_emlrtRSI;
            BoardIdx[1] = findNeighbor(&st, pointVectors, euclideanDists, b_v1);
            acoef = BoardIdx.size(0);
            if (3 > acoef) {
              emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &xd_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardIdx.size(1);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &wd_emlrtBCI, (emlrtCTX)
                sp);
            }

            st.site = &xh_emlrtRSI;
            BoardIdx[BoardIdx.size(0) + 2] = findNeighbor(&st, pointVectors,
              euclideanDists, v2);
            acoef = BoardIdx.size(0);
            if (1 > acoef) {
              emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &vd_emlrtBCI, (emlrtCTX)
                sp);
            }

            acoef = BoardIdx.size(1);
            if (2 > acoef) {
              emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ud_emlrtBCI, (emlrtCTX)
                sp);
            }

            b_v1[0] = -v2[0];
            b_v1[1] = -v2[1];
            st.site = &yh_emlrtRSI;
            BoardIdx[BoardIdx.size(0)] = findNeighbor(&st, pointVectors,
              euclideanDists, b_v1);
            csz_idx_0 = BoardIdx.size(0) * BoardIdx.size(1);
            b_this.set_size(&lg_emlrtRTEI, sp, csz_idx_0);
            for (acoef = 0; acoef < csz_idx_0; acoef++) {
              b_this[acoef] = (BoardIdx[acoef] < 0.0);
            }

            st.site = &ai_emlrtRSI;
            if (b_any(&st, b_this)) {
              isValid = false;
            } else {
              acoef = BoardIdx.size(0);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &td_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &sd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = Points.size(0);
              if (BoardIdx[BoardIdx.size(0) * 2 + 1] != static_cast<int32_T>
                  (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2 + 1]))) {
                emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2 + 1],
                  &u_emlrtDCI, (emlrtCTX)sp);
              }

              csz_idx_0 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2 + 1]);
              if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef, &rd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = Points.size(1);
              b_r.set_size(&mg_emlrtRTEI, sp, 1, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                b_r[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
              }

              acoef = BoardCoords.size(0);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &qd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardCoords.size(1);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &pd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r.set_size(&ng_emlrtRTEI, sp, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                r[acoef] = acoef;
              }

              b_iv[0] = 1;
              b_iv[1] = 1;
              b_iv[2] = r.size(0);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, b_r.size(), 2,
                &bb_emlrtECI, (emlrtCTX)sp);
              loop_ub = r.size(0);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                BoardCoords[(BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                             BoardCoords.size(1) * r[acoef]) + 1] = b_r[acoef];
              }

              acoef = BoardIdx.size(0);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &od_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &nd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = Points.size(0);
              if (BoardIdx[1] != static_cast<int32_T>(muDoubleScalarFloor
                   (BoardIdx[1]))) {
                emlrtIntegerCheckR2012b(BoardIdx[1], &t_emlrtDCI, (emlrtCTX)sp);
              }

              csz_idx_0 = static_cast<int32_T>(BoardIdx[1]);
              if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef, &md_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = Points.size(1);
              l.set_size(&og_emlrtRTEI, sp, 1, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                l[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
              }

              acoef = BoardCoords.size(0);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ld_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardCoords.size(1);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &kd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r.set_size(&pg_emlrtRTEI, sp, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                r[acoef] = acoef;
              }

              b_iv[0] = 1;
              b_iv[1] = 1;
              b_iv[2] = r.size(0);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, l.size(), 2,
                &ab_emlrtECI, (emlrtCTX)sp);
              loop_ub = r.size(0);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) * r[acoef]
                  + 1] = l[acoef];
              }

              acoef = BoardIdx.size(0);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &jd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &id_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = Points.size(0);
              if (BoardIdx[BoardIdx.size(0) + 2] != static_cast<int32_T>
                  (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) + 2]))) {
                emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) + 2],
                  &s_emlrtDCI, (emlrtCTX)sp);
              }

              csz_idx_0 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) + 2]);
              if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef, &hd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = Points.size(1);
              d.set_size(&qg_emlrtRTEI, sp, 1, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                d[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
              }

              acoef = BoardCoords.size(0);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &gd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardCoords.size(1);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &fd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r.set_size(&rg_emlrtRTEI, sp, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                r[acoef] = acoef;
              }

              b_iv[0] = 1;
              b_iv[1] = 1;
              b_iv[2] = r.size(0);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, d.size(), 2,
                &y_emlrtECI, (emlrtCTX)sp);
              loop_ub = r.size(0);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                BoardCoords[(BoardCoords.size(0) + BoardCoords.size(0) *
                             BoardCoords.size(1) * r[acoef]) + 2] = d[acoef];
              }

              acoef = BoardIdx.size(0);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &ed_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &dd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = Points.size(0);
              if (BoardIdx[BoardIdx.size(0)] != static_cast<int32_T>
                  (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0)]))) {
                emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0)], &r_emlrtDCI,
                  (emlrtCTX)sp);
              }

              csz_idx_0 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0)]);
              if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef, &cd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = Points.size(1);
              u.set_size(&sg_emlrtRTEI, sp, 1, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                u[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
              }

              acoef = BoardCoords.size(0);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &bd_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardCoords.size(1);
              if (2 > acoef) {
                emlrtDynamicBoundsCheckR2012b(2, 1, acoef, &ad_emlrtBCI,
                  (emlrtCTX)sp);
              }

              loop_ub = BoardCoords.size(2);
              r.set_size(&tg_emlrtRTEI, sp, loop_ub);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                r[acoef] = acoef;
              }

              b_iv[0] = 1;
              b_iv[1] = 1;
              b_iv[2] = r.size(0);
              emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, u.size(), 2,
                &x_emlrtECI, (emlrtCTX)sp);
              loop_ub = r.size(0);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                BoardCoords[BoardCoords.size(0) + BoardCoords.size(0) *
                  BoardCoords.size(1) * r[acoef]] = u[acoef];
              }

              iv1[0] = (*(int32_T (*)[2])u.size())[0];
              iv1[1] = (*(int32_T (*)[2])u.size())[1];
              iv2[0] = (*(int32_T (*)[2])center.size())[0];
              iv2[1] = (*(int32_T (*)[2])center.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &w_emlrtECI, (emlrtCTX)
                sp);
              u.set_size(&ug_emlrtRTEI, sp, 1, u.size(1));
              loop_ub = u.size(1) - 1;
              for (acoef = 0; acoef <= loop_ub; acoef++) {
                u[acoef] = u[acoef] - center[acoef];
              }

              iv1[0] = (*(int32_T (*)[2])d.size())[0];
              iv1[1] = (*(int32_T (*)[2])d.size())[1];
              iv2[0] = (*(int32_T (*)[2])center.size())[0];
              iv2[1] = (*(int32_T (*)[2])center.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &v_emlrtECI, (emlrtCTX)
                sp);
              d.set_size(&vg_emlrtRTEI, sp, 1, d.size(1));
              loop_ub = d.size(1) - 1;
              for (acoef = 0; acoef <= loop_ub; acoef++) {
                d[acoef] = d[acoef] - center[acoef];
              }

              iv1[0] = (*(int32_T (*)[2])b_r.size())[0];
              iv1[1] = (*(int32_T (*)[2])b_r.size())[1];
              iv2[0] = (*(int32_T (*)[2])center.size())[0];
              iv2[1] = (*(int32_T (*)[2])center.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &u_emlrtECI, (emlrtCTX)
                sp);
              b_r.set_size(&wg_emlrtRTEI, sp, 1, b_r.size(1));
              loop_ub = b_r.size(1) - 1;
              for (acoef = 0; acoef <= loop_ub; acoef++) {
                b_r[acoef] = b_r[acoef] - center[acoef];
              }

              iv1[0] = (*(int32_T (*)[2])l.size())[0];
              iv1[1] = (*(int32_T (*)[2])l.size())[1];
              iv2[0] = (*(int32_T (*)[2])center.size())[0];
              iv2[1] = (*(int32_T (*)[2])center.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &t_emlrtECI, (emlrtCTX)
                sp);
              l.set_size(&xg_emlrtRTEI, sp, 1, l.size(1));
              loop_ub = l.size(1) - 1;
              for (acoef = 0; acoef <= loop_ub; acoef++) {
                l[acoef] = l[acoef] - center[acoef];
              }

              iv1[0] = (*(int32_T (*)[2])u.size())[0];
              iv1[1] = (*(int32_T (*)[2])u.size())[1];
              iv2[0] = (*(int32_T (*)[2])l.size())[0];
              iv2[1] = (*(int32_T (*)[2])l.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &s_emlrtECI, (emlrtCTX)
                sp);
              acoef = BoardIdx.size(0);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &yc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &xc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              center.set_size(&yg_emlrtRTEI, sp, 1, u.size(1));
              loop_ub = u.size(1);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                center[acoef] = u[acoef] + l[acoef];
              }

              st.site = &bi_emlrtRSI;
              BoardIdx[0] = findNeighbor(&st, pointVectors, euclideanDists,
                center);
              iv1[0] = (*(int32_T (*)[2])d.size())[0];
              iv1[1] = (*(int32_T (*)[2])d.size())[1];
              iv2[0] = (*(int32_T (*)[2])l.size())[0];
              iv2[1] = (*(int32_T (*)[2])l.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &r_emlrtECI, (emlrtCTX)
                sp);
              acoef = BoardIdx.size(0);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &wc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &vc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              center.set_size(&ah_emlrtRTEI, sp, 1, d.size(1));
              loop_ub = d.size(1);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                center[acoef] = d[acoef] + l[acoef];
              }

              st.site = &ci_emlrtRSI;
              BoardIdx[2] = findNeighbor(&st, pointVectors, euclideanDists,
                center);
              iv1[0] = (*(int32_T (*)[2])d.size())[0];
              iv1[1] = (*(int32_T (*)[2])d.size())[1];
              iv2[0] = (*(int32_T (*)[2])b_r.size())[0];
              iv2[1] = (*(int32_T (*)[2])b_r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &q_emlrtECI, (emlrtCTX)
                sp);
              acoef = BoardIdx.size(0);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &uc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &tc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              center.set_size(&bh_emlrtRTEI, sp, 1, d.size(1));
              loop_ub = d.size(1);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                center[acoef] = d[acoef] + b_r[acoef];
              }

              st.site = &di_emlrtRSI;
              BoardIdx[BoardIdx.size(0) * 2 + 2] = findNeighbor(&st,
                pointVectors, euclideanDists, center);
              iv1[0] = (*(int32_T (*)[2])u.size())[0];
              iv1[1] = (*(int32_T (*)[2])u.size())[1];
              iv2[0] = (*(int32_T (*)[2])b_r.size())[0];
              iv2[1] = (*(int32_T (*)[2])b_r.size())[1];
              emlrtSizeEqCheckNDR2012b(&iv1[0], &iv2[0], &p_emlrtECI, (emlrtCTX)
                sp);
              acoef = BoardIdx.size(0);
              if (1 > acoef) {
                emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &sc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              acoef = BoardIdx.size(1);
              if (3 > acoef) {
                emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &rc_emlrtBCI,
                  (emlrtCTX)sp);
              }

              center.set_size(&ch_emlrtRTEI, sp, 1, u.size(1));
              loop_ub = u.size(1);
              for (acoef = 0; acoef < loop_ub; acoef++) {
                center[acoef] = u[acoef] + b_r[acoef];
              }

              st.site = &ei_emlrtRSI;
              BoardIdx[BoardIdx.size(0) * 2] = findNeighbor(&st, pointVectors,
                euclideanDists, center);
              csz_idx_0 = BoardIdx.size(0) * BoardIdx.size(1);
              b_this.set_size(&dh_emlrtRTEI, sp, csz_idx_0);
              for (acoef = 0; acoef < csz_idx_0; acoef++) {
                b_this[acoef] = (BoardIdx[acoef] > 0.0);
              }

              st.site = &fi_emlrtRSI;
              isValid = all(&st, b_this);
              if (isValid) {
                acoef = BoardCoords.size(0);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &nc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardCoords.size(1);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &mc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&eh_emlrtRTEI, sp, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r[acoef] = acoef;
                }

                acoef = BoardIdx.size(0);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &qc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardIdx.size(1);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &pc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = Points.size(0);
                if (BoardIdx[0] != static_cast<int32_T>(muDoubleScalarFloor
                     (BoardIdx[0]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[0], &q_emlrtDCI, (emlrtCTX)sp);
                }

                csz_idx_0 = static_cast<int32_T>(BoardIdx[0]);
                if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                  emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef,
                    &oc_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                r1.set_size(&fh_emlrtRTEI, sp, 1, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r1[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
                }

                b_iv[0] = 1;
                b_iv[1] = 1;
                b_iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, r1.size(), 2,
                  &o_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) *
                    r[acoef]] = r1[acoef];
                }

                acoef = BoardCoords.size(0);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &ic_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardCoords.size(1);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &hc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&gh_emlrtRTEI, sp, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r[acoef] = acoef;
                }

                acoef = BoardIdx.size(0);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &lc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardIdx.size(1);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &kc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = Points.size(0);
                if (BoardIdx[2] != static_cast<int32_T>(muDoubleScalarFloor
                     (BoardIdx[2]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[2], &p_emlrtDCI, (emlrtCTX)sp);
                }

                csz_idx_0 = static_cast<int32_T>(BoardIdx[2]);
                if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                  emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef,
                    &jc_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                r1.set_size(&hh_emlrtRTEI, sp, 1, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r1[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
                }

                b_iv[0] = 1;
                b_iv[1] = 1;
                b_iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, r1.size(), 2,
                  &n_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  BoardCoords[BoardCoords.size(0) * BoardCoords.size(1) *
                    r[acoef] + 2] = r1[acoef];
                }

                acoef = BoardCoords.size(0);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &dc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardCoords.size(1);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &cc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&ih_emlrtRTEI, sp, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r[acoef] = acoef;
                }

                acoef = BoardIdx.size(0);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &gc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardIdx.size(1);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &fc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = Points.size(0);
                if (BoardIdx[BoardIdx.size(0) * 2 + 2] != static_cast<int32_T>
                    (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2 + 2]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2 + 2],
                    &o_emlrtDCI, (emlrtCTX)sp);
                }

                csz_idx_0 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2 +
                  2]);
                if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                  emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef,
                    &ec_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                r1.set_size(&jh_emlrtRTEI, sp, 1, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r1[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
                }

                b_iv[0] = 1;
                b_iv[1] = 1;
                b_iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, r1.size(), 2,
                  &m_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  BoardCoords[(BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                               BoardCoords.size(1) * r[acoef]) + 2] = r1[acoef];
                }

                acoef = BoardCoords.size(0);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &xb_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardCoords.size(1);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &wb_emlrtBCI,
                    (emlrtCTX)sp);
                }

                loop_ub = BoardCoords.size(2);
                r.set_size(&kh_emlrtRTEI, sp, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r[acoef] = acoef;
                }

                acoef = BoardIdx.size(0);
                if (1 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(1, 1, acoef, &bc_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = BoardIdx.size(1);
                if (3 > acoef) {
                  emlrtDynamicBoundsCheckR2012b(3, 1, acoef, &ac_emlrtBCI,
                    (emlrtCTX)sp);
                }

                acoef = Points.size(0);
                if (BoardIdx[BoardIdx.size(0) * 2] != static_cast<int32_T>
                    (muDoubleScalarFloor(BoardIdx[BoardIdx.size(0) * 2]))) {
                  emlrtIntegerCheckR2012b(BoardIdx[BoardIdx.size(0) * 2],
                    &n_emlrtDCI, (emlrtCTX)sp);
                }

                csz_idx_0 = static_cast<int32_T>(BoardIdx[BoardIdx.size(0) * 2]);
                if ((csz_idx_0 < 1) || (csz_idx_0 > acoef)) {
                  emlrtDynamicBoundsCheckR2012b(csz_idx_0, 1, acoef,
                    &yb_emlrtBCI, (emlrtCTX)sp);
                }

                loop_ub = Points.size(1);
                r1.set_size(&lh_emlrtRTEI, sp, 1, loop_ub);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  r1[acoef] = Points[(csz_idx_0 + Points.size(0) * acoef) - 1];
                }

                b_iv[0] = 1;
                b_iv[1] = 1;
                b_iv[2] = r.size(0);
                emlrtSubAssignSizeCheckR2012b(&b_iv[0], 3, r1.size(), 2,
                  &l_emlrtECI, (emlrtCTX)sp);
                loop_ub = r.size(0);
                for (acoef = 0; acoef < loop_ub; acoef++) {
                  BoardCoords[BoardCoords.size(0) * 2 + BoardCoords.size(0) *
                    BoardCoords.size(1) * r[acoef]] = r1[acoef];
                }

                st.site = &gi_emlrtRSI;
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

// End of code generation (Checkerboard.cpp)
