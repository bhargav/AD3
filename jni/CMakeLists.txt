cmake_minimum_required(VERSION 2.8)
project(AD3Jni20)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(src/main/cpp)

set(AD3_JNI_SOURCES src/main/cpp/BinaryVariable.cpp
    src/main/cpp/MultiVariable.cpp
    src/main/cpp/Factor.cpp
    src/main/cpp/FactorGraph.cpp
    src/main/cpp/Utils.cpp)

add_library(AD3Jni20 MODULE ${AD3_JNI_SOURCES})
set_target_properties(AD3Jni20 PROPERTIES SUFFIX ".jnilib")
target_link_libraries(AD3Jni20 ${JNI_LIBRARIES} ad3)

if(${UNIX})
    set(CMAKE_CXX_FLAGS "-fPIC")
    set_target_properties(AD3Jni20 PROPERTIES CMAKE_SHARED_LINKER_FLAGS "-fPIC")
elseif(${WINDOWS})
    set(CMAKE_CXX_FLAGS "/MP /EHsc")
endif(${UNIX})

