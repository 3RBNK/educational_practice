//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_2_DETERMINE_TRIANGLE_H
#define PRACTICE_2_DETERMINE_TRIANGLE_H

#include <stdio.h>
#include <float.h>
#include <math.h>


double min2(const double a, const double b) {
    return a - b < 0.0 ? a : b;
}


double max2(const double a, const double b) {
    return a - b > 0.0 ? a : b;
}


void determine_triangle(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3) {
    const double AB = sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2));
    const double BC = sqrt(pow(x3 - x2, 2) +  pow(y3 - y2, 2));
    const double CA = sqrt(pow(x1 - x3, 2) +  pow(y1 - y3, 2));

    const double min = min2(AB, min2(BC, CA));
    const double max = max2(AB, max2(BC, CA));
    const double mid = AB + BC + CA - (min + max);

    if (fabs(min * min + mid * mid - max * max) < DBL_EPSILON) {
        printf("a right-angled triangle\n");
    } else if (min * min + mid * mid > max * max) {
        printf("an acute-angled triangle\n");
    } else if (min * min + mid * mid < max * max) {
        printf("an obtuse triangle\n");
    }
}


void test_determine_triangle_is_right_angled() {
    determine_triangle(0, 0, 3, 0, 3, 4);
}


void test_determine_triangle_is_acute_angled() {
    determine_triangle(0, 0, 3, 0, 1, 6);
}


void test_determine_triangle_is_obtuse_angled() {
    determine_triangle(0, 0, 3, 0, 5, 6);
}


void test_determine_triangle() {
    test_determine_triangle_is_right_angled(); // a right-angled triangle
    test_determine_triangle_is_acute_angled(); // an acute-angled triangle
    test_determine_triangle_is_obtuse_angled(); // an obtuse triangle
}


#endif //PRACTICE_2_DETERMINE_TRIANGLE_H
