#include "../includes/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int intValue) : value(intValue << fractionalBits) {}

Fixed::Fixed(const float floatValue) : value(static_cast<int>(roundf(floatValue * (1 << fractionalBits)))) {}

Fixed::Fixed(const Fixed &other) : value(other.value) {}

Fixed::~Fixed() {}

float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

int Fixed::toInt() const {
    return value >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    if (other.value == 0) {
        std::cerr << "Division by zero!" << std::endl;
        return Fixed(0);
    }
    return Fixed(toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed &Fixed::operator--() {
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    operator--();
    return temp;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b, bool &result) {
    if (a < b) {
        result = true;
        return a;
    } else {
        result = false;
        return b;
    }
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b, bool &result) {
    if (a > b) {
        result = true;
        return a;
    } else {
        result = false;
        return b;
    }
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}