cmake_minimum_required(VERSION 2.8)
project(ad3)

file(GLOB libAD3_SOURCES *.cpp)
file(GLOB libAD3_HEADERS *.h)

set(EIGEN3_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../Eigen)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
find_package(Eigen3 REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Eigen)

add_library(ad3 ${libAD3_SOURCES} ${libAD3_HEADERS})
target_include_directories(ad3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wno-sign-compare -c -fmessage-length=0 -fPIC")
set_target_properties(ad3 PROPERTIES CMAKE_SHARED_LINKER_FLAGS "-lpthread")
