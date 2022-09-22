cmake_minimum_required(VERSION 3.19)
project(clion_dev)

set(CMAKE_CXX_STANDARD 20)

add_executable(clion_dev main.cpp)

#add by fjp
include_directories(${CMAKE_SOURCE_DIR}/leetcode/include)
add_subdirectory(leetcode/include)
# auto gen by plugins
add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)