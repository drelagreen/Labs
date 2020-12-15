#pragma once
#include "MyShape.h"
#include "Shapes.h"
#include "ShapeType.h"
class Interactor {
private:
    MyShape* shape1 = nullptr;
    MyShape* shape2 = nullptr;
    bool running = true;
public:
    void showMenu();
    int getMenuNum();
    void execute(int cmd);
    static bool boolChoice(const char* text, const char* v1, const char* v2);
    void loop();
    ~Interactor(){
        delete shape1;
        delete shape2;
    }
};
