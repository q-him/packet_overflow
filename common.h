//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_COMMON_H
#define PACKET_OVERFLOW_COMMON_H

#include <chrono>

using Address = uint32_t;
using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

constexpr std::size_t TOTAL_FRAME_TYPES = 10;

#endif //PACKET_OVERFLOW_COMMON_H
