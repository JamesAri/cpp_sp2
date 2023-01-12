#ifndef CPP_SP2_CONVERSION_H
#define CPP_SP2_CONVERSION_H

#include "MPInt.h"

template <size_t T>  requires AtLeastFourBytes<T>
std::string MPInt<T>::to_string() const {
    if (sign == '-')
        return sign + value;
    return value;
}

#endif //CPP_SP2_CONVERSION_H
