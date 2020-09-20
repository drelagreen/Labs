#pragma once

class Stack {
    int* _stackArray;
    int _maxSize;
    int _size;
public:
    explicit Stack(int size);
    int pop();
    int back();
    void push(int element);
    bool isEmpty() const;
    int getMaxSize() const;
    ~Stack();
};