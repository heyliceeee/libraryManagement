cmake_minimum_required(VERSION 3.26)
project(libraryManagement C)

set(CMAKE_C_STANDARD 11)

add_executable(libraryManagement main.c
        main.h
        books.c
        books.h
        input.c
        input.h)
