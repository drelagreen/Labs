#include "Triad.h"
#include "Exceptions.h"
Triad::Triad(int maxA, int maxB, int maxC, int a, int b, int c) {
	this->maxA = maxA;
	this->maxB = maxB;
	this->maxC = maxC;
	if (check(a, b, c)) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	else {
		throw TriadDataException();
	}
}

bool Triad::isOverloaded() {
	return overloadedFlag;
}

int Triad::getAndIncrement(TriadNumber triadNumber) {
	int* n = getInt(triadNumber);
	int nV = *n;
	(*n)++;
	round(&a, &b, &c);
	return (nV);
}

int Triad::getAndDecrement(TriadNumber triadNumber) {
	int* n = getInt(triadNumber);
	int nV = *n;
	(*n)--;
	round(&a, &b, &c);
	return (nV);
}

int Triad::incrementAndGet(TriadNumber triadNumber) {
	int* n = getInt(triadNumber);
	(*n)++;
	round(&a, &b, &c);
	return (*n);
}

int Triad::decrementAndGet(TriadNumber triadNumber) {
	int* n = getInt(triadNumber);
	(*n)--;
	round(&a, &b, &c);
	return (*n);
}

int Triad::get(TriadNumber triadNumber) {
	return *getInt(triadNumber);
}

bool Triad::check(int a,int b,int c) {
	return (a <= maxA && b <= maxB && c <= maxC);
}

void Triad::round(int* a, int* b, int* c) {
	
	if (*a > maxA) {
		specialRound(a, b, c, INCREMENT);
		(*b)++;
		(*a)=0;
		specialRound(a, b, c, NULL_INCREMENT);
	}
	if (*b > maxB) {
		specialRound(a, b, c, INCREMENT);
		(*c)++;
		(*b)=0;
		specialRound(a, b, c, NULL_INCREMENT);
	}
	if (*c > maxC) {
		specialRound(a, b, c, INCREMENT);
		*c = 0;
		overloadedFlag = true;
		specialRound(a, b, c, NULL_INCREMENT);
	}

	
	specialRound(a, b, c, NULL_DECREMENT);
	if (*a < 0) {
		(*b)--;
		*a = maxA;
		specialRound(a, b, c, DECREMENT);
	}
	specialRound(a, b, c, NULL_DECREMENT);
	if (*b < 0) {
		(*c)--;
		*b = maxB;
		specialRound(a, b, c, DECREMENT);
	}
	specialRound(a, b, c, NULL_DECREMENT);
	if (*c < 0) {
		specialRound(a, b, c, DECREMENT);
		(*c) = maxC;
	}
}

void Triad::clear() {
	a = 0;
	b = 0;
	c = 0;
	overloadedFlag = false;
}
