//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_FRAME_H
#define PACKET_OVERFLOW_FRAME_H

#include <array>
#include <cstdint>
#include <chrono>
#include "common.h"

enum class Direction {
    FROM_AP,
    TO_AP
};

struct Frame {
    Address ap;
    Address client;
    Direction direction;
    TimePoint when = Clock::now();
    uint8_t type;
};

#endif //PACKET_OVERFLOW_FRAME_H
