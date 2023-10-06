#include "CPOSITION.h"

CPOSITION::CPOSITION() {
	X = Y = -1;
}

CPOSITION::CPOSITION(int X, int Y) {
	this->X = X;
	this->Y = Y;
}
int CPOSITION::getX() {
	return X;
}

int CPOSITION::getY() {
	return Y;
}

void CPOSITION::setPos(int X, int Y) {
	this->X = X;
	this->Y = Y;
}
CPOSITION::~CPOSITION() {
	
}