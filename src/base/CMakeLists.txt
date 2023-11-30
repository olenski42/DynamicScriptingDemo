cmake_minimum_required(VERSION 3.15)

project(base)

add_compile_definitions(LIB_PATH="${CMAKE_CURRENT_SOURCE_DIR}/../script/build/")

set(CMAKE_CXX_STANDARD 17)

add_executable(base ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(base PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../common)