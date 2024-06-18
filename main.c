#include <stdio.h>
#include "algorithms/task/5_is_transposed_matrix.h"

int main(void) {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix b = create_matrix_from_array((int[]) {10, 10, 10,
                                                 6, 5, 410,
                                                 3, 2, 10}, 3, 3);

    printf("%d\n", is_transposed_matrix(&a, &b));

    return 0;
}
