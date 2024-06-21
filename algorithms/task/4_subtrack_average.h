//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_4_SUBTRACK_AVERAGE_H
#define PRACTICE_4_SUBTRACK_AVERAGE_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


void print_array(const int a[], const int m) {
    for (int i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\n");
}


bool is_equal_array(const int a[], const int n, const int b[], const int m) {
    if (m != n)
        return false;

    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return false;

    return true;
}


void subtrack_average(int a[], const int m) {
    int x_average = 0;
    for (int i = 0; i < m; i++)
        x_average += a[i];
    x_average /= m;

    for (int i = 0; i < m; i++)
        a[i] -= x_average;
}


void test_subtrack_average_one_element() {
    int a[] = {5};
    const int n = 1;

    subtrack_average(a, n);

    const int b[] = {0};
    const int m = 1;

    assert(is_equal_array(a, n, b, m));
}


void test_subtrack_average_zero_element() {
    int a[] = {0, 0, 0, 0, 0};
    const int n = 5;

    subtrack_average(a, n);

    const int b[] = {0, 0, 0, 0, 0};
    const int m = 5;

    assert(is_equal_array(a, n, b, m));
}


void test_subtrack_average_different_element() {
    int a[] = {1, 2, 3, 4, 5};
    const int n = 5;

    subtrack_average(a, n);

    const int b[] = {-2, -1, 0, 1, 2};
    const int m = 5;

    assert(is_equal_array(a, n, b, m));
}


void test_subtrack_average() {
    test_subtrack_average_one_element();
    test_subtrack_average_zero_element();
    test_subtrack_average_different_element();
}

#endif //PRACTICE_4_SUBTRACK_AVERAGE_H