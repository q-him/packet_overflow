#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include "common.h"
#include "ConnectionMap.h"
#include "frame_generator/RandomFrameGenerator.h"
#include "frame_generator/ValidFrameGenerator.h"

using namespace std::chrono_literals;

static ConnectionMap map(32, 16);
static std::queue<Frame> frames;
static std::mutex frames_mutex;

std::vector<Address> load_addresses(const std::string &path) {
    std::vector<Address> addresses;

    std::ifstream file_stream {path};
    std::string line;

    std::regex address_regex {"(([0-9a-f]{1,2}):([0-9a-f]{1,2}):([0-9a-f]{1,2}):([0-9a-f]{1,2}))"};

    while (std::getline(file_stream, line)) {
        auto begin = std::sregex_iterator(line.begin(), line.end(), address_regex);
        auto end = std::sregex_iterator();

        if (begin == end) {
            continue;
        }

        const std::smatch& match = *begin;

        int b3 = std::stoi(match[2].str(), nullptr, 16);
        int b2 = std::stoi(match[3].str(), nullptr, 16);
        int b1 = std::stoi(match[4].str(), nullptr, 16);
        int b0 = std::stoi(match[5].str(), nullptr, 16);

        addresses.push_back(b0 | (b1 << 8) | (b2 << 16) | (b3 << 24));
    }

    return addresses;
}

[[noreturn]] void generator_thread(
        FrameGenerator &generator,
        std::chrono::duration<double, std::milli> sleep_time
) {
    while (true) {
        std::this_thread::sleep_for(sleep_time);
        std::lock_guard lock{frames_mutex};
        frames.push(generator.generate());
    }
}

[[noreturn]] void feeder_thread() {
    std::queue<Frame> frames_buffer;
    while (true) {
        {
            std::lock_guard lock{frames_mutex};

            if (frames.empty()) {
                continue;
            }

            std::swap(frames, frames_buffer);
        }

        while (!frames_buffer.empty()) {
            map.feed(frames_buffer.front());
            frames_buffer.pop();
        }
    }
}

[[noreturn]] int main() {
    RandomFrameGenerator random_generator;

    auto aps = load_addresses("../aps.txt");
    auto clients = load_addresses("../clients.txt");
    ValidFrameGenerator valid_generator{aps, clients};

    std::thread valid_generator_thread {generator_thread, std::ref(valid_generator), 500ms};
    std::thread random_generator_thread {generator_thread, std::ref(random_generator), 500ms};
    std::thread feeder {feeder_thread};

    while (true) {
        std::cin.get();
        std::lock_guard lock{frames_mutex};
        std::cout << map << std::endl;
    }
}
