cmake_minimum_required(VERSION 3.10)

project(Animal)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
src/main.cpp
src/Animal.cpp
src/Cat.cpp
src/Dog.cpp)
include_directories(src)

add_executable(calc ${SOURCES})