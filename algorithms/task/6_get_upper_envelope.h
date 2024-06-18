//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_6_GET_UPPER_ENVELOPE_H
#define PRACTICE_6_GET_UPPER_ENVELOPE_H

#include <stdio.h>
#include <math.h>
#include <float.h>


void print_upper_envelope() {
    int n;
    printf("Input amount \n");
    scanf("%d", &n);

    double max_a = -1e9;
    double max_b = -1e9;

    for (int i = 0; i < n; i++) {
        double a,b;
        printf("input %d ratio: \n", i + 1);
        scanf("%lf %lf", &a, &b);

        if (max_a < a || (fabs(a - max_a) < DBL_EPSILON && b > max_b)) {
            max_a = a;
            max_b = b;
        }
    }

    printf("y = %.2lfx + %.2lf", max_a, max_b);
}


#endif //PRACTICE_6_GET_UPPER_ENVELOPE_H
