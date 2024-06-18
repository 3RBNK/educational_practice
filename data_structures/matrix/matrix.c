//
// Created by bnkr on 18.06.24.
//

#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "matrix.h"

#include <stdlib.h>


static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


matrix get_mem_matrix(const int n_rows, const int n_cols) {
    int** values = (int**) malloc(sizeof(int*) * n_rows);

    for (size_t i = 0; i < n_rows; i++)
        values[i] = (int*) malloc(sizeof(int) * n_cols);

    return (matrix) {values, n_rows, n_cols};
}


matrix* get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * n_matrices);

    for (size_t i = 0; i < n_matrices; i++)
        ms[i] = get_mem_matrix(n_rows, n_cols);

    return ms;
}


void free_mem_matrix(matrix *m) {
    for (int i = 0; i < m->n_rows; i++)
        free(m->values[i]);

    free(m->values);
    m->values = NULL;
    m->n_rows = 0;
    m->n_cols = 0;
}


void free_mem_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        free_mem_matrix(ms + i);

    free(ms->values);
    ms->values = NULL;
    ms->n_rows = 0;
    ms->n_cols = 0;
}


void input_matrix(matrix  *m) {
    for (int i = 0; i < m->n_rows; i++) {
        printf("input %d row:", i + 1);
        for (int j = 0; j < m->n_cols; j++)
            scanf("%d", &m->values[i][j]);
    }
}


void input_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++) {
        printf("input %lld matrix\n", i + 1);
        input_matrix(ms + i);
        printf("\n");
    }
}


void output_matrix(matrix* m) {
    for (size_t i = 0; i < m->n_rows; i++) {
        for (size_t j = 0; j < m->n_cols; j++)
            printf("%d ", m->values[i][j]);
        printf("\n");
    }
    printf("\n");
}


void output_matrices(matrix *ms, int n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        output_matrix(ms + i);
}


void swap_rows(matrix* m, int i1, int i2) {
    int* temp = m->values[i1];
    m->values[i1] = m->values[i2];
    m->values[i2] = temp;
}


void swap_columns(matrix* m, int j1, int j2) {
    for (int i = 0; i < m->n_rows; i++)
        swap(&m->values[i][j1], &m->values[i][j2]);
}


void insertion_sort_rows_matrix_by_row_criteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_rows];

    for (size_t i = 0; i < m->n_rows; i++)
        res_criteria[i] = criteria(m->values[i], m->n_cols);

    int i, j, key;
    int* address_key;
    for (i = 1; i < m->n_rows; i++) {
        key = res_criteria[i];
        address_key = m->values[i];
        j = i - 1;

        while (j >= 0 && res_criteria[j] > key) {
            res_criteria[j + 1] = res_criteria[j];
            swap_rows(m, j + 1, j);

            j -= 1;
        }

        res_criteria[j + 1] = key;
        m->values[j + 1] = address_key;
    }
}


void selection_sort_cols_matrix_by_col_criteria(matrix* m, int (*criteria) (int*, int)) {
    int res_criteria[m->n_cols];

    for (size_t i = 0; i < m->n_cols; i++) {
        int temp[m->n_rows];
        for (size_t j = 0; j < m->n_rows; j++)
            temp[j] = m->values[j][i];

        res_criteria[i] = criteria(temp, m->n_rows);
    }

    int value_min_idx;
    for (int i = 0; i < m->n_cols; i++) {
        value_min_idx = i;

        for (int j = i + 1; j < m->n_cols; j++)
            if (res_criteria[j] < res_criteria[value_min_idx])
                value_min_idx = j;

        swap(&res_criteria[value_min_idx], &res_criteria[i]);
        swap_columns(m, value_min_idx, i);
    }
}


bool is_square_matrix(matrix* m) {
    return m->n_rows == m->n_cols;
}


bool are_two_matrices_equal(matrix* m1, matrix* m2) {
    for (size_t i = 0; i < m1->n_rows; i++)
        if (memcmp(m1->values[i], m2->values[i], m1->n_cols) != 0)
            return false;
    return true;
}


//bool is_E_matrix(matrix *m) {
//    int e[m->n_cols + 1];
//    for (size_t i = 1; i <= m->n_cols; i++)
//        e[i] = 0;
//    e[0] = 1;
//
//
//    for (size_t i = 0; i < m->n_rows; i++) {
//        if (memcmp(m->values[i], e, m->n_cols) != 0)
//            return false;
//
//        e[i + 1] = 1;
//        e[i] = 0;
//    }
//
//    return true;
//}


bool is_E_matrix(matrix *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = 0; j < m->n_cols; j++)
            if ((j != i && m->values[i][j] != 0) || (j == i && m->values[i][j] != 1))
                return false;
    return true;
}


bool is_symmetric_matrix(matrix *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = i + 1; j < m->n_cols; j++)
            if (m->values[i][j] != m->values[j][i])
                return false;
    return true;
}


void transpose_square_matrix(matrix* m) {
    if (m->n_rows != m->n_cols) {
        fprintf(stderr, "Is not square matrix");
        exit(1);
    }

    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = i + 1; j < m->n_cols; j++)
            if (i != j)
                swap(&m->values[i][j], &m->values[j][i]);
}


void transpose_square_matrix_of_side_diagonal(matrix* m) {
    if (m->n_rows != m->n_cols) {
        fprintf(stderr, "Is not square matrix");
        exit(1);
    }

    for (int i = m->n_rows - 2; i >= 0; i--)
        for (int j = 0; j < m->n_cols - i - 1; j++)
            swap(&m->values[i][j], &m->values[m->n_cols - j - 1][m->n_rows - i - 1]);
}


void transpose_matrix(matrix* m) {
    int** new_value = (int**) malloc(sizeof(int*) * m->n_cols);

    for (size_t i = 0; i < m->n_cols; i++) {
        new_value[i] = (int*) malloc(sizeof(int) * m->n_rows);

        for (size_t j = 0; j < m->n_rows; j++)
            new_value[i][j] = m->values[j][i];
    }

    for (size_t i = 0; i < m->n_rows; i++)
        free(m->values[i]);
    free(m->values);

    m->values = new_value;
    swap(&m->n_rows, &m->n_cols);
}


position get_min_value_pos(matrix m) {
    int min_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.n_rows; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (m.values[i][j] < min_value) {
                min_value = m.values[i][j];
                pos.row_index = i;
                pos.col_index = j;
            }

    return pos;
}


position get_max_value_pos(matrix m) {
    int max_value = m.values[0][0];
    position pos = {0, 0};

    for (int i = 0; i < m.n_rows; i++)
        for (int j = 0; j < m.n_cols; j++)
            if (m.values[i][j] > max_value) {
                max_value = m.values[i][j];
                pos.row_index = i;
                pos.col_index = j;
            }

    return pos;
}


matrix create_matrix_from_array(const int a[], int n_rows, int n_cols) {
    matrix m = get_mem_matrix(n_rows, n_cols);

    int k = 0;
    for (int i = 0; i < n_rows; i++)
        for (int j = 0; j < n_cols; j++)
            m.values[i][j] = a[k++];

    return m;
}


matrix* create_array_of_matrix_from_array(const int values[], size_t n_matrices, size_t n_rows, size_t n_cols) {
    matrix* ms = get_mem_array_of_matrices(n_matrices, n_rows, n_cols);

    int l = 0;
    for (size_t k = 0; k < n_matrices; k++)
        for (size_t i = 0; i < n_rows; i++)
            for (size_t j = 0; j < n_cols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}