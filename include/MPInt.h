#ifndef CPP_SP2_MPINT_H
#define CPP_SP2_MPINT_H

#include <string>
#include <iostream>
#include <cmath>

class MPInt {
protected:
    std::string value;
    char sign;
public:
    MPInt();

    MPInt(const MPInt&);
    explicit MPInt(const long long&);
    explicit MPInt(const std::string&);

    MPInt& operator=(const MPInt&);
    MPInt& operator=(const long long&);
    MPInt& operator=(const std::string&);

    MPInt operator+() const;
    MPInt operator-() const;

    MPInt operator+(const MPInt&) const;
    MPInt operator-(const MPInt&) const;
    MPInt operator*(const MPInt&) const;
    MPInt operator/(const MPInt&) const;
    MPInt operator%(const MPInt&) const;
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


    MPInt& operator+=(const MPInt&);
    MPInt& operator-=(const MPInt&);
    MPInt& operator*=(const MPInt&);
    MPInt& operator/=(const MPInt&);
    MPInt& operator%=(const MPInt&);
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


    bool operator<(const MPInt&) const;
    bool operator>(const MPInt&) const;
    bool operator==(const MPInt&) const;
    bool operator!=(const MPInt&) const;
    bool operator<=(const MPInt&) const;
    bool operator>=(const MPInt&) const;
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
