#ifndef CPP_SP2_MPINTBASE_H
#define CPP_SP2_MPINTBASE_H

#include <string>
#include <iostream>
#include <cmath>

class MPIntBase {
protected:
    std::string value;
    char sign;
public:
    MPIntBase();

    MPIntBase(const MPIntBase&);
    MPIntBase(const long long&);
    MPIntBase(const std::string&);

    MPIntBase& operator=(const MPIntBase&);
    MPIntBase& operator=(const long long&);
    MPIntBase& operator=(const std::string&);

    MPIntBase operator+() const;
    MPIntBase operator-() const;

    MPIntBase operator+(const MPIntBase&) const;
    MPIntBase operator-(const MPIntBase&) const;
    MPIntBase operator*(const MPIntBase&) const;
    MPIntBase operator/(const MPIntBase&) const;
    MPIntBase operator%(const MPIntBase&) const;
    MPIntBase operator+(const std::string&) const;
    MPIntBase operator-(const std::string&) const;
    MPIntBase operator*(const std::string&) const;
    MPIntBase operator/(const std::string&) const;
    MPIntBase operator%(const std::string&) const;
    MPIntBase operator+(const long long&) const;
    MPIntBase operator-(const long long&) const;
    MPIntBase operator*(const long long&) const;
    MPIntBase operator/(const long long&) const;
    MPIntBase operator%(const long long&) const;


    MPIntBase& operator+=(const MPIntBase&);
    MPIntBase& operator-=(const MPIntBase&);
    MPIntBase& operator*=(const MPIntBase&);
    MPIntBase& operator/=(const MPIntBase&);
    MPIntBase& operator%=(const MPIntBase&);
    MPIntBase& operator+=(const std::string&);
    MPIntBase& operator-=(const std::string&);
    MPIntBase& operator*=(const std::string&);
    MPIntBase& operator/=(const std::string&);
    MPIntBase& operator%=(const std::string&);
    MPIntBase& operator+=(const long long&);
    MPIntBase& operator-=(const long long&);
    MPIntBase& operator*=(const long long&);
    MPIntBase& operator/=(const long long&);
    MPIntBase& operator%=(const long long&);


    bool operator<(const MPIntBase&) const;
    bool operator>(const MPIntBase&) const;
    bool operator==(const MPIntBase&) const;
    bool operator!=(const MPIntBase&) const;
    bool operator<=(const MPIntBase&) const;
    bool operator>=(const MPIntBase&) const;
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

    friend std::istream& operator>>(std::istream&, MPIntBase&);
    friend std::ostream& operator<<(std::ostream&, const MPIntBase&);

    [[nodiscard]] std::string to_string() const;
};

#endif //CPP_SP2_MPINTBASE_H
