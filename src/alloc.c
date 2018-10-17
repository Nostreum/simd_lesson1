#include <alloc.h>

f32** alloc_f32_2D(int height, int width) {
    
    f32 **m = (f32**) malloc(height * sizeof(f32*));;

    for (int i=0; i<height; i++) {
        m[i] = (f32*) malloc(width * sizeof(f32));
    }

    return m;
}

void init_zero_f32_2D(f32 **m, int height, int width) {
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<height; j++) {
            m[i][j] = 0.0f;
        }
    }
}

void init_rand_f32_2D(f32 **m, int height, int width, int rand_max) {
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<height; j++) {
            m[i][j] = (f32)(rand() % rand_max + 1);
        }
    }
}
