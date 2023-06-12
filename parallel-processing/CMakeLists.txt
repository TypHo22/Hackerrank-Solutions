cmake_minimum_required(VERSION 3.5)

project(parallel-processing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(parallel-processing main.cpp)
target_link_libraries(parallel-processing  Threads::Threads)
