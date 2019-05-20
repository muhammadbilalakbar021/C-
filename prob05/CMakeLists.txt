cmake_minimum_required(VERSION 3.13)
project(prob05)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob05
        test/gtest_ext.h
        game_store.cpp
        game_store.hpp
        LICENSE
        main.cpp
        Makefile
        README.md)
