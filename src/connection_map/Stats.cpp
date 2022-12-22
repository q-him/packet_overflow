//
// Created by avkozyrev on 15.12.22.
//

#include <iomanip>
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
            std::chrono::duration_cast<std::chrono::seconds>(
                    last_seen - first_seen
            ).count()
    ) + 1.0;

    return score;
}

void write_time_point(std::ostream &out, const TimePoint &tp) {
    std::time_t time = Clock::to_time_t(tp);
    out << std::put_time(std::localtime(&time), "%H:%M:%S");
}

std::ostream &operator<<(std::ostream &out, const Stats &stats) {
    out << "first_seen=";
    write_time_point(out, stats.first_seen);
    out <<", last_seen=";
    write_time_point(out, stats.last_seen);
    out << ", total_frames=" << stats.total_frames;
    out << ", rating=" << stats.evaluate();

    constexpr std::size_t cols = 5;
    for (std::size_t i = 0; i < stats.type_counts.size(); i++) {
        if (i % cols == 0) {
            out << std::endl << '\t';
        }

        out << stats.type_counts[i] << '\t';
    }
    return out;
}
