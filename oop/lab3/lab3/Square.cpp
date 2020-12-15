#include "Square.h"

Square::Square(Point *p1, Point *p2) : MyShape(4, new Point* [4]{0 }){
    // p1 верхняя левая точка p2 - верхняя правая
    setPoint(0, p1);
    setPoint(1, p2);
    setPoint(2 , new Point(p1->getX() + (p2->getY() - p1->getY()), p1->getY() - (p2->getX() - p1->getX())));
    setPoint(3, new Point(p2->getX() + (p2->getY() - p1->getY()), p2->getY() - (p2->getX() - p1->getX())));
}

double Square::getArea() {
    return pow(sqrt(pow(getPoint(0)->getX() - getPoint(1)->getX(), 2) + pow(getPoint(0)->getY() - getPoint(1)->getY(), 2)), 2);
}

ShapeType Square::getType() {
    return SQUARE;
}
