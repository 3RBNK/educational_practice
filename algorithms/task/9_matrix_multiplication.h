//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_9_MATRIX_MULTIPLICATION_H
#define PRACTICE_9_MATRIX_MULTIPLICATION_H

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>


void matrix_multiplication(const int a[], const int b[],
                           const int m, const int n, const int k,
                           int c[]) {

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++) {
            c[i * k + j] = 0;
            for (int l = 0; l < n; l++)
                c[i * k + j] += a[i * n + l] * b[l * k + j];
        }
}


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


void test_matrix_multiplication_empty_matrix() {
    const int a[] = {};
    const int b[] = {};
    int c[] = {};
    const int check[] = {};

    const int m = 0;
    const int n = 0;
    const int k = 0;

    matrix_multiplication(a, b, m, n, k, c);

    assert(is_equal_array(c, 0, check, 0));
}


void test_matrix_multiplication_unit_matrix() {
    const int a[] = {1, 0, 0,
                     0, 1, 0,
                     0, 0, 1};
    const int b[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};

    const int m = 3;
    const int n = 3;
    const int k = 3;

    int c[m * k];
    const int check[] = {1, 2, 3,
                         4, 5, 6,
                         7, 8, 9};

    matrix_multiplication(a, b, m, n, k, c);

    assert(is_equal_array(c, 9, check, 9));
}


void test_matrix_multiplication_diff_matrix() {
    const int a[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};
    const int b[] = {1, 2, 3,
                     4, 5, 6,
                     7, 8, 9};

    const int m = 3;
    const int n = 3;
    const int k = 3;

    int c[m * k];
    const int check[] = {30, 36, 42,
                         66, 81, 96,
                         102, 126, 150};

    matrix_multiplication(a, b, m, n, k, c);

    assert(is_equal_array(c, 9, check, 9));
}


void test_matrix_multiplication() {
    test_matrix_multiplication_empty_matrix();
    test_matrix_multiplication_unit_matrix();
    test_matrix_multiplication_diff_matrix();
}


#endif //PRACTICE_9_MATRIX_MULTIPLICATION_H
