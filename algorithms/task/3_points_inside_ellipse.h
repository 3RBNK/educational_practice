//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_3_POINTS_INSIDE_ELLIPSE_H
#define PRACTICE_3_POINTS_INSIDE_ELLIPSE_H

#include <math.h>


int get_points_inside_ellipse(const double a, const double b) {
    const int whole_a = (int) fabs(a);
    const int whole_b =  (int) fabs(b);

    int result = 0;
    for (int i = -whole_a; i < whole_a + 1; i++)
        for (int j = -whole_b; j < whole_b + 1; j++)
            if (i * i / (whole_a * whole_a) + j * j / (whole_b * whole_b) <= 1)
                result++;

    return result;
}

#endif //PRACTICE_3_POINTS_INSIDE_ELLIPSE_H
