cmake_minimum_required(VERSION 2.9 FATAL_ERROR)
set(PROPERTIES LINKER_LANGUAGE CXX)

project (Maze)

include_directories(include)

add_library(Maze
    Maze.hpp
)

add_library(Robot
    Robot.cpp
)

add_library(RandomRobot
    RandomRobot.hpp
)

add_library(RightHandRuleRobot
    RightHandRuleRobot.hpp
)

add_executable(main
    main.cpp
)

target_link_libraries(main
    Robot
    RightHandRuleRobot
    RandomRobot
    Maze
)