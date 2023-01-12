#ifndef CPP_SP2_UNARY_H
#define CPP_SP2_UNARY_H

#include "MPInt.h"


MPInt MPInt::operator+() const {
    return *this;
}

MPInt MPInt::operator-() const {
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
