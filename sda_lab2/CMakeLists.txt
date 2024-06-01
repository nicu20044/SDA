cmake_minimum_required(VERSION 3.27)
project(sda_lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(sda_lab2 main.c
        functions.c
        functions.h
        structs.h
        structs.c)
