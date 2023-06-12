cmake_minimum_required(VERSION 3.5)

project(vowel-substring LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Threads REQUIRED)
add_executable(vowel-substring main.cpp)
target_link_libraries(vowel-substring  Threads::Threads)
