#ifndef CONV_H_
#define CONV_H_

#include <stdio.h>
#include <stdlib.h>
#include <simd.h>

/* Convolutions */
void f32_conv_3x3(f32 **img, f32 **mask, f32 **out, int h, int w);
void f32_conv_sse_3x3(f32 **img, f32 **mask, f32 **out, int h, int w);

#endif /* CONV_H_ */
