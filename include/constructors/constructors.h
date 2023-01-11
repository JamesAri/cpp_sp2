#ifndef CPP_SP2_CONSTRUCTORS_H
#define CPP_SP2_CONSTRUCTORS_H

#include "MPInt.h"

template <typename T>
MPInt<T>::MPInt() {
    value = "0";
    sign = '+';
}

template <typename T>
MPInt<T>::MPInt(const MPInt &num) {
    value = num.value;
    sign = num.sign;
}


template <typename T>
MPInt<T>::MPInt(const long long &num) {
    value = std::to_string(std::abs(num));
    if (num < 0)
        sign = '-';
    else
        sign = '+';
}


template <typename T>
MPInt<T>::MPInt(const std::string &num) {
    if (num[0] == '+' or num[0] == '-') {
        std::string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        } else {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    } else {      // if no sign is specified
        if (is_valid_number(num)) {
            value = num;
            sign = '+';    // positive by default
        } else {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    }
    strip_leading_zeroes(value);
}

#endif //CPP_SP2_CONSTRUCTORS_H
