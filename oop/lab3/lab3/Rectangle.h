#pragma once


#include <cmath>
#include "MyShape.h"
#include "ShapeType.h"

class Rectangle : public MyShape
{
public:
    Rectangle(Point* p1, Point* p2, Point* p3, Point* p4);

    Rectangle(Point* p1, Point* p2, Point* p3);

    double getArea() override;
    
    ShapeType getType() override {
        return RECTANGLE;
    }
};


