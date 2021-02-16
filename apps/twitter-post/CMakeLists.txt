cmake_minimum_required(VERSION 3.1)

project(TwPostImage CXX)
set(CMAKE_CXX_STANDARD 17)

find_package(CURL)
find_package(liboauth)
find_package(jansson)

add_executable(tw-post-image main.cpp)
target_link_libraries(tw-post-image PRIVATE CURL::CURL jansson::jansson liboauth::liboauth)
