#pragma once
#include "Console.h"
#include "CPOSITION.h"

#define LeftMap 2
#define RightMap 113

class CPEOPLE {
private:
	CPOSITION pos;
	vector<string> shape;
	bool isAlive;
public:
	CPEOPLE();
	CPEOPLE(CPOSITION);
	vector <string> getShape();
	bool getState();
	CPOSITION getPos();
	void checkDead(CPOSITION, vector<string>);
	void Left();
	void Right();
	void Up();
	void Down();
	~CPEOPLE();
};

