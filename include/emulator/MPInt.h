#ifndef CPP_SP2_MPINT_H
#define CPP_SP2_MPINT_H

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
class MPInt : public MPIntBase {
private:
    template<size_t U> requires AtLeastFourBytes<U>
    friend
    class MPIntWrapper;

    void overflowCheck();

    /** The count of available numbers */
    MPIntBase RANGE = MPIntBase(pow(2, 8 * T));
    /** Upper limit, this range includes zero, thus the additional minus one */
    MPIntBase MAX_SIZE = MPIntBase(pow(2, 8 * T - 1) - 1);
    /** Lower limit */
    MPIntBase MIN_SIZE = -MPIntBase(pow(2, 8 * T - 1));
public:
    using MPIntBase::MPIntBase;

    void printDebugInfo();

//    MPIntWrapper(): MPIntBase(){};

    /* Note:
     * Ze zadani: Výsledná přesnost (výše uvednená "maximální velikost") bude volena jako největší ze vstupních...
     * zde jsem si nebyl jisty zda vracet maximum, ci nechat puvodni velikost, jak je tomu obvykle zvykem.
     * Zde jsem zvolil to druhe.
     * Checks for overflow: if U's value is larger than T's maximum, exception is thrown. */
    template<size_t U>
    requires AtLeastFourBytes<U>
    explicit MPInt(const MPInt<U> &num) {
        value = num.value;
        sign = num.sign;
        overflowCheck();
    };

    explicit MPInt(const MPIntBase &num) : MPIntBase(num) { overflowCheck(); };

    explicit MPInt(const long long &num) : MPIntBase(num) { overflowCheck(); };

    explicit MPInt(const std::string &num) : MPIntBase(num) { overflowCheck(); };

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator=(const MPInt<U> &num) {
        *this = MPInt<T>(num);
        return *this;
    };

    MPInt<T> &operator=(const MPIntBase &num) {
        *this = MPInt<T>(num);
        return *this;
    };

    MPInt<T> &operator=(const long long &num) {
        *this = MPInt<T>(num);
        return *this;
    };

    MPInt<T> &operator=(const std::string &num) {
        *this = MPInt<T>(num);
        return *this;
    }

    MPInt<T> operator+() const {
        return MPInt<T>(MPIntBase::operator+());
    };

    MPInt<T> operator-() const {
        return MPInt<T>(MPIntBase::operator-());
    };

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator+(const MPInt<U> &num) const {
        return MPInt<std::max(T, U)>(MPIntBase::operator+(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator-(const MPInt<U> &num) const {
        return MPInt<std::max(T, U)>(MPIntBase::operator-(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator*(const MPInt<U> &num) const {
        return MPInt<std::max(T, U)>(MPIntBase::operator*(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator/(const MPInt<U> &num) const {
        return MPInt<std::max(T, U)>(MPIntBase::operator/(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator%(const MPInt<U> &num) const {
        return MPInt<std::max(T, U)>(MPIntBase::operator%(num));
    }

    MPInt<T> operator+(const std::string &num) const {
        return MPInt<T>(MPIntBase::operator+(num));
    };

    MPInt<T> operator-(const std::string &num) const {
        return MPInt<T>(MPIntBase::operator-(num));
    }

    MPInt<T> operator*(const std::string &num) const {
        return MPInt<T>(MPIntBase::operator*(num));
    }

    MPInt<T> operator/(const std::string &num) const {
        return MPInt<T>(MPIntBase::operator/(num));
    }

    MPInt<T> operator%(const std::string &num) const {
        return MPInt<T>(MPIntBase::operator%(num));
    }

    MPInt<T> operator+(const long long &num) const {
        return MPInt<T>(MPIntBase::operator+(num));
    };

    MPInt<T> operator-(const long long &num) const {
        return MPInt<T>(MPIntBase::operator-(num));
    }

    MPInt<T> operator*(const long long &num) const {
        return MPInt<T>(MPIntBase::operator*(num));
    }

    MPInt<T> operator/(const long long &num) const {
        return MPInt<T>(MPIntBase::operator/(num));
    }

    MPInt<T> operator%(const long long &num) const {
        return MPInt<T>(MPIntBase::operator%(num));
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator+=(const MPInt<U> &num) {
        this = MPIntBase::operator+=(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator-=(const MPInt<U> &num) {
        *this = MPIntBase::operator-(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator*=(const MPInt<U> &num) {
        *this = MPIntBase::operator*(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator/=(const MPInt<U> &num) {
        *this = MPIntBase::operator/(num);
        return *this;
    }

    template<size_t U>
    requires AtLeastFourBytes<U>
    MPInt<T> &operator%=(const MPInt<U> &num) {
        *this = MPIntBase::operator%(num);
        return *this;
    }

    MPInt<T> &operator+=(const std::string &num) {
        this = MPIntBase::operator+=(num);
        return *this;
    }


    MPInt<T> &operator-=(const std::string &num) {
        *this = MPIntBase::operator-(num);
        return *this;
    }

    MPInt<T> &operator*=(const std::string &num) {
        *this = MPIntBase::operator*(num);
        return *this;
    }

    MPInt<T> &operator/=(const std::string &num) {
        *this = MPIntBase::operator/(num);
        return *this;
    }

    MPInt<T> &operator%=(const std::string &num) {
        *this = MPIntBase::operator%(num);
        return *this;
    }

    MPInt<T> &operator+=(const long long &num) {
        *this = MPIntBase::operator+=(num);
        return *this;
    }

    MPInt<T> &operator-=(const long long &num) {
        *this = MPIntBase::operator-(num);
        return *this;
    }

    MPInt<T> &operator*=(const long long &num) {
        *this = MPIntBase::operator*(num);
        return *this;
    }

    MPInt<T> &operator/=(const long long &num) {
        *this = MPIntBase::operator/(num);
        return *this;
    }

    MPInt<T> &operator%=(const long long &num) {
        *this = MPIntBase::operator%(num);
        return *this;
    }

    friend std::istream& operator>>(std::istream& in, MPInt<T>& num) {
        std::string input;
        in >> input;
        num = MPIntBase(input);
        return in;
    };
};

template<size_t T>
requires AtLeastFourBytes<T>
void MPInt<T>::printDebugInfo() {
    std::stringstream ss;
    ss << "MPInt<" << T << ">:\n"
       << " value=" << *this << "\n"
       << " range=" << RANGE << "\n"
       << " max_size=" << MAX_SIZE << "\n"
       << " min_size=" << MIN_SIZE << "\n";
    std::cout << ss.rdbuf() << std::endl;
}

template<size_t T>
requires AtLeastFourBytes<T>
void MPInt<T>::overflowCheck() {
    if (T == UNLIMITED) return;
    bool error = true;
    if (this->value >= RANGE) {
        MPIntBase::operator%=(RANGE);
    } else if (this->value > MAX_SIZE) {
        MPIntBase::operator-=(RANGE);
    } else if (this->value < MIN_SIZE) {
        MPIntBase::operator+=(RANGE);
    } else {
        error = false;
    }
    if (error)
        throw OverflowException("\nMPInt<" + std::to_string(T) + "> number overflow, value=" + this->to_string());
}


#endif //CPP_SP2_MPINT_H
