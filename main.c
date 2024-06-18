#include <stdio.h>
#include "algorithms/task/9_matrix_multiplication.h"


void print_array(const int a[], const int m) {
    for (int i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\n");
}



int main() {
    const int a[6] = {1, 2, 3, 4, 5, 6};
    const int b[6] = {7, 8, 9, 10, 11, 12};
    const int m = 2;
    const int n = 3;
    const int k = 2;

    int c[m * k];

    matrix_multiplication(a, b, m, n, k, c);

    print_array(c, m*k);

    return 0;
}
