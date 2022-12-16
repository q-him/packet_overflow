//
// Created by avkozyrev on 16.12.22.
//

#include "RandomFrameGenerator.h"

Frame RandomFrameGenerator::generate() {
    return {
        .ap = address_generator(rng),
        .client = address_generator(rng),
        .direction = bool_generator(rng)
                ? Direction::FROM_AP
                : Direction::TO_AP,
        .type = type_generator(rng)
    };
}
