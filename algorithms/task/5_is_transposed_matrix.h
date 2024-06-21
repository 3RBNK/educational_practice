//
// Created by bnkr on 18.06.24.
//

#ifndef PRACTICE_5_IS_TRANSPOSED_MATRIX_H
#define PRACTICE_5_IS_TRANSPOSED_MATRIX_H

#include <stdbool.h>
#include <assert.h>

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


void test_is_transposed_matrix_equal_matrix() {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix b = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    assert(is_transposed_matrix(&a, &b));

    free_mem_matrix(&a);
    free_mem_matrix(&b);
}


void test_is_transposed_matrix_transposed_matrix() {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix b = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    transpose_square_matrix(&b);

    assert(is_transposed_matrix(&a, &b));

    free_mem_matrix(&a);
    free_mem_matrix(&b);
}


void test_is_transposed_matrix_transposed_of_side_diagonal() {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix b = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    transpose_square_matrix_of_side_diagonal(&b);

    assert(is_transposed_matrix(&a, &b));

    free_mem_matrix(&a);
    free_mem_matrix(&b);
}


void test_is_transposed_matrix_double_transposed() {
    matrix a = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    matrix b = create_matrix_from_array((int[]) {1, 2, 3,
                                                 4, 5, 6,
                                                 7, 8, 9}, 3, 3);

    transpose_square_matrix(&b);
    transpose_square_matrix_of_side_diagonal(&b);

    assert(is_transposed_matrix(&a, &b));

    free_mem_matrix(&a);
    free_mem_matrix(&b);
}


void test_is_transposed_matrix() {
    test_is_transposed_matrix_equal_matrix();
    test_is_transposed_matrix_transposed_matrix();
    test_is_transposed_matrix_transposed_of_side_diagonal();
    test_is_transposed_matrix_double_transposed();
}


#endif //PRACTICE_5_IS_TRANSPOSED_MATRIX_H
