#include "CBUTTERFLY.h"

CBUTTERFLY::CBUTTERFLY() {
	shape.push_back("   \"   ");
	shape.push_back("(_\\|/_)");
	shape.push_back(" (/|\\) ");
}

CBUTTERFLY::CBUTTERFLY(CPOSITION start, bool direction) : COBSTACLE(start, direction) {
	shape.push_back("   \"   ");
	shape.push_back("(_\\|/_)");
	shape.push_back(" (/|\\) ");
}

vector <string> CBUTTERFLY::getShape() {
	return shape;
}

int CBUTTERFLY::getType() {
	return 2;
}

void CBUTTERFLY::sound() {
	if (constantVar::isMute == false)
		PlaySound(TEXT("bird.wav"), NULL, SND_ALIAS);
}

CBUTTERFLY::~CBUTTERFLY() {

}