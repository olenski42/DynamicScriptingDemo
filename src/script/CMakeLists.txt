cmake_minimum_required(VERSION 3.15)

project(MyScript)

set(CMAKE_CXX_STANDARD 17)

add_library(MyScript SHARED MyScript.cpp)
target_include_directories(MyScript PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../common)
