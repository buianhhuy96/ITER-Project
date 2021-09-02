//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwlookup.cpp
//
// MATLAB Coder version            : 5.2
// C/C++ source code generated on  : 17-Aug-2021 16:46:43
//

// Include Files
#include "bwlookup.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &bwin
//                ::coder::array<bool, 2U> &B
// Return Type  : void
//
namespace coder {
void bwlookup(const ::coder::array<bool, 2U> &bwin, ::coder::array<bool, 2U> &B)
{
  static const bool lut[512]{
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, true,  true,  true,
      true,  false, true,  true,  true,  true,  true,  true,  false, false,
      true,  true,  false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  false,
      true,  true,  true,  false, true,  true,  false, false, true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, false, false, false, false, false, false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  true,  false, false, true,  true,  false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, false, false, false, false,
      false, false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  false, true,  true,
      true,  false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  false,
      false, false, false, false, false, false, true,  true,  true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, true,  true,  true,  false, true,  true,  true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, true,  true,  true,  false,
      true,  true,  false, false, true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      false, false, true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      true,  false, false, false, false, false, false, false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, true,  false, true,  true,  true,  false, true,  true,
      true,  true,  false, false, true,  true,  false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, true,  false, false, false, false, false,
      false, false, true,  true,  true,  true,  false, false, true,  true,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, true,  false, true,  true,
      true,  false, true,  true,  true,  true,  false, false, true,  true,
      false, false};
  unsigned int inDims[2];
  int b_rowInd;
  int i;
  int lookUpInd;
  B.set_size(bwin.size(0), bwin.size(1));
  if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
    int colInd;
    int rowInd;
    int ub_loop;
    bool guard1{false};
    inDims[0] = static_cast<unsigned int>(bwin.size(0));
    inDims[1] = static_cast<unsigned int>(bwin.size(1));
    guard1 = false;
    if (bwin.size(0) >= 2) {
      if (bwin.size(1) >= 2) {
        //  Process a 3x3 neighborhood centered around the pixel being
        //  processed. process the first column first row element
        B[0] = lut[((((static_cast<int>(bwin[0])) * 16) +
                     ((static_cast<int>(bwin[1])) * 32)) +
                    ((static_cast<int>(bwin[bwin.size(0)])) * 128)) +
                   ((static_cast<int>(bwin[bwin.size(0) + 1])) * 256)];
        //  process the first column interior elements
        ub_loop = bwin.size(0);
        for (rowInd = 0; rowInd <= (ub_loop - 3); rowInd++) {
          B[rowInd + 1] = lut
              [((((((static_cast<int>(bwin[rowInd])) * 8) +
                   ((static_cast<int>(bwin[rowInd + 1])) * 16)) +
                  ((static_cast<int>(bwin[rowInd + 2])) * 32)) +
                 ((static_cast<int>(bwin[rowInd + bwin.size(0)])) * 64)) +
                ((static_cast<int>(bwin[(rowInd + bwin.size(0)) + 1])) * 128)) +
               ((static_cast<int>(bwin[(rowInd + bwin.size(0)) + 2])) * 256)];
        }
        //  process the first column last row element
        lookUpInd =
            (((((static_cast<int>(bwin[bwin.size(0) - 2])) * 8) +
               ((static_cast<int>(bwin[bwin.size(0) - 1])) * 16)) +
              ((static_cast<int>(bwin[(bwin.size(0) + bwin.size(0)) - 2])) *
               64)) +
             ((static_cast<int>(bwin[(bwin.size(0) + bwin.size(0)) - 1])) *
              128)) +
            1;
        B[bwin.size(0) - 1] = lut[lookUpInd - 1];
        //  process second column to last but one
        //  column-------------------------
        ub_loop = bwin.size(1) - 3;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    lookUpInd, i, b_rowInd)

        for (int b_colInd = 0; b_colInd <= ub_loop; b_colInd++) {
          //  process second to last but one row for this column
          i = static_cast<int>(inDims[0]);
          for (b_rowInd = 0; b_rowInd <= (i - 3); b_rowInd++) {
            lookUpInd =
                (((((((((static_cast<int>(
                            bwin[b_rowInd + (bwin.size(0) * b_colInd)])) +
                        ((static_cast<int>(
                             bwin[(b_rowInd + (bwin.size(0) * b_colInd)) +
                                  1])) *
                         2)) +
                       ((static_cast<int>(
                            bwin[(b_rowInd + (bwin.size(0) * b_colInd)) + 2])) *
                        4)) +
                      ((static_cast<int>(
                           bwin[b_rowInd + (bwin.size(0) * (b_colInd + 1))])) *
                       8)) +
                     ((static_cast<int>(
                          bwin[(b_rowInd + (bwin.size(0) * (b_colInd + 1))) +
                               1])) *
                      16)) +
                    ((static_cast<int>(
                         bwin[(b_rowInd + (bwin.size(0) * (b_colInd + 1))) +
                              2])) *
                     32)) +
                   ((static_cast<int>(
                        bwin[b_rowInd + (bwin.size(0) * (b_colInd + 2))])) *
                    64)) +
                  ((static_cast<int>(
                       bwin[(b_rowInd + (bwin.size(0) * (b_colInd + 2))) +
                            1])) *
                   128)) +
                 ((static_cast<int>(
                      bwin[(b_rowInd + (bwin.size(0) * (b_colInd + 2))) + 2])) *
                  256)) +
                1;
            B[(b_rowInd + (B.size(0) * (b_colInd + 1))) + 1] =
                lut[lookUpInd - 1];
          }
        }
        ub_loop = static_cast<int>(inDims[1]);
        for (colInd = 0; colInd <= (ub_loop - 3); colInd++) {
          //  process first row element
          B[B.size(0) * (colInd + 1)] = lut
              [((((((static_cast<int>(bwin[bwin.size(0) * colInd])) * 2) +
                   ((static_cast<int>(bwin[(bwin.size(0) * colInd) + 1])) *
                    4)) +
                  ((static_cast<int>(bwin[bwin.size(0) * (colInd + 1)])) *
                   16)) +
                 ((static_cast<int>(bwin[(bwin.size(0) * (colInd + 1)) + 1])) *
                  32)) +
                ((static_cast<int>(bwin[bwin.size(0) * (colInd + 2)])) * 128)) +
               ((static_cast<int>(bwin[(bwin.size(0) * (colInd + 2)) + 1])) *
                256)];
          //  process the last row element
          B[((static_cast<int>(inDims[0])) + (B.size(0) * (colInd + 1))) - 1] =
              lut[(((((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                              (bwin.size(0) * colInd)) -
                                             2])) +
                      ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                               (bwin.size(0) * colInd)) -
                                              1])) *
                       2)) +
                     ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                              (bwin.size(0) * (colInd + 1))) -
                                             2])) *
                      8)) +
                    ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                             (bwin.size(0) * (colInd + 1))) -
                                            1])) *
                     16)) +
                   ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                            (bwin.size(0) * (colInd + 2))) -
                                           2])) *
                    64)) +
                  ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                           (bwin.size(0) * (colInd + 2))) -
                                          1])) *
                   128)];
        }
        //  end process second column to last but one
        //  column--------------------- process last column first row element
        colInd = (static_cast<int>(inDims[1])) - 1;
        B[B.size(0) * ((static_cast<int>(inDims[1])) - 1)] = lut
            [((((static_cast<int>(
                    bwin[bwin.size(0) * ((static_cast<int>(inDims[1])) - 2)])) *
                2) +
               ((static_cast<int>(
                    bwin[(bwin.size(0) * ((static_cast<int>(inDims[1])) - 2)) +
                         1])) *
                4)) +
              ((static_cast<int>(
                   bwin[bwin.size(0) * ((static_cast<int>(inDims[1])) - 1)])) *
               16)) +
             ((static_cast<int>(
                  bwin[(bwin.size(0) * ((static_cast<int>(inDims[1])) - 1)) +
                       1])) *
              32)];
        //  process last column second to last but one element
        ub_loop = static_cast<int>(inDims[0]);
        for (rowInd = 0; rowInd <= (ub_loop - 3); rowInd++) {
          B[(rowInd + (B.size(0) * colInd)) + 1] = lut
              [(((((static_cast<int>(
                       bwin[rowInd + (bwin.size(0) * (colInd - 1))])) +
                   ((static_cast<int>(
                        bwin[(rowInd + (bwin.size(0) * (colInd - 1))) + 1])) *
                    2)) +
                  ((static_cast<int>(
                       bwin[(rowInd + (bwin.size(0) * (colInd - 1))) + 2])) *
                   4)) +
                 ((static_cast<int>(bwin[rowInd + (bwin.size(0) * colInd)])) *
                  8)) +
                ((static_cast<int>(
                     bwin[(rowInd + (bwin.size(0) * colInd)) + 1])) *
                 16)) +
               ((static_cast<int>(
                    bwin[(rowInd + (bwin.size(0) * colInd)) + 2])) *
                32)];
        }
        //  process the last column last row element
        B[((static_cast<int>(inDims[0])) +
           (B.size(0) * ((static_cast<int>(inDims[1])) - 1))) -
          1] = lut
            [(((static_cast<int>(
                   bwin[((static_cast<int>(inDims[0])) +
                         (bwin.size(0) * ((static_cast<int>(inDims[1])) - 2))) -
                        2])) +
               ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                        (bwin.size(0) *
                                         ((static_cast<int>(inDims[1])) - 2))) -
                                       1])) *
                2)) +
              ((static_cast<int>(
                   bwin[((static_cast<int>(inDims[0])) +
                         (bwin.size(0) * ((static_cast<int>(inDims[1])) - 1))) -
                        2])) *
               8)) +
             ((static_cast<int>(
                  bwin[((static_cast<int>(inDims[0])) +
                        (bwin.size(0) * ((static_cast<int>(inDims[1])) - 1))) -
                       1])) *
              16)];
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      //  input is either 1x1, 1xN or Nx1
      if (bwin.size(0) == bwin.size(1)) {
        //  input size is 1x1
        B[0] = lut[(static_cast<int>(bwin[0])) * 16];
      }
      if (bwin.size(0) > 1) {
        //  input size is Nx1
        B[0] = lut[((static_cast<int>(bwin[0])) * 16) +
                   ((static_cast<int>(bwin[1])) * 32)];
        ub_loop = bwin.size(0);
        for (rowInd = 0; rowInd <= (ub_loop - 3); rowInd++) {
          B[rowInd + 1] = lut[(((static_cast<int>(bwin[rowInd])) * 8) +
                               ((static_cast<int>(bwin[rowInd + 1])) * 16)) +
                              ((static_cast<int>(bwin[rowInd + 2])) * 32)];
        }
        B[bwin.size(0) - 1] =
            lut[((static_cast<int>(bwin[bwin.size(0) - 2])) * 8) +
                ((static_cast<int>(bwin[bwin.size(0) - 1])) * 16)];
      }
      if (bwin.size(1) > 1) {
        //  input size is 1xN
        B[0] = lut[((static_cast<int>(bwin[0])) * 16) +
                   ((static_cast<int>(bwin[bwin.size(0)])) * 128)];
        ub_loop = bwin.size(1);
        for (colInd = 0; colInd <= (ub_loop - 3); colInd++) {
          B[B.size(0) * (colInd + 1)] = lut
              [(((static_cast<int>(bwin[bwin.size(0) * colInd])) * 2) +
                ((static_cast<int>(bwin[bwin.size(0) * (colInd + 1)])) * 16)) +
               ((static_cast<int>(bwin[bwin.size(0) * (colInd + 2)])) * 128)];
        }
        B[B.size(0) * (bwin.size(1) - 1)] =
            lut[((static_cast<int>(bwin[bwin.size(0) * (bwin.size(1) - 2)])) *
                 2) +
                ((static_cast<int>(bwin[bwin.size(0) * (bwin.size(1) - 1)])) *
                 16)];
      }
    }
  }
}

} // namespace coder

//
// File trailer for bwlookup.cpp
//
// [EOF]
//
