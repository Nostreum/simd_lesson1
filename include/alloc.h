#ifndef ALLOC_H_
#define ALLOC_H_

#include <stdlib.h>
#include <math.h>
#include <simd.h>

#define N 2096            /* matrix size */
#define MAX_VALUE 100    /* Max rand value */

/* 2D Array generic functions */
f32** alloc_f32_2D(int height, int width);
void init_zero_f32_2D(f32 **m, int height, int width);
void init_rand_f32_2D(f32 **m, int height, int width, int rand_max);


#endif /* ALLOC_H_ */
