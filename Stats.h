//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_STATS_H
#define PACKET_OVERFLOW_STATS_H

#include "common.h"
#include <array>

struct Stats {
    TimePoint first_seen = TimePoint();
    TimePoint last_seen = TimePoint();
    unsigned long total_frames = 0;
    std::array<unsigned int, TOTAL_FRAME_TYPES> type_counts = {0};

    [[nodiscard]] double evaluate() const;
};

#endif //PACKET_OVERFLOW_STATS_H
