//
// Created by avkozyrev on 16.12.22.
//

#ifndef PACKET_OVERFLOW_VALIDFRAMEGENERATOR_H
#define PACKET_OVERFLOW_VALIDFRAMEGENERATOR_H

#include <random>
#include "FrameGenerator.h"

class ValidFrameGenerator : public FrameGenerator {
public:
    Frame generate() override;

    ValidFrameGenerator(std::vector<Address> aps, std::vector<Address> clients);

private:
    std::vector<Address> aps;
    std::vector<Address> clients;
    std::random_device random_device;
    std::default_random_engine rng{random_device()};
    std::normal_distribution<double> type_generator{5, 2.0};
    std::uniform_int_distribution<std::size_t> ap_chooser{0, aps.size()};
    std::uniform_int_distribution<std::size_t> client_chooser{0, clients.size()};
    std::uniform_int_distribution<int> bool_generator {0, 1};
};


#endif //PACKET_OVERFLOW_VALIDFRAMEGENERATOR_H
