#include "CDUCK.h"

CDUCK::CDUCK() {
	shape.push_back("   _  ");
	shape.push_back("__(.)>");
	shape.push_back("\\___) ");
}

CDUCK::CDUCK(CPOSITION start, bool direction) : COBSTACLE(start, direction) {
	if (this->direction == 0) {
		shape.push_back("   _  ");
		shape.push_back("__(.)>");
		shape.push_back("\\___) ");
	}
	else if (this->direction == 1) {
		shape.push_back("  _   ");
		shape.push_back("<(.)__");
		shape.push_back(" (___/ ");
	}
}

vector <string> CDUCK::getShape() {
	return shape;
}

int CDUCK::getType() {
	return 4;
}

void CDUCK::sound() {
	if (constantVar::isMute == false)
		//PlaySound(TEXT("duck.wav"), NULL, SND_ASYNC);
		PlaySound(TEXT("duck.wav"), NULL, SND_ALIAS);
}

CDUCK::~CDUCK() {

}