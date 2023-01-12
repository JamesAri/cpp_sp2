#ifndef CPP_SP2_MATH_H
#define CPP_SP2_MATH_H

#include "MPInt.h"

MPInt abs(const MPInt &num) {
    return num < 0 ? -num : num;
}

#endif //CPP_SP2_MATH_H
