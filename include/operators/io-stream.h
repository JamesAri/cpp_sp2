#ifndef CPP_SP2_IO_STREAM_H
#define CPP_SP2_IO_STREAM_H

#include "MPIntBase.h"

std::istream &operator>>(std::istream &in, MPIntBase &num) {
    std::string input;
    in >> input;
    num = MPIntBase(input);

    return in;
}


std::ostream &operator<<(std::ostream &out, const MPIntBase &num) {
    if (num.sign == '-')
        out << num.sign;
    out << num.value;

    return out;
}

#endif //CPP_SP2_IO_STREAM_H
