#pragma once

class Stack {
    int* _stackArray;
    int _maxSize;
    int _size = 0;
public:
    Stack(int size);
    int pop();
    int back();
    void push(int element);
    bool isEmpty();
    int getMaxSize();
    ~Stack();
};