//
// Created by avkozyrev on 15.12.22.
//

#include "ConnectionMap.h"

Stats &ConnectionMap::get_or_create(const Frame &frame) {
    Connection connection{
            .ap = frame.ap,
            .client = frame.client
    };
    auto it{connection_stats.find(connection)};
    if (it != connection_stats.end()) {
        return it->second;
    }

    return connection_stats[connection];
}

void ConnectionMap::feed(const Frame &frame) {
    cleanup_if_needed();

    Stats &stats{get_or_create(frame)};

    if (stats.total_frames == 0) {
        stats.first_seen = frame.when;
        stats.last_seen = frame.when;
    } else if (stats.last_seen < frame.when) {
        stats.last_seen = frame.when;
    }

    stats.total_frames++;
    stats.type_counts[frame.type]++;
}

void ConnectionMap::cleanup_if_needed() {
    if (connection_stats.size() >= capacity) {
        cleanup();
    }
}

struct ConnectionRating {
    Connection connection;
    double rating;
};

void ConnectionMap::cleanup() {
    std::vector<ConnectionRating> ratings;

    for (auto &connection_stat: connection_stats) {
        ratings.push_back({
                                  connection_stat.first,
                                  connection_stat.second.evaluate()
                          });
    }

    std::sort(ratings.begin(), ratings.end(), [](auto r1, auto r2) {
        return r1.rating > r2.rating;
    });

    for (std::size_t i = count_after_cleanup; i < ratings.size(); i++) {
        connection_stats.erase(ratings[i].connection);
    }
}

ConnectionMap::ConnectionMap(std::size_t capacity, std::size_t count_after_cleanup)
        : capacity{capacity}, count_after_cleanup{count_after_cleanup} {
}
