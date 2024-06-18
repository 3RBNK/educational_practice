//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_5_IS_TRANSPOSED_MATRIX_H
#define PRACTICE_5_IS_TRANSPOSED_MATRIX_H

#include <stdbool.h>

#include "../../data_structures/matrix/matrix.h"


bool is_transposed_matrix(matrix* a, matrix* b) {
    bool is_transposed = false;

    if (are_two_matrices_equal(a, b))
        is_transposed = true;

    matrix temp = get_mem_matrix(a->n_rows, a->n_rows);
    for (int i = 0; i < a->n_rows; i++)
        for (int j = 0; j < a->n_cols; j++)
            temp.values[i][j] = a->values[i][j];

    transpose_square_matrix(&temp);
    if (are_two_matrices_equal(&temp, b))
        is_transposed = true;;

    transpose_square_matrix_of_side_diagonal(&temp);
    if (are_two_matrices_equal(&temp, b))
        is_transposed = true;;

    transpose_square_matrix(&temp);
    if (are_two_matrices_equal(&temp, b))
        is_transposed = true;;

    free_mem_matrix(&temp);

    return is_transposed;
}


#endif //PRACTICE_5_IS_TRANSPOSED_MATRIX_H
