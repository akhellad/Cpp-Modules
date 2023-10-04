#include "../includes/Point.hpp"

// Constructeur par défaut
Point::Point() : x(0), y(0) {}

// Constructeur prenant des valeurs float
Point::Point(const float xValue, const float yValue) : x(Fixed(xValue)), y(Fixed(yValue)) {}

// Constructeur de copie
Point::Point(const Point &other) : x(other.x), y(other.y) {}

// Destructeur
Point::~Point() {}

// Opérateur d'affectation
Point &Point::operator=(const Point &other) {
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

// Méthode pour le produit vectoriel
float Point::cross(const Point &other) const {
    return (this->x.toFloat() * other.y.toFloat()) - (other.x.toFloat() * this->y.toFloat());
}


// Opérateur de comparaison >=
bool Point::operator>=(const Point &other) const {
    return (this->x >= other.x) && (this->y >= other.y);
}

// Opérateur de comparaison <=
bool Point::operator<=(const Point &other) const {
    return (this->x <= other.x) && (this->y <= other.y);
}

// Opérateur de soustraction
Point Point::operator-(const Point &other) const {
    return Point(this->x.toFloat() - other.x.toFloat(), this->y.toFloat() - other.y.toFloat());
}