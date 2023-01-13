#ifndef CPP_SP2_UTIL_H
#define CPP_SP2_UTIL_H

#include <string>

inline void removeLeadingZeroes(std::string &num) {
    size_t i;
    for (i = 0; i < num.size(); i++) {
        if (num[i] != '0')
            break;
    }

    if (i == num.size())
        num = "0";
    else
        num = num.substr(i);
}


inline void prependZeroes(std::string &num, size_t num_zeroes) {
    num = std::string(num_zeroes, '0') + num;
}


inline void appendZeroes(std::string &num, size_t num_zeroes) {
    num += std::string(num_zeroes, '0');
}


inline std::tuple<std::string, std::string>
getLargerAndSmaller(const std::string &num1, const std::string &num2) {
    std::string larger, smaller;
    if (num1.size() > num2.size() || (num1.size() == num2.size() && num1 > num2)) {
        larger = num1;
        smaller = num2;
    } else {
        larger = num2;
        smaller = num1;
    }
    prependZeroes(smaller, larger.size() - smaller.size());
    return std::make_tuple(larger, smaller);
}


inline bool isValidNumber(const std::string &num) {
    for (const auto digit: num) { // Would use std::ranges::all_of(), but Apple Clang..
        if (digit < '0' || digit > '9')
            return false;
    }
    return true;
}


#endif //CPP_SP2_UTIL_H
