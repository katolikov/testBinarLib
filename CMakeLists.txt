cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(testBinarLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(testBinarLib main.cpp libbsoncpp.hpp msgpack.hpp cbor.hpp)

find_package(msgpack REQUIRED)
find_package(bson-1.0 REQUIRED)
find_package(benchmark REQUIRED)

target_link_libraries(testBinarLib msgpackc mongo::bson_shared benchmark::benchmark)

