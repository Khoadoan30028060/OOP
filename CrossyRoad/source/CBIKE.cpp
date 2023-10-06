#include "CBIKE.h"

CBIKE::CBIKE() {
	shape.push_back("   __o ");
	shape.push_back(" _ \\<_ ");
	shape.push_back("(_)/(_)");
}

CBIKE::CBIKE(CPOSITION start, bool direction) : COBSTACLE(start, direction) {
	if (this->direction == 0) {
		shape.push_back("   __o ");
		shape.push_back(" _ \\<_ ");
		shape.push_back("(_)/(_)");
	}
	else if (this->direction == 1) {
		shape.push_back(" o__   ");
		shape.push_back(" _>/ _ ");
		shape.push_back("(_)\\(_)");
	}
}

vector <string> CBIKE::getShape() {
	return shape;
}

int CBIKE::getType() {
	return 1;
}

void CBIKE::sound() {
	if (constantVar::isMute == false)
		PlaySound(TEXT("car.wav"), NULL, SND_ALIAS);
}

CBIKE::~CBIKE() {

}