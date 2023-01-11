#ifndef CPP_SP2_ARITHEMETIC_H
#define CPP_SP2_ARITHEMETIC_H

#include <cmath>
#include "MPInt.h"

template<typename T>
MPInt<T> MPInt<T>::operator+(const MPInt<T> &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) + (-num) = (+this) - (+num)
        MPInt tmp = num;
        tmp.sign = '+';
        return *this - tmp;
    } else if (this->sign == '-' and num.sign == '+') { // (-this) + (+num) = -( (+this) - (+num) )
        MPInt<T> tmp = *this;
        tmp.sign = '+';
        return -(tmp - num);
    }

    auto [larger, smaller] = get_larger_and_smaller(this->value, num.value);

    MPInt<T> result;
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

template<typename T>
MPInt<T> MPInt<T>::operator-(const MPInt<T> &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) - (-num) = (+this) + (+num)
        MPInt<T> tmp = num;
        tmp.sign = '+';
        return *this + tmp;
    } else if (this->sign == '-' and num.sign == '+') { // (-this) - (+num) = -( (+this) + (+num) )
        MPInt<T> tmp = *this;
        tmp.sign = '+';
        return -(tmp + num);
    }

    MPInt<T> result;
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

    result.value = "";  // the value is cleared as the digits will be appended
    short difference;
    long i, j;
    // subtract the two values
    for (i = larger.size() - 1; i >= 0; i--) {
        difference = larger[i] - smaller[i];
        if (difference < 0) {
            for (j = i - 1; j >= 0; j--) {
                if (larger[j] != '0') {
                    larger[j]--;    // borrow from the j-th digit
                    break;
                }
            }
            j++;
            while (j != i) {
                larger[j] = '9';    // add the borrow and take away 1
                j++;
            }
            difference += 10;   // add the borrow
        }
        result.value = std::to_string(difference) + result.value;
    }
    strip_leading_zeroes(result.value);

    // if the result is 0, set its sign as +
    if (result.value == "0")
        result.sign = '+';

    return result;
}

template<typename T>
MPInt<T> MPInt<T>::operator*(const MPInt<T> &num) const {
    if (*this == 0 or num == 0)
        return MPInt<T>(0);
    if (*this == 1)
        return num;
    if (num == 1)
        return *this;

    MPInt<T> product;
    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX and abs(num) <= FLOOR_SQRT_LLONG_MAX)
        product = std::stoll(this->value) * std::stoll(num.value);
    else if (is_power_of_10(this->value)) { // if LHS is a power of 10 do optimised operation
        product.value = num.value;
        product.value.append(this->value.begin() + 1, this->value.end());
    } else if (is_power_of_10(num.value)) { // if RHS is a power of 10 do optimised operation
        product.value = this->value;
        product.value.append(num.value.begin() + 1, num.value.end());
    } else {
        // identify the numbers as `larger` and `smaller`
        std::string larger, smaller;
        std::tie(larger, smaller) = get_larger_and_smaller(this->value, num.value);

        size_t half_length = larger.size() / 2;
        auto half_length_ceil = (size_t) ceil(larger.size() / 2.0);

        MPInt<T> num1_high, num1_low;
        num1_high = larger.substr(0, half_length);
        num1_low = larger.substr(half_length);

        MPInt<T> num2_high, num2_low;
        num2_high = smaller.substr(0, half_length);
        num2_low = smaller.substr(half_length);

        strip_leading_zeroes(num1_high.value);
        strip_leading_zeroes(num1_low.value);
        strip_leading_zeroes(num2_high.value);
        strip_leading_zeroes(num2_low.value);

        MPInt<T> prod_high, prod_mid, prod_low;
        prod_high = num1_high * num2_high;
        prod_low = num1_low * num2_low;
        prod_mid = (num1_high + num1_low) * (num2_high + num2_low)
                   - prod_high - prod_low;

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

template<typename T>
std::tuple<MPInt<T>, MPInt<T>> divide(const MPInt<T> &dividend, const MPInt<T> &divisor) {
    MPInt<T> quotient, remainder, temp;

    temp = divisor;
    quotient = 1;
    while (temp < dividend) {
        quotient++;
        temp += divisor;
    }
    if (temp > dividend) {
        quotient--;
        remainder = dividend - (temp - divisor);
    }

    return std::make_tuple(quotient, remainder);
}

template<typename T>
MPInt<T> MPInt<T>::operator/(const MPInt<T> &num) const {
    MPInt<T> abs_dividend = abs(*this);
    MPInt<T> abs_divisor = abs(num);

    if (num == 0)
        throw std::logic_error("Attempted division by zero");
    if (abs_dividend < abs_divisor)
        return MPInt<T>(0);
    if (num == 1)
        return *this;
    if (num == -1)
        return -(*this);

    MPInt<T> quotient;
    if (abs_dividend <= LLONG_MAX and abs_divisor <= LLONG_MAX)
        quotient = std::stoll(abs_dividend.value) / std::stoll(abs_divisor.value);
    else if (abs_dividend == abs_divisor)
        quotient = 1;
    else if (is_power_of_10(abs_divisor.value)) { // if divisor is a power of 10 do optimised calculation
        size_t digits_in_quotient = abs_dividend.value.size() - abs_divisor.value.size() + 1;
        quotient.value = abs_dividend.value.substr(0, digits_in_quotient);
    } else {
        quotient.value = "";    // the value is cleared as digits will be appended
        MPInt<T> chunk, chunk_quotient, chunk_remainder;
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

template<typename T>
MPInt<T> MPInt<T>::operator+(const long long &num) const {
    return *this + MPInt<T>(num);
}

template<typename T>
MPInt<T> operator+(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) + rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator-(const long long &num) const {
    return *this - MPInt<T>(num);
}

template<typename T>
MPInt<T> operator-(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) - rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator*(const long long &num) const {
    return *this * MPInt<T>(num);
}

template<typename T>
MPInt<T> operator*(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) * rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator/(const long long &num) const {
    return *this / MPInt<T>(num);
}

template<typename T>
MPInt<T> operator/(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) / rhs;
}

template<typename T>
MPInt<T> operator%(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) % rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator+(const std::string &num) const {
    return *this + MPInt<T>(num);
}

template<typename T>
MPInt<T> operator+(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) + rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator-(const std::string &num) const {
    return *this - MPInt<T>(num);
}

template<typename T>
MPInt<T> operator-(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) - rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator*(const std::string &num) const {
    return *this * MPInt<T>(num);
}

template<typename T>
MPInt<T> operator*(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) * rhs;
}

template<typename T>
MPInt<T> MPInt<T>::operator/(const std::string &num) const {
    return *this / MPInt<T>(num);
}

template<typename T>
MPInt<T> operator/(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) / rhs;
}

#endif //CPP_SP2_ARITHEMETIC_H
