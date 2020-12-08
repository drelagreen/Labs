#pragma once
#include "Triad.h"
template <typename T>

class TriadFactory {

public:
	static T* getTriad(int a, int b, int c) {
		T* t = new T(a, b, c);
		return t;
	}
};