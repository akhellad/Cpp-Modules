#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed &other);
    ~Fixed();

    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);


    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b, bool &result);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b, bool &result);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
