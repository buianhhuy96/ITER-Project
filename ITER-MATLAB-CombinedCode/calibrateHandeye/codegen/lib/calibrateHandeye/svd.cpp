//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 20-Oct-2021 19:51:03
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
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &U
// Return Type  : void
//
namespace coder {
namespace internal {
void b_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U)
{
  array<double, 2U> d_A;
  array<double, 1U> s;
  array<double, 1U> work;
  double e[8];
  double nrm;
  double rt;
  double sm;
  double sqds;
  int b_i;
  int c_n;
  int i1;
  int k;
  int minnp;
  int qq;
  d_A.set_size(A.size(0), 8);
  qq = A.size(0);
  for (b_i = 0; b_i < 8; b_i++) {
    for (i1 = 0; i1 < qq; i1++) {
      d_A[i1 + (d_A.size(0) * b_i)] = A[i1 + (A.size(0) * b_i)];
    }
  }
  c_n = A.size(0);
  minnp = A.size(0);
  if (minnp > 8) {
    minnp = 8;
  }
  qq = A.size(0) + 1;
  if (qq > 8) {
    qq = 8;
  }
  s.set_size(qq);
  for (b_i = 0; b_i < qq; b_i++) {
    s[b_i] = 0.0;
  }
  (void)std::memset(&e[0], 0, 8U * (sizeof(double)));
  work.set_size(A.size(0));
  qq = A.size(0);
  for (b_i = 0; b_i < qq; b_i++) {
    work[b_i] = 0.0;
  }
  if (A.size(0) != 0) {
    double r;
    double snorm;
    int iter;
    int jj;
    int m;
    int mm;
    int nct;
    int nrt;
    int q;
    int qjj;
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
      int nmq;
      bool apply_transform;
      m = q + 2;
      qq = (q + (c_n * q)) + 1;
      nmq = (c_n - q) - 1;
      apply_transform = false;
      if ((q + 1) <= nct) {
        nrm = blas::xnrm2(nmq + 1, d_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (d_A[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s[q] = nrm;
          if (std::abs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              d_A[k - 1] = nrm * d_A[k - 1];
            }
          } else {
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              d_A[k - 1] = d_A[k - 1] / s[q];
            }
          }
          d_A[qq - 1] = d_A[qq - 1] + 1.0;
          s[q] = -s[q];
        } else {
          s[q] = 0.0;
        }
      }
      for (jj = m; jj < 9; jj++) {
        qjj = q + (c_n * (jj - 1));
        if (apply_transform) {
          nrm = 0.0;
          if ((nmq + 1) >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += d_A[(qq + k) - 1] * d_A[qjj + k];
            }
          }
          nrm = -(nrm / d_A[q + (d_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(nrm == 0.0))) {
            for (k = 0; k <= nmq; k++) {
              i1 = qjj + k;
              d_A[i1] = d_A[i1] + (nrm * d_A[(qq + k) - 1]);
            }
          }
        }
        e[jj - 1] = d_A[qjj];
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
          if ((q + 2) <= c_n) {
            for (jj = m; jj <= c_n; jj++) {
              work[jj - 1] = 0.0;
            }
            for (jj = m; jj < 9; jj++) {
              nrm = e[jj - 1];
              iter = (q + (c_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (q + k) + 1;
                  work[mm] = work[mm] + (nrm * d_A[(iter + k) - 1]);
                }
              }
            }
            for (jj = m; jj < 9; jj++) {
              nrm = (-e[jj - 1]) / e[q + 1];
              iter = (q + (c_n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (iter + k) - 1;
                  d_A[mm] = d_A[mm] + (nrm * work[(q + k) + 1]);
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
      s[nct] = d_A[nct + (d_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = d_A[nrt + (d_A.size(0) * m)];
    }
    e[m] = 0.0;
    mm = m;
    iter = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      nrm = s[q];
      if (s[q] != 0.0) {
        rt = std::abs(s[q]);
        r = s[q] / rt;
        nrm = rt;
        s[q] = rt;
        if ((q + 1) < (m + 1)) {
          e[q] /= r;
        }
      }
      if (((q + 1) < (m + 1)) && (e[q] != 0.0)) {
        rt = std::abs(e[q]);
        r = rt / e[q];
        e[q] = rt;
        s[q + 1] = s[q + 1] * r;
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(nrm), std::abs(e[q])));
    }
    while (((m + 1) > 0) && (iter < 75)) {
      bool exitg1;
      jj = m;
      exitg1 = false;
      while (!(exitg1 || (jj == 0))) {
        nrm = std::abs(e[jj - 1]);
        if (nrm <= (2.2204460492503131E-16 *
                    (std::abs(s[jj - 1]) + std::abs(s[jj])))) {
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
            rt = std::abs(s[qq - 1]);
            if ((rt <= (2.2204460492503131E-16 * nrm)) ||
                (rt <= 1.0020841800044864E-292)) {
              s[qq - 1] = 0.0;
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
        rt = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= (jj + 1); k--) {
          blas::xrotg(&s[k - 1], &rt, &sqds, &sm);
          if (k > (jj + 1)) {
            r = e[k - 2];
            rt = (-sm) * r;
            e[k - 2] = r * sqds;
          }
        }
        break;
      case 2:
        rt = e[jj - 1];
        e[jj - 1] = 0.0;
        for (k = jj + 1; k <= (m + 1); k++) {
          blas::xrotg(&s[k - 1], &rt, &sqds, &sm);
          r = e[k - 1];
          rt = (-sm) * r;
          e[k - 1] = r * sqds;
        }
        break;
      case 3: {
        double scale;
        nrm = s[m - 1];
        rt = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s[m]), std::abs(nrm)),
                                std::abs(rt)),
                      std::abs(s[jj])),
            std::abs(e[jj]));
        sm = s[m] / scale;
        nrm /= scale;
        rt /= scale;
        sqds = s[jj] / scale;
        r = (((nrm + sm) * (nrm - sm)) + (rt * rt)) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((r != 0.0) || (nrm != 0.0)) {
          rt = std::sqrt((r * r) + nrm);
          if (r < 0.0) {
            rt = -rt;
          }
          rt = nrm / (r + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[jj] / scale);
        for (k = jj + 1; k <= m; k++) {
          blas::xrotg(&rt, &nrm, &sqds, &sm);
          if (k > (jj + 1)) {
            e[k - 2] = rt;
          }
          nrm = e[k - 1];
          r = s[k - 1];
          e[k - 1] = (sqds * nrm) - (sm * r);
          rt = sm * s[k];
          s[k] = s[k] * sqds;
          s[k - 1] = (sqds * r) + (sm * nrm);
          blas::xrotg(&s[k - 1], &rt, &sqds, &sm);
          rt = (sqds * e[k - 1]) + (sm * s[k]);
          s[k] = ((-sm) * e[k - 1]) + (sqds * s[k]);
          nrm = sm * e[k];
          e[k] *= sqds;
        }
        e[m - 1] = rt;
        iter++;
      } break;
      default:
        if (s[jj] < 0.0) {
          s[jj] = -s[jj];
        }
        qq = jj + 1;
        exitg1 = false;
        while ((!exitg1) && ((jj + 1) < (mm + 1))) {
          if (s[jj] < s[qq]) {
            rt = s[jj];
            s[jj] = s[qq];
            s[qq] = rt;
            jj = qq;
            qq++;
          } else {
            exitg1 = true;
          }
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  U.set_size(minnp);
  for (k = 0; k < minnp; k++) {
    U[k] = s[k];
  }
}

//
// Arguments    : const double A[3][3]
//                double U[3][3]
//                double s[3]
//                double V[3][3]
// Return Type  : void
//
void c_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3])
{
  double d_A[3][3];
  double d_s[3];
  double e[3];
  double work[3];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  for (kase = 0; kase < 3; kase++) {
    d_s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
    d_A[kase][0] = A[kase][0];
    U[kase][0] = 0.0;
    V[kase][0] = 0.0;
    d_A[kase][1] = A[kase][1];
    U[kase][1] = 0.0;
    V[kase][1] = 0.0;
    d_A[kase][2] = A[kase][2];
    U[kase][2] = 0.0;
    V[kase][2] = 0.0;
  }
  for (q = 0; q < 2; q++) {
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (3 * q)) + 1;
    apply_transform = false;
    nrm = blas::c_xnrm2(3 - q, d_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&d_A[0][0])[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      d_s[q] = nrm;
      if (std::abs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&d_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&d_A[0][0])[k - 1] /= d_s[q];
        }
      }
      (&d_A[0][0])[qq - 1]++;
      d_s[q] = -d_s[q];
    } else {
      d_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + (3 * (kase - 1));
      if (apply_transform) {
        blas::xaxpy(3 - q,
                    -(blas::xdotc(3 - q, d_A, qq, d_A, qjj + 1) / d_A[q][q]),
                    qq, d_A, qjj + 1);
      }
      e[kase - 1] = (&d_A[0][0])[qjj];
    }
    for (k = q + 1; k < 4; k++) {
      U[q][k - 1] = d_A[q][k - 1];
    }
    if ((q + 1) <= 1) {
      nrm = blas::f_xnrm2(e);
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
          blas::e_xaxpy(e[kase - 1], d_A, (3 * (kase - 1)) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::f_xaxpy((-e[kase - 1]) / e[1], work, d_A, (3 * (kase - 1)) + 2);
        }
      }
      for (k = qp1; k < 4; k++) {
        V[0][k - 1] = e[k - 1];
      }
    }
  }
  m = 1;
  d_s[2] = d_A[2][2];
  e[1] = d_A[2][1];
  e[2] = 0.0;
  U[2][0] = 0.0;
  U[2][1] = 0.0;
  U[2][2] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + (3 * q);
    if (d_s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + (3 * (kase - 1))) + 1;
        blas::xaxpy(3 - q,
                    -(blas::xdotc(3 - q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
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
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V, 5);
      blas::xaxpy(2, -(blas::xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V, 8);
    }
    V[q][0] = 0.0;
    V[q][1] = 0.0;
    V[q][2] = 0.0;
    V[q][q] = 1.0;
  }
  qp1 = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    nrm = d_s[q];
    if (nrm != 0.0) {
      rt = std::abs(nrm);
      nrm /= rt;
      d_s[q] = rt;
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
        d_s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          (&V[0][0])[k - 1] *= nrm;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(d_s[q]), std::abs(e[q])));
  }
  while (((m + 2) > 0) && (qp1 < 75)) {
    k = m;
    int exitg1;
    do {
      exitg1 = 0;
      q = k + 1;
      if ((k + 1) == 0) {
        exitg1 = 1;
      } else {
        nrm = std::abs(e[k]);
        if (nrm <= (2.2204460492503131E-16 *
                    (std::abs(d_s[k]) + std::abs(d_s[k + 1])))) {
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
      bool exitg2;
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
          rt = std::abs(d_s[kase - 1]);
          if ((rt <= (2.2204460492503131E-16 * nrm)) ||
              (rt <= 1.0020841800044864E-292)) {
            d_s[kase - 1] = 0.0;
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
        blas::xrotg(&d_s[k - 1], &rt, &sm, &sqds);
        if (k > (q + 1)) {
          rt = (-sqds) * e[0];
          e[0] *= sm;
        }
        blas::xrot(V, (3 * (k - 1)) + 1, (3 * (m + 1)) + 1, sm, sqds);
      }
      break;
    case 2: {
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        double b;
        blas::xrotg(&d_s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = (-sqds) * b;
        e[k - 1] = b * sm;
        blas::xrot(U, (3 * (k - 1)) + 1, (3 * (q - 1)) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      kase = m + 1;
      nrm = d_s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(d_s[m])),
                              std::abs(e[m])),
                    std::abs(d_s[q])),
          std::abs(e[q]));
      sm = nrm / scale;
      nrm = d_s[m] / scale;
      rt = e[m] / scale;
      sqds = d_s[q] / scale;
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
        b = d_s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * b);
        rt = sqds * d_s[k];
        d_s[k] *= sm;
        blas::xrot(V, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
        d_s[k - 1] = (sm * b) + (sqds * nrm);
        blas::xrotg(&d_s[k - 1], &rt, &sm, &sqds);
        rt = (sm * e[k - 1]) + (sqds * d_s[k]);
        d_s[k] = ((-sqds) * e[k - 1]) + (sm * d_s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::xrot(U, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
      }
      e[m] = rt;
      qp1++;
    } break;
    default:
      if (d_s[q] < 0.0) {
        d_s[q] = -d_s[q];
        kase = 3 * q;
        qjj = kase + 3;
        for (k = kase + 1; k <= qjj; k++) {
          (&V[0][0])[k - 1] = -(&V[0][0])[k - 1];
        }
      }
      qp1 = q + 1;
      while (((q + 1) < 3) && (d_s[q] < d_s[qp1])) {
        rt = d_s[q];
        d_s[q] = d_s[qp1];
        d_s[qp1] = rt;
        blas::xswap(V, (3 * q) + 1, (3 * (q + 1)) + 1);
        blas::xswap(U, (3 * q) + 1, (3 * (q + 1)) + 1);
        q = qp1;
        qp1++;
      }
      qp1 = 0;
      m--;
      break;
    }
  }
  s[0] = d_s[0];
  s[1] = d_s[1];
  s[2] = d_s[2];
}

//
// Arguments    : const double A[9][9]
//                double U[9][9]
//                double s[9]
//                double V[9][9]
// Return Type  : void
//
void d_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9])
{
  double d_A[9][9];
  double e[9];
  double work[9];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  for (qjj = 0; qjj < 9; qjj++) {
    s[qjj] = 0.0;
    e[qjj] = 0.0;
    work[qjj] = 0.0;
    for (qp1jj = 0; qp1jj < 9; qp1jj++) {
      d_A[qjj][qp1jj] = A[qjj][qp1jj];
      U[qjj][qp1jj] = 0.0;
      V[qjj][qp1jj] = 0.0;
    }
  }
  for (q = 0; q < 8; q++) {
    bool apply_transform;
    qp1 = q + 2;
    qq = (q + (9 * q)) + 1;
    apply_transform = false;
    nrm = blas::d_xnrm2(9 - q, d_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&d_A[0][0])[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      s[q] = nrm;
      if (std::abs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          (&d_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          (&d_A[0][0])[k - 1] /= s[q];
        }
      }
      (&d_A[0][0])[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (k = qp1; k < 10; k++) {
      qjj = q + (9 * (k - 1));
      if (apply_transform) {
        blas::b_xaxpy(
            9 - q, -(blas::b_xdotc(9 - q, d_A, qq, d_A, qjj + 1) / d_A[q][q]),
            qq, d_A, qjj + 1);
      }
      e[k - 1] = (&d_A[0][0])[qjj];
    }
    for (k = q + 1; k < 10; k++) {
      U[q][k - 1] = d_A[q][k - 1];
    }
    if ((q + 1) <= 7) {
      nrm = blas::e_xnrm2(8 - q, e, q + 2);
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
          for (k = qp1; k < 10; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 10; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 10; k++) {
          work[k - 1] = 0.0;
        }
        for (k = qp1; k < 10; k++) {
          blas::c_xaxpy(8 - q, e[k - 1], d_A, (q + (9 * (k - 1))) + 2, work,
                        q + 2);
        }
        for (k = qp1; k < 10; k++) {
          blas::d_xaxpy(8 - q, (-e[k - 1]) / e[q + 1], work, q + 2, d_A,
                        (q + (9 * (k - 1))) + 2);
        }
      }
      for (k = qp1; k < 10; k++) {
        V[q][k - 1] = e[k - 1];
      }
    }
  }
  m = 7;
  s[8] = d_A[8][8];
  e[7] = d_A[8][7];
  e[8] = 0.0;
  (void)std::memset(&U[8][0], 0, 9U * (sizeof(double)));
  U[8][8] = 1.0;
  for (q = 7; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + (9 * q);
    if (s[q] != 0.0) {
      for (k = qp1; k < 10; k++) {
        qjj = (q + (9 * (k - 1))) + 1;
        blas::b_xaxpy(
            9 - q, -(blas::b_xdotc(9 - q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
            qq + 1, U, qjj);
      }
      for (k = q + 1; k < 10; k++) {
        U[q][k - 1] = -U[q][k - 1];
      }
      (&U[0][0])[qq]++;
      for (k = 0; k < q; k++) {
        U[q][k] = 0.0;
      }
    } else {
      for (k = 0; k < 9; k++) {
        U[q][k] = 0.0;
      }
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (q = 8; q >= 0; q--) {
    if (((q + 1) <= 7) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (9 * q)) + 2;
      for (k = qp1; k < 10; k++) {
        qp1jj = (q + (9 * (k - 1))) + 2;
        blas::b_xaxpy(
            8 - q,
            -(blas::b_xdotc(8 - q, V, qjj, V, qp1jj) / (&V[0][0])[qjj - 1]),
            qjj, V, qp1jj);
      }
    }
    for (k = 0; k < 9; k++) {
      V[q][k] = 0.0;
    }
    V[q][q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 9; q++) {
    nrm = s[q];
    if (nrm != 0.0) {
      rt = std::abs(nrm);
      nrm /= rt;
      s[q] = rt;
      if ((q + 1) < 9) {
        e[q] /= nrm;
      }
      qjj = 9 * q;
      qp1jj = qjj + 9;
      for (k = qjj + 1; k <= qp1jj; k++) {
        (&U[0][0])[k - 1] *= nrm;
      }
    }
    if ((q + 1) < 9) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        s[q + 1] *= nrm;
        qjj = 9 * (q + 1);
        qp1jj = qjj + 9;
        for (k = qjj + 1; k <= qp1jj; k++) {
          (&V[0][0])[k - 1] *= nrm;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(s[q]), std::abs(e[q])));
  }
  while (((m + 2) > 0) && (qq < 75)) {
    k = m;
    int exitg1;
    do {
      exitg1 = 0;
      q = k + 1;
      if ((k + 1) == 0) {
        exitg1 = 1;
      } else {
        nrm = std::abs(e[k]);
        if (nrm <=
            (2.2204460492503131E-16 * (std::abs(s[k]) + std::abs(s[k + 1])))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else if ((nrm <= 1.0020841800044864E-292) ||
                   ((qq > 20) && (nrm <= (2.2204460492503131E-16 * snorm)))) {
          e[k] = 0.0;
          exitg1 = 1;
        } else {
          k--;
        }
      }
    } while (exitg1 == 0);
    if ((k + 1) == (m + 1)) {
      qjj = 4;
    } else {
      bool exitg2;
      qp1jj = m + 2;
      qjj = m + 2;
      exitg2 = false;
      while ((!exitg2) && (qjj >= (k + 1))) {
        qp1jj = qjj;
        if (qjj == (k + 1)) {
          exitg2 = true;
        } else {
          nrm = 0.0;
          if (qjj < (m + 2)) {
            nrm = std::abs(e[qjj - 1]);
          }
          if (qjj > (k + 2)) {
            nrm += std::abs(e[qjj - 2]);
          }
          rt = std::abs(s[qjj - 1]);
          if ((rt <= (2.2204460492503131E-16 * nrm)) ||
              (rt <= 1.0020841800044864E-292)) {
            s[qjj - 1] = 0.0;
            exitg2 = true;
          } else {
            qjj--;
          }
        }
      }
      if (qp1jj == (k + 1)) {
        qjj = 3;
      } else if (qp1jj == (m + 2)) {
        qjj = 1;
      } else {
        qjj = 2;
        q = qp1jj;
      }
    }
    switch (qjj) {
    case 1: {
      rt = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= (q + 1); k--) {
        blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
        if (k > (q + 1)) {
          double b;
          b = e[k - 2];
          rt = (-sqds) * b;
          e[k - 2] = b * sm;
        }
        blas::b_xrot(V, (9 * (k - 1)) + 1, (9 * (m + 1)) + 1, sm, sqds);
      }
    } break;
    case 2: {
      rt = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        double b;
        blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = (-sqds) * b;
        e[k - 1] = b * sm;
        blas::b_xrot(U, (9 * (k - 1)) + 1, (9 * (q - 1)) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      qjj = m + 1;
      nrm = s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(s[m])),
                              std::abs(e[m])),
                    std::abs(s[q])),
          std::abs(e[q]));
      sm = nrm / scale;
      nrm = s[m] / scale;
      rt = e[m] / scale;
      sqds = s[q] / scale;
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
      for (k = q + 1; k <= qjj; k++) {
        blas::xrotg(&rt, &nrm, &sm, &sqds);
        if (k > (q + 1)) {
          e[k - 2] = rt;
        }
        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * b);
        rt = sqds * s[k];
        s[k] *= sm;
        blas::b_xrot(V, (9 * (k - 1)) + 1, (9 * k) + 1, sm, sqds);
        s[k - 1] = (sm * b) + (sqds * nrm);
        blas::xrotg(&s[k - 1], &rt, &sm, &sqds);
        rt = (sm * e[k - 1]) + (sqds * s[k]);
        s[k] = ((-sqds) * e[k - 1]) + (sm * s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::b_xrot(U, (9 * (k - 1)) + 1, (9 * k) + 1, sm, sqds);
      }
      e[m] = rt;
      qq++;
    } break;
    default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = 9 * q;
        qp1jj = qjj + 9;
        for (k = qjj + 1; k <= qp1jj; k++) {
          (&V[0][0])[k - 1] = -(&V[0][0])[k - 1];
        }
      }
      qp1 = q + 1;
      while (((q + 1) < 9) && (s[q] < s[qp1])) {
        rt = s[q];
        s[q] = s[qp1];
        s[qp1] = rt;
        blas::b_xswap(V, (9 * q) + 1, (9 * (q + 1)) + 1);
        blas::b_xswap(U, (9 * q) + 1, (9 * (q + 1)) + 1);
        q = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
