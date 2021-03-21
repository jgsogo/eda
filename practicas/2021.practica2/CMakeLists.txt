cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(practica2
	src/practica1.cpp
	src/practica1.h
)
target_include_directories(practica2 PUBLIC src)


find_package(Catch2)

#
# Create a target for executing the Catch unit tests.
#
file(GLOB TEST_FILES tests/test_*.cpp)
add_executable(unit_tests
	tests/main.cpp
	${TEST_FILES}
)
target_include_directories(unit_tests PUBLIC test/)
target_link_libraries(unit_tests PUBLIC Catch2::Catch2 practica2)
