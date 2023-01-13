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
    inline MPIntBase();

    inline MPIntBase(const MPIntBase&);
    inline MPIntBase(const long long&);
    inline MPIntBase(const std::string&);

    inline MPIntBase& operator=(const MPIntBase&);
    inline MPIntBase& operator=(const long long&);
    inline MPIntBase& operator=(const std::string&);

    inline MPIntBase operator+() const;
    inline MPIntBase operator-() const;

    inline MPIntBase operator+(const MPIntBase&) const;
    inline MPIntBase operator-(const MPIntBase&) const;
    inline MPIntBase operator*(const MPIntBase&) const;
    inline MPIntBase operator/(const MPIntBase&) const;
    inline MPIntBase operator%(const MPIntBase&) const;
    inline MPIntBase operator+(const std::string&) const;
    inline MPIntBase operator-(const std::string&) const;
    inline MPIntBase operator*(const std::string&) const;
    inline MPIntBase operator/(const std::string&) const;
    inline MPIntBase operator%(const std::string&) const;
    inline MPIntBase operator+(const long long&) const;
    inline MPIntBase operator-(const long long&) const;
    inline MPIntBase operator*(const long long&) const;
    inline MPIntBase operator/(const long long&) const;
    inline MPIntBase operator%(const long long&) const;


    inline MPIntBase& operator+=(const MPIntBase&);
    inline MPIntBase& operator-=(const MPIntBase&);
    inline MPIntBase& operator*=(const MPIntBase&);
    inline MPIntBase& operator/=(const MPIntBase&);
    inline MPIntBase& operator%=(const MPIntBase&);
    inline MPIntBase& operator+=(const std::string&);
    inline MPIntBase& operator-=(const std::string&);
    inline MPIntBase& operator*=(const std::string&);
    inline MPIntBase& operator/=(const std::string&);
    inline MPIntBase& operator%=(const std::string&);
    inline MPIntBase& operator+=(const long long&);
    inline MPIntBase& operator-=(const long long&);
    inline MPIntBase& operator*=(const long long&);
    inline MPIntBase& operator/=(const long long&);
    inline MPIntBase& operator%=(const long long&);


    inline bool operator<(const MPIntBase&) const;
    inline bool operator>(const MPIntBase&) const;
    inline bool operator==(const MPIntBase&) const;
    inline bool operator!=(const MPIntBase&) const;
    inline bool operator<=(const MPIntBase&) const;
    inline bool operator>=(const MPIntBase&) const;
    inline bool operator<(const std::string&) const;
    inline bool operator>(const std::string&) const;
    inline bool operator==(const std::string&) const;
    inline bool operator!=(const std::string&) const;
    inline bool operator<=(const std::string&) const;
    inline bool operator>=(const std::string&) const;
    inline bool operator<(const long long&) const;
    inline bool operator>(const long long&) const;
    inline bool operator==(const long long&) const;
    inline bool operator!=(const long long&) const;
    inline bool operator<=(const long long&) const;
    inline bool operator>=(const long long&) const;

    inline friend std::istream& operator>>(std::istream&, MPIntBase&);
    inline friend std::ostream& operator<<(std::ostream&, const MPIntBase&);

    inline std::string to_string() const;
};

#endif //CPP_SP2_MPINTBASE_H
