#include "CLEVEL.h"

CLEVEL::CLEVEL() {
	Mode = 1;
	Level = 1;
	Initialize();
}

CLEVEL::CLEVEL(int level, int mode) {
	this->Level = level;
	this->Mode = mode;
	Initialize();
}
CLEVEL& CLEVEL::operator= (const CLEVEL& A) {
	this->Level = A.Level;
	this->Mode = A.Mode;
	Initialize();
	return *this;
}
void CLEVEL::Initialize() {
	Time = 10000 - 1000 * (Mode - 1)  - 500 * (Level - 1);
}

int CLEVEL::getLevel() {
	return Level;
}

int CLEVEL::getMode() {
	return Mode;
}
bool CLEVEL::setLevel(int lv, int mode) {
	if (lv > maxLevel) 
		return false;
	Level = lv;
	Mode = mode;
	Initialize();
	return true;
}

bool CLEVEL::nextLevel() {
	if (Level == maxLevel)
		return false;
	Level += 1;
	Initialize();
	return true;
}

int CLEVEL::getTime() {
	return Time;
}

COBSTACLE* CLEVEL::chooseTypeObs(CPOSITION pos, bool direction, int type) {
	switch (type) {
		case 1: return new CBIKE(pos, direction);
		case 2: return new CBUTTERFLY(pos, direction);
		case 3: return new CCAR(pos, direction);
		case 4: return new CDUCK(pos, direction);
	}
	return NULL;
}
CLEVEL::~CLEVEL() {

}