cmake_minimum_required(VERSION 3.5)

project(maximum-cost-of-laptop-count LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(maximum-cost-of-laptop-count main.cpp)
target_link_libraries(maximum-cost-of-laptop-count  Threads::Threads)
