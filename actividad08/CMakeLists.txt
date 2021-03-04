cmake_minimum_required(VERSION 3.5)
project(Actividad LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(actividad08
	src/check_braces.h
	src/check_braces.cpp
	src/Stack.cpp
	src/Stack.h
	src/ElementoListaSimple.cpp
	src/ElementoListaSimple.h
	src/TipoDato.h
	src/TipoDato.cpp
)
target_include_directories(actividad08 PUBLIC src)


find_package(Catch2)

#
# Create a target for executing the Catch unit tests.
#
add_executable(unit_tests
	tests/main.cpp
	tests/test_check_braces.cpp
)
target_include_directories(unit_tests PUBLIC test/)
target_link_libraries(unit_tests PUBLIC Catch2::Catch2 actividad08)
