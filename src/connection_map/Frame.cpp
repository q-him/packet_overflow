#include "Frame.h"

#include <iomanip>

std::ostream &operator<<(std::ostream &out, const Frame &frame) {
    out << "Frame{ap=";
    write_address(out, frame.ap);

    out << ", client=";
    write_address(out, frame.client);

    if (frame.direction == Direction::FROM_AP) {
        out << ", FROM_AP, ";
    } else {
        out << ", TO_AP, ";
    }

    std::time_t time = Clock::to_time_t(frame.when);
    out << std::put_time(std::localtime(&time), "%H:%M%S");

    // uint8_t может быть выведен как char в зависимости от компилятора
    out << ", type=" << static_cast<int>(frame.type) << "}";

    return out;
}
