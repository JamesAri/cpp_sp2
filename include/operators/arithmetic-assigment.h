#ifndef CPP_SP2_ARITHMETIC_ASSIGMENT_H
#define CPP_SP2_ARITHMETIC_ASSIGMENT_H

#include "MPInt.h"

template <typename T>
MPInt<T>& MPInt<T>::operator+=(const MPInt<T>& num) {
    *this = *this + num;

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator-=(const MPInt<T>& num) {
    *this = *this - num;

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator*=(const MPInt<T>& num) {
    *this = *this * num;

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator/=(const MPInt<T>& num) {
    *this = *this / num;

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator+=(const long long& num) {
    *this = *this + MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator-=(const long long& num) {
    *this = *this - MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator*=(const long long& num) {
    *this = *this * MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator/=(const long long& num) {
    *this = *this / MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator+=(const std::string& num) {
    *this = *this + MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator-=(const std::string& num) {
    *this = *this - MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator*=(const std::string& num) {
    *this = *this * MPInt<T>(num);

    return *this;
}

template <typename T>
MPInt<T>& MPInt<T>::operator/=(const std::string& num) {
    *this = *this / MPInt<T>(num);

    return *this;
}

#endif //CPP_SP2_ARITHMETIC_ASSIGMENT_H
