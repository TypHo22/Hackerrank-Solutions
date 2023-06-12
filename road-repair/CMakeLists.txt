cmake_minimum_required(VERSION 3.5)

project(road-repair LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(road-repair main.cpp)
target_link_libraries(road-repair  Threads::Threads)
