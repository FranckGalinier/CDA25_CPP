cmake_minimum_required(VERSION 3.10)

project(carnet)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
    src/main.cpp
    src/Carnet.cpp)

include_directories(src)

# Trouver MySQL Connector/C++
find_package(MySQL REQUIRED)

# Inclure les répertoires d'en-tête MySQL
include_directories(${MYSQL_INCLUDE_DIR})

# Ajouter l'exécutable
add_executable(calc ${SOURCES})

# Lier les bibliothèques MySQL
target_link_libraries(calc ${MYSQL_LIBRARY})
