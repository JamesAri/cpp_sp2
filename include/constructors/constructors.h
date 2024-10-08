#ifndef CPP_SP2_CONSTRUCTORS_H
#define CPP_SP2_CONSTRUCTORS_H

#include "base/MPIntBase.h"
#include "util/util.h"


MPIntBase::MPIntBase() {
    value = "0";
    sign = '+';
}


MPIntBase::MPIntBase(const MPIntBase &num) {
    value = num.value;
    sign = num.sign;
}


MPIntBase::MPIntBase(const long long &num) {
    value = std::to_string(std::abs(num));
    if (num < 0)
        sign = '-';
    else
        sign = '+';
}


MPIntBase::MPIntBase(const std::string &num) {
    if (num[0] == '+' or num[0] == '-') {
        std::string magnitude = num.substr(1);
        if (isValidNumber(magnitude)) {
            value = magnitude;
            sign = num[0];
        } else {
            throw std::invalid_argument("Expected an integer, but got: " + num);
        }
    } else {
        if (isValidNumber(num)) {
            value = num;
            sign = '+';
        } else {
            throw std::invalid_argument("Expected an integer, but got: " + num);
        }
    }
    removeLeadingZeroes(value);
}

#endif //CPP_SP2_CONSTRUCTORS_H
