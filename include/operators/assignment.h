#ifndef CPP_SP2_ASSIGNMENT_H
#define CPP_SP2_ASSIGNMENT_H

#include "MPInt.h"

template<size_t T> requires AtLeastFourBytes<T>
template<size_t U> requires AtLeastFourBytes<U>
MPInt<T> &MPInt<T>::operator=(const MPInt<U> &num) {
    value = num.value;
    sign = num.sign;

    return *this;
}

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator=(const long long &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> &MPInt<T>::operator=(const std::string &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

#endif //CPP_SP2_ASSIGNMENT_H
