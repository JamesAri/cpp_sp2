#ifndef CPP_SP2_ARITHMETIC_ASSIGMENT_H
#define CPP_SP2_ARITHMETIC_ASSIGMENT_H

#include "MPInt.h"

template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator+=(const MPInt<U> &num) {
    *this = *this + num;
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator-=(const MPInt<U> &num) {
    *this = *this - num;
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator*=(const MPInt<U> &num) {
    *this = *this * num;
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator/=(const MPInt<U> &num) {
    *this = *this / num;
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator%=(const MPInt<U> &num) {
    *this = *this % num;
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator+=(const std::string &num) {
    *this = *this + MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator-=(const std::string &num) {
    *this = *this - MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator*=(const std::string &num) {
    *this = *this * MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator/=(const std::string &num) {
    *this = *this / MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator%=(const std::string &num) {
    *this = *this % MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator+=(const long long &num) {
    *this = *this + MPInt(num);
    return *this;
}

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator-=(const long long &num) {
    *this = *this - MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator*=(const long long &num) {
    *this = *this * MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator/=(const long long &num) {
    *this = *this / MPInt(num);
    return *this;
}


template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator%=(const long long &num) {
    *this = *this % MPInt(num);
    return *this;
}

#endif //CPP_SP2_ARITHMETIC_ASSIGMENT_H
