cmake_minimum_required(VERSION 3.13)
project(prob03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob03
        test/gtest_ext.h
        main.cpp
        Makefile
        README.md
        weapons.cpp
        weapons.hpp)
