#ifndef CPP_SP2_OVERFLOWRUNTIMEEXCEPTION_H
#define CPP_SP2_OVERFLOWRUNTIMEEXCEPTION_H

#include <string>
#include <stdexcept>
#include "MPInt.h"

class OverflowRuntimeException : public std::runtime_error {
public:
    OverflowRuntimeException() : runtime_error("Number overflow") {}

    explicit OverflowRuntimeException(std::string &msg) : runtime_error(msg.c_str()) {}

    template<size_t T>
    explicit OverflowRuntimeException(MPInt<T> &num):
            runtime_error("MPInt<" + std::to_string(T) + "> number overflow.\n"
                                                         "value=" + num.to_string()) {}
};

#endif //CPP_SP2_OVERFLOWRUNTIMEEXCEPTION_H
