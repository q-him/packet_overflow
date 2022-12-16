//
// Created by avkozyrev on 16.12.22.
//

#include <iostream>
#include "common.h"

void write_address(std::ostream &out, Address address) {
    uint32_t b0 = address & 0xFF;
    uint32_t b1 = (address >> 8) & 0xFF;
    uint32_t b2 = (address >> 16) & 0xFF;
    uint32_t b3 = (address >> 24) & 0xFF;

    out << std::hex << b3 << ':' << b2 << ':' << b1 << ':' << b0 << std::dec;
}
