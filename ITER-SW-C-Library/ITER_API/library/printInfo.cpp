//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: printInfo.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "printInfo.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// Arguments    : bool newBlocking
//                int PROBLEM_TYPE
//                double alpha
//                double stepNorm
//                int activeConstrChangedType
//                int localActiveConstrIdx
//                int activeSetChangeID
//                double solution_fstar
//                double solution_firstorderopt
//                double solution_maxConstr
//                int solution_iterations
//                const int workingset_indexLB[8]
//                const int workingset_indexUB[8]
//                int b_workingset_nActiveConstr
// Return Type  : void
//
namespace ITER {
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace display {
void printInfo(bool newBlocking, int PROBLEM_TYPE, double alpha,
               double stepNorm, int activeConstrChangedType,
               int localActiveConstrIdx, int activeSetChangeID,
               double solution_fstar, double solution_firstorderopt,
               double solution_maxConstr, int solution_iterations,
               const int workingset_indexLB[8], const int workingset_indexUB[8],
               int b_workingset_nActiveConstr)
{
  (void)printf("%5i  %14.6e  %14.6e  %14.6e", solution_iterations,
               solution_fstar, solution_firstorderopt, solution_maxConstr);
  (void)fflush(stdout);
  (void)printf("  ");
  (void)fflush(stdout);
  if (std::isnan(alpha)) {
    (void)printf("       -      ");
    (void)fflush(stdout);
  } else {
    (void)printf("%14.6e", alpha);
    (void)fflush(stdout);
  }
  (void)printf("  ");
  (void)fflush(stdout);
  (void)printf("%14.6e", stepNorm);
  (void)fflush(stdout);
  (void)printf("    ");
  (void)fflush(stdout);
  if (newBlocking || (activeSetChangeID == -1)) {
    int b_localActiveConstrIdx;
    if (newBlocking) {
      activeSetChangeID = 1;
    }
    b_localActiveConstrIdx = localActiveConstrIdx;
    switch (activeSetChangeID) {
    case -1:
      (void)printf("-");
      (void)fflush(stdout);
      break;
    case 1:
      (void)printf("+");
      (void)fflush(stdout);
      break;
    default:
      (void)printf(" ");
      (void)fflush(stdout);
      break;
    }
    switch (activeConstrChangedType) {
    case 3:
      (void)printf("AINEQ");
      (void)fflush(stdout);
      break;
    case 4:
      (void)printf("LOWER");
      (void)fflush(stdout);
      b_localActiveConstrIdx = workingset_indexLB[localActiveConstrIdx - 1];
      break;
    case 5:
      (void)printf("UPPER");
      (void)fflush(stdout);
      b_localActiveConstrIdx = workingset_indexUB[localActiveConstrIdx - 1];
      break;
    default:
      (void)printf("SAME ");
      (void)fflush(stdout);
      b_localActiveConstrIdx = -1;
      break;
    }
    (void)printf("(%-5i)", b_localActiveConstrIdx);
    (void)fflush(stdout);
  } else {
    (void)printf(" SAME ");
    (void)fflush(stdout);
    (void)printf("(%-5i)", -1);
    (void)fflush(stdout);
  }
  (void)printf("           ");
  (void)fflush(stdout);
  (void)printf("%5i", b_workingset_nActiveConstr);
  (void)fflush(stdout);
  (void)printf("    ");
  (void)fflush(stdout);
  switch (PROBLEM_TYPE) {
  case 1:
    (void)printf("Phase One");
    (void)fflush(stdout);
    break;
  case 2:
    (void)printf("Regularized");
    (void)fflush(stdout);
    break;
  case 4:
    (void)printf("Phase One Reg");
    (void)fflush(stdout);
    break;
  default:
    (void)printf("Normal");
    (void)fflush(stdout);
    break;
  }
  (void)printf("\n");
  (void)fflush(stdout);
}

} // namespace display
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder
} // namespace ITER

//
// File trailer for printInfo.cpp
//
// [EOF]
//
