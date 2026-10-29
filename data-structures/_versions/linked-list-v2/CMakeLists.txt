cmake_minimum_required(VERSION 3.26)
project(HM1__ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HM1__
        LinkedList.c
        LinkedList.h
        main.c
        "last check/main.c")
