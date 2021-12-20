cmake_minimum_required(VERSION 3.19)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

set(SRC playground.cpp 234-palindrome-linked-list.cpp)

add_executable(leetcode ${SRC})

target_include_directories(leetcode PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})