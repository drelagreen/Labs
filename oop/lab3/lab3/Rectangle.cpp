#include "Rectangle.h"

double Rectangle::getArea() {
    return sqrt(pow(getPoint(1)->getX() - getPoint(0)->getX(), 2) + pow(getPoint(1)->getY() - getPoint(0)->getY(), 2)) *
           sqrt(pow(getPoint(0)->getX() - getPoint(2)->getX(), 2) + pow(getPoint(0)->getY() - getPoint(2)->getY(), 2));
}

Rectangle::Rectangle(Point *p1, Point *p2, Point *p3, Point *p4) : MyShape(4, new Point* [4]{ 0 }) {
    setPoint(0, p1);
    setPoint(1, p2);
    setPoint(2, p3);
    setPoint(3, p4);
}

Rectangle::Rectangle(Point *p1, Point *p2, Point *p3) : MyShape(4, new Point* [4]{ 0 }) {
    setPoint(0, p1);
    setPoint(1, p2);
    setPoint(2, p3);
    setPoint(3, new Point(p3->getX() + (p2->getX() - p1->getX()), p3->getY() + (p2->getY() - p1->getY())));
}