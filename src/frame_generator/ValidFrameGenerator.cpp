//
// Created by avkozyrev on 16.12.22.
//

#include <utility>
#include "ValidFrameGenerator.h"

Frame ValidFrameGenerator::generate() {
    uint8_t type;
    double generated = type_generator(rng);
    if (generated < 0) {
        type = 0;
    } else if (generated > TOTAL_FRAME_TYPES - 1) {
        type = TOTAL_FRAME_TYPES - 1;
    } else {
        type = static_cast<uint8_t>(generated);
    }

    return {
            .ap = aps[ap_chooser(rng)],
            .client = clients[client_chooser(rng)],
            .direction = bool_generator(rng)
                         ? Direction::FROM_AP
                         : Direction::TO_AP,
            .type = type
    };
}

ValidFrameGenerator::ValidFrameGenerator(std::vector<Address> aps, std::vector<Address> clients)
        : aps{std::move(aps)}, clients{std::move(clients)} {

}
