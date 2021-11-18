//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bwlookup.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 17-Nov-2021 17:42:35
//

// Include Files
#include "bwlookup.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const ::coder::array<bool, 2U> &bwin
//                ::coder::array<bool, 2U> &c_B
// Return Type  : void
//
namespace coder {
void bwlookup(const ::coder::array<bool, 2U> &bwin,
              ::coder::array<bool, 2U> &c_B)
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
  int c_rowInd;
  int i4;
  int lookUpInd;
  c_B.set_size(bwin.size(0), bwin.size(1));
  if ((bwin.size(0) != 0) && (bwin.size(1) != 0)) {
    bool guard1{false};
    inDims[0] = static_cast<unsigned int>(bwin.size(0));
    inDims[1] = static_cast<unsigned int>(bwin.size(1));
    guard1 = false;
    if (bwin.size(0) >= 2) {
      if (bwin.size(1) >= 2) {
        int b_i;
        int colInd_tmp;
        int i3;
        int i5;
        int ub_loop;
        //  Process a 3x3 neighborhood centered around the pixel being
        //  processed. process the first column first row element
        c_B[0] = lut[((((static_cast<int>(bwin[0])) * 16) +
                       ((static_cast<int>(bwin[1])) * 32)) +
                      ((static_cast<int>(bwin[bwin.size(0)])) * 128)) +
                     ((static_cast<int>(bwin[bwin.size(0) + 1])) * 256)];
        //  process the first column interior elements
        b_i = bwin.size(0);
        for (int rowInd{0}; rowInd <= (b_i - 3); rowInd++) {
          c_B[rowInd + 1] = lut
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
        c_B[bwin.size(0) - 1] = lut[lookUpInd - 1];
        //  process second column to last but one
        //  column-------------------------
        ub_loop = bwin.size(1) - 3;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    lookUpInd, i4, c_rowInd)

        for (int b_colInd = 0; b_colInd <= ub_loop; b_colInd++) {
          //  process second to last but one row for this column
          i4 = static_cast<int>(inDims[0]);
          for (c_rowInd = 0; c_rowInd <= (i4 - 3); c_rowInd++) {
            lookUpInd =
                (((((((((static_cast<int>(
                            bwin[c_rowInd + (bwin.size(0) * b_colInd)])) +
                        ((static_cast<int>(
                             bwin[(c_rowInd + (bwin.size(0) * b_colInd)) +
                                  1])) *
                         2)) +
                       ((static_cast<int>(
                            bwin[(c_rowInd + (bwin.size(0) * b_colInd)) + 2])) *
                        4)) +
                      ((static_cast<int>(
                           bwin[c_rowInd + (bwin.size(0) * (b_colInd + 1))])) *
                       8)) +
                     ((static_cast<int>(
                          bwin[(c_rowInd + (bwin.size(0) * (b_colInd + 1))) +
                               1])) *
                      16)) +
                    ((static_cast<int>(
                         bwin[(c_rowInd + (bwin.size(0) * (b_colInd + 1))) +
                              2])) *
                     32)) +
                   ((static_cast<int>(
                        bwin[c_rowInd + (bwin.size(0) * (b_colInd + 2))])) *
                    64)) +
                  ((static_cast<int>(
                       bwin[(c_rowInd + (bwin.size(0) * (b_colInd + 2))) +
                            1])) *
                   128)) +
                 ((static_cast<int>(
                      bwin[(c_rowInd + (bwin.size(0) * (b_colInd + 2))) + 2])) *
                  256)) +
                1;
            c_B[(c_rowInd + (c_B.size(0) * (b_colInd + 1))) + 1] =
                lut[lookUpInd - 1];
          }
        }
        i3 = static_cast<int>(inDims[1]);
        for (int c_colInd{0}; c_colInd <= (i3 - 3); c_colInd++) {
          //  process first row element
          c_B[c_B.size(0) * (c_colInd + 1)] =
              lut[((((((static_cast<int>(bwin[bwin.size(0) * c_colInd])) * 2) +
                      ((static_cast<int>(bwin[(bwin.size(0) * c_colInd) + 1])) *
                       4)) +
                     ((static_cast<int>(bwin[bwin.size(0) * (c_colInd + 1)])) *
                      16)) +
                    ((static_cast<int>(
                         bwin[(bwin.size(0) * (c_colInd + 1)) + 1])) *
                     32)) +
                   ((static_cast<int>(bwin[bwin.size(0) * (c_colInd + 2)])) *
                    128)) +
                  ((static_cast<int>(
                       bwin[(bwin.size(0) * (c_colInd + 2)) + 1])) *
                   256)];
          //  process the last row element
          c_B[((static_cast<int>(inDims[0])) + (c_B.size(0) * (c_colInd + 1))) -
              1] =
              lut[(((((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                              (bwin.size(0) * c_colInd)) -
                                             2])) +
                      ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                               (bwin.size(0) * c_colInd)) -
                                              1])) *
                       2)) +
                     ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                              (bwin.size(0) * (c_colInd + 1))) -
                                             2])) *
                      8)) +
                    ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                             (bwin.size(0) * (c_colInd + 1))) -
                                            1])) *
                     16)) +
                   ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                            (bwin.size(0) * (c_colInd + 2))) -
                                           2])) *
                    64)) +
                  ((static_cast<int>(bwin[((static_cast<int>(inDims[0])) +
                                           (bwin.size(0) * (c_colInd + 2))) -
                                          1])) *
                   128)];
        }
        //  end process second column to last but one
        //  column--------------------- process last column first row element
        colInd_tmp = (static_cast<int>(inDims[1])) - 1;
        c_B[c_B.size(0) * ((static_cast<int>(inDims[1])) - 1)] = lut
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
        i5 = static_cast<int>(inDims[0]);
        for (int d_rowInd{0}; d_rowInd <= (i5 - 3); d_rowInd++) {
          c_B[(d_rowInd + (c_B.size(0) * colInd_tmp)) + 1] =
              lut[(((((static_cast<int>(
                          bwin[d_rowInd + (bwin.size(0) * (colInd_tmp - 1))])) +
                      ((static_cast<int>(
                           bwin[(d_rowInd + (bwin.size(0) * (colInd_tmp - 1))) +
                                1])) *
                       2)) +
                     ((static_cast<int>(
                          bwin[(d_rowInd + (bwin.size(0) * (colInd_tmp - 1))) +
                               2])) *
                      4)) +
                    ((static_cast<int>(
                         bwin[d_rowInd + (bwin.size(0) * colInd_tmp)])) *
                     8)) +
                   ((static_cast<int>(
                        bwin[(d_rowInd + (bwin.size(0) * colInd_tmp)) + 1])) *
                    16)) +
                  ((static_cast<int>(
                       bwin[(d_rowInd + (bwin.size(0) * colInd_tmp)) + 2])) *
                   32)];
        }
        //  process the last column last row element
        c_B[((static_cast<int>(inDims[0])) +
             (c_B.size(0) * ((static_cast<int>(inDims[1])) - 1))) -
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
        c_B[0] = lut[(static_cast<int>(bwin[0])) * 16];
      }
      if (bwin.size(0) > 1) {
        int i1;
        //  input size is Nx1
        c_B[0] = lut[((static_cast<int>(bwin[0])) * 16) +
                     ((static_cast<int>(bwin[1])) * 32)];
        i1 = bwin.size(0);
        for (int b_rowInd{0}; b_rowInd <= (i1 - 3); b_rowInd++) {
          c_B[b_rowInd + 1] =
              lut[(((static_cast<int>(bwin[b_rowInd])) * 8) +
                   ((static_cast<int>(bwin[b_rowInd + 1])) * 16)) +
                  ((static_cast<int>(bwin[b_rowInd + 2])) * 32)];
        }
        c_B[bwin.size(0) - 1] =
            lut[((static_cast<int>(bwin[bwin.size(0) - 2])) * 8) +
                ((static_cast<int>(bwin[bwin.size(0) - 1])) * 16)];
      }
      if (bwin.size(1) > 1) {
        int i2;
        //  input size is 1xN
        c_B[0] = lut[((static_cast<int>(bwin[0])) * 16) +
                     ((static_cast<int>(bwin[bwin.size(0)])) * 128)];
        i2 = bwin.size(1);
        for (int colInd{0}; colInd <= (i2 - 3); colInd++) {
          c_B[c_B.size(0) * (colInd + 1)] = lut
              [(((static_cast<int>(bwin[bwin.size(0) * colInd])) * 2) +
                ((static_cast<int>(bwin[bwin.size(0) * (colInd + 1)])) * 16)) +
               ((static_cast<int>(bwin[bwin.size(0) * (colInd + 2)])) * 128)];
        }
        c_B[c_B.size(0) * (bwin.size(1) - 1)] =
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
