//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_9_MATRIX_MULTIPLICATION_H
#define PRACTICE_9_MATRIX_MULTIPLICATION_H


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


#endif //PRACTICE_9_MATRIX_MULTIPLICATION_H
