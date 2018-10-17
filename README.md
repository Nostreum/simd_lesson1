# SIMD lesson1

## General instructions

    * Write f32_conv_sse_3x3 function in conv.c
    * compile with "make all" and launch ./conv
    * if no errors, compare the scalar vs simd execution time
    * add -O2/-O3 to gcc, and retry
    * Try to beat him

## Intel intrinsics

You can find all the information about intel intrinsics function on this page : 

    https://software.intel.com/sites/landingpage/IntrinsicsGuide/

To start use SSE2 instructions (128bits registers, 4x32bits FP).
To go futher you can have a look at AVX/AVX-512 (512bits registers).

## Submit

Create your own remote branch with your name.
