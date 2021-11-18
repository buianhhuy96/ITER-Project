//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: my_nlparci.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "my_nlparci.h"
#include "calibrateCamera_rtwutil.h"
#include "cat1.h"
#include "eml_betainc.h"
#include "find.h"
#include "gammaln.h"
#include "mldivide.h"
#include "norm.h"
#include "qr.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// NLPARCI Confidence intervals for parameters in nonlinear regression.
//    CI = NLPARCI(BETA,RESID,'covar',SIGMA) returns 95% confidence intervals
//    CI for the nonlinear least squares parameter estimates BETA.   Before
//    calling NLPARCI, use NLINFIT to fit a nonlinear regression model
//    and get the coefficient estimates BETA, residuals RESID, and estimated
//    coefficient covariance matrix SIGMA.
//
//    CI = NLPARCI(BETA,RESID,'jacobian',J) is an alternative syntax that
//    also computes 95% confidence intervals.  J is the Jacobian computed by
//    NLINFIT.  You should use the 'covar' input rather than the 'jacobian'
//    input if you use a robust option with NLINFIT, because the SIGMA
//    parameter is required to take the robust fitting into account.
//
//    CI = NLPARCI(...,'alpha',ALPHA) returns 100(1-ALPHA) percent
//    confidence intervals.
//
//    NLPARCI treats NaNs in RESID or J as missing values, and ignores the
//    corresponding observations.
//
//    The confidence interval calculation is valid when the length of RESID
//    exceeds the length of BETA, and J has full column rank.  When J is
//    ill-conditioned, confidence intervals may be inaccurate.
//
//    Example:
//       load reaction;
//       [beta,resid,J,Sigma] = nlinfit(reactants,rate,@hougen,beta);
//       ci = nlparci(beta,resid,'covar',Sigma);
//
//    See also NLINFIT, NLPREDCI, NLINTOOL.
//
// Arguments    : const ::coder::array<real_T, 1U> &beta
//                ::coder::array<real_T, 1U> &resid
//                const ::coder::array<real_T, 2U> &b_jacobian
//                ::coder::array<real_T, 2U> &b_ci
// Return Type  : void
//
namespace Codegen {
void my_nlparci(const ::coder::array<real_T, 1U> &beta,
                ::coder::array<real_T, 1U> &resid,
                const ::coder::array<real_T, 2U> &b_jacobian,
                ::coder::array<real_T, 2U> &b_ci)
{
  ::coder::array<real_T, 2U> b_J;
  ::coder::array<real_T, 2U> b_R;
  ::coder::array<real_T, 2U> temp;
  ::coder::array<real_T, 2U> z1;
  ::coder::array<real_T, 1U> bsum;
  ::coder::array<real_T, 1U> delta;
  ::coder::array<int32_T, 2U> r;
  ::coder::array<int32_T, 1U> r1;
  ::coder::array<boolean_T, 2U> b_temp;
  ::coder::array<boolean_T, 1U> missing;
  real_T b;
  real_T b_a;
  real_T b_t;
  real_T oldf;
  real_T oldz;
  int32_T b_i;
  int32_T b_k;
  int32_T b_v;
  int32_T d_i;
  int32_T g_n;
  int32_T k;
  int32_T k0;
  int32_T lastBlockLength;
  int32_T nxin;
  int32_T nxout;
  uint32_T sz_idx_0;
  boolean_T guard1{false};
  //  Old syntax still supported:
  //     CI = NLPARCI(BETA,RESID,J,ALPHA)
  //    To compute confidence intervals when the parameters or data are complex,
  //    you will need to split the problem into its real and imaginary parts.
  //    First, define your parameter vector BETA as the concatenation of the
  //    real and imaginary parts of the original parameter vector.  Then
  //    concatenate the real and imaginary parts of the response vector Y as a
  //    single vector. Finally, modify your model function MODELFUN to accept X
  //    and the purely real parameter vector, and return a concatenation of the
  //    real and imaginary parts of the fitted values.  Given this formulation
  //    of the problem, NLINFIT will compute purely real estimates, and
  //    confidence intervals are feasible. References:
  //       [1] Seber, G.A.F, and Wild, C.J. (1989) Nonlinear Regression, Wiley.
  //    Copyright 1993-2009 The MathWorks, Inc.
  //  Remove missing values.
  missing.set_size(resid.size(0));
  nxin = resid.size(0);
  for (b_i = 0; b_i < nxin; b_i++) {
    missing[b_i] = std::isnan(resid[b_i]);
  }
  if (missing.size(0) != 0) {
    nxin = resid.size(0);
    g_n = 0;
    b_i = missing.size(0);
    for (k = 0; k < b_i; k++) {
      g_n += static_cast<int32_T>(missing[k]);
    }
    nxout = resid.size(0) - g_n;
    k0 = -1;
    for (k = 0; k < nxin; k++) {
      guard1 = false;
      if ((k + 1) > missing.size(0)) {
        guard1 = true;
      } else if (!missing[k]) {
        guard1 = true;
      } else {
        /* no actions */
      }
      if (guard1) {
        k0++;
        resid[k0] = resid[k];
      }
    }
    if (1 > nxout) {
      nxout = 0;
    }
    resid.set_size(nxout);
  }
  b_v = resid.size(0) - beta.size(0);
  //  Estimate covariance from J and residuals
  b_J.set_size(b_jacobian.size(0), b_jacobian.size(1));
  nxin = b_jacobian.size(1);
  for (b_i = 0; b_i < nxin; b_i++) {
    nxout = b_jacobian.size(0);
    for (g_n = 0; g_n < nxout; g_n++) {
      b_J[g_n + (b_J.size(0) * b_i)] =
          b_jacobian[g_n + (b_jacobian.size(0) * b_i)];
    }
  }
  k0 = b_jacobian.size(0);
  nxin = b_jacobian.size(1);
  g_n = 0;
  b_i = missing.size(0);
  for (k = 0; k < b_i; k++) {
    g_n += static_cast<int32_T>(missing[k]);
  }
  nxout = b_jacobian.size(0) - g_n;
  d_i = 0;
  for (k = 0; k < k0; k++) {
    guard1 = false;
    if ((k + 1) > missing.size(0)) {
      guard1 = true;
    } else if (!missing[k]) {
      guard1 = true;
    } else {
      /* no actions */
    }
    if (guard1) {
      for (lastBlockLength = 0; lastBlockLength < nxin; lastBlockLength++) {
        b_J[d_i + (b_J.size(0) * lastBlockLength)] =
            b_J[k + (b_J.size(0) * lastBlockLength)];
      }
      d_i++;
    }
  }
  if (1 > nxout) {
    nxin = 0;
  } else {
    nxin = nxout;
  }
  nxout = b_J.size(1) - 1;
  for (b_i = 0; b_i <= nxout; b_i++) {
    for (g_n = 0; g_n < nxin; g_n++) {
      b_J[g_n + (nxin * b_i)] = b_J[g_n + (b_J.size(0) * b_i)];
    }
  }
  b_J.set_size(nxin, nxout + 1);
  //  Approximation when a column is zero vector
  z1.set_size(nxin, nxout + 1);
  if (nxin != 0) {
    b_i = nxout + 1;
    for (k = 0; k < b_i; k++) {
      g_n = z1.size(0);
      for (b_k = 0; b_k < g_n; b_k++) {
        z1[b_k + (z1.size(0) * k)] = std::abs(b_J[b_k + (b_J.size(0) * k)]);
      }
    }
  }
  nxout = z1.size(0);
  g_n = z1.size(1);
  temp.set_size(1, z1.size(1));
  for (lastBlockLength = 0; lastBlockLength < g_n; lastBlockLength++) {
    temp[lastBlockLength] = z1[z1.size(0) * lastBlockLength];
    for (d_i = 2; d_i <= nxout; d_i++) {
      boolean_T p;
      b_a = temp[lastBlockLength];
      b = z1[(d_i + (z1.size(0) * lastBlockLength)) - 1];
      if (std::isnan(b)) {
        p = false;
      } else if (std::isnan(b_a)) {
        p = true;
      } else {
        p = (b_a < b);
      }
      if (p) {
        temp[lastBlockLength] = b;
      }
    }
  }
  b_temp.set_size(1, temp.size(1));
  nxout = temp.size(1);
  for (b_i = 0; b_i < nxout; b_i++) {
    b_temp[b_i] = (temp[b_i] == 0.0);
  }
  coder::b_eml_find(b_temp, r);
  temp.set_size(1, r.size(1));
  nxout = r.size(1);
  for (b_i = 0; b_i < nxout; b_i++) {
    temp[b_i] = static_cast<real_T>(r[b_i]);
  }
  if (temp.size(1) != 0) {
    r1.set_size(temp.size(1));
    nxout = temp.size(1);
    for (b_i = 0; b_i < nxout; b_i++) {
      r1[b_i] = static_cast<int32_T>(temp[b_i]);
    }
    nxout = r1.size(0);
    for (b_i = 0; b_i < nxout; b_i++) {
      for (g_n = 0; g_n < nxin; g_n++) {
        b_J[g_n + (b_J.size(0) * (r1[b_i] - 1))] = 1.4901161193847656E-8;
      }
    }
  }
  //  Calculate covariance matrix
  coder::qr(b_J, z1, b_R);
  sz_idx_0 = static_cast<uint32_T>(b_R.size(0));
  nxout = b_R.size(0);
  k0 = b_R.size(1);
  if (nxout <= k0) {
    k0 = nxout;
  }
  z1.set_size(b_R.size(0), b_R.size(1));
  nxin = b_R.size(1);
  for (b_i = 0; b_i < nxin; b_i++) {
    nxout = static_cast<int32_T>(sz_idx_0);
    for (g_n = 0; g_n < nxout; g_n++) {
      z1[g_n + (z1.size(0) * b_i)] = 0.0;
    }
  }
  if (k0 > 0) {
    for (k = 0; k < k0; k++) {
      z1[k + (z1.size(0) * k)] = 1.0;
    }
  }
  coder::mldivide(b_R, z1, b_J);
  b = coder::b_norm(resid) / std::sqrt(static_cast<real_T>(b_v));
  //  Calculate confidence interval
  if (b_v > 0) {
    if (b_v == 1) {
      b_t = 12.706204736174696;
    } else if (b_v < 1000) {
      real_T lbeta;
      real_T zhi;
      real_T zlo;
      boolean_T exitg1;
      b_a = (static_cast<real_T>(b_v)) / 2.0;
      oldz = b_a;
      coder::gammaln(&oldz);
      b_t = 0.5;
      coder::gammaln(&b_t);
      oldf = b_a + 0.5;
      coder::gammaln(&oldf);
      lbeta = (oldz + b_t) - oldf;
      b_t = (((4.0 * b_a) + 1.0) - 2.0) / 3.7455314379458984;
      if (b_t > 1.0) {
        b_t = 1.0 - (2.0 / (b_t + 1.0));
      } else {
        b_t = std::exp((std::log(0.050000000000000044 * b_a) + lbeta) / b_a);
      }
      b_t = std::fmin(std::fmax(b_t, 0.0001), 0.9999);
      oldf = rtInf;
      oldz = rtInf;
      zlo = 0.0;
      zhi = 1.0;
      d_i = 0;
      exitg1 = false;
      while ((!exitg1) && (d_i < 1000)) {
        real_T f;
        f = coder::eml_betainc(b_t, b_a, lbeta) - 0.050000000000000044;
        if ((f * oldf) < 0.0) {
          if (std::abs(oldf) <= std::abs(f)) {
            b_t = 0.5 * (b_t + oldz);
            f = coder::eml_betainc(b_t, b_a, lbeta) - 0.050000000000000044;
          }
        }
        if (f > 0.0) {
          zhi = b_t;
        } else {
          zlo = b_t;
        }
        if (std::abs(f) < 1.1102230246251575E-15) {
          exitg1 = true;
        } else if (std::abs(b_t - oldz) <
                   ((2.2204460492503131E-16 * b_t) + 2.2250738585072014E-308)) {
          exitg1 = true;
        } else {
          boolean_T b_guard1{false};
          boolean_T guard2{false};
          b_guard1 = false;
          guard2 = false;
          if (d_i < 200) {
            real_T log1mz;
            oldz = b_t;
            oldf = f;
            if ((1.0 - b_t) != 1.0) {
              log1mz = std::log(1.0 - b_t) * ((-b_t) / ((1.0 - b_t) - 1.0));
            } else {
              log1mz = -b_t;
            }
            b_t -=
                f / std::exp((((b_a - 1.0) * std::log(b_t)) + (-0.5 * log1mz)) -
                             lbeta);
            if (b_t <= zlo) {
              if (zlo == 0.0) {
                if (0.050000000000000044 <
                    std::abs(coder::eml_betainc(2.2250738585072014E-308, b_a,
                                                lbeta) -
                             0.050000000000000044)) {
                  b_t = 0.0;
                  exitg1 = true;
                } else {
                  zlo = 2.2250738585072014E-308;
                  guard2 = true;
                }
              } else {
                guard2 = true;
              }
            } else if (b_t >= zhi) {
              if (zhi == 1.0) {
                if (0.95 < std::abs(coder::eml_betainc(0.99999999999999989, b_a,
                                                       lbeta) -
                                    0.050000000000000044)) {
                  b_t = 1.0;
                  exitg1 = true;
                } else {
                  zhi = 0.99999999999999989;
                  b_guard1 = true;
                }
              } else {
                b_guard1 = true;
              }
            } else {
              d_i++;
            }
          } else {
            b_t = 0.5 * (zlo + zhi);
            d_i++;
          }
          if (guard2) {
            b_t = (0.99 * zlo) + (0.01 * zhi);
            d_i++;
          }
          if (b_guard1) {
            b_t = (0.01 * zlo) + (0.99 * zhi);
            d_i++;
          }
        }
      }
      b_t = std::sqrt((static_cast<real_T>(b_v)) * ((1.0 - b_t) / b_t));
    } else {
      b_t = ((((9.4890849211942481 / (4.0 * (static_cast<real_T>(b_v)))) +
               1.959963984540054) +
              (270.95986711100267 / (96.0 * ((static_cast<real_T>(b_v)) *
                                             (static_cast<real_T>(b_v)))))) +
             (981.44627693096527 /
              (384.0 * rt_powd_snf(static_cast<real_T>(b_v), 3.0)))) +
            (146491.45836077468 /
             (92160.0 * rt_powd_snf(static_cast<real_T>(b_v), 4.0)));
    }
  } else {
    b_t = rtNaN;
  }
  nxin = b_J.size(1);
  for (b_i = 0; b_i < nxin; b_i++) {
    nxout = b_J.size(0);
    for (g_n = 0; g_n < nxout; g_n++) {
      oldz = b_J[g_n + (b_J.size(0) * b_i)];
      oldz *= oldz;
      b_J[g_n + (b_J.size(0) * b_i)] = oldz;
    }
  }
  g_n = b_J.size(1);
  if ((b_J.size(0) == 0) || (b_J.size(1) == 0)) {
    delta.set_size(b_J.size(0));
    nxin = b_J.size(0);
    for (b_i = 0; b_i < nxin; b_i++) {
      delta[b_i] = 0.0;
    }
  } else {
    delta.set_size(b_J.size(0));
    bsum.set_size(b_J.size(0));
    if (b_J.size(1) <= 1024) {
      nxout = b_J.size(1);
      lastBlockLength = 0;
      d_i = 1;
    } else {
      nxout = 1024;
      d_i = b_J.size(1) / 1024;
      lastBlockLength = b_J.size(1) - (d_i * 1024);
      if (lastBlockLength > 0) {
        d_i++;
      } else {
        lastBlockLength = 1024;
      }
    }
    b_i = b_J.size(0);
    for (k = 0; k < b_i; k++) {
      delta[k] = b_J[k];
    }
    for (k = 2; k <= nxout; k++) {
      b_i = b_J.size(0);
      for (b_k = 0; b_k < b_i; b_k++) {
        if (g_n >= 2) {
          delta[b_k] = delta[b_k] + b_J[b_k + (b_J.size(0) * (k - 1))];
        }
      }
    }
    for (b_v = 2; b_v <= d_i; b_v++) {
      nxout = (b_v - 1) * 1024;
      b_i = b_J.size(0);
      for (k = 0; k < b_i; k++) {
        bsum[k] = b_J[k + (b_J.size(0) * nxout)];
      }
      if (b_v == d_i) {
        k0 = lastBlockLength;
      } else {
        k0 = 1024;
      }
      for (k = 2; k <= k0; k++) {
        nxin = nxout + k;
        b_i = b_J.size(0);
        for (b_k = 0; b_k < b_i; b_k++) {
          if (g_n >= 2) {
            bsum[b_k] = bsum[b_k] + b_J[b_k + (b_J.size(0) * (nxin - 1))];
          }
        }
      }
      b_i = delta.size(0);
      for (k = 0; k < b_i; k++) {
        delta[k] = delta[k] + bsum[k];
      }
    }
  }
  b_i = delta.size(0);
  for (k = 0; k < b_i; k++) {
    delta[k] = std::sqrt(delta[k]);
  }
  nxin = delta.size(0);
  for (b_i = 0; b_i < nxin; b_i++) {
    delta[b_i] = (delta[b_i] * b) * b_t;
  }
  if (beta.size(0) == delta.size(0)) {
    b_ci.set_size(beta.size(0), 2);
    nxin = beta.size(0);
    for (b_i = 0; b_i < nxin; b_i++) {
      b_ci[b_i] = beta[b_i] - delta[b_i];
    }
    nxin = beta.size(0);
    for (b_i = 0; b_i < nxin; b_i++) {
      b_ci[b_i + b_ci.size(0)] = beta[b_i] + delta[b_i];
    }
  } else {
    b_binary_expand_op(b_ci, beta, delta);
  }
}

} // namespace Codegen

//
// File trailer for my_nlparci.cpp
//
// [EOF]
//
