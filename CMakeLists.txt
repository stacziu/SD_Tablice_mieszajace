cmake_minimum_required(VERSION 3.28)
project(SD3)

set(CMAKE_CXX_STANDARD 17)

add_executable(SD3 main.cpp
        HashTable.cpp
        HashTable.h
        BST.cpp
        BST.h)
