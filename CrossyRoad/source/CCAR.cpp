#include "CCAR.h"

#include "CCAR.h"

CCAR::CCAR() {
	shape.push_back(" ____|~\\_");
	shape.push_back("[____|_|-]");
	shape.push_back(" (_)   (_)");
}

CCAR::CCAR(CPOSITION start, bool direction) : COBSTACLE(start, direction) {
	if (this->direction == 0) {
		shape.push_back(" ____|~\\_");
		shape.push_back("[____|_|-]");
		shape.push_back(" (_)   (_)");
	}
	else if (this->direction == 1) {
		shape.push_back(" _/~|____ ");
		shape.push_back("[-|_|____]");
		shape.push_back("(_)   (_) ");
	}
}

vector<string> CCAR::getShape() {
	return shape;
}

int CCAR::getType() {
	return 3;
}

void CCAR::sound() {
	if (constantVar::isMute == false)
		PlaySound(TEXT("car.wav"), NULL, SND_ALIAS);
}

CCAR::~CCAR() {

}