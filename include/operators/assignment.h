#ifndef CPP_SP2_ASSIGNMENT_H
#define CPP_SP2_ASSIGNMENT_H

#include "core/MPIntBase.h"



MPIntBase &MPIntBase::operator=(const MPIntBase &num) {
    value = num.value;
    sign = num.sign;

    return *this;
}


MPIntBase &MPIntBase::operator=(const long long &num) {
    MPIntBase temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}


MPIntBase &MPIntBase::operator=(const std::string &num) {
    MPIntBase temp(num);
    value = temp.value;
    sign = temp.sign;

    return *this;
}

#endif //CPP_SP2_ASSIGNMENT_H
