cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(testBinarLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(testBinarLib main.cpp)

find_package(msgpack)

target_link_libraries(testBinarLib msgpackc)
target_include_directories(testBinarLib PRIVATE ${PROJECT_SOURCE_DIR}/include)
