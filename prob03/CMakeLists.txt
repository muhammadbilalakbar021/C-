cmake_minimum_required(VERSION 3.13)
project(prob03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(test)

add_executable(prob03
        test/gtest_ext.h
        department_budget.cpp
        department_budget.hpp
        LICENSE
        main.cpp
        Makefile
        README.md
        Spending_Report1.txt
        Spending_Report2.txt)
