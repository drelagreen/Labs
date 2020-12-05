#include "Pare.h"

Pare::Pare() {}

Pare::Pare(Triad* key, Triad* value) {
	this->key = key;
	this->value = value;
}

Triad* Pare::getKey() {
	return key;
}

Triad* Pare::getValue() {
	return value;
}

void Pare::setKey(Triad* triad) {
	key = triad;
}

void Pare::setValue(Triad* triad) {
	value = triad;
}

Pare::~Pare() {
	if (key)
		delete key;

	if (value)
		delete value;

	key = NULL;
	value = NULL;
}