#include "Memories.h"

Memories::Memories(int size) {
	this->maxSize = size;
	pareArray = new Pare * [size] {NULL};
}

Pare* Memories::getPare(int index) {
	return pareArray[index];
}

void Memories::setPare(int index, Triad* t1, Triad* t2) {
	this->setPare(index, new Pare(t1, t2));
}

void Memories::setPare(int index, Pare* pare) {
	if (pareArray[index] != NULL) {
		delete pareArray[index];
	}

	pareArray[index] = pare;

}

void Memories::removePare(int index) {
	delete pareArray[index];
	pareArray[index] = NULL;
}

Memories::~Memories() {
	for (int i = 0; i < maxSize; i++) {
		if (pareArray[i])
			delete pareArray[i];

		pareArray[i] = NULL;
	}
}

int Memories::getMaxSize() {
	return maxSize;
}