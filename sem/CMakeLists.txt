cmake_minimum_required(VERSION 3.27)
project(sem C)

set(CMAKE_C_STANDARD 11)

add_executable(sem main.c
        functions.c
        functions.h
        struct.h)
