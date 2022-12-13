cmake_minimum_required(VERSION 3.23)
project(Nim_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(Nim_game main.cpp Player.cpp Player.h Human.cpp Human.h Computer.cpp Computer.h NimGame.cpp NimGame.h)
