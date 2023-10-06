#pragma once
#include "COBSTACLE.h"

class CCAR: public COBSTACLE {
public:
	CCAR();
	CCAR(CPOSITION, bool);
	vector<string> getShape();
	int getType();
	void sound();
	~CCAR();
};

