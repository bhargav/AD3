cmake_minimum_required(VERSION 2.8)
project(ad3_root)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wno-sign-compare -c -fmessage-length=0")

add_subdirectory(ad3)
add_subdirectory(jni)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples/dense)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples/logic)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples/parsing)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/examples/summarization)

add_executable(ad3_simple_coref ${CMAKE_CURRENT_SOURCE_DIR}/examples/logic/simple_coref.cpp)
