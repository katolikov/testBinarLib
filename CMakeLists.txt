cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else ()
    cmake_policy(VERSION 3.15)
endif ()

project(testBinarLib
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} source/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        include/bson.hpp
        include/cbor.hpp
        include/msgpack.hpp
        )

find_package(PkgConfig REQUIRED)
find_package(msgpack REQUIRED)
find_package(bson-1.0 REQUIRED)
find_package(benchmark REQUIRED)

pkg_check_modules(libcbor REQUIRED IMPORTED_TARGET libcbor)

target_link_libraries(${PROJECT_NAME} PUBLIC
        msgpackc
        mongo::bson_shared
        benchmark::benchmark
        PkgConfig::libcbor
        )

