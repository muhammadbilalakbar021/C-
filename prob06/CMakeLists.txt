cmake_minimum_required(VERSION 3.13)
project(prob01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob01
        test/gtest_ext.h
        doctors_schedule.cpp
        doctors_schedule.hpp
        LICENSE
        main.cpp
        Makefile
        README.md)
