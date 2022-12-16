//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_COMMON_H
#define PACKET_OVERFLOW_COMMON_H

#include <chrono>

using Address = uint32_t;
constexpr uint32_t ADDRESS_MIN = 0;
constexpr uint32_t ADDRESS_MAX = UINT32_MAX;
using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;

constexpr std::size_t TOTAL_FRAME_TYPES = 10;

void write_address(std::ostream &out, Address address);

#endif //PACKET_OVERFLOW_COMMON_H
