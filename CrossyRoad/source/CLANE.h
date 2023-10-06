#pragma once
#include "CONELANE.h"

class CLANE {
private:
	vector <CONELANE*> subLane;
public:
	CLANE();
	~CLANE() = default;
	vector <CONELANE*> getListLane();
	CONELANE* getLanePos(int);
	bool pushObs(COBSTACLE*, int, int);
	void pushLane(CONELANE*);
	void printAllLane();
	void eraseAllLane();
};

