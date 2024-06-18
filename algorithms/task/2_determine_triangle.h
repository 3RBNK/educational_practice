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


void determine_triangle() {
    int x1, y1, x2, y2, x3, y3;
    printf("Input coord A\n");
    scanf("%d %d", &x1, &y1);

    printf("Input coord B\n");
    scanf("%d %d", &x2, &y2);

    printf("Input coord C\n");
    scanf("%d %d", &x3, &y3);

    const double AB = sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2));
    const double BC = sqrt(pow(x3 - x2, 2) +  pow(y3 - y2, 2));
    const double CA = sqrt(pow(x1 - x3, 2) +  pow(y1 - y3, 2));

    const double min = min2(AB, min2(BC, CA));
    const double max = max2(AB, max2(BC, CA));
    const double mid = AB + BC + CA - (min + max);

    if (fabs(min * min + mid * mid - max * max) < DBL_EPSILON) {
        printf("a right-angled triangle");
    } else if (min * min + mid * mid > max * max) {
        printf("an acute-angled triangle");
    } else if (min * min + mid * mid < max * max) {
        printf("an obtuse triangle");
    } else {
        printf("It's not a triangle");
    }
}


#endif //PRACTICE_2_DETERMINE_TRIANGLE_H
