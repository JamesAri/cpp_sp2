#ifndef CPP_SP2_MPINT_H
#define CPP_SP2_MPINT_H

#include <string>
#include <iostream>
#include <cmath>

constexpr size_t UNLIMITED = 0;

template<size_t S>
concept AtLeastFourBytes = (S >= 4) || (S == UNLIMITED);

template <size_t T> requires AtLeastFourBytes<T>
class MPInt {
private:
    template <size_t U> requires AtLeastFourBytes<U>
    friend class MPInt;
    std::string value;
    char sign;
    size_t RANGE = pow(2, 8 * T);
    size_t MAX_SIZE = pow(2, 8 * T - 1) - 1;
    size_t MIN_SIZE = pow(2, 8 * T - 1);
public:
    void workWithTemplate() {
        std::cout << RANGE << std::endl;
        std::cout << MAX_SIZE << std::endl;
        std::cout << MIN_SIZE << std::endl;
    }

    MPInt();
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt(const MPInt<U>&);
    explicit MPInt(const long long&);
    explicit MPInt(const std::string&);

    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator=(const MPInt<U>&);
    MPInt& operator=(const long long&);
    MPInt& operator=(const std::string&);

    MPInt operator+() const;
    MPInt operator-() const;

    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator+(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator-(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator*(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator/(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<std::max(T, U)> operator%(const MPInt<U>&) const;
    MPInt operator+(const std::string&) const;
    MPInt operator-(const std::string&) const;
    MPInt operator*(const std::string&) const;
    MPInt operator/(const std::string&) const;
    MPInt operator%(const std::string&) const;
    MPInt operator+(const long long&) const;
    MPInt operator-(const long long&) const;
    MPInt operator*(const long long&) const;
    MPInt operator/(const long long&) const;
    MPInt operator%(const long long&) const;

    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator+=(const MPInt<U>&);
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator-=(const MPInt<U>&);
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator*=(const MPInt<U>&);
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator/=(const MPInt<U>&);
    template <size_t U> requires AtLeastFourBytes<U>
    MPInt<T>& operator%=(const MPInt<U>&);
    MPInt& operator+=(const std::string&);
    MPInt& operator-=(const std::string&);
    MPInt& operator*=(const std::string&);
    MPInt& operator/=(const std::string&);
    MPInt& operator%=(const std::string&);
    MPInt& operator+=(const long long&);
    MPInt& operator-=(const long long&);
    MPInt& operator*=(const long long&);
    MPInt& operator/=(const long long&);
    MPInt& operator%=(const long long&);

    template <size_t U> requires AtLeastFourBytes<U>
    bool operator<(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    bool operator>(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    bool operator==(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    bool operator!=(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    bool operator<=(const MPInt<U>&) const;
    template <size_t U> requires AtLeastFourBytes<U>
    bool operator>=(const MPInt<U>&) const;
    bool operator<(const std::string&) const;
    bool operator>(const std::string&) const;
    bool operator==(const std::string&) const;
    bool operator!=(const std::string&) const;
    bool operator<=(const std::string&) const;
    bool operator>=(const std::string&) const;
    bool operator<(const long long&) const;
    bool operator>(const long long&) const;
    bool operator==(const long long&) const;
    bool operator!=(const long long&) const;
    bool operator<=(const long long&) const;
    bool operator>=(const long long&) const;

    friend std::istream& operator>>(std::istream&, MPInt&);
    friend std::ostream& operator<<(std::ostream&, const MPInt&);

    [[nodiscard]] std::string to_string() const;
//    int to_int() const;
//    long to_long() const;
//    long long to_long_long() const;
};

#endif //CPP_SP2_MPINT_H
