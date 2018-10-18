#ifndef CHECKER_H_
#define CHECKER_H_

#include <stdlib.h>
#include <simd.h>
#include <stdbool.h>

bool matrices_are_equal(f32 **m1, f32 **m2, int h, int w);

#endif /* CHECKER_H_ */
