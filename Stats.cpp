//
// Created by avkozyrev on 15.12.22.
//
#include "Stats.h"

double Stats::evaluate() const {
    double max = 300.0;
    double min = 100.0;
    std::size_t steps = type_counts.size() / 2;
    double delta = (max - min) / static_cast<double>(steps);
    double increment = -delta;

    double score = 0.0;

    // score += tc[0] / max + ... + tc[i] / min + ... tc[n] / max;
    double divider = max;
    for (unsigned int count : type_counts) {
        score += count / divider;
        divider += increment;
        if (divider <= min) {
            increment = delta;
        }
    }
    score *= static_cast<double>(total_frames);
    score *= static_cast<double>(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                    last_seen - first_seen
            ).count()
    );

    return score;
}