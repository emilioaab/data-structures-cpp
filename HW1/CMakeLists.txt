cmake_minimum_required(VERSION 3.22)
project(HWEmilCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(HWEmilCpp Time.cpp Time.h driver.cpp tools.cpp tools.h)
