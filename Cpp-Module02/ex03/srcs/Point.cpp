/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:10:59 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/22 11:16:36 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xValue, const float yValue) : x(Fixed(xValue)), y(Fixed(yValue)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other) {
    if (this != &other) {
        this->x = other.x;
        this->y = other.y;
    }
    return *this;
}

float Point::cross(const Point &other) const {
    return (this->x.toFloat() * other.y.toFloat()) - (other.x.toFloat() * this->y.toFloat());
}


bool Point::operator>=(const Point &other) const {
    return (this->x >= other.x) && (this->y >= other.y);
}

bool Point::operator<=(const Point &other) const {
    return (this->x <= other.x) && (this->y <= other.y);
}

Point Point::operator-(const Point &other) const {
    return Point(this->x.toFloat() - other.x.toFloat(), this->y.toFloat() - other.y.toFloat());
}