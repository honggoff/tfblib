/* SPDX-License-Identifier: BSD-2-Clause */

#pragma once
#include <stdint.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) ((int)(sizeof(a)/sizeof(a[0])))
#define INT_ABS(x) ((x) > 0 ? (x) : (-(x)))

#define MIN(x, y) \
   ({ __typeof__ (x) _x = (x); \
      __typeof__ (y) _y = (y); \
      _x <= _y ? _x : _y; })

#define MAX(x, y) \
   ({ __typeof__ (x) _x = (x); \
      __typeof__ (y) _y = (y); \
      _x > _y ? _x : _y; })

/* Here in our internal header, it's safe to typedef our convenience types */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
