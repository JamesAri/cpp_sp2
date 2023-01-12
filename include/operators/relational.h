#ifndef CPP_SP2_RELATIONAL_H
#define CPP_SP2_RELATIONAL_H

#include "MPInt.h"
#include "operators/unary.h"
 


bool MPInt::operator<(const MPInt &num) const {
    if (sign == num.sign) {
        if (sign == '+') {
            if (value.length() == num.value.length())
                return value < num.value;
            else
                return value.length() < num.value.length();
        } else
            return -(*this) > -num;
    } else
        return sign == '-';
}




bool MPInt::operator>(const MPInt &num) const {
    return !((*this < num) or (*this == num));
}




bool MPInt::operator==(const MPInt &num) const {
    return (sign == num.sign) and (value == num.value);
}




bool MPInt::operator!=(const MPInt &num) const {
    return !(*this == num);
}




bool MPInt::operator>=(const MPInt &num) const {
    return !(*this < num);
}




bool MPInt::operator<=(const MPInt &num) const {
    return (*this < num) or (*this == num);
}



bool MPInt::operator<(const std::string &num) const {
    return *this < MPInt(num);
}



bool MPInt::operator<(const long long &num) const {
    return *this < MPInt(num);
}



bool operator<(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) < rhs;
}



bool operator<(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) < rhs;
}



bool MPInt::operator>(const std::string &num) const {
    return *this > MPInt(num);
}



bool MPInt::operator>(const long long &num) const {
    return *this > MPInt(num);
}



bool operator>(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) > rhs;
}



bool operator>(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) > rhs;
}



bool MPInt::operator==(const std::string &num) const {
    return *this == MPInt(num);
}



bool MPInt::operator==(const long long &num) const {
    return *this == MPInt(num);
}



bool operator==(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) == rhs;
}



bool operator==(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) == rhs;
}



bool MPInt::operator!=(const std::string &num) const {
    return !(*this == MPInt(num));
}



bool MPInt::operator!=(const long long &num) const {
    return !(*this == MPInt(num));
}



bool operator!=(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) != rhs;
}



bool operator!=(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) != rhs;
}



bool MPInt::operator<=(const std::string &num) const {
    return !(*this > MPInt(num));
}



bool MPInt::operator<=(const long long &num) const {
    return !(*this > MPInt(num));
}



bool operator<=(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) <= rhs;
}



bool operator<=(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) <= rhs;
}



bool MPInt::operator>=(const std::string &num) const {
    return !(*this < MPInt(num));
}



bool MPInt::operator>=(const long long &num) const {
    return !(*this < MPInt(num));
}



bool operator>=(const std::string &lhs, const MPInt &rhs) {
    return MPInt(lhs) >= rhs;
}



bool operator>=(const long long &lhs, const MPInt &rhs) {
    return MPInt(lhs) >= rhs;
}

#endif //CPP_SP2_RELATIONAL_H
