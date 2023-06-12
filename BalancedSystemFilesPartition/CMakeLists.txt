cmake_minimum_required(VERSION 3.5)

project(HackerRank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(BalancedSystemFilesPartition main.cpp)
target_link_libraries(BalancedSystemFilesPartition  Threads::Threads)
