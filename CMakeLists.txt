cmake_minimum_required(VERSION 3.14)
project(purec C)

set(CMAKE_C_STANDARD 11)

add_executable(purec main.c string.c reference_counted.c)