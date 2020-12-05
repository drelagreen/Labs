#pragma once
#include "Memories.h"
#include <cstddef>
class Interaction
{
private:
	Memories* memories = NULL;
	void menu1();
	bool menu2(int x);
	int scan();
	void printData();
	bool runningFlag = true;
public:
	Interaction(Memories* memories);
	Interaction() {}
	~Interaction() { if (memories) delete memories; }
	void start();
};

