//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H
#define PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H

#include <stdio.h>


void convert_to_metric_system() {
    int inch;
    printf("Input inch: \n");
    scanf("%d", &inch);

    const double inch_in_sm = inch * 2.54;

    const int m = (int) inch_in_sm / 100;
    const int sm = (int) inch_in_sm % 100;
    const double mm =  (int) (inch_in_sm * 100) % 100 / 10.0;

    printf("m: %d, sm: %d, mm: %.1lf", m, sm, mm);
}

#endif //PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H
