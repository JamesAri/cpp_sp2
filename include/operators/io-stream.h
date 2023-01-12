#ifndef CPP_SP2_IO_STREAM_H
#define CPP_SP2_IO_STREAM_H

#include "MPInt.h"

template<size_t T> requires AtLeastFourBytes<T>
std::istream &operator>>(std::istream &in, MPInt<T> &num) {
    std::string input;
    in >> input;
    num = MPInt<T>(input);

    return in;
}


template<size_t T> requires AtLeastFourBytes<T>
std::ostream &operator<<(std::ostream &out, const MPInt<T> &num) {
    if (num.sign == '-')
        out << num.sign;
    out << num.value;

    return out;
}

#endif //CPP_SP2_IO_STREAM_H
