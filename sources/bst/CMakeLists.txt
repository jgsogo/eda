cmake_minimum_required(VERSION 3.5)
project(bst LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(bst
    src/ElementoArbolBinario.h
    src/BinarySearchTree.cpp
    src/BinarySearchTree.h
)

target_include_directories(bst PUBLIC src)

add_executable(main main.cpp)
target_link_libraries(main bst)
