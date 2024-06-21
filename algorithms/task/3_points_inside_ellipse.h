//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_3_POINTS_INSIDE_ELLIPSE_H
#define PRACTICE_3_POINTS_INSIDE_ELLIPSE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>


int get_points_inside_ellipse(const double a, const double b) {
    const int whole_a = (int) fabs(a);
    const int whole_b =  (int) fabs(b);

    if (whole_a < 1 || whole_b < 1)
        return 1;

    int result = 0;
    for (int i = -whole_a; i < whole_a + 1; i++)
        for (int j = -whole_b; j < whole_b + 1; j++)
            if (i * i / (whole_a * whole_a) + j * j / (whole_b * whole_b) <= 1)
                result++;

    return result;
}


void test_get_points_inside_ellipse_one_dots() {
    const int result = get_points_inside_ellipse(0.5, 0.5);

    assert(result == 1);
}


void test_get_points_inside_ellipse_more_dots() {
    const int result = get_points_inside_ellipse(1.5, 1.5);

    assert(result == 5);
}


void test_get_points_inside_ellipse() {
    test_get_points_inside_ellipse_one_dots();
    test_get_points_inside_ellipse_more_dots();
}

#endif //PRACTICE_3_POINTS_INSIDE_ELLIPSE_H
