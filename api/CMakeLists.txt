cmake_minimum_required(VERSION 3.10)

project(json)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
src/main.cpp
)
include_directories(src)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(calc ${CURL_LIBRARIES})

add_executable(calc ${SOURCES})