cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(actividad14
    src/Avion.h
    src/Avion.cpp
    src/PriorityQueue.h
    src/PriorityQueue.cpp
    main.cpp
)

target_include_directories(actividad14 PUBLIC src)

add_executable(airport main.cpp)
target_link_libraries(airport actividad14)
