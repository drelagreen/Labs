#pragma once
#include "Triad.h"
#include <cstddef>

class Pare {
private:
	Triad* key = NULL;
	Triad* value = NULL;
public:
	Pare();

	Pare(Triad* key, Triad* value);

	Triad* getKey();

	Triad* getValue();

	void setKey(Triad* triad);
	void setValue(Triad* triad);

	~Pare();
};