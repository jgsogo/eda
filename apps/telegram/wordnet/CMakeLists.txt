cmake_minimum_required(VERSION 2.8.12)
project(WordnetGame CXX)

find_package(fmt)
find_package(tgbot)
find_package(wnb)

add_executable(wordnet_game main.cpp bot.h bot.cpp wordnet.h wordnet.cpp)
target_link_libraries(wordnet_game fmt::fmt tgbot::tgbot wnb::wnb)
set_target_properties(wordnet_game PROPERTIES CXX_STANDARD 11)
