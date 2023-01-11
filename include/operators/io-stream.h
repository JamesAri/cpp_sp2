#ifndef CPP_SP2_IO_STREAM_H
#define CPP_SP2_IO_STREAM_H

#include "MPInt.h"


std::istream& operator>>(std::istream& in, MPInt& num) {
    std::string input;
    in >> input;
    num = MPInt(input);

    return in;
}


std::ostream& operator<<(std::ostream& out, const MPInt& num) {
    if (num.sign == '-')
        out << num.sign;
    out << num.value;

    return out;
}
#endif //CPP_SP2_IO_STREAM_H
