#include "Point.h"

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::moveY(double l) { this->y += l; }

double Point::getX() const { return x; }

double Point::getY() const { return y; }

void Point::setX(double newX) { this->x = newX; }

void Point::setY(double newY) { this->y = newY; }

void Point::moveX(double l) { this->x += l; }
