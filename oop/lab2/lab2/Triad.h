#pragma once
#include "TriadNumber.h"
#include "SpecialRoundType.h"
class Triad
{
public:
	Triad(int maxA, int maxB, int maxC, int a, int b, int c);
	int getAndIncrement(TriadNumber triadNumber);
	int getAndDecrement(TriadNumber triadNumber);
	int incrementAndGet(TriadNumber triadNumber);
	int decrementAndGet(TriadNumber triadNumber);
	int get(TriadNumber triadNumber);
	void clear();
	bool isOverloaded();
private:
	bool overloadedFlag;
	int maxA;
	int maxB;
	int maxC;
	int a;
	int b;
	int c;
	int* getInt(TriadNumber triadNumber) {
		switch (triadNumber)
		{ 
		case FIRST:
			return &a;
		case SECOND:
			return &b;
		case THIRD:
			return &c;
		}
	}
	bool check(int a, int b, int c);
	void round(int *a, int *b, int *c);
protected:
	virtual void specialRound(int* a, int* b, int* c, SpecialRoundType flag) {};
};

