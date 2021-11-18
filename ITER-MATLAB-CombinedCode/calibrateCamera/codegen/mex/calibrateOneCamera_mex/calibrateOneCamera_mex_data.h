//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_mex_data.h
//
// Code generation for function 'calibrateOneCamera_mex_data'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include "omp.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo db_emlrtRSI;
extern emlrtRSInfo eb_emlrtRSI;
extern emlrtRSInfo fb_emlrtRSI;
extern emlrtRSInfo gb_emlrtRSI;
extern emlrtRSInfo hb_emlrtRSI;
extern emlrtRSInfo ib_emlrtRSI;
extern emlrtRSInfo jb_emlrtRSI;
extern emlrtRSInfo kb_emlrtRSI;
extern emlrtRSInfo lb_emlrtRSI;
extern emlrtRSInfo mb_emlrtRSI;
extern emlrtRSInfo nb_emlrtRSI;
extern emlrtRSInfo ob_emlrtRSI;
extern emlrtRSInfo pb_emlrtRSI;
extern emlrtRSInfo qb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo wb_emlrtRSI;
extern emlrtRSInfo xb_emlrtRSI;
extern emlrtRSInfo yb_emlrtRSI;
extern emlrtRSInfo ec_emlrtRSI;
extern emlrtRSInfo hc_emlrtRSI;
extern emlrtRSInfo ic_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo tc_emlrtRSI;
extern emlrtRSInfo uc_emlrtRSI;
extern emlrtRSInfo wc_emlrtRSI;
extern emlrtRSInfo xc_emlrtRSI;
extern emlrtRSInfo ad_emlrtRSI;
extern emlrtRSInfo kd_emlrtRSI;
extern emlrtRSInfo ld_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo rd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo je_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo me_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo qe_emlrtRSI;
extern emlrtRSInfo ef_emlrtRSI;
extern emlrtRSInfo lf_emlrtRSI;
extern emlrtRSInfo mf_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo of_emlrtRSI;
extern emlrtRSInfo pf_emlrtRSI;
extern emlrtRSInfo qf_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo gh_emlrtRSI;
extern emlrtRSInfo hh_emlrtRSI;
extern emlrtRSInfo ih_emlrtRSI;
extern emlrtRSInfo jh_emlrtRSI;
extern emlrtRSInfo rh_emlrtRSI;
extern emlrtRSInfo sh_emlrtRSI;
extern emlrtRSInfo wj_emlrtRSI;
extern emlrtRSInfo xj_emlrtRSI;
extern emlrtRSInfo ak_emlrtRSI;
extern emlrtRSInfo bk_emlrtRSI;
extern emlrtRSInfo dk_emlrtRSI;
extern emlrtRSInfo pk_emlrtRSI;
extern emlrtRSInfo rk_emlrtRSI;
extern emlrtRSInfo sk_emlrtRSI;
extern emlrtRSInfo tk_emlrtRSI;
extern emlrtRSInfo uk_emlrtRSI;
extern emlrtRSInfo vk_emlrtRSI;
extern emlrtRSInfo wk_emlrtRSI;
extern emlrtRSInfo xk_emlrtRSI;
extern emlrtRSInfo yk_emlrtRSI;
extern emlrtRSInfo al_emlrtRSI;
extern emlrtRSInfo ol_emlrtRSI;
extern emlrtRSInfo pl_emlrtRSI;
extern emlrtRSInfo ql_emlrtRSI;
extern emlrtRSInfo rl_emlrtRSI;
extern emlrtRSInfo sl_emlrtRSI;
extern emlrtRSInfo pm_emlrtRSI;
extern emlrtRSInfo qm_emlrtRSI;
extern emlrtRSInfo rm_emlrtRSI;
extern emlrtRSInfo bn_emlrtRSI;
extern emlrtRSInfo cn_emlrtRSI;
extern emlrtRSInfo gn_emlrtRSI;
extern emlrtRSInfo xo_emlrtRSI;
extern emlrtRSInfo fq_emlrtRSI;
extern emlrtRSInfo ur_emlrtRSI;
extern emlrtRSInfo vr_emlrtRSI;
extern emlrtRSInfo wr_emlrtRSI;
extern emlrtRSInfo xr_emlrtRSI;
extern emlrtRSInfo yr_emlrtRSI;
extern emlrtRSInfo as_emlrtRSI;
extern emlrtRSInfo bs_emlrtRSI;
extern emlrtRSInfo ut_emlrtRSI;
extern emlrtRSInfo wt_emlrtRSI;
extern emlrtRSInfo xt_emlrtRSI;
extern emlrtRSInfo au_emlrtRSI;
extern emlrtRSInfo mv_emlrtRSI;
extern emlrtRSInfo ww_emlrtRSI;
extern emlrtRSInfo yw_emlrtRSI;
extern emlrtRSInfo ax_emlrtRSI;
extern emlrtRSInfo bx_emlrtRSI;
extern emlrtRSInfo cx_emlrtRSI;
extern emlrtRSInfo dx_emlrtRSI;
extern emlrtRSInfo ex_emlrtRSI;
extern emlrtRSInfo fx_emlrtRSI;
extern emlrtRSInfo gx_emlrtRSI;
extern emlrtRSInfo jx_emlrtRSI;
extern emlrtRSInfo nx_emlrtRSI;
extern emlrtRSInfo sx_emlrtRSI;
extern emlrtRSInfo vx_emlrtRSI;
extern emlrtRSInfo ly_emlrtRSI;
extern emlrtRSInfo py_emlrtRSI;
extern emlrtMCInfo c_emlrtMCI;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t calibrateOneCamera_nestLockGlobal;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo e_emlrtRTEI;
extern emlrtRTEInfo g_emlrtRTEI;
extern emlrtECInfo b_emlrtECI;
extern emlrtECInfo c_emlrtECI;
extern emlrtECInfo d_emlrtECI;
extern emlrtECInfo e_emlrtECI;
extern emlrtECInfo f_emlrtECI;
extern emlrtECInfo g_emlrtECI;
extern emlrtECInfo h_emlrtECI;
extern emlrtECInfo i_emlrtECI;
extern emlrtBCInfo y_emlrtBCI;
extern emlrtBCInfo ab_emlrtBCI;
extern emlrtBCInfo bb_emlrtBCI;
extern emlrtBCInfo cb_emlrtBCI;
extern emlrtRTEInfo k_emlrtRTEI;
extern emlrtRTEInfo l_emlrtRTEI;
extern emlrtRTEInfo m_emlrtRTEI;
extern emlrtRTEInfo o_emlrtRTEI;
extern emlrtRTEInfo q_emlrtRTEI;
extern emlrtRTEInfo u_emlrtRTEI;
extern emlrtRTEInfo v_emlrtRTEI;
extern emlrtRTEInfo y_emlrtRTEI;
extern emlrtRTEInfo ab_emlrtRTEI;
extern emlrtRTEInfo fb_emlrtRTEI;
extern emlrtRTEInfo gb_emlrtRTEI;
extern emlrtRTEInfo ob_emlrtRTEI;
extern emlrtRTEInfo sb_emlrtRTEI;
extern emlrtBCInfo mt_emlrtBCI;
extern emlrtRTEInfo bd_emlrtRTEI;
extern emlrtRTEInfo ed_emlrtRTEI;
extern emlrtRTEInfo fd_emlrtRTEI;
extern emlrtRTEInfo gd_emlrtRTEI;
extern emlrtRTEInfo hd_emlrtRTEI;
extern emlrtRTEInfo id_emlrtRTEI;
extern emlrtRTEInfo jd_emlrtRTEI;
extern emlrtRTEInfo kd_emlrtRTEI;
extern emlrtRTEInfo ld_emlrtRTEI;
extern emlrtRTEInfo md_emlrtRTEI;
extern emlrtRTEInfo nd_emlrtRTEI;
extern emlrtRTEInfo od_emlrtRTEI;
extern emlrtRTEInfo pd_emlrtRTEI;
extern emlrtRTEInfo qd_emlrtRTEI;
extern emlrtRTEInfo rd_emlrtRTEI;
extern emlrtRTEInfo sd_emlrtRTEI;
extern emlrtRTEInfo td_emlrtRTEI;
extern emlrtRTEInfo ud_emlrtRTEI;
extern emlrtRTEInfo vd_emlrtRTEI;
extern emlrtRTEInfo wd_emlrtRTEI;
extern emlrtRTEInfo xd_emlrtRTEI;
extern emlrtRTEInfo yd_emlrtRTEI;
extern emlrtRTEInfo ae_emlrtRTEI;
extern emlrtRTEInfo be_emlrtRTEI;
extern emlrtRTEInfo ce_emlrtRTEI;
extern emlrtRTEInfo de_emlrtRTEI;
extern emlrtRTEInfo he_emlrtRTEI;
extern emlrtRTEInfo ne_emlrtRTEI;
extern emlrtRTEInfo re_emlrtRTEI;
extern emlrtRTEInfo ue_emlrtRTEI;
extern emlrtRTEInfo ve_emlrtRTEI;
extern emlrtRTEInfo we_emlrtRTEI;
extern emlrtRTEInfo xe_emlrtRTEI;
extern emlrtRTEInfo ye_emlrtRTEI;
extern emlrtRTEInfo af_emlrtRTEI;
extern emlrtRTEInfo if_emlrtRTEI;
extern emlrtRTEInfo mg_emlrtRTEI;
extern emlrtRTEInfo xi_emlrtRTEI;
extern emlrtRTEInfo bj_emlrtRTEI;
extern emlrtRTEInfo ck_emlrtRTEI;
extern emlrtRTEInfo rm_emlrtRTEI;
extern emlrtRTEInfo qo_emlrtRTEI;
extern emlrtRTEInfo ar_emlrtRTEI;
extern emlrtRTEInfo ls_emlrtRTEI;
extern emlrtRTEInfo ms_emlrtRTEI;
extern emlrtRTEInfo ns_emlrtRTEI;
extern const char_T cv[14];
extern const real_T dv[841];
extern const char_T cv1[14];
extern const char_T cv2[14];
extern const int8_T iv[9];
extern const char_T cv3[128];
extern emlrtRSInfo lbb_emlrtRSI;
extern covrtInstance emlrtCoverageInstance;

// End of code generation (calibrateOneCamera_mex_data.h)
