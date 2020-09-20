#include "Stack.h"
#include "MyExceptions.h"
#include <string.h>
	Stack::Stack(int size) {
		_stackArray = new int[size];
		_maxSize = size;
	}
	
	Stack::~Stack() {
		delete(_stackArray);
	}

	bool Stack::isEmpty(){
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

    int Stack::getMaxSize() {
        return _maxSize;
	}

  
