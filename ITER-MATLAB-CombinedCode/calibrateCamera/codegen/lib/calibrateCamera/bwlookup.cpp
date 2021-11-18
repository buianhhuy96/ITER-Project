//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwlookup.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Oct-2021 21:47:38
//

// Include Files
#include "bwlookup.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<boolean_T, 2U> &bwin
//                ::coder::array<boolean_T, 2U> &c_B
// Return Type  : void
//
namespace Codegen {
namespace coder {
void bwlookup(const ::coder::array<boolean_T, 2U> &bwin,
              ::coder::array<boolean_T, 2U> &c_B)
{
  static const boolean_T lut[512]{
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
  c_B.set_size(bwin.size(0), bwin.size(1));
  if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
    int32_T b_i;
    int32_T colInd;
    int32_T rowInd;
    uint32_T inDims_idx_0;
    uint32_T inDims_idx_1;
    boolean_T guard1{false};
    inDims_idx_0 = static_cast<uint32_T>(bwin.size(0));
    inDims_idx_1 = static_cast<uint32_T>(bwin.size(1));
    guard1 = false;
    if (bwin.size(0) >= 2) {
      if (bwin.size(1) >= 2) {
        //  Process a 3x3 neighborhood centered around the pixel being
        //  processed. process the first column first row element
        c_B[0] = lut[((((static_cast<int32_T>(bwin[0])) * 16) +
                       ((static_cast<int32_T>(bwin[1])) * 32)) +
                      ((static_cast<int32_T>(bwin[bwin.size(0)])) * 128)) +
                     ((static_cast<int32_T>(bwin[bwin.size(0) + 1])) * 256)];
        //  process the first column interior elements
        b_i = bwin.size(0);
        for (rowInd = 0; rowInd <= (b_i - 3); rowInd++) {
          c_B[rowInd + 1] =
              lut[((((((static_cast<int32_T>(bwin[rowInd])) * 8) +
                      ((static_cast<int32_T>(bwin[rowInd + 1])) * 16)) +
                     ((static_cast<int32_T>(bwin[rowInd + 2])) * 32)) +
                    ((static_cast<int32_T>(bwin[rowInd + bwin.size(0)])) *
                     64)) +
                   ((static_cast<int32_T>(bwin[(rowInd + bwin.size(0)) + 1])) *
                    128)) +
                  ((static_cast<int32_T>(bwin[(rowInd + bwin.size(0)) + 2])) *
                   256)];
        }
        //  process the first column last row element
        c_B[bwin.size(0) - 1] = lut
            [((((static_cast<int32_T>(bwin[bwin.size(0) - 2])) * 8) +
               ((static_cast<int32_T>(bwin[bwin.size(0) - 1])) * 16)) +
              ((static_cast<int32_T>(bwin[(bwin.size(0) + bwin.size(0)) - 2])) *
               64)) +
             ((static_cast<int32_T>(bwin[(bwin.size(0) + bwin.size(0)) - 1])) *
              128)];
        //  process second column to last but one
        //  column-------------------------
        b_i = bwin.size(1);
        for (colInd = 0; colInd <= (b_i - 3); colInd++) {
          int32_T i1;
          //  process second to last but one row for this column
          i1 = static_cast<int32_T>(inDims_idx_0);
          for (rowInd = 0; rowInd <= (i1 - 3); rowInd++) {
            c_B[(rowInd + (c_B.size(0) * (colInd + 1))) + 1] = lut
                [((((((((static_cast<int32_T>(
                            bwin[rowInd + (bwin.size(0) * colInd)])) +
                        ((static_cast<int32_T>(
                             bwin[(rowInd + (bwin.size(0) * colInd)) + 1])) *
                         2)) +
                       ((static_cast<int32_T>(
                            bwin[(rowInd + (bwin.size(0) * colInd)) + 2])) *
                        4)) +
                      ((static_cast<int32_T>(
                           bwin[rowInd + (bwin.size(0) * (colInd + 1))])) *
                       8)) +
                     ((static_cast<int32_T>(
                          bwin[(rowInd + (bwin.size(0) * (colInd + 1))) + 1])) *
                      16)) +
                    ((static_cast<int32_T>(
                         bwin[(rowInd + (bwin.size(0) * (colInd + 1))) + 2])) *
                     32)) +
                   ((static_cast<int32_T>(
                        bwin[rowInd + (bwin.size(0) * (colInd + 2))])) *
                    64)) +
                  ((static_cast<int32_T>(
                       bwin[(rowInd + (bwin.size(0) * (colInd + 2))) + 1])) *
                   128)) +
                 ((static_cast<int32_T>(
                      bwin[(rowInd + (bwin.size(0) * (colInd + 2))) + 2])) *
                  256)];
          }
        }
        b_i = bwin.size(1);
        for (colInd = 0; colInd <= (b_i - 3); colInd++) {
          //  process first row element
          c_B[c_B.size(0) * (colInd + 1)] = lut
              [((((((static_cast<int32_T>(bwin[bwin.size(0) * colInd])) * 2) +
                   ((static_cast<int32_T>(bwin[(bwin.size(0) * colInd) + 1])) *
                    4)) +
                  ((static_cast<int32_T>(bwin[bwin.size(0) * (colInd + 1)])) *
                   16)) +
                 ((static_cast<int32_T>(
                      bwin[(bwin.size(0) * (colInd + 1)) + 1])) *
                  32)) +
                ((static_cast<int32_T>(bwin[bwin.size(0) * (colInd + 2)])) *
                 128)) +
               ((static_cast<int32_T>(
                    bwin[(bwin.size(0) * (colInd + 2)) + 1])) *
                256)];
          //  process the last row element
          c_B[((static_cast<int32_T>(inDims_idx_0)) +
               (c_B.size(0) * (colInd + 1))) -
              1] =
              lut[(((((static_cast<int32_T>(
                          bwin[((static_cast<int32_T>(inDims_idx_0)) +
                                (bwin.size(0) * colInd)) -
                               2])) +
                      ((static_cast<int32_T>(
                           bwin[((static_cast<int32_T>(inDims_idx_0)) +
                                 (bwin.size(0) * colInd)) -
                                1])) *
                       2)) +
                     ((static_cast<int32_T>(
                          bwin[((static_cast<int32_T>(inDims_idx_0)) +
                                (bwin.size(0) * (colInd + 1))) -
                               2])) *
                      8)) +
                    ((static_cast<int32_T>(
                         bwin[((static_cast<int32_T>(inDims_idx_0)) +
                               (bwin.size(0) * (colInd + 1))) -
                              1])) *
                     16)) +
                   ((static_cast<int32_T>(
                        bwin[((static_cast<int32_T>(inDims_idx_0)) +
                              (bwin.size(0) * (colInd + 2))) -
                             2])) *
                    64)) +
                  ((static_cast<int32_T>(
                       bwin[((static_cast<int32_T>(inDims_idx_0)) +
                             (bwin.size(0) * (colInd + 2))) -
                            1])) *
                   128)];
        }
        //  end process second column to last but one
        //  column--------------------- process last column first row element
        c_B[c_B.size(0) * (bwin.size(1) - 1)] =
            lut[((((static_cast<int32_T>(
                       bwin[bwin.size(0) * (bwin.size(1) - 2)])) *
                   2) +
                  ((static_cast<int32_T>(
                       bwin[(bwin.size(0) * (bwin.size(1) - 2)) + 1])) *
                   4)) +
                 ((static_cast<int32_T>(
                      bwin[bwin.size(0) * (bwin.size(1) - 1)])) *
                  16)) +
                ((static_cast<int32_T>(
                     bwin[(bwin.size(0) * (bwin.size(1) - 1)) + 1])) *
                 32)];
        //  process last column second to last but one element
        b_i = bwin.size(0);
        for (rowInd = 0; rowInd <= (b_i - 3); rowInd++) {
          c_B[(rowInd +
               (c_B.size(0) * ((static_cast<int32_T>(inDims_idx_1)) - 1))) +
              1] =
              lut[(((((static_cast<int32_T>(
                          bwin[rowInd +
                               (bwin.size(0) *
                                ((static_cast<int32_T>(inDims_idx_1)) - 2))])) +
                      ((static_cast<int32_T>(
                           bwin[(rowInd +
                                 (bwin.size(0) *
                                  ((static_cast<int32_T>(inDims_idx_1)) - 2))) +
                                1])) *
                       2)) +
                     ((static_cast<int32_T>(
                          bwin[(rowInd +
                                (bwin.size(0) *
                                 ((static_cast<int32_T>(inDims_idx_1)) - 2))) +
                               2])) *
                      4)) +
                    ((static_cast<int32_T>(
                         bwin[rowInd +
                              (bwin.size(0) *
                               ((static_cast<int32_T>(inDims_idx_1)) - 1))])) *
                     8)) +
                   ((static_cast<int32_T>(
                        bwin[(rowInd +
                              (bwin.size(0) *
                               ((static_cast<int32_T>(inDims_idx_1)) - 1))) +
                             1])) *
                    16)) +
                  ((static_cast<int32_T>(
                       bwin[(rowInd +
                             (bwin.size(0) *
                              ((static_cast<int32_T>(inDims_idx_1)) - 1))) +
                            2])) *
                   32)];
        }
        //  process the last column last row element
        c_B[(bwin.size(0) + (c_B.size(0) * (bwin.size(1) - 1))) - 1] = lut
            [(((static_cast<int32_T>(
                   bwin[(bwin.size(0) + (bwin.size(0) * (bwin.size(1) - 2))) -
                        2])) +
               ((static_cast<int32_T>(
                    bwin[(bwin.size(0) + (bwin.size(0) * (bwin.size(1) - 2))) -
                         1])) *
                2)) +
              ((static_cast<int32_T>(
                   bwin[(bwin.size(0) + (bwin.size(0) * (bwin.size(1) - 1))) -
                        2])) *
               8)) +
             ((static_cast<int32_T>(
                  bwin[(bwin.size(0) + (bwin.size(0) * (bwin.size(1) - 1))) -
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
        c_B[0] = lut[(static_cast<int32_T>(bwin[0])) * 16];
      }
      if (bwin.size(0) > 1) {
        //  input size is Nx1
        c_B[0] = lut[((static_cast<int32_T>(bwin[0])) * 16) +
                     ((static_cast<int32_T>(bwin[1])) * 32)];
        b_i = bwin.size(0);
        for (rowInd = 0; rowInd <= (b_i - 3); rowInd++) {
          c_B[rowInd + 1] =
              lut[(((static_cast<int32_T>(bwin[rowInd])) * 8) +
                   ((static_cast<int32_T>(bwin[rowInd + 1])) * 16)) +
                  ((static_cast<int32_T>(bwin[rowInd + 2])) * 32)];
        }
        c_B[bwin.size(0) - 1] =
            lut[((static_cast<int32_T>(bwin[bwin.size(0) - 2])) * 8) +
                ((static_cast<int32_T>(bwin[bwin.size(0) - 1])) * 16)];
      }
      if (bwin.size(1) > 1) {
        //  input size is 1xN
        c_B[0] = lut[((static_cast<int32_T>(bwin[0])) * 16) +
                     ((static_cast<int32_T>(bwin[bwin.size(0)])) * 128)];
        b_i = bwin.size(1);
        for (colInd = 0; colInd <= (b_i - 3); colInd++) {
          c_B[c_B.size(0) * (colInd + 1)] =
              lut[(((static_cast<int32_T>(bwin[bwin.size(0) * colInd])) * 2) +
                   ((static_cast<int32_T>(bwin[bwin.size(0) * (colInd + 1)])) *
                    16)) +
                  ((static_cast<int32_T>(bwin[bwin.size(0) * (colInd + 2)])) *
                   128)];
        }
        c_B[c_B.size(0) * (bwin.size(1) - 1)] = lut
            [((static_cast<int32_T>(bwin[bwin.size(0) * (bwin.size(1) - 2)])) *
              2) +
             ((static_cast<int32_T>(bwin[bwin.size(0) * (bwin.size(1) - 1)])) *
              16)];
      }
    }
  }
}

} // namespace coder
} // namespace Codegen

//
// File trailer for bwlookup.cpp
//
// [EOF]
//
