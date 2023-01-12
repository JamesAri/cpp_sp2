#ifndef CPP_SP2_CONSTRUCTORS_H
#define CPP_SP2_CONSTRUCTORS_H

#include "MPInt.h"
#include "util/util.h"


MPInt::MPInt() {
    value = "0";
    sign = '+';
}


MPInt::MPInt(const MPInt &num) {
    value = num.value;
    sign = num.sign;
}


MPInt::MPInt(const long long &num) {
    value = std::to_string(std::abs(num));
    if (num < 0)
        sign = '-';
    else
        sign = '+';
}


MPInt::MPInt(const std::string &num) {
    if (num[0] == '+' or num[0] == '-') {
        std::string magnitude = num.substr(1);
        if (is_valid_number(magnitude)) {
            value = magnitude;
            sign = num[0];
        } else {
            throw std::invalid_argument("Expected an integer, got \"" + num + "\"");
        }
    } else {
        if (is_valid_number(num)) {
            value = num;
            sign = '+';
        } else {
            throw std::invalid_argument("Expected an integer, got \"" + num + "\"");
        }
    }
    strip_leading_zeroes(value);
}

#endif //CPP_SP2_CONSTRUCTORS_H
