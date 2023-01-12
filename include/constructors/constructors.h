#ifndef CPP_SP2_CONSTRUCTORS_H
#define CPP_SP2_CONSTRUCTORS_H

#include "MPInt.h"
#include "util/util.h"

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T>::MPInt() {
    value = "0";
    sign = '+';
}

template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T>::MPInt(const MPInt<U> &num) {
    value = num.value;
    sign = num.sign;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T>::MPInt(const long long &num) {
    value = std::to_string(std::abs(num));
    if (num < 0)
        sign = '-';
    else
        sign = '+';
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T>::MPInt(const std::string &num) {
    if (num[0] == '+' or num[0] == '-') {
        std::string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        } else {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    } else {
        if (is_valid_number(num)) {
            value = num;
            sign = '+';
        } else {
            throw std::invalid_argument("Expected an integer, got \'" + num + "\'");
        }
    }
    strip_leading_zeroes(value);
}

#endif //CPP_SP2_CONSTRUCTORS_H
