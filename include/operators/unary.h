#ifndef CPP_SP2_UNARY_H
#define CPP_SP2_UNARY_H

#include "MPInt.h"

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> MPInt<T>::operator+() const {
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> MPInt<T>::operator-() const {
    MPInt temp;
    temp.value = value;
    if (value != "0") {
        if (sign == '-')
            temp.sign = '+';
        else
            temp.sign = '-';
    }
    return temp;
}

#endif //CPP_SP2_UNARY_H
