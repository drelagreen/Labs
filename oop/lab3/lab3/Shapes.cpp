#include "Shapes.h"

MyShape *Shapes::createShape(Point *p1, Point *p2) {
    if (p1== nullptr || p2 == nullptr){
        delete p1, p2;
        throw MyException("Null pointer exception! (createShape2)");
    }
    if (*p1 == *p2) {
        delete p1, p2;
        throw MyException("Wrong coordinates!");
    }
    Square *s = new Square(p1, p2);
    return s;
}

MyShape *Shapes::createShape(Point *p1, Point *p2, Point *p3, Point *p4) {
    if (p1== nullptr || p2 == nullptr || p3 == nullptr || p4 == nullptr){
        delete p1, p2, p3, p4;
        throw MyException("Null pointer exception! (createShape4)");
    }
    if (*p1 == *p2 || *p1 == *p3 || *p1 == *p4 || *p2 == *p3 || *p2 == *p4 || *p3 == *p4) {
        delete p1, p2, p3, p4;
        throw MyException("Wrong coordinates!");
        
    }
    if (p3->getX() - p1->getX() != p2->getX() - p4->getX() && p3->getY() - p1->getY() != p2->getY() - p4->getY()) {
        delete p1, p2, p3, p4;
        throw MyException("Wrong coordinates!");
    }
    MyShape *s = nullptr;
    if (
            (p1->getX() + (p2->getY() - p1->getY())) == p3->getX() &&
            (p1->getY() - (p2->getX() - p1->getX())) == p3->getY()
            ) {
        delete p3, p4;
        s = new Square(p1, p2);
        return s;
    } else {
        s = new Rectangle(p1, p2, p3, p4);
        return s;
    }
}

MyShape *Shapes::createShape(Point *p1, Point *p2, Point *p3) {
    if (p1== nullptr || p2 == nullptr || p3 == nullptr){
        delete p1, p2, p3;
        throw MyException("Null pointer exception! (createShape3)");
    }
    if (*p1 == *p2 || *p1 == *p3 || *p2 == *p3) {
        delete p1, p2, p3;
        throw MyException("Wrong coordinates!");
    }
    if (
            ((p2->getX() - p1->getX()) * (p3->getX() - p1->getX()) +
             (p2->getY() - p1->getY()) * (p3->getY() - p1->getY())) /
            (sqrt(pow(p2->getX() - p1->getX(), 2) + pow(p2->getY() - p1->getY(), 2)) *
             sqrt(pow(p3->getX() - p1->getX(), 2) + pow(p3->getY() - p1->getY(), 2))) != 0
            ) {
        delete p1, p2, p3;
        throw MyException("Wrong coordinates!");
    }
    if (
            (p1->getX() + (p2->getY() - p1->getY())) == p3->getX() &&
            (p1->getY() - (p2->getX() - p1->getX())) == p3->getY()
            ) {
        delete p3;

        return new Square(p1, p2);
    } else {
        return new Rectangle(p1, p2, p3);
    }
}

MyShape *Shapes::createShape(int count, Point **points) {
    try {
        if (points == nullptr) {
            throw MyException("Null pointer exception! (createShape0)");
        }
        MyShape* shape = nullptr;
        switch (count) {
        case (2):
            shape = createShape(points[0], points[1]);
            delete points;
            return shape;
        case (3):
            shape = createShape(points[0], points[1], points[2]);
            delete points;
            return shape;
        case (4):
            shape = createShape(points[0], points[1], points[2], points[3]);
            delete points;
            return shape;
        default:
            throw MyException("Incorrect count of points!");
        }
    }
    catch (MyException& e) {
        delete[] points;
        throw e;
    }
}

double Shapes::compare(MyShape *s1, MyShape *s2) {
    if (s1 == nullptr || s2 == nullptr){
        throw MyException("Null pointer exception! (compare)");
    }
    return s1->getArea() - s2->getArea();
}

bool Shapes::isIntersect(MyShape *s1, MyShape *s2) {
    if (s1 == nullptr || s2 == nullptr){
        throw MyException("Null pointer exception! (isIntersect)");
    }
    //Моих знаниий и умений в векторной геометрии слишком мало, чтоб реализовать этот метод без ошибок :(
    return true;
}

bool Shapes::isInclude(MyShape *s1, MyShape *s2) {
    if (s1 == nullptr || s2 == nullptr){
        throw MyException("Null pointer exception! (isInclude)");
    }
    //Моих знаниий и умений в векторной геометрии слишком мало, чтоб реализовать этот метод без ошибок :(
    return true;
}
