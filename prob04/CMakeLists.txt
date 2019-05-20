cmake_minimum_required(VERSION 3.13)
project(prob04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob04
        test/gtest_ext.h
        car_comp.cpp
        car_comp.hpp
        LICENSE
        main.cpp
        Makefile
        README.md)
