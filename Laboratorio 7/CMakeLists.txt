#Battistin Claudio
cmake_minimum_required(VERSION 2.9 FATAL_ERROR)
project (Maze LANGUAGES CXX)

include_directories(include)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/labirinto.txt
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(main
    src/main.cpp
)
