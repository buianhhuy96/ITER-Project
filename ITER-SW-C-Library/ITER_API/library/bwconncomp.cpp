//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwconncomp.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "bwconncomp.h"
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &varargin_1
//                double *CC_Connectivity
//                double CC_ImageSize[2]
//                double *CC_NumObjects
//                ::coder::array<double, 1U> &CC_RegionIndices
//                ::coder::array<int, 1U> &CC_RegionLengths
// Return Type  : void
//
namespace ITER {
namespace coder {
void bwconncomp(const ::coder::array<bool, 2U> &varargin_1,
                double *CC_Connectivity, double CC_ImageSize[2],
                double *CC_NumObjects,
                ::coder::array<double, 1U> &CC_RegionIndices,
                ::coder::array<int, 1U> &CC_RegionLengths)
{
  ::coder::array<int, 1U> b_pixelIdxList;
  ::coder::array<int, 1U> b_x;
  ::coder::array<int, 1U> endRow;
  ::coder::array<int, 1U> idxCount;
  ::coder::array<int, 1U> labelForEachRun;
  ::coder::array<int, 1U> labelsRenumbered;
  ::coder::array<int, 1U> startCol;
  ::coder::array<int, 1U> startRow;
  double b_CC_NumObjects;
  int numRuns;
  numRuns = 0;
  if (varargin_1.size(0) != 0) {
    if (varargin_1.size(1) != 0) {
      int b_i;
      b_i = varargin_1.size(1);
      for (int col{0}; col < b_i; col++) {
        int i1;
        if (varargin_1[varargin_1.size(0) * col]) {
          numRuns++;
        }
        i1 = varargin_1.size(0);
        for (int k{0}; k <= (i1 - 2); k++) {
          if (varargin_1[(k + (varargin_1.size(0) * col)) + 1]) {
            if (!varargin_1[k + (varargin_1.size(0) * col)]) {
              numRuns++;
            }
          }
        }
      }
    }
  }
  if (numRuns == 0) {
    CC_ImageSize[0] = static_cast<double>(varargin_1.size(0));
    CC_ImageSize[1] = static_cast<double>(varargin_1.size(1));
    b_CC_NumObjects = 0.0;
    CC_RegionIndices.set_size(0);
    CC_RegionLengths.set_size(1);
    CC_RegionLengths[0] = 0;
  } else {
    double numComponents;
    int b_k;
    int b_loop_ub;
    int c_M;
    int c_loop_ub;
    int currentColumn;
    int d_loop_ub;
    int e_loop_ub;
    int firstRunOnPreviousColumn;
    int firstRunOnThisColumn;
    int i2;
    int lastRunOnPreviousColumn;
    int loop_ub;
    int loop_ub_tmp;
    int nextLabel;
    int runCounter;
    startRow.set_size(numRuns);
    endRow.set_size(numRuns);
    startCol.set_size(numRuns);
    c_M = varargin_1.size(0);
    runCounter = 0;
    i2 = varargin_1.size(1);
    for (int b_col{0}; b_col < i2; b_col++) {
      int row;
      row = 1;
      while (row <= c_M) {
        bool exitg1;
        exitg1 = false;
        while ((!exitg1) && (row <= c_M)) {
          if (!varargin_1[(row + (varargin_1.size(0) * b_col)) - 1]) {
            row++;
          } else {
            exitg1 = true;
          }
        }
        if (row <= c_M) {
          if (varargin_1[(row + (varargin_1.size(0) * b_col)) - 1]) {
            startCol[runCounter] = b_col + 1;
            startRow[runCounter] = row;
            exitg1 = false;
            while ((!exitg1) && (row <= c_M)) {
              if (varargin_1[(row + (varargin_1.size(0) * b_col)) - 1]) {
                row++;
              } else {
                exitg1 = true;
              }
            }
            endRow[runCounter] = row - 1;
            runCounter++;
          }
        }
      }
    }
    labelForEachRun.set_size(numRuns);
    loop_ub = numRuns;
    if ((static_cast<int>(numRuns < 4)) != 0) {
      for (int i3{0}; i3 < numRuns; i3++) {
        labelForEachRun[i3] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i3 = 0; i3 < loop_ub; i3++) {
        labelForEachRun[i3] = 0;
      }
    }
    b_k = 0;
    currentColumn = 1;
    nextLabel = 1;
    firstRunOnPreviousColumn = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 0;
    while ((b_k + 1) <= numRuns) {
      if (startCol[b_k] == (currentColumn + 1)) {
        firstRunOnPreviousColumn = firstRunOnThisColumn + 1;
        firstRunOnThisColumn = b_k;
        lastRunOnPreviousColumn = b_k;
        currentColumn = startCol[b_k];
      } else if (startCol[b_k] > (currentColumn + 1)) {
        firstRunOnPreviousColumn = -1;
        lastRunOnPreviousColumn = -1;
        firstRunOnThisColumn = b_k;
        currentColumn = startCol[b_k];
      } else {
        /* no actions */
      }
      if (firstRunOnPreviousColumn >= 0) {
        int p;
        p = firstRunOnPreviousColumn - 1;
        while ((p + 1) <= lastRunOnPreviousColumn) {
          if (endRow[b_k] >= (startRow[p] - 1)) {
            if (startRow[b_k] <= (endRow[p] + 1)) {
              if (labelForEachRun[b_k] == 0) {
                labelForEachRun[b_k] = labelForEachRun[p];
                nextLabel++;
              } else if (labelForEachRun[b_k] != labelForEachRun[p]) {
                int root_k;
                int root_p;
                root_k = b_k;
                while ((root_k + 1) != labelForEachRun[root_k]) {
                  labelForEachRun[root_k] =
                      labelForEachRun[labelForEachRun[root_k] - 1];
                  root_k = labelForEachRun[root_k] - 1;
                }
                root_p = p;
                while ((root_p + 1) != labelForEachRun[root_p]) {
                  labelForEachRun[root_p] =
                      labelForEachRun[labelForEachRun[root_p] - 1];
                  root_p = labelForEachRun[root_p] - 1;
                }
                if ((root_k + 1) != (root_p + 1)) {
                  if ((root_p + 1) < (root_k + 1)) {
                    labelForEachRun[root_k] = root_p + 1;
                    labelForEachRun[b_k] = root_p + 1;
                  } else {
                    labelForEachRun[root_p] = root_k + 1;
                    labelForEachRun[p] = root_k + 1;
                  }
                }
              } else {
                /* no actions */
              }
            }
          }
          p++;
        }
      }
      if (labelForEachRun[b_k] == 0) {
        labelForEachRun[b_k] = nextLabel;
        nextLabel++;
      }
      b_k++;
    }
    labelsRenumbered.set_size(labelForEachRun.size(0));
    numComponents = 0.0;
    for (int c_k{0}; c_k < numRuns; c_k++) {
      if (labelForEachRun[c_k] == (c_k + 1)) {
        numComponents++;
        labelsRenumbered[c_k] = static_cast<int>(numComponents);
      }
      labelsRenumbered[c_k] = labelsRenumbered[labelForEachRun[c_k] - 1];
    }
    loop_ub_tmp = static_cast<int>(numComponents);
    CC_RegionLengths.set_size(loop_ub_tmp);
    b_loop_ub = static_cast<int>(numComponents);
    if ((static_cast<int>((static_cast<int>(numComponents)) < 4)) != 0) {
      for (int i4{0}; i4 < loop_ub_tmp; i4++) {
        CC_RegionLengths[i4] = 0;
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i4 = 0; i4 < b_loop_ub; i4++) {
        CC_RegionLengths[i4] = 0;
      }
    }
    for (int d_k{0}; d_k < numRuns; d_k++) {
      if (labelsRenumbered[d_k] > 0) {
        CC_RegionLengths[labelsRenumbered[d_k] - 1] =
            ((CC_RegionLengths[labelsRenumbered[d_k] - 1] + endRow[d_k]) -
             startRow[d_k]) +
            1;
      }
    }
    b_pixelIdxList.set_size(
        static_cast<int>(c_combineVectorElements(CC_RegionLengths)));
    b_x.set_size(CC_RegionLengths.size(0));
    c_loop_ub = CC_RegionLengths.size(0);
    if ((static_cast<int>(CC_RegionLengths.size(0) < 4)) != 0) {
      for (int i5{0}; i5 < c_loop_ub; i5++) {
        b_x[i5] = CC_RegionLengths[i5];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i5 = 0; i5 < c_loop_ub; i5++) {
        b_x[i5] = CC_RegionLengths[i5];
      }
    }
    if (CC_RegionLengths.size(0) != 1) {
      if (CC_RegionLengths.size(0) != 0) {
        if (CC_RegionLengths.size(0) != 1) {
          int i6;
          i6 = CC_RegionLengths.size(0);
          for (int e_k{0}; e_k <= (i6 - 2); e_k++) {
            b_x[e_k + 1] = b_x[e_k] + b_x[e_k + 1];
          }
        }
      }
    }
    idxCount.set_size(b_x.size(0) + 1);
    idxCount[0] = 0;
    d_loop_ub = b_x.size(0);
    if ((static_cast<int>(b_x.size(0) < 4)) != 0) {
      for (int i7{0}; i7 < d_loop_ub; i7++) {
        idxCount[i7 + 1] = b_x[i7];
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i7 = 0; i7 < d_loop_ub; i7++) {
        idxCount[i7 + 1] = b_x[i7];
      }
    }
    for (int g_k{0}; g_k < numRuns; g_k++) {
      int b_i8;
      int column_offset;
      column_offset = (startCol[g_k] - 1) * varargin_1.size(0);
      b_i8 = labelsRenumbered[g_k];
      if (labelsRenumbered[g_k] > 0) {
        int i10;
        int i9;
        i9 = startRow[g_k];
        i10 = endRow[g_k];
        for (int rowidx{i9}; rowidx <= i10; rowidx++) {
          idxCount[b_i8 - 1] = idxCount[b_i8 - 1] + 1;
          b_pixelIdxList[idxCount[b_i8 - 1] - 1] = rowidx + column_offset;
        }
      }
    }
    CC_ImageSize[0] = static_cast<double>(varargin_1.size(0));
    CC_ImageSize[1] = static_cast<double>(varargin_1.size(1));
    b_CC_NumObjects = numComponents;
    CC_RegionIndices.set_size(b_pixelIdxList.size(0));
    e_loop_ub = b_pixelIdxList.size(0);
    if ((static_cast<int>(b_pixelIdxList.size(0) < 4)) != 0) {
      for (int i11{0}; i11 < e_loop_ub; i11++) {
        CC_RegionIndices[i11] = static_cast<double>(b_pixelIdxList[i11]);
      }
    } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

      for (int i11 = 0; i11 < e_loop_ub; i11++) {
        CC_RegionIndices[i11] = static_cast<double>(b_pixelIdxList[i11]);
      }
    }
  }
  *CC_Connectivity = 8.0;
  *CC_NumObjects = b_CC_NumObjects;
}

} // namespace coder
} // namespace ITER

//
// File trailer for bwconncomp.cpp
//
// [EOF]
//
