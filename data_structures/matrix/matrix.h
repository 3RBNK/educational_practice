//
// Created by bnkr on 18.06.24.
//

#ifndef CODE_MATRIX_H
#define CODE_MATRIX_H

#include <stdio.h>
#include <stdbool.h>


typedef struct matrix {
    int **values;
    int n_rows;
    int n_cols;
} matrix;


typedef struct position {
    int row_index;
    int col_index;
} position;


// выделяет память под матрицу размером n_rows на n_cols
matrix get_mem_matrix(int n_rows, int n_cols);


// выделяет память под n_matrices матриц размером n_rows на n_cols
matrix* get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols);


// освобождает память выделенную под массив m
void free_mem_matrix(matrix *m);


// освобождает память ms занимаемую n_matrices матрицами
void free_mem_matrices(matrix *ms, int n_matrices);


// ввод матрицы m
void input_matrix(matrix  *m);


// ввод ms состоящую из n_matrices матриц
void input_matrices(matrix *ms, int n_matrices);


// вывод матрицы m
void output_matrix(matrix* m);


// вывод ms состоящую из n_matrices матриц
void output_matrices(matrix *ms, int n_matrices);


// меняет местами строки i1 и i2 в матрице m
void swap_rows(matrix* m, int i1, int i2);


// меняет местами столбцы j1 и j2 в матрице m
void swap_columns(matrix* m, int j1, int j2);


// сортирует вставками строки матрицы m по критерию criteria
void insertion_sort_rows_matrix_by_row_criteria(matrix* m, int (*criteria) (int*, int));


// сортирует выборкой столбы матрицы m по критерию criteria
void selection_sort_cols_matrix_by_col_criteria(matrix* m, int (*criteria) (int*, int));


// возвращает true, если матрица m является квадратной
// иначе false
bool is_square_matrix(matrix* m);


// возвращает true, если матрицы m1 и m2 равны
// иначе false
bool are_two_matrices_equal(matrix* m1, matrix* m2);


// возвращает true, если матрица m является единичной
// иначе false
bool is_E_matrix(matrix *m);


// возвращает true, если матрица m является симметричной
bool is_symmetric_matrix(matrix *m);


// транспонирует квадратную матрицу m
void transpose_square_matrix(matrix* m);


// транспонирует квадратную матрицу m относительно побочной диагонали
void transpose_square_matrix_of_side_diagonal(matrix* m);


// транспонирует матрицу m
void transpose_matrix(matrix* m);


// возвращает position минимального элемента матрицы m
position get_min_value_pos(matrix m);


// возвращает position максимального элемента матрицы m
position get_max_value_pos(matrix m);


// возвращает матрицу matrix размера n_rows на n_cols
// построенную из элементов массива a
matrix create_matrix_from_array(const int a[], int n_rows, int n_cols);


// возвращает указатель на нулевую матрицу массива из n_matrices матриц размеров n_rows на n_cols
// построенных из элементов массива values
matrix* create_array_of_matrix_from_array(const int values[], size_t n_matrices, size_t n_rows, size_t n_cols);

#endif //CODE_MATRIX_H
