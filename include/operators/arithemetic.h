#ifndef CPP_SP2_ARITHEMETIC_H
#define CPP_SP2_ARITHEMETIC_H

#include "MPInt.h"
#include "math/math.h"
#include "util/util.h"
#include "util/constants.h"

#include <cmath>
#include <sstream>


/*
 * Algorithmic Time Complexity : O(n)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPInt MPInt::operator+(const MPInt &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) + (-num) = (+this) - (+num)
        MPInt tmp = num;
        tmp.sign = '+';
        return MPInt(*this - tmp);
    } else if (this->sign == '-' and num.sign == '+') { // (-this) + (+num) = -( (+this) - (+num) )
        MPInt tmp = *this;
        tmp.sign = '+';
        return MPInt(-(tmp - num));
    }

    auto [larger, smaller] = getLargerAndSmaller(this->value, num.value);

    MPInt result;
    result.value = "";
    int carry = 0, sum;
    auto length = static_cast<long>(larger.size());
    for (long i = length - 1; i >= 0; i--) {
        sum = larger[i] - '0' + smaller[i] - '0' + carry;
        result.value = std::to_string(sum % 10) + result.value;
        carry = static_cast<short>(sum / 10);
    }
    if (carry)
        result.value = std::to_string(carry) + result.value;

    if (this->sign == '-' and result.value != "0")
        result.sign = '-';

    return result;
}


MPInt MPInt::operator+(const std::string &num) const {
    return *this + MPInt(num);
}


MPInt MPInt::operator+(const long long &num) const {
    return *this + MPInt(num);
}


MPInt operator+(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) + rhs;
}


MPInt operator+(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) + rhs;
}


/*
 * Algorithmic Time Complexity : O(n)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPInt MPInt::operator-(const MPInt &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) - (-num) = (+this) + (+num)
        MPInt tmp = num;
        tmp.sign = '+';
        return MPInt(*this + tmp);
    } else if (this->sign == '-' and num.sign == '+') { // (-this) - (+num) = -( (+this) + (+num) )
        MPInt tmp = *this;
        tmp.sign = '+';
        return MPInt(-(tmp + num));
    }

    MPInt result;
    std::string larger, smaller;
    if (abs(*this) > abs(num)) {
        larger = this->value;
        smaller = num.value;

        if (this->sign == '-')      // (-larger) - (-smaller) = -result
            result.sign = '-';
    } else {
        larger = num.value;
        smaller = this->value;

        if (num.sign == '+')        // (+smaller) - (+larger) = -result
            result.sign = '-';
    }
    add_leading_zeroes(smaller, larger.size() - smaller.size());

    result.value = "";
    int difference;
    long i, j;
    auto length = static_cast<long>(larger.size());
    for (i = length - 1; i >= 0; i--) {
        difference = larger[i] - smaller[i];
        if (difference < 0) {
            for (j = i - 1; j >= 0; j--) {
                if (larger[j] != '0') {
                    larger[j]--;
                    break;
                }
            }
            j++;
            while (j != i) {
                larger[j] = '9';
                j++;
            }
            difference += 10;
        }
        result.value = std::to_string(difference) + result.value;
    }
    strip_leading_zeroes(result.value);

    if (result.value == "0")
        result.sign = '+';

    return result;
}


MPInt MPInt::operator-(const std::string &num) const {
    return *this - MPInt(num);
}


MPInt MPInt::operator-(const long long &num) const {
    return *this - MPInt(num);
}


MPInt operator-(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) - rhs;
}


MPInt operator-(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) - rhs;
}


/*
 * Using Karatsuba algorithm for fast multiplication.
 * https://en.wikipedia.org/wiki/Karatsuba_algorithm
 *
 * Algorithmic Time Complexity : O(n^log3)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPInt MPInt::operator*(const MPInt &num) const {
    if (*this == 0 or num == 0)
        return MPInt(0);
    if (*this == 1)
        return num;
    if (num == 1)
        return *this;

    MPInt product;
    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX and abs(num) <= FLOOR_SQRT_LLONG_MAX)
        product = std::stoll(this->value) * std::stoll(num.value);
    else {
        auto [larger, smaller] = getLargerAndSmaller(this->value, num.value);

        // Split the numbers in half
        size_t half_length = larger.size() / 2;
        auto half_length_ceil = (size_t) ceil(static_cast<double>(larger.size()) / 2.0);

        MPInt num1_high, num1_low, num2_high, num2_low;
        num1_high = larger.substr(0, half_length);
        num1_low = larger.substr(half_length);
        num2_high = smaller.substr(0, half_length);
        num2_low = smaller.substr(half_length);

        strip_leading_zeroes(num1_high.value);
        strip_leading_zeroes(num1_low.value);
        strip_leading_zeroes(num2_high.value);
        strip_leading_zeroes(num2_low.value);

        // Recursively compute high-, low- and mid-products
        MPInt prod_high, prod_mid, prod_low;
        prod_high = num1_high * num2_high;
        prod_low = num1_low * num2_low;
        prod_mid = (num1_high + num1_low) * (num2_high + num2_low) - prod_high - prod_low;

        add_trailing_zeroes(prod_high.value, 2 * half_length_ceil);
        add_trailing_zeroes(prod_mid.value, half_length_ceil);

        strip_leading_zeroes(prod_high.value);
        strip_leading_zeroes(prod_mid.value);
        strip_leading_zeroes(prod_low.value);

        product = prod_high + prod_mid + prod_low;
    }
    strip_leading_zeroes(product.value);

    if (this->sign == num.sign)
        product.sign = '+';
    else
        product.sign = '-';

    return product;
}


MPInt MPInt::operator*(const std::string &num) const {
    return *this * MPInt(num);
}


MPInt MPInt::operator*(const long long &num) const {
    return *this * MPInt(num);
}


MPInt operator*(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) * rhs;
}


MPInt operator*(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) * rhs;
}


std::tuple<MPInt, MPInt> divide(const MPInt &dividend, const MPInt &divisor) {
    MPInt quotient, remainder, temp;

    temp = divisor;
    quotient = 1;
    while (temp < dividend) {
        quotient += 1;
        temp += divisor;
    }
    if (temp > dividend) {
        quotient -= 1;
        remainder = dividend - (temp - divisor);
    }

    return std::make_tuple(quotient, remainder);
}

/*
 * Algorithmic Time Complexity : O(n^2)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPInt MPInt::operator/(const MPInt &num) const {
    MPInt abs_dividend = abs(*this);
    MPInt abs_divisor = abs(num);

    if (num == 0)
        throw std::logic_error("Attempted division by zero");
    if (abs_dividend < abs_divisor)
        return MPInt(0);
    if (num == 1)
        return *this;
    if (num == -1)
        return -(*this);

    MPInt quotient;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        quotient = std::stoll(abs_dividend.value) / std::stoll(abs_divisor.value);
    else if (abs_dividend == abs_divisor)
        quotient = 1;
    else {
        quotient.value = "";    // the value is cleared as digits will be appended
        MPInt chunk, chunk_quotient, chunk_remainder;
        size_t chunk_index = 0;
        chunk_remainder.value = abs_dividend.value.substr(chunk_index, abs_divisor.value.size() - 1);
        chunk_index = abs_divisor.value.size() - 1;
        while (chunk_index < abs_dividend.value.size()) {
            chunk.value = chunk_remainder.value.append(1, abs_dividend.value[chunk_index]);
            chunk_index++;
            while (chunk < abs_divisor) {
                quotient.value += "0";
                if (chunk_index < abs_dividend.value.size()) {
                    chunk.value.append(1, abs_dividend.value[chunk_index]);
                    chunk_index++;
                } else
                    break;
            }
            if (chunk == abs_divisor) {
                quotient.value += "1";
                chunk_remainder = 0;
            } else if (chunk > abs_divisor) {
                strip_leading_zeroes(chunk.value);
                std::tie(chunk_quotient, chunk_remainder) = divide(chunk, abs_divisor);
                quotient.value += chunk_quotient.value;
            }
        }
    }
    strip_leading_zeroes(quotient.value);

    if (this->sign == num.sign)
        quotient.sign = '+';
    else
        quotient.sign = '-';

    return quotient;
}


MPInt MPInt::operator/(const std::string &num) const {
    return *this / MPInt(num);
}


MPInt MPInt::operator/(const long long &num) const {
    return *this / MPInt(num);
}


MPInt operator/(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) / rhs;
}


MPInt operator/(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) / rhs;
}


MPInt MPInt::operator%(const MPInt &num) const {
    MPInt abs_dividend = abs(*this);
    MPInt abs_divisor = abs(num);

    if (abs_divisor == 0)
        throw std::logic_error("Attempted division by zero");
    if (abs_divisor == 1 or abs_divisor == abs_dividend)
        return MPInt(MPInt(0));

    MPInt remainder;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        remainder = std::stoll(abs_dividend.value) % std::stoll(abs_divisor.value);
    else if (abs_dividend < abs_divisor)
        remainder = abs_dividend;
    else if (is_power_of_10(num.value)) { // if num is a power of 10 use optimised calculation
        size_t no_of_zeroes = num.value.size() - 1;
        remainder.value = abs_dividend.value.substr(abs_dividend.value.size() - no_of_zeroes);
    } else {
        MPInt quotient = abs_dividend / abs_divisor;
        remainder = abs_dividend - quotient * abs_divisor;
    }
    strip_leading_zeroes(remainder.value);

    // remainder has the same sign as that of the dividend
    remainder.sign = this->sign;
    if (remainder.value == "0")     // except if its zero
        remainder.sign = '+';

    return remainder;
}


MPInt MPInt::operator%(const std::string &num) const {
    return *this % MPInt(num);
}


MPInt MPInt::operator%(const long long &num) const {
    return *this % MPInt(num);
}


MPInt operator%(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) % rhs;
}


MPInt operator%(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) % rhs;
}

#endif //CPP_SP2_ARITHEMETIC_H
