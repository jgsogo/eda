cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(actividad03
	src/sort_algorithms.h
	src/bubble_sort.cpp
	src/selection_sort.cpp
	src/merge_sort.cpp
	src/quick_sort.cpp
)
target_include_directories(actividad03 PUBLIC src)


find_package(Catch2)

#
# Create a target for executing the Catch unit tests.
#
add_executable(unit_tests
	tests/main.cpp
	tests/test_bubble_sort.cpp
	tests/test_merge_sort.cpp
	tests/test_quick_sort.cpp
	tests/test_selection_sort.cpp
)
target_include_directories(unit_tests PUBLIC test/)
target_link_libraries(unit_tests PUBLIC Catch2::Catch2 actividad03)
