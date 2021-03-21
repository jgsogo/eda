cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(actividad10
    src/Client.h
    src/ElementoListaSimple.h
    src/Lane.h
    src/Lane.cpp
)
target_include_directories(actividad10 PUBLIC src)

add_executable(lanes lanes.cpp)
target_link_libraries(lanes actividad10)

add_executable(single_lane single_lane.cpp)
target_link_libraries(single_lane actividad10)
