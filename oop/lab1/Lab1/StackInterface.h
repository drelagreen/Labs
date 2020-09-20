#pragma once
#include <iostream>

class StackInterface{
private:
    int getNextInt();
    int getStackSize();
    void printExceptionMessage(std::exception& e);
public:
    void start();
    ~StackInterface();
};