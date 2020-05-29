cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(testBinarLib)

set(CMAKE_CXX_STANDARD 20)

add_executable(testBinarLib main.cpp libbsoncpp.hpp)

find_package(msgpack)
find_package(bson-1.0 1.7 REQUIRED)

target_link_libraries(testBinarLib msgpackc mongo::bson_shared)
target_include_directories(testBinarLib PRIVATE ${PROJECT_SOURCE_DIR}/include)

#find_package(libbsoncxx REQUIRED)
#find_package(libmongocxx REQUIRED)
#find_package (libbson-1.0 1.7 REQUIRED)

#include_directories(${LIBMONGOCXX_LIBRARIES})
#include_directories(${LIBBSONCXX_LIBRARIES})
#include_directories(${LIBMONGOCXX_INCLUDE_DIRS})
#include_directories(${LIBBSONCXX_INCLUDE_DIRS})

#target_link_libraries(testBinarLib ${LIBMONGOCXX_LIBRARIES} ${LIBBSONCXX_LIBRARIES})

