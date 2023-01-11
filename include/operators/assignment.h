#ifndef CPP_SP2_ASSIGNMENT_H
#define CPP_SP2_ASSIGNMENT_H

#include "MPInt.h"

template<typename T>
MPInt<T> &MPInt<T>::operator=(const MPInt<T> &num) {
    value = num.value;
    sign = num.sign;

    return *this;
}

template<typename T>
MPInt<T> &MPInt<T>::operator=(const long long &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

template<typename T>
MPInt<T> &MPInt<T>::operator=(const std::string &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

#endif //CPP_SP2_ASSIGNMENT_H
