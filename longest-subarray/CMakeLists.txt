cmake_minimum_required(VERSION 3.5)

project(longest-subarray LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(longest-subarray main.cpp)
target_link_libraries(longest-subarray  Threads::Threads)

