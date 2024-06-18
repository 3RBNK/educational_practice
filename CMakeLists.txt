cmake_minimum_required(VERSION 3.28)
project(practice C)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "-lm")
set(CMAKE_C_STANDARD 11)


add_executable(practice main.c)
target_link_libraries(practice m)
