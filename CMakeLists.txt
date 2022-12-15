cmake_minimum_required(VERSION 3.24)
project(packet_overflow)

set(CMAKE_CXX_STANDARD 17)

add_executable(packet_overflow main.cpp Frame.h ConnectionMap.h ConnectionMap.cpp Stats.h common.h Stats.cpp)
