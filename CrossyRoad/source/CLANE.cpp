#include "CLANE.h"

CLANE::CLANE() {
	subLane.reserve(100);
}

vector <CONELANE*> CLANE::getListLane() {
	return subLane;
}

CONELANE* CLANE::getLanePos(int pos) {
	return subLane[pos];
}
bool CLANE::pushObs(COBSTACLE* newObs, int index_lane, int LV) {
	if (index_lane >= subLane.size())
		return false;
	return subLane[index_lane]->pushObs(newObs, LV);
}

void CLANE::pushLane(CONELANE* Lane) {
	subLane.push_back(Lane);
}

void CLANE::printAllLane() {
	for (int i = 0; i < subLane.size(); i++) {
		subLane[i]->printAllObs();
	}
}

void CLANE::eraseAllLane() {
	for (int i = 0; i < subLane.size(); i++) {
		subLane[i]->eraseAllObs();
	}
}
