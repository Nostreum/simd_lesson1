#include <conv.h>

/* f32_conv_3x3 : 
 *
 * Apply 3x3 convolution on 2D array 
 *
 * (mask is supposed to be 3x3)
 *
 */
void f32_conv_3x3(f32 **img, f32 **mask, f32 **out, int h, int w) {

    for (int i=1; i<h-1; i++) {
        for (int j=1; j<w-1; j++) {
            out[i][j] = img[i-1][j-1] * mask[0][0]
                      + img[i-1][j  ] * mask[0][1]
                      + img[i-1][j+1] * mask[0][2]
                      + img[i  ][j-1] * mask[1][0]
                      + img[i  ][j  ] * mask[1][1]
                      + img[i  ][j+1] * mask[1][2]
                      + img[i+1][j-1] * mask[2][0]
                      + img[i+1][j  ] * mask[2][1]
                      + img[i+1][j+1] * mask[2][2];
        }
    }
}

/* f32_conv_sse_3x3
 *
 * Apply 3x3 convolution on 2D array using SIMD 
 * SSE (intel) intresics.
 *
 * (mask is supposed to be 3x3)
 *
 * */
void f32_conv_sse_3x3(f32 **img, f32 **mask, f32 **out, int h, int w) {

    /* TODO */
}
