#pragma once
class CPOSITION {
private: 
	int X, Y;
public:
	CPOSITION();
	CPOSITION(int, int);
	int getX();
	int getY();
	void setPos(int,int);
	~CPOSITION();
};

