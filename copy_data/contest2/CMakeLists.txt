cmake_minimum_required(VERSION 3.0)

project(Contest1 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ProblemA a/main.cpp)
add_executable(ProblemB b/main.cpp)
add_executable(ProblemC_v1 c/main_v1.cpp)
add_executable(ProblemC_v2 c/main_v2.cpp)
add_executable(ProblemD d/main.cpp)
add_executable(ProblemE e/main.cpp)
add_executable(ProblemG g/main.cpp)
