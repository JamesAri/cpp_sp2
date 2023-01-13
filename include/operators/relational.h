#ifndef CPP_SP2_RELATIONAL_H
#define CPP_SP2_RELATIONAL_H

#include "core/MPIntBase.h"
#include "operators/unary.h"
 


bool MPIntBase::operator<(const MPIntBase &num) const {
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




bool MPIntBase::operator>(const MPIntBase &num) const {
    return !((*this < num) or (*this == num));
}




bool MPIntBase::operator==(const MPIntBase &num) const {
    return (sign == num.sign) and (value == num.value);
}




bool MPIntBase::operator!=(const MPIntBase &num) const {
    return !(*this == num);
}




bool MPIntBase::operator>=(const MPIntBase &num) const {
    return !(*this < num);
}




bool MPIntBase::operator<=(const MPIntBase &num) const {
    return (*this < num) or (*this == num);
}



bool MPIntBase::operator<(const std::string &num) const {
    return *this < MPIntBase(num);
}



bool MPIntBase::operator<(const long long &num) const {
    return *this < MPIntBase(num);
}



bool operator<(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) < rhs;
}



bool operator<(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) < rhs;
}



bool MPIntBase::operator>(const std::string &num) const {
    return *this > MPIntBase(num);
}



bool MPIntBase::operator>(const long long &num) const {
    return *this > MPIntBase(num);
}



bool operator>(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) > rhs;
}



bool operator>(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) > rhs;
}



bool MPIntBase::operator==(const std::string &num) const {
    return *this == MPIntBase(num);
}



bool MPIntBase::operator==(const long long &num) const {
    return *this == MPIntBase(num);
}



bool operator==(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) == rhs;
}



bool operator==(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) == rhs;
}



bool MPIntBase::operator!=(const std::string &num) const {
    return !(*this == MPIntBase(num));
}



bool MPIntBase::operator!=(const long long &num) const {
    return !(*this == MPIntBase(num));
}



bool operator!=(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) != rhs;
}



bool operator!=(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) != rhs;
}



bool MPIntBase::operator<=(const std::string &num) const {
    return !(*this > MPIntBase(num));
}



bool MPIntBase::operator<=(const long long &num) const {
    return !(*this > MPIntBase(num));
}



bool operator<=(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) <= rhs;
}



bool operator<=(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) <= rhs;
}



bool MPIntBase::operator>=(const std::string &num) const {
    return !(*this < MPIntBase(num));
}



bool MPIntBase::operator>=(const long long &num) const {
    return !(*this < MPIntBase(num));
}


bool operator>=(const std::string &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) >= rhs;
}



bool operator>=(const long long &lhs, const MPIntBase &rhs) {
    return MPIntBase(lhs) >= rhs;
}

#endif //CPP_SP2_RELATIONAL_H
