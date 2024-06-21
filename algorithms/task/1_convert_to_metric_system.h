//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H
#define PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H

#include <stdio.h>


void convert_to_metric_system(const double inch) {
    const double inch_in_sm = inch * 2.54;

    const int m = (int) inch_in_sm / 100;
    const int sm = (int) inch_in_sm % 100;
    const double mm =  (int) (inch_in_sm * 100) % 100 / 10.0;

    printf("m: %d, sm: %d, mm: %.1lf\n", m, sm, mm);
}


void test_convert_to_metric_system_only_mm() {
    convert_to_metric_system(0.3);
}


void test_convert_to_metric_system_only_mm_and_sm() {
    convert_to_metric_system(1);
}


void test_convert_to_metric_system_all_metric() {
    convert_to_metric_system(205);
}


void test_convert_to_metric_system() {
    test_convert_to_metric_system_only_mm();                  // 7.6 mm
    test_convert_to_metric_system_only_mm_and_sm();      // 2 sm 5.4 mm
    test_convert_to_metric_system_all_metric();     // 5 m 20 sm 7.0 mm
}

#endif //PRACTICE_1_CONVERT_TO_METRIC_SYSTEM_H
