#ifndef CPP_SP2_RELATIONAL_H
#define CPP_SP2_RELATIONAL_H

#include "MPInt.h"
#include "operators/unary.h"
 
template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator<(const MPInt<U> &num) const {
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


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator>(const MPInt<U> &num) const {
    return !((*this < num) or (*this == num));
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator==(const MPInt<U> &num) const {
    return (sign == num.sign) and (value == num.value);
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator!=(const MPInt<U> &num) const {
    return !(*this == num);
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator>=(const MPInt<U> &num) const {
    return !(*this < num);
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
bool MPInt<T>::operator<=(const MPInt<U> &num) const {
    return (*this < num) or (*this == num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator<(const std::string &num) const {
    return *this < MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator<(const long long &num) const {
    return *this < MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator<(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) < rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator<(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) < rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator>(const std::string &num) const {
    return *this > MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator>(const long long &num) const {
    return *this > MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator>(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) > rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator>(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) > rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator==(const std::string &num) const {
    return *this == MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator==(const long long &num) const {
    return *this == MPInt<T>(num);
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator==(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) == rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator==(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) == rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator!=(const std::string &num) const {
    return !(*this == MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator!=(const long long &num) const {
    return !(*this == MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator!=(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) != rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator!=(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) != rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator<=(const std::string &num) const {
    return !(*this > MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator<=(const long long &num) const {
    return !(*this > MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator<=(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) <= rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator<=(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) <= rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator>=(const std::string &num) const {
    return !(*this < MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool MPInt<T>::operator>=(const long long &num) const {
    return !(*this < MPInt<T>(num));
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator>=(const std::string &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) >= rhs;
}


template<size_t T> requires AtLeastFourBytes<T>
bool operator>=(const long long &lhs, const MPInt<T> &rhs) {
    return MPInt<T>(lhs) >= rhs;
}

#endif //CPP_SP2_RELATIONAL_H
