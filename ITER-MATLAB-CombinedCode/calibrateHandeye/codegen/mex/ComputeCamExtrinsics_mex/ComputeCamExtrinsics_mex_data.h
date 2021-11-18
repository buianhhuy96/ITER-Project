//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// ComputeCamExtrinsics_mex_data.h
//
// Code generation for function 'ComputeCamExtrinsics_mex_data'
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
extern emlrtRSInfo h_emlrtRSI;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo j_emlrtRSI;
extern emlrtRSInfo k_emlrtRSI;
extern emlrtRSInfo l_emlrtRSI;
extern emlrtRSInfo n_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo p_emlrtRSI;
extern emlrtRSInfo q_emlrtRSI;
extern emlrtRSInfo r_emlrtRSI;
extern emlrtRSInfo s_emlrtRSI;
extern emlrtRSInfo t_emlrtRSI;
extern emlrtRSInfo u_emlrtRSI;
extern emlrtRSInfo v_emlrtRSI;
extern emlrtRSInfo x_emlrtRSI;
extern emlrtRSInfo bb_emlrtRSI;
extern emlrtRSInfo kb_emlrtRSI;
extern emlrtRSInfo qb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
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
extern emlrtRSInfo rc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo tc_emlrtRSI;
extern emlrtRSInfo yc_emlrtRSI;
extern emlrtRSInfo cd_emlrtRSI;
extern emlrtRSInfo dd_emlrtRSI;
extern emlrtRSInfo ed_emlrtRSI;
extern emlrtRSInfo jd_emlrtRSI;
extern emlrtRSInfo kd_emlrtRSI;
extern emlrtRSInfo ld_emlrtRSI;
extern emlrtRSInfo md_emlrtRSI;
extern emlrtRSInfo nd_emlrtRSI;
extern emlrtRSInfo od_emlrtRSI;
extern emlrtRSInfo qd_emlrtRSI;
extern emlrtRSInfo rd_emlrtRSI;
extern emlrtRSInfo sd_emlrtRSI;
extern emlrtRSInfo td_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo xd_emlrtRSI;
extern emlrtRSInfo ie_emlrtRSI;
extern emlrtRSInfo je_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo me_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo pe_emlrtRSI;
extern emlrtRSInfo qe_emlrtRSI;
extern emlrtRSInfo re_emlrtRSI;
extern emlrtRSInfo lf_emlrtRSI;
extern emlrtRSInfo mf_emlrtRSI;
extern emlrtRSInfo of_emlrtRSI;
extern emlrtRSInfo pf_emlrtRSI;
extern emlrtRSInfo tf_emlrtRSI;
extern emlrtRSInfo ig_emlrtRSI;
extern emlrtRSInfo ki_emlrtRSI;
extern emlrtRSInfo li_emlrtRSI;
extern emlrtRSInfo mi_emlrtRSI;
extern emlrtRSInfo si_emlrtRSI;
extern emlrtRSInfo ti_emlrtRSI;
extern emlrtRSInfo ui_emlrtRSI;
extern emlrtRSInfo vi_emlrtRSI;
extern emlrtRSInfo dj_emlrtRSI;
extern emlrtRSInfo ej_emlrtRSI;
extern emlrtRSInfo ll_emlrtRSI;
extern emlrtRSInfo ml_emlrtRSI;
extern emlrtRSInfo ol_emlrtRSI;
extern emlrtRSInfo pl_emlrtRSI;
extern emlrtRSInfo rl_emlrtRSI;
extern emlrtRSInfo yl_emlrtRSI;
extern emlrtRSInfo gm_emlrtRSI;
extern emlrtRSInfo im_emlrtRSI;
extern emlrtRSInfo jm_emlrtRSI;
extern emlrtRSInfo lm_emlrtRSI;
extern emlrtRSInfo nm_emlrtRSI;
extern emlrtRSInfo om_emlrtRSI;
extern emlrtRSInfo pm_emlrtRSI;
extern emlrtRSInfo um_emlrtRSI;
extern emlrtRSInfo vm_emlrtRSI;
extern emlrtRSInfo ym_emlrtRSI;
extern emlrtRSInfo an_emlrtRSI;
extern emlrtRSInfo bn_emlrtRSI;
extern emlrtRSInfo cn_emlrtRSI;
extern emlrtRSInfo io_emlrtRSI;
extern emlrtRSInfo jo_emlrtRSI;
extern emlrtRSInfo ko_emlrtRSI;
extern emlrtRSInfo lo_emlrtRSI;
extern emlrtRSInfo no_emlrtRSI;
extern emlrtRSInfo ro_emlrtRSI;
extern emlrtRSInfo uo_emlrtRSI;
extern emlrtRSInfo vo_emlrtRSI;
extern emlrtRSInfo yo_emlrtRSI;
extern emlrtRSInfo ap_emlrtRSI;
extern emlrtRSInfo dr_emlrtRSI;
extern emlrtRSInfo ms_emlrtRSI;
extern emlrtRSInfo iu_emlrtRSI;
extern emlrtRSInfo ju_emlrtRSI;
extern emlrtRSInfo ku_emlrtRSI;
extern emlrtRSInfo lu_emlrtRSI;
extern emlrtRSInfo mu_emlrtRSI;
extern emlrtRSInfo nu_emlrtRSI;
extern emlrtRSInfo pu_emlrtRSI;
extern emlrtRSInfo ay_emlrtRSI;
extern emlrtRSInfo dy_emlrtRSI;
extern emlrtRSInfo ey_emlrtRSI;
extern emlrtRSInfo qy_emlrtRSI;
extern emlrtRSInfo ty_emlrtRSI;
extern emlrtRSInfo uy_emlrtRSI;
extern emlrtRSInfo vy_emlrtRSI;
extern emlrtRSInfo wy_emlrtRSI;
extern emlrtRSInfo eab_emlrtRSI;
extern emlrtRSInfo fab_emlrtRSI;
extern emlrtRSInfo gab_emlrtRSI;
extern emlrtMCInfo c_emlrtMCI;
extern emlrtRTEInfo emlrtRTEI;
extern emlrtRTEInfo b_emlrtRTEI;
extern emlrtRTEInfo c_emlrtRTEI;
extern emlrtRTEInfo e_emlrtRTEI;
extern emlrtRTEInfo f_emlrtRTEI;
extern emlrtRTEInfo g_emlrtRTEI;
extern emlrtECInfo d_emlrtECI;
extern emlrtECInfo e_emlrtECI;
extern emlrtECInfo f_emlrtECI;
extern emlrtECInfo g_emlrtECI;
extern emlrtECInfo h_emlrtECI;
extern emlrtECInfo i_emlrtECI;
extern emlrtECInfo j_emlrtECI;
extern emlrtECInfo k_emlrtECI;
extern emlrtRTEInfo j_emlrtRTEI;
extern emlrtBCInfo p_emlrtBCI;
extern emlrtBCInfo q_emlrtBCI;
extern emlrtBCInfo r_emlrtBCI;
extern emlrtBCInfo s_emlrtBCI;
extern emlrtRTEInfo l_emlrtRTEI;
extern emlrtDCInfo e_emlrtDCI;
extern emlrtRTEInfo p_emlrtRTEI;
extern emlrtRTEInfo s_emlrtRTEI;
extern emlrtRTEInfo u_emlrtRTEI;
extern emlrtRTEInfo v_emlrtRTEI;
extern emlrtRTEInfo ab_emlrtRTEI;
extern emlrtRTEInfo bb_emlrtRTEI;
extern emlrtRTEInfo db_emlrtRTEI;
extern emlrtRTEInfo eb_emlrtRTEI;
extern emlrtRTEInfo kb_emlrtRTEI;
extern emlrtRTEInfo lb_emlrtRTEI;
extern emlrtRTEInfo mb_emlrtRTEI;
extern emlrtRTEInfo tb_emlrtRTEI;
extern emlrtRTEInfo ub_emlrtRTEI;
extern emlrtRTEInfo yb_emlrtRTEI;
extern emlrtRTEInfo lc_emlrtRTEI;
extern emlrtRTEInfo xc_emlrtRTEI;
extern emlrtRTEInfo yc_emlrtRTEI;
extern emlrtRTEInfo ad_emlrtRTEI;
extern emlrtRTEInfo bd_emlrtRTEI;
extern emlrtRTEInfo cd_emlrtRTEI;
extern emlrtRTEInfo dd_emlrtRTEI;
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
extern emlrtRTEInfo re_emlrtRTEI;
extern emlrtRTEInfo se_emlrtRTEI;
extern emlrtRTEInfo te_emlrtRTEI;
extern emlrtRTEInfo ue_emlrtRTEI;
extern emlrtRTEInfo ye_emlrtRTEI;
extern emlrtRTEInfo if_emlrtRTEI;
extern emlrtRTEInfo mf_emlrtRTEI;
extern emlrtRTEInfo pf_emlrtRTEI;
extern emlrtRTEInfo qf_emlrtRTEI;
extern emlrtRTEInfo rf_emlrtRTEI;
extern emlrtRTEInfo sf_emlrtRTEI;
extern emlrtRTEInfo tf_emlrtRTEI;
extern emlrtRTEInfo uf_emlrtRTEI;
extern emlrtRTEInfo dg_emlrtRTEI;
extern emlrtRTEInfo hh_emlrtRTEI;
extern emlrtRTEInfo ih_emlrtRTEI;
extern emlrtRTEInfo uj_emlrtRTEI;
extern emlrtRTEInfo yj_emlrtRTEI;
extern emlrtRTEInfo al_emlrtRTEI;
extern emlrtRTEInfo nl_emlrtRTEI;
extern emlrtRTEInfo yn_emlrtRTEI;
extern emlrtRTEInfo ur_emlrtRTEI;
extern emlrtRTEInfo vr_emlrtRTEI;
extern emlrtRTEInfo bs_emlrtRTEI;
extern const real_T dv[841];
extern const char_T cv[14];
extern const char_T cv1[14];
extern const char_T cv2[14];
extern emlrtRSInfo beb_emlrtRSI;
extern covrtInstance emlrtCoverageInstance;

// End of code generation (ComputeCamExtrinsics_mex_data.h)
