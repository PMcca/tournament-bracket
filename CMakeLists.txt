cmake_minimum_required(VERSION 3.0)

include_directories(include/)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(tournament-bracket)

add_executable(
  tournament-main
  src/main.cpp
  src/Round.cpp
  src/Tournament.cpp
  include/Round.h
  include/Tournament.h
  include/Player.h
)
