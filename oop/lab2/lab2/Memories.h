#pragma once
#include "Pare.h"
class Memories {

private:
	Pare** pareArray;
	int maxSize;
	int size = 0;
public:
	Memories(int size);
	Pare* getPare(int index);
	void setPare(int index, Triad* t1, Triad* t2);
	void setPare(int index, Pare* pare);
	void removePare(int index);
	int getMaxSize();
	~Memories();
};