#ifndef CPP_SP2_OVERFLOWEXCEPTION_H
#define CPP_SP2_OVERFLOWEXCEPTION_H

#include <string>
#include <stdexcept>

class OverflowException : public std::runtime_error {
public:
    OverflowException() : std::runtime_error("Number overflow") {}

    OverflowException(std::string &msg) : std::runtime_error(msg.c_str()) {}
    OverflowException(std::string &&msg) : std::runtime_error(msg.c_str()) {}
};

#endif //CPP_SP2_OVERFLOWEXCEPTION_H
