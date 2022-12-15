//
// Created by avkozyrev on 15.12.22.
//

#ifndef PACKET_OVERFLOW_CONNECTIONMAP_H
#define PACKET_OVERFLOW_CONNECTIONMAP_H

#include "Frame.h"
#include "common.h"
#include "Stats.h"
#include <functional>
#include <unordered_map>

struct Connection {
    Address ap;
    Address client;
};

bool operator==(const Connection& lhs, const Connection& rhs) {
    return lhs.ap == rhs.ap && lhs.client == rhs.client;
}

template<>
struct std::hash<Connection> {
    std::size_t operator()(Connection const& c) const noexcept {
        uint64_t comibined =
                static_cast<uint64_t>(c.ap) + (static_cast<uint64_t>(c.client) << 32);
        return std::hash<uint64_t>{}(comibined);
    }
};

struct ConnectionMap {
    ConnectionMap(std::size_t capacity, std::size_t count_after_cleanup);
    void feed(const Frame& frame);
private:
    std::size_t capacity;
    std::size_t count_after_cleanup;
    std::unordered_map<Connection, Stats> connection_stats;

    Stats& get_or_create(const Frame &frame);
    void cleanup_if_needed();
    void cleanup();
};


#endif //PACKET_OVERFLOW_CONNECTIONMAP_H
