cmake_minimum_required(VERSION 3.13)
project(prob02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob02
        test/gtest_ext.h
        main.cpp
        Makefile
        README.md
        super_enemy.cpp
        super_enemy.hpp)
