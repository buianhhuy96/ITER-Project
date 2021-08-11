//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd1.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 08-Aug-2021 21:29:01
//

// Include Files
#include "svd1.h"
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
// Arguments    : const double A[29][29]
//                double U[29][29]
//                double s[29]
//                double V[29][29]
// Return Type  : void
//
namespace coder {
namespace internal {
void c_svd(const double A[29][29], double U[29][29], double s[29],
           double V[29][29])
{
  double b_A[29][29];
  double e[29];
  double work[29];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int k;
  int m;
  int q;
  int qjj;
  int qp1;
  int qp1jj;
  int qq;
  for (qjj = 0; qjj < 29; qjj++) {
    s[qjj] = 0.0;
    e[qjj] = 0.0;
    work[qjj] = 0.0;
    for (qp1jj = 0; qp1jj < 29; qp1jj++) {
      b_A[qjj][qp1jj] = A[qjj][qp1jj];
      U[qjj][qp1jj] = 0.0;
      V[qjj][qp1jj] = 0.0;
    }
  }
  for (q = 0; q < 28; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + (29 * q)) + 1;
    apply_transform = false;
    nrm = blas::xnrm2(29 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&b_A[0][0])[qq - 1] < 0.0) {
        ztest = -nrm;
        s[q] = -nrm;
      } else {
        ztest = nrm;
        s[q] = nrm;
      }
      if (std::abs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        qp1jj = (qq - q) + 28;
        for (k = qq; k <= qp1jj; k++) {
          (&b_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 28;
        for (k = qq; k <= qp1jj; k++) {
          (&b_A[0][0])[k - 1] /= s[q];
        }
      }
      (&b_A[0][0])[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (k = qp1; k < 30; k++) {
      qjj = q + (29 * (k - 1));
      if (apply_transform) {
        blas::xaxpy(29 - q,
                    -(blas::xdotc(29 - q, b_A, qq, b_A, qjj + 1) / b_A[q][q]),
                    qq, b_A, qjj + 1);
      }
      e[k - 1] = (&b_A[0][0])[qjj];
    }
    for (k = q + 1; k < 30; k++) {
      U[q][k - 1] = b_A[q][k - 1];
    }
    if ((q + 1) <= 27) {
      nrm = blas::b_xnrm2(28 - q, e, q + 2);
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
          for (k = qp1; k < 30; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (k = qp1; k < 30; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (k = qp1; k < 30; k++) {
          work[k - 1] = 0.0;
        }
        for (k = qp1; k < 30; k++) {
          blas::xaxpy(28 - q, e[k - 1], b_A, (q + (29 * (k - 1))) + 2, work,
                      q + 2);
        }
        for (k = qp1; k < 30; k++) {
          blas::b_xaxpy(28 - q, (-e[k - 1]) / e[q + 1], work, q + 2, b_A,
                        (q + (29 * (k - 1))) + 2);
        }
      }
      for (k = qp1; k < 30; k++) {
        V[q][k - 1] = e[k - 1];
      }
    }
  }
  m = 27;
  s[28] = b_A[28][28];
  e[27] = b_A[28][27];
  e[28] = 0.0;
  (void)std::memset(&U[28][0], 0, 29U * (sizeof(double)));
  U[28][28] = 1.0;
  for (q = 27; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + (29 * q);
    if (s[q] != 0.0) {
      for (k = qp1; k < 30; k++) {
        qjj = (q + (29 * (k - 1))) + 1;
        blas::xaxpy(29 - q,
                    -(blas::xdotc(29 - q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
                    qq + 1, U, qjj);
      }
      for (k = q + 1; k < 30; k++) {
        U[q][k - 1] = -U[q][k - 1];
      }
      (&U[0][0])[qq]++;
      for (k = 0; k < q; k++) {
        U[q][k] = 0.0;
      }
    } else {
      for (k = 0; k < 29; k++) {
        U[q][k] = 0.0;
      }
      (&U[0][0])[qq] = 1.0;
    }
  }
  for (q = 28; q >= 0; q--) {
    if (((q + 1) <= 27) && (e[q] != 0.0)) {
      qp1 = q + 2;
      qjj = (q + (29 * q)) + 2;
      for (k = qp1; k < 30; k++) {
        qp1jj = (q + (29 * (k - 1))) + 2;
        blas::xaxpy(
            28 - q,
            -(blas::xdotc(28 - q, V, qjj, V, qp1jj) / (&V[0][0])[qjj - 1]), qjj,
            V, qp1jj);
      }
    }
    for (k = 0; k < 29; k++) {
      V[q][k] = 0.0;
    }
    V[q][q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 29; q++) {
    ztest = s[q];
    if (ztest != 0.0) {
      rt = std::abs(ztest);
      nrm = ztest / rt;
      s[q] = rt;
      if ((q + 1) < 29) {
        e[q] /= nrm;
      }
      qjj = 29 * q;
      qp1jj = qjj + 29;
      for (k = qjj + 1; k <= qp1jj; k++) {
        (&U[0][0])[k - 1] *= nrm;
      }
    }
    if ((q + 1) < 29) {
      ztest = e[q];
      if (ztest != 0.0) {
        rt = std::abs(ztest);
        nrm = rt / ztest;
        e[q] = rt;
        s[q + 1] *= nrm;
        qjj = 29 * (q + 1);
        qp1jj = qjj + 29;
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
      boolean_T exitg2;
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
          ztest = std::abs(s[qjj - 1]);
          if ((ztest <= (2.2204460492503131E-16 * nrm)) ||
              (ztest <= 1.0020841800044864E-292)) {
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
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= (q + 1); k--) {
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        if (k > (q + 1)) {
          rt = e[k - 2];
          ztest = (-sqds) * rt;
          e[k - 2] = rt * sm;
        }
        blas::xrot(V, (29 * (k - 1)) + 1, (29 * (m + 1)) + 1, sm, sqds);
      }
      break;
    case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = (-sqds) * rt;
        e[k - 1] = rt * sm;
        blas::xrot(U, (29 * (k - 1)) + 1, (29 * (q - 1)) + 1, sm, sqds);
      }
      break;
    case 3: {
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
      ztest = e[m] / scale;
      sqds = s[q] / scale;
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
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        blas::xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > (q + 1)) {
          e[k - 2] = ztest;
        }
        nrm = e[k - 1];
        rt = s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * rt);
        ztest = sqds * s[k];
        s[k] *= sm;
        blas::xrot(V, (29 * (k - 1)) + 1, (29 * k) + 1, sm, sqds);
        s[k - 1] = (sm * rt) + (sqds * nrm);
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        ztest = (sm * e[k - 1]) + (sqds * s[k]);
        s[k] = ((-sqds) * e[k - 1]) + (sm * s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::xrot(U, (29 * (k - 1)) + 1, (29 * k) + 1, sm, sqds);
      }
      e[m] = ztest;
      qq++;
    } break;
    default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        qjj = 29 * q;
        qp1jj = qjj + 29;
        for (k = qjj + 1; k <= qp1jj; k++) {
          (&V[0][0])[k - 1] = -(&V[0][0])[k - 1];
        }
      }
      qp1 = q + 1;
      while (((q + 1) < 29) && (s[q] < s[qp1])) {
        rt = s[q];
        s[q] = s[qp1];
        s[qp1] = rt;
        blas::xswap(V, (29 * q) + 1, (29 * (q + 1)) + 1);
        blas::xswap(U, (29 * q) + 1, (29 * (q + 1)) + 1);
        q = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &U
// Return Type  : void
//
void c_svd(const ::coder::array<double, 2U> &A, ::coder::array<double, 1U> &U)
{
  array<double, 2U> b_A;
  array<double, 1U> s;
  array<double, 1U> work;
  double e[8];
  double nrm;
  double r;
  double sm;
  double sqds;
  int i;
  int i1;
  int k;
  int minnp;
  int n;
  int qq;
  b_A.set_size(A.size(0), 8);
  qq = A.size(0);
  for (i = 0; i < 8; i++) {
    for (i1 = 0; i1 < qq; i1++) {
      b_A[i1 + (b_A.size(0) * i)] = A[i1 + (A.size(0) * i)];
    }
  }
  n = A.size(0);
  minnp = A.size(0);
  if (minnp >= 8) {
    minnp = 8;
  }
  qq = A.size(0) + 1;
  if (qq >= 8) {
    qq = 8;
  }
  s.set_size(qq);
  for (i = 0; i < qq; i++) {
    s[i] = 0.0;
  }
  (void)std::memset(&e[0], 0, 8U * (sizeof(double)));
  work.set_size(A.size(0));
  qq = A.size(0);
  for (i = 0; i < qq; i++) {
    work[i] = 0.0;
  }
  if (A.size(0) != 0) {
    double b;
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
    if (6 < nrt) {
      nrt = 6;
    }
    if (A.size(0) > 1) {
      nct = A.size(0) - 1;
    } else {
      nct = 0;
    }
    if (nct >= 8) {
      nct = 8;
    }
    if (nct > nrt) {
      i = nct;
    } else {
      i = nrt;
    }
    for (q = 0; q < i; q++) {
      int nmq;
      boolean_T apply_transform;
      m = q + 2;
      qq = (q + (n * q)) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if ((q + 1) <= nct) {
        nrm = blas::xnrm2(nmq + 1, b_A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (b_A[qq - 1] < 0.0) {
            b = -nrm;
            s[q] = -nrm;
          } else {
            b = nrm;
            s[q] = nrm;
          }
          if (std::abs(b) >= 1.0020841800044864E-292) {
            nrm = 1.0 / b;
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              b_A[k - 1] = nrm * b_A[k - 1];
            }
          } else {
            i1 = qq + nmq;
            for (k = qq; k <= i1; k++) {
              b_A[k - 1] = b_A[k - 1] / s[q];
            }
          }
          b_A[qq - 1] = b_A[qq - 1] + 1.0;
          s[q] = -s[q];
        } else {
          s[q] = 0.0;
        }
      }
      for (jj = m; jj < 9; jj++) {
        qjj = q + (n * (jj - 1));
        if (apply_transform) {
          nrm = 0.0;
          if ((nmq + 1) >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += b_A[(qq + k) - 1] * b_A[qjj + k];
            }
          }
          nrm = -(nrm / b_A[q + (b_A.size(0) * q)]);
          if (((nmq + 1) >= 1) && (!(nrm == 0.0))) {
            for (k = 0; k <= nmq; k++) {
              i1 = qjj + k;
              b_A[i1] = b_A[i1] + (nrm * b_A[(qq + k) - 1]);
            }
          }
        }
        e[jj - 1] = b_A[qjj];
      }
      if ((q + 1) <= nrt) {
        nrm = blas::c_xnrm2(7 - q, e, q + 2);
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
          if ((q + 2) <= n) {
            for (jj = m; jj <= n; jj++) {
              work[jj - 1] = 0.0;
            }
            for (jj = m; jj < 9; jj++) {
              nrm = e[jj - 1];
              iter = (q + (n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (q + k) + 1;
                  work[mm] = work[mm] + (nrm * b_A[(iter + k) - 1]);
                }
              }
            }
            for (jj = m; jj < 9; jj++) {
              nrm = (-e[jj - 1]) / e[q + 1];
              iter = (q + (n * (jj - 1))) + 2;
              if ((nmq >= 1) && (!(nrm == 0.0))) {
                i1 = nmq - 1;
                for (k = 0; k <= i1; k++) {
                  mm = (iter + k) - 1;
                  b_A[mm] = b_A[mm] + (nrm * work[(q + k) + 1]);
                }
              }
            }
          }
        }
      }
    }
    if (8 < (A.size(0) + 1)) {
      m = 7;
    } else {
      m = A.size(0);
    }
    if (nct < 8) {
      s[nct] = b_A[nct + (b_A.size(0) * nct)];
    }
    if (A.size(0) < (m + 1)) {
      s[m] = 0.0;
    }
    if ((nrt + 1) < (m + 1)) {
      e[nrt] = b_A[nrt + (b_A.size(0) * m)];
    }
    e[m] = 0.0;
    mm = m;
    iter = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      b = s[q];
      if (s[q] != 0.0) {
        nrm = std::abs(s[q]);
        r = s[q] / nrm;
        b = nrm;
        s[q] = nrm;
        if ((q + 1) < (m + 1)) {
          e[q] /= r;
        }
      }
      if (((q + 1) < (m + 1)) && (e[q] != 0.0)) {
        nrm = std::abs(e[q]);
        r = nrm / e[q];
        e[q] = nrm;
        s[q + 1] = s[q + 1] * r;
      }
      snorm = std::fmax(snorm, std::fmax(std::abs(b), std::abs(e[q])));
    }
    while (((m + 1) > 0) && (iter < 75)) {
      boolean_T exitg1;
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
            r = std::abs(s[qq - 1]);
            if ((r <= (2.2204460492503131E-16 * nrm)) ||
                (r <= 1.0020841800044864E-292)) {
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
        r = e[m - 1];
        e[m - 1] = 0.0;
        for (k = m; k >= (jj + 1); k--) {
          blas::xrotg(&s[k - 1], &r, &sqds, &sm);
          if (k > (jj + 1)) {
            b = e[k - 2];
            r = (-sm) * b;
            e[k - 2] = b * sqds;
          }
        }
        break;
      case 2:
        r = e[jj - 1];
        e[jj - 1] = 0.0;
        for (k = jj + 1; k <= (m + 1); k++) {
          blas::xrotg(&s[k - 1], &r, &sqds, &sm);
          b = e[k - 1];
          r = (-sm) * b;
          e[k - 1] = b * sqds;
        }
        break;
      case 3: {
        double scale;
        nrm = s[m - 1];
        r = e[m - 1];
        scale = std::fmax(
            std::fmax(std::fmax(std::fmax(std::abs(s[m]), std::abs(nrm)),
                                std::abs(r)),
                      std::abs(s[jj])),
            std::abs(e[jj]));
        sm = s[m] / scale;
        nrm /= scale;
        r /= scale;
        sqds = s[jj] / scale;
        b = (((nrm + sm) * (nrm - sm)) + (r * r)) / 2.0;
        nrm = sm * r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          r = std::sqrt((b * b) + nrm);
          if (b < 0.0) {
            r = -r;
          }
          r = nrm / (b + r);
        } else {
          r = 0.0;
        }
        r += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[jj] / scale);
        for (k = jj + 1; k <= m; k++) {
          blas::xrotg(&r, &nrm, &sqds, &sm);
          if (k > (jj + 1)) {
            e[k - 2] = r;
          }
          nrm = e[k - 1];
          b = s[k - 1];
          e[k - 1] = (sqds * nrm) - (sm * b);
          r = sm * s[k];
          s[k] = s[k] * sqds;
          s[k - 1] = (sqds * b) + (sm * nrm);
          blas::xrotg(&s[k - 1], &r, &sqds, &sm);
          r = (sqds * e[k - 1]) + (sm * s[k]);
          s[k] = ((-sm) * e[k - 1]) + (sqds * s[k]);
          nrm = sm * e[k];
          e[k] *= sqds;
        }
        e[m - 1] = r;
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
            nrm = s[jj];
            s[jj] = s[qq];
            s[qq] = nrm;
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
void d_svd(const double A[3][3], double U[3][3], double s[3], double V[3][3])
{
  double b_A[3][3];
  double b_s[3];
  double e[3];
  double work[3];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  double ztest;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  for (kase = 0; kase < 3; kase++) {
    b_s[kase] = 0.0;
    e[kase] = 0.0;
    work[kase] = 0.0;
    b_A[kase][0] = A[kase][0];
    U[kase][0] = 0.0;
    V[kase][0] = 0.0;
    b_A[kase][1] = A[kase][1];
    U[kase][1] = 0.0;
    V[kase][1] = 0.0;
    b_A[kase][2] = A[kase][2];
    U[kase][2] = 0.0;
    V[kase][2] = 0.0;
  }
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + (3 * q)) + 1;
    apply_transform = false;
    nrm = blas::d_xnrm2(3 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&b_A[0][0])[qq - 1] < 0.0) {
        ztest = -nrm;
        b_s[q] = -nrm;
      } else {
        ztest = nrm;
        b_s[q] = nrm;
      }
      if (std::abs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&b_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 2;
        for (k = qq; k <= qjj; k++) {
          (&b_A[0][0])[k - 1] /= b_s[q];
        }
      }
      (&b_A[0][0])[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + (3 * (kase - 1));
      if (apply_transform) {
        blas::b_xaxpy(
            3 - q, -(blas::b_xdotc(3 - q, b_A, qq, b_A, qjj + 1) / b_A[q][q]),
            qq, b_A, qjj + 1);
      }
      e[kase - 1] = (&b_A[0][0])[qjj];
    }
    for (k = q + 1; k < 4; k++) {
      U[q][k - 1] = b_A[q][k - 1];
    }
    if ((q + 1) <= 1) {
      nrm = blas::e_xnrm2(2, e, 2);
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
          blas::c_xaxpy(2, e[kase - 1], b_A, (3 * (kase - 1)) + 2, work, 2);
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::d_xaxpy(2, (-e[kase - 1]) / e[1], work, 2, b_A,
                        (3 * (kase - 1)) + 2);
        }
      }
      for (k = qp1; k < 4; k++) {
        V[0][k - 1] = e[k - 1];
      }
    }
  }
  m = 1;
  b_s[2] = b_A[2][2];
  e[1] = b_A[2][1];
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
        blas::b_xaxpy(
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
      blas::b_xaxpy(2, -(blas::b_xdotc(2, V, 2, V, 5) / (&V[0][0])[1]), 2, V,
                    5);
      blas::b_xaxpy(2, -(blas::b_xdotc(2, V, 2, V, 8) / (&V[0][0])[1]), 2, V,
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
    ztest = b_s[q];
    if (ztest != 0.0) {
      rt = std::abs(ztest);
      nrm = ztest / rt;
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
      ztest = e[q];
      if (ztest != 0.0) {
        rt = std::abs(ztest);
        nrm = rt / ztest;
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
    int exitg1;
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
          ztest = std::abs(b_s[kase - 1]);
          if ((ztest <= (2.2204460492503131E-16 * nrm)) ||
              (ztest <= 1.0020841800044864E-292)) {
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
      ztest = e[m];
      e[m] = 0.0;
      qjj = m + 1;
      for (k = qjj; k >= (q + 1); k--) {
        blas::xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        if (k > (q + 1)) {
          ztest = (-sqds) * e[0];
          e[0] *= sm;
        }
        blas::b_xrot(V, (3 * (k - 1)) + 1, (3 * (m + 1)) + 1, sm, sqds);
      }
      break;
    case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        blas::xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = (-sqds) * rt;
        e[k - 1] = rt * sm;
        blas::b_xrot(U, (3 * (k - 1)) + 1, (3 * (q - 1)) + 1, sm, sqds);
      }
      break;
    case 3: {
      double scale;
      kase = m + 1;
      nrm = b_s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(b_s[m])),
                              std::abs(e[m])),
                    std::abs(b_s[q])),
          std::abs(e[q]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      ztest = e[m] / scale;
      sqds = b_s[q] / scale;
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
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= kase; k++) {
        blas::xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > (q + 1)) {
          e[0] = ztest;
        }
        nrm = e[k - 1];
        rt = b_s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * rt);
        ztest = sqds * b_s[k];
        b_s[k] *= sm;
        blas::b_xrot(V, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
        b_s[k - 1] = (sm * rt) + (sqds * nrm);
        blas::xrotg(&b_s[k - 1], &ztest, &sm, &sqds);
        ztest = (sm * e[k - 1]) + (sqds * b_s[k]);
        b_s[k] = ((-sqds) * e[k - 1]) + (sm * b_s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::b_xrot(U, (3 * (k - 1)) + 1, (3 * k) + 1, sm, sqds);
      }
      e[m] = ztest;
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
// Arguments    : const double A[9][9]
//                double U[9][9]
//                double s[9]
//                double V[9][9]
// Return Type  : void
//
void e_svd(const double A[9][9], double U[9][9], double s[9], double V[9][9])
{
  double b_A[9][9];
  double e[9];
  double work[9];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  double ztest;
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
      b_A[qjj][qp1jj] = A[qjj][qp1jj];
      U[qjj][qp1jj] = 0.0;
      V[qjj][qp1jj] = 0.0;
    }
  }
  for (q = 0; q < 8; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq = (q + (9 * q)) + 1;
    apply_transform = false;
    nrm = blas::f_xnrm2(9 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if ((&b_A[0][0])[qq - 1] < 0.0) {
        ztest = -nrm;
        s[q] = -nrm;
      } else {
        ztest = nrm;
        s[q] = nrm;
      }
      if (std::abs(ztest) >= 1.0020841800044864E-292) {
        nrm = 1.0 / ztest;
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          (&b_A[0][0])[k - 1] *= nrm;
        }
      } else {
        qp1jj = (qq - q) + 8;
        for (k = qq; k <= qp1jj; k++) {
          (&b_A[0][0])[k - 1] /= s[q];
        }
      }
      (&b_A[0][0])[qq - 1]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (k = qp1; k < 10; k++) {
      qjj = q + (9 * (k - 1));
      if (apply_transform) {
        blas::c_xaxpy(
            9 - q, -(blas::c_xdotc(9 - q, b_A, qq, b_A, qjj + 1) / b_A[q][q]),
            qq, b_A, qjj + 1);
      }
      e[k - 1] = (&b_A[0][0])[qjj];
    }
    for (k = q + 1; k < 10; k++) {
      U[q][k - 1] = b_A[q][k - 1];
    }
    if ((q + 1) <= 7) {
      nrm = blas::g_xnrm2(8 - q, e, q + 2);
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
          blas::e_xaxpy(8 - q, e[k - 1], b_A, (q + (9 * (k - 1))) + 2, work,
                        q + 2);
        }
        for (k = qp1; k < 10; k++) {
          blas::f_xaxpy(8 - q, (-e[k - 1]) / e[q + 1], work, q + 2, b_A,
                        (q + (9 * (k - 1))) + 2);
        }
      }
      for (k = qp1; k < 10; k++) {
        V[q][k - 1] = e[k - 1];
      }
    }
  }
  m = 7;
  s[8] = b_A[8][8];
  e[7] = b_A[8][7];
  e[8] = 0.0;
  (void)std::memset(&U[8][0], 0, 9U * (sizeof(double)));
  U[8][8] = 1.0;
  for (q = 7; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + (9 * q);
    if (s[q] != 0.0) {
      for (k = qp1; k < 10; k++) {
        qjj = (q + (9 * (k - 1))) + 1;
        blas::c_xaxpy(
            9 - q, -(blas::c_xdotc(9 - q, U, qq + 1, U, qjj) / (&U[0][0])[qq]),
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
        blas::c_xaxpy(
            8 - q,
            -(blas::c_xdotc(8 - q, V, qjj, V, qp1jj) / (&V[0][0])[qjj - 1]),
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
    ztest = s[q];
    if (ztest != 0.0) {
      rt = std::abs(ztest);
      nrm = ztest / rt;
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
      ztest = e[q];
      if (ztest != 0.0) {
        rt = std::abs(ztest);
        nrm = rt / ztest;
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
      boolean_T exitg2;
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
          ztest = std::abs(s[qjj - 1]);
          if ((ztest <= (2.2204460492503131E-16 * nrm)) ||
              (ztest <= 1.0020841800044864E-292)) {
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
    case 1:
      ztest = e[m];
      e[m] = 0.0;
      qp1jj = m + 1;
      for (k = qp1jj; k >= (q + 1); k--) {
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        if (k > (q + 1)) {
          rt = e[k - 2];
          ztest = (-sqds) * rt;
          e[k - 2] = rt * sm;
        }
        blas::c_xrot(V, (9 * (k - 1)) + 1, (9 * (m + 1)) + 1, sm, sqds);
      }
      break;
    case 2:
      ztest = e[q - 1];
      e[q - 1] = 0.0;
      for (k = q + 1; k <= (m + 2); k++) {
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        rt = e[k - 1];
        ztest = (-sqds) * rt;
        e[k - 1] = rt * sm;
        blas::c_xrot(U, (9 * (k - 1)) + 1, (9 * (q - 1)) + 1, sm, sqds);
      }
      break;
    case 3: {
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
      ztest = e[m] / scale;
      sqds = s[q] / scale;
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
      nrm = sqds * (e[q] / scale);
      for (k = q + 1; k <= qjj; k++) {
        blas::xrotg(&ztest, &nrm, &sm, &sqds);
        if (k > (q + 1)) {
          e[k - 2] = ztest;
        }
        nrm = e[k - 1];
        rt = s[k - 1];
        e[k - 1] = (sm * nrm) - (sqds * rt);
        ztest = sqds * s[k];
        s[k] *= sm;
        blas::c_xrot(V, (9 * (k - 1)) + 1, (9 * k) + 1, sm, sqds);
        s[k - 1] = (sm * rt) + (sqds * nrm);
        blas::xrotg(&s[k - 1], &ztest, &sm, &sqds);
        ztest = (sm * e[k - 1]) + (sqds * s[k]);
        s[k] = ((-sqds) * e[k - 1]) + (sm * s[k]);
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::c_xrot(U, (9 * (k - 1)) + 1, (9 * k) + 1, sm, sqds);
      }
      e[m] = ztest;
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
        blas::c_xswap(V, (9 * q) + 1, (9 * (q + 1)) + 1);
        blas::c_xswap(U, (9 * q) + 1, (9 * (q + 1)) + 1);
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
// File trailer for svd1.cpp
//
// [EOF]
//
