//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// calibrateOneCamera_v2_data.h
//
// Code generation for function 'calibrateOneCamera_v2_data'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo j_emlrtRSI;
extern emlrtRSInfo k_emlrtRSI;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo q_emlrtRSI;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo t_emlrtRSI;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo cb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo wb_emlrtRSI;
extern emlrtRSInfo xb_emlrtRSI;
extern emlrtRSInfo yb_emlrtRSI;
extern emlrtRSInfo ac_emlrtRSI;
extern emlrtRSInfo bc_emlrtRSI;
extern emlrtRSInfo cc_emlrtRSI;
extern emlrtRSInfo dc_emlrtRSI;
extern emlrtRSInfo ec_emlrtRSI;
extern emlrtRSInfo fc_emlrtRSI;
extern emlrtRSInfo gc_emlrtRSI;
extern emlrtRSInfo hc_emlrtRSI;
extern emlrtRSInfo ic_emlrtRSI;
extern emlrtRSInfo jc_emlrtRSI;
extern emlrtRSInfo kc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo yc_emlrtRSI;
extern emlrtRSInfo ad_emlrtRSI;
extern emlrtRSInfo bd_emlrtRSI;
extern emlrtRSInfo fd_emlrtRSI;
extern emlrtRSInfo id_emlrtRSI;
extern emlrtRSInfo jd_emlrtRSI;
extern emlrtRSInfo kd_emlrtRSI;
extern emlrtRSInfo ld_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo pd_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo rd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo ge_emlrtRSI;
extern emlrtRSInfo he_emlrtRSI;
extern emlrtRSInfo ie_emlrtRSI;
extern emlrtRSInfo je_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo me_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo pe_emlrtRSI;
extern emlrtRSInfo jf_emlrtRSI;
extern emlrtRSInfo kf_emlrtRSI;
extern emlrtRSInfo mf_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo gg_emlrtRSI;
extern emlrtRSInfo hi_emlrtRSI;
extern emlrtRSInfo ii_emlrtRSI;
extern emlrtRSInfo ji_emlrtRSI;
extern emlrtRSInfo pi_emlrtRSI;
extern emlrtRSInfo qi_emlrtRSI;
extern emlrtRSInfo ri_emlrtRSI;
extern emlrtRSInfo si_emlrtRSI;
extern emlrtRSInfo ti_emlrtRSI;
extern emlrtRSInfo ui_emlrtRSI;
extern emlrtRSInfo aj_emlrtRSI;
extern emlrtRSInfo bj_emlrtRSI;
extern emlrtRSInfo il_emlrtRSI;
extern emlrtRSInfo jl_emlrtRSI;
extern emlrtRSInfo ll_emlrtRSI;
extern emlrtRSInfo ml_emlrtRSI;
extern emlrtRSInfo ol_emlrtRSI;
extern emlrtRSInfo vl_emlrtRSI;
extern emlrtRSInfo gm_emlrtRSI;
extern emlrtRSInfo hm_emlrtRSI;
extern emlrtRSInfo im_emlrtRSI;
extern emlrtRSInfo jm_emlrtRSI;
extern emlrtRSInfo km_emlrtRSI;
extern emlrtRSInfo lm_emlrtRSI;
extern emlrtRSInfo mm_emlrtRSI;
extern emlrtRSInfo nm_emlrtRSI;
extern emlrtRSInfo om_emlrtRSI;
extern emlrtRSInfo hn_emlrtRSI;
extern emlrtRSInfo in_emlrtRSI;
extern emlrtRSInfo ho_emlrtRSI;
extern emlrtRSInfo io_emlrtRSI;
extern emlrtRSInfo jo_emlrtRSI;
extern emlrtRSInfo ko_emlrtRSI;
extern emlrtRSInfo mo_emlrtRSI;
extern emlrtRSInfo to_emlrtRSI;
extern emlrtRSInfo uo_emlrtRSI;
extern emlrtRSInfo xo_emlrtRSI;
extern emlrtRSInfo yo_emlrtRSI;
extern emlrtRSInfo ap_emlrtRSI;
extern emlrtRSInfo bp_emlrtRSI;
extern emlrtRSInfo cp_emlrtRSI;
extern emlrtRSInfo lp_emlrtRSI;
extern emlrtRSInfo cr_emlrtRSI;
extern emlrtRSInfo ks_emlrtRSI;
extern emlrtRSInfo ls_emlrtRSI;
extern emlrtRSInfo gu_emlrtRSI;
extern emlrtRSInfo hu_emlrtRSI;
extern emlrtRSInfo iu_emlrtRSI;
extern emlrtRSInfo ju_emlrtRSI;
extern emlrtRSInfo ku_emlrtRSI;
extern emlrtRSInfo lu_emlrtRSI;
extern emlrtRSInfo mu_emlrtRSI;
extern emlrtRSInfo ou_emlrtRSI;
extern emlrtRSInfo yx_emlrtRSI;
extern emlrtRSInfo cy_emlrtRSI;
extern emlrtRSInfo dy_emlrtRSI;
extern emlrtRSInfo sab_emlrtRSI;
extern emlrtRSInfo nbb_emlrtRSI;
extern emlrtRSInfo obb_emlrtRSI;
extern emlrtRSInfo pbb_emlrtRSI;
extern emlrtRSInfo qbb_emlrtRSI;
extern emlrtRSInfo lcb_emlrtRSI;
extern emlrtRSInfo rcb_emlrtRSI;
extern emlrtRSInfo vcb_emlrtRSI;
extern emlrtRSInfo xeb_emlrtRSI;
extern emlrtMCInfo c_emlrtMCI;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo c_emlrtRTEI;
extern emlrtRTEInfo d_emlrtRTEI;
extern emlrtRTEInfo e_emlrtRTEI;
extern emlrtECInfo b_emlrtECI;
extern emlrtECInfo c_emlrtECI;
extern emlrtECInfo d_emlrtECI;
extern emlrtECInfo e_emlrtECI;
extern emlrtECInfo f_emlrtECI;
extern emlrtECInfo g_emlrtECI;
extern emlrtECInfo h_emlrtECI;
extern emlrtECInfo i_emlrtECI;
extern emlrtRTEInfo h_emlrtRTEI;
extern emlrtBCInfo l_emlrtBCI;
extern emlrtBCInfo m_emlrtBCI;
extern emlrtBCInfo n_emlrtBCI;
extern emlrtBCInfo o_emlrtBCI;
extern emlrtRTEInfo i_emlrtRTEI;
extern emlrtRTEInfo l_emlrtRTEI;
extern emlrtDCInfo b_emlrtDCI;
extern emlrtRTEInfo q_emlrtRTEI;
extern emlrtRTEInfo s_emlrtRTEI;
extern emlrtRTEInfo t_emlrtRTEI;
extern emlrtRTEInfo x_emlrtRTEI;
extern emlrtRTEInfo y_emlrtRTEI;
extern emlrtRTEInfo bb_emlrtRTEI;
extern emlrtRTEInfo cb_emlrtRTEI;
extern emlrtRTEInfo db_emlrtRTEI;
extern emlrtRTEInfo ib_emlrtRTEI;
extern emlrtRTEInfo jb_emlrtRTEI;
extern emlrtRTEInfo qb_emlrtRTEI;
extern emlrtRTEInfo rb_emlrtRTEI;
extern emlrtRTEInfo tb_emlrtRTEI;
extern emlrtRTEInfo vb_emlrtRTEI;
extern emlrtRTEInfo bc_emlrtRTEI;
extern emlrtRTEInfo gc_emlrtRTEI;
extern emlrtRTEInfo hc_emlrtRTEI;
extern emlrtRTEInfo lc_emlrtRTEI;
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
extern emlrtRTEInfo ee_emlrtRTEI;
extern emlrtRTEInfo fe_emlrtRTEI;
extern emlrtRTEInfo ge_emlrtRTEI;
extern emlrtRTEInfo he_emlrtRTEI;
extern emlrtRTEInfo ie_emlrtRTEI;
extern emlrtRTEInfo je_emlrtRTEI;
extern emlrtRTEInfo ke_emlrtRTEI;
extern emlrtRTEInfo le_emlrtRTEI;
extern emlrtRTEInfo me_emlrtRTEI;
extern emlrtRTEInfo ne_emlrtRTEI;
extern emlrtRTEInfo oe_emlrtRTEI;
extern emlrtRTEInfo pe_emlrtRTEI;
extern emlrtRTEInfo qe_emlrtRTEI;
extern emlrtRTEInfo ue_emlrtRTEI;
extern emlrtRTEInfo ff_emlrtRTEI;
extern emlrtRTEInfo jf_emlrtRTEI;
extern emlrtRTEInfo mf_emlrtRTEI;
extern emlrtRTEInfo nf_emlrtRTEI;
extern emlrtRTEInfo of_emlrtRTEI;
extern emlrtRTEInfo pf_emlrtRTEI;
extern emlrtRTEInfo qf_emlrtRTEI;
extern emlrtRTEInfo rf_emlrtRTEI;
extern emlrtRTEInfo ag_emlrtRTEI;
extern emlrtRTEInfo eh_emlrtRTEI;
extern emlrtRTEInfo tj_emlrtRTEI;
extern emlrtRTEInfo uj_emlrtRTEI;
extern emlrtRTEInfo vj_emlrtRTEI;
extern emlrtRTEInfo al_emlrtRTEI;
extern emlrtRTEInfo jl_emlrtRTEI;
extern emlrtRTEInfo kl_emlrtRTEI;
extern emlrtRTEInfo nl_emlrtRTEI;
extern emlrtRTEInfo yn_emlrtRTEI;
extern emlrtRTEInfo fs_emlrtRTEI;
extern emlrtRTEInfo gs_emlrtRTEI;
extern emlrtRTEInfo hs_emlrtRTEI;
extern emlrtRTEInfo is_emlrtRTEI;
extern emlrtRTEInfo kt_emlrtRTEI;
extern const char_T cv[14];
extern const real_T dv[841];
extern const char_T cv1[14];
extern const char_T cv2[14];
extern emlrtRSInfo tfb_emlrtRSI;
extern covrtInstance emlrtCoverageInstance;

// End of code generation (calibrateOneCamera_v2_data.h)
