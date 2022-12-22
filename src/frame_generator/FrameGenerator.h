//
// Created by avkozyrev on 16.12.22.
//

#ifndef PACKET_OVERFLOW_FRAMEGENERATOR_H
#define PACKET_OVERFLOW_FRAMEGENERATOR_H

#include "../connection_map/Frame.h"

class FrameGenerator {
public:
    [[nodiscard]] virtual Frame generate() = 0;

    virtual ~FrameGenerator() = default;
};


#endif //PACKET_OVERFLOW_FRAMEGENERATOR_H
