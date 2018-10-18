#include <checker.h>

bool matrices_are_equal(f32 **m1, f32 **m2, int h, int w) {

    for (int i=1; i<h-1; i++)
        for (int j=1; j<w-1; j++)
            if (m1[i][j] != m2[i][j])
                return false;

    return true;
}
