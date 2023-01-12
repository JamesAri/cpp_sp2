#ifndef CPP_SP2_MATH_H
#define CPP_SP2_MATH_H

#include "MPInt.h"

template<size_t T> requires AtLeastFourBytes<T>
MPInt<T> abs(const MPInt<T> &num) {
    return num < 0 ? -num : num;
}

#endif //CPP_SP2_MATH_H
