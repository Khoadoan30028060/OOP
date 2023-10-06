#pragma once
#include "Console.h"
#include "CPOSITION.h"

class COBSTACLE {
protected:
	CPOSITION pos;
	vector <string> shape;
	bool direction;
public:
	COBSTACLE();

	COBSTACLE(CPOSITION, bool);

	CPOSITION getPos();

	virtual vector<string> getShape() = 0;

	virtual int getType() = 0;
	
	virtual void sound() = 0;

	void updatePos(int, int);
	

	virtual~COBSTACLE() = default;
};

