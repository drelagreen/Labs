#include "Stack.h"
#include <iostream>
#include "MyExceptions.h"
	Stack::Stack(int size) {
		_stackArray = new int[size];
		_maxSize = size;
		_size = 0;
	}

	bool Stack::isEmpty() const {
		return (_size == 0);
	}

	void Stack::push(int element) {
		if (_size >= _maxSize) {
			throw StackOverflowException();
		}
		else {
			Stack::_stackArray[_size++] = element;
		}
	}

	int Stack::pop() {
		if (_size <= 0) {
			throw StackUnderflowException();
		}
		else {
			return _stackArray[--_size];
		}
	}

	int Stack::back() {
		if (_size <= 0) {
			throw StackUnderflowException();
		}
		else {
			return _stackArray[_size-1];
		}
	}

    int Stack::getMaxSize() const{
        return _maxSize;
	}

    Stack::~Stack() {
		delete(_stackArray);
	}
