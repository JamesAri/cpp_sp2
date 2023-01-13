#ifndef CPP_SP2_UNARY_H
#define CPP_SP2_UNARY_H

#include "base/MPIntBase.h"


MPIntBase MPIntBase::operator+() const {
    return *this;
}

MPIntBase MPIntBase::operator-() const {
    MPIntBase temp;
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
