cmake_minimum_required(VERSION 3.26)
project(HW1DS C)

set(CMAKE_C_STANDARD 23)

add_executable(HW1DS main.c
        LinkedList.h
        LinkedList.c)
