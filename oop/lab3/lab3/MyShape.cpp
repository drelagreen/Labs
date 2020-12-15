#include "MyShape.h"

ShapeType MyShape::getType() {
    return NONE;
}

double MyShape::getArea() {
    return 0;
}

void MyShape::rotate(double alpha) {
    if (!massCenter) {
        massCenter = calculateMassCenter();
    }
    for (int i = 0; i < pointsCount; i++) {
        pointArray[i]->setX(massCenter->getX() + (pointArray[i]->getX() - massCenter->getX()) * cos(alpha) -
                            (pointArray[i]->getY() - massCenter->getY()) * sin(alpha));
        pointArray[i]->setY(massCenter->getY() + (pointArray[i]->getY() - massCenter->getY()) * cos(alpha) -
                            (pointArray[i]->getX() - massCenter->getX()) * sin(alpha));
    }
}

MyShape::MyShape(int pointsCount, Point **pointArray) {
    this->pointArray = pointArray;
    this->pointsCount = pointsCount;
}

void MyShape::move(double x, double y) {
    for (int i = 0; i < pointsCount; i++) {
        pointArray[i]->moveX(x);
        pointArray[i]->moveY(y);
    }
}

MyShape::~MyShape() {
    for (int i = 0; i < pointsCount; i++) {
        if (pointArray != nullptr)
            delete pointArray[i];
    }
    if (pointArray != nullptr)
        delete pointArray;
    if (massCenter != nullptr)
        delete massCenter;

}

Point *MyShape::getPoint(int index) {
    if (index < 0 || index > 3 || !pointArray[index - 1]) {
        throw MyException("Incorrect Index\n");
    }
    return pointArray[index];
}

double MyShape::getOutRadius() {
    return sqrt(pow(pointArray[0]->getX() - pointArray[3]->getX(), 2) +
                pow(pointArray[0]->getX() - pointArray[3]->getX(), 2)) / 2;
}

Point *MyShape::getMassCenter() {
    if (massCenter!=nullptr)
        delete massCenter;
    massCenter = calculateMassCenter();
    return massCenter;
}

int MyShape::getCount() const {
    return pointsCount;
}

Point *MyShape::calculateMassCenter() {
    return new Point(getPoint(0)->getX() - (getPoint(0)->getX() - getPoint(3)->getX()) / 2,
                     getPoint(0)->getY() - (getPoint(0)->getY() - getPoint(3)->getY()) / 2);
}

void MyShape::setPoint(int i, Point *p) {
    pointArray[i] = p;
}
