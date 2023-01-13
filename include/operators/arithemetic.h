#ifndef CPP_SP2_ARITHEMETIC_H
#define CPP_SP2_ARITHEMETIC_H

#include "core/MPIntBase.h"
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
MPIntBase MPIntBase::operator+(const MPIntBase &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) + (-num) = (+this) - (+num)
        MPIntBase tmp = num;
        tmp.sign = '+';
        return MPIntBase(*this - tmp);
    } else if (this->sign == '-' and num.sign == '+') { // (-this) + (+num) = -( (+this) - (+num) )
        MPIntBase tmp = *this;
        tmp.sign = '+';
        return MPIntBase(-(tmp - num));
    }

    auto [larger, smaller] = getLargerAndSmaller(this->value, num.value);

    MPIntBase result;
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


MPIntBase MPIntBase::operator+(const std::string &num) const {
    return *this + MPIntBase(num);
}


MPIntBase MPIntBase::operator+(const long long &num) const {
    return *this + MPIntBase(num);
}


MPIntBase operator+(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) + rhs;
}


MPIntBase operator+(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) + rhs;
}


/*
 * Algorithmic Time Complexity : O(n)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPIntBase MPIntBase::operator-(const MPIntBase &num) const {
    if (this->sign == '+' and num.sign == '-') { // (+this) - (-num) = (+this) + (+num)
        MPIntBase tmp = num;
        tmp.sign = '+';
        return MPIntBase(*this + tmp);
    } else if (this->sign == '-' and num.sign == '+') { // (-this) - (+num) = -( (+this) + (+num) )
        MPIntBase tmp = *this;
        tmp.sign = '+';
        return MPIntBase(-(tmp + num));
    }

    MPIntBase result;
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
    prependZeroes(smaller, larger.size() - smaller.size());

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
    removeLeadingZeroes(result.value);

    if (result.value == "0")
        result.sign = '+';

    return result;
}


MPIntBase MPIntBase::operator-(const std::string &num) const {
    return *this - MPIntBase(num);
}


MPIntBase MPIntBase::operator-(const long long &num) const {
    return *this - MPIntBase(num);
}


MPIntBase operator-(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) - rhs;
}


MPIntBase operator-(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) - rhs;
}


/*
 * Using Karatsuba algorithm for fast multiplication.
 * https://en.wikipedia.org/wiki/Karatsuba_algorithm
 *
 * Algorithmic Time Complexity : O(n^log3)
 * Algorithmic Space Complexity : O(n)
 * where n is the larger length of respective strings(Integers) provided.
 */
MPIntBase MPIntBase::operator*(const MPIntBase &num) const {
    if (*this == 0 or num == 0)
        return MPIntBase(0);
    if (*this == 1)
        return num;
    if (num == 1)
        return *this;

    MPIntBase product;
    if (abs(*this) <= FLOOR_SQRT_LLONG_MAX and abs(num) <= FLOOR_SQRT_LLONG_MAX)
        product = std::stoll(this->value) * std::stoll(num.value);
    else {
        auto [larger, smaller] = getLargerAndSmaller(this->value, num.value);

        // Split the numbers in half
        size_t halfLength = larger.size() / 2;
        auto halfLengthCeil = (size_t) ceil(static_cast<double>(larger.size()) / 2.0);

        MPIntBase num1High, num1Low, num2High, num2Low;
        num1High = larger.substr(0, halfLength);
        num1Low = larger.substr(halfLength);
        num2High = smaller.substr(0, halfLength);
        num2Low = smaller.substr(halfLength);

        removeLeadingZeroes(num1High.value);
        removeLeadingZeroes(num1Low.value);
        removeLeadingZeroes(num2High.value);
        removeLeadingZeroes(num2Low.value);

        // Recursively compute high-, low- and mid-products
        MPIntBase prodHigh, prodMid, prodLow;
        prodHigh = num1High * num2High;
        prodLow = num1Low * num2Low;
        prodMid = (num1High + num1Low) * (num2High + num2Low) - prodHigh - prodLow;

        appendZeroes(prodHigh.value, 2 * halfLengthCeil);
        appendZeroes(prodMid.value, halfLengthCeil);

        removeLeadingZeroes(prodHigh.value);
        removeLeadingZeroes(prodMid.value);
        removeLeadingZeroes(prodLow.value);

        product = prodHigh + prodMid + prodLow;
    }
    removeLeadingZeroes(product.value);

    if (this->sign == num.sign)
        product.sign = '+';
    else
        product.sign = '-';

    return product;
}


MPIntBase MPIntBase::operator*(const std::string &num) const {
    return *this * MPIntBase(num);
}


MPIntBase MPIntBase::operator*(const long long &num) const {
    return *this * MPIntBase(num);
}


MPIntBase operator*(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) * rhs;
}


MPIntBase operator*(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) * rhs;
}


std::tuple<MPIntBase, MPIntBase> divide(const MPIntBase &dividend, const MPIntBase &divisor) {
    MPIntBase quotient, remainder, temp;

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
MPIntBase MPIntBase::operator/(const MPIntBase &num) const {
    MPIntBase absDividend = abs(*this);
    MPIntBase absDivisor = abs(num);

    if (num == 0)
        throw std::logic_error("Attempted division by zero");
    if (absDividend < absDivisor)
        return 0;
    if (num == 1)
        return *this;
    if (num == -1)
        return -(*this);

    MPIntBase quotient;
    if (absDividend <= LLONG_MAX and absDivisor <= LLONG_MAX)
        quotient = std::stoll(absDividend.value) / std::stoll(absDivisor.value);
    else if (absDividend == absDivisor)
        quotient = 1;
    else {
        quotient.value = "";    // the value is cleared as digits will be appended
        MPIntBase chunk, chunkQuotient, chunkRemainder;
        size_t chunkIndex = 0;
        chunkRemainder.value = absDividend.value.substr(chunkIndex, absDivisor.value.size() - 1);
        chunkIndex = absDivisor.value.size() - 1;
        while (chunkIndex < absDividend.value.size()) {
            chunk.value = chunkRemainder.value.append(1, absDividend.value[chunkIndex]);
            chunkIndex++;
            while (chunk < absDivisor) {
                quotient.value += "0";
                if (chunkIndex < absDividend.value.size()) {
                    chunk.value.append(1, absDividend.value[chunkIndex]);
                    chunkIndex++;
                } else
                    break;
            }
            if (chunk == absDivisor) {
                quotient.value += "1";
                chunkRemainder = 0;
            } else if (chunk > absDivisor) {
                removeLeadingZeroes(chunk.value);
                std::tie(chunkQuotient, chunkRemainder) = divide(chunk, absDivisor);
                quotient.value += chunkQuotient.value;
            }
        }
    }
    removeLeadingZeroes(quotient.value);

    if (this->sign == num.sign)
        quotient.sign = '+';
    else
        quotient.sign = '-';

    return quotient;
}


MPIntBase MPIntBase::operator/(const std::string &num) const {
    return *this / MPIntBase(num);
}


MPIntBase MPIntBase::operator/(const long long &num) const {
    return *this / MPIntBase(num);
}


MPIntBase operator/(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) / rhs;
}


MPIntBase operator/(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) / rhs;
}


MPIntBase MPIntBase::operator%(const MPIntBase &num) const {
    MPIntBase absDividend = abs(*this);
    MPIntBase absDivisor = abs(num);

    if (absDivisor == 0)
        throw std::logic_error("Attempted division by zero");
    if (absDivisor == 1 or absDivisor == absDividend)
        return MPIntBase(MPIntBase(0));

    MPIntBase remainder;
    if (absDividend <= LLONG_MAX and absDivisor <= LLONG_MAX)
        remainder = std::stoll(absDividend.value) % std::stoll(absDivisor.value);
    else if (absDividend < absDivisor)
        remainder = absDividend;
    else {
        MPIntBase quotient = absDividend / absDivisor;
        remainder = absDividend - quotient * absDivisor;
    }
    removeLeadingZeroes(remainder.value);

    // remainder has the same sign as that of the dividend
    remainder.sign = this->sign;
    if (remainder.value == "0")     // except if its zero
        remainder.sign = '+';

    return remainder;
}


MPIntBase MPIntBase::operator%(const std::string &num) const {
    return *this % MPIntBase(num);
}


MPIntBase MPIntBase::operator%(const long long &num) const {
    return *this % MPIntBase(num);
}


MPIntBase operator%(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) % rhs;
}


MPIntBase operator%(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) % rhs;
}

#endif //CPP_SP2_ARITHEMETIC_H
