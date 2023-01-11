#ifndef CPP_SP2_CONVERT_H
#define CPP_SP2_CONVERT_H

#include "MPInt.h"

std::string MPInt::to_string() const {
    if (sign == '-')
        return sign + value;
    return value;
}

#endif //CPP_SP2_CONVERT_H
