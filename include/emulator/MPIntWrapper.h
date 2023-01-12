#ifndef CPP_SP2_MPINTWRAPPER_H
#define CPP_SP2_MPINTWRAPPER_H

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "core.h"
#include "util.h"

/** Used with MPInt for 'unlimited' precision */
constexpr size_t UNLIMITED = 0;


template<size_t S>
concept AtLeastFourBytes = (S >= 4) || (S == UNLIMITED);


template<size_t T> requires AtLeastFourBytes<T>
class MPIntWrapper : public MPInt {
private:
    template<size_t U> requires AtLeastFourBytes<U>
    friend
    class MPIntWrapper;

    void overflowCheck();

    /** The count of available numbers */
    MPInt RANGE = MPInt(pow(2, 8 * T));
    /** Upper limit, this range includes zero, thus the additional minus one */
    MPInt MAX_SIZE = MPInt(pow(2, 8 * T - 1) - 1);
    /** Lower limit */
    MPInt MIN_SIZE = -MPInt(pow(2, 8 * T - 1));
public:
    using MPInt::MPInt;

    void printDebugInfo();

    /* Note:
     * Ze zadani: Výsledná přesnost (výše uvednená "maximální velikost") bude volena jako největší ze vstupních...
     * zde jsem si nebyl jisty zda vracet maximum, ci nechat puvodni velikost, jak je tomu obvykle zvykem.
     * Zde jsem zvolil to druhe.
     * Checks for overflow: if U's value is larger than T's maximum, exception is thrown. */
    template<size_t U>
    requires AtLeastFourBytes<U>
    explicit MPIntWrapper(const MPIntWrapper<U> &num) {
        value = num.value;
        sign = num.sign;
        overflowCheck();
    };

    explicit MPIntWrapper(const MPInt &num) : MPInt(num) { overflowCheck(); };

    explicit MPIntWrapper(const long long &num) : MPInt(num) { overflowCheck(); };

    explicit MPIntWrapper(const std::string &num) : MPInt(num) { overflowCheck(); };

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator=(const MPIntWrapper<U> &num) {
        *this = MPIntWrapper<T>(num);
        return *this;
    };

    MPIntWrapper<T> &operator=(const MPInt &num) {
        *this = MPIntWrapper<T>(num);
        return *this;
    };

    MPIntWrapper<T> &operator=(const long long &num) {
        *this = MPIntWrapper<T>(num);
        return *this;
    };

    MPIntWrapper<T> &operator=(const std::string &num) {
        *this = MPIntWrapper<T>(num);
        return *this;
    }

    MPIntWrapper<T> operator+() const {
        return MPIntWrapper<T>(MPInt::operator+());
    };

    MPIntWrapper<T> operator-() const {
        return MPIntWrapper<T>(MPInt::operator-());
    };

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<std::max(T, U)> operator+(const MPIntWrapper<U> &num) const {
        return MPIntWrapper<std::max(T, U)>(MPInt::operator+(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<std::max(T, U)> operator-(const MPIntWrapper<U> &num) const {
        return MPIntWrapper<std::max(T, U)>(MPInt::operator-(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<std::max(T, U)> operator*(const MPIntWrapper<U> &num) const {
        return MPIntWrapper<std::max(T, U)>(MPInt::operator*(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<std::max(T, U)> operator/(const MPIntWrapper<U> &num) const {
        return MPIntWrapper<std::max(T, U)>(MPInt::operator/(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<std::max(T, U)> operator%(const MPIntWrapper<U> &num) const {
        return MPIntWrapper<std::max(T, U)>(MPInt::operator%(num));
    }

    MPIntWrapper<T> operator+(const std::string &num) const {
        return MPIntWrapper<T>(MPInt::operator+(num));
    };

    MPIntWrapper<T> operator-(const std::string &num) const {
        return MPIntWrapper<T>(MPInt::operator-(num));
    }

    MPIntWrapper<T> operator*(const std::string &num) const {
        return MPIntWrapper<T>(MPInt::operator*(num));
    }

    MPIntWrapper<T> operator/(const std::string &num) const {
        return MPIntWrapper<T>(MPInt::operator/(num));
    }

    MPIntWrapper<T> operator%(const std::string &num) const {
        return MPIntWrapper<T>(MPInt::operator%(num));
    }

    MPIntWrapper<T> operator+(const long long &num) const {
        return MPIntWrapper<T>(MPInt::operator+(num));
    };

    MPIntWrapper<T> operator-(const long long &num) const {
        return MPIntWrapper<T>(MPInt::operator-(num));
    }

    MPIntWrapper<T> operator*(const long long &num) const {
        return MPIntWrapper<T>(MPInt::operator*(num));
    }

    MPIntWrapper<T> operator/(const long long &num) const {
        return MPIntWrapper<T>(MPInt::operator/(num));
    }

    MPIntWrapper<T> operator%(const long long &num) const {
        return MPIntWrapper<T>(MPInt::operator%(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator+=(const MPIntWrapper<U> &num) {
        this = MPInt::operator+=(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator-=(const MPIntWrapper<U> &num) {
        *this = MPInt::operator-(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator*=(const MPIntWrapper<U> &num) {
        *this = MPInt::operator*(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator/=(const MPIntWrapper<U> &num) {
        *this = MPInt::operator/(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPIntWrapper<T> &operator%=(const MPIntWrapper<U> &num) {
        *this = MPInt::operator%(num);
        return *this;
    }

    MPIntWrapper<T> &operator+=(const std::string &num) {
        this = MPInt::operator+=(num);
        return *this;
    }


    MPIntWrapper<T> &operator-=(const std::string &num) {
        *this = MPInt::operator-(num);
        return *this;
    }

    MPIntWrapper<T> &operator*=(const std::string &num) {
        *this = MPInt::operator*(num);
        return *this;
    }

    MPIntWrapper<T> &operator/=(const std::string &num) {
        *this = MPInt::operator/(num);
        return *this;
    }

    MPIntWrapper<T> &operator%=(const std::string &num) {
        *this = MPInt::operator%(num);
        return *this;
    }

    MPIntWrapper<T> &operator+=(const long long &num) {
        *this = MPInt::operator+=(num);
        return *this;
    }

    MPIntWrapper<T> &operator-=(const long long &num) {
        *this = MPInt::operator-(num);
        return *this;
    }

    MPIntWrapper<T> &operator*=(const long long &num) {
        *this = MPInt::operator*(num);
        return *this;
    }

    MPIntWrapper<T> &operator/=(const long long &num) {
        *this = MPInt::operator/(num);
        return *this;
    }

    MPIntWrapper<T> &operator%=(const long long &num) {
        *this = MPInt::operator%(num);
        return *this;
    }
};

template<size_t T>
requires AtLeastFourBytes<T>
void MPIntWrapper<T>::printDebugInfo() {
    std::ostringstream ss;
    ss << "value=" << this << "\n"
       << "range=" << RANGE << "\n"
       << "max_size=" << MAX_SIZE << "\n"
       << "min_size=" << MIN_SIZE << "\n";
    std::cout << ss.rdbuf();
}

template<size_t T>
requires AtLeastFourBytes<T>
void MPIntWrapper<T>::overflowCheck() {
    if (T == UNLIMITED) return;
    bool error = true;
    if (this->value >= RANGE) {
        MPInt::operator%=(RANGE);
    } else if (this->value > MAX_SIZE) {
        MPInt::operator-=(RANGE);
    } else if (this->value < MIN_SIZE) {
        MPInt::operator+=(RANGE);
    } else {
        error = false;
    }
    if (error)
        throw OverflowException("\nMPInt<" + std::to_string(T) + "> number overflow, value=" + this->to_string());
}


#endif //CPP_SP2_MPINTWRAPPER_H
