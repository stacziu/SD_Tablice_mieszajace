cmake_minimum_required(VERSION 3.28)
project(SD3)

set(CMAKE_CXX_STANDARD 17)

add_executable(SD3 main.cpp
        SeparateChaining.cpp
        SeparateChaining.h
        BST.cpp
        BST.h
        CuckooHashTable.cpp
        CuckooHashTable.h)
