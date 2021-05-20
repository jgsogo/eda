cmake_minimum_required(VERSION 3.15)
project(printer)

add_executable(printer main.cpp src/PrintJob.cpp src/Printer.cpp)
set_target_properties(printer PROPERTIES CXX_STANDARD 17)
target_include_directories(printer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
