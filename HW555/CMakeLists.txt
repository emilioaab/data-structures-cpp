cmake_minimum_required(VERSION 3.26)
project(HW555)

set(CMAKE_CXX_STANDARD 17)

add_executable(HW555 driver.cpp
        List.cpp
        List.h
        Queue.cpp
        Queue.h
        Utility.cpp
        Utility.h)
