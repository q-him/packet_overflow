cmake_minimum_required(VERSION 3.24)
project(packet_overflow)

set(CMAKE_CXX_STANDARD 17)

add_executable(packet_overflow src/main.cpp src/Frame.h src/ConnectionMap.h src/ConnectionMap.cpp src/Stats.h src/common.h src/Stats.cpp src/frame_generator/FrameGenerator.h src/frame_generator/RandomFrameGenerator.cpp src/frame_generator/RandomFrameGenerator.h src/Frame.cpp src/common.cpp src/frame_generator/ValidFrameGenerator.cpp src/frame_generator/ValidFrameGenerator.h)
