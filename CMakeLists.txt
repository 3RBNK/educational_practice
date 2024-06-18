cmake_minimum_required(VERSION 3.28)
project(practice C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "-lm")
set(CMAKE_C_STANDARD 11)


add_executable(practice main.c
        algorithms/task/1_convert_to_metric_system.h
        algorithms/task/2_determine_triangle.h
        algorithms/task/3_points_inside_ellipse.h)
target_link_libraries(practice m)
