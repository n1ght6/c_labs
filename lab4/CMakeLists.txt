cmake_minimum_required(VERSION 3.10)
project(iomanip)

find_package(Catch2 REQUIRED)

add_library(iomanip INTERFACE)
target_include_directories(iomanip INTERFACE include)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/gprotect.cpp "#include <iomanip.hpp>\n")

file(GLOB TESTS tests/*.cpp)
add_executable(tests_iomanip ${TESTS} ${CMAKE_CURRENT_BINARY_DIR}/gprotect.cpp)
target_link_libraries(tests_iomanip iomanip Catch2::Catch2WithMain)


include(Catch)
catch_discover_tests(tests_iomanip)
