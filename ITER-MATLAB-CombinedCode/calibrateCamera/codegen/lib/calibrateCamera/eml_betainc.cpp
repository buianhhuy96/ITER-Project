//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_betainc.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "eml_betainc.h"
#include "calibrateCamera_rtwutil.h"
#include "gammaln.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Declarations
namespace Codegen {
namespace coder {
static real_T betainc_cf(real_T b_x, real_T b_a, real_T b);

}
} // namespace Codegen

// Function Definitions
//
// Arguments    : real_T b_x
//                real_T b_a
//                real_T b
// Return Type  : real_T
//
namespace Codegen {
namespace coder {
static real_T betainc_cf(real_T b_x, real_T b_a, real_T b)
{
  real_T Dinv;
  real_T aplusb;
  real_T b_C;
  real_T y;
  int32_T m;
  aplusb = b_a + b;
  b_C = 1.0;
  Dinv = 1.0 - ((aplusb * b_x) / (b_a + 1.0));
  y = 1.0 / Dinv;
  m = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (m < 1000) {
      real_T d;
      real_T d_tmp;
      real_T yold;
      int32_T twom;
      yold = y;
      twom = (m + 1) * 2;
      d_tmp = b_a + (static_cast<real_T>(twom));
      d = ((((static_cast<real_T>(m)) + 1.0) *
            (b - ((static_cast<real_T>(m)) + 1.0))) *
           b_x) /
          (((b_a - 1.0) + (static_cast<real_T>(twom))) * d_tmp);
      b_C = (d / b_C) + 1.0;
      Dinv = (d / Dinv) + 1.0;
      y *= b_C / Dinv;
      d = (((-(b_a + ((static_cast<real_T>(m)) + 1.0))) *
            (aplusb + ((static_cast<real_T>(m)) + 1.0))) *
           b_x) /
          (d_tmp * ((b_a + 1.0) + (static_cast<real_T>(twom))));
      b_C = (d / b_C) + 1.0;
      Dinv = (d / Dinv) + 1.0;
      y *= b_C / Dinv;
      if (std::abs(y - yold) < 2.2204460492503131E-15) {
        exitg1 = 1;
      } else {
        m++;
      }
    } else {
      y = rtNaN;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return y;
}

//
// Arguments    : real_T b_x
//                real_T b_a
//                real_T lbeta
// Return Type  : real_T
//
real_T eml_betainc(real_T b_x, real_T b_a, real_T lbeta)
{
  real_T logx;
  real_T rval;
  if ((0.0 < b_x) && (b_x < 1.0)) {
    if (std::isinf(b_a)) {
      rval = 0.0;
    } else {
      real_T log1mx;
      boolean_T guard1{false};
      guard1 = false;
      if ((b_a + 0.5) < 1.0E+7) {
        logx = std::log(b_x);
        if ((1.0 - b_x) != 1.0) {
          log1mx = std::log(1.0 - b_x) * ((-b_x) / ((1.0 - b_x) - 1.0));
        } else {
          log1mx = -b_x;
        }
        if (b_x < ((b_a + 1.0) / ((b_a + 0.5) + 2.0))) {
          rval = std::exp((((b_a * logx) + (0.5 * log1mx)) - std::log(b_a)) -
                          lbeta) *
                 betainc_cf(b_x, b_a, 0.5);
        } else {
          rval = 1.0 - (std::exp((((b_a * logx) + (0.5 * log1mx)) -
                                  -0.69314718055994529) -
                                 lbeta) *
                        betainc_cf(1.0 - b_x, 0.5, b_a));
        }
        if (!(rval == rval)) {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        logx = rt_powd_snf(0.5 * b_x, 0.33333333333333331);
        log1mx = rt_powd_snf(b_a * (1.0 - b_x), 0.33333333333333331);
        if ((((b_a + 0.5) - 1.0) * (1.0 - b_x)) > 0.8) {
          real_T b_t;
          real_T c_x;
          c_x =
              0.70710678118654746 *
              (-((3.0 * ((0.77777777777777779 * logx) -
                         ((1.0 - (1.0 / (9.0 * b_a))) * log1mx))) /
                 std::sqrt(((logx * logx) / 0.5) + ((log1mx * log1mx) / b_a))));
          b_t = 3.97886080735226 / (std::abs(c_x) + 3.97886080735226);
          rval =
              ((0.5 *
                ((((((((((((((((((((((((((((((((((((((((((((0.0012710976495261409 *
                                                            (b_t - 0.5)) +
                                                           0.00011931402283834095) *
                                                          (b_t - 0.5)) +
                                                         -0.0039638509736051354) *
                                                        (b_t - 0.5)) +
                                                       -0.00087077963531729586) *
                                                      (b_t - 0.5)) +
                                                     0.0077367252831352668) *
                                                    (b_t - 0.5)) +
                                                   0.0038333512626488732) *
                                                  (b_t - 0.5)) +
                                                 -0.012722381378212275) *
                                                (b_t - 0.5)) +
                                               -0.013382364453346007) *
                                              (b_t - 0.5)) +
                                             0.016131532973325226) *
                                            (b_t - 0.5)) +
                                           0.039097684558848406) *
                                          (b_t - 0.5)) +
                                         0.0024936720005350331) *
                                        (b_t - 0.5)) +
                                       -0.0838864557023002) *
                                      (b_t - 0.5)) +
                                     -0.11946395996432542) *
                                    (b_t - 0.5)) +
                                   0.016620792496936737) *
                                  (b_t - 0.5)) +
                                 0.35752427444953105) *
                                (b_t - 0.5)) +
                               0.80527640875291062) *
                              (b_t - 0.5)) +
                             1.1890298290927332) *
                            (b_t - 0.5)) +
                           1.3704021768233816) *
                          (b_t - 0.5)) +
                         1.313146538310231) *
                        (b_t - 0.5)) +
                       1.0792551515585667) *
                      (b_t - 0.5)) +
                     0.77436819911953858) *
                    (b_t - 0.5)) +
                   0.49016508058531844) *
                  (b_t - 0.5)) +
                 0.27537474159737679)) *
               b_t) *
              std::exp((-c_x) * c_x);
          if (c_x < 0.0) {
            rval = 1.0 - rval;
          }
        } else {
          real_T c_x;
          c_x = (0.5 * ((((b_a + 0.5) - 1.0) * (3.0 - b_x)) - -0.5)) *
                (1.0 - b_x);
          if (!(c_x > 0.0)) {
            if (c_x == 0.0) {
              rval = 1.0;
            } else {
              rval = rtNaN;
            }
          } else if (std::isinf(c_x)) {
            rval = 0.0;
          } else {
            real_T b_t;
            real_T old;
            real_T term;
            real_T xD0;
            int32_T exitg1;
            if (std::abs(0.5 - c_x) > (0.1 * (c_x + 0.5))) {
              if (0.5 < (2.2250738585072014E-308 * c_x)) {
                xD0 = c_x;
              } else if ((c_x < 1.0) &&
                         (0.5 > (1.7976931348623157E+308 * c_x))) {
                xD0 = (-0.34657359027997264 - (0.5 * std::log(c_x))) - 0.5;
              } else {
                xD0 = ((0.5 * std::log(0.5 / c_x)) + c_x) - 0.5;
              }
            } else {
              b_t = c_x / 0.5;
              logx = (1.0 - b_t) / (b_t + 1.0);
              log1mx = logx * logx;
              xD0 = (0.5 - c_x) * logx;
              old = xD0;
              term = 2.0 * (0.5 * logx);
              logx = 3.0;
              do {
                exitg1 = 0;
                term *= log1mx;
                xD0 += term / logx;
                if (xD0 == old) {
                  exitg1 = 1;
                } else {
                  old = xD0;
                  logx += 2.0;
                }
              } while (exitg1 == 0);
            }
            if (c_x > 1.0E+6) {
              real_T sqrtx;
              real_T tsq;
              sqrtx = std::sqrt(c_x);
              b_t = std::abs((0.5 - c_x) - 1.0) / sqrtx;
              tsq = b_t * b_t;
              if (b_t < 15.0) {
                logx = 0.70710678118654746 * b_t;
                log1mx = 3.97886080735226 / (logx + 3.97886080735226);
                log1mx =
                    ((((0.5 *
                        ((((((((((((((((((((((((((((((((((((((((((((0.0012710976495261409 *
                                                                    (log1mx -
                                                                     0.5)) +
                                                                   0.00011931402283834095) *
                                                                  (log1mx -
                                                                   0.5)) +
                                                                 -0.0039638509736051354) *
                                                                (log1mx -
                                                                 0.5)) +
                                                               -0.00087077963531729586) *
                                                              (log1mx - 0.5)) +
                                                             0.0077367252831352668) *
                                                            (log1mx - 0.5)) +
                                                           0.0038333512626488732) *
                                                          (log1mx - 0.5)) +
                                                         -0.012722381378212275) *
                                                        (log1mx - 0.5)) +
                                                       -0.013382364453346007) *
                                                      (log1mx - 0.5)) +
                                                     0.016131532973325226) *
                                                    (log1mx - 0.5)) +
                                                   0.039097684558848406) *
                                                  (log1mx - 0.5)) +
                                                 0.0024936720005350331) *
                                                (log1mx - 0.5)) +
                                               -0.0838864557023002) *
                                              (log1mx - 0.5)) +
                                             -0.11946395996432542) *
                                            (log1mx - 0.5)) +
                                           0.016620792496936737) *
                                          (log1mx - 0.5)) +
                                         0.35752427444953105) *
                                        (log1mx - 0.5)) +
                                       0.80527640875291062) *
                                      (log1mx - 0.5)) +
                                     1.1890298290927332) *
                                    (log1mx - 0.5)) +
                                   1.3704021768233816) *
                                  (log1mx - 0.5)) +
                                 1.313146538310231) *
                                (log1mx - 0.5)) +
                               1.0792551515585667) *
                              (log1mx - 0.5)) +
                             0.77436819911953858) *
                            (log1mx - 0.5)) +
                           0.49016508058531844) *
                          (log1mx - 0.5)) +
                         0.27537474159737679)) *
                       log1mx) *
                      std::exp((-logx) * logx)) *
                     2.5066282746310002) *
                    std::exp(0.5 * tsq);
                old = ((log1mx * ((tsq - 3.0) * b_t)) - (tsq - 4.0)) / 6.0;
                term = ((log1mx * ((((tsq * tsq) - 9.0) * tsq) + 6.0)) -
                        ((((tsq - 1.0) * tsq) - 6.0) * b_t)) /
                       72.0;
                logx = ((log1mx *
                         (((((((((5.0 * tsq) + 45.0) * tsq) - 81.0) * tsq) -
                             315.0) *
                            tsq) +
                           270.0) *
                          b_t)) -
                        ((((((((5.0 * tsq) + 40.0) * tsq) - 111.0) * tsq) -
                           174.0) *
                          tsq) +
                         192.0)) /
                       6480.0;
              } else {
                log1mx =
                    (((((3.0 - (15.0 / tsq)) / tsq) + -1.0) / tsq) + 1.0) / b_t;
                old = (((((25.0 - (210.0 / tsq)) / tsq) + -4.0) / tsq) + 1.0) /
                      tsq;
                term =
                    (((((130.0 - (1750.0 / tsq)) / tsq) + -11.0) / tsq) + 1.0) /
                    (tsq * b_t);
                logx = (((((546.0 - (11368.0 / tsq)) / tsq) + -26.0) / tsq) +
                        1.0) /
                       (tsq * tsq);
              }
              logx =
                  0.5 *
                  ((((log1mx / sqrtx) + (old / c_x)) + (term / (c_x * sqrtx))) +
                   (logx / (c_x * c_x)));
              if ((-0.72579135264472727 - xD0) < 709.782712893384) {
                rval = std::exp(-0.72579135264472727 - xD0) * logx;
              } else {
                rval = std::exp((-0.72579135264472727 - xD0) + std::log(logx));
              }
            } else if (c_x < 1.0) {
              logx = 0.5 * (-c_x);
              old = logx / 1.5;
              log1mx = 2.0;
              do {
                exitg1 = 0;
                logx = ((-c_x) * logx) / log1mx;
                term = logx / (log1mx + 0.5);
                old += term;
                if (std::abs(term) <=
                    (std::abs(old) * 2.2204460492503131E-16)) {
                  exitg1 = 1;
                } else {
                  log1mx++;
                }
              } while (exitg1 == 0);
              logx = 0.5;
              gammaln(&logx);
              logx = (0.5 * std::log(c_x)) - logx;
              log1mx = std::exp(logx);
              if ((log1mx - 1.0) == -1.0) {
                logx = -1.0;
              } else {
                logx = ((log1mx - 1.0) * logx) / std::log(log1mx);
              }
              rval = -((old + logx) + (old * logx));
              if (rval < 0.0) {
                rval = 0.0;
              }
            } else {
              int32_T b_i;
              logx = 1.0;
              log1mx = 1.0;
              do {
                exitg1 = 0;
                b_i = static_cast<int32_T>(std::floor(c_x + 0.5));
                if ((static_cast<int32_T>(log1mx)) <= b_i) {
                  logx = ((0.5 - log1mx) * logx) / c_x;
                  if (std::abs(logx) < 2.2204460492503131E-16) {
                    exitg1 = 1;
                  } else {
                    log1mx++;
                  }
                } else {
                  exitg1 = 1;
                }
              } while (exitg1 == 0);
              if ((static_cast<int32_T>(log1mx)) <= b_i) {
                logx = 1.0;
              } else {
                logx = 0.70710678118654746 * std::sqrt(2.0 * c_x);
                b_t = 3.97886080735226 / (logx + 3.97886080735226);
                logx =
                    (std::sqrt(3.1415926535897931 * c_x) * std::exp(c_x)) *
                    (2.0 *
                     (((0.5 *
                        ((((((((((((((((((((((((((((((((((((((((((((0.0012710976495261409 *
                                                                    (b_t -
                                                                     0.5)) +
                                                                   0.00011931402283834095) *
                                                                  (b_t - 0.5)) +
                                                                 -0.0039638509736051354) *
                                                                (b_t - 0.5)) +
                                                               -0.00087077963531729586) *
                                                              (b_t - 0.5)) +
                                                             0.0077367252831352668) *
                                                            (b_t - 0.5)) +
                                                           0.0038333512626488732) *
                                                          (b_t - 0.5)) +
                                                         -0.012722381378212275) *
                                                        (b_t - 0.5)) +
                                                       -0.013382364453346007) *
                                                      (b_t - 0.5)) +
                                                     0.016131532973325226) *
                                                    (b_t - 0.5)) +
                                                   0.039097684558848406) *
                                                  (b_t - 0.5)) +
                                                 0.0024936720005350331) *
                                                (b_t - 0.5)) +
                                               -0.0838864557023002) *
                                              (b_t - 0.5)) +
                                             -0.11946395996432542) *
                                            (b_t - 0.5)) +
                                           0.016620792496936737) *
                                          (b_t - 0.5)) +
                                         0.35752427444953105) *
                                        (b_t - 0.5)) +
                                       0.80527640875291062) *
                                      (b_t - 0.5)) +
                                     1.1890298290927332) *
                                    (b_t - 0.5)) +
                                   1.3704021768233816) *
                                  (b_t - 0.5)) +
                                 1.313146538310231) *
                                (b_t - 0.5)) +
                               1.0792551515585667) *
                              (b_t - 0.5)) +
                             0.77436819911953858) *
                            (b_t - 0.5)) +
                           0.49016508058531844) *
                          (b_t - 0.5)) +
                         0.27537474159737679)) *
                       b_t) *
                      std::exp((-logx) * logx)));
                log1mx = 1.0;
              }
              b_i = static_cast<int32_T>(log1mx);
              for (int32_T d_i{0}; d_i <= (b_i - 2); d_i++) {
                logx =
                    (((0.5 - ((log1mx - 1.0) + (-(static_cast<real_T>(d_i))))) *
                      logx) /
                     c_x) +
                    1.0;
              }
              logx = (logx * 0.5) / c_x;
              if ((-0.72579135264472727 - xD0) < 709.782712893384) {
                rval = std::exp(-0.72579135264472727 - xD0) * logx;
              } else {
                rval = std::exp((-0.72579135264472727 - xD0) + std::log(logx));
              }
              if (rval > 1.0) {
                rval = 1.0;
              }
            }
          }
        }
      }
    }
  } else if (b_x == 0.0) {
    rval = 0.0;
  } else if (b_x == 1.0) {
    rval = 1.0;
  } else {
    rval = rtNaN;
  }
  return rval;
}

} // namespace coder
} // namespace Codegen

//
// File trailer for eml_betainc.cpp
//
// [EOF]
//
