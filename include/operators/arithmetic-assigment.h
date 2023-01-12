#ifndef CPP_SP2_ARITHMETIC_ASSIGMENT_H
#define CPP_SP2_ARITHMETIC_ASSIGMENT_H

#include "MPIntBase.h"



MPIntBase &MPIntBase::operator+=(const MPIntBase &num) {
    *this = *this + num;
    return *this;
}




MPIntBase &MPIntBase::operator-=(const MPIntBase &num) {
    *this = *this - num;
    return *this;
}




MPIntBase &MPIntBase::operator*=(const MPIntBase &num) {
    *this = *this * num;
    return *this;
}




MPIntBase &MPIntBase::operator/=(const MPIntBase &num) {
    *this = *this / num;
    return *this;
}




MPIntBase &MPIntBase::operator%=(const MPIntBase &num) {
    *this = *this % num;
    return *this;
}



MPIntBase &MPIntBase::operator+=(const std::string &num) {
    *this = *this + MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator-=(const std::string &num) {
    *this = *this - MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator*=(const std::string &num) {
    *this = *this * MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator/=(const std::string &num) {
    *this = *this / MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator%=(const std::string &num) {
    *this = *this % MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator+=(const long long &num) {
    *this = *this + MPIntBase(num);
    return *this;
}


MPIntBase &MPIntBase::operator-=(const long long &num) {
    *this = *this - MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator*=(const long long &num) {
    *this = *this * MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator/=(const long long &num) {
    *this = *this / MPIntBase(num);
    return *this;
}



MPIntBase &MPIntBase::operator%=(const long long &num) {
    *this = *this % MPIntBase(num);
    return *this;
}

#endif //CPP_SP2_ARITHMETIC_ASSIGMENT_H
