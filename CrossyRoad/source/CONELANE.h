#pragma once
#include "Console.h"
#include "COBSTACLE.h"

#define RIGHTMAP 117
#define LEFTMAP 2

class CONELANE {
private:
	vector <COBSTACLE*> List;
	int speed, currentRow;
	bool RedLight;
	bool Direction; //false: to the left, true: to the right
public:
	CONELANE() = default;
	CONELANE(int, int, bool, bool);
	~CONELANE() = default;
	vector<COBSTACLE*> getObs();
	bool pushObs(COBSTACLE*, int); // thêm obs vào list
	void drawObs(CPOSITION, vector<string>); // vẽ một Obs
	void eraseObs(CPOSITION, vector<string>); // xóa một Obs
	void printAllObs(); // in xe di chuyển 
	void eraseAllObs(); // xóa tất cả các vật thể
	bool getRedLight();
	bool getDirection();
	void changeRedLight();
};

