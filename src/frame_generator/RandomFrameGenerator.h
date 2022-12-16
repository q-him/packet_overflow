//
// Created by avkozyrev on 16.12.22.
//

#ifndef PACKET_OVERFLOW_RANDOMFRAMEGENERATOR_H
#define PACKET_OVERFLOW_RANDOMFRAMEGENERATOR_H

#include <random>
#include "FrameGenerator.h"

class RandomFrameGenerator : public FrameGenerator {
public:
    Frame generate() override;
private:
    std::random_device random_device;
    std::default_random_engine rng{random_device()};
    std::uniform_int_distribution<Address> address_generator {ADDRESS_MIN, ADDRESS_MAX};
    std::uniform_int_distribution<uint8_t> type_generator {0, TOTAL_FRAME_TYPES - 1};
    std::uniform_int_distribution<int> bool_generator {0, 1};
};


#endif //PACKET_OVERFLOW_RANDOMFRAMEGENERATOR_H
