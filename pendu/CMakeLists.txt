cmake_minimum_required(VERSION 3.10)

project(pendu)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
src/main.cpp
src/utils.cpp)
include_directories(src)

add_executable(calc ${SOURCES})