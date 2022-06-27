//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sortLambdaQP.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Apr-2022 09:07:06
//

// Include Files
#include "sortLambdaQP.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : double lambda[15]
//                int WorkingSet_nActiveConstr
//                const int b_WorkingSet_sizes[5]
//                const int b_WorkingSet_isActiveIdx[6]
//                const int WorkingSet_Wid[15]
//                const int WorkingSet_Wlocalidx[15]
//                double workspace[8][15]
// Return Type  : void
//
namespace coder {
namespace optim {
namespace coder {
namespace qpactiveset {
namespace parseoutput {
void sortLambdaQP(double lambda[15], int WorkingSet_nActiveConstr,
                  const int b_WorkingSet_sizes[5],
                  const int b_WorkingSet_isActiveIdx[6],
                  const int WorkingSet_Wid[15],
                  const int WorkingSet_Wlocalidx[15], double workspace[8][15])
{
  if (WorkingSet_nActiveConstr != 0) {
    int currentMplier;
    int idx;
    int mAll;
    mAll = ((((b_WorkingSet_sizes[0] + b_WorkingSet_sizes[1]) +
              b_WorkingSet_sizes[3]) +
             b_WorkingSet_sizes[4]) +
            b_WorkingSet_sizes[2]) -
           1;
    if ((static_cast<int>((mAll + 1) < 4)) != 0) {
      for (int k{0}; k <= mAll; k++) {
        (&workspace[0][0])[k] = lambda[k];
        lambda[k] = 0.0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int k = 0; k <= mAll; k++) {
        (&workspace[0][0])[k] = lambda[k];
        lambda[k] = 0.0;
      }
    }
    currentMplier = 0;
    idx = 0;
    while (((idx + 1) <= WorkingSet_nActiveConstr) &&
           (WorkingSet_Wid[idx] <= 2)) {
      int b_WorkingSet_Wid;
      if (WorkingSet_Wid[idx] == 1) {
        b_WorkingSet_Wid = 1;
      } else {
        b_WorkingSet_Wid = b_WorkingSet_isActiveIdx[1];
      }
      lambda[(b_WorkingSet_Wid + WorkingSet_Wlocalidx[idx]) - 2] =
          (&workspace[0][0])[currentMplier];
      currentMplier++;
      idx++;
    }
    while ((idx + 1) <= WorkingSet_nActiveConstr) {
      int idxOffset;
      switch (WorkingSet_Wid[idx]) {
      case 3:
        idxOffset = b_WorkingSet_isActiveIdx[2];
        break;
      case 4:
        idxOffset = b_WorkingSet_isActiveIdx[3];
        break;
      default:
        idxOffset = b_WorkingSet_isActiveIdx[4];
        break;
      }
      lambda[(idxOffset + WorkingSet_Wlocalidx[idx]) - 2] =
          (&workspace[0][0])[currentMplier];
      currentMplier++;
      idx++;
    }
  }
}

} // namespace parseoutput
} // namespace qpactiveset
} // namespace coder
} // namespace optim
} // namespace coder

//
// File trailer for sortLambdaQP.cpp
//
// [EOF]
//
