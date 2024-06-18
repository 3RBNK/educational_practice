cmake_minimum_required(VERSION 3.28)
project(practice C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "-lm")
set(CMAKE_C_STANDARD 11)


add_executable(practice main.c
        algorithms/task/1_convert_to_metric_system.h
        algorithms/task/2_determine_triangle.h
        algorithms/task/3_points_inside_ellipse.h
        algorithms/task/4_subtrack_average.h
        data_structures/matrix/matrix.h
        data_structures/matrix/matrix.c
        algorithms/task/5_is_transposed_matrix.h
        algorithms/task/6_get_upper_envelope.h
        algorithms/task/7_get_multiples_of_eleven.h)
target_link_libraries(practice m)
