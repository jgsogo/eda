cmake_minimum_required(VERSION 3.5)
project(Practica LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_library(practica2
	src/ElementoListaDoble.cpp
	src/Persona.cpp
    src/Queue.cpp
    src/Police.cpp
    src/Wardrobe.cpp
    src/NameCounter.cpp
)
target_include_directories(practica2 PUBLIC src)

add_executable(main1 main1.cpp)
target_link_libraries(main1 PUBLIC practica2)

add_executable(main2 main2.cpp)
target_link_libraries(main2 PUBLIC practica2)

add_executable(main3 main3.cpp)
target_link_libraries(main3 PUBLIC practica2)

add_executable(main4 main4.cpp)
target_link_libraries(main4 PUBLIC practica2)


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
