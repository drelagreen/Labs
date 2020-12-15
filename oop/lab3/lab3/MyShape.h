#pragma once

#include "Point.h"
#include "cmath"
#include "MyException.h"
#include "ShapeType.h"

class MyShape {
private:
    Point **pointArray = nullptr;
    int pointsCount = 0;
    Point *massCenter = nullptr;
public:
    MyShape(int pointsCount, Point **pointArray);

    virtual ShapeType getType();

    virtual double getArea();

    virtual void rotate(double alpha);

    virtual void move(double x, double y);

    ~MyShape();

    Point *getPoint(int index);

    double getOutRadius();

    Point *getMassCenter();

    int getCount() const;
protected:

    Point *calculateMassCenter();

    void setPoint(int i, Point *p);
};
