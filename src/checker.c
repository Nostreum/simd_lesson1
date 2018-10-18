#include <checker.h>
#include <stdio.h>
#include <math.h>

/*
 * Border are not checked for now
 */
bool matrices_are_equal(f32 **m1, f32 **m2, int h, int w) {

    for (int i=1; i<h-1; i++) {
        for (int j=4; j<w-4; j++) {
            if (fabs(m1[i][j] - m2[i][j]) > 0.01) {
                return false;
            }
        }
    }

    return true;
}
