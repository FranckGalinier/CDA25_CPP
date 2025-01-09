cmake_minimum_required(VERSION 3.10)

project(carnet)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
src/main.cpp
src/Carnet.cpp)
include_directories(src)

add_executable(calc ${SOURCES})