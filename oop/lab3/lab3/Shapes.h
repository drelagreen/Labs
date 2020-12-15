#pragma once

#include <iostream>
#include "Point.h"
#include "Rectangle.h"
#include "Square.h"

class Shapes {
private:
    Shapes() {}

public:
    static MyShape *createShape(Point *p1, Point *p2);

    static MyShape *createShape(Point *p1, Point *p2, Point *p3, Point *p4);

    static MyShape *createShape(Point *p1, Point *p2, Point *p3);

    static MyShape *createShape(int count, Point** points);

    static double compare(MyShape *s1, MyShape *s2);

    static bool isIntersect(MyShape *s1, MyShape *s2);

    static bool isInclude(MyShape *s1, MyShape *s2);

};
