#ifndef CPP_SP2_VALIDATORS_H
#define CPP_SP2_VALIDATORS_H

#include <string>

bool is_valid_number(const std::string &num) {
    for (char digit: num)
        if (digit < '0' or digit > '9')
            return false;

    return true;
}


void strip_leading_zeroes(std::string &num) {
    size_t i;
    for (i = 0; i < num.size(); i++)
        if (num[i] != '0')
            break;

    if (i == num.size())
        num = "0";
    else
        num = num.substr(i);
}


void add_leading_zeroes(std::string &num, size_t num_zeroes) {
    num = std::string(num_zeroes, '0') + num;
}


void add_trailing_zeroes(std::string &num, size_t num_zeroes) {
    num += std::string(num_zeroes, '0');
}


std::tuple<std::string, std::string> getLargerAndSmaller(const std::string &num1,
                                                         const std::string &num2) {
    std::string larger, smaller;
    if (num1.size() > num2.size() or
        (num1.size() == num2.size() and num1 > num2)) {
        larger = num1;
        smaller = num2;
    } else {
        larger = num2;
        smaller = num1;
    }

    // pad the smaller number with zeroes
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    return std::make_tuple(larger, smaller);
}

bool is_power_of_10(const std::string &num) {
    if (num[0] != '1')
        return false;
    for (size_t i = 1; i < num.size(); i++)
        if (num[i] != '0')
            return false;

    return true;    // first digit is 1 and the following digits are all 0
}

#endif //CPP_SP2_VALIDATORS_H
