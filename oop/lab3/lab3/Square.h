#pragma once
#include "MyShape.h"
#include "ShapeType.h"

class Square: public MyShape {
public:
    Square(Point* p1, Point* p2);

    double getArea() override;

    ShapeType getType() override;
};


