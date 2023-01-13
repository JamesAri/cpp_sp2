#ifndef CPP_SP2_MATH_H
#define CPP_SP2_MATH_H

#include "base/MPIntBase.h"

MPIntBase abs(const MPIntBase &num) {
    return num < 0 ? -num : num;
}

#endif //CPP_SP2_MATH_H
