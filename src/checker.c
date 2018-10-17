#include <checker.h>

bool matrices_are_equal(f32 **m1, f32 **m2, int h, int w) {

    for (int i=0; i<h; i++)
        for (int j=0; j<w; j++)
            if (m1[i][j] != m2[i][j])
                return false;

    return true;
}
