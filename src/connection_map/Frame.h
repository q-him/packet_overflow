//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_FRAME_H
#define PACKET_OVERFLOW_FRAME_H

#include <array>
#include <cstdint>
#include <chrono>
#include <iostream>
#include "../common.h"

enum class Direction {
    FROM_AP,
    TO_AP
};

struct Frame {
    Address ap{0};
    Address client{0};
    Direction direction{Direction::FROM_AP};
    TimePoint when{Clock::now()};
    uint8_t type{0};
};

std::ostream &operator<<(std::ostream &out, const Frame &frame);

#endif //PACKET_OVERFLOW_FRAME_H
