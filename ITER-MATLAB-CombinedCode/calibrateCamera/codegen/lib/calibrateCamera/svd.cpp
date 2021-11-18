//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                ::coder::array<real_T, 2U> &U
//                real_T s_data[]
//                int32_T *s_size
//                real_T V[6][6]
// Return Type  : void
//
namespace Codegen {
namespace coder {
namespace internal {
void b_svd(const ::coder::array<real_T, 2U> &A, ::coder::array<real_T, 2U> &U,
           real_T s_data[], int32_T *s_size, real_T V[6][6])
{
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> work;
  real_T b_s_data[6];
  real_T e[6];
  real_T f;
  real_T rt;
  real_T scale;
  real_T sqds;
  int32_T b_i;
  int32_T d_i;
  int32_T g_n;
  int32_T m;
  int32_T minnp;
  int32_T qjj;
  e_A.set_size(A.size(0), 6);
  b_i = A.size(0);
  for (d_i = 0; d_i < 6; d_i++) {
    for (m = 0; m < b_i; m++) {
      e_A[m + (e_A.size(0) * d_i)] = A[m + (A.size(0) * d_i)];
    }
  }
  g_n = A.size(0);
  minnp = A.size(0);
  if (minnp > 6) {
    minnp = 6;
  }
  b_i = A.size(0) + 1;
  if (b_i > 6) {
    b_i = 6;
  }
  if (0 <= (b_i - 1)) {
    (void)std::memset(&b_s_data[0], 0,
                      (static_cast<uint32_T>(b_i)) * (sizeof(real_T)));
  }
  for (b_i = 0; b_i < 6; b_i++) {
    e[b_i] = 0.0;
  }
  work.set_size(A.size(0));
  b_i = A.size(0);
  for (d_i = 0; d_i < b_i; d_i++) {
    work[d_i] = 0.0;
  }
  U.set_size(A.size(0), A.size(0));
  b_i = A.size(0);
  for (d_i = 0; d_i < b_i; d_i++) {
    qjj = A.size(0);
    for (m = 0; m < qjj; m++) {
      U[m + (U.size(0) * d_i)] = 0.0;
    }
  }
  (void)std::memset(&V[0][0], 0, 36U * (sizeof(real_T)));
  if (A.size(0) == 0) {
    for (int32_T b_ii{0}; b_ii < 6; b_ii++) {
      V[b_ii][b_ii] = 1.0;
    }
  } else {
    real_T nrm;
    real_T snorm;
    int32_T b_ii;
    int32_T b_iy;
    int32_T jj;
    int32_T k;
    int32_T nct;
    int32_T nctp1;
    int32_T nmq;
    int32_T nrt;
    int32_T q;
    int32_T qq;
    nrt = A.size(0);
    if (4 <= nrt) {
      nrt = 4;
    }
    nct = A.size(0) - 1;
    if (nct > 6) {
      nct = 6;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      d_i = nct;
    } else {
      d_i = nrt;
    }
    for (q = 0; q < d_i; q++) {
      boolean_T apply_transform;
      b_iy = q + 2;
      qq = (q + (g_n * q)) + 1;
      nmq = (g_n - q) - 1;
      apply_transform = false;
      if ((q + 1) <= nct) {
        nrm = blas::xnrm2(nmq + 1, e_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (e_A[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          b_s_data[q] = nrm;
          if (std::abs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            m = qq + nmq;
            for (k = qq; k <= m; k++) {
              e_A[k - 1] = nrm * e_A[k - 1];
            }
          } else {
            m = qq + nmq;
            for (k = qq; k <= m; k++) {
              e_A[k - 1] = e_A[k - 1] / b_s_data[q];
            }
          }
          e_A[qq - 1] = e_A[qq - 1] + 1.0;
          b_s_data[q] = -b_s_data[q];
        } else {
          b_s_data[q] = 0.0;
        }
      }
      for (jj = b_iy; jj < 7; jj++) {
        qjj = q + (g_n * (jj - 1));
        if (apply_transform) {
          nrm = 0.0;
          if ((nmq + 1) >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += e_A[(qq + k) - 1] * e_A[qjj + k];
            }
          }
          nrm = -(nrm / e_A[q + (e_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(nrm == 0.0))) {
            for (k = 0; k <= nmq; k++) {
              m = qjj + k;
              e_A[m] = e_A[m] + (nrm * e_A[(qq + k) - 1]);
            }
          }
        }
        e[jj - 1] = e_A[qjj];
      }
      if ((q + 1) <= nct) {
        for (b_ii = q + 1; b_ii <= g_n; b_ii++) {
          U[(b_ii + (U.size(0) * q)) - 1] = e_A[(b_ii + (e_A.size(0) * q)) - 1];
        }
      }
      if ((q + 1) <= nrt) {
        nrm = blas::c_xnrm2(5 - q, e, q + 2);
        if (nrm == 0.0) {
          e[q] = 0.0;
        } else {
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }
          nrm = e[q];
          if (std::abs(e[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e[q];
            for (k = b_iy; k < 7; k++) {
              e[k - 1] *= nrm;
            }
          } else {
            for (k = b_iy; k < 7; k++) {
              e[k - 1] /= nrm;
            }
          }
          e[q + 1]++;
          e[q] = -e[q];
          if ((q + 2) <= g_n) {
            for (b_ii = b_iy; b_ii <= g_n; b_ii++) {
              work[b_ii - 1] = 0.0;
            }
            for (jj = b_iy; jj < 7; jj++) {
              nrm = e[jj - 1];
              b_i = (q + (g_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                m = nmq - 1;
                for (k = 0; k <= m; k++) {
                  qjj = (q + k) + 1;
                  work[qjj] = work[qjj] + (nrm * e_A[(b_i + k) - 1]);
                }
              }
            }
            for (jj = b_iy; jj < 7; jj++) {
              nrm = (-e[jj - 1]) / e[q + 1];
              b_i = (q + (g_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                m = nmq - 1;
                for (k = 0; k <= m; k++) {
                  qjj = (b_i + k) - 1;
                  e_A[qjj] = e_A[qjj] + (nrm * work[(q + k) + 1]);
                }
              }
            }
          }
        }
        for (b_ii = b_iy; b_ii < 7; b_ii++) {
          V[q][b_ii - 1] = e[b_ii - 1];
        }
      }
    }
    if (6 <= (A.size(0) + 1)) {
      m = 5;
    } else {
      m = A.size(0);
    }
    if (nct < 6) {
      b_s_data[nct] = e_A[nct + (e_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      b_s_data[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = e_A[nrt + (e_A.size(0) * m)];
    }
    e[m] = 0.0;
    if ((nct + 1) <= A.size(0)) {
      for (jj = nctp1; jj <= g_n; jj++) {
        for (b_ii = 0; b_ii < g_n; b_ii++) {
          U[b_ii + (U.size(0) * (jj - 1))] = 0.0;
        }
        U[(jj + (U.size(0) * (jj - 1))) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      nmq = q + 1;
      b_i = g_n - q;
      qq = (q + (g_n * (q - 1))) - 1;
      if (b_s_data[q - 1] != 0.0) {
        for (jj = nmq; jj <= g_n; jj++) {
          qjj = q + (g_n * (jj - 1));
          nrm = 0.0;
          if ((b_i + 1) >= 1) {
            for (k = 0; k <= b_i; k++) {
              nrm += U[qq + k] * U[(qjj + k) - 1];
            }
          }
          nrm = -(nrm / U[qq]);
          blas::xaxpy(b_i + 1, nrm, qq + 1, U, qjj);
        }
        for (b_ii = q; b_ii <= g_n; b_ii++) {
          U[(b_ii + (U.size(0) * (q - 1))) - 1] =
              -U[(b_ii + (U.size(0) * (q - 1))) - 1];
        }
        U[qq] = U[qq] + 1.0;
        for (b_ii = 0; b_ii <= (q - 2); b_ii++) {
          U[b_ii + (U.size(0) * (q - 1))] = 0.0;
        }
      } else {
        for (b_ii = 0; b_ii < g_n; b_ii++) {
          U[b_ii + (U.size(0) * (q - 1))] = 0.0;
        }
        U[qq] = 1.0;
      }
    }
    for (q = 5; q >= 0; q--) {
      if (((q + 1) <= nrt) && (e[q] != 0.0)) {
        nmq = q + 2;
        b_i = (q + (6 * q)) + 2;
        for (jj = nmq; jj < 7; jj++) {
          qjj = (q + (6 * (jj - 1))) + 2;
          blas::b_xaxpy(
              5 - q,
              -(blas::xdotc(5 - q, V, b_i, V, qjj) / (&V[0][0])[b_i - 1]), b_i,
              V, qjj);
        }
      }
      for (b_ii = 0; b_ii < 6; b_ii++) {
        V[q][b_ii] = 0.0;
      }
      V[q][q] = 1.0;
    }
    nct = m;
    nctp1 = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      nrm = b_s_data[q];
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        nrm /= rt;
        b_s_data[q] = rt;
        if ((q + 1) < (m + 1)) {
          e[q] /= nrm;
        }
        if ((q + 1) <= g_n) {
          b_i = g_n * q;
          d_i = b_i + g_n;
          for (k = b_i + 1; k <= d_i; k++) {
            U[k - 1] = nrm * U[k - 1];
          }
        }
      }
      if ((q + 1) < (m + 1)) {
        nrm = e[q];
        if (nrm != 0.0) {
          rt = std::abs(nrm);
          nrm = rt / nrm;
          e[q] = rt;
          b_s_data[q + 1] *= nrm;
          b_i = 6 * (q + 1);
          d_i = b_i + 6;
          for (k = b_i + 1; k <= d_i; k++) {
            (&V[0][0])[k - 1] *= nrm;
          }
        }
      }
      snorm =
          std::fmax(snorm, std::fmax(std::abs(b_s_data[q]), std::abs(e[q])));
    }
    while (((m + 1) > 0) && (nctp1 < 75)) {
      boolean_T exitg1;
      b_ii = m;
      exitg1 = false;
      while (!(exitg1 || (b_ii == 0))) {
        nrm = std::abs(e[b_ii - 1]);
        if (nrm <= (2.2204460492503131E-16 * (std::abs(b_s_data[b_ii - 1]) +
                                              std::abs(b_s_data[b_ii])))) {
          e[b_ii - 1] = 0.0;
          exitg1 = true;
        } else if ((nrm <= 1.0020841800044864E-292) ||
                   ((nctp1 > 20) &&
                    (nrm <= (2.2204460492503131E-16 * snorm)))) {
          e[b_ii - 1] = 0.0;
          exitg1 = true;
        } else {
          b_ii--;
        }
      }
      if (b_ii == m) {
        qjj = 4;
      } else {
        b_i = m + 1;
        qjj = m + 1;
        exitg1 = false;
        while ((!exitg1) && (qjj >= b_ii)) {
          b_i = qjj;
          if (qjj == b_ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (qjj < (m + 1)) {
              nrm = std::abs(e[qjj - 1]);
            }
            if (qjj > (b_ii + 1)) {
              nrm += std::abs(e[qjj - 2]);
            }
            rt = std::abs(b_s_data[qjj - 1]);
            if ((rt <= (2.2204460492503131E-16 * nrm)) ||
                (rt <= 1.0020841800044864E-292)) {
              b_s_data[qjj - 1] = 0.0;
              exitg1 = true;
            } else {
              qjj--;
            }
          }
        }
        if (b_i == b_ii) {
          qjj = 3;
        } else if (b_i == (m + 1)) {
          qjj = 1;
        } else {
          qjj = 2;
          b_ii = b_i;
        }
      }
      switch (qjj) {
      case 1: {
        f = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= (b_ii + 1); k--) {
          blas::xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          if (k > (b_ii + 1)) {
            real_T b;
            b = e[k - 2];
            f = (-scale) * b;
            e[k - 2] = b * sqds;
          }
          blas::xrot(V, (6 * (k - 1)) + 1, (6 * m) + 1, sqds, scale);
        }
      } break;
      case 2: {
        f = e[b_ii - 1];
        e[b_ii - 1] = 0.0;
        for (k = b_ii + 1; k <= (m + 1); k++) {
          real_T b;
          blas::xrotg(&b_s_data[k - 1], &f, &sqds, &scale);
          b = e[k - 1];
          f = (-scale) * b;
          e[k - 1] = b * sqds;
          if (g_n >= 1) {
            qjj = g_n * (k - 1);
            b_iy = g_n * (b_ii - 1);
            for (nmq = 0; nmq < g_n; nmq++) {
              qq = b_iy + nmq;
              b_i = qjj + nmq;
              nrm = (sqds * U[b_i]) + (scale * U[qq]);
              U[qq] = (sqds * U[qq]) - (scale * U[b_i]);
              U[b_i] = nrm;
            }
          }
        }
      } break;
      case 3: {
        real_T b;
        nrm = b_s_data[m - 1];
        rt = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(b_s_data[m]), std::abs(nrm)),
                                std::abs(rt)),
                      std::abs(b_s_data[b_ii])),
            std::abs(e[b_ii]));
        f = b_s_data[m] / scale;
        nrm /= scale;
        rt /= scale;
        sqds = b_s_data[b_ii] / scale;
        b = (((nrm + f) * (nrm - f)) + (rt * rt)) / 2.0;
        nrm = f * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = std::sqrt((b * b) + nrm);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        f = ((sqds + f) * (sqds - f)) + rt;
        rt = sqds * (e[b_ii] / scale);
        for (k = b_ii + 1; k <= m; k++) {
          blas::xrotg(&f, &rt, &sqds, &scale);
          if (k > (b_ii + 1)) {
            e[k - 2] = f;
          }
          nrm = e[k - 1];
          b = b_s_data[k - 1];
          e[k - 1] = (sqds * nrm) - (scale * b);
          rt = scale * b_s_data[k];
          b_s_data[k] *= sqds;
          blas::xrot(V, (6 * (k - 1)) + 1, (6 * k) + 1, sqds, scale);
          b_s_data[k - 1] = (sqds * b) + (scale * nrm);
          blas::xrotg(&b_s_data[k - 1], &rt, &sqds, &scale);
          f = (sqds * e[k - 1]) + (scale * b_s_data[k]);
          b_s_data[k] = ((-scale) * e[k - 1]) + (sqds * b_s_data[k]);
          rt = scale * e[k];
          e[k] *= sqds;
          if ((k < g_n) && (g_n >= 1)) {
            qjj = g_n * (k - 1);
            b_iy = g_n * k;
            for (nmq = 0; nmq < g_n; nmq++) {
              qq = b_iy + nmq;
              b_i = qjj + nmq;
              nrm = (sqds * U[b_i]) + (scale * U[qq]);
              U[qq] = (sqds * U[qq]) - (scale * U[b_i]);
              U[b_i] = nrm;
            }
          }
        }
        e[m - 1] = f;
        nctp1++;
      } break;
      default:
        if (b_s_data[b_ii] < 0.0) {
          b_s_data[b_ii] = -b_s_data[b_ii];
          b_i = 6 * b_ii;
          d_i = b_i + 6;
          for (k = b_i + 1; k <= d_i; k++) {
            (&V[0][0])[k - 1] = -(&V[0][0])[k - 1];
          }
        }
        nmq = b_ii + 1;
        while (((b_ii + 1) < (nct + 1)) && (b_s_data[b_ii] < b_s_data[nmq])) {
          rt = b_s_data[b_ii];
          b_s_data[b_ii] = b_s_data[nmq];
          b_s_data[nmq] = rt;
          blas::xswap(V, (6 * b_ii) + 1, (6 * (b_ii + 1)) + 1);
          if ((b_ii + 1) < g_n) {
            qjj = g_n * b_ii;
            b_iy = g_n * (b_ii + 1);
            for (k = 0; k < g_n; k++) {
              qq = qjj + k;
              nrm = U[qq];
              d_i = b_iy + k;
              U[qq] = U[d_i];
              U[d_i] = nrm;
            }
          }
          b_ii = nmq;
          nmq++;
        }
        nctp1 = 0;
        m--;
        break;
      }
    }
  }
  *s_size = minnp;
  if (0 <= (minnp - 1)) {
    (void)std::copy(&b_s_data[0], &b_s_data[minnp], &s_data[0]);
  }
}

//
// Arguments    : const real_T A[3][3]
//                real_T U[3][3]
//                real_T s[3]
//                real_T V[3][3]
// Return Type  : void
//
void c_svd(const real_T A[3][3], real_T U[3][3], real_T s[3], real_T V[3][3])
{
  real_T e_A[3][3];
  real_T b_s[3];
  real_T e[3];
  real_T work[3];
  real_T nrm;
  real_T rt;
  real_T sm;
  real_T snorm;
  real_T sqds;
  int32_T k;
  int32_T kase;
  int32_T m;
  int32_T q;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  for (kase = 0; kase < 3; kase++) {
    b_s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
    e_A[kase][0] = A[kase][0];
    U[kase][0] = 0.0;
    V[kase][0] = 0.0;
    e_A[kase][1] = A[kase][1];
    U[kase][1] = 0.0;
    V[kase][1] = 0.0;
    e_A[kase][2] = A[kase][2];
    U[kase][2] = 0.0;
    V[kase][2] = 0.0;
  }
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + (3 * q)) + 1;
    apply_transform = false;
    nrm = blas::d_xnrm2(3 - q, e_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&e_A[0][0])[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (std::abs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&e_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&e_A[0][0])[k - 1] /= b_s[q];
        }
      }
      (&e_A[0][0])[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + (3 * (kase - 1));
      if (apply_transform) {
        blas::c_xaxpy(
            3 - q, -(blas::b_xdotc(3 - q, e_A, qq, e_A, qjj + 1) / e_A[q][q]),
            qq, e_A, qjj + 1);
      }
      e[kase - 1] = (&e_A[0][0])[qjj];
    }
    for (k = q + 1; k < 4; k++) {
      U[q][k - 1] = e_A[q][k - 1];
    }
    if ((q + 1) <= 1) {
      nrm = blas::e_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        nrm = e[0];
        if (std::abs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (k = qp1; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (k = qp1; k < 4; k++) {
          work[k - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::d_xaxpy(e[kase - 1], e_A, (3 * (kase - 1)) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::e_xaxpy((-e[kase - 1]) / e[1], work, e_A, (3 * (kase - 1)) + 2);
        }
      }
      for (k = qp1; k < 4; k++) {
        V[0][k - 1] = e[k - 1];
      }
    }
  }
  m = 1;
  b_s[2] = e_A[2][2];
  e[1] = e_A[2][1];
  e[2] = 0.0;
  U[2][0] = 0.0;
  U[2][1] = 0.0;
  U[2][2] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + (3 * q);
    if (b_s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + (3 * (kase - 1))) + 1;
        blas::c_xaxpy(
            3 - q, -(blas::b_xdotc(3 - q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (k = q + 1; k < 4; k++) {
        U[q][k - 1] = -U[q][k - 1];
      }
      (&U[0][0])[qq]++;
      if (0 <= (q - 1)) {
        U[q][0] = 0.0;
      }
    } else {
      U[q][0] = 0.0;
      U[q][1] = 0.0;
      U[q][2] = 0.0;
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (q = 2; q >= 0; q--) {
    if (((q + 1) <= 1) && (e[0] != 0.0)) {
      blas::c_xaxpy(2, -(blas::b_xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V,
                    5);
      blas::c_xaxpy(2, -(blas::b_xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V,
                    8);
    }
    V[q][0] = 0.0;
    V[q][1] = 0.0;
    V[q][2] = 0.0;
    V[q][q] = 1.0;
  }
  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    nrm = b_s[q];
    if (nrm != 0.0) {
      rt = std::abs(nrm);
      nrm /= rt;
      b_s[q] = rt;
      if ((q + 1) < 3) {
        e[q] /= nrm;
      }
      kase = 3 * q;
      qjj = kase + 3;
      for (k = kase + 1; k <= qjj; k++) {
        (&U[0][0])[k - 1] *= nrm;
      }
    }
    if ((q + 1) < 3) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          (&V[0][0])[k - 1] *= nrm;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(b_s[q]), std::abs(e[q])));
  }
  while (((m + 2) > 0) && (qp1 < 75)) {
    k = m;
    int32_T exitg1;
    do {
      exitg1 = 0;
      q = k + 1;
      if ((k + 1) == 0) {
        exitg1 = 1;
      } else {
        nrm = std::abs(e[k]);
        if (nrm <= (2.2204460492503131E-16 *
                    (std::abs(b_s[k]) + std::abs(b_s[k + 1])))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else if ((nrm <= 1.0020841800044864E-292) ||
                   ((qp1 > 20) && (nrm <= (2.2204460492503131E-16 * snorm)))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);
    if ((k + 1) == (m + 1)) {
      kase = 4;
    } else {
      boolean_T exitg2;
      qjj = m + 2;
      kase = m + 2;
      exitg2 = false;
      while ((!exitg2) && (kase >= (k + 1))) {
        qjj = kase;
        if (kase == (k + 1)) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (kase < (m + 2)) {
            nrm = std::abs(e[kase - 1]);
          }
          if (kase > (k + 2)) {
            nrm += std::abs(e[kase - 2]);
          }
          rt = std::abs(b_s[kase - 1]);
          if ((rt <= (2.2204460492503131E-16 * nrm)) ||
              (rt <= 1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg2 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == (k + 1)) {
        kase = 3;
      } else if (qjj == (m + 2)) {
        kase = 1;
      } else {
        kase = 2;
        q = qjj;
      }
    }
    switch (kase) {
    case 1:
      rt = e[m];
      e[m] = 0.0;
      qjj = m + 1;
      for (k = qjj; k >= (q + 1); k--) {
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        if (k > (q + 1)) {
          rt = (-sqds) * e[0];
          e[0] *= sm;
        }
        blas::b_xrot(V, (3 * (k - 1)) + 1, (3 * (m + 1)) + 1, sm, sqds);
      }
      break;
    case 2: {
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        real_T b;
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = (-sqds) * b;
        e[k - 1] = b * sm;
        blas::b_xrot(U, (3 * (k - 1)) + 1, (3 * (q - 1)) + 1, sm, sqds);
      }
    } break;
    case 3: {
      real_T b;
      real_T scale;
      kase = m + 1;
      nrm = b_s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(b_s[m])),
                              std::abs(e[m])),
                    std::abs(b_s[q])),
          std::abs(e[q]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      rt = e[m] / scale;
      sqds = b_s[q] / scale;
      b = (((nrm + sm) * (nrm - sm)) + (rt * rt)) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = std::sqrt((b * b) + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= kase; k++) {
        blas::xrotg(&rt, &nrm, &sm, &sqds);
        if (k > (q + 1)) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * b);
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        blas::b_xrot(V, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
        b_s[k - 1] = (sm * b) + (sqds * nrm);
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        rt = (sm * e[k - 1]) + (sqds * b_s[k]);
        b_s[k] = ((-sqds) * e[k - 1]) + (sm * b_s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::b_xrot(U, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
      }
      e[m] = rt;
      qp1++;
    } break;
    default:
      if (b_s[q] < 0.0) {
        b_s[q] = -b_s[q];
        kase = 3 * q;
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          (&V[0][0])[k - 1] = -(&V[0][0])[k - 1];
        }
      }
      qp1 = q + 1;
      while (((q + 1) < 3) && (b_s[q] < b_s[qp1])) {
        rt = b_s[q];
        b_s[q] = b_s[qp1];
        b_s[qp1] = rt;
        blas::b_xswap(V, (3 * q) + 1, (3 * (q + 1)) + 1);
        blas::b_xswap(U, (3 * q) + 1, (3 * (q + 1)) + 1);
        q = qp1;
        qp1++;
      }
      qp1 = 0;
      m--;
      break;
    }
  }
  s[0] = b_s[0];
  s[1] = b_s[1];
  s[2] = b_s[2];
}

//
// Arguments    : const ::coder::array<real_T, 2U> &A
//                real_T d_U_data[]
//                int32_T *U_size
// Return Type  : void
//
void svd(const ::coder::array<real_T, 2U> &A, real_T d_U_data[],
         int32_T *U_size)
{
  ::coder::array<real_T, 2U> e_A;
  ::coder::array<real_T, 1U> work;
  real_T e[8];
  real_T s_data[8];
  real_T nrm;
  real_T sm;
  real_T sqds;
  real_T ztest;
  int32_T b_i;
  int32_T g_n;
  int32_T i1;
  int32_T qq;
  e_A.set_size(A.size(0), 8);
  qq = A.size(0);
  for (b_i = 0; b_i < 8; b_i++) {
    for (i1 = 0; i1 < qq; i1++) {
      e_A[i1 + (e_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  g_n = A.size(0);
  *U_size = A.size(0);
  if ((*U_size) > 8) {
    *U_size = 8;
  }
  qq = A.size(0) + 1;
  if (qq > 8) {
    qq = 8;
  }
  if (0 <= (qq - 1)) {
    (void)std::memset(&s_data[0], 0,
                      (static_cast<uint32_T>(qq)) * (sizeof(real_T)));
  }
  (void)std::memset(&e[0], 0, 8U * (sizeof(real_T)));
  work.set_size(A.size(0));
  qq = A.size(0);
  for (b_i = 0; b_i < qq; b_i++) {
    work[b_i] = 0.0;
  }
  if (A.size(0) != 0) {
    real_T rt;
    real_T snorm;
    int32_T iter;
    int32_T jj;
    int32_T k;
    int32_T m;
    int32_T mm;
    int32_T nct;
    int32_T nrt;
    int32_T q;
    int32_T qjj;
    nrt = A.size(0);
    if (6 <= nrt) {
      nrt = 6;
    }
    nct = A.size(0) - 1;
    if (nct > 8) {
      nct = 8;
    }
    if (nct >= nrt) {
      b_i = nct;
    } else {
      b_i = nrt;
    }
    for (q = 0; q < b_i; q++) {
      int32_T nmq;
      boolean_T apply_transform;
      m = q + 2;
      qq = (q + (g_n * q)) + 1;
      nmq = (g_n - q) - 1;
      apply_transform = false;
      if ((q + 1) <= nct) {
        nrm = blas::xnrm2(nmq + 1, e_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (e_A[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (std::abs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              e_A[k - 1] = nrm * e_A[k - 1];
            }
          } else {
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              e_A[k - 1] = e_A[k - 1] / s_data[q];
            }
          }
          e_A[qq - 1] = e_A[qq - 1] + 1.0;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (jj = m; jj < 9; jj++) {
        qjj = q + (g_n * (jj - 1));
        if (apply_transform) {
          nrm = 0.0;
          if ((nmq + 1) >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += e_A[(qq + k) - 1] * e_A[qjj + k];
            }
          }
          nrm = -(nrm / e_A[q + (e_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(nrm == 0.0))) {
            for (k = 0; k <= nmq; k++) {
              i1 = qjj + k;
              e_A[i1] = e_A[i1] + (nrm * e_A[(qq + k) - 1]);
            }
          }
        }
        e[jj - 1] = e_A[qjj];
      }
      if ((q + 1) <= nrt) {
        nrm = blas::b_xnrm2(7 - q, e, q + 2);
        if (nrm == 0.0) {
          e[q] = 0.0;
        } else {
          if (e[q + 1] < 0.0) {
            e[q] = -nrm;
          } else {
            e[q] = nrm;
          }
          nrm = e[q];
          if (std::abs(e[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e[q];
            for (k = m; k < 9; k++) {
              e[k - 1] *= nrm;
            }
          } else {
            for (k = m; k < 9; k++) {
              e[k - 1] /= nrm;
            }
          }
          e[q + 1]++;
          e[q] = -e[q];
          if ((q + 2) <= g_n) {
            for (jj = m; jj <= g_n; jj++) {
              work[jj - 1] = 0.0;
            }
            for (jj = m; jj < 9; jj++) {
              nrm = e[jj - 1];
              iter = (q + (g_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (q + k) + 1;
                  work[mm] = work[mm] + (nrm * e_A[(iter + k) - 1]);
                }
              }
            }
            for (jj = m; jj < 9; jj++) {
              nrm = (-e[jj - 1]) / e[q + 1];
              iter = (q + (g_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (iter + k) - 1;
                  e_A[mm] = e_A[mm] + (nrm * work[(q + k) + 1]);
                }
              }
            }
          }
        }
      }
    }
    if (8 <= (A.size(0) + 1)) {
      m = 7;
    } else {
      m = A.size(0);
    }
    if (nct < 8) {
      s_data[nct] = e_A[nct + (e_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s_data[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = e_A[nrt + (e_A.size(0) * m)];
    }
    e[m] = 0.0;
    mm = m;
    iter = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      nrm = s_data[q];
      ztest = nrm;
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        ztest = rt;
        s_data[q] = rt;
        if ((q + 1) < (m + 1)) {
          e[q] /= nrm / rt;
        }
      }
      if (((q + 1) < (m + 1)) && (e[q] != 0.0)) {
        rt = std::abs(e[q]);
        nrm = rt / e[q];
        e[q] = rt;
        s_data[q + 1] *= nrm;
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(ztest), std::abs(e[q])));
    }
    while (((m + 1) > 0) && (iter < 75)) {
      boolean_T exitg1;
      jj = m;
      exitg1 = false;
      while (!(exitg1 || (jj == 0))) {
        nrm = std::abs(e[jj - 1]);
        if (nrm <= (2.2204460492503131E-16 *
                    (std::abs(s_data[jj - 1]) + std::abs(s_data[jj])))) {
          e[jj - 1] = 0.0;
          exitg1 = true;
        } else if ((nrm <= 1.0020841800044864E-292) ||
                   ((iter > 20) && (nrm <= (2.2204460492503131E-16 * snorm)))) {
          e[jj - 1] = 0.0;
          exitg1 = true;
        } else {
          jj--;
        }
      }
      if (jj == m) {
        qq = 4;
      } else {
        qjj = m + 1;
        qq = m + 1;
        exitg1 = false;
        while ((!exitg1) && (qq >= jj)) {
          qjj = qq;
          if (qq == jj) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (qq < (m + 1)) {
              nrm = std::abs(e[qq - 1]);
            }
            if (qq > (jj + 1)) {
              nrm += std::abs(e[qq - 2]);
            }
            ztest = std::abs(s_data[qq - 1]);
            if ((ztest <= (2.2204460492503131E-16 * nrm)) ||
                (ztest <= 1.0020841800044864E-292)) {
              s_data[qq - 1] = 0.0;
              exitg1 = true;
            } else {
              qq--;
            }
          }
        }
        if (qjj == jj) {
          qq = 3;
        } else if (qjj == (m + 1)) {
          qq = 1;
        } else {
          qq = 2;
          jj = qjj;
        }
      }
      switch (qq) {
      case 1:
        ztest = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= (jj + 1); k--) {
          blas::xrotg(&s_data[k - 1], &ztest, &sqds, &sm);
          if (k > (jj + 1)) {
            rt = e[k - 2];
            ztest = (-sm) * rt;
            e[k - 2] = rt * sqds;
          }
        }
        break;
      case 2:
        ztest = e[jj - 1];
        e[jj - 1] = 0.0;
        for (k = jj + 1; k <= (m + 1); k++) {
          blas::xrotg(&s_data[k - 1], &ztest, &sqds, &sm);
          rt = e[k - 1];
          ztest = (-sm) * rt;
          e[k - 1] = rt * sqds;
        }
        break;
      case 3: {
        real_T scale;
        nrm = s_data[m - 1];
        ztest = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s_data[m]), std::abs(nrm)),
                                std::abs(ztest)),
                      std::abs(s_data[jj])),
            std::abs(e[jj]));
        sm = s_data[m] / scale;
        nrm /= scale;
        ztest /= scale;
        sqds = s_data[jj] / scale;
        rt = (((nrm + sm) * (nrm - sm)) + (ztest * ztest)) / 2.0;
        nrm = sm * ztest;
        nrm *= nrm;
        if ((rt != 0.0) || (nrm != 0.0)) {
          ztest = std::sqrt((rt * rt) + nrm);
          if (rt < 0.0) {
            ztest = -ztest;
          }
          ztest = nrm / (rt + ztest);
        } else {
          ztest = 0.0;
        }
        ztest += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[jj] / scale);
        for (k = jj + 1; k <= m; k++) {
          blas::xrotg(&ztest, &nrm, &sqds, &sm);
          if (k > (jj + 1)) {
            e[k - 2] = ztest;
          }
          nrm = e[k - 1];
          rt = s_data[k - 1];
          e[k - 1] = (sqds * nrm) - (sm * rt);
          ztest = sm * s_data[k];
          s_data[k] *= sqds;
          s_data[k - 1] = (sqds * rt) + (sm * nrm);
          blas::xrotg(&s_data[k - 1], &ztest, &sqds, &sm);
          ztest = (sqds * e[k - 1]) + (sm * s_data[k]);
          s_data[k] = ((-sm) * e[k - 1]) + (sqds * s_data[k]);
          nrm = sm * e[k];
          e[k] *= sqds;
        }
        e[m - 1] = ztest;
        iter++;
      } break;
      default:
        if (s_data[jj] < 0.0) {
          s_data[jj] = -s_data[jj];
        }
        qq = jj + 1;
        while (((jj + 1) < (mm + 1)) && (s_data[jj] < s_data[qq])) {
          rt = s_data[jj];
          s_data[jj] = s_data[qq];
          s_data[qq] = rt;
          jj = qq;
          qq++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  if (0 <= ((*U_size) - 1)) {
    (void)std::copy(&s_data[0], &s_data[*U_size], &d_U_data[0]);
  }
}

} // namespace internal
} // namespace coder
} // namespace Codegen

//
// File trailer for svd.cpp
//
// [EOF]
//
