cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(utils utils/utils.cpp utils/utils.h)
add_executable(lab2_main main.cpp)

target_link_libraries(lab2_main utils)

target_include_directories(lab2_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
