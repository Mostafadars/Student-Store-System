cmake_minimum_required(VERSION 3.22.3)
project(DSA3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DSA3
        main.cpp
        Student.h
        BST.h
        Menus.h
        file.h AVL.h)
