//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_4_SUBTRACK_AVERAGE_H
#define PRACTICE_4_SUBTRACK_AVERAGE_H


void print_array(const int a[], const int m) {
    for (int i = 0; i < m; i++)
        printf("%d ", a[i]);
    printf("\n");
}


void subtrack_average(int a[], const int m) {
    int x_average = 0;
    for (int i = 0; i < m; i++)
        x_average += a[i];
    x_average /= m;

    for (int i = 0; i < m; i++)
        a[i] -= x_average;
}


#endif //PRACTICE_4_SUBTRACK_AVERAGE_H
