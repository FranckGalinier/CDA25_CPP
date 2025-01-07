cmake_minimum_required(VERSION 3.10)

project(objets)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
src/contact.cpp
src/Person.cpp
src/Etudiant.cpp)
include_directories(src)

add_executable(calc ${SOURCES})