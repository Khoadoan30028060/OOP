#pragma once
#include "COBSTACLE.h"

class CBUTTERFLY: public COBSTACLE {
public:
	CBUTTERFLY();
	CBUTTERFLY(CPOSITION, bool);
	vector <string> getShape();
	int getType();
	void sound();
	~CBUTTERFLY();
};