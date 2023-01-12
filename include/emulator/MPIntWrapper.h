#ifndef CPP_SP2_MPINTWRAPPER_H
#define CPP_SP2_MPINTWRAPPER_H

#include <string>
#include <iostream>
#include <cmath>
#include "core.h"
#include "util.h"

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
    /** Upper limit, this range includes zero, thus the minus one */
    MPInt MAX_SIZE = MPInt(pow(2, 8 * T - 1) - 1);
    /** Lower limit */
    MPInt MIN_SIZE = -MPInt(pow(2, 8 * T - 1));
public:
    using MPInt::MPInt;

    void workWithTemplate() {
        std::cout << RANGE << std::endl;
        std::cout << MAX_SIZE << std::endl;
        std::cout << MIN_SIZE << std::endl;
    }

//    MPInt::MPIntWrapper();
    template<size_t U> requires AtLeastFourBytes<U>
    explicit MPIntWrapper(const MPIntWrapper<U> &num): MPIntWrapper(num.value) {};
    explicit MPIntWrapper(const long long &num) : MPInt(num) { overflowCheck(); };
    explicit MPIntWrapper(const std::string &num) : MPInt(num) { overflowCheck(); };

//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator=(const MPIntWrapper<U>&);
//    MPIntWrapper& operator=(const long long&);
//    MPIntWrapper& operator=(const std::string&);

//    MPIntWrapper operator+() const;
//    MPIntWrapper operator-() const {
//        auto temp = MPInt::operator-();
//        return temp;
//    };
//
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<std::max(T, U)> operator+(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<std::max(T, U)> operator-(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<std::max(T, U)> operator*(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<std::max(T, U)> operator/(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<std::max(T, U)> operator%(const MPIntWrapper<U>&) const;
//    MPIntWrapper operator+(const std::string&) const;
//    MPIntWrapper operator-(const std::string&) const;
//    MPIntWrapper operator*(const std::string&) const;
//    MPIntWrapper operator/(const std::string&) const;
//    MPIntWrapper operator%(const std::string&) const;
//    MPIntWrapper operator+(const long long&) const;
//    MPIntWrapper operator-(const long long&) const;
//    MPIntWrapper operator*(const long long&) const;
//    MPIntWrapper operator/(const long long&) const;
//    MPIntWrapper operator%(const long long&) const;
//
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator+=(const MPIntWrapper<U>&);
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator-=(const MPIntWrapper<U>&);
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator*=(const MPIntWrapper<U>&);
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator/=(const MPIntWrapper<U>&);
//    template <size_t U> requires AtLeastFourBytes<U>
//    MPIntWrapper<T>& operator%=(const MPIntWrapper<U>&);
//    MPIntWrapper& operator+=(const std::string&);
//    MPIntWrapper& operator-=(const std::string&);
//    MPIntWrapper& operator*=(const std::string&);
//    MPIntWrapper& operator/=(const std::string&);
//    MPIntWrapper& operator%=(const std::string&);
//    MPIntWrapper& operator+=(const long long&);
//    MPIntWrapper& operator-=(const long long&);
//    MPIntWrapper& operator*=(const long long&);
//    MPIntWrapper& operator/=(const long long&);
//    MPIntWrapper& operator%=(const long long&);
//
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator<(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator>(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator==(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator!=(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator<=(const MPIntWrapper<U>&) const;
//    template <size_t U> requires AtLeastFourBytes<U>
//    bool operator>=(const MPIntWrapper<U>&) const;
//    bool operator<(const std::string&) const;
//    bool operator>(const std::string&) const;
//    bool operator==(const std::string&) const;
//    bool operator!=(const std::string&) const;
//    bool operator<=(const std::string&) const;
//    bool operator>=(const std::string&) const;
//    bool operator<(const long long&) const;
//    bool operator>(const long long&) const;
//    bool operator==(const long long&) const;
//    bool operator!=(const long long&) const;
//    bool operator<=(const long long&) const;
//    bool operator>=(const long long&) const;
//
//    friend std::istream& operator>>(std::istream&, MPIntWrapper&);
//    friend std::ostream& operator<<(std::ostream&, const MPIntWrapper&);
//
//    [[nodiscard]] std::string to_string() const;
};

template<size_t T>
requires AtLeastFourBytes<T>void MPIntWrapper<T>::overflowCheck() {
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
        throw OverflowException("MPInt<" + std::to_string(T) + "> number overflow.\nvalue=" + this->to_string());
}


#endif //CPP_SP2_MPINTWRAPPER_H
