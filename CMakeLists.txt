cmake_minimum_required(VERSION 3.24)
project(packet_overflow)

set(CMAKE_CXX_STANDARD 17)

add_executable(packet_overflow src/main.cpp src/connection_map/Frame.h src/connection_map/ConnectionMap.h src/connection_map/ConnectionMap.cpp src/connection_map/Stats.h src/common.h src/connection_map/Stats.cpp src/frame_generator/FrameGenerator.h src/frame_generator/RandomFrameGenerator.cpp src/frame_generator/RandomFrameGenerator.h src/connection_map/Frame.cpp src/common.cpp src/frame_generator/ValidFrameGenerator.cpp src/frame_generator/ValidFrameGenerator.h)
