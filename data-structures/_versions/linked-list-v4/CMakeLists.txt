cmake_minimum_required(VERSION 3.26)
project(last_check C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(last_check
        LinkedList.c
        LinkedList.h
        main.c)
