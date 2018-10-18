#include <debug.h>

void print_2D_array(f32** m, int h, int w) {
    
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            printf("%.3f | ", m[i][j]);
        }
        printf("\n");
    }

}
