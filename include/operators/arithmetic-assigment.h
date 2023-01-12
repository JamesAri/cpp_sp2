#ifndef CPP_SP2_ARITHMETIC_ASSIGMENT_H
#define CPP_SP2_ARITHMETIC_ASSIGMENT_H

#include "MPInt.h"



MPInt &MPInt::operator+=(const MPInt &num) {
    *this = *this + num;
    return *this;
}




MPInt &MPInt::operator-=(const MPInt &num) {
    *this = *this - num;
    return *this;
}




MPInt &MPInt::operator*=(const MPInt &num) {
    *this = *this * num;
    return *this;
}




MPInt &MPInt::operator/=(const MPInt &num) {
    *this = *this / num;
    return *this;
}




MPInt &MPInt::operator%=(const MPInt &num) {
    *this = *this % num;
    return *this;
}



MPInt &MPInt::operator+=(const std::string &num) {
    *this = *this + MPInt(num);
    return *this;
}



MPInt &MPInt::operator-=(const std::string &num) {
    *this = *this - MPInt(num);
    return *this;
}



MPInt &MPInt::operator*=(const std::string &num) {
    *this = *this * MPInt(num);
    return *this;
}



MPInt &MPInt::operator/=(const std::string &num) {
    *this = *this / MPInt(num);
    return *this;
}



MPInt &MPInt::operator%=(const std::string &num) {
    *this = *this % MPInt(num);
    return *this;
}



MPInt &MPInt::operator+=(const long long &num) {
    *this = *this + MPInt(num);
    return *this;
}


MPInt &MPInt::operator-=(const long long &num) {
    *this = *this - MPInt(num);
    return *this;
}



MPInt &MPInt::operator*=(const long long &num) {
    *this = *this * MPInt(num);
    return *this;
}



MPInt &MPInt::operator/=(const long long &num) {
    *this = *this / MPInt(num);
    return *this;
}



MPInt &MPInt::operator%=(const long long &num) {
    *this = *this % MPInt(num);
    return *this;
}

#endif //CPP_SP2_ARITHMETIC_ASSIGMENT_H
