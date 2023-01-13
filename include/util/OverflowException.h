#ifndef CPP_SP2_OVERFLOWEXCEPTION_H
#define CPP_SP2_OVERFLOWEXCEPTION_H

#include <string>
#include <stdexcept>
#include "emulator/MPInt.h"
#include "emulator/concepts.h"

class OverflowException : public std::runtime_error {
public:
    const std::string number;

    OverflowException() : std::runtime_error("Number overflow"), number{0} {}

    explicit OverflowException(std::string &msg, std::string &&value) :
            std::runtime_error(msg.c_str()), number{value} {}

    explicit OverflowException(std::string &&msg, std::string &&value) :
            std::runtime_error(msg.c_str()), number{value} {}
};

#endif //CPP_SP2_OVERFLOWEXCEPTION_H
