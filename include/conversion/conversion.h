#ifndef CPP_SP2_CONVERSION_H
#define CPP_SP2_CONVERSION_H

#include "MPInt.h"

std::string MPInt::to_string() const {
    if (sign == '-')
        return sign + value;
    return value;
}

#endif //CPP_SP2_CONVERSION_H
