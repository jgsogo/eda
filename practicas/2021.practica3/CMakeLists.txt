cmake_minimum_required(VERSION 3.15)
project(practica3)

add_executable(employees employees.cpp src/Database.cpp src/Empleado.cpp src/FilterDatabase.cpp)
set_target_properties(employees PROPERTIES CXX_STANDARD 17)
target_include_directories(employees PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(math1 math1.cpp math/BinaryTree.cpp)
set_target_properties(math1 PROPERTIES CXX_STANDARD 17)
target_include_directories(math1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/math)

add_executable(math2 math2.cpp math/BinaryTree.cpp)
set_target_properties(math2 PROPERTIES CXX_STANDARD 17)
target_include_directories(math2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/math)
