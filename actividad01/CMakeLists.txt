cmake_minimum_required(VERSION 3.5)
project(Actividad01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(actividad01
	src/palindrome.h
	src/palindrome.cpp
)
target_include_directories(actividad01 PUBLIC src)


find_package(Catch2)

#
# Create a target for executing the Catch unit tests.
#
add_executable(unit_tests
	tests/main.cpp
	tests/test_palindrome.cpp
)
target_include_directories(unit_tests PUBLIC test/)
target_link_libraries(unit_tests PUBLIC Catch2::Catch2 actividad01)
