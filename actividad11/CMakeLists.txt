cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(actividad11
    src/TipoDato.h
    src/ElementoArbol.h
    src/Tree.h
    src/Tree.cpp
    src/Queue.h
    src/Queue.cpp
)
target_include_directories(actividad11 PUBLIC src)

add_executable(tree main.cpp)
target_link_libraries(tree actividad11)
