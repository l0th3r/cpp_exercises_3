cmake_minimum_required(VERSION 3.5)

project(cpp_exercises_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_exercises_3 s_number.h main.cpp s_number.cpp)
