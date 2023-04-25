cmake_minimum_required(VERSION 3.5)

project(HackerRank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HackerRank main.cpp)

install(TARGETS HackerRank
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
