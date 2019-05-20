cmake_minimum_required(VERSION 3.13)
project(prob04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob04
        test/gtest_ext.h
        cash_debit_card.cpp
        cash_debit_card.hpp
        LICENSE
        main.cpp
        Makefile
        README.md)
