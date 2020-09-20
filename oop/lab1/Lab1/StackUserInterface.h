#pragma once
#include <iostream>
#include "Stack.h"

class StackUserInterface{
private:
    Stack* _stack;
    int getNextInt();
    int getStackSize();
    void printExceptionMessage(std::exception& e);
public:
    void start();
    ~StackUserInterface();
};