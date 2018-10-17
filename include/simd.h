#ifndef SIMD_H_
#define SIMD_H_

#include <emmintrin.h>

#define SIMD_ALIGNMENT 16
#define _ALIGN_SIMD_ __attribute__ ((aligned(SIMD_ALIGNMENT)))

/* 32-bits floating point aligned for SIMD */
typedef float f32 _ALIGN_SIMD_;

/* Intrinsics macros */
/* TODO */

#endif /* SIMD_H_ */
