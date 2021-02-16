cmake_minimum_required(VERSION 2.8.12)
project(BotHelloWorld CXX)

find_package(fmt)
find_package(tgbot)

add_executable(bot_hello_world main.cpp)
target_link_libraries(bot_hello_world fmt::fmt tgbot::tgbot)
set_target_properties(bot_hello_world PROPERTIES CXX_STANDARD 11)
