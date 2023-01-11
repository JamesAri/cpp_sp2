#ifndef CPP_SP2_ASSIGNMENT_H
#define CPP_SP2_ASSIGNMENT_H

#include "MPInt.h"

MPInt &MPInt::operator=(const MPInt &num) {
    value = num.value;
    sign = num.sign;

    return *this;
}


MPInt &MPInt::operator=(const long long &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}


MPInt &MPInt::operator=(const std::string &num) {
    MPInt temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

#endif //CPP_SP2_ASSIGNMENT_H
