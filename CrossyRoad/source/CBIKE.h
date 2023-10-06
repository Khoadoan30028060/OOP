#pragma once
#include "COBSTACLE.h"

class CBIKE: public COBSTACLE {
public:
	CBIKE();
	CBIKE(CPOSITION, bool); 
	vector <string> getShape();
	int getType();
	void sound();
	~CBIKE();
};

