//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ITER_API_data.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 21-Jul-2022 16:01:17
//

// Include Files
#include "ITER_API_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
namespace ITER {
unsigned int method;

unsigned int state;

unsigned int b_state[2];

bool state_not_empty;

#if defined(_OPENMP)
extern omp_nest_lock_t calibrateOneCamera_nestLockGlobal;
#endif

const signed char iv[3][3]{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

const double dv[2]{0.14592274678111589, 0.85407725321888417};

const char cv[19]{'l', 'e', 'v', 'e', 'n', 'b', 'e', 'r', 'g', '-',
                  'm', 'a', 'r', 'q', 'u', 'a', 'r', 'd', 't'};

const char cv1[128]{
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\x07', '\x08',
    '	',   '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

bool isInitialized_ITER_API{false};

} // namespace ITER

//
// File trailer for ITER_API_data.cpp
//
// [EOF]
//
